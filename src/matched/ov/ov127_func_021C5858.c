/*
 * function: func_021C5858
 * address:  0x021C5858
 * packet:   pkt_ov127_021C5858
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled accessor veneer after func_021C584C (`ldr r0,[r0,#4]; ldr r3,=
 * func_021C4224; bx r3`).  Blocker of ov099 func_021B989C.
 *
 * symbols:
 *   func_021C4224  0x021C4224  thumb  ov127
 */
#include "../include/Obj23052.h"

typedef unsigned char u8;

extern int func_021C4224(u8 *p);

int func_021C5858(u8 *p)
{
    return func_021C4224(((struct Obj23052 *)p)->f4);
}
