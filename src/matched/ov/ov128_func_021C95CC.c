/*
 * function: WF2DMAP_TOUCH_StepSlideIn
 * address: 0x021C95CC
 * packet: pkt_ov128_021C95CC
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte zero padding at 021C9626 before next label 021C9628.
 * symbols:
 *   WF2DMAP_TOUCH_SetValue 0x021C9BEC thumb ov128
 *   Wf2dmapFriend_SetActorAutoAnim 0x021C6DF8 thumb ov128
 *   WF2DMAP_TOUCH_DrawSlider 0x021C9BF8 thumb ov128
 *   BG_SYS_FillScrollArea 0x02040618 arm
 */
#include "../include/Obj02842.h"
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
extern void WF2DMAP_TOUCH_SetValue(u16 *p, void *b, void *c, int flag, int value, int a5);
typedef unsigned int   u32;
extern void Wf2dmapFriend_SetActorAutoAnim(u8 *p, u32 a);
extern void WF2DMAP_TOUCH_DrawSlider(u8 *p, u8 *q, int idx);
extern void BG_SYS_FillScrollArea(u32 layer, u32 a, u32 b);
int WF2DMAP_TOUCH_StepSlideIn(u8 *p,void *a,void *b,int c)
{
    int value=((struct Obj02842 *)p)->f4;
    int offset;
    if(value>8) {
        WF2DMAP_TOUCH_SetValue((u16 *)p,a,b,0,((struct Obj02842 *)p)->f0,c);
        Wf2dmapFriend_SetActorAutoAnim(b,1);
        WF2DMAP_TOUCH_DrawSlider(p,b,255);
        return 1;
    }
    offset=(value*256)/8;
    if(((struct Obj02842 *)p)->f8==2) offset=-offset;
    BG_SYS_FillScrollArea(3,0,offset);
    ((struct Obj02842 *)p)->f4=((struct Obj02842 *)p)->f4+1;
    return 0;
}
