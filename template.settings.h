// Top controlling defines
// Uncomment for debugging
//#define DEBUG
// Uncomment for debug messages sent to mqtt
//#define MQTT_DEBUGGING
// Uncomment for testing
//#define TEST

// Main settings
#define HOSTNAME "p1_meter"
#define OTA_PASSWORD_HASH "MD5 hash of my password"

// WiFi settings
#define WIFI_SSID "MyWifi"
#define WIFI_PASS "MyWifiPassword"
// Comment out below define if you think WiFi connection is stable with any other power saving settings
#define TURN_OFF_WIFI_PS
#define WIFI_MAX_RECONNECT_TRIES 5

#define BAUD_RATE 115200
#define RXD2 16
#define TXD2 17

// Change LED_PIN definition to actual setup
//#define LED_PIN LED_BUILTIN
#define LED_PIN 32

// MQTT related settings
#define MQTT_HOST "homeassistant.local"
#define MQTT_PORT "1883"
#define MQTT_USER "mqtt"
#define MQTT_PASS "mqttpass"

#define MQTT_MAX_RECONNECT_TRIES 10
#define MQTT_ROOT_TOPIC "p1_meter/sensor"
#define MQTT_STATUS_TOPIC "p1_meter/status"
// Uncomment to restart ESP on MQTT errors. 
// Be mindfull because this can make device unreachable if settings are wrong - restarting might cause infinite loop
// Uncomment only when MQTT settings are correct and server is reachable.
//#define MQTT_RESTART_ON_ERROR

#ifdef MQTT_DEBUGGING
#define MQTT_DEBUG_TOPIC "p1_meter/debug"
#endif

// Schedule of reading telegrams
// Update treshold in milliseconds, messages will only be sent on this interval
//#define UPDATE_INTERVAL 1000 // 1 second
//#define UPDATE_INTERVAL 30000 // 30 seconds
#define UPDATE_INTERVAL 60000  // 1 minute
//#define UPDATE_INTERVAL 300000 // 5 minutes

// Schedule of forced full telegram readout
// Update treshold in milliseconds,
// this will also send values that are more than the tresholds time the same
#define UPDATE_FULL_INTERVAL 600000 // 10 minutes
// #define UPDATE_FULL_INTERVAL 1800000 // 30 minutes
// #define UPDATE_FULL_INTERVAL 3600000 // 1 Hour

// Specify CPU frequenxy in MHz to reduce power usage
// 0, if frequency should be handled automatically using ArduinoIDE and board settings
// CAUTION: please make sure your CPU can handle frequency!
#define CPU_FREQ 80

// if your P1 values with units need to be multiplied by any multiplier, specify it here
#define VALUE_NUMERIC_MULTIPLIER 1

// Decimal places for float values, by default it's 2
// Integers are handled automatically and no decimals are used
#define VALUE_FLOAT_DECIMAL_PLACES 3

#define VALUE_START_CHAR '('
#define VALUE_END_CHAR '*'
#define VALUE_NO_UNITS_END_CHAR ')'
#define NA "N/A"

#define P1_MAXLINELENGTH 1100

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
