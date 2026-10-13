/*
 * function: SODATEYA_AddMove
 * address:  0x021C42F4
 * packet:   pkt_ov021_021C42F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj02093.h"

typedef unsigned int u32;

void SODATEYA_AddMove(u32 *p, u32 v)
{
    int i;
    u32 n;

    if (v == 0)
        return;
    n = ((struct Obj02093 *)p)->f38;
    for (i = 0; i < n; i++) {
        if (v == *(u32 *)((char *)p + i * 4 + 0x3c))
            return;
    }
    if (n < 4) {
        *(u32 *)((char *)p + n * 4 + 0x3c) = v;
        ((struct Obj02093 *)p)->f38 = ((struct Obj02093 *)p)->f38 + 1;
        return;
    }
    for (i = 0; i < 3; i++)
        *(u32 *)((char *)p + i * 4 + 0x3c) = *(u32 *)((char *)p + i * 4 + 0x40);
    *(u32 *)((char *)p + i * 4 + 0x3c) = v;
}
