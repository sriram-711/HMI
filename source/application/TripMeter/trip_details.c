#include "trip_details.h"

TRIP_DETAILS_TYPE_St TRIP_DETAILS_St[MAX_TRIP];

void TripVariableInit(void)
{
    PRINTF("TripVariableInit\r\n");
    TripAppNormal();
}

void TripAppNormal(void)
{
    uint8_t i = 0;
    for(i = 0; i < MAX_TRIP; i++)
    {
        switch (i)
        {
        case TRIP_A:
            TRIP_DETAILS_St[TRIP_A].values.trip_total_time_travelled = 0;
            TRIP_DETAILS_St[TRIP_A].values.battery_consumed = 10;
            TRIP_DETAILS_St[TRIP_A].values.trip_top_speed = 10;
            TRIP_DETAILS_St[TRIP_A].values.trip_avg_mileage = 10;
            TRIP_DETAILS_St[TRIP_A].values.avg_speed = 10;
            TRIP_DETAILS_St[TRIP_A].values.trip_total_distance_covered = 10;
        break;
        case TRIP_B:
            TRIP_DETAILS_St[TRIP_B].values.trip_total_time_travelled = 0;
            TRIP_DETAILS_St[TRIP_B].values.battery_consumed = 20;
            TRIP_DETAILS_St[TRIP_B].values.trip_top_speed = 20;
            TRIP_DETAILS_St[TRIP_B].values.trip_avg_mileage = 20;
            TRIP_DETAILS_St[TRIP_B].values.avg_speed = 20;
            TRIP_DETAILS_St[TRIP_B].values.trip_total_distance_covered = 20;
        break;
        case TRIP_C:
            TRIP_DETAILS_St[TRIP_C].values.trip_total_time_travelled = 0;
            TRIP_DETAILS_St[TRIP_C].values.battery_consumed = 30;
            TRIP_DETAILS_St[TRIP_C].values.trip_top_speed = 30;
            TRIP_DETAILS_St[TRIP_C].values.trip_avg_mileage = 30;
            TRIP_DETAILS_St[TRIP_C].values.avg_speed = 30;
            TRIP_DETAILS_St[TRIP_C].values.trip_total_distance_covered = 30;
        break;
        case TRIP_D:
            TRIP_DETAILS_St[TRIP_D].values.trip_total_time_travelled = 0;
            TRIP_DETAILS_St[TRIP_D].values.battery_consumed = 40;
            TRIP_DETAILS_St[TRIP_D].values.trip_top_speed = 40;
            TRIP_DETAILS_St[TRIP_D].values.trip_avg_mileage = 40;
            TRIP_DETAILS_St[TRIP_D].values.avg_speed = 40;
            TRIP_DETAILS_St[TRIP_D].values.trip_total_distance_covered = 40;
        break;
        case DAILY_TRIP_RESET:
            TRIP_DETAILS_St[DAILY_TRIP_RESET].values.trip_total_time_travelled = 0;
            TRIP_DETAILS_St[DAILY_TRIP_RESET].values.battery_consumed = 50;
            TRIP_DETAILS_St[DAILY_TRIP_RESET].values.trip_top_speed = 50;
            TRIP_DETAILS_St[DAILY_TRIP_RESET].values.trip_avg_mileage = 50;
            TRIP_DETAILS_St[DAILY_TRIP_RESET].values.avg_speed = 50;
            TRIP_DETAILS_St[DAILY_TRIP_RESET].values.trip_total_distance_covered = 50;
        break;
        default:
            break;
        }
    }
}

uint32_t GetTripAverageMilege(uint8_t element)
{
    return TRIP_DETAILS_St[element].values.trip_avg_mileage;
}

uint32_t GetTripAverageSpeed(uint8_t element)
{
    return TRIP_DETAILS_St[element].values.avg_speed;
}

uint8_t GetTripTopSpeed(uint8_t element)
{
    return TRIP_DETAILS_St[element].values.trip_top_speed;
}

uint32_t GetTripBatteryConsumption(uint8_t element)
{
    return TRIP_DETAILS_St[element].values.battery_consumed;
}

uint32_t GetTripTimeValue(uint8_t element)
{
    return TRIP_DETAILS_St[element].values.trip_total_distance_covered;
}

uint32_t GetTripDistanceTravelled(uint8_t element)
{
    return TRIP_DETAILS_St[element].values.trip_total_time_travelled;
}

