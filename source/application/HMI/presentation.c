/*
 * presentation.c
 *
 *  Created on: Apr 22, 2024
 *      Author: Admin
 */

#include "../includes/presentation.h"

lv_ui *present_ui;

uint16_t curentSpeedValue = 0;
uint8_t currentgearValue = 0;
uint8_t currentBatteryValue = 0;
uint8_t currentRideModeValue = 0;
uint8_t currentButtonValue = 0;
uint8_t currentBluetoothFrameType = 0;
uint8_t currentScreenType = 0;

void set_ui(lv_ui *ui)
{
	present_ui =ui;
}
void setSpeed(uint16_t speedValue)	{
	lv_img_set_angle(present_ui->baseScreen_speedometerNeedle, speedValue*15);


	/*
	 * lv_anim_t anim;
lv_anim_init(&anim);
lv_anim_set_var(&anim, needle_image); // Assuming you have an image for the needle
lv_anim_set_values(&anim, 0, 180);     // Rotate from 0 to 180 degrees
lv_anim_set_time(&anim, 500);          // Animation duration 500ms
lv_anim_set_exec_cb(&anim, set_needle_angle); // Callback function to set angle
lv_anim_start(&anim);
	 */

	char speedstring[5] ={0};
	sprintf(speedstring, "%d", speedValue);
	lv_label_set_text(present_ui->baseScreen_speedometerValue, speedstring);
	lv_label_set_text(present_ui->baseScreen_speedometerMenuValue, speedstring);
}

