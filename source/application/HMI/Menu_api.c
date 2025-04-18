#include "Menu_api.h"

// Define menu items
MenuItem mainHome = { "Home Screen", LoadMainScreen, NULL, NULL, NULL, NULL };
MenuItem mainMenu = { "Main Menu", NULL, NULL, &mainHome, NULL, NULL };

MenuItem Trip_1 = { "Trip 1", loadOption1, NULL, NULL, NULL, NULL };
MenuItem Trip_2 = { "Trip 2", loadOption2, NULL, &Trip_1, NULL, NULL };
MenuItem Trip_3 = { "Trip 3", loadOption3, NULL, &Trip_2, NULL, NULL };
MenuItem Trip_4 = { "Trip 4", loadOption1, NULL, &Trip_3, NULL, NULL };
MenuItem Trip_Daily = { "Trip Daily", loadOption2, NULL, &Trip_4, NULL, NULL };
MenuItem Trips = { "Trips", loadTrips, NULL, NULL, NULL, &Trip_1 };

MenuItem ResetTrip_1 = { "Reset Trip 1", loadOption1, NULL, NULL, NULL, NULL };
MenuItem ResetTrip_2 = { "Reset Trip 2", loadOption2, NULL, NULL, NULL, NULL };
MenuItem ResetTrip_3 = { "Reset Trip 3", loadOption3, NULL, NULL, NULL, NULL };
MenuItem ResetTrip_4 = { "Reset Trip 4", loadOption1, NULL, NULL, NULL, NULL };
MenuItem ResetTrip_Daily = { "Reset Trip Daily", loadOption2, NULL, NULL, NULL, NULL };

MenuItem Service = { "Service", loadOption1, NULL, NULL, NULL, NULL };
MenuItem Performance = { "Performance", loadOption2, NULL, &Service, NULL, NULL };
MenuItem Documents = { "Documents", loadOption3, NULL, &Performance, NULL, NULL };
MenuItem Vehicle = { "Vehicle", loadVehicle, NULL, &Trips, NULL, &Service };

MenuItem Devices = { "Devices", loadOption1, NULL, NULL, NULL, NULL };
MenuItem DisplayCall = { "Display Call", loadOption2, NULL, &Devices, NULL, NULL };
MenuItem Bluetooth = { "Bluetooth", loadBluetooth, NULL, &Vehicle, NULL, &Devices };

MenuItem AdaptiveHeadLamp = { "Adaptive HeadLamp", loadOption1, NULL, NULL, NULL, NULL };
MenuItem DRL = { "DRL", loadOption2, NULL, &AdaptiveHeadLamp, NULL, NULL };
MenuItem TractionControl = { "Traction Control", loadOption3, NULL, &DRL, NULL, NULL };
MenuItem QuickShifter = { "Quick Shifter", loadOption1, NULL, &TractionControl, NULL, NULL };
MenuItem DisplaySetup = { "Display Setup", loadOption2, NULL, &QuickShifter, NULL, NULL };
MenuItem SpeedAlert = { "Speed Alert", loadOption3, NULL, &DisplaySetup, NULL, NULL };
MenuItem GoPro = { "GoPro", loadOption1, NULL, &SpeedAlert, NULL, NULL };
MenuItem Preference = { "Preference", loadPreference, NULL, &Bluetooth, NULL, &AdaptiveHeadLamp };

MenuItem LiveWidgets = { "Live Widgets", loadOption1, NULL, NULL, NULL, NULL };
MenuItem DriveMode = { "Drive Mode", loadOption2, NULL, &LiveWidgets, NULL, NULL };
MenuItem Customization = { "Customization", loadCustomization, NULL, &Preference, NULL, &LiveWidgets };

// Pointer to track the current menu
MenuItem* currentMenu = &mainHome;

// Handle button input and navigate the menu
void handleButtonInput() {
    switch(getButtonInput()) {
        case BUTTON_RIGHT:
            if (currentMenu->action != NULL) {
                currentMenu->action();
            }
            if (currentMenu->child != NULL) {
                currentMenu = currentMenu->child;
            }
            break;
        case BUTTON_LEFT:
            if (currentMenu->parent != NULL) {
                currentMenu = currentMenu->parent;
            }
            break;
        case BUTTON_DOWN:
            if (currentMenu->next != NULL) {
                currentMenu = currentMenu->next;
            }
            break;
        case BUTTON_UP:
            if (currentMenu->prev != NULL) {
                currentMenu = currentMenu->prev;
            }
            break;
    }
}

