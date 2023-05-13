#include "GPS.h"
#include <math.h>
#include <string.h>
#include "UART.h"
#include <stdbool.h>
#include <stdlib.h>
//float lattx,longx;

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

  
/*void GPS_Read(){
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


}*/
  
  void GPS_Read(){
    //char i=0;
    char flag=1;
    char receivedChar;
       check();
     while (1)
         {

             if(flag){
    receivedChar =  UART5_RecieveChar();

    if(receivedChar==',')
    {
        c++;
    }
}
switch(c){



    case 1: valid= UART5_RecieveChar();
         break;
    case 2: UART5_ReceiveString(lattA_recieve,','); c++; flag=0;
         break;
    case 3: NS=  UART5_RecieveChar(); flag=1;
         break;
    case 4: UART5_ReceiveString(longA_recieve,','); c++; flag=0;
         break;
    case 5: EW= UART5_RecieveChar(); flag=1;
         break;
    case 6: UART5_ReceiveString(speed,','); c++; flag=0;
         break;
}
    if(c==7) break;
}

            if(valid=='A'){

        //if (NS == "N" ))

        lattA= atof(lattA_recieve);
        //else
            //lattA = -  atof(lattA_recieve);

            //if (EW=="E" )

    longA= atof(longA_recieve);
    //  else
    //  longA= -  atof(longA_recieve);
    //



    }
  }

  
 /*void edit_coor(){

char no_Token=0;
    token= strtok(GPS, ",");

    do{
        strcpy(GPS_final[no_Token],token);
        token=strtok(NULL,",");
        no_Token++;
    } while(token!=NULL);

    if(strcmp(GPS_final[1],"A")==0){

        if (strcmp(GPS_final[3], "N" )==0)

    lattA= atof(GPS_final[2]);
        else
            lattA= -  atof(GPS_final[2]);

            if (strcmp(GPS_final[5], "E" )==0)

   longA= atof(GPS_final[4]);
        else
      longA= -  atof(GPS_final[4]);
    }

    lattx=lattA;
    longx=longA;

}*/
