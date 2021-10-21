'''!
  @file read_gyro_data.py
  @brief Through the example, you can get the sensor data by using getAllData:
  @n     get gyroscope data of sensor.
  @n     With the rotation of the sensor, data changes are visible.
  @copyright	Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
  @license     The MIT License (MIT)
  @author [luoyufeng] (yufeng.luo@dfrobot.com)
  @maintainer [Fary](feng.yang@dfrobot.com)
  @version  V1.0
  @date  2021-10-20
  @url https://github.com/DFRobot/DFRobot_BMX160
'''
import sys
sys.path.append('../../')
import time
from DFRobot_BMX160 import BMX160

bmx = BMX160(1)

#begin return True if succeed, otherwise return False
while not bmx.begin():
    time.sleep(2)
  
'''
GyroRange_2000DPS
GyroRange_1000DPS
GyroRange_500DPS
GyroRange_250DPS
GyroRange_125DPS
'''
bmx.set_gyro_range(bmx.GyroRange_500DPS)

time.sleep(0.1)


def main():
    while True:
        data= bmx.get_all_data()
        time.sleep(1)
        print("gyro  x: {0:.2f} g, y: {1:.2f} g, z: {2:.2f} g".format(data[3],data[4],data[5]))
        print(" ")

if __name__ == "__main__":
    main()