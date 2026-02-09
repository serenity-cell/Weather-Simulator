#include "weather.hpp"

int main(){

    weather_reading::temperature += weather_reading::get_random_value("temperature");
    //MAIN CODE\LOOP
    for (int time = 0; time < 25 ; time++) {
        double old_temp = weather_reading::temperature;
        double new_temp = weather_reading::get_temp(time);
        if (time < 9) {
            std::cout << "day: " << "\n temp: " << new_temp << "\n humidity: " << weather_reading::get_humidity(old_temp, new_temp) << "\n---------------- \n ";
        }
        else {
            std::cout << "night: " << "\n temp: "<< new_temp << "\n humidity: "  << weather_reading::get_humidity(old_temp, new_temp) << "\n---------------- \n ";

        }
    }
}