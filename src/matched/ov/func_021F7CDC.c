/*
 * function: func_021F7CDC
 * address:  0x021F7CDC
 * packet:   pkt_021F7CDC
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F9968  0x021F9968  thumb  ov135

 * Publish the 0xffff sentinel at +0xbc and the u32 at +0xde4, then latch state 9.
 */
#include "../include/Obj09231.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void func_021F9968(u8 *p, int mode);

int func_021F7CDC(u8 *p)
{
    ((struct Obj09231 *)p)->fBC = 0xffff;
    func_021F9968((u8 *)(((struct Obj09231 *)p)->fDE4), 1);
    ((struct Obj09231 *)p)->f28 = 9;
    return 2;
}
