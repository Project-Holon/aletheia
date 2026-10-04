/*
 * function: func_021C425C
 * address:  0x021C425C
 * packet:   pkt_ov127_021C425C
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call stub: ldr r0,[r0,#4]; ldr r3,=0x0204B3F4; bx r3.
 * Leaf of ov127 func_021C5834 (blocker of ov099 func_021BA2D4).
 *
 * symbols:
 *   func_0204B3F4  0x0204B3F4  arm
 */
#include "../include/Obj23016.h"

typedef unsigned int   u32;
struct Obj;
extern u32 func_0204B3F4(struct Obj *p);

int func_021C425C(char *p)
{
    return func_0204B3F4(((struct Obj23016 *)p)->f4);
}
