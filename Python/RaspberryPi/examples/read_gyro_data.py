'''
file read_all_data.py

Through the example, you can get the sensor data by using getAllData:
get gyroscope data of sensor.

With the rotation of the sensor, data changes are visible..

Copyright   [DFRobot](http://www.dfrobot.com), 2016
Copyright   GNU Lesser General Public License

version  V1.0
date  2019-7-9
'''
import sys
sys.path.append('../')
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