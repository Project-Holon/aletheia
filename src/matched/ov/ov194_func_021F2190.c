/*
 * function: func_021F2190
 * address:  0x021F2190
 * packet:   pkt_021F2190
 * region:   ov194
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GX_GetBankForLCDC 0x02045A98 arm
 */
#include "../include/Obj02909.h"

extern unsigned int GX_GetBankForLCDC(void);

int func_021F2190(char *p, unsigned short v)
{
    if (((struct Obj02909 *)p)->f1E < ((struct Obj02909 *)p)->f22)
    {
        *(unsigned short *)(p + (((struct Obj02909 *)p)->f1E << 1)) = v;
        ((struct Obj02909 *)p)->f1E += 1;
        *(unsigned short *)(p + (((struct Obj02909 *)p)->f1E << 1)) = GX_GetBankForLCDC();
        ((struct Obj02909 *)p)->f28 = 1;
        return 1;
    }
    return 0;
}
