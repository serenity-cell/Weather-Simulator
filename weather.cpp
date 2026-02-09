#include "weather.hpp"
double weather_reading::temperature = 0;

double weather_reading::get_random_value (const std::string& time) {
    double value = 0;
    double minimum = 0;
    double maximum = 0;

    if (time == "night") {
        minimum = 0.2;
        maximum = 0.3;
    }
    else if (time == "day") {
        minimum = 0.2;
        maximum = 0.4;
    }
    else if (time == "temperature") {
        minimum = -1.5;
        maximum = 1.5;
    }
    else if (time == "humidity") {
        minimum = -3;
        maximum = 3;
    }
    else if (time == "pressure") {
        minimum = 0.2;
        maximum = 0.4;

    }
    std::uniform_real_distribution<double> dist(minimum, maximum);  //(min, max)
    //Mersenne Twister: Good quality random number generator
    std::mt19937 rng;
    //Initialize with non-deterministic seeds
    rng.seed(std::random_device{}());
    value =  dist(rng);
    return value;

}


double weather_reading::get_temp(const std::string& time) {

    //daytime temperature changes
    if (time == "day") {
        temperature= temperature + get_random_value("day");
    }
    //nighttime temperature changes
    else if  (time == "night") {
        temperature= temperature - get_random_value("night");
    }
    return temperature;

};

//void weather_reading::get_humidity() {

//}
