/*
 * function: func_021D5318
 * address:  0x021D5318
 * packet:   pkt_021D5318
 * region:   ov120
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02028148  0x02028148  thumb
 *   func_02041B6C  0x02041B6C  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj10390.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_02028148(u8 *p);
extern void func_02041B6C(u32 bit);

void func_021D5318(u8 *p)
{
    if (((struct Obj10390 *)p)->f34) {
        func_02028148(((struct Obj10390 *)p)->f34);
        func_02041B6C(5);
        *(u32 *)&((struct Obj10390 *)p)->f34 = 0;
    }
}
