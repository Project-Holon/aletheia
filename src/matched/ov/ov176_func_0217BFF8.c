/*
 * function: LIVEBATTLEMATCH_FLOW_Confirm
 * address: 0x0217BFF8
 * packet: pkt_ov176_0217BFF8
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0217D028 0x0217D028 thumb ov176
 *   func_0217D1A0 0x0217D1A0 thumb ov176
 *   func_0217D244 0x0217D244 thumb ov176
 *   func_0217D188 0x0217D188 thumb ov176
 *   func_0217D2A4 0x0217D2A4 thumb ov176
 *   func_0217CFE8 0x0217CFE8 thumb ov176
 *   func_021E8AB4 0x021E8AB4 thumb ov177
 *   LIVEBATTLEMATCH_FLOW_DrawMenu 0x0217CEAC thumb ov176
 *   LIVEBATTLEMATCH_FLOW_GetWindowResult 0x0217CFDC thumb ov176
 *   LIVEBATTLEMATCH_FLOW_HideWindow 0x0217CFD0 thumb ov176
 *   func_0217D2B0 0x0217D2B0 thumb ov176
 *   func_0217D290 0x0217D290 thumb ov176
 *   REGULATION_NoOp 0x0200AE14 thumb
 *   func_0217D2BC 0x0217D2BC thumb ov176
 *   POKEPARTY_GetBattleReadyCount 0x0201AA50 thumb
 *   POKE_REGULATION_CheckParty 0x0201A090 thumb
 *   func_0217D194 0x0217D194 thumb ov176
 *   func_0217D174 0x0217D174 thumb ov176
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   BATTLE_BOX_GetFromSave 0x0200BAC8 thumb
 *   BATTLE_COMPETITION_GetFromSave 0x0200B358 thumb
 *   REGULATION_GetParty 0x0200B204 thumb
 *   func_0200BAF4 0x0200BAF4 thumb
 *   BATTLE_BOX_SetLockFlags 0x0200BBC8 thumb
 *   REGULATION_Card_SetValue 0x0200B110 thumb
 *   REGULATION_BuildParty 0x0200B2A4 thumb
 *   func_020307B0 0x020307B0 arm
 *   GAME_DATA_SaveStart 0x02012DAC thumb
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   LIVEBATTLEMATCH_FLOW_Battle 0x0217C2EC thumb ov176
 *   func_0217D010 0x0217D010 thumb ov176
 *   func_0217D000 0x0217D000 thumb ov176
 *   func_021E8AB8 0x021E8AB8 thumb ov177
 */
