/*
 * file:     gtsnego_disp.c
 * unit:     yes
 * function: GTSNEGO_DISP_SetCallback, GTSNEGO_DISP_SetStateCallback, GTSNEGO_DISP_OnTradeSync, GTSNEGO_DISP_OnStatusSync, GTSNEGO_DISP_OnRecordSync, GTSNEGO_DISP_StartTrade, GTSNEGO_DISP_CycleRowB, GTSNEGO_DISP_CycleRowC, GTSNEGO_DISP_CycleRowA, GTSNEGO_DISP_MoveRowCursor, GTSNEGO_DISP_OnRowCursorMoved, GTSNEGO_DISP_MoveCursorVertical, GTSNEGO_DISP_WaitWipeDone, GTSNEGO_DISP_StartWipe, GTSNEGO_DISP_ShowTradeReady, GTSNEGO_DISP_WaitTradeStart, GTSNEGO_DISP_ShowTradeConfirm, GTSNEGO_DISP_ConfirmStatus, GTSNEGO_DISP_PrepareTrade, GTSNEGO_DISP_StartSync, GTSNEGO_DISP_SendStatus, GTSNEGO_DISP_SendRecord, GTSNEGO_DISP_SendHandshake, GTSNEGO_DISP_WaitNegotiation, GTSNEGO_DISP_CheckNegotiation, GTSNEGO_DISP_WaitPartnerReady, GTSNEGO_DISP_HandleTradeKeys, GTSNEGO_DISP_ScoreMatch, GTSNEGO_DISP_StartMatchmaking, GTSNEGO_DISP_OnMenuCallback, GTSNEGO_DISP_OnConfirmDone, GTSNEGO_DISP_HandleConfirmKeys, GTSNEGO_DISP_CreateConfirmUi, GTSNEGO_DISP_GetEntry, GTSNEGO_DISP_GetEntryClamped, GTSNEGO_DISP_ShowSubPlanes, GTSNEGO_DISP_Teardown, GTSNEGO_DISP_OnDisconnect, GTSNEGO_DISP_OnDisconnectCallback, GTSNEGO_DISP_CreateExitTooltip, GTSNEGO_DISP_OnExitMenuDone, GTSNEGO_DISP_OpenExitMenu, GTSNEGO_DISP_ShowListMessage, GTSNEGO_DISP_EndList, GTSNEGO_DISP_ListCursorUp, GTSNEGO_DISP_ListCursorDown, GTSNEGO_DISP_OnListConfirmDone, GTSNEGO_DISP_DeleteMenuWindow, GTSNEGO_DISP_HandleListInput, GTSNEGO_DISP_WaitSelectStart, GTSNEGO_DISP_ShowPokemonList, GTSNEGO_DISP_ShowPartySelect, GTSNEGO_DISP_SelectParty, GTSNEGO_DISP_CheckPartySelect, GTSNEGO_DISP_OnPartySelected, GTSNEGO_DISP_OnPartyMenuDone, GTSNEGO_DISP_OpenPartyMenu, GTSNEGO_DISP_HandlePartyInput, GTSNEGO_DISP_ResetScreen, GTSNEGO_DISP_Create, GTSNEGO_DISP_Step, GTSNEGO_DISP_Delete, GTSNEGO_DISP_CreateMsgSystem, GTSNEGO_DISP_DrawSystem, GTSNEGO_DISP_DeleteMsgSystem, GTSNEGO_DISP_GetUnit, GTSNEGO_DISP_InitBgLayers, GTSNEGO_DISP_BlendPalette, GTSNEGO_DISP_SetTradePalette, GTSNEGO_DISP_VBlank, GTSNEGO_DISP_RegisterGraphics, GTSNEGO_DISP_Noop, GTSNEGO_DISP_RedrawActors, GTSNEGO_DISP_ResetActors, GTSNEGO_DISP_CreateTouchbar, GTSNEGO_DISP_GetTouchbar, GTSNEGO_DISP_DeleteTouchbar, GTSNEGO_DISP_CreateCursorActor, GTSNEGO_DISP_SetCursorState
 * address:  0x021D4240
 * region:   ov120
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   MYSTATUS_GetSize 0x02008468 thumb
 *   UI_SetInputMode 0x020355D8 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   GTSNEGO_MSG_RedrawRowA 0x021D7E88 thumb ov120
 *   GTSNEGO_MSG_RedrawRowB 0x021D7E9C thumb ov120
 *   GTSNEGO_MSG_RedrawRowC 0x021D7EB0 thumb ov120
 *   GTSNEGO_MSG_SetActorMode 0x021D6B84 thumb ov120
 *   APP_TASKMENU_WIN_SetActive 0x02028218 thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   WIPE_SYS_Start 0x0202208C thumb
 *   d_021D8904 0x021D8904 data a2
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   GTSNEGO_MSG_CreateDraw 0x021D8430 thumb ov120
 *   GTSNEGO_MSG_PrintDraw 0x021D8484 thumb ov120
 *   GTSNEGO_MSG_PrintWindowB 0x021D7A74 thumb ov120
 *   GTSNEGO_MSG_PrintTooltip 0x021D7F5C thumb ov120
 *   GTSNEGO_MSG_DeleteEntryWindow 0x021D80D4 thumb ov120
 *   GTSNEGO_MSG_PrintSummary 0x021D880C thumb ov120
 *   GTSNEGO_MSG_SetIdleAnim 0x021D74B0 thumb ov120
 *   DWC_CheckProfanityProcess 0x0217BC90 arm ov009
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   STRBUF_Delete 0x02045808 arm
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   MET_TRAINERS_GetFromSave 0x0200ED48 thumb
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   MYSTATUS_CreateNameStrbuf 0x02008510 thumb
 *   MI_CpuFill8 0x02082BCC arm
 *   STRBUF_GetChars 0x02045A90 arm
 *   STRBUF_GetLength 0x020458F8 arm
 *   STRBUF_GetEosChar 0x02045A98 arm
 *   DWC_CheckProfanityExAsync 0x0217BC44 arm ov009
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   GTSNEGO_MSG_UpdatePrintStream 0x021D7AF4 thumb ov120
 *   GFL_NET_HANDLE_GetNegotiationNum 0x020399EC arm
 *   TRADE_HISTORY_GetTradeCount 0x02009EA8 thumb
 *   GFL_NET_HANDLE_CheckNegotiation 0x02039ACC arm
 *   GTSNEGO_MSG_UpdateButtons  0x021D7C10  thumb  ov120
 *   GTSNEGO_MSG_SetDecide  0x021D8638  thumb  ov120
 *   GTSNEGO_MSG_DeleteWindow  0x021D7B38  thumb  ov120
 *   GTSNEGO_MSG_DeleteConfirmWindow  0x021D8648  thumb  ov120
 *   KEY_GetTrg  0x020362DC  arm
 *   GFL_NET_STATE_WifiDisconnect  0x0203C554  arm
 *   GFL_NET_STATE_GetWifiState  0x0203C3EC  arm
 *   GFL_NET_SetAutoExit  0x0203D7B0  arm
 *   GFL_NET_SetLoginOption  0x0203D7BC  arm
 *   DWC_GetMatchIntValue 0x0216CB30 arm ov009
 *   TRADE_HISTORY_GetFromSave 0x02009EC8 thumb
 *   TRADE_HISTORY_HasPartner 0x02009E74 thumb
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   MYSTATUS_GetId 0x02008530 thumb
 *   GTSNEGO_MSG_CreateConfirmUi 0x021D8590 thumb ov120
 *   GFL_NET_SetWaitMode 0x0203D644 arm
 *   WIFILIST_CreateExchangeToken 0x02009CA8 thumb
 *   DWC_AddMatchKeyInt 0x0216C8DC arm ov009
 *   STD_TSPrintf 0x0208D7E0 arm
 *   DWC_RAP_StartMatchWithFilter 0x0215580C thumb ov009
 *   GFL_NET_STATE_WifiEnterFriendMatch 0x0203C35C arm
 *   DWC_RAP_SetVchatEnabled 0x02156BC4 thumb ov009
 *   GFL_NET_STATE_SetError 0x0203C9AC arm
 *   d_021D8B40 0x021D8B40 data a2
 *   d_021D8B50 0x021D8B50 data a1
 *   APP_TASKMENU_WIN_IsFinish 0x02028230 thumb
 *   APP_TASKMENU_WIN_Delete 0x02028148 thumb
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 *   GTSNEGO_MSG_PrintWindow 0x021D79F4 thumb ov120
 *   GTSNEGO_MSG_CreateIdleUi 0x021D7550 thumb ov120
 *   GTSNEGO_MSG_PrintStatus 0x021D8520 thumb ov120
 *   TOUCHBAR_IsBusy 0x021B6498 thumb ov067
 *   UI_GetInputMode 0x020355C4 arm
 *   GTSNEGO_MSG_SetCursorAnimSeq 0x021D6A9C thumb ov120
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   d_021D88D0 0x021D88D0 data a4
 *   TOUCHBAR_Update 0x021B63D0 thumb ov067
 *   TOUCHBAR_GetPressedButtonIdIfDone 0x021B6448 thumb ov067
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   GTSNEGO_MSG_DeleteButtonsKeep 0x021D7EC4 thumb ov120
 *   TOUCHBAR_SetAllButtonsVisible 0x021B64D0 thumb ov067
 *   GTSNEGO_MSG_ClearRows 0x021D7D3C thumb ov120
 *   GTSNEGO_MSG_CreateListUi 0x021D7DC8 thumb ov120
 *   GTSNEGO_MSG_CreateTooltip 0x021D7ECC thumb ov120
 *   GAME_DATA_GetTradeHistory 0x02012F14 thumb
 *   TRADE_HISTORY_GetPartnerCount 0x02009E8C thumb
 *   TRADE_HISTORY_GetPartner 0x02009E54 thumb
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm
 *   GTSNEGO_MSG_Teardown 0x021D761C thumb ov120
 *   GTSNEGO_MSG_DeleteAll 0x021D883C thumb ov120
 *   GTSNEGO_MSG_IsConfirmFinished 0x021D8664 thumb ov120
 *   GTSNEGO_MSG_TeardownTileRows 0x021D6D94 thumb ov120
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   GTSNEGO_MSG_CloseMenu 0x021D8418 thumb ov120
 *   TOUCHBAR_SetButtonVisible 0x021B6558 thumb ov067
 *   GTSNEGO_MSG_RestartIconAnim 0x021D6FD8 thumb ov120
 *   GTSNEGO_MSG_OpenMenuB 0x021D8358 thumb ov120
 *   GTSNEGO_MSG_CursorUp 0x021D6E50 thumb ov120
 *   GTSNEGO_MSG_SetScrollState 0x021D6FF8 thumb ov120
 *   GTSNEGO_MSG_PrintListEntryN 0x021D82D8 thumb ov120
 *   GTSNEGO_MSG_CursorDown 0x021D6E1C thumb ov120
 *   GTSNEGO_MSG_PrintListEntryAt 0x021D822C thumb ov120
 *   GTSNEGO_MSG_StepScroll 0x021D702C thumb ov120
 *   GTSNEGO_MSG_DrawTileRows 0x021D6D10 thumb ov120
 *   GTSNEGO_MSG_ShiftListUp 0x021D82F8 thumb ov120
 *   GTSNEGO_MSG_ScrollListUp 0x021D7260 thumb ov120
 *   GTSNEGO_MSG_ShiftListDown 0x021D824C thumb ov120
 *   GTSNEGO_MSG_ScrollListDown 0x021D7220 thumb ov120
 *   KEY_GetRepeat 0x0203633C arm
 *   GTSNEGO_MSG_ClearScrollState 0x021D7020 thumb ov120
 *   GTSNEGO_MSG_ScrollAllRows 0x021D70C8 thumb ov120
 *   GTSNEGO_MSG_SetIconY 0x021D733C thumb ov120
 *   APP_TASKMENU_WIN_SetDecide 0x0202822C thumb
 *   GTSNEGO_MSG_SetCursorIndex 0x021D6E70 thumb ov120
 *   TOUCHPANEL_HitCont 0x02035BA4 arm
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   GTSNEGO_MSG_SetIconYClamped 0x021D7374 thumb ov120
 *   GTSNEGO_MSG_PrintListRange 0x021D82A8 thumb ov120
 *   GTSNEGO_MSG_FillListRange 0x021D72A0 thumb ov120
 *   GTSNEGO_MSG_TeardownActorList 0x021D6D48 thumb ov120
 *   d_021D88D8 0x021D88D8 data
 *   d_021D88C8 0x021D88C8 data
 *   GTSNEGO_MSG_InitWindows 0x021D6BB0 thumb ov120
 *   GTSNEGO_MSG_PrintList 0x021D81E0 thumb ov120
 *   GTSNEGO_MSG_SetupRowBg 0x021D70F0 thumb ov120
 *   GFL_NET_ERR_RestoreBrightness 0x0200F800 thumb
 *   GTSNEGO_MSG_CreateYesNoUi 0x021D7D6C thumb ov120
 *   GAME_DATA_GetMyParty 0x02012934 thumb
 *   POKEPARTY_GetNonEggCount 0x0201AA1C thumb
 *   GTSNEGO_MSG_IsCursorAnimDone  0x021D6AC0  thumb
 *   GTSNEGO_MSG_OpenMenu 0x021D7B60 thumb ov120
 *   GTSNEGO_MSG_DeleteDraw 0x021D846C thumb ov120
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   GTSNEGO_MSG_Create 0x021D7724 thumb ov120
 *   GFL_NET_COMMAND_AddCommandTable 0x0203A574 arm
 *   d_021D88EC 0x021D88EC data a4
 *   GFL_NET_ERR_SetKeepDark 0x0200F7E8 thumb
 *   GFL_NET_RefreshWmIconAtTopRight 0x0203D34C arm
 *   GFL_NET_ERR_GetErrorLevel 0x0200FB24 thumb
 *   APP_TASKMENU_WIN_Update 0x02028178 thumb
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 *   GTSNEGO_MSG_Main 0x021D7858 thumb ov120
 *   DWC_RAPCOMMON_HandleNetError 0x02157170 thumb ov009
 *   WIPE_SetBrightnessFadeOut 0x0202223C thumb
 *   GFL_NET_ERR_Halt 0x0200F7DC thumb
 *   GFL_NET_ERR_ClearKeepDark 0x0200F7F4 thumb
 *   GFL_NET_COMMAND_DeleteCommandTable 0x0203A5E4 arm
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   GTSNEGO_MSG_Delete 0x021D7898 thumb ov120
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GF_OVERLAY_Load 0x02034AC4 arm
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 *   GX_DispOn 0x0207D46C arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   d_021D8BC8 0x021D8BC8 data a1
 *   ov_id 0x00000043 data
 *   d_021D8B98 0x021D8B98 data a4
 *   d_021D8974 0x021D8974 data a4
 *   d_021D8B60 0x021D8B60 data a4
 *   CLACT_DrawSystem 0x0204A600 arm
 *   BLINK_PALANM_Update 0x0202EA40 thumb
 *   GTSNEGO_MSG_StepIdleFade 0x021D75F4 thumb ov120
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   GTSNEGO_MSG_DeleteCursorActor 0x021D6ED8 thumb ov120
 *   GTSNEGO_MSG_DeleteTileHandle 0x021D6C64 thumb ov120
 *   GFL_HEAP_Free 0x020307B0 arm
 *   GTSNEGO_MSG_DeleteActors 0x021D6B5C thumb ov120
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   TCB_DeleteTask 0x02030EAC arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   BLINK_PALANM_Delete 0x0202EA20 thumb
 *   BG_SYS_FreeTileRun 0x0203FB44 arm
 *   BG_SYS_FreeTiles 0x02040DA8 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   d_021D89B0      0x021D89B0  data
 *   BG_SYS_InitBgLayer   0x0203FCA0  arm
 *   BG_SYS_FreeSlot   0x020414AC  arm
 *   BG_SYS_PushTile   0x020409B4  arm
 *   BG_SYS_Init   0x02040C14  arm
 *   BG_SYS_SetTileEntry   0x02041300  arm
 *   PALANM_Create 0x02021518 thumb
 *   PALANM_AllocSlotBuffers 0x0202155C thumb
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 *   PALANM_BlendChannel 0x02021FD8 thumb
 *   PALANM_GetTransWork 0x02021730 thumb
 *   DC_FlushRange 0x020862F0 arm
 *   GXS_LoadOBJPltt 0x0207E5D0 arm
 *   GXS_LoadBGPltt 0x0207E468 arm
 *   PALANM_FreeSlotBuffers 0x020215A0 thumb
 *   PALANM_Delete 0x02021540 thumb
 *   d_021D8920 0x021D8920 data a4
 *   d_021D891C 0x021D891C data a4
 *   d_021D8918 0x021D8918 data a4
 *   d_021D895C 0x021D895C data a4
 *   d_021D896C 0x021D896C data a4
 *   d_021D894C 0x021D894C data a4
 *   d_021D8954 0x021D8954 data a4
 *   d_021D8944 0x021D8944 data a4
 *   d_021D8964 0x021D8964 data a4
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_RegisterObjCharFromHandle 0x02049740 arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandle 0x02049990 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   BLINK_PALANM_Create 0x0202E940 thumb
 *   BLINK_PALANM_LoadPalettes 0x0202E9AC thumb
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   G2x_SetBlendAlpha_ 0x0207D63C arm
 *   GTSNEGO_MSG_CreateActorAt 0x021D6AF0 thumb ov120
 *   d_021D8990 0x021D8990 data a4
 *   TOUCHBAR_Create 0x021B62E0 thumb ov067
 *   TOUCHBAR_Delete  0x021B639C  thumb  ov067
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   gGtsnegoEntryTable 0x021D8B70 data a1
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb  arm9
 *   MYSTATUS_Copy  0x02008494  thumb  arm9
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb  arm9
 *   GREETING_SAVEDATA_GetSentence  0x0200E6FC  thumb  arm9
 *   MET_TRAINERS_Insert  0x0200ED54  thumb  arm9
 *   GAME_DATA_GetWifiList  0x0201283C  thumb  arm9
 *   GAME_DATA_GetMyStatusPlayer  0x02012950  thumb  arm9
 *   GREETING_SAVEDATA_GetFromSaveThunk  0x0200E6E8  thumb  arm9
 *   MYSTATUS_NameFromStrbuf  0x020084E4  thumb  arm9
 *   MYSTATUS_GetTrainerView  0x02008554  thumb  arm9
 */
