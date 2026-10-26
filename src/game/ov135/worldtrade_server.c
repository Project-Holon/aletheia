/*
 * file:     worldtrade_server.c
 * unit:     yes
 * function: WORLDTRADE_SERVER_Init, WORLDTRADE_SERVER_CallStateHandler, WORLDTRADE_SERVER_Exit, WORLDTRADE_SERVER_SetupBgPlanes, WORLDTRADE_SERVER_ExitBgPlanes, WORLDTRADE_SERVER_LoadBgGraphics, WORLDTRADE_SERVER_CreateWindows, WORLDTRADE_SERVER_DeleteWindows, WORLDTRADE_SERVER_CreateStrings, WORLDTRADE_SERVER_DeleteStrings, WORLDTRADE_SERVER_StartRequest, WORLDTRADE_SERVER_SendUploadRequest, WORLDTRADE_SERVER_PollUploadResponse, WORLDTRADE_SERVER_StartNameCheck, WORLDTRADE_SERVER_WaitNameCheck, WORLDTRADE_SERVER_StartDataTransfer, WORLDTRADE_SERVER_WaitUploadResult, WORLDTRADE_SERVER_StartUploadFinish, WORLDTRADE_SERVER_WaitUploadFinish, WORLDTRADE_SERVER_StartDownload, WORLDTRADE_SERVER_WaitDownload, WORLDTRADE_SERVER_StartUploadFinishB, WORLDTRADE_SERVER_WaitUploadFinishB, WORLDTRADE_SERVER_StartTrade, WORLDTRADE_SERVER_WaitTrade, WORLDTRADE_SERVER_StartTradeFinish, WORLDTRADE_SERVER_WaitTradeFinish, WORLDTRADE_SERVER_StartReturn, WORLDTRADE_SERVER_WaitReturn, WORLDTRADE_SERVER_StateShowResultA, WORLDTRADE_SERVER_StartDownloadB, WORLDTRADE_SERVER_WaitDownloadB, WORLDTRADE_SERVER_ShowResultByMode, WORLDTRADE_SERVER_RecordTradeResult, WORLDTRADE_SERVER_StartCancel, WORLDTRADE_SERVER_WaitCancel, WORLDTRADE_SERVER_StateStartWipeOutDisconnect, WORLDTRADE_SERVER_StateFinishTrade, WORLDTRADE_SERVER_StartDelete, WORLDTRADE_SERVER_WaitDelete, WORLDTRADE_SERVER_StateIdle, WORLDTRADE_SERVER_StateSetBusyMessage, WORLDTRADE_SERVER_StateClearBusyMessage, WORLDTRADE_SERVER_StatePrintMessage9, WORLDTRADE_SERVER_StatePrintMessage10, WORLDTRADE_SERVER_StateStartUploadFinishAsync, WORLDTRADE_SERVER_StateWaitUploadFinishAsync, WORLDTRADE_SERVER_StateShowRetryMessage, WORLDTRADE_SERVER_GetErrorMessageId, WORLDTRADE_SERVER_StateShowErrorMessage, WORLDTRADE_SERVER_StateCheckAsyncEnd, WORLDTRADE_SERVER_StateShowErrorMessageB, WORLDTRADE_SERVER_StateOpenSavePrompt, WORLDTRADE_SERVER_StartSave, WORLDTRADE_SERVER_StateCountdown, WORLDTRADE_SERVER_WaitSave, WORLDTRADE_SERVER_StateSaveGame, WORLDTRADE_SERVER_StartSaveB, WORLDTRADE_SERVER_WaitSaveB, WORLDTRADE_SERVER_StateStartWipeOutRestore, WORLDTRADE_SERVER_StateWaitMessage, WORLDTRADE_SERVER_StateWaitMessageOrTouch
 * address:  0x02200C0C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from worldtrade_box.c, worldtrade_enter.c, worldtrade_adapter.c, WORLDTRADE_ADAPTER_QueueMessagePrint.c by tools/splitfile.py.
 *
 * symbols:
 *   WORLDTRADE_ADAPTER_AllocHeapBuf  0x02202608  thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   GF_PANIC_Fail 0x02034714 arm
 *   memset 0x02082BCC arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   WORLDTRADE_TITLE_ScrollBg 0x021FFFE8 thumb ov135
 *   WORLDTRADE_SUBLCD_SetSlotActorPositions 0x021FFD44 thumb ov135
 *   GXx_GetMasterBrightness_ 0x0207D55C arm
 *   WORLDTRADE_ENTER_RestartNetTimeout 0x021F9254 thumb ov135
 *   WORLDTRADE_SUBLCD_SetSlotActorPositionsLower 0x021FFD74 thumb ov135
 *   WORLDTRADE_TITLE_ExitBgPlanes 0x022000E4 thumb ov135
 *   BG_SYS_GetSubVisiblePlanes  0x02043668  arm
 *   BG_SYS_SetGraphicsMode  0x0203FC28  arm
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   BG_SYS_ClearSlot  0x020414EC  arm
 *   BG_SYS_SetPlaneVisible  0x02040588  arm
 *   BG_SYS_InitRun  0x02040B94  arm
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm
 *   ARC_UTIL_UploadPaletteFromArchiveWhole 0x02049B40 arm
 *   WORLDTRADE_TITLE_LoadMainBgSwap 0x02200AB4 thumb ov135
 *   WORLDTRADE_TITLE_LoadSubBgSwap 0x02200B34 thumb ov135
 *   WORLDTRADE_ADAPTER_DeletePrintStream 0x02202940 thumb ov135
 *   BMP_WIN_Delete 0x020452E8 arm
 *   STRBUF_Create 0x020457B0 arm
 *   WORLDTRADE_ADAPTER_IsStreamBusy  0x02202840  thumb  ov135
 *   BMP_WIN_GetBmp   0x02045770  arm
 *   BMP_Clear   0x02043B5C  arm
 *   BMP_WIN_TransferChars   0x02045334  arm
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   WORLDTRADE_NoOp  0x0200ADB4  thumb
 *   WORLDTRADE_CopyPokemon  0x0200AD9C  thumb
 *   POKE_TOOL_CopyPartyPokemon  0x02019CE0  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   WIPE_SYS_Start 0x0202208C thumb
 *   BMP_WIN_Create 0x020450F0 arm
 *   TOUCHPANEL_GetTrg  0x02035C60  arm  arm9
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm  arm9
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 *   KEY_GetTrg  0x020362DC  arm  arm9
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm  arm9
 *   WORLDTRADE_AdvanceScreenId  0x021F4EC8  thumb  ov135
 *   WORLDTRADE_SetStateAndReturn  0x021F4EC0  thumb
 *   MYSTATUS_GetProfileId 0x0200853C thumb
 *   WORLDTRADE_CancelSave  0x021F513C  thumb  ov135
 *   WORLDTRADE_DeleteTimeIcon  0x021F4FC4  thumb  ov135
 *   DPW_TR_IsAsyncEnd  0x021C866C  arm
 *   DPW_TR_GetAsyncResult  0x021C86A8  arm
 *   GFL_NET_ERR_ShowScreen 0x0200F7B8 thumb
 *   DPW_TR_End 0x021C8658 arm ov114
 *   GFL_NET_RefreshWmIconAtTopRight  0x0203D34C  arm  arm9
 *   BMP_MENUWORK_LoadCharAndPltt 0x0201F5BC thumb
 *   WORLDTRADE_SetNextState 0x021F4E98 thumb ov135
 *   GFL_NET_ERR_WaitLinkClosed  0x0200FBB0  thumb
 *   GFL_NET_ERR_ResetState  0x0200FBA0  thumb
 *   GFL_NET_STATE_SetWifiError  0x0203CA04  arm
 *   GFL_NET_STATE_ClearErrorMode  0x0203C968  arm
 *   g_02203E94  0x02203E94  data  ov135
 *   g_02203A04  0x02203A04  data  ov135
 *   g_02203A14  0x02203A14  data  ov135
 *   g_02203A54  0x02203A54  data  ov135
 *   g_02203A34  0x02203A34  data  ov135
 *   WORLDTRADE_INPUT_PrintStringPlain  0x021F90A0  thumb
 *   WORLDTRADE_CreateTimeIcon  0x021F4FA4  thumb
 *   str_02203F58  0x02203F58  data  a1
 *   NATION_AREA_SanitizeNation 0x02025C1C thumb
 *   NATION_AREA_SanitizeArea 0x02025C30 thumb
 *   POKE_TOOL_GetPartyParamSize 0x020173EC thumb
 *   NHTTP_RAP_Create 0x021B9800 thumb ov114
 *   NHTTP_RAP_AllocPostData 0x021B98A0 thumb ov114
 *   NHTTP_RAP_AppendPostData 0x021B98D8 thumb ov114
 *   NHTTP_RAP_CreatePostRequest 0x021B98F8 thumb ov114
 *   NHTTP_RAP_StartConnection 0x021B9748 thumb ov114
 *   NHTTP_RAP_GetResultCode  0x021B99DC  thumb  ov114
 *   NHTTP_RAP_PollConnection  0x021B9790  thumb  ov114
 *   NHTTP_RAP_GetRecvBuffer  0x021B97F4  thumb  ov114
 *   NHTTP_RAP_DeleteConnection  0x021B9774  thumb  ov114
 *   NHTTP_RAP_FreePostData  0x021B99B8  thumb  ov114
 *   NHTTP_RAP_Destroy  0x021B9838  thumb  ov114
 *   NHTTP_RAP_RecordList_GetCount  0x021B99F0  thumb  ov114
 *   NHTTP_RAP_RecordList_GetValue  0x021B99F4  thumb  ov114
 *   NHTTP_RAP_RecordList_GetRecord  0x021B9A14  thumb  ov114
 *   GFL_NET_ERR_RaiseFatal  0x0200FB4C  thumb
 *   MI_CpuCopy8  0x02082D44  arm
 *   STRBUF_SetStringN 0x02045994 arm
 *   STRBUF_GetChars 0x02045A90 arm
 *   STRBUF_GetLength 0x020458F8 arm
 *   STRBUF_GetEosChar 0x02045A98 arm
 *   DWC_CheckProfanityExAsync 0x0217BC44 arm ov009
 *   DWC_CheckProfanityProcess 0x0217BC90 arm ov009
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   RECORD_AddOne  0x02008DF0  thumb
 *   WORLDTRADE_GetReturnBox  0x0200ADE0  thumb
 *   DPW_TR_TradeAsync 0x021C8C68 arm ov114
 *   WORLDTRADE_GetIsDeposited  0x0200AD8C  thumb
 *   WORDSET_SetSlotMonNickname  0x0201EEF4  thumb
 *   WORLDTRADE_SetIsDeposited  0x0200AD94  thumb
 *   MET_TRAINERS_GetFromSave 0x0200ED48 thumb
 *   MET_TRAINERS_Insert 0x0200ED54 thumb
 *   WORLDTRADE_DEMO_CreateMyStatusFromEntry 0x021F72C4 thumb ov135
 *   TRADE_HISTORY_GetFromSave 0x02009EC8 thumb
 *   TRADE_HISTORY_AddPartner 0x02009DE8 thumb
 *   memset 0x02082BCC arm
 *   MYSTATUS_Copy 0x02008494 thumb
 *   COMM_HISTORY_InsertIfNationSet 0x0202EB7C thumb
 *   DPW_TR_CancelAsync  0x021C89F0  arm  ov114
 *   WORLDTRADE_INPUT_PrintStringTop  0x021F9088  thumb  ov135
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 *   GAME_DATA_SaveStart  0x02012DAC  thumb  arm9
 *   DPW_TR_GetUploadResultAsync  0x021C8770  arm  ov114
 *   DPW_TR_DownloadAsync  0x021C87FC  arm  ov114
 *   DPW_TR_ReturnAsync  0x021C887C  arm  ov114
 *   DPW_TR_DeleteAsync  0x021C88FC  arm  ov114
 *   DPW_TR_UploadFinishAsync  0x021C8978  arm  ov114
 *   DPW_TR_TradeFinishAsync  0x021C8D14  arm  ov114
 *   WORLDTRADE_SUBLCD_UpdateSlotAnims 0x021FFBC8 thumb ov135
 *   WORLDTRADE_ADAPTER_RemovePartyMon 0x022021F8 thumb ov135
 *   WORLDTRADE_ADAPTER_RegisterReceivedMon 0x022022B8 thumb ov135
 *   WORLDTRADE_ADAPTER_RegisterReceivedMonB 0x022023A4 thumb ov135
 *   WORLDTRADE_ADAPTER_RegisterLanguageVersion 0x022024B0 thumb ov135
 *   WORLDTRADE_ADAPTER_CheckPartyHasOther 0x022024DC thumb ov135
 *   WORLDTRADE_ADAPTER_SetPair 0x0220251C thumb ov135
 *   WORLDTRADE_ADAPTER_CanProceed 0x0220252C thumb ov135
 *   WORLDTRADE_ADAPTER_CreateMail 0x0220254C thumb ov135
 *   GFL_USE_GetRandom  0x020056EC  thumb  arm9
 */
