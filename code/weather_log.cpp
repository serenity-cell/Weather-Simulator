#include "weather_features.hpp"
#include <fstream>
#include <iostream>

weather_log::weather_log() {
    std::string filename = "weather.csv";
    save_file.open(filename, std::ios::app);
    load_file.open(filename);
    if (!save_file.is_open()) { 
        std::cout << "Error trying to open the file:" << filename << "\n" ;
    }
}

weather_log::~weather_log() {
    if (save_file.is_open()) {
        save_file.close();
    }
}

void weather_log::record(double temp, double humidity, double pressure) {
    save_file << temp << "," << humidity << "," << pressure << "\n";
    save_file.flush();
}

void weather_log::calculate_daily_average() {
    // Implement logic to calculate daily average from the recorded data

    load_file.clear();
    std::string line;
    while (getline(load_file, line)) {
        // Parse the line and calculate averages
        // Parse the line and store individual values
        // This is a placeholder - adjust parsing logic as needed
    }
}


