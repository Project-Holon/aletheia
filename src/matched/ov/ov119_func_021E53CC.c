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
 *   BG_SYS_SetTileUnit 0x02040DA8 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 */
#include "../include/Obj13923.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern void BG_SYS_SetTileUnit(u32 idx, u32 count, u32 tile);
extern void BG_SYS_FreeLayerBuf(u32 i);
void POKETRADE_2D_ExitSummaryBgs(int p)
{
    if (((struct Obj13923 *)p)->f11EC != 0) {
        BG_SYS_SetTileUnit(6, 1, 0);
        BG_SYS_FreeLayerBuf(6);
        BG_SYS_FreeLayerBuf(7);
        ((struct Obj13923 *)p)->f11EC = 0;
    }
}
