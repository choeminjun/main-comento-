#include "main.h"
#include "uds_can.h"

/* CAN RX → UDS 처리 */
void CAN_IF_Process(void)
{
    CAN_RxHeaderTypeDef rxHeader;
    uint8_t rxData[8];

    if(HAL_CAN_GetRxFifoFillLevel(&hcan1, CAN_RX_FIFO0) > 0)
    {
        HAL_CAN_GetRxMessage(&hcan1,
                             CAN_RX_FIFO0,
                             &rxHeader,
                             rxData);

        /* UDS 처리 */
        UDS_CAN_Process(rxData, rxHeader.DLC);
    }
}
