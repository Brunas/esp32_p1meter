/**
  setupDataReadout()

  This method reads JSON string specified in DsmrMap variable in dsmr_map.h file 
    and converts to telegramDecodedObjects MQTT vector.
*/
void setupDataReadout() {
  //There is no point of usin Description - let's filter it out
  StaticJsonDocument<48> _filterDoc;
  JsonObject _filterObj = _filterDoc.createNestedObject();
  _filterObj["OBIS"] = true;
  _filterObj["Name"] = true;

  DynamicJsonDocument _dsmrMapDocument(13000);
  DeserializationError _error = deserializeJson(_dsmrMapDocument, DsmrMap, DeserializationOption::Filter(_filterDoc));
  if (_error) {
    Serial.print("deserializeJson() failed: ");
    Serial.println(_error.c_str());
    return;
  }

  // Convert JSON document to JSON array
  JsonArray _jsonArray = _dsmrMapDocument.as<JsonArray>();

  // Create TelegramObject vector which will be used to send MQTT messages
  const uint _count = _jsonArray.size();
  for (int i = 0; i < _count; i++) {
    JsonObject _item = _jsonArray[i];

    TelegramDecodedObject _tdo;
    strcpy(_tdo.code, _item["OBIS"]);
    _tdo.name = _item["Name"].as<String>();

    telegramObjects.push_back(_tdo);
  }

#ifdef DEBUG
  Serial.println("MQTT Topics initialized (" + String(_count) + "):");
  for (int i = 0; i < _count; i++) {
    Serial.println(String(MQTT_ROOT_TOPIC) + "/" + telegramObjects[i].name);
  }
#endif
}