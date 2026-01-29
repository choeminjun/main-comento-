#include "main.h"
#include "dtc.h"

void DTC_Send(uint16_t dtc)
{
    CAN_TxHeaderTypeDef txHeader;
    uint32_t mailbox;
    uint8_t data[8]={0};

    data[0] = (dtc >> 8);
    data[1] = (dtc & 0xFF);

    txHeader.StdId = 0x700;
    txHeader.DLC = 8;
    txHeader.IDE = CAN_ID_STD;
    txHeader.RTR = CAN_RTR_DATA;

    HAL_CAN_AddTxMessage(&hcan1, &txHeader, data, &mailbox);
}
