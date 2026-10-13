/*
 * function: func_021DC2A0
 * address:  0x021DC2A0
 * packet:   pkt_021DC2A0
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MI_CpuCopy8  0x02082D44  arm
 *
 * Sibling of func_021DC240 on the +0x148 block: take-and-clear, and when
 *     it was live, feed the object's +0x218 port block, the caller's argument
 *     and the literal 4 to 0x02082D44.
 */
#include "../include/Obj14346.h"

typedef unsigned long u32;

extern void MI_CpuCopy8(char *dst, u32 arg, u32 n);

u32 func_021DC2A0(char *obj, u32 arg)
{
    u32 v = ((struct Obj14346 *)obj)->f148;

    if (v != 0) {
        ((struct Obj14346 *)obj)->f148 = 0;
        MI_CpuCopy8(obj + 0x218, arg, 4);
    }
    return v;
}

