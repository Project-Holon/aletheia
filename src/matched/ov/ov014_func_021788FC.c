/*
 * function: DWCi_MOV_WH_EndScan
 * address:  0x021788FC
 * packet:   pkt_ov014_021788FC
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   gWihWork     0x021797A8  data  a4
 *   WIH_ChangeSysState  0x02178138  thumb  ov014
 *   DWCi_MOV_WH_StateInStartScan  0x0217863C  thumb  ov014
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 */

#include "../include/G_S.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed short s16;

extern struct S *gWihWork;
void WIH_ChangeSysState(int a);
int DWCi_MOV_WH_StateInStartScan(void);
int OS_DisableInterrupts(void);
void OS_RestoreInterrupts(int a);

int DWCi_MOV_WH_EndScan(void)
{
    int irq;
    int r = 0;

    irq = OS_DisableInterrupts();

    if (*(u32 *)(((u8 *)gWihWork) + 0x1E70) == 2) {
        if (*(s16 *)(((u8 *)gWihWork) + 0x1EBE) != 0) {
            if (DWCi_MOV_WH_StateInStartScan() == 0)
                WIH_ChangeSysState(9);
        }
        *(s16 *)(((u8 *)gWihWork) + 0x1EBE) = -1;
        *(u16 *)(((u8 *)gWihWork) + 0x1EB4) = 0;
        r = 1;
        ((u8 *)gWihWork)[0x1EDF] = 1;
        WIH_ChangeSysState(3);
    }
    OS_RestoreInterrupts(irq);
    return r;
}
