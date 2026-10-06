/*
 * function: func_021ABE18
 * address:  0x021ABE18
 * packet:   pkt_021ABE18
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: the object's word at +0x8.
 *
 * symbols:
 *   func_02188CD8  0x02188CD8  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18080.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_02188CD8(u8 *p);

u32 func_021ABE18(u8 *p)
{
    return func_02188CD8((u8 *)(((struct Obj18080 *)p)->f8));
}