#include "../version.h"
#include "../sdk_ioreg.h"
#include "ov120_types.h"
struct GtsnegoDispCtx;
struct GtsnegoParentCtx;

typedef struct { u32 value; u8 kind; u8 pad; u16 detail; u32 tail; } MatchFilterRecord;

/* The sentence and trade count a player sends to the partner (12 bytes). */
struct GtsnegoDispRecord {
    unsigned short sentence[4];
    int tradeCount;
};

/* List cursor state passed to GTSNEGO_MSG_CursorUp and GTSNEGO_MSG_CursorDown. */
struct GtsnegoListState {
    int count;
    int cursor;
    int scrollTop;
};

/* Name check state of the partner (0x28 bytes cleared as one block). */
struct GtsnegoProfanity {
    unsigned short name[12];
    unsigned short *words;
    char flags[4];
    int result;
    unsigned short maxChars;
    unsigned char pad_1AE[2];
};

struct GtsnegoDispCtx {
    void (*stateFunc)(struct GtsnegoDispCtx *);
    int (*rowInputCallback)(int, struct GtsnegoDispCtx *);
    unsigned char pad_8[4];
    unsigned short heapId;
    unsigned char pad_E[2];
    unsigned int clactUnit;
    int waitFrames;
    unsigned int selectedPartnerId;
    unsigned char pad_1C[16];
    void *gameData;
    void *saveControl;
    void *tooltipWin;
    void *taskMenu;
    struct GtsnegoActorSys *actorSys;
    struct GtsnegoMsgCtx *msgCtx;
    void *wifiList;
    struct GtsnegoParentCtx *parentCtx;
    unsigned char pad_4C[12];
    MatchFilterRecord matchKeys[8];
    char matchFilter[128];
    int tradeMode;
    int rowBIndex;
    int rowCIndex;
    int rowAIndex;
    int selectedListIndex;
    unsigned int myTrainerId;
    struct GtsnegoListState list;
    int partyCursor;
    int buttonCursor;
    int listCursorRow;
    struct GtsnegoDispRecord myRecord;
    struct GtsnegoDispRecord partnerRecord;
    unsigned char pad_180[4];
    int cannotTrade;
    struct GtsnegoProfanity profanity;
    unsigned int restoreBrightness;
    unsigned int restoreDelay;
};

struct GtsnegoParentCtx {
    void *gameData;
    unsigned int rowAIndex;
    unsigned int rowBIndex;
    unsigned int partnerRowA;
    unsigned int partnerRowB;
    void *myStatus;
    void *partnerStatus;
    int recentIds[100];
    int recentIdCount;
    int screenState;
};

struct GtsnegoDispEntry;
struct Link;
struct ClactActor;
struct Sub0200852CObj;
struct MsgBank;
struct Rec;
struct U16Vec;
struct L0200ED54;
struct Rec44;
struct Sub24;
struct Rec0200E6FC;
struct Sub02009D9CObj;
struct TouchBar;
struct TaskMenu;
struct BigObj;
struct Proc;
struct Big;
struct Proc;
struct DispVram;
struct Bank;
struct Cfg;
struct Row;
struct Node;
struct BlinkPalAnm;
struct Chan02021FD8;
struct CodeIn;
struct ClactActor;
struct Vec2;
#include "../types.h"

typedef struct { u16 v[4]; } Halfwords;





#include "../arm9/bg_sys.h"

typedef struct GtsnegoDispPair { int a,b; } GtsnegoDispPair;

typedef struct Word { int a; } Word;

typedef struct Data { u32 w[8]; } Data;

typedef struct GtsnegoDispConfig { Data *defs; u32 count; int actorSys; u32 bgLayer, bgPlttSlot, actorPlttSlot; int iconSet, skipBgGfx; } GtsnegoDispConfig;

typedef struct PosRecord { u16 x, y, z; u8 a, b; } PosRecord;

typedef struct GtsnegoDispEntry { u8 code, x, y, other; } GtsnegoDispEntry;

typedef struct GtsnegoDispVec { s16 x, y; } GtsnegoDispVec;

