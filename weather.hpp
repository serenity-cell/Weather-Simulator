//#include <vector>
#pragma once
//#include <fstream>
#include <iostream>
#include <string>
#include <random>
#include <ctime>


#ifndef WEATHER_SIMULATOR_WEATHER_H
#define WEATHER_SIMULATOR_WEATHER_H


class weather_reading {
public:
    static double temperature ;
    static double humidity;
    static double pressure;

    static double get_random_value(const std::string& time);
    static double get_temp(const std::string &time);
    void get_humidity();
    void get_pressure();
};

class weather_station {

    public:
    void update();
    void get_reading();

};
class weather_log {

};


#endif //WEATHER_SIMULATOR_WEATHER_H