// Initialize the menu system
void initMenu() {
    // Set parent-child relationships
    mainHome.child = &mainMenu;
    mainMenu.parent = &mainHome;

    mainMenu.child = &Trips;
    Trips.parent = &mainMenu;
    Trips.next = &Vehicle;
    Vehicle.parent = &mainMenu;
    Vehicle.prev = &Trips;
    Vehicle.next = &Bluetooth;
    Bluetooth.parent = &mainMenu;
    Bluetooth.prev = &Vehicle;
    Bluetooth.next = &Preference;
    Preference.parent = &mainMenu;
    Preference.prev = &Bluetooth;
    Preference.next = &Customization;
    Customization.parent = &mainMenu;
    Customization.prev = &Preference;

    Trips.child = &Trip_1;
    Trip_1.parent = &Trips;
    Trip_1.next = &Trip_2;
    Trip_2.parent = &Trips;
    Trip_2.prev = &Trip_1;
    Trip_2.next = &Trip_3;
    Trip_3.parent = &Trips;
    Trip_3.prev = &Trip_2;
    Trip_3.next = &Trip_4;
    Trip_4.parent = &Trips;
    Trip_4.prev = &Trip_3;
    Trip_4.next = &Trip_Daily;
    Trip_Daily.parent = &Trips;
    Trip_Daily.prev = &Trip_4;

    Vehicle.child = &Service;
    Service.parent = &Vehicle;
    Service.next = &Performance;
    Performance.parent = &Vehicle;
    Performance.prev = &Service;
    Performance.next = &Documents;
    Documents.parent = &Vehicle;
    Documents.prev = &Performance;

    Bluetooth.child = &Devices;
    Devices.parent = &Bluetooth;
    Devices.next = &DisplayCall;
    DisplayCall.parent = &Bluetooth;
    DisplayCall.prev = &Devices;

    Preference.child = &AdaptiveHeadLamp;
    AdaptiveHeadLamp.parent = &Preference;
    AdaptiveHeadLamp.next = &DRL;
    DRL.parent = &Preference;
    DRL.prev = &AdaptiveHeadLamp;
    DRL.next = &TractionControl;
    TractionControl.parent = &Preference;
    TractionControl.prev = &DRL;
    TractionControl.next = &QuickShifter;
    QuickShifter.parent = &Preference;
    QuickShifter.prev = &TractionControl;
    QuickShifter.next = &DisplaySetup;
    DisplaySetup.parent = &Preference;
    DisplaySetup.prev = &QuickShifter;
    DisplaySetup.next = &SpeedAlert;
    SpeedAlert.parent = &Preference;
    SpeedAlert.prev = &DisplaySetup;
    SpeedAlert.next = &GoPro;
    GoPro.parent = &Preference;
    GoPro.prev = &SpeedAlert;

    Customization.child = &LiveWidgets;
    LiveWidgets.parent = &Customization;
    LiveWidgets.next = &DriveMode;
    DriveMode.parent = &Customization;
    DriveMode.prev = &LiveWidgets;

    Trip_1.child = &ResetTrip_1;
    ResetTrip_1.parent = &Trip_1;

    Trip_2.child = &ResetTrip_2;
    ResetTrip_2.parent = &Trip_2;

    Trip_3.child = &ResetTrip_3;
    ResetTrip_3.parent = &Trip_3;

    Trip_4.child = &ResetTrip_4;
    ResetTrip_4.parent = &Trip_4;

    Trip_Daily.child = &ResetTrip_Daily;
    ResetTrip_Daily.parent = &Trip_Daily;

    PRINTF("Menu Initialized!!!\n");
}

// Main menu function
void Menu() {
}

// Screen and action functions
void LoadMainScreen() {
    PRINTF("Main Screen Loaded !!!\n");
}

void loadSettings_TripSettings() {
    PRINTF("Trip Settings Screen Loaded !!!\n");
}

void loadSettings_DisplaySettings() {
    PRINTF("Display Settings Screen Loaded !!!\n");
}

void loadOption1() {
    PRINTF("Option 1 Screen Loaded !!!\n");
}

void loadOption2() {
    PRINTF("Option 2 Screen Loaded !!!\n");
}

void loadOption3() {
    PRINTF("Option 3 Screen Loaded !!!\n");
}

void loadTrips() {
    PRINTF("Trips Screen Loaded !!!\n");
}

void loadVehicle() {
    PRINTF("Vehicle Screen Loaded !!!\n");
}

void loadBluetooth() {
    PRINTF("Bluetooth Screen Loaded !!!\n");
}

void loadPreference() {
    PRINTF("Preference Screen Loaded !!!\n");
}

void loadCustomization() {
    PRINTF("Customization Screen Loaded !!!\n");
}
