 /*!
  * file readGyroData.ino
  *
  * Through the example, you can get the sensor data by using getAllData:
  * get gyroscope data of sensor.
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
  
  /** @typedef enum{eGyroRange_2000DPS,
   *                eGyroRange_1000DPS,
   *                eGyroRange_500DPS,
   *                eGyroRange_250DPS,
   *                eGyroRange_125DPS
   *                }eGyroRange_t;
   **/
  //bmx160.setGyroRange(eGyroRange_500DPS);
  
  delay(100);
}

void loop(){
  bmx160SensorData Ogyro;

  /* Get a new sensor event */
  bmx160.getAllData(NULL, &Ogyro, NULL);


  /* Display the gyroscope results (gyroscope data is in g) */
  Serial.print("G ");
  Serial.print("X: "); Serial.print(Ogyro.x); Serial.print("  ");
  Serial.print("Y: "); Serial.print(Ogyro.y); Serial.print("  ");
  Serial.print("Z: "); Serial.print(Ogyro.z); Serial.print("  ");
  Serial.println("g");

  Serial.println("");

  delay(500);
}










