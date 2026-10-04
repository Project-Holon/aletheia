/*
 * function: func_021BA194
 * address:  0x021BA194
 * packet:   pkt_ov068_021BA194
 * region:   ov068
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf after func_021BA190; func_021BA7C0 calls it with an
 * 8-byte stack pair.  Copies one of three (x, y) pairs at +4/+0xC/+0x14.
 * The source is `const`: without it each second load sinks below the
 * first store (the out pointer may alias).
 */
#include "../include/Obj05150.h"

typedef unsigned char u8;

void func_021BA194(const u8 *p, int which, int *out)
{
    if (out == 0)
        return;
    switch (which) {
    case 0:
        out[0] = *(const int *)&((struct Obj05150 *)p)->f4;
        out[1] = *(const int *)&((struct Obj05150 *)p)->f8;
        break;
    case 1:
        out[0] = *(const int *)&((struct Obj05150 *)p)->fC;
        out[1] = *(const int *)&((struct Obj05150 *)p)->f10;
        break;
    case 2:
        out[0] = *(const int *)&((struct Obj05150 *)p)->f14;
        out[1] = *(const int *)&((struct Obj05150 *)p)->f18;
        break;
    }
}
