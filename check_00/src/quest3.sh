chmod +x ai_door_control.sh ai_door_management_module.sh ai_initial_module.sh ai_module_2.sh
mv door_management_fi door_management_files
mkdir door_configuration door_logs door_map
mv *.conf door_configuration
mv *.log door_logs
mv door_map_1.1 door_map
echo -e 'chmod +x ai_door_control.sh ai_door_management_module.sh ai_initial_module.sh ai_module_2.sh
mv door_management_fi door_management_files
mkdir door_configuration door_logs door_map
mv *.conf door_configuration
mv *.log door_logs
mv door_map_1.1 door_map' > quest3.sh