#include "../version.h"
#include "../sdk_ioreg.h"
#include "worldtrade_types.h"

#include "../arm9/mi_memory.h"

#include "../arm9/msgdata.h"

#include "../arm9/gfl_heap_wrap.h"

#include "../arm9/gf_panic.h"
struct Strbuf;


#include "../arm9/strbuf.h"
struct BmpWin;

#include "../arm9/bmp_win.h"


#include "../arm9/bg_sys.h"

struct WorldtradeCtx;
struct GameSystem;
struct GameData;
#include "../arm9/gamesystem.h"

#include "worldtrade_input.h"
#include "worldtrade_demo.h"






#include "../arm9/arc_util.h"

#include "../arm9/bmp_menuwork.h"

struct Bmp;


typedef short s16_p07;
#include "../arm9/bmp.h"




#include "../arm9/key.h"

#include "../arm9/touchpanel.h"
struct WorldTradeData;



#include "../arm9/poke_tool.h"

#include "worldtrade.h"
#include "../arm9/worldtrade.h"
struct MyStatus;

#include "../arm9/mystatus.h"

#include "../ov114/dpw_tr.h"



#include "../arm9/net_err.h"

#include "../arm9/net.h"


struct Sub02008C20Obj;

struct L0200ED54;

struct Sub02009D9CObj;

typedef struct {
    u8 raw[0x20];
    u16 old_species;
    u16 new_species;
    u8 x;
    u8 y;
    u8 flags;
    u8 tail;
} WorldtradeServerRecord;


#include "../arm9/wipe.h"







#include "../arm9/gfl_use.h"
struct PokemonParam;






#include "../arm9/gx.h"





#include "../arm9/net_state.h"




struct PartyPokemon;


#include "../arm9/bmp_oam.h"

struct _NHTTPRapSession;

#include "../ov114/nhttp_rap.h"










struct _NHTTPRapRecordList;


struct _NHTTPRapRecord;








#include "../ov009/dwc_prof.h"




#include "../arm9/record.h"









#include "../arm9/wordset.h"


#include "../arm9/met_trainers_savedata.h"
struct MetTrainersSave;


struct SaveControl;
struct TradeHistory;

#include "../arm9/trade_history.h"


extern void *memset(void *, int, u32);

struct HistoryEntry;
struct HistoryOwner;

#include "../arm9/comm_history.h"




#include "../arm9/game_data.h"



#include "worldtrade_sublcd.h"



#include "worldtrade_title.h"




int WORLDTRADE_SERVER_Init(WorldtradeWork *p);

int WORLDTRADE_SERVER_CallStateHandler(u8 *p);

int WORLDTRADE_SERVER_Exit(WorldtradeWork *p);

void WORLDTRADE_SERVER_SetupBgPlanes(void);

void WORLDTRADE_SERVER_ExitBgPlanes(void);

void WORLDTRADE_SERVER_LoadBgGraphics(WorldtradeWork *p);

void WORLDTRADE_SERVER_CreateWindows(WorldtradeWork *p);

void WORLDTRADE_SERVER_DeleteWindows(WorldtradeWork *p);

void WORLDTRADE_SERVER_CreateStrings(WorldtradeWork *p);

void WORLDTRADE_SERVER_DeleteStrings(WorldtradeWork *p);

int WORLDTRADE_SERVER_StartRequest(WorldtradeWork *p);

int WORLDTRADE_SERVER_SendUploadRequest(WorldtradeWork *p);

int WORLDTRADE_SERVER_PollUploadResponse(WorldtradeWork *p);

int WORLDTRADE_SERVER_StartNameCheck(u8 *p);

int WORLDTRADE_SERVER_WaitNameCheck(u8 *p);

int WORLDTRADE_SERVER_StartDataTransfer(WorldtradeWork *p);

int WORLDTRADE_SERVER_WaitUploadResult(WorldtradeWork *p);

int WORLDTRADE_SERVER_StartUploadFinish(WorldtradeWork *p);

int WORLDTRADE_SERVER_WaitUploadFinish(WorldtradeWork *p);

int WORLDTRADE_SERVER_StartDownload(WorldtradeWork *p);

int WORLDTRADE_SERVER_WaitDownload(WorldtradeWork *p);

int WORLDTRADE_SERVER_StartUploadFinishB(WorldtradeWork *p);

int WORLDTRADE_SERVER_WaitUploadFinishB(WorldtradeWork *p);

int WORLDTRADE_SERVER_StartTrade(WorldtradeWork *p);

int WORLDTRADE_SERVER_WaitTrade(WorldtradeWork *p);

int WORLDTRADE_SERVER_StartTradeFinish(WorldtradeWork *p);

int WORLDTRADE_SERVER_WaitTradeFinish(WorldtradeWork *p);

int WORLDTRADE_SERVER_StartReturn(WorldtradeWork *p);

int WORLDTRADE_SERVER_WaitReturn(WorldtradeWork *p);

int WORLDTRADE_SERVER_StateShowResultA(WorldtradeWork *p);

int WORLDTRADE_SERVER_StartDownloadB(WorldtradeWork *p);

int WORLDTRADE_SERVER_WaitDownloadB(WorldtradeWork *p);

void WORLDTRADE_SERVER_ShowResultByMode(WorldtradeWork *p);

void WORLDTRADE_SERVER_RecordTradeResult(WorldtradeWork *p, void *mon, WorldtradeEntry *r, void *old);

int WORLDTRADE_SERVER_StartCancel(WorldtradeWork *p);

int WORLDTRADE_SERVER_WaitCancel(WorldtradeWork *p);

int WORLDTRADE_SERVER_StateStartWipeOutDisconnect(WorldtradeWork *p);

int WORLDTRADE_SERVER_StateFinishTrade(WorldtradeWork *p);

int WORLDTRADE_SERVER_StartDelete(WorldtradeWork *p);

int WORLDTRADE_SERVER_WaitDelete(WorldtradeWork *p);

int WORLDTRADE_SERVER_StateIdle(void);

int WORLDTRADE_SERVER_StateSetBusyMessage(WorldtradeWork *p);

int WORLDTRADE_SERVER_StateClearBusyMessage(WorldtradeWork *p);

int WORLDTRADE_SERVER_StatePrintMessage9(WorldtradeWork *p);

int WORLDTRADE_SERVER_StatePrintMessage10(WorldtradeWork *p);

int WORLDTRADE_SERVER_StateStartUploadFinishAsync(WorldtradeWork *p);

int WORLDTRADE_SERVER_StateWaitUploadFinishAsync(WorldtradeWork *p);

int WORLDTRADE_SERVER_StateShowRetryMessage(WorldtradeWork *p);

void WORLDTRADE_SERVER_GetErrorMessageId(WorldtradeWork *p);

int WORLDTRADE_SERVER_StateShowErrorMessage(WorldtradeWork *p);

int WORLDTRADE_SERVER_StateCheckAsyncEnd(WorldtradeWork *p);

int WORLDTRADE_SERVER_StateShowErrorMessageB(WorldtradeWork *p);

int WORLDTRADE_SERVER_StateOpenSavePrompt(WorldtradeWork *p);

