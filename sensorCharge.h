#ifndef SENSORCHARGE_H
#define SENSORCHARGE_H

#include <vector>
#include <iostream>
#include <cstdlib>

const int MAX_CHARGE_VALUE = 100;
const int MIN_CHARGE_VALUE = 0;

using namespace std;

vector<int> generateChargeValues(int maxChargeValue, int minChargeValue, int numberOfReadings);

#endif