#include "../arm9/net_handle.h"
#ifdef __MWERKS__
#define GFL_NET_SendToHandle GFL_NET_SendToHandle_hdr
#endif
#include "../arm9/net.h"
#ifdef __MWERKS__
#undef GFL_NET_SendToHandle
int GFL_NET_SendToHandle(GFLNetHandle *, u16, u16, const void *);
#endif
#include "../arm9/mi_memory.h"
#include "../arm9/config.h"
#include "../arm9/ui.h"
#include "../arm9/gfl_use.h"
#include "gtsnego_message.h"
struct TaskMenuWin;
#include "../arm9/app_taskmenu.h"
#include "../arm9/wipe.h"
struct GtsnegoMsgCtx;
struct GameData;
struct MyStatus;
#include "../arm9/game_data.h"
#include "../arm9/mystatus.h"
struct GtsnegoActorSys;
#include "../ov009/dwc_prof.h"
#include "../arm9/msgdata.h"
struct Strbuf;
#include "../arm9/strbuf.h"
#include "../arm9/net_system.h"
#include "../arm9/met_trainers_savedata.h"
struct MetTrainersSave;
struct GFLNetHandle;
#include "../arm9/greeting_savedata.h"
struct QuadRecord;
struct TradeHistory;
#include "../arm9/trade_history.h"
#include "../arm9/key.h"
#include "../arm9/net_state.h"
#include "../ov009/dwc_match.h"
struct SaveControl;
#include "../arm9/wifilist.h"
#include "../arm9/std_sprintf.h"
#include "../ov009/dwc_rap.h"
#include "../ov067/touchbar.h"
#include "../arm9/touchpanel.h"
struct TaskMenuWork;
#include "../arm9/net_err.h"
struct Party;
#include "../arm9/pokeparty.h"
#include "../arm9/gfl_heap.h"
#include "../arm9/procsys.h"
struct FieldState;
#include "../arm9/net_command.h"
#include "../ov009/dwc_rapcommon.h"
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/gf_overlay.h"
#include "../arm9/gx.h"
struct DispVramCfg;
struct SysInit;
#include "../arm9/clact.h"
struct TcbTask;
#include "../arm9/blink_palanm.h"
struct TcbTask;
#include "../arm9/tcb_list.h"
#include "../arm9/palanm.h"
#include "../arm9/os_cache.h"
#include "../arm9/gx_load2d.h"
#include "../arm9/arc_tool.h"
#include "../arm9/arc_util.h"
#include "../arm9/g2.h"
void GTSNEGO_DISP_SetCallback(void **slot, void *callback);
void GTSNEGO_DISP_SetStateCallback(void *dispCtx, void *callback, int line);
void GTSNEGO_DISP_OnTradeSync(u32 netId,int size,const void *data,struct GtsnegoDispCtx *dispCtx,struct GFLNetHandle *netHandle);
void GTSNEGO_DISP_OnStatusSync(u32 netId,int size,const void *data,struct GtsnegoDispCtx *dispCtx,struct GFLNetHandle *netHandle);
void GTSNEGO_DISP_OnRecordSync(u32 netId,int size,const void *data,struct GtsnegoDispCtx *dispCtx,struct GFLNetHandle *netHandle);
int GTSNEGO_DISP_StartTrade(int choice, struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_CycleRowB(int delta, struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_CycleRowC(int delta, struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_CycleRowA(int delta, struct GtsnegoDispCtx *dispCtx);
int GTSNEGO_DISP_MoveRowCursor(int selection, struct GtsnegoDispCtx *dispCtx);
int GTSNEGO_DISP_OnRowCursorMoved(int selection,struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_MoveCursorVertical(int direction,struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_WaitWipeDone(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_StartWipe(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_ShowTradeReady(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_WaitTradeStart(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_ShowTradeConfirm(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_ConfirmStatus(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_PrepareTrade(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_StartSync(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_SendStatus(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_SendRecord(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_SendHandshake(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_WaitNegotiation(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_CheckNegotiation(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_WaitPartnerReady(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_HandleTradeKeys(struct GtsnegoDispCtx *dispCtx);
int GTSNEGO_DISP_ScoreMatch(int matchData, void *param);
void GTSNEGO_DISP_StartMatchmaking(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_OnMenuCallback(u32 selection,s32 event,void *);
void GTSNEGO_DISP_OnConfirmDone(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_HandleConfirmKeys(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_CreateConfirmUi(struct GtsnegoDispCtx *dispCtx);
void *GTSNEGO_DISP_GetEntry(void **list,int index);
void *GTSNEGO_DISP_GetEntryClamped(void **list,int index);
void GTSNEGO_DISP_ShowSubPlanes(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_Teardown(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_OnDisconnect(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_OnDisconnectCallback(u32 unused, s32 buttonIndex, void *);
void GTSNEGO_DISP_CreateExitTooltip(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_OnExitMenuDone(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_OpenExitMenu(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_ShowListMessage(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_EndList(struct GtsnegoDispCtx *dispCtx);
int GTSNEGO_DISP_ListCursorUp(struct GtsnegoDispCtx *dispCtx);
int GTSNEGO_DISP_ListCursorDown(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_OnListConfirmDone(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_DeleteMenuWindow(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_HandleListInput(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_WaitSelectStart(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_ShowPokemonList(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_ShowPartySelect(struct GtsnegoDispCtx *dispCtx);
int GTSNEGO_DISP_SelectParty(struct GtsnegoDispCtx *dispCtx,int position);
int GTSNEGO_DISP_CheckPartySelect(struct GtsnegoDispCtx *dispCtx, int position);
void GTSNEGO_DISP_OnPartySelected(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_OnPartyMenuDone(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_OpenPartyMenu(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_HandlePartyInput(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_ResetScreen(struct GtsnegoDispCtx *dispCtx);
int GTSNEGO_DISP_Create(void *owner, int unused, struct GtsnegoParentCtx *parentCtx);
int GTSNEGO_DISP_Step(int unusedA, int unusedB, int unusedC, struct GtsnegoDispCtx *dispCtx);
int GTSNEGO_DISP_Delete(void *owner, int unusedA, int unusedB, struct GtsnegoDispCtx *dispCtx);
struct GtsnegoActorSys *GTSNEGO_DISP_CreateMsgSystem(u32 heap,void *arg);
void GTSNEGO_DISP_DrawSystem(struct GtsnegoActorSys *actorSys);
void GTSNEGO_DISP_DeleteMsgSystem(struct GtsnegoActorSys *actorSys);
struct Unit *GTSNEGO_DISP_GetUnit(struct GtsnegoActorSys *actorSys);
void GTSNEGO_DISP_InitBgLayers(struct GtsnegoActorSys *actorSys);
void GTSNEGO_DISP_BlendPalette(struct GtsnegoActorSys *actorSys,int bank,int *offset,int *size,int count);
void GTSNEGO_DISP_SetTradePalette(struct GtsnegoActorSys *actorSys,int flag,int mode);
void GTSNEGO_DISP_VBlank(struct TcbTask *unused, void *actorSysArg);
void GTSNEGO_DISP_RegisterGraphics(struct GtsnegoActorSys *actorSys);
void GTSNEGO_DISP_Noop(struct GtsnegoActorSys *actorSys, int unusedFlag);
void GTSNEGO_DISP_RedrawActors(struct GtsnegoActorSys *actorSys);
void GTSNEGO_DISP_ResetActors(struct GtsnegoActorSys *actorSys);
void GTSNEGO_DISP_CreateTouchbar(struct GtsnegoActorSys *actorSys, int actorPlttSlot);
struct TouchBar *GTSNEGO_DISP_GetTouchbar(struct GtsnegoActorSys *actorSys);
void GTSNEGO_DISP_DeleteTouchbar(struct GtsnegoActorSys *actorSys);
void GTSNEGO_DISP_CreateCursorActor(struct GtsnegoActorSys *actorSys);
void GTSNEGO_DISP_SetCursorState(struct GtsnegoActorSys *actorSys, void *taskMenuWin, u32 position);
extern const Halfwords d_021D8904;
extern const u16 d_021D8B40[];
extern const char d_021D8B50[];
extern const u32 d_021D88D0[];
extern const u8 d_021D88D8[];
extern const u8 d_021D88C8[];
extern NetCommandEntry d_021D88EC[];
extern const char d_021D8BC8[];
extern const u8 ov_id[];
extern const struct DispVram d_021D8B98;
extern const u32 d_021D8974[];
extern struct DispConfig d_021D8B60;
extern const struct BgTemplate d_021D89B0[8];
extern const Word d_021D8920,d_021D891C,d_021D8918;
extern const GtsnegoDispPair d_021D895C,d_021D896C,d_021D894C,d_021D8954,d_021D8944,d_021D8964;
extern const Data d_021D8990;
extern const GtsnegoDispEntry gGtsnegoEntryTable[];

void GTSNEGO_DISP_SetCallback(void **slot, void *callback) { *slot=callback; }

void GTSNEGO_DISP_SetStateCallback(void *dispCtx, void *callback, int line) { GTSNEGO_DISP_SetCallback(dispCtx, callback); }

void GTSNEGO_DISP_OnTradeSync(u32 netId,int size,const void *data,struct GtsnegoDispCtx *dispCtx,struct GFLNetHandle *netHandle) { struct GtsnegoParentCtx *q; q=dispCtx->parentCtx; if(netHandle==GFL_NET_HANDLE_GetCurrentHandle() && netId!=GFL_NET_GetHandleNetID((GFLNetHandle *)(struct Link *)GFL_NET_HANDLE_GetCurrentHandle())) MI_CpuCopy8(data,&q->partnerRowA,8); }

void GTSNEGO_DISP_OnStatusSync(u32 netId,int size,const void *data,struct GtsnegoDispCtx *dispCtx,struct GFLNetHandle *netHandle) { struct GtsnegoParentCtx *q; q=dispCtx->parentCtx; if(netHandle==GFL_NET_HANDLE_GetCurrentHandle() && netId!=GFL_NET_GetHandleNetID((GFLNetHandle *)(struct Link *)GFL_NET_HANDLE_GetCurrentHandle())) MI_CpuCopy8(data,q->partnerStatus,MYSTATUS_GetSize()); }

void GTSNEGO_DISP_OnRecordSync(u32 netId,int size,const void *data,struct GtsnegoDispCtx *dispCtx,struct GFLNetHandle *netHandle) { if(netHandle==GFL_NET_HANDLE_GetCurrentHandle() && netId!=GFL_NET_GetHandleNetID((GFLNetHandle *)(struct Link *)GFL_NET_HANDLE_GetCurrentHandle())) MI_CpuCopy8(data,&dispCtx->partnerRecord,12); }

/*
 * extent: existing matched followers 021D435C, 021D437C, 021D439C remain separate.
 */
int GTSNEGO_DISP_StartTrade(int choice, struct GtsnegoDispCtx *dispCtx)
{
    dispCtx->tradeMode = choice;
    UI_SetInputMode(1);
    if (dispCtx->cannotTrade == 1) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        return 1;
    }
    if (choice == 0) {
        dispCtx->partyCursor = 0;
        GTSNEGO_DISP_SetCursorState(dispCtx->actorSys, dispCtx->tooltipWin, 0);
        GTSNEGO_DISP_SelectParty(dispCtx, dispCtx->partyCursor);
        GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_OnPartySelected, 0x177);
    } else {
        dispCtx->partyCursor = 1;
        GTSNEGO_DISP_SetCursorState(dispCtx->actorSys, dispCtx->tooltipWin, 1);
        GTSNEGO_DISP_SelectParty(dispCtx, dispCtx->partyCursor);
        GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_OnPartySelected, 0x17e);
    }
    return 1;
}

/*
 * follower: separately filed 021D437C.
 */
void GTSNEGO_DISP_CycleRowB(int delta, struct GtsnegoDispCtx *dispCtx) {
    dispCtx->rowBIndex+=delta;
    if(dispCtx->rowBIndex>=5) dispCtx->rowBIndex=0;
    else if(dispCtx->rowBIndex<0) dispCtx->rowBIndex=4;
}

/*
 * follower: separately filed 021D439C.
 */
void GTSNEGO_DISP_CycleRowC(int delta, struct GtsnegoDispCtx *dispCtx) {
    dispCtx->rowCIndex+=delta;
    if(dispCtx->rowCIndex>=5) dispCtx->rowCIndex=0;
    else if(dispCtx->rowCIndex<0) dispCtx->rowCIndex=4;
}

void GTSNEGO_DISP_CycleRowA(int delta, struct GtsnegoDispCtx *dispCtx) {
    dispCtx->rowAIndex+=delta;
    if(dispCtx->rowAIndex>=4) dispCtx->rowAIndex=0;
    else if(dispCtx->rowAIndex<0) dispCtx->rowAIndex=3;
}

int GTSNEGO_DISP_MoveRowCursor(int selection, struct GtsnegoDispCtx *dispCtx) {
    int result=0;
    switch(selection) {
    case 0:GTSNEGO_DISP_CycleRowA(-1,dispCtx);result=2;GTSNEGO_MSG_RedrawRowA((dispCtx->msgCtx),dispCtx->rowAIndex);break;
    case 1:GTSNEGO_DISP_CycleRowA(1,dispCtx);result=2;GTSNEGO_MSG_RedrawRowA((dispCtx->msgCtx),dispCtx->rowAIndex);break;
    case 2:GTSNEGO_DISP_CycleRowB(-1,dispCtx);result=3;GTSNEGO_MSG_RedrawRowB((dispCtx->msgCtx),dispCtx->rowBIndex);break;
    case 3:GTSNEGO_DISP_CycleRowB(1,dispCtx);result=3;GTSNEGO_MSG_RedrawRowB((dispCtx->msgCtx),dispCtx->rowBIndex);break;
    case 4:GTSNEGO_DISP_CycleRowC(-1,dispCtx);result=4;GTSNEGO_MSG_RedrawRowC((dispCtx->msgCtx),dispCtx->rowCIndex);break;
    case 5:GTSNEGO_DISP_CycleRowC(1,dispCtx);result=4;GTSNEGO_MSG_RedrawRowC((dispCtx->msgCtx),dispCtx->rowCIndex);break;
    }
    if(selection>=0 && selection<=5) {GFL_USE_PlaySeDefaultVolume(0x548);GTSNEGO_MSG_SetActorMode((dispCtx->actorSys),selection);}
    return result;
}

int GTSNEGO_DISP_OnRowCursorMoved(int selection,struct GtsnegoDispCtx *dispCtx) { int result; if(*(struct ClactActor * *)&dispCtx->tooltipWin) APP_TASKMENU_WIN_SetActive((struct TaskMenuWin *)(*(struct ClactActor * *)&dispCtx->tooltipWin),0); result=GTSNEGO_DISP_MoveRowCursor(selection,dispCtx); if(result) dispCtx->buttonCursor=result; return 1; }

void GTSNEGO_DISP_MoveCursorVertical(int direction,struct GtsnegoDispCtx *dispCtx) { int v; v=dispCtx->buttonCursor-2; if(dispCtx->buttonCursor>=2 || dispCtx->buttonCursor<=4) GTSNEGO_DISP_MoveRowCursor(direction+v*2,dispCtx); }

void GTSNEGO_DISP_WaitWipeDone(struct GtsnegoDispCtx *dispCtx) { if (WIPE_SYS_EndCheck()) GTSNEGO_DISP_SetStateCallback(dispCtx, 0, 0x213); }

void GTSNEGO_DISP_StartWipe(struct GtsnegoDispCtx *dispCtx) {
    if (--dispCtx->waitFrames<=0) {
        WIPE_SYS_Start(0,0,0,0,6,1,dispCtx->heapId);
        GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_WaitWipeDone, 0x21e);
    }
}

void GTSNEGO_DISP_ShowTradeReady(struct GtsnegoDispCtx *dispCtx)
{
    Halfwords table = d_021D8904;
    const Halfwords *p = &table;
    if (GFL_NET_GetRunState() != 0)
        p = (const Halfwords *)&dispCtx->partnerRecord;
    dispCtx->waitFrames = 0xb4;
    GTSNEGO_MSG_CreateDraw((struct GtsnegoMsgCtx *)(dispCtx->msgCtx), (dispCtx->actorSys));
    GTSNEGO_MSG_PrintDraw((struct GtsnegoMsgCtx *)(dispCtx->msgCtx), (void *)p);
    GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_StartWipe, 0x232);
}

void GTSNEGO_DISP_WaitTradeStart(struct GtsnegoDispCtx *dispCtx)
{
    --dispCtx->waitFrames;
    if (dispCtx->waitFrames == 20)
        GTSNEGO_MSG_PrintWindowB((dispCtx->msgCtx), 0x27);
    if (dispCtx->waitFrames == 0) {
        GTSNEGO_MSG_PrintTooltip((dispCtx->msgCtx), 0x23);
        GTSNEGO_MSG_DeleteEntryWindow((struct GtsnegoMsgCtx *)(dispCtx->msgCtx));
        GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_ShowTradeReady, 0x241);
    }
}

void GTSNEGO_DISP_ShowTradeConfirm(struct GtsnegoDispCtx *dispCtx)
{
    struct GtsnegoParentCtx *parentCtx = dispCtx->parentCtx;
    void *value;
    int tradeCount = 2;
    if (GFL_NET_GetRunState() == 0) {
        value = GAME_DATA_GetMyStatus((void *)(parentCtx->gameData));
    } else {
        value = parentCtx->partnerStatus;
        tradeCount = dispCtx->partnerRecord.tradeCount;
        parentCtx->recentIds[parentCtx->recentIdCount] = MYSTATUS_GetId((struct MyStatus *)value);
        parentCtx->recentIdCount = parentCtx->recentIdCount + 1;
        if (parentCtx->recentIdCount >= 100)
            parentCtx->recentIdCount = 0;
    }
    GTSNEGO_MSG_PrintSummary((dispCtx->msgCtx), (void *)value, tradeCount);
    GTSNEGO_MSG_SetIdleAnim((struct GtsnegoActorSys *)(dispCtx->actorSys), MYSTATUS_GetTrainerView((struct MyStatus *)value));
    dispCtx->waitFrames = 0xb4;
    GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_WaitTradeStart, 0x265);
}

void GTSNEGO_DISP_ConfirmStatus(struct GtsnegoDispCtx *dispCtx)
{
    int ready = 0;
    void *value = dispCtx->parentCtx->partnerStatus;
    int active;
    void *message;
    void *text;
    int result;
    active = DWC_CheckProfanityProcess() == 2;
    if (active)
        ready = dispCtx->profanity.result > 0;
    if (active) {
        if (ready) {
            message = MSGDATA_CreateFromArchive(0, 2, 0x51, 0x1f);
            text = MSGDATA_AllocString(message, MSG_PROFANITY_NOTICE);
            MSGDATA_Delete(message);
            MYSTATUS_NameFromStrbuf((u16 *)value, text);
            STRBUF_Delete(text);
        }
        MYSTATUS_Copy((void *)value, GAME_DATA_GetMyStatusPlayer((struct GameData *)(dispCtx->gameData), 1 - GFL_NET_SYSTEM_GetCurrentAid()));
        result = MYSTATUS_GetId((struct MyStatus *)value);
        MET_TRAINERS_Insert(MET_TRAINERS_GetFromSave((void *)(dispCtx->saveControl)), result);
        GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_ShowTradeConfirm, 0x283);
    }
}

/*
 * evidence: 020399A8's r0 is consumed by 02039CB4 despite its void definition.
 * evidence: 020458F8 returns ldrh r0; this caller uses full-word r0+1 without narrowing.
 */
void GTSNEGO_DISP_PrepareTrade(struct GtsnegoDispCtx *dispCtx)
{
    void *str;
    u16 *chars;
    u32 i;
    void *value = dispCtx->parentCtx->partnerStatus;
    if (GFL_NET_HANDLE_IsTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(), 3, 0x22) != 0) {
        str = MYSTATUS_CreateNameStrbuf(value, 31);
        MI_CpuFill8(&dispCtx->profanity, 0, sizeof(dispCtx->profanity));
        dispCtx->profanity.maxChars = 31;
        chars = STRBUF_GetChars(str);
        for (i = 0; i < STRBUF_GetLength(str) + 1u; i++) {
            u16 ch = chars[i];
            if (ch == STRBUF_GetEosChar()) dispCtx->profanity.name[i] = 0;
            else dispCtx->profanity.name[i] = ch;
        }
        dispCtx->profanity.words = dispCtx->profanity.name;
        dispCtx->profanity.result = 0;
        DWC_CheckProfanityExAsync(&dispCtx->profanity.words, 1, 0, 0, dispCtx->profanity.flags, &dispCtx->profanity.result, 128);
        STRBUF_Delete(str);
        GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_ConfirmStatus, 0x29c);
    }
}

void GTSNEGO_DISP_StartSync(struct GtsnegoDispCtx *dispCtx) { GFL_NET_HANDLE_SetTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),3,34); GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_PrepareTrade, 0x2ac); }

void GTSNEGO_DISP_SendStatus(struct GtsnegoDispCtx *dispCtx) { void *link; int n; link=GFL_NET_HANDLE_GetCurrentHandle(); n=MYSTATUS_GetSize(); if (GFL_NET_SendToHandle(link,0x2201,n,dispCtx->parentCtx->myStatus)) GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_StartSync, 0x2bd); }

void GTSNEGO_DISP_SendRecord(struct GtsnegoDispCtx *dispCtx) { if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0x2202,12,(const void *)&dispCtx->myRecord)) GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_SendStatus, 0x2cf); }

void GTSNEGO_DISP_SendHandshake(struct GtsnegoDispCtx *dispCtx)
{
    if (GFL_NET_GetRunState() == 0) {
        GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_ShowTradeConfirm, 0x2df);
        return;
    }
    if (GFL_NET_HANDLE_IsTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(), 2, 0x22) != 0) {
        if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x2200, 8, (const void *)&dispCtx->parentCtx->rowAIndex) != 0)
            GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_SendRecord, 0x2e7);
    }
}

void GTSNEGO_DISP_WaitNegotiation(struct GtsnegoDispCtx *dispCtx)
{
    struct GtsnegoParentCtx *parentCtx;
    void *value;
    if (GTSNEGO_MSG_UpdatePrintStream((struct GtsnegoMsgCtx *)(dispCtx->msgCtx))) {
        if (GFL_NET_GetRunState() == 0) {
            GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_SendHandshake, 0x2fe);
            return;
        }
        if (dispCtx->waitFrames > 0) {
            dispCtx->waitFrames = dispCtx->waitFrames - 1;
            return;
        }
        if (GFL_NET_HANDLE_GetNegotiationNum() == 2) {
            parentCtx = dispCtx->parentCtx;
            value = GREETING_SAVEDATA_GetFromSaveThunk(dispCtx->saveControl);
            parentCtx->rowAIndex = dispCtx->rowAIndex;
            parentCtx->rowBIndex = dispCtx->rowBIndex;
            GREETING_SAVEDATA_GetSentence((struct QuadRecord *)value, 0, (struct QuadRecord *)&dispCtx->myRecord);
            dispCtx->myRecord.tradeCount = TRADE_HISTORY_GetTradeCount(GAME_DATA_GetTradeHistory((struct GameData *)((void **)(dispCtx->gameData))));
            GFL_NET_HANDLE_SetTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(), 2, 0x22);
            GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_SendHandshake, 0x314);
        }
    }
}

void GTSNEGO_DISP_CheckNegotiation(struct GtsnegoDispCtx *dispCtx)
{
    if (GFL_NET_GetRunState() == 0) {
        GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_WaitNegotiation, 0x31d);
        return;
    }
    if (GFL_NET_HANDLE_GetNegotiationNum() != 0 && GFL_NET_HANDLE_CheckNegotiation() != 0)
        GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_WaitNegotiation, 0x322);
}

void GTSNEGO_DISP_WaitPartnerReady(struct GtsnegoDispCtx *dispCtx)
{
    if (GTSNEGO_MSG_UpdatePrintStream((struct GtsnegoMsgCtx *)(dispCtx->msgCtx)) != 0) {
        if (dispCtx->waitFrames > 0) {
            dispCtx->waitFrames = dispCtx->waitFrames - 1;
            return;
        }
        if (GFL_NET_SYSTEM_GetCurrentAid() != 0) {
            if (GFL_NET_HANDLE_CheckNegotiation() != 0) {
                dispCtx->waitFrames = 0xb4;
                GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_WaitNegotiation, 0x33f);
                return;
            }
        } else {
            dispCtx->waitFrames = 0xb4;
            GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_CheckNegotiation, 0x344);
        }
    }
}

/*
 * Blocker resolved: the call to GFL_NET_STATE_GetWifiState (site +0050) was the only
 *          unresolved relocation.  It is an unlabelled ARM leaf in the ARM9
 *          image; it was matched in arm9 (src/matched/GFL_NET_STATE_GetWifiState.c, shard
 *          pkt_0203C3EC) so `attest_matched` now resolves the BL field.  All
 *          17 relocations and all 152 bytes agree.
 */
void GTSNEGO_DISP_HandleTradeKeys(struct GtsnegoDispCtx *dispCtx)
{
    GTSNEGO_MSG_UpdateButtons((struct GtsnegoMsgCtx *)(dispCtx->msgCtx));
    if (KEY_GetTrg() == 2) {
        GTSNEGO_MSG_SetDecide((struct GtsnegoMsgCtx *)(dispCtx->msgCtx));
        if (GFL_NET_GetRunState() != 0)
            GFL_NET_STATE_WifiDisconnect(1);
        UI_SetInputMode(0);
        GFL_USE_PlaySeDefaultVolume(0x551);
        GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_OnDisconnect, 0x360);
    }
    if (GFL_NET_GetRunState() == 0) {
        if (KEY_GetTrg() != 1)
            return;
    } else {
        if (GFL_NET_STATE_GetWifiState() != 1)
            return;
        GFL_NET_SetAutoExit(1);
        GFL_NET_SetLoginOption(1);
    }
    GTSNEGO_MSG_DeleteWindow((struct GtsnegoMsgCtx *)(dispCtx->msgCtx));
    GTSNEGO_MSG_PrintWindowB((dispCtx->msgCtx), 0x10);
    dispCtx->waitFrames = 0xb4;
    GTSNEGO_MSG_DeleteConfirmWindow((dispCtx->msgCtx));
    GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_WaitPartnerReady, 0x377);
}

int GTSNEGO_DISP_ScoreMatch(int matchData, void *param)
{
    struct GtsnegoDispCtx *dispCtx = param;
    int mode;
    int x;
    int y;
    int score = -1;
    int id;
    int group;
    int i;
    struct GtsnegoParentCtx *parentCtx = dispCtx->parentCtx;
    mode = DWC_GetMatchIntValue(matchData, (char *)&dispCtx->matchKeys[2].detail, -1);
    x = DWC_GetMatchIntValue(matchData, (char *)&dispCtx->matchKeys[4].detail, -1);
    y = DWC_GetMatchIntValue(matchData, (char *)&dispCtx->matchKeys[3].detail, -1);
    id = DWC_GetMatchIntValue(matchData, (char *)&dispCtx->matchKeys[0].detail, 0);
    group = DWC_GetMatchIntValue(matchData, (char *)&dispCtx->matchKeys[7].detail, 0);
    if (dispCtx->tradeMode == 1) {
        if (mode == 4) {
            if (dispCtx->selectedListIndex == -1) {
                if (TRADE_HISTORY_HasPartner(TRADE_HISTORY_GetFromSave(dispCtx->saveControl), id) != 0)
                    score = 100;
            } else {
                if (dispCtx->selectedPartnerId == id) score = 100;
            }
        } else {
            if (group == MYSTATUS_GetId((struct MyStatus *)GAME_DATA_GetMyStatus((void *)(parentCtx->gameData)))) {
                if (dispCtx->selectedListIndex == -1) {
                    if (TRADE_HISTORY_HasPartner(TRADE_HISTORY_GetFromSave(dispCtx->saveControl), id) != 0)
                        score = 100;
                } else {
                    if (dispCtx->selectedPartnerId == id) score = 100;
                }
            }
        }
    } else {
        if (dispCtx->rowAIndex == mode) {
            if (dispCtx->rowBIndex == x) score += 20;
            else if (dispCtx->rowBIndex == 0 || x == 0) score += 10;
            else score -= 40;
            if (dispCtx->rowCIndex == y) score += 20;
            else if (y == 0 || dispCtx->rowCIndex == 0) score += 10;
            else score -= 40;
            for (i = 0; i < 100; i++) {
                if (id == parentCtx->recentIds[i] && id != 0) {
                    score = 0;
                    break;
                }
            }
        }
    }
    return score;
}

void GTSNEGO_DISP_StartMatchmaking(struct GtsnegoDispCtx *dispCtx)
{
    u32 values[8];
    void *entry;
    int i;
    MatchFilterRecord *record;
    if (GTSNEGO_MSG_UpdatePrintStream(dispCtx->msgCtx)) {
        if (GFL_NET_GetRunState() == 0) {
            GTSNEGO_MSG_CreateConfirmUi(dispCtx->msgCtx, GTSNEGO_DISP_OnDisconnectCallback, dispCtx);
            GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_HandleTradeKeys, 0x3ea);
            return;
        }
        GFL_NET_SetWaitMode(0);
        WIFILIST_CreateExchangeToken((void *)(dispCtx->wifiList), values);
        values[0] = dispCtx->myTrainerId;
        values[1] = dispCtx->tradeMode;
        values[2] = dispCtx->rowAIndex;
        values[3] = dispCtx->rowBIndex;
        values[4] = dispCtx->rowCIndex;
        values[5] = PM_LANG_VERSION_KEY;
        values[6] = 1;
        values[7] = 0;
        if (dispCtx->tradeMode == 1) {
            if (dispCtx->selectedListIndex == -1)
                values[2] = 4;
            else {
                entry = GTSNEGO_DISP_GetEntry(dispCtx->gameData, dispCtx->selectedListIndex);
                values[7] = MYSTATUS_GetId(entry);
                dispCtx->selectedPartnerId = MYSTATUS_GetId(entry);
            }
        }
        for (i = 0; i < 8; i++) {
            record = dispCtx->matchKeys + i;
            MI_CpuCopy8(d_021D8B40 + i, &record->detail, 2);
            record->value = values[i];
            record->kind = DWC_AddMatchKeyInt(record->kind, (char *)(&record->detail), (int *)record);
        }
        STD_TSPrintf(dispCtx->matchFilter, d_021D8B50, dispCtx->tradeMode, 1);
        if (DWC_RAP_StartMatchWithFilter(dispCtx->matchFilter, 2, GTSNEGO_DISP_ScoreMatch, dispCtx)) {
            GFL_NET_STATE_WifiEnterFriendMatch();
            DWC_RAP_SetVchatEnabled(0);
            GTSNEGO_MSG_CreateConfirmUi(dispCtx->msgCtx, GTSNEGO_DISP_OnDisconnectCallback, dispCtx);
            GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_HandleTradeKeys, 0x41d);
            return;
        }
        GFL_NET_STATE_SetError(0, 0, 0, 0x3f1);
    }
}

void GTSNEGO_DISP_OnMenuCallback(u32 selection,s32 event,void *arg) { struct GtsnegoDispCtx *dispCtx = arg; if (event==0 && dispCtx->rowInputCallback) { GTSNEGO_DISP_SetCursorState(dispCtx->actorSys,dispCtx->tooltipWin,9); UI_SetInputMode(1); if (dispCtx->rowInputCallback(selection,dispCtx)==0) return; } }

void GTSNEGO_DISP_OnConfirmDone(struct GtsnegoDispCtx *dispCtx)
{
    if (APP_TASKMENU_WIN_IsFinish(dispCtx->tooltipWin)) {
        APP_TASKMENU_WIN_Delete(dispCtx->tooltipWin);
        dispCtx->tooltipWin = 0;
        BG_SYS_MarkTileDirty(5);
        GTSNEGO_MSG_PrintWindow(dispCtx->msgCtx, 14);
        GTSNEGO_MSG_CreateIdleUi(dispCtx->actorSys);
        GTSNEGO_MSG_PrintStatus(dispCtx->msgCtx, 13);
        GTSNEGO_DISP_SetTradePalette(dispCtx->actorSys, 1, 2);
        dispCtx->parentCtx->screenState = 2;
        GTSNEGO_DISP_SetCursorState(dispCtx->actorSys, 0, 9);
        GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_StartMatchmaking, 0x460);
    }
}

void GTSNEGO_DISP_HandleConfirmKeys(struct GtsnegoDispCtx *dispCtx)
{
    int changed = 0;
    int done = 0;
    u8 *touchbar = (u8 *)GTSNEGO_DISP_GetTouchbar(dispCtx->actorSys);
    if (GTSNEGO_MSG_UpdatePrintStream((struct GtsnegoMsgCtx *)(dispCtx->msgCtx))) {
        if (TOUCHBAR_IsBusy((TouchBar *)touchbar) == 0) {
            GTSNEGO_MSG_UpdateButtons((struct GtsnegoMsgCtx *)(dispCtx->msgCtx));
            if (KEY_GetTrg() != 0 && UI_GetInputMode() == 1) {
                GTSNEGO_DISP_SetCursorState(dispCtx->actorSys, dispCtx->tooltipWin, dispCtx->buttonCursor);
                UI_SetInputMode(changed);
                return;
            }
            if (KEY_GetTrg() == 0x20) GTSNEGO_DISP_MoveCursorVertical(0, dispCtx);
            if (KEY_GetTrg() == 0x10) GTSNEGO_DISP_MoveCursorVertical(1, dispCtx);
            if (KEY_GetTrg() == 0x40) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                changed = 1;
                if (dispCtx->buttonCursor != 2) --dispCtx->buttonCursor;
            }
            if (KEY_GetTrg() == 0x80) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                changed = 1;
                if (dispCtx->buttonCursor != 5) ++dispCtx->buttonCursor;
            }
            if (KEY_GetTrg() == 1 && dispCtx->buttonCursor == 5) {
                GFL_USE_PlaySeDefaultVolume(0x54c);
                GTSNEGO_MSG_SetCursorAnimSeq(dispCtx->actorSys, dispCtx->buttonCursor);
                APP_TASKMENU_WIN_SetDecide(dispCtx->tooltipWin, 1);
                GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_OnConfirmDone, 0x4ca);
                return;
            }
            if (changed)
                GTSNEGO_DISP_SetCursorState(dispCtx->actorSys, dispCtx->tooltipWin, dispCtx->buttonCursor);
            if (TOUCHPANEL_HitTrg((const TouchHitTable *)d_021D88D0) == 0) {
                UI_SetInputMode(1);
                GFL_USE_PlaySeDefaultVolume(0x54c);
                APP_TASKMENU_WIN_SetDecide(dispCtx->tooltipWin, 1);
                GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_OnConfirmDone, 0x4f2);
                return;
            }
        }
        TOUCHBAR_Update((TouchBar *)((struct TouchBar *)GTSNEGO_DISP_GetTouchbar(dispCtx->actorSys)));
        if (TOUCHBAR_GetPressedButtonIdIfDone((TouchBar *)((u8 *)GTSNEGO_DISP_GetTouchbar(dispCtx->actorSys))) == 1) done = 1;
        if (done) {
            int zero = 0;
            BG_SYS_SetPlaneVisible(4, 0);
            GTSNEGO_DISP_SetCursorState(dispCtx->actorSys, dispCtx->tooltipWin, 9);
            GTSNEGO_MSG_DeleteButtonsKeep(dispCtx->msgCtx);
            GTSNEGO_DISP_ResetActors(dispCtx->actorSys);
            APP_TASKMENU_WIN_Delete(dispCtx->tooltipWin);
            *(int *)&dispCtx->tooltipWin = zero;
            BG_SYS_MarkTileDirty(5);
            GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_ShowPartySelect, 0x50b);
        }
    }
}

