/*
 * Copyright 2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "FreeRTOS.h"
#include "task.h"
#include "fsl_debug_console.h"
#include "lvgl_support.h"
#include "pin_mux.h"
#include "board.h"
#include "lvgl.h"
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"
#include "lvgl_demo_utils.h"
#include "lvgl_freertos.h"
#include "pin_mux.h"
#include "fsl_soc_src.h"
#include "application/includes/presentation.h"
#include "application/includes/can.h"
#include "application/includes/trip_details.h"
#include "application/includes/uart.h"
#include "application/includes/rtc.h"
#include "fsl_gpt.h"


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

#define PORT_GPIO3               GPIO3
#define PORT_GPIO13               GPIO13
#define GPIO3_0_15_IRQ           GPIO3_Combined_0_15_IRQn
#define GPIO3_0_15_IRQHandler    GPIO3_Combined_0_15_IRQHandler
#define GPIO13_0_31_IRQ           GPIO13_Combined_0_31_IRQn
#define GPIO13_0_31_IRQHandler    GPIO13_Combined_0_31_IRQHandler
#define GPIO_PIN_2               (2U)
#define GPIO_PIN_3               (3U)
#define GPIO_PIN_4               (4U)
#define GPIO_PIN_5               (5U)
#define GPIO_PIN_6               (6U)

#define BUTTON_2         "BUTTON_2"
#define BUTTON_3         "BUTTON_3"
#define BUTTON_4         "BUTTON_4"
#define BUTTON_5         "BUTTON_5"
#define BUTTON_6         "BUTTON_6"

#define BUTTON_RIGHT  	2
#define BUTTON_LEFT		3
#define BUTTON_DOWN		4
#define BUTTON_UP		5
#define WHEEL_CIRCUMFERENCE 2.29 // in meters
#define SECONDS_PER_HOUR 3600.0
#define METERS_TO_KM 0.001
volatile int pulseCount = 0;
volatile unsigned long lastPulseTime = 0;
volatile unsigned long lastTimeBetweenPulses = 0;
#define DEBOUNCE_TIME 50

float wheelCircumference = 2.29;  // Wheel circumference in meters
float speed = 0;
float tripDistance = 0.0;
float odometer = 0.0;
unsigned long lastTime = 0;

unsigned long idleTimeout = 2000;
unsigned long lastMovementTime = 0;

volatile uint32_t last_pulse_time = 0;
volatile uint32_t current_pulse_time = 0;

volatile float speed_kmph = 0.0;
unsigned long currentTime=0;

void Init_GPT(void) ;
unsigned long calib=0;
/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief delay a while.
 */

/*******************************************************************************
 * Variables
 ******************************************************************************/
/* Whether the SW is turned on */
volatile bool button_pressed = false;
/*******************************************************************************
 * Variables
 ******************************************************************************/
static volatile bool s_lvgl_initialized = false;
lv_ui guider_ui;
uint32_t gpt_freq=0;
uint32_t gpt_ticks=0;

uint32_t millis() {
     gpt_ticks = GPT_GetCurrentTimerCount(GPT1); // Get current GPT counter value
     gpt_freq = CLOCK_GetFreq(kCLOCK_OscRc16M);    // Get GPT clock frequency
      calib=GPT_GetCurrentTimerCount(GPT1) / (gpt_freq / 1000);
    // calib=calib*0.04087;
   // calib=calib*1000;
     return calib;
  //  return (gpt_ticks * 1000U) / gpt_freq;  // Convert GPT ticks to milliseconds


}

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

#if LV_USE_LOG
static void print_cb(const char *buf)
{
	PRINTF("\r%s\n", buf);
}
#endif

static uint32_t get_idle_time_cb(void)
{
	return (getIdleTaskTime() / 1000);
}

static void reset_idle_time_cb(void)
{
	resetIdleTaskTime();
}


