/*
 * function: MB_SetParentCommParam
 * address:  0x021F5B4C
 * packet:   pkt_ov107_021F5B4C
 * region:   ov107
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MB_SetParentCommParam (libmb.TWL.HYB.a(mb_wm_base.o))
 *
 * symbols:
 *   OS_DisableInterrupts 0x02087988 arm
 *   OS_RestoreInterrupts 0x0208799C arm
 *   func_021F5ADC 0x021F5ADC arm ov107
 *   g_021F6F90 0x021F6F90 data
 */

#include "../include/G_WmBase.h"

extern struct WmBase g_021F6F90;

extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern int func_021F5ADC(unsigned short sendSize, unsigned short recvSize, unsigned short entry_num);

int MB_SetParentCommParam(unsigned short sendSize, unsigned short maxChildren)
{
    unsigned long enabled = OS_DisableInterrupts();

    if ((*(unsigned char **)(((unsigned char *)&g_021F6F90) + 0xC))[0x50D] != 0) {
        OS_RestoreInterrupts(enabled);
        return 0;
    }
    if (func_021F5ADC(sendSize, 8, maxChildren) == 0) {
        OS_RestoreInterrupts(enabled);
        return 0;
    }
    *(unsigned short *)(*(unsigned char **)(((unsigned char *)&g_021F6F90) + 0xC) + 0x10) = maxChildren;
    *(unsigned short *)(*(unsigned char **)(((unsigned char *)&g_021F6F90) + 0xC) + 0x500) = sendSize;
    *(unsigned short *)(*(unsigned char **)(((unsigned char *)&g_021F6F90) + 0xC) + 0x502) = 8;
    OS_RestoreInterrupts(enabled);
    return 1;
}