void GTSNEGO_DISP_CreateConfirmUi(struct GtsnegoDispCtx *dispCtx)
{
    dispCtx->tradeMode = 0;
    TOUCHBAR_SetAllButtonsVisible((TouchBar *)((u8 *)GTSNEGO_DISP_GetTouchbar(dispCtx->actorSys)), 1);
    GTSNEGO_MSG_ClearRows(dispCtx->msgCtx);
    GTSNEGO_DISP_RedrawActors(dispCtx->actorSys);
    dispCtx->rowInputCallback = GTSNEGO_DISP_OnRowCursorMoved;
    GTSNEGO_MSG_CreateListUi(dispCtx->msgCtx, GTSNEGO_DISP_OnMenuCallback, dispCtx, dispCtx->rowAIndex, dispCtx->rowBIndex, dispCtx->rowCIndex);
    GTSNEGO_MSG_PrintWindow(dispCtx->msgCtx, 20);
    dispCtx->tooltipWin = GTSNEGO_MSG_CreateTooltip(dispCtx->msgCtx, 18);
    if (UI_GetInputMode() == 0) {
        GTSNEGO_DISP_SetCursorState(dispCtx->actorSys, 0, dispCtx->buttonCursor);
        if (dispCtx->buttonCursor == 5)
            APP_TASKMENU_WIN_SetActive(dispCtx->tooltipWin, 1);
    } else {
        GTSNEGO_DISP_SetCursorState(dispCtx->actorSys, 0, 9);
    }
    BG_SYS_MarkTileDirty(6);
    GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_HandleConfirmKeys, 0x537);
}

