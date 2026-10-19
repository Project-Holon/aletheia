/*
 * file:     livebattlematch_flow.c
 * unit:     yes
 * function: LIVEBATTLEMATCH_FLOW_Create, LIVEBATTLEMATCH_FLOW_Delete, LIVEBATTLEMATCH_FLOW_Release, LIVEBATTLEMATCH_FLOW_GetResult, LIVEBATTLEMATCH_FLOW_SelectPhase, LIVEBATTLEMATCH_FLOW_End, LIVEBATTLEMATCH_FLOW_Main, LIVEBATTLEMATCH_FLOW_Confirm, LIVEBATTLEMATCH_FLOW_Battle, LIVEBATTLEMATCH_FLOW_Result, LIVEBATTLEMATCH_FLOW_Card, LIVEBATTLEMATCH_FLOW_Sub, LIVEBATTLEMATCH_FLOW_DrawMenu, LIVEBATTLEMATCH_FLOW_HideWindow, LIVEBATTLEMATCH_FLOW_GetWindowResult
 * address:  0x0217B984
 * region:   ov176
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from battle_championship_flow.c by tools/splitfile.py.
 *
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   WIFIBATTLEMATCH_UTIL_CreateCallback 0x021E8A3C thumb ov177
 *   WIFIBATTLEMATCH_UTIL_DeleteCallback  0x021E8A78  thumb  ov177
 *   WIFIBATTLEMATCH_UTIL_InvokeCallback 0x021E8A80 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_IsCallbackNull 0x021E8A90 thumb ov177
 *   WIFIBATTLEMATCH_GRAPHIC_GetCamera  0x021E5548  thumb  ov177
 *   GF_FONT_Create 0x0201D7EC thumb
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   WIFIBATTLEMATCH_UTIL_SetCallback 0x021E8AA0 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_ClearCallback 0x021E8AA8 thumb ov177
 *   GF_PANIC_Fail 0x02034714 arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   BATTLE_REC_ClearWork 0x0200B480 thumb
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   BATTLE_COMPETITION_GetFromSave 0x0200B358 thumb
 *   REGULATION_GetCard 0x0200B1D4 thumb
 *   WIFIBATTLEMATCH_UTIL_CreateMenu 0x021E88B0 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_DeleteMenu 0x021E89D0 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_UpdateMenu 0x021E8A00 thumb ov177
 *   BATTLE_REC_IsDataExist 0x0200B45C thumb
 *   WIFIBATTLEMATCH_VIEW_LoadBgPalette 0x021E58A4 thumb ov177
 *   WORDSET_Create 0x0201EC74 thumb
 *   LIVEBATTLEMATCH_IRC_Create 0x0217E00C thumb ov176
 *   WIFIBATTLEMATCH_VIEW_CreateActorArray 0x021E7D20 thumb ov177
 *   WIFIBATTLEMATCH_VIEW_SetActorVisible 0x021E7E0C thumb ov177
 *   LIVEBATTLEMATCH_SAVE_GetFromSave 0x0200E9F4 thumb
 *   LIVEBATTLEMATCH_SAVE_GetRecord 0x0200EA08 thumb
 *   POKEPARTY_Create 0x0201A920 thumb
 *   UI_SetSoftResetInhibitGlobal 0x0203516C arm
 *   d_0217E600 0x0217E600 data a4
 *   UI_ClearSoftResetInhibitGlobal 0x020351A0 arm
 *   DIGITALCARDCHECK_DeleteRecord 0x0217D174 thumb ov176
 *   DIGITALCARDCHECK_DeleteRecord2 0x0217D224 thumb ov176
 *   WIFIBATTLEMATCH_VIEW_DeleteActorArray 0x021E7DF0 thumb ov177
 *   LIVEBATTLEMATCH_IRC_Delete 0x0217E058 thumb ov176
 *   WORDSET_Delete 0x0201ED04 thumb
 *   LIVEBATTLEMATCH_IRC_NoOp 0x0217E074 thumb ov176
 *   WIFIBATTLEMATCH_VIEW_Noop 0x021E7E08 thumb ov177
 *   WIFIBATTLEMATCH_VIEW_UpdatePokeList 0x021E64C0 thumb ov177
 *   WIFIBATTLEMATCH_VIEW_UpdateRecordWindow 0x021E7774 thumb ov177
 *   WIFIBATTLEMATCH_VIEW_UpdatePartyWindow 0x021E84F8 thumb ov177
 *   REGULATION_Card_GetValue 0x0200B078 thumb
 *   d_0217E618 0x0217E618 data a4
 *   DIGITALCARDCHECK_CreateRecord 0x0217D028 thumb ov176
 *   DIGITALCARDCHECK_SetRecordMode 0x0217D1A0 thumb ov176
 *   DIGITALCARDCHECK_IsRecordDone 0x0217D188 thumb ov176
 *   BATTLE_BOX_GetFromSave 0x0200BAC8 thumb
 *   DIGITALCARDCHECK_UpdateMenu 0x0217CFE8 thumb ov176
 *   WIFIBATTLEMATCH_UTIL_SetRequest 0x021E8AB4 thumb ov177
 *   DIGITALCARDCHECK_IsWorkDone 0x0217D194 thumb ov176
 *   DIGITALCARDCHECK_End 0x0217D010 thumb ov176
 *   REGULATION_GetParty 0x0200B204 thumb
 *   REGULATION_Card_SetValue 0x0200B110 thumb
 *   GAME_DATA_SaveStart 0x02012DAC thumb
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 *   DIGITALCARDCHECK_GetMenuResult 0x0217D000 thumb ov176
 *   WIFIBATTLEMATCH_UTIL_CommitRequest 0x021E8AB8 thumb ov177
 *   BATTLE_BOX_IsLocked 0x0200BBFC thumb
 *   LIVEBATTLEMATCH_IRC_CreateDelivery 0x0217E318 thumb ov176
 *   LIVEBATTLEMATCH_IRC_DeliveryMain 0x0217E380 thumb ov176
 *   LIVEBATTLEMATCH_IRC_CheckError 0x0217E078 thumb ov176
 *   KEY_GetTrg 0x020362DC arm
 *   LIVEBATTLEMATCH_IRC_ClearState 0x0217E40C thumb ov176
 *   LIVEBATTLEMATCH_IRC_DeliveryEnd 0x0217E414 thumb ov176
 *   REGULATION_Card_IsCrcValid 0x0200B1A8 thumb
 *   LIVEBATTLEMATCH_SAVE_InitRecord 0x0200E904 thumb
 *   REGULATION_InitParty 0x0200B1F8 thumb
 *   REGULATION_SetCard 0x0200B1E0 thumb
 *   DIGITALCARDCHECK_CreateRecord3 0x0217D244 thumb ov176
 *   DIGITALCARDCHECK_IsRecord3DoneA 0x0217D2A4 thumb ov176
 *   DIGITALCARDCHECK_IsRecord3DoneB 0x0217D2B0 thumb ov176
 *   DIGITALCARDCHECK_DeleteRecord3 0x0217D290 thumb ov176
 *   REGULATION_NoOp 0x0200AE14 thumb
 *   DIGITALCARDCHECK_CopyRegulation 0x0217D2BC thumb ov176
 *   POKEPARTY_GetBattleReadyCount 0x0201AA50 thumb
 *   POKE_REGULATION_CheckParty 0x0201A090 thumb
 *   BATTLE_BOX_CreateParty 0x0200BAF4 thumb
 *   BATTLE_BOX_SetLockFlags 0x0200BBC8 thumb
 *   REGULATION_BuildParty 0x0200B2A4 thumb
 *   DIGITALCARDCHECK_BuildBattleRecord 0x0217D2F0 thumb ov176
 *   LIVEBATTLEMATCH_SAVE_GetCounter 0x0200E918 thumb
 *   REGULATION_GetRuleValue 0x0200AE54 thumb
 *   BATTLE_BOX_ClearLockFlags 0x0200BBD8 thumb
 *   BATTLE_REC_IsVersionSupported 0x0200BA38 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   LIVEBATTLEMATCH_IRC_InitState 0x0217E0A8 thumb ov176
 *   LIVEBATTLEMATCH_IRC_StartSession 0x0217E0B0 thumb ov176
 *   LIVEBATTLEMATCH_IRC_Exit 0x0217E158 thumb ov176
 *   LIVEBATTLEMATCH_IRC_WaitExit 0x0217E178 thumb ov176
 *   DIGITALCARDCHECK_SetBattleRecordValue 0x0217D388 thumb ov176
 *   LIVEBATTLEMATCH_IRC_SendRegulation 0x0217E1FC thumb ov176
 *   LIVEBATTLEMATCH_IRC_TakeRegulation 0x0217E23C thumb ov176
 *   POKE_REGULATION_GetDataSize 0x0201A918 thumb
 *   MI_CpuCopy8 0x02082D44 arm
 *   LIVEBATTLEMATCH_SAVE_HasOpponentMac 0x0200E994 thumb
 *   GFL_USE_StopAllSe 0x02006210 thumb
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   LIVEBATTLEMATCH_IRC_SendSyncValue 0x0217E2C0 thumb ov176
 *   LIVEBATTLEMATCH_IRC_RecvSyncValue 0x0217E2F8 thumb ov176
 *   LIVEBATTLEMATCH_IRC_ResetState 0x0217E1B8 thumb ov176
 *   LIVEBATTLEMATCH_IRC_EndSession 0x0217E1C0 thumb ov176
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   DIGITALCARDCHECK_CreateRecord2 0x0217D1C8 thumb ov176
 *   DIGITALCARDCHECK_IsRecord2Done 0x0217D238 thumb ov176
 *   MET_TRAINERS_GetFromSave 0x0200ED48 thumb
 *   MYSTATUS_GetId 0x02008530 thumb
 *   MET_TRAINERS_Insert 0x0200ED54 thumb
 *   LIVEBATTLEMATCH_SAVE_SetOpponentMac 0x0200E958 thumb
 *   LIVEBATTLEMATCH_SAVE_SetOpponentResultByte 0x0200E978 thumb
 *   LIVEBATTLEMATCH_SAVE_AddCounter 0x0200E920 thumb
 *   DIGITALCARDCHECK_WaitRecord 0x0217D160 thumb ov176
 */
