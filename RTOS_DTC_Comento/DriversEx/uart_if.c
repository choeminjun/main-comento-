#include "main.h"
#include "string.h"

/* UART Fault Log */
void UART_IF_Process(void)
{
    char msg[] = "System Monitoring OK\r\n";

    HAL_UART_Transmit(&huart4,
                      (uint8_t*)msg,
                      strlen(msg),
                      100);
}
