#include "hmi_api.h"

void setApiValue()	{
	// Speedometer
	if((get_speedometer_value() >= MIN_SPEEDOMETERVALUE) && (get_speedometer_value() <= MAX_SPEEDOMETERVALUE))
		setSpeed(get_speedometer_value());

	// Ride Mode
	if((get_ridemode_value() >= RM_ERROR) && (get_ridemode_value() <= RM_POWER))
		setRideMode(get_ridemode_value());

	// Battery Percentage
	if((get_battery_value() >= MIN_BATTERYPERCENTAGE) && (get_battery_value() <= MAX_BATTERYPERCENTAGE))
		setBatteryPercentage(get_battery_value());

	// Odometer Value
	if((get_odometer_value() >= MIN_ODOMETERVALUE) && (get_odometer_value() <= MAX_ODOMETERVALUE))
		setOdometerValue(get_odometer_value());

	// AdaptiveHeadlamp
	if((get_adaptivelamp_value() >= AH_LEVEL0) && (get_adaptivelamp_value() <= AH_OFF))
		setAdaptiveHeadLampValue(get_adaptivelamp_value());

	// DRL
	if((get_DRL_value() >= DRL_OFF) && (get_DRL_value() <= DRL_AUTOMATIC))
		setDRLValue(get_DRL_value());

	// DRL
	if((get_tractioncontrol_value() >= TC_OFF) && (get_tractioncontrol_value() <= TC_AUTOMATIC))
		setTractionControlValue(get_tractioncontrol_value());

	// Quick Shifter
	if((get_quickshifter_value() >= QS_OFF) && (get_quickshifter_value() <= QS_AUTOMATIC))
		setQuickShifterValue(get_quickshifter_value());

	// Cruise Control
	if((get_cruise_value() >= CC_RESET) && (get_cruise_value() <= CC_SET))
		setCruiseControlValue(get_cruise_value());

	// Gear Indicators
	if((get_gearposition_value() >= GEAR_NEUTRAL) && (get_gearposition_value() <= GEAR_INVALID))
		setGearShiftIndicator(get_gearposition_value(), get_gearindicator_value());
}
