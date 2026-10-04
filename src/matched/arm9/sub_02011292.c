/*
 * function: sub_02011292
 * address:  0x02011292
 * packet:   pkt_020113F0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * A byte field at +0x0d and a word field at +0x14 set from the same value,
 * no prologue and nothing else in the body: an unlabelled leaf.  The caller's
 * value is stored as a byte first, in source order.
 *
 
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02011292.c \
 *       --func sub_02011292 --addr 0x02011292 --cc 1.1p1 --thumb
 */
#include "../include/Obj11716.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


void sub_02011292(void *o, u32 v)
{
    ((struct Obj11716 *)o)->fD = (u8)v;
    ((struct Obj11716 *)o)->f14 = v;
}

