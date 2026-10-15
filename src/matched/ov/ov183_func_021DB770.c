/*
 * function: func_021DB770
 * address: 0x021DB770
 * packet: pkt_ov183_021DB770
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: explicit case-3 call arms preserve the original block shape; ARM9 division helper uses the proven _u32_div_f ABI.
 * symbols:
 *   BR_FADE_Start 0x021FE784 thumb ov186
 *   BR_FADE_GetResult 0x021FE7B0 thumb ov186
 *   BR_BTN_GetField14 0x021FA018 thumb ov186
 *   BR_BTN_UpdatePrint 0x021F9FE8 thumb ov186
 *   BR_BTN_GetPlacement 0x021FA004 thumb ov186
 *   BR_PROC_SYS_PushEntry 0x021F9BF4 thumb ov186
 *   BR_PROC_SYS_PopEntry 0x021F9BA0 thumb ov186
 *   BR_BTN_GetField54 0x021FA01C thumb ov186
 *   BR_RES_GetPalSet 0x021FC238 thumb ov186
 *   BR_RES_SetPalSet 0x021FC230 thumb ov186
 *   BR_RES_GetCurrentSetParam 0x021FC224 thumb ov186
 *   BR_FADE_SetBlendColor 0x021FE7F4 thumb ov186
 *   BR_UTIL_RunHandles 0x021FD854 thumb ov186
 *   func_021DB924 0x021DB924 thumb ov183
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_020056A0 0x020056A0 thumb
 *   func_02030EAC 0x02030EAC arm
 *   _u32_div_f 0x0209C2B0 arm
 *   d_021E3280 0x021E3280 data a4
 */
#include "../include/Obj01004.h"
#include "../include/Obj02891.h"
typedef unsigned int u32;
extern void BR_FADE_Start(int,int,int,int);
extern int BR_FADE_GetResult(int *);
extern int BR_BTN_GetField14(char *),BR_BTN_GetField54(char *);
extern void BR_BTN_UpdatePrint(char *);
extern int BR_BTN_GetPlacement(char *,int *,int *);
extern void BR_PROC_SYS_PushEntry(unsigned *,unsigned);
extern void BR_PROC_SYS_PopEntry(unsigned *ctx);
extern int BR_RES_GetPalSet(char *),BR_RES_GetCurrentSetParam(char *);
extern void BR_RES_SetPalSet(char *,int),BR_FADE_SetBlendColor(int *,int);
extern void BR_UTIL_RunHandles(char *);
extern void func_021DB924(int a0, char *p);
extern u32 TOUCHPANEL_GetPointTrg(u32 *,u32 *);
struct Node;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void *func_020056A0(void (*)(void),void *,int);
extern void func_02030EAC(struct Node *n);
extern int d_021E3280[];
int func_021DB770(int *task,int *state,char *p,char *q)
{
    u32 x,y;
    switch(*state) {
    case 0: BR_FADE_Start(*(int *)&((struct Obj01004 *)p)->f10,((struct Obj01004 *)p)->fC,3,0);*state=1;break;
    case 1: if(BR_FADE_GetResult(*(int * *)&((struct Obj01004 *)p)->f10))*state=2;break;
    case 2:
        if(((struct Obj01004 *)p)->f0<=4 && !BR_BTN_GetField14(*(char * *)&((struct Obj02891 *)q)->f0) && TOUCHPANEL_GetPointTrg(&x,&y)) {
            if(x<8 || x>248) {GFL_USE_PlaySeDefaultVolume(0x703);*state=6;break;}
        }
        BR_BTN_UpdatePrint(*(char * *)&((struct Obj02891 *)q)->f0);
        if(BR_BTN_GetPlacement(*(char * *)&((struct Obj02891 *)q)->f0,(int *)(p+4),(int *)(p+8))) *state=3;
        break;
    case 3:
        if(((struct Obj01004 *)p)->f4==12)BR_FADE_Start(*(int *)&((struct Obj01004 *)p)->f10,4,3,1);
        else BR_FADE_Start(*(int *)&((struct Obj01004 *)p)->f10,2,3,1);
        *state=4;break;
    case 4: if(BR_FADE_GetResult(*(int * *)&((struct Obj01004 *)p)->f10))*state=5;break;
    case 5:
        switch(BR_BTN_GetPlacement(*(char * *)&((struct Obj02891 *)q)->f0,(int *)(p+4),(int *)(p+8))) {
        case 1: BR_PROC_SYS_PushEntry(*(unsigned * *)&((struct Obj01004 *)p)->f1C,(unsigned short)((struct Obj01004 *)p)->f4);return 1;
        case 2: BR_PROC_SYS_PopEntry(((struct Obj01004 *)p)->f1C);**(int * *)&((struct Obj01004 *)p)->f28=BR_BTN_GetField54(*(char * *)&((struct Obj02891 *)q)->f0);return 1;
        }
        break;
    case 6: {
        int v=BR_RES_GetPalSet(*(char * *)&((struct Obj01004 *)p)->f18);u32 i;
        for(i=0;i<7;i++) {if(v==d_021E3280[i]) {v=d_021E3280[(i+1)%7];break;}}
        BR_RES_SetPalSet(*(char * *)&((struct Obj01004 *)p)->f18,v);
        BR_FADE_SetBlendColor(*(int * *)&((struct Obj01004 *)p)->f10,BR_RES_GetCurrentSetParam(*(char * *)&((struct Obj01004 *)p)->f18));
        BR_FADE_Start(*(int *)&((struct Obj01004 *)p)->f10,3,3,1);*state=7;break;
    }
    case 7: if(BR_FADE_GetResult(*(int * *)&((struct Obj01004 *)p)->f10))*state=8;break;
    case 8: ((struct Obj02891 *)q)->f8=func_020056A0((void (*)(void))func_021DB924,q,0);((struct Obj02891 *)q)->f10=0;*state=9;break;
    case 9: if(((struct Obj02891 *)q)->f10) {func_02030EAC(((struct Obj02891 *)q)->f8);*state=10;}break;
    case 10: BR_FADE_Start(*(int *)&((struct Obj01004 *)p)->f10,3,3,0);*state=11;break;
    case 11: if(BR_FADE_GetResult(*(int * *)&((struct Obj01004 *)p)->f10))*state=2;break;
    }
    BR_UTIL_RunHandles(*(char * *)&((struct Obj02891 *)q)->f4);return 0;
}
