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
 *   WORDSET_CreateDefault 0x0201EC64 thumb
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
struct Party;

struct WordSet;

struct BattleCompetitionSave;

struct Obj;

struct Rec1E;

struct RecBig;

struct Regulation;

struct Entry;

struct GFLNetHandle;

struct L0200ED54;

struct MyStatus;

#include "../ov177/wifibattlematch_util.h"
struct WifibattlematchCallback;
                              




#include "../ov177/wifibattlematch_graphic.h"

#include "../arm9/gf_font.h"

#include "../arm9/msgdata.h"




#include "../arm9/gf_panic.h"

#include "../arm9/gfl_heap_wrap.h"

#include "../types.h"
#include "../arm9/battle_rec.h"

struct SaveControl;
struct BattleCompetitionSave;
struct BattleCompetitionSave;

#include "../arm9/regulation.h"

struct WifibattlematchMenuDesc;
struct WifibattlematchMenu;




#include "../ov177/wifibattlematch_view.h"

#include "../arm9/wordset.h"

#include "livebattlematch_irc.h"



#include "../arm9/livebattlematch_savedata.h"

#include "../arm9/pokeparty.h"

#include "../arm9/ui.h"

#include "digitalcardcheck.h"









struct BattleBoxSave;

#include "../arm9/battle_box.h"

struct RegulationParty;


struct GameData;








#include "../arm9/key.h"






struct BoxMonGroup;

                                    






#include "../arm9/gfl_use.h"






struct GFLNetHandle;



#include "../arm9/net_handle.h"







#include "../arm9/bg_sys.h"

#include "../arm9/met_trainers_savedata.h"

#include "../arm9/mystatus.h"

#include "../arm9/game_data.h"
#include "../arm9/mi_memory.h"
#include "../arm9/poke_regulation.h"
#include "livebattlematch_flow.h"

extern const char d_0217E600[];

extern const char d_0217E618[];
extern const char str_ja_0217E59C[];
extern const char str_ja_0217E5B4[];
extern const char str_ja_0217E5B8[];

/*
 * Note 2026-10-04 (wD2 lane12): byte-correct. Only unresolved relocation: LIVEBATTLEMATCH_SAVE_GetRecord (witness). Filed src/matched/arm9/LIVEBATTLEMATCH_SAVE_GetRecord.c (EXACT) this wave; it needs a manifest/shard so the witness exists, then this file re-verifies as EXACT with no C change.
 *   unsigned char *LIVEBATTLEMATCH_SAVE_GetRecord(unsigned char *p) { return p; }
 */
struct LiveBattleMatchWork *LIVEBATTLEMATCH_FLOW_Create(LiveBattleMatchInit *src,u16 heap)
{
    int size=0x109;
    struct LiveBattleMatchWork *p;
    size=0x1dc;
    p=GFL_HEAP_Alloc(heap,size,0,PM_LANG_JA(d_0217E600, str_ja_0217E59C),0x109);
    MI_CpuFill8(p,0,size);
    *(LiveBattleMatchInit *)&p->initMode=*src;
    p->heap=heap;
    p->hasExtraOption=BATTLE_REC_IsDataExist();
    WIFIBATTLEMATCH_VIEW_LoadBgPalette(p->view,1,heap);
#if LANGUAGE == LANGUAGE_JAPANESE
    p->arg2C=WORDSET_CreateDefault(heap);
#else
    p->arg2C=WORDSET_Create(8,0x40,heap);
#endif
    p->menuValue=MSGDATA_CreateFromArchive(0,2,0x3a,heap);
    p->mgr=MSGDATA_CreateFromArchive(0,2,0xd2,heap);
    p->partyFont=GF_FONT_Create(0x17,3,0,0,heap);
    p->proc=WIFIBATTLEMATCH_UTIL_CreateCallback(p, LIVEBATTLEMATCH_FLOW_SelectPhase,heap);
    p->irc=LIVEBATTLEMATCH_IRC_Create(p->save,heap);
    p->viewObj=WIFIBATTLEMATCH_VIEW_CreateActorArray(WIFIBATTLEMATCH_GRAPHIC_GetCamera(p->graphic),p->view,heap);
    WIFIBATTLEMATCH_VIEW_SetActorVisible(p->viewObj,0);
    p->card=REGULATION_GetCard((struct RegulationCard *)(BATTLE_COMPETITION_GetFromSave((struct SaveControl *)(GAME_DATA_GetSaveControl(p->save)))),1);
    p->saveBlock=LIVEBATTLEMATCH_SAVE_GetRecord(LIVEBATTLEMATCH_SAVE_GetFromSave(GAME_DATA_GetSaveControl(p->save)));
    p->party=POKEPARTY_Create(heap);
    if(p->initMode==0)UI_SetSoftResetInhibitGlobal(8);
    return p;
}

void LIVEBATTLEMATCH_FLOW_Delete(struct LiveBattleMatchWork *p)
{
    GFL_HEAP_Free(p->party);
    if (p->flowResult == 1) UI_ClearSoftResetInhibitGlobal(8);
    DIGITALCARDCHECK_DeleteRecord(p);
    DIGITALCARDCHECK_DeleteRecord2(p);
    WIFIBATTLEMATCH_VIEW_DeleteActorArray(p->viewObj);
    LIVEBATTLEMATCH_IRC_Delete(p->irc);
    WIFIBATTLEMATCH_UTIL_DeleteCallback(p->proc);
    GF_FONT_Delete(p->partyFont);
    MSGDATA_Delete(p->mgr);
    MSGDATA_Delete(p->menuValue);
    WORDSET_Delete(p->arg2C);
    GFL_HEAP_Free(p);
}

