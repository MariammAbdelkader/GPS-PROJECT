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
