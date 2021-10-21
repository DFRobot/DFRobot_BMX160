# DFRobot_BMX160

- [中文版](./README_CN.md)

The BMX160 is a highly integrated, low power 9-axis sensor that provides precise acceleration and angular rate (gyroscopic) and geomagnetic measurement in each spatial direction.<br>
The BMX160 contains 16 bit digtial,triaxial accelerometer 16 bit digital, triaxial gyroscope and geomagnetic sensor.<br>
This example is for BMX160 sensor and it oprated via Arduino I2C.

![](../../resources/images/SEN0373.png)

## Product Link(https://www.dfrobot.com/product-2141.html)

    SKU：SEN0373

## Table of Contents

* [Summary](#summary)
* [Installation](#installation)
* [Methods](#methods)
* [Compatibility](#compatibility)
* [History](#history)
* [Credits](#credits)


## Summary
Provide an raspberrypi library to control the bmx160 to get magnetometer, accelerometer, gyroscope and step counter, via I2C communication.


## Installation

This Sensor should work with BMX160 on RaspberryPi.<br>
Run the program:
```
$> python read_all_data.py

```

## Methods

```Python

    def begin(self):
        '''!
          @brief initialization the i2c.
          @return returns the initialization status
          @retval True Initialization succeeded
          @retval False Initialization  failed
        '''

    def set_low_power(self):
        '''!
          @brief disabled the the magn, gyro sensor to reduce power consumption
        '''

    def wake_up(self):
        '''!
          @brief enabled the the magn, gyro sensor
        '''

    def soft_reset(self):
        '''!
          @brief reset bmx160 hardware
          @return returns the reset status
          @retval True reset succeeded
          @retval False  reset  failed
        '''

    def set_gyro_range(self, bits):
        '''!
          @brief set gyroscope angular rate range and resolution.
          @param bits 
          @n       GyroRange_125DPS      Gyroscope sensitivity at 125dps
          @n       GyroRange_250DPS      Gyroscope sensitivity at 250dps
          @n       GyroRange_500DPS      Gyroscope sensitivity at 500dps
          @n       GyroRange_1000DPS     Gyroscope sensitivity at 1000dps
          @n       GyroRange_2000DPS     Gyroscope sensitivity at 2000dps
        '''

    def set_accel_range(self, bits):
        '''!
          @brief allow the selection of the accelerometer g-range.
          @param bits 
          @n       AccelRange_2G        Macro for mg per LSB at +/- 2g sensitivity (1 LSB = 0.000061035mg) 
          @n       AccelRange_4G        Macro for mg per LSB at +/- 4g sensitivity (1 LSB = 0.000122070mg) 
          @n       AccelRange_8G        Macro for mg per LSB at +/- 8g sensitivity (1 LSB = 0.000244141mg) 
          @n       AccelRange_16G       Macro for mg per LSB at +/- 16g sensitivity (1 LSB = 0.000488281mg)
        '''

    def get_all_data(self):
        '''!
          @brief get the magn, gyro and accel data 
          @return all data
        '''

```
## Compatibility

* RaspberryPi Version

| Board        | Work Well | Work Wrong | Untested | Remarks |
| ------------ | :-------: | :--------: | :------: | ------- |
| RaspberryPi2 |           |            |    √     |         |
| RaspberryPi3 |     √     |            |          |         |
| RaspberryPi4 |           |            |    √     |         |

* Python Version

| Python  | Work Well | Work Wrong | Untested | Remarks |
| ------- | :-------: | :--------: | :------: | ------- |
| Python2 |     √     |            |          |         |
| Python3 |     √     |            |          |         |

## History

- 2021/10/20 - Version 1.0.1 released.
- 2019/06/25 - Version 1.0.0 released.

## Credits


Written by Fary(feng.yang@dfrobot.com), 2021. (Welcome to our [website](https://www.dfrobot.com/))
