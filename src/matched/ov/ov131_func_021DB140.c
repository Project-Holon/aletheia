/*
 * function: P_STA_SKILL_HandleTouchForget
 * address: 0x021DB140
 * packet: pkt_ov131_021DB140
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: callee func_0202F72C filed as arm9 witness (pkt_0202F72C).
 * interface: C08 returns -1 or 0..4 for this five-record list (full
 *   C08/BBC/ADC bodies and nonwriting A70/AA4 predicates, retained evidence).
 *   BA14 writes every four-byte record; the sixth first byte is the sentinel.
 *   BA54 stores both output halfwords before returning. Only sentinel byte
 *   touch[5][0] is read; no other bytes of its partial record are consumed.
 * arithmetic: loop i is initialized zero and guarded <5; selected index
 *   admitted after -1 rejection is 0..4, so index+54 and index*24 are safe.
 *   Secondary record selector is an ldrb, 0..255, product <=6120. No menu
 *   domain, default output value, volatile or narrowed full-word result.
 * symbols:
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   P_STA_SKILL_SetSlotAnim 0x021DBA78 thumb ov131
 *   P_STA_SKILL_SetCursor 0x021DB468 thumb ov131
 *   P_STA_SKILL_RefreshMoveDetail 0x021D9EE8 thumb ov131
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   P_STA_SKILL_SetNewMoveHeld 0x021DB614 thumb ov131
 *   P_STA_SKILL_GetSlotTouchRect 0x021DBA14 thumb ov131
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   P_STATUS_GetPokePara 0x021D6064 thumb ov131
 *   func_02017E88 0x02017E88 thumb
 *   func_0202F72C 0x0202F72C thumb
 *   P_STA_SKILL_GetSlotPos 0x021DBA54 thumb ov131
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_RestartActorAnim 0x0204B9A0 arm
 *   P_STA_SKILL_ShowCantForgetMsg 0x021DB688 thumb ov131
 */
#include "../include/Obj00026.h"
#include "../include/Obj00132.h"
#include "../include/Obj23167.h"
#include "../include/Obj23168.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Actor;
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void P_STA_SKILL_SetSlotAnim(u8 *,int);
extern void P_STA_SKILL_SetCursor(u8 *,u8 *,u8,int);
extern void P_STA_SKILL_RefreshMoveDetail(u8 *,u8 *);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void P_STA_SKILL_SetNewMoveHeld(void *,u8 *,int);
extern void P_STA_SKILL_GetSlotTouchRect(u8 *,u8 *);
extern int TOUCHPANEL_HitTrg(const void *p);
extern void *P_STATUS_GetPokePara(u8 *);
extern int func_02017E88(void *,int,int);
extern u32 func_0202F72C(void *a, u16 b, u16 c);
struct Vec2;
extern void P_STA_SKILL_GetSlotPos(unsigned char *p, unsigned short *o);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void CLACT_RestartActorAnim(struct Actor *);
extern void P_STA_SKILL_ShowCantForgetMsg(u8 *,u8 *,int);

