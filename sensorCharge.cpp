#include "sensorCharge.h"

vector<int> generateChargeValues(int maxChargeValue, int minChargeValue, int numberOfReadings)
{
    vector<int> chargeValueList;
    for(int count = 0; count < numberOfReadings; count++)
    {
        int rValue = rand() % maxChargeValue + maxChargeValue;
        chargeValueList.push_back(rValue);
    }
    return chargeValueList;
}