static void HMI_AppTask(void *param)
{
#if LV_USE_LOG
	lv_log_register_print_cb(print_cb);
#endif

	lv_timer_register_get_idle_cb(get_idle_time_cb);
	lv_timer_register_reset_idle_cb(reset_idle_time_cb);
	lv_port_pre_init();
	lv_init();
	lv_port_disp_init();
	lv_port_indev_init();

	s_lvgl_initialized = true;

	setup_ui(&guider_ui);
	events_init(&guider_ui);
	custom_init(&guider_ui);

	//called for presentation.c
	set_ui(&guider_ui);

	/* Define the init structure for the input switch pin */
	gpio_pin_config_t sw_config = {
				kGPIO_DigitalInput,
				0,
				kGPIO_IntRisingEdge,
		};

	/* Init input switch GPIO. */
	EnableIRQ(GPIO13_0_31_IRQ);
	GPIO_PinInit(PORT_GPIO13, GPIO_PIN_3, &sw_config);
	GPIO_PinInit(PORT_GPIO13, GPIO_PIN_4, &sw_config);
	GPIO_PinInit(PORT_GPIO13, GPIO_PIN_5, &sw_config);
	GPIO_PinInit(PORT_GPIO13, GPIO_PIN_6, &sw_config);

	/* Enable GPIO pin interrupt */
	GPIO_PortEnableInterrupts(PORT_GPIO13, 1U << GPIO_PIN_3);
	GPIO_PortEnableInterrupts(PORT_GPIO13, 1U << GPIO_PIN_4);
	GPIO_PortEnableInterrupts(PORT_GPIO13, 1U << GPIO_PIN_5);
	GPIO_PortEnableInterrupts(PORT_GPIO13, 1U << GPIO_PIN_6);
	lastTime=millis();
	setApiValue();
	for (;;)
	{
		lv_task_handler();


//		if(button_pressed)
//		{
//			if (1 == GPIO_PinRead(PORT_GPIO13, GPIO_PIN_3))
//			{
//				//PRINTF("%s is pressed.\r\n", BUTTON_3);
//				setButtonValue(BUTTON_RIGHT);
//			}
//			else if (1 == GPIO_PinRead(PORT_GPIO13, GPIO_PIN_4))
//			{
//				//PRINTF("%s is pressed.\r\n", BUTTON_4);
//				setButtonValue(BUTTON_LEFT);
//				//PRINTF("%d \n", getButtonValue());
//			}
//			else if (1 == GPIO_PinRead(PORT_GPIO13, GPIO_PIN_5))
//			{
//				//PRINTF("%s is pressed.\r\n", BUTTON_5);
//				setButtonValue(BUTTON_DOWN);
//				//PRINTF("%d", getButtonValue());
//			}
//			else if (1 == GPIO_PinRead(PORT_GPIO13, GPIO_PIN_6))
//			{
//				//PRINTF("%s is pressed.\r\n", BUTTON_6);
//				setButtonValue(BUTTON_UP);
//				//PRINTF("%d", getButtonValue());
//			}
//			setMenuScreen();
//			button_pressed = false;
//		}
		 setSpeed(speedbro);
		 setBatteryPercentage(batterybro);
		 setOdometerValue(odobro);
		 setTripmeter(tripbro);
		 setdistance1(distance1);
		 setdistance2(distance2);
		 setCameraDetails1(frontside);
		 setCameraDetails2(rearside);
//		 currentTime = millis();
//					    if (currentTime - lastMovementTime > idleTimeout) {
//					        speed = 0;
//					        lastTimeBetweenPulses = 0;
//					        setSpeed(speed);
//					        //setBatteryPercentage( batt);
//					    }
//
//					    if (lastTimeBetweenPulses > 0) {
//					        speed = (wheelCircumference / (lastTimeBetweenPulses / 1000.0)) * 3.6;
//					        setSpeed(speed);
//					        //setBatteryPercentage( batt);
//					    }

					  //  lastTime=currentTime;
		if(uartDatareceived)	{
			if(frameType == PHONE_STATUS)	{
			//	setTime(phnSts.hour, phnSts.min, phnSts.sec);
			}
			uartDatareceived = 0;
		}
		setBLE_ConnectionStatus(BLEStatus);
		if(BLEStatus)	{
			setBLE_PhoneBatteryStatus(phnSts.batterylevel);
			setBLE_PhoneSignalStrengthStatus(phnSts.signalStrenght);
			setBLE_PhoneMissedCallStatus(setmissedCallNotify);
			setBLE_PhoneCallStatus(frameType);
			if(frameType == CALL_END)	{
				vTaskDelay(pdMS_TO_TICKS(1000));
				CallState = false;
				frameType = 0;
			}
			set_BLENavigationStatus(frameType, removeNavNotify);
			HomeScreen();
		}
		if(frameType == INC_CALL)	{

			setCallerName_Number(incCallFrm.name, incCallFrm.nameLen, incCallFrm.number, incCallFrm.numberLen);
		}	else if(frameType == ONG_CALL){
			setCallerName_Number(ongCallFrm.name, ongCallFrm.nameLen, ongCallFrm.number, ongCallFrm.numberLen);
		}	else if(frameType == CALL_END){
			setCallerName_Number(ongCallFrm.name, ongCallFrm.nameLen, ongCallFrm.number, ongCallFrm.numberLen);
		}

		if(frameType == NAV_DETAILS)	{
	//	setNavigationTurn_by_TurnInfo(navDtls.destination, navDtls.destLen, navDtls.ETA, navDtls.etaLen, navDtls.dirDist, navDtls.ddLen, navDtls.dir, navDtls.iconIdx);
		}
	}
}

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Interrupt service function of switch.
 */
void GPIO3_0_15_IRQHandler(void)
{
	GPIO_PortClearInterruptFlags(PORT_GPIO3, 1U << GPIO_PIN_2);
	GPIO_PortClearInterruptFlags(PORT_GPIO3, 1U << GPIO_PIN_3);
	GPIO_PortClearInterruptFlags(PORT_GPIO3, 1U << GPIO_PIN_4);
	GPIO_PortClearInterruptFlags(PORT_GPIO3, 1U << GPIO_PIN_5);
	//button_pressed = true;

	SDK_ISR_EXIT_BARRIER;
}
/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Interrupt service function of switch.
 */
