'''
  @file set_low_power.py
  @brief Through the example disable or enable the gyroscope and accelerometer sensor.
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
Revise the following two paramters according to actula reading of the INA219 and the multimeter
for linearly calibration
'''
bmx.set_low_power();   #disable the gyro and accel sensor
#bmx.wake_up();        #enable the gyro and accel sensor
#bmx.soft_reset();     #reset the sensor

time.sleep(0.1)


def main():
    while True:
        time.sleep(1)

if __name__ == "__main__":
    main()