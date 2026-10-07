/*
 * function: func_021FD65C
 * address:  0x021FD65C
 * packet:   pkt_021FD65C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021FD5F0  0x021FD5F0  thumb  ov135

 *
 * Reset the sub-state and report 2.
 */
#include "../../../matched/include/Obj02860.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021FD5F0(u8 *p);

int func_021FD65C(u8 *p)
{
    func_021FD5F0(p);
    ((struct Obj02860 *)p)->f28 = 1;
    return 2;
}
