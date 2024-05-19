#include <ArduinoOTA.h>
#include <PubSubClient.h>
#include <esp_wifi.h>
#include <WiFi.h>
#include <ESPmDNS.h>
#include <ArduinoJson.h>
#include <tiny-collections.h>
#include <TLog.h>

#include "settings.h"
#include "dsmr_map.h"

WiFiClient espClient;
PubSubClient mqttClient(espClient);

#ifdef MQTT_DEBUGGING
#include <MqttlogStream.h>
#endif
#ifdef WEB_DEBUGGING
#include <WebSerialStream.h>
#endif
/***********************************
            Main Setup
 ***********************************/
void setup() {
  // Initialize pins and blink once for setup start
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  blinkLed(1, 500);

  // Force CPU frequency if constant is specified
  if (CPU_FREQ > 0) {
    setCpuFrequencyMhz(CPU_FREQ);
  }

  Serial.begin(BAUD_RATE);

#ifdef DEBUG
  // Blinking 2 times long to indicate DEBUG mode
  debug("Booting - DEBUG mode on");
  blinkLed(2, 2000);
#endif

  makeSureWiFiConnected(true);

  MDNS.begin(String(HOSTNAME).c_str());
  delay(1000);

  setupDataReadout();
  setupOTA();

  mqttClient.setServer(MQTT_HOST, atoi(MQTT_PORT));
  makeSureMqttConnected();

#ifdef MQTT_DEBUGGING
  MqttStream mqttStream = MqttStream(&mqttClient);
  mqttStream.setTopic(MQTT_DEBUG_TOPIC);

  const std::shared_ptr<LOGBase> mqttStreamPtr = std::make_shared<MqttStream>(mqttStream);
  Log.addPrintStream(mqttStreamPtr);
#endif

#ifdef WEB_DEBUGGING
  WebSerialStream webSerialStream = WebSerialStream();
  Log.addPrintStream(std::make_shared<WebSerialStream>(webSerialStream));
#endif

  Log.begin();

#ifndef TEST
  Serial2.begin(BAUD_RATE, SERIAL_8N1, RXD2, TXD2, true);
#endif

  debug("System initialised successfully!");

  blinkLed(5, 500);  // Blink 5 times to indicate end of setup
}

/***********************************
            Main Loop
 ***********************************/
void loop() {
  long now = millis();

  Log.loop();

  makeSureWiFiConnected(false);

  ArduinoOTA.handle();

  makeSureMqttConnected();
  mqttClient.loop();
 
  // Check if we want a full update of all the data including the unchanged data.
  if (now - LAST_FULL_UPDATE_SENT > UPDATE_FULL_INTERVAL) {
    for (int i = 0; i < telegramObjects.size(); i++) {
      telegramObjects[i].sendData = true;
      LAST_FULL_UPDATE_SENT = millis();
    }
  }

  if (now - LAST_UPDATE_SENT > UPDATE_INTERVAL) {
#ifdef TEST
    if (readTestSerial()) {
#else
    if (readP1Serial()) {
#endif
      LAST_UPDATE_SENT = millis();
      sendDataToBroker();
    }
  }
}

/***********************************
            Setup Methods
 ***********************************/
/**
   Over the Air update setup
*/
void setupOTA() {
  ArduinoOTA.onStart([]() {
              String type;
              if (ArduinoOTA.getCommand() == U_FLASH)
                type = "sketch";
              else  // U_SPIFFS
                type = "filesystem";

              // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
              Log.println("Start updating " + type);
            })
    .onEnd([]() {
      Log.println("\nEnd");
    })
    .onProgress([](unsigned int progress, unsigned int total) {
      Log.printf("Progress: %u%%\r", (progress / (total / 100)));
    })
    .onError([](ota_error_t error) {
      Log.printf("Error[%u]: ", error);
      if (error == OTA_AUTH_ERROR)
        Log.println("Auth Failed");
      else if (error == OTA_BEGIN_ERROR)
        Log.println("Begin Failed");
      else if (error == OTA_CONNECT_ERROR)
        Log.println("Connect Failed");
      else if (error == OTA_RECEIVE_ERROR)
        Log.println("Receive Failed");
      else if (error == OTA_END_ERROR)
        Log.println("End Failed");
    });
  ArduinoOTA.setHostname(String(HOSTNAME).c_str());
  ArduinoOTA.setPasswordHash(String(OTA_PASSWORD_HASH).c_str());
  ArduinoOTA.begin();
}