#include "main.h"
#include "pmic_i2c.h"

HAL_StatusTypeDef PMIC_SetVout(I2C_HandleTypeDef *hi2c,
                               PMIC_VOUT_U data)
{
    return HAL_I2C_Mem_Write(hi2c,
                             PMIC_SLAVE_ADDR,
                             PMIC_REG_VOUT_SET,
                             I2C_MEMADD_SIZE_8BIT,
                             &data.Raw,
                             1,
                             100);
}

HAL_StatusTypeDef PMIC_ReadStatus(I2C_HandleTypeDef *hi2c,
                                  PMIC_STATUS_U *status)
{
    return HAL_I2C_Mem_Read(hi2c,
                            PMIC_SLAVE_ADDR,
                            PMIC_REG_STATUS,
                            I2C_MEMADD_SIZE_8BIT,
                            &status->Raw,
                            1,
                            100);
}
