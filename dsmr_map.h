/*
  The main readout JSON file. Adopt it for your needs. Items can be removed from it.
  OBIS represents code and Name is name of MQTT topic.
  The code for finding this in the telegram see
    https://www.eso.lt/download/523006/p1%20s%C4%85sajos%20duomen%C5%B3%20modelis.pdf

  UPDATE 2024-05: Lithuanian ESO has introduced standard, extended and maximum plans with
  appropriately assigned readouts. Below is the list for extended plan according to ESO best 
  suited for solar plant owners. Here is the link to readout-plan assignment 
    https://www.eso.lt/download/585550/p1%20duomenu%20modelis_v2.xlsx
*/
const char* DSMR_MAP = R""""(
[
  {
    "OBIS": "0-0:1.0.0",
    "Name": "clock"
  },
  {
    "OBIS": "1-0:1.8.0",
    "Name": "active_energy_import"
  },
  {
    "OBIS": "1-0:1.8.1",
    "Name": "active_energy_import_rate_1"
  },
  {
    "OBIS": "1-0:1.8.2",
    "Name": "active_energy_import_rate_2"
  },
  {
    "OBIS": "1-0:2.8.0",
    "Name": "active_energy_export"
  },
  {
    "OBIS": "1-0:3.8.0",
    "Name": "reactive_energy_import"
  },
  {
    "OBIS": "1-0:4.8.0",
    "Name": "reactive_energy_export"
  },
  {
    "OBIS": "1-0:1.7.0",
    "Name": "instantaneous_active_import_power"
  },
  {
    "OBIS": "1-0:2.7.0",
    "Name": "instantaneous_active_export_power"
  },
  {
    "OBIS": "1-0:3.7.0",
    "Name": "instantaneous_reactive_import_power"
  },
  {
    "OBIS": "1-0:4.7.0",
    "Name": "instantaneous_reactive_export_power"
  },
  {
    "OBIS": "1-0:21.7.0",
    "Name": "instantaneous_active_import_power_in_phase_l1"
  },
  {
    "OBIS": "1-0:41.7.0",
    "Name": "instantaneous_active_import_power_in_phase_l2"
  },
  {
    "OBIS": "1-0:61.7.0",
    "Name": "instantaneous_active_import_power_in_phase_l3"
  },
  {
    "OBIS": "1-0:22.7.0",
    "Name": "instantaneous_active_export_power_in_phase_l1"
  },
  {
    "OBIS": "1-0:42.7.0",
    "Name": "instantaneous_active_export_power_in_phase_l2"
  },
  {
    "OBIS": "1-0:62.7.0",
    "Name": "instantaneous_active_export_power_in_phase_l3"
  },
  {
    "OBIS": "1-0:23.7.0",
    "Name": "instantaneous_reactive_import_power_in_phase_l1"
  },
  {
    "OBIS": "1-0:43.7.0",
    "Name": "instantaneous_reactive_import_power_in_phase_l2"
  },
  {
    "OBIS": "1-0:63.7.0",
    "Name": "instantaneous_reactive_import_power_in_phase_l3"
  },
  {
    "OBIS": "1-0:24.7.0",
    "Name": "instantaneous_reactive_export_power_in_phase_l1"
  },
  {
    "OBIS": "1-0:44.7.0",
    "Name": "instantaneous_reactive_export_power_in_phase_l2"
  },
  {
    "OBIS": "1-0:64.7.0",
    "Name": "instantaneous_reactive_export_power_in_phase_l3"
  },
  {
    "OBIS": "1-0:32.7.0",
    "Name": "instantaneous_voltage_l1"
  },
  {
    "OBIS": "1-0:31.7.0",
    "Name": "instantaneous_current_l1"
  },
  {
    "OBIS": "1-0:52.7.0",
    "Name": "instantaneous_voltage_l2"
  },
  {
    "OBIS": "1-0:51.7.0",
    "Name": "instantaneous_current_l2"
  },
  {
    "OBIS": "1-0:72.7.0",
    "Name": "instantaneous_voltage_l3"
  },
  {
    "OBIS": "1-0:71.7.0",
    "Name": "instantaneous_current_l3"
  },
  {
    "OBIS": "1-0:14.7.0",
    "Name": "instantaneous_net_frequency_any_phase"
  },
  {
    "OBIS": "1-0:13.7.0",
    "Name": "instantaneous_power_factor"
  },
  {
    "OBIS": "1-0:33.7.0",
    "Name": "instantaneous_power_factor_in_phase_l1"
  },
  {
    "OBIS": "1-0:53.7.0",
    "Name": "instantaneous_power_factor_in_phase_l2"
  },
  {
    "OBIS": "1-0:73.7.0",
    "Name": "instantaneous_power_factor_in_phase_l3"
  },
  {
    "OBIS": "0-0:96.7.21",
    "Name": "number_of_power_failures_in_any_phase"
  },
  {
    "OBIS": "0-0:96.13.0",
    "Name": "consumer_message_text"
  },
  {
    "OBIS": "1-0:32.32.0",
    "Name": "number_of_voltage_sags_in_phase_l1"
  },
  {
    "OBIS": "1-0:52.32.0",
    "Name": "number_of_voltage_sags_in_phase_l2"
  },
  {
    "OBIS": "1-0:72.32.0",
    "Name": "number_of_voltage_sags_in_phase_l3"
  },
  {
    "OBIS": "1-0:32.36.0",
    "Name": "number_of_voltage_swells_in_phase_l1"
  },
  {
    "OBIS": "1-0:52.36.0",
    "Name": "number_of_voltage_swells_in_phase_l2"
  },
  {
    "OBIS": "1-0:72.36.0",
    "Name": "number_of_voltage_swells_in_phase_l3"
  },
  {
    "OBIS": "0-0:96.1.1",
    "Name": "equipment_identifier"
  }
]
)"""";