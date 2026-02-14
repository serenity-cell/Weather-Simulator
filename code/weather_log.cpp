#include "weather_features.hpp"

weather_log::weather_log() {
    save_file.open("weather.csv", std::ios::app);
}

weather_log::~weather_log() {
    if (save_file.is_open()) {
        save_file.close();
    }
}

void weather_log::record(double temp, double humidity, double pressure) {
    weather_vector.push_back(temp);
    weather_vector.push_back(humidity);
    weather_vector.push_back(pressure);
    save_file << temp << "," << humidity << "," << pressure << "\n";
    save_file.flush();
}


