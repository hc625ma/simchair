  //version 1.1
#include "UnoJoy.h"

uint8_t x_min = 0;
uint8_t y_min = 0;
uint16_t x_max = 1000;
uint16_t y_max = 1001;

uint16_t x_center = 374;
uint16_t y_center = 612;

const bool CALIBRATION = 0; 
  // set to 1 to calibrate cyclic, put the centering bracket on the cyclic, 
  // write center values to x_center and y_center variables. After that, remove the bracket and write minimums and maximums of both axes.
  // Set DEBUG to 1, upload the sketch again and test yor results. Output should be in range from 0 to 1023 and center values of axes 
  // should be more or less equal.
const bool DEBUG =  0; // set this to 1 to see calibration results through com port, DISABLE THIS FOR NORMAL OPERATION

void setup()
{
  setupUnoJoy();
}

void loop()
{
  // Always be getting fresh data  
  dataForController_t controllerData = getControllerData();
  setControllerData(controllerData);
  if (CALIBRATION) { calibration(controllerData); }
  
}

void calibration (dataForController_t controllerData)
{
  while(1)
  {
     controllerData.leftStickX = filteredRead(A1,20);
     delay(1);
     controllerData.leftStickY = filteredRead(A0,20);
     Serial.print("CALIBRATION X: ");
     Serial.print(controllerData.leftStickX);
     Serial.print(" ");
     Serial.print("CALIBRATION Y: ");
     Serial.println(controllerData.leftStickY);
     
  }
}

uint16_t invert (uint16_t val)
{
  val = 1023-val;
  return val;
}

uint16_t filteredRead (uint16_t input,uint8_t filter_counter)
{
  uint32_t filter = 0;
  for (uint8_t i=0;i<filter_counter;i++)
  {
    
      filter+= analogRead(input);
      delay(1); 
  }

  uint16_t val = filter/filter_counter;
  return val;
  
}

uint16_t calibrate (int16_t val, int8_t MIN, int16_t MAX, int16_t CENTER)
{
  int16_t correction = 512 - CENTER;
  int16_t x_corr = abs(512 - x_center);
  int16_t y_corr = abs(512 - y_center);

  int16_t max_correction = max(x_corr,y_corr);
  int16_t cal_max = MAX - (max_correction);
  int16_t cal_min = MIN + (max_correction);

  val+=correction;
  val = constrain(val,cal_min,cal_max);
  val = map(val,cal_min,cal_max,0,1023);
  
  return val;
}

dataForController_t getControllerData(void){

  //  Set up a place for our controller data
  //  Use the getBlankDataForController() function, since
  //  just declaring a fresh dataForController_t tends
  //  to get you one filled with junk from other, random
  //  values that were in those memory locations before
  
  dataForController_t controllerData = getBlankDataForController();
  
  //  Because of unrelable serial port communication between 16u2 and 328p, noise spikes occur.
  //  Filtering is added on the 16u2 side to prevent this, but filtering induces lag. It shouldnt be noticeable with 3 axes.
  //  Some basic sensors filtering greatly improves flying experience, adjust filter_counter value to your liking!
  //  6 is a great default to start with.

  uint8_t filter_counter_x = 6;
  uint8_t filter_counter_y = 6;
  uint8_t filter_counter_z = 6; //pedals tend to be more noisy due to physical loads they take
  uint8_t filter_counter_rz = 2;
  uint8_t filter_counter_dial = 2;
  uint8_t filter_counter_slider = 2;

  //First 3 axes have 10 bit resolution, good for cyclic and pedals 
  controllerData.leftStickX = invert(calibrate(filteredRead(A1,filter_counter_x),x_min,x_max,x_center)); // read analog input, apply filters, apply offset, adjust range and invert axis
  controllerData.leftStickY = calibrate(filteredRead(A0,filter_counter_y),y_min,y_max,y_center);
  controllerData.rightStickX = filteredRead(A5,filter_counter_z);

  if (DEBUG)
  {
     Serial.print("X: ");
     Serial.print(controllerData.leftStickX);
     Serial.print(" ");
     Serial.print("Y: ");
     Serial.println(controllerData.leftStickY);
  }
  //  These axes have 8 bit resolution, enough for everything else
  //  Since analogRead(pin) returns a 10 bit value,
  //  we need to perform a bit shift operation to
  //  lose the 2 least significant bits and get an
  //  8 bit number that we can use  
  controllerData.rightStickY = filteredRead(A3,filter_counter_rz) >> 2;
  controllerData.dial = filteredRead(A2,filter_counter_dial) >> 2;
  controllerData.slider = filteredRead(A4,filter_counter_slider) >> 2;
  //And return the data!
  return controllerData;

}
