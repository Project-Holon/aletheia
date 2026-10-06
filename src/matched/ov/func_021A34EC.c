/*
 * function: func_021A34EC
 * address:  0x021A34EC
 * packet:   pkt_021A34EC
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
 *   func_021A3A10  0x021A3A10  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18021.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_021A3A10(u32 a);

int func_021A34EC(u8 *p)
{
    return func_021A3A10(((struct Obj18021 *)p)->f4);
}
