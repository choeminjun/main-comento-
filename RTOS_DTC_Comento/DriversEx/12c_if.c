#include "main.h"
#include "pmic_i2c.h"

/* PMIC Vout 제어 + Status 확인 */
void I2C_IF_Process(void)
{
    PMIC_VOUT_U vout;
    PMIC_STATUS_U status;

    /* 전압 설정 */
    vout.Raw = 0;
    vout.Bit.VSET = 20;   // 전압값 (Datasheet 스케일 기준 수정)
    vout.Bit.EN = 1;

    PMIC_SetVout(&hi2c1, vout);

    /* 상태 Read */
    PMIC_ReadStatus(&hi2c1, &status);

    if(status.Bit.UV)
    {
        // UV Fault
    }
}
