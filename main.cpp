#include "weather.hpp"

int main(){

    weather_reading::temperature += weather_reading::get_random_value("temperature");
    weather_reading::humidity += weather_reading::get_random_value("humidity");

    //MAIN CODE\LOOP
    for (int time = 0; time < 25 ; time++) {
        if (time < 9) {
            std::cout << "day: " << weather_reading::get_temp("day") << "\n";
        }
        else {
            std::cout << "night: " <<weather_reading::get_temp("night") << "\n";

        }
    }
}