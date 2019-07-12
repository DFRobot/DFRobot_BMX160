# BMX160-Arduino
The BMX160 is a highly integrated, low power 9-axis sensor that provides precise acceleration and angular rate (gyroscopic) and geomagnetic measurement in each spatial direction.<br>
The BMX160 contains 16 bit digtial,triaxial accelerometer 16 bit digital, triaxial gyroscope and geomagnetic sensor.<br>
This example is for BMX160 sensor and it oprated via Arduino I2C.


## DFRobot_BMX160 Library for Arduino
---------------------------------------------------------

Provide an Arduino library to control the bmx160 to get acell, gyro and step counter, via I2C communication.

## Table of Contents

* [Summary](#summary)
* [Installation](#installation)
* [Methods](#methods)
* [Compatibility](#compatibility)
* [History](#history)
* [Credits](#credits)

## Summary

Provide an Arduino library to control the bmx160 to get magnetometer accelerometer, gyroscope and step counter, via I2C communication.

## Installation

To use this library, first download the library file, paste it into the \Arduino\libraries directory, then open the examples folder and run the demo in the folder.

## Methods

```C++

#include <DFRobot_BMX160.h>
/*
 * @brief set gyroscope angular rate range and resolution.
 */
typedef enum{
 eGyroRange_2000DPS, /*Gyroscope sensitivity at 2000dps*/
 eGyroRange_1000DPS, /*Gyroscope sensitivity at 1000dps*/
 eGyroRange_500DPS,  /*Gyroscope sensitivity at 500dps*/
 eGyroRange_250DPS,  /*Gyroscope sensitivity at 250dps*/
 eGyroRange_125DPS   /*Gyroscope sensitivity at 125dps*/
}eGyroRange_t;

/*
 * @brief allow the selection of the accelerometer g-range.
 */
typedef enum{
 eAccelRange_2G,  /* Macro for mg per LSB at +/- 2g sensitivity (1 LSB = 0.000061035mg) */
 eAccelRange_4G,  /* Macro for mg per LSB at +/- 4g sensitivity (1 LSB = 0.000122070mg) */
 eAccelRange_8G,  /* Macro for mg per LSB at +/- 8g sensitivity (1 LSB = 0.000244141mg) */
 eAccelRange_16G  /* Macro for mg per LSB at +/- 16g sensitivity (1 LSB = 0.000488281mg) */
}eAccelRange_t;

/*
 * @brief reset bmx160 hardware
 * @return true means success
 */
bool softReset();

/*
 * @brief set the i2c addr and init the i2c.
 * @return true means success
 */
bool begin();

/*
 * @brief set gyroscope angular rate range and resolution.
 * @param eGyroRange_t bits in 
 */
void setGyroRange(eGyroRange_t bits);

/*
 * @brief allow the selection of the accelerometer g-range.
 * @param eAccelRange_t bits in 
 */
void setAccelRange(eAccelRange_t bits);

/*
 * @brief get the magn, gyro and accel data 
 * @param pointer to store the data: &Omagn, &Ogyro, &Oaccel.
 */
void getAllData(struct bmx160SensorData *magn, struct bmx160SensorData *gyro, struct bmx160SensorData *accel);

/*
 * @brief disabled the the magn, gyro sensor to reduce power consumption
 */
void setLowPower();

/*
 * @brief enabled the the magn, gyro sensor
 */
void wakeUp();

```

## Compatibility

MCU                | Work Well    | Work Wrong   | Untested    | Remarks
------------------ | :----------: | :----------: | :---------: | -----
Arduino uno        |      √       |              |             | 
Mega2560        |      √       |              |             | 
Leonardo        |      √       |              |             | 
ESP32        |      √       |              |             | 


## History

- data 2019-6-25
- version V0.1


## Credits

Written by(yufeng.luo@dfrobot.com), 2019. (Welcome to our [website](https://www.dfrobot.com/))





