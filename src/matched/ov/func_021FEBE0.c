/*
 * function: func_021FEBE0
 * address:  0x021FEBE0
 * packet:   pkt_021FEBE0
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

 * Publish +0xde4, kick helper 9, latch state 6.
 */
#include "../include/Obj12214.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void func_021F9968(u8 *p, int mode);
extern void func_021FF570(u32 k);

int func_021FEBE0(u8 *p)
{
    func_021F9968((u8 *)(((struct Obj12214 *)p)->fDE4), 0);
    func_021FF570(9);
    ((struct Obj12214 *)p)->f28 = 6;
    return 2;
}
