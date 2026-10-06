/*
 * function: func_021DCE08
 * address:  0x021DCE08
 * packet:   pkt_021DCE08
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203C9AC  0x0203C9AC  arm
 *
 * The +0x14 sibling of func_021DCE58: stores the caller's word at +0x18,
 *     hard-codes 5 at +0x1c and then calls 0x0203C9AC(0, 0, 0, 0x3F5).
 */
#include "../include/Obj14349.h"

typedef unsigned long u32;

extern void func_0203C9AC(int a, u32 b, u32 c, u32 d);

void func_021DCE08(char *ctx, u32 v, int line)
{
    ((struct Obj14349 *)ctx)->f18 = v;
    ((struct Obj14349 *)ctx)->f1C = 5;
    func_0203C9AC(0, 0, 0, 0x3F5);
}

