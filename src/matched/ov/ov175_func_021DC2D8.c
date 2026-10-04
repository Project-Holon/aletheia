/*
 * function: func_021DC2D8
 * address:  0x021DC2D8
 * packet:   pkt_021DC2D8
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)
 *
 * Take-and-clear: returns the word at +0x14c; when it is set, clears it and hands back the word at +0x150 through out.
 */
#include "../include/Obj10689.h"

typedef unsigned long u32;

u32 func_021DC2D8(char *obj, u32 *out)
{
    u32 v = ((struct Obj10689 *)obj)->f14C;
    if (v != 0) {
        ((struct Obj10689 *)obj)->f14C = 0;
        *out = ((struct Obj10689 *)obj)->f150;
    }
    return v;
}
