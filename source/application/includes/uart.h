/*
 * uart.h
 *
 *  Created on: 03-Jul-2024
 *      Author: petla
 */

#ifndef APPLICATION_UART_UART_H_
#define APPLICATION_UART_UART_H_

#define BLE_LPUART            LPUART1
#define BLE_LPUART_CLK_FREQ   BOARD_DebugConsoleSrcFreq()
#define BLE_LPUART_IRQn       LPUART1_IRQn
#define BLE_LPUART_IRQHandler LPUART1_IRQHandler
#define DEMO_LPUART            LPUART12
#define DEMO_LPUART_CLK_FREQ   BOARD_DebugConsoleSrcFreq()
#define DEMO_LPUART_IRQn       LPUART12_IRQn
#define DEMO_LPUART_IRQHandler LPUART12_IRQHandler

#define BLE_UART_BUFFER_SIZE 200

enum frameTypes {
	BLE_STATUS = 1,
	PHONE_STATUS,
	NAV_DETAILS,
	INC_CALL,
	ONG_CALL,
	CALL_END,
	MIS_CALL_NTFY,
	RM_MIS_CALL_NTFY,
	RM_NAV_DETAILS
};

typedef struct {
	uint8_t signalStrenght;
	uint8_t batterylevel;
	uint8_t hour;
	uint8_t min;
	uint8_t sec;
	uint8_t Mer[2];
}phoneStatus;

typedef struct {
	uint8_t destLen;
	uint8_t destination[15];
	uint8_t ttLen;
	uint8_t travelTime[15];
	uint8_t etaLen;
	uint8_t ETA[10];
	uint8_t ddLen;
	uint8_t dirDist[10];
	uint8_t dirLen;
	uint8_t dir[30];
	uint8_t iconIdx;
}navigationDetails;

typedef struct {
	uint8_t nameLen;
	uint8_t name[30];
	uint8_t numberLen;
	uint8_t number[18];
}callFrame;

extern phoneStatus phnSts;
extern navigationDetails navDtls;
extern callFrame incCallFrm, ongCallFrm;
extern uint8_t callEndStatus;
extern uint8_t BLEStatus;
extern uint8_t uartDatareceived;
extern uint8_t frameType;
extern uint8_t setmissedCallNotify;
extern uint8_t resetMisCallNotify;
extern uint8_t removeNavNotify;
extern uint8_t speedbro;
extern uint8_t batterybro;
extern uint16_t odobro;
extern uint8_t tripbro;
extern uint8_t frontside;
extern uint8_t rearside;
extern uint8_t distance1;
extern uint8_t distance2;
extern void UART_TaskCreate();
extern void UART_TaskCreate12();
#endif /* APPLICATION_UART_UART_H_ */
