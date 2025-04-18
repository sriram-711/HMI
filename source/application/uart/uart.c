/*
 * uart.c
 *
 *  Created on: 03-Jul-2024
 *      Author: petla
 */
#include "FreeRTOS.h"
#include "task.h"
#include "fsl_debug_console.h"
#include "pin_mux.h"
#include "fsl_lpuart.h"
#include "board.h"
#include "uart.h"

#define BLE_STATUS_LEN		1
#define PHONE_STATUS_LEN	7
#define NAV_DETAILS_LEN		86
#define INC_CALL_LEN		50
#define ONG_CALL_LEN		50

static uint16_t rxUartIndex; /* Index of the data to send out. */
static uint8_t BLEUartBuffer[BLE_UART_BUFFER_SIZE];
static uint16_t rxUartIndex1;
static uint8_t BLEUartBuffer1[BLE_UART_BUFFER_SIZE];


phoneStatus phnSts = {0};
navigationDetails navDtls = {0};
callFrame incCallFrm = {0}, ongCallFrm = {0};
uint8_t callEndStatus = 0;
uint8_t BLEStatus = 0;
uint8_t setmissedCallNotify = 0;
uint8_t resetMisCallNotify = 0;
uint8_t removeNavNotify = 0;
uint8_t uartDatareceived = 0;
uint8_t frameType = 0;
uint8_t speedbro =0;
uint8_t batterybro =0;
uint16_t odobro =0;
uint8_t tripbro =0;
uint8_t frontside =0;
uint8_t rearside =0;
uint8_t distance1 =0;
uint8_t distance2 =0;
static void setFrameType(const uint8_t type)
{
//	PRINTF("%s %d\n", __func__,type);
	frameType = type;
}

static void setBLEStatus(const uint8_t status)
{
//	PRINTF("%s\n", __func__);
	BLEStatus = status;
}

static void setPhnStatus(const uint8_t uartBuffer[])
{
//	PRINTF("%s\n", __func__);
	if(uartBuffer[0] == PHONE_STATUS_LEN)
	{
		phnSts.signalStrenght = uartBuffer[1];
		phnSts.batterylevel = uartBuffer[2];
		phnSts.hour = uartBuffer[3];
		phnSts.min = uartBuffer[4];
		phnSts.sec = uartBuffer[5];
		memcpy(phnSts.Mer, uartBuffer+6, 2);
	}
	else
	{
		//invalid len
	}
}

static void setNavDetails(const uint8_t uartBuffer[])
{
//	PRINTF("%s\n", __func__);
	if(uartBuffer[0] == NAV_DETAILS_LEN)
	{
		navDtls.destLen = uartBuffer[1];
		if(navDtls.destLen != 0) {
			memcpy(navDtls.destination, uartBuffer+2, navDtls.destLen);
		} else {
			memset(navDtls.destination, 0, sizeof(navDtls.destination));
		}

		navDtls.ttLen = uartBuffer[17];
		if(navDtls.ttLen != 0) {
			memcpy(navDtls.travelTime, uartBuffer+18, navDtls.ttLen);
		} else {
			memset(navDtls.travelTime, 0, sizeof(navDtls.travelTime));
		}

		navDtls.etaLen = uartBuffer[33];
		if(navDtls.etaLen != 0) {
			memcpy(navDtls.ETA, uartBuffer+34, navDtls.etaLen);
		} else {
			memset(navDtls.ETA, 0, sizeof(navDtls.ETA));
		}

		navDtls.ddLen = uartBuffer[44];
		if(navDtls.ddLen != 0) {
			memcpy(navDtls.dirDist, uartBuffer+45, navDtls.ddLen);
		} else {
			memset(navDtls.dirDist, 0, sizeof(navDtls.dirDist));
		}

		navDtls.dirLen = uartBuffer[55];
		if(navDtls.dirLen != 0) {
			memcpy(navDtls.dir, uartBuffer+56, navDtls.dirLen);
		} else {
			memset(navDtls.dir, 0, sizeof(navDtls.dir));
		}

		navDtls.iconIdx = uartBuffer[86];
	}
	else
	{
		//invalid len
	}
}

static void setincCallFrame(const uint8_t uartBuffer[])
{
//	PRINTF("%s\n", __func__);
	if(uartBuffer[0] == INC_CALL_LEN)
	{
		incCallFrm.nameLen = uartBuffer[1];
		if(incCallFrm.nameLen != 0) {
			memcpy(incCallFrm.name, uartBuffer+2, incCallFrm.nameLen);
		} else {
			memset(incCallFrm.name, 0, sizeof(incCallFrm.name));
		}

		incCallFrm.numberLen = uartBuffer[32];
		if(incCallFrm.numberLen != 0) {
			memcpy(incCallFrm.number, uartBuffer+33, incCallFrm.numberLen);
		} else {
			memset(incCallFrm.number, 0, sizeof(incCallFrm.number));
		}
	}
	else
	{
		//invalid len
	}
}

