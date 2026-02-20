#include "weather_features.hpp"
#include <iostream>

int main(){

    weather_reading::temperature += weather_reading::get_random_value("temperature");
    // Create weather_log object to record data
    weather_log logger;
    
    //MAIN CODE\LOOP
    for (int time = 1; time < 24 ; time++) {
        std::cout << time + 1 << "\n";
        double temp = weather_reading::get_temp(time + 1);
        double humidity = weather_reading::get_humidity(weather_reading::temperature, temp);
        double pressure = weather_reading::get_pressure();
        weather_station::update(time + 1);
        // Record the weather data to file
        logger.record(temp, humidity, pressure);
    }
}