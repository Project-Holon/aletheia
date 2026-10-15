/*
 * function: LIVEBATTLEMATCH_FLOW_Result
 * address: 0x0217C628
 * packet: pkt_ov176_0217C628
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * prototypes: E1FC and E2C0 return r0 consumed by the original although their own C returns void.
 * symbols:
 *   func_0217CFE8 0x0217CFE8 thumb ov176
 *   func_021E8AB4 0x021E8AB4 thumb ov177
 *   LIVEBATTLEMATCH_FLOW_DrawMenu 0x0217CEAC thumb ov176
 *   LIVEBATTLEMATCH_FLOW_GetWindowResult 0x0217CFDC thumb ov176
 *   LIVEBATTLEMATCH_FLOW_HideWindow 0x0217CFD0 thumb ov176
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   LIVEBATTLEMATCH_FLOW_Battle 0x0217C2EC thumb ov176
 *   REGULATION_NoOp 0x0200AE14 thumb
 *   func_0217D010 0x0217D010 thumb ov176
 *   func_0217D000 0x0217D000 thumb ov176
 *   func_021E8AB8 0x021E8AB8 thumb ov177
 *   func_0217E078 0x0217E078 thumb ov176
 *   func_021E7E0C 0x021E7E0C thumb ov177
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_0217E0A8 0x0217E0A8 thumb ov176
 *   func_0217E0B0 0x0217E0B0 thumb ov176
 *   KEY_GetTrg 0x020362DC arm
 *   func_0217E158 0x0217E158 thumb ov176
 *   func_0217E178 0x0217E178 thumb ov176
 *   func_0217D388 0x0217D388 thumb ov176
 *   func_0217E1FC 0x0217E1FC thumb ov176
 *   func_0217E23C 0x0217E23C thumb ov176
 *   POKE_REGULATION_GetDataSize 0x0201A918 thumb
 *   MI_CpuCopy8 0x02082D44 arm
 *   REGULATION_Card_GetValue 0x0200B078 thumb
 *   func_0200E994 0x0200E994 thumb
 *   GFL_USE_StopAllSe 0x02006210 thumb
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   func_0217E2C0 0x0217E2C0 thumb ov176
 *   func_0217E2F8 0x0217E2F8 thumb ov176
 *   func_0217E1B8 0x0217E1B8 thumb ov176
 *   func_0217E1C0 0x0217E1C0 thumb ov176
 *   func_02040588 0x02040588 arm
 *   func_0217D1C8 0x0217D1C8 thumb ov176
 *   func_0217D238 0x0217D238 thumb ov176
 *   REGULATION_GetRuleValue 0x0200AE54 thumb
 */
