#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "common.h"
#include "receiverTemperature.h"
#include "receiverSOC.h"
#include "bmsReceiver.h"

#define TEST_INPUTS 50

using namespace std;

TEST_CASE("To verify functionality of calculateMaxTemperatureValue()" )
{
    std::vector<int> testTempVector = {10,20,40,60,100};
    int maxTemp = calculateMaxTemperatureValue(testTempVector);
    REQUIRE(maxTemp == 100);
}

TEST_CASE("To verify functionality of calculateMaxSOCValue()" )
{
    std::vector<int> testTempVector = {10,20,40,60,100};
    int maxTemp = calculateMaxSOCValue(testTempVector);
    REQUIRE(maxTemp == 100);
}

TEST_CASE("To verify functionality of calculateMinTemperature()" )
{
    std::vector<int> testTempVector = {10,20,40,60,100};
    int maxTemp = calculateMinTemperature(testTempVector);
    REQUIRE(maxTemp == 10);
}

TEST_CASE("To verify functionality of calculateMinSOCValue()" )
{
    std::vector<int> testTempVector = {10,20,40,60,100};
    int maxTemp = calculateMinSOCValue(testTempVector);
    REQUIRE(maxTemp == 10);
}


TEST_CASE("To verify functionality of calculateSimpleMovingAverageValue()" )
{
    std::vector<int> testTempVector = {10,20,40,60,100};
    float SMA_Temperature;
    SMA_Temperature = calculateSimpleMovingAverageValue(testTempVector, SAMPLES);
    REQUIRE(SMA_Temperature == 46.);
}
TEST_CASE("Tests to check whether sensor data is read from console and also to check whether correct Max, Min and SMA values of sensor parameters are printed on console") 
{
    receiverCentralControl();

}