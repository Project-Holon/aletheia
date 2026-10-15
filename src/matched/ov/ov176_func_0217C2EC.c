/*
 * function: LIVEBATTLEMATCH_FLOW_Battle
 * address: 0x0217C2EC
 * packet: pkt_ov176_0217C2EC
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DIGITALCARDCHECK_CreateRecord 0x0217D028 thumb ov176
 *   DIGITALCARDCHECK_SetRecordMode 0x0217D1A0 thumb ov176
 *   DIGITALCARDCHECK_IsRecordDone 0x0217D188 thumb ov176
 *   DIGITALCARDCHECK_IsWorkDone 0x0217D194 thumb ov176
 *   DIGITALCARDCHECK_DeleteRecord 0x0217D174 thumb ov176
 *   DIGITALCARDCHECK_UpdateMenu 0x0217CFE8 thumb ov176
 *   WIFIBATTLEMATCH_UTIL_SetRequest 0x021E8AB4 thumb ov177
 *   LIVEBATTLEMATCH_FLOW_DrawMenu 0x0217CEAC thumb ov176
 *   LIVEBATTLEMATCH_FLOW_GetWindowResult 0x0217CFDC thumb ov176
 *   LIVEBATTLEMATCH_FLOW_HideWindow 0x0217CFD0 thumb ov176
 *   REGULATION_NoOp 0x0200AE14 thumb
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   BATTLE_BOX_GetFromSave 0x0200BAC8 thumb
 *   REGULATION_Card_SetValue 0x0200B110 thumb
 *   GAME_DATA_SaveStart 0x02012DAC thumb
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 *   WIFIBATTLEMATCH_UTIL_SetCallback 0x021E8AA0 thumb ov177
 *   DIGITALCARDCHECK_End 0x0217D010 thumb ov176
 *   DIGITALCARDCHECK_GetMenuResult 0x0217D000 thumb ov176
 *   WIFIBATTLEMATCH_UTIL_CommitRequest 0x021E8AB8 thumb ov177
 *   DIGITALCARDCHECK_BuildBattleRecord 0x0217D2F0 thumb ov176
 *   func_0200E918 0x0200E918 thumb
 *   REGULATION_GetRuleValue 0x0200AE54 thumb
 *   LIVEBATTLEMATCH_FLOW_Sub 0x0217CC78 thumb ov176
 *   LIVEBATTLEMATCH_FLOW_Result 0x0217C628 thumb ov176
 *   BATTLE_BOX_ClearLockFlags 0x0200BBD8 thumb
 *   BATTLE_REC_IsVersionSupported 0x0200BA38 thumb
 */
