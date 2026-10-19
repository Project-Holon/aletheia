/*
 * function: WF2DMAP_SCRDRAW_SetScroll
 * address: 0x021C5B0C
 * packet: pkt_ov127_021C5B0C
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   WF2DMAP_SCRDRAW_DrawTilesClipped 0x021C5B98 thumb ov127
 *   func_02041B6C 0x02041B6C arm
 *   BG_SYS_ChangeScroll 0x02041EE4 arm
 */
#include "../include/Obj02840.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
extern void WF2DMAP_SCRDRAW_DrawTilesClipped(void *p, int layer, unsigned int q, s16 x, s16 y);
extern void func_02041B6C(u32 bit);
extern void BG_SYS_ChangeScroll(u32 index, u32 a, u32 b);
void WF2DMAP_SCRDRAW_SetScroll(char *p,int x,int y)
{
    s16 tx,ty,rx,ry;
    tx=x/8; ty=y/8; rx=x%8; ry=y%8;
    if(tx!=((struct Obj02840 *)p)->f18||ty!=((struct Obj02840 *)p)->f1A) {
        ((struct Obj02840 *)p)->f1A=ty; ((struct Obj02840 *)p)->f18=tx;
        WF2DMAP_SCRDRAW_DrawTilesClipped(((struct Obj02840 *)p)->f4,((struct Obj02840 *)p)->f14,(unsigned int)(((struct Obj02840 *)p)->fC),-tx,-ty);
        func_02041B6C((u8)(((struct Obj02840 *)p)->f14));
    }
    BG_SYS_ChangeScroll((u8)(((struct Obj02840 *)p)->f14),(int)0,(int)rx);
    BG_SYS_ChangeScroll((u8)(((struct Obj02840 *)p)->f14),(int)3,(int)ry);
}
