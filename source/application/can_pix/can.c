/*
 * can.c
 *
 *  Created on: 30-Apr-2024
 *      Author: sankar
 */
#include "FreeRTOS.h"
#include "task.h"
#include "fsl_debug_console.h"
#include "fsl_flexcan.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"
#include "can.h"

flexcan_handle_t flexcanHandle;
volatile bool txComplete = false;
volatile bool rxComplete = false;
volatile bool wakenUp    = false;
flexcan_mb_transfer_t txXfer, rxXfer;
flexcan_frame_t frame;
uint32_t txIdentifier;
uint32_t rxIdentifier;

typedef struct can_frame_
{
	uint8_t speedometer;
	uint8_t battery;
	uint8_t ridemode:3;
	uint8_t gearposition:3;
	uint8_t gearindicator:2;
	uint8_t adaptivelamp:3;
	uint8_t reserved1:1;
	uint8_t DRL:2;
	uint8_t tractioncontrol:2;
	uint8_t quickshifter:2;
	uint8_t cruise:2;
	uint8_t reserved2:4;
	uint32_t odometer:20;
}can_frame;

uint8_t g_can_rx_msg[8]={0};
can_frame can_rx_msg, last_can_msg;
uint8_t g_speedometer;
uint8_t g_battery;
uint8_t g_ridemode;
uint8_t g_gearpositiom;
uint8_t g_gearindicator;
uint8_t g_adaptivelamp;
uint8_t g_DRL;
uint8_t g_tractioncontrol;
uint8_t g_quickshifter;
uint8_t g_cruise;
uint32_t g_odometer;

void set_speedometer_value(uint8_t);
void set_battery_value(uint8_t);
void set_ridemode_value(uint8_t);
void set_gearposition_value(uint8_t);
void set_gearindicator_value(uint8_t);
void set_adaptivelamp_value(uint8_t);
void set_DRL_value(uint8_t);
void set_tractioncontrol_value(uint8_t);
void set_quickshifter_value(uint8_t);
void set_cruise_value(uint8_t);
void set_odometer_value(uint32_t);

void set_speedometer_value(uint8_t value)
{
     g_speedometer = value;
}
void set_battery_value(uint8_t value)
{
	g_battery = value;
}
void set_ridemode_value(uint8_t value)
{
	g_ridemode = value;
}
void set_gearposition_value(uint8_t value)
{
	g_gearpositiom = value;
}
void set_gearindicator_value(uint8_t value)
{
	g_gearindicator = value;
}
void set_adaptivelamp_value(uint8_t value)
{
	g_adaptivelamp = value;
}
void set_DRL_value(uint8_t value)
{
	g_DRL = value;
}
void set_tractioncontrol_value(uint8_t value)
{
	g_tractioncontrol = value;
}

void set_quickshifter_value(uint8_t value)
{
	g_quickshifter = value;
}
void set_cruise_value(uint8_t value)
{
	g_cruise = value;
}
void set_odometer_value(uint32_t value)
{
	g_odometer = value;
}

uint8_t get_speedometer_value(void)
{
     return g_speedometer;
}
uint8_t get_battery_value(void)
{
	return g_battery;
}

uint8_t get_ridemode_value(void)
{
	return g_ridemode;
}
uint8_t get_gearposition_value(void)
{
	return g_gearpositiom;
}
uint8_t get_gearindicator_value(void)
{
	return g_gearindicator;
}
uint8_t get_adaptivelamp_value(void)
{
	return g_adaptivelamp;
}
uint8_t get_DRL_value(void)
{
	return g_DRL;
}
uint8_t get_tractioncontrol_value(void)
{
	return g_tractioncontrol;
}

uint8_t get_quickshifter_value(void)
{
	return g_quickshifter;
}
uint8_t get_cruise_value(void)
{
	return g_cruise;
}
uint32_t get_odometer_value(void)
{
	return g_odometer;
}

void cpy_can_data(flexcan_mb_transfer_t *rxcanmsg)
{
	memset(g_can_rx_msg, 0, sizeof(g_can_rx_msg));

	g_can_rx_msg[0] = rxcanmsg->frame->dataByte0;
	g_can_rx_msg[1] = rxcanmsg->frame->dataByte1;
	g_can_rx_msg[2] = rxcanmsg->frame->dataByte2;
	g_can_rx_msg[3] = rxcanmsg->frame->dataByte3;
	g_can_rx_msg[4] = rxcanmsg->frame->dataByte4;
	g_can_rx_msg[5] = rxcanmsg->frame->dataByte5;
	g_can_rx_msg[6] = rxcanmsg->frame->dataByte6;
	g_can_rx_msg[7] = rxcanmsg->frame->dataByte7;
}

void CAN_Rx_message_buffer()
{
	cpy_can_data(&rxXfer);

	memcpy(&can_rx_msg,&g_can_rx_msg, DLC);

	set_speedometer_value(can_rx_msg.speedometer);
	set_battery_value(can_rx_msg.battery);
	set_ridemode_value(can_rx_msg.ridemode);
	set_gearposition_value(can_rx_msg.gearposition);
	set_gearindicator_value(can_rx_msg.gearindicator);
	set_adaptivelamp_value(can_rx_msg.adaptivelamp);
	set_DRL_value(can_rx_msg.DRL);
	set_tractioncontrol_value(can_rx_msg.tractioncontrol);
	set_quickshifter_value(can_rx_msg.quickshifter);
	set_cruise_value(can_rx_msg.cruise);
	set_odometer_value(can_rx_msg.odometer);
}

