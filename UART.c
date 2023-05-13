#include "tm4c123gh6pm.h"
#include "edit_bit.h"
#include <string.h>
#include <stdint.h>

//UART0 initialization

void UART0_Init(void){

    SYSCTL_RCGCUART_R |= 0x0001;        //activate uart0
    
    SYSCTL_RCGCGPIO_R |= 0x0001;        //activate portA
    while ((SYSCTL_PRGPIO_R & 0x0001) == 0) {};
    UART0_CTL_R &= ~0x0001;

    //Set the baudrate
    UART0_IBRD_R = 104;     //int(16M /(16*9600) )
    UART0_FBRD_R = 11;      //int (0.1667*64+0.5)

    UART0_LCRH_R = 0x0070;      //8bit word length and enbale fifo
    UART0_CTL_R = 0x0301;           //enable RXE,TXE,UART

    GPIO_PORTA_DEN_R |= 0x03;       //enable digital pins
    GPIO_PORTA_AMSEL_R &= ~0x03;     //disable analog
    GPIO_PORTA_AFSEL_R |= 0x03;     //disable alternate functions
    GPIO_PORTA_PCTL_R |= 0x00000011;


}
