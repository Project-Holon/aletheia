/*
 * function: func_021DC638
 * address: 0x021DC638
 * packet: pkt_ov183_021DC638
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * abi: DD0AC/DD0F4 retain caller-loaded r1.
 * symbols:
 *   BR_FADE_Start 0x021FE784 thumb ov186
 *   BR_FADE_GetResult 0x021FE7B0 thumb ov186
 *   func_021DCE28 0x021DCE28 thumb ov183
 *   func_021DCE48 0x021DCE48 thumb ov183
 *   func_021DD054 0x021DD054 thumb ov183
 *   func_021DD128 0x021DD128 thumb ov183
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   func_021DD2FC 0x021DD2FC thumb ov183
 *   func_021DD33C 0x021DD33C thumb ov183
 *   func_021DD1D4 0x021DD1D4 thumb ov183
 *   func_021DD0AC 0x021DD0AC thumb ov183
 *   func_021DD0F4 0x021DD0F4 thumb ov183
 *   func_021FD170 0x021FD170 thumb ov186
 *   GAME_DATA_SaveStart 0x02012DAC thumb
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 *   func_021FD860 0x021FD860 thumb ov186
 *   GFL_USE_IsSeqPlaying 0x02006254 thumb
 *   func_021F9C50 0x021F9C50 thumb ov186
 *   func_021FD744 0x021FD744 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021DBC68 0x021DBC68 thumb ov183
 */
#include "../include/Obj00050.h"
#include "../include/Obj24555.h"
#include "../include/Obj24556.h"
#include "../include/Obj24557.h"
#include "../include/Obj24558.h"
#include "../include/Obj24559.h"
#include "../include/Obj24560.h"
#include "../include/Obj24561.h"
#include "../include/Obj24562.h"
#include "../include/Obj24563.h"
#include "../include/Obj24564.h"
#include "../include/Obj24565.h"
#include "../include/Obj24566.h"
#include "../include/Obj24567.h"
#include "../include/Obj24568.h"
#include "../include/Obj24569.h"
#include "../include/Obj24571.h"
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct S S;
extern void BR_FADE_Start(int a, int b, int c, int d);
extern int BR_FADE_GetResult(int *);
extern void func_021DCE28(char *,char *),func_021DCE48(char *,char *),func_021DD054(char *,char *),func_021DD128(char *,char *),func_021DD1D4(char *,char *);
extern void func_021DD0AC(char *,char *),func_021DD0F4(char *,char *);
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern int func_021DD2FC(char *,int,int),func_021DD33C(char *,int,int);
extern void func_021FD170(char *p, char *q, void *text);
extern int GAME_DATA_SaveStart(int),GAME_DATA_SaveMain(u8 *);
extern void func_021FD860(int,int,int *);
extern int GFL_USE_IsSeqPlaying(u32 a);
extern void func_021F9C50(S *);
extern int func_021FD744(int *a);
extern int *func_021FD73C(int *p, int v);
extern void func_021DBC68(int a, int b, char *p);
void func_021DC638(int *a,int *state,char *p)
{
    u32 x,y;
    switch(*state) {
    case 0: BR_FADE_Start((int)(*(int * *)&((struct Obj24555 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->fC),2,3,1);*state=1;break;
    case 1: if(BR_FADE_GetResult(*(int * *)&((struct Obj24556 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->fC)) *state=2;break;
    case 2:
        if(((struct Obj00050 *)p)->fB0) func_021DCE28(p,*(char * *)&((struct Obj00050 *)p)->fD0);
        else func_021DCE48(p,*(char * *)&((struct Obj00050 *)p)->fD0);
        func_021DD054(p,*(char * *)&((struct Obj00050 *)p)->fD0);func_021DD128(p,*(char * *)&((struct Obj00050 *)p)->fD0);*state=3;break;
    case 3: BR_FADE_Start((int)(*(int * *)&((struct Obj24557 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->fC),2,3,0);++*state;break;
    case 4: if(BR_FADE_GetResult(*(int * *)&((struct Obj24558 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->fC)) ++*state;break;
    case 5: ++*state;break;
    case 6:
        if(TOUCHPANEL_GetPointTrg(&x,&y)) {
            if(func_021DD2FC(p,x,y)) *state=7;
            else if(func_021DD33C(p,x,y)) *state=10;
        }
        break;
    case 7: BR_FADE_Start((int)(*(int * *)&((struct Obj24559 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->fC),2,3,1);++*state;break;
    case 8: if(BR_FADE_GetResult(*(int * *)&((struct Obj24560 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->fC)) ++*state;break;
    case 9: func_021DD1D4(p,*(char * *)&((struct Obj00050 *)p)->fD0);*state=13;break;
    case 10: BR_FADE_Start((int)(*(int * *)&((struct Obj24561 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->fC),2,3,1);++*state;break;
    case 11: if(BR_FADE_GetResult(*(int * *)&((struct Obj24562 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->fC)) ++*state;break;
    case 12: func_021DD1D4(p,*(char * *)&((struct Obj00050 *)p)->fD0);func_021FD73C(a,(int)func_021DBC68);break;
    case 13: func_021DD0AC(p,*(char * *)&((struct Obj00050 *)p)->fD0);*state=14;break;
    case 14:
        func_021FD170(((struct Obj00050 *)p)->f18,(char *)(((struct Obj24563 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->f10),(void *)0x152);
        BR_FADE_Start((int)(*(int * *)&((struct Obj24564 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->fC),2,3,0);*state=15;break;
    case 15: if(BR_FADE_GetResult(*(int * *)&((struct Obj24565 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->fC)) *state=16;break;
    case 16: *state=17;break;
    case 17: GAME_DATA_SaveStart(((struct Obj24566 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->f28);*state=18;break;
    case 18:
        if(GAME_DATA_SaveMain(*(u8 * *)&((struct Obj24567 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->f28)==2) {func_021FD860(*(int *)&((struct Obj00050 *)p)->fC,0,0);*state=19;}
        break;
    case 19: BR_FADE_Start((int)(*(int * *)&((struct Obj24568 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->fC),2,3,1);*state=20;break;
    case 20: if(BR_FADE_GetResult(*(int * *)&((struct Obj24569 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->fC)) *state=21;break;
    case 21:
        if(!GFL_USE_IsSeqPlaying(0x701)) {
            func_021DD0F4(p,*(char * *)&((struct Obj00050 *)p)->fD0);
            **(int * *)&((struct Obj00050 *)p)->fD0=1;
            func_021F9C50(*(S * *)&((struct Obj24571 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->f14);
            func_021FD744((int *)a);
        }
        break;
    }
}