int WORLDTRADE_SERVER_StartSave(WorldtradeWork *p);

int WORLDTRADE_SERVER_StateCountdown(WorldtradeWork *p);

int WORLDTRADE_SERVER_WaitSave(WorldtradeWork *p);

int WORLDTRADE_SERVER_StateSaveGame(WorldtradeWork *p);

int WORLDTRADE_SERVER_StartSaveB(WorldtradeWork *p);

int WORLDTRADE_SERVER_WaitSaveB(WorldtradeWork *p);

int WORLDTRADE_SERVER_StateStartWipeOutRestore(WorldtradeWork *p);

int WORLDTRADE_SERVER_StateWaitMessage(WorldtradeWork *p);

int WORLDTRADE_SERVER_StateWaitMessageOrTouch(WorldtradeWork *p);

#include "worldtrade_adapter.h"











extern int (*g_02203E94[])(u8 *);

extern struct DispConfig g_02203A04;

extern struct BgTemplate g_02203A14;

extern struct BgTemplate g_02203A54;

extern struct BgTemplate g_02203A34;

extern const char str_02203F58[];

int WORLDTRADE_SERVER_Init(WorldtradeWork *p) { WORLDTRADE_SERVER_CreateStrings(p); WORLDTRADE_SERVER_SetupBgPlanes(); WORLDTRADE_TITLE_ScrollBg(p,0,0); if((p->kind)==11) { BG_SYS_SetPlaneVisible(4,0); BG_SYS_SetPlaneVisible(6,0); } WORLDTRADE_SERVER_LoadBgGraphics(p); WORLDTRADE_SERVER_CreateWindows(p); WORLDTRADE_SUBLCD_SetSlotActorPositions(p); WIPE_SYS_Start((void *)3,1,1,0,6,1,72); WORLDTRADE_ENTER_RestartNetTimeout((u8 *)p); p->state=0; p->keepBgLayers=0; return 1; }

/*
 * WorldtradeState-table dispatch through the table at 0x02203E94.
 */
int WORLDTRADE_SERVER_CallStateHandler(u8 *p)
{
    return g_02203E94[((struct WorldtradeWork *)p)->state](p);
}

int WORLDTRADE_SERVER_Exit(WorldtradeWork *p) { if(GXx_GetMasterBrightness_((u16 *)REG_DB_MASTER_BRIGHT_ADDR)) WORLDTRADE_SUBLCD_SetSlotActorPositionsLower(p); WORLDTRADE_SERVER_DeleteStrings(p); WORLDTRADE_SERVER_DeleteWindows(p); WORLDTRADE_SERVER_ExitBgPlanes(); WORLDTRADE_TITLE_ExitBgPlanes(p); WORLDTRADE_AdvanceScreenId(p); return 0; }

/*
 * Three-layer bring-up with all three layers 020414EC'd, tilemap clears for
 * layers 0 and 1 and plane 0x10 toggled.
 */
void WORLDTRADE_SERVER_SetupBgPlanes(void)
{
    struct DispConfig c = g_02203A04;
    u32 v = BG_SYS_GetSubVisiblePlanes();

    BG_SYS_SetGraphicsMode(&c);
    BG_SYS_SetSubVisiblePlanes(v);
    {
        struct BgTemplate t = g_02203A14;
        BG_SYS_InitBgLayer(0, &t, 0);
    }
    BG_SYS_ClearSlot(0);
    BG_SYS_SetPlaneVisible(0, 1);
    {
        struct BgTemplate t = g_02203A54;
        BG_SYS_InitBgLayer(1, &t, 0);
    }
    BG_SYS_ClearSlot(1);
    BG_SYS_SetPlaneVisible(1, 1);
    {
        struct BgTemplate t = g_02203A34;
        BG_SYS_InitBgLayer(2, &t, 0);
    }
    BG_SYS_ClearSlot(2);
    BG_SYS_SetPlaneVisible(2, 1);
    BG_SYS_InitRun(0, 0x20, 0, 0x48);
    BG_SYS_InitRun(1, 0x20, 0, 0x48);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
}

void WORLDTRADE_SERVER_ExitBgPlanes(void)
{
    BG_SYS_FreeLayerBuf(2);
    BG_SYS_FreeLayerBuf(1);
    BG_SYS_FreeLayerBuf(0);
}

void WORLDTRADE_SERVER_LoadBgGraphics(WorldtradeWork *p)
{
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 0, 0x1a0, 0x20, 0x48);
    BMP_MENUWORK_LoadCharAndPltt(0, 1, 0xe, 0, 0x48);
    BMP_MENUWORK_LoadCharAndPltt(0, 0x1f, 0xb, 0, 0x48);
    if (p->active == 0) {
        BG_SYS_SetPlaneVisible(4, 0);
        BG_SYS_SetPlaneVisible(5, 0);
        BG_SYS_SetSubPlaneVisible(0x10, 0);
    }
    if (p->prevScreenId == 9) {
        WORLDTRADE_TITLE_LoadMainBgSwap(p);
        WORLDTRADE_TITLE_LoadSubBgSwap(p);
    }
}

/*
 * tail: 02200E92..02200E94 two zero alignment bytes.
 */
void WORLDTRADE_SERVER_CreateWindows(WorldtradeWork *p)
{
    struct BmpWin *w;
    p->frame = BMP_WIN_Create((unsigned int)0, (unsigned int)2, (unsigned int)0x13, 0x1b, 4, 0xd, 1);
    BMP_Clear((struct Bmp *)(BMP_WIN_GetBmp((struct BmpWin *)p->frame)), 0);
    w = p->frame;
    BMP_WIN_TransferChars((struct BmpWin *)w);
    BMP_WIN_MakeScreen((struct BmpWin *)w);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct BmpWin *)w));
}

/*
 * Tear down the +0xfa0 sub-object, then release the +0xd40 resource.
 */
void WORLDTRADE_SERVER_DeleteWindows(WorldtradeWork *p)
{
    WORLDTRADE_ADAPTER_DeletePrintStream((struct WorldtradeObj *)((u8 *)&((struct WorldtradeWork *)p)->printer));
    BMP_WIN_Delete((struct BmpWin *)p->d40);
}

/*
 * Claim the 0xb4/0x48 resource and park it at +0xb88.
 */
void WORLDTRADE_SERVER_CreateStrings(WorldtradeWork *p)
{
    (*(unsigned int *)&p->str) = (uptr)STRBUF_Create(0xb4, 0x48);
}

/*
 * Tail call into STRBUF_Delete with the pointer held at +0xb88.
 */
void WORLDTRADE_SERVER_DeleteStrings(WorldtradeWork *p)
{
    STRBUF_Delete((struct Strbuf *)((p->str)));
}

int WORLDTRADE_SERVER_StartRequest(WorldtradeWork *p)
{
    switch (p->kind) {
    case 7:
        WORLDTRADE_INPUT_PrintStringPlain(p, p->bank, 0x18, 1, 0xF0F);
        WORLDTRADE_SetNextState(p, 0x29, 2);
        p->done = 0;
        p->next = 6;
        break;
    case 8:
        WORLDTRADE_INPUT_PrintStringPlain(p, p->bank, 0x18, 1, 0xF0F);
        WORLDTRADE_SetNextState(p, 0x29, 0xB);
        break;
    case 9:
        WORLDTRADE_INPUT_PrintStringPlain(p, p->bank, 0x18, 1, 0xF0F);
        WORLDTRADE_SetNextState(p, 0x29, 2);
        p->done = 0;
        p->next = 0x10;
        break;
    case 10:
        WORLDTRADE_INPUT_PrintStringPlain(p, p->bank, 0x18, 1, 0xF0F);
        WORLDTRADE_SetNextState(p, 0x29, 0x16);
        p->eb4 = 1;
        break;
    case 11:
        WORLDTRADE_INPUT_PrintStringPlain(p, p->bank, 0x18, 1, 0xF0F);
        WORLDTRADE_SetNextState(p, 0x29, 0x1C);
        break;
    case 12:
        WORLDTRADE_INPUT_PrintStringPlain(p, p->bank, 0x9A, 1, 0xF0F);
        p->state = 0x21;
        p->nextScreenId = 1;
        GFL_NET_RefreshWmIconAtTopRight(1, 0x48);
        break;
    default:
        GF_PANIC_Fail(str_02203F58, 0, str_02203F58);
        break;
    }
    WORLDTRADE_CreateTimeIcon(p);
    return 2;
}

int WORLDTRADE_SERVER_SendUploadRequest(WorldtradeWork *p)
{
    u8 *mon=(u8 *)&((struct WorldtradeWork *)p)->ent;
    int ready;
    POKE_TOOL_CopyPartyPokemon((struct PartyPokemon *)mon, (struct PartyPokemon *)(*(struct RecDC * *)&p->tradeMon));
    ((u8 *)p)[0x204]=NATION_AREA_SanitizeNation(((u8 *)p)[0x204],((u8 *)p)[0x205],((u8 *)p)[0x209]);
    ((u8 *)p)[0x205]=NATION_AREA_SanitizeArea(((u8 *)p)[0x204],((u8 *)p)[0x205],((u8 *)p)[0x209]);
    *(u8 * *)&p->wm=(unsigned char *)NHTTP_RAP_Create(0x48,MYSTATUS_GetProfileId(p->ctx->myStatus),(char *)(((u8 *)&((struct WorldtradeWork *)p)->netBuf)));
    NHTTP_RAP_AllocPostData((struct _NHTTPRapSession *)(*(u8 * *)&p->wm),0x48,POKE_TOOL_GetPartyParamSize(),1);
    NHTTP_RAP_AppendPostData((struct _NHTTPRapSession *)(*(u8 * *)&p->wm),mon,POKE_TOOL_GetPartyParamSize());
    if(NHTTP_RAP_CreatePostRequest((struct _NHTTPRapSession *)(*(u8 * *)&p->wm))==0) GF_PANIC_Fail(str_02203F58,0,str_02203F58);
    ready=NHTTP_RAP_StartConnection((struct _NHTTPRapSession *)(((struct WorldtradeWork *)p)->wm))==0;
    if(ready==0) GF_PANIC_Fail(str_02203F58,0,str_02203F58);
    p->state=3;
    return 2;
}