#include "../include/Obj00053.h"
typedef unsigned char u8;
typedef unsigned u32;
extern void func_0217D028(u8 *);
extern void func_0217D1A0(u8 *,int);
extern void func_0217D244(char *);
extern int func_0217D188(u8 *);
extern int func_0217D2A4(u8 *);
extern void func_0217CFE8(void *,int,int);
extern void func_021E8AB4(u32,u32);
typedef signed int     s32;
struct Big;
struct Obj;
struct Rec1E;
struct RecBig;
struct Reg2;
extern void LIVEBATTLEMATCH_FLOW_DrawMenu(u8 *p, int mode);
extern int LIVEBATTLEMATCH_FLOW_GetWindowResult(int *p);
extern void LIVEBATTLEMATCH_FLOW_HideWindow(int *p);
extern int func_0217D2B0(u8 *);
extern void func_0217D290(u8 *);
extern void * REGULATION_NoOp(void *);
extern void func_0217D2BC(u8 *p, const void *q);
extern u32 POKEPARTY_GetBattleReadyCount(void *);
extern int POKE_REGULATION_CheckParty(void *,void *,u32 *);
extern int func_0217D194(int *p);
extern void func_0217D174(int *);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void * BATTLE_BOX_GetFromSave(void *);
extern void * BATTLE_COMPETITION_GetFromSave(void *);
extern struct Rec1E *REGULATION_GetParty(struct RecBig *p, u32 index);
extern void * func_0200BAF4(int,int);
extern void BATTLE_BOX_SetLockFlags(struct Obj *p, u32 v);
extern void REGULATION_Card_SetValue(struct Reg2 *p, u32 id, s32 value);
extern void REGULATION_BuildParty(int,int);
extern u32 func_020307B0(void *p);
extern int GAME_DATA_SaveStart(int);
extern int GAME_DATA_SaveMain(u8 *);
extern void func_021E8AA0(int *,int);
extern void LIVEBATTLEMATCH_FLOW_Battle(int *sys, u32 *state, u8 *p);
extern void func_0217D010(u8 *,int);
extern int func_0217D000(u8 *);
extern void func_021E8AB8(u32);
void LIVEBATTLEMATCH_FLOW_Confirm(int *sys,u32 *state,u8 *p)
{
    switch(*state){
    case 0:func_0217D028(p);func_0217D1A0(p,2);func_0217D244((char *)p);*state=1;break;
    case 1:{
        int flag=1;
        flag&=func_0217D188(p);
        flag&=func_0217D2A4(p);
        if(flag)*state=2;break;
    }
    case 2:func_0217CFE8(p,5,1);*state=21;func_021E8AB4((u32)sys,3);break;
    case 3:LIVEBATTLEMATCH_FLOW_DrawMenu(p,0);*state=4;break;
    case 4:{
        int v=LIVEBATTLEMATCH_FLOW_GetWindowResult((int *)p);
        if(v!=-1){LIVEBATTLEMATCH_FLOW_HideWindow((int *)p);switch(v){case 0:*state=8;break;case 1:*state=5;break;}}break;
    }
    case 5:func_0217CFE8(p,8,1);*state=21;func_021E8AB4((u32)sys,6);break;
    case 6:LIVEBATTLEMATCH_FLOW_DrawMenu(p,0);*state=7;break;
    case 7:{
        int v=LIVEBATTLEMATCH_FLOW_GetWindowResult((int *)p);
        if(v!=-1){LIVEBATTLEMATCH_FLOW_HideWindow((int *)p);switch(v){case 0:*state=19;break;case 1:*state=2;break;}}break;
    }
    case 8:if(func_0217D2B0(p)){func_0217D290(p);*state=9;}break;
    case 9:{
        u32 mask=0;
        void *v=REGULATION_NoOp(((struct Obj00053 *)p)->f38);
        func_0217D2BC(p,((struct Obj00053 *)p)->f30);
        if(POKEPARTY_GetBattleReadyCount(((struct Obj00053 *)p)->f30)==0)*state=11;
        else if(POKE_REGULATION_CheckParty(v,((struct Obj00053 *)p)->f30,&mask)==0)*state=13;
        else *state=10;
        break;
    }
    case 10:func_0217CFE8(p,9,1);*state=21;func_021E8AB4((u32)sys,12);break;
    case 11:func_0217CFE8(p,37,1);*state=21;func_021E8AB4((u32)sys,12);break;
    case 12:if(func_0217D194((int *)p)){func_0217D174((int *)p);*state=20;}break;
    case 13:{
        void *base=GAME_DATA_GetSaveControl(((struct Obj00053 *)p)->f1B8);
        void *rules=BATTLE_BOX_GetFromSave(base);
        void *entry=REGULATION_GetParty(BATTLE_COMPETITION_GetFromSave(base),1);
        void *tmp=func_0200BAF4((int)rules,0x8056);
        BATTLE_BOX_SetLockFlags(rules,2);
        REGULATION_Card_SetValue(((struct Obj00053 *)p)->f38,10,2);
        REGULATION_BuildParty((int)entry,(int)tmp);
        func_020307B0(tmp);
        *state=14;break;
    }
    case 14:func_0217CFE8(p,10,2);*state=21;func_021E8AB4((u32)sys,15);break;
    case 15:GAME_DATA_SaveStart(*(int *)&((struct Obj00053 *)p)->f1B8);*state=16;break;
    case 16:if(GAME_DATA_SaveMain(*(u8 * *)&((struct Obj00053 *)p)->f1B8)==2)*state=17;break;
    case 17:func_0217D1A0(p,0);func_0217CFE8(p,11,1);*state=21;func_021E8AB4((u32)sys,18);break;
    case 18:func_021E8AA0(sys,(int)LIVEBATTLEMATCH_FLOW_Battle);break;
    case 19:{
        int flag=1;
        flag&=func_0217D194((int *)p);
        flag&=func_0217D2B0(p);
        if(flag){func_0217D174((int *)p);func_0217D290(p);*state=20;}break;
    }
    case 20:func_0217D010(p,1);break;
    case 21:if(func_0217D000(p))func_021E8AB8((u32)sys);break;
    }
}