static FLEXCAN_CALLBACK(flexcan_callback)
{
    switch (status)
    {
        case kStatus_FLEXCAN_RxIdle:
            if (RX_MESSAGE_BUFFER_NUM == result)
            {
                rxComplete = true;
                CAN_Rx_message_buffer();
            }
            break;

        case kStatus_FLEXCAN_TxIdle:
            if (TX_MESSAGE_BUFFER_NUM == result)
            {
                txComplete = true;
            }
            break;

        case kStatus_FLEXCAN_WakeUp:
            wakenUp = true;
            break;

        default:
            break;
    }
}


static void CAN_AppTask(void *param)
{
    flexcan_config_t flexcanConfig;
    flexcan_rx_mb_config_t mbConfig;

    /*Clock setting for FLEXCAN*/
    clock_root_config_t rootCfg = {0};
    rootCfg.mux                 = FLEXCAN_CLOCK_SOURCE_SELECT;
    rootCfg.div                 = FLEXCAN_CLOCK_SOURCE_DIVIDER;
    CLOCK_SetRootClock(kCLOCK_Root_Can3, &rootCfg);

    /* Select mailbox ID. */
    rxIdentifier = 0;

    /* Get FlexCAN module default Configuration. */
    /*
     * flexcanConfig.clkSrc                 = kFLEXCAN_ClkSrc0;
     * flexcanConfig.bitRate               = 1000000U;
     * flexcanConfig.bitRateFD             = 2000000U;
     * flexcanConfig.maxMbNum               = 16;
     * flexcanConfig.enableLoopBack         = false;
     * flexcanConfig.enableSelfWakeup       = false;
     * flexcanConfig.enableIndividMask      = false;
     * flexcanConfig.disableSelfReception   = false;
     * flexcanConfig.enableListenOnlyMode   = false;
     * flexcanConfig.enableDoze             = false;
     */
    FLEXCAN_GetDefaultConfig(&flexcanConfig);

    flexcanConfig.bitRate = 500000U;

#if (defined(USE_IMPROVED_TIMING_CONFIG) && USE_IMPROVED_TIMING_CONFIG)
    flexcan_timing_config_t timing_config;
    memset(&timing_config, 0, sizeof(flexcan_timing_config_t));
    if (FLEXCAN_CalculateImprovedTimingValues(EXAMPLE_CAN, flexcanConfig.bitRate, EXAMPLE_CAN_CLK_FREQ, &timing_config))
    {
        /* Update the improved timing configuration*/
        memcpy(&(flexcanConfig.timingConfig), &timing_config, sizeof(flexcan_timing_config_t));
    }
    else
    {
        LOG_INFO("No found Improved Timing Configuration. Just used default configuration\r\n\r\n");
    }
#endif

    FLEXCAN_Init(EXAMPLE_CAN, &flexcanConfig, EXAMPLE_CAN_CLK_FREQ);

    /* Create FlexCAN handle structure and set call back function. */
    FLEXCAN_TransferCreateHandle(EXAMPLE_CAN, &flexcanHandle, flexcan_callback, NULL);

    /* Set Rx Masking mechanism. */
    FLEXCAN_SetRxMbGlobalMask(EXAMPLE_CAN, FLEXCAN_RX_MB_STD_MASK(rxIdentifier, 0, 0));

    /* Setup Rx Message Buffer. */
    mbConfig.format = kFLEXCAN_FrameFormatStandard;
    mbConfig.type   = kFLEXCAN_FrameTypeData;
    mbConfig.id     = FLEXCAN_ID_STD(rxIdentifier);
    FLEXCAN_SetRxMbConfig(EXAMPLE_CAN, RX_MESSAGE_BUFFER_NUM, &mbConfig, true);

    for (;;)
    {
        /* Start receive data through Rx Message Buffer. */
        rxXfer.mbIdx = (uint8_t)RX_MESSAGE_BUFFER_NUM;
        frame.id     = FLEXCAN_ID_STD(rxIdentifier);
        frame.format = (uint8_t)kFLEXCAN_FrameFormatStandard;
        frame.type   = (uint8_t)kFLEXCAN_FrameTypeData;
        frame.length = (uint8_t)DLC;
        rxXfer.frame = &frame;

        (void)FLEXCAN_TransferReceiveNonBlocking(EXAMPLE_CAN, &flexcanHandle, &rxXfer);
        /* Wait until Rx MB full. */
		while (!rxComplete)
        {
        };
        rxComplete = false;
    }
}

void CAN_TaskCreate(void)
{
	BaseType_t stat2;
	//BOARD_InitCANPins();

	stat2 = xTaskCreate(CAN_AppTask, "lvg2", configMINIMAL_STACK_SIZE + 800, NULL, tskIDLE_PRIORITY + 1, NULL);
	if (pdPASS != stat2)
	{
		PRINTF("Failed to create lvg2 task");
		while (1)
			;
	}
}

