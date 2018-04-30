


#ifndef __MY_SHARP_SENSOR__
#define __MY_SHARP_SENSOR__


Servo LWheel, RWheel;
//this function takes as input the value obtained by a short distance sensor,
//and it should return its respective value in inches
float shortToInches(int value) {
  float inches;
  inches =  1359.649606 * pow(value, -1.055966 ) ;
  return inches;
}

//this function takes as input the value obtained by the long distance sensor,
//and it should return its respective value in inches
float longToInches(int value) {
  float inches;
  inches = 4192.936 * pow(value, -0.935) - 3.937;
  return inches;
}


//the following two functions are meant for combining (taking the mean, median or etc) multiple measurements

//this function should read and store a new measurement taken with sensor given by the parameter 'sensor'
#define SLEFT   0
#define SSFRONT 1
#define SRIGHT  2
#define SLONG   3
float measureLong[10];
float measureR[10];
float measureL[10];
float measureF[10];



int a = 0, b = 0, c = 0, d = 0;
float in;
void insertionsort(float* data, int size) {
  float temp;
  int j;
 for (int i = 0; i < size; i++)
  {
   j = i;
    while (j > 0 && (data[j] < data[j - 1]))
   {
      temp = data[j];
      data[j] = data[j - 1];
     data[j - 1] = temp;
    j--;
    }
  }
}
void takeNewMaeasurement  (int sensor) {
  if ( sensor == 0) {
    float SensorValue = analogRead(A3);
    in = shortToInches (SensorValue);
    Serial.println(in);
    measureL [a] = in;
    a++;
  }
  else if ( sensor == 1) {
    float SensorValue = analogRead(A0);
    in = shortToInches (SensorValue);
   // Serial.println(in);

    measureF [b] = in;
    b++;
  } else if ( sensor == 2) {
    float SensorValue = analogRead(A2);
    in = shortToInches(SensorValue);
    measureR [c] = in;
    c++;
  }
  else if (sensor == 3) {
    float SensorValue = analogRead(A3);
    in = longToInches(SensorValue);
    measureLong [d] = in;
    d++;
  }

}


//this function should combine the last N measurement taken with sensor 'sensor' and return the result.
//You are free to chose the value of N

float getCombinedDistance  (int sensor) {
  float value;
  if ( sensor == 0) {
   insertionsort(measureL, 5 );
    value = measureL [2] ;
    return value;
  }
  else if ( sensor == 1) {
    insertionsort(measureF, 5 );
    value = measureF [2] ;
    return value;
  } else if ( sensor == 2) {
    insertionsort(measureR, 5 );
    value = measureR [2] ;
    return value;
  }
  else if (sensor == 3) {
    insertionsort(measureLong, 5 );
    value = measureLong [2] ;
    return value;
}
}


#endif

