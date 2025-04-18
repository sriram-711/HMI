/*
 * presentation.h
 *
 *  Created on: Apr 22, 2024
 *      Author: Admin
 */

#ifndef APPLICATION_HMI_PRESENTATION_H_
#define APPLICATION_HMI_PRESENTATION_H_

#include "menu.h"
#include "uart.h"
#include "FreeRTOS.h"
#include "task.h"

#define OBJECT_OPAQUE 255
#define OBJECT_TRANSPARENT 0
#define OBJECT_DISABLED 76

// Speedometer
#define MIN_SPEEDOMETERVALUE 0
#define ALERT_SPEEDOMETERVALUE 140
#define MAX_SPEEDOMETERVALUE 180

// Battery Percentage
#define MIN_BATTERYPERCENTAGE 0
#define MAX_BATTERYPERCENTAGE 100

// Odometer
#define MIN_ODOMETERVALUE 0
#define MAX_ODOMETERVALUE 999999

// Gear Value
#define GEAR_NEUTRAL 0
#define GEAR_FIRST  1
#define GEAR_SECOND  2
#define GEAR_THIRD  3
#define GEAR_FOURTH 4
#define GEAR_FIFTH 5
#define GEAR_REVERSE 6
#define GEAR_INVALID 7

// Gear Shifter
#define GEAR_NOSHIFT 0
#define GEAR_UPSHIFT 1
#define GEAR_DOWNSHIFT 2

// Ride Mode
#define RM_ERROR 0
#define RM_ECONOMY 1
#define RM_AUTOMATIC 2
#define RM_POWER 3

// Adaptive Headlamp
#define AH_LEVEL0 0
#define AH_LEVEL1 1
#define AH_LEVEL2 2
#define AH_LEVEL3 3
#define AH_AUTOMATIC 4
#define AH_OFF 5

//DRL
#define DRL_OFF 0
#define DRL_ON 1
#define DRL_AUTOMATIC 2

//Quick Shifter
#define QS_OFF 0
#define QS_ON 1
#define QS_AUTOMATIC 2

//Traction Control
#define TC_OFF 0
#define TC_ON 1
#define TC_AUTOMATIC 2

// Cruise Control
#define CC_RESET 0
#define CC_INCREASE 1
#define CC_DECREASE 2
#define CC_SET 3

// API UPDATE
void setSpeed(uint16_t speedValue);
void setRideMode(uint8_t rideModeValue);
void setBatteryPercentage(uint8_t batteryPercentageValue);
void setOdometerValue(uint32_t odometerValue);
void setAdaptiveHeadLampValue(uint32_t adaptiveHeadLampValue);
void setDRLValue(uint32_t DRLValue);
void setTractionControlValue(uint32_t tractionControlValue);
void setQuickShifterValue(uint32_t quickShifterValue);
void setCruiseControlValue(uint32_t cruiseControlValue);
void setGearShiftIndicator(uint8_t gearValue, uint8_t gearShiftDirection);

void setTPMS(uint8_t frontTPMS, uint8_t rearTPMS);
void setAverageMileage(uint16_t averageMileageValue);
void setInstantMileage(uint16_t instantMileageValue);
void setAverageSpeed(uint16_t AveragespeedValue);
void setTopSpeed(uint16_t TopspeedValue);
void set0to60(uint8_t inSeconds);
void setBateryEfficiency(uint8_t BatteryEfficiency);


// Menu Button
void setButtonValue(uint8_t buttonValue);
void HomeScreen();

void setBLE_ConnectionStatus(uint8_t BLE_Status);
void setBLE_PhoneBatteryStatus(uint8_t BLE_PhoneBatteryStatus);
void setBLE_PhoneSignalStrengthStatus(uint8_t BLE_PhoneSignalStrengthStatus);
void setCallerName_Number(uint8_t BLE_callername[], uint8_t BLE_callernameLength, uint8_t BLE_callernumber[], uint8_t BLE_callernumberLength);
void setBLE_PhoneMissedCallStatus(uint8_t BLE_PhoneMissedCallStatus);
void setNavigationTurn_by_TurnInfo(uint8_t BLE_navDestination[], uint8_t BLE_navDestinationLength, uint8_t BLE_navETA[], uint8_t BLE_navETALength, uint8_t BLE_navDirection[], uint8_t BLE_navDirectionLength, uint8_t BLE_navDirectionType[], uint8_t BLE_navDirectionIconIndex);


void setBLE_PhoneCallStatus(uint8_t BLE_FrameType);
void set_BLENavigationStatus(uint8_t BLE_FrameType, uint8_t BLE_navRmNtfy);

void enableMainScreen();
void disableMainScreen();

void enableMenuScreen();
void disableMenuScreen();

void enableBLECallScreen();
void disableBLECallScreen();

void enableBLENavigationScreen();
void disableBLENavigationScreen();


// Menu Screens
void setMenuScreen();
void set_ui(lv_ui *ui);

extern bool CallState;

void setCallState(bool callState);
bool getCallState();

extern bool NavigationState;

void setNavigationState(bool navigationState);
bool getNavigationState();
void setCameraDetails1(uint8_t FrontvehicleType);
void setCameraDetails2(uint8_t RearvehicleType);
void setdistance1(uint8_t dis);
void setdistance2(uint8_t dis);

//Time
// void setHour(uint8_t hr);
// void setMin(uint8_t min);
// void setSecond(uint8_t sec);

#endif /* APPLICATION_HMI_PRESENTATION_H_ */
