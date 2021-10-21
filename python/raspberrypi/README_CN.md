# DFRobot_BMX160
- [English Version](./README.md)

BMX160是一款高度集成的低功率9轴传感器，可在每个空间方向提供精确的加速度、角速度(陀螺)和地磁测量
BMX160九轴传感器集成三个传感器：16位陀螺仪、16位加速度、地磁传感器
这个库是针对BMX160传感器，它通过Arduino I2C操作。


![](../../resources/images/SEN0373.png)


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

提供一个树莓派python库，通过I2C通信控制bmx160以获取磁强计加速计、陀螺仪和步进计数器。

## 库安装

使用此库前，请首先下载库文件，将其粘贴到树莓派的自定义目录中，然后打开examples文件夹并在该文件夹中运行演示。

## 方法

```python

    def begin(self):
        '''!
          @brief 初始化iic
          @return 返回初始化结果
          @retval True 初始化成功
          @retval False 初始化失败
        '''

    def set_low_power(self):
        '''!
          @brief 禁用地磁计、陀螺仪传感器以降低功耗
        '''

    def wake_up(self):
        '''!
          @brief 使能地磁计、陀螺仪传感器
        '''

    def soft_reset(self):
        '''!
          @brief 重启传感器
          @return 重启结果
          @retval True 设置重启成功
          @retval False  设置重启失败
        '''

    def set_gyro_range(self, bits):
        '''!
          @brief 设置陀螺仪角速率范围和分辨率。
          @param bits 
          @n       GyroRange_125DPS      125dps的陀螺仪灵敏度
          @n       GyroRange_250DPS      250dps的陀螺仪灵敏度
          @n       GyroRange_500DPS      500dps的陀螺仪灵敏度
          @n       GyroRange_1000DPS     1000dps的陀螺仪灵敏度
          @n       GyroRange_2000DPS     2000dps的陀螺仪灵敏度
        '''

    def set_accel_range(self, bits):
        '''!
          @brief 选择加速计g范围。
          @param bits 
          @n       AccelRange_2G         (1 LSB = 0.000061035mg) 
          @n       AccelRange_4G         (1 LSB = 0.000122070mg) 
          @n       AccelRange_8G         (1 LSB = 0.000244141mg) 
          @n       AccelRange_16G        (1 LSB = 0.000488281mg)
        '''

    def get_all_data(self):
        '''!
          @brief 获取陀螺仪、加速计、地磁计数据
          @return 数据
        '''
```

## 兼容性

* RaspberryPi Version

| Board        | Work Well | Work Wrong | Untested | Remarks |
| ------------ | :-------: | :--------: | :------: | ------- |
| RaspberryPi2 |           |            |    √     |         |
| RaspberryPi3 |     √     |            |          |         |
| RaspberryPi4 |           |            |    √     |         |

* Python 版本

| Python  | Work Well | Work Wrong | Untested | Remarks |
| ------- | :-------: | :--------: | :------: | ------- |
| Python2 |     √     |            |          |         |
| Python3 |     √     |            |          |         |


## 历史

- 2021/10/20 - Version 1.0.1 released.
- 2019/06/25 - Version 1.0.0 released.


## 创作者

Written by yangfeng(feng.yang@dfrobot.com), 2021. (Welcome to our [website](https://www.dfrobot.com/))

