/*
 * function: func_0202B914
 * address:  0x0202B914
 * packet:   pkt_0202B7BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Clamps the second argument to 0x7f and stores it in the +8 byte.  No
 * relocations; pure.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B914.c \
 *       --func func_0202B914 --addr 0x0202B914 --thumb --cc 1.1p1
 */
#include "../include/Obj15845.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct Obj;

void func_0202B914(struct Obj *o, u32 v)
{
    if (v > 0x7f) {
        v = 0x7f;
    }
    ((struct Obj15845 *)o)->f8 = (u8)v;
}
