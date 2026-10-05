/*
 * function: func_021DA45C
 * address:  0x021DA45C
 * packet:   pkt_021DA45C
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   (none)
 *
 * Takes and clears the pointer the object keeps at +0x140, returning it
 *     (or 0 when it was already empty).  No call, so disasm.py needed a branch
 *     target to label it.
 */
#include "../include/Obj14333.h"

typedef unsigned long u32;

u32 func_021DA45C(char *obj)
{
    u32 v = ((struct Obj14333 *)obj)->f140;

    if (v != 0)
        ((struct Obj14333 *)obj)->f140 = 0;
    return v;
}

