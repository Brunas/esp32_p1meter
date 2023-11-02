void sendMQTTMessage(const char *topic, const char *payload) {
  bool result = mqttClient.publish(topic, payload, false);
}

void makeSureMqttConnected() {
  uint _retries = MQTT_MAX_RECONNECT_TRIES;

  while (!mqttClient.connected() && _retries > 0) {
    if (mqttClient.connect(String(HOSTNAME).c_str(), MQTT_USER, MQTT_PASS)) {
      char *message = new char[16 + strlen(HOSTNAME) + 1];
      strcpy(message, "p1 meter alive: ");
      strcat(message, HOSTNAME);
      mqttClient.publish("hass/status", message);
    }
    else {
#ifdef DEBUG
      Serial.print("MQTT Connection Failed! Retries left: ");
      Serial.println(_retries);
#endif
      _retries--;
      delay(5000);
    }
  }

  if (!mqttClient.connected()) {
    blinkLed(20, 200); // Blink moderately fast to indicate failed connection
#ifdef DEBUG
    Serial.println("Connection to MQTT Failed! Rebooting...");
#endif
    ESP.restart();
  }
}

void sendMetric(String name, String metric) {
  String topic = String(MQTT_ROOT_TOPIC) + "/" + name;
#ifdef DEBUG
  Serial.println(topic);
#endif
  sendMQTTMessage(topic.c_str(), metric.c_str());
}

void sendDataToBroker() {
  for (int i = 0; i < telegramObjects.size(); i++) {
#ifdef DEBUG
    Serial.println((String) "Sending: " + telegramObjects[i].name + " value: " + telegramObjects[i].value);
#endif
    if (telegramObjects[i].sendData) {
      sendMetric(telegramObjects[i].name, telegramObjects[i].value);
      telegramObjects[i].sendData = false;
    }
  }
}