uint32_t last_time, current_time, total_time;
void GPIO13_0_31_IRQHandler(void)
{
	GPIO_PortClearInterruptFlags(PORT_GPIO13, ((1U << GPIO_PIN_3) | (1U << GPIO_PIN_4) | (1U << GPIO_PIN_5) | (1U << GPIO_PIN_6)));

	 currentTime = millis();
		     if (currentTime - lastPulseTime > DEBOUNCE_TIME) {
		         lastTimeBetweenPulses = currentTime - lastPulseTime;
		         lastPulseTime = currentTime;
		         pulseCount++;
		         lastMovementTime = currentTime;
		     }
	SDK_ISR_EXIT_BARRIER;
}

/*******************************************************************************
 * Code
 ******************************************************************************/
#define RPI_ADDR  0x45
/* Get frequency of lpi2c clock */
#define LPI2C_CLOCK_FREQUENCY (CLOCK_GetFreq(kCLOCK_OscRc48MDiv2))
#define RPI_I2C_BASEADDR  LPI2C5

void talk_to_raspi(void)
{
	uint8_t tmp;
	uint8_t brightness = 0x80;

	BOARD_LPI2C_Init(RPI_I2C_BASEADDR, LPI2C_CLOCK_FREQUENCY);

	//    VIDEO_DelayMs(2000);

	//init_cmd_check
	//read_reg(RPI_ADDR, 0x80, &tmp);
	BOARD_LPI2C_Receive(RPI_I2C_BASEADDR, RPI_ADDR, 0x80, 1, &tmp, 1);
	PRINTF("reg 0x80 is 0x%x\r\n", tmp);

	//rpi_display_screen_power_up
	//write_reg(RPI_ADDR, 0x85, 0x00);
	tmp = 0;
	BOARD_LPI2C_Send(RPI_I2C_BASEADDR, RPI_ADDR, 0x85, 1, &tmp, 1);
	VIDEO_DelayMs(800);
	//write_reg(RPI_ADDR, 0x85, 0x01);
	tmp = 0x01;
	BOARD_LPI2C_Send(RPI_I2C_BASEADDR, RPI_ADDR, 0x85, 1, &tmp, 1);
	VIDEO_DelayMs(800);
	//write_reg(RPI_ADDR, 0x81, 0x04);
	tmp = 0x04;
	BOARD_LPI2C_Send(RPI_I2C_BASEADDR, RPI_ADDR, 0x81, 1, &tmp, 1);

	PRINTF("done\r\n");
	VIDEO_DelayMs(800);
	//rpi_display_set_bright
	//write_reg(RPI_ADDR, 0x86, brightness);
	BOARD_LPI2C_Send(RPI_I2C_BASEADDR, RPI_ADDR, 0x86, 1, &brightness, 1);
}
void Init_GPT(void) {
    gpt_config_t gptConfig;
    GPT_GetDefaultConfig(&gptConfig);
    gptConfig.clockSource = kGPT_ClockSource_Periph;

    GPT_Init(GPT1, &gptConfig);
    GPT_StartTimer(GPT1);


}
/*!
 * @brief Main function
 */
int main(void)
{
	BaseType_t stat;
	/* Init board hardware. */
	BOARD_ConfigMPU();
	BOARD_BootClockRUN();
//	BOARD_InitDebugConsole();
	Init_GPT();
	/*
	 * Reset the displaymix, otherwise during debugging, the
	 * debugger may not reset the display, then the behavior
	 * is not right.
	 */
	SRC_AssertSliceSoftwareReset(SRC, kSRC_DisplaySlice);

	BOARD_InitPins();
	BOARD_InitMipiPanelPins();
	BOARD_MIPIPanelTouch_I2C_Init();
//	BOARD_InitDebugConsole();
	DEMO_InitUsTimer();
	RtcInit();




	stat = xTaskCreate(HMI_AppTask, "HMI", configMINIMAL_STACK_SIZE + 8000, NULL, tskIDLE_PRIORITY + 2, NULL);

	if (pdPASS != stat)
	{
		PRINTF("Failed to create HMI task");
		while (1)
			;
	}

	CAN_TaskCreate(); //TASK 2 Initialization and Can Initialization

	TripVariableInit(); //for testing

	UART_TaskCreate();

	vTaskStartScheduler();

	for (;;)
	{
	} /* should never get here */
}

/*!
 * @brief Malloc failed hook.
 */
void vApplicationMallocFailedHook(void)
{
	PRINTF("Malloc failed. Increase the heap size.");

	for (;;)
		;
}

/*!
 * @brief FreeRTOS tick hook.
 */
void vApplicationTickHook(void)
{
	if (s_lvgl_initialized)
	{
		lv_tick_inc(1);
	}
}

/*!
 * @brief Stack overflow hook.
 */
void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName)
{
	(void)pcTaskName;
	(void)xTask;

	for (;;)
		;
}
