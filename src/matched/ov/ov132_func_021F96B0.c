/*
 * function: func_021F96B0
 * address:  0x021F96B0
 * packet:   pkt_021F96B0
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj23188.h"

extern void GFL_USE_CancelChangeAndPlayBgm(int, int);

void func_021F96B0(char *p, int a)
{
    ((struct Obj23188 *)p)->f2C = 1;
    GFL_USE_CancelChangeAndPlayBgm(a, 0xffff);
}
