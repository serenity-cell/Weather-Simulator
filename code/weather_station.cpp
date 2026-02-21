#include "weather_features.hpp"
#include <iostream>

void weather_station::update() {
    weather_reading::temperature += weather_reading::get_random_value("temperature");
    // Create weather_log object to record data
    weather_log logger;
    //MAIN CODE\LOOP
    for (int time = 1; time < 25 ; time++) {
        std::cout << time << "\n";
        get_reading(time);
        
    }
    logger.calculate_daily_average();
    
}

void weather_station::get_reading(int time) {
    double old_temp = weather_reading::temperature;
    double new_temp = weather_reading::get_temp(time);
    double humidity = weather_reading::get_humidity(old_temp, new_temp);
    double pressure = weather_reading::get_pressure();

    weather_log logger;
    if (time <= 9) {

        std::cout << " day: " << "\n temp: " << new_temp << "\n humidity: "
        << humidity << "\n pressure: " << pressure << "\n---------------- \n ";
    }
    else {
        std::cout << " night: " << "\n temp: "<< new_temp << "\n humidity: "
        << humidity << "\n pressure: " << pressure  << "\n---------------- \n ";
    }
    
    logger.record(new_temp, humidity, pressure);
}
