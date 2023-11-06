# esp32_p1meter
Software for the ESP32 (uPesy ESP32 Wroom Devkit) that decodes and sends P1 smart meter (DSMR) data to a MQTT broker, with the possibility for Over The Air (OTA) firmware updates.

## About this fork
This fork is based on work from [bartwo](https://github.com/bartwo/esp32_p1meter).

How is this form different from base:
- Make MQTT sensors configured using JSON map with all available data and get MQTT sensors created dynamically.
- Add email sending for debugging purposes.
- Even more refactored code for readability. 

## Setup
This setup requires:
- An ESP32 (I have used [ESP32-WROOM-32U](https://www.aliexpress.com/item/32864722159.html?spm=a2g0o.order_detail.order_detail_item.9.221ff19cMYLPDE) because of external antenna - my meter is in metal case ~15m outside from the access point)
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
I have used the RX02 pin on the ESP32 so u can still use the USB port for debugging you ESP32.
Connect the ESP32 to an RJ11 cable/connector following the diagram.

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

All metrics are send to their own MQTT topic.
The software generates all the topic through the Serial monitor when starting up
Example topics are:

```
sensors/power/p1meter/consumption_low_tarif
sensors/power/p1meter/consumption_high_tarif
sensors/power/p1meter/actual_received
sensors/power/p1meter/instant_power_usage_l1
sensors/power/p1meter/instant_power_usage_l2
sensors/power/p1meter/instant_power_usage_l3
sensors/power/p1meter/instant_power_current_l1
sensors/power/p1meter/instant_power_current_l2
sensors/power/p1meter/instant_power_current_l3
sensors/power/p1meter/instant_voltage_l1
sensors/power/p1meter/instant_voltage_l2
sensors/power/p1meter/instant_voltage_l3
sensors/power/p1meter/actual_tarif_group
sensors/power/p1meter/short_power_outages
sensors/power/p1meter/long_power_outages
sensors/power/p1meter/short_power_drops
sensors/power/p1meter/short_power_peaks
```

But all the metrics you need are easily added in JSON map `dsmr_map.h` file. With the DEBUG mode it is easy to see all the topics you add/create by the serial monitor.

### Home Assistant Configuration

Use this [example](https://raw.githubusercontent.com/daniel-jong/esp8266_p1meter/master/assets/p1_sensors.yaml) for home assistant's `sensor.yaml`
