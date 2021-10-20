/*!
 * @file readGyroData.ino
 * @brief Through the example, you can get the sensor data by using getAllData:
 * @n     get gyroscope data of sensor.
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
   * enum{eGyroRange_2000DPS,
   *      eGyroRange_1000DPS,
   *      eGyroRange_500DPS,
   *      eGyroRange_250DPS,
   *      eGyroRange_125DPS
   *      }eGyroRange_t;
   */
  //bmx160.setGyroRange(eGyroRange_500DPS);
  
  delay(100);
}

void loop(){
  sBmx160SensorData_t Ogyro;

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










