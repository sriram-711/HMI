
#ifndef TRIPMETER_API_H
#define TRIPMETER_API_H

#include "hmi_api.h"

typedef struct {
    uint16_t tripDistance;      // In kilometers (km)
    uint8_t tripTime_Days;   	// In Hours (DD)
    uint8_t tripTime_Hours;   	// In Hours (HH)
    uint8_t tripTime_Minutes;   // In Hours (MM)
    uint8_t tripTime_Seconds;   // In Hours (SS)
    uint8_t avgSpeed;			// In kilometers per hour (km/h)
    uint8_t topSpeed;			// In kilometers per hour (km/h)
    uint8_t batteryConsumed;    // In Percentages (%)
    uint8_t avgMileage;    // In Km per Full Charge (%)
    bool resetState;// In Pressed or Released (True or False)
} TripDetails;

void setTripDistanceCovered(uint32_t odometerValue);

// Trip Management
void startTrip();
TripDetails endTrip();

// Data Retrieval
float getSpeed();
unsigned long getOdometer();
float getBatteryLevel();
unsigned long getTime();



#endif
