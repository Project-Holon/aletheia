/*
 * function: POKETRADE_2D_ExitSubBgs
 * address: 0x021E57A4
 * packet: pkt_ov119_021E57A4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_FreeTiles 0x02040DA8 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 */
#include "../include/Obj00001.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern void BG_SYS_FreeTiles(u32 idx, u32 count, u32 tile);
extern void BG_SYS_FreeLayerBuf(u32 i);
void POKETRADE_2D_ExitSubBgs(int p)
{
    if (((struct Obj00001 *)p)->f11EB == 1) {
        BG_SYS_FreeTiles(4, 1, 0);
        BG_SYS_FreeTiles(6, 1, 0);
        BG_SYS_FreeLayerBuf(4);
        BG_SYS_FreeLayerBuf(5);
        BG_SYS_FreeLayerBuf(6);
        BG_SYS_FreeLayerBuf(7);
        ((struct Obj00001 *)p)->f11EB = 0;
    }
}
