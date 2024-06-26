# esp32_p1meter
Software for the ESP32 (uPesy ESP32 Wroom Devkit) that decodes and sends P1 smart meter (DSMR) data to a MQTT broker, with the possibility for Over The Air (OTA) firmware updates.

## About this fork
This fork is based on work from [bartwo](https://github.com/bartwo/esp32_p1meter).

How is this fork different from base:
- Make MQTT sensors configured using JSON map with all available data and get MQTT sensors created dynamically.
- Added support for string readings not just numbers.
- Added logging.
- Even more refactored code for readability.

![P1 plugged into meter with external antenna](assets/3.jpg)

## Setup
This setup requires:
- An ESP32 (I have used [ESP32-WROOM-32U](https://www.aliexpress.com/item/32864722159.html) because of external antenna - my meter is in metal case ~15m outside from the access point with thick wall)
- IPEX-SMA cable of appropriate length to have antenna outside and put it through some hole in the meter metal case. For me 50cm length is more than enough. 
- A 10k ohm resistor.
- A simple LED for debugging and appropriate resistor for it for more information read [here](https://kitronik.co.uk/blogs/resources/which-resistor-should-i-use-with-my-led).
- A 6 pin RJ11 cable created from UTP cable and soldered directly to the kit. 4 pin version should work too but in Lithuania it's hard to have external power for the device in the meter box.

Setting up your Arduino IDE:
- Ensure you have selected the right board (you might need to install your esp32board in the Arduino IDE).
- Using the Tools->Manage Libraries... install `PubSubClient`, `ArduinoJson`, and `tiny-collections`.
- I have tested this on the 240 MHz and 160 MHz CPU frequency mode, pick either one. It has worked but not for long 😁. I've added `CPU_FREQ` constant to set CPU frequency to as low value as your board supports to assign more power from P1 port to the most important WiFi connection. In my case it's 80 MHz. It has been working well since the change due to no heavy calculations in the code.
- I have also added `TURN_OFF_WIFI_PS` define disabled WiFi power saving by executing `esp_wifi_set_ps(WIFI_PS_NONE)`. Comment it out if you think WiFi connection will be stable.
- Copy file `template.settings.h` to `settings.h` and change values accordingly in it.
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

![Wiring ESP32 is instead of ESP8286](assets/esp8266_p1meter_bb_PoweredByMeter.png)
>**_NOTE:_**  The diagram says `D1 mini` but all of this can be applied to ESP32 too.

On most models a 10K resistor should be used between the ESP's 3.3v and the P1's DATA (RXD) pin. Many howto's mention RTS requires 5V (VIN) to activate the P1 port, but for me 3V3 suffices.

![UTP cable with blue wires cut](assets/1.jpg)
![UTP cable to RJ11](assets/2.jpg)

<details><summary>Optional: Simpler 4 pin cable without power from your DSMR5+ meter</summary>
<p>
If you have how to power ESP32, a 4 pin cable is OK.

| P1 pin   | ESP32 Pin |
| ----     | ---- |
| 2 - RTS  | 3.3v |
| 3 - GND  | GND  |
| 4 -      |      |
| 5 - RXD (data) | RX02 (gpio16) |

![Wiring ESP32 is instead of ESP8286](assets/esp8266_p1meter_bb.png)
>**_NOTE:_**  The diagram says `D1 mini` but all of this can be applied to ESP32 too.

</p>
</details>

### Data Sent

All metrics are send to their own MQTT topic. The software outputs all the topics through the Serial monitor when starting up
Example:

```
p1_meter/sensor/clock
p1_meter/sensor/active_energy_import
p1_meter/sensor/active_energy_import_rate_1
p1_meter/sensor/active_energy_import_rate_2
p1_meter/sensor/active_energy_export
p1_meter/sensor/reactive_energy_import
p1_meter/sensor/reactive_energy_export
p1_meter/sensor/instantaneous_active_import_power
p1_meter/sensor/instantaneous_active_export_power
p1_meter/sensor/instantaneous_reactive_import_power
p1_meter/sensor/instantaneous_reactive_export_power
p1_meter/sensor/instantaneous_active_import_power_in_phase_l1
p1_meter/sensor/instantaneous_active_import_power_in_phase_l2
p1_meter/sensor/instantaneous_active_import_power_in_phase_l3
p1_meter/sensor/instantaneous_active_export_power_in_phase_l1
p1_meter/sensor/instantaneous_active_export_power_in_phase_l2
p1_meter/sensor/instantaneous_active_export_power_in_phase_l3
p1_meter/sensor/instantaneous_reactive_import_power_in_phase_l1
p1_meter/sensor/instantaneous_reactive_import_power_in_phase_l2
p1_meter/sensor/instantaneous_reactive_import_power_in_phase_l3
p1_meter/sensor/instantaneous_reactive_export_power_in_phase_l1
p1_meter/sensor/instantaneous_reactive_export_power_in_phase_l2
p1_meter/sensor/instantaneous_reactive_export_power_in_phase_l3
p1_meter/sensor/instantaneous_voltage_l1
p1_meter/sensor/instantaneous_current_l1
p1_meter/sensor/instantaneous_voltage_l2
p1_meter/sensor/instantaneous_current_l2
p1_meter/sensor/instantaneous_voltage_l3
p1_meter/sensor/instantaneous_current_l3
p1_meter/sensor/instantaneous_net_frequency_any_phase
p1_meter/sensor/instantaneous_power_factor
p1_meter/sensor/instantaneous_power_factor_in_phase_l1
p1_meter/sensor/instantaneous_power_factor_in_phase_l2
p1_meter/sensor/instantaneous_power_factor_in_phase_l3
p1_meter/sensor/number_of_power_failures_in_any_phase
p1_meter/sensor/consumer_message_text
p1_meter/sensor/number_of_voltage_sags_in_phase_l1
p1_meter/sensor/number_of_voltage_sags_in_phase_l2
p1_meter/sensor/number_of_voltage_sags_in_phase_l3
p1_meter/sensor/number_of_voltage_swells_in_phase_l1
p1_meter/sensor/number_of_voltage_swells_in_phase_l2
p1_meter/sensor/number_of_voltage_swells_in_phase_l3
p1_meter/sensor/equipment_identifier
```

All the metrics you need are easily added in `DSMR_MAP` variable in `dsmr_map.h` file. With the `DEBUG` mode it's possible to see all the topics you add/create in the serial monitor. Also, it's possible to configure topic structure by changing `MQTT_ROOT_TOPIC` value in `settings.h` file.
There is additional `TEST` mode to try your setup with test telegram and actual MQTT message send while your adapter is not connected to P1 port.
Additionally, I've implemented `MQTT_DEBUGGING` mode to allow sending debug messages to MQTT topic defined by `MQTT_DEBUG_TOPIC`.

### Home Assistant Configuration

Use this [example](assets/mqtt.yaml) for home assistant's `mqtt.yaml` which must be included in main `configuration.yaml` as follows:
```yaml
mqtt: !include mqtt.yaml
```
