/*
 * function: func_021A30BC
 * address:  0x021A30BC
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
 *   func_021A3990  0x021A3990  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18018.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_021A3990(u8 *p);

int func_021A30BC(u8 *p)
{
    return func_021A3990((u8 *)(((struct Obj18018 *)p)->f4));
}
