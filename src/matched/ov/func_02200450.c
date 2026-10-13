/*
 * function: func_02200450
 * address:  0x02200450
 * packet:   pkt_02200450
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F4EC0  0x021F4EC0  thumb  ov135
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm  arm9

 * When the u16 at +0xe18 is set, kick the three half-shades, set 7/0xb and roll to state 9.
 */
#include "../include/Obj09243.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void BG_SYS_SetMainPlaneVisible(u32 a, u32 b);
extern void func_021F4EC0(u8 *p, u32 a, u32 b);

int func_02200450(u8 *p)
{
    if (((struct Obj09243 *)p)->fE18 != 0) {
        BG_SYS_SetMainPlaneVisible(1, 0);
        BG_SYS_SetMainPlaneVisible(2, 0);
        BG_SYS_SetMainPlaneVisible(4, 0);
        func_021F4EC0(p, 7, 0xb);
        ((struct Obj09243 *)p)->f18 = 1;
        ((struct Obj09243 *)p)->f28 = 9;
    }
    return 2;
}
