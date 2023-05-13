#include "tm4c123gh6pm.h"
#include "GPIO.h"
#include "edit_bit.h"

// Intialize PORTF "LEDs ,Switches"
void GPIOF_Init(){
	     set_bit(SYSCTL_RCGCGPIO_R,5);              //Activate clock for port F
	while (get_bit(SYSCTL_PRGPIO_R,5)==0){};	    //Delay
				GPIO_PORTF_LOCK_R = 0x4C4F434B  ;       //Unlock GPIO port F
        GPIO_PORTF_CR_R=0x1F;                  //Allow changes to PF4-PF0
				GPIO_PORTF_AMSEL_R = 0x00;           // Disable analog function
				GPIO_PORTF_AFSEL_R = 0x00;          //no alternative function
				GPIO_PORTF_PCTL_R = 0x00000000;         // no alternative function
				GPIO_PORTF_DIR_R =0x0E;           // PF0,PF4 in,PF3-PF1 out
				GPIO_PORTF_DEN_R =0x1F;          // Digital I/O on PF4-PF0
				GPIO_PORTF_DATA_R &= ~0x0E;      //Intializes the LEDs to be off
		    GPIO_PORTF_PUR_R = 0x11;        //specifiy pull up resistance for PF4,PF0
}   
