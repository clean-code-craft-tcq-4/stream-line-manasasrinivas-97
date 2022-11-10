#include "sensorTemperature.h"

vector<int> generateTemperatureValues(int minTemperatureValue, int maxTemperatureValue, int numberOfReadings)
{
    vector<int> temperatureValueList;
    for(int count = 0; count < numberOfReadings; count++)
    {
        int rValue = rand() % maxTemperatureValue + minTemperatureValue;
        temperatureValueList.push_back(rValue);
    }
    return temperatureValueList;
}

