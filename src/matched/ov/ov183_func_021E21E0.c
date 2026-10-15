/*
 * function: BR_CODEIN_SaveStepVideo
 * address: 0x021E21E0
 * packet: pkt_ov183_021E21E0
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: separate function-scope coordinate pairs retain the switch cases' stack slots.
 * symbols:
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   BR_CODEIN_SaveHitButtonA 0x021E24F8 thumb ov183
 *   BR_CODEIN_SaveHitButtonB 0x021E2538 thumb ov183
 *   BR_UTIL_SetWindowText 0x021FD170 thumb ov186
 *   BR_FADE_Start 0x021FE784 thumb ov186
 *   BR_FADE_GetResult 0x021FE7B0 thumb ov186
 *   BR_CODEIN_SaveTeardown 0x021E24C4 thumb ov183
 *   BR_UTIL_StartEffect 0x021FD860 thumb ov186
 *   GDS_RAP_StartVideoSave 0x021D76A8 thumb ov125
 *   GDS_RAP_StepVideoSave 0x021D76D8 thumb ov125
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb ov186
 *   BR_CODEIN_SaveStepFadeOut 0x021E2194 thumb ov183
 */
#include "../include/Obj00683.h"
#include "../include/Obj24654.h"
#include "../include/Obj24655.h"
#include "../include/Obj24656.h"
#include "../include/Obj24657.h"
#include "../include/Obj24658.h"
#include "../include/Obj24659.h"
#include "../include/Obj24660.h"
#include "../include/Obj24662.h"
#include "../include/Obj24664.h"
#include "../include/Obj24665.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef struct {u32 a,b;} Pair;
extern u32 TOUCHPANEL_GetPointTrg(u32 *,u32 *);
extern int TOUCHPANEL_GetTrg(void);
extern int BR_CODEIN_SaveHitButtonA(char *,int,int),BR_CODEIN_SaveHitButtonB(char *,int,int);
extern void BR_UTIL_SetWindowText(char *p, char *q, void *text);
extern void BR_FADE_Start(int,int,int,int);
extern int BR_FADE_GetResult(int *);
extern void BR_CODEIN_SaveTeardown(char *,char *),BR_UTIL_StartEffect(int,int,Pair *);
extern void GDS_RAP_StartVideoSave(int,int,int);
extern int GDS_RAP_StepVideoSave(char *p, int id);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern int *BR_UTIL_SetTaskStep(int *p, int v);
extern void BR_CODEIN_SaveStepFadeOut(int *task, int *state, char *p);
void BR_CODEIN_SaveStepVideo(int task,int *state,char *p) {
    u32 x0,y0,x1,y1; Pair first; u32 x9,y9; Pair second;
    u32 old; int result;
    switch(*state) {
    case 0:
        if(TOUCHPANEL_GetPointTrg(&x0,&y0)) {
            if(BR_CODEIN_SaveHitButtonA(p,x0,y0)) {BR_UTIL_SetWindowText((char *)(((struct Obj00683 *)p)->f4),(char *)(((struct Obj24654 *)(*(char * *)&((struct Obj00683 *)p)->f20))->fC),(void *)322);*state=1;}
            else if(BR_CODEIN_SaveHitButtonB(p,x0,y0))*state=10;
        } break;
    case 1:
        if(TOUCHPANEL_GetPointTrg(&x1,&y1)) {
            if(BR_CODEIN_SaveHitButtonA(p,x1,y1))*state=2;
            else if(BR_CODEIN_SaveHitButtonB(p,x1,y1))*state=10;
        } break;
    case 2:BR_FADE_Start(((struct Obj24655 *)(*(char * *)&((struct Obj00683 *)p)->f20))->f4,2,2,1);++*state;break;
    case 3:
        if(BR_FADE_GetResult(*(int * *)&((struct Obj24656 *)(*(char * *)&((struct Obj00683 *)p)->f20))->f4)) {
            BR_CODEIN_SaveTeardown(p,*(char * *)&((struct Obj00683 *)p)->f20);
            BR_UTIL_SetWindowText((char *)(((struct Obj00683 *)p)->f4),(char *)(((struct Obj24657 *)(*(char * *)&((struct Obj00683 *)p)->f20))->fC),(void *)323);
            first.a=128;first.b=96;BR_UTIL_StartEffect(((struct Obj00683 *)p)->f14,4,&first);
            ((struct Obj00683 *)p)->f24=0;++*state;
        } break;
    case 4:BR_FADE_Start(((struct Obj24658 *)(*(char * *)&((struct Obj00683 *)p)->f20))->f4,2,2,0);++*state;break;
    case 5:if(BR_FADE_GetResult(*(int * *)&((struct Obj24659 *)(*(char * *)&((struct Obj00683 *)p)->f20))->f4))++*state;break;
    case 6:
        GDS_RAP_StartVideoSave(((struct Obj24660 *)(*(char * *)&((struct Obj00683 *)p)->f20))->f14,((struct Obj00683 *)p)->f1C,**(int * *)&((struct Obj00683 *)p)->f20);
        ++((struct Obj00683 *)p)->f24;++*state;break;
    case 7:
        result=GDS_RAP_StepVideoSave((char *)(((struct Obj24662 *)(*(char * *)&((struct Obj00683 *)p)->f20))->f14),**(int * *)&((struct Obj00683 *)p)->f20);
        ++((struct Obj00683 *)p)->f24;
        if((u32)(result-2)<=1) {((struct Obj24664 *)(*(char * *)&((struct Obj00683 *)p)->f20))->f1C=1;*state=8;}break;
    case 8:
        old=((struct Obj00683 *)p)->f24;((struct Obj00683 *)p)->f24=old+1;
        if(old>96) {BR_UTIL_StartEffect(((struct Obj00683 *)p)->f14,0,0);BR_UTIL_SetWindowText((char *)(((struct Obj00683 *)p)->f4),(char *)(((struct Obj24665 *)(*(char * *)&((struct Obj00683 *)p)->f20))->fC),(void *)324);*state=9;}break;
    case 9:
        if(TOUCHPANEL_GetTrg()) {
            TOUCHPANEL_GetPointTrg(&x9,&y9);second.a=x9;second.b=y9;
            BR_UTIL_StartEffect(((struct Obj00683 *)p)->f18,1,&second);GFL_USE_PlaySeDefaultVolume(0x703);*state=10;
        }break;
    case 10:BR_UTIL_SetTaskStep((int *)task,(int)BR_CODEIN_SaveStepFadeOut);break;
    }
}
