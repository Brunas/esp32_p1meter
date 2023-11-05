/**
  setupDataReadout()

  This method reads JSON string specified in DsmrMap variable in dsmr_map.h file 
    and converts to telegramDecodedObjects MQTT vector.
*/
void setupDataReadout() {
  DynamicJsonDocument _dsmrMapDocument(DYNAMIC_JSON_DOCUMENT_SIZE);
  DeserializationError _error = deserializeJson(_dsmrMapDocument, DSMR_MAP);
  if (_error) {
    Serial.print("deserializeJson() failed: ");
    Serial.println(_error.c_str());
    return;
  }

  // Create TelegramObject vector which will be used to send MQTT messages
  const uint _count = _dsmrMapDocument.as<JsonArray>().size();
  for (int i = 0; i < _count; i++) {
    TelegramDecodedObject _tdo;
    strcpy(_tdo.code, _dsmrMapDocument.as<JsonArray>()[i]["OBIS"]);
    _tdo.name = _dsmrMapDocument.as<JsonArray>()[i]["Name"].as<String>();

    telegramObjects.push_back(_tdo);
  }

#ifdef DEBUG
  Serial.println("MQTT Topics initialized (" + String(_count) + "):");
  for (int i = 0; i < _count; i++) {
    Serial.println(String(MQTT_ROOT_TOPIC) + "/" + telegramObjects[i].name);
  }
#endif
}