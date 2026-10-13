/*
 * function: P_STA_SKILL_SetCursor
 * address: 0x021DB468
 * packet: pkt_ov131_021DB468
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: repeat CLACT_SetActorDrawEnable in both arms to retain branch to next.
 * symbols:
 *   P_STA_SKILL_GetSlotPos 0x021DBA54 thumb ov131
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   P_STA_SKILL_SetSlotAnim 0x021DBA78 thumb ov131
 *   P_STA_SKILL_RefreshMoveDetail 0x021D9EE8 thumb ov131
 */
#include "../include/Obj00536.h"
typedef unsigned char u8;
extern void P_STA_SKILL_GetSlotPos(unsigned char *p, unsigned short *o);
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, unsigned int which);
typedef unsigned int   u32;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void P_STA_SKILL_SetSlotAnim(u8 *,int);
extern void P_STA_SKILL_RefreshMoveDetail(u8 *,u8 *);
void P_STA_SKILL_SetCursor(u8 *a,u8 *b,u8 c,int d) {
    u8 box[4];
    if(a[28]==0) {
        P_STA_SKILL_GetSlotPos(b+176+c*24,(short unsigned int *)box);
        CLACT_AddActorSurfacePos(((struct Obj00536 *)b)->f98,(const struct Vec2 *)box,0);
        CLACT_SetActorDrawEnable(((struct Obj00536 *)b)->f98,0);
    } else CLACT_SetActorDrawEnable(((struct Obj00536 *)b)->f98,0);
    if(b[41]!=b[42] || ((struct Obj00536 *)b)->f14==0) {
        if(b[41]!=255) P_STA_SKILL_SetSlotAnim(b+176+b[41]*24,0);
    } else P_STA_SKILL_SetSlotAnim(b+176+b[41]*24,2);
    P_STA_SKILL_SetSlotAnim(b+176+c*24,1);
    if(b[41]!=c || d==1) {
        b[41]=c;
        P_STA_SKILL_RefreshMoveDetail(a,b);
    }
}
