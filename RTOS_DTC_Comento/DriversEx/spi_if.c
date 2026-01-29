#include "main.h"

/* SPI DMA 송수신 테스트 */
void SPI_IF_Process(void)
{
    uint8_t tx[8]={0};
    uint8_t rx[8]={0};

    HAL_SPI_TransmitReceive_DMA(&hspi1, tx, rx, 8);
}
