/*
 * function: CircleGraph_SetCenterDepth
 * address:  0x021C11A4
 * packet:   pkt_ov217_021C11A4
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CircleGraph_SetCenter  0x021C1194  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14758.h"

typedef unsigned char u8;
typedef short s16;

struct Pos {
    s16 a;
    s16 b;
    s16 c;
};

extern void CircleGraph_SetCenter(u8 *p, struct Pos *v);

void CircleGraph_SetCenterDepth(u8 *p, int a1)
{
    struct Pos v;
    s16 y = ((struct Obj14758 *)p)->f1B6;
    s16 x = ((struct Obj14758 *)p)->f1B4;
    v.a = x;
    v.b = y;
    v.c = a1;
    CircleGraph_SetCenter(p, &v);
}
