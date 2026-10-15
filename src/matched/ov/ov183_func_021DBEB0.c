/*
 * function: func_021DBEB0
 * address: 0x021DBEB0
 * packet: pkt_ov183_021DBEB0
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_FADE_Start 0x021FE784 thumb ov186
 *   BR_FADE_GetResult 0x021FE7B0 thumb ov186
 *   BR_RES_GetFont 0x021FC20C thumb ov186
 *   BR_RES_GetMsgData 0x021FC214 thumb ov186
 *   BR_UTIL_SetTextFromMessage 0x021FC754 thumb ov186
 *   func_021DCE48 0x021DCE48 thumb ov183
 *   func_021DCDD8 0x021DCDD8 thumb ov183
 *   func_021DCE28 0x021DCE28 thumb ov183
 *   func_021DC8EC 0x021DC8EC thumb ov183
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb ov186
 *   func_021DBD7C 0x021DBD7C thumb ov183
 */
#include "../include/Obj00050.h"
#include "../include/Obj24549.h"
#include "../include/Obj24550.h"
#include "../include/Obj24551.h"
#include "../include/Obj24552.h"
#include "../include/Obj24553.h"
#include "../include/Obj24554.h"
extern void BR_FADE_Start(int,int,int,int);
extern int BR_FADE_GetResult(int *);
extern unsigned BR_RES_GetFont(char *p);
extern int BR_RES_GetMsgData(char *);
extern void BR_UTIL_SetTextFromMessage(char *,void *,void *,void *,unsigned short);
extern void func_021DCE48(char *,char *),func_021DCDD8(char *,char *),func_021DCE28(char *,char *);
extern void func_021DC8EC(char *p, char *q);
extern int *BR_UTIL_SetTaskStep(int *p, int v);
extern void func_021DBD7C(int *task, int *state, char *p);
void func_021DBEB0(int *task,int *state,char *p)
{
    int a,b;
    switch(*state) {
    case 0:
        BR_FADE_Start(((struct Obj24549 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->fC,2,1,1);
        (*state)++;break;
    case 1:
        if(BR_FADE_GetResult(*(int * *)&((struct Obj24550 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->fC))(*state)++;
        break;
    case 2:
        a=BR_RES_GetFont(*(char * *)&((struct Obj24551 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->f10);
        b=BR_RES_GetMsgData(*(char * *)&((struct Obj24552 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->f10);
        if(((struct Obj00050 *)p)->fB0) {
            func_021DCE48(p,*(char * *)&((struct Obj00050 *)p)->fD0);
            BR_UTIL_SetTextFromMessage(*(char * *)&((struct Obj00050 *)p)->f28,(void *)b,(void *)0x72,(void *)a,0x3da0);
            func_021DCDD8(p,*(char * *)&((struct Obj00050 *)p)->fD0);
        }else{
            func_021DCE28(p,*(char * *)&((struct Obj00050 *)p)->fD0);
            BR_UTIL_SetTextFromMessage(*(char * *)&((struct Obj00050 *)p)->f28,(void *)b,(void *)0x71,(void *)a,0x3da0);
            func_021DC8EC(p,(char *)(*(int *)&((struct Obj00050 *)p)->fD0));
        }
        BR_FADE_Start(((struct Obj24553 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->fC,2,1,0);
        (*state)++;break;
    case 3:
        if(BR_FADE_GetResult(*(int * *)&((struct Obj24554 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->fC))BR_UTIL_SetTaskStep(task,(int)func_021DBD7C);
        break;
    }
}
