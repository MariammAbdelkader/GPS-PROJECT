#include "tm4c123gh6pm.h"
void Systick_wait (unsigned int delay){
	NVIC_ST_CTRL_R = 0x0;
	NVIC_ST_RELOAD_R = delay-1;
	NVIC_ST_CURRENT_R =0;
	NVIC_ST_CTRL_R = 0x05;
	while ((NVIC_ST_CTRL_R & 0x10000)==0);
	}
