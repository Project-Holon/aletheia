/*
 * function: func_021A44BC
 * address:  0x021A44BC
 * packet:   pkt_021A44BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: the object's word at +0xc.
 *
 * symbols:
 *   func_021A3AA0  0x021A3AA0  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18048.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_021A3AA0(u32 a);

void func_021A44BC(u8 *p)
{
    func_021A3AA0(((struct Obj18048 *)p)->fC);
}
