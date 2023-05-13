#include "GPS.h"
#include <math.h>
#include <string.h>
#include "UART.h"
#include <stdbool.h>
#include <stdlib.h>


#define PI 3.1415926535
#define Earth_radius 6371000;
char GPS[80];
char GPS_Logname[]= "$GPRMC,";
char GPS_final [10][20];
char * token;
double longA,lattA, lattfA,longfA ;
char c,valid,EW,NS;
  char longA_recieve[15],lattA_recieve[15],speed[15];

double GPS_getdistance(double longA, double lattA, double longB, double lattB){
    //calculating Radian angle for the parameters
double longA_Rad= toRad(longA);
double lattA_Rad=toRad(lattA);
double longB_Rad=toRad(longB);
double lattB_Rad=toRad(lattB);

//Get Difference
    double longdiff= longB_Rad -  longA_Rad;
    double lattdiff= lattB_Rad -  lattA_Rad;


//calc distance
    // another way: d= 3440.1 arccos[(sin(lattA_Rad)*sin (lattB_Rad)) + cos(lattA_Rad)*cos(longA_Rad -longB_Rad)

//Haversine formula
float a= pow(sin(lattdiff/2),2)+cos(lattA_Rad)*cos(lattB_Rad)*pow(sin(longdiff/2),2);
double c= 2*atan2(sqrt(a),sqrt(1-a));
return 6371000*c;
}

void check(){
    char i=0;
     do{
 while( UART5_RecieveChar ()!= GPS_Logname[i]);
    i++;
}while(i!=6);
    
    double toDegree(double angle){
    int degree = (int)angle/100 ;
     double minutes = angle -(double)degree*100;
        return (degree+(minutes/60)) ;
}


double toRad(double angle){

    return angle* (PI/180.0);
}

  
void GPS_Read(){
char receivedChar;
    char i=0;


do{
 while( UART0_ReadChar()!= GPS_Logname[i]);
    i++;
}while(i!=6);


strcpy(GPS, "")


do{
    char GPScount=0;
    receivedChar = UART0_ReadChar();
    GPS[GPScount++]= receivedChar;
} while(receivedChar != '*');
}

void GPS_final(){

    char no_Token=0;
    token= strtok(GPS, ",");

    do{
        strcpy(GPS_final[no_Token],token);
        token=strtok(NULL,",");
        no_Token++;
    } while(token!=NULL);

    if(strcmp(GPS_final[1],"A")==0){

        if (strcmp(GPS_final[3], "N" )==0)

        currentlatt= atof(Gps_final[2]);
        else
            currentlatt= -  atof(Gps_final[2]);

            if (strcmp(GPS_final[5], "E" )==0)

        currentlong= atof(Gps_final[4]);
        else
            currentlong= -  atof(Gps_final[4]);
    }
}



}