void LIVEBATTLEMATCH_FLOW_Release(struct LiveBattleMatchWork *p)
{
    WIFIBATTLEMATCH_UTIL_InvokeCallback(p->proc);
    LIVEBATTLEMATCH_IRC_NoOp(p->irc);
    WIFIBATTLEMATCH_VIEW_Noop(p->viewObj);
    if (p->record) WIFIBATTLEMATCH_VIEW_UpdatePokeList(p->record, p->printQue);
    if (p->record2) WIFIBATTLEMATCH_VIEW_UpdateRecordWindow(p->record2, p->printQue);
    if (p->record3) WIFIBATTLEMATCH_VIEW_UpdatePartyWindow(p->record3, p->printQue);
}

int LIVEBATTLEMATCH_FLOW_GetResult(struct LiveBattleMatchWork *p)
{
    if (WIFIBATTLEMATCH_UTIL_IsCallbackNull(p->proc))
        return p->flowResult;
    return 0;
}

void LIVEBATTLEMATCH_FLOW_SelectPhase(WifibattlematchCallback *p, int *state, void *qArg)
{
    struct LiveBattleMatchWork *q = qArg;
    switch(q->initMode) {
    case 0: WIFIBATTLEMATCH_UTIL_SetCallback(p, LIVEBATTLEMATCH_FLOW_Main); break;
    case 1:
        if(REGULATION_Card_GetValue((struct RegulationCard *)((struct BattleCompetitionSave *)(q->card)),10)==3) WIFIBATTLEMATCH_UTIL_SetCallback(p, LIVEBATTLEMATCH_FLOW_Sub);
        else WIFIBATTLEMATCH_UTIL_SetCallback(p, LIVEBATTLEMATCH_FLOW_Battle);
        break;
    case 2: WIFIBATTLEMATCH_UTIL_SetCallback(p, LIVEBATTLEMATCH_FLOW_Card); break;
    case 3: WIFIBATTLEMATCH_UTIL_SetCallback(p, LIVEBATTLEMATCH_FLOW_Sub); break;
    default: GF_PANIC_Fail(PM_LANG_JA(d_0217E618, str_ja_0217E59C),PM_SRC_LINE(0, 0x1c8),PM_LANG_JA(d_0217E618, str_ja_0217E5B4)); break;
    }
}

void LIVEBATTLEMATCH_FLOW_End(WifibattlematchCallback *p, int *unusedState, void *unusedWork) {WIFIBATTLEMATCH_UTIL_ClearCallback(p);}

