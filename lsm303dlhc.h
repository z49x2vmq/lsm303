#include "stm32l4xx_hal.h"


#ifndef __LSM303DLHC_H__
#define __LSM303DLHC_H__
// vim: ts=4 sw=4 expandtab


#define CTRL_REG1_A     ((uint8_t)0x20)
#define CTRL_REG2_A     ((uint8_t)0x21)
#define CTRL_REG3_A     ((uint8_t)0x22)
#define CTRL_REG4_A     ((uint8_t)0x23)
#define CTRL_REG5_A     ((uint8_t)0x24)
#define CTRL_REG6_A     ((uint8_t)0x25)
#define REFERENCE_A     ((uint8_t)0x26)
#define STATUS_REG_A    ((uint8_t)0x27)
#define OUT_X_L_A       ((uint8_t)0x28)
#define OUT_X_H_A       ((uint8_t)0x29)
#define OUT_Y_L_A       ((uint8_t)0x2a)
#define OUT_Y_H_A       ((uint8_t)0x2b)
#define OUT_Z_L_A       ((uint8_t)0x2c)
#define OUT_Z_H_A       ((uint8_t)0x2d)
#define FIFO_CTRL_REG_A ((uint8_t)0x2e)
#define FIFO_SRC_REG_A  ((uint8_t)0x2f)
#define INT1_CFG_A      ((uint8_t)0x30)
#define INT1_SOURCE_A   ((uint8_t)0x31)
#define INT1_THS_A      ((uint8_t)0x32)
#define INT1_DURATION_A ((uint8_t)0x33)
#define INT2_CFG_A      ((uint8_t)0x34)
#define INT2_SOURCE_A   ((uint8_t)0x35)
#define INT2_THS_A      ((uint8_t)0x36)
#define INT2_DURATION_A ((uint8_t)0x37)
#define CLICK_CFG_A     ((uint8_t)0x38)
#define CLICK_SRC_A     ((uint8_t)0x39)
#define CLICK_THS_A     ((uint8_t)0x3a)
#define TIME_LIMIT_A    ((uint8_t)0x3b)
#define TIME_LATENCY_A  ((uint8_t)0x3c)
#define TIME_WINDOW_A   ((uint8_t)0x3d)
#define CRA_REG_M       ((uint8_t)0x00)
#define CRB_REG_M       ((uint8_t)0x01)
#define MR_REG_M        ((uint8_t)0x02)
#define OUT_X_H_M       ((uint8_t)0x03)
#define OUT_X_L_M       ((uint8_t)0x04)
#define OUT_Z_H_M       ((uint8_t)0x05)
#define OUT_Z_L_M       ((uint8_t)0x06)
#define OUT_Y_H_M       ((uint8_t)0x07)
#define OUT_Y_L_M       ((uint8_t)0x08)
#define SR_REG_M        ((uint8_t)0x09)
#define IRA_REG_M       ((uint8_t)0x0a)
#define IRB_REG_M       ((uint8_t)0x0b)
#define IRC_REG_M       ((uint8_t)0x0c)
#define TEMP_OUT_H_M    ((uint8_t)0x31)
#define TEMP_OUT_L_M    ((uint8_t)0x32)

#define LA_ADDRESS      ((uint8_t)0x32)
#define MF_ADDRESS      ((uint8_t)0x3c)

void lsm303dlhc_init_la(I2C_HandleTypeDef *i2c);
void lsm303dlhc_init_mf(I2C_HandleTypeDef *i2c);

void lsm303dlhc_read_la(I2C_HandleTypeDef *i2c, uint8_t *buf);
void lsm303dlhc_read_mf(I2C_HandleTypeDef *i2c, uint8_t *buf);

#endif //__LSM303DLHC_H__
