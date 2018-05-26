#include "lsm303dlhc.h"


void lsm303dlhc_init_la(I2C_HandleTypeDef *i2c) {
    uint8_t init[2][2] = {
        {CTRL_REG1_A, ODR_400Hz | LPen | Xen | Yen | Zen},
        {CTRL_REG4_A, BDU | FS_4G | HR}
    };

    HAL_StatusTypeDef ret;

    ret = HAL_I2C_Master_Transmit(i2c, LA_ADDRESS, init[0], 2, 1000);

    if (ret != HAL_OK) {
        return;
    }

    ret = HAL_I2C_Master_Transmit(i2c, LA_ADDRESS, init[1], 2, 1000);

    if (ret != HAL_OK) {
        return;
    }
}

void lsm303dlhc_init_mf(I2C_HandleTypeDef *i2c) {
    uint8_t init[2][2] = {
        {CRB_REG_M, (uint8_t)0x20},
        {MR_REG_M, (uint8_t)0x00}
    };

    HAL_StatusTypeDef ret;

    ret = HAL_I2C_Master_Transmit(i2c, MF_ADDRESS, init[0], 2, 1000);
    if (ret != HAL_OK) {
        return;
    }

    ret = HAL_I2C_Master_Transmit(i2c, MF_ADDRESS, init[1], 2, 1000);
    if (ret != HAL_OK) {
        return;
    }

}

void lsm303dlhc_read_la(I2C_HandleTypeDef *i2c, uint8_t *buf) {
    uint8_t reg = OUT_X_L_A | 0b10000000;

    HAL_StatusTypeDef ret;

    ret = HAL_I2C_Master_Sequential_Transmit_IT(i2c, LA_ADDRESS, &reg, 1, I2C_FIRST_FRAME);
    if (ret != HAL_OK) {
        return;
    }

    while (!__HAL_I2C_GET_FLAG(i2c, I2C_FLAG_TC));

    ret = HAL_I2C_Master_Sequential_Receive_IT(i2c, LA_ADDRESS, buf, 6, I2C_LAST_FRAME);
    if (ret != HAL_OK) {
        return;
    }
    while(i2c->State != HAL_I2C_STATE_READY);
}

void lsm303dlhc_read_mf(I2C_HandleTypeDef *i2c, uint8_t *buf) {
    uint8_t reg = OUT_X_H_M;

    HAL_StatusTypeDef ret;

    ret = HAL_I2C_Master_Sequential_Transmit_IT(i2c, MF_ADDRESS, &reg, 1, I2C_FIRST_FRAME);
    if (ret != HAL_OK) {
        return;
    }
    while (!__HAL_I2C_GET_FLAG(i2c, I2C_FLAG_TC));

    ret = HAL_I2C_Master_Sequential_Receive_IT(i2c, MF_ADDRESS, buf, 6, I2C_LAST_FRAME);
    if (ret != HAL_OK) {
        return;
    }
    while(i2c->State != HAL_I2C_STATE_READY);
}

void lsm303dlhc_read_la_b(I2C_HandleTypeDef *i2c, uint8_t *buf) {
    uint8_t reg = OUT_X_L_A | 0b10000000;

    HAL_StatusTypeDef ret;

    ret = HAL_I2C_Master_Transmit(i2c, LA_ADDRESS, &reg, 1, 1000);
    if (ret != HAL_OK) {
        return;
    }

    ret = HAL_I2C_Master_Receive(i2c, LA_ADDRESS, buf, 6, 1000);
    if (ret != HAL_OK) {
        return;
    }
}

void lsm303dlhc_read_mf_b(I2C_HandleTypeDef *i2c, uint8_t *buf) {
    uint8_t reg = OUT_X_H_M;

    HAL_StatusTypeDef ret;

    ret = HAL_I2C_Master_Transmit(i2c, MF_ADDRESS, &reg, 1, 1000);
    if (ret != HAL_OK) {
        return;
    }

    ret = HAL_I2C_Master_Receive(i2c, MF_ADDRESS, buf, 6, 1000);
    if (ret != HAL_OK) {
        return;
    }
}
// vim: ts=4 sw=4 expandtab
