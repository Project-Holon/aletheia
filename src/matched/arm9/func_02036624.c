/*
 * function: GFL_NET_RING_BUFF_WrapPos
 * address:  0x02036624
 * packet:   pkt_02036624
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   _s32_div_f  0x0209C0A4  arm
 */
#include "../include/Obj15900.h"

int GFL_NET_RING_BUFF_WrapPos(void *p, int v)
{
    return v % ((struct Obj15900 *)p)->f4;
}
