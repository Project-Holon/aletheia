/*
 * unit: yes
 * function: BR_CODEIN_SidebarStepSlideOut, BR_CODEIN_SidebarClearStep
 * address: 0x021DB61C
 * packet: pkt_ov183_021DB61C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_FADE_StartTimed 0x021FE794 thumb ov186
 *   BR_FADE_GetResult 0x021FE7B0 thumb ov186
 *   BR_SIDEBAR_ResetPositions 0x021FEE9C thumb ov186
 *   BR_SIDEBAR_StartWobble 0x021FEE4C thumb ov186
 *   BR_PROC_SYS_PushEntry 0x021F9BF4 thumb ov186
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb ov186
 *   BR_CODEIN_SidebarClearStep 0x021DB690 thumb ov183
 *   BR_UTIL_ClearTaskStep 0x021FD744 thumb ov186
 */
#include "../include/Obj06597.h"
#include "../include/Obj24535.h"
#include "../include/Obj24536.h"
#include "../include/Obj24537.h"
#include "../include/Obj24538.h"
#include "../include/Obj24539.h"
typedef unsigned int   u32;
extern void BR_FADE_StartTimed(char *p, u32 index, u32 a, u32 b, u32 c);
extern int BR_FADE_GetResult(int *);
extern void BR_SIDEBAR_ResetPositions(char *p);
extern void BR_SIDEBAR_StartWobble(char *p);
extern void BR_PROC_SYS_PushEntry(unsigned *ctx, unsigned index);
extern int *BR_UTIL_SetTaskStep(int *p, int v);
extern void BR_CODEIN_SidebarClearStep(int *);
extern int BR_UTIL_ClearTaskStep(int *a);
void BR_CODEIN_SidebarStepSlideOut(int *task, int *state, char *p)
{
    switch(*state) {
    case 0:
        BR_FADE_StartTimed((char *)(((struct Obj24535 *)(*(char * *)&((struct Obj06597 *)p)->f1C))->f8),2,3,1,1);
        *state=1;
        break;
    case 1:
        if(BR_FADE_GetResult(*(int * *)&((struct Obj24536 *)(*(char * *)&((struct Obj06597 *)p)->f1C))->f8)) *state=2;
        break;
    case 2:
        BR_SIDEBAR_ResetPositions((char *)(((struct Obj24537 *)(*(char * *)&((struct Obj06597 *)p)->f1C))->f14));
        BR_SIDEBAR_StartWobble((char *)(((struct Obj24538 *)(*(char * *)&((struct Obj06597 *)p)->f1C))->f14));
        BR_PROC_SYS_PushEntry((unsigned int *)(((struct Obj24539 *)(*(char * *)&((struct Obj06597 *)p)->f1C))->f10),1);
        BR_UTIL_SetTaskStep(task,(int)BR_CODEIN_SidebarClearStep);
        break;
    }
}
void BR_CODEIN_SidebarClearStep(int *task)
{
    BR_UTIL_ClearTaskStep((int *)task);
}
