/*
  The main readout JSON file. Adopt it for your needs. Items can be removed from it.
  OBIS represents code and Name is name of MQTT topic.
  The code for finding this in the telegram see
    https://www.eso.lt/download/523006/p1%20s%C4%85sajos%20duomen%C5%B3%20modelis.pdf
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
    "OBIS": "1-0:3.8.0",
    "Name": "reactive_energy_import"
  },
  {
    "OBIS": "1-0:4.8.0",
    "Name": "reactive_energy_export"
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
    "OBIS": "1-0:2.8.1",
    "Name": "active_energy_export_rate_1"
  },
  {
    "OBIS": "1-0:2.8.2",
    "Name": "active_energy_export_rate_2"
  },
  {
    "OBIS": "1-0:3.8.1",
    "Name": "reactive_energy_rate_1"
  },
  {
    "OBIS": "1-0:3.8.2",
    "Name": "reactive_energy_rate_2"
  },
  {
    "OBIS": "1-0:4.8.1",
    "Name": "reactive_energy_minusr_rate_1"
  },
  {
    "OBIS": "1-0:4.8.2",
    "Name": "reactive_energy_minusr_rate_2"
  },
  {
    "OBIS": "1-0:32.7.0",
    "Name": "instantaneous_voltage_l1"
  },
  {
    "OBIS": "1-0:32.24.0",
    "Name": "average_voltage_l1"
  },
  {
    "OBIS": "1-0:31.7.0",
    "Name": "instantaneous_current_l1"
  },
  {
    "OBIS": "1-0:31.4.0",
    "Name": "sliding_average_current_l1"
  },
  {
    "OBIS": "1-0:52.7.0",
    "Name": "instantaneous_voltage_l2"
  },
  {
    "OBIS": "1-0:52.24.0",
    "Name": "average_voltage_l2"
  },
  {
    "OBIS": "1-0:51.7.0",
    "Name": "instantaneous_current_l2"
  },
  {
    "OBIS": "1-0:51.4.0",
    "Name": "sliding_average_current_l2"
  },
  {
    "OBIS": "1-0:72.7.0",
    "Name": "instantaneous_voltage_l3"
  },
  {
    "OBIS": "1-0:72.24.0",
    "Name": "average_voltage_l3"
  },
  {
    "OBIS": "1-0:71.7.0",
    "Name": "instantaneous_current_l3"
  },
  {
    "OBIS": "1-0:71.4.0",
    "Name": "sliding_average_current_l3"
  },
  {
    "OBIS": "1-0:12.7.0",
    "Name": "instantaneous_voltage"
  },
  {
    "OBIS": "1-0:11.7.0",
    "Name": "instantaneous_current"
  },
  {
    "OBIS": "1-0:91.7.0",
    "Name": "instantaneous_current_in_neutral"
  },
  {
    "OBIS": "1-0:90.7.0",
    "Name": "instantaneous_current_sum_over_all_phases"
  },
  {
    "OBIS": "1-0:14.7.0",
    "Name": "instantaneous_net_frequency_any_phase"
  },
  {
    "OBIS": "1-0:15.7.0",
    "Name": "instantaneous_active_power"
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
    "OBIS": "1-0:9.7.0",
    "Name": "instantaneous_apparent_import_power"
  },
  {
    "OBIS": "1-0:29.7.0",
    "Name": "instantaneous_apparent_import_power_in_phase_l1"
  },
  {
    "OBIS": "1-0:49.7.0",
    "Name": "instantaneous_apparent_import_power_in_phase_l2"
  },
  {
    "OBIS": "1-0:69.7.0",
    "Name": "instantaneous_apparent_import_power_in_phase_l3"
  },
  {
    "OBIS": "1-0:10.7.0",
    "Name": "instantaneous_apparent_export_power"
  },
  {
    "OBIS": "1-0:30.7.0",
    "Name": "instantaneous_apparent_export_power_in_phase_l1"
  },
  {
    "OBIS": "1-0:50.7.0",
    "Name": "instantaneous_apparent_export_power_in_phase_l2"
  },
  {
    "OBIS": "1-0:70.7.0",
    "Name": "instantaneous_apparent_export_power_in_phase_l3"
  },
  {
    "OBIS": "1-0:1.24.0",
    "Name": "average_import_power"
  },
  {
    "OBIS": "1-0:16.24.0",
    "Name": "average_net_power"
  },
  {
    "OBIS": "1-0:15.24.0",
    "Name": "average_total_power"
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
    "OBIS": "1-0:13.3.0",
    "Name": "minimum_power_factor"
  },
  {
    "OBIS": "1-0:1.4.0",
    "Name": "demand_register_1_active_energy_import"
  },
  {
    "OBIS": "1-0:2.4.0",
    "Name": "demand_register_2_active_energy_export"
  },
  {
    "OBIS": "1-0:3.4.0",
    "Name": "demand_register_3_reactive_energy_import"
  },
  {
    "OBIS": "1-0:4.4.0",
    "Name": "demand_register_4_reactive_energy_export"
  },
  {
    "OBIS": "1-0:9.4.0",
    "Name": "demand_register_5_apparent_energy_import"
  },
  {
    "OBIS": "1-0:10.4.0",
    "Name": "demand_register_6_apparent_energy_export"
  },
  {
    "OBIS": "1-0:1.5.0",
    "Name": "last_average_demand_register_1_active_energy_import"
  },
  {
    "OBIS": "1-0:2.5.0",
    "Name": "last_average_demand_register_2_active_energy_export"
  },
  {
    "OBIS": "1-0:3.5.0",
    "Name": "last_average_demand_register_3_reactive_energy_import"
  },
  {
    "OBIS": "1-0:4.5.0",
    "Name": "last_average_demand_register_4_reactive_energy_export"
  },
  {
    "OBIS": "1-0:9.5.0",
    "Name": "last_average_demand_register_5_apparent_energy_import"
  },
  {
    "OBIS": "1-0:10.5.0",
    "Name": "last_average_demand_register_6_apparent_energy_export"
  },
  {
    "OBIS": "0-0:96.7.21",
    "Name": "number_of_power_failures_in_any_phase"
  },
  {
    "OBIS": "1-0:32.33.0",
    "Name": "duration_of_last_voltage_sag_in_phase_l1"
  },
  {
    "OBIS": "1-0:52.33.0",
    "Name": "duration_of_last_voltage_sag_in_phase_l2"
  },
  {
    "OBIS": "1-0:72.33.0",
    "Name": "duration_of_last_voltage_sag_in_phase_l3"
  },
  {
    "OBIS": "1-0:32.34.0",
    "Name": "magnitude_of_last_voltage_sag_in_phase_l1"
  },
  {
    "OBIS": "1-0:52.34.0",
    "Name": "magnitude_of_last_voltage_sag_in_phase_l2"
  },
  {
    "OBIS": "1-0:72.34.0",
    "Name": "magnitude_of_last_voltage_sag_in_phase_l3"
  },
  {
    "OBIS": "1-0:32.37.0",
    "Name": "duration_of_last_voltage_swell_in_phase_l1"
  },
  {
    "OBIS": "1-0:52.37.0",
    "Name": "duration_of_last_voltage_swell_in_phase_l2"
  },
  {
    "OBIS": "1-0:72.37.0",
    "Name": "duration_of_last_voltage_swell_in_phase_l3"
  },
  {
    "OBIS": "1-0:32.38.0",
    "Name": "magnitude_of_last_voltage_swell_in_phase_l1"
  },
  {
    "OBIS": "1-0:52.38.0",
    "Name": "magnitude_of_last_voltage_swell_in_phase_l2"
  },
  {
    "OBIS": "1-0:72.38.0",
    "Name": "magnitude_of_last_voltage_swell_in_phase_l3"
  }
]
)"""";

/*
  Removed irrelavant readings (missing rate 3-4 related and meter firmware)
  {
    "OBIS": "1-0:1.8.3",
    "Name": "active_energy_import_rate_3"
  },
  {
    "OBIS": "1-0:1.8.4",
    "Name": "active_energy_import_rate_4"
  },
  {
    "OBIS": "1-0:2.8.3",
    "Name": "active_energy_export_rate_3"
  },
  {
    "OBIS": "1-0:2.8.4",
    "Name": "active_energy_export_rate_4"
  },
  {
    "OBIS": "1-0:3.8.3",
    "Name": "reactive_energy_rate_3"
  },
  {
    "OBIS": "1-0:3.8.4",
    "Name": "reactive_energy_rate_4"
  },
  {
    "OBIS": "1-0:4.8.3",
    "Name": "reactive_energy_minusr_rate_3"
  },
  {
    "OBIS": "1-0:4.8.4",
    "Name": "reactive_energy_minusr_rate_4"
  },
  {
    "OBIS": "1-0:0.2.0",
    "Name": "active_firmware_identifier"
  },
  {
    "OBIS": "1-0:0.2.8",
    "Name": "active_firmware_signature"
  },
  {
    "OBIS": "1-1:0.2.0",
    "Name": "active_firmware_identifier_1"
  },
  {
    "OBIS": "1-1:0.2.8",
    "Name": "active_firmware_signature_1"
  }

*/