#ifndef __DTC_H__
#define __DTC_H__

#include "stdint.h"

#define DTC_UV_FAULT   0x1001
#define DTC_OV_FAULT   0x1002
#define DTC_OC_FAULT   0x1003
#define DTC_OT_FAULT   0x1004

void DTC_Send(uint16_t dtc);

#endif
