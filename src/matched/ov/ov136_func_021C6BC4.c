/*
 * function: func_021C6BC4
 * address:  0x021C6BC4
 * packet:   pkt_021C6BC4
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C5C84  0x021C5C84  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj23617.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern int func_021C5C84(u8 *p);

int func_021C6BC4(u8 *p)
{
    if (func_021C5C84(p) == 0)
        return ((struct Obj23617 *)p)->f28;
    return 5;
}
