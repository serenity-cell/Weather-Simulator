#include "weather_reading.hpp"

void weather_station::update(int time) {
    double old_temp = weather_reading::temperature;
    double new_temp = weather_reading::get_temp(time);
    if (time <= 9) {

        std::cout << " day: " << "\n temp: " << new_temp << "\n humidity: "
        << weather_reading::get_humidity(old_temp, new_temp) << "\n pressure: " << weather_reading::get_pressure() << "\n---------------- \n ";
    }
    else {
        std::cout << " night: " << "\n temp: "<< new_temp << "\n humidity: "
        << weather_reading::get_humidity(old_temp, new_temp) << "\n pressure: " << weather_reading::get_pressure()  << "\n---------------- \n ";

    }
}