void *GTSNEGO_DISP_GetEntry(void **list,int index) { int n; n=TRADE_HISTORY_GetPartnerCount((struct TradeHistory *)GAME_DATA_GetTradeHistory((struct GameData *)list)); if (index>=n || index<0) return 0; return TRADE_HISTORY_GetPartner((struct TradeHistory *)GAME_DATA_GetTradeHistory((struct GameData *)list),index); }

void *GTSNEGO_DISP_GetEntryClamped(void **list,int index) { int n; n=TRADE_HISTORY_GetPartnerCount(GAME_DATA_GetTradeHistory((struct GameData *)list)); if (index<0) index=0; if (index>=n) index=n-1; return TRADE_HISTORY_GetPartner(GAME_DATA_GetTradeHistory((struct GameData *)list),index); }

/*
 * Addresses are Black-image addresses.
 */
void GTSNEGO_DISP_ShowSubPlanes(struct GtsnegoDispCtx *dispCtx)
{
    GTSNEGO_DISP_ShowPartySelect(dispCtx);
    BG_SYS_SetSubVisiblePlanes(0x1f);
}

void GTSNEGO_DISP_Teardown(struct GtsnegoDispCtx *dispCtx) { GTSNEGO_MSG_Teardown(dispCtx->actorSys); GTSNEGO_MSG_DeleteAll(dispCtx->msgCtx); GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_ShowSubPlanes, 0x5c5); }

void GTSNEGO_DISP_OnDisconnect(struct GtsnegoDispCtx *dispCtx)
{
    if (GTSNEGO_MSG_IsConfirmFinished(dispCtx->msgCtx)) {
        BG_SYS_SetSubVisiblePlanes(8);
        GTSNEGO_MSG_DeleteButtonsKeep(dispCtx->msgCtx);
        GTSNEGO_DISP_ResetActors(dispCtx->actorSys);
        GTSNEGO_DISP_SetTradePalette(dispCtx->actorSys, 0, 0);
        GTSNEGO_DISP_SetCursorState(dispCtx->actorSys, 0, 9);
        BG_SYS_MarkTileDirty(5);
        if (dispCtx->tradeMode == 1) {
            BG_SYS_SetPlaneVisible(4, 0);
            GTSNEGO_MSG_TeardownTileRows(dispCtx->actorSys);
        }
        GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_Teardown, 0x5dd);
    }
}

void GTSNEGO_DISP_OnDisconnectCallback(u32 unused, s32 buttonIndex, void *arg)
{
    struct GtsnegoDispCtx *dispCtx = arg;
    if (buttonIndex == 0 && *(void **)dispCtx == GTSNEGO_DISP_HandleTradeKeys) {
        GTSNEGO_MSG_SetDecide((struct GtsnegoMsgCtx *)(dispCtx->msgCtx));
        GFL_NET_STATE_WifiDisconnect(1);
        UI_SetInputMode(1);
        GFL_USE_PlaySeDefaultVolume(0x551);
        GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_OnDisconnect, 0x5f5);
    }
}

void GTSNEGO_DISP_CreateExitTooltip(struct GtsnegoDispCtx *dispCtx) { dispCtx->tooltipWin=GTSNEGO_MSG_CreateTooltip(dispCtx->msgCtx,44); GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_HandleListInput, 0x5ff); }

void GTSNEGO_DISP_OnExitMenuDone(struct GtsnegoDispCtx *dispCtx)
{
    int state;
    if (APP_TASKMENU_IsFinish(dispCtx->taskMenu)) {
        int zero;
        state = APP_TASKMENU_GetCursorPos(dispCtx->taskMenu);
        GTSNEGO_MSG_CloseMenu(*(struct TaskMenuWork **)&dispCtx->taskMenu);
        zero = 0;
        *(int *)&dispCtx->taskMenu = zero;
        TOUCHBAR_SetButtonVisible((TouchBar *)GTSNEGO_DISP_GetTouchbar(dispCtx->actorSys), 1, 1);
        switch (state) {
        case 0:
            GTSNEGO_MSG_PrintWindow(dispCtx->msgCtx, 0xe);
            GTSNEGO_MSG_CreateIdleUi(dispCtx->actorSys);
            GTSNEGO_MSG_PrintStatus(dispCtx->msgCtx, 0xd);
            dispCtx->rowAIndex = zero;
            dispCtx->rowBIndex = zero;
            dispCtx->rowCIndex = zero;
            dispCtx->parentCtx->screenState = 3;
            GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_StartMatchmaking, 0x614);
            return;
        case 1:
            GTSNEGO_DISP_SetTradePalette(dispCtx->actorSys, zero, zero);
            GTSNEGO_MSG_PrintWindow(dispCtx->msgCtx, 0x13);
            if (UI_GetInputMode() == 0)
                GTSNEGO_DISP_SetCursorState(dispCtx->actorSys, 0, dispCtx->listCursorRow);
            else
                GTSNEGO_DISP_SetCursorState(dispCtx->actorSys, 0, 9);
            GTSNEGO_MSG_RestartIconAnim(dispCtx->actorSys, 1);
            GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_CreateExitTooltip, 0x620);
            break;
        }
    }
}

void GTSNEGO_DISP_OpenExitMenu(struct GtsnegoDispCtx *dispCtx)
{
    if (GTSNEGO_MSG_UpdatePrintStream((struct GtsnegoMsgCtx *)dispCtx->msgCtx)) {
        TOUCHBAR_SetButtonVisible((TouchBar *)GTSNEGO_DISP_GetTouchbar(dispCtx->actorSys), 1, 0);
        dispCtx->taskMenu = GTSNEGO_MSG_OpenMenuB(dispCtx->msgCtx, 1);
        GTSNEGO_DISP_SetTradePalette(dispCtx->actorSys, 1, 1);
        GTSNEGO_MSG_RestartIconAnim(dispCtx->actorSys, 0);
        GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_OnExitMenuDone, 0x634);
    }
}

/*
 * lever: The caller has no halfword truncation before GTSNEGO_MSG_PrintWindow;
 * widen its copied u16 argument to int. Explicit calls in both branches
 * hoist the shared p+64 load; a ternary places it after the selection.
 */
void GTSNEGO_DISP_ShowListMessage(struct GtsnegoDispCtx *dispCtx) { if (dispCtx->selectedListIndex==-1) GTSNEGO_MSG_PrintWindow((struct GtsnegoMsgCtx *)(dispCtx->msgCtx),45); else GTSNEGO_MSG_PrintWindow((struct GtsnegoMsgCtx *)(dispCtx->msgCtx),31); GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_OpenExitMenu, 0x646); }

void GTSNEGO_DISP_EndList(struct GtsnegoDispCtx *dispCtx) { BG_SYS_SetPlaneVisible(4,0); GTSNEGO_MSG_TeardownTileRows(dispCtx->actorSys); GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_ShowPartySelect, 0x64e); }

/*
 * extent: two zero padding bytes at 0x021D5282 precede labelled 0x021D5284.
 */
int GTSNEGO_DISP_ListCursorUp(struct GtsnegoDispCtx *dispCtx)
{
    int result = GTSNEGO_MSG_CursorUp(dispCtx->actorSys, &dispCtx->list.count);
    switch (result) {
    case 0: break;
    case 1:
        if (dispCtx->listCursorRow != 6)
            (dispCtx->listCursorRow)--;
        break;
    case 2: {
        int index;
        GTSNEGO_MSG_SetScrollState(dispCtx->actorSys, 1);
        index = dispCtx->list.scrollTop - 1;
        if (index >= 0)
            GTSNEGO_MSG_PrintListEntryN(dispCtx->msgCtx, dispCtx->gameData, index);
        break;
    }
    }
    return result;
}

int GTSNEGO_DISP_ListCursorDown(struct GtsnegoDispCtx *dispCtx)
{
    int result = GTSNEGO_MSG_CursorDown(dispCtx->actorSys, &dispCtx->list.count);
    switch (result) {
    case 0: break;
    case 1:
        if (dispCtx->listCursorRow != 8)
            (dispCtx->listCursorRow)++;
        break;
    case 2:
        GTSNEGO_MSG_SetScrollState(dispCtx->actorSys, 2);
        GTSNEGO_MSG_PrintListEntryAt(dispCtx->msgCtx, dispCtx->gameData, dispCtx->list.scrollTop + 2);
        break;
    }
    return result;
}

void GTSNEGO_DISP_OnListConfirmDone(struct GtsnegoDispCtx *dispCtx)
{
    if (APP_TASKMENU_WIN_IsFinish(dispCtx->tooltipWin)) {
        APP_TASKMENU_WIN_Delete(dispCtx->tooltipWin);
        dispCtx->tooltipWin = 0;
        dispCtx->selectedListIndex = -1;
        GTSNEGO_DISP_SetCursorState(dispCtx->actorSys, 0, 9);
        BG_SYS_MarkTileDirty(5);
        GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_ShowListMessage, 0x6ba);
    }
}

void GTSNEGO_DISP_DeleteMenuWindow(struct GtsnegoDispCtx *dispCtx)
{
    if (dispCtx->tooltipWin) {
        APP_TASKMENU_WIN_Delete(dispCtx->tooltipWin);
        BG_SYS_MarkTileDirty(5);
        dispCtx->tooltipWin = 0;
    }
}

void GTSNEGO_DISP_HandleListInput(struct GtsnegoDispCtx *dispCtx)
{
    int out;
    sptr touchbar;
    int acc = 0;
    int i;
    int sel;
    int x, y;
    out = 0;
    touchbar = (sptr)GTSNEGO_DISP_GetTouchbar(dispCtx->actorSys);
    if (GTSNEGO_MSG_UpdatePrintStream((struct GtsnegoMsgCtx *)dispCtx->msgCtx) == 0)
        return;
    if (TOUCHBAR_IsBusy((TouchBar *)touchbar) != 0)
        goto end;
    touchbar = GTSNEGO_MSG_StepScroll(dispCtx->actorSys, &out);
    if (out == 1) {
        GTSNEGO_MSG_DrawTileRows((struct GtsnegoActorSys *)dispCtx->actorSys, dispCtx->gameData, dispCtx->list.scrollTop - 2);
        GTSNEGO_MSG_ShiftListUp(dispCtx->msgCtx);
        GTSNEGO_MSG_ScrollListUp(dispCtx->actorSys, GTSNEGO_DISP_GetEntryClamped(dispCtx->gameData, dispCtx->list.scrollTop - 2));
    } else if (out == 2) {
        GTSNEGO_MSG_DrawTileRows((struct GtsnegoActorSys *)dispCtx->actorSys, dispCtx->gameData, dispCtx->list.scrollTop - 2);
        GTSNEGO_MSG_ShiftListDown(dispCtx->msgCtx);
        GTSNEGO_MSG_ScrollListDown(dispCtx->actorSys, GTSNEGO_DISP_GetEntryClamped(dispCtx->gameData, dispCtx->list.scrollTop + 3));
    }
    if (touchbar != 0)
        return;
    if (UI_GetInputMode() == 1 && KEY_GetTrg() != 0) {
        GTSNEGO_DISP_SetCursorState(dispCtx->actorSys, 0, dispCtx->listCursorRow);
        UI_SetInputMode(0);
        return;
    }
    if (KEY_GetRepeat() == 0x100) {
        acc = 0;
        for (i = 0; i < 3; i++) {
            touchbar = GTSNEGO_DISP_ListCursorDown(dispCtx);
            acc |= touchbar;
            GTSNEGO_MSG_ClearScrollState((struct GtsnegoActorSys *)dispCtx->actorSys);
            if (touchbar == 0)
                break;
            if (touchbar == 1) {
                i--;
            } else {
                GTSNEGO_MSG_ScrollAllRows(dispCtx->actorSys, 1);
                GTSNEGO_MSG_DrawTileRows((struct GtsnegoActorSys *)dispCtx->actorSys, dispCtx->gameData, dispCtx->list.scrollTop - 2);
                GTSNEGO_MSG_ShiftListDown(dispCtx->msgCtx);
                GTSNEGO_MSG_ScrollListDown(dispCtx->actorSys, GTSNEGO_DISP_GetEntryClamped(dispCtx->gameData, dispCtx->list.scrollTop + 3));
                GTSNEGO_DISP_SetCursorState(dispCtx->actorSys, 0, dispCtx->listCursorRow);
            }
        }
    }
    if (KEY_GetRepeat() == 0x200) {
        acc = 0;
        for (i = 0; i < 3; i++) {
            touchbar = GTSNEGO_DISP_ListCursorUp(dispCtx);
            acc |= touchbar;
            GTSNEGO_MSG_ClearScrollState((struct GtsnegoActorSys *)dispCtx->actorSys);
            if (touchbar == 0)
                break;
            if (touchbar == 1) {
                i--;
            } else {
                GTSNEGO_DISP_SetCursorState(dispCtx->actorSys, 0, dispCtx->listCursorRow);
                GTSNEGO_MSG_ScrollAllRows(dispCtx->actorSys, 0);
                GTSNEGO_MSG_DrawTileRows((struct GtsnegoActorSys *)dispCtx->actorSys, dispCtx->gameData, dispCtx->list.scrollTop - 2);
                GTSNEGO_MSG_ShiftListUp(dispCtx->msgCtx);
                GTSNEGO_MSG_ScrollListUp(dispCtx->actorSys, GTSNEGO_DISP_GetEntryClamped(dispCtx->gameData, dispCtx->list.scrollTop - 2));
            }
        }
    }
    if (KEY_GetRepeat() == 0x40)
        acc = GTSNEGO_DISP_ListCursorUp(dispCtx);
    if (KEY_GetRepeat() == 0x80)
        acc = GTSNEGO_DISP_ListCursorDown(dispCtx);
    if (acc != 0) {
        GFL_USE_PlaySeDefaultVolume(0x548);
        GTSNEGO_MSG_SetIconY((struct GtsnegoActorSys *)dispCtx->actorSys, dispCtx->list.scrollTop + dispCtx->listCursorRow - 6, dispCtx->list.count);
        GTSNEGO_DISP_SetCursorState(dispCtx->actorSys, 0, dispCtx->listCursorRow);
        return;
    }
    if (KEY_GetTrg() == 1) {
        GFL_USE_PlaySeDefaultVolume(0x54C);
        GTSNEGO_MSG_SetCursorAnimSeq((struct GtsnegoActorSys *)dispCtx->actorSys, dispCtx->listCursorRow);
        dispCtx->selectedListIndex = dispCtx->list.scrollTop + dispCtx->listCursorRow - 6;
        GTSNEGO_DISP_DeleteMenuWindow(dispCtx);
        GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_ShowListMessage, 0x760);
        return;
    }
    if (KEY_GetTrg() == 8) {
        GFL_USE_PlaySeDefaultVolume(0x54C);
        APP_TASKMENU_WIN_SetDecide(dispCtx->tooltipWin, 1);
        GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_OnListConfirmDone, 0x766);
        return;
    }
    sel = TOUCHPANEL_HitTrg((const TouchHitTable *)d_021D88D8);
    switch (sel) {
    case 3:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        APP_TASKMENU_WIN_SetDecide(dispCtx->tooltipWin, 1);
        GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_OnListConfirmDone, 0x770);
        return;
    case 2:
        if (dispCtx->list.count < 3)
            break;
    case 1:
        if (dispCtx->list.count < 2)
            break;
    case 0:
        UI_SetInputMode(1);
        dispCtx->listCursorRow = sel + 6;
        GTSNEGO_DISP_SetCursorState(dispCtx->actorSys, 0, dispCtx->listCursorRow);
        GTSNEGO_MSG_SetCursorAnimSeq((struct GtsnegoActorSys *)dispCtx->actorSys, dispCtx->listCursorRow);
        dispCtx->selectedListIndex = dispCtx->list.scrollTop + dispCtx->listCursorRow - 6;
        GTSNEGO_MSG_SetCursorIndex(dispCtx->actorSys, &dispCtx->list.count, sel);
        GTSNEGO_MSG_SetIconY((struct GtsnegoActorSys *)dispCtx->actorSys, dispCtx->list.scrollTop + dispCtx->listCursorRow - 6, dispCtx->list.count);
        GFL_USE_PlaySeDefaultVolume(0x54C);
        GTSNEGO_DISP_DeleteMenuWindow(dispCtx);
        GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_ShowListMessage, 0x78B);
        return;
    }
    if (TOUCHPANEL_HitCont((const TouchHitTable *)d_021D88C8) != 0)
        goto end;
    if (TOUCHPANEL_GetPointCont((u32 *)(&x), (u32 *)(&y)) == 1) {
        touchbar = GTSNEGO_MSG_SetIconYClamped((struct GtsnegoActorSys *)dispCtx->actorSys, y, dispCtx->list.count);
        if (dispCtx->list.scrollTop != touchbar) {
            dispCtx->list.scrollTop = touchbar;
            GTSNEGO_MSG_PrintListRange(dispCtx->msgCtx, dispCtx->gameData, touchbar - 2);
            GTSNEGO_MSG_FillListRange(dispCtx->actorSys, dispCtx->gameData, dispCtx->list.scrollTop - 2);
            GTSNEGO_MSG_DrawTileRows((struct GtsnegoActorSys *)dispCtx->actorSys, dispCtx->gameData, dispCtx->list.scrollTop - 2);
            GFL_USE_PlaySeDefaultVolume(0x548);
        }
    }
    return;
