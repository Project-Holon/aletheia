/*
 * function: WF2DMAP_TOUCH_DrawCursorBg
 * address: 0x021C9CCC
 * packet: pkt_ov128_021C9CCC
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_DrawTileEx 0x020410D0 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj14046.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void BG_SYS_DrawTileEx(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern void func_02041B6C(u32);
void WF2DMAP_TOUCH_DrawCursorBg(void *unused,u8 *p)
{
    u16 *q = *(u16 * *)&((struct Obj14046 *)p)->f178;
    BG_SYS_DrawTileEx(2,0,20,32,4,(u32)((u8 *)q+12),0,28,(u32)q[0]>>3,(u32)q[1]>>3);
    func_02041B6C(2);
}