void LIVEBATTLEMATCH_FLOW_Main(WifibattlematchCallback *sys, int *state, void *pArg)
{
    struct LiveBattleMatchWork *p = pArg;
    switch(*state){
    case 0:
        switch(REGULATION_Card_GetValue(p->card,10)){
        case 0:case 3:case 4:case 5:
            if(REGULATION_Card_GetValue(p->card,2)==0)*state=12;else *state=1;break;
        case 1:WIFIBATTLEMATCH_UTIL_SetCallback(sys, LIVEBATTLEMATCH_FLOW_Confirm);break;
        case 2:WIFIBATTLEMATCH_UTIL_SetCallback(sys, LIVEBATTLEMATCH_FLOW_Battle);break;
        }break;
    case 1:DIGITALCARDCHECK_CreateRecord(p);DIGITALCARDCHECK_SetRecordMode(p,1);*state=2;break;
    case 2:if(DIGITALCARDCHECK_IsRecordDone(p))*state=3;break;
    case 3:if(BATTLE_BOX_IsLocked((struct BattleBoxSave *)(BATTLE_BOX_GetFromSave((struct SaveControl *)(GAME_DATA_GetSaveControl(p->save)))),2))*state=5;else *state=4;break;
    case 4:DIGITALCARDCHECK_UpdateMenu(p,0,1);*state=31;WIFIBATTLEMATCH_UTIL_SetRequest(sys,6);break;
    case 5:DIGITALCARDCHECK_UpdateMenu(p,1,1);*state=31;WIFIBATTLEMATCH_UTIL_SetRequest(sys,6);break;
    case 6:LIVEBATTLEMATCH_FLOW_DrawMenu(p,0);*state=7;break;
    case 7:{
        int v=LIVEBATTLEMATCH_FLOW_GetWindowResult(p);
        if(v!=-1){LIVEBATTLEMATCH_FLOW_HideWindow(p);switch(v){case 0:*state=8;break;case 1:*state=10;break;}}break;
    }
    case 8:if(DIGITALCARDCHECK_IsWorkDone(p))*state=9;break;
    case 9:DIGITALCARDCHECK_DeleteRecord(p);*state=12;break;
    case 10:if(DIGITALCARDCHECK_IsWorkDone(p))*state=11;break;
    case 11:DIGITALCARDCHECK_DeleteRecord(p);DIGITALCARDCHECK_End(p,1);break;
    case 12:DIGITALCARDCHECK_UpdateMenu(p,2,1);*state=31;WIFIBATTLEMATCH_UTIL_SetRequest(sys,13);break;
    case 13:WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)(p->viewObj),1);DIGITALCARDCHECK_UpdateMenu(p,32,0);*state=31;WIFIBATTLEMATCH_UTIL_SetRequest(sys,14);break;
    case 14:LIVEBATTLEMATCH_IRC_CreateDelivery(p->irc,p->card_3C);*state=15;break;
    case 15:{
        int v=LIVEBATTLEMATCH_IRC_DeliveryMain(p->irc);
        if(v){WIFIBATTLEMATCH_VIEW_SetActorVisible(p->viewObj,0);if(v==1)*state=21;else *state=26;}
        if(LIVEBATTLEMATCH_IRC_CheckError(p->irc)==1){WIFIBATTLEMATCH_VIEW_SetActorVisible(p->viewObj,0);*state=12;}
        else if(KEY_GetTrg()&2)*state=16;
        break;
    }
    case 16:LIVEBATTLEMATCH_IRC_ClearState(p->irc);*state=17;break;
    case 17:if(LIVEBATTLEMATCH_IRC_DeliveryEnd(p->irc))*state=18;break;
    case 18:WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)(p->viewObj),0);DIGITALCARDCHECK_UpdateMenu(p,21,1);*state=31;WIFIBATTLEMATCH_UTIL_SetRequest(sys,19);break;
    case 19:LIVEBATTLEMATCH_FLOW_DrawMenu(p,0);*state=20;break;
    case 20:{
        int v=LIVEBATTLEMATCH_FLOW_GetWindowResult(p);
        if(v!=-1){LIVEBATTLEMATCH_FLOW_HideWindow(p);switch(v){case 0:*state=30;break;case 1:*state=12;break;}}break;
    }
    case 21:
        if(REGULATION_Card_IsCrcValid((struct RegulationCard *)(p->card_3C))){
            unsigned a=REGULATION_Card_GetValue((struct RegulationCard *)(p->card_3C),1);
            if(a&PM_VERSION_MASK){
                unsigned a=REGULATION_Card_GetValue((struct RegulationCard *)(p->card),2);
                unsigned b=REGULATION_Card_GetValue((struct RegulationCard *)(p->card_3C),2);
                if(a==b){
                    switch(REGULATION_Card_GetValue(p->card,10)){
                    case 4:*state=27;break;
                    case 3:*state=28;break;
                    default:*state=22;break;
                    }
                }else *state=22;
            }else *state=26;
        }else *state=25;
        break;
    case 22:BATTLE_REC_ClearWork();DIGITALCARDCHECK_UpdateMenu(p,10,2);*state=31;WIFIBATTLEMATCH_UTIL_SetRequest(sys,23);break;
    case 23:{
        void *base=BATTLE_COMPETITION_GetFromSave((struct SaveControl *)(GAME_DATA_GetSaveControl(p->save)));
        void *entry=REGULATION_GetParty((struct BattleCompetitionSave *)base,1);
        REGULATION_Card_SetValue((struct RegulationCard *)(p->card_3C),10,1);
        LIVEBATTLEMATCH_SAVE_InitRecord(p->saveBlock);
        REGULATION_InitParty((struct RegulationParty *)entry);
        REGULATION_SetCard((struct RegulationCard *)base,1,(const struct RegulationCard *)(p->card_3C));
        GAME_DATA_SaveStart((struct GameData *)(p->save));*state=24;break;
    }
    case 24:if(GAME_DATA_SaveMain((struct GameData *)(p->save))==2)*state=29;break;
    case 25:DIGITALCARDCHECK_UpdateMenu(p,26,1);*state=31;WIFIBATTLEMATCH_UTIL_SetRequest(sys,30);break;
    case 26:DIGITALCARDCHECK_UpdateMenu(p,27,1);*state=31;WIFIBATTLEMATCH_UTIL_SetRequest(sys,30);break;
    case 27:DIGITALCARDCHECK_UpdateMenu(p,3,1);*state=31;WIFIBATTLEMATCH_UTIL_SetRequest(sys,30);break;
    case 28:DIGITALCARDCHECK_UpdateMenu(p,4,1);*state=31;WIFIBATTLEMATCH_UTIL_SetRequest(sys,30);break;
    case 29:WIFIBATTLEMATCH_UTIL_SetCallback(sys, LIVEBATTLEMATCH_FLOW_Confirm);break;
    case 30:DIGITALCARDCHECK_End(p,1);break;
    case 31:if(DIGITALCARDCHECK_GetMenuResult(p))WIFIBATTLEMATCH_UTIL_CommitRequest(sys);break;
    }
}

