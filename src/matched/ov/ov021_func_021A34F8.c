/*
 * function: func_021A34F8
 * address:  0x021A34F8
 * packet:   pkt_ov021_021A34F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf, tail-call thunk: the object's word at +0x4.
 * Sole blocker of the func_021645E0 MATCH (ov010).
 *
 * symbols:
 *   func_021A39E4  0x021A39E4  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj19771.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_021A39E4(u8 *p);

int func_021A34F8(u8 *p)
{
    return func_021A39E4(*(u8 * *)&((struct Obj19771 *)p)->f4);
}
