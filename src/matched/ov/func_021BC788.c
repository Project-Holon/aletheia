/*
 * function: func_021BC788
 * address:  0x021BC788
 * packet:   pkt_021BC788
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: the object's word at +0x2c.
 *
 * symbols:
 *   func_0204ADA4  0x0204ADA4  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18190.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_0204ADA4(u32 i);

void func_021BC788(u8 *p)
{
    func_0204ADA4(((struct Obj18190 *)p)->f2C);
}
