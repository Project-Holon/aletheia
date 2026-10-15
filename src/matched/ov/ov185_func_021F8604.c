/*
 * function: BR_POKESEARCH_OpenTask
 * address: 0x021F8604
 * packet: pkt_ov185_021F8604
 * region: ov185
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_POKESEARCH_UpdatePrint 0x021FFE34 thumb ov186
 *   BR_FADE_Start 0x021FE784 thumb ov186
 *   BR_FADE_GetResult 0x021FE7B0 thumb ov186
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb ov186
 *   BR_POKESEARCH_MainTask 0x021F86A4 thumb ov185
 */
#include "../include/Obj10769.h"
extern unsigned BR_POKESEARCH_UpdatePrint(char *p);
extern void BR_FADE_Start(int a, int b, int c, int d);
extern int BR_FADE_GetResult(int *p);
extern int *BR_UTIL_SetTaskStep(int *p, int v);
extern void BR_POKESEARCH_MainTask(int,int,char *);
void BR_POKESEARCH_OpenTask(int a,int *state,char *p)
{
    switch (*state) {
    case 0: if (BR_POKESEARCH_UpdatePrint((char *)(((struct Obj10769 *)p)->f0))) { BR_FADE_Start(**(int * *)&((struct Obj10769 *)p)->f34,2,3,0); *state=1; } break;
    case 1: if (BR_FADE_GetResult((int *)(**(int * *)&((struct Obj10769 *)p)->f34))) *state=2; break;
    case 2: BR_UTIL_SetTaskStep((int *)a,(int)BR_POKESEARCH_MainTask); break;
    }
}
