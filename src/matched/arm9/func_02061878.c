/*
 * function: func_02061878
 * address:  0x02061878
 * packet:   pkt_0206123C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Returns whether the +0xc halfword is zero.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02061878.c \
 *       --func func_02061878 --addr 0x02061878 --arm --cc 1.1p1
 */
#include "../include/Obj16394.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj02061BD0;

int func_02061878(struct Obj02061BD0 *p)
{
    return ((struct Obj16394 *)p)->fC == 0 ? 1 : 0;
}