#include "../version.h"
#include "livebattlematch_shared_types.h"
#include "livebattlematch_shared_types.h"

struct Party;

struct WordSet;

struct Reg2;

struct Obj;

struct Rec1E;

struct RecBig;

struct Reg;

struct Entry;

struct Link;

struct L0200ED54;

struct MyStatus;









extern void WIFIBATTLEMATCH_UTIL_InvokeCallback(FlowCallback *cb);
extern void MI_CpuFill8(void *,int,unsigned);

extern int *WIFIBATTLEMATCH_UTIL_CreateCallback(int a, int b, int c);

extern void WIFIBATTLEMATCH_UTIL_DeleteCallback(int);

extern int WIFIBATTLEMATCH_UTIL_IsCallbackNull(int **);

extern int WIFIBATTLEMATCH_GRAPHIC_GetCamera(int *p);

#include "../arm9/gf_font.h"

extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);

extern u32 MSGDATA_Delete(struct Rec *rec);


extern void WIFIBATTLEMATCH_UTIL_SetCallback(int *p, int v);

extern void WIFIBATTLEMATCH_UTIL_ClearCallback(int a);

#include "../arm9/gf_panic.h"

#include "../arm9/gfl_heap_wrap.h"


typedef unsigned long long u64;
#include "../arm9/battle_rec.h"

extern void *GAME_DATA_GetSaveControl(struct Big *p);

extern void *BATTLE_COMPETITION_GetFromSave(void *);

extern struct RegulationCard *REGULATION_GetCard(struct RegulationCard *arr, u32 index);

extern void *WIFIBATTLEMATCH_UTIL_CreateMenu(WifibattlematchMenuDesc *,u8,u8,u8,u32,int);

extern void WIFIBATTLEMATCH_UTIL_DeleteMenu(void *);

extern int WIFIBATTLEMATCH_UTIL_UpdateMenu(void *);


extern void WIFIBATTLEMATCH_VIEW_LoadBgPalette(int,int,u32);

extern void *WORDSET_Create(u32,u32,u32);

extern void *LIVEBATTLEMATCH_IRC_Create(int,int);

extern void **WIFIBATTLEMATCH_VIEW_CreateActorArray(void *,void *,u32);

extern void WIFIBATTLEMATCH_VIEW_SetActorVisible(void **,int);

#include "../arm9/livebattlematch_savedata.h"


#include "../arm9/pokeparty.h"

#include "../arm9/ui.h"


#include "digitalcardcheck.h"


extern void WIFIBATTLEMATCH_VIEW_DeleteActorArray(int *p);

extern void LIVEBATTLEMATCH_IRC_Delete(int *p);

extern unsigned int WORDSET_Delete(struct WordSet *p);

extern void LIVEBATTLEMATCH_IRC_NoOp(int);

extern void WIFIBATTLEMATCH_VIEW_Noop(int);

extern int WIFIBATTLEMATCH_VIEW_UpdatePokeList(unsigned char *, void *);

extern int WIFIBATTLEMATCH_VIEW_UpdateRecordWindow(void *p, void *mgr);

extern int WIFIBATTLEMATCH_VIEW_UpdatePartyWindow(char *p, void *q);

extern s32 REGULATION_Card_GetValue(struct Reg2 *p, unsigned int id);




extern void * BATTLE_BOX_GetFromSave(void *);


extern void WIFIBATTLEMATCH_UTIL_SetRequest(unsigned int,unsigned int);



extern struct Rec1E *REGULATION_GetParty(struct RecBig *p, unsigned int index);

extern void REGULATION_Card_SetValue(struct Reg2 *p, unsigned int id, s32 value);

extern int GAME_DATA_SaveStart(int);

extern int GAME_DATA_SaveMain(u8 *);


extern void WIFIBATTLEMATCH_UTIL_CommitRequest(unsigned int);

extern unsigned int BATTLE_BOX_IsLocked(struct Obj *p, unsigned int mask);

extern void LIVEBATTLEMATCH_IRC_CreateDelivery(char *,unsigned);

extern int LIVEBATTLEMATCH_IRC_DeliveryMain(char *);

extern int LIVEBATTLEMATCH_IRC_CheckError(u8 *p);

#include "../arm9/key.h"

extern void LIVEBATTLEMATCH_IRC_ClearState(int *);

extern int LIVEBATTLEMATCH_IRC_DeliveryEnd(char *);

extern unsigned int REGULATION_Card_IsCrcValid(struct Reg2 *p);


extern void REGULATION_InitParty(struct Rec1E *p);

extern void REGULATION_SetCard(struct RegulationCard *arr, unsigned int index, const struct RegulationCard *src);





extern void * REGULATION_NoOp(void *);



extern int POKE_REGULATION_CheckParty(void *,void *,unsigned int *);

extern void * BATTLE_BOX_CreateParty(int,int);

extern void BATTLE_BOX_SetLockFlags(struct Obj *p, unsigned int v);

extern void REGULATION_BuildParty(int,int);



extern unsigned int REGULATION_GetRuleValue(struct Reg *p, unsigned int id);

extern void BATTLE_BOX_ClearLockFlags(struct Obj *p, int v);


#include "../arm9/gfl_use.h"

extern int LIVEBATTLEMATCH_IRC_InitState(int *);

extern int LIVEBATTLEMATCH_IRC_StartSession(unsigned *);

extern void LIVEBATTLEMATCH_IRC_Exit(unsigned *);

extern int LIVEBATTLEMATCH_IRC_WaitExit(int *);


extern int LIVEBATTLEMATCH_IRC_SendRegulation(int,int);

extern int LIVEBATTLEMATCH_IRC_TakeRegulation(char *,void **);

extern int POKE_REGULATION_GetDataSize(void);

extern void MI_CpuCopy8(const void *,void *,unsigned int);



extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);

extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *,unsigned int,unsigned int);

extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *,unsigned int,unsigned int);

extern unsigned int LIVEBATTLEMATCH_IRC_SendSyncValue(int unused, int a);

extern int LIVEBATTLEMATCH_IRC_RecvSyncValue(u8 *p, const void *q);

extern int LIVEBATTLEMATCH_IRC_ResetState(int *);

extern int LIVEBATTLEMATCH_IRC_EndSession(int *);

#include "../arm9/bg_sys.h"



#include "../arm9/met_trainers_savedata.h"

#include "../arm9/mystatus.h"






u8 *LIVEBATTLEMATCH_FLOW_Create(LiveBattleMatchInit *src,u32 heap);

void LIVEBATTLEMATCH_FLOW_Delete(int *p);

void LIVEBATTLEMATCH_FLOW_Release(int *p);

int LIVEBATTLEMATCH_FLOW_GetResult(int *p);

void LIVEBATTLEMATCH_FLOW_SelectPhase(int p,int *state,char *q);

void LIVEBATTLEMATCH_FLOW_End(int p);

void LIVEBATTLEMATCH_FLOW_Main(int *sys,unsigned int *state,u8 *p);

void LIVEBATTLEMATCH_FLOW_Confirm(int *sys,unsigned int *state,u8 *p);

void LIVEBATTLEMATCH_FLOW_Battle(int *sys,unsigned int *state,u8 *p);

void LIVEBATTLEMATCH_FLOW_Result(int *sys,unsigned int *state,u8 *p);

void LIVEBATTLEMATCH_FLOW_Card(int *sys,unsigned int *state,u8 *p);

void LIVEBATTLEMATCH_FLOW_Sub(int *a, int *state, u8 *p);

void LIVEBATTLEMATCH_FLOW_DrawMenu(u8 *p, int mode);

void LIVEBATTLEMATCH_FLOW_HideWindow(int *p);

int LIVEBATTLEMATCH_FLOW_GetWindowResult(int *p);

extern const char d_0217E600[];

extern const char d_0217E618[];

/*
 * Note 2026-10-04 (wD2 lane12): byte-correct. Only unresolved relocation: LIVEBATTLEMATCH_SAVE_GetRecord (witness). Filed src/matched/arm9/LIVEBATTLEMATCH_SAVE_GetRecord.c (EXACT) this wave; it needs a manifest/shard so the witness exists, then this file re-verifies as EXACT with no C change.
 *   unsigned char *LIVEBATTLEMATCH_SAVE_GetRecord(unsigned char *p) { return p; }
 */
u8 *LIVEBATTLEMATCH_FLOW_Create(LiveBattleMatchInit *src,u32 heap)
{
    int size=0x109;
    u8 *p;
    size=0x1dc;
    p=GFL_HEAP_Alloc(heap,size,0,d_0217E600,0x109);
    MI_CpuFill8(p,0,size);
    *(LiveBattleMatchInit *)(p+0x1a0)=*src;
    *(u16 *)(p+0x1c8)=heap;
    *(u32 *)(p+0x1d0)=BATTLE_REC_IsDataExist();
    WIFIBATTLEMATCH_VIEW_LoadBgPalette(*(int *)(p+0x1b0),1,heap);
    *(void **)(p+0x2c)=WORDSET_Create(8,0x40,heap);
    *(void **)(p+0x20)=MSGDATA_CreateFromArchive(0,2,0x3a,heap);
    *(void **)(p+0x24)=MSGDATA_CreateFromArchive(0,2,0xd2,heap);
    *(void **)(p+0x28)=GF_FONT_Create(0x17,3,0,0,heap);
    *(int **)p=WIFIBATTLEMATCH_UTIL_CreateCallback((int)p,(int)LIVEBATTLEMATCH_FLOW_SelectPhase,heap);
    *(void **)(p+0xc)=LIVEBATTLEMATCH_IRC_Create(*(int *)(p+0x1b8),heap);
    *(void ***)(p+0x1c)=WIFIBATTLEMATCH_VIEW_CreateActorArray((void *)WIFIBATTLEMATCH_GRAPHIC_GetCamera(*(int **)(p+0x1b4)),*(void **)(p+0x1b0),heap);
    WIFIBATTLEMATCH_VIEW_SetActorVisible(*(void ***)(p+0x1c),0);
    *(void **)(p+0x38)=REGULATION_GetCard(BATTLE_COMPETITION_GetFromSave(GAME_DATA_GetSaveControl(*(void **)(p+0x1b8))),1);
    *(void **)(p+0x34)=(void *)LIVEBATTLEMATCH_SAVE_GetRecord((int)LIVEBATTLEMATCH_SAVE_GetFromSave(GAME_DATA_GetSaveControl(*(void **)(p+0x1b8))));
    *(void **)(p+0x30)=POKEPARTY_Create(heap);
    if(*(int *)(p+0x1a0)==0)UI_SetSoftResetInhibitGlobal(8);
    return p;
}

void LIVEBATTLEMATCH_FLOW_Delete(int *p)
{
    GFL_HEAP_Free((void *)p[12]);
    if (p[0x67] == 1) UI_ClearSoftResetInhibitGlobal(8);
    DIGITALCARDCHECK_DeleteRecord(p);
    DIGITALCARDCHECK_DeleteRecord2(p);
    WIFIBATTLEMATCH_VIEW_DeleteActorArray((int *)p[7]);
    LIVEBATTLEMATCH_IRC_Delete((int *)p[3]);
    WIFIBATTLEMATCH_UTIL_DeleteCallback((int)((void *)p[0]));
    GF_FONT_Delete((void *)p[10]);
    MSGDATA_Delete((struct Rec *)p[9]);
    MSGDATA_Delete((struct Rec *)p[8]);
    WORDSET_Delete((struct WordSet *)p[11]);
    GFL_HEAP_Free(p);
}

void LIVEBATTLEMATCH_FLOW_Release(int *p)
{
    WIFIBATTLEMATCH_UTIL_InvokeCallback((FlowCallback *)p[0]);
    LIVEBATTLEMATCH_IRC_NoOp(p[3]);
    WIFIBATTLEMATCH_VIEW_Noop(p[7]);
    if (p[4]) WIFIBATTLEMATCH_VIEW_UpdatePokeList((unsigned char *)p[4], (void *)p[0x6B]);
    if (p[5]) WIFIBATTLEMATCH_VIEW_UpdateRecordWindow((void *)p[5], (void *)p[0x6B]);
    if (p[6]) WIFIBATTLEMATCH_VIEW_UpdatePartyWindow((char *)p[6], (void *)p[0x6B]);
}

int LIVEBATTLEMATCH_FLOW_GetResult(int *p)
{
    if (WIFIBATTLEMATCH_UTIL_IsCallbackNull((int **)(((struct LiveBattleMatchWork *)p)->proc)))
        return ((struct LiveBattleMatchWork *)p)->flowResult;
    return 0;
}

void LIVEBATTLEMATCH_FLOW_SelectPhase(int p,int *state,char *q)
{
    switch(((struct LiveBattleMatchWork *)q)->initMode) {
    case 0: WIFIBATTLEMATCH_UTIL_SetCallback((int *)p,(int)LIVEBATTLEMATCH_FLOW_Main); break;
    case 1:
        if(REGULATION_Card_GetValue((struct Reg2 *)(((struct LiveBattleMatchWork *)q)->card),10)==3) WIFIBATTLEMATCH_UTIL_SetCallback((int *)p,(int)LIVEBATTLEMATCH_FLOW_Sub);
        else WIFIBATTLEMATCH_UTIL_SetCallback((int *)p,(int)LIVEBATTLEMATCH_FLOW_Battle);
        break;
    case 2: WIFIBATTLEMATCH_UTIL_SetCallback((int *)p,(int)LIVEBATTLEMATCH_FLOW_Card); break;
    case 3: WIFIBATTLEMATCH_UTIL_SetCallback((int *)p,(int)LIVEBATTLEMATCH_FLOW_Sub); break;
    default: GF_PANIC_Fail(d_0217E618,0,d_0217E618); break;
    }
}

