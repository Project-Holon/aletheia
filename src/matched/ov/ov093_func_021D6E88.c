/*
 * function: func_021D6E88
 * address: 0x021D6E88
 * packet: pkt_ov093_021D6E88
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: existing follower ov093_func_021D6EA0 stays separate.
 */
#include "../include/Obj00041.h"
typedef unsigned char u8;
typedef unsigned short u16;
void func_021D6E88(u8 *p)
{
    if (p[0x1f6] != 0x1f) {
        p[0x1f6] = 0x1f;
        ((struct Obj00041 *)p)->f1F4 = 0;
    }
}
