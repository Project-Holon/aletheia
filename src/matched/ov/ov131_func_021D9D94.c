/*
 * function: P_STA_SKILL_HideStatsPage
 * address: 0x021D9D94
 * packet: pkt_ov131_021D9D94
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   P_STA_SKILL_HideSlot 0x021DB9FC thumb ov131
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   func_020409B4 0x020409B4 arm
 *   BG_SYS_ClearLayerEx 0x02041570 arm
 *   func_02041B6C 0x02041B6C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 */
#include "../include/Obj10519.h"
#include "../include/Obj10520.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void P_STA_SKILL_HideSlot(void *,void *,u8 *);
extern void BG_SYS_SetTileEntry(u32,int,int,int,u8,u8,u8);
extern void func_020409B4(u32);
typedef unsigned short u16;
struct Obj;
extern void BG_SYS_ClearLayerEx(int channel, u16 val);
extern void func_02041B6C(u32);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
void P_STA_SKILL_HideStatsPage(u8 *a,u8 *p)
{
    u8 i;
    for(i=0;i<p[0x2b];i++) P_STA_SKILL_HideSlot(a,p,p+0xb0+i*24);
    BG_SYS_SetTileEntry(1,0,0,0,19,21,16);
    func_020409B4(1);
    BG_SYS_ClearLayerEx(4,0);
    func_02041B6C(4);
    CLACT_SetActorDrawEnable(((struct Obj10520 *)p)->f90,0);
    CLACT_SetActorDrawEnable(((struct Obj10520 *)p)->f94,0);
    CLACT_SetActorDrawEnable(((struct Obj10519 *)a)->f198,0);
    CLACT_SetActorDrawEnable(((struct Obj10519 *)a)->f19C,0);
    CLACT_SetActorAnimSeq(((struct Obj10519 *)a)->f17C,1);
}
