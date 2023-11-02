#include <tiny-collections.h>

#define DEBUG
// Update treshold in milliseconds, messages will only be sent on this interval
//#define UPDATE_INTERVAL 1000 // 1 second
//#define UPDATE_INTERVAL 10000 // 10 seconds
#define UPDATE_INTERVAL 60000  // 1 minute
//#define UPDATE_INTERVAL 300000 // 5 minutes

// Update treshold in milliseconds,
// this will also send values that are more than the tresholds time the same
#define UPDATE_FULL_INTERVAL 600000 // 10 minutes
// #define UPDATE_FULL_INTERVAL 1800000 // 30 minutes
// #define UPDATE_FULL_INTERVAL 3600000 // 1 Hour

#define NA "N/A"

#define HOSTNAME "p1_meter"
#define OTA_PASSWORD "12345"

#define BAUD_RATE 115200
#define RXD2 RX
#define TXD2 TX

//default
//#define LED_PIN LED_BUILTIN
#define LED_PIN MISO

#define P1_MAXLINELENGTH 1050

#define MQTT_MAX_RECONNECT_TRIES 10
#define MQTT_ROOT_TOPIC "sensor"

#define WIFI_MAX_RECONNECT_TRIES 5

long LAST_UPDATE_SENT = 0;
long LAST_FULL_UPDATE_SENT = 0;

char WIFI_SSID[32] = "MyWifi";
char WIFI_PASS[32] = "MyPsw";

char MQTT_HOST[64] = "homeassistant.local";
char MQTT_PORT[6] = "1883";
char MQTT_USER[32] = "user";
char MQTT_PASS[32] = "pass";

char EMAIL_ADDRESS[32] = "myemail@gmail.com";
char EMAIL_PASSWORD[32] = "mygmailapppass";

char telegram[P1_MAXLINELENGTH];

const char VALUE_START_CHAR = '(';
const char VALUE_END_CHAR = '*';
const char VALUE_NO_UNITS_END_CHAR = ')';

struct TelegramDecodedObject
{
  String name;
  String value;
  char code[16];
  bool sendData = true;
};

tc::vector<struct TelegramDecodedObject> telegramObjects;

unsigned int currentCRC = 0;



