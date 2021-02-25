// Jetty Detector
//    Detector of movement using Arduino and basic accelerometer

#include <Wire.h>
#include <Adafruit_MMA8451.h>
#include <Adafruit_Sensor.h>

Adafruit_MMA8451 mma = Adafruit_MMA8451();


// Create a space in memory for current reading
gyroReading currentReading

void setup(void) {

  // Init Serial
  Serial.begin(9600);
  Serial.println("Starting....");


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
  
  // Get data
  while!(getData(currentReading))

  // Write to SD Card
  while!(writeToSDCard())
}

// gyroReading_c
// This outlines structure for data aquisition
class gyroReading{
  public:
    float x = 0;
    float y = 0;
    float z = 0;
    float ax = 0;
    float ay = 0;
    float az = 0;
}

// getData
// Uses mma library to get data and store in gyroReading
// Utilises pointers so only returns finish.
int getData(gyroReading *nextReading){
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

  return 1;
}

int writeToSDCard( gyroReading myReading ){
  rowString = {String(myReading.x_}

  return 1;
}