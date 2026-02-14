#include "weather_features.hpp"
#include <random>
#include <algorithm>

double weather_reading::temperature = 23.3;
double weather_reading::humidity = 74.7;
double weather_reading::pressure = weather_reading::get_random_value("base_pressure");

double weather_reading::get_random_value (const std::string& type) {
    double value = 0;
    double minimum = 0;
    double maximum = 0;

    if (type == "night") {
        minimum = 0.2;
        maximum = 0.3;
    }
    else if (type == "day") {
        minimum = 0.2;
        maximum = 0.4;
    }
    else if (type == "temperature") {
        minimum = 0.1;
        maximum = 2.5;
    }
    else if (type == "humidity") {
        minimum = 0.1;
        maximum = 1.3;
    }
    else if (type == "pressure") {
        minimum = 0.1;
        maximum = 1.3;

    }
    else if (type == "base_pressure") {
        minimum = 1013;
        maximum = 1017;
    }
    else {
        // Unknown type: return 0 rather than relying on a (0,0) distribution.
        return 0.0;
    }

    std::uniform_real_distribution<double> dist(minimum, maximum);  //(min, max)
    //Mersenne Twister: Good quality random number generator
    std::mt19937 rng;
    //Initialize with non-deterministic seeds
    rng.seed(std::random_device{}());;
    value =  dist(rng);
    return value;

}

double weather_reading::get_temp(int time) {
    //daytime temperature changes
    if (time <= 9) {
        temperature= temperature + get_random_value("day");
    }
    //nighttime temperature changes
    else {
        temperature= temperature - get_random_value("night");
    }
    return temperature;

};


//gets humidity data based on old and new temperature fluctuation data
double weather_reading::get_humidity(double old_data, double new_data) {
    double delta = new_data - old_data;
    if (delta < 0) {
      humidity = humidity + get_random_value("humidity") + 0.3;
    }
    else if (delta > 0) {
       humidity = humidity - get_random_value("humidity") - 0.3;
    }
    humidity = std::round(humidity);
    humidity = std::clamp(humidity, 0.0, 100.0);

    return humidity;

}


double weather_reading::get_pressure() {
    if (pressure >=  1015) {
        pressure = pressure - get_random_value("pressure");
    }
    else if (pressure < 1015) {
        pressure = pressure + get_random_value("pressure");
    }

    return pressure;
}
