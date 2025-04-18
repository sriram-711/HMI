#include "rtc.h"
#include "presentation.h"

snvs_hp_rtc_datetime_t rtcDate;
snvs_lp_srtc_datetime_t srtcDate;
snvs_hp_rtc_config_t snvsRtcConfig;
snvs_lp_srtc_config_t snvsSrtcConfig;

uint8_t hour;
uint8_t minute;
uint8_t second;

void RtcInit()
{
    SNVS_HP_RTC_GetDefaultConfig(&snvsRtcConfig);
    SNVS_HP_RTC_Init(SNVS, &snvsRtcConfig);

    SNVS_LP_SRTC_GetDefaultConfig(&snvsSrtcConfig);
    SNVS_LP_SRTC_Init(SNVS, &snvsSrtcConfig);

    /* Set a start date time and start RT */
    srtcDate.year   = 2014U;
    srtcDate.month  = 12U;
    srtcDate.day    = 25U;
    srtcDate.hour   = 19U;
    srtcDate.minute = 0;
    srtcDate.second = 0;

    /* Set SRTC time to default time and date and start the SRTC */
    SNVS_LP_SRTC_SetDatetime(SNVS, &srtcDate);
    SNVS_LP_SRTC_StartTimer(SNVS);

    /* Synchronize RTC time and date with SRTC and start RTC */
    SNVS_HP_RTC_TimeSynchronize(SNVS);
    SNVS_HP_RTC_StartTimer(SNVS);

    RtcApp();
}

void RtcApp()
{
        /* Get date time */
        SNVS_HP_RTC_GetDatetime(SNVS, &rtcDate);
                /* print default time */
        PRINTF("Current time:%02hd:%02hd:%02hd\r\n",rtcDate.hour, rtcDate.minute, rtcDate.second);
        // setHour(rtcDate.hour);
        // setMinute(rtcDate.minute);
        // setSecond(rtcDate.second);
//        setTime(rtcDate.hour, rtcDate.minute, rtcDate.second);
               
}

void setHour(uint8_t hr)
{
    hour = hr;
}

void setMinute(uint8_t min)
{
    minute = min;
}

void setSecond(uint8_t sec)
{
    second = sec;
}

uint8_t getHour()
{
    return hour;
}

uint8_t getMinute()
{
    return minute;
}

uint8_t getSecond()
{
    return second;
}