void LIVEBATTLEMATCH_FLOW_End(int p) {WIFIBATTLEMATCH_UTIL_ClearCallback(p);}

void LIVEBATTLEMATCH_FLOW_Main(int *sys,unsigned int *state,u8 *p)
{
    switch(*state){
    case 0:
        switch(REGULATION_Card_GetValue(((struct LiveBattleMatchWork *)p)->card,10)){
        case 0:case 3:case 4:case 5:
            if(REGULATION_Card_GetValue(((struct LiveBattleMatchWork *)p)->card,2)==0)*state=12;else *state=1;break;
        case 1:WIFIBATTLEMATCH_UTIL_SetCallback(sys,(int)LIVEBATTLEMATCH_FLOW_Confirm);break;
        case 2:WIFIBATTLEMATCH_UTIL_SetCallback(sys,(int)LIVEBATTLEMATCH_FLOW_Battle);break;
        }break;
    case 1:DIGITALCARDCHECK_CreateRecord(p);DIGITALCARDCHECK_SetRecordMode(p,1);*state=2;break;
    case 2:if(DIGITALCARDCHECK_IsRecordDone(p))*state=3;break;
    case 3:if(BATTLE_BOX_IsLocked(BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl(((struct LiveBattleMatchWork *)p)->save)),2))*state=5;else *state=4;break;
    case 4:DIGITALCARDCHECK_UpdateMenu(p,0,1);*state=31;WIFIBATTLEMATCH_UTIL_SetRequest((unsigned int)sys,6);break;
    case 5:DIGITALCARDCHECK_UpdateMenu(p,1,1);*state=31;WIFIBATTLEMATCH_UTIL_SetRequest((unsigned int)sys,6);break;
    case 6:LIVEBATTLEMATCH_FLOW_DrawMenu(p,0);*state=7;break;
    case 7:{
        int v=LIVEBATTLEMATCH_FLOW_GetWindowResult((int *)p);
        if(v!=-1){LIVEBATTLEMATCH_FLOW_HideWindow((int *)p);switch(v){case 0:*state=8;break;case 1:*state=10;break;}}break;
    }
    case 8:if(DIGITALCARDCHECK_IsWorkDone((int *)p))*state=9;break;
    case 9:DIGITALCARDCHECK_DeleteRecord((int *)p);*state=12;break;
    case 10:if(DIGITALCARDCHECK_IsWorkDone((int *)p))*state=11;break;
    case 11:DIGITALCARDCHECK_DeleteRecord((int *)p);DIGITALCARDCHECK_End(p,1);break;
    case 12:DIGITALCARDCHECK_UpdateMenu(p,2,1);*state=31;WIFIBATTLEMATCH_UTIL_SetRequest((unsigned int)sys,13);break;
    case 13:WIFIBATTLEMATCH_VIEW_SetActorVisible(*(void ** *)&((struct LiveBattleMatchWork *)p)->viewObj,1);DIGITALCARDCHECK_UpdateMenu(p,32,0);*state=31;WIFIBATTLEMATCH_UTIL_SetRequest((unsigned int)sys,14);break;
    case 14:LIVEBATTLEMATCH_IRC_CreateDelivery(*(char * *)&((struct LiveBattleMatchWork *)p)->irc,(unsigned int)(p+0x3c));*state=15;break;
    case 15:{
        int v=LIVEBATTLEMATCH_IRC_DeliveryMain(*(char * *)&((struct LiveBattleMatchWork *)p)->irc);
        if(v){WIFIBATTLEMATCH_VIEW_SetActorVisible(*(void ** *)&((struct LiveBattleMatchWork *)p)->viewObj,0);if(v==1)*state=21;else *state=26;}
        if(LIVEBATTLEMATCH_IRC_CheckError(((struct LiveBattleMatchWork *)p)->irc)==1){WIFIBATTLEMATCH_VIEW_SetActorVisible(*(void ** *)&((struct LiveBattleMatchWork *)p)->viewObj,0);*state=12;}
        else if(KEY_GetTrg()&2)*state=16;
        break;
    }
    case 16:LIVEBATTLEMATCH_IRC_ClearState(*(int * *)&((struct LiveBattleMatchWork *)p)->irc);*state=17;break;
    case 17:if(LIVEBATTLEMATCH_IRC_DeliveryEnd(*(char * *)&((struct LiveBattleMatchWork *)p)->irc))*state=18;break;
    case 18:WIFIBATTLEMATCH_VIEW_SetActorVisible(*(void ** *)&((struct LiveBattleMatchWork *)p)->viewObj,0);DIGITALCARDCHECK_UpdateMenu(p,21,1);*state=31;WIFIBATTLEMATCH_UTIL_SetRequest((unsigned int)sys,19);break;
    case 19:LIVEBATTLEMATCH_FLOW_DrawMenu(p,0);*state=20;break;
    case 20:{
        int v=LIVEBATTLEMATCH_FLOW_GetWindowResult((int *)p);
        if(v!=-1){LIVEBATTLEMATCH_FLOW_HideWindow((int *)p);switch(v){case 0:*state=30;break;case 1:*state=12;break;}}break;
    }
    case 21:
        if(REGULATION_Card_IsCrcValid((struct Reg2 *)(p+0x3c))){
            unsigned a=REGULATION_Card_GetValue((struct Reg2 *)(p+0x3c),1);
            if(a&PM_VERSION_MASK){
                unsigned a=REGULATION_Card_GetValue(((struct LiveBattleMatchWork *)p)->card,2);
                unsigned b=REGULATION_Card_GetValue((struct Reg2 *)(p+0x3c),2);
                if(a==b){
                    switch(REGULATION_Card_GetValue(((struct LiveBattleMatchWork *)p)->card,10)){
                    case 4:*state=27;break;
                    case 3:*state=28;break;
                    default:*state=22;break;
                    }
                }else *state=22;
            }else *state=26;
        }else *state=25;
        break;
    case 22:BATTLE_REC_ClearWork();DIGITALCARDCHECK_UpdateMenu(p,10,2);*state=31;WIFIBATTLEMATCH_UTIL_SetRequest((unsigned int)sys,23);break;
    case 23:{
        void *base=BATTLE_COMPETITION_GetFromSave(GAME_DATA_GetSaveControl(((struct LiveBattleMatchWork *)p)->save));
        void *entry=REGULATION_GetParty(base,1);
        REGULATION_Card_SetValue((struct Reg2 *)(p+0x3c),10,1);
        LIVEBATTLEMATCH_SAVE_InitRecord(((struct LiveBattleMatchWork *)p)->saveBlock);
        REGULATION_InitParty(entry);
        REGULATION_SetCard(base,1,(const struct RegulationCard *)(p+0x3c));
        GAME_DATA_SaveStart(*(int *)&((struct LiveBattleMatchWork *)p)->save);*state=24;break;
    }
    case 24:if(GAME_DATA_SaveMain(*(u8 * *)&((struct LiveBattleMatchWork *)p)->save)==2)*state=29;break;
    case 25:DIGITALCARDCHECK_UpdateMenu(p,26,1);*state=31;WIFIBATTLEMATCH_UTIL_SetRequest((unsigned int)sys,30);break;
    case 26:DIGITALCARDCHECK_UpdateMenu(p,27,1);*state=31;WIFIBATTLEMATCH_UTIL_SetRequest((unsigned int)sys,30);break;
    case 27:DIGITALCARDCHECK_UpdateMenu(p,3,1);*state=31;WIFIBATTLEMATCH_UTIL_SetRequest((unsigned int)sys,30);break;
    case 28:DIGITALCARDCHECK_UpdateMenu(p,4,1);*state=31;WIFIBATTLEMATCH_UTIL_SetRequest((unsigned int)sys,30);break;
    case 29:WIFIBATTLEMATCH_UTIL_SetCallback(sys,(int)LIVEBATTLEMATCH_FLOW_Confirm);break;
    case 30:DIGITALCARDCHECK_End(p,1);break;
    case 31:if(DIGITALCARDCHECK_GetMenuResult(p))WIFIBATTLEMATCH_UTIL_CommitRequest((unsigned int)sys);break;
    }
}

