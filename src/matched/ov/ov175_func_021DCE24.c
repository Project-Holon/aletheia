/*
 * function: func_021DCE24
 * address:  0x021DCE24
 * packet:   pkt_021DCE24
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
 * Set the word at +0 and mark the object armed at +0x1c, then start the
 * 0x3f7 service with a zeroed first three arguments.
 */
#include "../include/Obj14350.h"

typedef unsigned int   u32;
extern void func_0203C9AC(int a, u32 b, u32 c, u32 d);

void func_021DCE24(char *p, int v, int a2)
{
    ((struct Obj14350 *)p)->f0 = v;
    ((struct Obj14350 *)p)->f1C = 1;
    func_0203C9AC(0, 0, 0, 0x3f7);
}

