/*
 * function: func_02061BB0
 * address:  0x02061BB0
 * packet:   pkt_0206123C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Returns the base pointer plus the +8 halfword shifted left four.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02061BB0.c \
 *       --func func_02061BB0 --addr 0x02061BB0 --arm --cc 1.1p1
 */
#include "../include/Obj11497.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 func_02061BB0(u8 *p)
{
    return ((struct Obj11497 *)p)->f0 + ((u32)((struct Obj11497 *)p)->f8 << 4);
}
