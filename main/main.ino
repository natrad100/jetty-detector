/**************************************************************************/
/*!
    @file     Adafruit_MMA8451.h
    @author   K. Townsend (Adafruit Industries)
    @license  BSD (see license.txt)

    This is an example for the Adafruit MMA8451 Accel breakout board
    ----> https://www.adafruit.com/products/2019

    Adafruit invests time and resources providing this open source code,
    please support Adafruit and open-source hardware by purchasing
    products from Adafruit!

    @section  HISTORY

    v1.0  - First release
*/
/**************************************************************************/

#include <Wire.h>
#include <Adafruit_MMA8451.h>
#include <Adafruit_Sensor.h>

Adafruit_MMA8451 mma = Adafruit_MMA8451();


// Create a space in memory for current reading
gyroReading currentReading

void setup(void) {
  Serial.begin(9600);
  
  Serial.println("Adafruit MMA8451 test!");
  

  if (! mma.begin()) {
    Serial.println("Couldnt start");
    while (1);
  }
  Serial.println("MMA8451 found!");
  
  mma.setRange(MMA8451_RANGE_2_G);
  
  Serial.print("Range = "); Serial.print(2 << mma.getRange());  
  Serial.println("G");

  
  
}

void loop() {
  
  getData(currentReading)
  
}

class gyroReading{
  public:
    float x = 0;
    float y = 0;
    float z = 0;
    float ax = 0;
    float ay = 0;
    float az = 0;
}


int getData(gyroReading nextReading){
  // trigger reading
  mma.read();
  sensors_event_t event; 
  mma.getEvent(&event);
  gyroReading.x = mma.x;
  gyroReading.y = mma.y;
  gyroReading.z = mma.z;
  gyroReading.ax =  event.acceleration.x;
  gyroReading.ay = event.acceleration.y;
  gyroReading.az = event.acceleration.z;

}

int writeToSDCard( gyroReading myReading ){
  rowString = {String(myReading.x_}
}