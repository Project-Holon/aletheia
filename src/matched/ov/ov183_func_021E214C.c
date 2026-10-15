/*
 * function: BR_CODEIN_SaveStepFadeIn
 * address: 0x021E214C
 * packet: pkt_ov183_021E214C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_FADE_Start 0x021FE784 thumb ov186
 *   BR_FADE_GetResult 0x021FE7B0 thumb ov186
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb ov186
 *   BR_CODEIN_SaveStepVideo 0x021E21E0 thumb ov183
 */
#include "../include/Obj14442.h"
#include "../include/Obj24649.h"
#include "../include/Obj24650.h"
extern void BR_FADE_Start(int a, int b, int c, int d);
extern int BR_FADE_GetResult(int *);
extern int *BR_UTIL_SetTaskStep(int *p, int v);
extern void BR_CODEIN_SaveStepVideo(int task, int *state, char *p);
void BR_CODEIN_SaveStepFadeIn(int *task,int *state,char *p)
{
    switch (*state) {
    case 0: BR_FADE_Start(((struct Obj24649 *)(*(char * *)&((struct Obj14442 *)p)->f20))->f4,2,3,0); *state=1; break;
    case 1: if (BR_FADE_GetResult(*(int * *)&((struct Obj24650 *)(*(char * *)&((struct Obj14442 *)p)->f20))->f4)) *state=2; break;
    case 2: BR_UTIL_SetTaskStep(task,(int)BR_CODEIN_SaveStepVideo); break;
    }
}
