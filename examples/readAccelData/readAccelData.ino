/*!
 * @file readAccelData.ino
 * @brief Through the example, you can get the sensor data by using getAllData:
 * @n     get accelerometer data of sensor.
 * @n     With the rotation of the sensor, data changes are visible.
 * @copyright	Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author [luoyufeng] (yufeng.luo@dfrobot.com)
 * @maintainer [Fary](feng.yang@dfrobot.com)
 * @version  V1.0
 * @date  2021-10-20
 * @url https://github.com/DFRobot/DFRobot_BMX160
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
  
  /** 
   *  enum{eAccelRange_2G,
   *        eAccelRange_4G,
   *        eAccelRange_8G,
   *        eAccelRange_16G
   *        }eAccelRange_t;
   */
  //bmx160.setAccelRange(eAccelRange_4G);
  delay(100);
}

void loop(){
  sBmx160SensorData_t  Oaccel;

  /* Get a new sensor event */
  bmx160.getAllData(NULL, NULL, &Oaccel);
  
  /* Display the accelerometer results (accelerometer data is in m/s^2) */
  Serial.print("Accel ");
  Serial.print("X: "); Serial.print(Oaccel.x    ); Serial.print("  ");
  Serial.print("Y: "); Serial.print(Oaccel.y    ); Serial.print("  ");
  Serial.print("Z: "); Serial.print(Oaccel.z    ); Serial.print("  ");
  Serial.println("m/s^2");

  Serial.println("");

  delay(500);
}
