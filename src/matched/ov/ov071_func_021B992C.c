/*
 * function: MONOLITH_TOOL_LIST_FitBackground
 * address:  0x021B992C
 * packet:   pkt_ov071_021B992C
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_SetTileEntry  0x02041300  arm
 *   func_020409B4  0x020409B4  arm
 */
#include "../include/Obj20752.h"

typedef unsigned int u32;
typedef unsigned char u8;

extern void BG_SYS_SetTileEntry(u32 a, u32 b, u32 c, u32 d, u8 e, u8 f, u8 g);
extern void func_020409B4(u32 a);

void MONOLITH_TOOL_LIST_FitBackground(char *a)
{
    int x;
    int t;

    x = ((struct Obj20752 *)a)->f27C;
    if (x - 2 < 7) {
        t = (x - 1) * 32 / 8;
        BG_SYS_SetTileEntry(6, 0, 0, (u8)t, 0x20, 0x20 - t, 0x11);
        func_020409B4(6);
    }
}
