/*
 * unit:     no
 * function: sub_0202B584
 * address:  0x0202B584
 * packet:   pkt_0202B4BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * A constructor-shaped clear on a small object: a leading halfword and ten
 * words, all zeroed in address order. No relocation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202B584.c \
 *       --func sub_0202B584 --addr 0x0202B584 --cc 1.1p1 --thumb
 */
#include "../include/Obj00563.h"

typedef unsigned short u16;
typedef unsigned int u32;

void sub_0202B584(void *obj)
{
    ((struct Obj00563 *)obj)->f0 = 0;
    ((struct Obj00563 *)obj)->f4 = 0;
    ((struct Obj00563 *)obj)->f8 = 0;
    ((struct Obj00563 *)obj)->fC = 0;
    ((struct Obj00563 *)obj)->f10 = 0;
    ((struct Obj00563 *)obj)->f14 = 0;
    ((struct Obj00563 *)obj)->f18 = 0;
    ((struct Obj00563 *)obj)->f1C = 0;
    ((struct Obj00563 *)obj)->f20 = 0;
    ((struct Obj00563 *)obj)->f24 = 0;
}