void LIVEBATTLEMATCH_FLOW_Confirm(int *sys,unsigned int *state,u8 *p)
{
    switch(*state){
    case 0:DIGITALCARDCHECK_CreateRecord(p);DIGITALCARDCHECK_SetRecordMode(p,2);DIGITALCARDCHECK_CreateRecord3((char *)p);*state=1;break;
    case 1:{
        int flag=1;
        flag&=DIGITALCARDCHECK_IsRecordDone(p);
        flag&=DIGITALCARDCHECK_IsRecord3DoneA(p);
        if(flag)*state=2;break;
    }
    case 2:DIGITALCARDCHECK_UpdateMenu(p,5,1);*state=21;WIFIBATTLEMATCH_UTIL_SetRequest((unsigned int)sys,3);break;
    case 3:LIVEBATTLEMATCH_FLOW_DrawMenu(p,0);*state=4;break;
    case 4:{
        int v=LIVEBATTLEMATCH_FLOW_GetWindowResult((int *)p);
        if(v!=-1){LIVEBATTLEMATCH_FLOW_HideWindow((int *)p);switch(v){case 0:*state=8;break;case 1:*state=5;break;}}break;
    }
    case 5:DIGITALCARDCHECK_UpdateMenu(p,8,1);*state=21;WIFIBATTLEMATCH_UTIL_SetRequest((unsigned int)sys,6);break;
    case 6:LIVEBATTLEMATCH_FLOW_DrawMenu(p,0);*state=7;break;
    case 7:{
        int v=LIVEBATTLEMATCH_FLOW_GetWindowResult((int *)p);
        if(v!=-1){LIVEBATTLEMATCH_FLOW_HideWindow((int *)p);switch(v){case 0:*state=19;break;case 1:*state=2;break;}}break;
    }
    case 8:if(DIGITALCARDCHECK_IsRecord3DoneB(p)){DIGITALCARDCHECK_DeleteRecord3(p);*state=9;}break;
    case 9:{
        unsigned int mask=0;
        void *v=REGULATION_NoOp(((struct LiveBattleMatchWork *)p)->card);
        DIGITALCARDCHECK_CopyRegulation(p,((struct LiveBattleMatchWork *)p)->party);
        if(POKEPARTY_GetBattleReadyCount(((struct LiveBattleMatchWork *)p)->party)==0)*state=11;
        else if(POKE_REGULATION_CheckParty(v,((struct LiveBattleMatchWork *)p)->party,&mask)==0)*state=13;
        else *state=10;
        break;
    }
    case 10:DIGITALCARDCHECK_UpdateMenu(p,9,1);*state=21;WIFIBATTLEMATCH_UTIL_SetRequest((unsigned int)sys,12);break;
    case 11:DIGITALCARDCHECK_UpdateMenu(p,37,1);*state=21;WIFIBATTLEMATCH_UTIL_SetRequest((unsigned int)sys,12);break;
    case 12:if(DIGITALCARDCHECK_IsWorkDone((int *)p)){DIGITALCARDCHECK_DeleteRecord((int *)p);*state=20;}break;
    case 13:{
        void *base=GAME_DATA_GetSaveControl(((struct LiveBattleMatchWork *)p)->save);
        void *rules=BATTLE_BOX_GetFromSave(base);
        void *entry=REGULATION_GetParty(BATTLE_COMPETITION_GetFromSave(base),1);
        void *tmp=BATTLE_BOX_CreateParty((int)rules,0x8056);
        BATTLE_BOX_SetLockFlags(rules,2);
        REGULATION_Card_SetValue(((struct LiveBattleMatchWork *)p)->card,10,2);
        REGULATION_BuildParty((int)entry,(int)tmp);
        GFL_HEAP_Free(tmp);
        *state=14;break;
    }
    case 14:DIGITALCARDCHECK_UpdateMenu(p,10,2);*state=21;WIFIBATTLEMATCH_UTIL_SetRequest((unsigned int)sys,15);break;
    case 15:GAME_DATA_SaveStart(*(int *)&((struct LiveBattleMatchWork *)p)->save);*state=16;break;
    case 16:if(GAME_DATA_SaveMain(*(u8 * *)&((struct LiveBattleMatchWork *)p)->save)==2)*state=17;break;
    case 17:DIGITALCARDCHECK_SetRecordMode(p,0);DIGITALCARDCHECK_UpdateMenu(p,11,1);*state=21;WIFIBATTLEMATCH_UTIL_SetRequest((unsigned int)sys,18);break;
    case 18:WIFIBATTLEMATCH_UTIL_SetCallback(sys,(int)LIVEBATTLEMATCH_FLOW_Battle);break;
    case 19:{
        int flag=1;
        flag&=DIGITALCARDCHECK_IsWorkDone((int *)p);
        flag&=DIGITALCARDCHECK_IsRecord3DoneB(p);
        if(flag){DIGITALCARDCHECK_DeleteRecord((int *)p);DIGITALCARDCHECK_DeleteRecord3(p);*state=20;}break;
    }
    case 20:DIGITALCARDCHECK_End(p,1);break;
    case 21:if(DIGITALCARDCHECK_GetMenuResult(p))WIFIBATTLEMATCH_UTIL_CommitRequest((unsigned int)sys);break;
    }
}

