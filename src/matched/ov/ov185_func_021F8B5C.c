/*
 * function: BR_POKESEARCH_ChangePageTask
 * address: 0x021F8B5C
 * packet: pkt_ov185_021F8B5C
 * region: ov185
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * abi: 021F8BBC/021F8BD6 load r1 for BR_POKESEARCH_DestroyText, retained despite unused callee input.
 * symbols:
 *   BR_FADE_Start 0x021FE784 thumb ov186
 *   BR_FADE_GetResult 0x021FE7B0 thumb ov186
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb ov186
 *   BR_POKESEARCH_CreateSidebar 0x021F8D18 thumb ov185
 *   BR_POKESEARCH_ShowBg 0x021F8D5C thumb ov185
 *   BR_POKESEARCH_CreateText 0x021F8E90 thumb ov185
 *   BR_POKESEARCH_DestroyText 0x021F8EE8 thumb ov185
 *   BR_POKESEARCH_HandleTouch 0x021F86E4 thumb ov185
 */
#include "../include/Obj01568.h"
extern void BR_FADE_Start(int a, int b, int c, int d);
extern int BR_FADE_GetResult(int *);
extern int *BR_UTIL_SetTaskStep(int *p, int v);
extern void BR_POKESEARCH_CreateSidebar(char *,int *);
extern void BR_POKESEARCH_ShowBg(char *p, char *q);
extern void BR_POKESEARCH_CreateText(char *,int *);
extern void BR_POKESEARCH_DestroyText(char *,int *);
extern void BR_POKESEARCH_HandleTouch(int,int,char *);
void BR_POKESEARCH_ChangePageTask(int *task,int *state,char *p)
{
    switch (*state) {
    case 0:
        if (((struct Obj01568 *)p)->f20) BR_FADE_Start(**(int * *)&((struct Obj01568 *)p)->f34,1,1,1);
        else BR_FADE_Start(**(int * *)&((struct Obj01568 *)p)->f34,2,1,1);
        *state=1;break;
    case 1: if (BR_FADE_GetResult(*(int **)*(int * *)&((struct Obj01568 *)p)->f34)) *state=2;break;
    case 2:
        if (((struct Obj01568 *)p)->f20) {
            BR_POKESEARCH_DestroyText(p,*(int * *)&((struct Obj01568 *)p)->f34);
            BR_POKESEARCH_ShowBg(p,(char *)(*(int * *)&((struct Obj01568 *)p)->f34));
            BR_POKESEARCH_CreateSidebar(p,*(int * *)&((struct Obj01568 *)p)->f34);
        } else {
            BR_POKESEARCH_DestroyText(p,*(int * *)&((struct Obj01568 *)p)->f34);
            BR_POKESEARCH_ShowBg(p,(char *)(*(int * *)&((struct Obj01568 *)p)->f34));
            BR_POKESEARCH_CreateText(p,*(int * *)&((struct Obj01568 *)p)->f34);
        }
        *state=3;break;
    case 3:
        if (((struct Obj01568 *)p)->f20) BR_FADE_Start(**(int * *)&((struct Obj01568 *)p)->f34,1,1,0);
        else BR_FADE_Start(**(int * *)&((struct Obj01568 *)p)->f34,2,1,0);
        *state=4;break;
    case 4: if (BR_FADE_GetResult(*(int **)*(int * *)&((struct Obj01568 *)p)->f34)) *state=5;break;
    case 5: BR_UTIL_SetTaskStep(task,(int)BR_POKESEARCH_HandleTouch);break;
    }
}