/*
 * relocation stays wildcarded (requested in docs/sessions/2026-09-27/arm9_requests.md).
 * The four ov114 targets 0x021B97F4, 0x021B99F0, 0x021B99F4, 0x021B9A14 were seeded
 * by tree_ov135_4. Every other byte is identical. Labelling 0x0200FB4C makes this EXACT.
 */
int WORLDTRADE_SERVER_PollUploadResponse(WorldtradeWork *p)
{
    int st;
    int r;
    void *rec;

    st = NHTTP_RAP_GetResultCode(p->wm);
    r = NHTTP_RAP_PollConnection(p->wm);
    if (r == 0) {
        rec = NHTTP_RAP_GetRecvBuffer(p->wm);
        switch (st) {
        case 400:
            GFL_NET_ERR_RaiseFatal(0x41);
            GFL_NET_ERR_ShowScreen(0);
            NHTTP_RAP_DeleteConnection(p->wm);
            NHTTP_RAP_FreePostData(p->wm);
            NHTTP_RAP_Destroy(p->wm);
            p->state_i = 0x2C;
            return 2;
        case 401:
            GFL_NET_ERR_RaiseFatal(0x42);
            GFL_NET_ERR_ShowScreen(0);
            NHTTP_RAP_DeleteConnection(p->wm);
            NHTTP_RAP_FreePostData(p->wm);
            NHTTP_RAP_Destroy(p->wm);
            p->state_i = 0x2C;
            return 2;
        case 408:
            GFL_NET_ERR_RaiseFatal(0x44);
            GFL_NET_ERR_ShowScreen(0);
            NHTTP_RAP_DeleteConnection(p->wm);
            NHTTP_RAP_FreePostData(p->wm);
            NHTTP_RAP_Destroy(p->wm);
            p->state_i = 0x2C;
            return 2;
        default:
            GFL_NET_ERR_RaiseFatal(0x43);
            GFL_NET_ERR_ShowScreen(0);
            NHTTP_RAP_DeleteConnection(p->wm);
            NHTTP_RAP_FreePostData(p->wm);
            NHTTP_RAP_Destroy(p->wm);
            p->state_i = 0x2C;
            return 2;
        case 200:
            p->valid = NHTTP_RAP_RecordList_GetCount(rec);
            p->count_u = NHTTP_RAP_RecordList_GetValue(rec, 0);
            MI_CpuCopy8(NHTTP_RAP_RecordList_GetRecord(rec, 1), p->buf_b128, 0x80);
            NHTTP_RAP_FreePostData(p->wm);
            NHTTP_RAP_Destroy(p->wm);
            if (p->valid == 0) {
                if (p->count_u == 0) {
                    p->state_i = 4;
                } else if (p->done == 0) {
                    p->done++;
                    p->state_i = 2;
                    WORLDTRADE_ADAPTER_CreateMail(p->ent, 0x48);
                } else {
                    p->err = -7;
                    p->state_i = 0x2D;
                }
            } else if (p->done == 0) {
                p->done++;
                p->state_i = 2;
                WORLDTRADE_ADAPTER_CreateMail(p->ent, 0x48);
            } else {
                p->err = -7;
                p->state_i = 0x2D;
            }
            break;
        }
    } else if (r != 0xF) {
        p->err = -15;
        p->state_i = 0x2B;
        NHTTP_RAP_FreePostData(p->wm);
        NHTTP_RAP_Destroy(p->wm);
        GFL_NET_ERR_WaitLinkClosed();
        GFL_NET_STATE_SetWifiError();
        GFL_NET_ERR_ResetState();
        GFL_NET_STATE_ClearErrorMode();
    }
    return 2;
}

#ifdef __MWERKS__
int WORLDTRADE_SERVER_StartNameCheck(u8 *p)
{
    struct U16Vec *s;
    u16 *text;
    u32 i;
    u16 c;
    s=(struct U16Vec *)STRBUF_Create(8,0x48);
    STRBUF_SetStringN((struct Strbuf *)s,(u16 *)((WorldtradeWork *)p)->ent[0].name,8);
    MI_CpuFill8(((WorldtradeWork *)p)->nameBuf,0,sizeof(((WorldtradeWork *)p)->nameBuf));
    ((WorldtradeWork *)p)->reserved1324=0x48;
    text=STRBUF_GetChars((struct Strbuf *)s);
    for(i=0;i<STRBUF_GetLength((struct Strbuf *)s)+1;i++) {
        c=*(u16 *)((uptr)text+i*2);
        if(c==STRBUF_GetEosChar()) *(u16 *)(p+i*2+0x1300)=0;
        else *(u16 *)(p+i*2+0x1300)=c;
    }
    ((WorldtradeWork *)p)->profanityWords=(u16 *)(p+0x1300);
    ((WorldtradeWork *)p)->badWordCountU=0;
    DWC_CheckProfanityExAsync((short unsigned int **)((u8 *)&((struct WorldtradeWork *)p)->profanityWords),1,0,0,(char *)((WorldtradeWork *)p)->pad131C,(int *)((u8 *)&((struct WorldtradeWork *)p)->badWordCountU),0x80);
    STRBUF_Delete((struct Strbuf *)s);
    ((WorldtradeWork *)p)->state=5;
    ((WorldtradeWork *)p)->timer=0;
    return 2;
}
#else
int WORLDTRADE_SERVER_StartNameCheck(u8 *p)
{
    struct U16Vec *s;
    u16 *text;
    u32 i;
    u16 c;
    s=(struct U16Vec *)STRBUF_Create(8,0x48);
    STRBUF_SetStringN((struct Strbuf *)s,(u16 *)((WorldtradeWork *)p)->ent[0].name,8);
    MI_CpuFill8(((WorldtradeWork *)p)->nameBuf,0,sizeof(((WorldtradeWork *)p)->nameBuf));
    ((WorldtradeWork *)p)->reserved1324=0x48;
    text=STRBUF_GetChars((struct Strbuf *)s);
    for(i=0;i<STRBUF_GetLength((struct Strbuf *)s)+1;i++) {
        c=*(u16 *)((uptr)text+i*2);
        if(c==STRBUF_GetEosChar()) ((WorldtradeWork *)p)->nameBuf[i]=0;
        else ((WorldtradeWork *)p)->nameBuf[i]=c;
    }
    ((WorldtradeWork *)p)->profanityWords=((WorldtradeWork *)p)->nameBuf;
    ((WorldtradeWork *)p)->badWordCountU=0;
    DWC_CheckProfanityExAsync((short unsigned int **)((u8 *)&((struct WorldtradeWork *)p)->profanityWords),1,0,0,(char *)((WorldtradeWork *)p)->pad131C,(int *)((u8 *)&((struct WorldtradeWork *)p)->badWordCountU),0x80);
    STRBUF_Delete((struct Strbuf *)s);
    ((WorldtradeWork *)p)->state=5;
    ((WorldtradeWork *)p)->timer=0;
    return 2;
}
#endif

int WORLDTRADE_SERVER_WaitNameCheck(u8 *p)
{
    int done;
    int positive;
    u16 *dst;
    void *bank;
    void *str;
    u16 *text;
    int i;
    done = DWC_CheckProfanityProcess() == 2;
    if (done) positive = ((WorldtradeWork *)p)->nameCheckResult > 0;
    if (done) {
        if (positive) {
            dst = (u16 *)((WorldtradeWork *)p)->ent[0].name;
            bank = MSGDATA_CreateFromArchive(0, 2, 0x51, 0x48);
            str = MSGDATA_AllocString(bank, MSG_PROFANITY_NOTICE);
            MSGDATA_Delete(bank);
            text = STRBUF_GetChars(str);
            for (i = 0; i < 7 && (u32)i < STRBUF_GetLength(str); i++) dst[i] = text[i];
            dst[i] = STRBUF_GetEosChar();
            STRBUF_Delete(str);
        }
        ((WorldtradeWork *)p)->state = ((WorldtradeWork *)p)->next;
    } else {
        if ((((WorldtradeWork *)p)->timer)++ == 0xe10) {
            ((WorldtradeWork *)p)->err = -5;
            ((WorldtradeWork *)p)->state = 0x2b;
            GFL_NET_ERR_WaitLinkClosed();
            GFL_NET_STATE_SetWifiError();
            GFL_NET_ERR_ResetState();
            GFL_NET_STATE_ClearErrorMode();
        }
    }
    return 2;
}

/*
 * Move 0x80 bytes between the +0xe4 and +0x10ec sub-objects, latch state 7 and publish the 8/0xa pair.
 */
int WORLDTRADE_SERVER_StartDataTransfer(WorldtradeWork *p)
{
    DPW_TR_UploadAsync((u8 *)&((struct WorldtradeWork *)p)->ent, (u8 *)&((struct WorldtradeWork *)p)->buf_b128, 0x80);
    p->state = 7;
    p->wait = 0;
    WORLDTRADE_ADAPTER_SetPair((WorldtradeWork *)p, 8, 0xa);
    return 2;
}

/*
 * Switch on the 0x021C86A8 index (case value = index + 15): state
 * 0x22 with the 0x022021F8/0x02008DF0 pair, state 0x2b with the four
 * middleware calls, state 0x2d alone, or a plain WORLDTRADE_CancelSave redraw.
 * The shape is settled and every concrete byte is reproduced; the site is
 * parked because TWO of its callees have no witness anywhere in the tree.
 * Both BLX sites resolve as "(arm, from name) has no witness outside
 * 02201414..02201480; 8 overlays overlap this address (ov016, ov021, ov093,
 * ov111, ov114, ov128, ov172, ov208), none resolvable without a region hint
 * on the symbols: line".  A region hint cannot help: match.py's `label`
 * class needs EXACTLY ONE overlay listing to carry a func_ label at the
 * address, and 0x021C866C / 0x021C86A8 carry none in any overlay.  The
 * neighbours 0x021C8770/0x021C87FC/0x021C887C/0x021C8978 DO carry labels --
 * they are in asm/overlays/ov114.s -- so the fix is to trace those two
 * entries (layout/function_starts.txt is not this lane's file).
 *
 * UNBLOCKED: DPW_TR_IsAsyncEnd(0x021C866C) and DPW_TR_GetAsyncResult
 * (0x021C86A8) are now EXACT entries in layout/matched/ov114
 * (pkt_ov114_021C866C, pkt_ov114_021C86A8); both BLX sites
 * resolve as `matched`.  Verdict promoted to EXACT.
 */
