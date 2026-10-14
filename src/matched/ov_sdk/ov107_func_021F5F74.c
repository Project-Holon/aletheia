/*
 * function: MB_EndToIdle
 * address:  0x021F5F74
 * packet:   pkt_ov107_021F5F74
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK: TwlSDK/libmb.TWL.HYB.a(mb_wm_base.o).
 *
 * symbols:
 *   OS_DisableInterrupts             0x02087988 arm
 *   OS_Terminate                     0x02088234 arm
 *   MBi_CommEnd                      0x021f5ee4 arm
 *   OS_RestoreInterrupts             0x0208799c arm
 *   gMbWm                       0x021F6F90 data
 */

#include "../include/G_WmBase.h"

typedef unsigned long u32;

extern struct WmBase gMbWm;
extern u32 OS_DisableInterrupts(void);
extern void OS_Terminate(void);
extern int MBi_CommEnd(void);
extern u32 OS_RestoreInterrupts(u32 state);

void MB_EndToIdle(void)
{
    u32 enabled = OS_DisableInterrupts();

    if (*(u32 *)(*(char **)(((char *)&gMbWm) + 0x10) + 0x1320) == 0)
        OS_Terminate();
    MBi_CommEnd();
    OS_RestoreInterrupts(enabled);
}
