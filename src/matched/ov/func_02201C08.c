/*
 * function: func_02201C08
 * address:  0x02201C08
 * packet:   pkt_02201C08
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   DPW_TR_CancelAsync  0x021C89F0  arm  ov114
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12238.h"

extern void DPW_TR_CancelAsync(void);

int func_02201C08(char *p)
{
    ((struct Obj12238 *)p)->fF8C = 0;
    DPW_TR_CancelAsync();
    ((struct Obj12238 *)p)->f28 = 0x2f;
    return 2;
}
