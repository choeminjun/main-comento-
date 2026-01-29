#include "main.h"
#include "eeprom_spi.h"

HAL_StatusTypeDef EEPROM_Write(uint8_t *data, uint16_t size)
{
    return HAL_SPI_Transmit_DMA(&hspi2, data, size);
}

HAL_StatusTypeDef EEPROM_Read(uint8_t *data, uint16_t size)
{
    static uint8_t dummy[64]={0};

    return HAL_SPI_TransmitReceive_DMA(&hspi2,
                                       dummy,
                                       data,
                                       size);
}
