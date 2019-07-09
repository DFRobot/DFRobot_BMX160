'''
file read_all_data.py

Through the example, you can get the sensor data by using getAllData:
get accelerometer data of sensor.

With the rotation of the sensor, data changes are visible.

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
AccelRange_2G
AccelRange_4G
AccelRange_8G
AccelRange_16G
'''
bmx.set_accel_range(bmx.AccelRange_4G)
time.sleep(0.1)


def main():
    while True:
        data= bmx.get_all_data()
        time.sleep(1)
        print("accel x: {0:.2f} m/s^2, y: {1:.2f} m/s^2, z: {2:.2f} m/s^2".format(data[6],data[7],data[8]))
        print(" ")

if __name__ == "__main__":
    main()