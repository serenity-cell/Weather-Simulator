#pragma once
#include <vector>
#include <fstream>
#include <string>
#include <ctime>
#include <cmath>

#ifndef WEATHER_SIMULATOR_WEATHER_H
#define WEATHER_SIMULATOR_WEATHER_H



class weather_reading {
    public:
    static double temperature ;
    static double humidity;
    static double pressure;

    static double get_random_value(const std::string& type);
    static double get_temp(int time);
    static double get_humidity(double old_data, double new_data);
    static double get_pressure();
};

class weather_station {
    public:
    static void update();
    static void get_reading(int time);

};

class weather_log {
    std::vector<double> weather_vector_temp;
    std::vector<double> weather_vector_humidity;
    std::vector<double> weather_vector_pressure;
    std::ifstream load_file;
    std::ofstream save_file;

private:
    double avg_temp_ = 0.0;
    double avg_humidity_ = 0.0;
    double avg_pressure_ = 0.0;

public:
    weather_log();
    ~weather_log();
    void record(double temp, double humidity, double pressure);
    void calculate_daily_average();
    void export_csv();
    double get_avg_temp() const { return avg_temp_; }
    double get_avg_humidity() const { return avg_humidity_; }
    double get_avg_pressure() const { return avg_pressure_; }
};

#endif //WEATHER_SIMULATOR_WEATHER_H