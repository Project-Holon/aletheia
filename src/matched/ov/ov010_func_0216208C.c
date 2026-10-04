/*
 * function: func_0216208C
 * address:  0x0216208C
 * packet:   pkt_ov010_0216208C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf (no lr save, prints as .word data in the listing),
 * called from ov020 func_021871F8.
 */
#include "../include/Obj18951.h"

typedef unsigned short u16;

int func_0216208C(char *p, int unused)
{
    if (((struct Obj18951 *)p)->f2 & 8)
        return 1;
    return 0;
}
