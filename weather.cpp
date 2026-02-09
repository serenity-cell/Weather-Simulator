#include "weather.hpp"
double weather_reading::temperature = 23.3;
double weather_reading::humidity = 43.2;

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
        minimum = 0.1;
        maximum = 2.5;
    }
    else if (time == "humidity") {
        minimum = 0.1;
        maximum = 1.3;
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

double weather_reading::get_temp(const int& time) {
    //daytime temperature changes
    if (time < 9) {
        temperature= temperature + get_random_value("day");
    }
    //nighttime temperature changes
    else if  (time >= 10) {
        temperature= temperature - get_random_value("night");
    }
    return temperature;

};

double weather_reading::get_humidity(double old_data, double new_data) {
    double delta = new_data - old_data;
    if (delta < 0) {
      humidity = humidity + get_random_value("humidity") + 0.3;
    }
    else if (delta > 0) {
       humidity = humidity - get_random_value("humidity") - 0.3;
    }
    humidity = round(humidity);

    return humidity;

}
