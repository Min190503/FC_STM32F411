#ifndef DRV_MPU6500_H_
#define DRV_MPU6500_H_

#include "main.h"
#include <stdint.h>


// --- Định nghĩa thanh ghi MPU6500 ---
#define MPU6500_REG_WHO_AM_I    0x75

// Giá trị WHO_AM_I mặc định của MPU6500 thường là 0x70
#define MPU6500_WHO_AM_I_VAL    0x70

uint8_t MPU6500_ReadReg(uint8_t reg);
void MPU6500_WriteReg(uint8_t reg, uint8_t data);
uint8_t MPU6500_Init(void);

#endif
