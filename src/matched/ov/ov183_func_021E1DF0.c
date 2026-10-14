/*
 * function: func_021E1DF0
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
 *   func_021FD744 0x021FD744 thumb ov186
 *   func_021F9BA0 0x021F9BA0 thumb ov186
 */
#include "../include/Obj10756.h"
#include "../include/Obj24637.h"
extern void BR_FADE_Start(int a, int b, int c, int d);
extern int BR_FADE_GetResult(int *p);
extern int func_021FD744(int *a);
extern void func_021F9BA0(unsigned *ctx);
void func_021E1DF0(int *a,int *state,char *p)
{
    switch (*state) {
    case 0: BR_FADE_Start(**(int * *)&((struct Obj10756 *)p)->f18,2,3,1); *state=1; break;
    case 1: if (BR_FADE_GetResult((int *)(**(int * *)&((struct Obj10756 *)p)->f18))) *state=2; break;
    case 2: func_021F9BA0((unsigned int *)(((struct Obj24637 *)(*(char * *)&((struct Obj10756 *)p)->f18))->fC)); func_021FD744(a); break;
    }
}
