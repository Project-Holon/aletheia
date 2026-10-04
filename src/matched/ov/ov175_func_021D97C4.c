/*
 * function: func_021D97C4
 * address:  0x021D97C4
 * packet:   pkt_021D97C4
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E65FC  0x021E65FC  thumb  ov177
 *
 * Thunk: hands the +0x1c block to 0x021E65FC (ov177) and returns its result.
 */
#include "../include/Obj24303.h"

typedef unsigned long u32;

extern u32 func_021E65FC(u32 p);

u32 func_021D97C4(char *obj)
{
    return func_021E65FC(((struct Obj24303 *)obj)->f1C);
}
