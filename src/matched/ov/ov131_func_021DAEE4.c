/*
 * function: P_STA_SKILL_HandleKeysForget
 * address: 0x021DAEE4
 * packet: pkt_ov131_021DAEE4
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: the index re-read after the 021D6064 call is volatile (the original reloads it; a plain
 *   read is CSE'd into a callee-saved register); the B688 arm skips the shared 020061E4 call via goto.
 * symbols:
 *   func_020362DC 0x020362DC arm
 *   P_STA_SKILL_SetCursor 0x021DB468 thumb ov131
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   func_020061E4 0x020061E4 thumb
 *   P_STA_SKILL_SetSlotAnim 0x021DBA78 thumb ov131
 *   func_0204B3DC 0x0204B3DC arm
 *   P_STA_SKILL_SetNewMoveHeld 0x021DB614 thumb ov131
 *   P_STATUS_GetPokePara 0x021D6064 thumb ov131
 *   func_02017E88 0x02017E88 thumb
 *   func_0202F72C 0x0202F72C thumb
 *   P_STA_SKILL_ShowCantForgetMsg 0x021DB688 thumb ov131
 *   P_STA_SKILL_GetSlotPos 0x021DBA54 thumb ov131
 *   func_0204B404 0x0204B404 arm
 *   CLACT_RestartActorAnim 0x0204B9A0 arm
 *   P_STA_SKILL_StepCursor 0x021DB3F0 thumb ov131
 */
#include "../include/Obj00026.h"
#include "../include/Obj00132.h"
#include "../include/Obj23165.h"
#include "../include/Obj23166.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Point { s16 x,y; };
extern u32 func_020362DC(void);
extern void P_STA_SKILL_SetCursor(u8 *,u8 *,u8,int);
struct Actor;
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void func_020061E4(u32 a);
extern void P_STA_SKILL_SetSlotAnim(u8 *,int);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void P_STA_SKILL_SetNewMoveHeld(void *a, u8 *b, int c);
extern void *P_STATUS_GetPokePara(u8 *);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern u32 func_0202F72C(void *,u16,u16);
extern void P_STA_SKILL_ShowCantForgetMsg(u8 *,u8 *,int);
extern void P_STA_SKILL_GetSlotPos(unsigned char *p, unsigned short *o);
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void CLACT_RestartActorAnim(struct Actor *a);
extern void P_STA_SKILL_StepCursor(u8 *,u8 *);
int P_STA_SKILL_HandleKeysForget(u8 *a,u8 *p)
{
    struct Point pt;
    u32 r;
    u8 t;
    if(a[0x1c]==1 && func_020362DC()!=0) {
        a[0x1c]=0;
        if(((struct Obj00026 *)p)->f18==0) {
            p[0x2a]=5;
            P_STA_SKILL_SetCursor(a,p,p[0x29],0);
        }
    }
    if(func_020362DC()==2) {
        if(((struct Obj00026 *)p)->f18==0) {
            a[0x1c]=0;
            ((struct Obj00132 *)a)->f54=1;
            (*(u8 **)(a+8))[0x12]=1;
            ((struct Obj00132 *)a)->f50=2;
            CLACT_SetActorAnimSeq(((struct Obj00132 *)a)->f194,9);
            ((struct Obj00132 *)a)->f1A0=((struct Obj00132 *)a)->f194;
            func_020061E4(0x551);
            return 1;
        } else {
            a[0x1c]=0;
            P_STA_SKILL_SetSlotAnim(p+0xb0+p[0x2a]*0x18,0);
            P_STA_SKILL_SetCursor(a,p,p[0x29],0);
            func_0204B3DC(((struct Obj00026 *)p)->f9C,0);
            p[0x29]=p[0x2a];
            p[0x2a]=5;
            ((struct Obj00026 *)p)->f18=0;
            P_STA_SKILL_SetCursor(a,p,p[0x29],0);
            CLACT_SetActorAnimSeq(((struct Obj00132 *)a)->f194,9);
            P_STA_SKILL_SetNewMoveHeld(a,p,0);
            func_020061E4(0x551);
        }
    } else if(((struct Obj00026 *)p)->f18!=0) {
        if(func_020362DC()==1) {
            a[0x1c]=0;
            ((struct Obj00132 *)a)->f54=1;
            (*(u8 **)(a+8))[0x11]=p[0x2a];
            (*(u8 **)(a+8))[0x12]=0;
            ((struct Obj00026 *)p)->f20=1;
            ((struct Obj00026 *)p)->f24=1;
            *(int *)&((struct Obj00132 *)a)->f1A0=0;
            func_020061E4(0x54c);
        }
    } else if(func_020362DC()==1) {
        a[0x1c]=0;
        if(p[0x29]<4) {
            r=func_0202F72C(((struct Obj23165 *)((*(u8 * *)&((struct Obj00132 *)a)->f8)))->f8,func_02017E88(P_STATUS_GetPokePara(a),*(volatile u8 *)&((struct Obj00026 *)p)->f29+0x36,0),((struct Obj00132 *)a)->f0);
            if(r==0 || ((struct Obj00132 *)a)->f14==1) {
                if(((struct Obj23166 *)((*(u8 * *)&((struct Obj00132 *)a)->f8)))->f14==0) {
                    ((struct Obj00132 *)a)->f54=1;
                    (*(u8 **)(a+8))[0x12]=0;
                    (*(u8 **)(a+8))[0x11]=p[0x29];
                    ((struct Obj00026 *)p)->f20=1;
                    *(int *)&((struct Obj00132 *)a)->f1A0=0;
                } else {
                    ((struct Obj00026 *)p)->f18=1;
                    t=p[0x29];
                    p[0x2a]=t;
                    P_STA_SKILL_SetSlotAnim(p+0xb0+t*0x18,2);
                    p[0x29]=4;
                    P_STA_SKILL_SetCursor(a,p,p[0x29],0);
                    P_STA_SKILL_GetSlotPos(p+0xb0+p[0x2a]*0x18,(short unsigned int *)(&pt));
                    func_0204B404(((struct Obj00026 *)p)->f9C,(const struct Vec2 *)(&pt),0);
                    func_0204B3DC(((struct Obj00026 *)p)->f9C,1);
                    CLACT_RestartActorAnim(((struct Obj00026 *)p)->f9C);
                    P_STA_SKILL_SetNewMoveHeld(a,p,1);
                }
            } else {
                P_STA_SKILL_ShowCantForgetMsg(a,p,r);
                goto done;
            }
        } else {
            ((struct Obj00132 *)a)->f54=1;
            (*(u8 **)(a+8))[0x12]=1;
            ((struct Obj00026 *)p)->f20=1;
            *(int *)&((struct Obj00132 *)a)->f1A0=0;
        }
        func_020061E4(0x54c);
done:
        return 1;
    } else {
        if(func_020362DC()==0x40 || func_020362DC()==0x80) {
            P_STA_SKILL_StepCursor(a,p);
            return 1;
        }
    }
    return 0;
}
