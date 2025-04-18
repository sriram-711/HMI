#include "menu.h"


uint8_t Button = 0;

uint8_t leftRightCount = 0;
uint8_t upDownCount = 0;

uint8_t currentMenuID = 0;
uint8_t currentMenuType = 0;
uint8_t currentLoadedMenu = 0;
uint8_t currentSelectedTrip = 0;
bool currentTripResetState = 0;

void setMenuLoaded(uint8_t loadedMenu){
	currentLoadedMenu = loadedMenu;
}

uint8_t getMenuLoaded()	{
	return currentLoadedMenu;
}

void setSelectedTrip(uint8_t selectedTrip){
	currentSelectedTrip = selectedTrip;
}

uint8_t getSelectedTrip()	{
	return currentSelectedTrip;
}

void setTripResetState(bool resetState)	{
	currentTripResetState = resetState;
}
bool getTripResetState()	{
	return currentTripResetState;
}

void setUpDownLeftRightCount(uint8_t buttonInput)	{

	switch(buttonInput){
	case BUTTON_RIGHT:
		setMenuOption(0);
		if(leftRightCount < 9)	{
			leftRightCount++;
		}
		break;
	case BUTTON_LEFT:
		setMenuOption(0);
		if(leftRightCount > 0)	{
			leftRightCount--;
		}
		break;
	case BUTTON_DOWN:
		if(upDownCount < 14  )	{
			upDownCount++;
		}
		break;
	case BUTTON_UP:
		if(upDownCount > 0)	{
			upDownCount--;
		}
		break;
	}
	Button = buttonInput;
//	handleButtonInput();
}

uint8_t getButtonInput()	{
	return Button;
}

uint8_t getMenuLevel()	{
	return leftRightCount;
}

void setMenuLevel(uint8_t leftRight_COUNT)	{
	leftRightCount = leftRight_COUNT;
}

uint8_t getMenuOption()	{
	return upDownCount;
}

void setMenuOption(uint8_t upDown_COUNT)	{
	upDownCount = upDown_COUNT;
}

