/*
 * function: func_021BB3AC
 * address:  0x021BB3AC
 * packet:   pkt_021BB3AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: the object's word at +0x0.
 *
 * symbols:
 *   func_021B79C4  0x021B79C4  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18168.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021B79C4(u32 *p, u32 v);

void func_021BB3AC(u8 *p, u32 b)
{
    func_021B79C4((u32 *)(((struct Obj18168 *)p)->f0), b);
}
