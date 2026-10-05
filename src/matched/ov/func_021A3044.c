/*
 * function: func_021A3044
 * address:  0x021A3044
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
 *   func_021A38A4  0x021A38A4  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18012.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021A38A4(u8 *p, void *v);

void func_021A3044(u8 *p, void *v)
{
    func_021A38A4((u8 *)((struct Obj18012 *)p)->f4, v);
}
