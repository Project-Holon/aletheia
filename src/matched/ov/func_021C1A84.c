/*
 * function: func_021C1A84
 * address:  0x021C1A84
 * packet:   pkt_021C1A84
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Pattern-generated from the ov021 family.
 *
 * symbols:
 *   func_02050DB8  0x02050DB8  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09206.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern void func_02050DB8(u8 *p);

void func_021C1A84(u8 *p)
{
    u32 v = ((struct Obj09206 *)p)->fC;
    if (v != 0) {
        func_02050DB8((u8 *)v);
        ((struct Obj09206 *)p)->fC = 0;
    }
}
