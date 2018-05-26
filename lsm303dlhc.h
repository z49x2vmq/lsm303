#include "stm32l4xx_hal.h"


#ifndef __LSM303DLHC_H
#define __LSM303DLHC_H
// vim: ts=4 sw=4 expandtab

// Linear acceleration related register addesses
static const uint8_t CTRL_REG1_A     = 0x20;
static const uint8_t CTRL_REG2_A     = 0x21;
static const uint8_t CTRL_REG3_A     = 0x22;
static const uint8_t CTRL_REG4_A     = 0x23;
static const uint8_t CTRL_REG5_A     = 0x24;
static const uint8_t CTRL_REG6_A     = 0x25;
static const uint8_t REFERENCE_A     = 0x26;
static const uint8_t STATUS_REG_A    = 0x27;
static const uint8_t OUT_X_L_A       = 0x28;
static const uint8_t OUT_X_H_A       = 0x29;
static const uint8_t OUT_Y_L_A       = 0x2a;
static const uint8_t OUT_Y_H_A       = 0x2b;
static const uint8_t OUT_Z_L_A       = 0x2c;
static const uint8_t OUT_Z_H_A       = 0x2d;
static const uint8_t FIFO_CTRL_REG_A = 0x2e;
static const uint8_t FIFO_SRC_REG_A  = 0x2f;
static const uint8_t INT1_CFG_A      = 0x30;
static const uint8_t INT1_SOURCE_A   = 0x31;
static const uint8_t INT1_THS_A      = 0x32;
static const uint8_t INT1_DURATION_A = 0x33;
static const uint8_t INT2_CFG_A      = 0x34;
static const uint8_t INT2_SOURCE_A   = 0x35;
static const uint8_t INT2_THS_A      = 0x36;
static const uint8_t INT2_DURATION_A = 0x37;
static const uint8_t CLICK_CFG_A     = 0x38;
static const uint8_t CLICK_SRC_A     = 0x39;
static const uint8_t CLICK_THS_A     = 0x3a;
static const uint8_t TIME_LIMIT_A    = 0x3b;
static const uint8_t TIME_LATENCY_A  = 0x3c;
static const uint8_t TIME_WINDOW_A   = 0x3d;

// Options for CTRL_REG1_A
static const uint8_t ODR_DOWN  = 0b0000 << 4;
static const uint8_t ODR_1Hz   = 0b0001 << 4;
static const uint8_t ODR_10Hz  = 0b0010 << 4;
static const uint8_t ODR_25Hz  = 0b0011 << 4;
static const uint8_t ODR_50Hz  = 0b0100 << 4;
static const uint8_t ODR_100Hz = 0b0101 << 4;
static const uint8_t ODR_200Hz = 0b0110 << 4;
static const uint8_t ODR_400Hz = 0b0111 << 4;
static const uint8_t LPen      = 0b0001 << 3;
static const uint8_t Zen       = 0b0001 << 2;
static const uint8_t Yen       = 0b0001 << 1;
static const uint8_t Xen       = 0b0001 << 0;

// Options for CTRL_REG4_A
static const uint8_t BDU       = 0b01 << 7;
static const uint8_t BLE       = 0b01 << 6;
static const uint8_t FS_2G     = 0b00 << 4;
static const uint8_t FS_4G     = 0b01 << 4;
static const uint8_t FS_8G     = 0b10 << 4;
static const uint8_t FS_16G    = 0b11 << 4;
static const uint8_t HR        = 0b01 << 3;
static const uint8_t SIM       = 0b01 << 0;


// Magnetic field related register addesses
static const uint8_t CRA_REG_M       = 0x00;
static const uint8_t CRB_REG_M       = 0x01;
static const uint8_t MR_REG_M        = 0x02;
static const uint8_t OUT_X_H_M       = 0x03;
static const uint8_t OUT_X_L_M       = 0x04;
static const uint8_t OUT_Z_H_M       = 0x05;
static const uint8_t OUT_Z_L_M       = 0x06;
static const uint8_t OUT_Y_H_M       = 0x07;
static const uint8_t OUT_Y_L_M       = 0x08;
static const uint8_t SR_REG_M        = 0x09;
static const uint8_t IRA_REG_M       = 0x0a;
static const uint8_t IRB_REG_M       = 0x0b;
static const uint8_t IRC_REG_M       = 0x0c;
static const uint8_t TEMP_OUT_H_M    = 0x31;
static const uint8_t TEMP_OUT_L_M    = 0x32;

// I2C addresses (Datasheet << 1)
static const uint8_t LA_ADDRESS      = 0x32;
static const uint8_t MF_ADDRESS      = 0x3c;

void lsm303dlhc_init_la(I2C_HandleTypeDef *i2c);
void lsm303dlhc_init_mf(I2C_HandleTypeDef *i2c);

void lsm303dlhc_read_la(I2C_HandleTypeDef *i2c, uint8_t *buf);
void lsm303dlhc_read_mf(I2C_HandleTypeDef *i2c, uint8_t *buf);

void lsm303dlhc_read_la_b(I2C_HandleTypeDef *i2c, uint8_t *buf);
void lsm303dlhc_read_mf_b(I2C_HandleTypeDef *i2c, uint8_t *buf);

#endif //__LSM303DLHC_H