void LIVEBATTLEMATCH_FLOW_Confirm(WifibattlematchCallback *sys, int *state, void *pArg)
{
    struct LiveBattleMatchWork *p = pArg;
    switch(*state){
    case 0:DIGITALCARDCHECK_CreateRecord(p);DIGITALCARDCHECK_SetRecordMode(p,2);DIGITALCARDCHECK_CreateRecord3(p);*state=1;break;
    case 1:{
        int flag=1;
        flag&=DIGITALCARDCHECK_IsRecordDone(p);
        flag&=DIGITALCARDCHECK_IsRecord3DoneA(p);
        if(flag)*state=2;break;
    }
    case 2:DIGITALCARDCHECK_UpdateMenu(p,5,1);*state=21;WIFIBATTLEMATCH_UTIL_SetRequest(sys,3);break;
    case 3:LIVEBATTLEMATCH_FLOW_DrawMenu(p,0);*state=4;break;
    case 4:{
        int v=LIVEBATTLEMATCH_FLOW_GetWindowResult(p);
        if(v!=-1){LIVEBATTLEMATCH_FLOW_HideWindow(p);switch(v){case 0:*state=8;break;case 1:*state=5;break;}}break;
    }
    case 5:DIGITALCARDCHECK_UpdateMenu(p,8,1);*state=21;WIFIBATTLEMATCH_UTIL_SetRequest(sys,6);break;
    case 6:LIVEBATTLEMATCH_FLOW_DrawMenu(p,0);*state=7;break;
    case 7:{
        int v=LIVEBATTLEMATCH_FLOW_GetWindowResult(p);
        if(v!=-1){LIVEBATTLEMATCH_FLOW_HideWindow(p);switch(v){case 0:*state=19;break;case 1:*state=2;break;}}break;
    }
    case 8:if(DIGITALCARDCHECK_IsRecord3DoneB(p)){DIGITALCARDCHECK_DeleteRecord3(p);*state=9;}break;
    case 9:{
        unsigned int mask=0;
        void *v=REGULATION_NoOp(p->card);
        DIGITALCARDCHECK_CopyRegulation(p,p->party);
        if(POKEPARTY_GetBattleReadyCount(p->party)==0)*state=11;
        else if(POKE_REGULATION_CheckParty(v,p->party,&mask)==0)*state=13;
        else *state=10;
        break;
    }
    case 10:DIGITALCARDCHECK_UpdateMenu(p,9,1);*state=21;WIFIBATTLEMATCH_UTIL_SetRequest(sys,12);break;
    case 11:DIGITALCARDCHECK_UpdateMenu(p,37,1);*state=21;WIFIBATTLEMATCH_UTIL_SetRequest(sys,12);break;
    case 12:if(DIGITALCARDCHECK_IsWorkDone(p)){DIGITALCARDCHECK_DeleteRecord(p);*state=20;}break;
    case 13:{
        void *base=GAME_DATA_GetSaveControl(p->save);
        void *rules=BATTLE_BOX_GetFromSave(base);
        void *entry=REGULATION_GetParty(BATTLE_COMPETITION_GetFromSave(base),1);
        void *tmp=BATTLE_BOX_CreateParty(rules,0x8056);
        BATTLE_BOX_SetLockFlags(rules,2);
        REGULATION_Card_SetValue(p->card,10,2);
        REGULATION_BuildParty(entry,tmp);
        GFL_HEAP_Free(tmp);
        *state=14;break;
    }
    case 14:DIGITALCARDCHECK_UpdateMenu(p,10,2);*state=21;WIFIBATTLEMATCH_UTIL_SetRequest(sys,15);break;
    case 15:GAME_DATA_SaveStart((struct GameData *)(p->save));*state=16;break;
    case 16:if(GAME_DATA_SaveMain((struct GameData *)(p->save))==2)*state=17;break;
    case 17:DIGITALCARDCHECK_SetRecordMode(p,0);DIGITALCARDCHECK_UpdateMenu(p,11,1);*state=21;WIFIBATTLEMATCH_UTIL_SetRequest(sys,18);break;
    case 18:WIFIBATTLEMATCH_UTIL_SetCallback(sys, LIVEBATTLEMATCH_FLOW_Battle);break;
    case 19:{
        int flag=1;
        flag&=DIGITALCARDCHECK_IsWorkDone(p);
        flag&=DIGITALCARDCHECK_IsRecord3DoneB(p);
        if(flag){DIGITALCARDCHECK_DeleteRecord(p);DIGITALCARDCHECK_DeleteRecord3(p);*state=20;}break;
    }
    case 20:DIGITALCARDCHECK_End(p,1);break;
    case 21:if(DIGITALCARDCHECK_GetMenuResult(p))WIFIBATTLEMATCH_UTIL_CommitRequest(sys);break;
    }
}

