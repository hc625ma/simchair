#include "UnoJoy.h"
int i = 0;
int g = 0;
bool rising = true;
bool g_rising = true;
void setup(){
 // setupPins();
  setupUnoJoy();
}

void loop(){
  // Always be getting fresh data
  dataForController_t controllerData = getControllerData();
  setControllerData(controllerData);
}

void setupPins(void){
  // Set all the digital pins as inputs
  // with the pull-up enabled, except for the 
  // two serial line pins
  for (int i = 2; i <= 12; i++){
    pinMode(i, INPUT);
    digitalWrite(i, HIGH);
  }
}


dataForController_t getControllerData(void){
  int k = 20;
  int j = 50;
  //Serial.println(g/j);
  if ((i/k < 1023) && (rising))
  {
    i++;
    
  }
  else if (i/k > 0) 
  {
    i--;
    rising = false;
  }
  else
  {
    rising = true;
  }

  if ((g/j < 255) && (g_rising))
  {
    g++;
    
  }
  else if (g/j > 0) 
  {
    g--;
    g_rising = false;
  }
  else
  {
    g_rising = true;
  }
  // Set up a place for our controller data
  //  Use the getBlankDataForController() function, since
  //  just declaring a fresh dataForController_t tends
  //  to get you one filled with junk from other, random
  //  values that were in those memory locations before
  dataForController_t controllerData = getBlankDataForController();
  // Since our buttons are all held high and
  //  pulled low when pressed, we use the "!"
  //  operator to invert the readings from the pins


 
  // Set the analog sticks
  //  Since analogRead(pin) returns a 10 bit value,
  //  we need to perform a bit shift operation to
  //  lose the 2 least significant bits and get an
  //  8 bit number that we can use  
  
 
  //Serial.print(millis()/k);
  controllerData.leftStickX = i/k;//analogRead(A1);
  controllerData.leftStickY = i/k;//analogRead(A0);
  controllerData.rightStickX = i/k;//analogRead(A5);
  controllerData.rightStickY = g/j;//analogRead(A3);
  controllerData.dial = g/j;//analogRead(A2);
  controllerData.slider = g/j;//analogRead(A4);
  // And return the data!
  return controllerData;
}
