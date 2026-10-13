/*
 * function: BEACON_VIEW_SetArrowAnim
 * address:  0x021F05E8
 * packet:   pkt_ov032_021F05E8
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F0DF4  0x021F0DF4  thumb  ov032
 */
#include "../include/Obj00007.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_021F0DF4(void *p, unsigned short v);

void BEACON_VIEW_SetArrowAnim(u8 *p, int a, u32 b)
{
    u8 m;

    if (a == 4)
        m = 0xf;
    else
        m = 1 << a;
    if ((1 & m) && ((struct Obj00007 *)p)->f28 != 0x30)
        func_021F0DF4((void *)(*(u32 *)&((struct Obj00007 *)p)->f2BC), (u8)(b + 1));
    if (2 & m)
        func_021F0DF4((void *)(((struct Obj00007 *)p)->f2C0), (u8)(b + 4));
    if ((4 & m) && p[0x7b] != 0)
        func_021F0DF4((void *)(*(u32 *)&((struct Obj00007 *)p)->f2C4), (u8)(b + 7));
    if (8 & m)
        func_021F0DF4((void *)(((struct Obj00007 *)p)->f2C8), (u8)(b + 10));
}
