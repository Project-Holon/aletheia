/*
 * file:     nwm_end.c
 * unit:     yes
 * function: NWM_End
 * address:  0x02702A98
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * sdk:      libnwm.TWL.HYB.a nwm_end.o
 *
 * symbols:
 *   NWMi_ClearFifoRecvFlag  0x027026EC  arm
 *   NWMi_CheckState  0x027028E4  arm
 *   OS_DisableInterrupts  0x02087988  arm  arm9
 *   OS_RestoreInterrupts  0x0208799C  arm  arm9
 *   PXI_SetFifoRecvCallback  0x020885A0  arm  arm9
 *   DAT_027341a0                 0x027341A0  data
 *   DAT_027341a4                 0x027341A4  data
 */
#include "../types.h"

#ifdef __MWERKS__
extern u32 NWMi_CheckState(u32, ...);
#else
#include "nwm_system.h"
#endif
typedef unsigned int OSIntrMode;
#include "../arm9/os_system.h"
#include "../arm9/pxi_fifo.h"
extern u32 DAT_027341a4[];
extern u8 DAT_027341a0[];

u32 NWM_End(void) {
    u32 st = NWMi_CheckState(1, 1);
    u32 irq;
    if (st != 0 && st != 2) {
        return st;
    }
    irq = OS_DisableInterrupts();
    *(u16 *)(*(u32 *)(DAT_027341a4[0] + 0x2278) + 0x24) = 0;
    NWMi_ClearFifoRecvFlag();
    PXI_SetFifoRecvCallback(0x16, 0);
    DAT_027341a4[0] = 0;
    DAT_027341a0[0] = 0;
    OS_RestoreInterrupts(irq);
    return 0;
}