#include "../include/Obj00241.h"
#include "../include/Obj24411.h"
#include "../include/Obj24412.h"
#include "../include/Obj24413.h"
typedef unsigned char u8;
typedef unsigned u32;
extern void func_0217CFE8(void *,int,int);
extern void func_021E8AB4(u32,u32);
typedef signed int     s32;
struct Reg;
struct Reg2;
extern void LIVEBATTLEMATCH_FLOW_DrawMenu(u8 *p, int mode);
extern int LIVEBATTLEMATCH_FLOW_GetWindowResult(int *p);
extern void LIVEBATTLEMATCH_FLOW_HideWindow(int *p);
extern void func_021E8AA0(int *,int);
extern void LIVEBATTLEMATCH_FLOW_Battle(int *sys, u32 *state, u8 *p);
extern void * REGULATION_NoOp(void *);
extern void func_0217D010(u8 *,int);
extern int func_0217D000(u8 *);
extern void func_021E8AB8(u32);
extern int func_0217E078(u8 *p);
extern void func_021E7E0C(void **,int);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern int func_0217E0A8(int *);
extern int func_0217E0B0(unsigned *);
extern u32 KEY_GetTrg(void);
extern void func_0217E158(unsigned *);
extern int func_0217E178(int *);
extern void func_0217D388(int *,int *);
extern int func_0217E1FC(int,int);
extern int func_0217E23C(char *,void **);
extern int POKE_REGULATION_GetDataSize(void);
extern void MI_CpuCopy8(const void *,void *,u32);
extern s32 REGULATION_Card_GetValue(struct Reg2 *p, u32 id);
extern u32 func_0200E994(void *base, void *key);
extern void GFL_USE_StopAllSe(void);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *,u32,u32);
extern u32 GFL_NET_HANDLE_IsTimingSyncRange(struct Link *,u32,u32);
extern u32 func_0217E2C0(int unused, int a);
extern int func_0217E2F8(u8 *p, const void *q);
extern int func_0217E1B8(int *);
extern int func_0217E1C0(int *);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0217D1C8(char *,int);
extern int func_0217D238(u8 *);
extern u32 REGULATION_GetRuleValue(struct Reg *p, u32 id);
void LIVEBATTLEMATCH_FLOW_Result(int *sys,u32 *state,u8 *p)
{
    if(func_0217E078(((struct Obj00241 *)p)->fC)==1){
        ((struct Obj24411 *)(*(u8 * *)&((struct Obj00241 *)p)->f1C4))->fC=1;
        func_021E8AA0(sys,(int)LIVEBATTLEMATCH_FLOW_Battle);
    }
    switch(*state){
    case 0:func_0217CFE8(p,20,1);*state=40;func_021E8AB4((u32)sys,1);break;
    case 1:func_0217CFE8(p,33,0);func_021E7E0C(*(void ** *)&((struct Obj00241 *)p)->f1C,1);GFL_USE_PlaySeDefaultVolume(0x80d);((struct Obj00241 *)p)->f1D4=0;((struct Obj00241 *)p)->f1D8=0;*state=40;func_021E8AB4((u32)sys,2);break;
    case 2:if(func_0217E0A8(*(int * *)&((struct Obj00241 *)p)->fC))*state=3;break;
    case 3:switch(func_0217E0B0(*(unsigned * *)&((struct Obj00241 *)p)->fC)){case 1:*state=13;break;case 2:*state=9;break;}if(KEY_GetTrg()&2)*state=4;break;
    case 4:func_0217E158(*(unsigned * *)&((struct Obj00241 *)p)->fC);*state=5;break;
    case 5:if(func_0217E178(*(int * *)&((struct Obj00241 *)p)->fC))*state=6;break;
    case 6:func_021E7E0C(*(void ** *)&((struct Obj00241 *)p)->f1C,0);func_0217CFE8(p,21,1);*state=40;func_021E8AB4((u32)sys,7);break;
    case 7:LIVEBATTLEMATCH_FLOW_DrawMenu(p,0);*state=8;break;
    case 8:{
        int v=LIVEBATTLEMATCH_FLOW_GetWindowResult((int *)p);
        if(v!=-1){LIVEBATTLEMATCH_FLOW_HideWindow((int *)p);switch(v){
        case 0:func_021E7E0C(*(void ** *)&((struct Obj00241 *)p)->f1C,0);func_021E8AA0(sys,(int)LIVEBATTLEMATCH_FLOW_Battle);break;
        case 1:*state=1;break;
        }}break;
    }
    case 9:func_021E7E0C(*(void ** *)&((struct Obj00241 *)p)->f1C,0);func_0217E158(*(unsigned * *)&((struct Obj00241 *)p)->fC);*state=10;break;
    case 10:if(func_0217E178(*(int * *)&((struct Obj00241 *)p)->fC))*state=11;break;
    case 11:func_0217CFE8(p,28,1);*state=40;func_021E8AB4((u32)sys,12);break;
    case 12:func_021E8AA0(sys,(int)LIVEBATTLEMATCH_FLOW_Battle);break;
    case 13:func_0217D388(*(int * *)&((struct Obj00241 *)p)->f1BC,(int *)p);if(func_0217E1FC(*(int *)&((struct Obj00241 *)p)->fC,*(int *)&((struct Obj00241 *)p)->f1BC))*state=14;break;
    case 14:{
        void *out;
        if(func_0217E23C(*(char * *)&((struct Obj00241 *)p)->fC,&out)){MI_CpuCopy8(out,((struct Obj00241 *)p)->f1C0,POKE_REGULATION_GetDataSize()+0xd4);*state=15;}break;
    }
    case 15:
        if(((struct Obj24412 *)(*(u8 * *)&((struct Obj00241 *)p)->f1BC))->f40==((struct Obj24413 *)(*(u8 * *)&((struct Obj00241 *)p)->f1C0))->f40){
            u32 a=REGULATION_Card_GetValue(((struct Obj00241 *)p)->f38,12);
            int b=func_0200E994(((struct Obj00241 *)p)->f34,*(u8 * *)&((struct Obj00241 *)p)->f1C0+0x20);
            ((struct Obj00241 *)p)->f1D4=(a!=0||(a==0&&b==0));
            *state=16;
        }else{func_021E7E0C(*(void ** *)&((struct Obj00241 *)p)->f1C,0);GFL_USE_StopAllSe();*state=21;}
        break;
    case 16:GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x48,0x1f);*state=17;break;
    case 17:if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x48,0x1f))*state=18;break;
    case 18:if(func_0217E2C0((int)(((struct Obj00241 *)p)->fC),(int)((u32 *)(p+0x1d4))))*state=19;break;
    case 19:if(func_0217E2F8(((struct Obj00241 *)p)->fC,(u32 *)(p+0x1d8)))*state=20;break;
    case 20:
        func_021E7E0C(*(void ** *)&((struct Obj00241 *)p)->f1C,0);GFL_USE_StopAllSe();
        if(((struct Obj00241 *)p)->f1D8&&((struct Obj00241 *)p)->f1D4){GFL_USE_PlaySeDefaultVolume(0x63a);*state=27;}else *state=24;break;
    case 21:if(func_0217E1B8(*(int * *)&((struct Obj00241 *)p)->fC))*state=22;break;
    case 22:if(func_0217E1C0(*(int * *)&((struct Obj00241 *)p)->fC))*state=23;break;
    case 23:func_0217CFE8(p,22,1);*state=40;func_021E8AB4((u32)sys,39);break;
    case 24:if(func_0217E1B8(*(int * *)&((struct Obj00241 *)p)->fC))*state=25;break;
    case 25:if(func_0217E1C0(*(int * *)&((struct Obj00241 *)p)->fC))*state=26;break;
    case 26:func_0217CFE8(p,36,1);*state=40;func_021E8AB4((u32)sys,39);break;
    case 27:func_0217CFE8(p,23,1);*state=40;func_021E8AB4((u32)sys,28);break;
    case 28:if((((struct Obj00241 *)p)->f1CC)++>120){((struct Obj00241 *)p)->f1CC=0;func_02040588(0,0);*state=29;}break;
    case 29:func_0217D1C8((char *)p,*(int *)&((struct Obj00241 *)p)->f1C0);*state=30;break;
    case 30:if(func_0217D238(p))*state=31;break;
    case 31:if((((struct Obj00241 *)p)->f1CC)++>300){((struct Obj00241 *)p)->f1CC=0;*state=32;}break;
    case 32:func_02040588(0,1);func_0217CFE8(p,24,1);*state=40;func_021E8AB4((u32)sys,33);break;
    case 33:func_0217CFE8(p,35,2);*state=40;func_021E8AB4((u32)sys,34);break;
    case 34:GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x47,0x1f);*state=35;break;
    case 35:if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x47,0x1f))*state=36;break;
    case 36:func_02040588(0,1);func_0217CFE8(p,38,2);*state=40;func_021E8AB4((u32)sys,37);break;
    case 37:
        if((((struct Obj00241 *)p)->f1CC)++>60){
            void *v=REGULATION_NoOp(((struct Obj00241 *)p)->f38);
            ((struct Obj00241 *)p)->f1CC=0;REGULATION_GetRuleValue(v,19);*state=38;
        }break;
    case 38:func_0217D010(p,2);break;
    case 39:func_021E8AA0(sys,(int)LIVEBATTLEMATCH_FLOW_Battle);break;
    case 40:if(func_0217D000(p))func_021E8AB8((u32)sys);break;
    }
}
