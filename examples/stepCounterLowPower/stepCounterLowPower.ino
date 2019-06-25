/*!
  * lowPowerAndWakeUp.ino
  *
  * I2C addr:
  *   0x68: connect SDIO pin of the BMX160 to GND which means the default I2C address
  *   0x69: set I2C address by parameter
  *
  * Through the example, you can get the sensor data which means step counter.
  * set step counter power mode by setStepPowerMode(stepNormalPowerMode means normal model,stepLowPowerMode means low power model)
  * upload interrupt number by setInt (choose int1 or int2)  
  * data from int1 and int2 read in readStepCounter
  *
  * Copyright   [DFRobot](http://www.dfrobot.com), 2016
  * Copyright   GNU Lesser General Public License
  *
  * version  V1.0
  * date  2017-11-27
  */

#include <DFRobot_BMX160.h>

DFRobot_BMX160 bmx160;

void setup(){
  Serial.begin(115200);
  delay(100);
  
  //init the hardware bmin160  
  if (bmx160.begin() != true){
    Serial.println("init false");
    while(1);
  }
  bmx160.setLowPower();

}

void loop(){
}