void P_STA_SKILL_HandleTouchForget(u8 *a,u8 *b)
{
    u8 i;
    int index,result;
    u16 point[2];
    u8 touch[6][4];
    if (((struct Obj00132 *)a)->f24==7) {
        if (((struct Obj00026 *)b)->f18==0) {
            ((struct Obj00132 *)a)->f54=1;
            (*(u8 **)(a+8))[18]=1;
            ((struct Obj00132 *)a)->f50=2;
            CLACT_SetActorAnimSeq(((struct Obj00132 *)a)->f194,9);
            ((struct Obj00132 *)a)->f1A0=((struct Obj00132 *)a)->f194;
            GFL_USE_PlaySeDefaultVolume(1361);
            return;
        }
        a[28]=1;
        P_STA_SKILL_SetSlotAnim(b+176+b[42]*24,0);
        P_STA_SKILL_SetCursor(a,b,b[41],0);
        CLACT_SetActorDrawEnable(((struct Obj00026 *)b)->f9C,0);
        b[42]=5;
        ((struct Obj00026 *)b)->f18=0;
        if (b[43]==5) {
            P_STA_SKILL_SetCursor(a,b,4,0);
            P_STA_SKILL_RefreshMoveDetail(a,b);
        } else {
            b[41]=255;
            P_STA_SKILL_SetCursor(a,b,255,0);
        }
        P_STA_SKILL_SetNewMoveHeld(a,b,0);
        GFL_USE_PlaySeDefaultVolume(1361);
        return;
    }
    for (i=0;i<5;i++) P_STA_SKILL_GetSlotTouchRect(b+176+i*24,touch[i]);
    touch[5][0]=255;
    index=TOUCHPANEL_HitTrg(touch[0]);
    if (index==-1) return;
    if (((struct Obj00026 *)b)->f18==0) {
        if (index<4) {
            if (func_02017E88(P_STATUS_GetPokePara(a),index+54,0)==0) return;
            result=func_0202F72C(((struct Obj23167 *)(*(u8 * *)&((struct Obj00132 *)a)->f8))->f8,func_02017E88(P_STATUS_GetPokePara(a),index+54,0),((struct Obj00132 *)a)->f0);
            if (result==0 || ((struct Obj00132 *)a)->f14==1) {
                if (((struct Obj23168 *)(*(u8 * *)&((struct Obj00132 *)a)->f8))->f14==0) {
                    ((struct Obj00132 *)a)->f54=1;
                    (*(u8 **)(a+8))[18]=0;
                    (*(u8 **)(a+8))[17]=index;
                    ((struct Obj00026 *)b)->f20=1;
                    *(int *)&((struct Obj00132 *)a)->f1A0=0;
                    GFL_USE_PlaySeDefaultVolume(1356);
                    P_STA_SKILL_SetCursor(a,b,index,0);
                    P_STA_SKILL_SetSlotAnim(b+176+index*24,2);
                    return;
                }
                a[28]=1;
                ((struct Obj00026 *)b)->f18=1;
                P_STA_SKILL_SetCursor(a,b,index,0);
                b[42]=index;
                P_STA_SKILL_SetSlotAnim(b+176+index*24,2);
                b[41]=4;
                P_STA_SKILL_SetCursor(a,b,b[41],0);
                P_STA_SKILL_GetSlotPos(b+176+b[42]*24,(short unsigned int *)point);
                CLACT_AddActorSurfacePos(((struct Obj00026 *)b)->f9C,(const struct Vec2 *)point,0);
                CLACT_SetActorDrawEnable(((struct Obj00026 *)b)->f9C,1);
                CLACT_RestartActorAnim(*(struct Actor * *)&((struct Obj00026 *)b)->f9C);
                P_STA_SKILL_SetNewMoveHeld(a,b,1);
                GFL_USE_PlaySeDefaultVolume(1356);
                return;
            }
            P_STA_SKILL_SetCursor(a,b,index,0);
            b[42]=index;
            P_STA_SKILL_SetSlotAnim(b+176+index*24,2);
            P_STA_SKILL_ShowCantForgetMsg(a,b,result);
            return;
        }
        P_STA_SKILL_SetCursor(a,b,index,0);
        a[28]=1;
        ((struct Obj00132 *)a)->f54=1;
        (*(u8 **)(a+8))[18]=1;
        ((struct Obj00026 *)b)->f20=1;
        *(int *)&((struct Obj00132 *)a)->f1A0=0;
        GFL_USE_PlaySeDefaultVolume(1356);
        return;
    }
    if (index==4) {
        a[28]=1;
        ((struct Obj00132 *)a)->f54=1;
        (*(u8 **)(a+8))[17]=b[42];
        (*(u8 **)(a+8))[18]=0;
        ((struct Obj00026 *)b)->f20=1;
        ((struct Obj00026 *)b)->f24=1;
        *(int *)&((struct Obj00132 *)a)->f1A0=0;
        GFL_USE_PlaySeDefaultVolume(1356);
    }
}
