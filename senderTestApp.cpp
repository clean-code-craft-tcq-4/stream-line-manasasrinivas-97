#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <vector>
#include <iostream>
#include "sensorTemperature.h"
#include "sensorCharge.h"
#include "sensorDataSender.h"

using namespace std;

TEST_CASE("To check if temperature values are generated correctly") 
{
    vector<int> temperatureData = generateTemperatureValues(MAX_TEMPERATURE_VALUE , MIN_TEMPERATURE_VALUE , NUMBER_OF_SAMPLES);
    int tSize = temperatureData.size();
    REQUIRE(tSize == NUMBER_OF_SAMPLES);
}

TEST_CASE("To check if charge values are generated correctly") 
{
    vector<int> chargeData = generateChargeValues(MAX_CHARGE_VALUE , MIN_CHARGE_VALUE , NUMBER_OF_SAMPLES );
    int cSize = chargeData.size();
    REQUIRE(cSize == NUMBER_OF_SAMPLES);
}

TEST_CASE("TestWriteDataToConsole") {
  
  REQUIRE(writeDataToConsole() == true);
  
}
