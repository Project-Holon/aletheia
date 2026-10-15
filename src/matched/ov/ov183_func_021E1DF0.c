/*
 * function: BR_CODEIN_UploadStepFadeOut
 * address: 0x021E1DF0
 * packet: pkt_ov183_021E1DF0
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_FADE_Start 0x021FE784 thumb ov186
 *   BR_FADE_GetResult 0x021FE7B0 thumb ov186
 *   BR_UTIL_ClearTaskStep 0x021FD744 thumb ov186
 *   BR_PROC_SYS_PopEntry 0x021F9BA0 thumb ov186
 */
#include "../include/Obj10756.h"
#include "../include/Obj24637.h"
extern void BR_FADE_Start(int a, int b, int c, int d);
extern int BR_FADE_GetResult(int *p);
extern int BR_UTIL_ClearTaskStep(int *a);
extern void BR_PROC_SYS_PopEntry(unsigned *ctx);
void BR_CODEIN_UploadStepFadeOut(int *a,int *state,char *p)
{
    switch (*state) {
    case 0: BR_FADE_Start(**(int * *)&((struct Obj10756 *)p)->f18,2,3,1); *state=1; break;
    case 1: if (BR_FADE_GetResult((int *)(**(int * *)&((struct Obj10756 *)p)->f18))) *state=2; break;
    case 2: BR_PROC_SYS_PopEntry((unsigned int *)(((struct Obj24637 *)(*(char * *)&((struct Obj10756 *)p)->f18))->fC)); BR_UTIL_ClearTaskStep(a); break;
    }
}
