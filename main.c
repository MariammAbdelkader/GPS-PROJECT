#include <math.h>
#include <stdlib.h>
#include "GPS.h"
#include "tm4c123gh6pm.h"
#include "GPIO.h"
#include "UART.h"
#include "Systick.h"
#include <string.h>
#include <stdio.h>
#include "GPIO.h"
#include "GPS.h"
#include "UART.h"
extern double lattA,longA;
double lattB=30.063447,longB=31.279826;
//float total_distance=0;
double distance=0;
   //char d;
//extern float lattx,longx,lattA,longA;

#include <stdio.h>
#include <string.h>
/****************to read distance on serial*************************/
/*
char globalArray[100];

void doubleToString(double value) {
    int integerPart = (int)value;
    double decimalPart = value - integerPart;
    int index = 0;
    int i;

    // Convert the integer part to string
    while (integerPart > 0) {
        globalArray[index++] = '0' + integerPart % 10;
        integerPart /= 10;
    }

    // Reverse the string
    for ( i = 0; i < index / 2; i++) {
        char temp = globalArray[i];
        globalArray[i] = globalArray[index - i - 1];
        globalArray[index - i - 1] = temp;
    }

    // Add the decimal point
    globalArray[index++] = '.';

    // Convert the decimal part to string
    for ( i = 0; i < 6; i++) {
        decimalPart *= 10;
        int digit = (int)decimalPart;
        globalArray[index++] = '0' + digit;
        decimalPart -= digit;
    }

    // Add the null terminator
    globalArray[index] = '\0';
}


*/

int main(){
//int i=0;

 
    GPIOF_Init();
    UART0_Init();
    UART5_Init();
 // edit_coor(); (to calc total distance)


while (1){

      GPS_Read();

      //doubleToString(distance);
       // printf("%s\n", globalArray);

   distance = GPS_getdistance( toDegree(longA), toDegree (lattA), longB,  lattB);
    
    //total_distance +=  GPS_getdistance(lattx,longx,lattA,longA);
    // edit_coor(); (to calc total distance)
    //void NumSplit( double counted)

     LED_Conditions(distance);



}
}