int WORLDTRADE_SERVER_WaitUploadResult(WorldtradeWork *p)
{
    s32 n;

    if (DPW_TR_IsAsyncEnd() != 0) {
        n = DPW_TR_GetAsyncResult();
        p->timer = 0;
        switch (n + 15) {
        case 15:
            WORLDTRADE_ADAPTER_RemovePartyMon((WorldtradeWork *)p, 1);
            RECORD_AddOne((struct RecordBlock *)p->ctx->record, 0x1c);
            p->state = 0x22;
            break;
        case 14:
            (p->err) = n;
            p->state = 0x2b;
            GFL_NET_ERR_WaitLinkClosed();
            GFL_NET_STATE_SetWifiError();
            GFL_NET_ERR_ResetState();
            GFL_NET_STATE_ClearErrorMode();
            break;
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
            (p->err) = n;
            p->state = 0x2d;
            break;
        case 3:
        case 11:
            (p->err) = n;
            p->state = 0x2d;
            break;
        case 0:
        case 1:
        case 13:
            (p->err) = n;
            p->state = 0x2b;
            GFL_NET_ERR_WaitLinkClosed();
            GFL_NET_STATE_SetWifiError();
            GFL_NET_ERR_ResetState();
            GFL_NET_STATE_ClearErrorMode();
            break;
        case 2:
            WORLDTRADE_CancelSave(p);
            break;
        }
    } else {
        if (++p->timer == 0xe10) {
            WORLDTRADE_CancelSave(p);
        }
    }
    return 2;
}

/*
 * WorldtradeState 9 with the slot cleared and the u16 at +0x32 set.
 */
int WORLDTRADE_SERVER_StartUploadFinish(WorldtradeWork *p)
{
    DPW_TR_GetUploadResultAsync();
    p->state = 9;
    p->timer = 0;
    p->busy = 1;
    return 2;
}

/*
 * Switch on the 0x021C86A8 index (case value = index + 15): state 0x25
 * with the u16 at +0x36 cleared, state 0x2d with the index archived at
 * +0x38, or a plain WORLDTRADE_CancelSave redraw.
 * The shape is settled and every concrete byte is reproduced; the site is
 * parked because TWO of its callees have no witness anywhere in the tree.
 * Both BLX sites resolve as "(arm, from name) has no witness outside
 * 02201414..02201480; 8 overlays overlap this address (ov016, ov021, ov093,
 * ov111, ov114, ov128, ov172, ov208), none resolvable without a region hint
 * on the symbols: line".  A region hint cannot help: match.py's `label`
 * class needs EXACTLY ONE overlay listing to carry a func_ label at the
 * address, and 0x021C866C / 0x021C86A8 carry none in any overlay.  The
 * neighbours 0x021C8770/0x021C87FC/0x021C887C/0x021C8978 DO carry labels --
 * they are in asm/overlays/ov114.s -- so the fix is to trace those two
 * entries (layout/function_starts.txt is not this lane's file).
 *
 * UNBLOCKED: DPW_TR_IsAsyncEnd(0x021C866C) and DPW_TR_GetAsyncResult
 * (0x021C86A8) are now EXACT entries in layout/matched/ov114
 * (pkt_ov114_021C866C, pkt_ov114_021C86A8); both BLX sites
 * resolve as `matched`.  Verdict promoted to EXACT.
 */
int WORLDTRADE_SERVER_WaitUploadFinish(WorldtradeWork *p)
{
    s32 n;

    if (DPW_TR_IsAsyncEnd() != 0) {
        n = DPW_TR_GetAsyncResult();
        p->timer = 0;
        switch (n + 15) {
        case 15:
            p->cooldownFrames = 0;
            p->state = 0x25;
            break;
        case 3:
        case 11:
            (p->err) = n;
            p->state = 0x2d;
            break;
        case 0:
        case 1:
        case 10:
        case 12:
        case 13:
        case 14:
            WORLDTRADE_CancelSave(p);
            break;
        case 2:
            WORLDTRADE_CancelSave(p);
            break;
        }
    } else {
        if (++p->timer == 0xe10) {
            WORLDTRADE_CancelSave(p);
        }
    }
    return 2;
}

/*
 * WorldtradeState 0xc, slot cleared, then publish the 0xd/0xf pair.
 */
int WORLDTRADE_SERVER_StartDownload(WorldtradeWork *p)
{
    DPW_TR_DownloadAsync((u8 *)&((struct WorldtradeWork *)p)->ent);
    p->state = 0xc;
    p->timer = 0;
    WORLDTRADE_ADAPTER_SetPair(p, 0xd, 0xf);
    return 2;
}

/*
 * Switch on the 0x021C86A8 index (case value = index + 15): state 0x22
 * (with the two 0x0200ADxx queries and a 0x022022B8 call, or 0x1c when the
 * s8 flag at +0x207 is set), then the 0x2b pair (index 12 with the +0x38
 * archive, index 11 without), 0x2d, the +0x38/0x2b group and the plain
 * redraw; indexes 4..10 and 14 are table holes.
 * The shape is settled and every concrete byte is reproduced; the site is
 * parked because 0x021C866C / 0x021C86A8 carry no func_ label in any
 * overlay listing (see the wave-5 residue note for the one-line fix).
 */
int WORLDTRADE_SERVER_WaitDownload(WorldtradeWork *p)
{
    s32 n;
    s32 v;

    if (DPW_TR_IsAsyncEnd() != 0) {
        n = DPW_TR_GetAsyncResult();
        p->timer = 0;
        switch (n + 15) {
        case 15:
            v = p->receivedEgg;
            if (v != 0) {
                p->state = 0x1c;
            } else {
                WORLDTRADE_ADAPTER_RegisterReceivedMon((WorldtradeWork *)p, (void *)(WORLDTRADE_NoOp(*(void **)((p->ctx)))),
                              WORLDTRADE_GetReturnBox((struct WorldTradeData *)(*(struct RegB **)((p->ctx)))), v);
                p->state = 0x22;
            }
            break;
        case 12:
            p->state = 0x2b;
            GFL_NET_ERR_WaitLinkClosed();
            GFL_NET_STATE_SetWifiError();
            GFL_NET_ERR_ResetState();
            GFL_NET_STATE_ClearErrorMode();
            break;
        case 11:
            p->state = 0x2b;
            GFL_NET_ERR_WaitLinkClosed();
            GFL_NET_STATE_SetWifiError();
            GFL_NET_ERR_ResetState();
            GFL_NET_STATE_ClearErrorMode();
            break;
        case 3:
            (p->err) = n;
            p->state = 0x2d;
            break;
        case 0:
        case 1:
        case 13:
            (p->err) = n;
            p->state = 0x2b;
            GFL_NET_ERR_WaitLinkClosed();
            GFL_NET_STATE_SetWifiError();
            GFL_NET_ERR_ResetState();
            GFL_NET_STATE_ClearErrorMode();
            break;
        case 2:
            WORLDTRADE_CancelSave(p);
            break;
        }
    } else {
        if (++p->timer == 0xe10) {
            WORLDTRADE_CancelSave(p);
        }
    }
    return 2;
}

/*
 * WorldtradeState-setter: hand the object to DPW_TR_UploadFinishAsync, latch state 0xe at +0x28,
 * clear the word at +0xf8c and report 2.
 */
int WORLDTRADE_SERVER_StartUploadFinishB(WorldtradeWork *p)
{
    DPW_TR_UploadFinishAsync();
    p->state = 0xe;
    p->timer = 0;
    return 2;
}

/*
 * Switch on the 0x021C86A8 index (case value = index + 15): state 0x25
 * or a plain WORLDTRADE_CancelSave redraw.
 * The shape is settled and every concrete byte is reproduced; the site is
 * parked because TWO of its callees have no witness anywhere in the tree.
 * Both BLX sites resolve as "(arm, from name) has no witness outside
 * 02201414..02201480; 8 overlays overlap this address (ov016, ov021, ov093,
 * ov111, ov114, ov128, ov172, ov208), none resolvable without a region hint
 * on the symbols: line".  A region hint cannot help: match.py's `label`
 * class needs EXACTLY ONE overlay listing to carry a func_ label at the
 * address, and 0x021C866C / 0x021C86A8 carry none in any overlay.  The
 * neighbours 0x021C8770/0x021C87FC/0x021C887C/0x021C8978 DO carry labels --
 * they are in asm/overlays/ov114.s -- so the fix is to trace those two
 * entries (layout/function_starts.txt is not this lane's file).
 *
 * UNBLOCKED: DPW_TR_IsAsyncEnd(0x021C866C) and DPW_TR_GetAsyncResult
 * (0x021C86A8) are now EXACT entries in layout/matched/ov114
 * (pkt_ov114_021C866C, pkt_ov114_021C86A8); both BLX sites
 * resolve as `matched`.  Verdict promoted to EXACT.
 */
int WORLDTRADE_SERVER_WaitUploadFinishB(WorldtradeWork *p)
{
    s32 n;

    if (DPW_TR_IsAsyncEnd() != 0) {
        n = DPW_TR_GetAsyncResult();
        p->timer = 0;
        switch (n + 15) {
        case 15:
            p->state = 0x25;
            break;
        case 10:
        case 11:
        case 12:
            WORLDTRADE_CancelSave(p);
            break;
        case 0:
        case 1:
        case 3:
        case 13:
            WORLDTRADE_CancelSave(p);
            break;
        case 2:
            WORLDTRADE_CancelSave(p);
            break;
        }
    } else {
        if (++p->timer == 0xe10) {
            WORLDTRADE_CancelSave(p);
        }
    }
    return 2;
}