void LIVEBATTLEMATCH_FLOW_Battle(WifibattlematchCallback *sys, int *state, void *pArg)
{
    struct LiveBattleMatchWork *p = pArg;
    switch(*state){
    case 0:DIGITALCARDCHECK_BuildBattleRecord(p->battleData,p);if(p->record)*state=4;else{DIGITALCARDCHECK_CreateRecord(p);DIGITALCARDCHECK_SetRecordMode(p,0);*state=1;}break;
    case 1:if(DIGITALCARDCHECK_IsRecordDone(p))*state=2;break;
    case 2:if(((struct LiveMatchState *)(p->stateObj))->flag)*state=3;else *state=4;break;
    case 3:DIGITALCARDCHECK_UpdateMenu(p,39,1);*state=25;WIFIBATTLEMATCH_UTIL_SetRequest(sys,4);break;
    case 4:{
        void *v=REGULATION_NoOp(p->card);
        unsigned sel=LIVEBATTLEMATCH_SAVE_GetCounter(p->saveBlock,0);
        if(sel>=REGULATION_GetRuleValue((struct Regulation *)v,22))WIFIBATTLEMATCH_UTIL_SetCallback(sys, LIVEBATTLEMATCH_FLOW_Sub);else *state=5;break;
    }
    case 5:DIGITALCARDCHECK_UpdateMenu(p,12,1);*state=25;WIFIBATTLEMATCH_UTIL_SetRequest(sys,6);break;
    case 6:LIVEBATTLEMATCH_FLOW_DrawMenu(p,1);*state=7;break;
    case 7:{
        int v=LIVEBATTLEMATCH_FLOW_GetWindowResult(p);
        if(v!=-1){LIVEBATTLEMATCH_FLOW_HideWindow(p);
            if(p->hasExtraOption&&((struct LiveMatchState *)(p->stateObj))->flag==0){
                switch(v){case 0:*state=23;break;case 1:*state=19;break;case 2:*state=8;break;}
            }else switch(v){case 0:*state=23;break;case 1:*state=8;break;}
        }break;
    }
    case 8:DIGITALCARDCHECK_UpdateMenu(p,17,1);*state=25;WIFIBATTLEMATCH_UTIL_SetRequest(sys,9);break;
    case 9:LIVEBATTLEMATCH_FLOW_DrawMenu(p,3);*state=10;break;
    case 10:{
        int v=LIVEBATTLEMATCH_FLOW_GetWindowResult(p);
        if(v!=-1){LIVEBATTLEMATCH_FLOW_HideWindow(p);switch(v){case 0:*state=11;break;case 1:*state=5;break;}}break;
    }
    case 11:DIGITALCARDCHECK_UpdateMenu(p,18,1);*state=25;WIFIBATTLEMATCH_UTIL_SetRequest(sys,12);break;
    case 12:LIVEBATTLEMATCH_FLOW_DrawMenu(p,3);*state=13;break;
    case 13:{
        int v=LIVEBATTLEMATCH_FLOW_GetWindowResult(p);
        if(v!=-1){LIVEBATTLEMATCH_FLOW_HideWindow(p);switch(v){case 0:*state=14;break;case 1:*state=5;break;}}break;
    }
    case 14:DIGITALCARDCHECK_UpdateMenu(p,10,2);*state=25;WIFIBATTLEMATCH_UTIL_SetRequest(sys,15);break;
    case 15:REGULATION_Card_SetValue((struct RegulationCard *)(p->card),10,4);BATTLE_BOX_ClearLockFlags((struct BattleBoxSave *)(BATTLE_BOX_GetFromSave((struct SaveControl *)(GAME_DATA_GetSaveControl(p->save)))),2);GAME_DATA_SaveStart((struct GameData *)(p->save));*state=16;break;
    case 16:switch((unsigned int)GAME_DATA_SaveMain((struct GameData *)(p->save))){case 2:case 3:*state=17;break;case 0:case 1:break;}break;
    case 17:DIGITALCARDCHECK_SetRecordMode(p,1);DIGITALCARDCHECK_UpdateMenu(p,19,1);*state=25;WIFIBATTLEMATCH_UTIL_SetRequest(sys,18);break;
    case 18:if(DIGITALCARDCHECK_IsWorkDone(p)){DIGITALCARDCHECK_DeleteRecord(p);*state=24;}break;
    case 19:if(BATTLE_REC_IsVersionSupported((u8)(((struct BattleRecord *)(p->partyData))->version)))*state=20;else *state=21;break;
    case 20:DIGITALCARDCHECK_UpdateMenu(p,16,1);*state=25;WIFIBATTLEMATCH_UTIL_SetRequest(sys,22);break;
    case 21:DIGITALCARDCHECK_UpdateMenu(p,34,1);*state=25;WIFIBATTLEMATCH_UTIL_SetRequest(sys,5);break;
    case 22:DIGITALCARDCHECK_End(p,4);break;
    case 23:WIFIBATTLEMATCH_UTIL_SetCallback(sys, LIVEBATTLEMATCH_FLOW_Result);break;
    case 24:DIGITALCARDCHECK_End(p,1);break;
    case 25:if(DIGITALCARDCHECK_GetMenuResult(p))WIFIBATTLEMATCH_UTIL_CommitRequest(sys);break;
    }
}

/*
 * prototypes: E1FC and E2C0 return r0 consumed by the original although their own C returns void.
 */
