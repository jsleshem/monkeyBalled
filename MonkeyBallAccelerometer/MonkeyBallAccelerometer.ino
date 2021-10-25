#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <Adafruit_MMA8451.h>

Adafruit_MMA8451 mma = Adafruit_MMA8451();
int pauseCount = 0;

void setup(void) {
  Serial.begin(9600);

  //Accelerometer Setup
  if (!mma.begin()) {
    Serial.println("Couldnt start");
    while (1);
  }
  Serial.println("MMA8451 found!");
  mma.setRange(MMA8451_RANGE_2_G);
  
}

void loop() {
  // Accelerometer - mma.x, mma.y, mma.z
  //Range: 2000 to - 2000
  mma.read();
  int xPos = mma.x * -1;
  int yPos = mma.y * -1;
  int zPos = mma.z * 1;

  writeAnalogStick(xPos, yPos, zPos);
  
  //Pausing - Shake to pause, prevents multiple trips
  bool pausable = canPause();
  if (mma.z < 0 && pausable) {
    //TODO Press Start
    pauseCount = 0;
  }
   
  //Take inputs 10 times a second
  delay(100);
}

bool canPause() {
  if (pauseCount > 10) {
    return true; 
  }
  else {
    pauseCount ++; 
    return false;
  }
}

void writeAnalogStick(int xPos, int yPos, int zPos) {
  long modifiedXPos = xPos + 2000;
  long modifiedYPos = yPos + 2000;

  modifiedXPos *= 8;
  modifiedYPos *= 8;

  // if joystick is in deadzone
  if ((modifiedXPos < 20000 && modifiedXPos > 14000)) {
      modifiedXPos = 32768/2;
  }
   if ((modifiedYPos < 20000 && modifiedYPos > 14000)) {
      modifiedYPos = 32768/2;
  }

  // if joystick is above max
  if (modifiedXPos > 32000) {
    modifiedXPos = 32766;
  }
  if (modifiedYPos > 32000) {
    modifiedYPos = 32766;
  }

  // if joystick is below min
  if (modifiedXPos < 0) {
    modifiedXPos = 1;
  }
  if (modifiedYPos < 0) {
    modifiedYPos = 1;
  }

 Serial.println("x" + String(modifiedXPos) + "|y" + String(modifiedYPos) + "~");
}
