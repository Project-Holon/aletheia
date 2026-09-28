/*
 * function: func_0205F970
 * address:  0x0205F970
 * packet:   pkt_0205F970
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ReadNVRAM (libncfg.TWL.HYB.a backup.o)
 *
 * symbols:
 *   NVRAMi_Read 0x02083844 arm
 *   OS_IsTickAvailable  0x02087058 arm
 *   OS_IsAlarmAvailable 0x02087244 arm
 *   OS_Sleep            0x02085A38 arm
 */

typedef unsigned long u32;
typedef signed long   s32;
typedef int           BOOL;

typedef enum NVRAMResult {
    NVRAM_RESULT_SUCCESS = 0,
    NVRAM_RESULT_BUSY = 1
} NVRAMResult;

extern NVRAMResult NVRAMi_Read(u32 address, u32 size, void *pData);
extern BOOL OS_IsTickAvailable(void);
extern BOOL OS_IsAlarmAvailable(void);
extern void OS_Sleep(u32 msec);

NVRAMResult func_0205F970(u32 address, u32 size, void *pData)
{
    NVRAMResult nvramResult;
    s32 i;

    for (i = 0; i < 5; i++) {
        nvramResult = NVRAMi_Read(address, size, pData);
        if (nvramResult != NVRAM_RESULT_BUSY)
            break;
        if (OS_IsTickAvailable() && OS_IsAlarmAvailable())
            OS_Sleep(1);
    }
    return nvramResult;
}
