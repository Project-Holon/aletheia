/*
 * function: BR_CODEIN_SidebarStepSlideIn
 * address: 0x021DB594
 * packet: pkt_ov183_021DB594
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: enum mask local materializes one before the call; int mask left nine bytes different
 * symbols:
 *   BR_SIDEBAR_StartSlide 0x021FEE74 thumb ov186
 *   BR_FADE_StartTimed 0x021FE794 thumb ov186
 *   BR_FADE_GetResult 0x021FE7B0 thumb ov186
 *   BR_PROC_SYS_PopEntry 0x021F9BA0 thumb ov186
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb ov186
 *   BR_CODEIN_SidebarClearStep 0x021DB690 thumb ov183
 */
#include "../include/Obj05470.h"
#include "../include/Obj24531.h"
#include "../include/Obj24532.h"
#include "../include/Obj24533.h"
#include "../include/Obj24534.h"
typedef unsigned int   u32;
extern void BR_SIDEBAR_StartSlide(char *p);
extern void BR_FADE_StartTimed(char *p, u32 index, u32 a, u32 b, u32 c);
extern int BR_FADE_GetResult(int *);
extern void BR_PROC_SYS_PopEntry(unsigned *ctx);
extern int *BR_UTIL_SetTaskStep(int *p, int v);
extern void BR_CODEIN_SidebarClearStep(int *);
void BR_CODEIN_SidebarStepSlideIn(int *task, int *state, char *p)
{
    switch(*state) {
    case 0: *state=1; break;
    case 1:
        BR_SIDEBAR_StartSlide((char *)(((struct Obj24531 *)(*(char * *)&((struct Obj05470 *)p)->f1C))->f14));
        *state=2;
        break;
    case 2:
        if((((struct Obj05470 *)p)->f10)++ !=0) {
            ((struct Obj05470 *)p)->f10=0;
            BR_FADE_StartTimed((char *)(((struct Obj24532 *)(*(char * *)&((struct Obj05470 *)p)->f1C))->f8),3,3,1,26);
            *state=3;
        }
        break;
    case 3:
    {
        enum { MASK=1 } mask=MASK;
        if(BR_FADE_GetResult(*(int * *)&((struct Obj24533 *)(*(char * *)&((struct Obj05470 *)p)->f1C))->f8)&mask) *state=4;
        break;
    }
    case 4:
        BR_PROC_SYS_PopEntry(((struct Obj24534 *)(*(char * *)&((struct Obj05470 *)p)->f1C))->f10);
        BR_UTIL_SetTaskStep(task,(int)BR_CODEIN_SidebarClearStep);
        break;
    }
}
