#include "fsl_debug_console.h"
#include "clock_config.h"
#include "board.h"
#include "fsl_snvs_hp.h"
#include "fsl_snvs_lp.h"

void RtcInit();
void RtcApp();
void setHour(uint8_t hr);
void setMinute(uint8_t min);
void setSecond(uint8_t sec);
uint8_t getHour();
uint8_t getMinute();
uint8_t getSecond();
