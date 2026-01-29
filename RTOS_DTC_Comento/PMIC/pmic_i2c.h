#ifndef __PMIC_I2C_H__
#define __PMIC_I2C_H__

#include "stdint.h"
#include "stm32f4xx_hal.h"

#define PMIC_SLAVE_ADDR (0x48 << 1)

typedef enum
{
    PMIC_REG_VOUT_SET = 0x20,
    PMIC_REG_STATUS   = 0x30

} PMIC_REG_e;

typedef union
{
    uint8_t Raw;

    struct
    {
        uint8_t VSET :6;
        uint8_t EN   :1;
        uint8_t RES  :1;

    } Bit;

} PMIC_VOUT_U;

typedef union
{
    uint8_t Raw;

    struct
    {
        uint8_t UV :1;
        uint8_t OV :1;
        uint8_t OC :1;
        uint8_t OT :1;
        uint8_t RES:4;

    } Bit;

} PMIC_STATUS_U;

HAL_StatusTypeDef PMIC_SetVout(I2C_HandleTypeDef *hi2c,
                               PMIC_VOUT_U data);

HAL_StatusTypeDef PMIC_ReadStatus(I2C_HandleTypeDef *hi2c,
                                  PMIC_STATUS_U *status);

#endif