void LIVEBATTLEMATCH_FLOW_Battle(int *sys,unsigned int *state,u8 *p)
{
    switch(*state){
    case 0:DIGITALCARDCHECK_BuildBattleRecord(*(u8 * *)&((struct LiveBattleMatchWork *)p)->battleData,p);if(*(int *)&((struct LiveBattleMatchWork *)p)->record)*state=4;else{DIGITALCARDCHECK_CreateRecord(p);DIGITALCARDCHECK_SetRecordMode(p,0);*state=1;}break;
    case 1:if(DIGITALCARDCHECK_IsRecordDone(p))*state=2;break;
    case 2:if(((struct LiveMatchState *)(*(u8 * *)&((struct LiveBattleMatchWork *)p)->stateObj))->flag)*state=3;else *state=4;break;
    case 3:DIGITALCARDCHECK_UpdateMenu(p,39,1);*state=25;WIFIBATTLEMATCH_UTIL_SetRequest((unsigned int)sys,4);break;
    case 4:{
        void *v=REGULATION_NoOp(((struct LiveBattleMatchWork *)p)->card);
        unsigned sel=LIVEBATTLEMATCH_SAVE_GetCounter(*(u8 * *)&((struct LiveBattleMatchWork *)p)->saveBlock,0);
        if(sel>=REGULATION_GetRuleValue(v,22))WIFIBATTLEMATCH_UTIL_SetCallback(sys,(int)LIVEBATTLEMATCH_FLOW_Sub);else *state=5;break;
    }
    case 5:DIGITALCARDCHECK_UpdateMenu(p,12,1);*state=25;WIFIBATTLEMATCH_UTIL_SetRequest((unsigned int)sys,6);break;
    case 6:LIVEBATTLEMATCH_FLOW_DrawMenu(p,1);*state=7;break;
    case 7:{
        int v=LIVEBATTLEMATCH_FLOW_GetWindowResult((int *)p);
        if(v!=-1){LIVEBATTLEMATCH_FLOW_HideWindow((int *)p);
            if(((struct LiveBattleMatchWork *)p)->hasExtraOption&&((struct LiveMatchState *)(*(u8 * *)&((struct LiveBattleMatchWork *)p)->stateObj))->flag==0){
                switch(v){case 0:*state=23;break;case 1:*state=19;break;case 2:*state=8;break;}
            }else switch(v){case 0:*state=23;break;case 1:*state=8;break;}
        }break;
    }
    case 8:DIGITALCARDCHECK_UpdateMenu(p,17,1);*state=25;WIFIBATTLEMATCH_UTIL_SetRequest((unsigned int)sys,9);break;
    case 9:LIVEBATTLEMATCH_FLOW_DrawMenu(p,3);*state=10;break;
    case 10:{
        int v=LIVEBATTLEMATCH_FLOW_GetWindowResult((int *)p);
        if(v!=-1){LIVEBATTLEMATCH_FLOW_HideWindow((int *)p);switch(v){case 0:*state=11;break;case 1:*state=5;break;}}break;
    }
    case 11:DIGITALCARDCHECK_UpdateMenu(p,18,1);*state=25;WIFIBATTLEMATCH_UTIL_SetRequest((unsigned int)sys,12);break;
    case 12:LIVEBATTLEMATCH_FLOW_DrawMenu(p,3);*state=13;break;
    case 13:{
        int v=LIVEBATTLEMATCH_FLOW_GetWindowResult((int *)p);
        if(v!=-1){LIVEBATTLEMATCH_FLOW_HideWindow((int *)p);switch(v){case 0:*state=14;break;case 1:*state=5;break;}}break;
    }
    case 14:DIGITALCARDCHECK_UpdateMenu(p,10,2);*state=25;WIFIBATTLEMATCH_UTIL_SetRequest((unsigned int)sys,15);break;
    case 15:REGULATION_Card_SetValue(((struct LiveBattleMatchWork *)p)->card,10,4);BATTLE_BOX_ClearLockFlags(BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl(((struct LiveBattleMatchWork *)p)->save)),2);GAME_DATA_SaveStart(*(int *)&((struct LiveBattleMatchWork *)p)->save);*state=16;break;
    case 16:switch((unsigned int)GAME_DATA_SaveMain(*(u8 * *)&((struct LiveBattleMatchWork *)p)->save)){case 2:case 3:*state=17;break;case 0:case 1:break;}break;
    case 17:DIGITALCARDCHECK_SetRecordMode(p,1);DIGITALCARDCHECK_UpdateMenu(p,19,1);*state=25;WIFIBATTLEMATCH_UTIL_SetRequest((unsigned int)sys,18);break;
    case 18:if(DIGITALCARDCHECK_IsWorkDone((int *)p)){DIGITALCARDCHECK_DeleteRecord((int *)p);*state=24;}break;
    case 19:if(BATTLE_REC_IsVersionSupported((u8)(((struct BattleRecord *)(*(u8 * *)&((struct LiveBattleMatchWork *)p)->partyData))->version)))*state=20;else *state=21;break;
    case 20:DIGITALCARDCHECK_UpdateMenu(p,16,1);*state=25;WIFIBATTLEMATCH_UTIL_SetRequest((unsigned int)sys,22);break;
    case 21:DIGITALCARDCHECK_UpdateMenu(p,34,1);*state=25;WIFIBATTLEMATCH_UTIL_SetRequest((unsigned int)sys,5);break;
    case 22:DIGITALCARDCHECK_End(p,4);break;
    case 23:WIFIBATTLEMATCH_UTIL_SetCallback(sys,(int)LIVEBATTLEMATCH_FLOW_Result);break;
    case 24:DIGITALCARDCHECK_End(p,1);break;
    case 25:if(DIGITALCARDCHECK_GetMenuResult(p))WIFIBATTLEMATCH_UTIL_CommitRequest((unsigned int)sys);break;
    }
}

/*
 * prototypes: E1FC and E2C0 return r0 consumed by the original although their own C returns void.
 */
