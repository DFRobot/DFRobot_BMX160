 /*!
  * file readMagnData.ino
  *
  * Through the example, you can get the sensor data by using getSensorData:
  * get magnetometer data of sensor.
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
  delay(100);
}

void loop(){
  bmx160SensorData Omagn;

  /* Get a new sensor event */
  bmx160.getAllData(&Omagn, NULL, NULL);

  /* Display the magnetometer results (magn is magnetometer in uTesla) */
  Serial.print("Magn ");
  Serial.print("X: "); Serial.print(Omagn.x); Serial.print("  ");
  Serial.print("Y: "); Serial.print(Omagn.y); Serial.print("  ");
  Serial.print("Z: "); Serial.print(Omagn.z); Serial.print("  ");
  Serial.println("uT");

  Serial.println("");

  delay(500);
}










