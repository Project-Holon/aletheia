/*
 * function: func_021A3068
 * address:  0x021A3068
 * packet:   pkt_021A2F48
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: the object's word at +0x4.
 *
 * symbols:
 *   func_021A395C  0x021A395C  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18014.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_021A395C(u8 *p);

void func_021A3068(u8 *p)
{
    func_021A395C((u8 *)(((struct Obj18014 *)p)->f4));
}
