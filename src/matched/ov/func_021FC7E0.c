/*
 * function: func_021FC7E0
 * address:  0x021FC7E0
 * packet:   pkt_021FC7E0
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02202840  0x02202840  thumb  ov135

 * When the build query answers 0, bump the countdown at +0xdfc and roll state when it passes 0x2d.
 */
#include "../include/Obj07246.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern u32 func_02202840(u8 *p);

int func_021FC7E0(u8 *p)
{
    if (func_02202840(p + 0xfa0) == 0) {
        if (++((struct Obj07246 *)p)->fDFC > 0x2d) {
            ((struct Obj07246 *)p)->fDFC = 0;
            ((struct Obj07246 *)p)->f28 = ((struct Obj07246 *)p)->f2C;
        }
    }
    return 2;
}
