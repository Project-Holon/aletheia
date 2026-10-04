/*
 * function: func_021C800C
 * address:  0x021C800C
 * packet:   pkt_021C8000
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards the object's first word to func_021C7E30.
 *
 * symbols:
 *   func_021C7E30  0x021C7E30  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18332.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021C7E30(u32 v);

void func_021C800C(u8 *p)
{
    func_021C7E30(((struct Obj18332 *)p)->f0);
}