static void setOngCallFrame(const uint8_t uartBuffer[])
{
//	PRINTF("%s\n", __func__);
	if(uartBuffer[0] == ONG_CALL_LEN)
	{
		ongCallFrm.nameLen = uartBuffer[1];
		if(ongCallFrm.nameLen != 0) {
			memcpy(ongCallFrm.name, uartBuffer+2, ongCallFrm.nameLen);
		} else {
			memset(ongCallFrm.name, 0, sizeof(ongCallFrm.name));
		}

		ongCallFrm.numberLen = uartBuffer[32];
		if(ongCallFrm.numberLen != 0) {
			memcpy(ongCallFrm.number, uartBuffer+33, ongCallFrm.numberLen);
		} else {
			memset(ongCallFrm.number, 0, sizeof(ongCallFrm.number));
		}
	}
	else
	{
		//invalid len
	}
}

static void setCallEnd(const uint8_t status)
{
//	PRINTF("%s\n", __func__);
	callEndStatus = status;
}

static void setMissedCallNotify(const uint8_t status)
{
//	PRINTF("%s\n", __func__);
	setmissedCallNotify = status;
}

static void resetMissedCallNotify(const uint8_t status)
{
//	PRINTF("%s\n", __func__);
	resetMisCallNotify = status;
}

static void resetNavNotify(const uint8_t status)
{
//	PRINTF("%s\n", __func__);
	removeNavNotify = status;
}
static void parseUartData(const uint8_t uartBuffer[], uint16_t rxLenght)
{
//	PRINTF("%s\n", __func__);
	if(uartBuffer[0] == 0xE6)
	{
		if(uartBuffer[1] == BLE_STATUS)
		{
			setFrameType(uartBuffer[1]);
			if(uartBuffer[2] == BLE_STATUS_LEN)
			{
				setBLEStatus(uartBuffer[3]);
				uartDatareceived = 1;
			}
			else
			{
				setFrameType(0);
				//invalid len
			}
		}
		else if(uartBuffer[1] == PHONE_STATUS)
		{
			setFrameType(uartBuffer[1]);
			if(uartBuffer[2] == PHONE_STATUS_LEN)
			{
				setPhnStatus(uartBuffer+2);
				uartDatareceived = 1;
			}
			else
			{
				setFrameType(0);
				//invalid len
			}
		}
		else if(uartBuffer[1] == NAV_DETAILS)
		{
			setFrameType(uartBuffer[1]);
			if(uartBuffer[2] == NAV_DETAILS_LEN)
			{
				setNavDetails(uartBuffer+2);
				resetNavNotify(0);
				uartDatareceived = 1;
			}
			else
			{
				setFrameType(0);
				//invalid len
			}
		}
		else if(uartBuffer[1] == INC_CALL)
		{
			resetNavNotify(1);
			setFrameType(uartBuffer[1]);
			if(uartBuffer[2] == INC_CALL_LEN)
			{
				setincCallFrame(uartBuffer+2);
				uartDatareceived = 1;
			}
			else
			{
				setFrameType(0);
				//invalid len
			}
		}
		else if(uartBuffer[1] == ONG_CALL)
		{
			resetNavNotify(1);
			setFrameType(uartBuffer[1]);
			if(uartBuffer[2] == ONG_CALL_LEN)
			{
				setOngCallFrame(uartBuffer+2);
				uartDatareceived = 1;
			}
			else
			{
				setFrameType(0);
				//invalid len
			}
		}
		else if(uartBuffer[1] == CALL_END)
		{
			resetNavNotify(1);
			setFrameType(uartBuffer[1]);
			setCallEnd(1);
			uartDatareceived = 1;
		}
		else if(uartBuffer[1] == MIS_CALL_NTFY)
		{
			setFrameType(uartBuffer[1]);
			setMissedCallNotify(1);
			uartDatareceived = 1;
		}
		else if(uartBuffer[1] == RM_MIS_CALL_NTFY)
		{
			setFrameType(uartBuffer[1]);
			resetMissedCallNotify(1);
			uartDatareceived = 1;
		}
		else if(uartBuffer[1] == RM_NAV_DETAILS)
		{
			setFrameType(uartBuffer[1]);
			resetNavNotify(1);
			uartDatareceived = 1;
		}
		else
		{
			setFrameType(0);
			//invalid frame type
		}
	}
	else
	{
		//invalid data
	}
}
void jetsonuart(const uint8_t uartBuffer[], uint16_t rxLenght)
{
	frontside=uartBuffer[1];
		rearside=uartBuffer[2];
		distance1=uartBuffer[3];
		//odobro=odobro<<8|uartBuffer[4];
		distance2=uartBuffer[4];
}
void BLE_LPUART_IRQHandler(void)
{
	uint8_t data;

    /* If new data arrived. */
    if ((kLPUART_RxDataRegFullFlag)&LPUART_GetStatusFlags(BLE_LPUART))
    {
        data = LPUART_ReadByte(BLE_LPUART);
        //0xe6
        if(data == 0x33) {
        	rxUartIndex = 0;
        }
        BLEUartBuffer[rxUartIndex] = data;
        rxUartIndex++;
        if(data == 0xF3) {
        	jetsonuart(BLEUartBuffer, rxUartIndex);
        	//parseUartData(BLEUartBuffer, rxUartIndex);
        //	speeduart(BLEUartBuffer,rxUartIndex);

        	rxUartIndex = 0;
        }
    }
}
void speeduart(const uint8_t uartBuffer[], uint16_t rxLenght)
{
	speedbro=uartBuffer[1];
	batterybro=uartBuffer[2];
	odobro=uartBuffer[3];
	odobro=odobro<<8|uartBuffer[4];
	tripbro=uartBuffer[5];
	//setSpeed(uartBuffer[1]);
	//setBatteryPercentage(uartBuffer[2]);
}
uint8_t mass=0;
void DEMO_LPUART_IRQHandler(void)
{
	uint8_t data;
mass++;
	    /* If new data arrived. */
	    if ((kLPUART_RxDataRegFullFlag)&LPUART_GetStatusFlags(DEMO_LPUART))
	    {
	        data = LPUART_ReadByte(DEMO_LPUART);
	        if(data == 0xF6) {
	//        	PRINTF("data receive begin\n");
	        	rxUartIndex1 = 0;
	        }
	        BLEUartBuffer1[rxUartIndex1] = data;
	        rxUartIndex1++;
	        if(data == 0xFB) {
	//        	PRINTF("data received \n");
	        //	parseUartData(BLEUartBuffer, rxUartIndex);
	        	speeduart(BLEUartBuffer1,rxUartIndex1);
	        	rxUartIndex1 = 0;
	        }
	    }


}
static void UART_AppTask()
{
	lpuart_config_t config;
    LPUART_GetDefaultConfig(&config);
    config.baudRate_Bps = BOARD_DEBUG_UART_BAUDRATE;
    config.enableTx     = true;
    config.enableRx     = true;

    if(LPUART_Init(BLE_LPUART, &config, BLE_LPUART_CLK_FREQ) != kStatus_Success) {
    	while(1);
    }

    LPUART_EnableInterrupts(BLE_LPUART, kLPUART_RxDataRegFullInterruptEnable);
    EnableIRQ(BLE_LPUART_IRQn);
//    LPUART12  //
    if(LPUART_Init(DEMO_LPUART, &config, DEMO_LPUART_CLK_FREQ) != kStatus_Success) {
      	while(1);
      }

      LPUART_EnableInterrupts(DEMO_LPUART, kLPUART_RxDataRegFullInterruptEnable);
      EnableIRQ(DEMO_LPUART_IRQn);

    for(;;) {

    }
}

