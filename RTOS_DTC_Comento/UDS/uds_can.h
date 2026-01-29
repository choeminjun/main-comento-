#ifndef __UDS_CAN_H__
#define __UDS_CAN_H__

#include "stdint.h"

/* UDS SID */
#define UDS_SID_DIAG_SESSION   0x10
#define UDS_SID_READ_DTC       0x19
#define UDS_SID_CLEAR_DTC      0x14

void UDS_CAN_Process(uint8_t *rxData, uint8_t len);

#endif
