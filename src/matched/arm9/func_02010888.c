/*
 * function: func_02010888
 * address:  0x02010888
 * packet:   pkt_0201058C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stores the value at the object's +8 field.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02010888.c \
 *       --func func_02010888 --addr 0x02010888 --thumb --cc 1.1p1
 */
#include "../include/Obj15612.h"

typedef unsigned char u8;
typedef unsigned int  u32;

void func_02010888(u8 *p, u32 v)
{
    ((struct Obj15612 *)p)->f8 = v;
}
