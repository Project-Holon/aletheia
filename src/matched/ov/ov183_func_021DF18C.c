/*
 * function: BR_CODEIN_SearchStepFade
 * address: 0x021DF18C
 * packet: pkt_ov183_021DF18C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_FADE_Start 0x021FE784 thumb ov186
 *   BR_FADE_GetResult 0x021FE7B0 thumb ov186
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb ov186
 *   BR_CODEIN_StatSetup 0x021DEB4C thumb ov183
 */
#include "../include/Obj14432.h"
#include "../include/Obj24617.h"
#include "../include/Obj24618.h"
extern void BR_FADE_Start(int a, int b, int c, int d);
extern int BR_FADE_GetResult(int *);
extern int *BR_UTIL_SetTaskStep(int *p, int v);
extern void BR_CODEIN_StatSetup(int *task, int *state, char *p);
void BR_CODEIN_SearchStepFade(int *p, int *state, char *q)
{
    switch (*state) {
    case 0:
        BR_FADE_Start((int)(*(int * *)&((struct Obj24617 *)(*(char * *)&((struct Obj14432 *)q)->f108))->f8), 2, 3, 1);
        *state = 1;
        break;
    case 1:
        if (BR_FADE_GetResult(*(int * *)&((struct Obj24618 *)(*(char * *)&((struct Obj14432 *)q)->f108))->f8) != 0) *state = 2;
        break;
    case 2:
        BR_UTIL_SetTaskStep(p, (int)BR_CODEIN_StatSetup);
        break;
    }
}
