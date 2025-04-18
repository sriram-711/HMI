/*
 * widgets.h
 *
 *  Created on: Jul 17, 2024
 *      Author: Admin
 */

#ifndef APPLICATION_INCLUDES_WIDGETS_H_
#define APPLICATION_INCLUDES_WIDGETS_H_

#include "FreeRTOS.h"
#include "task.h"

enum WidgetsType	{
	Unknown = 0,
	Odometer,
	AverageMileage,
	Trip_1,
	Trip_2,
	Trip_3,
	Zero_to_Sixty,
	InstantMileage,
	AverageSpeed,
	TyrePressure,
	FuelEfficiency,
	DailyTrip,
	TopSpeed
};

typedef struct {
	uint8_t AVG_MILEAGE;
	uint8_t TOP_SPEED;
	uint8_t AVG_SPEED;
}PerfomanceRecord;

typedef struct {
	uint8_t DD_TO_SERVICE;
	uint8_t MM_TO_SERVICE;
	uint16_t YY_TO_SERVICE;
	uint8_t KM_TO_SERVICE;
	uint8_t DAYS_FROM_LASTSERVICE;
}ServiceRecord;

typedef struct {
	uint32_t DIST_COVERED;
	uint8_t SS_TRIP;
	uint16_t MM_TRIP;
	uint8_t HH_TRIP;
	uint8_t AVG_SPEED;
	uint8_t TOP_SPEED;
	uint8_t BATTERY_USED;
	uint8_t AVG_MILEAGE;
}TripRecord;

// Performance Data
void vehiclePerformanceData(uint8_t averageMileage, uint8_t topSpeed, uint8_t averageSpeed);

//Service Data
void vehicleServiceData(uint16_t yearService, uint8_t monthService, uint8_t dayService, uint8_t kmService, uint8_t daysFromService);

// Trip Data
void VehicleTripData(uint8_t tripType, uint32_t distanceCovered, uint8_t secondsTrip, uint8_t minutesTrip, uint8_t hoursTrip,
		uint8_t averageSpeed, uint8_t topSpeed, uint8_t batteryUsed, uint8_t averageMileage, uint8_t resetState);

// Widget
void VehicleWidget(uint8_t widgetType,  uint8_t activeWidget);

#endif /* APPLICATION_INCLUDES_WIDGETS_H_ */
