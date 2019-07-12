# BOASH BMX160-RaspberryPi
The BMX160 is a highly integrated, low power 9-axis sensor that provides precise acceleration and angular rate (gyroscopic) and geomagnetic measurement in each spatial direction.<br>
The BMX160 contains 16 bit digtial,triaxial accelerometer 16 bit digital, triaxial gyroscope and geomagnetic sensor.<br>
This example is for BMX160 sensor and it oprated via Arduino I2C.

## DFRobot_BMX160 Library for RaspberryPi
---------------------------------------------------------
Provide a Raspberry Pi library for the BMX160 modules.

## Table of Contents

* [Summary](#summary)
* [Feature](#feature)
* [Installation](#installation)
* [Methods](#methods)
* [History](#history)
* [Credits](#credits)
<snippet>
<content>

## Summary
Provide an Arduino library to control the bmx160 to get magnetometer, accelerometer, gyroscope and step counter, via I2C communication.

## Feature
1. Low standby current
2. Serial input via I2C-bus

## Installation

This Sensor should work with BMX160 on RaspberryPi.<br>
Run the program:
```
$> python read_all_data.py

```

## Methods

```Python

'''
@brief Init The BMX160

@param bus      I2C bus
'''
DFRobot_BMX160(bus)
    
    '''
    brief set the i2c addr and init the i2c.
    return true means success
    '''
    def begin(self)
    '''
    brief reset bmx160 hardware
    return true means success
    '''
    def soft_reset(self)
    
    '''
    brief set gyroscope angular rate range and resolution.
    param bits in range(0, 5)
    '''
    def set_gyro_range(self, bits)
    
    '''
    brief allow the selection of the accelerometer g-range.
    param eAccelRange_t bits in range(0, 4)
    '''
    def set_accel_range(self, bits);
    
    '''
    brief get the magn, gyro and accel data 
    return a list include all data
    '''
    def get_all_data(self)
    
    '''
    brief disabled the the magn, gyro sensor to reduce power consumption
    '''
    def set_low_power(self)
    
    '''
    brief enabled the the magn, gyro sensor
    '''
    def wake_up(self)


```
## History

- data 2019-6-25
- version V0.1

## Credits

author [luoyufeng yufeng.luo@dfrobot.com]
