/*
 * function: P_STA_SKILL_HandleKeys
 * address: 0x021DA998
 * packet: pkt_ov131_021DA998
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: original shared return0 branch is goto out; selected byte local
 *   preserves the loaded value across its neighbouring selector store.
 * semantics: every key poll is independent; selector bytes retain their
 *   full0..255 domain, so promoted selector*24 is at most6120. No menu
 *   bound is assumed. BA54 unconditionally writes both point halfwords
 *   at BA5E/BA6A before4B404 reads them; no default or success assumption.
 * interfaces: own matched callees, else own-region matched callers.
 *   362DC own body returns a full-word pointer payload; this caller uses
 *   full r0 as a scalar comparison, retained as u32. No argument narrowed
 *   beyond original/callee width. All original call/store order retained.
 * symbols:
 *   KEY_GetTrg 0x020362DC arm
 *   P_STATUS_SetInputEnable 0x021D5A9C thumb ov131
 *   P_STA_SKILL_SetCursor 0x021DB468 thumb ov131
 *   P_STA_SKILL_RefreshMoveDetail 0x021D9EE8 thumb ov131
 *   P_STA_SKILL_PrintStatsPage 0x021D9E30 thumb ov131
 *   P_STA_SKILL_SetSlotAnim 0x021DBA78 thumb ov131
 *   P_STA_SKILL_GetSlotPos 0x021DBA54 thumb ov131
 *   P_STA_SKILL_SwapMoves 0x021DB508 thumb ov131
 *   P_STA_SKILL_StepCursor 0x021DB3F0 thumb ov131
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_RestartActorAnim 0x0204B9A0 arm
 */
#include "../include/Obj00026.h"
#include "../include/Obj00132.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Obj;
struct Actor;
struct Vec2 { s16 x,y; };
extern u32 KEY_GetTrg(void);
extern void P_STATUS_SetInputEnable(char *,int);
extern void P_STA_SKILL_SetCursor(u8 *,u8 *,u8,int);
extern void P_STA_SKILL_RefreshMoveDetail(u8 *,u8 *);
extern void P_STA_SKILL_PrintStatsPage(void *a, int b);
extern void P_STA_SKILL_SetSlotAnim(u8 *,int);
extern void P_STA_SKILL_GetSlotPos(unsigned char *p, unsigned short *o);
extern void P_STA_SKILL_SwapMoves(u8 *,u8 *,u32,u32);
extern void P_STA_SKILL_StepCursor(u8 *,u8 *);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void CLACT_SetActorAnimSeq(struct Obj *,u16);
extern void CLACT_SetActorDrawEnable(struct Obj *,u32);
extern void CLACT_AddActorSurfacePos(struct Obj *,const struct Vec2 *,u32);
extern void CLACT_RestartActorAnim(struct Actor *);
int P_STA_SKILL_HandleKeys(u8 *a,u8 *b)
{
    struct Vec2 point;
    if (((struct Obj00026 *)b)->f1C==1) return 0;
    if (((struct Obj00132 *)a)->f44==1) {
        if (KEY_GetTrg()!=1) goto out;
            b[41]=0;
            a[28]=0;
            P_STATUS_SetInputEnable((char *)a,0);
            P_STA_SKILL_SetCursor(a,b,b[41],0);
            P_STA_SKILL_RefreshMoveDetail(a,b);
            GFL_USE_PlaySeDefaultVolume(1356);
            return 1;
    } else {
        if (KEY_GetTrg()==2 && ((struct Obj00026 *)b)->f14==0) {
            P_STATUS_SetInputEnable((char *)a,1);
            CLACT_SetActorAnimSeq(*(struct Obj * *)&((struct Obj00132 *)a)->f194,9);
            P_STA_SKILL_SetSlotAnim(b+176+b[41]*24,0);
            CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj00026 *)b)->f98,0);
            P_STA_SKILL_PrintStatsPage(a,(int)b);
            a[28]=0;
            GFL_USE_PlaySeDefaultVolume(1361);
            return 1;
        }
        if (a[28]==1) {
            if (KEY_GetTrg()==0) goto out;
                a[28]=0;
                b[42]=5;
                P_STA_SKILL_SetCursor(a,b,b[41],0);
                GFL_USE_PlaySeDefaultVolume(1352);
                return 1;
        } else {
            if (KEY_GetTrg()==1) {
                if ((*(u8 **)(a+8))[13]==6) goto out;
                if (((struct Obj00026 *)b)->f14==0) {
                    u8 selected;
                    ((struct Obj00026 *)b)->f14=1;
                    selected=b[41];
                    b[42]=selected;
                    P_STA_SKILL_SetSlotAnim(b+176+selected*24,2);
                    P_STA_SKILL_GetSlotPos(b+176+b[42]*24,(short unsigned int *)((u8 *)&point));
                    CLACT_AddActorSurfacePos(*(struct Obj * *)&((struct Obj00026 *)b)->f9C,&point,0);
                    CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj00026 *)b)->f9C,1);
                    CLACT_RestartActorAnim(*(struct Actor * *)&((struct Obj00026 *)b)->f9C);
                    GFL_USE_PlaySeDefaultVolume(1356);
                } else {
                    if (b[42]!=b[41]) {
                        P_STA_SKILL_SwapMoves(a,b,b[42],b[41]);
                        GFL_USE_PlaySeDefaultVolume(1357);
                    } else {
                        ((struct Obj00026 *)b)->f14=0;
                        P_STA_SKILL_SetCursor(a,b,b[41],0);
                        CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj00026 *)b)->f9C,0);
                        GFL_USE_PlaySeDefaultVolume(1356);
                    }
                }
                return 1;
            }
            if (KEY_GetTrg()==2 && ((struct Obj00026 *)b)->f14==1) {
                P_STA_SKILL_SetSlotAnim(b+176+b[42]*24,0);
                P_STA_SKILL_SetCursor(a,b,b[41],0);
                CLACT_SetActorAnimSeq(*(struct Obj * *)&((struct Obj00132 *)a)->f194,9);
                CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj00026 *)b)->f9C,0);
                ((struct Obj00026 *)b)->f14=0;
                b[42]=5;
                GFL_USE_PlaySeDefaultVolume(1361);
                return 1;
            }
            if (KEY_GetTrg()==64 || KEY_GetTrg()==128) {
                P_STA_SKILL_StepCursor(a,b);
                return 1;
            }
        }
    }
out:
    return 0;
}
