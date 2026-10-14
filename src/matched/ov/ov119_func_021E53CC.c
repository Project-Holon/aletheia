/*
 * function: POKETRADE_2D_ExitSummaryBgs
 * address:  0x021E53CC
 * packet:   pkt_ov119_021E53CC
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02040DA8 0x02040DA8 arm
 *   func_020403F4 0x020403F4 arm
 */
#include "../include/Obj13923.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern void func_020403F4(u32 i);
void POKETRADE_2D_ExitSummaryBgs(int p)
{
    if (((struct Obj13923 *)p)->f11EC != 0) {
        func_02040DA8(6, 1, 0);
        func_020403F4(6);
        func_020403F4(7);
        ((struct Obj13923 *)p)->f11EC = 0;
    }
}
