/*
 * function: func_0217BBDC
 * address: 0x0217BBDC
 * packet: pkt_ov176_0217BBDC
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_0217C2EC 0x0217C2EC thumb ov176
 *   func_0217D028 0x0217D028 thumb ov176
 *   func_0217D1A0 0x0217D1A0 thumb ov176
 *   func_0217D188 0x0217D188 thumb ov176
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   BATTLE_BOX_GetFromSave 0x0200BAC8 thumb
 *   func_0217CFE8 0x0217CFE8 thumb ov176
 *   func_021E8AB4 0x021E8AB4 thumb ov177
 *   func_0217CEAC 0x0217CEAC thumb ov176
 *   func_0217CFDC 0x0217CFDC thumb ov176
 *   func_0217CFD0 0x0217CFD0 thumb ov176
 *   func_0217D194 0x0217D194 thumb ov176
 *   func_0217D174 0x0217D174 thumb ov176
 *   func_0217D010 0x0217D010 thumb ov176
 *   BATTLE_COMPETITION_GetFromSave 0x0200B358 thumb
 *   REGULATION_GetParty 0x0200B204 thumb
 *   REGULATION_Card_SetValue 0x0200B110 thumb
 *   GAME_DATA_SaveStart 0x02012DAC thumb
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 *   func_0217D000 0x0217D000 thumb ov176
 *   func_021E8AB8 0x021E8AB8 thumb ov177
 *   REGULATION_Card_GetValue 0x0200B078 thumb
 *   func_0217BFF8 0x0217BFF8 thumb ov176
 *   BATTLE_BOX_IsLocked 0x0200BBFC thumb
 *   func_021E7E0C 0x021E7E0C thumb ov177
 *   func_0217E318 0x0217E318 thumb ov176
 *   func_0217E380 0x0217E380 thumb ov176
 *   func_0217E078 0x0217E078 thumb ov176
 *   KEY_GetTrg 0x020362DC arm
 *   func_0217E40C 0x0217E40C thumb ov176
 *   func_0217E414 0x0217E414 thumb ov176
 *   REGULATION_Card_IsCrcValid 0x0200B1A8 thumb
 *   BATTLE_REC_ClearWork 0x0200B480 thumb
 *   func_0200E904 0x0200E904 thumb
 *   REGULATION_InitParty 0x0200B1F8 thumb
 *   REGULATION_SetCard 0x0200B1E0 thumb
 */
