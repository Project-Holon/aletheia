/*
 * function: BR_POKESEARCH_EnterListTask
 * address: 0x021F8AA8
 * packet: pkt_ov185_021F8AA8
 * region: ov185
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_FADE_Start 0x021FE784 thumb ov186
 *   BR_FADE_GetResult 0x021FE7B0 thumb ov186
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb ov186
 *   BR_POKESEARCH_NetworkTask 0x021F8790 thumb ov185
 *   BR_POKESEARCH_DestroySearch 0x021F8F58 thumb ov185
 *   BR_POKESEARCH_CreateMsgbox 0x021F8F88 thumb ov185
 *   BR_UTIL_StartEffect 0x021FD860 thumb ov186
 */
#include "../include/Obj04582.h"
extern void BR_FADE_Start(int a, int b, int c, int d);
extern int BR_FADE_GetResult(int *);
extern int *BR_UTIL_SetTaskStep(int *p, int v);
extern void BR_POKESEARCH_NetworkTask(int *task, unsigned *state, char *p);
extern void BR_POKESEARCH_DestroySearch(char *p, char *q);
extern void BR_POKESEARCH_CreateMsgbox(char *,int *);
extern void BR_UTIL_StartEffect(void *,int,int *);
void BR_POKESEARCH_EnterListTask(int *sys,int *state,char *p)
{
    int pair[2];
    switch(*state) {
    case 0: BR_FADE_Start(**(int * *)&((struct Obj04582 *)p)->f34,2,3,1); *state=1; break;
    case 1: if(BR_FADE_GetResult(*(int **)*(int * *)&((struct Obj04582 *)p)->f34)) *state=2; break;
    case 2:
        BR_POKESEARCH_DestroySearch(p,(char *)(*(int * *)&((struct Obj04582 *)p)->f34));
        BR_POKESEARCH_CreateMsgbox(p,*(int * *)&((struct Obj04582 *)p)->f34);
        pair[0]=0x80;pair[1]=0x60;
        BR_UTIL_StartEffect(((struct Obj04582 *)p)->f38,4,pair); *state=3; break;
    case 3: BR_FADE_Start(**(int * *)&((struct Obj04582 *)p)->f34,2,3,0); *state=4; break;
    case 4: if(BR_FADE_GetResult(*(int **)*(int * *)&((struct Obj04582 *)p)->f34)) *state=5; break;
    case 5: BR_UTIL_SetTaskStep(sys,(int)BR_POKESEARCH_NetworkTask); break;
    }
}
