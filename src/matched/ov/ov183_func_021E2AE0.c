/*
 * function: BR_CODEIN_MenuStepInput
 * address: 0x021E2AE0
 * packet: pkt_ov183_021E2AE0
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Declare scalar locals before Pair; assign the returned Pair as a whole to p+0x4C. Separate word stores produced the wrong stack/copy schedule.
 * symbols:
 *   BR_CODEIN_CopySoclResource 0x021E2E60 thumb ov183
 *   BR_CODEIN_CallStoredFnA 0x021E2E30 thumb ov183
 *   BR_CODEIN_CallStoredFnB 0x021E2E48 thumb ov183
 *   BR_CODEIN_HitTestOptionA 0x021E31E8 thumb ov183
 *   BR_CODEIN_HitTestOptionB 0x021E3228 thumb ov183
 *   BR_FADE_Start 0x021FE784 thumb ov186
 *   BR_FADE_GetResult 0x021FE7B0 thumb ov186
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb ov186
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   BR_CODEIN_MenuStepSave 0x021E2C2C thumb ov183
 *   BR_CODEIN_MenuStep 0x021E2910 thumb ov183
 */
#include "../include/Obj03334.h"
typedef struct Pair {int a,b;} Pair;
extern void BR_CODEIN_CopySoclResource(Pair *);
extern void BR_CODEIN_CallStoredFnA(char *,int,int);
extern void BR_CODEIN_CallStoredFnB(char *p, int a, int b);
extern int BR_CODEIN_HitTestOptionA(char *,int,int),BR_CODEIN_HitTestOptionB(char *,int,int);
extern void BR_FADE_Start(int,int,int,int);
typedef unsigned int   u32;
extern int BR_FADE_GetResult(int *);
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern int *BR_UTIL_SetTaskStep(int *p, int v);
extern void BR_CODEIN_MenuStepSave(int *task, unsigned *state, char *p);
extern void BR_CODEIN_MenuStep(int *task, int *state, char *p);
void BR_CODEIN_MenuStepInput(int *task,unsigned *state,char *p)
{
    unsigned x,y;
    Pair a;
    switch(*state) {
    case 0:
        BR_CODEIN_CopySoclResource(&a);
        *(Pair *)(p+0x4c)=a;
        BR_CODEIN_CallStoredFnA(p+0x4c,(int)p,*(int *)&((struct Obj03334 *)p)->f3C);
        ++*state; break;
    case 1:
        BR_FADE_Start(**(int * *)&((struct Obj03334 *)p)->f3C,2,3,0);
        ++*state; break;
    case 2:
        if(BR_FADE_GetResult(**(int ** *)&((struct Obj03334 *)p)->f3C)) ++*state;
        break;
    case 3:
        if(TOUCHPANEL_GetPointTrg(&x,&y)) {
            if(BR_CODEIN_HitTestOptionA(p,x,y)) *state=4;
            if(BR_CODEIN_HitTestOptionB(p,x,y)) *state=7;
        }
        break;
    case 4:
        BR_FADE_Start(**(int * *)&((struct Obj03334 *)p)->f3C,2,3,1);
        ++*state; break;
    case 5:
        if(BR_FADE_GetResult(**(int ** *)&((struct Obj03334 *)p)->f3C)) ++*state;
        break;
    case 6:
        BR_CODEIN_CallStoredFnB(p+0x4c,(int)p,(int)(*(char * *)&((struct Obj03334 *)p)->f3C));
        BR_UTIL_SetTaskStep(task,(int)BR_CODEIN_MenuStepSave); break;
    case 7:
        BR_FADE_Start(**(int * *)&((struct Obj03334 *)p)->f3C,2,3,1);
        ++*state; break;
    case 8:
        if(BR_FADE_GetResult(**(int ** *)&((struct Obj03334 *)p)->f3C)) ++*state;
        break;
    case 9:
        BR_CODEIN_CallStoredFnB(p+0x4c,(int)p,(int)(*(char * *)&((struct Obj03334 *)p)->f3C));
        BR_UTIL_SetTaskStep(task,(int)BR_CODEIN_MenuStep); break;
    }
}
