/*
 * function: LIVEBATTLEMATCH_FLOW_Main
 * address: 0x0217BBDC
 * packet: pkt_ov176_0217BBDC
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFIBATTLEMATCH_UTIL_SetCallback 0x021E8AA0 thumb ov177
 *   LIVEBATTLEMATCH_FLOW_Battle 0x0217C2EC thumb ov176
 *   DIGITALCARDCHECK_CreateRecord 0x0217D028 thumb ov176
 *   DIGITALCARDCHECK_SetRecordMode 0x0217D1A0 thumb ov176
 *   DIGITALCARDCHECK_IsRecordDone 0x0217D188 thumb ov176
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   BATTLE_BOX_GetFromSave 0x0200BAC8 thumb
 *   DIGITALCARDCHECK_UpdateMenu 0x0217CFE8 thumb ov176
 *   WIFIBATTLEMATCH_UTIL_SetRequest 0x021E8AB4 thumb ov177
 *   LIVEBATTLEMATCH_FLOW_DrawMenu 0x0217CEAC thumb ov176
 *   LIVEBATTLEMATCH_FLOW_GetWindowResult 0x0217CFDC thumb ov176
 *   LIVEBATTLEMATCH_FLOW_HideWindow 0x0217CFD0 thumb ov176
 *   DIGITALCARDCHECK_IsWorkDone 0x0217D194 thumb ov176
 *   DIGITALCARDCHECK_DeleteRecord 0x0217D174 thumb ov176
 *   DIGITALCARDCHECK_End 0x0217D010 thumb ov176
 *   BATTLE_COMPETITION_GetFromSave 0x0200B358 thumb
 *   REGULATION_GetParty 0x0200B204 thumb
 *   REGULATION_Card_SetValue 0x0200B110 thumb
 *   GAME_DATA_SaveStart 0x02012DAC thumb
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 *   DIGITALCARDCHECK_GetMenuResult 0x0217D000 thumb ov176
 *   WIFIBATTLEMATCH_UTIL_CommitRequest 0x021E8AB8 thumb ov177
 *   REGULATION_Card_GetValue 0x0200B078 thumb
 *   LIVEBATTLEMATCH_FLOW_Confirm 0x0217BFF8 thumb ov176
 *   BATTLE_BOX_IsLocked 0x0200BBFC thumb
 *   WIFIBATTLEMATCH_VIEW_SetActorVisible 0x021E7E0C thumb ov177
 *   LIVEBATTLEMATCH_IRC_CreateDelivery 0x0217E318 thumb ov176
 *   LIVEBATTLEMATCH_IRC_DeliveryMain 0x0217E380 thumb ov176
 *   LIVEBATTLEMATCH_IRC_CheckError 0x0217E078 thumb ov176
 *   KEY_GetTrg 0x020362DC arm
 *   LIVEBATTLEMATCH_IRC_ClearState 0x0217E40C thumb ov176
 *   LIVEBATTLEMATCH_IRC_DeliveryEnd 0x0217E414 thumb ov176
 *   REGULATION_Card_IsCrcValid 0x0200B1A8 thumb
 *   BATTLE_REC_ClearWork 0x0200B480 thumb
 *   func_0200E904 0x0200E904 thumb
 *   REGULATION_InitParty 0x0200B1F8 thumb
 *   REGULATION_SetCard 0x0200B1E0 thumb
 */
