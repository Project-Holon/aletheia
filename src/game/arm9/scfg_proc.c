/*
 * file:     scfg_proc.c
 * unit:     yes
 * function: SCFG_Init, SCFG_SetCpuSpeed, SCFGi_CommonCallback
 * address:  0x0208C960
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   PXI_SetFifoRecvCallback        0x020885A0  arm
 *   SCFGi_CommonCallback           0x0208C9C4  arm
 *   OS_DisableInterrupts           0x02087988  arm
 *   SCFGi_SwitchCpuSpeed           0x01FF87D4  arm
 *   OS_RestoreInterrupts           0x0208799C  arm
 *   OS_Terminate                   0x02088234  arm
 *   SCFGi_FuseInfo                 0x02153040  data
 */
#include "../types.h"

#include "../sdk_os.h"

typedef void (*SCFGCallback)(u64 fuseData, void *arg);

typedef struct SCFGFuseInfo {
    volatile BOOL lock;
    u64 fuseData;
    u32 readFlag;
    SCFGCallback callback;
    void *callbackArg;
} SCFGFuseInfo;

#include "os_system.h"
typedef int SCFGCpuSpeed;
#include "../arm9_autoload0_ITCM/scfg_proc.h"
#include "os_terminate_processor.h"
void PXI_SetFifoRecvCallback(int fifotag, void (*callback)(int tag, u32 data, int err));
void SCFGi_CommonCallback(int tag, u32 data, int err);
void SCFG_Init(void);
void SCFG_SetCpuSpeed(int cpuSpeed);
extern SCFGFuseInfo SCFGi_FuseInfo;

#define reg_SCFG_CLK (*(vu16 *)0x04004004)

/*
 * sdk:      SCFG_Init (libscfg.TWL.HYB.a scfg_proc.o)
 */
void SCFG_Init(void)
{
    PXI_SetFifoRecvCallback(0x17, SCFGi_CommonCallback);
    SCFGi_FuseInfo.lock = 0;
}

/*
 * sdk:      SCFG_SetCpuSpeed (libscfg.TWL.HYB.a scfg_proc.o)
 */
void SCFG_SetCpuSpeed(int cpuSpeed)
{
    OSIntrMode enable = OS_DisableInterrupts();

    if (cpuSpeed != (reg_SCFG_CLK & 1)) {
        SCFGi_SwitchCpuSpeed(cpuSpeed);
    }
    (void)OS_RestoreInterrupts(enable);
}

/*
 * sdk:      SCFGi_CommonCallback (libscfg.TWL.HYB.a scfg_proc.o)
 *
 * The PXI FIFO callback: data and err arrive in r1 and r2 behind the unused
 * tag (the DWARF lists only pxiData).
 */
void SCFGi_CommonCallback(int tag, u32 pxiData, BOOL err)
{
    u16 command = (u16)((pxiData & 0x03F00000) >> 20);
    u16 ordinal = (u16)((pxiData & 0x000F0000) >> 16);
    u16 data = (u16)pxiData;
    u64 tempData;

    switch (command) {
    case 1:
        SCFGi_FuseInfo.fuseData |= ((u64)data << (ordinal * 16));
        SCFGi_FuseInfo.readFlag |= (1 << ordinal);
        if (SCFGi_FuseInfo.readFlag == 0xF) {
            if (SCFGi_FuseInfo.callback) {
                SCFGi_FuseInfo.callback(SCFGi_FuseInfo.fuseData, SCFGi_FuseInfo.callbackArg);
                SCFGi_FuseInfo.callback = 0;
            }
            SCFGi_FuseInfo.lock = 0;
        }
        break;
    case 2:
        *(u16 *)&tempData = data;
        if (SCFGi_FuseInfo.callback) {
            SCFGi_FuseInfo.callback(tempData, SCFGi_FuseInfo.callbackArg);
            SCFGi_FuseInfo.callback = 0;
        }
        SCFGi_FuseInfo.lock = 0;
        break;
    default:
        OS_Terminate();
    }
}
