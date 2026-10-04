/*
 * function: func_021FEF24
 * address:  0x021FEF24
 * packet:   pkt_021FEF24
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

 * Sentinel at +0xbc, publish +0xde4, kick helper 9, latch state 0xf.
 */
#include "../include/Obj09240.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void func_021F9968(u8 *p, int mode);
extern void func_021FF570(u32 k);

int func_021FEF24(u8 *p)
{
    ((struct Obj09240 *)p)->fBC = 0xffff;
    func_021F9968((u8 *)(((struct Obj09240 *)p)->fDE4), 3);
    func_021FF570(9);
    ((struct Obj09240 *)p)->f28 = 0xf;
    return 2;
}
