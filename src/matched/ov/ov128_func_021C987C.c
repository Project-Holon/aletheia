/*
 * function: WF2DMAP_TOUCH_CloseEditScreen
 * address: 0x021C987C
 * packet: pkt_ov128_021C987C
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   Wf2dmapFriend_SetActorDrawEnable 0x021C6DD8 thumb ov128
 *   WF2DMAP_TOUCH_DrawCursorBg 0x021C9CCC thumb ov128
 *   WF2DMAP_TOUCH_ClearTrainerScreens 0x021C9BC4 thumb ov128
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   func_02041B6C 0x02041B6C arm
 *   BG_SYS_DrawTile 0x02041090 arm
 *   Wf2dmapFriend_ClearWindow 0x021C6B38 thumb ov128
 *   WF2DMAP_TOUCH_ReleaseActor 0x021CA4C8 thumb ov128
 */
#include "../include/Obj00773.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void Wf2dmapFriend_SetActorDrawEnable(u8 *p, u32 a);
extern void WF2DMAP_TOUCH_DrawCursorBg(void *,u8 *);
extern void WF2DMAP_TOUCH_ClearTrainerScreens(u32 p);
extern void BG_SYS_SetTileEntry(u32,int,int,int,u8,u8,u8);
extern void func_02041B6C(u32);
extern void BG_SYS_DrawTile(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5);
extern void Wf2dmapFriend_ClearWindow(u8 *p);
extern void WF2DMAP_TOUCH_ReleaseActor(int *p);
void WF2DMAP_TOUCH_CloseEditScreen(u8 *p,u8 *q)
{
    u16 *t;
    Wf2dmapFriend_SetActorDrawEnable(q,0);
    WF2DMAP_TOUCH_DrawCursorBg(p,q);
    WF2DMAP_TOUCH_ClearTrainerScreens((u32)p);
    BG_SYS_SetTileEntry(2,0,0,0,32,32,0);
    func_02041B6C(2);
    t=*(u16 * *)&((struct Obj00773 *)p)->f10C;
    BG_SYS_DrawTile(0,(u32)((u8 *)t+12),0,0,(u32)t[0]>>3,(u32)t[1]>>3);
    func_02041B6C(0);
    Wf2dmapFriend_ClearWindow(q);
    WF2DMAP_TOUCH_ReleaseActor((int *)p);
}