end:
    TOUCHBAR_Update((TouchBar *)GTSNEGO_DISP_GetTouchbar(dispCtx->actorSys));
    if (TOUCHBAR_GetPressedButtonIdIfDone((TouchBar *)GTSNEGO_DISP_GetTouchbar(dispCtx->actorSys)) == 1) {
        BG_SYS_SetPlaneVisible(4, 0);
        BG_SYS_SetPlaneVisible(6, 0);
        GTSNEGO_DISP_DeleteMenuWindow(dispCtx);
        GTSNEGO_DISP_SetCursorState(dispCtx->actorSys, dispCtx->tooltipWin, 9);
        GTSNEGO_MSG_TeardownActorList(dispCtx->actorSys);
        GTSNEGO_MSG_ClearRows(dispCtx->msgCtx);
        GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_EndList, 0x7AD);
    }
}

void GTSNEGO_DISP_WaitSelectStart(struct GtsnegoDispCtx *dispCtx)
{
    if (GTSNEGO_MSG_UpdatePrintStream(dispCtx->msgCtx)) {
        if (--dispCtx->waitFrames <= 0) {
            GTSNEGO_MSG_PrintWindow((struct GtsnegoMsgCtx *)dispCtx->msgCtx, 0x20);
            TOUCHBAR_SetAllButtonsVisible((TouchBar *)GTSNEGO_DISP_GetTouchbar(dispCtx->actorSys), 1);
            GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_HandlePartyInput, 0x7c7);
            if (UI_GetInputMode() == 0)
                GTSNEGO_DISP_SetCursorState(dispCtx->actorSys, 0, dispCtx->partyCursor);
        }
    }
}

void GTSNEGO_DISP_ShowPokemonList(struct GtsnegoDispCtx *dispCtx)
{
    int flag = 1;
    int n = TRADE_HISTORY_GetPartnerCount(GAME_DATA_GetTradeHistory((struct GameData *)(*(void ** *)&dispCtx->gameData)));
    dispCtx->tradeMode = flag;
    if (n == 0) {
        GTSNEGO_MSG_PrintWindow(dispCtx->msgCtx, 0x1d);
        dispCtx->waitFrames = 0x78;
        GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_WaitSelectStart, 0x7e7);
        return;
    }
    dispCtx->list.count = n;
    GTSNEGO_MSG_PrintWindow(dispCtx->msgCtx, 0x13);
    if (UI_GetInputMode() == 0)
        GTSNEGO_DISP_SetCursorState(dispCtx->actorSys, 0, dispCtx->listCursorRow);
    else
        GTSNEGO_DISP_SetCursorState(dispCtx->actorSys, 0, 9);
    GTSNEGO_MSG_ClearRows(dispCtx->msgCtx);
    if (n <= 3) flag = 0;
    GTSNEGO_MSG_InitWindows(dispCtx->actorSys, flag);
    GTSNEGO_MSG_PrintList(dispCtx->msgCtx, dispCtx->gameData);
    GTSNEGO_MSG_PrintListRange(dispCtx->msgCtx, dispCtx->gameData, dispCtx->list.scrollTop - 2);
    GTSNEGO_MSG_FillListRange(dispCtx->actorSys, dispCtx->gameData, dispCtx->list.scrollTop - 2);
    GTSNEGO_MSG_DrawTileRows(dispCtx->actorSys, dispCtx->gameData, dispCtx->list.scrollTop - 2);
    dispCtx->tooltipWin = GTSNEGO_MSG_CreateTooltip(dispCtx->msgCtx, 0x2c);
    GTSNEGO_MSG_SetIconY(dispCtx->actorSys, dispCtx->list.scrollTop + dispCtx->listCursorRow - 6, dispCtx->list.count);
    GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_HandleListInput, 0x815);
}

void GTSNEGO_DISP_ShowPartySelect(struct GtsnegoDispCtx *dispCtx)
{
    GTSNEGO_MSG_SetupRowBg(dispCtx->actorSys);
    if (dispCtx->restoreBrightness) {
        if ((dispCtx->restoreDelay)++ < 3)
            return;
        GFL_NET_ERR_RestoreBrightness();
        dispCtx->restoreBrightness = 0;
    }
    if (UI_GetInputMode() == 0)
        GTSNEGO_DISP_SetCursorState(dispCtx->actorSys, 0, dispCtx->partyCursor);
    else
        GTSNEGO_DISP_SetCursorState(dispCtx->actorSys, 0, 9);
    GTSNEGO_MSG_CreateYesNoUi(dispCtx->msgCtx, GTSNEGO_DISP_OnMenuCallback, dispCtx);
    dispCtx->rowInputCallback = GTSNEGO_DISP_StartTrade;
    if ((int)POKEPARTY_GetNonEggCount(GAME_DATA_GetMyParty(dispCtx->gameData)) < 2)
        dispCtx->cannotTrade = 1;
    if (dispCtx->cannotTrade == 0)
        GTSNEGO_MSG_PrintWindow(dispCtx->msgCtx, 0x20);
    else
        GTSNEGO_MSG_PrintWindow(dispCtx->msgCtx, 0x2b);
    BG_SYS_SetPlaneVisible(4, 1);
    BG_SYS_SetPlaneVisible(6, 1);
    GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_HandlePartyInput, 0x86c);
}

int GTSNEGO_DISP_SelectParty(struct GtsnegoDispCtx *dispCtx,int position) { if (GTSNEGO_MSG_SetCursorAnimSeq((struct GtsnegoActorSys *)(dispCtx->actorSys),position)) { TOUCHBAR_SetAllButtonsVisible((TouchBar *)((u8 *)GTSNEGO_DISP_GetTouchbar((dispCtx->actorSys))),0); GFL_USE_PlaySeDefaultVolume(1356); return position; } return 9; }

int GTSNEGO_DISP_CheckPartySelect(struct GtsnegoDispCtx *dispCtx, int position)
{
    if (GTSNEGO_MSG_IsCursorAnimDone(dispCtx->actorSys) == 0)
        position = 9;
    return position;
}

void GTSNEGO_DISP_OnPartySelected(struct GtsnegoDispCtx *dispCtx)
{
    int state = GTSNEGO_DISP_CheckPartySelect(dispCtx, dispCtx->partyCursor);
    if (state == 0) {
        GTSNEGO_DISP_SetCursorState(dispCtx->actorSys, dispCtx->tooltipWin, 9);
        GTSNEGO_MSG_ClearRows(dispCtx->msgCtx);
        BG_SYS_MarkTileDirty(6);
        GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_CreateConfirmUi, 0x8a3);
        return;
    }
    if (state == 1) {
        GTSNEGO_DISP_SetCursorState(dispCtx->actorSys, dispCtx->tooltipWin, 9);
        GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_ShowPokemonList, 0x8a7);
    }
}

void GTSNEGO_DISP_OnPartyMenuDone(struct GtsnegoDispCtx *dispCtx)
{
    int state;
    if (APP_TASKMENU_IsFinish(dispCtx->taskMenu)) {
        state = APP_TASKMENU_GetCursorPos(dispCtx->taskMenu);
        GTSNEGO_MSG_CloseMenu(*(struct TaskMenuWork **)&dispCtx->taskMenu);
        dispCtx->taskMenu = 0;
        switch (state) {
        case 0:
            dispCtx->parentCtx->screenState = 1;
            dispCtx->waitFrames = 0;
            GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_StartWipe, 0x8b5);
            return;
        case 1:
            if (dispCtx->cannotTrade == 0)
                GTSNEGO_MSG_PrintWindow(dispCtx->msgCtx, 0x20);
            else
                GTSNEGO_MSG_PrintWindow(dispCtx->msgCtx, 0x2b);
            if (UI_GetInputMode() == 0)
                GTSNEGO_DISP_SetCursorState(dispCtx->actorSys, 0, dispCtx->partyCursor);
            TOUCHBAR_SetButtonVisible((TouchBar *)GTSNEGO_DISP_GetTouchbar(dispCtx->actorSys), 1, 1);
            GTSNEGO_DISP_SetTradePalette(dispCtx->actorSys, 0, 0);
            GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_HandlePartyInput, 0x8c3);
            break;
        }
    }
}

void GTSNEGO_DISP_OpenPartyMenu(struct GtsnegoDispCtx *dispCtx)
{
    if (GTSNEGO_MSG_UpdatePrintStream((struct GtsnegoMsgCtx *)dispCtx->msgCtx)) {
        TOUCHBAR_SetButtonVisible((TouchBar *)GTSNEGO_DISP_GetTouchbar(dispCtx->actorSys), 1, 0);
        dispCtx->taskMenu = GTSNEGO_MSG_OpenMenu(dispCtx->msgCtx, 1);
        GTSNEGO_DISP_SetTradePalette(dispCtx->actorSys, 1, 0);
        GTSNEGO_DISP_SetCursorState(dispCtx->actorSys, 0, 9);
        GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_OnPartyMenuDone, 0x8d4);
    }
}

void GTSNEGO_DISP_HandlePartyInput(struct GtsnegoDispCtx *dispCtx)
{
    int changed = 0;
    u8 *touchbar = (u8 *)GTSNEGO_DISP_GetTouchbar(dispCtx->actorSys);
    if (GTSNEGO_MSG_UpdatePrintStream((struct GtsnegoMsgCtx *)(dispCtx->msgCtx))) {
        if (TOUCHBAR_IsBusy((TouchBar *)touchbar) == 0) {
            if (KEY_GetTrg() != 0 && UI_GetInputMode() == 1) {
                GTSNEGO_DISP_SetCursorState(dispCtx->actorSys, 0, dispCtx->partyCursor);
                UI_SetInputMode(changed);
                return;
            }
            if (KEY_GetTrg() == 1) {
                if (dispCtx->cannotTrade == 0) {
                    GTSNEGO_DISP_SelectParty(dispCtx, dispCtx->partyCursor);
                    GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_OnPartySelected, 0x8f4);
                    return;
                }
                GFL_USE_PlaySeDefaultVolume(0x551);
            }
            if (KEY_GetTrg() == 0x40) {
                changed = 1;
                GFL_USE_PlaySeDefaultVolume(0x548);
                dispCtx->partyCursor = 0;
            }
            if (KEY_GetTrg() == 0x80) {
                changed = 1;
                GFL_USE_PlaySeDefaultVolume(0x548);
                dispCtx->partyCursor = 1;
            }
            if (changed)
                GTSNEGO_DISP_SetCursorState(dispCtx->actorSys, 0, dispCtx->partyCursor);
            GTSNEGO_MSG_UpdateButtons((struct GtsnegoMsgCtx *)(dispCtx->msgCtx));
        }
        TOUCHBAR_Update((TouchBar *)((struct TouchBar *)GTSNEGO_DISP_GetTouchbar(dispCtx->actorSys)));
        if (TOUCHBAR_GetPressedButtonIdIfDone((TouchBar *)((u8 *)GTSNEGO_DISP_GetTouchbar(dispCtx->actorSys))) == 1) {
            dispCtx->waitFrames = 1;
            GTSNEGO_MSG_PrintWindow(dispCtx->msgCtx, 0x2a);
            if (UI_GetInputMode() == 1)
                GTSNEGO_DISP_SetCursorState(dispCtx->actorSys, 0, 9);
            GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_OpenPartyMenu, 0x916);
        }
    }
}

void GTSNEGO_DISP_ResetScreen(struct GtsnegoDispCtx *dispCtx)
{
    if (dispCtx->parentCtx->screenState != 1) {
        int zero = 0;
        GFL_NET_SetAutoExit(0);
        GFL_NET_SetLoginOption(0);
        GTSNEGO_MSG_DeleteDraw(dispCtx->msgCtx);
        GTSNEGO_DISP_SetTradePalette(dispCtx->actorSys, 0, 0);
        BG_SYS_SetPlaneVisible(4, 0);
        GTSNEGO_MSG_Teardown(dispCtx->actorSys);
        GTSNEGO_MSG_DeleteWindow((struct GtsnegoMsgCtx *)(dispCtx->msgCtx));
        GTSNEGO_MSG_DeleteAll(dispCtx->msgCtx);
        GTSNEGO_DISP_SetCursorState(dispCtx->actorSys, 0, 9);
        dispCtx->restoreBrightness = 1;
        dispCtx->restoreDelay = zero;
        dispCtx->parentCtx->screenState = 1;
        GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_ShowPartySelect, 0x937);
    }
}

