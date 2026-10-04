/*
 * function: func_021D63BC
 * address:  0x021D63BC
 * packet:   pkt_021D63BC
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
 * Thunk: hands the +0x18 block to 0x021E65FC and returns its result, the
 *     poll partner of func_021D63B0 on the same field.
 */
#include "../include/Obj24229.h"

typedef unsigned long u32;

extern u32 func_021E65FC(u32 p);

u32 func_021D63BC(char *obj)
{
    return func_021E65FC(((struct Obj24229 *)obj)->f18);
}

