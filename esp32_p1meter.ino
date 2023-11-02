#include <ArduinoOTA.h>
#include <PubSubClient.h>
#include <WiFi.h>
#include <ESPmDNS.h>
#include <EMailSender.h>
#include <ArduinoJson.h>

#include "settings.h"
#include "dsmr_map.h"

WiFiClient espClient;
PubSubClient mqttClient(espClient);

EMailSender emailSend(EMAIL_ADDRESS, EMAIL_PASSWORD);

/***********************************
            Main Setup
 ***********************************/
void setup() {
  Serial.begin(BAUD_RATE);
 
  // Initialize pins
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

#ifdef DEBUG
  // Blinking 2 times fast and 2 slower to indicate DEBUG mode
  Serial.println("Booting - DEBUG mode on");
  blinkLed(2, 500);
  blinkLed(2, 2000);
#endif

  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  makeSureWiFiConnected();

  MDNS.begin(String(HOSTNAME).c_str());
  delay(1000);
  Serial.println("mDNS responder started");

  setupDataReadout();
  setupOTA();

  mqttClient.setServer(MQTT_HOST, atoi(MQTT_PORT));
  makeSureMqttConnected();

  Serial2.begin(BAUD_RATE, SERIAL_8N1, RXD2, TXD2, true);
  delay(1000);
  if (!Serial2.available()) {
    Serial2.end();
  }

  sendEmailMessage(String(HOSTNAME) + " message", "System initialised successfully!");

#ifdef DEBUG
  Serial.println("Ready");//
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
#endif
  blinkLed(5, 500);  // Blink 5 times to indicate end of setup
}

/***********************************
            Main Loop
 ***********************************/
void loop() {
  long now = millis();

  makeSureWiFiConnected();

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
    if (readP1Serial()) {
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
  ArduinoOTA.setHostname(String(HOSTNAME).c_str());
  ArduinoOTA.onStart([]() {
              String type;
              if (ArduinoOTA.getCommand() == U_FLASH)
                type = "sketch";
              else  // U_SPIFFS
                type = "filesystem";

              // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
              Serial.println("Start updating " + type);
            })
    .onEnd([]() {
      Serial.println("\nEnd");
    })
    .onProgress([](unsigned int progress, unsigned int total) {
      Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
    })
    .onError([](ota_error_t error) {
      Serial.printf("Error[%u]: ", error);
      if (error == OTA_AUTH_ERROR)
        Serial.println("Auth Failed");
      else if (error == OTA_BEGIN_ERROR)
        Serial.println("Begin Failed");
      else if (error == OTA_CONNECT_ERROR)
        Serial.println("Connect Failed");
      else if (error == OTA_RECEIVE_ERROR)
        Serial.println("Receive Failed");
      else if (error == OTA_END_ERROR)
        Serial.println("End Failed");
    });

  ArduinoOTA.begin();
}
