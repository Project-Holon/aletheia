/*
 * function: BR_POKESEARCH_ExitTask
 * address: 0x021F8950
 * packet: pkt_ov185_021F8950
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
 *   BR_POKESEARCH_DestroyText 0x021F8EE8 thumb ov185
 *   BR_POKESEARCH_ShowBg 0x021F8D5C thumb ov185
 *   BR_POKESEARCH_DestroyDetail 0x021F8E60 thumb ov185
 *   BR_POKESEARCH_CreateSearch 0x021F8EFC thumb ov185
 */
#include "../include/Obj00278.h"
extern void BR_FADE_Start(int a, int b, int c, int d);
extern int BR_FADE_GetResult(int *);
extern int *BR_UTIL_SetTaskStep(int *p, int v);
extern void BR_POKESEARCH_MainTask(int,int,char *);
extern void BR_POKESEARCH_DestroyText(char *,int *);
extern void BR_POKESEARCH_ShowBg(char *p, char *q);
extern void BR_POKESEARCH_DestroyDetail(char *p, char *q);
extern void BR_POKESEARCH_CreateSearch(char *,int *);
void BR_POKESEARCH_ExitTask(int *sys,int *state,char *p)
{
    switch(*state) {
    case 0:
        if(((struct Obj00278 *)p)->f20) BR_FADE_Start(**(int * *)&((struct Obj00278 *)p)->f34,4,3,1);
        else BR_FADE_Start(**(int * *)&((struct Obj00278 *)p)->f34,2,3,1);
        *state=1; break;
    case 1: if(BR_FADE_GetResult(*(int **)*(int * *)&((struct Obj00278 *)p)->f34)) *state=2; break;
    case 2:
        BR_POKESEARCH_DestroyText(p,*(int * *)&((struct Obj00278 *)p)->f34);
        BR_POKESEARCH_ShowBg(p,(char *)(*(int * *)&((struct Obj00278 *)p)->f34));
        BR_POKESEARCH_DestroyDetail(p,(char *)(*(int * *)&((struct Obj00278 *)p)->f34));
        BR_POKESEARCH_CreateSearch(p,*(int * *)&((struct Obj00278 *)p)->f34);
        *state=3; break;
    case 3:
        if(((struct Obj00278 *)p)->f20) BR_FADE_Start(**(int * *)&((struct Obj00278 *)p)->f34,4,3,0);
        else BR_FADE_Start(**(int * *)&((struct Obj00278 *)p)->f34,2,3,0);
        *state=4; break;
    case 4: if(BR_FADE_GetResult(*(int **)*(int * *)&((struct Obj00278 *)p)->f34)) *state=5; break;
    case 5: BR_UTIL_SetTaskStep(sys,(int)BR_POKESEARCH_MainTask); break;
    }
}
