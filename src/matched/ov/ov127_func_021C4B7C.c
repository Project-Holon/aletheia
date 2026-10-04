/*
 * function: func_021C4B7C
 * address:  0x021C4B7C
 * packet:   pkt_021C4B7C
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00535.h"

typedef unsigned short u16;

struct pair {
    u16 a;
    u16 b;
};

void func_021C4B7C(char *p, struct pair v)
{
    ((struct Obj00535 *)p)->f4 = v.a;
    ((struct Obj00535 *)p)->f6 = v.b;
}