int WORLDTRADE_SERVER_StartTrade(WorldtradeWork *p)
{
    DPW_TR_TradeAsync(*(u32 *)((u8 *)&p->ent[1].profileId + (p->cur) * (int)sizeof(WorldtradeEntry)), (u8 *)&((struct WorldtradeWork *)p)->ent, (u8 *)&p->ent[8], (u8 *)&((struct WorldtradeWork *)p)->buf_b128, 0x80);
    WORLDTRADE_ADAPTER_SetPair(p, 0x12, 0x14);
    p->state = 0x11;
    p->timer = 0;
    return 2;
}

int WORLDTRADE_SERVER_WaitTrade(WorldtradeWork *p)
{
    int r;
    if(DPW_TR_IsAsyncEnd()) {
        r=DPW_TR_GetAsyncResult();
        p->timer=0;
        switch(r) {
        case 0:
            p->state=0x22;
            WORLDTRADE_ADAPTER_RemovePartyMon((WorldtradeWork *)p,0);
            WORLDTRADE_ADAPTER_RegisterReceivedMonB((WorldtradeWork *)p,(void *)&p->ent[8],(void *)((u8 *)&((struct WorldtradeWork *)p)->ent),(void *)&p->ent[8],p->box);
            WORLDTRADE_ADAPTER_RegisterLanguageVersion((void *)p->ctx->wifiHistory,&p->ent[8]);
            WORLDTRADE_SERVER_RecordTradeResult(p,(u8 *)&p->ent[8],&p->ent[8],(u8 *)&((struct WorldtradeWork *)p)->ent);
            break;
        case -5:
            p->err=r;
            p->state=0x15;
            break;
        case -6: case -7: case -8: case -9: case -10: case -11:
            p->err=r;
            p->state=0x2D;
            break;
        case -12:
            p->err=r;
            p->state=0x2D;
            break;
        case -15: case -14: case -2:
            p->err=r;
            p->state=0x2B;
            GFL_NET_ERR_WaitLinkClosed(); GFL_NET_STATE_SetWifiError(); GFL_NET_ERR_ResetState(); GFL_NET_STATE_ClearErrorMode();
            break;
        case -13:
            WORLDTRADE_CancelSave(p);
            break;
        }
    } else {
        if(++p->timer==0xE10) WORLDTRADE_CancelSave(p);
    }
    return 2;
}

/*
 * WorldtradeState setter: hand over the object, latch the state word at +0x28 and clear the slot.
 */
int WORLDTRADE_SERVER_StartTradeFinish(WorldtradeWork *p)
{
    DPW_TR_TradeFinishAsync();
    p->state = 0x13;
    p->timer = 0x0;
    return 0x2;
}

int WORLDTRADE_SERVER_WaitTradeFinish(WorldtradeWork *p)
{
    s32 n;

    if (DPW_TR_IsAsyncEnd() != 0) {
        n = DPW_TR_GetAsyncResult();
        p->timer = 0;
        switch (n + 15) {
        case 15:
            p->state = 0x25;
            break;
        case 10:
            WORLDTRADE_CancelSave(p);
            break;
        case 0:
        case 1:
        case 3:
        case 13:
            WORLDTRADE_CancelSave(p);
            break;
        case 2:
            WORLDTRADE_CancelSave(p);
            break;
        }
    } else {
        if (++p->timer == 0xe10) {
            WORLDTRADE_CancelSave(p);
        }
    }
    return 2;
}

int WORLDTRADE_SERVER_StartReturn(WorldtradeWork *p)
{
    DPW_TR_ReturnAsync((u8 *)&((struct WorldtradeWork *)p)->ent);
    p->state = 0x1d;
    p->timer = 0x0;
    return 0x2;
}

int WORLDTRADE_SERVER_WaitReturn(WorldtradeWork *p)
{
    int r;
    void *mon;

    if (DPW_TR_IsAsyncEnd() != 0) {
        r = DPW_TR_GetAsyncResult();
        p->timer = 0;
        switch (r) {
        case 0:
            p->state_i = 0x1E;
            break;
        case 1:
            p->busy = 1;
            switch (WORLDTRADE_ADAPTER_CheckPartyHasOther((WorldtradeWork *)p, p->ent)) {
            case 1:
                WORLDTRADE_DeleteTimeIcon(p);
                WORLDTRADE_INPUT_PrintStringPlain(p, p->bank, 0x23, 1, 0xF0F);
                WORLDTRADE_SetNextState(p, 0x2A, 0x20);
                break;
            case 2:
                WORLDTRADE_DeleteTimeIcon(p);
                WORLDTRADE_INPUT_PrintStringPlain(p, p->bank, 0x29, 1, 0xF0F);
                WORLDTRADE_SetNextState(p, 0x2A, 0x20);
                break;
            case 0:
                p->state_i = 0x16;
                p->eb4 = 1;
                p->checkEvolution = 1;
                break;
            }
            break;
        case -3:
            p->busy = 0;
            if (WORLDTRADE_GetIsDeposited(p->ctx->sys) != 0) {
                mon = WORLDTRADE_ADAPTER_AllocHeapBuf(0x48);
                WORLDTRADE_CopyPokemon(p->ctx->sys, mon);
                WORDSET_SetSlotMonNickname(p->words, 0, mon);
                p->mode = 2;
                p->state_i = 0x26;
                WORLDTRADE_ADAPTER_RegisterReceivedMon((WorldtradeWork *)p, (void *)mon, WORLDTRADE_GetReturnBox(p->ctx->sys), 0);
                WORLDTRADE_SetIsDeposited(p->ctx->sys, 0);
                GFL_HEAP_Free(mon);
            } else {
                WORLDTRADE_SERVER_ShowResultByMode(p);
            }
            break;
        case -4:
            p->busy = 0;
            if (WORLDTRADE_GetIsDeposited(p->ctx->sys) != 0) {
                mon = WORLDTRADE_ADAPTER_AllocHeapBuf(0x48);
                WORLDTRADE_CopyPokemon(p->ctx->sys, mon);
                WORDSET_SetSlotMonNickname(p->words, 0, mon);
                p->mode = 3;
                p->state_i = 0x26;
                WORLDTRADE_SetIsDeposited(p->ctx->sys, 0);
                GFL_HEAP_Free(mon);
            }
            break;
        case -15:
        case -14:
        case -12:
        case -2:
            p->err = r;
            p->state_i = 0x2B;
            GFL_NET_ERR_WaitLinkClosed();
            GFL_NET_STATE_SetWifiError();
            GFL_NET_ERR_ResetState();
            GFL_NET_STATE_ClearErrorMode();
            break;
        case -13:
            WORLDTRADE_CancelSave(p);
            break;
        }
    } else {
        if (++p->timer == 0xE10) {
            WORLDTRADE_CancelSave(p);
        }
    }
    return 2;
}

/*
 * Set the mode pair and latch state 0x28.
 */
int WORLDTRADE_SERVER_StateShowResultA(WorldtradeWork *p)
{
    WORLDTRADE_SetStateAndReturn(p, 0x1, 0x0);
    p->state = 0x28;
    return 2;
}

int WORLDTRADE_SERVER_StartDownloadB(WorldtradeWork *p)
{
    DPW_TR_DownloadAsync((u8 *)&((struct WorldtradeWork *)p)->ent);
    p->state = 0x1f;
    p->timer = 0x0;
    return 0x2;
}

/*
 * Switch on the 0x021C86A8 index (case value = index + 15): the 0x1a guard
 * over WORLDTRADE_ADAPTER_CanProceed with the +0x32 flag, index 12 with only the flag, the
 * +0x38/0x2b group returning 2, and the plain redraw returning 2.  The nine
 * hole indices 4..11 and 14 are LISTED as empty cases: without them the
 * compiler folds the case set into a compare chain instead of the listing's
 * 16-slot table, and the WORLDTRADE_SERVER_ShowResultByMode call sits after the switch (every
 * break and every hole lands on it).
 * The shape is settled and every concrete byte is reproduced; the site is
 * parked because 0x021C866C / 0x021C86A8 carry no func_ label in any
 * overlay listing (see the wave-5 residue note for the one-line fix).
 *
 * UNBLOCKED: DPW_TR_IsAsyncEnd(0x021C866C) and DPW_TR_GetAsyncResult
 * (0x021C86A8) are now EXACT entries in layout/matched/ov114
 * (pkt_ov114_021C866C, pkt_ov114_021C86A8); both BLX sites
 * resolve as `matched`.  Verdict promoted to EXACT.
 */
int WORLDTRADE_SERVER_WaitDownloadB(WorldtradeWork *p)
{
    s32 n;

    if (DPW_TR_IsAsyncEnd() != 0) {
        n = DPW_TR_GetAsyncResult();
        p->timer = 0;
        switch (n + 15) {
        case 15:
            if (WORLDTRADE_ADAPTER_CanProceed(p) != 0) {
                p->state = 0x1a;
                p->busy = 0;
                return 2;
            }
            p->busy = 1;
            break;
        case 12:
            p->busy = 0;
            break;
        case 0:
        case 1:
        case 3:
        case 13:
            (p->err) = n;
            p->state = 0x2b;
            GFL_NET_ERR_WaitLinkClosed();
            GFL_NET_STATE_SetWifiError();
            GFL_NET_ERR_ResetState();
            GFL_NET_STATE_ClearErrorMode();
            return 2;
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 14:
            break;
        case 2:
            WORLDTRADE_CancelSave(p);
            return 2;
        }
        WORLDTRADE_SERVER_ShowResultByMode(p);
    } else {
        if (++p->timer == 0xe10) {
            WORLDTRADE_CancelSave(p);
        }
    }
    return 2;
}

/*
 * Switch on the mode word at +0x18; both arms latch state 0x28.
 */
void WORLDTRADE_SERVER_ShowResultByMode(WorldtradeWork *p)
{
    switch (p->f18_u) {
    case 1:
        WORLDTRADE_SetStateAndReturn(p, 1, 0);
        p->state = 0x28;
        break;
    case 2:
        WORLDTRADE_SetStateAndReturn(p, 2, 3);
        p->state = 0x28;
        break;
    }
}