void LIVEBATTLEMATCH_FLOW_Result(WifibattlematchCallback *sys, int *state, void *pArg)
{
    struct LiveBattleMatchWork *p = pArg;
    if(LIVEBATTLEMATCH_IRC_CheckError(p->irc)==1){
        ((struct LiveMatchState *)(p->stateObj))->flag=1;
        WIFIBATTLEMATCH_UTIL_SetCallback(sys, LIVEBATTLEMATCH_FLOW_Battle);
    }
    switch(*state){
    case 0:DIGITALCARDCHECK_UpdateMenu(p,20,1);*state=40;WIFIBATTLEMATCH_UTIL_SetRequest(sys,1);break;
    case 1:DIGITALCARDCHECK_UpdateMenu(p,33,0);WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)(p->viewObj),1);GFL_USE_PlaySeDefaultVolume(0x80d);p->syncFlag=0;p->syncValue=0;*state=40;WIFIBATTLEMATCH_UTIL_SetRequest(sys,2);break;
    case 2:if(LIVEBATTLEMATCH_IRC_InitState(p->irc))*state=3;break;
    case 3:switch(LIVEBATTLEMATCH_IRC_StartSession(p->irc)){case 1:*state=13;break;case 2:*state=9;break;}if(KEY_GetTrg()&2)*state=4;break;
    case 4:LIVEBATTLEMATCH_IRC_Exit(p->irc);*state=5;break;
    case 5:if(LIVEBATTLEMATCH_IRC_WaitExit(p->irc))*state=6;break;
    case 6:WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)(p->viewObj),0);DIGITALCARDCHECK_UpdateMenu(p,21,1);*state=40;WIFIBATTLEMATCH_UTIL_SetRequest(sys,7);break;
    case 7:LIVEBATTLEMATCH_FLOW_DrawMenu(p,0);*state=8;break;
    case 8:{
        int v=LIVEBATTLEMATCH_FLOW_GetWindowResult(p);
        if(v!=-1){LIVEBATTLEMATCH_FLOW_HideWindow(p);switch(v){
        case 0:WIFIBATTLEMATCH_VIEW_SetActorVisible(p->viewObj,0);WIFIBATTLEMATCH_UTIL_SetCallback(sys, LIVEBATTLEMATCH_FLOW_Battle);break;
        case 1:*state=1;break;
        }}break;
    }
    case 9:WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)(p->viewObj),0);LIVEBATTLEMATCH_IRC_Exit(p->irc);*state=10;break;
    case 10:if(LIVEBATTLEMATCH_IRC_WaitExit(p->irc))*state=11;break;
    case 11:DIGITALCARDCHECK_UpdateMenu(p,28,1);*state=40;WIFIBATTLEMATCH_UTIL_SetRequest(sys,12);break;
    case 12:WIFIBATTLEMATCH_UTIL_SetCallback(sys, LIVEBATTLEMATCH_FLOW_Battle);break;
    case 13:DIGITALCARDCHECK_SetBattleRecordValue(p->battleData,p);if(LIVEBATTLEMATCH_IRC_SendRegulation(p->irc,p->battleData))*state=14;break;
    case 14:{
        void *out;
        if(LIVEBATTLEMATCH_IRC_TakeRegulation(p->irc,&out)){MI_CpuCopy8(out,p->partyData,POKE_REGULATION_GetDataSize()+0xd4);*state=15;}break;
    }
    case 15:
        if(((struct BattleRecord *)(p->battleData))->cardValue==((struct BattleRecord *)(p->partyData))->cardValue){
            unsigned int a=REGULATION_Card_GetValue(p->card,12);
            int b=LIVEBATTLEMATCH_SAVE_HasOpponentMac(p->saveBlock,p->partyData->data+0x20);
            p->syncFlag=(a!=0||(a==0&&b==0));
            *state=16;
        }else{WIFIBATTLEMATCH_VIEW_SetActorVisible(p->viewObj,0);GFL_USE_StopAllSe();*state=21;}
        break;
    case 16:GFL_NET_HANDLE_SetTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),0x48,0x1f);*state=17;break;
    case 17:if(GFL_NET_HANDLE_IsTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),0x48,0x1f))*state=18;break;
    case 18:if(LIVEBATTLEMATCH_IRC_SendSyncValue(p->irc,&p->syncFlag))*state=19;break;
    case 19:if(LIVEBATTLEMATCH_IRC_RecvSyncValue(p->irc,&p->syncValue))*state=20;break;
    case 20:
        WIFIBATTLEMATCH_VIEW_SetActorVisible(p->viewObj,0);GFL_USE_StopAllSe();
        if(p->syncValue&&p->syncFlag){GFL_USE_PlaySeDefaultVolume(0x63a);*state=27;}else *state=24;break;
    case 21:if(LIVEBATTLEMATCH_IRC_ResetState(p->irc))*state=22;break;
    case 22:if(LIVEBATTLEMATCH_IRC_EndSession(p->irc))*state=23;break;
    case 23:DIGITALCARDCHECK_UpdateMenu(p,22,1);*state=40;WIFIBATTLEMATCH_UTIL_SetRequest(sys,39);break;
    case 24:if(LIVEBATTLEMATCH_IRC_ResetState(p->irc))*state=25;break;
    case 25:if(LIVEBATTLEMATCH_IRC_EndSession(p->irc))*state=26;break;
    case 26:DIGITALCARDCHECK_UpdateMenu(p,36,1);*state=40;WIFIBATTLEMATCH_UTIL_SetRequest(sys,39);break;
    case 27:DIGITALCARDCHECK_UpdateMenu(p,23,1);*state=40;WIFIBATTLEMATCH_UTIL_SetRequest(sys,28);break;
    case 28:if((p->timer)++>120){p->timer=0;BG_SYS_SetPlaneVisible(0,0);*state=29;}break;
    case 29:DIGITALCARDCHECK_CreateRecord2(p,(const WifiBattleMatchViewRecord *)p->partyData);*state=30;break;
    case 30:if(DIGITALCARDCHECK_IsRecord2Done(p))*state=31;break;
    case 31:if((p->timer)++>300){p->timer=0;*state=32;}break;
    case 32:BG_SYS_SetPlaneVisible(0,1);DIGITALCARDCHECK_UpdateMenu(p,24,1);*state=40;WIFIBATTLEMATCH_UTIL_SetRequest(sys,33);break;
    case 33:DIGITALCARDCHECK_UpdateMenu(p,35,2);*state=40;WIFIBATTLEMATCH_UTIL_SetRequest(sys,34);break;
    case 34:GFL_NET_HANDLE_SetTimingSyncRange((GFLNetHandle *)((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle()),0x47,0x1f);*state=35;break;
    case 35:if(GFL_NET_HANDLE_IsTimingSyncRange((GFLNetHandle *)((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle()),0x47,0x1f))*state=36;break;
    case 36:BG_SYS_SetPlaneVisible(0,1);DIGITALCARDCHECK_UpdateMenu(p,38,2);*state=40;WIFIBATTLEMATCH_UTIL_SetRequest(sys,37);break;
    case 37:
        if((p->timer)++>60){
            void *v=REGULATION_NoOp(p->card);
            p->timer=0;REGULATION_GetRuleValue(v,19);*state=38;
        }break;
    case 38:DIGITALCARDCHECK_End(p,2);break;
    case 39:WIFIBATTLEMATCH_UTIL_SetCallback(sys, LIVEBATTLEMATCH_FLOW_Battle);break;
    case 40:if(DIGITALCARDCHECK_GetMenuResult(p))WIFIBATTLEMATCH_UTIL_CommitRequest(sys);break;
    }
}

