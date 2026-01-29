#include "main.h"
#include "uds_can.h"

/* UDS Response 송신 */
static void UDS_SendResponse(uint8_t sid, uint8_t *data, uint8_t len)
{
    CAN_TxHeaderTypeDef txHeader;
    uint32_t mailbox;
    uint8_t txData[8]={0};

    txData[0] = sid + 0x40;   // Positive Response SID

    for(int i=0;i<len;i++)
    {
        txData[i+1] = data[i];
    }

    txHeader.StdId = 0x7E8;   // ECU Response ID
    txHeader.DLC = 8;
    txHeader.IDE = CAN_ID_STD;
    txHeader.RTR = CAN_RTR_DATA;

    HAL_CAN_AddTxMessage(&hcan1, &txHeader, txData, &mailbox);
}

/* UDS Request 처리 */
void UDS_CAN_Process(uint8_t *rxData, uint8_t len)
{
    uint8_t sid = rxData[0];

    switch(sid)
    {
        /* Diagnostic Session Control */
        case UDS_SID_DIAG_SESSION:
        {
            uint8_t resp[1]={0x01};
            UDS_SendResponse(UDS_SID_DIAG_SESSION, resp, 1);
        }
        break;

        /* Read DTC */
        case UDS_SID_READ_DTC:
        {
            uint8_t resp[2]={0x10,0x01};
            UDS_SendResponse(UDS_SID_READ_DTC, resp, 2);
        }
        break;

        /* Clear DTC */
        case UDS_SID_CLEAR_DTC:
        {
            uint8_t resp[1]={0x00};
            UDS_SendResponse(UDS_SID_CLEAR_DTC, resp, 1);
        }
        break;

        default:
        break;
    }
}
