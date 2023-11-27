# esp32_p1meter
Software for the ESP32 (uPesy ESP32 Wroom Devkit) that decodes and sends P1 smart meter (DSMR) data to a MQTT broker, with the possibility for Over The Air (OTA) firmware updates.

## About this fork
This fork is based on work from [bartwo](https://github.com/bartwo/esp32_p1meter).

How is this fork different from base:
- Make MQTT sensors configured using JSON map with all available data and get MQTT sensors created dynamically.
- Add email sending for debugging purposes.
- Added support for string readings not just numbers.
- Even more refactored code for readability.

## Setup
This setup requires:
- An ESP32 (I have used [ESP32-WROOM-32U](https://www.aliexpress.com/item/32864722159.html) because of external antenna - my meter is in metal case ~15m outside from the access point with thick wall)
- IPEX-SMA cable of appropriate length to have antenna outside and put it through some hole in the meter metal case. For me 50cm length is more than enough. 
- A 10k ohm resistor.
- A simple LED for debugging and appropriate resistor for it for more information read [here](https://kitronik.co.uk/blogs/resources/which-resistor-should-i-use-with-my-led).
- A 6 pin RJ12 cable created from UTP cable and soldered directly to the kit. 4 pin version should work too but in Lithuania it's hard to have external power for the device in the meter box.

Setting up your Arduino IDE:
- Ensure you have selected the right board (you might need to install your esp32board in the Arduino IDE).
- I have tested this on the 240 MHz and 160 MHz CPU frequency mode, pick either one.
- Using the Tools->Manage Libraries... install `PubSubClient`, `ArduinoJson` and `tiny-collections`. For email debugging install `EmailSender` library.
- In the file `Settings.h` change all values accordingly
- Write to your device via USB the first time, you can do it OTA all times thereafter.

### Circuit diagram
I have used the RX02 pin on the ESP32 to still use the USB port on devkit for debugging your ESP32. You could use any other pin however if you use standard RX and try debugging using USB, conflicts will happen. 
Connect the ESP32 to an RJ12 cable/connector following the diagram.

| P1 pin   | ESP32 Pin |
| ----     | ---- |
| 1 - 5v out | 5v or Vin |
| 2 - RTS  | 3.3v |
| 3 - GND  | GND  |
| 4 -      |      |
| 5 - RXD (data) | RX02 (gpio16) |
| 6 - GND  | GND  |

On most models a 10K resistor should be used between the ESP's 3.3v and the P1's DATA (RXD) pin. Many howto's mention RTS requires 5V (VIN) to activate the P1 port, but for me 3V3 suffices.

<details><summary>Optional: Simpler 4 pin cable without power from your DSMR5+ meter</summary>
<p>
If you have how to power ESP32, a 4 pin cable is OK.

| P1 pin   | ESP32 Pin |
| ----     | ---- |
| 2 - RTS  | 3.3v |
| 3 - GND  | GND  |
| 4 -      |      |
| 5 - RXD (data) | RX02 (gpio16) |
  
</p>
</details>

### Data Sent

All metrics are send to their own MQTT topic. The software outputs all the topics through the Serial monitor when starting up
Example:

```
p1_meter/sensor/active_energy_import
```

All the metrics you need are easily added in `DSMR_MAP` variable in `dsmr_map.h` file. With the DEBUG mode it's possible to see all the topics you add/create in the serial monitor. Also, it's possible to configure topic structure by changing `MQTT_ROOT_TOPIC` value in `settings.h` file.
There is additional TEST mode to try your setup with test telegram and actual MQTT message send while your adapter is not connected to P1 port. 
EMAIL_DEBUGGING is used to send debug messages to any email, e.g. GMail address. This is might be usefull to trace what's going on when device is connected to P1 port and actual debugging using USB port is impossible.
### Home Assistant Configuration

Use this [example](https://raw.githubusercontent.com/daniel-jong/esp8266_p1meter/master/assets/p1_sensors.yaml) for home assistant's `sensor.yaml`
