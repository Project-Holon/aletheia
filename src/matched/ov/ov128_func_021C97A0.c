/*
 * function: WF2DMAP_TOUCH_InitEditScreen
 * address: 0x021C97A0
 * packet: pkt_ov128_021C97A0
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: u16 heap keeps its word spill before the first indexed load.
 * symbols:
 *   Wf2dmapFriend_PrintMyStatus 0x021C6BCC thumb ov128
 *   Wf2dmapFriend_DrawText 0x021C6ADC thumb ov128
 *   BG_SYS_DrawTile 0x02041090 arm
 *   func_02041B6C 0x02041B6C arm
 *   WF2DMAP_TOUCH_CreateTrainerWidgets 0x021C991C thumb ov128
 *   WF2DMAP_TOUCH_SetValue 0x021C9BEC thumb ov128
 *   WF2DMAP_TOUCH_FindNextEntry 0x021C9D88 thumb ov128
 *   Wf2dmapFriend_RestartActorAnim 0x021C6E18 thumb ov128
 *   Wf2dmapFriend_SetActorDrawEnable 0x021C6DD8 thumb ov128
 */
#include "../include/Obj00773.h"
#include "../include/Obj00992.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void Wf2dmapFriend_PrintMyStatus(u8 *,u8 *,int,unsigned);
extern void Wf2dmapFriend_DrawText(u8 *,u8 *,unsigned);
extern void BG_SYS_DrawTile(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5);
extern void func_02041B6C(u32);
extern void WF2DMAP_TOUCH_CreateTrainerWidgets(u8 *p, u8 *q, u8 *ctx, u16 heap);
extern void WF2DMAP_TOUCH_SetValue(u16 *p, void *b, void *c, int flag, int value, int a5);
extern int WF2DMAP_TOUCH_FindNextEntry(u8 *,int);
extern void Wf2dmapFriend_RestartActorAnim(u8 *p, int i, u16 a);
extern void Wf2dmapFriend_SetActorDrawEnable(u8 *p, u32 a);
void WF2DMAP_TOUCH_InitEditScreen(u8 *p,u8 *q,u8 *r,u16 heap)
{
    u16 *t;
    Wf2dmapFriend_PrintMyStatus(r,(u8 *)q,(q+((struct Obj00992 *)q)->fB)[24],heap);
    Wf2dmapFriend_DrawText(r,r+12,13);
    t=*(u16 * *)&((struct Obj00773 *)p)->fFC;
    BG_SYS_DrawTile(0,(u32)((u8 *)t+12),0,0,(u32)t[0]>>3,(u32)t[1]>>3);
    func_02041B6C(0);
    t=*(u16 * *)&((struct Obj00773 *)p)->f104;
    BG_SYS_DrawTile(2,(u32)((u8 *)t+12),0,0,(u32)t[0]>>3,(u32)t[1]>>3);
    func_02041B6C(2);
    WF2DMAP_TOUCH_CreateTrainerWidgets(p,(u8 *)q,r,heap);
    WF2DMAP_TOUCH_SetValue((u16 *)p,(u8 *)q,r,0,*(s16 *)&((struct Obj00773 *)p)->f0,heap);
    if(WF2DMAP_TOUCH_FindNextEntry((u8 *)q,0)==1) {
        Wf2dmapFriend_RestartActorAnim(r,1,3);
        Wf2dmapFriend_RestartActorAnim(r,0,2);
    } else {
        Wf2dmapFriend_RestartActorAnim(r,1,17);
        Wf2dmapFriend_RestartActorAnim(r,0,16);
    }
    Wf2dmapFriend_SetActorDrawEnable(r,1);
}