#include "../include/Obj00053.h"
typedef unsigned char u8;
typedef unsigned u32;
extern void WIFIBATTLEMATCH_UTIL_SetCallback(int *,int);
struct Big;
struct Obj;
struct Rec1E;
struct RecBig;
extern void LIVEBATTLEMATCH_FLOW_Battle(int *sys, u32 *state, u8 *p);
extern void DIGITALCARDCHECK_CreateRecord(u8 *);
extern void DIGITALCARDCHECK_SetRecordMode(u8 *,int);
extern int DIGITALCARDCHECK_IsRecordDone(u8 *);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void * BATTLE_BOX_GetFromSave(void *);
extern void DIGITALCARDCHECK_UpdateMenu(void *,int,int);
extern void WIFIBATTLEMATCH_UTIL_SetRequest(u32,u32);
extern void LIVEBATTLEMATCH_FLOW_DrawMenu(u8 *p, int mode);
typedef signed int     s32;
struct Rec160;
struct Reg2;
extern int LIVEBATTLEMATCH_FLOW_GetWindowResult(int *p);
extern void LIVEBATTLEMATCH_FLOW_HideWindow(int *p);
extern int DIGITALCARDCHECK_IsWorkDone(int *p);
extern void DIGITALCARDCHECK_DeleteRecord(int *);
extern void DIGITALCARDCHECK_End(u8 *,int);
extern void * BATTLE_COMPETITION_GetFromSave(void *);
extern struct Rec1E *REGULATION_GetParty(struct RecBig *p, u32 index);
extern void REGULATION_Card_SetValue(struct Reg2 *p, u32 id, s32 value);
extern int GAME_DATA_SaveStart(int);
extern int GAME_DATA_SaveMain(u8 *);
extern int DIGITALCARDCHECK_GetMenuResult(u8 *);
extern void WIFIBATTLEMATCH_UTIL_CommitRequest(u32);
extern s32 REGULATION_Card_GetValue(struct Reg2 *p, u32 id);
extern void LIVEBATTLEMATCH_FLOW_Confirm(int *sys, u32 *state, u8 *p);
extern u32 BATTLE_BOX_IsLocked(struct Obj *p, u32 mask);
extern void WIFIBATTLEMATCH_VIEW_SetActorVisible(void **,int);
extern void LIVEBATTLEMATCH_IRC_CreateDelivery(char *,unsigned);
extern int LIVEBATTLEMATCH_IRC_DeliveryMain(char *);
extern int LIVEBATTLEMATCH_IRC_CheckError(u8 *p);
extern u32 KEY_GetTrg(void);
extern void LIVEBATTLEMATCH_IRC_ClearState(int *);
extern int LIVEBATTLEMATCH_IRC_DeliveryEnd(char *);
extern u32 REGULATION_Card_IsCrcValid(struct Reg2 *p);
extern void BATTLE_REC_ClearWork(void);
extern void func_0200E904(void *);
extern void REGULATION_InitParty(struct Rec1E *p);
extern void REGULATION_SetCard(struct Rec160 *arr, u32 index, const struct Rec160 *src);
void LIVEBATTLEMATCH_FLOW_Main(int *sys,u32 *state,u8 *p)
{
    switch(*state){
    case 0:
        switch(REGULATION_Card_GetValue(((struct Obj00053 *)p)->f38,10)){
        case 0:case 3:case 4:case 5:
            if(REGULATION_Card_GetValue(((struct Obj00053 *)p)->f38,2)==0)*state=12;else *state=1;break;
        case 1:WIFIBATTLEMATCH_UTIL_SetCallback(sys,(int)LIVEBATTLEMATCH_FLOW_Confirm);break;
        case 2:WIFIBATTLEMATCH_UTIL_SetCallback(sys,(int)LIVEBATTLEMATCH_FLOW_Battle);break;
        }break;
    case 1:DIGITALCARDCHECK_CreateRecord(p);DIGITALCARDCHECK_SetRecordMode(p,1);*state=2;break;
    case 2:if(DIGITALCARDCHECK_IsRecordDone(p))*state=3;break;
    case 3:if(BATTLE_BOX_IsLocked(BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl(((struct Obj00053 *)p)->f1B8)),2))*state=5;else *state=4;break;
    case 4:DIGITALCARDCHECK_UpdateMenu(p,0,1);*state=31;WIFIBATTLEMATCH_UTIL_SetRequest((u32)sys,6);break;
    case 5:DIGITALCARDCHECK_UpdateMenu(p,1,1);*state=31;WIFIBATTLEMATCH_UTIL_SetRequest((u32)sys,6);break;
    case 6:LIVEBATTLEMATCH_FLOW_DrawMenu(p,0);*state=7;break;
    case 7:{
        int v=LIVEBATTLEMATCH_FLOW_GetWindowResult((int *)p);
        if(v!=-1){LIVEBATTLEMATCH_FLOW_HideWindow((int *)p);switch(v){case 0:*state=8;break;case 1:*state=10;break;}}break;
    }
    case 8:if(DIGITALCARDCHECK_IsWorkDone((int *)p))*state=9;break;
    case 9:DIGITALCARDCHECK_DeleteRecord((int *)p);*state=12;break;
    case 10:if(DIGITALCARDCHECK_IsWorkDone((int *)p))*state=11;break;
    case 11:DIGITALCARDCHECK_DeleteRecord((int *)p);DIGITALCARDCHECK_End(p,1);break;
    case 12:DIGITALCARDCHECK_UpdateMenu(p,2,1);*state=31;WIFIBATTLEMATCH_UTIL_SetRequest((u32)sys,13);break;
    case 13:WIFIBATTLEMATCH_VIEW_SetActorVisible(*(void ** *)&((struct Obj00053 *)p)->f1C,1);DIGITALCARDCHECK_UpdateMenu(p,32,0);*state=31;WIFIBATTLEMATCH_UTIL_SetRequest((u32)sys,14);break;
    case 14:LIVEBATTLEMATCH_IRC_CreateDelivery(*(char * *)&((struct Obj00053 *)p)->fC,(u32)(p+0x3c));*state=15;break;
    case 15:{
        int v=LIVEBATTLEMATCH_IRC_DeliveryMain(*(char * *)&((struct Obj00053 *)p)->fC);
        if(v){WIFIBATTLEMATCH_VIEW_SetActorVisible(*(void ** *)&((struct Obj00053 *)p)->f1C,0);if(v==1)*state=21;else *state=26;}
        if(LIVEBATTLEMATCH_IRC_CheckError(((struct Obj00053 *)p)->fC)==1){WIFIBATTLEMATCH_VIEW_SetActorVisible(*(void ** *)&((struct Obj00053 *)p)->f1C,0);*state=12;}
        else if(KEY_GetTrg()&2)*state=16;
        break;
    }
    case 16:LIVEBATTLEMATCH_IRC_ClearState(*(int * *)&((struct Obj00053 *)p)->fC);*state=17;break;
    case 17:if(LIVEBATTLEMATCH_IRC_DeliveryEnd(*(char * *)&((struct Obj00053 *)p)->fC))*state=18;break;
    case 18:WIFIBATTLEMATCH_VIEW_SetActorVisible(*(void ** *)&((struct Obj00053 *)p)->f1C,0);DIGITALCARDCHECK_UpdateMenu(p,21,1);*state=31;WIFIBATTLEMATCH_UTIL_SetRequest((u32)sys,19);break;
    case 19:LIVEBATTLEMATCH_FLOW_DrawMenu(p,0);*state=20;break;
    case 20:{
        int v=LIVEBATTLEMATCH_FLOW_GetWindowResult((int *)p);
        if(v!=-1){LIVEBATTLEMATCH_FLOW_HideWindow((int *)p);switch(v){case 0:*state=30;break;case 1:*state=12;break;}}break;
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
    case 22:BATTLE_REC_ClearWork();DIGITALCARDCHECK_UpdateMenu(p,10,2);*state=31;WIFIBATTLEMATCH_UTIL_SetRequest((u32)sys,23);break;
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
    case 25:DIGITALCARDCHECK_UpdateMenu(p,26,1);*state=31;WIFIBATTLEMATCH_UTIL_SetRequest((u32)sys,30);break;
    case 26:DIGITALCARDCHECK_UpdateMenu(p,27,1);*state=31;WIFIBATTLEMATCH_UTIL_SetRequest((u32)sys,30);break;
    case 27:DIGITALCARDCHECK_UpdateMenu(p,3,1);*state=31;WIFIBATTLEMATCH_UTIL_SetRequest((u32)sys,30);break;
    case 28:DIGITALCARDCHECK_UpdateMenu(p,4,1);*state=31;WIFIBATTLEMATCH_UTIL_SetRequest((u32)sys,30);break;
    case 29:WIFIBATTLEMATCH_UTIL_SetCallback(sys,(int)LIVEBATTLEMATCH_FLOW_Confirm);break;
    case 30:DIGITALCARDCHECK_End(p,1);break;
    case 31:if(DIGITALCARDCHECK_GetMenuResult(p))WIFIBATTLEMATCH_UTIL_CommitRequest((u32)sys);break;
    }
}