void setRideMode(uint8_t rideModeValue)	{
	switch (rideModeValue)	{
	case RM_ERROR:
		lv_obj_set_style_img_opa(present_ui->baseScreen_ecoImage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_img_opa(present_ui->baseScreen_autoImage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_img_opa(present_ui->baseScreen_powerImage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		break;
	case RM_ECONOMY:
		lv_obj_set_style_img_opa(present_ui->baseScreen_ecoImage, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_img_opa(present_ui->baseScreen_autoImage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_img_opa(present_ui->baseScreen_powerImage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		break;
	case RM_AUTOMATIC:
		lv_obj_set_style_img_opa(present_ui->baseScreen_ecoImage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_img_opa(present_ui->baseScreen_autoImage, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_img_opa(present_ui->baseScreen_powerImage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		break;
	case RM_POWER:
		lv_obj_set_style_img_opa(present_ui->baseScreen_ecoImage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_img_opa(present_ui->baseScreen_autoImage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_img_opa(present_ui->baseScreen_powerImage, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
		break;
	default:
		break;
	}
}

// Battery Percentage
void setBatteryPercentage(uint8_t batteryPercentageValue)	{
	lv_obj_set_style_img_opa(present_ui->baseScreen_segment1, ((batteryPercentageValue > 0) ? 255 : 0), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(present_ui->baseScreen_segment2, ((batteryPercentageValue > 10) ? 255 : 0), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(present_ui->baseScreen_segment3, ((batteryPercentageValue > 20) ? 255 : 0), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(present_ui->baseScreen_segment4, ((batteryPercentageValue > 30) ? 255 : 0), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(present_ui->baseScreen_segment5, ((batteryPercentageValue > 40) ? 255 : 0), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(present_ui->baseScreen_segment6, ((batteryPercentageValue > 50) ? 255 : 0), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(present_ui->baseScreen_segment7, ((batteryPercentageValue > 60) ? 255 : 0), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(present_ui->baseScreen_segment8, ((batteryPercentageValue > 70) ? 255 : 0), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(present_ui->baseScreen_segment9, ((batteryPercentageValue > 80) ? 255 : 0), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(present_ui->baseScreen_segment10, ((batteryPercentageValue > 90) ? 255 : 0), LV_PART_MAIN|LV_STATE_DEFAULT);

	char batteruString[2] ={0};
	sprintf(batteruString, "%d %", batteryPercentageValue);
	lv_label_set_text(present_ui->baseScreen_batteryMenuvalue, batteruString);
	lv_label_set_text(present_ui->baseScreen_batteryIcon, batteruString);
}

// Odometer
void setOdometerValue(uint32_t odometerValue){
	char odoString[5] ={0};
	sprintf(odoString, "%d", odometerValue);
	lv_label_set_text(present_ui->baseScreen_TripA_Value, odoString);
}
void setTripmeter(uint32_t tripmeter)
{
	char TripString[5] ={0};
		sprintf(TripString, "%d", tripmeter);
		lv_label_set_text(present_ui->baseScreen_TripB_Value, TripString);
}
// Set Gear Shift Indicators
void setGearShiftIndicator(uint8_t gearValue, uint8_t gearShiftDirection)	{

	// Gear Value
	if(gearValue == GEAR_NEUTRAL)	{
		lv_label_set_text(present_ui->baseScreen_gearIndicatorValue, "N");
	}	else if(gearValue == GEAR_REVERSE)	{
		lv_label_set_text(present_ui->baseScreen_gearIndicatorValue, "R");
	}	else if(gearValue == GEAR_INVALID)	{
		lv_label_set_text(present_ui->baseScreen_gearIndicatorValue, "-");
	}	else	{
		char gearString[5] ={0};
		sprintf(gearString, "%d", gearValue);
		lv_label_set_text(present_ui->baseScreen_gearIndicatorValue, gearString);
	}

	// Gear Shift Arrow
	lv_obj_set_style_img_opa(present_ui->baseScreen_arrowButtons,
			((gearShiftDirection > GEAR_NOSHIFT) ? 255 : 0), LV_PART_MAIN|LV_STATE_DEFAULT);
	if(gearShiftDirection == GEAR_UPSHIFT)	{
		lv_img_set_angle(present_ui->baseScreen_arrowButtons, 0);
	}	else if(gearShiftDirection == GEAR_DOWNSHIFT)	{
		lv_img_set_angle(present_ui->baseScreen_arrowButtons, 180);
	}
}

// Adaptive Headlamp
void setAdaptiveHeadLampValue(uint32_t adaptiveHeadLampValue){

}

// DRL
void setDRLValue(uint32_t DRLValue){

}

// Traction Control
void setTractionControlValue(uint32_t tractionControlValue){

}

// Quick Shifter
void setQuickShifterValue(uint32_t quickShifterValue){

}

// Cruise Control
void setCruiseControlValue(uint32_t cruiseControlValue){

}

// TPMS
void setTPMS(uint8_t frontTPMS, uint8_t rearTPMS)	{
	char frontTPMSString[5] ={0};
	sprintf(frontTPMSString, "%d", frontTPMS);

	char rearTPMSString[5] ={0};
	sprintf(rearTPMSString, "%d", rearTPMS);
}

// Average Mileage
void setAverageMileage(uint16_t averageMileageValue)	{
	char Averagemileagestring[5] ={0};
	sprintf(Averagemileagestring, "%d", averageMileageValue);
}

// Instant Mileage
void setInstantMileage(uint16_t instantMileageValue)	{
	char Averagemileagestring[5] ={0};
	sprintf(Averagemileagestring, "%d", instantMileageValue);
}

// Top Speed
void setTopSpeed(uint16_t TopspeedValue)	{
	char Topspeedstring[5] ={0};
	sprintf(Topspeedstring, "%d", TopspeedValue);
}

// AverageSpeed
void setAverageSpeed(uint16_t AveragespeedValue)	{
	char Averagespeedstring[5] ={0};
	sprintf(Averagespeedstring, "%d", AveragespeedValue);
}

// 0 to 60
void set0to60(uint8_t inSeconds)	{
	char inSecondsString[5] = {0};
	sprintf(inSecondsString, "%02d s", inSeconds);
}

// Battery Efficiency
void setBateryEfficiency(uint8_t BatteryEfficiency)	{
	char BatteryEfficiencyString[5] = {0};
	sprintf(BatteryEfficiencyString, "%d", BatteryEfficiency);
}

// Button Input
void setButtonValue(uint8_t buttonValue)	{
	if(CallState == false)	{
		setUpDownLeftRightCount(buttonValue);
	}
}

bool CallState = 0;
bool NavigationState = 0;

void setCallState(bool callState)	{
	CallState = callState;
}
void setNavigationState(bool navigationState)	{
	NavigationState = navigationState;
}

void enableMainScreen()	{
	lv_obj_set_style_opa(present_ui->baseScreen_ringArea, OBJECT_OPAQUE, LV_PART_MAIN|LV_STATE_DEFAULT);
}
void disableMainScreen()	{
	lv_obj_set_style_opa(present_ui->baseScreen_ringArea, OBJECT_TRANSPARENT, LV_PART_MAIN|LV_STATE_DEFAULT);
}
void enableMenuScreen()	{
	lv_obj_set_style_opa(present_ui->baseScreen_menuWidget, OBJECT_OPAQUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_opa(present_ui->baseScreen_controllerIndicationContainer, OBJECT_OPAQUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_opa(present_ui->baseScreen_batteryMenuWidget, OBJECT_OPAQUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_opa(present_ui->baseScreen_speedometerMenuWidget, OBJECT_OPAQUE, LV_PART_MAIN|LV_STATE_DEFAULT);
}
void disableMenuScreen()	{
	lv_obj_set_style_opa(present_ui->baseScreen_menuWidget, OBJECT_TRANSPARENT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_opa(present_ui->baseScreen_controllerIndicationContainer, OBJECT_TRANSPARENT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_opa(present_ui->baseScreen_batteryMenuWidget, OBJECT_TRANSPARENT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_opa(present_ui->baseScreen_speedometerMenuWidget, OBJECT_TRANSPARENT, LV_PART_MAIN|LV_STATE_DEFAULT);
}
void enableBLECallScreen()	{
	lv_obj_set_style_opa(present_ui->baseScreen_batteryMenuWidget, OBJECT_OPAQUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_opa(present_ui->baseScreen_speedometerMenuWidget, OBJECT_OPAQUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_opa(present_ui->baseScreen_phoneCall_Navigation, OBJECT_OPAQUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_opa(present_ui->baseScreen_PhoneCall, OBJECT_OPAQUE, LV_PART_MAIN|LV_STATE_DEFAULT);
}
void disableBLECallScreen()	{
	lv_obj_set_style_opa(present_ui->baseScreen_batteryMenuWidget, OBJECT_TRANSPARENT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_opa(present_ui->baseScreen_speedometerMenuWidget, OBJECT_TRANSPARENT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_opa(present_ui->baseScreen_phoneCall_Navigation, OBJECT_TRANSPARENT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_opa(present_ui->baseScreen_PhoneCall, OBJECT_TRANSPARENT, LV_PART_MAIN|LV_STATE_DEFAULT);
}
void enableBLENavigationScreen()	{
	lv_obj_set_style_opa(present_ui->baseScreen_batteryMenuWidget, OBJECT_OPAQUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_opa(present_ui->baseScreen_speedometerMenuWidget, OBJECT_OPAQUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_opa(present_ui->baseScreen_phoneCall_Navigation, OBJECT_OPAQUE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_opa(present_ui->baseScreen_Navigation, OBJECT_OPAQUE, LV_PART_MAIN|LV_STATE_DEFAULT);
}
void disableBLENavigationScreen()	{
	lv_obj_set_style_opa(present_ui->baseScreen_batteryMenuWidget, OBJECT_TRANSPARENT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_opa(present_ui->baseScreen_speedometerMenuWidget, OBJECT_TRANSPARENT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_opa(present_ui->baseScreen_phoneCall_Navigation, OBJECT_TRANSPARENT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_opa(present_ui->baseScreen_Navigation, OBJECT_TRANSPARENT, LV_PART_MAIN|LV_STATE_DEFAULT);
}

void setCameraDetails1(uint8_t FrontvehicleType) {
    lv_obj_set_style_opa(present_ui->baseScreen_fg_car, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(present_ui->baseScreen_fg_bus, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(present_ui->baseScreen_fg_truck, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(present_ui->baseScreen_fg_bicycle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(present_ui->baseScreen_fg_motorcycle,0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(present_ui->baseScreen_fg_person, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(present_ui->baseScreen_fg_auto, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(present_ui->baseScreen_fg_unknown, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_opa(present_ui->baseScreen_fo_car, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(present_ui->baseScreen_fo_bus, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(present_ui->baseScreen_fo_truck, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(present_ui->baseScreen_fo_bicycle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(present_ui->baseScreen_fo_motorcycle,0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(present_ui->baseScreen_fo_person, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(present_ui->baseScreen_fo_auto, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(present_ui->baseScreen_fo_unknown, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_opa(present_ui->baseScreen_fb_car, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(present_ui->baseScreen_fb_bus, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(present_ui->baseScreen_fb_truck, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(present_ui->baseScreen_fb_bicycle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(present_ui->baseScreen_fb_motorcycle,0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(present_ui->baseScreen_fb_person, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(present_ui->baseScreen_fb_auto, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(present_ui->baseScreen_fb_unknown, 0, LV_PART_MAIN | LV_STATE_DEFAULT);



    switch (FrontvehicleType) {
        case 0:
        	lv_obj_set_style_opa(present_ui->baseScreen_fr_car, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_fr_bus, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_fr_truck, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_fr_bicycle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_fr_motorcycle,0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_fr_person, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_fr_auto, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_fr_unknown, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    break;

        case 1: // Car
            lv_obj_set_style_opa(present_ui->baseScreen_fr_unknown, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(present_ui->baseScreen_fr_person, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(present_ui->baseScreen_fr_bicycle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(present_ui->baseScreen_fr_motorcycle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(present_ui->baseScreen_fr_auto, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(present_ui->baseScreen_fr_car, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(present_ui->baseScreen_fr_truck, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(present_ui->baseScreen_fr_bus, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            break;
        case 2: // Bike
        	lv_obj_set_style_opa(present_ui->baseScreen_fr_unknown, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	            lv_obj_set_style_opa(present_ui->baseScreen_fr_person, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        	            lv_obj_set_style_opa(present_ui->baseScreen_fr_bicycle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	            lv_obj_set_style_opa(present_ui->baseScreen_fr_motorcycle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	            lv_obj_set_style_opa(present_ui->baseScreen_fr_auto, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	            lv_obj_set_style_opa(present_ui->baseScreen_fr_car, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	            lv_obj_set_style_opa(present_ui->baseScreen_fr_truck, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	            lv_obj_set_style_opa(present_ui->baseScreen_fr_bus, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            break;
        case 3: // Truck
        	lv_obj_set_style_opa(present_ui->baseScreen_fr_unknown, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                	            lv_obj_set_style_opa(present_ui->baseScreen_fr_person, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                	            lv_obj_set_style_opa(present_ui->baseScreen_fr_bicycle,255, LV_PART_MAIN | LV_STATE_DEFAULT);
                	            lv_obj_set_style_opa(present_ui->baseScreen_fr_motorcycle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                	            lv_obj_set_style_opa(present_ui->baseScreen_fr_auto, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                	            lv_obj_set_style_opa(present_ui->baseScreen_fr_car, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                	            lv_obj_set_style_opa(present_ui->baseScreen_fr_truck, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                	            lv_obj_set_style_opa(present_ui->baseScreen_fr_bus, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            break;
        case 4: // Bus
        	lv_obj_set_style_opa(present_ui->baseScreen_fr_unknown, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                	            lv_obj_set_style_opa(present_ui->baseScreen_fr_person, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                	            lv_obj_set_style_opa(present_ui->baseScreen_fr_bicycle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                	            lv_obj_set_style_opa(present_ui->baseScreen_fr_motorcycle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                	            lv_obj_set_style_opa(present_ui->baseScreen_fr_auto, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                	            lv_obj_set_style_opa(present_ui->baseScreen_fr_car, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                	            lv_obj_set_style_opa(present_ui->baseScreen_fr_truck, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                	            lv_obj_set_style_opa(present_ui->baseScreen_fr_bus, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            break;
        case 5: // Van
        	lv_obj_set_style_opa(present_ui->baseScreen_fr_unknown, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                	            lv_obj_set_style_opa(present_ui->baseScreen_fr_person, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                	            lv_obj_set_style_opa(present_ui->baseScreen_fr_bicycle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                	            lv_obj_set_style_opa(present_ui->baseScreen_fr_motorcycle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                	            lv_obj_set_style_opa(present_ui->baseScreen_fr_auto, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                	            lv_obj_set_style_opa(present_ui->baseScreen_fr_car, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                	            lv_obj_set_style_opa(present_ui->baseScreen_fr_truck, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                	            lv_obj_set_style_opa(present_ui->baseScreen_fr_bus, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            break;
        case 6: // SUV
        	lv_obj_set_style_opa(present_ui->baseScreen_fr_unknown, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                	            lv_obj_set_style_opa(present_ui->baseScreen_fr_person, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                	            lv_obj_set_style_opa(present_ui->baseScreen_fr_bicycle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                	            lv_obj_set_style_opa(present_ui->baseScreen_fr_motorcycle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                	            lv_obj_set_style_opa(present_ui->baseScreen_fr_auto, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                	            lv_obj_set_style_opa(present_ui->baseScreen_fr_car, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                	            lv_obj_set_style_opa(present_ui->baseScreen_fr_truck, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                	            lv_obj_set_style_opa(present_ui->baseScreen_fr_bus, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            break;
        case 7: // Bicycle
        	lv_obj_set_style_opa(present_ui->baseScreen_fr_unknown, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                	            lv_obj_set_style_opa(present_ui->baseScreen_fr_person, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                	            lv_obj_set_style_opa(present_ui->baseScreen_fr_bicycle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                	            lv_obj_set_style_opa(present_ui->baseScreen_fr_motorcycle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                	            lv_obj_set_style_opa(present_ui->baseScreen_fr_auto, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                	            lv_obj_set_style_opa(present_ui->baseScreen_fr_car, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                	            lv_obj_set_style_opa(present_ui->baseScreen_fr_truck, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                	            lv_obj_set_style_opa(present_ui->baseScreen_fr_bus, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            break;
        case 8: // Pedestrian
        	lv_obj_set_style_opa(present_ui->baseScreen_fr_unknown, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                	            lv_obj_set_style_opa(present_ui->baseScreen_fr_person, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                	            lv_obj_set_style_opa(present_ui->baseScreen_fr_bicycle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                	            lv_obj_set_style_opa(present_ui->baseScreen_fr_motorcycle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                	            lv_obj_set_style_opa(present_ui->baseScreen_fr_auto, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                	            lv_obj_set_style_opa(present_ui->baseScreen_fr_car, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                	            lv_obj_set_style_opa(present_ui->baseScreen_fr_truck, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                	            lv_obj_set_style_opa(present_ui->baseScreen_fr_bus,255, LV_PART_MAIN | LV_STATE_DEFAULT);
            break;
        default:
            // No vehicle detected, all remain hidden
            break;
    }
}
void setdistance1(uint8_t dis)
{
	char distance[5] ={0};
		sprintf(distance, "%d",dis);
	lv_label_set_text(present_ui->baseScreen_vehicle1_dist, distance);
}
void setdistance2(uint8_t dis)
{
	char distance[5] ={0};
		sprintf(distance, "%d",dis);
		lv_label_set_text(present_ui->baseScreen_vehicle2_dist, distance);
}
void setCameraDetails2(uint8_t RearvehicleType) {
    lv_obj_set_style_opa(present_ui->baseScreen_rg_car, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(present_ui->baseScreen_rg_bus, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(present_ui->baseScreen_rg_truck, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(present_ui->baseScreen_rg_bicycle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(present_ui->baseScreen_rg_motorcycle,0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(present_ui->baseScreen_rg_person, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(present_ui->baseScreen_rg_auto, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(present_ui->baseScreen_rg_unknown, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_opa(present_ui->baseScreen_ro_car, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(present_ui->baseScreen_ro_bus, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(present_ui->baseScreen_ro_truck, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(present_ui->baseScreen_ro_bicycle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(present_ui->baseScreen_ro_motorcycle,0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(present_ui->baseScreen_ro_person, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(present_ui->baseScreen_ro_auto, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(present_ui->baseScreen_ro_unknown, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_opa(present_ui->baseScreen_rb_car, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(present_ui->baseScreen_rb_bus, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(present_ui->baseScreen_rb_truck, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(present_ui->baseScreen_rb_bicycle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(present_ui->baseScreen_rb_motorcycle,0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(present_ui->baseScreen_rb_person, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(present_ui->baseScreen_rb_auto, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(present_ui->baseScreen_rb_unknown, 0, LV_PART_MAIN | LV_STATE_DEFAULT);



    switch (RearvehicleType) {

    case 0:

        lv_obj_set_style_opa(present_ui->baseScreen_rr_car, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_opa(present_ui->baseScreen_rr_bus, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_opa(present_ui->baseScreen_rr_truck, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_opa(present_ui->baseScreen_rr_bicycle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_opa(present_ui->baseScreen_rr_motorcycle,0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_opa(present_ui->baseScreen_rr_person, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_opa(present_ui->baseScreen_rr_auto, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_opa(present_ui->baseScreen_rr_unknown, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        break;

        case 1: // Car
        	 lv_obj_set_style_opa(present_ui->baseScreen_rr_car, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_bus, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_truck, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_bicycle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_motorcycle,0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_person, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_auto, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_unknown, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            break;
        case 2: // Bike
        	 lv_obj_set_style_opa(present_ui->baseScreen_rr_car, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_bus, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_truck, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_bicycle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_motorcycle,0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_person, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_auto, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_unknown, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            break;
        case 3: // Truck
        	 lv_obj_set_style_opa(present_ui->baseScreen_rr_car, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_bus, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_truck, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_bicycle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_motorcycle,0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_person, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_auto, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_unknown, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            break;
        case 4: // Bus
        	 lv_obj_set_style_opa(present_ui->baseScreen_rr_car, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_bus, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_truck, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_bicycle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_motorcycle,255, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_person, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_auto, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_unknown, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            break;
        case 5: // Van
        	 lv_obj_set_style_opa(present_ui->baseScreen_rr_car, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_bus, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_truck, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_bicycle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_motorcycle,0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_person, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_auto, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_unknown, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            break;
        case 6: // SUV
        	 lv_obj_set_style_opa(present_ui->baseScreen_rr_car, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_bus, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_truck, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_bicycle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_motorcycle,0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_person, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_auto, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_unknown, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            break;
        case 7: // Bicycle
        	 lv_obj_set_style_opa(present_ui->baseScreen_rr_car, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_bus, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_truck, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_bicycle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_motorcycle,0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_person, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_auto, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_unknown, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            break;
        case 8: // Pedestrian
        	 lv_obj_set_style_opa(present_ui->baseScreen_rr_car, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_bus,255, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_truck, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_bicycle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_motorcycle,0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_person, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_auto, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        	    lv_obj_set_style_opa(present_ui->baseScreen_rr_unknown, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            break;
        default:
            // No vehicle detected, all remain hidden
            break;
    }
}




void HomeScreen()	{
	if(getMenuLevel() == 0)	{
		disableMenuScreen();
		enableMainScreen();
		if(CallState && NavigationState){
			disableMainScreen();
			disableBLENavigationScreen();
			enableBLECallScreen();
		}	else if(CallState && !NavigationState)	{
			disableMainScreen();
			disableBLENavigationScreen();
			enableBLECallScreen();
		}	else if(!CallState && NavigationState)	{
			disableBLECallScreen();
			disableMainScreen();
			enableBLENavigationScreen();
		}	else if(!CallState && !NavigationState)	{
			disableBLECallScreen();
			disableBLENavigationScreen();
			enableMainScreen();
		}

		/*
		if((CallState && NavigationState) ||  CallState){
			disableBLENavigationScreen();
			disableMainScreen();
			enableBLECallScreen();
		}	else if(NavigationState && !CallState)	{
			disableBLECallScreen();
			disableMainScreen();
			enableBLENavigationScreen();
		}	else	{
			disableBLECallScreen();
			disableBLENavigationScreen();
			enableMainScreen();
		}
		 */

	}	else	{
		disableMainScreen();
		enableMenuScreen();
		if(CallState){
			disableBLENavigationScreen();
			disableMenuScreen();
			disableMainScreen();
			enableBLECallScreen();
		}	else	{
			disableMainScreen();
			disableBLECallScreen();
			disableBLENavigationScreen();
			enableMenuScreen();
		}
	}
}

void setBLE_ConnectionStatus(uint8_t BLE_Status)	{
	if(BLE_Status)	{
		lv_obj_set_pos(present_ui->baseScreen_phoneBluetooth, 180, 0);
		lv_obj_set_style_opa(present_ui->baseScreen_phoneBluetooth, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	//	lv_obj_set_style_opa(present_ui->baseScreen_PhoneBattery, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	//	lv_obj_set_style_opa(present_ui->baseScreen_phoneNetworkSignal, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_warnings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_messageInbox, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_missedCall, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	}	else	{
		lv_obj_set_pos(present_ui->baseScreen_phoneBluetooth, 300, 0);
		lv_obj_set_style_opa(present_ui->baseScreen_phoneBluetooth, 76, LV_PART_MAIN|LV_STATE_DEFAULT);
	//	lv_obj_set_style_opa(present_ui->baseScreen_PhoneBattery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	//	lv_obj_set_style_opa(present_ui->baseScreen_phoneNetworkSignal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_warnings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_messageInbox, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_missedCall, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	}
}
void setBLE_PhoneBatteryStatus(uint8_t BLE_PhoneBatteryStatus)	{
//	if(BLE_PhoneBatteryStatus >= 75)
//	lv_img_set_src(present_ui->baseScreen_PhoneBattery, &_batteryFullIcon_alpha_50x50);
//	else if(BLE_PhoneBatteryStatus >= 50 && BLE_PhoneBatteryStatus < 75)
//		lv_img_set_src(present_ui->baseScreen_PhoneBattery, &_batteryMidIcon_alpha_50x50);
//	else if(BLE_PhoneBatteryStatus >= 25 && BLE_PhoneBatteryStatus < 50)
//		lv_img_set_src(present_ui->baseScreen_PhoneBattery, &_batteryAverageIcon_alpha_50x50);
//	else if(BLE_PhoneBatteryStatus >= 5 && BLE_PhoneBatteryStatus < 25)
//		lv_img_set_src(present_ui->baseScreen_PhoneBattery, &_batteryLowIcon_alpha_50x50);
//	else if(BLE_PhoneBatteryStatus >= 0 && BLE_PhoneBatteryStatus < 5)
//		lv_img_set_src(present_ui->baseScreen_PhoneBattery, &_batteryTooLowIcon_alpha_50x50);
//	else
//		lv_img_set_src(present_ui->baseScreen_PhoneBattery, &_waringsIcon_alpha_50x50);
}
void setBLE_PhoneSignalStrengthStatus(uint8_t BLE_PhoneSignalStrengthStatus)	{
	switch (BLE_PhoneSignalStrengthStatus) {
	case 0:
//		lv_img_set_src(present_ui->baseScreen_phoneNetworkSignal, &_Signal0Icon_alpha_50x50);
		break;
	case 1:
//	lv_img_set_src(present_ui->baseScreen_phoneNetworkSignal, &_Signal1Icon_alpha_50x50);
		break;
	case 2:
//		lv_img_set_src(present_ui->baseScreen_phoneNetworkSignal, &_Signal2Icon_alpha_50x50);
		break;
	case 3:
//		lv_img_set_src(present_ui->baseScreen_phoneNetworkSignal, &_Signal3Icon_alpha_50x50);
		break;
	case 4:
//		lv_img_set_src(present_ui->baseScreen_phoneNetworkSignal, &_Signal4Icon_alpha_50x50);
		break;
	}
}
void setBLE_PhoneMissedCallStatus(uint8_t BLE_PhoneMissedCallStatus){
	if(BLE_PhoneMissedCallStatus)
		lv_obj_set_style_opa(present_ui->baseScreen_missedCall, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	else
		lv_obj_set_style_opa(present_ui->baseScreen_missedCall, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
}
//void setNavigationTurn_by_TurnInfo(uint8_t BLE_navDestination[], uint8_t BLE_navDestinationLength, uint8_t BLE_navETA[], uint8_t BLE_navETALength, uint8_t BLE_navDirection[], uint8_t BLE_navDirectionLength, uint8_t BLE_navDirectionType[], uint8_t BLE_navDirectionIconIndex)	{
//	lv_label_set_text(present_ui->baseScreen_turningDistance, BLE_navDestination);
//	lv_label_set_text(present_ui->baseScreen_ETA, BLE_navETA);
//	lv_label_set_text(present_ui->baseScreen_distance, BLE_navDirection);
//
//	switch (BLE_navDirectionIconIndex) {
//	case 0:
//		lv_img_set_src(present_ui->baseScreen_turnbyTurnSign, &_turnType_keepLane_alpha_256x256);
//		break;
//	case 1:
//		lv_img_set_src(present_ui->baseScreen_turnbyTurnSign, &_turnType_goStraight_alpha_256x256);
//		break;
//	case 2:
//		lv_img_set_src(present_ui->baseScreen_turnbyTurnSign, &_turnType_turnLeft_alpha_256x256);
//		break;
//	case 3:
//		lv_img_set_src(present_ui->baseScreen_turnbyTurnSign, &_turnType_turnRight_alpha_256x256);
//		break;
//	case 4:
//		lv_img_set_src(present_ui->baseScreen_turnbyTurnSign, &_turnType_turnSlightlyLeft_alpha_256x256);
//		break;
//	case 5:
//		lv_img_set_src(present_ui->baseScreen_turnbyTurnSign, &_turnType_turnSlightlyRight_alpha_256x256);
//		break;
//	case 6:
//		lv_img_set_src(present_ui->baseScreen_turnbyTurnSign, &_turnType_roundAboutLeft_alpha_256x256);
//		break;
//	case 7:
//		lv_img_set_src(present_ui->baseScreen_turnbyTurnSign, &_turnType_roundAboutRight_alpha_256x256);
//		break;
//	}
//}
void setCallerName_Number(uint8_t BLE_callername[], uint8_t BLE_callernameLength, uint8_t BLE_callernumber[], uint8_t BLE_callernumberLength)	{
	if(BLE_callernameLength != 0){
		lv_label_set_text(present_ui->baseScreen_callerName, BLE_callername);
		lv_label_set_text(present_ui->baseScreen_callerNumber, "from PhoneBook");
	}	else	{
		lv_label_set_text(present_ui->baseScreen_callerName, "Unknown");
		lv_label_set_text(present_ui->baseScreen_callerNumber, BLE_callernumber);
	}
}

void set_BLENavigationStatus(uint8_t BLE_FrameType, uint8_t BLE_navRmNtfy){
	if((BLE_FrameType == NAV_DETAILS) && (BLE_navRmNtfy == 0))	{
		lv_label_set_text(present_ui->baseScreen_bluetoothWidgetType, "Navigation");
		NavigationState = true;
	}	else	{
		NavigationState = false;
	}
}

void setBLE_PhoneCallStatus(uint8_t BLE_FrameType)	{
	if(BLE_FrameType == INC_CALL)	{
		CallState = true;
		lv_label_set_text(present_ui->baseScreen_bluetoothWidgetType, "Incoming Call");
		lv_obj_set_style_opa(present_ui->baseScreen_callTime, 76, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_AcceptCallButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_RejectCallButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	//	lv_obj_set_style_opa(present_ui->baseScreen_callAcceptRejectInfo, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	}	else if(BLE_FrameType == ONG_CALL)	{
		CallState = true;
		lv_label_set_text(present_ui->baseScreen_bluetoothWidgetType, "Ongoing Call");
		lv_obj_set_style_opa(present_ui->baseScreen_callTime, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
//		lv_obj_set_style_opa(present_ui->baseScreen_callAcceptRejectInfo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_AcceptCallButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_RejectCallButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	} 	else if(BLE_FrameType == CALL_END)	{
		CallState = true;
		lv_label_set_text(present_ui->baseScreen_bluetoothWidgetType, "Call Ended");
		lv_obj_set_style_opa(present_ui->baseScreen_AcceptCallButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_RejectCallButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	//	lv_obj_set_style_opa(present_ui->baseScreen_callAcceptRejectInfo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	}	else	{
		CallState = false;
	}
}

void setMenuScreen()	{
	uint8_t leftRightCount = getMenuLevel();
	uint8_t upDownCount = getMenuOption();
	if(0 == leftRightCount)	{
		disableMenuScreen();
		if(CallState == false)
			enableMainScreen();
	}
	if(1 == leftRightCount){
		lv_obj_set_style_opa(present_ui->baseScreen_menuScrollBar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_label_set_text(present_ui->baseScreen_menuHeading, "Menu");
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeOne, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeTwo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeThree, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeFour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeFive, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeSix, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeSeven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeEight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeNine, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeTen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeEleven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

		lv_obj_set_style_opa(present_ui->baseScreen_optionOne, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_optionTwo, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_optionThree, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_optionFour, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_optionFive, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

		lv_label_set_text(present_ui->baseScreen_optionOne, "Trip settings");
		lv_label_set_text(present_ui->baseScreen_optionTwo, "Vehicle");
		lv_label_set_text(present_ui->baseScreen_optionThree, "Bluetooth settings");
		lv_label_set_text(present_ui->baseScreen_optionFour, "Preferences");
		lv_label_set_text(present_ui->baseScreen_optionFive, "Customization");

		switch( upDownCount)	{
		case 0:
			setMenuLoaded(MENU_TRIPDETAILS);
			lv_obj_set_y(present_ui->baseScreen_menuSelectedCategoryIcon, 0);
			lv_obj_set_style_img_opa(present_ui->baseScreen_tripSettings, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_img_opa(present_ui->baseScreen_vehicleData, 76, LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_img_opa(present_ui->baseScreen_bluetoothSettings, 76, LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_img_opa(present_ui->baseScreen_preferences, 76, LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_img_opa(present_ui->baseScreen_rideModeData, 76, LV_PART_MAIN|LV_STATE_DEFAULT);

			lv_obj_set_style_text_color(present_ui->baseScreen_optionOne, lv_color_hex(0x00A0EE), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionTwo, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionThree, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionFour, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionFive, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			break;
		case 1:
			setMenuLoaded(MENU_VEHICLE);
			lv_obj_set_y(present_ui->baseScreen_menuSelectedCategoryIcon, 144);
			lv_obj_set_style_img_opa(present_ui->baseScreen_tripSettings, 76, LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_img_opa(present_ui->baseScreen_vehicleData, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_img_opa(present_ui->baseScreen_bluetoothSettings, 76, LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_img_opa(present_ui->baseScreen_preferences, 76, LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_img_opa(present_ui->baseScreen_rideModeData, 76, LV_PART_MAIN|LV_STATE_DEFAULT);

			lv_obj_set_style_text_color(present_ui->baseScreen_optionOne, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionTwo, lv_color_hex(0x00A0EE), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionThree, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionFour, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionFive, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);

			break;
		case 2:
			setMenuLoaded(MENU_BLUETOOTH);
			lv_obj_set_y(present_ui->baseScreen_menuSelectedCategoryIcon, 288);
			lv_obj_set_style_img_opa(present_ui->baseScreen_tripSettings, 76, LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_img_opa(present_ui->baseScreen_vehicleData, 76, LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_img_opa(present_ui->baseScreen_bluetoothSettings, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_img_opa(present_ui->baseScreen_preferences, 76, LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_img_opa(present_ui->baseScreen_rideModeData, 76, LV_PART_MAIN|LV_STATE_DEFAULT);

			lv_obj_set_style_text_color(present_ui->baseScreen_optionOne, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionTwo, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionThree, lv_color_hex(0x00A0EE), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionFour, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionFive, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			break;
		case 3:
			setMenuLoaded(MENU_PREFERENCES);
			lv_obj_set_y(present_ui->baseScreen_menuSelectedCategoryIcon, 432);
			lv_obj_set_style_img_opa(present_ui->baseScreen_tripSettings, 76, LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_img_opa(present_ui->baseScreen_vehicleData, 76, LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_img_opa(present_ui->baseScreen_bluetoothSettings, 76, LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_img_opa(present_ui->baseScreen_preferences, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_img_opa(present_ui->baseScreen_rideModeData, 76, LV_PART_MAIN|LV_STATE_DEFAULT);

			lv_obj_set_style_text_color(present_ui->baseScreen_optionOne, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionTwo, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionThree, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionFour, lv_color_hex(0x00A0EE), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionFive, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			break;
		case 4:
			setMenuLoaded(MENU_CUSTOMIZATION);
			lv_obj_set_y(present_ui->baseScreen_menuSelectedCategoryIcon, 576);
			lv_obj_set_style_img_opa(present_ui->baseScreen_tripSettings, 76, LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_img_opa(present_ui->baseScreen_vehicleData, 76, LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_img_opa(present_ui->baseScreen_bluetoothSettings, 76, LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_img_opa(present_ui->baseScreen_preferences, 76, LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_img_opa(present_ui->baseScreen_rideModeData, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

			lv_obj_set_style_text_color(present_ui->baseScreen_optionOne, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionTwo, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionThree, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionFour, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionFive, lv_color_hex(0x00A0EE), LV_PART_MAIN|LV_STATE_DEFAULT);
			break;
		default:
			break;
		}
	}
	if(2 == leftRightCount && (getMenuLoaded() == MENU_TRIPDETAILS))	{
		lv_obj_set_style_opa(present_ui->baseScreen_menuScrollBar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_label_set_text(present_ui->baseScreen_menuHeading, "Trip settings");
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeOne, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeTwo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeThree, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeFour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeFive, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeSix, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeSeven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeEight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeNine, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeTen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeEleven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

		lv_label_set_text(present_ui->baseScreen_optionOne, "Trip 1");
		lv_label_set_text(present_ui->baseScreen_optionTwo, "Trip 2");
		lv_label_set_text(present_ui->baseScreen_optionThree, "Trip 3");
		lv_label_set_text(present_ui->baseScreen_optionFour, "Daily trip");
		lv_obj_set_style_opa(present_ui->baseScreen_optionFive, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

		lv_obj_set_y(present_ui->baseScreen_menuSelectedCategoryIcon, 0);
		lv_obj_set_style_img_opa(present_ui->baseScreen_tripSettings, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_img_opa(present_ui->baseScreen_vehicleData, 76, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_img_opa(present_ui->baseScreen_bluetoothSettings, 76, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_img_opa(present_ui->baseScreen_preferences, 76, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_img_opa(present_ui->baseScreen_rideModeData, 76, LV_PART_MAIN|LV_STATE_DEFAULT);

		switch( upDownCount)	{
		case 0:
			setSelectedTrip(TRIP_ONE);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionOne, lv_color_hex(0x00A0EE), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionTwo, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionThree, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionFour, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			break;
		case 1:
			setSelectedTrip(TRIP_TWO);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionOne, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionTwo, lv_color_hex(0x00A0EE), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionThree, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionFour, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			break;
		case 2:
			setSelectedTrip(TRIP_THREE);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionOne, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionTwo, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionThree, lv_color_hex(0x00A0EE), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionFour, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			break;
		case 3:
			setSelectedTrip(TRIP_DAILYTRIP);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionOne, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionTwo, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionThree, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionFour, lv_color_hex(0x00A0EE), LV_PART_MAIN|LV_STATE_DEFAULT);
			break;
		}
	}

	if(2 == leftRightCount && (getMenuLoaded() == MENU_VEHICLE))	{
		lv_obj_set_style_opa(present_ui->baseScreen_menuScrollBar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_label_set_text(present_ui->baseScreen_menuHeading, "Vehicle info");
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeOne, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeTwo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeThree, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeFour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeFive, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeSix, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeSeven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeEight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeNine, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeTen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeEleven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

		lv_label_set_text(present_ui->baseScreen_optionOne, "Service");
		lv_label_set_text(present_ui->baseScreen_optionTwo, "Performance");
		lv_label_set_text(present_ui->baseScreen_optionThree, "Documents");
		lv_obj_set_style_opa(present_ui->baseScreen_optionFour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_optionFive, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

		lv_obj_set_y(present_ui->baseScreen_menuSelectedCategoryIcon, 144);
		lv_obj_set_style_img_opa(present_ui->baseScreen_tripSettings, 76, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_img_opa(present_ui->baseScreen_vehicleData, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_img_opa(present_ui->baseScreen_bluetoothSettings, 76, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_img_opa(present_ui->baseScreen_preferences, 76, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_img_opa(present_ui->baseScreen_rideModeData, 76, LV_PART_MAIN|LV_STATE_DEFAULT);

		switch( upDownCount)	{
		case 0:
			lv_obj_set_style_text_color(present_ui->baseScreen_optionOne, lv_color_hex(0x00A0EE), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionTwo, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionThree, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			break;
		case 1:
			lv_obj_set_style_text_color(present_ui->baseScreen_optionOne, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionTwo, lv_color_hex(0x00A0EE), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionThree, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			break;
		case 2:
			lv_obj_set_style_text_color(present_ui->baseScreen_optionOne, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionTwo, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionThree, lv_color_hex(0x00A0EE), LV_PART_MAIN|LV_STATE_DEFAULT);
			break;
		}
	}

	if(2 == leftRightCount && (getMenuLoaded() == MENU_BLUETOOTH))	{
		lv_obj_set_style_opa(present_ui->baseScreen_menuScrollBar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_label_set_text(present_ui->baseScreen_menuHeading, "Bluetooth");
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeOne, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeTwo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeThree, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeFour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeFive, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeSix, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeSeven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeEight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeNine, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeTen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeEleven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

		lv_label_set_text(present_ui->baseScreen_optionOne, "Devices");
		lv_label_set_text(present_ui->baseScreen_optionTwo, "Display Call");
		lv_obj_set_style_opa(present_ui->baseScreen_optionThree, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_optionFour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_optionFive, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

		lv_obj_set_y(present_ui->baseScreen_menuSelectedCategoryIcon, 288);
		lv_obj_set_style_img_opa(present_ui->baseScreen_tripSettings, 76, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_img_opa(present_ui->baseScreen_vehicleData, 76, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_img_opa(present_ui->baseScreen_bluetoothSettings, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_img_opa(present_ui->baseScreen_preferences, 76, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_img_opa(present_ui->baseScreen_rideModeData, 76, LV_PART_MAIN|LV_STATE_DEFAULT);

		switch( upDownCount)	{
		case 0:
			lv_obj_set_style_text_color(present_ui->baseScreen_optionOne, lv_color_hex(0x00A0EE), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionTwo, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			break;
		case 1:
			lv_obj_set_style_text_color(present_ui->baseScreen_optionOne, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionTwo, lv_color_hex(0x00A0EE), LV_PART_MAIN|LV_STATE_DEFAULT);
			break;
		}
	}

	if(2 == leftRightCount && (getMenuLoaded() == MENU_PREFERENCES))	{
		lv_obj_set_style_opa(present_ui->baseScreen_menuScrollBar, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_label_set_text(present_ui->baseScreen_menuHeading, "Preference");
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeOne, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeTwo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeThree, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeFour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeFive, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeSix, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeSeven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeEight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeNine, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeTen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeEleven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

		lv_obj_set_y(present_ui->baseScreen_menuSelectedCategoryIcon, 432);
		lv_obj_set_style_img_opa(present_ui->baseScreen_tripSettings, 76, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_img_opa(present_ui->baseScreen_vehicleData, 76, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_img_opa(present_ui->baseScreen_bluetoothSettings, 76, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_img_opa(present_ui->baseScreen_preferences, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_img_opa(present_ui->baseScreen_rideModeData, 76, LV_PART_MAIN|LV_STATE_DEFAULT);

		if(upDownCount < 5)	{
			lv_obj_set_y(present_ui->baseScreen_menuScrollBar, 0);

			lv_obj_set_style_opa(present_ui->baseScreen_optionOne, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_opa(present_ui->baseScreen_optionTwo, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_opa(present_ui->baseScreen_optionThree, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_opa(present_ui->baseScreen_optionFour, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_opa(present_ui->baseScreen_optionFive, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

			lv_label_set_text(present_ui->baseScreen_optionOne, "Adaptive headlamp");
			lv_label_set_text(present_ui->baseScreen_optionTwo, "DRL");
			lv_label_set_text(present_ui->baseScreen_optionThree, "Traction control");
			lv_label_set_text(present_ui->baseScreen_optionFour, "Quick shifter");
			lv_label_set_text(present_ui->baseScreen_optionFive, "Display setup");
		}	else if(upDownCount >= 5)	{
			lv_obj_set_y(present_ui->baseScreen_menuScrollBar, 320);

			lv_obj_set_style_opa(present_ui->baseScreen_optionOne, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_opa(present_ui->baseScreen_optionTwo, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_opa(present_ui->baseScreen_optionThree, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_opa(present_ui->baseScreen_optionFour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_opa(present_ui->baseScreen_optionFive, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

			lv_label_set_text(present_ui->baseScreen_optionOne, "Speed alert");
			lv_label_set_text(present_ui->baseScreen_optionTwo, "GoPro");
		}

		switch( upDownCount)	{
		case 0:
			lv_obj_set_style_text_color(present_ui->baseScreen_optionOne, lv_color_hex(0x00A0EE), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionTwo, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionThree, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionFour, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionFive, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			break;
		case 1:
			lv_obj_set_style_text_color(present_ui->baseScreen_optionOne, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionTwo, lv_color_hex(0x00A0EE), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionThree, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionFour, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionFive, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			break;
		case 2:
			lv_obj_set_style_text_color(present_ui->baseScreen_optionOne, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionTwo, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionThree, lv_color_hex(0x00A0EE), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionFour, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionFive, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			break;
		case 3:
			lv_obj_set_style_text_color(present_ui->baseScreen_optionOne, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionTwo, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionThree, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionFour, lv_color_hex(0x00A0EE), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionFive, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			break;
		case 4:
			lv_obj_set_style_text_color(present_ui->baseScreen_optionOne, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionTwo, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionThree, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionFour, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionFive, lv_color_hex(0x00A0EE), LV_PART_MAIN|LV_STATE_DEFAULT);
			break;
		case 5:
			lv_obj_set_style_text_color(present_ui->baseScreen_optionOne, lv_color_hex(0x00A0EE), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionTwo, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionThree, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionFour, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionFive, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			break;
		case 6:
			lv_obj_set_style_text_color(present_ui->baseScreen_optionOne, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionTwo, lv_color_hex(0x00A0EE), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionThree, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionFour, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionFive, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			break;
		}
	}
	if(2 == leftRightCount && (getMenuLoaded() == MENU_CUSTOMIZATION))	{
		lv_obj_set_style_opa(present_ui->baseScreen_menuScrollBar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_label_set_text(present_ui->baseScreen_menuHeading, "Customization");
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeOne, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeTwo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeThree, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeFour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeFive, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeSix, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeSeven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeEight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeNine, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeTen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeEleven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

		lv_label_set_text(present_ui->baseScreen_optionOne, "Widgets");
		lv_label_set_text(present_ui->baseScreen_optionTwo, "GoPro");
		lv_obj_set_style_opa(present_ui->baseScreen_optionThree, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_optionFour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_optionFive, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

		lv_obj_set_y(present_ui->baseScreen_menuSelectedCategoryIcon, 576);
		lv_obj_set_style_img_opa(present_ui->baseScreen_tripSettings, 76, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_img_opa(present_ui->baseScreen_vehicleData, 76, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_img_opa(present_ui->baseScreen_bluetoothSettings, 76, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_img_opa(present_ui->baseScreen_preferences, 76, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_img_opa(present_ui->baseScreen_rideModeData, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

		switch( upDownCount)	{
		case 0:
			lv_obj_set_style_text_color(present_ui->baseScreen_optionOne, lv_color_hex(0x00A0EE), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionTwo, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			break;
		case 1:
			lv_obj_set_style_text_color(present_ui->baseScreen_optionOne, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(present_ui->baseScreen_optionTwo, lv_color_hex(0x00A0EE), LV_PART_MAIN|LV_STATE_DEFAULT);
			break;
		}
	}


	if(3 == leftRightCount && (getMenuLoaded() == MENU_TRIPDETAILS))	{
		lv_obj_set_style_opa(present_ui->baseScreen_menuScrollBar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeOne, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeTwo, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeThree, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeFour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeFive, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeSix, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeSeven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeEight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeNine, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeTen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeEleven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

		if(getSelectedTrip() != TRIP_DAILYTRIP)	{
			lv_obj_set_style_opa(present_ui->baseScreen_resetButton, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_label_set_text(present_ui->baseScreen_resetButton, "Reset");
		}
		else	{
			lv_obj_set_style_opa(present_ui->baseScreen_resetButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		}

		if(getSelectedTrip() == TRIP_ONE && (getTripResetState() == false))	{
			lv_label_set_text(present_ui->baseScreen_menuHeading, "Trip 1");
			setTopSpeed(100);
			setAverageSpeed(60);
			setAverageMileage(200);
		}	else if(getSelectedTrip() == TRIP_TWO && (getTripResetState() == false))	{
			lv_label_set_text(present_ui->baseScreen_menuHeading, "Trip 2");
			setTopSpeed(60);
			setAverageSpeed(52);
			setAverageMileage(280);
		}	else if(getSelectedTrip() == TRIP_THREE && (getTripResetState() == false))	{
			lv_label_set_text(present_ui->baseScreen_menuHeading, "Trip 3");
			setTopSpeed(80);
			setAverageSpeed(36);
			setAverageMileage(120);
		}	else if(getSelectedTrip() == TRIP_DAILYTRIP && (getTripResetState() == false))	{
			lv_label_set_text(present_ui->baseScreen_menuHeading, "Daily Trip");
			setTopSpeed(100);
			setAverageSpeed(60);
			setAverageMileage(200);
		}
	}
	if(4 == leftRightCount && (getMenuLoaded() == MENU_TRIPDETAILS))	{
		lv_obj_set_style_opa(present_ui->baseScreen_menuScrollBar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeOne, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeTwo, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeThree, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeFour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeFive, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeSix, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeSeven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeEight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeNine, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeTen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_opa(present_ui->baseScreen_menuTypeEleven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		if(getSelectedTrip() != TRIP_DAILYTRIP)	{
			lv_obj_set_style_opa(present_ui->baseScreen_resetButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_label_set_text(present_ui->baseScreen_resetButton, "Reset");
		}
		else	{
			lv_obj_set_style_opa(present_ui->baseScreen_resetButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
		}
		if(getSelectedTrip() == TRIP_ONE)	{
			setTripResetState(true);
			lv_label_set_text(present_ui->baseScreen_menuHeading, "Trip 1");
			setTopSpeed(0);
			setAverageSpeed(0);
			setAverageMileage(0);
		}	else if(getSelectedTrip() == TRIP_TWO)	{
			setTripResetState(true);
			lv_label_set_text(present_ui->baseScreen_menuHeading, "Trip 2");
			setTopSpeed(0);
			setAverageSpeed(0);
			setAverageMileage(0);
		}	else if(getSelectedTrip() == TRIP_THREE)	{
			setTripResetState(true);
			lv_label_set_text(present_ui->baseScreen_menuHeading, "Trip 3");
			setTopSpeed(0);
			setAverageSpeed(0);
			setAverageMileage(0);
		}	else if(getSelectedTrip() == TRIP_DAILYTRIP)	{
			setTripResetState(true);
			setTopSpeed(0);
			setAverageSpeed(0);
			setAverageMileage(0);
		}
	}
	if(5 == leftRightCount)	{
		setMenuLevel(0);
		setMenuOption(0);
		setMenuScreen();

	}
}

