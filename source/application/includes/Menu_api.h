#ifndef APPLICATION_INCLUDES_MENU_API_H_
#define APPLICATION_INCLUDES_MENU_API_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "menu.h"

// Struct definition for MenuItem
typedef struct MenuItem {
    char* name;
    void (*action)(void);        // Function pointer for action
    struct MenuItem* next;
    struct MenuItem* prev;
    struct MenuItem* parent;
    struct MenuItem* child;
} MenuItem;

// Function declarations
void Menu();
void handleButtonInput();
void initMenu();
void LoadMainScreen();
void loadTrips();
void loadVehicle();
void loadBluetooth();
void loadPreference();
void loadCustomization();
void loadOption1();
void loadOption2();
void loadOption3();
void loadSettings_TripSettings();
void loadSettings_DisplaySettings();

// Global menu items
extern MenuItem mainMenu;
extern MenuItem mainHome;

extern MenuItem Trip_1;
extern MenuItem Trip_2;
extern MenuItem Trip_3;
extern MenuItem Trip_4;
extern MenuItem Trip_Daily;
extern MenuItem Trips;

extern MenuItem ResetTrip_1;
extern MenuItem ResetTrip_2;
extern MenuItem ResetTrip_3;
extern MenuItem ResetTrip_4;
extern MenuItem ResetTrip_Daily;

extern MenuItem Service;
extern MenuItem Performance;
extern MenuItem Documents;
extern MenuItem Vehicle;

extern MenuItem Devices;
extern MenuItem DisplayCall;
extern MenuItem Bluetooth;

extern MenuItem AdaptiveHeadLamp;
extern MenuItem DRL;
extern MenuItem TractionControl;
extern MenuItem QuickShifter;
extern MenuItem DisplaySetup;
extern MenuItem SpeedAlert;
extern MenuItem GoPro;
extern MenuItem Preference;

extern MenuItem LiveWidgets;
extern MenuItem DriveMode;
extern MenuItem Customization;

// Pointer to track the current menu
extern MenuItem* currentMenu;

#endif /* APPLICATION_INCLUDES_MENU_API_H_ */
