#include "weather_features.hpp"
#include <iostream>

int main(){

    weather_reading::temperature += weather_reading::get_random_value("temperature");
    //MAIN CODE\LOOP
    for (int time = 0; time < 25 ; time++) {
        std::cout << time << "\n";
        weather_station::update(time);
    }
}