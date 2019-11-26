/*
===============================================
bmx160 magnetometer/accelerometer/gyroscope library for Intel(R) Curie(TM) devices.
Copyright (c) 2015 Intel Corporation.  All rights reserved.

Based on MPU6050 Arduino library provided by Jeff Rowberg as part of his
excellent I2Cdev device library: https://github.com/jrowberg/i2cdevlib

===============================================
I2Cdev device library code is placed under the MIT license
Copyright (c) 2012 Jeff Rowberg

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
===============================================
*/
#include "DFRobot_BMX160.h"

DFRobot_BMX160::DFRobot_BMX160()
{
  Obmx160 = (struct bmx160Dev *)malloc(sizeof(struct bmx160Dev));
  Oaccel = (struct bmx160SensorData*)malloc(sizeof(struct bmx160SensorData));
  Ogyro = (struct bmx160SensorData*)malloc(sizeof(struct bmx160SensorData));
  Omagn = (struct bmx160SensorData*)malloc(sizeof(struct bmx160SensorData));
}

const uint8_t int_mask_lookup_table[13] = {
    BMX160_INT1_SLOPE_MASK,
    BMX160_INT1_SLOPE_MASK,
    BMX160_INT2_LOW_STEP_DETECT_MASK,
    BMX160_INT1_DOUBLE_TAP_MASK,
    BMX160_INT1_SINGLE_TAP_MASK,
    BMX160_INT1_ORIENT_MASK,
    BMX160_INT1_FLAT_MASK,
    BMX160_INT1_HIGH_G_MASK,
    BMX160_INT1_LOW_G_MASK,
    BMX160_INT1_NO_MOTION_MASK,
    BMX160_INT2_DATA_READY_MASK,
    BMX160_INT2_FIFO_FULL_MASK,
    BMX160_INT2_FIFO_WM_MASK
};

bool DFRobot_BMX160::begin()
{
    Wire.begin();
    if (scan() == true){
        softReset();
        writeBmxReg(BMX160_COMMAND_REG_ADDR, 0x11);
        delay(50);
        /* Set gyro to normal mode */
        writeBmxReg(BMX160_COMMAND_REG_ADDR, 0x15);
        delay(100);
        /* Set mag to normal mode */
        writeBmxReg(BMX160_COMMAND_REG_ADDR, 0x19);
        delay(10);
        setMagnConf();
        return true;
    }
    else
        return false;
}

void DFRobot_BMX160::setLowPower(){
    softReset();
    delay(100);
    setMagnConf();
    delay(100);
    writeBmxReg(BMX160_COMMAND_REG_ADDR, 0x12);
    delay(100);
    /* Set gyro to normal mode */
    writeBmxReg(BMX160_COMMAND_REG_ADDR, 0x17);
    delay(100);
    /* Set mag to normal mode */
    writeBmxReg(BMX160_COMMAND_REG_ADDR, 0x1B);
    delay(100);
}

void DFRobot_BMX160::wakeUp(){
    softReset();
    delay(100);
    setMagnConf();
    delay(100);
    writeBmxReg(BMX160_COMMAND_REG_ADDR, 0x11);
    delay(100);
    /* Set gyro to normal mode */
    writeBmxReg(BMX160_COMMAND_REG_ADDR, 0x15);
    delay(100);
    /* Set mag to normal mode */
    writeBmxReg(BMX160_COMMAND_REG_ADDR, 0x19);
    delay(100);
}

bool DFRobot_BMX160::softReset()
{
  int8_t rslt=BMX160_OK;
  if (Obmx160 == NULL){
    rslt = BMX160_E_NULL_PTR;
  }  
  rslt = softReset(Obmx160);
  if (rslt == 0)
    return true;
  else
    return false;
}

int8_t DFRobot_BMX160::softReset(struct bmx160Dev *dev)
{
  int8_t rslt=BMX160_OK;
  uint8_t data = BMX160_SOFT_RESET_CMD;
  if (dev==NULL){
    rslt = BMX160_E_NULL_PTR;
  }
  writeBmxReg(BMX160_COMMAND_REG_ADDR, data);
  delay(BMX160_SOFT_RESET_DELAY_MS);
  if (rslt == BMX160_OK){
    DFRobot_BMX160::defaultParamSettg(dev);
  }  
  return rslt;
}

void DFRobot_BMX160::defaultParamSettg(struct bmx160Dev *dev)
{
  // Initializing accel and gyro params with
  dev->gyroCfg.bw = BMX160_GYRO_BW_NORMAL_MODE;
  dev->gyroCfg.odr = BMX160_GYRO_ODR_100HZ;
  dev->gyroCfg.power = BMX160_GYRO_SUSPEND_MODE;
  dev->gyroCfg.range = BMX160_GYRO_RANGE_2000_DPS;
  dev->accelCfg.bw = BMX160_ACCEL_BW_NORMAL_AVG4;
  dev->accelCfg.odr = BMX160_ACCEL_ODR_100HZ;
  dev->accelCfg.power = BMX160_ACCEL_SUSPEND_MODE;
  dev->accelCfg.range = BMX160_ACCEL_RANGE_2G;
  

  dev->prevMagnCfg = dev->magnCfg;
  dev->prevGyroCfg = dev->gyroCfg;
  dev->prevAccelCfg = dev->accelCfg;
}

