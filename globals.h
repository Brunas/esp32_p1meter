// Nothing to change below - globals to make it all work as simple as possible
char telegram[P1_MAXLINELENGTH];

long LAST_UPDATE_SENT = 0;
long LAST_FULL_UPDATE_SENT = 0;

struct TelegramDecodedObject
{
  String name;
  String value;
  char code[16];
  bool sendData = true;
};

tc::vector<struct TelegramDecodedObject> telegramObjects;

unsigned int currentCRC = 0;

WiFiClient espClient;
PubSubClient mqttClient(espClient);
