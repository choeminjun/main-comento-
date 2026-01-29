#ifndef __EEPROM_SPI_H__
#define __EEPROM_SPI_H__

#include "stdint.h"
#include "stm32f4xx_hal.h"

HAL_StatusTypeDef EEPROM_Write(uint8_t *data, uint16_t size);
HAL_StatusTypeDef EEPROM_Read(uint8_t *data, uint16_t size);

#endif
