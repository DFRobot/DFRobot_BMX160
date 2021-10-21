# DFRobot_BMX160
- [English Version](./README.md)

BMX160是一款高度集成的低功率9轴传感器，可在每个空间方向提供精确的加速度、角速度(陀螺)和地磁测量
BMX160九轴传感器集成三个传感器：16位陀螺仪、16位加速度、地磁传感器
这个库是针对BMX160传感器，它通过Arduino I2C操作。

![](./resources/images/SEN0373.png)


## 产品链接(https://www.dfrobot.com.cn/goods-2947.html)

    SKU：SEN0373

## 目录

* [概述](#概述)
* [库安装](#库安装)
* [方法](#方法)
* [兼容性](#兼容性)
* [历史](#历史)
* [创作者](#创作者)
 
## 概述

提供一个Arduino库，通过I2C通信控制bmx160以获取磁强计加速计、陀螺仪和步进计数器。

## 库安装

这里提供两种使用本库的方法：
1. 打开Arduino IDE,在状态栏中的Tools--->Manager Libraries 搜索"DFRobot_VEML6075"并安装本库.
2. 首先下载库文件,将其粘贴到\Arduino\libraries目录中,然后打开examples文件夹并在该文件夹中运行演示.


## 方法

```C++
    /**
     * @fn begin
     * @brief 初始化iic
     * @return 返回初始化结果
     * @retval true 初始化成功
     * @retval false 初始化失败
     */
    bool begin();

    /**
     * @fn setGyroRange
     * @brief 设置陀螺仪角速率范围和分辨率。
     * @param bits 
     * @n       eGyroRange_2000DPS     2000dps的陀螺仪灵敏度
     * @n       eGyroRange_1000DPS     1000dps的陀螺仪灵敏度
     * @n       eGyroRange_500DPS      500dps的陀螺仪灵敏度
     * @n       eGyroRange_250DPS      250dps的陀螺仪灵敏度
     * @n       eGyroRange_125DPS      125dps的陀螺仪灵敏度
     */
    void setGyroRange(eGyroRange_t bits);

    /**
     * @fn setAccelRange
     * @brief 选择加速计g范围。
     * @param bits 
     * @n       eAccelRange_2G        (1 LSB = 0.000061035mg) 
     * @n       eAccelRange_4G        (1 LSB = 0.000122070mg) 
     * @n       eAccelRange_8G        (1 LSB = 0.000244141mg) 
     * @n       eAccelRange_16G       (1 LSB = 0.000488281mg)
     */
    void setAccelRange(eAccelRange_t bits);
    
    /**
     * @fn getAllData
     * @brief 获取陀螺仪、加速计、地磁计数据
     * @param magn  存储地磁计数据
     * @param gyro  存储陀螺仪数据
     * @param accel  存储加速计数据
     */
    void getAllData( sBmx160SensorData_t *magn,  sBmx160SensorData_t *gyro,  sBmx160SensorData_t *accel);

    /**
     * @fn softReset
     * @brief 重启传感器
     * @return 重启结果
     * @retval true 设置重启成功
     * @retval false 设置重启失败
     */
    bool softReset();

    /**
     * @fn setLowPower
     * @brief 禁用地磁计、陀螺仪传感器以降低功耗
     */
    void setLowPower();

    /**
     * @fn wakeUp
     * @brief 使能地磁计、陀螺仪传感器
     */
    void wakeUp();
```

## 兼容性

| 主板          | 通过 | 未通过 | 未测试 | 备注 |
| ------------- | :--: | :----: | :----: | ---- |
| Arduino uno   |  √   |        |        |      |
| Mega2560      |  √   |        |        |      |
| Leonardo      |  √   |        |        |      |
| ESP32         |  √   |        |        |      |
| micro:bit     |  √   |        |        |      |
| FireBeetle M0 |  √   |        |        |      |


## 历史

- 2021/10/20 - 1.0.1 版本
- 2019/06/25 - 1.0.0 版本

## 创作者

Written by yangfeng(feng.yang@dfrobot.com), 2021. (Welcome to our [website](https://www.dfrobot.com/))
