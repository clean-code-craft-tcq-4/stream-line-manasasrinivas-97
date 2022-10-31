#include "bmsReceiver.h"

std::string readFromConsole()
{
    std::string tempbuffer,inputBuffer;
    std::cout << "Waiting for input...";
    for(int i = 0; i< MAX_INPUTS; i++)
    {
        getline(std::cin,tempbuffer);
        inputBuffer = inputBuffer + "\n" + tempbuffer;
        std::cout << "Received line: " << tempbuffer << std::endl;
    }
    return inputBuffer;
}

float calculateSimpleMovingAverageValue(std::vector<int> inputBuffer,int sampleSize)
{
    float tempAverage = 0.0;
    float sum = 0.0;
    int inputBufferSize = inputBuffer.size();
    for(int cursor = inputBufferSize-sampleSize; cursor < inputBufferSize ; cursor++) //
    {
        sum = sum + inputBuffer[cursor]; 
        tempAverage = sum/sampleSize;
    }
    return tempAverage;
}
std::vector<std::string> extractSensorData(std::vector<std::string> input)
{
    std::vector<std::string> combined_sensor_data;
    for (auto it : input)
    {
        std::stringstream console_line(it);
        std::string sensor_data;
        while (std::getline(console_line, sensor_data, ','))
        {
            combined_sensor_data.push_back(sensor_data.substr(sensor_data.rfind('=') + 1)); // extract and pass only int data
        }
    }
    return combined_sensor_data;
}

void receiverCentralControl()
{
    float SMA_Temperature,SMA_SOC;
    std::string buffer = readFromConsole();
    std::vector<int> temperatureReadings = extractTemperatureData(buffer);
    std::vector<int> socReadings = extractSOCData(buffer);
    // for (auto i: temperatureReadings)
    //     std::cout << i << ' ';

    int maxTemperature = calculateMaxTemperatureValue(temperatureReadings);
    int minTemperature = calculateMinTemperature(temperatureReadings);
    int minSOC = calculateMinSOCValue(socReadings);
    int maxSOC = calculateMaxSOCValue(socReadings);
    SMA_Temperature = calculateSimpleMovingAverageValue(temperatureReadings, SAMPLES);
    SMA_SOC = calculateSimpleMovingAverageValue(socReadings, SAMPLES);
    printTemperatureStatistics(maxTemperature, minTemperature, SMA_Temperature);
    printSOCStatistics(maxSOC, minSOC, SMA_SOC);

}
