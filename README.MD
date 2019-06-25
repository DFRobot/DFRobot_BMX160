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

Provide an Arduino library to control the bmx160 to get acell, gyro and step counter, via I2C communication.

## Installation

To use this library, first download the library file, paste it into the \Arduino\libraries directory, then open the examples folder and run the demo in the folder.

## Methods

```C++	

#include <DFRobot_BMX160.h>

/*
 * @brief reset bmx160 hardware
 * @return BMX160_OK(0) means success
 */
int8_t softReset();

/*
 * @brief set the i2c addr and init the i2c.
 * @return true means success
 */
bool begin();

/*
 * @brief set gyroscope angular rate range and resolution.
 * @param eGyroRange_t bits in 
 * @typedef enum{eGyroRange_2000DPS,
 *               eGyroRange_1000DPS,
 *               eGyroRange_500DPS,
 *               eGyroRange_250DPS,
 *               eGyroRange_125DPS
 *               }eGyroRange_t;
 */
void setGyroRange(eGyroRange_t bits);

/*
 * @brief allow the selection of the accelerometer g-range.
 * @param eAccelRange_t bits in 
 * @typedef enum{eAccelRange_2G,
 *               eAccelRange_4G,
 *               eAccelRange_8G,
 *               eAccelRange_16G
 *               }eAccelRange_t;
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


## History

- data 2019-6-25
- version V0.1


## Credits

Written by DFRobot_haoJ(hao.jiang@dfrobot.com), 2017. (Welcome to our [website](https://www.dfrobot.com/))





