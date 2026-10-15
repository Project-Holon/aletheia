/*
 * function: BR_POKESEARCH_CloseTask
 * address: 0x021F8658
 * packet: pkt_ov185_021F8658
 * region: ov185
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
#include "../include/Obj08320.h"
#include "../include/Obj24722.h"
extern void BR_FADE_Start(int a, int b, int c, int d);
extern int BR_FADE_GetResult(int *p);
extern int BR_UTIL_ClearTaskStep(int *a);
extern void BR_PROC_SYS_PopEntry(unsigned *ctx);
void BR_POKESEARCH_CloseTask(int a,int *state,char *p)
{
    switch (*state) {
    case 0: BR_FADE_Start(**(int * *)&((struct Obj08320 *)p)->f34,2,3,1); *state=1; break;
    case 1: if (BR_FADE_GetResult((int *)(**(int * *)&((struct Obj08320 *)p)->f34))) *state=2; break;
    case 2: BR_UTIL_ClearTaskStep((int *)(((struct Obj08320 *)p)->f24)); BR_PROC_SYS_PopEntry((unsigned int *)(((struct Obj24722 *)(*(char * *)&((struct Obj08320 *)p)->f34))->f10)); break;
    }
}