void DFRobot_BMX160::setMagnConf()
{
    writeBmxReg(BMX160_MAGN_IF_0_ADDR, 0x80);
    delay(50);
    // Sleep mode
    writeBmxReg(BMX160_MAGN_IF_3_ADDR, 0x01);
    writeBmxReg(BMX160_MAGN_IF_2_ADDR, 0x4B);
    // REPXY regular preset
    writeBmxReg(BMX160_MAGN_IF_3_ADDR, 0x04);
    writeBmxReg(BMX160_MAGN_IF_2_ADDR, 0x51);
    // REPZ regular preset
    writeBmxReg(BMX160_MAGN_IF_3_ADDR, 0x0E);
    writeBmxReg(BMX160_MAGN_IF_2_ADDR, 0x52);
    
    writeBmxReg(BMX160_MAGN_IF_3_ADDR, 0x02);
    writeBmxReg(BMX160_MAGN_IF_2_ADDR, 0x4C);
    writeBmxReg(BMX160_MAGN_IF_1_ADDR, 0x42);
    writeBmxReg(BMX160_MAGN_CONFIG_ADDR, 0x08);
    writeBmxReg(BMX160_MAGN_IF_0_ADDR, 0x03);
    delay(50);
}

void DFRobot_BMX160::setGyroRange(eGyroRange_t bits){
    switch (bits){
        case eGyroRange_125DPS:
            gyroRange = BMX160_GYRO_SENSITIVITY_125DPS;
            break;
        case eGyroRange_250DPS:
            gyroRange = BMX160_GYRO_SENSITIVITY_250DPS;
            break;
        case eGyroRange_500DPS:
            gyroRange = BMX160_GYRO_SENSITIVITY_500DPS;
            break;
        case eGyroRange_1000DPS:
            gyroRange = BMX160_GYRO_SENSITIVITY_1000DPS;
            break;
        case eGyroRange_2000DPS:
            gyroRange = BMX160_GYRO_SENSITIVITY_2000DPS;
            break;
        default:
            gyroRange = BMX160_GYRO_SENSITIVITY_250DPS;
            break;
    }
}

void DFRobot_BMX160::setAccelRange(eAccelRange_t bits){
    switch (bits){
        case eAccelRange_2G:
            accelRange = BMX160_ACCEL_MG_LSB_2G * 10;
            break;
        case eAccelRange_4G:
            accelRange = BMX160_ACCEL_MG_LSB_4G * 10;
            break;
        case eAccelRange_8G:
            accelRange = BMX160_ACCEL_MG_LSB_8G * 10;
            break;
        case eAccelRange_16G:
            accelRange = BMX160_ACCEL_MG_LSB_16G * 10;
            break;
        default:
            accelRange = BMX160_ACCEL_MG_LSB_2G * 10;
            break;
    }
}

void DFRobot_BMX160::getAllData(struct bmx160SensorData *magn, struct bmx160SensorData *gyro, struct bmx160SensorData *accel){

    uint8_t data[23] = {0};
    // put your main code here, to run repeatedly:
    readReg(BMX160_MAG_DATA_ADDR, data, 23);
    if(magn){
        magn->x = (int16_t) ((data[1] << 8) | data[0]);
        magn->y = (int16_t) ((data[3] << 8) | data[2]);
        magn->z = (int16_t) ((data[5] << 8) | data[4]);
        magn->x *= BMX160_MAGN_UT_LSB;
        magn->y *= BMX160_MAGN_UT_LSB;
        magn->z *= BMX160_MAGN_UT_LSB;
    }
    if(gyro){
        gyro->x = (int16_t) ((data[9] << 8) | data[8]);
        gyro->y = (int16_t) ((data[11] << 8) | data[10]);
        gyro->z = (int16_t) ((data[13] << 8) | data[12]);
        gyro->x *= gyroRange;
        gyro->y *= gyroRange;
        gyro->z *= gyroRange;
    }
    if(accel){
        accel->x = (int16_t) ((data[15] << 8) | data[14]);
        accel->y = (int16_t) ((data[17] << 8) | data[16]);
        accel->z = (int16_t) ((data[19] << 8) | data[18]);
        accel->x *= accelRange;
        accel->y *= accelRange;
        accel->z *= accelRange;
    }
}

int8_t DFRobot_BMX160::readBmxReg(uint8_t reg)
{
    uint8_t buf[1] = {0};
    
    readReg(reg, buf, sizeof(buf));
    return buf[1];
}

void DFRobot_BMX160::writeBmxReg(uint8_t reg, uint8_t value)
{
    uint8_t buffer[1] = {value};
    writeReg(reg, buffer, 1);
}

void DFRobot_BMX160::writeReg(uint8_t reg, uint8_t *pBuf, uint16_t len)
{
    Wire.begin();
    Wire.beginTransmission(_addr);
    Wire.write(reg);
    for(uint16_t i = 0; i < len; i ++)
        Wire.write(pBuf[i]);
    Wire.endTransmission();
}

void DFRobot_BMX160::readReg(uint8_t reg, uint8_t *pBuf, uint16_t len)
{
    Wire.begin();
    Wire.beginTransmission(_addr);
    Wire.write(reg);
    if(Wire.endTransmission() != 0)
        return;
    Wire.requestFrom(_addr, (uint8_t) len);
    for(uint16_t i = 0; i < len; i ++) {
        pBuf[i] = Wire.read();
    }
    Wire.endTransmission();
}

bool DFRobot_BMX160::scan()
{
    Wire.beginTransmission(_addr);
    if (Wire.endTransmission() == 0){
        return true;
    }
    return false;
}