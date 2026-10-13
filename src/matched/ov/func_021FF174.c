/*
 * function: func_021FF174
 * address:  0x021FF174
 * packet:   pkt_021FF174
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIPE_SYS_EndCheck  0x020221A4  thumb  arm9
 *

 * Decrement the countdown at +0xd3c and, when the tick returns non-zero, zero it and latch state 1.
 */
#include "../include/Obj07251.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern u32 WIPE_SYS_EndCheck(void);

int func_021FF174(u8 *p)
{
    u32 v = ((struct Obj07251 *)p)->fD3C - 1;

    ((struct Obj07251 *)p)->fD3C = v;
    if (WIPE_SYS_EndCheck() != 0) {
        ((struct Obj07251 *)p)->fD3C = 0;
        ((struct Obj07251 *)p)->f28 = 1;
    }
    return 2;
}
