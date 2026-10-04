/*
 * function: func_021C6DE0
 * address:  0x021C6DE0
 * packet:   pkt_ov021_021C6DE0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C6E5C  0x021C6E5C  thumb  ov021
 *   func_021C6CC4  0x021C6CC4  thumb  ov021
 *   func_021C6CA8  0x021C6CA8  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12957.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021C6E5C(u8 *p, u8 i, u32 a, u32 b);
extern void func_021C6CC4(u32 a);
extern void func_021C6CA8(u32 a);

void func_021C6DE0(u8 *p, u32 a, u32 b)
{
    int i;

    for (i = 0; i < p[0]; i++) {
        if (((u32 *)((struct Obj12957 *)p)->f4)[i] == 0) {
            func_021C6E5C(p, i, a, b);
            if (b == 0)
                func_021C6CC4(a);
            return;
        }
    }
    func_021C6CA8(a);
}
