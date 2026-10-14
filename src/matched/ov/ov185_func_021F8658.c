/*
 * function: func_021F8658
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
 *   func_021FD744 0x021FD744 thumb ov186
 *   func_021F9BA0 0x021F9BA0 thumb ov186
 */
#include "../include/Obj08320.h"
#include "../include/Obj24722.h"
extern void BR_FADE_Start(int a, int b, int c, int d);
extern int BR_FADE_GetResult(int *p);
extern int func_021FD744(int *a);
extern void func_021F9BA0(unsigned *ctx);
void func_021F8658(int a,int *state,char *p)
{
    switch (*state) {
    case 0: BR_FADE_Start(**(int * *)&((struct Obj08320 *)p)->f34,2,3,1); *state=1; break;
    case 1: if (BR_FADE_GetResult((int *)(**(int * *)&((struct Obj08320 *)p)->f34))) *state=2; break;
    case 2: func_021FD744((int *)(((struct Obj08320 *)p)->f24)); func_021F9BA0((unsigned int *)(((struct Obj24722 *)(*(char * *)&((struct Obj08320 *)p)->f34))->f10)); break;
    }
}
