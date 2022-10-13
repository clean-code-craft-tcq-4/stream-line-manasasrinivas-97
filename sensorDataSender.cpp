#include "sensorDataSender.h"

bool writeDataToConsole()
{
    bool sendStatus = false;
    vector<int> temperatureData = generateTemperatureValues(MAX_TEMPERATURE_VALUE , MIN_TEMPERATURE_VALUE , NUMBER_OF_SAMPLES);
    vector<int> chargeData = generateChargeValues(MAX_CHARGE_VALUE , MIN_CHARGE_VALUE , NUMBER_OF_SAMPLES);
    if((temperatureData.size() == NUMBER_OF_SAMPLES) && (chargeData.size() == NUMBER_OF_SAMPLES))
    {
        for(int count = 0; count < NUMBER_OF_SAMPLES; count ++)
        {
            cout << temperatureData[count]<< "," << chargeData[count] <<endl;
        }
        sendStatus = true;
    }
    return sendStatus;

}




