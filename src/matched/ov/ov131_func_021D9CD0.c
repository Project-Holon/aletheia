/*
 * function: P_STA_SKILL_ShowStatsPage
 * address: 0x021D9CD0
 * packet: pkt_ov131_021D9CD0
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_DrawTileEx 0x020410D0 arm
 *   func_02041B6C 0x02041B6C arm
 *   P_STA_SKILL_ApplyStatsScreen 0x021D9E44 thumb ov131
 *   P_STA_SKILL_ShowSlot 0x021DB964 thumb ov131
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 */
#include "../include/Obj00136.h"
#include "../include/Obj04512.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void BG_SYS_DrawTileEx(u32,u32,u32,u32,u8,u32,u8,u8,u8,u8);
extern void func_02041B6C(u32);
extern void P_STA_SKILL_ApplyStatsScreen(u8 *,u8 *);
typedef unsigned short u16;
struct Obj;
extern void P_STA_SKILL_ShowSlot(u8 *a, void *b, u8 *p);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
void P_STA_SKILL_ShowStatsPage(u8 *a,u8 *p)
{
    u8 i;
    BG_SYS_DrawTileEx(2,0,0,32,24,((struct Obj04512 *)p)->f34+12,0,0,32,32);
    func_02041B6C(2);
    P_STA_SKILL_ApplyStatsScreen(a,p);
    for(i=0;i<p[0x2b];i++) P_STA_SKILL_ShowSlot(a,p,p+0xb0+i*24);
    CLACT_SetActorAnimSeq(((struct Obj00136 *)a)->f17C,4);
}