#include "../include/Obj00053.h"
typedef unsigned char u8;
typedef unsigned u32;
extern void func_021E8AA0(int *,int);
struct Big;
struct Obj;
struct Rec1E;
struct RecBig;
extern void func_0217C2EC(int *sys, u32 *state, u8 *p);
extern void func_0217D028(u8 *);
extern void func_0217D1A0(u8 *,int);
extern int func_0217D188(u8 *);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void * BATTLE_BOX_GetFromSave(void *);
extern void func_0217CFE8(void *,int,int);
extern void func_021E8AB4(u32,u32);
extern void func_0217CEAC(u8 *p, int mode);
typedef signed int     s32;
struct Rec160;
struct Reg2;
extern int func_0217CFDC(int *p);
extern void func_0217CFD0(int *p);
extern int func_0217D194(int *p);
extern void func_0217D174(int *);
extern void func_0217D010(u8 *,int);
extern void * BATTLE_COMPETITION_GetFromSave(void *);
extern struct Rec1E *REGULATION_GetParty(struct RecBig *p, u32 index);
extern void REGULATION_Card_SetValue(struct Reg2 *p, u32 id, s32 value);
extern int GAME_DATA_SaveStart(int);
extern int GAME_DATA_SaveMain(u8 *);
extern int func_0217D000(u8 *);
extern void func_021E8AB8(u32);
extern s32 REGULATION_Card_GetValue(struct Reg2 *p, u32 id);
extern void func_0217BFF8(int *sys, u32 *state, u8 *p);
extern u32 BATTLE_BOX_IsLocked(struct Obj *p, u32 mask);
extern void func_021E7E0C(void **,int);
extern void func_0217E318(char *,unsigned);
extern int func_0217E380(char *);
extern int func_0217E078(u8 *p);
extern u32 KEY_GetTrg(void);
extern void func_0217E40C(int *);
extern int func_0217E414(char *);
extern u32 REGULATION_Card_IsCrcValid(struct Reg2 *p);
extern void BATTLE_REC_ClearWork(void);
extern void func_0200E904(void *);
extern void REGULATION_InitParty(struct Rec1E *p);
extern void REGULATION_SetCard(struct Rec160 *arr, u32 index, const struct Rec160 *src);
void func_0217BBDC(int *sys,u32 *state,u8 *p)
{
    switch(*state){
    case 0:
        switch(REGULATION_Card_GetValue(((struct Obj00053 *)p)->f38,10)){
        case 0:case 3:case 4:case 5:
            if(REGULATION_Card_GetValue(((struct Obj00053 *)p)->f38,2)==0)*state=12;else *state=1;break;
        case 1:func_021E8AA0(sys,(int)func_0217BFF8);break;
        case 2:func_021E8AA0(sys,(int)func_0217C2EC);break;
        }break;
    case 1:func_0217D028(p);func_0217D1A0(p,1);*state=2;break;
    case 2:if(func_0217D188(p))*state=3;break;
    case 3:if(BATTLE_BOX_IsLocked(BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl(((struct Obj00053 *)p)->f1B8)),2))*state=5;else *state=4;break;
    case 4:func_0217CFE8(p,0,1);*state=31;func_021E8AB4((u32)sys,6);break;
    case 5:func_0217CFE8(p,1,1);*state=31;func_021E8AB4((u32)sys,6);break;
    case 6:func_0217CEAC(p,0);*state=7;break;
    case 7:{
        int v=func_0217CFDC((int *)p);
        if(v!=-1){func_0217CFD0((int *)p);switch(v){case 0:*state=8;break;case 1:*state=10;break;}}break;
    }
    case 8:if(func_0217D194((int *)p))*state=9;break;
    case 9:func_0217D174((int *)p);*state=12;break;
    case 10:if(func_0217D194((int *)p))*state=11;break;
    case 11:func_0217D174((int *)p);func_0217D010(p,1);break;
    case 12:func_0217CFE8(p,2,1);*state=31;func_021E8AB4((u32)sys,13);break;
    case 13:func_021E7E0C(*(void ** *)&((struct Obj00053 *)p)->f1C,1);func_0217CFE8(p,32,0);*state=31;func_021E8AB4((u32)sys,14);break;
    case 14:func_0217E318(*(char * *)&((struct Obj00053 *)p)->fC,(u32)(p+0x3c));*state=15;break;
    case 15:{
        int v=func_0217E380(*(char * *)&((struct Obj00053 *)p)->fC);
        if(v){func_021E7E0C(*(void ** *)&((struct Obj00053 *)p)->f1C,0);if(v==1)*state=21;else *state=26;}
        if(func_0217E078(((struct Obj00053 *)p)->fC)==1){func_021E7E0C(*(void ** *)&((struct Obj00053 *)p)->f1C,0);*state=12;}
        else if(KEY_GetTrg()&2)*state=16;
        break;
    }
    case 16:func_0217E40C(*(int * *)&((struct Obj00053 *)p)->fC);*state=17;break;
    case 17:if(func_0217E414(*(char * *)&((struct Obj00053 *)p)->fC))*state=18;break;
    case 18:func_021E7E0C(*(void ** *)&((struct Obj00053 *)p)->f1C,0);func_0217CFE8(p,21,1);*state=31;func_021E8AB4((u32)sys,19);break;
    case 19:func_0217CEAC(p,0);*state=20;break;
    case 20:{
        int v=func_0217CFDC((int *)p);
        if(v!=-1){func_0217CFD0((int *)p);switch(v){case 0:*state=30;break;case 1:*state=12;break;}}break;
    }
    case 21:
        if(REGULATION_Card_IsCrcValid((struct Reg2 *)(p+0x3c))){
            unsigned a=REGULATION_Card_GetValue((struct Reg2 *)(p+0x3c),1);
            if(a&0x200000){
                unsigned a=REGULATION_Card_GetValue(((struct Obj00053 *)p)->f38,2);
                unsigned b=REGULATION_Card_GetValue((struct Reg2 *)(p+0x3c),2);
                if(a==b){
                    switch(REGULATION_Card_GetValue(((struct Obj00053 *)p)->f38,10)){
                    case 4:*state=27;break;
                    case 3:*state=28;break;
                    default:*state=22;break;
                    }
                }else *state=22;
            }else *state=26;
        }else *state=25;
        break;
    case 22:BATTLE_REC_ClearWork();func_0217CFE8(p,10,2);*state=31;func_021E8AB4((u32)sys,23);break;
    case 23:{
        void *base=BATTLE_COMPETITION_GetFromSave(GAME_DATA_GetSaveControl(((struct Obj00053 *)p)->f1B8));
        void *entry=REGULATION_GetParty(base,1);
        REGULATION_Card_SetValue((struct Reg2 *)(p+0x3c),10,1);
        func_0200E904(((struct Obj00053 *)p)->f34);
        REGULATION_InitParty(entry);
        REGULATION_SetCard(base,1,(const struct Rec160 *)(p+0x3c));
        GAME_DATA_SaveStart(*(int *)&((struct Obj00053 *)p)->f1B8);*state=24;break;
    }
    case 24:if(GAME_DATA_SaveMain(*(u8 * *)&((struct Obj00053 *)p)->f1B8)==2)*state=29;break;
    case 25:func_0217CFE8(p,26,1);*state=31;func_021E8AB4((u32)sys,30);break;
    case 26:func_0217CFE8(p,27,1);*state=31;func_021E8AB4((u32)sys,30);break;
    case 27:func_0217CFE8(p,3,1);*state=31;func_021E8AB4((u32)sys,30);break;
    case 28:func_0217CFE8(p,4,1);*state=31;func_021E8AB4((u32)sys,30);break;
    case 29:func_021E8AA0(sys,(int)func_0217BFF8);break;
    case 30:func_0217D010(p,1);break;
    case 31:if(func_0217D000(p))func_021E8AB8((u32)sys);break;
    }
}
