/*
 * function: BR_POKESEARCH_RefreshTask
 * address: 0x021F8A0C
 * packet: pkt_ov185_021F8A0C
 * region: ov185
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_FADE_Start 0x021FE784 thumb ov186
 *   BR_FADE_GetResult 0x021FE7B0 thumb ov186
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb ov186
 *   BR_POKESEARCH_MainTask 0x021F86A4 thumb ov185
 *   BR_POKESEARCH_DestroyMsgbox 0x021F8FB0 thumb ov185
 *   BR_POKESEARCH_CreateSearch 0x021F8EFC thumb ov185
 *   BR_POKESEARCH_UpdatePrint 0x021FFE34 thumb ov186
 */
#include "../include/Obj00278.h"
extern void BR_FADE_Start(int a, int b, int c, int d);
extern int BR_FADE_GetResult(int *);
extern int *BR_UTIL_SetTaskStep(int *p, int v);
extern void BR_POKESEARCH_MainTask(int,int,char *);
extern void BR_POKESEARCH_DestroyMsgbox(char *p, char *a1);
extern void BR_POKESEARCH_CreateSearch(char *,int *);
extern unsigned BR_POKESEARCH_UpdatePrint(char *p);
void BR_POKESEARCH_RefreshTask(int *sys,int *state,char *p)
{
    switch(*state) {
    case 0: BR_FADE_Start(**(int * *)&((struct Obj00278 *)p)->f34,2,3,1); *state=1; break;
    case 1: if(BR_FADE_GetResult(*(int **)*(int * *)&((struct Obj00278 *)p)->f34)) *state=2; break;
    case 2: BR_POKESEARCH_DestroyMsgbox(p,(char *)(*(int * *)&((struct Obj00278 *)p)->f34)); BR_POKESEARCH_CreateSearch(p,*(int * *)&((struct Obj00278 *)p)->f34); *state=3; break;
    case 3: if(BR_POKESEARCH_UpdatePrint((char *)(*(int *)&((struct Obj00278 *)p)->f0))) {BR_FADE_Start(**(int * *)&((struct Obj00278 *)p)->f34,2,3,0); *state=4;} break;
    case 4: if(BR_FADE_GetResult(*(int **)*(int * *)&((struct Obj00278 *)p)->f34)) *state=5; break;
    case 5: BR_UTIL_SetTaskStep(sys,(int)BR_POKESEARCH_MainTask); break;
    }
}
