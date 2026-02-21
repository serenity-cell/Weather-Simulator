#include "weather_features.hpp"
#include <fstream>
#include <iostream>
#include <numeric>
#include <string>
#include <sstream>

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
    load_file.seekg(0, std::ios::beg);
    
    // Clear previous data before reading
    weather_vector_temp.clear();
    weather_vector_humidity.clear();
    weather_vector_pressure.clear();
    
    std::string line;
    while (std::getline(load_file, line)) {
        if (line.empty()) continue;
        
        std::istringstream iss(line);
        std::string temperature_str, humidity_str, pressure_str;
        
        // Extract comma-separated fields
        if (!std::getline(iss, temperature_str, ',') || temperature_str.empty()) continue;
        if (!std::getline(iss, humidity_str, ',') || humidity_str.empty()) continue;
        if (!std::getline(iss, pressure_str) || pressure_str.empty()) continue;
        
        // Parse and validate numeric values
        try {
            double temp = std::stod(temperature_str);
            double humidity = std::stod(humidity_str);
            double pressure = std::stod(pressure_str);
            
            weather_vector_temp.push_back(temp);
            weather_vector_humidity.push_back(humidity);
            weather_vector_pressure.push_back(pressure);
        } catch (const std::invalid_argument& e) {
            std::cout << "Skipping malformed line: " << line << " (invalid number format)\n";
            continue;
        } catch (const std::out_of_range& e) {
            std::cout << "Skipping malformed line: " << line << " (number out of range)\n";
            continue;
        }
    }
    
    // Calculate averages with division by zero protection
    if (!weather_vector_temp.empty()) {
        avg_temp_ = std::accumulate(weather_vector_temp.begin(), weather_vector_temp.end(), 0.0) / weather_vector_temp.size();
    } else {
        avg_temp_ = 0.0;
    }
    
    if (!weather_vector_humidity.empty()) {
        avg_humidity_ = std::accumulate(weather_vector_humidity.begin(), weather_vector_humidity.end(), 0.0) / weather_vector_humidity.size();
    } else {
        avg_humidity_ = 0.0;
    }
    
    if (!weather_vector_pressure.empty()) {
        avg_pressure_ = std::accumulate(weather_vector_pressure.begin(), weather_vector_pressure.end(), 0.0) / weather_vector_pressure.size();
    } else {
        avg_pressure_ = 0.0;
    }

    std::cout << "daily average - Temperature: " << avg_temp_ << ", Humidity: " << avg_humidity_ << ", Pressure: " << avg_pressure_ << "\n";
    save_file.clear();
}