void UART_TaskCreate()
{
	BaseType_t status;

	status = xTaskCreate(UART_AppTask, "UART", configMINIMAL_STACK_SIZE + 800, NULL, tskIDLE_PRIORITY + 1, NULL);
	if (pdPASS != status)
	{
		PRINTF("Failed to create uart task");
		while (1)
			;
	}
}
//static void UART_AppTask12();
/////new
//void UART_TaskCreate12()
//{
//	BaseType_t status;
//
//	status = xTaskCreate(UART_AppTask12, "UART", configMINIMAL_STACK_SIZE + 800, NULL, tskIDLE_PRIORITY + 1, NULL);
//	if (pdPASS != status)
//	{
//		PRINTF("Failed to create uart task");
//		while (1)
//			;
//	}
//}
////end new
//
////new/*
//static void UART_AppTask12()
//{
//	lpuart_config_t config;
//    LPUART_GetDefaultConfig(&config);
//    config.baudRate_Bps = BOARD_DEBUG_UART_BAUDRATE;
//    config.enableTx     = true;
//    config.enableRx     = true;
//
//    if(    LPUART_Init(DEMO_LPUART, &config, DEMO_LPUART_CLK_FREQ) != kStatus_Success) {
//    	while(1);
//    }
//    LPUART_ReadBlocking(DEMO_LPUART, rxbuff, sizeof(rxbuff));
//
//    		 // Copy received data to send buffer
//    for (int i = 0; i < 4; i++)
//   {
//    send[0] = rxbuff[0];
//   send[1] = rxbuff[1];
//    send[2] = rxbuff[2];
//   send[3] = rxbuff[3];
//   //received_odometer = (send[1] << 8) | send[2];
//  }batt=send[0];
//  setBatteryPercentage(batt);
//
//   // LPUART_EnableInterrupts(DEMO_LPUART, kLPUART_RxDataRegFullInterruptEnable);
//   // EnableIRQ(DEMO_LPUART_IRQn);
//
//
//    for(;;) {
//
//    }
//}
//end new
//new

//end new*/