void LIVEBATTLEMATCH_FLOW_Card(WifibattlematchCallback *sys, int *state, void *pArg)
{
    struct LiveBattleMatchWork *p = pArg;
    if(LIVEBATTLEMATCH_IRC_CheckError(p->irc)==1){
        ((struct LiveMatchState *)(p->stateObj))->flag=1;
        WIFIBATTLEMATCH_UTIL_SetCallback(sys, LIVEBATTLEMATCH_FLOW_Battle);
    }
    switch(*state){
    case 0:{
        void *v=MET_TRAINERS_GetFromSave(GAME_DATA_GetSaveControl(p->save));
        MET_TRAINERS_Insert(v,MYSTATUS_GetId((struct MyStatus *)p->partyData));
        *state=1;break;
    }
    case 1:if(LIVEBATTLEMATCH_IRC_ResetState(p->irc)) *state=2;break;
    case 2:if(LIVEBATTLEMATCH_IRC_EndSession(p->irc)) *state=3;break;
    case 3:{
        int b;
        u8 index=(unsigned int)LIVEBATTLEMATCH_SAVE_GetCounter(p->saveBlock,0);
        u8 a=0;
        LIVEBATTLEMATCH_SAVE_SetOpponentMac(p->saveBlock,index,p->partyData->data+0x20);
        LIVEBATTLEMATCH_SAVE_SetOpponentResultByte(p->saveBlock,index,0,((struct LiveMatchState *)p->stateObj)->byte8);
        LIVEBATTLEMATCH_SAVE_SetOpponentResultByte(p->saveBlock,index,1,((struct LiveMatchState *)p->stateObj)->byte9);
        b=0;
        switch(((struct LiveMatchState *)p->stateObj)->kind){
        case 1:case 4:a=1;break;
        case 0:case 3:b=1;break;
        case 2:break;
#if LANGUAGE == LANGUAGE_JAPANESE
        default:GF_PANIC_FailPrintf(str_ja_0217E59C,0x7E9,str_ja_0217E5B8,((struct LiveMatchState *)p->stateObj)->kind);break;
#else
        default:GF_PANIC_Fail(d_0217E618,0,d_0217E618);break;
#endif
        }
        LIVEBATTLEMATCH_SAVE_AddCounter(p->saveBlock,1,a);
        LIVEBATTLEMATCH_SAVE_AddCounter(p->saveBlock,2,b);
        LIVEBATTLEMATCH_SAVE_AddCounter(p->saveBlock,0,1);
        DIGITALCARDCHECK_WaitRecord(p);
        *state=4;break;
    }
    case 4:DIGITALCARDCHECK_UpdateMenu(p,10,2);*state=8;WIFIBATTLEMATCH_UTIL_SetRequest(sys,5);break;
    case 5:GAME_DATA_SaveStart((struct GameData *)(p->save));*state=6;break;
    case 6:if(GAME_DATA_SaveMain((struct GameData *)(p->save))==2)*state=7;break;
    case 7:DIGITALCARDCHECK_End(p,3);break;
    case 8:if(DIGITALCARDCHECK_GetMenuResult(p))WIFIBATTLEMATCH_UTIL_CommitRequest(sys);break;
    }
}

/*
 * ABI: 0200AE14 leaves supplied pointer in r0 despite its void own declaration.
 */
