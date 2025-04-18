/*
* Copyright 2025 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



int baseScreen_widgetMenuType3Value2_min_value = 0;
int baseScreen_widgetMenuType3Value2_hour_value = 0;
int baseScreen_widgetMenuType3Value2_sec_value = 0;
int baseScreen_clusterTime_min_value = 47;
int baseScreen_clusterTime_hour_value = 3;
int baseScreen_clusterTime_sec_value = 20;
char baseScreen_clusterTime_meridiem[] = "PM";
void setup_scr_baseScreen(lv_ui *ui)
{
	//Write codes baseScreen
	ui->baseScreen = lv_obj_create(NULL);
	lv_obj_set_size(ui->baseScreen, 1280, 720);
	lv_obj_set_scrollbar_mode(ui->baseScreen, LV_SCROLLBAR_MODE_OFF);

	//Write style for baseScreen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->baseScreen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->baseScreen, &_screenBackground_1280x720, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->baseScreen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_controllerIndicationContainer
	ui->baseScreen_controllerIndicationContainer = lv_obj_create(ui->baseScreen);
	lv_obj_set_pos(ui->baseScreen_controllerIndicationContainer, 150, 670);
	lv_obj_set_size(ui->baseScreen_controllerIndicationContainer, 1130, 50);
	lv_obj_set_scrollbar_mode(ui->baseScreen_controllerIndicationContainer, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->baseScreen_controllerIndicationContainer, LV_OBJ_FLAG_HIDDEN);

	//Write style for baseScreen_controllerIndicationContainer, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_controllerIndicationContainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_controllerIndicationContainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_controllerIndicationContainer, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->baseScreen_controllerIndicationContainer, lv_color_hex(0x002032), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->baseScreen_controllerIndicationContainer, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_controllerIndicationContainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_controllerIndicationContainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_controllerIndicationContainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_controllerIndicationContainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_controllerIndicationContainer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_arrowButtons
	ui->baseScreen_arrowButtons = lv_img_create(ui->baseScreen_controllerIndicationContainer);
	lv_obj_add_flag(ui->baseScreen_arrowButtons, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_arrowButtons, &_arrows_alpha_48x48);
	lv_img_set_pivot(ui->baseScreen_arrowButtons, 50,50);
	lv_img_set_angle(ui->baseScreen_arrowButtons, 0);
	lv_obj_set_pos(ui->baseScreen_arrowButtons, 280, 1);
	lv_obj_set_size(ui->baseScreen_arrowButtons, 48, 48);

	//Write style for baseScreen_arrowButtons, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_arrowButtons, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_controllerIndicationAlert
	ui->baseScreen_controllerIndicationAlert = lv_label_create(ui->baseScreen_controllerIndicationContainer);
	lv_label_set_text(ui->baseScreen_controllerIndicationAlert, "use buttons to control menu");
	lv_label_set_long_mode(ui->baseScreen_controllerIndicationAlert, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_controllerIndicationAlert, 0, 12);
	lv_obj_set_size(ui->baseScreen_controllerIndicationAlert, 1130, 28);

	//Write style for baseScreen_controllerIndicationAlert, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_controllerIndicationAlert, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_controllerIndicationAlert, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_controllerIndicationAlert, lv_color_hex(0x00A0EE), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_controllerIndicationAlert, &lv_font_MIMXRT1170EVKB_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_controllerIndicationAlert, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_controllerIndicationAlert, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_controllerIndicationAlert, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_controllerIndicationAlert, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_controllerIndicationAlert, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_controllerIndicationAlert, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_controllerIndicationAlert, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_controllerIndicationAlert, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_controllerIndicationAlert, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_controllerIndicationAlert, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_statusBarWidget
	ui->baseScreen_statusBarWidget = lv_obj_create(ui->baseScreen);
	lv_obj_set_pos(ui->baseScreen_statusBarWidget, 900, 37);
	lv_obj_set_size(ui->baseScreen_statusBarWidget, 355, 55);
	lv_obj_set_scrollbar_mode(ui->baseScreen_statusBarWidget, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->baseScreen_statusBarWidget, LV_OBJ_FLAG_HIDDEN);

	//Write style for baseScreen_statusBarWidget, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_statusBarWidget, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->baseScreen_statusBarWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->baseScreen_statusBarWidget, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->baseScreen_statusBarWidget, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_statusBarWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_statusBarWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_statusBarWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_statusBarWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_statusBarWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_statusBarWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_statusBarWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_warnings
	ui->baseScreen_warnings = lv_img_create(ui->baseScreen_statusBarWidget);
	lv_obj_add_flag(ui->baseScreen_warnings, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_warnings, &_waringsIcon_alpha_50x50);
	lv_img_set_pivot(ui->baseScreen_warnings, 50,50);
	lv_img_set_angle(ui->baseScreen_warnings, 0);
	lv_obj_set_pos(ui->baseScreen_warnings, 0, 0);
	lv_obj_set_size(ui->baseScreen_warnings, 50, 50);

	//Write style for baseScreen_warnings, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_warnings, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_messageInbox
	ui->baseScreen_messageInbox = lv_img_create(ui->baseScreen_statusBarWidget);
	lv_obj_add_flag(ui->baseScreen_messageInbox, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_messageInbox, &_messagesIcon_alpha_50x50);
	lv_img_set_pivot(ui->baseScreen_messageInbox, 50,50);
	lv_img_set_angle(ui->baseScreen_messageInbox, 0);
	lv_obj_set_pos(ui->baseScreen_messageInbox, 60, 0);
	lv_obj_set_size(ui->baseScreen_messageInbox, 50, 50);

	//Write style for baseScreen_messageInbox, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_messageInbox, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_missedCall
	ui->baseScreen_missedCall = lv_img_create(ui->baseScreen_statusBarWidget);
	lv_obj_add_flag(ui->baseScreen_missedCall, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_missedCall, &_missedcallIcon_alpha_50x50);
	lv_img_set_pivot(ui->baseScreen_missedCall, 50,50);
	lv_img_set_angle(ui->baseScreen_missedCall, 0);
	lv_obj_set_pos(ui->baseScreen_missedCall, 120, 0);
	lv_obj_set_size(ui->baseScreen_missedCall, 50, 50);

	//Write style for baseScreen_missedCall, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_missedCall, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_phoneBluetooth
	ui->baseScreen_phoneBluetooth = lv_img_create(ui->baseScreen_statusBarWidget);
	lv_obj_add_flag(ui->baseScreen_phoneBluetooth, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_phoneBluetooth, &_bluetoothIcon_alpha_50x50);
	lv_img_set_pivot(ui->baseScreen_phoneBluetooth, 50,50);
	lv_img_set_angle(ui->baseScreen_phoneBluetooth, 0);
	lv_obj_set_pos(ui->baseScreen_phoneBluetooth, 180, 0);
	lv_obj_set_size(ui->baseScreen_phoneBluetooth, 50, 50);

	//Write style for baseScreen_phoneBluetooth, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_phoneBluetooth, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_batteryFullIcon
	ui->baseScreen_batteryFullIcon = lv_img_create(ui->baseScreen_statusBarWidget);
	lv_obj_add_flag(ui->baseScreen_batteryFullIcon, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_batteryFullIcon, &_batteryFullIcon_alpha_50x50);
	lv_img_set_pivot(ui->baseScreen_batteryFullIcon, 50,50);
	lv_img_set_angle(ui->baseScreen_batteryFullIcon, 0);
	lv_obj_set_pos(ui->baseScreen_batteryFullIcon, 300, 0);
	lv_obj_set_size(ui->baseScreen_batteryFullIcon, 50, 50);

	//Write style for baseScreen_batteryFullIcon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_batteryFullIcon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_batteryLowIcon
	ui->baseScreen_batteryLowIcon = lv_img_create(ui->baseScreen_statusBarWidget);
	lv_obj_add_flag(ui->baseScreen_batteryLowIcon, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_batteryLowIcon, &_batteryLowIcon_alpha_50x50);
	lv_img_set_pivot(ui->baseScreen_batteryLowIcon, 50,50);
	lv_img_set_angle(ui->baseScreen_batteryLowIcon, 0);
	lv_obj_set_pos(ui->baseScreen_batteryLowIcon, 300, 0);
	lv_obj_set_size(ui->baseScreen_batteryLowIcon, 50, 50);

	//Write style for baseScreen_batteryLowIcon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_batteryLowIcon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_batteryMidIcon
	ui->baseScreen_batteryMidIcon = lv_img_create(ui->baseScreen_statusBarWidget);
	lv_obj_add_flag(ui->baseScreen_batteryMidIcon, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_batteryMidIcon, &_batteryMidIcon_alpha_50x50);
	lv_img_set_pivot(ui->baseScreen_batteryMidIcon, 50,50);
	lv_img_set_angle(ui->baseScreen_batteryMidIcon, 0);
	lv_obj_set_pos(ui->baseScreen_batteryMidIcon, 300, 0);
	lv_obj_set_size(ui->baseScreen_batteryMidIcon, 50, 50);

	//Write style for baseScreen_batteryMidIcon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_batteryMidIcon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_batteryAverageIcon
	ui->baseScreen_batteryAverageIcon = lv_img_create(ui->baseScreen_statusBarWidget);
	lv_obj_add_flag(ui->baseScreen_batteryAverageIcon, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_batteryAverageIcon, &_batteryAverageIcon_alpha_50x50);
	lv_img_set_pivot(ui->baseScreen_batteryAverageIcon, 50,50);
	lv_img_set_angle(ui->baseScreen_batteryAverageIcon, 0);
	lv_obj_set_pos(ui->baseScreen_batteryAverageIcon, 300, 0);
	lv_obj_set_size(ui->baseScreen_batteryAverageIcon, 50, 50);

	//Write style for baseScreen_batteryAverageIcon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_batteryAverageIcon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_PhoneBatteryEmpty
	ui->baseScreen_PhoneBatteryEmpty = lv_img_create(ui->baseScreen_statusBarWidget);
	lv_obj_add_flag(ui->baseScreen_PhoneBatteryEmpty, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_PhoneBatteryEmpty, &_batteryTooLowIcon_alpha_50x50);
	lv_img_set_pivot(ui->baseScreen_PhoneBatteryEmpty, 50,50);
	lv_img_set_angle(ui->baseScreen_PhoneBatteryEmpty, 0);
	lv_obj_set_pos(ui->baseScreen_PhoneBatteryEmpty, 300, 0);
	lv_obj_set_size(ui->baseScreen_PhoneBatteryEmpty, 50, 50);

	//Write style for baseScreen_PhoneBatteryEmpty, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_PhoneBatteryEmpty, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_phoneNetworkSignal0
	ui->baseScreen_phoneNetworkSignal0 = lv_img_create(ui->baseScreen_statusBarWidget);
	lv_obj_add_flag(ui->baseScreen_phoneNetworkSignal0, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_phoneNetworkSignal0, &_Signal0Icon_alpha_50x50);
	lv_img_set_pivot(ui->baseScreen_phoneNetworkSignal0, 50,50);
	lv_img_set_angle(ui->baseScreen_phoneNetworkSignal0, 0);
	lv_obj_set_pos(ui->baseScreen_phoneNetworkSignal0, 240, 0);
	lv_obj_set_size(ui->baseScreen_phoneNetworkSignal0, 50, 50);

	//Write style for baseScreen_phoneNetworkSignal0, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_phoneNetworkSignal0, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_phoneNetworkSignal1
	ui->baseScreen_phoneNetworkSignal1 = lv_img_create(ui->baseScreen_statusBarWidget);
	lv_obj_add_flag(ui->baseScreen_phoneNetworkSignal1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_phoneNetworkSignal1, &_Signal1Icon_alpha_50x50);
	lv_img_set_pivot(ui->baseScreen_phoneNetworkSignal1, 50,50);
	lv_img_set_angle(ui->baseScreen_phoneNetworkSignal1, 0);
	lv_obj_set_pos(ui->baseScreen_phoneNetworkSignal1, 240, 0);
	lv_obj_set_size(ui->baseScreen_phoneNetworkSignal1, 50, 50);

	//Write style for baseScreen_phoneNetworkSignal1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_phoneNetworkSignal1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_phoneNetworkSignal2
	ui->baseScreen_phoneNetworkSignal2 = lv_img_create(ui->baseScreen_statusBarWidget);
	lv_obj_add_flag(ui->baseScreen_phoneNetworkSignal2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_phoneNetworkSignal2, &_Signal2Icon_alpha_50x50);
	lv_img_set_pivot(ui->baseScreen_phoneNetworkSignal2, 50,50);
	lv_img_set_angle(ui->baseScreen_phoneNetworkSignal2, 0);
	lv_obj_set_pos(ui->baseScreen_phoneNetworkSignal2, 240, 0);
	lv_obj_set_size(ui->baseScreen_phoneNetworkSignal2, 50, 50);

	//Write style for baseScreen_phoneNetworkSignal2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_phoneNetworkSignal2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_phoneNetworkSignal3
	ui->baseScreen_phoneNetworkSignal3 = lv_img_create(ui->baseScreen_statusBarWidget);
	lv_obj_add_flag(ui->baseScreen_phoneNetworkSignal3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_phoneNetworkSignal3, &_Signal3Icon_alpha_50x50);
	lv_img_set_pivot(ui->baseScreen_phoneNetworkSignal3, 50,50);
	lv_img_set_angle(ui->baseScreen_phoneNetworkSignal3, 0);
	lv_obj_set_pos(ui->baseScreen_phoneNetworkSignal3, 240, 0);
	lv_obj_set_size(ui->baseScreen_phoneNetworkSignal3, 50, 50);

	//Write style for baseScreen_phoneNetworkSignal3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_phoneNetworkSignal3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_phoneNetworkSignal4
	ui->baseScreen_phoneNetworkSignal4 = lv_img_create(ui->baseScreen_statusBarWidget);
	lv_obj_add_flag(ui->baseScreen_phoneNetworkSignal4, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_phoneNetworkSignal4, &_Signal4Icon_alpha_50x50);
	lv_img_set_pivot(ui->baseScreen_phoneNetworkSignal4, 50,50);
	lv_img_set_angle(ui->baseScreen_phoneNetworkSignal4, 0);
	lv_obj_set_pos(ui->baseScreen_phoneNetworkSignal4, 240, 0);
	lv_obj_set_size(ui->baseScreen_phoneNetworkSignal4, 50, 50);

	//Write style for baseScreen_phoneNetworkSignal4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_phoneNetworkSignal4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_menuWidget
	ui->baseScreen_menuWidget = lv_obj_create(ui->baseScreen);
	lv_obj_set_pos(ui->baseScreen_menuWidget, 0, 0);
	lv_obj_set_size(ui->baseScreen_menuWidget, 1280, 720);
	lv_obj_set_scrollbar_mode(ui->baseScreen_menuWidget, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->baseScreen_menuWidget, LV_OBJ_FLAG_HIDDEN);

	//Write style for baseScreen_menuWidget, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_menuWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_menuWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_menuWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_menuWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_menuWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_menuWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_menuWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_menuWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_MenuCategory
	ui->baseScreen_MenuCategory = lv_obj_create(ui->baseScreen_menuWidget);
	lv_obj_set_pos(ui->baseScreen_MenuCategory, 0, 0);
	lv_obj_set_size(ui->baseScreen_MenuCategory, 150, 720);
	lv_obj_set_scrollbar_mode(ui->baseScreen_MenuCategory, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->baseScreen_MenuCategory, LV_OBJ_FLAG_HIDDEN);

	//Write style for baseScreen_MenuCategory, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_MenuCategory, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_MenuCategory, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_MenuCategory, 32, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->baseScreen_MenuCategory, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->baseScreen_MenuCategory, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_MenuCategory, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_MenuCategory, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_MenuCategory, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_MenuCategory, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_MenuCategory, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_menuSelectedCategory
	ui->baseScreen_menuSelectedCategory = lv_obj_create(ui->baseScreen_MenuCategory);
	lv_obj_set_pos(ui->baseScreen_menuSelectedCategory, 0, 0);
	lv_obj_set_size(ui->baseScreen_menuSelectedCategory, 150, 720);
	lv_obj_set_scrollbar_mode(ui->baseScreen_menuSelectedCategory, LV_SCROLLBAR_MODE_OFF);

	//Write style for baseScreen_menuSelectedCategory, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_menuSelectedCategory, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_menuSelectedCategory, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_menuSelectedCategory, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_menuSelectedCategory, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_menuSelectedCategory, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_menuSelectedCategory, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_menuSelectedCategory, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_menuSelectedCategory, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_menuSelectedCategoryIcon
	ui->baseScreen_menuSelectedCategoryIcon = lv_img_create(ui->baseScreen_menuSelectedCategory);
	lv_obj_add_flag(ui->baseScreen_menuSelectedCategoryIcon, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_menuSelectedCategoryIcon, &_menuSelectedCategoryIcon_alpha_150x144);
	lv_img_set_pivot(ui->baseScreen_menuSelectedCategoryIcon, 50,50);
	lv_img_set_angle(ui->baseScreen_menuSelectedCategoryIcon, 0);
	lv_obj_set_pos(ui->baseScreen_menuSelectedCategoryIcon, 0, 0);
	lv_obj_set_size(ui->baseScreen_menuSelectedCategoryIcon, 150, 144);

	//Write style for baseScreen_menuSelectedCategoryIcon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_menuSelectedCategoryIcon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_menuCategoryIcons
	ui->baseScreen_menuCategoryIcons = lv_obj_create(ui->baseScreen_MenuCategory);
	lv_obj_set_pos(ui->baseScreen_menuCategoryIcons, 0, 0);
	lv_obj_set_size(ui->baseScreen_menuCategoryIcons, 150, 720);
	lv_obj_set_scrollbar_mode(ui->baseScreen_menuCategoryIcons, LV_SCROLLBAR_MODE_OFF);

	//Write style for baseScreen_menuCategoryIcons, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_menuCategoryIcons, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_menuCategoryIcons, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_menuCategoryIcons, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_menuCategoryIcons, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_menuCategoryIcons, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_menuCategoryIcons, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_menuCategoryIcons, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_menuCategoryIcons, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_tripSettings
	ui->baseScreen_tripSettings = lv_img_create(ui->baseScreen_menuCategoryIcons);
	lv_obj_add_flag(ui->baseScreen_tripSettings, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_tripSettings, &_Trips_alpha_72x72);
	lv_img_set_pivot(ui->baseScreen_tripSettings, 50,50);
	lv_img_set_angle(ui->baseScreen_tripSettings, 0);
	lv_obj_set_pos(ui->baseScreen_tripSettings, 39, 36);
	lv_obj_set_size(ui->baseScreen_tripSettings, 72, 72);

	//Write style for baseScreen_tripSettings, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_tripSettings, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_vehicleData
	ui->baseScreen_vehicleData = lv_img_create(ui->baseScreen_menuCategoryIcons);
	lv_obj_add_flag(ui->baseScreen_vehicleData, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_vehicleData, &_Vehicle_alpha_72x72);
	lv_img_set_pivot(ui->baseScreen_vehicleData, 50,50);
	lv_img_set_angle(ui->baseScreen_vehicleData, 0);
	lv_obj_set_pos(ui->baseScreen_vehicleData, 39, 180);
	lv_obj_set_size(ui->baseScreen_vehicleData, 72, 72);

	//Write style for baseScreen_vehicleData, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_vehicleData, 77, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_bluetoothSettings
	ui->baseScreen_bluetoothSettings = lv_img_create(ui->baseScreen_menuCategoryIcons);
	lv_obj_add_flag(ui->baseScreen_bluetoothSettings, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_bluetoothSettings, &_bluetoothConnectivity_alpha_72x72);
	lv_img_set_pivot(ui->baseScreen_bluetoothSettings, 50,50);
	lv_img_set_angle(ui->baseScreen_bluetoothSettings, 0);
	lv_obj_set_pos(ui->baseScreen_bluetoothSettings, 39, 324);
	lv_obj_set_size(ui->baseScreen_bluetoothSettings, 72, 72);

	//Write style for baseScreen_bluetoothSettings, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_bluetoothSettings, 77, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_preferences
	ui->baseScreen_preferences = lv_img_create(ui->baseScreen_menuCategoryIcons);
	lv_obj_add_flag(ui->baseScreen_preferences, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_preferences, &_Preference_alpha_72x72);
	lv_img_set_pivot(ui->baseScreen_preferences, 50,50);
	lv_img_set_angle(ui->baseScreen_preferences, 0);
	lv_obj_set_pos(ui->baseScreen_preferences, 39, 468);
	lv_obj_set_size(ui->baseScreen_preferences, 72, 72);

	//Write style for baseScreen_preferences, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_preferences, 77, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_rideModeData
	ui->baseScreen_rideModeData = lv_img_create(ui->baseScreen_menuCategoryIcons);
	lv_obj_add_flag(ui->baseScreen_rideModeData, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_rideModeData, &_Mode_alpha_72x72);
	lv_img_set_pivot(ui->baseScreen_rideModeData, 50,50);
	lv_img_set_angle(ui->baseScreen_rideModeData, 0);
	lv_obj_set_pos(ui->baseScreen_rideModeData, 39, 612);
	lv_obj_set_size(ui->baseScreen_rideModeData, 72, 72);

	//Write style for baseScreen_rideModeData, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_rideModeData, 77, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_menuMainArea
	ui->baseScreen_menuMainArea = lv_obj_create(ui->baseScreen_menuWidget);
	lv_obj_set_pos(ui->baseScreen_menuMainArea, 150, 0);
	lv_obj_set_size(ui->baseScreen_menuMainArea, 660, 720);
	lv_obj_set_scrollbar_mode(ui->baseScreen_menuMainArea, LV_SCROLLBAR_MODE_OFF);

	//Write style for baseScreen_menuMainArea, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_menuMainArea, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_menuMainArea, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_menuMainArea, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_menuMainArea, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_menuMainArea, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_menuMainArea, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_menuMainArea, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_menuMainArea, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_menuTypeEleven
	ui->baseScreen_menuTypeEleven = lv_obj_create(ui->baseScreen_menuMainArea);
	lv_obj_set_pos(ui->baseScreen_menuTypeEleven, -150, 0);
	lv_obj_set_size(ui->baseScreen_menuTypeEleven, 1280, 720);
	lv_obj_set_scrollbar_mode(ui->baseScreen_menuTypeEleven, LV_SCROLLBAR_MODE_OFF);

	//Write style for baseScreen_menuTypeEleven, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_menuTypeEleven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_menuTypeEleven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_menuTypeEleven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_menuTypeEleven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_menuTypeEleven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_menuTypeEleven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_menuTypeEleven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_menuTypeEleven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_Document
	ui->baseScreen_Document = lv_img_create(ui->baseScreen_menuTypeEleven);
	lv_obj_add_flag(ui->baseScreen_Document, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_Document, &_screenBackground_alpha_1280x720);
	lv_img_set_pivot(ui->baseScreen_Document, 25,0);
	lv_img_set_angle(ui->baseScreen_Document, 0);
	lv_obj_set_pos(ui->baseScreen_Document, -144, 0);
	lv_obj_set_size(ui->baseScreen_Document, 1280, 720);

	//Write style for baseScreen_Document, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.

	//Write codes baseScreen_documentLabel
	ui->baseScreen_documentLabel = lv_label_create(ui->baseScreen_menuTypeEleven);
	lv_label_set_text(ui->baseScreen_documentLabel, "Document");
	lv_label_set_long_mode(ui->baseScreen_documentLabel, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_documentLabel, 0, 25);
	lv_obj_set_size(ui->baseScreen_documentLabel, 1280, 75);

	//Write style for baseScreen_documentLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_documentLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_documentLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_documentLabel, lv_color_hex(0x0093E7), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_documentLabel, &lv_font_MIMXRT1170EVKB_75, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_documentLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_documentLabel, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_documentLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_documentLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_documentLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_documentLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_documentLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_documentLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_documentLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_documentLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_menuTypeTen
	ui->baseScreen_menuTypeTen = lv_obj_create(ui->baseScreen_menuMainArea);
	lv_obj_set_pos(ui->baseScreen_menuTypeTen, 0, 144);
	lv_obj_set_size(ui->baseScreen_menuTypeTen, 660, 576);
	lv_obj_set_scrollbar_mode(ui->baseScreen_menuTypeTen, LV_SCROLLBAR_MODE_OFF);

	//Write style for baseScreen_menuTypeTen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_menuTypeTen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_menuTypeTen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_menuTypeTen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_menuTypeTen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_menuTypeTen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_menuTypeTen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_menuTypeTen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_menuTypeTen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_year
	ui->baseScreen_year = lv_obj_create(ui->baseScreen_menuTypeTen);
	lv_obj_set_pos(ui->baseScreen_year, 110, 0);
	lv_obj_set_size(ui->baseScreen_year, 660, 576);
	lv_obj_set_scrollbar_mode(ui->baseScreen_year, LV_SCROLLBAR_MODE_OFF);

	//Write style for baseScreen_year, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_year, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_year, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_year, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_year, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_year, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_year, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_year, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_year, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_yearBackground
	ui->baseScreen_yearBackground = lv_img_create(ui->baseScreen_year);
	lv_obj_add_flag(ui->baseScreen_yearBackground, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_yearBackground, &_timePickerInactive_alpha_300x150);
	lv_img_set_pivot(ui->baseScreen_yearBackground, 50,50);
	lv_img_set_angle(ui->baseScreen_yearBackground, 0);
	lv_obj_set_pos(ui->baseScreen_yearBackground, 226, 180);
	lv_obj_set_size(ui->baseScreen_yearBackground, 300, 150);

	//Write style for baseScreen_yearBackground, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_yearBackground, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_yearUpArrow
	ui->baseScreen_yearUpArrow = lv_img_create(ui->baseScreen_year);
	lv_obj_add_flag(ui->baseScreen_yearUpArrow, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_yearUpArrow, &_arrowWhite_alpha_54x54);
	lv_img_set_pivot(ui->baseScreen_yearUpArrow, 0,0);
	lv_img_set_angle(ui->baseScreen_yearUpArrow, 0);
	lv_obj_set_pos(ui->baseScreen_yearUpArrow, 350, 110);
	lv_obj_set_size(ui->baseScreen_yearUpArrow, 54, 54);

	//Write style for baseScreen_yearUpArrow, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_yearUpArrow, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_yearDownArrow
	ui->baseScreen_yearDownArrow = lv_img_create(ui->baseScreen_year);
	lv_obj_add_flag(ui->baseScreen_yearDownArrow, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_yearDownArrow, &_arrowWhite_alpha_54x54);
	lv_img_set_pivot(ui->baseScreen_yearDownArrow, 25,0);
	lv_img_set_angle(ui->baseScreen_yearDownArrow, 1800);
	lv_obj_set_pos(ui->baseScreen_yearDownArrow, 350, 405);
	lv_obj_set_size(ui->baseScreen_yearDownArrow, 54, 54);

	//Write style for baseScreen_yearDownArrow, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_yearDownArrow, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_yearText
	ui->baseScreen_yearText = lv_label_create(ui->baseScreen_year);
	lv_label_set_text(ui->baseScreen_yearText, "2024");
	lv_label_set_long_mode(ui->baseScreen_yearText, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_yearText, 226, 207);
	lv_obj_set_size(ui->baseScreen_yearText, 300, 100);

	//Write style for baseScreen_yearText, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_yearText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_yearText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_yearText, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_yearText, &lv_font_MIMXRT1170EVKB_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_yearText, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_yearText, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_yearText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_yearText, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_yearText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_yearText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_yearText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_yearText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_yearText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_yearText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_month
	ui->baseScreen_month = lv_obj_create(ui->baseScreen_menuTypeTen);
	lv_obj_set_pos(ui->baseScreen_month, -50, 0);
	lv_obj_set_size(ui->baseScreen_month, 660, 576);
	lv_obj_set_scrollbar_mode(ui->baseScreen_month, LV_SCROLLBAR_MODE_OFF);

	//Write style for baseScreen_month, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_month, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_month, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_month, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_month, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_month, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_month, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_month, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_month, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_monthBackground
	ui->baseScreen_monthBackground = lv_img_create(ui->baseScreen_month);
	lv_obj_add_flag(ui->baseScreen_monthBackground, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_monthBackground, &_timePickerActive_alpha_150x150);
	lv_img_set_pivot(ui->baseScreen_monthBackground, 50,50);
	lv_img_set_angle(ui->baseScreen_monthBackground, 0);
	lv_obj_set_pos(ui->baseScreen_monthBackground, 226, 180);
	lv_obj_set_size(ui->baseScreen_monthBackground, 150, 150);

	//Write style for baseScreen_monthBackground, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_monthBackground, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_monthUpArrow
	ui->baseScreen_monthUpArrow = lv_img_create(ui->baseScreen_month);
	lv_obj_add_flag(ui->baseScreen_monthUpArrow, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_monthUpArrow, &_arrowWhite_alpha_54x54);
	lv_img_set_pivot(ui->baseScreen_monthUpArrow, 0,0);
	lv_img_set_angle(ui->baseScreen_monthUpArrow, 0);
	lv_obj_set_pos(ui->baseScreen_monthUpArrow, 275, 110);
	lv_obj_set_size(ui->baseScreen_monthUpArrow, 54, 54);

	//Write style for baseScreen_monthUpArrow, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_monthUpArrow, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_monthDownArrow
	ui->baseScreen_monthDownArrow = lv_img_create(ui->baseScreen_month);
	lv_obj_add_flag(ui->baseScreen_monthDownArrow, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_monthDownArrow, &_arrowWhite_alpha_54x54);
	lv_img_set_pivot(ui->baseScreen_monthDownArrow, 25,0);
	lv_img_set_angle(ui->baseScreen_monthDownArrow, 1800);
	lv_obj_set_pos(ui->baseScreen_monthDownArrow, 275, 405);
	lv_obj_set_size(ui->baseScreen_monthDownArrow, 54, 54);

	//Write style for baseScreen_monthDownArrow, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_monthDownArrow, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_monthText
	ui->baseScreen_monthText = lv_label_create(ui->baseScreen_month);
	lv_label_set_text(ui->baseScreen_monthText, "12\n");
	lv_label_set_long_mode(ui->baseScreen_monthText, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_monthText, 226, 207);
	lv_obj_set_size(ui->baseScreen_monthText, 150, 100);

	//Write style for baseScreen_monthText, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_monthText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_monthText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_monthText, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_monthText, &lv_font_MIMXRT1170EVKB_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_monthText, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_monthText, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_monthText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_monthText, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_monthText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_monthText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_monthText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_monthText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_monthText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_monthText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_date
	ui->baseScreen_date = lv_obj_create(ui->baseScreen_menuTypeTen);
	lv_obj_set_pos(ui->baseScreen_date, -210, 0);
	lv_obj_set_size(ui->baseScreen_date, 660, 576);
	lv_obj_set_scrollbar_mode(ui->baseScreen_date, LV_SCROLLBAR_MODE_OFF);

	//Write style for baseScreen_date, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_dateBackground
	ui->baseScreen_dateBackground = lv_img_create(ui->baseScreen_date);
	lv_obj_add_flag(ui->baseScreen_dateBackground, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_dateBackground, &_timePickerSelected_alpha_150x150);
	lv_img_set_pivot(ui->baseScreen_dateBackground, 50,50);
	lv_img_set_angle(ui->baseScreen_dateBackground, 0);
	lv_obj_set_pos(ui->baseScreen_dateBackground, 226, 180);
	lv_obj_set_size(ui->baseScreen_dateBackground, 150, 150);

	//Write style for baseScreen_dateBackground, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_dateBackground, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_dateUpArrow
	ui->baseScreen_dateUpArrow = lv_img_create(ui->baseScreen_date);
	lv_obj_add_flag(ui->baseScreen_dateUpArrow, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_dateUpArrow, &_arrowWhite_alpha_54x54);
	lv_img_set_pivot(ui->baseScreen_dateUpArrow, 0,0);
	lv_img_set_angle(ui->baseScreen_dateUpArrow, 0);
	lv_obj_set_pos(ui->baseScreen_dateUpArrow, 275, 110);
	lv_obj_set_size(ui->baseScreen_dateUpArrow, 54, 54);

	//Write style for baseScreen_dateUpArrow, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_dateUpArrow, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_dateDownArrow
	ui->baseScreen_dateDownArrow = lv_img_create(ui->baseScreen_date);
	lv_obj_add_flag(ui->baseScreen_dateDownArrow, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_dateDownArrow, &_arrowWhite_alpha_54x54);
	lv_img_set_pivot(ui->baseScreen_dateDownArrow, 25,0);
	lv_img_set_angle(ui->baseScreen_dateDownArrow, 1800);
	lv_obj_set_pos(ui->baseScreen_dateDownArrow, 275, 405);
	lv_obj_set_size(ui->baseScreen_dateDownArrow, 54, 54);

	//Write style for baseScreen_dateDownArrow, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_dateDownArrow, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_dateText
	ui->baseScreen_dateText = lv_label_create(ui->baseScreen_date);
	lv_label_set_text(ui->baseScreen_dateText, "31\n\n");
	lv_label_set_long_mode(ui->baseScreen_dateText, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_dateText, 226, 207);
	lv_obj_set_size(ui->baseScreen_dateText, 150, 100);

	//Write style for baseScreen_dateText, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_dateText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_dateText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_dateText, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_dateText, &lv_font_MIMXRT1170EVKB_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_dateText, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_dateText, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_dateText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_dateText, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_dateText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_dateText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_dateText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_dateText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_dateText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_dateText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_menuTypeNine
	ui->baseScreen_menuTypeNine = lv_obj_create(ui->baseScreen_menuMainArea);
	lv_obj_set_pos(ui->baseScreen_menuTypeNine, 0, 144);
	lv_obj_set_size(ui->baseScreen_menuTypeNine, 660, 576);
	lv_obj_set_scrollbar_mode(ui->baseScreen_menuTypeNine, LV_SCROLLBAR_MODE_OFF);

	//Write style for baseScreen_menuTypeNine, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_menuTypeNine, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_menuTypeNine, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_menuTypeNine, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_menuTypeNine, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_menuTypeNine, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_menuTypeNine, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_menuTypeNine, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_menuTypeNine, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_ampm
	ui->baseScreen_ampm = lv_obj_create(ui->baseScreen_menuTypeNine);
	lv_obj_set_pos(ui->baseScreen_ampm, 210, 0);
	lv_obj_set_size(ui->baseScreen_ampm, 660, 576);
	lv_obj_set_scrollbar_mode(ui->baseScreen_ampm, LV_SCROLLBAR_MODE_OFF);

	//Write style for baseScreen_ampm, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_ampm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_ampm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_ampm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_ampm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_ampm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_ampm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_ampm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_ampm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_ampmBackground
	ui->baseScreen_ampmBackground = lv_img_create(ui->baseScreen_ampm);
	lv_obj_add_flag(ui->baseScreen_ampmBackground, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_ampmBackground, &_timePickerInactive_alpha_200x150);
	lv_img_set_pivot(ui->baseScreen_ampmBackground, 50,50);
	lv_img_set_angle(ui->baseScreen_ampmBackground, 0);
	lv_obj_set_pos(ui->baseScreen_ampmBackground, 226, 180);
	lv_obj_set_size(ui->baseScreen_ampmBackground, 200, 150);

	//Write style for baseScreen_ampmBackground, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_ampmBackground, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_ampmUpArrow
	ui->baseScreen_ampmUpArrow = lv_img_create(ui->baseScreen_ampm);
	lv_obj_add_flag(ui->baseScreen_ampmUpArrow, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_ampmUpArrow, &_arrowWhite_alpha_54x54);
	lv_img_set_pivot(ui->baseScreen_ampmUpArrow, 0,0);
	lv_img_set_angle(ui->baseScreen_ampmUpArrow, 0);
	lv_obj_set_pos(ui->baseScreen_ampmUpArrow, 300, 110);
	lv_obj_set_size(ui->baseScreen_ampmUpArrow, 54, 54);

	//Write style for baseScreen_ampmUpArrow, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_ampmUpArrow, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_ampmDownArrow
	ui->baseScreen_ampmDownArrow = lv_img_create(ui->baseScreen_ampm);
	lv_obj_add_flag(ui->baseScreen_ampmDownArrow, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_ampmDownArrow, &_arrowWhite_alpha_54x54);
	lv_img_set_pivot(ui->baseScreen_ampmDownArrow, 25,0);
	lv_img_set_angle(ui->baseScreen_ampmDownArrow, 1800);
	lv_obj_set_pos(ui->baseScreen_ampmDownArrow, 300, 405);
	lv_obj_set_size(ui->baseScreen_ampmDownArrow, 54, 54);

	//Write style for baseScreen_ampmDownArrow, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_ampmDownArrow, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_ampmText
	ui->baseScreen_ampmText = lv_label_create(ui->baseScreen_ampm);
	lv_label_set_text(ui->baseScreen_ampmText, "AM");
	lv_label_set_long_mode(ui->baseScreen_ampmText, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_ampmText, 226, 207);
	lv_obj_set_size(ui->baseScreen_ampmText, 200, 100);

	//Write style for baseScreen_ampmText, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_ampmText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_ampmText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_ampmText, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_ampmText, &lv_font_MIMXRT1170EVKB_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_ampmText, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_ampmText, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_ampmText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_ampmText, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_ampmText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_ampmText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_ampmText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_ampmText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_ampmText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_ampmText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_minute
	ui->baseScreen_minute = lv_obj_create(ui->baseScreen_menuTypeNine);
	lv_obj_set_pos(ui->baseScreen_minute, 0, 0);
	lv_obj_set_size(ui->baseScreen_minute, 660, 576);
	lv_obj_set_scrollbar_mode(ui->baseScreen_minute, LV_SCROLLBAR_MODE_OFF);

	//Write style for baseScreen_minute, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_minute, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_minute, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_minute, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_minute, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_minute, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_minute, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_minute, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_minute, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_mmBackground
	ui->baseScreen_mmBackground = lv_img_create(ui->baseScreen_minute);
	lv_obj_add_flag(ui->baseScreen_mmBackground, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_mmBackground, &_timePickerActive_alpha_200x150);
	lv_img_set_pivot(ui->baseScreen_mmBackground, 50,50);
	lv_img_set_angle(ui->baseScreen_mmBackground, 0);
	lv_obj_set_pos(ui->baseScreen_mmBackground, 226, 180);
	lv_obj_set_size(ui->baseScreen_mmBackground, 200, 150);

	//Write style for baseScreen_mmBackground, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_mmBackground, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_mmUpArrow
	ui->baseScreen_mmUpArrow = lv_img_create(ui->baseScreen_minute);
	lv_obj_add_flag(ui->baseScreen_mmUpArrow, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_mmUpArrow, &_arrowWhite_alpha_54x54);
	lv_img_set_pivot(ui->baseScreen_mmUpArrow, 0,0);
	lv_img_set_angle(ui->baseScreen_mmUpArrow, 0);
	lv_obj_set_pos(ui->baseScreen_mmUpArrow, 300, 110);
	lv_obj_set_size(ui->baseScreen_mmUpArrow, 54, 54);

	//Write style for baseScreen_mmUpArrow, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_mmUpArrow, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_mmDownArrow
	ui->baseScreen_mmDownArrow = lv_img_create(ui->baseScreen_minute);
	lv_obj_add_flag(ui->baseScreen_mmDownArrow, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_mmDownArrow, &_arrowWhite_alpha_54x54);
	lv_img_set_pivot(ui->baseScreen_mmDownArrow, 25,0);
	lv_img_set_angle(ui->baseScreen_mmDownArrow, 1800);
	lv_obj_set_pos(ui->baseScreen_mmDownArrow, 300, 405);
	lv_obj_set_size(ui->baseScreen_mmDownArrow, 54, 54);

	//Write style for baseScreen_mmDownArrow, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_mmDownArrow, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_mmText
	ui->baseScreen_mmText = lv_label_create(ui->baseScreen_minute);
	lv_label_set_text(ui->baseScreen_mmText, "100\n");
	lv_label_set_long_mode(ui->baseScreen_mmText, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_mmText, 226, 207);
	lv_obj_set_size(ui->baseScreen_mmText, 200, 100);

	//Write style for baseScreen_mmText, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_mmText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_mmText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_mmText, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_mmText, &lv_font_MIMXRT1170EVKB_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_mmText, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_mmText, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_mmText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_mmText, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_mmText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_mmText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_mmText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_mmText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_mmText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_mmText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_hour
	ui->baseScreen_hour = lv_obj_create(ui->baseScreen_menuTypeNine);
	lv_obj_set_pos(ui->baseScreen_hour, -210, 0);
	lv_obj_set_size(ui->baseScreen_hour, 660, 576);
	lv_obj_set_scrollbar_mode(ui->baseScreen_hour, LV_SCROLLBAR_MODE_OFF);

	//Write style for baseScreen_hour, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_hour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_hour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_hour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_hour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_hour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_hour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_hour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_hour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_hhBackground
	ui->baseScreen_hhBackground = lv_img_create(ui->baseScreen_hour);
	lv_obj_add_flag(ui->baseScreen_hhBackground, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_hhBackground, &_timePickerSelected_alpha_200x150);
	lv_img_set_pivot(ui->baseScreen_hhBackground, 50,50);
	lv_img_set_angle(ui->baseScreen_hhBackground, 0);
	lv_obj_set_pos(ui->baseScreen_hhBackground, 226, 180);
	lv_obj_set_size(ui->baseScreen_hhBackground, 200, 150);

	//Write style for baseScreen_hhBackground, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_hhBackground, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_hhUpArrow
	ui->baseScreen_hhUpArrow = lv_img_create(ui->baseScreen_hour);
	lv_obj_add_flag(ui->baseScreen_hhUpArrow, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_hhUpArrow, &_arrowWhite_alpha_54x54);
	lv_img_set_pivot(ui->baseScreen_hhUpArrow, 0,0);
	lv_img_set_angle(ui->baseScreen_hhUpArrow, 0);
	lv_obj_set_pos(ui->baseScreen_hhUpArrow, 300, 110);
	lv_obj_set_size(ui->baseScreen_hhUpArrow, 54, 54);

	//Write style for baseScreen_hhUpArrow, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_hhUpArrow, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_hhDownArrow
	ui->baseScreen_hhDownArrow = lv_img_create(ui->baseScreen_hour);
	lv_obj_add_flag(ui->baseScreen_hhDownArrow, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_hhDownArrow, &_arrowWhite_alpha_54x54);
	lv_img_set_pivot(ui->baseScreen_hhDownArrow, 25,0);
	lv_img_set_angle(ui->baseScreen_hhDownArrow, 1800);
	lv_obj_set_pos(ui->baseScreen_hhDownArrow, 300, 405);
	lv_obj_set_size(ui->baseScreen_hhDownArrow, 54, 54);

	//Write style for baseScreen_hhDownArrow, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_hhDownArrow, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_hhText
	ui->baseScreen_hhText = lv_label_create(ui->baseScreen_hour);
	lv_label_set_text(ui->baseScreen_hhText, "100\n");
	lv_label_set_long_mode(ui->baseScreen_hhText, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_hhText, 226, 207);
	lv_obj_set_size(ui->baseScreen_hhText, 200, 100);

	//Write style for baseScreen_hhText, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_hhText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_hhText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_hhText, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_hhText, &lv_font_MIMXRT1170EVKB_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_hhText, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_hhText, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_hhText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_hhText, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_hhText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_hhText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_hhText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_hhText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_hhText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_hhText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_menuTypeEight
	ui->baseScreen_menuTypeEight = lv_obj_create(ui->baseScreen_menuMainArea);
	lv_obj_set_pos(ui->baseScreen_menuTypeEight, 0, 144);
	lv_obj_set_size(ui->baseScreen_menuTypeEight, 660, 576);
	lv_obj_set_scrollbar_mode(ui->baseScreen_menuTypeEight, LV_SCROLLBAR_MODE_OFF);

	//Write style for baseScreen_menuTypeEight, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_menuTypeEight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_menuTypeEight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_menuTypeEight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_menuTypeEight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_menuTypeEight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_menuTypeEight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_menuTypeEight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_menuTypeEight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_BrightnessLevel10
	ui->baseScreen_BrightnessLevel10 = lv_img_create(ui->baseScreen_menuTypeEight);
	lv_obj_add_flag(ui->baseScreen_BrightnessLevel10, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_BrightnessLevel10, &_barEmpty_alpha_100x45);
	lv_img_set_pivot(ui->baseScreen_BrightnessLevel10, 50,50);
	lv_img_set_angle(ui->baseScreen_BrightnessLevel10, 0);
	lv_obj_set_pos(ui->baseScreen_BrightnessLevel10, 270, 0);
	lv_obj_set_size(ui->baseScreen_BrightnessLevel10, 100, 45);

	//Write style for baseScreen_BrightnessLevel10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_BrightnessLevel10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_BrightnessLevel9
	ui->baseScreen_BrightnessLevel9 = lv_img_create(ui->baseScreen_menuTypeEight);
	lv_obj_add_flag(ui->baseScreen_BrightnessLevel9, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_BrightnessLevel9, &_barEmpty_alpha_100x45);
	lv_img_set_pivot(ui->baseScreen_BrightnessLevel9, 50,50);
	lv_img_set_angle(ui->baseScreen_BrightnessLevel9, 0);
	lv_obj_set_pos(ui->baseScreen_BrightnessLevel9, 270, 50);
	lv_obj_set_size(ui->baseScreen_BrightnessLevel9, 100, 45);

	//Write style for baseScreen_BrightnessLevel9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_BrightnessLevel9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_BrightnessLevel8
	ui->baseScreen_BrightnessLevel8 = lv_img_create(ui->baseScreen_menuTypeEight);
	lv_obj_add_flag(ui->baseScreen_BrightnessLevel8, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_BrightnessLevel8, &_barEmpty_alpha_100x45);
	lv_img_set_pivot(ui->baseScreen_BrightnessLevel8, 50,50);
	lv_img_set_angle(ui->baseScreen_BrightnessLevel8, 0);
	lv_obj_set_pos(ui->baseScreen_BrightnessLevel8, 270, 100);
	lv_obj_set_size(ui->baseScreen_BrightnessLevel8, 100, 45);

	//Write style for baseScreen_BrightnessLevel8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_BrightnessLevel8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_BrightnessLevel7
	ui->baseScreen_BrightnessLevel7 = lv_img_create(ui->baseScreen_menuTypeEight);
	lv_obj_add_flag(ui->baseScreen_BrightnessLevel7, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_BrightnessLevel7, &_barEmpty_alpha_100x45);
	lv_img_set_pivot(ui->baseScreen_BrightnessLevel7, 50,50);
	lv_img_set_angle(ui->baseScreen_BrightnessLevel7, 0);
	lv_obj_set_pos(ui->baseScreen_BrightnessLevel7, 270, 150);
	lv_obj_set_size(ui->baseScreen_BrightnessLevel7, 100, 45);

	//Write style for baseScreen_BrightnessLevel7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_BrightnessLevel7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_BrightnessLevel6
	ui->baseScreen_BrightnessLevel6 = lv_img_create(ui->baseScreen_menuTypeEight);
	lv_obj_add_flag(ui->baseScreen_BrightnessLevel6, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_BrightnessLevel6, &_barEmpty_alpha_100x45);
	lv_img_set_pivot(ui->baseScreen_BrightnessLevel6, 50,50);
	lv_img_set_angle(ui->baseScreen_BrightnessLevel6, 0);
	lv_obj_set_pos(ui->baseScreen_BrightnessLevel6, 270, 200);
	lv_obj_set_size(ui->baseScreen_BrightnessLevel6, 100, 45);

	//Write style for baseScreen_BrightnessLevel6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_BrightnessLevel6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_BrightnessLevel5
	ui->baseScreen_BrightnessLevel5 = lv_img_create(ui->baseScreen_menuTypeEight);
	lv_obj_add_flag(ui->baseScreen_BrightnessLevel5, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_BrightnessLevel5, &_barEmpty_alpha_100x45);
	lv_img_set_pivot(ui->baseScreen_BrightnessLevel5, 50,50);
	lv_img_set_angle(ui->baseScreen_BrightnessLevel5, 0);
	lv_obj_set_pos(ui->baseScreen_BrightnessLevel5, 270, 250);
	lv_obj_set_size(ui->baseScreen_BrightnessLevel5, 100, 45);

	//Write style for baseScreen_BrightnessLevel5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_BrightnessLevel5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_BrightnessLevel4
	ui->baseScreen_BrightnessLevel4 = lv_img_create(ui->baseScreen_menuTypeEight);
	lv_obj_add_flag(ui->baseScreen_BrightnessLevel4, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_BrightnessLevel4, &_barEmpty_alpha_100x45);
	lv_img_set_pivot(ui->baseScreen_BrightnessLevel4, 50,50);
	lv_img_set_angle(ui->baseScreen_BrightnessLevel4, 0);
	lv_obj_set_pos(ui->baseScreen_BrightnessLevel4, 270, 300);
	lv_obj_set_size(ui->baseScreen_BrightnessLevel4, 100, 45);

	//Write style for baseScreen_BrightnessLevel4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_BrightnessLevel4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_BrightnessLevel3
	ui->baseScreen_BrightnessLevel3 = lv_img_create(ui->baseScreen_menuTypeEight);
	lv_obj_add_flag(ui->baseScreen_BrightnessLevel3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_BrightnessLevel3, &_barEmpty_alpha_100x45);
	lv_img_set_pivot(ui->baseScreen_BrightnessLevel3, 50,50);
	lv_img_set_angle(ui->baseScreen_BrightnessLevel3, 0);
	lv_obj_set_pos(ui->baseScreen_BrightnessLevel3, 270, 350);
	lv_obj_set_size(ui->baseScreen_BrightnessLevel3, 100, 45);

	//Write style for baseScreen_BrightnessLevel3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_BrightnessLevel3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_BrightnessLevel2
	ui->baseScreen_BrightnessLevel2 = lv_img_create(ui->baseScreen_menuTypeEight);
	lv_obj_add_flag(ui->baseScreen_BrightnessLevel2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_BrightnessLevel2, &_barEmpty_alpha_100x45);
	lv_img_set_pivot(ui->baseScreen_BrightnessLevel2, 50,50);
	lv_img_set_angle(ui->baseScreen_BrightnessLevel2, 0);
	lv_obj_set_pos(ui->baseScreen_BrightnessLevel2, 270, 400);
	lv_obj_set_size(ui->baseScreen_BrightnessLevel2, 100, 45);

	//Write style for baseScreen_BrightnessLevel2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_BrightnessLevel2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_BrightnessLevel1
	ui->baseScreen_BrightnessLevel1 = lv_img_create(ui->baseScreen_menuTypeEight);
	lv_obj_add_flag(ui->baseScreen_BrightnessLevel1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_BrightnessLevel1, &_barFill_alpha_100x45);
	lv_img_set_pivot(ui->baseScreen_BrightnessLevel1, 50,50);
	lv_img_set_angle(ui->baseScreen_BrightnessLevel1, 0);
	lv_obj_set_pos(ui->baseScreen_BrightnessLevel1, 270, 450);
	lv_obj_set_size(ui->baseScreen_BrightnessLevel1, 100, 45);

	//Write style for baseScreen_BrightnessLevel1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_BrightnessLevel1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_menuTypeSeven
	ui->baseScreen_menuTypeSeven = lv_obj_create(ui->baseScreen_menuMainArea);
	lv_obj_set_pos(ui->baseScreen_menuTypeSeven, 0, 144);
	lv_obj_set_size(ui->baseScreen_menuTypeSeven, 660, 576);
	lv_obj_set_scrollbar_mode(ui->baseScreen_menuTypeSeven, LV_SCROLLBAR_MODE_OFF);

	//Write style for baseScreen_menuTypeSeven, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_menuTypeSeven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_menuTypeSeven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_menuTypeSeven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_menuTypeSeven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_menuTypeSeven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_menuTypeSeven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_menuTypeSeven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_menuTypeSeven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_pairingKey
	ui->baseScreen_pairingKey = lv_label_create(ui->baseScreen_menuTypeSeven);
	lv_label_set_text(ui->baseScreen_pairingKey, "A X Y V R 2");
	lv_label_set_long_mode(ui->baseScreen_pairingKey, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_pairingKey, 30, 198);
	lv_obj_set_size(ui->baseScreen_pairingKey, 600, 100);

	//Write style for baseScreen_pairingKey, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_pairingKey, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_pairingKey, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_pairingKey, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_pairingKey, &lv_font_MIMXRT1170EVKB_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_pairingKey, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_pairingKey, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_pairingKey, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_pairingKey, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_pairingKey, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_pairingKey, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_pairingKey, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_pairingKey, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_pairingKey, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_pairingKey, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_menuTypeSix
	ui->baseScreen_menuTypeSix = lv_obj_create(ui->baseScreen_menuMainArea);
	lv_obj_set_pos(ui->baseScreen_menuTypeSix, 0, 144);
	lv_obj_set_size(ui->baseScreen_menuTypeSix, 660, 576);
	lv_obj_set_scrollbar_mode(ui->baseScreen_menuTypeSix, LV_SCROLLBAR_MODE_OFF);

	//Write style for baseScreen_menuTypeSix, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_menuTypeSix, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_menuTypeSix, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_menuTypeSix, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_menuTypeSix, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_menuTypeSix, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_menuTypeSix, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_menuTypeSix, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_menuTypeSix, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_speedAlertBackground
	ui->baseScreen_speedAlertBackground = lv_img_create(ui->baseScreen_menuTypeSix);
	lv_obj_add_flag(ui->baseScreen_speedAlertBackground, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_speedAlertBackground, &_timePickerSelected_alpha_200x150);
	lv_img_set_pivot(ui->baseScreen_speedAlertBackground, 50,50);
	lv_img_set_angle(ui->baseScreen_speedAlertBackground, 0);
	lv_obj_set_pos(ui->baseScreen_speedAlertBackground, 226, 180);
	lv_obj_set_size(ui->baseScreen_speedAlertBackground, 200, 150);

	//Write style for baseScreen_speedAlertBackground, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_speedAlertBackground, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_arrowUp
	ui->baseScreen_arrowUp = lv_img_create(ui->baseScreen_menuTypeSix);
	lv_obj_add_flag(ui->baseScreen_arrowUp, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_arrowUp, &_arrowWhite_alpha_54x54);
	lv_img_set_pivot(ui->baseScreen_arrowUp, 0,0);
	lv_img_set_angle(ui->baseScreen_arrowUp, 0);
	lv_obj_set_pos(ui->baseScreen_arrowUp, 300, 110);
	lv_obj_set_size(ui->baseScreen_arrowUp, 54, 54);

	//Write style for baseScreen_arrowUp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_arrowUp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_arrowDown
	ui->baseScreen_arrowDown = lv_img_create(ui->baseScreen_menuTypeSix);
	lv_obj_add_flag(ui->baseScreen_arrowDown, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_arrowDown, &_arrowWhite_alpha_54x54);
	lv_img_set_pivot(ui->baseScreen_arrowDown, 25,0);
	lv_img_set_angle(ui->baseScreen_arrowDown, 1800);
	lv_obj_set_pos(ui->baseScreen_arrowDown, 300, 405);
	lv_obj_set_size(ui->baseScreen_arrowDown, 54, 54);

	//Write style for baseScreen_arrowDown, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_arrowDown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_speedlimitUnit
	ui->baseScreen_speedlimitUnit = lv_label_create(ui->baseScreen_menuTypeSix);
	lv_label_set_text(ui->baseScreen_speedlimitUnit, "km/h");
	lv_label_set_long_mode(ui->baseScreen_speedlimitUnit, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_speedlimitUnit, 226, 270);
	lv_obj_set_size(ui->baseScreen_speedlimitUnit, 200, 50);

	//Write style for baseScreen_speedlimitUnit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_speedlimitUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_speedlimitUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_speedlimitUnit, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_speedlimitUnit, &lv_font_MIMXRT1170EVKB_50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_speedlimitUnit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_speedlimitUnit, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_speedlimitUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_speedlimitUnit, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_speedlimitUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_speedlimitUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_speedlimitUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_speedlimitUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_speedlimitUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_speedlimitUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_speedLimitValue
	ui->baseScreen_speedLimitValue = lv_label_create(ui->baseScreen_menuTypeSix);
	lv_label_set_text(ui->baseScreen_speedLimitValue, "100\n");
	lv_label_set_long_mode(ui->baseScreen_speedLimitValue, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_speedLimitValue, 226, 175);
	lv_obj_set_size(ui->baseScreen_speedLimitValue, 200, 100);

	//Write style for baseScreen_speedLimitValue, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_speedLimitValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_speedLimitValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_speedLimitValue, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_speedLimitValue, &lv_font_MIMXRT1170EVKB_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_speedLimitValue, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_speedLimitValue, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_speedLimitValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_speedLimitValue, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_speedLimitValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_speedLimitValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_speedLimitValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_speedLimitValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_speedLimitValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_speedLimitValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_menuTypeFive
	ui->baseScreen_menuTypeFive = lv_obj_create(ui->baseScreen_menuMainArea);
	lv_obj_set_pos(ui->baseScreen_menuTypeFive, 0, 144);
	lv_obj_set_size(ui->baseScreen_menuTypeFive, 660, 576);
	lv_obj_set_scrollbar_mode(ui->baseScreen_menuTypeFive, LV_SCROLLBAR_MODE_OFF);

	//Write style for baseScreen_menuTypeFive, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_menuTypeFive, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_menuTypeFive, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_menuTypeFive, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_menuTypeFive, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_menuTypeFive, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_menuTypeFive, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_menuTypeFive, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_menuTypeFive, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_topSpeedUnit
	ui->baseScreen_topSpeedUnit = lv_label_create(ui->baseScreen_menuTypeFive);
	lv_label_set_text(ui->baseScreen_topSpeedUnit, "km/h");
	lv_label_set_long_mode(ui->baseScreen_topSpeedUnit, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_topSpeedUnit, 30, 410);
	lv_obj_set_size(ui->baseScreen_topSpeedUnit, 600, 50);

	//Write style for baseScreen_topSpeedUnit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_topSpeedUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_topSpeedUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_topSpeedUnit, lv_color_hex(0x666666), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_topSpeedUnit, &lv_font_MIMXRT1170EVKB_50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_topSpeedUnit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_topSpeedUnit, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_topSpeedUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_topSpeedUnit, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_topSpeedUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_topSpeedUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_topSpeedUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_topSpeedUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_topSpeedUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_topSpeedUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_topSpeedLabel
	ui->baseScreen_topSpeedLabel = lv_label_create(ui->baseScreen_menuTypeFive);
	lv_label_set_text(ui->baseScreen_topSpeedLabel, "Top speed");
	lv_label_set_long_mode(ui->baseScreen_topSpeedLabel, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_topSpeedLabel, 30, 260);
	lv_obj_set_size(ui->baseScreen_topSpeedLabel, 600, 50);

	//Write style for baseScreen_topSpeedLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_topSpeedLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_topSpeedLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_topSpeedLabel, lv_color_hex(0x00A0EE), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_topSpeedLabel, &lv_font_MIMXRT1170EVKB_50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_topSpeedLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_topSpeedLabel, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_topSpeedLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_topSpeedLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_topSpeedLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_topSpeedLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_topSpeedLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_topSpeedLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_topSpeedLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_topSpeedLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_topSpeedValue
	ui->baseScreen_topSpeedValue = lv_label_create(ui->baseScreen_menuTypeFive);
	lv_label_set_text(ui->baseScreen_topSpeedValue, "115");
	lv_label_set_long_mode(ui->baseScreen_topSpeedValue, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_topSpeedValue, 30, 335);
	lv_obj_set_size(ui->baseScreen_topSpeedValue, 600, 75);

	//Write style for baseScreen_topSpeedValue, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_topSpeedValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_topSpeedValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_topSpeedValue, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_topSpeedValue, &lv_font_MIMXRT1170EVKB_75, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_topSpeedValue, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_topSpeedValue, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_topSpeedValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_topSpeedValue, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_topSpeedValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_topSpeedValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_topSpeedValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_topSpeedValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_topSpeedValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_topSpeedValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_averageSpeedUnit
	ui->baseScreen_averageSpeedUnit = lv_label_create(ui->baseScreen_menuTypeFive);
	lv_label_set_text(ui->baseScreen_averageSpeedUnit, "km/h");
	lv_label_set_long_mode(ui->baseScreen_averageSpeedUnit, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_averageSpeedUnit, 30, 175);
	lv_obj_set_size(ui->baseScreen_averageSpeedUnit, 600, 50);

	//Write style for baseScreen_averageSpeedUnit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_averageSpeedUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_averageSpeedUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_averageSpeedUnit, lv_color_hex(0x666666), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_averageSpeedUnit, &lv_font_MIMXRT1170EVKB_50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_averageSpeedUnit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_averageSpeedUnit, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_averageSpeedUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_averageSpeedUnit, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_averageSpeedUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_averageSpeedUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_averageSpeedUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_averageSpeedUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_averageSpeedUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_averageSpeedUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_averageSpeedValue
	ui->baseScreen_averageSpeedValue = lv_label_create(ui->baseScreen_menuTypeFive);
	lv_label_set_text(ui->baseScreen_averageSpeedValue, "65");
	lv_label_set_long_mode(ui->baseScreen_averageSpeedValue, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_averageSpeedValue, 0, 100);
	lv_obj_set_size(ui->baseScreen_averageSpeedValue, 660, 75);

	//Write style for baseScreen_averageSpeedValue, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_averageSpeedValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_averageSpeedValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_averageSpeedValue, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_averageSpeedValue, &lv_font_MIMXRT1170EVKB_75, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_averageSpeedValue, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_averageSpeedValue, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_averageSpeedValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_averageSpeedValue, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_averageSpeedValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_averageSpeedValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_averageSpeedValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_averageSpeedValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_averageSpeedValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_averageSpeedValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_averageSpeedLabel
	ui->baseScreen_averageSpeedLabel = lv_label_create(ui->baseScreen_menuTypeFive);
	lv_label_set_text(ui->baseScreen_averageSpeedLabel, "Average speed");
	lv_label_set_long_mode(ui->baseScreen_averageSpeedLabel, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_averageSpeedLabel, 30, 25);
	lv_obj_set_size(ui->baseScreen_averageSpeedLabel, 600, 50);

	//Write style for baseScreen_averageSpeedLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_averageSpeedLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_averageSpeedLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_averageSpeedLabel, lv_color_hex(0x00A0EE), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_averageSpeedLabel, &lv_font_MIMXRT1170EVKB_50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_averageSpeedLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_averageSpeedLabel, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_averageSpeedLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_averageSpeedLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_averageSpeedLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_averageSpeedLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_averageSpeedLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_averageSpeedLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_averageSpeedLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_averageSpeedLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_menuTypeFour
	ui->baseScreen_menuTypeFour = lv_obj_create(ui->baseScreen_menuMainArea);
	lv_obj_set_pos(ui->baseScreen_menuTypeFour, 0, 144);
	lv_obj_set_size(ui->baseScreen_menuTypeFour, 660, 576);
	lv_obj_set_scrollbar_mode(ui->baseScreen_menuTypeFour, LV_SCROLLBAR_MODE_OFF);

	//Write style for baseScreen_menuTypeFour, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_menuTypeFour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_menuTypeFour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_menuTypeFour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_menuTypeFour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_menuTypeFour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_menuTypeFour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_menuTypeFour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_menuTypeFour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_serviceDaysValue
	ui->baseScreen_serviceDaysValue = lv_label_create(ui->baseScreen_menuTypeFour);
	lv_label_set_text(ui->baseScreen_serviceDaysValue, "68\n\n");
	lv_label_set_long_mode(ui->baseScreen_serviceDaysValue, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_serviceDaysValue, 345, 335);
	lv_obj_set_size(ui->baseScreen_serviceDaysValue, 300, 75);

	//Write style for baseScreen_serviceDaysValue, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_serviceDaysValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_serviceDaysValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_serviceDaysValue, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_serviceDaysValue, &lv_font_MIMXRT1170EVKB_75, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_serviceDaysValue, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_serviceDaysValue, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_serviceDaysValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_serviceDaysValue, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_serviceDaysValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_serviceDaysValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_serviceDaysValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_serviceDaysValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_serviceDaysValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_serviceDaysValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_serviceDaysUnit
	ui->baseScreen_serviceDaysUnit = lv_label_create(ui->baseScreen_menuTypeFour);
	lv_label_set_text(ui->baseScreen_serviceDaysUnit, "Days");
	lv_label_set_long_mode(ui->baseScreen_serviceDaysUnit, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_serviceDaysUnit, 345, 410);
	lv_obj_set_size(ui->baseScreen_serviceDaysUnit, 300, 50);

	//Write style for baseScreen_serviceDaysUnit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_serviceDaysUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_serviceDaysUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_serviceDaysUnit, lv_color_hex(0x666666), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_serviceDaysUnit, &lv_font_MIMXRT1170EVKB_50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_serviceDaysUnit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_serviceDaysUnit, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_serviceDaysUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_serviceDaysUnit, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_serviceDaysUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_serviceDaysUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_serviceDaysUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_serviceDaysUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_serviceDaysUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_serviceDaysUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_serviceDistanceUnit
	ui->baseScreen_serviceDistanceUnit = lv_label_create(ui->baseScreen_menuTypeFour);
	lv_label_set_text(ui->baseScreen_serviceDistanceUnit, "Km");
	lv_label_set_long_mode(ui->baseScreen_serviceDistanceUnit, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_serviceDistanceUnit, 30, 410);
	lv_obj_set_size(ui->baseScreen_serviceDistanceUnit, 300, 50);

	//Write style for baseScreen_serviceDistanceUnit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_serviceDistanceUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_serviceDistanceUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_serviceDistanceUnit, lv_color_hex(0x666666), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_serviceDistanceUnit, &lv_font_MIMXRT1170EVKB_50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_serviceDistanceUnit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_serviceDistanceUnit, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_serviceDistanceUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_serviceDistanceUnit, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_serviceDistanceUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_serviceDistanceUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_serviceDistanceUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_serviceDistanceUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_serviceDistanceUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_serviceDistanceUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_serviceDistanceValue
	ui->baseScreen_serviceDistanceValue = lv_label_create(ui->baseScreen_menuTypeFour);
	lv_label_set_text(ui->baseScreen_serviceDistanceValue, "115");
	lv_label_set_long_mode(ui->baseScreen_serviceDistanceValue, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_serviceDistanceValue, 30, 335);
	lv_obj_set_size(ui->baseScreen_serviceDistanceValue, 300, 75);

	//Write style for baseScreen_serviceDistanceValue, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_serviceDistanceValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_serviceDistanceValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_serviceDistanceValue, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_serviceDistanceValue, &lv_font_MIMXRT1170EVKB_75, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_serviceDistanceValue, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_serviceDistanceValue, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_serviceDistanceValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_serviceDistanceValue, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_serviceDistanceValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_serviceDistanceValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_serviceDistanceValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_serviceDistanceValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_serviceDistanceValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_serviceDistanceValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_dividers
	ui->baseScreen_dividers = lv_img_create(ui->baseScreen_menuTypeFour);
	lv_obj_add_flag(ui->baseScreen_dividers, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_dividers, &_barFill_alpha_10x100);
	lv_img_set_pivot(ui->baseScreen_dividers, 200,60);
	lv_img_set_angle(ui->baseScreen_dividers, 0);
	lv_obj_set_pos(ui->baseScreen_dividers, 325, 350);
	lv_obj_set_size(ui->baseScreen_dividers, 10, 100);

	//Write style for baseScreen_dividers, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_dividers, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_lastServiceLabel
	ui->baseScreen_lastServiceLabel = lv_label_create(ui->baseScreen_menuTypeFour);
	lv_label_set_text(ui->baseScreen_lastServiceLabel, "Since last service");
	lv_label_set_long_mode(ui->baseScreen_lastServiceLabel, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_lastServiceLabel, 30, 260);
	lv_obj_set_size(ui->baseScreen_lastServiceLabel, 600, 50);

	//Write style for baseScreen_lastServiceLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_lastServiceLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_lastServiceLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_lastServiceLabel, lv_color_hex(0x00A0EE), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_lastServiceLabel, &lv_font_MIMXRT1170EVKB_50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_lastServiceLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_lastServiceLabel, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_lastServiceLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_lastServiceLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_lastServiceLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_lastServiceLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_lastServiceLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_lastServiceLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_lastServiceLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_lastServiceLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_serviceDateUnit
	ui->baseScreen_serviceDateUnit = lv_label_create(ui->baseScreen_menuTypeFour);
	lv_label_set_text(ui->baseScreen_serviceDateUnit, "DD/MM/YY");
	lv_label_set_long_mode(ui->baseScreen_serviceDateUnit, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_serviceDateUnit, 30, 175);
	lv_obj_set_size(ui->baseScreen_serviceDateUnit, 600, 50);

	//Write style for baseScreen_serviceDateUnit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_serviceDateUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_serviceDateUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_serviceDateUnit, lv_color_hex(0x666666), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_serviceDateUnit, &lv_font_MIMXRT1170EVKB_50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_serviceDateUnit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_serviceDateUnit, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_serviceDateUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_serviceDateUnit, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_serviceDateUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_serviceDateUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_serviceDateUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_serviceDateUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_serviceDateUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_serviceDateUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_serviceDateValue
	ui->baseScreen_serviceDateValue = lv_label_create(ui->baseScreen_menuTypeFour);
	lv_label_set_text(ui->baseScreen_serviceDateValue, "24/04/2024");
	lv_label_set_long_mode(ui->baseScreen_serviceDateValue, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_serviceDateValue, 0, 100);
	lv_obj_set_size(ui->baseScreen_serviceDateValue, 660, 75);

	//Write style for baseScreen_serviceDateValue, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_serviceDateValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_serviceDateValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_serviceDateValue, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_serviceDateValue, &lv_font_MIMXRT1170EVKB_75, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_serviceDateValue, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_serviceDateValue, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_serviceDateValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_serviceDateValue, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_serviceDateValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_serviceDateValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_serviceDateValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_serviceDateValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_serviceDateValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_serviceDateValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_serviceDateLabel
	ui->baseScreen_serviceDateLabel = lv_label_create(ui->baseScreen_menuTypeFour);
	lv_label_set_text(ui->baseScreen_serviceDateLabel, "Next service due date");
	lv_label_set_long_mode(ui->baseScreen_serviceDateLabel, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_serviceDateLabel, 30, 25);
	lv_obj_set_size(ui->baseScreen_serviceDateLabel, 600, 50);

	//Write style for baseScreen_serviceDateLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_serviceDateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_serviceDateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_serviceDateLabel, lv_color_hex(0x00A0EE), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_serviceDateLabel, &lv_font_MIMXRT1170EVKB_50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_serviceDateLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_serviceDateLabel, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_serviceDateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_serviceDateLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_serviceDateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_serviceDateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_serviceDateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_serviceDateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_serviceDateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_serviceDateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_menuTypeThree
	ui->baseScreen_menuTypeThree = lv_obj_create(ui->baseScreen_menuMainArea);
	lv_obj_set_pos(ui->baseScreen_menuTypeThree, 0, 144);
	lv_obj_set_size(ui->baseScreen_menuTypeThree, 660, 576);
	lv_obj_set_scrollbar_mode(ui->baseScreen_menuTypeThree, LV_SCROLLBAR_MODE_OFF);

	//Write style for baseScreen_menuTypeThree, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_menuTypeThree, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_menuTypeThree, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_menuTypeThree, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_menuTypeThree, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_menuTypeThree, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_menuTypeThree, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_menuTypeThree, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_menuTypeThree, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_loading
	ui->baseScreen_loading = lv_img_create(ui->baseScreen_menuTypeThree);
	lv_obj_add_flag(ui->baseScreen_loading, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_loading, &_loadingIcon_alpha_75x75);
	lv_img_set_pivot(ui->baseScreen_loading, 37,37);
	lv_img_set_angle(ui->baseScreen_loading, 0);
	lv_obj_set_pos(ui->baseScreen_loading, 280, 160);
	lv_obj_set_size(ui->baseScreen_loading, 75, 75);

	//Write style for baseScreen_loading, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_loading, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_loadingText
	ui->baseScreen_loadingText = lv_label_create(ui->baseScreen_menuTypeThree);
	lv_label_set_text(ui->baseScreen_loadingText, "Loading");
	lv_label_set_long_mode(ui->baseScreen_loadingText, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_loadingText, 0, 275);
	lv_obj_set_size(ui->baseScreen_loadingText, 660, 50);

	//Write style for baseScreen_loadingText, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_loadingText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_loadingText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_loadingText, lv_color_hex(0x0093E7), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_loadingText, &lv_font_MIMXRT1170EVKB_50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_loadingText, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_loadingText, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_loadingText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_loadingText, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_loadingText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_loadingText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_loadingText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_loadingText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_loadingText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_loadingText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_menuTypeTwo
	ui->baseScreen_menuTypeTwo = lv_obj_create(ui->baseScreen_menuMainArea);
	lv_obj_set_pos(ui->baseScreen_menuTypeTwo, 0, 144);
	lv_obj_set_size(ui->baseScreen_menuTypeTwo, 660, 576);
	lv_obj_set_scrollbar_mode(ui->baseScreen_menuTypeTwo, LV_SCROLLBAR_MODE_OFF);

	//Write style for baseScreen_menuTypeTwo, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_menuTypeTwo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_menuTypeTwo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_menuTypeTwo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_menuTypeTwo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_menuTypeTwo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_menuTypeTwo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_menuTypeTwo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_menuTypeTwo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_containerOne
	ui->baseScreen_containerOne = lv_obj_create(ui->baseScreen_menuTypeTwo);
	lv_obj_set_pos(ui->baseScreen_containerOne, 10, 25);
	lv_obj_set_size(ui->baseScreen_containerOne, 200, 200);
	lv_obj_set_scrollbar_mode(ui->baseScreen_containerOne, LV_SCROLLBAR_MODE_OFF);

	//Write style for baseScreen_containerOne, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_containerOne, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_containerOne, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_containerOne, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_containerOne, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_containerOne, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_containerOne, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_containerOne, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_containerOne, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_widgetMenuType3Label1
	ui->baseScreen_widgetMenuType3Label1 = lv_label_create(ui->baseScreen_containerOne);
	lv_label_set_text(ui->baseScreen_widgetMenuType3Label1, "Trip Distance\nCovered");
	lv_label_set_long_mode(ui->baseScreen_widgetMenuType3Label1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_widgetMenuType3Label1, 0, 0);
	lv_obj_set_size(ui->baseScreen_widgetMenuType3Label1, 200, 60);

	//Write style for baseScreen_widgetMenuType3Label1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_widgetMenuType3Label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_widgetMenuType3Label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_widgetMenuType3Label1, lv_color_hex(0x0093E7), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_widgetMenuType3Label1, &lv_font_MIMXRT1170EVKB_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_widgetMenuType3Label1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_widgetMenuType3Label1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_widgetMenuType3Label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_widgetMenuType3Label1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_widgetMenuType3Label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_widgetMenuType3Label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_widgetMenuType3Label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_widgetMenuType3Label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_widgetMenuType3Label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_widgetMenuType3Label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_widgetMenuType3Unit
	ui->baseScreen_widgetMenuType3Unit = lv_label_create(ui->baseScreen_containerOne);
	lv_label_set_text(ui->baseScreen_widgetMenuType3Unit, "km");
	lv_label_set_long_mode(ui->baseScreen_widgetMenuType3Unit, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_widgetMenuType3Unit, 0, 125);
	lv_obj_set_size(ui->baseScreen_widgetMenuType3Unit, 200, 30);

	//Write style for baseScreen_widgetMenuType3Unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_widgetMenuType3Unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_widgetMenuType3Unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_widgetMenuType3Unit, lv_color_hex(0xAEAEAE), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_widgetMenuType3Unit, &lv_font_MIMXRT1170EVKB_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_widgetMenuType3Unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_widgetMenuType3Unit, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_widgetMenuType3Unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_widgetMenuType3Unit, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_widgetMenuType3Unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_widgetMenuType3Unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_widgetMenuType3Unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_widgetMenuType3Unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_widgetMenuType3Unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_widgetMenuType3Unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_widgetMenuType3Value
	ui->baseScreen_widgetMenuType3Value = lv_label_create(ui->baseScreen_containerOne);
	lv_label_set_text(ui->baseScreen_widgetMenuType3Value, "999");
	lv_label_set_long_mode(ui->baseScreen_widgetMenuType3Value, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_widgetMenuType3Value, 0, 75);
	lv_obj_set_size(ui->baseScreen_widgetMenuType3Value, 200, 50);

	//Write style for baseScreen_widgetMenuType3Value, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_widgetMenuType3Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_widgetMenuType3Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_widgetMenuType3Value, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_widgetMenuType3Value, &lv_font_MIMXRT1170EVKB_50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_widgetMenuType3Value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_widgetMenuType3Value, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_widgetMenuType3Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_widgetMenuType3Value, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_widgetMenuType3Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_widgetMenuType3Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_widgetMenuType3Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_widgetMenuType3Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_widgetMenuType3Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_widgetMenuType3Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_containerTwo
	ui->baseScreen_containerTwo = lv_obj_create(ui->baseScreen_menuTypeTwo);
	lv_obj_set_pos(ui->baseScreen_containerTwo, 220, 25);
	lv_obj_set_size(ui->baseScreen_containerTwo, 200, 200);
	lv_obj_set_scrollbar_mode(ui->baseScreen_containerTwo, LV_SCROLLBAR_MODE_OFF);

	//Write style for baseScreen_containerTwo, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_containerTwo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_containerTwo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_containerTwo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_containerTwo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_containerTwo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_containerTwo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_containerTwo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_containerTwo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_widgetMenuType3Label2
	ui->baseScreen_widgetMenuType3Label2 = lv_label_create(ui->baseScreen_containerTwo);
	lv_label_set_text(ui->baseScreen_widgetMenuType3Label2, "Total time travelled");
	lv_label_set_long_mode(ui->baseScreen_widgetMenuType3Label2, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_widgetMenuType3Label2, 0, 0);
	lv_obj_set_size(ui->baseScreen_widgetMenuType3Label2, 200, 60);

	//Write style for baseScreen_widgetMenuType3Label2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_widgetMenuType3Label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_widgetMenuType3Label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_widgetMenuType3Label2, lv_color_hex(0x0093E7), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_widgetMenuType3Label2, &lv_font_MIMXRT1170EVKB_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_widgetMenuType3Label2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_widgetMenuType3Label2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_widgetMenuType3Label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_widgetMenuType3Label2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_widgetMenuType3Label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_widgetMenuType3Label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_widgetMenuType3Label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_widgetMenuType3Label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_widgetMenuType3Label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_widgetMenuType3Label2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_widgetMenuType3Unit2
	ui->baseScreen_widgetMenuType3Unit2 = lv_label_create(ui->baseScreen_containerTwo);
	lv_label_set_text(ui->baseScreen_widgetMenuType3Unit2, "hh:mm:ss");
	lv_label_set_long_mode(ui->baseScreen_widgetMenuType3Unit2, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_widgetMenuType3Unit2, 0, 125);
	lv_obj_set_size(ui->baseScreen_widgetMenuType3Unit2, 200, 30);

	//Write style for baseScreen_widgetMenuType3Unit2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_widgetMenuType3Unit2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_widgetMenuType3Unit2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_widgetMenuType3Unit2, lv_color_hex(0xAEAEAE), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_widgetMenuType3Unit2, &lv_font_MIMXRT1170EVKB_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_widgetMenuType3Unit2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_widgetMenuType3Unit2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_widgetMenuType3Unit2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_widgetMenuType3Unit2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_widgetMenuType3Unit2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_widgetMenuType3Unit2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_widgetMenuType3Unit2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_widgetMenuType3Unit2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_widgetMenuType3Unit2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_widgetMenuType3Unit2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_widgetMenuType3Value2
	static bool baseScreen_widgetMenuType3Value2_timer_enabled = false;
	ui->baseScreen_widgetMenuType3Value2 = lv_dclock_create(ui->baseScreen_containerTwo, "0:00:00");
	if (!baseScreen_widgetMenuType3Value2_timer_enabled) {
		lv_timer_create(baseScreen_widgetMenuType3Value2_timer, 1000, NULL);
		baseScreen_widgetMenuType3Value2_timer_enabled = true;
	}
	lv_obj_set_pos(ui->baseScreen_widgetMenuType3Value2, 0, 68);
	lv_obj_set_size(ui->baseScreen_widgetMenuType3Value2, 200, 50);

	//Write style for baseScreen_widgetMenuType3Value2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_radius(ui->baseScreen_widgetMenuType3Value2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_widgetMenuType3Value2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_widgetMenuType3Value2, &lv_font_MIMXRT1170EVKB_50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_widgetMenuType3Value2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_widgetMenuType3Value2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_widgetMenuType3Value2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_widgetMenuType3Value2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_widgetMenuType3Value2, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_widgetMenuType3Value2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_widgetMenuType3Value2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_widgetMenuType3Value2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_widgetMenuType3Value2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_containerThree
	ui->baseScreen_containerThree = lv_obj_create(ui->baseScreen_menuTypeTwo);
	lv_obj_set_pos(ui->baseScreen_containerThree, 430, 25);
	lv_obj_set_size(ui->baseScreen_containerThree, 200, 200);
	lv_obj_set_scrollbar_mode(ui->baseScreen_containerThree, LV_SCROLLBAR_MODE_OFF);

	//Write style for baseScreen_containerThree, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_containerThree, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_containerThree, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_containerThree, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_containerThree, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_containerThree, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_containerThree, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_containerThree, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_containerThree, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_widgetMenuType3Label3
	ui->baseScreen_widgetMenuType3Label3 = lv_label_create(ui->baseScreen_containerThree);
	lv_label_set_text(ui->baseScreen_widgetMenuType3Label3, "Average\nspeed");
	lv_label_set_long_mode(ui->baseScreen_widgetMenuType3Label3, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_widgetMenuType3Label3, 0, 0);
	lv_obj_set_size(ui->baseScreen_widgetMenuType3Label3, 200, 60);

	//Write style for baseScreen_widgetMenuType3Label3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_widgetMenuType3Label3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_widgetMenuType3Label3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_widgetMenuType3Label3, lv_color_hex(0x0093E7), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_widgetMenuType3Label3, &lv_font_MIMXRT1170EVKB_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_widgetMenuType3Label3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_widgetMenuType3Label3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_widgetMenuType3Label3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_widgetMenuType3Label3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_widgetMenuType3Label3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_widgetMenuType3Label3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_widgetMenuType3Label3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_widgetMenuType3Label3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_widgetMenuType3Label3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_widgetMenuType3Label3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_widgetMenuType3Unit3
	ui->baseScreen_widgetMenuType3Unit3 = lv_label_create(ui->baseScreen_containerThree);
	lv_label_set_text(ui->baseScreen_widgetMenuType3Unit3, "km/h");
	lv_label_set_long_mode(ui->baseScreen_widgetMenuType3Unit3, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_widgetMenuType3Unit3, 0, 125);
	lv_obj_set_size(ui->baseScreen_widgetMenuType3Unit3, 200, 30);

	//Write style for baseScreen_widgetMenuType3Unit3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_widgetMenuType3Unit3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_widgetMenuType3Unit3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_widgetMenuType3Unit3, lv_color_hex(0xAEAEAE), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_widgetMenuType3Unit3, &lv_font_MIMXRT1170EVKB_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_widgetMenuType3Unit3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_widgetMenuType3Unit3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_widgetMenuType3Unit3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_widgetMenuType3Unit3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_widgetMenuType3Unit3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_widgetMenuType3Unit3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_widgetMenuType3Unit3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_widgetMenuType3Unit3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_widgetMenuType3Unit3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_widgetMenuType3Unit3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_widgetMenuType3Value3
	ui->baseScreen_widgetMenuType3Value3 = lv_label_create(ui->baseScreen_containerThree);
	lv_label_set_text(ui->baseScreen_widgetMenuType3Value3, "999");
	lv_label_set_long_mode(ui->baseScreen_widgetMenuType3Value3, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_widgetMenuType3Value3, 0, 75);
	lv_obj_set_size(ui->baseScreen_widgetMenuType3Value3, 200, 50);

	//Write style for baseScreen_widgetMenuType3Value3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_widgetMenuType3Value3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_widgetMenuType3Value3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_widgetMenuType3Value3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_widgetMenuType3Value3, &lv_font_MIMXRT1170EVKB_50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_widgetMenuType3Value3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_widgetMenuType3Value3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_widgetMenuType3Value3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_widgetMenuType3Value3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_widgetMenuType3Value3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_widgetMenuType3Value3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_widgetMenuType3Value3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_widgetMenuType3Value3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_widgetMenuType3Value3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_widgetMenuType3Value3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_containerFour
	ui->baseScreen_containerFour = lv_obj_create(ui->baseScreen_menuTypeTwo);
	lv_obj_set_pos(ui->baseScreen_containerFour, 10, 225);
	lv_obj_set_size(ui->baseScreen_containerFour, 200, 200);
	lv_obj_set_scrollbar_mode(ui->baseScreen_containerFour, LV_SCROLLBAR_MODE_OFF);

	//Write style for baseScreen_containerFour, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_containerFour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_containerFour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_containerFour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_containerFour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_containerFour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_containerFour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_containerFour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_containerFour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_widgetMenuType3Label4
	ui->baseScreen_widgetMenuType3Label4 = lv_label_create(ui->baseScreen_containerFour);
	lv_label_set_text(ui->baseScreen_widgetMenuType3Label4, "\nTop speed");
	lv_label_set_long_mode(ui->baseScreen_widgetMenuType3Label4, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_widgetMenuType3Label4, 0, 0);
	lv_obj_set_size(ui->baseScreen_widgetMenuType3Label4, 200, 60);

	//Write style for baseScreen_widgetMenuType3Label4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_widgetMenuType3Label4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_widgetMenuType3Label4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_widgetMenuType3Label4, lv_color_hex(0x0093E7), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_widgetMenuType3Label4, &lv_font_MIMXRT1170EVKB_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_widgetMenuType3Label4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_widgetMenuType3Label4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_widgetMenuType3Label4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_widgetMenuType3Label4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_widgetMenuType3Label4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_widgetMenuType3Label4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_widgetMenuType3Label4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_widgetMenuType3Label4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_widgetMenuType3Label4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_widgetMenuType3Label4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_widgetMenuType3Unit4
	ui->baseScreen_widgetMenuType3Unit4 = lv_label_create(ui->baseScreen_containerFour);
	lv_label_set_text(ui->baseScreen_widgetMenuType3Unit4, "km");
	lv_label_set_long_mode(ui->baseScreen_widgetMenuType3Unit4, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_widgetMenuType3Unit4, 0, 125);
	lv_obj_set_size(ui->baseScreen_widgetMenuType3Unit4, 200, 30);

	//Write style for baseScreen_widgetMenuType3Unit4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_widgetMenuType3Unit4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_widgetMenuType3Unit4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_widgetMenuType3Unit4, lv_color_hex(0xAEAEAE), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_widgetMenuType3Unit4, &lv_font_MIMXRT1170EVKB_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_widgetMenuType3Unit4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_widgetMenuType3Unit4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_widgetMenuType3Unit4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_widgetMenuType3Unit4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_widgetMenuType3Unit4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_widgetMenuType3Unit4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_widgetMenuType3Unit4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_widgetMenuType3Unit4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_widgetMenuType3Unit4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_widgetMenuType3Unit4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_widgetMenuType3Value4
	ui->baseScreen_widgetMenuType3Value4 = lv_label_create(ui->baseScreen_containerFour);
	lv_label_set_text(ui->baseScreen_widgetMenuType3Value4, "999");
	lv_label_set_long_mode(ui->baseScreen_widgetMenuType3Value4, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_widgetMenuType3Value4, 0, 75);
	lv_obj_set_size(ui->baseScreen_widgetMenuType3Value4, 200, 50);

	//Write style for baseScreen_widgetMenuType3Value4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_widgetMenuType3Value4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_widgetMenuType3Value4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_widgetMenuType3Value4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_widgetMenuType3Value4, &lv_font_MIMXRT1170EVKB_50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_widgetMenuType3Value4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_widgetMenuType3Value4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_widgetMenuType3Value4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_widgetMenuType3Value4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_widgetMenuType3Value4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_widgetMenuType3Value4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_widgetMenuType3Value4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_widgetMenuType3Value4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_widgetMenuType3Value4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_widgetMenuType3Value4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_containerFive
	ui->baseScreen_containerFive = lv_obj_create(ui->baseScreen_menuTypeTwo);
	lv_obj_set_pos(ui->baseScreen_containerFive, 220, 225);
	lv_obj_set_size(ui->baseScreen_containerFive, 200, 200);
	lv_obj_set_scrollbar_mode(ui->baseScreen_containerFive, LV_SCROLLBAR_MODE_OFF);

	//Write style for baseScreen_containerFive, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_containerFive, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_containerFive, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_containerFive, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_containerFive, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_containerFive, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_containerFive, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_containerFive, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_containerFive, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_widgetMenuType3Label5
	ui->baseScreen_widgetMenuType3Label5 = lv_label_create(ui->baseScreen_containerFive);
	lv_label_set_text(ui->baseScreen_widgetMenuType3Label5, "Battery\nconsumed");
	lv_label_set_long_mode(ui->baseScreen_widgetMenuType3Label5, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_widgetMenuType3Label5, 0, 0);
	lv_obj_set_size(ui->baseScreen_widgetMenuType3Label5, 200, 60);

	//Write style for baseScreen_widgetMenuType3Label5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_widgetMenuType3Label5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_widgetMenuType3Label5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_widgetMenuType3Label5, lv_color_hex(0x0093E7), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_widgetMenuType3Label5, &lv_font_MIMXRT1170EVKB_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_widgetMenuType3Label5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_widgetMenuType3Label5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_widgetMenuType3Label5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_widgetMenuType3Label5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_widgetMenuType3Label5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_widgetMenuType3Label5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_widgetMenuType3Label5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_widgetMenuType3Label5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_widgetMenuType3Label5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_widgetMenuType3Label5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_widgetMenuType3Unit5
	ui->baseScreen_widgetMenuType3Unit5 = lv_label_create(ui->baseScreen_containerFive);
	lv_label_set_text(ui->baseScreen_widgetMenuType3Unit5, "km");
	lv_label_set_long_mode(ui->baseScreen_widgetMenuType3Unit5, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_widgetMenuType3Unit5, 0, 125);
	lv_obj_set_size(ui->baseScreen_widgetMenuType3Unit5, 200, 30);

	//Write style for baseScreen_widgetMenuType3Unit5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_widgetMenuType3Unit5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_widgetMenuType3Unit5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_widgetMenuType3Unit5, lv_color_hex(0xAEAEAE), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_widgetMenuType3Unit5, &lv_font_MIMXRT1170EVKB_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_widgetMenuType3Unit5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_widgetMenuType3Unit5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_widgetMenuType3Unit5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_widgetMenuType3Unit5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_widgetMenuType3Unit5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_widgetMenuType3Unit5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_widgetMenuType3Unit5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_widgetMenuType3Unit5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_widgetMenuType3Unit5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_widgetMenuType3Unit5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_widgetMenuType3Value5
	ui->baseScreen_widgetMenuType3Value5 = lv_label_create(ui->baseScreen_containerFive);
	lv_label_set_text(ui->baseScreen_widgetMenuType3Value5, "999");
	lv_label_set_long_mode(ui->baseScreen_widgetMenuType3Value5, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_widgetMenuType3Value5, 0, 75);
	lv_obj_set_size(ui->baseScreen_widgetMenuType3Value5, 200, 50);

	//Write style for baseScreen_widgetMenuType3Value5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_widgetMenuType3Value5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_widgetMenuType3Value5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_widgetMenuType3Value5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_widgetMenuType3Value5, &lv_font_MIMXRT1170EVKB_50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_widgetMenuType3Value5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_widgetMenuType3Value5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_widgetMenuType3Value5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_widgetMenuType3Value5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_widgetMenuType3Value5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_widgetMenuType3Value5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_widgetMenuType3Value5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_widgetMenuType3Value5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_widgetMenuType3Value5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_widgetMenuType3Value5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_containerSix
	ui->baseScreen_containerSix = lv_obj_create(ui->baseScreen_menuTypeTwo);
	lv_obj_set_pos(ui->baseScreen_containerSix, 430, 225);
	lv_obj_set_size(ui->baseScreen_containerSix, 200, 200);
	lv_obj_set_scrollbar_mode(ui->baseScreen_containerSix, LV_SCROLLBAR_MODE_OFF);

	//Write style for baseScreen_containerSix, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_containerSix, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_containerSix, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_containerSix, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_containerSix, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_containerSix, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_containerSix, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_containerSix, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_containerSix, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_widgetMenuType3Label6
	ui->baseScreen_widgetMenuType3Label6 = lv_label_create(ui->baseScreen_containerSix);
	lv_label_set_text(ui->baseScreen_widgetMenuType3Label6, "Average\nmileage");
	lv_label_set_long_mode(ui->baseScreen_widgetMenuType3Label6, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_widgetMenuType3Label6, 0, 0);
	lv_obj_set_size(ui->baseScreen_widgetMenuType3Label6, 200, 60);

	//Write style for baseScreen_widgetMenuType3Label6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_widgetMenuType3Label6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_widgetMenuType3Label6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_widgetMenuType3Label6, lv_color_hex(0x0093E7), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_widgetMenuType3Label6, &lv_font_MIMXRT1170EVKB_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_widgetMenuType3Label6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_widgetMenuType3Label6, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_widgetMenuType3Label6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_widgetMenuType3Label6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_widgetMenuType3Label6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_widgetMenuType3Label6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_widgetMenuType3Label6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_widgetMenuType3Label6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_widgetMenuType3Label6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_widgetMenuType3Label6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_widgetMenuType3Unit6
	ui->baseScreen_widgetMenuType3Unit6 = lv_label_create(ui->baseScreen_containerSix);
	lv_label_set_text(ui->baseScreen_widgetMenuType3Unit6, "km");
	lv_label_set_long_mode(ui->baseScreen_widgetMenuType3Unit6, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_widgetMenuType3Unit6, 0, 125);
	lv_obj_set_size(ui->baseScreen_widgetMenuType3Unit6, 200, 30);

	//Write style for baseScreen_widgetMenuType3Unit6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_widgetMenuType3Unit6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_widgetMenuType3Unit6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_widgetMenuType3Unit6, lv_color_hex(0xAEAEAE), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_widgetMenuType3Unit6, &lv_font_MIMXRT1170EVKB_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_widgetMenuType3Unit6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_widgetMenuType3Unit6, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_widgetMenuType3Unit6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_widgetMenuType3Unit6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_widgetMenuType3Unit6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_widgetMenuType3Unit6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_widgetMenuType3Unit6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_widgetMenuType3Unit6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_widgetMenuType3Unit6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_widgetMenuType3Unit6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_widgetMenuType3Value6
	ui->baseScreen_widgetMenuType3Value6 = lv_label_create(ui->baseScreen_containerSix);
	lv_label_set_text(ui->baseScreen_widgetMenuType3Value6, "999");
	lv_label_set_long_mode(ui->baseScreen_widgetMenuType3Value6, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_widgetMenuType3Value6, 0, 75);
	lv_obj_set_size(ui->baseScreen_widgetMenuType3Value6, 200, 50);

	//Write style for baseScreen_widgetMenuType3Value6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_widgetMenuType3Value6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_widgetMenuType3Value6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_widgetMenuType3Value6, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_widgetMenuType3Value6, &lv_font_MIMXRT1170EVKB_50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_widgetMenuType3Value6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_widgetMenuType3Value6, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_widgetMenuType3Value6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_widgetMenuType3Value6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_widgetMenuType3Value6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_widgetMenuType3Value6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_widgetMenuType3Value6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_widgetMenuType3Value6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_widgetMenuType3Value6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_widgetMenuType3Value6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_resetButton
	ui->baseScreen_resetButton = lv_label_create(ui->baseScreen_menuTypeTwo);
	lv_label_set_text(ui->baseScreen_resetButton, "Reset trip");
	lv_label_set_long_mode(ui->baseScreen_resetButton, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_resetButton, 0, 400);
	lv_obj_set_size(ui->baseScreen_resetButton, 660, 75);

	//Write style for baseScreen_resetButton, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_resetButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_resetButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_resetButton, lv_color_hex(0xFCCD26), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_resetButton, &lv_font_MIMXRT1170EVKB_75, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_resetButton, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_resetButton, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_resetButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_resetButton, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_resetButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_resetButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_resetButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_resetButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_resetButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_resetButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_menuTypeOne
	ui->baseScreen_menuTypeOne = lv_obj_create(ui->baseScreen_menuMainArea);
	lv_obj_set_pos(ui->baseScreen_menuTypeOne, 0, 144);
	lv_obj_set_size(ui->baseScreen_menuTypeOne, 660, 576);
	lv_obj_set_scrollbar_mode(ui->baseScreen_menuTypeOne, LV_SCROLLBAR_MODE_OFF);

	//Write style for baseScreen_menuTypeOne, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_menuTypeOne, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_menuTypeOne, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_menuTypeOne, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_menuTypeOne, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_menuTypeOne, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_menuTypeOne, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_menuTypeOne, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_menuTypeOne, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_optionOne
	ui->baseScreen_optionOne = lv_label_create(ui->baseScreen_menuTypeOne);
	lv_label_set_text(ui->baseScreen_optionOne, "Trip 1");
	lv_label_set_long_mode(ui->baseScreen_optionOne, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_optionOne, 0, 20);
	lv_obj_set_size(ui->baseScreen_optionOne, 660, 75);

	//Write style for baseScreen_optionOne, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_optionOne, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_optionOne, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_optionOne, lv_color_hex(0xFCCD26), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_optionOne, &lv_font_MIMXRT1170EVKB_75, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_optionOne, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_optionOne, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_optionOne, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_optionOne, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_optionOne, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_optionOne, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_optionOne, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_optionOne, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_optionOne, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_optionOne, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_optionTwo
	ui->baseScreen_optionTwo = lv_label_create(ui->baseScreen_menuTypeOne);
	lv_label_set_text(ui->baseScreen_optionTwo, "Trip 2\n");
	lv_label_set_long_mode(ui->baseScreen_optionTwo, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_optionTwo, 0, 115);
	lv_obj_set_size(ui->baseScreen_optionTwo, 660, 75);

	//Write style for baseScreen_optionTwo, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_optionTwo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_optionTwo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_optionTwo, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_optionTwo, &lv_font_MIMXRT1170EVKB_75, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_optionTwo, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_optionTwo, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_optionTwo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_optionTwo, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_optionTwo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_optionTwo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_optionTwo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_optionTwo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_optionTwo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_optionTwo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_optionThree
	ui->baseScreen_optionThree = lv_label_create(ui->baseScreen_menuTypeOne);
	lv_label_set_text(ui->baseScreen_optionThree, "Trip 3\n\n");
	lv_label_set_long_mode(ui->baseScreen_optionThree, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_optionThree, 0, 210);
	lv_obj_set_size(ui->baseScreen_optionThree, 660, 75);

	//Write style for baseScreen_optionThree, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_optionThree, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_optionThree, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_optionThree, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_optionThree, &lv_font_MIMXRT1170EVKB_75, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_optionThree, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_optionThree, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_optionThree, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_optionThree, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_optionThree, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_optionThree, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_optionThree, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_optionThree, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_optionThree, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_optionThree, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_optionFour
	ui->baseScreen_optionFour = lv_label_create(ui->baseScreen_menuTypeOne);
	lv_label_set_text(ui->baseScreen_optionFour, "Trip 4");
	lv_label_set_long_mode(ui->baseScreen_optionFour, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_optionFour, 0, 305);
	lv_obj_set_size(ui->baseScreen_optionFour, 660, 75);

	//Write style for baseScreen_optionFour, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_optionFour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_optionFour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_optionFour, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_optionFour, &lv_font_MIMXRT1170EVKB_75, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_optionFour, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_optionFour, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_optionFour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_optionFour, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_optionFour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_optionFour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_optionFour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_optionFour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_optionFour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_optionFour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_optionFive
	ui->baseScreen_optionFive = lv_label_create(ui->baseScreen_menuTypeOne);
	lv_label_set_text(ui->baseScreen_optionFive, "Daily trip meter");
	lv_label_set_long_mode(ui->baseScreen_optionFive, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_optionFive, 0, 400);
	lv_obj_set_size(ui->baseScreen_optionFive, 660, 75);

	//Write style for baseScreen_optionFive, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_optionFive, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_optionFive, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_optionFive, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_optionFive, &lv_font_MIMXRT1170EVKB_75, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_optionFive, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_optionFive, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_optionFive, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_optionFive, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_optionFive, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_optionFive, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_optionFive, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_optionFive, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_optionFive, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_optionFive, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_toggle
	ui->baseScreen_toggle = lv_img_create(ui->baseScreen_menuTypeOne);
	lv_obj_add_flag(ui->baseScreen_toggle, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_toggle, &_toggleIcon_alpha_75x75);
	lv_img_set_pivot(ui->baseScreen_toggle, 200,60);
	lv_img_set_angle(ui->baseScreen_toggle, 0);
	lv_obj_set_pos(ui->baseScreen_toggle, 585, 20);
	lv_obj_set_size(ui->baseScreen_toggle, 75, 75);

	//Write style for baseScreen_toggle, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_toggle, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_menuHeading
	ui->baseScreen_menuHeading = lv_label_create(ui->baseScreen_menuMainArea);
	lv_label_set_text(ui->baseScreen_menuHeading, "Trip settings");
	lv_label_set_long_mode(ui->baseScreen_menuHeading, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_menuHeading, 0, 40);
	lv_obj_set_size(ui->baseScreen_menuHeading, 660, 75);

	//Write style for baseScreen_menuHeading, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_menuHeading, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_menuHeading, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_menuHeading, lv_color_hex(0x00A0EE), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_menuHeading, &lv_font_MIMXRT1170EVKB_75, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_menuHeading, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_menuHeading, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_menuHeading, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_menuHeading, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_menuHeading, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_menuHeading, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_menuHeading, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_menuHeading, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_menuHeading, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_menuHeading, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_menuScrollBar
	ui->baseScreen_menuScrollBar = lv_obj_create(ui->baseScreen_menuWidget);
	lv_obj_set_pos(ui->baseScreen_menuScrollBar, 150, 15);
	lv_obj_set_size(ui->baseScreen_menuScrollBar, 10, 640);
	lv_obj_set_scrollbar_mode(ui->baseScreen_menuScrollBar, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->baseScreen_menuScrollBar, LV_OBJ_FLAG_HIDDEN);

	//Write style for baseScreen_menuScrollBar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_menuScrollBar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_menuScrollBar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_menuScrollBar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_menuScrollBar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_menuScrollBar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_menuScrollBar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_menuScrollBar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_menuScrollBar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_scroll2Div
	ui->baseScreen_scroll2Div = lv_img_create(ui->baseScreen_menuScrollBar);
	lv_obj_add_flag(ui->baseScreen_scroll2Div, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_scroll2Div, &_scrol2Div_alpha_10x320);
	lv_img_set_pivot(ui->baseScreen_scroll2Div, 200,60);
	lv_img_set_angle(ui->baseScreen_scroll2Div, 0);
	lv_obj_set_pos(ui->baseScreen_scroll2Div, 0, 0);
	lv_obj_set_size(ui->baseScreen_scroll2Div, 10, 320);

	//Write style for baseScreen_scroll2Div, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_scroll2Div, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_scroll3Div
	ui->baseScreen_scroll3Div = lv_img_create(ui->baseScreen_menuScrollBar);
	lv_obj_add_flag(ui->baseScreen_scroll3Div, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_scroll3Div, &_scroll3Div_alpha_10x210);
	lv_img_set_pivot(ui->baseScreen_scroll3Div, 200,60);
	lv_img_set_angle(ui->baseScreen_scroll3Div, 0);
	lv_obj_set_pos(ui->baseScreen_scroll3Div, 0, 0);
	lv_obj_set_size(ui->baseScreen_scroll3Div, 10, 210);

	//Write style for baseScreen_scroll3Div, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_scroll3Div, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_ringArea
	ui->baseScreen_ringArea = lv_obj_create(ui->baseScreen);
	lv_obj_set_pos(ui->baseScreen_ringArea, 0, 0);
	lv_obj_set_size(ui->baseScreen_ringArea, 1280, 720);
	lv_obj_set_scrollbar_mode(ui->baseScreen_ringArea, LV_SCROLLBAR_MODE_OFF);

	//Write style for baseScreen_ringArea, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_ringArea, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_ringArea, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_ringArea, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_ringArea, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_ringArea, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_ringArea, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_ringArea, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_ringArea, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_speedometerWidget
	ui->baseScreen_speedometerWidget = lv_obj_create(ui->baseScreen_ringArea);
	lv_obj_set_pos(ui->baseScreen_speedometerWidget, 50, 60);
	lv_obj_set_size(ui->baseScreen_speedometerWidget, 801, 602);
	lv_obj_set_scrollbar_mode(ui->baseScreen_speedometerWidget, LV_SCROLLBAR_MODE_OFF);

	//Write style for baseScreen_speedometerWidget, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_speedometerWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_speedometerWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_speedometerWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_speedometerWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_speedometerWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_speedometerWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_speedometerWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_speedometerWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_speedometerScale
	ui->baseScreen_speedometerScale = lv_img_create(ui->baseScreen_speedometerWidget);
	lv_obj_add_flag(ui->baseScreen_speedometerScale, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_speedometerScale, &_speedometerBackground_alpha_508x506);
	lv_img_set_pivot(ui->baseScreen_speedometerScale, 50,50);
	lv_img_set_angle(ui->baseScreen_speedometerScale, 0);
	lv_obj_set_pos(ui->baseScreen_speedometerScale, 147, 34);
	lv_obj_set_size(ui->baseScreen_speedometerScale, 508, 506);

	//Write style for baseScreen_speedometerScale, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_speedometerScale, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_speedometerNeedle
	ui->baseScreen_speedometerNeedle = lv_img_create(ui->baseScreen_speedometerWidget);
	lv_obj_add_flag(ui->baseScreen_speedometerNeedle, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_speedometerNeedle, &_speedometerNeedle_alpha_507x507);
	lv_img_set_pivot(ui->baseScreen_speedometerNeedle, 253,253);
	lv_img_set_angle(ui->baseScreen_speedometerNeedle, 0);
	lv_obj_set_pos(ui->baseScreen_speedometerNeedle, 147, 35);
	lv_obj_set_size(ui->baseScreen_speedometerNeedle, 507, 507);

	//Write style for baseScreen_speedometerNeedle, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_speedometerNeedle, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_speedometerRing
	ui->baseScreen_speedometerRing = lv_img_create(ui->baseScreen_speedometerWidget);
	lv_obj_add_flag(ui->baseScreen_speedometerRing, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_speedometerRing, &_speedometerRing_alpha_801x602);
	lv_img_set_pivot(ui->baseScreen_speedometerRing, 50,50);
	lv_img_set_angle(ui->baseScreen_speedometerRing, 0);
	lv_obj_set_pos(ui->baseScreen_speedometerRing, 0, 0);
	lv_obj_set_size(ui->baseScreen_speedometerRing, 801, 602);

	//Write style for baseScreen_speedometerRing, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_speedometerRing, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_speedometerValue
	ui->baseScreen_speedometerValue = lv_label_create(ui->baseScreen_speedometerWidget);
	lv_label_set_text(ui->baseScreen_speedometerValue, "0");
	lv_label_set_long_mode(ui->baseScreen_speedometerValue, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_speedometerValue, 0, 188);
	lv_obj_set_size(ui->baseScreen_speedometerValue, 802, 185);

	//Write style for baseScreen_speedometerValue, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_speedometerValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_speedometerValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_speedometerValue, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_speedometerValue, &lv_font_speedometerValue_200, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_speedometerValue, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_speedometerValue, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_speedometerValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_speedometerValue, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_speedometerValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_speedometerValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_speedometerValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_speedometerValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_speedometerValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_speedometerValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_speedometerUnit
	ui->baseScreen_speedometerUnit = lv_label_create(ui->baseScreen_speedometerWidget);
	lv_label_set_text(ui->baseScreen_speedometerUnit, "kmph");
	lv_label_set_long_mode(ui->baseScreen_speedometerUnit, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_speedometerUnit, 0, 390);
	lv_obj_set_size(ui->baseScreen_speedometerUnit, 802, 30);

	//Write style for baseScreen_speedometerUnit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_speedometerUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_speedometerUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_speedometerUnit, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_speedometerUnit, &lv_font_MIMXRT1170EVKB_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_speedometerUnit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_speedometerUnit, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_speedometerUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_speedometerUnit, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_speedometerUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_speedometerUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_speedometerUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_speedometerUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_speedometerUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_speedometerUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_batteryWidget
	ui->baseScreen_batteryWidget = lv_obj_create(ui->baseScreen_ringArea);
	lv_obj_set_pos(ui->baseScreen_batteryWidget, 50, 60);
	lv_obj_set_size(ui->baseScreen_batteryWidget, 202, 560);
	lv_obj_set_scrollbar_mode(ui->baseScreen_batteryWidget, LV_SCROLLBAR_MODE_OFF);

	//Write style for baseScreen_batteryWidget, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_batteryWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_batteryWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_batteryWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_batteryWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_batteryWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_batteryWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_batteryWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_batteryWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_segment1
	ui->baseScreen_segment1 = lv_img_create(ui->baseScreen_batteryWidget);
	lv_obj_add_flag(ui->baseScreen_segment1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_segment1, &_1_alpha_120x110);
	lv_img_set_pivot(ui->baseScreen_segment1, 50,50);
	lv_img_set_angle(ui->baseScreen_segment1, 0);
	lv_obj_set_pos(ui->baseScreen_segment1, 76, 452);
	lv_obj_set_size(ui->baseScreen_segment1, 120, 110);

	//Write style for baseScreen_segment1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_segment1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_segment2
	ui->baseScreen_segment2 = lv_img_create(ui->baseScreen_batteryWidget);
	lv_obj_add_flag(ui->baseScreen_segment2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_segment2, &_2_alpha_126x98);
	lv_img_set_pivot(ui->baseScreen_segment2, 50,50);
	lv_img_set_angle(ui->baseScreen_segment2, 0);
	lv_obj_set_pos(ui->baseScreen_segment2, 44, 415);
	lv_obj_set_size(ui->baseScreen_segment2, 126, 98);

	//Write style for baseScreen_segment2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_segment2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_segment3
	ui->baseScreen_segment3 = lv_img_create(ui->baseScreen_batteryWidget);
	lv_obj_add_flag(ui->baseScreen_segment3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_segment3, &_3_alpha_128x85);
	lv_img_set_pivot(ui->baseScreen_segment3, 50,50);
	lv_img_set_angle(ui->baseScreen_segment3, 0);
	lv_obj_set_pos(ui->baseScreen_segment3, 20, 375);
	lv_obj_set_size(ui->baseScreen_segment3, 128, 85);

	//Write style for baseScreen_segment3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_segment3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_segment4
	ui->baseScreen_segment4 = lv_img_create(ui->baseScreen_batteryWidget);
	lv_obj_add_flag(ui->baseScreen_segment4, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_segment4, &_4_alpha_128x68);
	lv_img_set_pivot(ui->baseScreen_segment4, 50,50);
	lv_img_set_angle(ui->baseScreen_segment4, 0);
	lv_obj_set_pos(ui->baseScreen_segment4, 5, 332);
	lv_obj_set_size(ui->baseScreen_segment4, 128, 68);

	//Write style for baseScreen_segment4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_segment4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_segment5
	ui->baseScreen_segment5 = lv_img_create(ui->baseScreen_batteryWidget);
	lv_obj_add_flag(ui->baseScreen_segment5, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_segment5, &_5_alpha_123x51);
	lv_img_set_pivot(ui->baseScreen_segment5, 50,50);
	lv_img_set_angle(ui->baseScreen_segment5, 0);
	lv_obj_set_pos(ui->baseScreen_segment5, 0, 288);
	lv_obj_set_size(ui->baseScreen_segment5, 123, 51);

	//Write style for baseScreen_segment5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_segment5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_segment6
	ui->baseScreen_segment6 = lv_img_create(ui->baseScreen_batteryWidget);
	lv_obj_add_flag(ui->baseScreen_segment6, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_segment6, &_6_alpha_124x51);
	lv_img_set_pivot(ui->baseScreen_segment6, 50,50);
	lv_img_set_angle(ui->baseScreen_segment6, 0);
	lv_obj_set_pos(ui->baseScreen_segment6, 0, 226);
	lv_obj_set_size(ui->baseScreen_segment6, 124, 51);

	//Write style for baseScreen_segment6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_segment6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_segment7
	ui->baseScreen_segment7 = lv_img_create(ui->baseScreen_batteryWidget);
	lv_obj_add_flag(ui->baseScreen_segment7, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_segment7, &_7_alpha_127x72);
	lv_img_set_pivot(ui->baseScreen_segment7, 50,50);
	lv_img_set_angle(ui->baseScreen_segment7, 0);
	lv_obj_set_pos(ui->baseScreen_segment7, 7, 165);
	lv_obj_set_size(ui->baseScreen_segment7, 127, 72);

	//Write style for baseScreen_segment7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_segment7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_segment8
	ui->baseScreen_segment8 = lv_img_create(ui->baseScreen_batteryWidget);
	lv_obj_add_flag(ui->baseScreen_segment8, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_segment8, &_8_alpha_128x88);
	lv_img_set_pivot(ui->baseScreen_segment8, 50,50);
	lv_img_set_angle(ui->baseScreen_segment8, 0);
	lv_obj_set_pos(ui->baseScreen_segment8, 24, 107);
	lv_obj_set_size(ui->baseScreen_segment8, 128, 88);

	//Write style for baseScreen_segment8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_segment8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_segment9
	ui->baseScreen_segment9 = lv_img_create(ui->baseScreen_batteryWidget);
	lv_obj_add_flag(ui->baseScreen_segment9, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_segment9, &_9_alpha_125x101);
	lv_img_set_pivot(ui->baseScreen_segment9, 50,50);
	lv_img_set_angle(ui->baseScreen_segment9, 0);
	lv_obj_set_pos(ui->baseScreen_segment9, 49, 53);
	lv_obj_set_size(ui->baseScreen_segment9, 125, 101);

	//Write style for baseScreen_segment9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_segment9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_segment10
	ui->baseScreen_segment10 = lv_img_create(ui->baseScreen_batteryWidget);
	lv_obj_add_flag(ui->baseScreen_segment10, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_segment10, &_10_alpha_119x112);
	lv_img_set_pivot(ui->baseScreen_segment10, 50,50);
	lv_img_set_angle(ui->baseScreen_segment10, 0);
	lv_obj_set_pos(ui->baseScreen_segment10, 81, 2);
	lv_obj_set_size(ui->baseScreen_segment10, 119, 112);

	//Write style for baseScreen_segment10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_segment10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_gearIndicatorsWidget
	ui->baseScreen_gearIndicatorsWidget = lv_obj_create(ui->baseScreen_ringArea);
	lv_obj_set_pos(ui->baseScreen_gearIndicatorsWidget, 373, 546);
	lv_obj_set_size(ui->baseScreen_gearIndicatorsWidget, 150, 75);
	lv_obj_set_scrollbar_mode(ui->baseScreen_gearIndicatorsWidget, LV_SCROLLBAR_MODE_OFF);

	//Write style for baseScreen_gearIndicatorsWidget, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_gearIndicatorsWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_gearIndicatorsWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_gearIndicatorsWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_gearIndicatorsWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_gearIndicatorsWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_gearIndicatorsWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_gearIndicatorsWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_gearIndicatorsWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_gearIndicatorArrow
	ui->baseScreen_gearIndicatorArrow = lv_img_create(ui->baseScreen_gearIndicatorsWidget);
	lv_obj_add_flag(ui->baseScreen_gearIndicatorArrow, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_gearIndicatorArrow, &_gearindicatorArrow_alpha_37x33);
	lv_img_set_pivot(ui->baseScreen_gearIndicatorArrow, 50,50);
	lv_img_set_angle(ui->baseScreen_gearIndicatorArrow, 0);
	lv_obj_set_pos(ui->baseScreen_gearIndicatorArrow, 20, 22);
	lv_obj_set_size(ui->baseScreen_gearIndicatorArrow, 37, 33);

	//Write style for baseScreen_gearIndicatorArrow, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_gearIndicatorArrow, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_gearIndicatorValue
	ui->baseScreen_gearIndicatorValue = lv_label_create(ui->baseScreen_gearIndicatorsWidget);
	lv_label_set_text(ui->baseScreen_gearIndicatorValue, "N");
	lv_label_set_long_mode(ui->baseScreen_gearIndicatorValue, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_gearIndicatorValue, 38, 13);
	lv_obj_set_size(ui->baseScreen_gearIndicatorValue, 100, 50);

	//Write style for baseScreen_gearIndicatorValue, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_gearIndicatorValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_gearIndicatorValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_gearIndicatorValue, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_gearIndicatorValue, &lv_font_MIMXRT1170EVKB_50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_gearIndicatorValue, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_gearIndicatorValue, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_gearIndicatorValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_gearIndicatorValue, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_gearIndicatorValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_gearIndicatorValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_gearIndicatorValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_gearIndicatorValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_gearIndicatorValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_gearIndicatorValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_rideModeWidget
	ui->baseScreen_rideModeWidget = lv_obj_create(ui->baseScreen_ringArea);
	lv_obj_set_pos(ui->baseScreen_rideModeWidget, 641, 60);
	lv_obj_set_size(ui->baseScreen_rideModeWidget, 209, 575);
	lv_obj_set_scrollbar_mode(ui->baseScreen_rideModeWidget, LV_SCROLLBAR_MODE_OFF);

	//Write style for baseScreen_rideModeWidget, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_rideModeWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_rideModeWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_rideModeWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_rideModeWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_rideModeWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_rideModeWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_rideModeWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_rideModeWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_powerImage
	ui->baseScreen_powerImage = lv_img_create(ui->baseScreen_rideModeWidget);
	lv_obj_add_flag(ui->baseScreen_powerImage, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_powerImage, &_power_alpha_189x211);
	lv_img_set_pivot(ui->baseScreen_powerImage, 50,50);
	lv_img_set_angle(ui->baseScreen_powerImage, 0);
	lv_obj_set_pos(ui->baseScreen_powerImage, 7, 355);
	lv_obj_set_size(ui->baseScreen_powerImage, 189, 211);

	//Write style for baseScreen_powerImage, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_powerImage, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_autoImage
	ui->baseScreen_autoImage = lv_img_create(ui->baseScreen_rideModeWidget);
	lv_obj_add_flag(ui->baseScreen_autoImage, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_autoImage, &_auto_alpha_130x208);
	lv_img_set_pivot(ui->baseScreen_autoImage, 50,50);
	lv_img_set_angle(ui->baseScreen_autoImage, 0);
	lv_obj_set_pos(ui->baseScreen_autoImage, 79, 179);
	lv_obj_set_size(ui->baseScreen_autoImage, 130, 208);

	//Write style for baseScreen_autoImage, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_autoImage, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_ecoImage
	ui->baseScreen_ecoImage = lv_img_create(ui->baseScreen_rideModeWidget);
	lv_obj_add_flag(ui->baseScreen_ecoImage, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_ecoImage, &_eco_alpha_189x211);
	lv_img_set_pivot(ui->baseScreen_ecoImage, 50,50);
	lv_img_set_angle(ui->baseScreen_ecoImage, 0);
	lv_obj_set_pos(ui->baseScreen_ecoImage, 7, 0);
	lv_obj_set_size(ui->baseScreen_ecoImage, 189, 211);

	//Write style for baseScreen_ecoImage, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_ecoImage, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_batteryValueGroup
	ui->baseScreen_batteryValueGroup = lv_obj_create(ui->baseScreen_ringArea);
	lv_obj_set_pos(ui->baseScreen_batteryValueGroup, 179, 34);
	lv_obj_set_size(ui->baseScreen_batteryValueGroup, 184, 120);
	lv_obj_set_scrollbar_mode(ui->baseScreen_batteryValueGroup, LV_SCROLLBAR_MODE_OFF);

	//Write style for baseScreen_batteryValueGroup, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_batteryValueGroup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_batteryValueGroup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_batteryValueGroup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_batteryValueGroup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_batteryValueGroup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_batteryValueGroup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_batteryValueGroup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_batteryValueGroup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_batteryValue
	ui->baseScreen_batteryValue = lv_img_create(ui->baseScreen_batteryValueGroup);
	lv_obj_add_flag(ui->baseScreen_batteryValue, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_batteryValue, &_powerIcon_alpha_48x48);
	lv_img_set_pivot(ui->baseScreen_batteryValue, 50,50);
	lv_img_set_angle(ui->baseScreen_batteryValue, 0);
	lv_obj_set_pos(ui->baseScreen_batteryValue, 10, 10);
	lv_obj_set_size(ui->baseScreen_batteryValue, 48, 48);

	//Write style for baseScreen_batteryValue, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_batteryValue, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_batteryIcon
	ui->baseScreen_batteryIcon = lv_label_create(ui->baseScreen_batteryValueGroup);
	lv_label_set_text(ui->baseScreen_batteryIcon, "100");
	lv_label_set_long_mode(ui->baseScreen_batteryIcon, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_batteryIcon, 35, 40);
	lv_obj_set_size(ui->baseScreen_batteryIcon, 75, 48);

	//Write style for baseScreen_batteryIcon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_batteryIcon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_batteryIcon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_batteryIcon, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_batteryIcon, &lv_font_MIMXRT1170EVKB_50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_batteryIcon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_batteryIcon, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_batteryIcon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_batteryIcon, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_batteryIcon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_batteryIcon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_batteryIcon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_batteryIcon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_batteryIcon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_batteryIcon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_widgetWindow
	ui->baseScreen_widgetWindow = lv_obj_create(ui->baseScreen_ringArea);
	lv_obj_set_pos(ui->baseScreen_widgetWindow, 860, 110);
	lv_obj_set_size(ui->baseScreen_widgetWindow, 400, 600);
	lv_obj_set_scrollbar_mode(ui->baseScreen_widgetWindow, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->baseScreen_widgetWindow, LV_OBJ_FLAG_HIDDEN);

	//Write style for baseScreen_widgetWindow, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_widgetWindow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_widgetWindow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_widgetWindow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_widgetWindow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_widgetWindow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_widgetWindow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_widgetWindow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_widgetWindow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_fourthWidget
	ui->baseScreen_fourthWidget = lv_obj_create(ui->baseScreen_widgetWindow);
	lv_obj_set_pos(ui->baseScreen_fourthWidget, 0, 375);
	lv_obj_set_size(ui->baseScreen_fourthWidget, 400, 120);
	lv_obj_set_scrollbar_mode(ui->baseScreen_fourthWidget, LV_SCROLLBAR_MODE_OFF);

	//Write style for baseScreen_fourthWidget, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_fourthWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_fourthWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_fourthWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_fourthWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_fourthWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_fourthWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_fourthWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_fourthWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_widgetFourBackground
	ui->baseScreen_widgetFourBackground = lv_img_create(ui->baseScreen_fourthWidget);
	lv_obj_add_flag(ui->baseScreen_widgetFourBackground, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_widgetFourBackground, &_widgetbackground_alpha_400x120);
	lv_img_set_pivot(ui->baseScreen_widgetFourBackground, 200,60);
	lv_img_set_angle(ui->baseScreen_widgetFourBackground, 0);
	lv_obj_set_pos(ui->baseScreen_widgetFourBackground, 0, 0);
	lv_obj_set_size(ui->baseScreen_widgetFourBackground, 400, 120);

	//Write style for baseScreen_widgetFourBackground, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_widgetFourBackground, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_widgetFourUnit
	ui->baseScreen_widgetFourUnit = lv_label_create(ui->baseScreen_fourthWidget);
	lv_label_set_text(ui->baseScreen_widgetFourUnit, "psi\n");
	lv_label_set_long_mode(ui->baseScreen_widgetFourUnit, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_widgetFourUnit, 35, 85);
	lv_obj_set_size(ui->baseScreen_widgetFourUnit, 160, 30);

	//Write style for baseScreen_widgetFourUnit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_widgetFourUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_widgetFourUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_widgetFourUnit, lv_color_hex(0xAEAEAE), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_widgetFourUnit, &lv_font_MIMXRT1170EVKB_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_widgetFourUnit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_widgetFourUnit, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_widgetFourUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_widgetFourUnit, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_widgetFourUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_widgetFourUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_widgetFourUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_widgetFourUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_widgetFourUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_widgetFourUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_widgetFourValue
	ui->baseScreen_widgetFourValue = lv_label_create(ui->baseScreen_fourthWidget);
	lv_label_set_text(ui->baseScreen_widgetFourValue, "45");
	lv_label_set_long_mode(ui->baseScreen_widgetFourValue, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_widgetFourValue, 35, 35);
	lv_obj_set_size(ui->baseScreen_widgetFourValue, 160, 50);

	//Write style for baseScreen_widgetFourValue, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_widgetFourValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_widgetFourValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_widgetFourValue, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_widgetFourValue, &lv_font_MIMXRT1170EVKB_50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_widgetFourValue, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_widgetFourValue, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_widgetFourValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_widgetFourValue, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_widgetFourValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_widgetFourValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_widgetFourValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_widgetFourValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_widgetFourValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_widgetFourValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_widgetFourLabel
	ui->baseScreen_widgetFourLabel = lv_label_create(ui->baseScreen_fourthWidget);
	lv_label_set_text(ui->baseScreen_widgetFourLabel, "Tyre pressure");
	lv_label_set_long_mode(ui->baseScreen_widgetFourLabel, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_widgetFourLabel, 40, 5);
	lv_obj_set_size(ui->baseScreen_widgetFourLabel, 320, 30);

	//Write style for baseScreen_widgetFourLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_widgetFourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_widgetFourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_widgetFourLabel, lv_color_hex(0x0093E7), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_widgetFourLabel, &lv_font_MIMXRT1170EVKB_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_widgetFourLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_widgetFourLabel, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_widgetFourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_widgetFourLabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_widgetFourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_widgetFourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_widgetFourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_widgetFourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_widgetFourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_widgetFourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_widgetFourValue2
	ui->baseScreen_widgetFourValue2 = lv_label_create(ui->baseScreen_fourthWidget);
	lv_label_set_text(ui->baseScreen_widgetFourValue2, "24");
	lv_label_set_long_mode(ui->baseScreen_widgetFourValue2, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_widgetFourValue2, 205, 35);
	lv_obj_set_size(ui->baseScreen_widgetFourValue2, 160, 50);

	//Write style for baseScreen_widgetFourValue2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_widgetFourValue2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_widgetFourValue2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_widgetFourValue2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_widgetFourValue2, &lv_font_MIMXRT1170EVKB_50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_widgetFourValue2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_widgetFourValue2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_widgetFourValue2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_widgetFourValue2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_widgetFourValue2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_widgetFourValue2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_widgetFourValue2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_widgetFourValue2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_widgetFourValue2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_widgetFourValue2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_widgetFourUnit2
	ui->baseScreen_widgetFourUnit2 = lv_label_create(ui->baseScreen_fourthWidget);
	lv_label_set_text(ui->baseScreen_widgetFourUnit2, "psi");
	lv_label_set_long_mode(ui->baseScreen_widgetFourUnit2, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_widgetFourUnit2, 205, 85);
	lv_obj_set_size(ui->baseScreen_widgetFourUnit2, 160, 30);

	//Write style for baseScreen_widgetFourUnit2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_widgetFourUnit2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_widgetFourUnit2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_widgetFourUnit2, lv_color_hex(0xAEAEAE), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_widgetFourUnit2, &lv_font_MIMXRT1170EVKB_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_widgetFourUnit2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_widgetFourUnit2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_widgetFourUnit2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_widgetFourUnit2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_widgetFourUnit2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_widgetFourUnit2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_widgetFourUnit2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_widgetFourUnit2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_widgetFourUnit2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_widgetFourUnit2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_divider
	ui->baseScreen_divider = lv_img_create(ui->baseScreen_fourthWidget);
	lv_obj_add_flag(ui->baseScreen_divider, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_divider, &_barFill_alpha_5x50);
	lv_img_set_pivot(ui->baseScreen_divider, 200,60);
	lv_img_set_angle(ui->baseScreen_divider, 0);
	lv_obj_set_pos(ui->baseScreen_divider, 195, 50);
	lv_obj_set_size(ui->baseScreen_divider, 5, 50);

	//Write style for baseScreen_divider, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_divider, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_thirdWidget
	ui->baseScreen_thirdWidget = lv_obj_create(ui->baseScreen_widgetWindow);
	lv_obj_set_pos(ui->baseScreen_thirdWidget, 0, 250);
	lv_obj_set_size(ui->baseScreen_thirdWidget, 400, 120);
	lv_obj_set_scrollbar_mode(ui->baseScreen_thirdWidget, LV_SCROLLBAR_MODE_OFF);

	//Write style for baseScreen_thirdWidget, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_thirdWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_thirdWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_thirdWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_thirdWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_thirdWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_thirdWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_thirdWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_thirdWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_widgetThreeBackground
	ui->baseScreen_widgetThreeBackground = lv_img_create(ui->baseScreen_thirdWidget);
	lv_obj_add_flag(ui->baseScreen_widgetThreeBackground, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_widgetThreeBackground, &_widgetbackground_alpha_400x120);
	lv_img_set_pivot(ui->baseScreen_widgetThreeBackground, 200,60);
	lv_img_set_angle(ui->baseScreen_widgetThreeBackground, 0);
	lv_obj_set_pos(ui->baseScreen_widgetThreeBackground, 0, 0);
	lv_obj_set_size(ui->baseScreen_widgetThreeBackground, 400, 120);

	//Write style for baseScreen_widgetThreeBackground, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_widgetThreeBackground, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_widgethreeUnit
	ui->baseScreen_widgethreeUnit = lv_label_create(ui->baseScreen_thirdWidget);
	lv_label_set_text(ui->baseScreen_widgethreeUnit, "km");
	lv_label_set_long_mode(ui->baseScreen_widgethreeUnit, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_widgethreeUnit, 40, 85);
	lv_obj_set_size(ui->baseScreen_widgethreeUnit, 320, 30);

	//Write style for baseScreen_widgethreeUnit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_widgethreeUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_widgethreeUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_widgethreeUnit, lv_color_hex(0xAEAEAE), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_widgethreeUnit, &lv_font_MIMXRT1170EVKB_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_widgethreeUnit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_widgethreeUnit, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_widgethreeUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_widgethreeUnit, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_widgethreeUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_widgethreeUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_widgethreeUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_widgethreeUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_widgethreeUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_widgethreeUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_widgetThreeValue
	ui->baseScreen_widgetThreeValue = lv_label_create(ui->baseScreen_thirdWidget);
	lv_label_set_text(ui->baseScreen_widgetThreeValue, "120");
	lv_label_set_long_mode(ui->baseScreen_widgetThreeValue, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_widgetThreeValue, 40, 35);
	lv_obj_set_size(ui->baseScreen_widgetThreeValue, 320, 50);

	//Write style for baseScreen_widgetThreeValue, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_widgetThreeValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_widgetThreeValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_widgetThreeValue, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_widgetThreeValue, &lv_font_MIMXRT1170EVKB_50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_widgetThreeValue, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_widgetThreeValue, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_widgetThreeValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_widgetThreeValue, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_widgetThreeValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_widgetThreeValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_widgetThreeValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_widgetThreeValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_widgetThreeValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_widgetThreeValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_widgetThreeLabel
	ui->baseScreen_widgetThreeLabel = lv_label_create(ui->baseScreen_thirdWidget);
	lv_label_set_text(ui->baseScreen_widgetThreeLabel, "Trip A");
	lv_label_set_long_mode(ui->baseScreen_widgetThreeLabel, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_widgetThreeLabel, 40, 5);
	lv_obj_set_size(ui->baseScreen_widgetThreeLabel, 320, 30);

	//Write style for baseScreen_widgetThreeLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_widgetThreeLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_widgetThreeLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_widgetThreeLabel, lv_color_hex(0x0093E7), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_widgetThreeLabel, &lv_font_MIMXRT1170EVKB_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_widgetThreeLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_widgetThreeLabel, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_widgetThreeLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_widgetThreeLabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_widgetThreeLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_widgetThreeLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_widgetThreeLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_widgetThreeLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_widgetThreeLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_widgetThreeLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_secondWidget
	ui->baseScreen_secondWidget = lv_obj_create(ui->baseScreen_widgetWindow);
	lv_obj_set_pos(ui->baseScreen_secondWidget, 0, 125);
	lv_obj_set_size(ui->baseScreen_secondWidget, 400, 120);
	lv_obj_set_scrollbar_mode(ui->baseScreen_secondWidget, LV_SCROLLBAR_MODE_OFF);

	//Write style for baseScreen_secondWidget, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_secondWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_secondWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_secondWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_secondWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_secondWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_secondWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_secondWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_secondWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_widgetTwoBackground
	ui->baseScreen_widgetTwoBackground = lv_img_create(ui->baseScreen_secondWidget);
	lv_obj_add_flag(ui->baseScreen_widgetTwoBackground, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_widgetTwoBackground, &_widgetbackground_alpha_400x120);
	lv_img_set_pivot(ui->baseScreen_widgetTwoBackground, 200,60);
	lv_img_set_angle(ui->baseScreen_widgetTwoBackground, 0);
	lv_obj_set_pos(ui->baseScreen_widgetTwoBackground, 0, 0);
	lv_obj_set_size(ui->baseScreen_widgetTwoBackground, 400, 120);

	//Write style for baseScreen_widgetTwoBackground, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_widgetTwoBackground, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_widgetTwoUnit
	ui->baseScreen_widgetTwoUnit = lv_label_create(ui->baseScreen_secondWidget);
	lv_label_set_text(ui->baseScreen_widgetTwoUnit, "km / charge");
	lv_label_set_long_mode(ui->baseScreen_widgetTwoUnit, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_widgetTwoUnit, 40, 85);
	lv_obj_set_size(ui->baseScreen_widgetTwoUnit, 320, 30);

	//Write style for baseScreen_widgetTwoUnit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_widgetTwoUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_widgetTwoUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_widgetTwoUnit, lv_color_hex(0xAEAEAE), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_widgetTwoUnit, &lv_font_MIMXRT1170EVKB_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_widgetTwoUnit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_widgetTwoUnit, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_widgetTwoUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_widgetTwoUnit, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_widgetTwoUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_widgetTwoUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_widgetTwoUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_widgetTwoUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_widgetTwoUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_widgetTwoUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_widgetTwoValue
	ui->baseScreen_widgetTwoValue = lv_label_create(ui->baseScreen_secondWidget);
	lv_label_set_text(ui->baseScreen_widgetTwoValue, "62");
	lv_label_set_long_mode(ui->baseScreen_widgetTwoValue, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_widgetTwoValue, 40, 35);
	lv_obj_set_size(ui->baseScreen_widgetTwoValue, 320, 50);

	//Write style for baseScreen_widgetTwoValue, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_widgetTwoValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_widgetTwoValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_widgetTwoValue, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_widgetTwoValue, &lv_font_MIMXRT1170EVKB_50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_widgetTwoValue, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_widgetTwoValue, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_widgetTwoValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_widgetTwoValue, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_widgetTwoValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_widgetTwoValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_widgetTwoValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_widgetTwoValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_widgetTwoValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_widgetTwoValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_widgetTwoLabel
	ui->baseScreen_widgetTwoLabel = lv_label_create(ui->baseScreen_secondWidget);
	lv_label_set_text(ui->baseScreen_widgetTwoLabel, "Avg fuel economy");
	lv_label_set_long_mode(ui->baseScreen_widgetTwoLabel, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_widgetTwoLabel, 40, 5);
	lv_obj_set_size(ui->baseScreen_widgetTwoLabel, 320, 30);

	//Write style for baseScreen_widgetTwoLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_widgetTwoLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_widgetTwoLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_widgetTwoLabel, lv_color_hex(0x0093E7), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_widgetTwoLabel, &lv_font_MIMXRT1170EVKB_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_widgetTwoLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_widgetTwoLabel, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_widgetTwoLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_widgetTwoLabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_widgetTwoLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_widgetTwoLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_widgetTwoLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_widgetTwoLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_widgetTwoLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_widgetTwoLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_front
	ui->baseScreen_front = lv_obj_create(ui->baseScreen_ringArea);
	lv_obj_set_pos(ui->baseScreen_front, 1038, 345);
	lv_obj_set_size(ui->baseScreen_front, 71, 71);
	lv_obj_set_scrollbar_mode(ui->baseScreen_front, LV_SCROLLBAR_MODE_OFF);

	//Write style for baseScreen_front, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_front, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->baseScreen_front, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->baseScreen_front, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->baseScreen_front, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_front, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_front, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_front, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_front, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_front, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_front, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_front, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_fb_car
	ui->baseScreen_fb_car = lv_img_create(ui->baseScreen_front);
	lv_obj_add_flag(ui->baseScreen_fb_car, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_fb_car, &_b_car_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_fb_car, 50,50);
	lv_img_set_angle(ui->baseScreen_fb_car, 0);
	lv_obj_set_pos(ui->baseScreen_fb_car, 0, 0);
	lv_obj_set_size(ui->baseScreen_fb_car, 71, 71);

	//Write style for baseScreen_fb_car, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_fb_car, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_fg_car
	ui->baseScreen_fg_car = lv_img_create(ui->baseScreen_front);
	lv_obj_add_flag(ui->baseScreen_fg_car, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_fg_car, &_g_car_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_fg_car, 50,50);
	lv_img_set_angle(ui->baseScreen_fg_car, 0);
	lv_obj_set_pos(ui->baseScreen_fg_car, 0, 0);
	lv_obj_set_size(ui->baseScreen_fg_car, 71, 71);

	//Write style for baseScreen_fg_car, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_fg_car, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_fr_car
	ui->baseScreen_fr_car = lv_img_create(ui->baseScreen_front);
	lv_obj_add_flag(ui->baseScreen_fr_car, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_fr_car, &_r_car_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_fr_car, 50,50);
	lv_img_set_angle(ui->baseScreen_fr_car, 0);
	lv_obj_set_pos(ui->baseScreen_fr_car, 0, 0);
	lv_obj_set_size(ui->baseScreen_fr_car, 71, 71);

	//Write style for baseScreen_fr_car, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_fr_car, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_fo_car
	ui->baseScreen_fo_car = lv_img_create(ui->baseScreen_front);
	lv_obj_add_flag(ui->baseScreen_fo_car, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_fo_car, &_o_car_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_fo_car, 50,50);
	lv_img_set_angle(ui->baseScreen_fo_car, 0);
	lv_obj_set_pos(ui->baseScreen_fo_car, 0, 0);
	lv_obj_set_size(ui->baseScreen_fo_car, 71, 71);

	//Write style for baseScreen_fo_car, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_fo_car, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_fb_auto
	ui->baseScreen_fb_auto = lv_img_create(ui->baseScreen_front);
	lv_obj_add_flag(ui->baseScreen_fb_auto, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_fb_auto, &_b_auto_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_fb_auto, 50,50);
	lv_img_set_angle(ui->baseScreen_fb_auto, 0);
	lv_obj_set_pos(ui->baseScreen_fb_auto, 0, 0);
	lv_obj_set_size(ui->baseScreen_fb_auto, 71, 71);

	//Write style for baseScreen_fb_auto, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_fb_auto, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_fg_auto
	ui->baseScreen_fg_auto = lv_img_create(ui->baseScreen_front);
	lv_obj_add_flag(ui->baseScreen_fg_auto, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_fg_auto, &_g_auto_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_fg_auto, 50,50);
	lv_img_set_angle(ui->baseScreen_fg_auto, 0);
	lv_obj_set_pos(ui->baseScreen_fg_auto, 0, 0);
	lv_obj_set_size(ui->baseScreen_fg_auto, 71, 71);

	//Write style for baseScreen_fg_auto, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_fg_auto, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_fr_auto
	ui->baseScreen_fr_auto = lv_img_create(ui->baseScreen_front);
	lv_obj_add_flag(ui->baseScreen_fr_auto, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_fr_auto, &_r_auto_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_fr_auto, 50,50);
	lv_img_set_angle(ui->baseScreen_fr_auto, 0);
	lv_obj_set_pos(ui->baseScreen_fr_auto, 0, 0);
	lv_obj_set_size(ui->baseScreen_fr_auto, 71, 71);

	//Write style for baseScreen_fr_auto, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_fr_auto, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_fo_auto
	ui->baseScreen_fo_auto = lv_img_create(ui->baseScreen_front);
	lv_obj_add_flag(ui->baseScreen_fo_auto, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_fo_auto, &_o_auto_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_fo_auto, 50,50);
	lv_img_set_angle(ui->baseScreen_fo_auto, 0);
	lv_obj_set_pos(ui->baseScreen_fo_auto, 0, 0);
	lv_obj_set_size(ui->baseScreen_fo_auto, 71, 71);

	//Write style for baseScreen_fo_auto, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_fo_auto, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_fr_bicycle
	ui->baseScreen_fr_bicycle = lv_img_create(ui->baseScreen_front);
	lv_obj_add_flag(ui->baseScreen_fr_bicycle, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_fr_bicycle, &_r_bicycle_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_fr_bicycle, 50,50);
	lv_img_set_angle(ui->baseScreen_fr_bicycle, 0);
	lv_obj_set_pos(ui->baseScreen_fr_bicycle, 0, 0);
	lv_obj_set_size(ui->baseScreen_fr_bicycle, 71, 71);

	//Write style for baseScreen_fr_bicycle, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_fr_bicycle, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_fg_bicycle
	ui->baseScreen_fg_bicycle = lv_img_create(ui->baseScreen_front);
	lv_obj_add_flag(ui->baseScreen_fg_bicycle, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_fg_bicycle, &_g_bicycle_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_fg_bicycle, 50,50);
	lv_img_set_angle(ui->baseScreen_fg_bicycle, 0);
	lv_obj_set_pos(ui->baseScreen_fg_bicycle, 0, 0);
	lv_obj_set_size(ui->baseScreen_fg_bicycle, 71, 71);

	//Write style for baseScreen_fg_bicycle, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_fg_bicycle, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_fb_bicycle
	ui->baseScreen_fb_bicycle = lv_img_create(ui->baseScreen_front);
	lv_obj_add_flag(ui->baseScreen_fb_bicycle, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_fb_bicycle, &_b_bicycle_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_fb_bicycle, 50,50);
	lv_img_set_angle(ui->baseScreen_fb_bicycle, 0);
	lv_obj_set_pos(ui->baseScreen_fb_bicycle, 0, 0);
	lv_obj_set_size(ui->baseScreen_fb_bicycle, 71, 71);

	//Write style for baseScreen_fb_bicycle, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_fb_bicycle, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_fo_bicycle
	ui->baseScreen_fo_bicycle = lv_img_create(ui->baseScreen_front);
	lv_obj_add_flag(ui->baseScreen_fo_bicycle, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_fo_bicycle, &_o_bicycle_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_fo_bicycle, 50,50);
	lv_img_set_angle(ui->baseScreen_fo_bicycle, 0);
	lv_obj_set_pos(ui->baseScreen_fo_bicycle, 0, 0);
	lv_obj_set_size(ui->baseScreen_fo_bicycle, 71, 71);

	//Write style for baseScreen_fo_bicycle, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_fo_bicycle, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_fr_bus
	ui->baseScreen_fr_bus = lv_img_create(ui->baseScreen_front);
	lv_obj_add_flag(ui->baseScreen_fr_bus, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_fr_bus, &_r_bus_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_fr_bus, 50,50);
	lv_img_set_angle(ui->baseScreen_fr_bus, 0);
	lv_obj_set_pos(ui->baseScreen_fr_bus, 0, 0);
	lv_obj_set_size(ui->baseScreen_fr_bus, 71, 71);

	//Write style for baseScreen_fr_bus, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_fr_bus, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_fb_bus
	ui->baseScreen_fb_bus = lv_img_create(ui->baseScreen_front);
	lv_obj_add_flag(ui->baseScreen_fb_bus, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_fb_bus, &_b_bus_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_fb_bus, 50,50);
	lv_img_set_angle(ui->baseScreen_fb_bus, 0);
	lv_obj_set_pos(ui->baseScreen_fb_bus, 0, 0);
	lv_obj_set_size(ui->baseScreen_fb_bus, 71, 71);

	//Write style for baseScreen_fb_bus, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_fb_bus, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_fg_bus
	ui->baseScreen_fg_bus = lv_img_create(ui->baseScreen_front);
	lv_obj_add_flag(ui->baseScreen_fg_bus, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_fg_bus, &_g_bus_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_fg_bus, 50,50);
	lv_img_set_angle(ui->baseScreen_fg_bus, 0);
	lv_obj_set_pos(ui->baseScreen_fg_bus, 0, 0);
	lv_obj_set_size(ui->baseScreen_fg_bus, 71, 71);

	//Write style for baseScreen_fg_bus, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_fg_bus, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_fo_bus
	ui->baseScreen_fo_bus = lv_img_create(ui->baseScreen_front);
	lv_obj_add_flag(ui->baseScreen_fo_bus, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_fo_bus, &_o_bus_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_fo_bus, 50,50);
	lv_img_set_angle(ui->baseScreen_fo_bus, 0);
	lv_obj_set_pos(ui->baseScreen_fo_bus, 0, 0);
	lv_obj_set_size(ui->baseScreen_fo_bus, 71, 71);

	//Write style for baseScreen_fo_bus, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_fo_bus, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_fr_motorcycle
	ui->baseScreen_fr_motorcycle = lv_img_create(ui->baseScreen_front);
	lv_obj_add_flag(ui->baseScreen_fr_motorcycle, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_fr_motorcycle, &_r_motorcye_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_fr_motorcycle, 50,50);
	lv_img_set_angle(ui->baseScreen_fr_motorcycle, 0);
	lv_obj_set_pos(ui->baseScreen_fr_motorcycle, 0, 0);
	lv_obj_set_size(ui->baseScreen_fr_motorcycle, 71, 71);

	//Write style for baseScreen_fr_motorcycle, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_fr_motorcycle, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_fb_motorcycle
	ui->baseScreen_fb_motorcycle = lv_img_create(ui->baseScreen_front);
	lv_obj_add_flag(ui->baseScreen_fb_motorcycle, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_fb_motorcycle, &_b_motorcycle_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_fb_motorcycle, 50,50);
	lv_img_set_angle(ui->baseScreen_fb_motorcycle, 0);
	lv_obj_set_pos(ui->baseScreen_fb_motorcycle, 0, 0);
	lv_obj_set_size(ui->baseScreen_fb_motorcycle, 71, 71);

	//Write style for baseScreen_fb_motorcycle, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_fb_motorcycle, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_fg_motorcycle
	ui->baseScreen_fg_motorcycle = lv_img_create(ui->baseScreen_front);
	lv_obj_add_flag(ui->baseScreen_fg_motorcycle, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_fg_motorcycle, &_g_motorcycle_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_fg_motorcycle, 50,50);
	lv_img_set_angle(ui->baseScreen_fg_motorcycle, 0);
	lv_obj_set_pos(ui->baseScreen_fg_motorcycle, 0, 0);
	lv_obj_set_size(ui->baseScreen_fg_motorcycle, 71, 71);

	//Write style for baseScreen_fg_motorcycle, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_fg_motorcycle, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_fo_motorcycle
	ui->baseScreen_fo_motorcycle = lv_img_create(ui->baseScreen_front);
	lv_obj_add_flag(ui->baseScreen_fo_motorcycle, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_fo_motorcycle, &_o_motorcycle_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_fo_motorcycle, 50,50);
	lv_img_set_angle(ui->baseScreen_fo_motorcycle, 0);
	lv_obj_set_pos(ui->baseScreen_fo_motorcycle, 0, 0);
	lv_obj_set_size(ui->baseScreen_fo_motorcycle, 71, 71);

	//Write style for baseScreen_fo_motorcycle, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_fo_motorcycle, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_fr_person
	ui->baseScreen_fr_person = lv_img_create(ui->baseScreen_front);
	lv_obj_add_flag(ui->baseScreen_fr_person, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_fr_person, &_r_person_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_fr_person, 50,50);
	lv_img_set_angle(ui->baseScreen_fr_person, 0);
	lv_obj_set_pos(ui->baseScreen_fr_person, 0, 0);
	lv_obj_set_size(ui->baseScreen_fr_person, 71, 71);

	//Write style for baseScreen_fr_person, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_fr_person, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_fb_person
	ui->baseScreen_fb_person = lv_img_create(ui->baseScreen_front);
	lv_obj_add_flag(ui->baseScreen_fb_person, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_fb_person, &_b_person_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_fb_person, 50,50);
	lv_img_set_angle(ui->baseScreen_fb_person, 0);
	lv_obj_set_pos(ui->baseScreen_fb_person, 0, 0);
	lv_obj_set_size(ui->baseScreen_fb_person, 71, 71);

	//Write style for baseScreen_fb_person, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_fb_person, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_fg_person
	ui->baseScreen_fg_person = lv_img_create(ui->baseScreen_front);
	lv_obj_add_flag(ui->baseScreen_fg_person, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_fg_person, &_g_person_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_fg_person, 50,50);
	lv_img_set_angle(ui->baseScreen_fg_person, 0);
	lv_obj_set_pos(ui->baseScreen_fg_person, 0, 0);
	lv_obj_set_size(ui->baseScreen_fg_person, 71, 71);

	//Write style for baseScreen_fg_person, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_fg_person, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_fo_person
	ui->baseScreen_fo_person = lv_img_create(ui->baseScreen_front);
	lv_obj_add_flag(ui->baseScreen_fo_person, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_fo_person, &_o_person_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_fo_person, 50,50);
	lv_img_set_angle(ui->baseScreen_fo_person, 0);
	lv_obj_set_pos(ui->baseScreen_fo_person, 0, 0);
	lv_obj_set_size(ui->baseScreen_fo_person, 71, 71);

	//Write style for baseScreen_fo_person, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_fo_person, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_fr_truck
	ui->baseScreen_fr_truck = lv_img_create(ui->baseScreen_front);
	lv_obj_add_flag(ui->baseScreen_fr_truck, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_fr_truck, &_redtruck_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_fr_truck, 50,50);
	lv_img_set_angle(ui->baseScreen_fr_truck, 0);
	lv_obj_set_pos(ui->baseScreen_fr_truck, 0, 0);
	lv_obj_set_size(ui->baseScreen_fr_truck, 71, 71);

	//Write style for baseScreen_fr_truck, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_fr_truck, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_fb_truck
	ui->baseScreen_fb_truck = lv_img_create(ui->baseScreen_front);
	lv_obj_add_flag(ui->baseScreen_fb_truck, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_fb_truck, &_b_truck_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_fb_truck, 50,50);
	lv_img_set_angle(ui->baseScreen_fb_truck, 0);
	lv_obj_set_pos(ui->baseScreen_fb_truck, 0, 0);
	lv_obj_set_size(ui->baseScreen_fb_truck, 71, 71);

	//Write style for baseScreen_fb_truck, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_fb_truck, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_fg_truck
	ui->baseScreen_fg_truck = lv_img_create(ui->baseScreen_front);
	lv_obj_add_flag(ui->baseScreen_fg_truck, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_fg_truck, &_g_truck_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_fg_truck, 50,50);
	lv_img_set_angle(ui->baseScreen_fg_truck, 0);
	lv_obj_set_pos(ui->baseScreen_fg_truck, 0, 0);
	lv_obj_set_size(ui->baseScreen_fg_truck, 71, 71);

	//Write style for baseScreen_fg_truck, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_fg_truck, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_fo_truck
	ui->baseScreen_fo_truck = lv_img_create(ui->baseScreen_front);
	lv_obj_add_flag(ui->baseScreen_fo_truck, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_fo_truck, &_o_truck_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_fo_truck, 50,50);
	lv_img_set_angle(ui->baseScreen_fo_truck, 0);
	lv_obj_set_pos(ui->baseScreen_fo_truck, 0, 0);
	lv_obj_set_size(ui->baseScreen_fo_truck, 71, 71);

	//Write style for baseScreen_fo_truck, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_fo_truck, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_fr_unknown
	ui->baseScreen_fr_unknown = lv_img_create(ui->baseScreen_front);
	lv_obj_add_flag(ui->baseScreen_fr_unknown, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_fr_unknown, &_r_unknown_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_fr_unknown, 50,50);
	lv_img_set_angle(ui->baseScreen_fr_unknown, 0);
	lv_obj_set_pos(ui->baseScreen_fr_unknown, 0, 0);
	lv_obj_set_size(ui->baseScreen_fr_unknown, 71, 71);

	//Write style for baseScreen_fr_unknown, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_fr_unknown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_fb_unknown
	ui->baseScreen_fb_unknown = lv_img_create(ui->baseScreen_front);
	lv_obj_add_flag(ui->baseScreen_fb_unknown, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_fb_unknown, &_b_unknown_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_fb_unknown, 50,50);
	lv_img_set_angle(ui->baseScreen_fb_unknown, 0);
	lv_obj_set_pos(ui->baseScreen_fb_unknown, 0, 0);
	lv_obj_set_size(ui->baseScreen_fb_unknown, 71, 71);

	//Write style for baseScreen_fb_unknown, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_fb_unknown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_fg_unknown
	ui->baseScreen_fg_unknown = lv_img_create(ui->baseScreen_front);
	lv_obj_add_flag(ui->baseScreen_fg_unknown, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_fg_unknown, &_g_unknown_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_fg_unknown, 50,50);
	lv_img_set_angle(ui->baseScreen_fg_unknown, 0);
	lv_obj_set_pos(ui->baseScreen_fg_unknown, 0, 0);
	lv_obj_set_size(ui->baseScreen_fg_unknown, 71, 71);

	//Write style for baseScreen_fg_unknown, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_fg_unknown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_fo_unknown
	ui->baseScreen_fo_unknown = lv_img_create(ui->baseScreen_front);
	lv_obj_add_flag(ui->baseScreen_fo_unknown, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_fo_unknown, &_o_unknown_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_fo_unknown, 50,50);
	lv_img_set_angle(ui->baseScreen_fo_unknown, 0);
	lv_obj_set_pos(ui->baseScreen_fo_unknown, 0, 0);
	lv_obj_set_size(ui->baseScreen_fo_unknown, 71, 71);

	//Write style for baseScreen_fo_unknown, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_fo_unknown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_cameraData
	ui->baseScreen_cameraData = lv_obj_create(ui->baseScreen_ringArea);
	lv_obj_set_pos(ui->baseScreen_cameraData, 931, 316);
	lv_obj_set_size(ui->baseScreen_cameraData, 300, 353);
	lv_obj_set_scrollbar_mode(ui->baseScreen_cameraData, LV_SCROLLBAR_MODE_OFF);

	//Write style for baseScreen_cameraData, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_cameraData, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->baseScreen_cameraData, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->baseScreen_cameraData, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->baseScreen_cameraData, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_cameraData, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_cameraData, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_cameraData, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_cameraData, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_cameraData, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_cameraData, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_cameraData, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_cameraBackground
	ui->baseScreen_cameraBackground = lv_img_create(ui->baseScreen_cameraData);
	lv_obj_add_flag(ui->baseScreen_cameraBackground, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_cameraBackground, &_background_alpha_300x300);
	lv_img_set_pivot(ui->baseScreen_cameraBackground, 50,50);
	lv_img_set_angle(ui->baseScreen_cameraBackground, 0);
	lv_obj_set_pos(ui->baseScreen_cameraBackground, -8, -1);
	lv_obj_set_size(ui->baseScreen_cameraBackground, 300, 300);

	//Write style for baseScreen_cameraBackground, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_cameraBackground, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_vehicle1_container
	ui->baseScreen_vehicle1_container = lv_obj_create(ui->baseScreen_cameraData);
	lv_obj_set_pos(ui->baseScreen_vehicle1_container, 240, 16);
	lv_obj_set_size(ui->baseScreen_vehicle1_container, 56, 93);
	lv_obj_set_scrollbar_mode(ui->baseScreen_vehicle1_container, LV_SCROLLBAR_MODE_OFF);

	//Write style for baseScreen_vehicle1_container, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_vehicle1_container, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->baseScreen_vehicle1_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->baseScreen_vehicle1_container, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->baseScreen_vehicle1_container, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_vehicle1_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_vehicle1_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_vehicle1_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_vehicle1_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_vehicle1_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_vehicle1_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_vehicle1_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_vehicle1_distUnit
	ui->baseScreen_vehicle1_distUnit = lv_label_create(ui->baseScreen_vehicle1_container);
	lv_label_set_text(ui->baseScreen_vehicle1_distUnit, "meters");
	lv_label_set_long_mode(ui->baseScreen_vehicle1_distUnit, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_vehicle1_distUnit, 1, 58);
	lv_obj_set_size(ui->baseScreen_vehicle1_distUnit, 56, 26);

	//Write style for baseScreen_vehicle1_distUnit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_vehicle1_distUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_vehicle1_distUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_vehicle1_distUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_vehicle1_distUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_vehicle1_distUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_vehicle1_distUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_vehicle1_distUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_vehicle1_distUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_vehicle1_distUnit, lv_color_hex(0xAEAEAE), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_vehicle1_distUnit, &lv_font_MIMXRT1170EVKB_15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_vehicle1_distUnit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_vehicle1_distUnit, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_vehicle1_distUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_vehicle1_distUnit, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_vehicle1_dist
	ui->baseScreen_vehicle1_dist = lv_label_create(ui->baseScreen_vehicle1_container);
	lv_label_set_text(ui->baseScreen_vehicle1_dist, "10");
	lv_label_set_long_mode(ui->baseScreen_vehicle1_dist, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_vehicle1_dist, 6, 17);
	lv_obj_set_size(ui->baseScreen_vehicle1_dist, 42, 66);

	//Write style for baseScreen_vehicle1_dist, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_vehicle1_dist, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_vehicle1_dist, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_vehicle1_dist, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_vehicle1_dist, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_vehicle1_dist, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_vehicle1_dist, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_vehicle1_dist, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_vehicle1_dist, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_vehicle1_dist, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_vehicle1_dist, &lv_font_MIMXRT1170EVKB_45, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_vehicle1_dist, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_vehicle1_dist, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_vehicle1_dist, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_vehicle1_dist, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_vehicle1_in
	ui->baseScreen_vehicle1_in = lv_label_create(ui->baseScreen_vehicle1_container);
	lv_label_set_text(ui->baseScreen_vehicle1_in, "in");
	lv_label_set_long_mode(ui->baseScreen_vehicle1_in, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_vehicle1_in, 17, 4);
	lv_obj_set_size(ui->baseScreen_vehicle1_in, 15, 26);

	//Write style for baseScreen_vehicle1_in, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_vehicle1_in, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_vehicle1_in, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_vehicle1_in, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_vehicle1_in, &lv_font_MIMXRT1170EVKB_15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_vehicle1_in, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_vehicle1_in, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_vehicle1_in, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_vehicle1_in, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_vehicle1_in, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_vehicle1_in, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_vehicle1_in, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_vehicle1_in, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_vehicle1_in, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_vehicle1_in, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_vehicle2_container
	ui->baseScreen_vehicle2_container = lv_obj_create(ui->baseScreen_cameraData);
	lv_obj_set_pos(ui->baseScreen_vehicle2_container, 240, 217);
	lv_obj_set_size(ui->baseScreen_vehicle2_container, 56, 93);
	lv_obj_set_scrollbar_mode(ui->baseScreen_vehicle2_container, LV_SCROLLBAR_MODE_OFF);

	//Write style for baseScreen_vehicle2_container, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_vehicle2_container, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->baseScreen_vehicle2_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->baseScreen_vehicle2_container, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->baseScreen_vehicle2_container, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_vehicle2_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_vehicle2_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_vehicle2_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_vehicle2_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_vehicle2_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_vehicle2_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_vehicle2_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_vehicle2_distUnit
	ui->baseScreen_vehicle2_distUnit = lv_label_create(ui->baseScreen_vehicle2_container);
	lv_label_set_text(ui->baseScreen_vehicle2_distUnit, "meters\n");
	lv_label_set_long_mode(ui->baseScreen_vehicle2_distUnit, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_vehicle2_distUnit, -1, 60);
	lv_obj_set_size(ui->baseScreen_vehicle2_distUnit, 56, 26);

	//Write style for baseScreen_vehicle2_distUnit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_vehicle2_distUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_vehicle2_distUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_vehicle2_distUnit, lv_color_hex(0xAEAEAE), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_vehicle2_distUnit, &lv_font_MIMXRT1170EVKB_15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_vehicle2_distUnit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_vehicle2_distUnit, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_vehicle2_distUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_vehicle2_distUnit, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_vehicle2_distUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_vehicle2_distUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_vehicle2_distUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_vehicle2_distUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_vehicle2_distUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_vehicle2_distUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_vehicle2_dist
	ui->baseScreen_vehicle2_dist = lv_label_create(ui->baseScreen_vehicle2_container);
	lv_label_set_text(ui->baseScreen_vehicle2_dist, "10");
	lv_label_set_long_mode(ui->baseScreen_vehicle2_dist, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_vehicle2_dist, 6, 17);
	lv_obj_set_size(ui->baseScreen_vehicle2_dist, 42, 66);

	//Write style for baseScreen_vehicle2_dist, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_vehicle2_dist, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_vehicle2_dist, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_vehicle2_dist, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_vehicle2_dist, &lv_font_MIMXRT1170EVKB_45, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_vehicle2_dist, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_vehicle2_dist, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_vehicle2_dist, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_vehicle2_dist, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_vehicle2_dist, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_vehicle2_dist, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_vehicle2_dist, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_vehicle2_dist, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_vehicle2_dist, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_vehicle2_dist, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_vehicle2_in
	ui->baseScreen_vehicle2_in = lv_label_create(ui->baseScreen_vehicle2_container);
	lv_label_set_text(ui->baseScreen_vehicle2_in, "in");
	lv_label_set_long_mode(ui->baseScreen_vehicle2_in, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_vehicle2_in, 20, 2);
	lv_obj_set_size(ui->baseScreen_vehicle2_in, 16, 22);

	//Write style for baseScreen_vehicle2_in, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_vehicle2_in, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_vehicle2_in, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_vehicle2_in, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_vehicle2_in, &lv_font_MIMXRT1170EVKB_15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_vehicle2_in, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_vehicle2_in, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_vehicle2_in, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_vehicle2_in, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_vehicle2_in, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_vehicle2_in, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_vehicle2_in, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_vehicle2_in, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_vehicle2_in, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_vehicle2_in, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_CameraName
	ui->baseScreen_CameraName = lv_label_create(ui->baseScreen_cameraData);
	lv_label_set_text(ui->baseScreen_CameraName, "Camera\n");
	lv_label_set_long_mode(ui->baseScreen_CameraName, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_CameraName, -7, 294);
	lv_obj_set_size(ui->baseScreen_CameraName, 300, 36);

	//Write style for baseScreen_CameraName, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_CameraName, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_CameraName, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_CameraName, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_CameraName, &lv_font_montserratMedium_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_CameraName, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_CameraName, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_CameraName, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_CameraName, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_CameraName, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_CameraName, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_CameraName, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_CameraName, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_CameraName, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_CameraName, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_rear
	ui->baseScreen_rear = lv_obj_create(ui->baseScreen_cameraData);
	lv_obj_set_pos(ui->baseScreen_rear, 103, 201);
	lv_obj_set_size(ui->baseScreen_rear, 71, 71);
	lv_obj_set_scrollbar_mode(ui->baseScreen_rear, LV_SCROLLBAR_MODE_OFF);

	//Write style for baseScreen_rear, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_rear, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->baseScreen_rear, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->baseScreen_rear, lv_color_hex(0xff0027), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->baseScreen_rear, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_rear, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_rear, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_rear, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_rear, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_rear, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_rear, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_rear, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_ro_unknown
	ui->baseScreen_ro_unknown = lv_img_create(ui->baseScreen_rear);
	lv_obj_add_flag(ui->baseScreen_ro_unknown, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_ro_unknown, &_o_unknown_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_ro_unknown, 50,50);
	lv_img_set_angle(ui->baseScreen_ro_unknown, 0);
	lv_obj_set_pos(ui->baseScreen_ro_unknown, 0, 0);
	lv_obj_set_size(ui->baseScreen_ro_unknown, 71, 71);

	//Write style for baseScreen_ro_unknown, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_ro_unknown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_rb_unknown
	ui->baseScreen_rb_unknown = lv_img_create(ui->baseScreen_rear);
	lv_obj_add_flag(ui->baseScreen_rb_unknown, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_rb_unknown, &_b_unknown_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_rb_unknown, 50,50);
	lv_img_set_angle(ui->baseScreen_rb_unknown, 0);
	lv_obj_set_pos(ui->baseScreen_rb_unknown, 0, 0);
	lv_obj_set_size(ui->baseScreen_rb_unknown, 71, 71);

	//Write style for baseScreen_rb_unknown, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_rb_unknown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_rr_unknown
	ui->baseScreen_rr_unknown = lv_img_create(ui->baseScreen_rear);
	lv_obj_add_flag(ui->baseScreen_rr_unknown, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_rr_unknown, &_redunknow_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_rr_unknown, 50,50);
	lv_img_set_angle(ui->baseScreen_rr_unknown, 0);
	lv_obj_set_pos(ui->baseScreen_rr_unknown, 0, 0);
	lv_obj_set_size(ui->baseScreen_rr_unknown, 71, 71);

	//Write style for baseScreen_rr_unknown, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_rr_unknown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_rg_unknown
	ui->baseScreen_rg_unknown = lv_img_create(ui->baseScreen_rear);
	lv_obj_add_flag(ui->baseScreen_rg_unknown, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_rg_unknown, &_g_unknown_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_rg_unknown, 50,50);
	lv_img_set_angle(ui->baseScreen_rg_unknown, 0);
	lv_obj_set_pos(ui->baseScreen_rg_unknown, 0, 0);
	lv_obj_set_size(ui->baseScreen_rg_unknown, 71, 71);

	//Write style for baseScreen_rg_unknown, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_rg_unknown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_ro_truck
	ui->baseScreen_ro_truck = lv_img_create(ui->baseScreen_rear);
	lv_obj_add_flag(ui->baseScreen_ro_truck, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_ro_truck, &_o_truck_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_ro_truck, 50,50);
	lv_img_set_angle(ui->baseScreen_ro_truck, 0);
	lv_obj_set_pos(ui->baseScreen_ro_truck, 0, 0);
	lv_obj_set_size(ui->baseScreen_ro_truck, 71, 71);

	//Write style for baseScreen_ro_truck, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_ro_truck, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_rg_truck
	ui->baseScreen_rg_truck = lv_img_create(ui->baseScreen_rear);
	lv_obj_add_flag(ui->baseScreen_rg_truck, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_rg_truck, &_g_truck_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_rg_truck, 50,50);
	lv_img_set_angle(ui->baseScreen_rg_truck, 0);
	lv_obj_set_pos(ui->baseScreen_rg_truck, 0, 0);
	lv_obj_set_size(ui->baseScreen_rg_truck, 71, 71);

	//Write style for baseScreen_rg_truck, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_rg_truck, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_rb_truck
	ui->baseScreen_rb_truck = lv_img_create(ui->baseScreen_rear);
	lv_obj_add_flag(ui->baseScreen_rb_truck, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_rb_truck, &_b_truck_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_rb_truck, 50,50);
	lv_img_set_angle(ui->baseScreen_rb_truck, 0);
	lv_obj_set_pos(ui->baseScreen_rb_truck, 0, 0);
	lv_obj_set_size(ui->baseScreen_rb_truck, 71, 71);

	//Write style for baseScreen_rb_truck, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_rb_truck, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_rr_truck
	ui->baseScreen_rr_truck = lv_img_create(ui->baseScreen_rear);
	lv_obj_add_flag(ui->baseScreen_rr_truck, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_rr_truck, &_redtruck_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_rr_truck, 50,50);
	lv_img_set_angle(ui->baseScreen_rr_truck, 0);
	lv_obj_set_pos(ui->baseScreen_rr_truck, 0, 0);
	lv_obj_set_size(ui->baseScreen_rr_truck, 71, 71);

	//Write style for baseScreen_rr_truck, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_rr_truck, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_ro_person
	ui->baseScreen_ro_person = lv_img_create(ui->baseScreen_rear);
	lv_obj_add_flag(ui->baseScreen_ro_person, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_ro_person, &_o_person_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_ro_person, 50,50);
	lv_img_set_angle(ui->baseScreen_ro_person, 0);
	lv_obj_set_pos(ui->baseScreen_ro_person, 0, 0);
	lv_obj_set_size(ui->baseScreen_ro_person, 71, 71);

	//Write style for baseScreen_ro_person, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_ro_person, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_rg_person
	ui->baseScreen_rg_person = lv_img_create(ui->baseScreen_rear);
	lv_obj_add_flag(ui->baseScreen_rg_person, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_rg_person, &_g_person_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_rg_person, 50,50);
	lv_img_set_angle(ui->baseScreen_rg_person, 0);
	lv_obj_set_pos(ui->baseScreen_rg_person, 0, 0);
	lv_obj_set_size(ui->baseScreen_rg_person, 71, 71);

	//Write style for baseScreen_rg_person, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_rg_person, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_rb_person
	ui->baseScreen_rb_person = lv_img_create(ui->baseScreen_rear);
	lv_obj_add_flag(ui->baseScreen_rb_person, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_rb_person, &_b_person_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_rb_person, 50,50);
	lv_img_set_angle(ui->baseScreen_rb_person, 0);
	lv_obj_set_pos(ui->baseScreen_rb_person, 0, 0);
	lv_obj_set_size(ui->baseScreen_rb_person, 71, 71);

	//Write style for baseScreen_rb_person, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_rb_person, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_rr_person
	ui->baseScreen_rr_person = lv_img_create(ui->baseScreen_rear);
	lv_obj_add_flag(ui->baseScreen_rr_person, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_rr_person, &_r_person_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_rr_person, 50,50);
	lv_img_set_angle(ui->baseScreen_rr_person, 0);
	lv_obj_set_pos(ui->baseScreen_rr_person, 0, 0);
	lv_obj_set_size(ui->baseScreen_rr_person, 71, 71);

	//Write style for baseScreen_rr_person, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_rr_person, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_ro_motorcycle
	ui->baseScreen_ro_motorcycle = lv_img_create(ui->baseScreen_rear);
	lv_obj_add_flag(ui->baseScreen_ro_motorcycle, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_ro_motorcycle, &_o_motorcycle_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_ro_motorcycle, 50,50);
	lv_img_set_angle(ui->baseScreen_ro_motorcycle, 0);
	lv_obj_set_pos(ui->baseScreen_ro_motorcycle, 0, 0);
	lv_obj_set_size(ui->baseScreen_ro_motorcycle, 71, 71);

	//Write style for baseScreen_ro_motorcycle, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_ro_motorcycle, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_rg_motorcycle
	ui->baseScreen_rg_motorcycle = lv_img_create(ui->baseScreen_rear);
	lv_obj_add_flag(ui->baseScreen_rg_motorcycle, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_rg_motorcycle, &_g_motorcycle_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_rg_motorcycle, 50,50);
	lv_img_set_angle(ui->baseScreen_rg_motorcycle, 0);
	lv_obj_set_pos(ui->baseScreen_rg_motorcycle, 0, 0);
	lv_obj_set_size(ui->baseScreen_rg_motorcycle, 71, 71);

	//Write style for baseScreen_rg_motorcycle, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_rg_motorcycle, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_rb_motorcycle
	ui->baseScreen_rb_motorcycle = lv_img_create(ui->baseScreen_rear);
	lv_obj_add_flag(ui->baseScreen_rb_motorcycle, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_rb_motorcycle, &_b_motorcycle_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_rb_motorcycle, 50,50);
	lv_img_set_angle(ui->baseScreen_rb_motorcycle, 0);
	lv_obj_set_pos(ui->baseScreen_rb_motorcycle, 0, 0);
	lv_obj_set_size(ui->baseScreen_rb_motorcycle, 71, 71);

	//Write style for baseScreen_rb_motorcycle, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_rb_motorcycle, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_rr_motorcycle
	ui->baseScreen_rr_motorcycle = lv_img_create(ui->baseScreen_rear);
	lv_obj_add_flag(ui->baseScreen_rr_motorcycle, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_rr_motorcycle, &_r_motorcye_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_rr_motorcycle, 50,50);
	lv_img_set_angle(ui->baseScreen_rr_motorcycle, 0);
	lv_obj_set_pos(ui->baseScreen_rr_motorcycle, 0, 0);
	lv_obj_set_size(ui->baseScreen_rr_motorcycle, 71, 71);

	//Write style for baseScreen_rr_motorcycle, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_rr_motorcycle, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_ro_car
	ui->baseScreen_ro_car = lv_img_create(ui->baseScreen_rear);
	lv_obj_add_flag(ui->baseScreen_ro_car, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_ro_car, &_o_car_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_ro_car, 50,50);
	lv_img_set_angle(ui->baseScreen_ro_car, 0);
	lv_obj_set_pos(ui->baseScreen_ro_car, 0, 0);
	lv_obj_set_size(ui->baseScreen_ro_car, 71, 71);

	//Write style for baseScreen_ro_car, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_ro_car, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_rg_car
	ui->baseScreen_rg_car = lv_img_create(ui->baseScreen_rear);
	lv_obj_add_flag(ui->baseScreen_rg_car, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_rg_car, &_g_car_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_rg_car, 50,50);
	lv_img_set_angle(ui->baseScreen_rg_car, 0);
	lv_obj_set_pos(ui->baseScreen_rg_car, 0, 0);
	lv_obj_set_size(ui->baseScreen_rg_car, 71, 71);

	//Write style for baseScreen_rg_car, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_rg_car, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_rb_car
	ui->baseScreen_rb_car = lv_img_create(ui->baseScreen_rear);
	lv_obj_add_flag(ui->baseScreen_rb_car, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_rb_car, &_b_car_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_rb_car, 50,50);
	lv_img_set_angle(ui->baseScreen_rb_car, 0);
	lv_obj_set_pos(ui->baseScreen_rb_car, 0, 0);
	lv_obj_set_size(ui->baseScreen_rb_car, 71, 71);

	//Write style for baseScreen_rb_car, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_rb_car, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_rr_car
	ui->baseScreen_rr_car = lv_img_create(ui->baseScreen_rear);
	lv_obj_add_flag(ui->baseScreen_rr_car, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_rr_car, &_r_car_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_rr_car, 50,50);
	lv_img_set_angle(ui->baseScreen_rr_car, 0);
	lv_obj_set_pos(ui->baseScreen_rr_car, 0, 0);
	lv_obj_set_size(ui->baseScreen_rr_car, 71, 71);

	//Write style for baseScreen_rr_car, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_rr_car, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_ro_bus
	ui->baseScreen_ro_bus = lv_img_create(ui->baseScreen_rear);
	lv_obj_add_flag(ui->baseScreen_ro_bus, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_ro_bus, &_o_bus_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_ro_bus, 50,50);
	lv_img_set_angle(ui->baseScreen_ro_bus, 0);
	lv_obj_set_pos(ui->baseScreen_ro_bus, 0, 0);
	lv_obj_set_size(ui->baseScreen_ro_bus, 71, 71);

	//Write style for baseScreen_ro_bus, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_ro_bus, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_rg_bus
	ui->baseScreen_rg_bus = lv_img_create(ui->baseScreen_rear);
	lv_obj_add_flag(ui->baseScreen_rg_bus, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_rg_bus, &_g_bus_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_rg_bus, 50,50);
	lv_img_set_angle(ui->baseScreen_rg_bus, 0);
	lv_obj_set_pos(ui->baseScreen_rg_bus, 0, 0);
	lv_obj_set_size(ui->baseScreen_rg_bus, 71, 71);

	//Write style for baseScreen_rg_bus, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_rg_bus, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_rb_bus
	ui->baseScreen_rb_bus = lv_img_create(ui->baseScreen_rear);
	lv_obj_add_flag(ui->baseScreen_rb_bus, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_rb_bus, &_b_bus_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_rb_bus, 50,50);
	lv_img_set_angle(ui->baseScreen_rb_bus, 0);
	lv_obj_set_pos(ui->baseScreen_rb_bus, 0, 0);
	lv_obj_set_size(ui->baseScreen_rb_bus, 71, 71);

	//Write style for baseScreen_rb_bus, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_rb_bus, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_rr_bus
	ui->baseScreen_rr_bus = lv_img_create(ui->baseScreen_rear);
	lv_obj_add_flag(ui->baseScreen_rr_bus, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_rr_bus, &_r_bus_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_rr_bus, 50,50);
	lv_img_set_angle(ui->baseScreen_rr_bus, 0);
	lv_obj_set_pos(ui->baseScreen_rr_bus, 0, 0);
	lv_obj_set_size(ui->baseScreen_rr_bus, 71, 71);

	//Write style for baseScreen_rr_bus, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_rr_bus, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_ro_bicycle
	ui->baseScreen_ro_bicycle = lv_img_create(ui->baseScreen_rear);
	lv_obj_add_flag(ui->baseScreen_ro_bicycle, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_ro_bicycle, &_o_bicycle_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_ro_bicycle, 50,50);
	lv_img_set_angle(ui->baseScreen_ro_bicycle, 0);
	lv_obj_set_pos(ui->baseScreen_ro_bicycle, 0, 0);
	lv_obj_set_size(ui->baseScreen_ro_bicycle, 71, 71);

	//Write style for baseScreen_ro_bicycle, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_ro_bicycle, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_rg_bicycle
	ui->baseScreen_rg_bicycle = lv_img_create(ui->baseScreen_rear);
	lv_obj_add_flag(ui->baseScreen_rg_bicycle, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_rg_bicycle, &_g_bicycle_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_rg_bicycle, 50,50);
	lv_img_set_angle(ui->baseScreen_rg_bicycle, 0);
	lv_obj_set_pos(ui->baseScreen_rg_bicycle, 0, 0);
	lv_obj_set_size(ui->baseScreen_rg_bicycle, 71, 71);

	//Write style for baseScreen_rg_bicycle, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_rg_bicycle, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_rb_bicycle
	ui->baseScreen_rb_bicycle = lv_img_create(ui->baseScreen_rear);
	lv_obj_add_flag(ui->baseScreen_rb_bicycle, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_rb_bicycle, &_b_bicycle_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_rb_bicycle, 50,50);
	lv_img_set_angle(ui->baseScreen_rb_bicycle, 0);
	lv_obj_set_pos(ui->baseScreen_rb_bicycle, 0, 0);
	lv_obj_set_size(ui->baseScreen_rb_bicycle, 71, 71);

	//Write style for baseScreen_rb_bicycle, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_rb_bicycle, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_rr_bicycle
	ui->baseScreen_rr_bicycle = lv_img_create(ui->baseScreen_rear);
	lv_obj_add_flag(ui->baseScreen_rr_bicycle, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_rr_bicycle, &_redcycle_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_rr_bicycle, 50,50);
	lv_img_set_angle(ui->baseScreen_rr_bicycle, 0);
	lv_obj_set_pos(ui->baseScreen_rr_bicycle, 0, 0);
	lv_obj_set_size(ui->baseScreen_rr_bicycle, 71, 71);

	//Write style for baseScreen_rr_bicycle, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_rr_bicycle, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_ro_auto
	ui->baseScreen_ro_auto = lv_img_create(ui->baseScreen_rear);
	lv_obj_add_flag(ui->baseScreen_ro_auto, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_ro_auto, &_o_auto_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_ro_auto, 50,50);
	lv_img_set_angle(ui->baseScreen_ro_auto, 0);
	lv_obj_set_pos(ui->baseScreen_ro_auto, 0, 0);
	lv_obj_set_size(ui->baseScreen_ro_auto, 71, 71);

	//Write style for baseScreen_ro_auto, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_ro_auto, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_rg_auto
	ui->baseScreen_rg_auto = lv_img_create(ui->baseScreen_rear);
	lv_obj_add_flag(ui->baseScreen_rg_auto, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_rg_auto, &_g_auto_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_rg_auto, 50,50);
	lv_img_set_angle(ui->baseScreen_rg_auto, 0);
	lv_obj_set_pos(ui->baseScreen_rg_auto, 0, 0);
	lv_obj_set_size(ui->baseScreen_rg_auto, 71, 71);

	//Write style for baseScreen_rg_auto, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_rg_auto, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_rr_auto
	ui->baseScreen_rr_auto = lv_img_create(ui->baseScreen_rear);
	lv_obj_add_flag(ui->baseScreen_rr_auto, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_rr_auto, &_redauto_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_rr_auto, 50,50);
	lv_img_set_angle(ui->baseScreen_rr_auto, 0);
	lv_obj_set_pos(ui->baseScreen_rr_auto, 0, 0);
	lv_obj_set_size(ui->baseScreen_rr_auto, 71, 71);

	//Write style for baseScreen_rr_auto, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_rr_auto, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_rb_auto
	ui->baseScreen_rb_auto = lv_img_create(ui->baseScreen_rear);
	lv_obj_add_flag(ui->baseScreen_rb_auto, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_rb_auto, &_b_auto_alpha_71x71);
	lv_img_set_pivot(ui->baseScreen_rb_auto, 50,50);
	lv_img_set_angle(ui->baseScreen_rb_auto, 0);
	lv_obj_set_pos(ui->baseScreen_rb_auto, 0, 0);
	lv_obj_set_size(ui->baseScreen_rb_auto, 71, 71);

	//Write style for baseScreen_rb_auto, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_rb_auto, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_phoneCall_Navigation
	ui->baseScreen_phoneCall_Navigation = lv_obj_create(ui->baseScreen);
	lv_obj_set_pos(ui->baseScreen_phoneCall_Navigation, 0, 0);
	lv_obj_set_size(ui->baseScreen_phoneCall_Navigation, 1280, 720);
	lv_obj_set_scrollbar_mode(ui->baseScreen_phoneCall_Navigation, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->baseScreen_phoneCall_Navigation, LV_OBJ_FLAG_HIDDEN);

	//Write style for baseScreen_phoneCall_Navigation, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_phoneCall_Navigation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_phoneCall_Navigation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_phoneCall_Navigation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_phoneCall_Navigation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_phoneCall_Navigation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_phoneCall_Navigation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_phoneCall_Navigation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_phoneCall_Navigation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_Navigation
	ui->baseScreen_Navigation = lv_obj_create(ui->baseScreen_phoneCall_Navigation);
	lv_obj_set_pos(ui->baseScreen_Navigation, 0, 0);
	lv_obj_set_size(ui->baseScreen_Navigation, 1280, 720);
	lv_obj_set_scrollbar_mode(ui->baseScreen_Navigation, LV_SCROLLBAR_MODE_OFF);

	//Write style for baseScreen_Navigation, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_Navigation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_Navigation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_Navigation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_Navigation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_Navigation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_Navigation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_Navigation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_Navigation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_ETA
	ui->baseScreen_ETA = lv_label_create(ui->baseScreen_Navigation);
	lv_label_set_text(ui->baseScreen_ETA, "16:24 PM");
	lv_label_set_long_mode(ui->baseScreen_ETA, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_ETA, 170, 540);
	lv_obj_set_size(ui->baseScreen_ETA, 660, 50);

	//Write style for baseScreen_ETA, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_ETA, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_ETA, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_ETA, lv_color_hex(0x00A0EE), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_ETA, &lv_font_MIMXRT1170EVKB_50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_ETA, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_ETA, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_ETA, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_ETA, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_ETA, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_ETA, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_ETA, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_ETA, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_ETA, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_ETA, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_turnbyTurnSign
	ui->baseScreen_turnbyTurnSign = lv_img_create(ui->baseScreen_Navigation);
	lv_obj_add_flag(ui->baseScreen_turnbyTurnSign, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_turnbyTurnSign, &_takeNextRamp_alpha_256x256);
	lv_img_set_pivot(ui->baseScreen_turnbyTurnSign, 200,60);
	lv_img_set_angle(ui->baseScreen_turnbyTurnSign, 0);
	lv_obj_set_pos(ui->baseScreen_turnbyTurnSign, 365, 260);
	lv_obj_set_size(ui->baseScreen_turnbyTurnSign, 256, 256);

	//Write style for baseScreen_turnbyTurnSign, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_turnbyTurnSign, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_turningDistance
	ui->baseScreen_turningDistance = lv_label_create(ui->baseScreen_Navigation);
	lv_label_set_text(ui->baseScreen_turningDistance, "In 100 meter");
	lv_label_set_long_mode(ui->baseScreen_turningDistance, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_turningDistance, 170, 165);
	lv_obj_set_size(ui->baseScreen_turningDistance, 660, 75);

	//Write style for baseScreen_turningDistance, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_turningDistance, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_turningDistance, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_turningDistance, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_turningDistance, &lv_font_MIMXRT1170EVKB_75, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_turningDistance, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_turningDistance, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_turningDistance, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_turningDistance, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_turningDistance, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_turningDistance, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_turningDistance, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_turningDistance, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_turningDistance, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_turningDistance, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_distance
	ui->baseScreen_distance = lv_label_create(ui->baseScreen_Navigation);
	lv_label_set_text(ui->baseScreen_distance, "100 km");
	lv_label_set_long_mode(ui->baseScreen_distance, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_distance, 170, 600);
	lv_obj_set_size(ui->baseScreen_distance, 660, 75);

	//Write style for baseScreen_distance, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_distance, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_distance, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_distance, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_distance, &lv_font_MIMXRT1170EVKB_75, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_distance, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_distance, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_distance, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_distance, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_distance, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_distance, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_distance, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_distance, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_distance, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_distance, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_PhoneCall
	ui->baseScreen_PhoneCall = lv_obj_create(ui->baseScreen_phoneCall_Navigation);
	lv_obj_set_pos(ui->baseScreen_PhoneCall, 0, 0);
	lv_obj_set_size(ui->baseScreen_PhoneCall, 1280, 720);
	lv_obj_set_scrollbar_mode(ui->baseScreen_PhoneCall, LV_SCROLLBAR_MODE_OFF);

	//Write style for baseScreen_PhoneCall, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_PhoneCall, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_PhoneCall, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_PhoneCall, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_PhoneCall, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_PhoneCall, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_PhoneCall, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_PhoneCall, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_PhoneCall, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_RejectCallButton
	ui->baseScreen_RejectCallButton = lv_obj_create(ui->baseScreen_PhoneCall);
	lv_obj_set_pos(ui->baseScreen_RejectCallButton, 215, 552);
	lv_obj_set_size(ui->baseScreen_RejectCallButton, 250, 75);
	lv_obj_set_scrollbar_mode(ui->baseScreen_RejectCallButton, LV_SCROLLBAR_MODE_OFF);

	//Write style for baseScreen_RejectCallButton, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_RejectCallButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_RejectCallButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_RejectCallButton, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->baseScreen_RejectCallButton, lv_color_hex(0xC20000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->baseScreen_RejectCallButton, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_RejectCallButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_RejectCallButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_RejectCallButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_RejectCallButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_RejectCallButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_rejectTextButton
	ui->baseScreen_rejectTextButton = lv_label_create(ui->baseScreen_RejectCallButton);
	lv_label_set_text(ui->baseScreen_rejectTextButton, "Reject");
	lv_label_set_long_mode(ui->baseScreen_rejectTextButton, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_rejectTextButton, 0, 13);
	lv_obj_set_size(ui->baseScreen_rejectTextButton, 250, 50);

	//Write style for baseScreen_rejectTextButton, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_rejectTextButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_rejectTextButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_rejectTextButton, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_rejectTextButton, &lv_font_MIMXRT1170EVKB_50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_rejectTextButton, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_rejectTextButton, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_rejectTextButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_rejectTextButton, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_rejectTextButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_rejectTextButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_rejectTextButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_rejectTextButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_rejectTextButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_rejectTextButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_AcceptCallButton
	ui->baseScreen_AcceptCallButton = lv_obj_create(ui->baseScreen_PhoneCall);
	lv_obj_set_pos(ui->baseScreen_AcceptCallButton, 515, 552);
	lv_obj_set_size(ui->baseScreen_AcceptCallButton, 250, 75);
	lv_obj_set_scrollbar_mode(ui->baseScreen_AcceptCallButton, LV_SCROLLBAR_MODE_OFF);

	//Write style for baseScreen_AcceptCallButton, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_AcceptCallButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_AcceptCallButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_AcceptCallButton, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->baseScreen_AcceptCallButton, lv_color_hex(0x00C213), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->baseScreen_AcceptCallButton, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_AcceptCallButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_AcceptCallButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_AcceptCallButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_AcceptCallButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_AcceptCallButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_acceptCallButton
	ui->baseScreen_acceptCallButton = lv_label_create(ui->baseScreen_AcceptCallButton);
	lv_label_set_text(ui->baseScreen_acceptCallButton, "Accept");
	lv_label_set_long_mode(ui->baseScreen_acceptCallButton, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_acceptCallButton, 0, 13);
	lv_obj_set_size(ui->baseScreen_acceptCallButton, 250, 50);

	//Write style for baseScreen_acceptCallButton, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_acceptCallButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_acceptCallButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_acceptCallButton, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_acceptCallButton, &lv_font_MIMXRT1170EVKB_50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_acceptCallButton, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_acceptCallButton, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_acceptCallButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_acceptCallButton, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_acceptCallButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_acceptCallButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_acceptCallButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_acceptCallButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_acceptCallButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_acceptCallButton, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_ProfileIcon
	ui->baseScreen_ProfileIcon = lv_img_create(ui->baseScreen_PhoneCall);
	lv_obj_add_flag(ui->baseScreen_ProfileIcon, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_ProfileIcon, &_Profile_alpha_100x100);
	lv_img_set_pivot(ui->baseScreen_ProfileIcon, 200,60);
	lv_img_set_angle(ui->baseScreen_ProfileIcon, 0);
	lv_obj_set_pos(ui->baseScreen_ProfileIcon, 440, 170);
	lv_obj_set_size(ui->baseScreen_ProfileIcon, 100, 100);

	//Write style for baseScreen_ProfileIcon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_ProfileIcon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_callerName
	ui->baseScreen_callerName = lv_label_create(ui->baseScreen_PhoneCall);
	lv_label_set_text(ui->baseScreen_callerName, "Caller Name");
	lv_label_set_long_mode(ui->baseScreen_callerName, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_callerName, 170, 304);
	lv_obj_set_size(ui->baseScreen_callerName, 660, 75);

	//Write style for baseScreen_callerName, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_callerName, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_callerName, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_callerName, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_callerName, &lv_font_MIMXRT1170EVKB_75, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_callerName, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_callerName, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_callerName, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_callerName, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_callerName, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_callerName, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_callerName, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_callerName, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_callerName, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_callerName, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_callTime
	ui->baseScreen_callTime = lv_label_create(ui->baseScreen_PhoneCall);
	lv_label_set_text(ui->baseScreen_callTime, "00:00");
	lv_label_set_long_mode(ui->baseScreen_callTime, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_callTime, 170, 450);
	lv_obj_set_size(ui->baseScreen_callTime, 660, 75);

	//Write style for baseScreen_callTime, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_callTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_callTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_callTime, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_callTime, &lv_font_MIMXRT1170EVKB_75, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_callTime, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_callTime, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_callTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_callTime, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_callTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_callTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_callTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_callTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_callTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_callTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_callerNumber
	ui->baseScreen_callerNumber = lv_label_create(ui->baseScreen_PhoneCall);
	lv_label_set_text(ui->baseScreen_callerNumber, "+91 8111010315");
	lv_label_set_long_mode(ui->baseScreen_callerNumber, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_callerNumber, 170, 390);
	lv_obj_set_size(ui->baseScreen_callerNumber, 660, 50);

	//Write style for baseScreen_callerNumber, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_callerNumber, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_callerNumber, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_callerNumber, lv_color_hex(0x00A0EE), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_callerNumber, &lv_font_MIMXRT1170EVKB_50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_callerNumber, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_callerNumber, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_callerNumber, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_callerNumber, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_callerNumber, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_callerNumber, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_callerNumber, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_callerNumber, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_callerNumber, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_callerNumber, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_bluetoothWidgetType
	ui->baseScreen_bluetoothWidgetType = lv_label_create(ui->baseScreen_phoneCall_Navigation);
	lv_label_set_text(ui->baseScreen_bluetoothWidgetType, "IncommingCall");
	lv_label_set_long_mode(ui->baseScreen_bluetoothWidgetType, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_bluetoothWidgetType, 170, 40);
	lv_obj_set_size(ui->baseScreen_bluetoothWidgetType, 660, 75);

	//Write style for baseScreen_bluetoothWidgetType, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_bluetoothWidgetType, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_bluetoothWidgetType, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_bluetoothWidgetType, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_bluetoothWidgetType, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_bluetoothWidgetType, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_bluetoothWidgetType, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_bluetoothWidgetType, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_bluetoothWidgetType, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_bluetoothWidgetType, lv_color_hex(0xFCCD26), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_bluetoothWidgetType, &lv_font_MIMXRT1170EVKB_75, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_bluetoothWidgetType, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_bluetoothWidgetType, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_bluetoothWidgetType, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_bluetoothWidgetType, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_speedometerMenuWidget
	ui->baseScreen_speedometerMenuWidget = lv_obj_create(ui->baseScreen);
	lv_obj_set_pos(ui->baseScreen_speedometerMenuWidget, 858, 240);
	lv_obj_set_size(ui->baseScreen_speedometerMenuWidget, 400, 225);
	lv_obj_set_scrollbar_mode(ui->baseScreen_speedometerMenuWidget, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->baseScreen_speedometerMenuWidget, LV_OBJ_FLAG_HIDDEN);

	//Write style for baseScreen_speedometerMenuWidget, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_speedometerMenuWidget, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->baseScreen_speedometerMenuWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->baseScreen_speedometerMenuWidget, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->baseScreen_speedometerMenuWidget, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_speedometerMenuWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_speedometerMenuWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_speedometerMenuWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_speedometerMenuWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_speedometerMenuWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_speedometerMenuWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_speedometerMenuWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_speedometermenuUnit
	ui->baseScreen_speedometermenuUnit = lv_label_create(ui->baseScreen_speedometerMenuWidget);
	lv_label_set_text(ui->baseScreen_speedometermenuUnit, "kmph");
	lv_label_set_long_mode(ui->baseScreen_speedometermenuUnit, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_speedometermenuUnit, 0, 180);
	lv_obj_set_size(ui->baseScreen_speedometermenuUnit, 400, 30);

	//Write style for baseScreen_speedometermenuUnit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_speedometermenuUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_speedometermenuUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_speedometermenuUnit, lv_color_hex(0x0093E7), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_speedometermenuUnit, &lv_font_MIMXRT1170EVKB_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_speedometermenuUnit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_speedometermenuUnit, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_speedometermenuUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_speedometermenuUnit, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_speedometermenuUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_speedometermenuUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_speedometermenuUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_speedometermenuUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_speedometermenuUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_speedometermenuUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_speedometerMenuValue
	ui->baseScreen_speedometerMenuValue = lv_label_create(ui->baseScreen_speedometerMenuWidget);
	lv_label_set_text(ui->baseScreen_speedometerMenuValue, "0");
	lv_label_set_long_mode(ui->baseScreen_speedometerMenuValue, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_speedometerMenuValue, 0, 0);
	lv_obj_set_size(ui->baseScreen_speedometerMenuValue, 400, 185);

	//Write style for baseScreen_speedometerMenuValue, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_speedometerMenuValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_speedometerMenuValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_speedometerMenuValue, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_speedometerMenuValue, &lv_font_speedometerValue_200, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_speedometerMenuValue, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_speedometerMenuValue, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_speedometerMenuValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_speedometerMenuValue, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_speedometerMenuValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_speedometerMenuValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_speedometerMenuValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_speedometerMenuValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_speedometerMenuValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_speedometerMenuValue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_batteryMenuWidget
	ui->baseScreen_batteryMenuWidget = lv_obj_create(ui->baseScreen);
	lv_obj_set_pos(ui->baseScreen_batteryMenuWidget, 975, 475);
	lv_obj_set_size(ui->baseScreen_batteryMenuWidget, 184, 64);
	lv_obj_set_scrollbar_mode(ui->baseScreen_batteryMenuWidget, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->baseScreen_batteryMenuWidget, LV_OBJ_FLAG_HIDDEN);

	//Write style for baseScreen_batteryMenuWidget, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_batteryMenuWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_batteryMenuWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_batteryMenuWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_batteryMenuWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_batteryMenuWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_batteryMenuWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_batteryMenuWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_batteryMenuWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_batteryMenuIcon
	ui->baseScreen_batteryMenuIcon = lv_img_create(ui->baseScreen_batteryMenuWidget);
	lv_obj_add_flag(ui->baseScreen_batteryMenuIcon, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_batteryMenuIcon, &_powerIcon_alpha_64x64);
	lv_img_set_pivot(ui->baseScreen_batteryMenuIcon, 50,50);
	lv_img_set_angle(ui->baseScreen_batteryMenuIcon, 0);
	lv_obj_set_pos(ui->baseScreen_batteryMenuIcon, 0, 0);
	lv_obj_set_size(ui->baseScreen_batteryMenuIcon, 64, 64);

	//Write style for baseScreen_batteryMenuIcon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_batteryMenuIcon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_batteryMenuvalue
	ui->baseScreen_batteryMenuvalue = lv_label_create(ui->baseScreen_batteryMenuWidget);
	lv_label_set_text(ui->baseScreen_batteryMenuvalue, "100");
	lv_label_set_long_mode(ui->baseScreen_batteryMenuvalue, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_batteryMenuvalue, 74, 8);
	lv_obj_set_size(ui->baseScreen_batteryMenuvalue, 100, 48);

	//Write style for baseScreen_batteryMenuvalue, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_batteryMenuvalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_batteryMenuvalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_batteryMenuvalue, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_batteryMenuvalue, &lv_font_MIMXRT1170EVKB_50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_batteryMenuvalue, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_batteryMenuvalue, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_batteryMenuvalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_batteryMenuvalue, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_batteryMenuvalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_batteryMenuvalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_batteryMenuvalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_batteryMenuvalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_batteryMenuvalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_batteryMenuvalue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_firstWidget
	ui->baseScreen_firstWidget = lv_obj_create(ui->baseScreen);
	lv_obj_set_pos(ui->baseScreen_firstWidget, 850, 155);
	lv_obj_set_size(ui->baseScreen_firstWidget, 400, 120);
	lv_obj_set_scrollbar_mode(ui->baseScreen_firstWidget, LV_SCROLLBAR_MODE_OFF);

	//Write style for baseScreen_firstWidget, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_firstWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_firstWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_firstWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_firstWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_firstWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_firstWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_firstWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_firstWidget, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_widgetOneBackground
	ui->baseScreen_widgetOneBackground = lv_img_create(ui->baseScreen_firstWidget);
	lv_obj_add_flag(ui->baseScreen_widgetOneBackground, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->baseScreen_widgetOneBackground, &_widgetbackground_alpha_400x120);
	lv_img_set_pivot(ui->baseScreen_widgetOneBackground, 200,60);
	lv_img_set_angle(ui->baseScreen_widgetOneBackground, 0);
	lv_obj_set_pos(ui->baseScreen_widgetOneBackground, 0, 0);
	lv_obj_set_size(ui->baseScreen_widgetOneBackground, 400, 120);

	//Write style for baseScreen_widgetOneBackground, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->baseScreen_widgetOneBackground, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_TripA_Unit
	ui->baseScreen_TripA_Unit = lv_label_create(ui->baseScreen_firstWidget);
	lv_label_set_text(ui->baseScreen_TripA_Unit, "km");
	lv_label_set_long_mode(ui->baseScreen_TripA_Unit, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_TripA_Unit, 12, 90);
	lv_obj_set_size(ui->baseScreen_TripA_Unit, 169, 24);

	//Write style for baseScreen_TripA_Unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_TripA_Unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_TripA_Unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_TripA_Unit, lv_color_hex(0x0078ff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_TripA_Unit, &lv_font_MIMXRT1170EVKB_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_TripA_Unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_TripA_Unit, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_TripA_Unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_TripA_Unit, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_TripA_Unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_TripA_Unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_TripA_Unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_TripA_Unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_TripA_Unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_TripA_Unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_TripA_Value
	ui->baseScreen_TripA_Value = lv_label_create(ui->baseScreen_firstWidget);
	lv_label_set_text(ui->baseScreen_TripA_Value, "0003");
	lv_label_set_long_mode(ui->baseScreen_TripA_Value, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_TripA_Value, 6, 39);
	lv_obj_set_size(ui->baseScreen_TripA_Value, 169, 86);

	//Write style for baseScreen_TripA_Value, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_TripA_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_TripA_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_TripA_Value, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_TripA_Value, &lv_font_MIMXRT1170EVKB_50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_TripA_Value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_TripA_Value, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_TripA_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_TripA_Value, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_TripA_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_TripA_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_TripA_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_TripA_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_TripA_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_TripA_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_TripA
	ui->baseScreen_TripA = lv_label_create(ui->baseScreen_firstWidget);
	lv_label_set_text(ui->baseScreen_TripA, "OdoMtr\n");
	lv_label_set_long_mode(ui->baseScreen_TripA, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_TripA, -2, 1);
	lv_obj_set_size(ui->baseScreen_TripA, 169, 32);

	//Write style for baseScreen_TripA, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_TripA, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_TripA, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_TripA, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_TripA, &lv_font_montserratMedium_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_TripA, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_TripA, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_TripA, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_TripA, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_TripA, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_TripA, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_TripA, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_TripA, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_TripA, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_TripA, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_TripB
	ui->baseScreen_TripB = lv_label_create(ui->baseScreen_firstWidget);
	lv_label_set_text(ui->baseScreen_TripB, "TripMtr");
	lv_label_set_long_mode(ui->baseScreen_TripB, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_TripB, 222, 2);
	lv_obj_set_size(ui->baseScreen_TripB, 169, 32);

	//Write style for baseScreen_TripB, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_TripB, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_TripB, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_TripB, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_TripB, &lv_font_montserratMedium_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_TripB, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_TripB, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_TripB, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_TripB, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_TripB, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_TripB, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_TripB, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_TripB, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_TripB, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_TripB, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_TripB_Value
	ui->baseScreen_TripB_Value = lv_label_create(ui->baseScreen_firstWidget);
	lv_label_set_text(ui->baseScreen_TripB_Value, "0003");
	lv_label_set_long_mode(ui->baseScreen_TripB_Value, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_TripB_Value, 231, 41);
	lv_obj_set_size(ui->baseScreen_TripB_Value, 169, 86);

	//Write style for baseScreen_TripB_Value, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_TripB_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_TripB_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_TripB_Value, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_TripB_Value, &lv_font_MIMXRT1170EVKB_50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_TripB_Value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_TripB_Value, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_TripB_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_TripB_Value, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_TripB_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_TripB_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_TripB_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_TripB_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_TripB_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_TripB_Value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_TripB_Unit
	ui->baseScreen_TripB_Unit = lv_label_create(ui->baseScreen_firstWidget);
	lv_label_set_text(ui->baseScreen_TripB_Unit, "km");
	lv_label_set_long_mode(ui->baseScreen_TripB_Unit, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->baseScreen_TripB_Unit, 226, 91);
	lv_obj_set_size(ui->baseScreen_TripB_Unit, 169, 24);

	//Write style for baseScreen_TripB_Unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_TripB_Unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_TripB_Unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_TripB_Unit, lv_color_hex(0x0085ff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_TripB_Unit, &lv_font_MIMXRT1170EVKB_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_TripB_Unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_TripB_Unit, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->baseScreen_TripB_Unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_TripB_Unit, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_TripB_Unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_TripB_Unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_TripB_Unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_TripB_Unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_TripB_Unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_TripB_Unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_cont_1
	ui->baseScreen_cont_1 = lv_obj_create(ui->baseScreen_firstWidget);
	lv_obj_set_pos(ui->baseScreen_cont_1, 200, 5);
	lv_obj_set_size(ui->baseScreen_cont_1,5, 100);
	lv_obj_set_scrollbar_mode(ui->baseScreen_cont_1, LV_SCROLLBAR_MODE_OFF);

	//Write style for baseScreen_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->baseScreen_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->baseScreen_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->baseScreen_cont_1, lv_color_hex(0x928100), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->baseScreen_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->baseScreen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->baseScreen_cont_1, lv_color_hex(0xa6a500), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->baseScreen_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes baseScreen_clusterTime
	static bool baseScreen_clusterTime_timer_enabled = false;
	ui->baseScreen_clusterTime = lv_dclock_create(ui->baseScreen, "3:47:20 PM");
	if (!baseScreen_clusterTime_timer_enabled) {
		lv_timer_create(baseScreen_clusterTime_timer, 1000, NULL);
		baseScreen_clusterTime_timer_enabled = true;
	}
	lv_obj_set_pos(ui->baseScreen_clusterTime, 860, 610);
	lv_obj_set_size(ui->baseScreen_clusterTime, 400, 64);
	lv_obj_add_flag(ui->baseScreen_clusterTime, LV_OBJ_FLAG_HIDDEN);

	//Write style for baseScreen_clusterTime, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_radius(ui->baseScreen_clusterTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->baseScreen_clusterTime, lv_color_hex(0x0093E7), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->baseScreen_clusterTime, &lv_font_MIMXRT1170EVKB_50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->baseScreen_clusterTime, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->baseScreen_clusterTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->baseScreen_clusterTime, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->baseScreen_clusterTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->baseScreen_clusterTime, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->baseScreen_clusterTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->baseScreen_clusterTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->baseScreen_clusterTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->baseScreen_clusterTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//The custom code of baseScreen.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->baseScreen);

}
