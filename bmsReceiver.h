#ifndef BMSRECEIVER_H
#define BMSRECEIVER_H

#include "common.h"
#include "receiverTemperature.h"
#include "receiverSOC.h"

std::string readFromConsole();
std::map<std::vector<int>, std::vector<int>>  splitData(std::vector<std::string> combined_sensor_data);
std::vector<std::string> extractSensorData(std::vector<std::string> input);
float calculateSimpleMovingAverageValue(std::vector<int> buffer,int sampleSize);
void receiverCentralControl();

#endif