/*
 * volatile: hardware halfword registers written at 0x021D5C78 and 0x021D5C7E.
 * prototype: 0203064C r2 explicitly loaded despite two-arg definition;
 * 0203159C r0 allocation result used despite void matched definition.
 */
int GTSNEGO_DISP_Create(void *owner, int unused, struct GtsnegoParentCtx *parentCtx)
{
    struct GtsnegoDispCtx *dispCtx;
    int zero = 0;
    GFL_HEAP_CreateChildHeap(1, 0x1f, 0x38000);
    *(volatile u16 *)REG_BLDCNT_ADDR = zero;
    *(volatile u16 *)REG_DB_BLDCNT_ADDR = zero;
    WIPE_SetBrightnessFadeOut(0, 0);
    WIPE_SetBrightnessFadeOut(1, 0);
    dispCtx = PROCSYS_AllocProcWork(owner, sizeof(*dispCtx), 0x1f);
    MI_CpuFill8(dispCtx, 0, sizeof(*dispCtx));
    dispCtx->heapId = 0x1f;
    dispCtx->parentCtx = parentCtx;
    dispCtx->actorSys = GTSNEGO_DISP_CreateMsgSystem(dispCtx->heapId, parentCtx->gameData);
    dispCtx->msgCtx = GTSNEGO_MSG_Create(dispCtx->heapId, 0x28);
    dispCtx->gameData = parentCtx->gameData;
    dispCtx->saveControl = GAME_DATA_GetSaveControl(parentCtx->gameData);
    dispCtx->wifiList = GAME_DATA_GetWifiList(parentCtx->gameData);
    dispCtx->parentCtx->screenState = 1;
    dispCtx->partyCursor = zero;
    dispCtx->buttonCursor = 2;
    dispCtx->listCursorRow = 6;
    dispCtx->myTrainerId = MYSTATUS_GetId((struct MyStatus *)GAME_DATA_GetMyStatus(parentCtx->gameData));
    if (GFL_NET_GetRunState())
        GFL_NET_COMMAND_AddCommandTable(0x2200, d_021D88EC, 3, dispCtx);
    WIPE_SYS_Start(0, 1, 1, 0, 6, 1, dispCtx->heapId);
    GFL_USE_CancelChangeAndPlayBgm(0x486, 0xffff);
    GFL_NET_RefreshWmIconAtTopRight(1, dispCtx->heapId);
    GFL_NET_ERR_SetKeepDark(1);
    GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_ShowPartySelect, 0x96a);
    return 1;
}

int GTSNEGO_DISP_Step(int unusedA, int unusedB, int unusedC, struct GtsnegoDispCtx *dispCtx)
{
    void (*callback)(struct GtsnegoDispCtx *) = dispCtx->stateFunc;
    int result = 1;
    if (callback) {
        if (GFL_NET_ERR_GetErrorLevel() == 0)
            callback(dispCtx);
        result = 0;
    }
    if (dispCtx->tooltipWin) {
        void *touchbar = (void *)GTSNEGO_DISP_GetTouchbar(dispCtx->actorSys);
        if (touchbar == 0 || TOUCHBAR_IsBusy(touchbar) == 0)
            APP_TASKMENU_WIN_Update(dispCtx->tooltipWin);
    }
    if (dispCtx->taskMenu)
        APP_TASKMENU_UpdateMenu(dispCtx->taskMenu);
    GTSNEGO_DISP_DrawSystem(dispCtx->actorSys);
    GTSNEGO_MSG_Main(dispCtx->msgCtx);
    if (GFL_NET_GetRunState()) {
        if (GFL_NET_ERR_GetErrorLevel()) {
            switch (DWC_RAPCOMMON_HandleNetError(1, 1)) {
            case 0: break;
            case 1:
            case 4:
                GTSNEGO_DISP_ResetScreen(dispCtx);
                break;
            case 2:
                dispCtx->parentCtx->screenState = 0;
                result = 1;
                WIPE_SetBrightnessFadeOut(0, 0);
                WIPE_SetBrightnessFadeOut(1, 0);
                break;
            case 3:
                GFL_NET_ERR_Halt();
                break;
            }
        }
    } else if (GFL_NET_ERR_GetErrorLevel()) {
        result = 1;
    }
    return result;
}

/*
 * trailing: 2-byte zero alignment padding at 0x021D5E86.
 */
int GTSNEGO_DISP_Delete(void *owner, int unusedA, int unusedB, struct GtsnegoDispCtx *dispCtx)
{
    GFL_NET_ERR_ClearKeepDark();
    if (!WIPE_SYS_EndCheck()) return 0;
    if (GFL_NET_GetRunState()) GFL_NET_COMMAND_DeleteCommandTable(0x2200);
    if (dispCtx->tooltipWin) APP_TASKMENU_WIN_Delete(dispCtx->tooltipWin);
    if (dispCtx->taskMenu) APP_TASKMENU_CloseMenu(dispCtx->taskMenu);
    GTSNEGO_MSG_Delete(dispCtx->msgCtx);
    GTSNEGO_DISP_DeleteMsgSystem(dispCtx->actorSys);
    PROCSYS_FreeProcWork(owner);
    GFL_HEAP_DeleteChecked(31);
    return 1;
}

/*
 * interface: arg is a full-word pointer, as matched caller 021D5C60 supplies.
 * interface: 021D6100 gets p explicitly loaded despite its legacy void(void).
 * volatile: hardware 0x04001000 read/written at 0x021D5EC4/0x021D5ECA.
 */
struct GtsnegoActorSys *GTSNEGO_DISP_CreateMsgSystem(u32 heap,void *arg)
{
    struct GtsnegoActorSys *actorSys;
    actorSys=GFL_HEAP_Alloc(heap,sizeof(*actorSys),1,d_021D8BC8,258);
    ((struct GtsnegoActorSys *)actorSys)->heapId=heap;
    ((struct GtsnegoActorSys *)actorSys)->gameData=arg;
    GF_OVERLAY_Load((sptr)ov_id);
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    BG_SYS_SetLcdSwap(1);
    *(volatile u32 *)REG_DB_DISPCNT_ADDR|=0x10000;
    GX_DispOn();
    BG_SYS_Create(((struct GtsnegoActorSys *)actorSys)->heapId);
    CLACT_InitSystem((const struct ClactSysInit *)d_021D8974,(const struct DispVramCfg *)((struct DispVramCfg *)(&d_021D8B98)),((struct GtsnegoActorSys *)actorSys)->heapId);
    ((struct GtsnegoActorSys *)actorSys)->clactUnit=CLACT_CreateUnit(64,0,((struct GtsnegoActorSys *)actorSys)->heapId);
    BG_SYS_SetVramBanks(&d_021D8B98);
    BG_SYS_SetGraphicsMode(&d_021D8B60);
    GTSNEGO_DISP_InitBgLayers(actorSys);
    GTSNEGO_DISP_RegisterGraphics(actorSys);
    ((struct GtsnegoActorSys *)actorSys)->vblankTask=GFL_USE_AddMainTask(GTSNEGO_DISP_VBlank,(void *)actorSys,0);
    ((struct GtsnegoActorSys *)actorSys)->savedObjPltt=GFL_HEAP_Alloc(((struct GtsnegoActorSys *)actorSys)->heapId,0x200,0,d_021D8BC8,280);
    ((struct GtsnegoActorSys *)actorSys)->savedBgPltt=GFL_HEAP_Alloc(((struct GtsnegoActorSys *)actorSys)->heapId,0x200,0,d_021D8BC8,281);
    GTSNEGO_DISP_CreateCursorActor(actorSys);
    GTSNEGO_DISP_CreateTouchbar(actorSys,0);
    BG_SYS_SetSubVisiblePlanes(31);
    BG_SYS_SetMainVisiblePlanes(31);
    return actorSys;
}

void GTSNEGO_DISP_DrawSystem(struct GtsnegoActorSys *actorSys){CLACT_DrawSystem();if(actorSys->blinkAnimA)BLINK_PALANM_Update(actorSys->blinkAnimA);if(actorSys->blinkAnimB)BLINK_PALANM_Update(actorSys->blinkAnimB);GTSNEGO_MSG_StepIdleFade((struct GtsnegoActorSys *)actorSys);}

void GTSNEGO_DISP_DeleteMsgSystem(struct GtsnegoActorSys *actorSys)
{
    int i;
    CLACT_DeleteActor(((struct GtsnegoActorSys *)actorSys)->cursorActor);
    GTSNEGO_DISP_DeleteTouchbar(actorSys);
    GTSNEGO_MSG_DeleteCursorActor(actorSys);
    GTSNEGO_MSG_DeleteTileHandle(actorSys);
    GFL_HEAP_Free(((struct GtsnegoActorSys *)actorSys)->savedObjPltt);
    GFL_HEAP_Free(((struct GtsnegoActorSys *)actorSys)->savedBgPltt);
    GTSNEGO_MSG_DeleteActors(actorSys);
    CLACT_ReleasePalette(((struct GtsnegoActorSys *)actorSys)->uiPalette);
    CLACT_ReleasePalette(((struct GtsnegoActorSys *)actorSys)->idlePalette);
    CLACT_ReleaseCharacter(((struct GtsnegoActorSys *)actorSys)->uiChar);
    CLACT_ReleaseCharacter(((struct GtsnegoActorSys *)actorSys)->idleChar);
    CLACT_ReleaseCellAnim(((struct GtsnegoActorSys *)actorSys)->uiCellAnim);
    CLACT_ReleaseCellAnim(((struct GtsnegoActorSys *)actorSys)->idleCellAnim);
    CLACT_ReleasePalette(((struct GtsnegoActorSys *)actorSys)->cursorPalette);
    CLACT_ReleaseCharacter(((struct GtsnegoActorSys *)actorSys)->cursorChar);
    CLACT_ReleaseCellAnim(((struct GtsnegoActorSys *)actorSys)->cursorCellAnim);
    CLACT_ReleasePalette(((struct GtsnegoActorSys *)actorSys)->listPalette);
    for(i=0;i<16;i++) {
        CLACT_ReleaseCharacter(((struct GtsnegoActorSys *)actorSys)->listChars[i]);
        CLACT_ReleaseCellAnim(((struct GtsnegoActorSys *)actorSys)->listCellAnims[i]);
    }
    TCB_DeleteTask(((struct GtsnegoActorSys *)actorSys)->vblankTask);
    CLACT_DeleteUnit(((struct GtsnegoActorSys *)actorSys)->clactUnit);
    CLACT_ExitSystem();
    BLINK_PALANM_Delete(((struct GtsnegoActorSys *)actorSys)->blinkAnimA);
    BLINK_PALANM_Delete(((struct GtsnegoActorSys *)actorSys)->blinkAnimB);
    BG_SYS_FreeTileRun(7,(u16)actorSys->bgCharLayer7,(u16)(actorSys->bgCharLayer7>>16));
    BG_SYS_FreeTileRun(4,(u16)(((struct GtsnegoActorSys *)actorSys)->bgCharLayer4),(u16)(((struct GtsnegoActorSys *)actorSys)->bgCharLayer4>>16));
    BG_SYS_FreeTileRun(0,(u16)(((struct GtsnegoActorSys *)actorSys)->bgCharLayer0),(u16)(((struct GtsnegoActorSys *)actorSys)->bgCharLayer0>>16));
    BG_SYS_FreeTiles(1,1,0);
    BG_SYS_FreeTiles(5,1,0);
    BG_SYS_FreeTiles(6,1,0);
    BG_SYS_SetPlaneVisible(5,0);
    for(i=0;i<=7;i++) BG_SYS_FreeLayerBuf((u8)i);
    BG_SYS_Delete();
    GFL_HEAP_Free(actorSys);
    GF_OVERLAY_Unload((sptr)ov_id);
}

struct Unit *GTSNEGO_DISP_GetUnit(struct GtsnegoActorSys *actorSys){return actorSys->clactUnit;}

/*
 * BG-layer init: eight copies of the const template table at 0x021D89B0
 * (index order 0,5,1,2,3,4,6,7) passed to BG_SYS_InitBgLayer, each followed by
 * its layer enable / fill sequence.  The local array is written high-to-low
 * (b[7] first) because the original places the first-used slot at the top of
 * the frame.
 */