/*
 * lever: u16 local joins species branches; byte flags use explicit masked RMW.
 */
void WORLDTRADE_SERVER_RecordTradeResult(WorldtradeWork *p, void *mon, WorldtradeEntry *ent, void *old)
{
    void *copy;
    WorldtradeServerRecord rec;
    u16 species;
    RECORD_AddOne(p->ctx->record, 0x10);
    MET_TRAINERS_Insert(MET_TRAINERS_GetFromSave(p->ctx->saveData), ent->trainerId);
    copy = WORLDTRADE_DEMO_CreateMyStatusFromEntry(ent);
    TRADE_HISTORY_AddPartner(TRADE_HISTORY_GetFromSave(p->ctx->saveData), copy);
    GFL_HEAP_Free(copy);
    copy = WORLDTRADE_DEMO_CreateMyStatusFromEntry(ent);
    memset(&rec, 0, sizeof(rec));
    MYSTATUS_Copy((struct MyStatus *)copy, (struct MyStatus *)(&rec));
    if (old != 0) species = POKE_TOOL_GetPartyValue(old, 5, 0);
    else species = *(u16 *)&((Deposit *)ent)->have.species;
    rec.old_species = species;
    rec.new_species = POKE_TOOL_GetPartyValue(mon, 5, 0);
    rec.x = ent->greetingSet;
    rec.flags = (rec.flags & ~7) | (ent->ratingLevel & 7);
    rec.y = ent->visitedCountryCount;
    COMM_HISTORY_InsertIfNationSet((p->ctx->wifiHistory), (struct HistoryEntry *)((&rec)));
    GFL_HEAP_Free(copy);
}

/*
 * Addresses are Black-image addresses.
 */
int WORLDTRADE_SERVER_StartCancel(WorldtradeWork *p)
{
    p->wait = 0;
    DPW_TR_CancelAsync();
    p->state_i = 0x2f;
    return 2;
}

/*
 * Small sparse switch on the 0x021C86A8 index: state 0x30 for the +15 index
 * 3 and for the 0/1/13 group, the plain redraw for index 2, and a
 * state-0x30 (not redraw) counter arm.  This handler does not clear
 * p+0xf8c.
 * The shape is settled and every concrete byte is reproduced; the site is
 * parked because 0x021C866C / 0x021C86A8 carry no func_ label in any
 * overlay listing (see the wave-5 residue note for the one-line fix).
 *
 * UNBLOCKED: DPW_TR_IsAsyncEnd(0x021C866C) and DPW_TR_GetAsyncResult
 * (0x021C86A8) are now EXACT entries in layout/matched/ov114
 * (pkt_ov114_021C866C, pkt_ov114_021C86A8); both BLX sites
 * resolve as `matched`.  Verdict promoted to EXACT.
 */
int WORLDTRADE_SERVER_WaitCancel(WorldtradeWork *p)
{
    s32 n;

    if (DPW_TR_IsAsyncEnd() != 0) {
        n = DPW_TR_GetAsyncResult();
        switch (n) {
        case -12:
            p->state = 0x30;
            break;
        case -15:
        case -14:
        case -2:
            p->state = 0x30;
            break;
        case -13:
            WORLDTRADE_CancelSave(p);
            break;
        }
    } else {
        if (++p->timer == 0xe10) {
            p->state = 0x30;
        }
    }
    return 2;
}

/*
 * Every concrete byte is reproduced (52 bytes of code; the listing's extra two
 * are alignment padding).  The one wildcard is the BLX at +0006 to
 * DPW_TR_End, which has no independent witness outside 0x02201C88..0x02201CBA; the
 * resolver reports "(arm, from name) ... 8 overlays overlap this address
 * (ov016, ov021, ov093, ov111, ov114, ov128, ov172, ov208), none resolvable
 * without a region hint on the symbols: line".  Naming one of those eight
 * regions would be a guess, so the site stays parked.
 *
 * Shape: two hand-overs, then the fixed 6/1/0x48 opener, state 0, return 3.
 */
int WORLDTRADE_SERVER_StateStartWipeOutDisconnect(WorldtradeWork *p)
{
    DPW_TR_End();
    WORLDTRADE_DeleteTimeIcon(p);
    WIPE_SYS_Start(0, 0, 0, 0, 6, 1, 0x48);
    p->state = 0;
    return 3;
}

int WORLDTRADE_SERVER_StateFinishTrade(WorldtradeWork *p)
{
    WORLDTRADE_ADAPTER_RegisterReceivedMon((WorldtradeWork *)p, (void *)((u8 *)&((struct WorldtradeWork *)p)->ent), WORLDTRADE_GetReturnBox((struct WorldTradeData *)(**(void ** *)(void **)&p->ctx)), p->receivedEgg);
    WORLDTRADE_ADAPTER_RegisterLanguageVersion((void *)p->ctx->wifiHistory, (WorldtradeEntry *)((u8 *)&((struct WorldtradeWork *)p)->ent));
    WORLDTRADE_SERVER_RecordTradeResult(p, (u8 *)&((struct WorldtradeWork *)p)->ent, &p->ent[0], 0);
    WORLDTRADE_SetIsDeposited(**(void ** *)(void **)&p->ctx, 0);
    p->state = 0x22;
    WORLDTRADE_ADAPTER_SetPair(p, 0x17, 0xf);
    return 2;
}

int WORLDTRADE_SERVER_StartDelete(WorldtradeWork *p)
{
    DPW_TR_DeleteAsync();
    p->state = 0x18;
    p->timer = 0x0;
    return 0x2;
}

/*
 * Switch on the 0x021C86A8 index (case value = index + 15): state 0x25, the
 * +0x38/0x2b four-call group, the +0x38 archive with a plain redraw for the
 * 3+11 pair, the 0/1/13 and 2 redraw groups; 4..10 and 14 are table holes.
 * Concrete bytes reproduced; parked because 0x021C866C / 0x021C86A8 carry
 * no func_ label in any overlay listing (see pkt_ov135_residue.c.txt).
 * Concrete bytes are identical to the image; the only wildcards are the two
 * BLX sites to 0x021C866C and 0x021C86A8, which carry no func_ label in any
 * overlay listing (match.py's `label` class needs exactly one listing to
 * carry the label, so no region hint can witness them).  One-line fix:
 * trace 0x021C866C / 0x021C86A8 in layout/function_starts.txt and this
 * promotes automatically.
 *
 * UNBLOCKED: DPW_TR_IsAsyncEnd(0x021C866C) and DPW_TR_GetAsyncResult
 * (0x021C86A8) are now EXACT entries in layout/matched/ov114
 * (pkt_ov114_021C866C, pkt_ov114_021C86A8); both BLX sites
 * resolve as `matched`.  Verdict promoted to EXACT*.
 */
int WORLDTRADE_SERVER_WaitDelete(WorldtradeWork *p)
{
    s32 n;

    if (DPW_TR_IsAsyncEnd() != 0) {
        n = DPW_TR_GetAsyncResult();
        p->timer = 0;
        switch (n + 15) {
        case 15:
            p->state = 0x25;
            break;
        case 12:
            (p->err) = n;
            p->state = 0x2b;
            GFL_NET_ERR_WaitLinkClosed();
            GFL_NET_STATE_SetWifiError();
            GFL_NET_ERR_ResetState();
            GFL_NET_STATE_ClearErrorMode();
            break;
        case 3:
        case 11:
            (p->err) = n;
        case 0:
        case 1:
        case 13:
            WORLDTRADE_CancelSave(p);
            break;
        case 2:
            WORLDTRADE_CancelSave(p);
            break;
        }
    } else {
        if (++p->timer == 0xe10) {
            WORLDTRADE_CancelSave(p);
        }
    }
    return 2;
}

int WORLDTRADE_SERVER_StateIdle(void)
{
    return 2;
}

/*
 * Enter the 201DC0 sub-state: flag the u16 at +0x32, set the two work values and stamp the state.
 */
int WORLDTRADE_SERVER_StateSetBusyMessage(WorldtradeWork *p)
{
    p->busy = 1;
    WORLDTRADE_SetStateAndReturn(p, 9, 7);
    p->state = 0x28;
    return 2;
}

/*
 * Enter the 201DD8 sub-state: flag the u16 at +0x32, set the two work values and stamp the state.
 */
int WORLDTRADE_SERVER_StateClearBusyMessage(WorldtradeWork *p)
{
    p->busy = 0;
    WORLDTRADE_SetStateAndReturn(p, 9, 8);
    p->state = 0x28;
    return 2;
}

int WORLDTRADE_SERVER_StatePrintMessage9(WorldtradeWork *p)
{
    WORLDTRADE_SetStateAndReturn(p, 0x9, 0x9);
    p->state = 0x28;
    return 2;
}

int WORLDTRADE_SERVER_StatePrintMessage10(WorldtradeWork *p)
{
    p->busy = 0;
    WORLDTRADE_SetStateAndReturn(p, 9, 10);
    p->state = 0x22;
    return 2;
}

int WORLDTRADE_SERVER_StateStartUploadFinishAsync(WorldtradeWork *p)
{
    DPW_TR_UploadFinishAsync();
    p->state = 0x1b;
    p->timer = 0x0;
    return 0x2;
}

/*
 * Switch on the 0x021C86A8 index (case value = index + 15): three
 * WORLDTRADE_SERVER_ShowResultByMode calls falling into the state-0x2b group (archive at +0x38,
 * then the four redraw calls), the two WORLDTRADE_CancelSave groups at indexes 0/1/3/13
 * and 2, and the plain redraw; indexes 4..9 and 14 are table holes.
 * Every concrete byte reproduced; parked only because 0x021C866C / 0x021C86A8
 * carry no func_ label in any overlay listing (wave-5 residue note).
 * Concrete bytes are identical to the image; the only wildcards are the two
 * BLX sites to 0x021C866C and 0x021C86A8, which carry no func_ label in any
 * overlay listing (match.py's `label` class needs exactly one listing to
 * carry the label, so no region hint can witness them).  One-line fix:
 * trace 0x021C866C / 0x021C86A8 in layout/function_starts.txt and this
 * promotes automatically.
 *
 * UNBLOCKED: DPW_TR_IsAsyncEnd(0x021C866C) and DPW_TR_GetAsyncResult
 * (0x021C86A8) are now EXACT entries in layout/matched/ov114
 * (pkt_ov114_021C866C, pkt_ov114_021C86A8); both BLX sites
 * resolve as `matched`.  Verdict promoted to EXACT.
 */
