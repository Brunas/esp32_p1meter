/*
  The main readout JSON file. Adopt it for your needs. Items can be removed from it.
  OBIS represents code and Name is name of MQTT topic. Description is optional.
  The code for finding this in the telegram see
    https://www.netbeheernederland.nl/_upload/Files/Slimme_meter_15_a727fce1f1.pdf for the dutch codes pag. 19 -23
    https://www.eso.lt/download/523006/p1%20s%C4%85sajos%20duomen%C5%B3%20modelis.pdf
*/
const String DsmrMap = R""""(
[{
    "OBIS": "0-0:1.0.0",
    "Name": "clock",
    "Description": "Clock"
  },
  {
    "OBIS": "1-0:1.8.0",
    "Name": "active_energy_import",
    "Description": "Active energy import (+A)"
  },
  {
    "OBIS": "1-0:3.8.0",
    "Name": "reactive_energy_import",
    "Description": "Reactive energy import (+R) (QI+QII)"
  },
  {
    "OBIS": "1-0:4.8.0",
    "Name": "reactive_energy_export",
    "Description": "Reactive energy export (-R) (QIII+QIV)"
  },
  {
    "OBIS": "1-0:1.8.1",
    "Name": "active_energy_import_rate_1",
    "Description": "Active energy import (+A) rate 1"
  },
  {
    "OBIS": "1-0:1.8.2",
    "Name": "active_energy_import_rate_2",
    "Description": "Active energy import (+A) rate 2"
  },
  {
    "OBIS": "1-0:1.8.3",
    "Name": "active_energy_import_rate_3",
    "Description": "Active energy import (+A) rate 3"
  },
  {
    "OBIS": "1-0:1.8.4",
    "Name": "active_energy_import_rate_4",
    "Description": "Active energy import (+A) rate 4"
  },
  {
    "OBIS": "1-0:2.8.1",
    "Name": "active_energy_export_rate_1",
    "Description": "Active energy export (−A) rate 1"
  },
  {
    "OBIS": "1-0:2.8.2",
    "Name": "active_energy_export_rate_2",
    "Description": "Active energy export (−A) rate 2"
  },
  {
    "OBIS": "1-0:2.8.3",
    "Name": "active_energy_export_rate_3",
    "Description": "Active energy export (−A) rate 3"
  },
  {
    "OBIS": "1-0:2.8.4",
    "Name": "active_energy_export_rate_4",
    "Description": "Active energy export (−A) rate 4"
  },
  {
    "OBIS": "1-0:3.8.1",
    "Name": "reactive_energy_rate_1",
    "Description": "Reactive energy (+R) rate 1"
  },
  {
    "OBIS": "1-0:3.8.2",
    "Name": "reactive_energy_rate_2",
    "Description": "Reactive energy (+R) rate 2"
  },
  {
    "OBIS": "1-0:3.8.3",
    "Name": "reactive_energy_rate_3",
    "Description": "Reactive energy (+R) rate 3"
  },
  {
    "OBIS": "1-0:3.8.4",
    "Name": "reactive_energy_rate_4",
    "Description": "Reactive energy (+R) rate 4"
  },
  {
    "OBIS": "1-0:4.8.1",
    "Name": "reactive_energy_rate_1",
    "Description": "Reactive energy (-R) rate 1"
  },
  {
    "OBIS": "1-0:4.8.2",
    "Name": "reactive_energy_rate_2",
    "Description": "Reactive energy (-R) rate 2"
  },
  {
    "OBIS": "1-0:4.8.3",
    "Name": "reactive_energy_rate_3",
    "Description": "Reactive energy (-R) rate 3"
  },
  {
    "OBIS": "1-0:4.8.4",
    "Name": "reactive_energy_rate_4",
    "Description": "Reactive energy (-R) rate 4"
  },
  {
    "OBIS": "1-0:32.7.0",
    "Name": "instantaneous_voltage_l1",
    "Description": "Instantaneous voltage L1"
  },
  {
    "OBIS": "1-0:32.24.0",
    "Name": "average_voltage_l1",
    "Description": "Average voltage L1"
  },
  {
    "OBIS": "1-0:31.7.0",
    "Name": "instantaneous_current_l1",
    "Description": "Instantaneous current L1"
  },
  {
    "OBIS": "1-0:31.4.0",
    "Name": "sliding_average_current_l1",
    "Description": "Sliding Average current L1 (for fuse supervision)"
  },
  {
    "OBIS": "1-0:52.7.0",
    "Name": "instantaneous_voltage_l2",
    "Description": "Instantaneous voltage L2"
  },
  {
    "OBIS": "1-0:52.24.0",
    "Name": "average_voltage_l2",
    "Description": "Average voltage L2"
  },
  {
    "OBIS": "1-0:51.7.0",
    "Name": "instantaneous_current_l2",
    "Description": "Instantaneous current L2"
  },
  {
    "OBIS": "1-0:51.4.0",
    "Name": "sliding_average_current_l2",
    "Description": "Sliding Average current L2 (for fuse supervision)"
  },
  {
    "OBIS": "1-0:72.7.0",
    "Name": "instantaneous_voltage_l3",
    "Description": "Instantaneous voltage L3"
  },
  {
    "OBIS": "1-0:72.24.0",
    "Name": "average_voltage_l3",
    "Description": "Average voltage L3"
  },
  {
    "OBIS": "1-0:71.7.0",
    "Name": "instantaneous_current_l3",
    "Description": "Instantaneous current L3"
  },
  {
    "OBIS": "1-0:71.4.0",
    "Name": "sliding_average_current_l3",
    "Description": "Sliding Average current L3 (for fuse supervision)"
  },
  {
    "OBIS": "1-0:12.7.0",
    "Name": "instantaneous_voltage",
    "Description": "Instantaneous voltage (U) [V]"
  },
  {
    "OBIS": "1-0:11.7.0",
    "Name": "instantaneous_current",
    "Description": "Instantaneous current [A]"
  },
  {
    "OBIS": "1-0:91.7.0",
    "Name": "instantaneous_current_in_neutral",
    "Description": "Instantaneous current in neutral [A]"
  },
  {
    "OBIS": "1-0:90.7.0",
    "Name": "instantaneous_current",
    "Description": "Instantaneous current (sum over all phases)"
  },
  {
    "OBIS": "1-0:14.7.0",
    "Name": "instantaneous_net_frequency_any_phase",
    "Description": "Instantaneous net frequency; any phase"
  },
  {
    "OBIS": "1-0:15.7.0",
    "Name": "instantaneous_active_power",
    "Description": "Instantaneous active power (|+A|+|-A|)"
  },
  {
    "OBIS": "1-0:21.7.0",
    "Name": "instantaneous_active_import_power_in_phase_l1",
    "Description": "Instantaneous active import power (+A) in phase L1 [kW]"
  },
  {
    "OBIS": "1-0:41.7.0",
    "Name": "instantaneous_active_import_power_in_phase_l2",
    "Description": "Instantaneous active import power (+A) in phase L2 [kW]"
  },
  {
    "OBIS": "1-0:61.7.0",
    "Name": "instantaneous_active_import_power_in_phase_l3",
    "Description": "Instantaneous active import power (+A) in phase L3 [kW]"
  },
  {
    "OBIS": "1-0:22.7.0",
    "Name": "instantaneous_active_export_power_in_phase_l1",
    "Description": "Instantaneous active export power (-A) in phase L1 [kW]"
  },
  {
    "OBIS": "1-0:42.7.0",
    "Name": "instantaneous_active_export_power_in_phase_l2",
    "Description": "Instantaneous active export power (-A) in phase L2 [kW]"
  },
  {
    "OBIS": "1-0:62.7.0",
    "Name": "instantaneous_active_export_power_in_phase_l3",
    "Description": "Instantaneous active export power (-A) in phase L3 [kW]"
  },
  {
    "OBIS": "1-0:23.7.0",
    "Name": "instantaneous_reactive_import_power_in_phase_l1",
    "Description": "Instantaneous reactive import power (+R) in phase L1 [kvar]"
  },
  {
    "OBIS": "1-0:43.7.0",
    "Name": "instantaneous_reactive_import_power_in_phase_l2",
    "Description": "Instantaneous reactive import power (+R) in phase L2 [kvar]"
  },
  {
    "OBIS": "1-0:63.7.0",
    "Name": "instantaneous_reactive_import_power_in_phase_l3",
    "Description": "Instantaneous reactive import power (+R) in phase L3 [kvar]"
  },
  {
    "OBIS": "1-0:24.7.0",
    "Name": "instantaneous_reactive_export_power_in_phase_l1",
    "Description": "Instantaneous reactive export power (-R) in phase L1 [kvar]"
  },
  {
    "OBIS": "1-0:44.7.0",
    "Name": "instantaneous_reactive_export_power_in_phase_l2",
    "Description": "Instantaneous reactive export power (-R) in phase L2 [kvar]"
  },
  {
    "OBIS": "1-0:64.7.0",
    "Name": "instantaneous_reactive_export_power_in_phase_l3",
    "Description": "Instantaneous reactive export power (-R) in phase L3 [kvar]"
  },
  {
    "OBIS": "1-0:9.7.0",
    "Name": "instantaneous_apparent_import_power",
    "Description": "Instantaneous apparent import power (+VA)"
  },
  {
    "OBIS": "1-0:29.7.0",
    "Name": "instantaneous_apparent_import_power_in_phase_l1",
    "Description": "Instantaneous apparent import power (+VA) in phase L1"
  },
  {
    "OBIS": "1-0:49.7.0",
    "Name": "instantaneous_apparent_import_power_in_phase_l2",
    "Description": "Instantaneous apparent import power (+VA) in phase L2"
  },
  {
    "OBIS": "1-0:69.7.0",
    "Name": "instantaneous_apparent_import_power_in_phase_l3",
    "Description": "Instantaneous apparent import power (+VA) in phase L3"
  },
  {
    "OBIS": "1-0:10.7.0",
    "Name": "instantaneous_apparent_export_power",
    "Description": "Instantaneous apparent export power (-VA)"
  },
  {
    "OBIS": "1-0:30.7.0",
    "Name": "instantaneous_apparent_export_power_in_phase_l1",
    "Description": "Instantaneous apparent export power (-VA) in phase L1"
  },
  {
    "OBIS": "1-0:50.7.0",
    "Name": "instantaneous_apparent_export_power_in_phase_l2",
    "Description": "Instantaneous apparent export power (-VA) in phase L2"
  },
  {
    "OBIS": "1-0:70.7.0",
    "Name": "instantaneous_apparent_export_power_in_phase_l3",
    "Description": "Instantaneous apparent export power (-VA) in phase L3"
  },
  {
    "OBIS": "1-0:1.24.0",
    "Name": "average_import_power",
    "Description": "Average Import Power (+A)"
  },
  {
    "OBIS": "1-0:16.24.0",
    "Name": "average_net_power",
    "Description": "Average Net Power (|+A|-|-A|)"
  },
  {
    "OBIS": "1-0:15.24.0",
    "Name": "average_total_power",
    "Description": "Average Total Power (|+A|+|-A|)"
  },
  {
    "OBIS": "1-0:13.7.0",
    "Name": "instantaneous_power_factor",
    "Description": "Instantaneous Power factor (+A/+VA)"
  },
  {
    "OBIS": "1-0:33.7.0",
    "Name": "instantaneous_power_factor_in_phase_l1",
    "Description": "Instantaneous power factor in phase L1"
  },
  {
    "OBIS": "1-0:53.7.0",
    "Name": "instantaneous_power_factor_in_phase_l2",
    "Description": "Instantaneous power factor in phase L2"
  },
  {
    "OBIS": "1-0:73.7.0",
    "Name": "instantaneous_power_factor_in_phase_l3",
    "Description": "Instantaneous power factor in phase L3"
  },
  {
    "OBIS": "1-0:13.3.0",
    "Name": "minimum_power_factor",
    "Description": "Minimum Power factor (+A/+VA)"
  },
  {
    "OBIS": "1-0:1.4.0",
    "Name": "demand_register_1_active_energy_import",
    "Description": "Demand Register 1 - Active energy import (+A)"
  },
  {
    "OBIS": "1-0:2.4.0",
    "Name": "demand_register_2_active_energy_export",
    "Description": "Demand Register 2 - Active energy export (−A)"
  },
  {
    "OBIS": "1-0:3.4.0",
    "Name": "demand_register_3_reactive_energy_import",
    "Description": "Demand Register 3 - Reactive energy import (+R)"
  },
  {
    "OBIS": "1-0:4.4.0",
    "Name": "demand_register_4_reactive_energy_export",
    "Description": "Demand Register 4 - Reactive energy export (-R)"
  },
  {
    "OBIS": "1-0:9.4.0",
    "Name": "demand_register_5_apparent_energy_import",
    "Description": "Demand Register 5 - Apparent energy import (+VA)"
  },
  {
    "OBIS": "1-0:10.4.0",
    "Name": "demand_register_6_apparent_energy_export",
    "Description": "Demand Register 6 - Apparent energy export (-VA)"
  },
  {
    "OBIS": "1-0:1.5.0",
    "Name": "last_average_demand_register_1_active_energy_import",
    "Description": "Last Average Demand Register 1 - Active energy import (+A)"
  },
  {
    "OBIS": "1-0:2.5.0",
    "Name": "last_average_demand_register_2_active_energy_export",
    "Description": "Last Average Demand Register 2 - Active energy export (−A)"
  },
  {
    "OBIS": "1-0:3.5.0",
    "Name": "last_average_demand_register_3_reactive_energy_import",
    "Description": "Last Average Demand Register 3 - Reactive energy import (+R)"
  },
  {
    "OBIS": "1-0:4.5.0",
    "Name": "last_average_demand_register_4_reactive_energy_export",
    "Description": "Last Average Demand Register 4 - Reactive energy export (-R)"
  },
  {
    "OBIS": "1-0:9.5.0",
    "Name": "last_average_demand_register_5_apparent_energy_import",
    "Description": "Last Average Demand Register 5 - Apparent energy import (+VA)"
  },
  {
    "OBIS": "1-0:10.5.0",
    "Name": "last_average_demand_register_6_apparent_energy_export",
    "Description": "Last Average Demand Register 6 - Apparent energy export (-VA)"
  },
  {
    "OBIS": "0-0:96.7.21",
    "Name": "number_of_power_failures_in_any_phase",
    "Description": "Number of power failures in any phase"
  },
  {
    "OBIS": "1-0:32.33.0",
    "Name": "duration_of_last_voltage_sag_in_phase_l1",
    "Description": "Duration of last voltage sag in phase L1"
  },
  {
    "OBIS": "1-0:52.33.0",
    "Name": "duration_of_last_voltage_sag_in_phase_l2",
    "Description": "Duration of last voltage sag in phase L2"
  },
  {
    "OBIS": "1-0:72.33.0",
    "Name": "duration_of_last_voltage_sag_in_phase_l3",
    "Description": "Duration of last voltage sag in phase L3"
  },
  {
    "OBIS": "1-0:32.34.0",
    "Name": "magnitude_of_last_voltage_sag_in_phase_l1",
    "Description": "Magnitude of last voltage sag in phase L1"
  },
  {
    "OBIS": "1-0:52.34.0",
    "Name": "magnitude_of_last_voltage_sag_in_phase_l2",
    "Description": "Magnitude of last voltage sag in phase L2"
  },
  {
    "OBIS": "1-0:72.34.0",
    "Name": "magnitude_of_last_voltage_sag_in_phase_l3",
    "Description": "Magnitude of last voltage sag in phase L3"
  },
  {
    "OBIS": "1-0:32.37.0",
    "Name": "duration_of_last_voltage_swell_in_phase_l1",
    "Description": "Duration of last voltage swell in phase L1"
  },
  {
    "OBIS": "1-0:52.37.0",
    "Name": "duration_of_last_voltage_swell_in_phase_l2",
    "Description": "Duration of last voltage swell in phase L2"
  },
  {
    "OBIS": "1-0:72.37.0",
    "Name": "duration_of_last_voltage_swell_in_phase_l3",
    "Description": "Duration of last voltage swell in phase L3"
  },
  {
    "OBIS": "1-0:32.38.0",
    "Name": "magnitude_of_last_voltage_swell_in_phase_l1",
    "Description": "Magnitude of last voltage swell in phase L1"
  },
  {
    "OBIS": "1-0:52.38.0",
    "Name": "magnitude_of_last_voltage_swell_in_phase_l2",
    "Description": "Magnitude of last voltage swell in phase L2"
  },
  {
    "OBIS": "1-0:72.38.0",
    "Name": "magnitude_of_last_voltage_swell_in_phase_l3",
    "Description": "Magnitude of last voltage swell in phase L3"
  },
  {
    "OBIS": "1-0:0.2.0",
    "Name": "active_firmware_identifier",
    "Description": "Active firmware identifier"
  },
  {
    "OBIS": "1-0:0.2.8",
    "Name": "active_firmware_signature",
    "Description": "Active firmware signature"
  },
  {
    "OBIS": "1-1:0.2.0",
    "Name": "active_firmware_identifier_1",
    "Description": "Active firmware identifier 1"
  },
  {
    "OBIS": "1-1:0.2.8",
    "Name": "active_firmware_signature_1",
    "Description": "Active firmware signature 1"
  }
]
)"""";