void GTSNEGO_DISP_InitBgLayers(struct GtsnegoActorSys *actorSys)
{
    struct BgTemplate b[8];

    b[7] = d_021D89B0[0];
    BG_SYS_InitBgLayer(0, &b[7], 0);
    BG_SYS_FreeSlot(0);
    BG_SYS_PushTile(0);
    BG_SYS_SetPlaneVisible(0, 1);

    b[6] = d_021D89B0[5];
    BG_SYS_InitBgLayer(1, &b[6], 0);
    BG_SYS_SetPlaneVisible(1, 1);
    BG_SYS_Init(1, 0, 1, 0);
    BG_SYS_SetTileEntry(1, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_PushTile(1);

    b[5] = d_021D89B0[1];
    BG_SYS_InitBgLayer(2, &b[5], 0);
    BG_SYS_SetPlaneVisible(2, 1);
    BG_SYS_SetTileEntry(2, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_PushTile(2);

    b[4] = d_021D89B0[2];
    BG_SYS_InitBgLayer(3, &b[4], 0);
    BG_SYS_SetPlaneVisible(3, 1);
    BG_SYS_SetTileEntry(3, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_PushTile(3);

    b[3] = d_021D89B0[3];
    BG_SYS_InitBgLayer(4, &b[3], 0);
    BG_SYS_SetPlaneVisible(4, 1);
    BG_SYS_PushTile(4);

    b[2] = d_021D89B0[4];
    BG_SYS_InitBgLayer(5, &b[2], 0);
    BG_SYS_SetPlaneVisible(5, 1);
    BG_SYS_Init(5, 0, 1, 0);
    BG_SYS_SetTileEntry(5, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_PushTile(5);

    b[1] = d_021D89B0[6];
    BG_SYS_InitBgLayer(6, &b[1], 0);
    BG_SYS_SetPlaneVisible(6, 1);
    BG_SYS_Init(6, 0, 1, 0);
    BG_SYS_SetTileEntry(6, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_PushTile(6);

    b[0] = d_021D89B0[7];
    BG_SYS_InitBgLayer(7, &b[0], 0);
    BG_SYS_SetPlaneVisible(7, 1);
    BG_SYS_PushTile(7);
}

void GTSNEGO_DISP_BlendPalette(struct GtsnegoActorSys *actorSys,int bank,int *offset,int *size,int count)
{
    int i;
    void *obj;
    u8 *buffer;
    obj=PALANM_Create(actorSys->heapId);
    PALANM_AllocSlotBuffers(obj,bank,0x200,actorSys->heapId);
    PALANM_CopyHwPaletteToSlot(obj,bank,0,0x200);
    PALANM_BlendChannel(obj,bank,0,0x100,6,0);
    buffer=(u8 *)PALANM_GetTransWork(obj,bank);
    for(i=0;i<count;i++) {
        switch(bank) {
        case 3:
            DC_FlushRange(buffer+offset[i]*32,size[i]*32);
            GXS_LoadOBJPltt(buffer+offset[i]*32,offset[i]*32,size[i]*32);
            break;
        case 1:
            DC_FlushRange(buffer+offset[i]*32,size[i]*32);
            GXS_LoadBGPltt(buffer+offset[i]*32,offset[i]*32,size[i]*32);
            break;
        }
    }
    PALANM_FreeSlotBuffers(obj,bank);
    PALANM_Delete(obj);
}

/*
 * lever: one-word aggregate locals preserve the early address setup and merge.
 */
void GTSNEGO_DISP_SetTradePalette(struct GtsnegoActorSys *actorSys,int flag,int mode)
{
    if(flag) {
        MI_CpuCopy8((void *)HW_DB_OBJ_PLTT,actorSys->savedObjPltt,0x200);
        MI_CpuCopy8((void *)HW_DB_BG_PLTT,actorSys->savedBgPltt,0x200);
        switch(mode) {
        case 2: {
            Word offsets={0};
            Word sizes=d_021D8920;
            GTSNEGO_DISP_BlendPalette(actorSys,3,&offsets.a,&sizes.a,1);
            break;
        }
        case 0: {
            Word offsets=d_021D891C;
            Word sizes=d_021D8918;
            GTSNEGO_DISP_BlendPalette(actorSys,3,&offsets.a,&sizes.a,1);
            break;
        }
        case 1: {
            GtsnegoDispPair offsets=d_021D895C;
            GtsnegoDispPair sizes=d_021D896C;
            GTSNEGO_DISP_BlendPalette(actorSys,3,&offsets.a,&sizes.a,2);
            break;
        }
        }
        switch(mode) {
        case 0: case 2: {
            GtsnegoDispPair offsets=d_021D894C;
            GtsnegoDispPair sizes=d_021D8954;
            GTSNEGO_DISP_BlendPalette(actorSys,1,&offsets.a,&sizes.a,2);
            break;
        }
        case 1: {
            GtsnegoDispPair offsets=d_021D8944;
            GtsnegoDispPair sizes=d_021D8964;
            GTSNEGO_DISP_BlendPalette(actorSys,1,&offsets.a,&sizes.a,2);
            break;
        }
        }
    } else {
        DC_FlushRange(actorSys->savedObjPltt,0x200);
        GXS_LoadOBJPltt(actorSys->savedObjPltt,0,0x200);
        DC_FlushRange(actorSys->savedBgPltt,0x200);
        GXS_LoadBGPltt(actorSys->savedBgPltt,0,0x200);
    }
}

/*
 * extent: two-byte zero alignment padding follows.
 */
void GTSNEGO_DISP_VBlank(struct TcbTask *unused, void *actorSysArg){
    struct GtsnegoActorSys *actorSys = actorSysArg;CLACT_VBlankSystem();if(((struct GtsnegoActorSys *)actorSys)->scrollDirty){BG_SYS_ChangeScrollImmediate(4,3,((struct GtsnegoActorSys *)actorSys)->scrollOffset+72);BG_SYS_ChangeScrollImmediate(6,3,((struct GtsnegoActorSys *)actorSys)->scrollOffset+72);((struct GtsnegoActorSys *)actorSys)->scrollDirty=0;}}

void GTSNEGO_DISP_RegisterGraphics(struct GtsnegoActorSys *actorSys)
{
    int i;
    void *arcHandle;
    arcHandle=ARC_TOOL_CreateHandle((uptr)((void *)144),((struct GtsnegoActorSys *)actorSys)->heapId);
    ARC_UTIL_UploadPaletteFromHandleWhole(arcHandle,3,4,0,192,((struct GtsnegoActorSys *)actorSys)->heapId);
    ARC_UTIL_UploadPaletteFromHandleWhole(arcHandle,1,4,0,64,((struct GtsnegoActorSys *)actorSys)->heapId);
    actorSys->bgCharLayer7=ARC_UTIL_RegisterObjCharFromHandle(arcHandle,6,7,0,0,((struct GtsnegoActorSys *)actorSys)->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(arcHandle,17,7,0,(u16)actorSys->bgCharLayer7,0,0,((struct GtsnegoActorSys *)actorSys)->heapId);
    ((struct GtsnegoActorSys *)actorSys)->bgCharLayer4=ARC_UTIL_RegisterObjCharFromHandle(arcHandle,8,4,0,0,((struct GtsnegoActorSys *)actorSys)->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(arcHandle,18,4,0,(u16)(((struct GtsnegoActorSys *)actorSys)->bgCharLayer4),0,0,((struct GtsnegoActorSys *)actorSys)->heapId);
    ARC_UTIL_UploadPaletteFromHandleWhole(arcHandle,1,0,0,0,((struct GtsnegoActorSys *)actorSys)->heapId);
    ((struct GtsnegoActorSys *)actorSys)->bgCharLayer0=ARC_UTIL_RegisterObjCharFromHandle(arcHandle,6,0,0,0,((struct GtsnegoActorSys *)actorSys)->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(arcHandle,12,0,0,(u16)(((struct GtsnegoActorSys *)actorSys)->bgCharLayer0),0,0,((struct GtsnegoActorSys *)actorSys)->heapId);
    ((struct GtsnegoActorSys *)actorSys)->cursorChar=CLACT_RegisterCharacter(arcHandle,5,0,1,((struct GtsnegoActorSys *)actorSys)->heapId);
    ((struct GtsnegoActorSys *)actorSys)->cursorPalette=CLACT_RegisterPaletteEx(arcHandle,0,1,320,0,1,((struct GtsnegoActorSys *)actorSys)->heapId);
    ((struct GtsnegoActorSys *)actorSys)->cursorCellAnim=CLACT_RegisterCellAnim(arcHandle,10,22,((struct GtsnegoActorSys *)actorSys)->heapId);
    ((struct GtsnegoActorSys *)actorSys)->uiChar=CLACT_RegisterCharacter(arcHandle,7,0,1,((struct GtsnegoActorSys *)actorSys)->heapId);
    ((struct GtsnegoActorSys *)actorSys)->uiPalette=CLACT_RegisterPaletteEx(arcHandle,2,1,256,0,8,((struct GtsnegoActorSys *)actorSys)->heapId);
    ((struct GtsnegoActorSys *)actorSys)->uiCellAnim=CLACT_RegisterCellAnim(arcHandle,11,23,((struct GtsnegoActorSys *)actorSys)->heapId);
    ((struct GtsnegoActorSys *)actorSys)->idleChar=CLACT_RegisterCharacter(arcHandle,7,0,0,((struct GtsnegoActorSys *)actorSys)->heapId);
    ((struct GtsnegoActorSys *)actorSys)->idlePalette=CLACT_RegisterPaletteEx(arcHandle,2,0,0,0,8,((struct GtsnegoActorSys *)actorSys)->heapId);
    ((struct GtsnegoActorSys *)actorSys)->idleCellAnim=CLACT_RegisterCellAnim(arcHandle,11,23,((struct GtsnegoActorSys *)actorSys)->heapId);
    ((struct GtsnegoActorSys *)actorSys)->blinkAnimA=BLINK_PALANM_Create(0,16,0,((struct GtsnegoActorSys *)actorSys)->heapId);
    BLINK_PALANM_LoadPalettes(((struct GtsnegoActorSys *)actorSys)->blinkAnimA,arcHandle,1,0,16);
    ((struct GtsnegoActorSys *)actorSys)->blinkAnimB=BLINK_PALANM_Create(0,16,7,((struct GtsnegoActorSys *)actorSys)->heapId);
    BLINK_PALANM_LoadPalettes(((struct GtsnegoActorSys *)actorSys)->blinkAnimB,arcHandle,1,0,16);
    ARC_TOOL_DeleteHandle(arcHandle);
    arcHandle=ARC_TOOL_CreateHandle((uptr)((void *)32),((struct GtsnegoActorSys *)actorSys)->heapId);
    for(i=0;i<16;i++) {
        ((struct GtsnegoActorSys *)actorSys)->listChars[i]=CLACT_RegisterCharacter(arcHandle,i+1,0,1,((struct GtsnegoActorSys *)actorSys)->heapId);
        ((struct GtsnegoActorSys *)actorSys)->listCellAnims[i]=CLACT_RegisterCellAnim(arcHandle,i*2+17,i*2+18,((struct GtsnegoActorSys *)actorSys)->heapId);
    }
    ((struct GtsnegoActorSys *)actorSys)->listPalette=CLACT_RegisterPaletteEx(arcHandle,0,1,0,0,8,((struct GtsnegoActorSys *)actorSys)->heapId);
    ARC_TOOL_DeleteHandle(arcHandle);
    G2x_SetBlendAlpha_((void *)REG_DB_BLDCNT_ADDR,5,24,15,9);
}

void GTSNEGO_DISP_Noop(struct GtsnegoActorSys *actorSys, int unusedFlag){}

void GTSNEGO_DISP_RedrawActors(struct GtsnegoActorSys *actorSys)
{
    void *arcHandle;
    GTSNEGO_DISP_Noop(actorSys, 0);
    arcHandle = ARC_TOOL_CreateHandle(144, ((struct GtsnegoActorSys *)actorSys)->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(arcHandle, 19, 4, 0, (u16)(((struct GtsnegoActorSys *)actorSys)->bgCharLayer4), 0, 0, ((struct GtsnegoActorSys *)actorSys)->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(arcHandle, 20, 4, 0, (u16)(((struct GtsnegoActorSys *)actorSys)->bgCharLayer4), 192, 0, ((struct GtsnegoActorSys *)actorSys)->heapId);
    ARC_TOOL_DeleteHandle(arcHandle);
    GTSNEGO_MSG_CreateActorAt(actorSys, 96, 56, 0);
    GTSNEGO_MSG_CreateActorAt(actorSys, 240, 56, 1);
    GTSNEGO_MSG_CreateActorAt(actorSys, 120, 96, 0);
    GTSNEGO_MSG_CreateActorAt(actorSys, 240, 96, 1);
    GTSNEGO_MSG_CreateActorAt(actorSys, 120, 136, 0);
    GTSNEGO_MSG_CreateActorAt(actorSys, 240, 136, 1);
}

/*
 * trailing: 2-byte zero alignment padding at 0x021D692A.
 */
void GTSNEGO_DISP_ResetActors(struct GtsnegoActorSys *actorSys)
{
    void *arcHandle = ARC_TOOL_CreateHandle(144, ((struct GtsnegoActorSys *)actorSys)->heapId);
    GTSNEGO_MSG_DeleteActors(actorSys);
    BG_SYS_SetTileEntry(6, 0, 0, 0, 32, 32, 17);
    BG_SYS_MarkTileDirty(6);
    ARC_UTIL_UploadBgPaletteAddFromHandle(arcHandle, 18, 4, 0, (u16)(((struct GtsnegoActorSys *)actorSys)->bgCharLayer4), 0, 0, ((struct GtsnegoActorSys *)actorSys)->heapId);
    BG_SYS_MarkTileDirty(4);
    ARC_TOOL_DeleteHandle(arcHandle);
}

void GTSNEGO_DISP_CreateTouchbar(struct GtsnegoActorSys *actorSys, int actorPlttSlot)
{
    Data data = d_021D8990;
    GtsnegoDispConfig params;
    MI_CpuFill8(&params, 0, sizeof(params));
    params.defs = &data;
    params.count = 1;
    params.actorSys = *(u32 *)&((struct GtsnegoActorSys *)actorSys)->clactUnit;
    params.bgLayer = 7;
    params.bgPlttSlot = 15;
    params.iconSet = 2;
    params.skipBgGfx = 0;
    params.actorPlttSlot = actorPlttSlot;
    ((struct GtsnegoActorSys *)actorSys)->touchbar = TOUCHBAR_Create((TouchBarParams *)&params, ((struct GtsnegoActorSys *)actorSys)->heapId);
}

struct TouchBar *GTSNEGO_DISP_GetTouchbar(struct GtsnegoActorSys *actorSys){return ((struct GtsnegoActorSys *)actorSys)->touchbar;}

void GTSNEGO_DISP_DeleteTouchbar(struct GtsnegoActorSys *actorSys)
{
    if (((struct GtsnegoActorSys *)actorSys)->touchbar) {
        TOUCHBAR_Delete(((struct GtsnegoActorSys *)actorSys)->touchbar);
        ((struct GtsnegoActorSys *)actorSys)->touchbar = 0;
    }
}

void GTSNEGO_DISP_CreateCursorActor(struct GtsnegoActorSys *actorSys)
{
    PosRecord actorPos;
    actorPos.x = 0; actorPos.y = 0; actorPos.z = 0; actorPos.a = 0; actorPos.b = 2;
    ((struct GtsnegoActorSys *)actorSys)->cursorActor = CLACT_CreateActor((struct Unit *)((void *)((struct GtsnegoActorSys *)actorSys)->clactUnit), ((struct GtsnegoActorSys *)actorSys)->uiChar, ((struct GtsnegoActorSys *)actorSys)->uiPalette, ((struct GtsnegoActorSys *)actorSys)->uiCellAnim, (const struct ActorInitParam *)&actorPos, 1, ((struct GtsnegoActorSys *)actorSys)->heapId);
    CLACT_SetActorAutoAnim(((struct GtsnegoActorSys *)actorSys)->cursorActor, 1);
    CLACT_SetActorDrawEnable(((struct GtsnegoActorSys *)actorSys)->cursorActor, 0);
    CLACT_SetActorObjMode(((struct GtsnegoActorSys *)actorSys)->cursorActor, 1);
}

void GTSNEGO_DISP_SetCursorState(struct GtsnegoActorSys *actorSys, void *taskMenuWin, u32 position)
{
    GtsnegoDispVec v;
    switch (position) {
    case 9:
        CLACT_SetActorDrawEnable(((struct GtsnegoActorSys *)actorSys)->cursorActor, 0);
        return;
    case 5:
        CLACT_SetActorDrawEnable(((struct GtsnegoActorSys *)actorSys)->cursorActor, 0);
        if (taskMenuWin) APP_TASKMENU_WIN_SetActive(taskMenuWin, 1);
        return;
    case 2: case 3: case 4: case 6: case 7: case 8:
        if (taskMenuWin) APP_TASKMENU_WIN_SetActive(taskMenuWin, 0);
        break;
    case 0: case 1: default: break;
    }
    v.x = gGtsnegoEntryTable[position].x;
    v.y = gGtsnegoEntryTable[position].y;
    CLACT_AddActorSurfacePos((struct ClactActor *)(((struct GtsnegoActorSys *)actorSys)->cursorActor), (const struct ClactVec2 *)((const struct Vec2 *)(&v)), 1);
    CLACT_SetActorAnimSeq(((struct GtsnegoActorSys *)actorSys)->cursorActor, gGtsnegoEntryTable[position].code);
    CLACT_SetActorDrawEnable(((struct GtsnegoActorSys *)actorSys)->cursorActor, 1);
}
