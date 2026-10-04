/*
 * function: func_021FEE44
 * address:  0x021FEE44
 * packet:   pkt_021FEE44
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F9968  0x021F9968  thumb  ov135
 *   func_021FF570  0x021FF570  thumb  ov135

 * Sentinel at +0xbc, publish +0xde4, kick helper 9, latch state 0xc.
 */
#include "../include/Obj09239.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void func_021F9968(u8 *p, int mode);
extern void func_021FF570(u32 k);

int func_021FEE44(u8 *p)
{
    ((struct Obj09239 *)p)->fBC = 0xffff;
    func_021F9968((u8 *)(((struct Obj09239 *)p)->fDE4), 2);
    func_021FF570(9);
    ((struct Obj09239 *)p)->f28 = 0xc;
    return 2;
}