int WORLDTRADE_SERVER_StateWaitUploadFinishAsync(WorldtradeWork *p)
{
    s32 n;

    if (DPW_TR_IsAsyncEnd() != 0) {
        n = DPW_TR_GetAsyncResult();
        p->timer = 0;
        switch (n + 15) {
        case 15:
            WORLDTRADE_SERVER_ShowResultByMode(p);
            break;
        case 12:
            WORLDTRADE_SERVER_ShowResultByMode(p);
        case 11:
            WORLDTRADE_SERVER_ShowResultByMode(p);
        case 10:
            (p->err) = n;
            p->state = 0x2b;
            GFL_NET_ERR_WaitLinkClosed();
            GFL_NET_STATE_SetWifiError();
            GFL_NET_ERR_ResetState();
            GFL_NET_STATE_ClearErrorMode();
            break;
        case 0:
        case 1:
        case 3:
        case 13:
            WORLDTRADE_CancelSave(p);
            break;
        case 2:
            WORLDTRADE_CancelSave(p);
            break;
        }
    } else {
        if (++p->timer == 0xe10) {
            WORLDTRADE_CancelSave(p);
        }
    }
    return 2;
}

int WORLDTRADE_SERVER_StateShowRetryMessage(WorldtradeWork *p)
{
    WORLDTRADE_INPUT_PrintStringPlain(p, (p->bank), 0x99, 1, 0xf0f);
    WORLDTRADE_SetNextState(p, 0x2a, 0x28);
    WORLDTRADE_SetStateAndReturn(p, 1, 0);
    WORLDTRADE_DeleteTimeIcon(p);
    WORLDTRADE_SUBLCD_UpdateSlotAnims(p);
    return 2;
}

/*
 * Maps the state word at +0x38 to one of fifteen codes (cases written in
 * descending order, which is the order MWCC lays the bodies out in) and
 * forwards to WORLDTRADE_INPUT_PrintStringTop with p, the +0xb6c word, the code, 1 and 0x0f0f.
 */
void WORLDTRADE_SERVER_GetErrorMessageId(WorldtradeWork *p)
{
    u32 v;

    switch ((p->err) + 15) {
    case 14:
        v = 0x9d;
        break;
    case 13:
        v = 0xa9;
        break;
    case 12:
        v = 0xa2;
        break;
    case 11:
        v = 0xa4;
        break;
    case 10:
        v = 0xa3;
        break;
    case 9:
        v = 0x1b;
        break;
    case 8:
        v = 0x1c;
        break;
    case 7:
        v = 0x1d;
        break;
    case 6:
        v = 0x1e;
        break;
    case 5:
        v = 0x1f;
        break;
    case 4:
        v = 0x20;
        break;
    case 3:
        v = 0xa0;
        break;
    case 2:
        v = 0xa5;
        break;
    case 1:
        v = 0xaa;
        break;
    case 0:
        v = 0xa1;
        break;
    default:
        v = 0x9f;
        break;
    }
    WORLDTRADE_INPUT_PrintStringTop(p, p->bank, v, 1, 0x0f0f);
}

int WORLDTRADE_SERVER_StateShowErrorMessage(WorldtradeWork *p) { WORLDTRADE_SERVER_GetErrorMessageId(p); if(DPW_TR_IsAsyncEnd()) WORLDTRADE_SetNextState(p,41,48); else WORLDTRADE_SetNextState(p,41,46); WORLDTRADE_SetStateAndReturn(p,0,21); WORLDTRADE_DeleteTimeIcon(p); return 2; }

/*
 * Every concrete byte is reproduced (36 bytes, the last two of them the
 * listing's alignment padding).  The single wildcard is the BLX at +0004 to
 * DPW_TR_IsAsyncEnd, which has no independent witness outside 02201FDC..02201FFE;
 * the resolver reports "(arm, from name) ... 8 overlays overlap this address
 * (ov016, ov021, ov093, ov111, ov114, ov128, ov172, ov208), none resolvable
 * without a region hint on the symbols: line".  Guessing one of those eight
 * regions would be a false witness, so the site stays parked until the region
 * that owns 0x021C866C is named.
 *
 * The shape itself is settled: the callee's result selects state 0x30 or 0x2e,
 * then the 0/0x15 pair is published and 2 is returned.
 *
 * UNBLOCKED: DPW_TR_IsAsyncEnd(0x021C866C) and DPW_TR_GetAsyncResult
 * (0x021C86A8) are now EXACT entries in layout/matched/ov114
 * (pkt_ov114_021C866C, pkt_ov114_021C86A8); both BLX sites
 * resolve as `matched`.  Verdict promoted to EXACT*.
 */
int WORLDTRADE_SERVER_StateCheckAsyncEnd(WorldtradeWork *p)
{
    if (DPW_TR_IsAsyncEnd() != 0) {
        p->state = 0x30;
    } else {
        p->state = 0x2e;
    }
    WORLDTRADE_SetStateAndReturn(p, 0, 0x15);
    return 2;
}

int WORLDTRADE_SERVER_StateShowErrorMessageB(WorldtradeWork *p) { WORLDTRADE_SERVER_GetErrorMessageId(p); WORLDTRADE_SetNextState(p,41,40); WORLDTRADE_SetStateAndReturn(p,1,0); WORLDTRADE_DeleteTimeIcon(p); if((*(int *)&p->d0)>0) WORLDTRADE_SUBLCD_UpdateSlotAnims(p); return 2; }

/*
 * Publish the 0x29/0x22 then the 0x25/0x28 pair and report 2.
 */
int WORLDTRADE_SERVER_StateOpenSavePrompt(WorldtradeWork *p)
{
    WORLDTRADE_SetNextState(p, 0x29, 0x22);
    WORLDTRADE_ADAPTER_SetPair(p, 0x25, 0x28);
    return 2;
}

/*
 * Latch state 0x23 and publish the +2 tick of the 0x3c query into +0xdfc.
 */
int WORLDTRADE_SERVER_StartSave(WorldtradeWork *p)
{
    GAME_DATA_SaveStart(GAMESYSTEM_GetGameData((struct GameSystem *)p->ctx->gameData));
    p->state = 0x23;
    (p->cnt) = GFL_USE_GetRandom(0x3c) + 2;
    return 2;
}

int WORLDTRADE_SERVER_StateCountdown(WorldtradeWork *p)
{
    p->cnt--;
    if (p->cnt == 0) {
        p->state_i = 0x24;
    }
    return 2;
}

int WORLDTRADE_SERVER_WaitSave(WorldtradeWork *p)
{
    if (GAME_DATA_SaveMain(GAMESYSTEM_GetGameData((struct GameSystem *)p->ctx->gameData)) == 1) {
        p->state = p->stateAfterSaveWait;
    }
    return 2;
}

/*
 * When the mode query answers 2, publish the u16 at +0xe0e and hand the object back.
 */
int WORLDTRADE_SERVER_StateSaveGame(WorldtradeWork *p)
{
    if (GAME_DATA_SaveMain(GAMESYSTEM_GetGameData((struct GameSystem *)p->ctx->gameData)) == 2) {
        p->state = p->stateAfterSave;
        WORLDTRADE_DeleteTimeIcon(p);
    }
    return 2;
}

/*
 * Run the sub-object init, stamp 0x27 and report 2.
 */
int WORLDTRADE_SERVER_StartSaveB(WorldtradeWork *p)
{
    GAME_DATA_SaveStart(GAMESYSTEM_GetGameData((struct GameSystem *)p->ctx->gameData));
    p->state = 0x27;
    return 2;
}

int WORLDTRADE_SERVER_WaitSaveB(WorldtradeWork *p)
{
    if (GAME_DATA_SaveMain(GAMESYSTEM_GetGameData((struct GameSystem *)(p->ctx->gameData))) == 2) {
        WORLDTRADE_SetStateAndReturn(p, 1, 0);
        WORLDTRADE_DeleteTimeIcon(p);
        WORLDTRADE_INPUT_PrintStringPlain(p, (p->bank), (p->mode), 1, 0xF0F);
        WORLDTRADE_SetNextState(p, 0x2A, 0x20);
    }
    return 2;
}

/*
 * lever: nested if with equal sentinel arm first preserves the branch hop.
 */
int WORLDTRADE_SERVER_StateStartWipeOutRestore(WorldtradeWork *p)
{
    WORLDTRADE_DeleteTimeIcon(p);
    if (p->eb4 == 1) {
        if (GXx_GetMasterBrightness_((u16 *)REG_DB_MASTER_BRIGHT_ADDR) == -16)
            WIPE_SYS_Start((void *)3, 0, 0, 0, 6, 1, 0x48);
        else
            WIPE_SYS_Start(0, 0, 0, 0, 6, 1, 0x48);
    } else {
        WIPE_SYS_Start((void *)3, 0, 0, 0, 6, 1, 0x48);
    }
    p->state = 0;
    return 3;
}

int WORLDTRADE_SERVER_StateWaitMessage(WorldtradeWork *p)
{
    if (WORLDTRADE_ADAPTER_IsStreamBusy((PrintStreamCtx *)((u8 *)&((struct WorldtradeWork *)p)->printer)) == 0) {
        p->state = p->returnState;
    }
    return 2;
}

int WORLDTRADE_SERVER_StateWaitMessageOrTouch(WorldtradeWork *p) { if((WORLDTRADE_ADAPTER_IsStreamBusy((PrintStreamCtx *)((u8 *)&((struct WorldtradeWork *)p)->printer))==0 && (KEY_GetTrg()&1)) || TOUCHPANEL_GetTrg()) { GFL_USE_PlaySeDefaultVolume(0x547); p->state=p->returnState; } return 2; }
