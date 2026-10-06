/*
 * function: func_021A3238
 * address:  0x021A3238
 * packet:   pkt_021A3238
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
 *   func_021A3A20  0x021A3A20  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18019.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_021A3A20(u32 a);

int func_021A3238(u8 *p)
{
    return func_021A3A20(((struct Obj18019 *)p)->f4);
}
