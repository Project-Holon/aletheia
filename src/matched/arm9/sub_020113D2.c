/*
 * function: sub_020113D2
 * address:  0x020113D2
 * packet:   pkt_020113F0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The sibling of sub_02011292 with two different values: the byte at +0x0d
 * takes the second argument and the word at +0x10 the first, and the stores
 * are emitted in that order.
 *
 
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020113D2.c \
 *       --func sub_020113D2 --addr 0x020113D2 --cc 1.1p1 --thumb
 */
#include "../include/Obj11717.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


void sub_020113D2(void *o, u32 v1, u32 v2)
{
    ((struct Obj11717 *)o)->fD = (u8)v2;
    ((struct Obj11717 *)o)->f10 = v1;
}

