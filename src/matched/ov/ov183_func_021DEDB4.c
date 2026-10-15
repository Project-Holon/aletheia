/*
 * function: BR_CODEIN_StatStepMenu
 * address: 0x021DEDB4
 * packet: pkt_ov183_021DEDB4
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_CODEIN_SearchMainList 0x021DF3DC thumb ov183
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   BR_BTN_HitTestWithSound 0x021FB4B4 thumb ov186
 *   BR_UTIL_StartEffect 0x021FD860 thumb ov186
 *   BR_PROC_SYS_PopEntry 0x021F9BA0 thumb ov186
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb ov186
 *   BR_CODEIN_StatStepFadeOut 0x021DED64 thumb ov183
 *   BR_CODEIN_SearchHitBox 0x021DF8F0 thumb ov183
 *   BR_CODEIN_SearchGetHitId 0x021DF41C thumb ov183
 *   func_02034714 0x02034714 arm
 *   BR_PROC_SYS_PushEntry 0x021F9BF4 thumb ov186
 *   d_021E3964 0x021E3964 data a1
 */
#include "../include/Obj03880.h"
#include "../include/Obj24605.h"
#include "../include/Obj24606.h"
#include "../include/Obj24607.h"
#include "../include/Obj24608.h"
#include "../include/Obj24609.h"
#include "../include/Obj24610.h"
typedef unsigned int u32;
typedef unsigned short u16;
extern void BR_CODEIN_SearchMainList(char *, int);
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern int BR_BTN_HitTestWithSound(unsigned int *obj, int x, int y);
extern void BR_UTIL_StartEffect(int, int, int *);
extern void BR_PROC_SYS_PopEntry(unsigned *ctx);
extern int *BR_UTIL_SetTaskStep(int *p, int v);
extern void BR_CODEIN_StatStepFadeOut(int *p, int *state, char *q);
extern int BR_CODEIN_SearchHitBox(int x, int y);
extern int BR_CODEIN_SearchGetHitId(char *p);
extern void func_02034714(const char *, u32, const char *);
extern void BR_PROC_SYS_PushEntry(unsigned *, unsigned);
extern const char d_021E3964[];
void BR_CODEIN_StatStepMenu(int *task, int *state, char *p)
{
    u32 x,y;
    BR_CODEIN_SearchMainList(p+0x28,((struct Obj03880 *)p)->f18);
    if (TOUCHPANEL_GetPointTrg(&x,&y)) {
        if (BR_BTN_HitTestWithSound((unsigned int *)(((struct Obj03880 *)p)->f4),x,y)) {
            int args[2];
            args[0]=x; args[1]=y;
            BR_UTIL_StartEffect(((struct Obj03880 *)p)->f20,1,args);
            BR_PROC_SYS_PopEntry(((struct Obj24605 *)(*(char * *)&((struct Obj03880 *)p)->f108))->f14);
            BR_UTIL_SetTaskStep(task,(int)BR_CODEIN_StatStepFadeOut);
        }
        if (BR_CODEIN_SearchHitBox(x,y)) {
            u32 selection;
            int args[2];
            selection=BR_CODEIN_SearchGetHitId(p+0x28);
            if (selection>=((struct Obj24607 *)(*(char * *)&((struct Obj24606 *)(*(char * *)&((struct Obj03880 *)p)->f108))->f1C))->f1718)
                func_02034714(d_021E3964,0,d_021E3964);
            ((struct Obj24609 *)(*(char * *)&((struct Obj24608 *)(*(char * *)&((struct Obj03880 *)p)->f108))->f1C))->f171C=selection;
            BR_PROC_SYS_PushEntry(*(unsigned * *)&((struct Obj24610 *)(*(char * *)&((struct Obj03880 *)p)->f108))->f14,2);
            BR_UTIL_SetTaskStep(task,(int)BR_CODEIN_StatStepFadeOut);
            args[0]=x; args[1]=y;
            BR_UTIL_StartEffect(((struct Obj03880 *)p)->f20,1,args);
        }
    }
}