void LIVEBATTLEMATCH_FLOW_Result(int *sys,unsigned int *state,u8 *p)
{
    if(LIVEBATTLEMATCH_IRC_CheckError(((struct LiveBattleMatchWork *)p)->irc)==1){
        ((struct LiveMatchState *)(*(u8 * *)&((struct LiveBattleMatchWork *)p)->stateObj))->flag=1;
        WIFIBATTLEMATCH_UTIL_SetCallback(sys,(int)LIVEBATTLEMATCH_FLOW_Battle);
    }
    switch(*state){
    case 0:DIGITALCARDCHECK_UpdateMenu(p,20,1);*state=40;WIFIBATTLEMATCH_UTIL_SetRequest((unsigned int)sys,1);break;
    case 1:DIGITALCARDCHECK_UpdateMenu(p,33,0);WIFIBATTLEMATCH_VIEW_SetActorVisible(*(void ** *)&((struct LiveBattleMatchWork *)p)->viewObj,1);GFL_USE_PlaySeDefaultVolume(0x80d);((struct LiveBattleMatchWork *)p)->syncFlag=0;((struct LiveBattleMatchWork *)p)->syncValue=0;*state=40;WIFIBATTLEMATCH_UTIL_SetRequest((unsigned int)sys,2);break;
    case 2:if(LIVEBATTLEMATCH_IRC_InitState(*(int * *)&((struct LiveBattleMatchWork *)p)->irc))*state=3;break;
    case 3:switch(LIVEBATTLEMATCH_IRC_StartSession(*(unsigned * *)&((struct LiveBattleMatchWork *)p)->irc)){case 1:*state=13;break;case 2:*state=9;break;}if(KEY_GetTrg()&2)*state=4;break;
    case 4:LIVEBATTLEMATCH_IRC_Exit(*(unsigned * *)&((struct LiveBattleMatchWork *)p)->irc);*state=5;break;
    case 5:if(LIVEBATTLEMATCH_IRC_WaitExit(*(int * *)&((struct LiveBattleMatchWork *)p)->irc))*state=6;break;
    case 6:WIFIBATTLEMATCH_VIEW_SetActorVisible(*(void ** *)&((struct LiveBattleMatchWork *)p)->viewObj,0);DIGITALCARDCHECK_UpdateMenu(p,21,1);*state=40;WIFIBATTLEMATCH_UTIL_SetRequest((unsigned int)sys,7);break;
    case 7:LIVEBATTLEMATCH_FLOW_DrawMenu(p,0);*state=8;break;
    case 8:{
        int v=LIVEBATTLEMATCH_FLOW_GetWindowResult((int *)p);
        if(v!=-1){LIVEBATTLEMATCH_FLOW_HideWindow((int *)p);switch(v){
        case 0:WIFIBATTLEMATCH_VIEW_SetActorVisible(*(void ** *)&((struct LiveBattleMatchWork *)p)->viewObj,0);WIFIBATTLEMATCH_UTIL_SetCallback(sys,(int)LIVEBATTLEMATCH_FLOW_Battle);break;
        case 1:*state=1;break;
        }}break;
    }
    case 9:WIFIBATTLEMATCH_VIEW_SetActorVisible(*(void ** *)&((struct LiveBattleMatchWork *)p)->viewObj,0);LIVEBATTLEMATCH_IRC_Exit(*(unsigned * *)&((struct LiveBattleMatchWork *)p)->irc);*state=10;break;
    case 10:if(LIVEBATTLEMATCH_IRC_WaitExit(*(int * *)&((struct LiveBattleMatchWork *)p)->irc))*state=11;break;
    case 11:DIGITALCARDCHECK_UpdateMenu(p,28,1);*state=40;WIFIBATTLEMATCH_UTIL_SetRequest((unsigned int)sys,12);break;
    case 12:WIFIBATTLEMATCH_UTIL_SetCallback(sys,(int)LIVEBATTLEMATCH_FLOW_Battle);break;
    case 13:DIGITALCARDCHECK_SetBattleRecordValue(*(int * *)&((struct LiveBattleMatchWork *)p)->battleData,(int *)p);if(LIVEBATTLEMATCH_IRC_SendRegulation(*(int *)&((struct LiveBattleMatchWork *)p)->irc,*(int *)&((struct LiveBattleMatchWork *)p)->battleData))*state=14;break;
    case 14:{
        void *out;
        if(LIVEBATTLEMATCH_IRC_TakeRegulation(*(char * *)&((struct LiveBattleMatchWork *)p)->irc,&out)){MI_CpuCopy8(out,((struct LiveBattleMatchWork *)p)->partyData,POKE_REGULATION_GetDataSize()+0xd4);*state=15;}break;
    }
    case 15:
        if(((struct BattleRecord *)(*(u8 * *)&((struct LiveBattleMatchWork *)p)->battleData))->cardValue==((struct BattleRecord *)(*(u8 * *)&((struct LiveBattleMatchWork *)p)->partyData))->cardValue){
            unsigned int a=REGULATION_Card_GetValue(((struct LiveBattleMatchWork *)p)->card,12);
            int b=LIVEBATTLEMATCH_SAVE_HasOpponentMac(((struct LiveBattleMatchWork *)p)->saveBlock,*(u8 * *)&((struct LiveBattleMatchWork *)p)->partyData+0x20);
            ((struct LiveBattleMatchWork *)p)->syncFlag=(a!=0||(a==0&&b==0));
            *state=16;
        }else{WIFIBATTLEMATCH_VIEW_SetActorVisible(*(void ** *)&((struct LiveBattleMatchWork *)p)->viewObj,0);GFL_USE_StopAllSe();*state=21;}
        break;
    case 16:GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x48,0x1f);*state=17;break;
    case 17:if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x48,0x1f))*state=18;break;
    case 18:if(LIVEBATTLEMATCH_IRC_SendSyncValue((int)(((struct LiveBattleMatchWork *)p)->irc),(int)((unsigned int *)(p+0x1d4))))*state=19;break;
    case 19:if(LIVEBATTLEMATCH_IRC_RecvSyncValue(((struct LiveBattleMatchWork *)p)->irc,(unsigned int *)(p+0x1d8)))*state=20;break;
    case 20:
        WIFIBATTLEMATCH_VIEW_SetActorVisible(*(void ** *)&((struct LiveBattleMatchWork *)p)->viewObj,0);GFL_USE_StopAllSe();
        if(((struct LiveBattleMatchWork *)p)->syncValue&&((struct LiveBattleMatchWork *)p)->syncFlag){GFL_USE_PlaySeDefaultVolume(0x63a);*state=27;}else *state=24;break;
    case 21:if(LIVEBATTLEMATCH_IRC_ResetState(*(int * *)&((struct LiveBattleMatchWork *)p)->irc))*state=22;break;
    case 22:if(LIVEBATTLEMATCH_IRC_EndSession(*(int * *)&((struct LiveBattleMatchWork *)p)->irc))*state=23;break;
    case 23:DIGITALCARDCHECK_UpdateMenu(p,22,1);*state=40;WIFIBATTLEMATCH_UTIL_SetRequest((unsigned int)sys,39);break;
    case 24:if(LIVEBATTLEMATCH_IRC_ResetState(*(int * *)&((struct LiveBattleMatchWork *)p)->irc))*state=25;break;
    case 25:if(LIVEBATTLEMATCH_IRC_EndSession(*(int * *)&((struct LiveBattleMatchWork *)p)->irc))*state=26;break;
    case 26:DIGITALCARDCHECK_UpdateMenu(p,36,1);*state=40;WIFIBATTLEMATCH_UTIL_SetRequest((unsigned int)sys,39);break;
    case 27:DIGITALCARDCHECK_UpdateMenu(p,23,1);*state=40;WIFIBATTLEMATCH_UTIL_SetRequest((unsigned int)sys,28);break;
    case 28:if((((struct LiveBattleMatchWork *)p)->timer)++>120){((struct LiveBattleMatchWork *)p)->timer=0;BG_SYS_SetPlaneVisible(0,0);*state=29;}break;
    case 29:DIGITALCARDCHECK_CreateRecord2((char *)p,*(int *)&((struct LiveBattleMatchWork *)p)->partyData);*state=30;break;
    case 30:if(DIGITALCARDCHECK_IsRecord2Done(p))*state=31;break;
    case 31:if((((struct LiveBattleMatchWork *)p)->timer)++>300){((struct LiveBattleMatchWork *)p)->timer=0;*state=32;}break;
    case 32:BG_SYS_SetPlaneVisible(0,1);DIGITALCARDCHECK_UpdateMenu(p,24,1);*state=40;WIFIBATTLEMATCH_UTIL_SetRequest((unsigned int)sys,33);break;
    case 33:DIGITALCARDCHECK_UpdateMenu(p,35,2);*state=40;WIFIBATTLEMATCH_UTIL_SetRequest((unsigned int)sys,34);break;
    case 34:GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x47,0x1f);*state=35;break;
    case 35:if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x47,0x1f))*state=36;break;
    case 36:BG_SYS_SetPlaneVisible(0,1);DIGITALCARDCHECK_UpdateMenu(p,38,2);*state=40;WIFIBATTLEMATCH_UTIL_SetRequest((unsigned int)sys,37);break;
    case 37:
        if((((struct LiveBattleMatchWork *)p)->timer)++>60){
            void *v=REGULATION_NoOp(((struct LiveBattleMatchWork *)p)->card);
            ((struct LiveBattleMatchWork *)p)->timer=0;REGULATION_GetRuleValue(v,19);*state=38;
        }break;
    case 38:DIGITALCARDCHECK_End(p,2);break;
    case 39:WIFIBATTLEMATCH_UTIL_SetCallback(sys,(int)LIVEBATTLEMATCH_FLOW_Battle);break;
    case 40:if(DIGITALCARDCHECK_GetMenuResult(p))WIFIBATTLEMATCH_UTIL_CommitRequest((unsigned int)sys);break;
    }
}

void LIVEBATTLEMATCH_FLOW_Card(int *sys,unsigned int *state,u8 *p)
{
    if(LIVEBATTLEMATCH_IRC_CheckError(((struct LiveBattleMatchWork *)p)->irc)==1){
        ((struct LiveMatchState *)(*(u8 * *)&((struct LiveBattleMatchWork *)p)->stateObj))->flag=1;
        WIFIBATTLEMATCH_UTIL_SetCallback(sys,(int)LIVEBATTLEMATCH_FLOW_Battle);
    }
    switch(*state){
    case 0:{
        void *v=MET_TRAINERS_GetFromSave(GAME_DATA_GetSaveControl(((struct LiveBattleMatchWork *)p)->save));
        MET_TRAINERS_Insert(v,MYSTATUS_GetId(((struct LiveBattleMatchWork *)p)->partyData));
        *state=1;break;
    }
    case 1:if(LIVEBATTLEMATCH_IRC_ResetState(*(int * *)&((struct LiveBattleMatchWork *)p)->irc)) *state=2;break;
    case 2:if(LIVEBATTLEMATCH_IRC_EndSession(*(int * *)&((struct LiveBattleMatchWork *)p)->irc)) *state=3;break;
    case 3:{
        int a=0;
        int b;
        u8 index=(unsigned int)LIVEBATTLEMATCH_SAVE_GetCounter(*(u8 * *)&((struct LiveBattleMatchWork *)p)->saveBlock,0);
        LIVEBATTLEMATCH_SAVE_SetOpponentMac(*(u8 * *)&((struct LiveBattleMatchWork *)p)->saveBlock,index,*(u8 * *)&((struct LiveBattleMatchWork *)p)->partyData+0x20);
        LIVEBATTLEMATCH_SAVE_SetOpponentResultByte(*(u8 * *)&((struct LiveBattleMatchWork *)p)->saveBlock,index,0,(*(u8 **)(p+0x1c4))[8]);
        LIVEBATTLEMATCH_SAVE_SetOpponentResultByte(*(u8 * *)&((struct LiveBattleMatchWork *)p)->saveBlock,index,1,(*(u8 **)(p+0x1c4))[9]);
        b=0;
        switch(**(unsigned int * *)&((struct LiveBattleMatchWork *)p)->stateObj){
        case 1:case 4:a=1;break;
        case 0:case 3:b=1;break;
        case 2:break;
        default:GF_PANIC_Fail(d_0217E618,0,d_0217E618);break;
        }
        LIVEBATTLEMATCH_SAVE_AddCounter(*(u8 * *)&((struct LiveBattleMatchWork *)p)->saveBlock,1,a);
        LIVEBATTLEMATCH_SAVE_AddCounter(*(u8 * *)&((struct LiveBattleMatchWork *)p)->saveBlock,2,b);
        LIVEBATTLEMATCH_SAVE_AddCounter(*(u8 * *)&((struct LiveBattleMatchWork *)p)->saveBlock,0,1);
        DIGITALCARDCHECK_WaitRecord((int *)p);
        *state=4;break;
    }
    case 4:DIGITALCARDCHECK_UpdateMenu(p,10,2);*state=8;WIFIBATTLEMATCH_UTIL_SetRequest((unsigned int)sys,5);break;
    case 5:GAME_DATA_SaveStart(*(int *)&((struct LiveBattleMatchWork *)p)->save);*state=6;break;
    case 6:if(GAME_DATA_SaveMain(*(u8 * *)&((struct LiveBattleMatchWork *)p)->save)==2)*state=7;break;
    case 7:DIGITALCARDCHECK_End(p,3);break;
    case 8:if(DIGITALCARDCHECK_GetMenuResult(p))WIFIBATTLEMATCH_UTIL_CommitRequest((unsigned int)sys);break;
    }
}