void LIVEBATTLEMATCH_FLOW_Sub(WifibattlematchCallback *a, int *state, void *pArg)
{
    struct LiveBattleMatchWork *p = pArg;
    void *record;
    unsigned int value;
    int result;
    switch (*state) {
    case 0:
        DIGITALCARDCHECK_WaitRecord(p);
        if (REGULATION_Card_GetValue(p->card, 10) == 3) *state = 6;
        else *state = 1;
        break;
    case 1:
        record = REGULATION_NoOp(p->card);
        value = LIVEBATTLEMATCH_SAVE_GetCounter(p->saveBlock, 0);
        if (value >= REGULATION_GetRuleValue((struct Regulation *)record, 0x16)) *state = 2;
        else *state = 16;
        break;
    case 2: DIGITALCARDCHECK_UpdateMenu(p, 10, 2); *state = 17; WIFIBATTLEMATCH_UTIL_SetRequest(a, 3); break;
    case 3:
        REGULATION_Card_SetValue(p->card, 10, 3);
        BATTLE_BOX_ClearLockFlags(BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl(p->save)), 2);
        GAME_DATA_SaveStart((p->save)); *state = 4; break;
    case 4:
        switch (GAME_DATA_SaveMain(p->save)) {
        case 0: case 1: break;
        case 2: case 3: *state = 5; break;
        }
        break;
    case 5: DIGITALCARDCHECK_SetRecordMode(p, 1); DIGITALCARDCHECK_UpdateMenu(p, 25, 1); *state = 17; WIFIBATTLEMATCH_UTIL_SetRequest(a, 6); break;
    case 6: DIGITALCARDCHECK_UpdateMenu(p, 29, 1); *state = 17; WIFIBATTLEMATCH_UTIL_SetRequest(a, 7); break;
    case 7: LIVEBATTLEMATCH_FLOW_DrawMenu(p, 2); *state = 8; break;
    case 8:
        result = LIVEBATTLEMATCH_FLOW_GetWindowResult(p);
        if (result != -1) {
            LIVEBATTLEMATCH_FLOW_HideWindow(p);
            if (p->hasExtraOption && ((struct LiveMatchState *)(p->stateObj))->flag == 0) {
                switch (result) { case 0: *state = PM_LANG_JA(11, 14); break; case 1: *state = 9; break; }
            } else if (result == 0) *state = 9;
        }
        break;
    case 9: DIGITALCARDCHECK_UpdateMenu(p, 31, 1); *state = 17; WIFIBATTLEMATCH_UTIL_SetRequest(a, 10); break;
    case 10: if (DIGITALCARDCHECK_IsWorkDone(p)) { DIGITALCARDCHECK_DeleteRecord(p); *state = 15; } break;
    case 11:
#if LANGUAGE == LANGUAGE_JAPANESE
        if (((struct BattleRecord *)(p->battleData))->version >= ((struct BattleRecord *)(p->partyData))->version) *state = 12;
        else *state = 13;
#else
        if (BATTLE_REC_IsVersionSupported((u8)(((struct BattleRecord *)(p->partyData))->version))) *state = 12;
        else *state = 13;
#endif
        break;
    case 12: DIGITALCARDCHECK_UpdateMenu(p, 16, 1); *state = 17; WIFIBATTLEMATCH_UTIL_SetRequest(a, 14); break;
    case 13: DIGITALCARDCHECK_UpdateMenu(p, 34, 1); *state = 17; WIFIBATTLEMATCH_UTIL_SetRequest(a, 6); break;
    case 14: DIGITALCARDCHECK_End(p, 4); break;
    case 15: DIGITALCARDCHECK_End(p, 1); break;
    case 16: WIFIBATTLEMATCH_UTIL_SetCallback(a, LIVEBATTLEMATCH_FLOW_Battle); break;
    case 17: if (DIGITALCARDCHECK_GetMenuResult(p)) WIFIBATTLEMATCH_UTIL_CommitRequest(a); break;
    }
}

/*
 * function_starts: 0217CFD0,0217CFDC
 * ABI: coordinates are byte locals; X/width/height externs are widened because original has no call-site narrowing.
 */
void LIVEBATTLEMATCH_FLOW_DrawMenu(struct LiveBattleMatchWork *p, int mode)
{
    WifibattlematchMenuDesc rec;
    int layout;
    u8 x, y, width, height;
    MI_CpuFill8(&rec, 0, sizeof(rec));
    rec.msgBank = p->menuValue;
    rec.font = p->font;
    rec.printQue = p->printQue;
    switch (mode) {
    case 3: rec.row = 1;
    case 0:
        rec.items[0] = 6; rec.items[1] = 7; rec.count = 2; rec.enabled = 1; rec.kind = 1; layout = 1; break;
    case 1:
        rec.enabled = 0;
        if (p->hasExtraOption && ((struct LiveMatchState *)(p->stateObj))->flag == 0) {
            rec.items[0] = 13; rec.items[1] = 14; rec.items[2] = 15; rec.count = 3;
        } else { rec.items[0] = 13; rec.items[1] = 15; rec.count = 2; }
        layout = 0; break;
    case 2:
        rec.enabled = 0;
        if (p->hasExtraOption && ((struct LiveMatchState *)(p->stateObj))->flag == 0) {
            rec.items[0] = 14; rec.items[1] = 30; rec.count = 2;
        } else { rec.items[0] = 30; rec.count = 1; }
        layout = 0; break;
    }
    rec.a = 0; rec.b = 15; rec.c = 13; rec.d = 1;
    switch (layout) {
    case 0: width = 28; height = rec.count * 2; x = 2; y = 9 - height / 2; break;
    case 1: width = 12; height = rec.count * 2; x = 19; y = 17 - height; break;
    }
    p->window = WIFIBATTLEMATCH_UTIL_CreateMenu(&rec, x, y, width, height, p->heap);
    p->mode = mode;
}

void LIVEBATTLEMATCH_FLOW_HideWindow(struct LiveBattleMatchWork *p) { WIFIBATTLEMATCH_UTIL_DeleteMenu(p->window); }

int LIVEBATTLEMATCH_FLOW_GetWindowResult(struct LiveBattleMatchWork *p) { return WIFIBATTLEMATCH_UTIL_UpdateMenu(p->window); }
