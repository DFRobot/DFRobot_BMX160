 /*!
  * file setLowPower.ino
  *
  * Through the example disable or enable the gyroscope and accelerometer sensor.
  * 
  * With the rotation of the sensor, data changes are visible.
  *
  * Copyright   [DFRobot](http://www.dfrobot.com), 2016
  * Copyright   GNU Lesser General Public License
  *
  * version  V0.1
  * date  2019-6-25
  */

#include <DFRobot_BMX160.h>

DFRobot_BMX160 bmx160;
void setup(){
  Serial.begin(115200);
  delay(100);
  
  //init the hardware bmx160  
  if (bmx160.begin() != true){
    Serial.println("init false");
    while(1);
  }
  bmx160.setLowPower();   //disable the gyroscope and accelerometer sensor
  //bmx160.wakeUp();        //enable the gyroscope and accelerometer sensor
  //bmx160.softReset();     //reset the sensor
  
  delay(100);
}

void loop(){


  delay(500);
}










