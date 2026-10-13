/*
 * function: BTL_POKEPARAM_RecordMoveUse
 * address:  0x021D6744
 * packet:   pkt_ov093_021D6744
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj03699.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
void BTL_POKEPARAM_RecordMoveUse(u8 *p, u8 a, int f, u8 b, u16 c, u16 d)
{
    u16 old = ((struct Obj03699 *)p)->f14C;
    ((struct Obj03699 *)p)->f14A = d;
    ((struct Obj03699 *)p)->f14C = c;
    p[0x152] = a;
    p[0x144] = b;
    if (old == c) {
        if (f) ((struct Obj03699 *)p)->f14E += 1;
        else ((struct Obj03699 *)p)->f14E = 0;
    } else {
        ((struct Obj03699 *)p)->f14E = f ? 1 : 0;
    }
}
