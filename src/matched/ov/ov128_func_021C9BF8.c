/*
 * function: WF2DMAP_TOUCH_DrawSlider
 * address: 0x021C9BF8
 * packet: pkt_ov128_021C9BF8
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: the table value in r1 supplies both destination x and clip x;
 * raw u32 address arithmetic preserves base-plus-row accesses without
 * imposing unproven row or index bounds; all shifts/adds wrap at 32 bits.
 * symbols:
 *   BG_SYS_DrawTileEx 0x020410D0 arm
 *   func_02041B6C 0x02041B6C arm
 *   gWf2dmapSliderTileX 0x021CA544 data a1
 *   gWf2dmapSliderFlags 0x021CA4F7 data a1
 *   gWf2dmapSliderTileY 0x021CA554 data a1
 */
#include "../include/Obj02842.h"
#include "../include/Obj10494.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void BG_SYS_DrawTileEx(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern void func_02041B6C(u32);
extern const u8 gWf2dmapSliderTileX[],gWf2dmapSliderFlags[],gWf2dmapSliderTileY[];
void WF2DMAP_TOUCH_DrawSlider(u8 *p,u8 *q,int idx)
{
    u16 *t;
    if (((struct Obj02842 *)p)->f10==1) {
        t=*(u16 * *)&((struct Obj10494 *)q)->f178;
        BG_SYS_DrawTileEx(2,0,20,32,4,(u32)((u8 *)t+12),0,12,(u32)t[0]>>3,(u32)t[1]>>3);
    } else {
        t=*(u16 * *)&((struct Obj10494 *)q)->f178;
        BG_SYS_DrawTileEx(2,0,20,32,4,(u32)((u8 *)t+12),0,20,(u32)t[0]>>3,(u32)t[1]>>3);
    }
    if (idx==255) {
        func_02041B6C(2);
        return;
    }
    t=*(u16 * *)&((struct Obj10494 *)q)->f178;
    BG_SYS_DrawTileEx(2,*(const u8 *)((u32)gWf2dmapSliderTileX+((u32)((struct Obj02842 *)p)->f10<<3)+(u32)idx),20,
        *(const u8 *)((u32)gWf2dmapSliderTileY+((u32)((struct Obj02842 *)p)->f10<<3)+(u32)idx),4,(u32)((u8 *)t+12),
        *(const u8 *)((u32)gWf2dmapSliderTileX+((u32)((struct Obj02842 *)p)->f10<<3)+(u32)idx),
        *(const u8 *)((u32)gWf2dmapSliderFlags+(u32)((struct Obj02842 *)p)->f10),(u32)t[0]>>3,(u32)t[1]>>3);
    func_02041B6C(2);
}
