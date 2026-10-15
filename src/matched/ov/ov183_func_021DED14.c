/*
 * function: func_021DED14
 * address: 0x021DED14
 * packet: pkt_ov183_021DED14
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_FADE_Start 0x021FE784 thumb ov186
 *   BR_FADE_GetResult 0x021FE7B0 thumb ov186
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb ov186
 *   func_021DEDB4 0x021DEDB4 thumb ov183
 */
#include "../include/Obj14430.h"
#include "../include/Obj24601.h"
#include "../include/Obj24602.h"
extern void BR_FADE_Start(int a, int b, int c, int d);
extern int BR_FADE_GetResult(int *);
extern int *BR_UTIL_SetTaskStep(int *p, int v);
extern void func_021DEDB4(int *task, int *state, char *p);
void func_021DED14(int *a, int *state, char *p)
{
    switch (*state) {
    case 0:
        BR_FADE_Start((int)(((struct Obj24601 *)(*(char * *)&((struct Obj14430 *)p)->f108))->f8), 2, 3, 0);
        *state = 1;
        break;
    case 1:
        if (BR_FADE_GetResult(*(int * *)&((struct Obj24602 *)(*(char * *)&((struct Obj14430 *)p)->f108))->f8) != 0) *state = 2;
        break;
    case 2:
        BR_UTIL_SetTaskStep(a, (int)func_021DEDB4);
        break;
    }
}
