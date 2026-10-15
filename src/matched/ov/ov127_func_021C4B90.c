/*
 * function: WF2DMAP_OBJ_SetDestPos
 * address:  0x021C4B90
 * packet:   pkt_021C4B90
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

void WF2DMAP_OBJ_SetDestPos(char *p, struct pair v)
{
    ((struct Obj00535 *)p)->f8 = v.a;
    ((struct Obj00535 *)p)->fA = v.b;
}
