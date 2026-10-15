/*
 * function: func_021C72E4
 * address: 0x021C72E4
 * packet: pkt_ov128_021C72E4
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021C6ADC 0x021C6ADC thumb ov128
 *   BG_SYS_DrawTile 0x02041090 arm
 *   func_02040618 0x02040618 arm
 *   WF2DMAP_TOUCH_SetTopHighlight3 0x021CA16C thumb ov128
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj14035.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_021C6ADC(u8 *,u8 *,unsigned);
extern void BG_SYS_DrawTile(unsigned int index, unsigned int a1, unsigned int a2, unsigned int a3, u8 a4, u8 a5);
extern void func_02040618(unsigned,unsigned,unsigned);
extern void WF2DMAP_TOUCH_SetTopHighlight3(u8 *,int);
typedef unsigned int   u32;
extern void func_02041B6C(u32 bit);
void func_021C72E4(u8 *p,int *q,u8 *ctx)
{
    u16 *data;
    func_021C6ADC(ctx,ctx+12,0);
    data=*(u16 * *)&((struct Obj14035 *)p)->f18;
    BG_SYS_DrawTile(2,(unsigned int)((u8 *)data+12),0,0,data[0]>>3,data[1]>>3);
    func_02040618(2,0,0);
    func_02040618(2,3,0);
    if(*q==0) WF2DMAP_TOUCH_SetTopHighlight3(ctx,((struct Obj14035 *)p)->f0);
    else func_02041B6C(2);
}
