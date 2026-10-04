/*
 * function: func_021BB3B8
 * address:  0x021BB3B8
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
 *   func_021B79CC  0x021B79CC  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18169.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021B79CC(u32 *p);

void func_021BB3B8(u8 *p)
{
    func_021B79CC((u32 *)(((struct Obj18169 *)p)->f0));
}
