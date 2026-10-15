/*
 * function: BR_POKESEARCH_DownloadDoneTask
 * address: 0x021F88B0
 * packet: pkt_ov185_021F88B0
 * region: ov185
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_FADE_Start 0x021FE784 thumb ov186
 *   BR_FADE_GetResult 0x021FE7B0 thumb ov186
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb ov186
 *   BR_POKESEARCH_DestroyMsgbox 0x021F8FB0 thumb ov185
 *   BR_POKESEARCH_CreateSidebar 0x021F8D18 thumb ov185
 *   BR_POKESEARCH_CreateDetail 0x021F8D98 thumb ov185
 *   BR_POKESEARCH_HandleTouch 0x021F86E4 thumb ov185
 */
#include "../include/Obj03886.h"
extern void BR_FADE_Start(int a, int b, int c, int d);
extern int BR_FADE_GetResult(int *p);
extern int *BR_UTIL_SetTaskStep(int *p, int v);
extern void BR_POKESEARCH_DestroyMsgbox(char *,char *);
extern void BR_POKESEARCH_CreateSidebar(char *,int *);
extern void BR_POKESEARCH_CreateDetail(char *,char *);
extern void BR_POKESEARCH_HandleTouch(int,int,char *);
void BR_POKESEARCH_DownloadDoneTask(int a,int *state,char *p)
{
    switch (*state) {
    case 0: BR_FADE_Start(**(int * *)&((struct Obj03886 *)p)->f34,4,3,1); *state=1; break;
    case 1: if (BR_FADE_GetResult((int *)(**(int * *)&((struct Obj03886 *)p)->f34))) *state=2; break;
    case 2: BR_POKESEARCH_DestroyMsgbox(p,*(char * *)&((struct Obj03886 *)p)->f34); BR_POKESEARCH_CreateSidebar(p,*(int * *)&((struct Obj03886 *)p)->f34); BR_POKESEARCH_CreateDetail(p,*(char * *)&((struct Obj03886 *)p)->f34); *state=3; break;
    case 3: BR_FADE_Start(**(int * *)&((struct Obj03886 *)p)->f34,4,3,0); *state=4; break;
    case 4: if (BR_FADE_GetResult((int *)(**(int * *)&((struct Obj03886 *)p)->f34))) *state=5; break;
    case 5: ((struct Obj03886 *)p)->f20=1; BR_UTIL_SetTaskStep((int *)a,(int)BR_POKESEARCH_HandleTouch); break;
    }
}
