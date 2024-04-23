/*
 * ADXL345.h
 *
 *  Created on: Apr 22, 2024
 *      Author: burak
 */

#ifndef INC_ADXL345_H_
#define INC_ADXL345_H_

#include "stm32f0xx_hal.h"

#define ADXL345_ADDRESS 0x53 << 1 // 0xA6-> Device Address

extern I2C_HandleTypeDef hi2c2;


void Scan_I2C_Address(void);
void ADXL345_Init(void);
void ADXL345_Read(uint8_t rRegister,uint8_t SizeOfByte);
void ADXL345_Write(uint8_t wRegister,uint8_t data) ;



extern float xg,yg,zg;
extern uint8_t data_rec[6];
extern uint8_t MyDatas[6];
extern int16_t x,y,z;
#endif /* INC_ADXL345_H_ */


