// Menu Updated
/*
 * #include "menu.h"

uint8_t currentMenuLevel = 0;
uint8_t currentMenuOptionIndex = 0;
uint8_t currentMenuID = 0;
uint8_t currentMenuType = 0;
uint8_t currentButtonInput = 0;

uint8_t maxMenuLevel = 9;
uint8_t maxMenuOptionIndex = 13;

void setButtonInput(uint8_t buttonInput)	{
	currentButtonInput = buttonInput;
}
uint8_t getButtonInput()	{
	return currentButtonInput;
}

void setMaxMenuLevel(uint8_t maxMenulevel)	{
	maxMenuLevel = maxMenulevel;
}
uint8_t getMaxMenulevel()	{
	return maxMenuLevel;
}

void setMaxMenuOptionIndex(uint8_t maxMenuOptionindex)	{
	maxMenuOptionIndex = maxMenuOptionindex;
}
uint8_t getMaxMenuOptionIndex()	{
	return maxMenuOptionIndex;
}


void setUpDownLeftRightCount()	{

	switch(getButtonInput()){
	case BUTTON_RIGHT:
		if(getMenulevel() < getMaxMenulevel())	{
			currentMenuLevel++;
		}
		break;
	case BUTTON_LEFT:
		if(getMenulevel() > 0)	{
			currentMenuLevel--;
		}
		break;
	case BUTTON_DOWN:
		if(getMenuOptionIndex() < getMaxMenuOptionIndex())	{
			currentMenuOptionIndex++;
		}
		break;
	case BUTTON_UP:
		if(getMenuOptionIndex() > 0)	{
			currentMenuOptionIndex--;
		}
		break;
	default:
		break;
	}
}

uint8_t getMenulevel()	{
	return currentMenuLevel;
}

uint8_t getMenuOptionIndex()	{
	return currentMenuOptionIndex;
}

uint8_t getMenuID()	{
	return currentMenuID;
}

uint8_t getMenuType()	{
	return currentMenuType;
}

void setMenuIDandType(uint8_t menuID, uint8_t menuType)	{
	currentMenuID = menuID;
	currentMenuType = menuType;
}


void setmenuScreen()	{

	// BUTTOn Value Counter
	setUpDownLeftRightCount();

	switch(getMenulevel())	{
	case MENU_LEVEL_0:
		setMenuIDandType(MENU_HOMESCREEN, MENU_TYPEZERO);
		setMaxMenuLevel(0);
		setMaxMenuOptionIndex(0);
	default:
		break;
	case MENU_LEVEL_1:
		setMaxMenuLevel(9);
		setMaxMenuOptionIndex(5);
		switch(getMenuOptionIndex())	{
		case MENU_OPTION_INDEX_0:
			setMenuIDandType(MENU_TRIPDETAILS, MENU_TYPEONE);
			break;
		case MENU_OPTION_INDEX_1:
			setMenuIDandType(MENU_VEHICLE, MENU_TYPEONE);
			break;
		case MENU_OPTION_INDEX_2:
			setMenuIDandType(MENU_BLUETOOTH, MENU_TYPEONE);
			break;
		case MENU_OPTION_INDEX_3:
			setMenuIDandType(MENU_PREFERENCES, MENU_TYPEONE);
			break;
		case MENU_OPTION_INDEX_4:
			setMenuIDandType(MENU_CUSTOMIZATION, MENU_TYPEONE);
			break;
		default:
			break;
		}
		case MENU_LEVEL_2:
			switch(getMenuOptionIndex())	{
			case MENU_OPTION_INDEX_0:
				if(getMenuID() == MENU_TRIPDETAILS)	{
					setMenuIDandType(MENU_TRIPDETAILS_TRIPONE, MENU_TYPETWO);
				}	else if(getMenuID() == MENU_VEHICLE)	{
					setMenuIDandType(MENU_VEHICLE_SERVICERECORD, MENU_TYPEONE);
				}	else if(getMenuID() == MENU_BLUETOOTH)	{
					setMenuIDandType(MENU_BLUETOOTH_DEVICES, MENU_TYPEONE);
				}	else if(getMenuID() == MENU_PREFERENCES)	{
					setMenuIDandType(MENU_PREFERENCES_ADAPTIVEHEADLAMP, MENU_TYPETHREE);
				}	else if(getMenuID() == MENU_CUSTOMIZATION){
					setMenuIDandType(MENU_CUSTOMIZATION_LIVEWIDGETS, MENU_TYPEONE);
				}	else {
					// Nothing to Display
				}

				break;
			case MENU_OPTION_INDEX_1:
				if(getMenuID() == MENU_TRIPDETAILS)	{
					setMenuIDandType(MENU_TRIPDETAILS_TRIPTWO, MENU_TYPETWO);
				}	else if(getMenuID() == MENU_VEHICLE)	{
					setMenuIDandType(MENU_VEHICLE_PERFOMANCE_RECORD, MENU_TYPEONE);
				}	else if(getMenuID() == MENU_BLUETOOTH)	{
					setMenuIDandType(MENU_BLUETOOTH_DISPLAY_CALL, MENU_TYPEONE);
				}	else if(getMenuID() == MENU_PREFERENCES)	{
					setMenuIDandType(MENU_PREFERENCES_DRL, MENU_TYPETHREE);
				}	else if(getMenuID() == MENU_CUSTOMIZATION){
					setMenuIDandType(MENU_CUSTOMIZATION_DRIVEMODE, MENU_TYPEONE);
				}	else {
					// Nothing to Display
				}
				break;
			case MENU_OPTION_INDEX_2:
				if(getMenuID() == MENU_TRIPDETAILS)	{
					setMenuIDandType(MENU_TRIPDETAILS_TRIPTHREE, MENU_TYPETWO);
				}	else if(getMenuID() == MENU_VEHICLE)	{
					setMenuIDandType(MENU_VEHICLE_DOCUMENTS, MENU_TYPEONE);
				}	else if(getMenuID() == MENU_PREFERENCES)	{
					setMenuIDandType(MENU_PREFERENCES_TRACTIONCONTROL, MENU_TYPETHREE);
				}	else {
					// Nothing to Display
				}
				break;
			case MENU_OPTION_INDEX_3:
				if(getMenuID() == MENU_TRIPDETAILS)	{
					setMenuIDandType(MENU_TRIPDETAILS_TRIPFOUR, MENU_TYPETWO);
				}	else if(getMenuID() == MENU_PREFERENCES)	{
					setMenuIDandType(MENU_PREFERENCES_QUICKSHIFTER, MENU_TYPETHREE);
				}	else {
					// Nothing to Display
				}
				break;
			case MENU_OPTION_INDEX_4:
				if(getMenuID() == MENU_TRIPDETAILS)	{
					setMenuIDandType(MENU_TRIPDETAILS_TRIPDAILYTRIP, MENU_TYPETWO);
				}	else if(getMenuID() == MENU_PREFERENCES)	{
					setMenuIDandType(MENU_PREFERENCES_DISPLAYSETUP, MENU_TYPETHREE);
				}	else {
					// Nothing to Display
				}
				break;
			case MENU_OPTION_INDEX_5:
				if(getMenuID() == MENU_PREFERENCES)	{
					setMenuIDandType(MENU_PREFERENCES_SPEEDALERT, MENU_TYPETHREE);
				}	else {
					// Nothing to Display
				}
				break;
			case MENU_OPTION_INDEX_6:
				if(getMenuID() == MENU_PREFERENCES)	{
					setMenuIDandType(MENU_PREFERENCES_GOPRO, MENU_TYPETHREE);
				}	else {
					// Nothing to Display
				}
				break;
			default:
				break;
			}
			break;
			case MENU_LEVEL_3:
				switch(getMenuOptionIndex())	{
				case MENU_OPTION_INDEX_0:
					break;
				case MENU_OPTION_INDEX_1:
					break;
				case MENU_OPTION_INDEX_2:
					break;
				case MENU_OPTION_INDEX_3:
					break;
				case MENU_OPTION_INDEX_4:
					break;
				case MENU_OPTION_INDEX_5:
					break;
				case MENU_OPTION_INDEX_6:
					break;
				case MENU_OPTION_INDEX_7:
					break;
				case MENU_OPTION_INDEX_8:
					break;
				case MENU_OPTION_INDEX_9:
					break;
				case MENU_OPTION_INDEX_10:
					break;
				case MENU_OPTION_INDEX_11:
					break;
				case MENU_OPTION_INDEX_12:
					break;
				case MENU_OPTION_INDEX_13:
					break;
				}
				break;
				case MENU_LEVEL_4:
					switch(getMenuOptionIndex())	{
					case MENU_OPTION_INDEX_0:
						break;
					case MENU_OPTION_INDEX_1:
						break;
					case MENU_OPTION_INDEX_2:
						break;
					case MENU_OPTION_INDEX_3:
						break;
					case MENU_OPTION_INDEX_4:
						break;
					case MENU_OPTION_INDEX_5:
						break;
					case MENU_OPTION_INDEX_6:
						break;
					case MENU_OPTION_INDEX_7:
						break;
					case MENU_OPTION_INDEX_8:
						break;
					case MENU_OPTION_INDEX_9:
						break;
					case MENU_OPTION_INDEX_10:
						break;
					case MENU_OPTION_INDEX_11:
						break;
					case MENU_OPTION_INDEX_12:
						break;
					case MENU_OPTION_INDEX_13:
						break;
					}
					break;
					case MENU_LEVEL_5:
						switch(getMenuOptionIndex())	{
						case MENU_OPTION_INDEX_0:
							break;
						case MENU_OPTION_INDEX_1:
							break;
						case MENU_OPTION_INDEX_2:
							break;
						case MENU_OPTION_INDEX_3:
							break;
						case MENU_OPTION_INDEX_4:
							break;
						case MENU_OPTION_INDEX_5:
							break;
						case MENU_OPTION_INDEX_6:
							break;
						case MENU_OPTION_INDEX_7:
							break;
						case MENU_OPTION_INDEX_8:
							break;
						case MENU_OPTION_INDEX_9:
							break;
						case MENU_OPTION_INDEX_10:
							break;
						case MENU_OPTION_INDEX_11:
							break;
						case MENU_OPTION_INDEX_12:
							break;
						case MENU_OPTION_INDEX_13:
							break;
						}
						break;
						case MENU_LEVEL_6:
							switch(getMenuOptionIndex())	{
							case MENU_OPTION_INDEX_0:
								break;
							case MENU_OPTION_INDEX_1:
								break;
							case MENU_OPTION_INDEX_2:
								break;
							case MENU_OPTION_INDEX_3:
								break;
							case MENU_OPTION_INDEX_4:
								break;
							case MENU_OPTION_INDEX_5:
								break;
							case MENU_OPTION_INDEX_6:
								break;
							case MENU_OPTION_INDEX_7:
								break;
							case MENU_OPTION_INDEX_8:
								break;
							case MENU_OPTION_INDEX_9:
								break;
							case MENU_OPTION_INDEX_10:
								break;
							case MENU_OPTION_INDEX_11:
								break;
							case MENU_OPTION_INDEX_12:
								break;
							case MENU_OPTION_INDEX_13:
								break;
							}
							break;
							case MENU_LEVEL_7:
								switch(getMenuOptionIndex())	{
								case MENU_OPTION_INDEX_0:
									break;
								case MENU_OPTION_INDEX_1:
									break;
								case MENU_OPTION_INDEX_2:
									break;
								case MENU_OPTION_INDEX_3:
									break;
								case MENU_OPTION_INDEX_4:
									break;
								case MENU_OPTION_INDEX_5:
									break;
								case MENU_OPTION_INDEX_6:
									break;
								case MENU_OPTION_INDEX_7:
									break;
								case MENU_OPTION_INDEX_8:
									break;
								case MENU_OPTION_INDEX_9:
									break;
								case MENU_OPTION_INDEX_10:
									break;
								case MENU_OPTION_INDEX_11:
									break;
								case MENU_OPTION_INDEX_12:
									break;
								case MENU_OPTION_INDEX_13:
									break;
								}
								break;
								case MENU_LEVEL_8:
									switch(getMenuOptionIndex())	{
									case MENU_OPTION_INDEX_0:
										break;
									case MENU_OPTION_INDEX_1:
										break;
									case MENU_OPTION_INDEX_2:
										break;
									case MENU_OPTION_INDEX_3:
										break;
									case MENU_OPTION_INDEX_4:
										break;
									case MENU_OPTION_INDEX_5:
										break;
									case MENU_OPTION_INDEX_6:
										break;
									case MENU_OPTION_INDEX_7:
										break;
									case MENU_OPTION_INDEX_8:
										break;
									case MENU_OPTION_INDEX_9:
										break;
									case MENU_OPTION_INDEX_10:
										break;
									case MENU_OPTION_INDEX_11:
										break;
									case MENU_OPTION_INDEX_12:
										break;
									case MENU_OPTION_INDEX_13:
										break;
									}
									break;
									case MENU_LEVEL_9:
										switch(getMenuOptionIndex())	{
										case MENU_OPTION_INDEX_0:
											break;
										case MENU_OPTION_INDEX_1:
											break;
										case MENU_OPTION_INDEX_2:
											break;
										case MENU_OPTION_INDEX_3:
											break;
										case MENU_OPTION_INDEX_4:
											break;
										case MENU_OPTION_INDEX_5:
											break;
										case MENU_OPTION_INDEX_6:
											break;
										case MENU_OPTION_INDEX_7:
											break;
										case MENU_OPTION_INDEX_8:
											break;
										case MENU_OPTION_INDEX_9:
											break;
										case MENU_OPTION_INDEX_10:
											break;
										case MENU_OPTION_INDEX_11:
											break;
										case MENU_OPTION_INDEX_12:
											break;
										case MENU_OPTION_INDEX_13:
											break;
										}
										break;
	}
}
 *
 *
 */
