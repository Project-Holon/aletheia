/*
 * function: BR_POKESEARCH_ChangeCategoryTask
 * address: 0x021F8C30
 * packet: pkt_ov185_021F8C30
 * region: ov185
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * abi: 021F8C9E passes r1 to BR_POKESEARCH_DestroyText despite its unused second input.
 * symbols:
 *   BR_FADE_Start 0x021FE784 thumb ov186
 *   BR_FADE_GetResult 0x021FE7B0 thumb ov186
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb ov186
 *   BR_RES_GetFont 0x021FC20C thumb ov186
 *   BR_RES_GetMsgData 0x021FC214 thumb ov186
 *   BR_UTIL_SetTextFromMessage 0x021FC754 thumb ov186
 *   BR_POKESEARCH_CreateSidebar 0x021F8D18 thumb ov185
 *   BR_POKESEARCH_ShowBg 0x021F8D5C thumb ov185
 *   BR_POKESEARCH_CreateText 0x021F8E90 thumb ov185
 *   BR_POKESEARCH_DestroyText 0x021F8EE8 thumb ov185
 *   BR_POKESEARCH_HandleTouch 0x021F86E4 thumb ov185
 */
#include "../include/Obj01769.h"
#include "../include/Obj24755.h"
#include "../include/Obj24756.h"
extern void BR_FADE_Start(int a, int b, int c, int d);
extern int BR_FADE_GetResult(int *);
extern int *BR_UTIL_SetTaskStep(int *p, int v);
extern unsigned BR_RES_GetFont(char *p);
extern int BR_RES_GetMsgData(char *);
extern void BR_UTIL_SetTextFromMessage(char *,void *,void *,void *,unsigned short);
extern void BR_POKESEARCH_CreateSidebar(char *,int *);
extern void BR_POKESEARCH_ShowBg(char *p, char *q);
extern void BR_POKESEARCH_CreateText(char *,int *);
extern void BR_POKESEARCH_DestroyText(char *,int *);
extern void BR_POKESEARCH_HandleTouch(int,int,char *);
void BR_POKESEARCH_ChangeCategoryTask(int *task,int *state,char *p)
{
    int flag,a,b,c;
    switch (*state) {
    case 0: BR_FADE_Start(**(int * *)&((struct Obj01769 *)p)->f34,1,1,1);*state=1;break;
    case 1: if(BR_FADE_GetResult(*(int **)*(int * *)&((struct Obj01769 *)p)->f34)) *state=2;break;
    case 2:
        flag=1;
        if(!((struct Obj01769 *)p)->f14) flag=0;
        if(flag) {
            BR_POKESEARCH_ShowBg(p,(char *)(*(int * *)&((struct Obj01769 *)p)->f34));
            BR_POKESEARCH_CreateText(p,*(int * *)&((struct Obj01769 *)p)->f34);
        } else {
            BR_POKESEARCH_DestroyText(p,*(int * *)&((struct Obj01769 *)p)->f34);
            BR_POKESEARCH_CreateSidebar(p,*(int * *)&((struct Obj01769 *)p)->f34);
        }
        a=BR_RES_GetFont(*(char * *)&((struct Obj24755 *)(*(char * *)&((struct Obj01769 *)p)->f34))->fC);
        b=BR_RES_GetMsgData(*(char * *)&((struct Obj24756 *)(*(char * *)&((struct Obj01769 *)p)->f34))->fC);
        if(flag) {((struct Obj01769 *)p)->f20=0;c=0x72;}
        else {((struct Obj01769 *)p)->f20=1;c=0x71;}
        BR_UTIL_SetTextFromMessage(*(char * *)&((struct Obj01769 *)p)->f1C,(void *)b,(void *)c,(void *)a,0x3da0);
        *state=3;break;
    case 3: BR_FADE_Start(**(int * *)&((struct Obj01769 *)p)->f34,1,1,0);*state=4;break;
    case 4: if(BR_FADE_GetResult(*(int **)*(int * *)&((struct Obj01769 *)p)->f34)) *state=5;break;
    case 5: BR_UTIL_SetTaskStep(task,(int)BR_POKESEARCH_HandleTouch);break;
    }
}
