/*
 * can.h
 *
 *  Created on: 30-Apr-2024
 *      Author: sankar
 */

#ifndef APPLICATION_INCLUDES_CAN_H_
#define APPLICATION_INCLUDES_CAN_H_


#define EXAMPLE_CAN           CAN1
#define RX_MESSAGE_BUFFER_NUM (9)
#define TX_MESSAGE_BUFFER_NUM (8)
#define USE_CANFD             (0)

/* Select OSC24Mhz as master flexcan clock source */
#define FLEXCAN_CLOCK_SOURCE_SELECT (1U)
/* Clock divider for master flexcan clock source */
#define FLEXCAN_CLOCK_SOURCE_DIVIDER (1U)
/* Get frequency of flexcan clock */
#define EXAMPLE_CAN_CLK_FREQ ((CLOCK_GetRootClockFreq(kCLOCK_Root_Can3) / 100000U) * 100000U)
/* Set USE_IMPROVED_TIMING_CONFIG macro to use api to calculates the improved CAN / CAN FD timing values. */
#define USE_IMPROVED_TIMING_CONFIG (1U)
/* Fix MISRA_C-2012 Rule 17.7. */
#define LOG_INFO (void)PRINTF
#define DLC (8)

uint8_t get_speedometer_value(void);
uint8_t get_battery_value(void);
uint8_t get_ridemode_value(void);
uint8_t get_gearposition_value(void);
uint8_t get_gearindicator_value(void);
uint8_t get_adaptivelamp_value(void);
uint8_t get_DRL_value(void);
uint8_t get_tractioncontrol_value(void);
uint8_t get_quickshifter_value(void);
uint8_t get_cruise_value(void);
uint32_t get_odometer_value(void);


void CAN_TaskCreate(void);


#endif /* APPLICATION_INCLUDES_CAN_H_ */
