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
    std::vector<double> weather_vector;
    std::ifstream load_file;
    std::ofstream save_file;

public:
    weather_log();
    ~weather_log();
    void record(double temp, double humidity, double pressure);
    static void calculate_daily_average();
    static void export_csv();
};


#endif //WEATHER_SIMULATOR_WEATHER_H