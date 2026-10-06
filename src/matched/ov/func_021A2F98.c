/*
 * function: func_021A2F98
 * address:  0x021A2F98
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
 *   func_021A3AD4  0x021A3AD4  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18009.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_021A3AD4(u8 *p);

u32 func_021A2F98(u8 *p)
{
    return func_021A3AD4((u8 *)(((struct Obj18009 *)p)->f4));
}
