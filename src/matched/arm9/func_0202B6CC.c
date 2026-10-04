/*
 * function: func_0202B6CC
 * address:  0x0202B6CC
 * packet:   pkt_0202B6CC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 *
 * Blocked: 0202B1F4 (thumb, from header) has no witness outside 0202B6CC..0202B6DC. Every concrete byte reproduces.
 * status:   EXACT
 * symbols:
 *   func_0202B1F4  0x0202B1F4  thumb
 *

 * Closed by the `matched` class: 0x0202B1F4 -> 0x0202B230 -> 0x0202B254, all filed this wave.
 */
#include "../include/Obj02010.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_0202B1F4(u32 v);

void func_0202B6CC(u8 *o)
{
    if ((((struct Obj02010 *)o)->fC & 1) == 0) {
        func_0202B1F4(((struct Obj02010 *)o)->f14);
    }
}