/*
 * ABI: 0200AE14 leaves supplied pointer in r0 despite its void own declaration.
 */
void LIVEBATTLEMATCH_FLOW_Sub(int *a, int *state, u8 *p)
{
    void *record;
    unsigned int value;
    int result;
    switch (*state) {
    case 0:
        DIGITALCARDCHECK_WaitRecord((int *)p);
        if (REGULATION_Card_GetValue(((struct LiveBattleMatchWork *)p)->card, 10) == 3) *state = 6;
        else *state = 1;
        break;
    case 1:
        record = REGULATION_NoOp(((struct LiveBattleMatchWork *)p)->card);
        value = LIVEBATTLEMATCH_SAVE_GetCounter(*(u8 * *)&((struct LiveBattleMatchWork *)p)->saveBlock, 0);
        if (value >= REGULATION_GetRuleValue(record, 0x16)) *state = 2;
        else *state = 16;
        break;
    case 2: DIGITALCARDCHECK_UpdateMenu(p, 10, 2); *state = 17; WIFIBATTLEMATCH_UTIL_SetRequest((unsigned int)a, 3); break;
    case 3:
        REGULATION_Card_SetValue(((struct LiveBattleMatchWork *)p)->card, 10, 3);
        BATTLE_BOX_ClearLockFlags(BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl(((struct LiveBattleMatchWork *)p)->save)), 2);
        GAME_DATA_SaveStart((int)(((struct LiveBattleMatchWork *)p)->save)); *state = 4; break;
    case 4:
        switch (GAME_DATA_SaveMain(((struct LiveBattleMatchWork *)p)->save)) {
        case 0: case 1: break;
        case 2: case 3: *state = 5; break;
        }
        break;
    case 5: DIGITALCARDCHECK_SetRecordMode(p, 1); DIGITALCARDCHECK_UpdateMenu(p, 25, 1); *state = 17; WIFIBATTLEMATCH_UTIL_SetRequest((unsigned int)a, 6); break;
    case 6: DIGITALCARDCHECK_UpdateMenu(p, 29, 1); *state = 17; WIFIBATTLEMATCH_UTIL_SetRequest((unsigned int)a, 7); break;
    case 7: LIVEBATTLEMATCH_FLOW_DrawMenu(p, 2); *state = 8; break;
    case 8:
        result = LIVEBATTLEMATCH_FLOW_GetWindowResult((int *)p);
        if (result != -1) {
            LIVEBATTLEMATCH_FLOW_HideWindow((int *)p);
            if (((struct LiveBattleMatchWork *)p)->hasExtraOption && ((struct LiveMatchState *)(*(u8 * *)&((struct LiveBattleMatchWork *)p)->stateObj))->flag == 0) {
                switch (result) { case 0: *state = 11; break; case 1: *state = 9; break; }
            } else if (result == 0) *state = 9;
        }
        break;
    case 9: DIGITALCARDCHECK_UpdateMenu(p, 31, 1); *state = 17; WIFIBATTLEMATCH_UTIL_SetRequest((unsigned int)a, 10); break;
    case 10: if (DIGITALCARDCHECK_IsWorkDone((int *)p)) { DIGITALCARDCHECK_DeleteRecord((int *)p); *state = 15; } break;
    case 11:
        if (BATTLE_REC_IsVersionSupported((u8)(((struct BattleRecord *)(*(u8 * *)&((struct LiveBattleMatchWork *)p)->partyData))->version))) *state = 12;
        else *state = 13;
        break;
    case 12: DIGITALCARDCHECK_UpdateMenu(p, 16, 1); *state = 17; WIFIBATTLEMATCH_UTIL_SetRequest((unsigned int)a, 14); break;
    case 13: DIGITALCARDCHECK_UpdateMenu(p, 34, 1); *state = 17; WIFIBATTLEMATCH_UTIL_SetRequest((unsigned int)a, 6); break;
    case 14: DIGITALCARDCHECK_End(p, 4); break;
    case 15: DIGITALCARDCHECK_End(p, 1); break;
    case 16: WIFIBATTLEMATCH_UTIL_SetCallback(a, (int)LIVEBATTLEMATCH_FLOW_Battle); break;
    case 17: if (DIGITALCARDCHECK_GetMenuResult(p)) WIFIBATTLEMATCH_UTIL_CommitRequest((unsigned int)a); break;
    }
}

/*
 * function_starts: 0217CFD0,0217CFDC
 * ABI: coordinates are byte locals; X/width/height externs are widened because original has no call-site narrowing.
 */
void LIVEBATTLEMATCH_FLOW_DrawMenu(u8 *p, int mode)
{
    WifibattlematchMenuDesc rec;
    int layout;
    u8 x, y, width, height;
    MI_CpuFill8(&rec, 0, 0x30);
    rec.msgBank = ((struct LiveBattleMatchWork *)p)->menuValue;
    rec.font = *(unsigned int *)&((struct LiveBattleMatchWork *)p)->font;
    rec.printQue = *(unsigned int *)&((struct LiveBattleMatchWork *)p)->printQue;
    switch (mode) {
    case 3: rec.row = 1;
    case 0:
        rec.items[0] = 6; rec.items[1] = 7; rec.count = 2; rec.enabled = 1; rec.kind = 1; layout = 1; break;
    case 1:
        rec.enabled = 0;
        if (((struct LiveBattleMatchWork *)p)->hasExtraOption && ((struct LiveMatchState *)(*(u8 * *)&((struct LiveBattleMatchWork *)p)->stateObj))->flag == 0) {
            rec.items[0] = 13; rec.items[1] = 14; rec.items[2] = 15; rec.count = 3;
        } else { rec.items[0] = 13; rec.items[1] = 15; rec.count = 2; }
        layout = 0; break;
    case 2:
        rec.enabled = 0;
        if (((struct LiveBattleMatchWork *)p)->hasExtraOption && ((struct LiveMatchState *)(*(u8 * *)&((struct LiveBattleMatchWork *)p)->stateObj))->flag == 0) {
            rec.items[0] = 14; rec.items[1] = 30; rec.count = 2;
        } else { rec.items[0] = 30; rec.count = 1; }
        layout = 0; break;
    }
    rec.a = 0; rec.b = 15; rec.c = 13; rec.d = 1;
    switch (layout) {
    case 0: width = 28; height = rec.count * 2; x = 2; y = 9 - height / 2; break;
    case 1: width = 12; height = rec.count * 2; x = 19; y = 17 - height; break;
    }
    ((struct LiveBattleMatchWork *)p)->window = WIFIBATTLEMATCH_UTIL_CreateMenu(&rec, x, y, width, height, ((struct LiveBattleMatchWork *)p)->heap);
    ((struct LiveBattleMatchWork *)p)->mode = mode;
}

void LIVEBATTLEMATCH_FLOW_HideWindow(int *p) { WIFIBATTLEMATCH_UTIL_DeleteMenu((void *)p[1]); }

int LIVEBATTLEMATCH_FLOW_GetWindowResult(int *p) { return WIFIBATTLEMATCH_UTIL_UpdateMenu((void *)p[1]); }