#include "../include/Obj00053.h"
#include "../include/Obj24408.h"
#include "../include/Obj24409.h"
#include "../include/Obj24410.h"
typedef unsigned char u8;
typedef unsigned u32;
extern void DIGITALCARDCHECK_CreateRecord(u8 *);
extern void DIGITALCARDCHECK_SetRecordMode(u8 *,int);
extern int DIGITALCARDCHECK_IsRecordDone(u8 *);
extern int DIGITALCARDCHECK_IsWorkDone(int *p);
extern void DIGITALCARDCHECK_DeleteRecord(int *);
extern void DIGITALCARDCHECK_UpdateMenu(void *,int,int);
extern void WIFIBATTLEMATCH_UTIL_SetRequest(u32,u32);
typedef signed int     s32;
typedef unsigned short u16;
struct Big;
struct Obj;
struct Reg;
struct Reg2;
extern void LIVEBATTLEMATCH_FLOW_DrawMenu(u8 *p, int mode);
extern int LIVEBATTLEMATCH_FLOW_GetWindowResult(int *p);
extern void LIVEBATTLEMATCH_FLOW_HideWindow(int *p);
extern void * REGULATION_NoOp(void *);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void * BATTLE_BOX_GetFromSave(void *);
extern void REGULATION_Card_SetValue(struct Reg2 *p, u32 id, s32 value);
extern int GAME_DATA_SaveStart(int);
extern int GAME_DATA_SaveMain(u8 *);
extern void WIFIBATTLEMATCH_UTIL_SetCallback(int *,int);
extern void DIGITALCARDCHECK_End(u8 *,int);
extern int DIGITALCARDCHECK_GetMenuResult(u8 *);
extern void WIFIBATTLEMATCH_UTIL_CommitRequest(u32);
extern void DIGITALCARDCHECK_BuildBattleRecord(u8 *,u8 *);
extern u8 func_0200E918(const u8 *base, u32 idx);
extern u32 REGULATION_GetRuleValue(struct Reg *p, u32 id);
extern void LIVEBATTLEMATCH_FLOW_Sub(int *a, int *state, u8 *p);
extern void LIVEBATTLEMATCH_FLOW_Result(int *sys, u32 *state, u8 *p);
extern void BATTLE_BOX_ClearLockFlags(struct Obj *p, int v);
extern u32 BATTLE_REC_IsVersionSupported(u32 v);
void LIVEBATTLEMATCH_FLOW_Battle(int *sys,u32 *state,u8 *p)
{
    switch(*state){
    case 0:DIGITALCARDCHECK_BuildBattleRecord(*(u8 * *)&((struct Obj00053 *)p)->f1BC,p);if(*(int *)&((struct Obj00053 *)p)->f10)*state=4;else{DIGITALCARDCHECK_CreateRecord(p);DIGITALCARDCHECK_SetRecordMode(p,0);*state=1;}break;
    case 1:if(DIGITALCARDCHECK_IsRecordDone(p))*state=2;break;
    case 2:if(((struct Obj24408 *)(*(u8 * *)&((struct Obj00053 *)p)->f1C4))->fC)*state=3;else *state=4;break;
    case 3:DIGITALCARDCHECK_UpdateMenu(p,39,1);*state=25;WIFIBATTLEMATCH_UTIL_SetRequest((u32)sys,4);break;
    case 4:{
        void *v=REGULATION_NoOp(((struct Obj00053 *)p)->f38);
        unsigned sel=func_0200E918(*(u8 * *)&((struct Obj00053 *)p)->f34,0);
        if(sel>=REGULATION_GetRuleValue(v,22))WIFIBATTLEMATCH_UTIL_SetCallback(sys,(int)LIVEBATTLEMATCH_FLOW_Sub);else *state=5;break;
    }
    case 5:DIGITALCARDCHECK_UpdateMenu(p,12,1);*state=25;WIFIBATTLEMATCH_UTIL_SetRequest((u32)sys,6);break;
    case 6:LIVEBATTLEMATCH_FLOW_DrawMenu(p,1);*state=7;break;
    case 7:{
        int v=LIVEBATTLEMATCH_FLOW_GetWindowResult((int *)p);
        if(v!=-1){LIVEBATTLEMATCH_FLOW_HideWindow((int *)p);
            if(((struct Obj00053 *)p)->f1D0&&((struct Obj24409 *)(*(u8 * *)&((struct Obj00053 *)p)->f1C4))->fC==0){
                switch(v){case 0:*state=23;break;case 1:*state=19;break;case 2:*state=8;break;}
            }else switch(v){case 0:*state=23;break;case 1:*state=8;break;}
        }break;
    }
    case 8:DIGITALCARDCHECK_UpdateMenu(p,17,1);*state=25;WIFIBATTLEMATCH_UTIL_SetRequest((u32)sys,9);break;
    case 9:LIVEBATTLEMATCH_FLOW_DrawMenu(p,3);*state=10;break;
    case 10:{
        int v=LIVEBATTLEMATCH_FLOW_GetWindowResult((int *)p);
        if(v!=-1){LIVEBATTLEMATCH_FLOW_HideWindow((int *)p);switch(v){case 0:*state=11;break;case 1:*state=5;break;}}break;
    }
    case 11:DIGITALCARDCHECK_UpdateMenu(p,18,1);*state=25;WIFIBATTLEMATCH_UTIL_SetRequest((u32)sys,12);break;
    case 12:LIVEBATTLEMATCH_FLOW_DrawMenu(p,3);*state=13;break;
    case 13:{
        int v=LIVEBATTLEMATCH_FLOW_GetWindowResult((int *)p);
        if(v!=-1){LIVEBATTLEMATCH_FLOW_HideWindow((int *)p);switch(v){case 0:*state=14;break;case 1:*state=5;break;}}break;
    }
    case 14:DIGITALCARDCHECK_UpdateMenu(p,10,2);*state=25;WIFIBATTLEMATCH_UTIL_SetRequest((u32)sys,15);break;
    case 15:REGULATION_Card_SetValue(((struct Obj00053 *)p)->f38,10,4);BATTLE_BOX_ClearLockFlags(BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl(((struct Obj00053 *)p)->f1B8)),2);GAME_DATA_SaveStart(*(int *)&((struct Obj00053 *)p)->f1B8);*state=16;break;
    case 16:switch((u32)GAME_DATA_SaveMain(*(u8 * *)&((struct Obj00053 *)p)->f1B8)){case 2:case 3:*state=17;break;case 0:case 1:break;}break;
    case 17:DIGITALCARDCHECK_SetRecordMode(p,1);DIGITALCARDCHECK_UpdateMenu(p,19,1);*state=25;WIFIBATTLEMATCH_UTIL_SetRequest((u32)sys,18);break;
    case 18:if(DIGITALCARDCHECK_IsWorkDone((int *)p)){DIGITALCARDCHECK_DeleteRecord((int *)p);*state=24;}break;
    case 19:if(BATTLE_REC_IsVersionSupported((u8)(((struct Obj24410 *)(*(u8 * *)&((struct Obj00053 *)p)->f1C0))->f44)))*state=20;else *state=21;break;
    case 20:DIGITALCARDCHECK_UpdateMenu(p,16,1);*state=25;WIFIBATTLEMATCH_UTIL_SetRequest((u32)sys,22);break;
    case 21:DIGITALCARDCHECK_UpdateMenu(p,34,1);*state=25;WIFIBATTLEMATCH_UTIL_SetRequest((u32)sys,5);break;
    case 22:DIGITALCARDCHECK_End(p,4);break;
    case 23:WIFIBATTLEMATCH_UTIL_SetCallback(sys,(int)LIVEBATTLEMATCH_FLOW_Result);break;
    case 24:DIGITALCARDCHECK_End(p,1);break;
    case 25:if(DIGITALCARDCHECK_GetMenuResult(p))WIFIBATTLEMATCH_UTIL_CommitRequest((u32)sys);break;
    }
}
