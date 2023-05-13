#include "SevenSegment.h"
#include "GPIO.h"
#include "math.h"
#include "tm4c123gh6pm.h"
unsigned digit1,digit2,digit3 ;
 
 static unsigned char sevenSegmentArray[10] ={0x3F,0x6,0x5B,0x4F,0x66,0x6D,0x7D,0x27,0x7F,0x6F};
 
void SevenSegment_Set (unsigned char value_SevenSegment){
	GPIO_PORTC_set( sevenSegmentArray[value_SevenSegment]);
}

void NumSplit( double counted){
	int count =(int)counted;
	digit1 = count%10;	    //Copies value in counter, divides it by 10 and then keeps remainder
    count /= 10;	       //Dividing value in counter by 10 shifts it by one decimal
    digit2 = count%10;
    count /= 10;
    digit3 = count%10;
    count /= 10;
    
}

void Display(int digit, char number){
	GPIO_PORTC_DATA_R = 0x00;							// Turns off LEDs
	GPIO_PORTE_DATA_R = digit;						// Selects digit
	GPIO_PORTB_DATA_R = sevenSegmentArray[number];	// Turns on number in selected digit


    }



	 void Delay2(void){
	unsigned long volatile time;
	time = 727240*200/91000;  // 0.1 ms
  while(time){
			time--;
  } 
}
