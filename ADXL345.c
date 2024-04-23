/*
 * ADXL345.c
 *
 *  Created on: Apr 22, 2024
 *      Author: burak
 */

#include "ADXL345.h"

uint8_t i;
uint8_t MyDatas[6];
uint8_t value[2] = {0} ;
int16_t x,y,z;
uint8_t data_rec[6];

void Scan_I2C_Address()
{


	for( i = 0 ; i < 255 ; i++)
	{
		if(HAL_I2C_IsDeviceReady(&hi2c2, i, 1, 10)==HAL_OK)
		{
			break;
		}


	}

}
void ADXL345_Write(uint8_t wRegister,uint8_t value)
{

	uint8_t data[2]={0};
	data[0] = wRegister;
	data[1] = value;


	HAL_I2C_Master_Transmit(&hi2c2, ADXL345_ADDRESS, data, 2, 100) ;



}
void ADXL345_Read(uint8_t rRegister,uint8_t sizeOfByte)
{
	HAL_I2C_Mem_Read(&hi2c2, ADXL345_ADDRESS, rRegister, 1, data_rec, sizeOfByte, 100);


}


void ADXL345_Init()
{


	ADXL345_Read(0x00,1); // 1 byte lık okuma yapacagım diyorum



	ADXL345_Write(0x2D,0);  /* 0X2D adresli register ,control registerıdır,öncec bunu bi sıfırlayalım -> power cont. reg reset all bits
	 	 	 	 	 	 	 	 */


	ADXL345_Write(0x2D,0x08);  // 0 0 0 0 1 0 0 0 -> measure bitini 1 yaptıkve ölçüm modunu aktif ettik

	ADXL345_Write(0x31, 0x01);	  //0x31 register -> data format registerıdır. +-8g aralığında ölçüm yapmak istiyorum. D1-D0 bitlerini 1 0 yazdım
								// 0 0 0 0 0 0 1 0




}


