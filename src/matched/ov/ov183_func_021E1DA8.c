/*
 * function: func_021E1DA8
 * address: 0x021E1DA8
 * packet: pkt_ov183_021E1DA8
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_FADE_Start 0x021FE784 thumb ov186
 *   BR_FADE_GetResult 0x021FE7B0 thumb ov186
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb ov186
 *   func_021E1E3C 0x021E1E3C thumb ov183
 */
#include "../include/Obj14441.h"
extern void BR_FADE_Start(int a, int b, int c, int d);
extern int BR_FADE_GetResult(int *p);
extern int *BR_UTIL_SetTaskStep(int *p, int v);
extern void func_021E1E3C(int *task, int *state, char *p);
void func_021E1DA8(int a,int *state,char *p)
{
    switch (*state) {
    case 0: BR_FADE_Start(**(int * *)&((struct Obj14441 *)p)->f18,2,3,0); *state=1; break;
    case 1: if (BR_FADE_GetResult((int *)(**(int * *)&((struct Obj14441 *)p)->f18))) *state=2; break;
    case 2: BR_UTIL_SetTaskStep((int *)a,(int)func_021E1E3C); break;
    }
}
