#ifndef SENSORTEMPERATURE_H
#define SENSORTEMPERATURE_H

#include <vector>
#include <iostream>
#include <cstdlib>

const int MAX_TEMPERATURE_VALUE = 100;
const int MIN_TEMPERATURE_VALUE = -50;

using namespace std;

vector<int> generateTemperatureValues(int minTemperatureValue, int maxTemperatureValue, int numberOfReadings);

#endif
