#include <stdint.h>
#include "fsl_debug_console.h"


enum
{
	TRIP_DISTANCE = 0,
	TRIP_AVG_MILEAGE,
	TRIP_BATTERY,
	TRIP_TIME,
	TRIP_AVG_SPEED,
	TRIP_TOP_SPEED
};

enum
{
	TRIP_A = 0,
	TRIP_B,
	TRIP_C,	
	TRIP_D,
    DAILY_TRIP,
	MAX_TRIP
};

enum
{
	TRIP_TIME_HR,
	TRIP_TIME_MIN,
	TRIP_TIME_SEC,
	MAX_TRIP_TIME
};

enum
{
	TRIP_A_RESET,
	TRIP_B_RESET,
	TRIP_C_RESET,
	TRIP_D_RESET,
    DAILY_TRIP_RESET,
	MAX_TRIP_RESET
};


typedef union
{
	uint8_t trip_cumulative_data[14];
	struct
	{
		uint8_t trip_total_time_travelled;	/*3*/ //trip_total_time_travelled[MAX_TRIP_TIME];
		uint8_t battery_consumed;							/*4*/ //battery_consumed[4]
		uint8_t trip_top_speed;                             /*1*/
		uint8_t trip_avg_mileage;                           /*1*/
		uint8_t avg_speed;                                  /*1*/
		uint8_t trip_total_distance_covered;             /*4*/ //trip_total_distance_covered[4]
	}values;
}TRIP_DETAILS_TYPE_St;

/**********************************************************************************************************************/
/*                                    P U B L I C     F U N C T I O N S    D E C L A R A T I O N                      */
/**********************************************************************************************************************/

void TripVariableInit(void);
void TripAppNormal(void);
void Trip_A_Reset(void);
void Trip_B_Reset(void);
void Trip_C_Reset(void);
void Trip_D_Reset(void);
void Daily_Trip_Reset(void);
uint32_t GetTripAverageMilege(uint8_t element);
uint32_t GetTripAverageSpeed(uint8_t element);
uint8_t GetTripTopSpeed(uint8_t element);
uint32_t GetTripBatteryConsumption(uint8_t element);
uint32_t GetTripTimeValue(uint8_t element);
uint32_t GetTripDistanceTravelled(uint8_t parameter);
