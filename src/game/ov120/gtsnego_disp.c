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
 *   BMP_SetDisplaySwap 0x0204363C arm
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
#include "ov120_types.h"
struct GtsnegoDispCtx;
struct GtsnegoParentCtx;

struct GtsnegoDispCtx {
    void *stateFunc;
    unsigned int rowInputCallback;
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
    void *actorSys;
    void *msgCtx;
    unsigned int wifiList;
    void *parentCtx;
    unsigned char pad_4C[236];
    int tradeMode;
    int rowBIndex;
    int rowCIndex;
    int rowAIndex;
    int selectedListIndex;
    unsigned int myTrainerId;
    int listCount;
    int listCursor;
    int listScrollTop;
    int partyCursor;
    int buttonCursor;
    int listCursorRow;
    unsigned char pad_168[8];
    int myTradeCount;
    unsigned char pad_174[8];
    int partnerTradeCount;
    unsigned char pad_180[4];
    int cannotTrade;
    unsigned short nameBuf;
    unsigned char pad_18A[22];
    void *profanityWords;
    unsigned char pad_1A4[4];
    int profanityResult;
    unsigned short nameMaxChars;
    unsigned char pad_1AE[2];
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

#define I(k) (*(int *)(dispCtx + (k)))
struct Entry;
struct Link;
struct Obj;
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
struct Ctx;
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
struct PalAnmSlot;
struct CodeIn;
struct Actor;
struct Vec2;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u16 v[4]; } Halfwords;

typedef struct { u32 value; u8 kind; u8 pad; u16 detail; u32 tail; } MatchFilterRecord;

typedef signed int     s32;

typedef struct Ctx {
    u8 pad0[0x2C];
    void *gameData;
    u8 pad30[4];
    void *tooltipWin;
    u8 pad38[4];
    u8 *actorSys;
    void *msgCtx;
    u8 pad44[0x148 - 0x44];
    int selectedListIndex;
    u8 pad14C[4];
    int listCount;
    u8 pad154[4];
    int listScrollTop;
    u8 pad15C[8];
    int listCursorRow;
} Ctx;

struct DispConfig { u32 a,b,c,d; };

struct BgTemplate {
    u32 scrollX;
    u32 scrollY;
    u32 bufSize;
    u32 baseTile;
    u8  screenSize;
    u8  colorMode;
    u8  screenBase;
    u8  charBase;
    u32 tileDataSize;
    u8  extPltt;
    u8  priority;
    u8  areaOver;
    u8  pad_1b;
    u32 mosaic;
};

typedef struct Pair { int a,b; } Pair;

typedef struct Word { int a; } Word;

typedef struct Data { u32 w[8]; } Data;

typedef struct Config { Data *defs; u32 count; int actorSys; u32 bgLayer, bgPlttSlot, actorPlttSlot; int iconSet, skipBgGfx; } Config;

typedef struct PosRecord { u16 x, y, z; u8 a, b; } PosRecord;

typedef signed short s16;

typedef struct Entry { u8 code, x, y, other; } Entry;

typedef struct Vec { s16 x, y; } Vec;

extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_GetHandleNetID(struct Link *);
extern void MI_CpuCopy8(const void *,void *,u32);
extern int MYSTATUS_GetSize(void);
extern void UI_SetInputMode(u8 v);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void GTSNEGO_MSG_RedrawRowA(char *p, int i);
extern void GTSNEGO_MSG_RedrawRowB(char *p, int i);
extern void GTSNEGO_MSG_RedrawRowC(char *p, int i);
extern void GTSNEGO_MSG_SetActorMode(u8 *p, u32 n);
extern void APP_TASKMENU_WIN_SetActive(struct Obj *,u32);
extern u32 WIPE_SYS_EndCheck(void);
extern void WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);
extern int GFL_NET_GetRunState(void);
extern void GTSNEGO_MSG_CreateDraw(u8 *p, void *q);
extern void GTSNEGO_MSG_PrintDraw(struct GtsnegoMsgCtx *p, void *n);
extern void GTSNEGO_MSG_PrintWindowB(u8 *p, int n);
extern void GTSNEGO_MSG_PrintTooltip(char *p, u16 n);
extern void GTSNEGO_MSG_DeleteEntryWindow(char *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern u32 MYSTATUS_GetId(const struct Sub0200852CObj *obj);
extern u8 MYSTATUS_GetTrainerView(const struct Sub0200852CObj *obj);
extern void GTSNEGO_MSG_PrintSummary(char *p, void *q, u32 n);
extern void GTSNEGO_MSG_SetIdleAnim(u8 *p, int n);
extern int DWC_CheckProfanityProcess(void);
extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *MSGDATA_AllocString(struct MsgBank *bank, u32 index);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void MYSTATUS_NameFromStrbuf(u16 *out, struct U16Vec *vec);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern struct Rec44 *GAME_DATA_GetMyStatusPlayer(struct Sub24 *p, u32 i);
extern void MYSTATUS_Copy(void *src, void *dst);
extern void *MET_TRAINERS_GetFromSave(void *p);
extern void MET_TRAINERS_Insert(struct L0200ED54 *l, u32 val);
extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *, unsigned int, unsigned int);
extern void *MYSTATUS_CreateNameStrbuf(void *, int);
extern void MI_CpuFill8(void *, u8, u32);
extern u16 *STRBUF_GetChars(struct U16Vec *vec);
extern u16 STRBUF_GetLength(struct U16Vec *vec);
extern u16 STRBUF_GetEosChar(void);
extern int DWC_CheckProfanityExAsync(u16 **, int, char *, int, char *, int *, int);
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *,u32,u32);
extern int GFL_NET_SendToHandle(void *,u16,u16,u32);
extern int GTSNEGO_MSG_UpdatePrintStream(char *p);
extern int GFL_NET_HANDLE_GetNegotiationNum(void);
extern void *GREETING_SAVEDATA_GetFromSaveThunk(u32 a);
extern void GREETING_SAVEDATA_GetSentence(struct Rec0200E6FC *src, int idx, struct Rec0200E6FC *dst);
extern void *GAME_DATA_GetTradeHistory(void **h);
extern u32 TRADE_HISTORY_GetTradeCount(const struct Sub02009D9CObj *obj);
extern int GFL_NET_HANDLE_CheckNegotiation(void);
extern int GTSNEGO_MSG_UpdateButtons(char *p);
extern u32 KEY_GetTrg(void);
extern void GTSNEGO_MSG_SetDecide(unsigned char *p);
extern void GFL_NET_STATE_WifiDisconnect(u32 a);
extern int GFL_NET_STATE_GetWifiState(void);
extern void GFL_NET_SetAutoExit(u8 autoExit);
extern void GFL_NET_SetLoginOption(u8 loginOption);
extern void GTSNEGO_MSG_DeleteWindow(char *p);
extern void GTSNEGO_MSG_DeleteConfirmWindow(u8 *p);
extern int DWC_GetMatchIntValue(int, int, int);
extern void *TRADE_HISTORY_GetFromSave(void *);
extern u32 TRADE_HISTORY_HasPartner(struct Sub02009D9CObj *obj, u32 id);
extern void GTSNEGO_MSG_CreateConfirmUi(u8 *, int, int);
extern void GFL_NET_SetWaitMode(int);
extern void WIFILIST_CreateExchangeToken(void *account, void *out);
extern u8 DWC_AddMatchKeyInt(u8 keyID, char *keyString, int *valueSrc);
extern int STD_TSPrintf(char *, const char *, ...);
extern int DWC_RAP_StartMatchWithFilter(int, int, int, int);
extern u32 GFL_NET_STATE_WifiEnterFriendMatch(void);
extern void DWC_RAP_SetVchatEnabled(int);
extern void GFL_NET_STATE_SetError(int, u32, u32, u32);
extern u32 APP_TASKMENU_WIN_IsFinish(u8 *p);
extern void APP_TASKMENU_WIN_Delete(u8 *p);
extern void BG_SYS_MarkTileDirty(u32 bit);
extern void GTSNEGO_MSG_PrintWindow(u8 *p, u16 n);
extern void GTSNEGO_MSG_CreateIdleUi(u8 *p);
extern void GTSNEGO_MSG_PrintStatus(char *p, u16 n);
extern int TOUCHBAR_IsBusy(u8 *);
extern u8 UI_GetInputMode(void);
extern int GTSNEGO_MSG_SetCursorAnimSeq(u8 *p, u32 n);
extern void APP_TASKMENU_WIN_SetDecide(char *p, int v);
extern int TOUCHPANEL_HitTrg(const void *p);
extern void TOUCHBAR_Update(struct TouchBar *p);
extern int TOUCHBAR_GetPressedButtonIdIfDone(u8 *);
extern void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);
extern void GTSNEGO_MSG_DeleteButtonsKeep(u8 *p);
extern void TOUCHBAR_SetAllButtonsVisible(u8 *, u32);
extern void GTSNEGO_MSG_ClearRows(char *p);
extern void GTSNEGO_MSG_CreateListUi(char *p, int a, int b, int c, int d, int e);
extern void *GTSNEGO_MSG_CreateTooltip(char *p, u16 n);
extern int TRADE_HISTORY_GetPartnerCount(void *);
extern void *TRADE_HISTORY_GetPartner(void *,int);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
extern void GTSNEGO_MSG_Teardown(u8 *);
extern void GTSNEGO_MSG_DeleteAll(char *);
extern int GTSNEGO_MSG_IsConfirmFinished(u8 *p);
extern void GTSNEGO_MSG_TeardownTileRows(u8 *p);
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *);
extern void GTSNEGO_MSG_CloseMenu(int);
extern void TOUCHBAR_SetButtonVisible(unsigned char *p, unsigned int id, unsigned int v);
extern void GTSNEGO_MSG_RestartIconAnim(u8 *p, u32 flag);
extern void *GTSNEGO_MSG_OpenMenuB(char *p, int n);
extern int GTSNEGO_MSG_CursorUp(void *unused, int *p);
extern void GTSNEGO_MSG_SetScrollState(u8 *p, int state);
extern void GTSNEGO_MSG_PrintListEntryN(char *p, void *q, int n);
extern int GTSNEGO_MSG_CursorDown(void *unused, int *p);
extern void GTSNEGO_MSG_PrintListEntryAt(char *p, void *q, int index);
extern int GTSNEGO_MSG_StepScroll(u8 *p, int *out);
extern void GTSNEGO_MSG_DrawTileRows(u8 *p, void *list, int first);
extern void GTSNEGO_MSG_ShiftListUp(char *p);
extern void GTSNEGO_MSG_ScrollListUp(u8 *p, void *q);
extern void GTSNEGO_MSG_ShiftListDown(char *p);
extern void GTSNEGO_MSG_ScrollListDown(u8 *p, void *q);
extern u32 KEY_GetRepeat(void);
extern void GTSNEGO_MSG_ClearScrollState(u8 *p);
extern void GTSNEGO_MSG_ScrollAllRows(u8 *p, int flag);
extern void GTSNEGO_MSG_SetIconY(u8 *p, int index, int count);
extern void GTSNEGO_MSG_SetCursorIndex(void *unused, int *p, int n);
extern int TOUCHPANEL_HitCont(const void *t);
extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);
extern int GTSNEGO_MSG_SetIconYClamped(char *p, int y, int count);
extern void GTSNEGO_MSG_PrintListRange(char *p, void *q, int start);
extern void GTSNEGO_MSG_FillListRange(u8 *p, void *list, int n);
extern void GTSNEGO_MSG_TeardownActorList(u8 *p);
extern void GTSNEGO_MSG_InitWindows(u8 *, int);
extern void GTSNEGO_MSG_PrintList(char *, void *);
extern void GTSNEGO_MSG_SetupRowBg(void *);
extern void GFL_NET_ERR_RestoreBrightness(void);
extern void GTSNEGO_MSG_CreateYesNoUi(char *p, int a, int b);
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern u32 POKEPARTY_GetNonEggCount(void *);
extern int GTSNEGO_MSG_IsCursorAnimDone(u8 *p);
extern void *GTSNEGO_MSG_OpenMenu(char *p, int n);
extern void GTSNEGO_MSG_DeleteDraw(u8 *);
extern void GFL_HEAP_CreateChildHeap(u32, u32, u32);
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern char *GTSNEGO_MSG_Create(u32 heap, u32 n);
extern void WIPE_SetBrightnessFadeOut(u32, u32);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern u32 GAME_DATA_GetWifiList(const struct BigObj *p);
extern void GFL_NET_COMMAND_AddCommandTable(u32, u32, u32, u32);
extern void GFL_USE_CancelChangeAndPlayBgm(u32, u32);
extern void GFL_NET_RefreshWmIconAtTopRight(u32, u32);
extern void GFL_NET_ERR_SetKeepDark(u32 value);
extern u32 GFL_NET_ERR_GetErrorLevel(void);
extern void APP_TASKMENU_WIN_Update(u8 *p);
extern void APP_TASKMENU_UpdateMenu(void *);
extern void GTSNEGO_MSG_Main(u8 *p);
extern int DWC_RAPCOMMON_HandleNetError(int a0, int a1);
extern void GFL_NET_ERR_Halt(void);
extern void GFL_NET_ERR_ClearKeepDark(void);
extern void GFL_NET_COMMAND_DeleteCommandTable(unsigned int);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern void GTSNEGO_MSG_Delete(char *p);
extern void PROCSYS_FreeProcWork(struct Proc *p);
extern void GFL_HEAP_DeleteChecked(unsigned int heap);
extern void *GFL_HEAP_Alloc(u32,u32,int,const char *,u16);
extern int GF_OVERLAY_Load(int);
extern void BG_SYS_SetMainVisiblePlanes(u32);
extern void BMP_SetDisplaySwap(u32 swap);
extern void GX_DispOn(void);
extern void BG_SYS_Create(u16);
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void BG_SYS_SetVramBanks(const struct DispVram *);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *);
extern void *GFL_USE_AddMainTask(void (*)(void *,u8 *),void *,int);
extern void CLACT_DrawSystem(void);
extern s32 BLINK_PALANM_Update(struct Row *p);
extern void GTSNEGO_MSG_StepIdleFade(char *p);
extern void CLACT_DeleteActor(struct Obj *p);
extern void GTSNEGO_MSG_DeleteCursorActor(u8 *);
extern void GTSNEGO_MSG_DeleteTileHandle(u8 *);
extern u32 GFL_HEAP_Free(void *p);
extern void GTSNEGO_MSG_DeleteActors(u8 *);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern void TCB_DeleteTask(struct Node *n);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern u32 BLINK_PALANM_Delete(struct BlinkPalAnm *p);
extern void BG_SYS_FreeTileRun(u32 layer, u32 offset, u32 size);
extern void BG_SYS_FreeTiles(u32,u32,u32);
extern void BG_SYS_FreeLayerBuf(u32 i);
extern void BG_SYS_Delete(void);
extern void GF_OVERLAY_Unload(int handle);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_FreeSlot(u32);
extern void BG_SYS_PushTile(u32);
extern void BG_SYS_Init(u32, u32, u32, u32);
extern void BG_SYS_SetTileEntry(u32, u32, u32, u32, u8, u8, u8);
extern void *PALANM_Create(u32);
extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void PALANM_BlendChannel(struct Chan02021FD8 *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
extern int PALANM_GetTransWork(char *,int);
extern void DC_FlushRange(void *,unsigned long);
extern void GXS_LoadOBJPltt(void *,int,int);
extern void GXS_LoadBGPltt(void *,int,int);
extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *slots, u32 idx);
extern u32 PALANM_Delete(void *ctx);
extern void CLACT_VBlankSystem(void);
extern void BG_SYS_ChangeScrollImmediate(u32,u32,u32);
extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);
extern void ARC_UTIL_UploadPaletteFromHandleWhole(void *,u32,u32,u32,u32,u16);
extern u32 ARC_UTIL_RegisterObjCharFromHandle(void *,u32,u32,u32,u32,u16);
extern u32 ARC_UTIL_UploadBgPaletteAddFromHandle(void *arc, u32 memberIdx, u32 channel, u32 offset, u32 add, u32 size, u32 heapID, u16 flags);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 vram_mode, u16 flags);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern struct CodeIn *BLINK_PALANM_Create(u16 firstColor, u16 colorCount, u32 mode, u16 heap);
extern void BLINK_PALANM_LoadPalettes(struct CodeIn *p, u8 *archive, u32 fileId, u32 srcStart, u32 dstStart);
extern void ARC_TOOL_DeleteHandle(void *);
extern void G2x_SetBlendAlpha_(void *,int,int,int,int);
extern void GTSNEGO_MSG_CreateActorAt(u8 *, u16, u16, int);
extern void *TOUCHBAR_Create(Config *, int);
extern void TOUCHBAR_Delete(u8 *p);
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
void GTSNEGO_DISP_SetCallback(void **p, void *v);
void GTSNEGO_DISP_SetStateCallback(void *p, void *fn, int line);
void GTSNEGO_DISP_OnTradeSync(u32 id,int b,const void *src,struct GtsnegoDispCtx *p,struct Entry *entry);
void GTSNEGO_DISP_OnStatusSync(u32 id,int b,const void *src,struct GtsnegoDispCtx *p,struct Entry *entry);
void GTSNEGO_DISP_OnRecordSync(u32 id,int b,const void *src,u8 *p,struct Entry *entry);
int GTSNEGO_DISP_StartTrade(int n, u8 *p);
void GTSNEGO_DISP_CycleRowB(int n, char *p);
void GTSNEGO_DISP_CycleRowC(int n, char *p);
void GTSNEGO_DISP_CycleRowA(int n, char *p);
int GTSNEGO_DISP_MoveRowCursor(int n, char *p);
int GTSNEGO_DISP_OnRowCursorMoved(int n,char *p);
void GTSNEGO_DISP_MoveCursorVertical(int n,char *p);
void GTSNEGO_DISP_WaitWipeDone(u8 *p);
void GTSNEGO_DISP_StartWipe(struct GtsnegoDispCtx *p);
void GTSNEGO_DISP_ShowTradeReady(u8 *a);
void GTSNEGO_DISP_WaitTradeStart(struct GtsnegoDispCtx *a);
void GTSNEGO_DISP_ShowTradeConfirm(struct GtsnegoDispCtx *p);
void GTSNEGO_DISP_ConfirmStatus(struct GtsnegoDispCtx *p);
void GTSNEGO_DISP_PrepareTrade(u8 *p);
void GTSNEGO_DISP_StartSync(u8 *p);
void GTSNEGO_DISP_SendStatus(struct GtsnegoDispCtx *p);
void GTSNEGO_DISP_SendRecord(u8 *p);
void GTSNEGO_DISP_SendHandshake(struct GtsnegoDispCtx *a);
void GTSNEGO_DISP_WaitNegotiation(u8 *p);
void GTSNEGO_DISP_CheckNegotiation(int *a);
void GTSNEGO_DISP_WaitPartnerReady(struct GtsnegoDispCtx *a);
void GTSNEGO_DISP_HandleTradeKeys(struct GtsnegoDispCtx *a);
int GTSNEGO_DISP_ScoreMatch(int a, u8 *p);
void GTSNEGO_DISP_StartMatchmaking(u8 *p);
void GTSNEGO_DISP_OnMenuCallback(void *p,int n,u8 *s);
void GTSNEGO_DISP_OnConfirmDone(struct GtsnegoDispCtx *p);
void GTSNEGO_DISP_HandleConfirmKeys(u8 *p);
void GTSNEGO_DISP_CreateConfirmUi(u8 *p);
void *GTSNEGO_DISP_GetEntry(void **p,int i);
void *GTSNEGO_DISP_GetEntryClamped(void **p,int i);
void GTSNEGO_DISP_ShowSubPlanes(u8 *p);
void GTSNEGO_DISP_Teardown(struct GtsnegoDispCtx *p);
void GTSNEGO_DISP_OnDisconnect(struct GtsnegoDispCtx *p);
void GTSNEGO_DISP_OnDisconnectCallback(int a, int b, int *p);
void GTSNEGO_DISP_CreateExitTooltip(struct GtsnegoDispCtx *p);
void GTSNEGO_DISP_OnExitMenuDone(struct GtsnegoDispCtx *p);
void GTSNEGO_DISP_OpenExitMenu(struct GtsnegoDispCtx *p);
void GTSNEGO_DISP_ShowListMessage(struct GtsnegoDispCtx *p);
void GTSNEGO_DISP_EndList(struct GtsnegoDispCtx *p);
int GTSNEGO_DISP_ListCursorUp(u8 *p);
int GTSNEGO_DISP_ListCursorDown(u8 *p);
void GTSNEGO_DISP_OnListConfirmDone(struct GtsnegoDispCtx *p);
void GTSNEGO_DISP_DeleteMenuWindow(u8 *p);
void GTSNEGO_DISP_HandleListInput(Ctx *p);
void GTSNEGO_DISP_WaitSelectStart(struct GtsnegoDispCtx *p);
void GTSNEGO_DISP_ShowPokemonList(struct GtsnegoDispCtx *p);
void GTSNEGO_DISP_ShowPartySelect(u8 *p);
int GTSNEGO_DISP_SelectParty(u8 *p,int n);
int GTSNEGO_DISP_CheckPartySelect(struct GtsnegoDispCtx *p, int x);
void GTSNEGO_DISP_OnPartySelected(struct GtsnegoDispCtx *p);
void GTSNEGO_DISP_OnPartyMenuDone(struct GtsnegoDispCtx *p);
void GTSNEGO_DISP_OpenPartyMenu(struct GtsnegoDispCtx *p);
void GTSNEGO_DISP_HandlePartyInput(u8 *p);
void GTSNEGO_DISP_ResetScreen(u8 *p);
int GTSNEGO_DISP_Create(void *a, int unused, u8 *q);
int GTSNEGO_DISP_Step(int a, int b, int c, u8 *p);
int GTSNEGO_DISP_Delete(void *p, int a, int b, struct GtsnegoDispCtx *q);
u8 *GTSNEGO_DISP_CreateMsgSystem(u32 heap,void *arg);
void GTSNEGO_DISP_DrawSystem(struct GtsnegoActorSys *p);
void GTSNEGO_DISP_DeleteMsgSystem(u8 *p);
u32 GTSNEGO_DISP_GetUnit(struct GtsnegoActorSys *actorSys);
void GTSNEGO_DISP_InitBgLayers(u8 *actorSys);
void GTSNEGO_DISP_BlendPalette(struct GtsnegoActorSys *p,int bank,int *offset,int *size,int count);
void GTSNEGO_DISP_SetTradePalette(struct GtsnegoActorSys *p,int flag,int mode);
void GTSNEGO_DISP_VBlank(void *unused,u8 *p);
void GTSNEGO_DISP_RegisterGraphics(u8 *p);
void GTSNEGO_DISP_Noop(u8 *actorSys, int unusedFlag);
void GTSNEGO_DISP_RedrawActors(u8 *p);
void GTSNEGO_DISP_ResetActors(u8 *p);
void GTSNEGO_DISP_CreateTouchbar(u8 *p, int n);
u32 GTSNEGO_DISP_GetTouchbar(u8 *p);
void GTSNEGO_DISP_DeleteTouchbar(u8 *p);
void GTSNEGO_DISP_CreateCursorActor(u8 *p);
void GTSNEGO_DISP_SetCursorState(u8 *p, void *q, u32 n);
extern const Halfwords d_021D8904;
extern const u16 d_021D8B40[];
extern const char d_021D8B50[];
extern const u32 d_021D88D0[];
extern const u8 d_021D88D8[];
extern const u8 d_021D88C8[];
extern const u32 d_021D88EC[];
extern const char d_021D8BC8[];
extern const u8 ov_id[];
extern const struct DispVram d_021D8B98;
extern const u32 d_021D8974[];
extern struct DispConfig d_021D8B60;
extern const struct BgTemplate d_021D89B0[8];
extern const Word d_021D8920,d_021D891C,d_021D8918;
extern const Pair d_021D895C,d_021D896C,d_021D894C,d_021D8954,d_021D8944,d_021D8964;
extern const Data d_021D8990;
extern const Entry gGtsnegoEntryTable[];




void GTSNEGO_DISP_SetCallback(void **slot, void *callback) { *slot=callback; }




void GTSNEGO_DISP_SetStateCallback(void *dispCtx, void *callback, int line) { GTSNEGO_DISP_SetCallback(dispCtx, callback); }




void GTSNEGO_DISP_OnTradeSync(u32 netId,int size,const void *data,struct GtsnegoDispCtx *dispCtx,struct Entry *netHandle) { u8 *q; q=*(u8 * *)&dispCtx->parentCtx; if(netHandle==GFL_NET_HANDLE_GetCurrentHandle() && netId!=GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle())) MI_CpuCopy8(data,q+12,8); }




void GTSNEGO_DISP_OnStatusSync(u32 netId,int size,const void *data,struct GtsnegoDispCtx *dispCtx,struct Entry *netHandle) { u8 *q; q=*(u8 * *)&dispCtx->parentCtx; if(netHandle==GFL_NET_HANDLE_GetCurrentHandle() && netId!=GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle())) MI_CpuCopy8(data,((struct GtsnegoParentCtx *)q)->partnerStatus,MYSTATUS_GetSize()); }




void GTSNEGO_DISP_OnRecordSync(u32 netId,int size,const void *data,u8 *dispCtx,struct Entry *netHandle) { if(netHandle==GFL_NET_HANDLE_GetCurrentHandle() && netId!=GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle())) MI_CpuCopy8(data,dispCtx+0x174,12); }




/*
 * extent: existing matched followers 021D435C, 021D437C, 021D439C remain separate.
 */
int GTSNEGO_DISP_StartTrade(int choice, u8 *dispCtx)
{
    ((struct GtsnegoDispCtx *)dispCtx)->tradeMode = choice;
    UI_SetInputMode(1);
    if (((struct GtsnegoDispCtx *)dispCtx)->cannotTrade == 1) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        return 1;
    }
    if (choice == 0) {
        ((struct GtsnegoDispCtx *)dispCtx)->partyCursor = 0;
        GTSNEGO_DISP_SetCursorState(*(u8 * *)&((struct GtsnegoDispCtx *)dispCtx)->actorSys, ((struct GtsnegoDispCtx *)dispCtx)->tooltipWin, 0);
        GTSNEGO_DISP_SelectParty(dispCtx, ((struct GtsnegoDispCtx *)dispCtx)->partyCursor);
        GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_OnPartySelected, 0x177);
    } else {
        ((struct GtsnegoDispCtx *)dispCtx)->partyCursor = 1;
        GTSNEGO_DISP_SetCursorState(*(u8 * *)&((struct GtsnegoDispCtx *)dispCtx)->actorSys, ((struct GtsnegoDispCtx *)dispCtx)->tooltipWin, 1);
        GTSNEGO_DISP_SelectParty(dispCtx, ((struct GtsnegoDispCtx *)dispCtx)->partyCursor);
        GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_OnPartySelected, 0x17e);
    }
    return 1;
}




/*
 * follower: separately filed 021D437C.
 */
void GTSNEGO_DISP_CycleRowB(int delta, char *dispCtx) {
    ((struct GtsnegoDispCtx *)dispCtx)->rowBIndex+=delta;
    if(((struct GtsnegoDispCtx *)dispCtx)->rowBIndex>=5) ((struct GtsnegoDispCtx *)dispCtx)->rowBIndex=0;
    else if(((struct GtsnegoDispCtx *)dispCtx)->rowBIndex<0) ((struct GtsnegoDispCtx *)dispCtx)->rowBIndex=4;
}




/*
 * follower: separately filed 021D439C.
 */
void GTSNEGO_DISP_CycleRowC(int delta, char *dispCtx) {
    ((struct GtsnegoDispCtx *)dispCtx)->rowCIndex+=delta;
    if(((struct GtsnegoDispCtx *)dispCtx)->rowCIndex>=5) ((struct GtsnegoDispCtx *)dispCtx)->rowCIndex=0;
    else if(((struct GtsnegoDispCtx *)dispCtx)->rowCIndex<0) ((struct GtsnegoDispCtx *)dispCtx)->rowCIndex=4;
}




void GTSNEGO_DISP_CycleRowA(int delta, char *dispCtx) {
    ((struct GtsnegoDispCtx *)dispCtx)->rowAIndex+=delta;
    if(((struct GtsnegoDispCtx *)dispCtx)->rowAIndex>=4) ((struct GtsnegoDispCtx *)dispCtx)->rowAIndex=0;
    else if(((struct GtsnegoDispCtx *)dispCtx)->rowAIndex<0) ((struct GtsnegoDispCtx *)dispCtx)->rowAIndex=3;
}




int GTSNEGO_DISP_MoveRowCursor(int selection, char *dispCtx) {
    int result=0;
    switch(selection) {
    case 0:GTSNEGO_DISP_CycleRowA(-1,dispCtx);result=2;GTSNEGO_MSG_RedrawRowA((char *)(*(int *)&((struct GtsnegoDispCtx *)dispCtx)->msgCtx),((struct GtsnegoDispCtx *)dispCtx)->rowAIndex);break;
    case 1:GTSNEGO_DISP_CycleRowA(1,dispCtx);result=2;GTSNEGO_MSG_RedrawRowA((char *)(*(int *)&((struct GtsnegoDispCtx *)dispCtx)->msgCtx),((struct GtsnegoDispCtx *)dispCtx)->rowAIndex);break;
    case 2:GTSNEGO_DISP_CycleRowB(-1,dispCtx);result=3;GTSNEGO_MSG_RedrawRowB((char *)(*(int *)&((struct GtsnegoDispCtx *)dispCtx)->msgCtx),((struct GtsnegoDispCtx *)dispCtx)->rowBIndex);break;
    case 3:GTSNEGO_DISP_CycleRowB(1,dispCtx);result=3;GTSNEGO_MSG_RedrawRowB((char *)(*(int *)&((struct GtsnegoDispCtx *)dispCtx)->msgCtx),((struct GtsnegoDispCtx *)dispCtx)->rowBIndex);break;
    case 4:GTSNEGO_DISP_CycleRowC(-1,dispCtx);result=4;GTSNEGO_MSG_RedrawRowC((char *)(*(int *)&((struct GtsnegoDispCtx *)dispCtx)->msgCtx),((struct GtsnegoDispCtx *)dispCtx)->rowCIndex);break;
    case 5:GTSNEGO_DISP_CycleRowC(1,dispCtx);result=4;GTSNEGO_MSG_RedrawRowC((char *)(*(int *)&((struct GtsnegoDispCtx *)dispCtx)->msgCtx),((struct GtsnegoDispCtx *)dispCtx)->rowCIndex);break;
    }
    if(selection>=0 && selection<=5) {GFL_USE_PlaySeDefaultVolume(0x548);GTSNEGO_MSG_SetActorMode((u8 *)(*(int *)&((struct GtsnegoDispCtx *)dispCtx)->actorSys),selection);}
    return result;
}




int GTSNEGO_DISP_OnRowCursorMoved(int selection,char *dispCtx) { int result; if(*(struct Obj * *)&((struct GtsnegoDispCtx *)dispCtx)->tooltipWin) APP_TASKMENU_WIN_SetActive(*(struct Obj * *)&((struct GtsnegoDispCtx *)dispCtx)->tooltipWin,0); result=GTSNEGO_DISP_MoveRowCursor(selection,dispCtx); if(result) ((struct GtsnegoDispCtx *)dispCtx)->buttonCursor=result; return 1; }


void GTSNEGO_DISP_MoveCursorVertical(int direction,char *dispCtx) { int v; v=((struct GtsnegoDispCtx *)dispCtx)->buttonCursor-2; if(((struct GtsnegoDispCtx *)dispCtx)->buttonCursor>=2 || ((struct GtsnegoDispCtx *)dispCtx)->buttonCursor<=4) GTSNEGO_DISP_MoveRowCursor(direction+v*2,dispCtx); }






void GTSNEGO_DISP_WaitWipeDone(u8 *dispCtx) { if (WIPE_SYS_EndCheck()) GTSNEGO_DISP_SetStateCallback(dispCtx, 0, 0x213); }






void GTSNEGO_DISP_StartWipe(struct GtsnegoDispCtx *dispCtx) {
    if (--dispCtx->waitFrames<=0) {
        WIPE_SYS_Start(0,0,0,0,6,1,dispCtx->heapId);
        GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_WaitWipeDone, 0x21e);
    }
}





void GTSNEGO_DISP_ShowTradeReady(u8 *dispCtx)
{
    Halfwords table = d_021D8904;
    const Halfwords *p = &table;
    if (GFL_NET_GetRunState() != 0)
        p = (const Halfwords *)(dispCtx + 0x174);
    ((struct GtsnegoDispCtx *)dispCtx)->waitFrames = 0xb4;
    GTSNEGO_MSG_CreateDraw((u8 *)(*(int *)&((struct GtsnegoDispCtx *)dispCtx)->msgCtx), (void *)(*(int *)&((struct GtsnegoDispCtx *)dispCtx)->actorSys));
    GTSNEGO_MSG_PrintDraw((struct GtsnegoMsgCtx *)(*(int *)&((struct GtsnegoDispCtx *)dispCtx)->msgCtx), (void *)p);
    GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_StartWipe, 0x232);
}




void GTSNEGO_DISP_WaitTradeStart(struct GtsnegoDispCtx *dispCtx)
{
    --dispCtx->waitFrames;
    if (dispCtx->waitFrames == 20)
        GTSNEGO_MSG_PrintWindowB((u8 *)(*(int *)&dispCtx->msgCtx), 0x27);
    if (dispCtx->waitFrames == 0) {
        GTSNEGO_MSG_PrintTooltip((char *)(*(int *)&dispCtx->msgCtx), 0x23);
        GTSNEGO_MSG_DeleteEntryWindow((char *)(*(int *)&dispCtx->msgCtx));
        GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_ShowTradeReady, 0x241);
    }
}




void GTSNEGO_DISP_ShowTradeConfirm(struct GtsnegoDispCtx *dispCtx)
{
    u8 *parentCtx = *(u8 * *)&dispCtx->parentCtx;
    int value;
    int tradeCount = 2;
    if (GFL_NET_GetRunState() == 0) {
        value = (int)GAME_DATA_GetMyStatus((void *)(*(int *)&((struct GtsnegoParentCtx *)parentCtx)->gameData));
    } else {
        value = *(int *)&((struct GtsnegoParentCtx *)parentCtx)->partnerStatus;
        tradeCount = dispCtx->partnerTradeCount;
        *(int *)(parentCtx + ((struct GtsnegoParentCtx *)parentCtx)->recentIdCount * 4 + 0x1c) = MYSTATUS_GetId((const struct Sub0200852CObj *)value);
        ((struct GtsnegoParentCtx *)parentCtx)->recentIdCount = ((struct GtsnegoParentCtx *)parentCtx)->recentIdCount + 1;
        if (((struct GtsnegoParentCtx *)parentCtx)->recentIdCount >= 100)
            ((struct GtsnegoParentCtx *)parentCtx)->recentIdCount = 0;
    }
    GTSNEGO_MSG_PrintSummary((char *)(*(int *)&dispCtx->msgCtx), (void *)value, tradeCount);
    GTSNEGO_MSG_SetIdleAnim((u8 *)(*(int *)&dispCtx->actorSys), MYSTATUS_GetTrainerView((const struct Sub0200852CObj *)value));
    dispCtx->waitFrames = 0xb4;
    GTSNEGO_DISP_SetStateCallback(((int *)dispCtx), GTSNEGO_DISP_WaitTradeStart, 0x265);
}




void GTSNEGO_DISP_ConfirmStatus(struct GtsnegoDispCtx *dispCtx)
{
    int ready = 0;
    int value = *(int *)&((struct GtsnegoParentCtx *)dispCtx->parentCtx)->partnerStatus;
    int active;
    void *message;
    void *text;
    int result;
    active = DWC_CheckProfanityProcess() == 2;
    if (active)
        ready = dispCtx->profanityResult > 0;
    if (active) {
        if (ready) {
            message = MSGDATA_CreateFromArchive(0, 2, 0x51, 0x1f);
            text = MSGDATA_AllocString(message, 15);
            MSGDATA_Delete(message);
            MYSTATUS_NameFromStrbuf((u16 *)value, text);
            STRBUF_Delete(text);
        }
        MYSTATUS_Copy((void *)value, GAME_DATA_GetMyStatusPlayer((struct Sub24 *)(*(int *)&dispCtx->gameData), 1 - GFL_NET_SYSTEM_GetCurrentAid()));
        result = MYSTATUS_GetId((const struct Sub0200852CObj *)value);
        MET_TRAINERS_Insert(MET_TRAINERS_GetFromSave((void *)(*(int *)&dispCtx->saveControl)), result);
        GTSNEGO_DISP_SetStateCallback(((int *)dispCtx), GTSNEGO_DISP_ShowTradeConfirm, 0x283);
    }
}




/*
 * evidence: 020399A8's r0 is consumed by 02039CB4 despite its void definition.
 * evidence: 020458F8 returns ldrh r0; this caller uses full-word r0+1 without narrowing.
 */
void GTSNEGO_DISP_PrepareTrade(u8 *dispCtx)
{
    void *str;
    u16 *chars;
    u32 i;
    void *value = ((struct GtsnegoParentCtx *)((struct GtsnegoDispCtx *)dispCtx)->parentCtx)->partnerStatus;
    if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 3, 0x22) != 0) {
        str = MYSTATUS_CreateNameStrbuf(value, 31);
        MI_CpuFill8(dispCtx + 0x188, 0, 40);
        ((struct GtsnegoDispCtx *)dispCtx)->nameMaxChars = 31;
        chars = STRBUF_GetChars(str);
        for (i = 0; i < STRBUF_GetLength(str) + 1u; i++) {
            u16 ch = chars[i];
            if (ch == STRBUF_GetEosChar()) ((u16 *)(dispCtx + 0x188))[i] = 0;
            else ((u16 *)(dispCtx + 0x188))[i] = ch;
        }
        ((struct GtsnegoDispCtx *)dispCtx)->profanityWords = dispCtx + 0x188;
        *(unsigned int *)&((struct GtsnegoDispCtx *)dispCtx)->profanityResult = 0;
        DWC_CheckProfanityExAsync((u16 **)(dispCtx + 0x1a0), 1, 0, 0, (char *)(dispCtx + 0x1a4), (int *)(dispCtx + 0x1a8), 128);
        STRBUF_Delete(str);
        GTSNEGO_DISP_SetStateCallback(((int *)dispCtx), GTSNEGO_DISP_ConfirmStatus, 0x29c);
    }
}




void GTSNEGO_DISP_StartSync(u8 *dispCtx) { GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),3,34); GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_PrepareTrade, 0x2ac); }




void GTSNEGO_DISP_SendStatus(struct GtsnegoDispCtx *dispCtx) { void *link; int n; link=GFL_NET_HANDLE_GetCurrentHandle(); n=MYSTATUS_GetSize(); if (GFL_NET_SendToHandle(link,0x2201,n,*(u32 *)(*(unsigned int *)&dispCtx->parentCtx+20))) GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_StartSync, 0x2bd); }








void GTSNEGO_DISP_SendRecord(u8 *dispCtx) { if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0x2202,12,(u32)(dispCtx+360))) GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_SendStatus, 0x2cf); }









void GTSNEGO_DISP_SendHandshake(struct GtsnegoDispCtx *dispCtx)
{
    if (GFL_NET_GetRunState() == 0) {
        GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_ShowTradeConfirm, 0x2df);
        return;
    }
    if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 2, 0x22) != 0) {
        if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x2200, 8, (u32)(*(char * *)&dispCtx->parentCtx + 4)) != 0)
            GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_SendRecord, 0x2e7);
    }
}









void GTSNEGO_DISP_WaitNegotiation(u8 *dispCtx)
{
    u8 *parentCtx;
    int value;
    if (GTSNEGO_MSG_UpdatePrintStream((char *)(*(int *)&((struct GtsnegoDispCtx *)dispCtx)->msgCtx))) {
        if (GFL_NET_GetRunState() == 0) {
            GTSNEGO_DISP_SetStateCallback(((int *)dispCtx), GTSNEGO_DISP_SendHandshake, 0x2fe);
            return;
        }
        if (((struct GtsnegoDispCtx *)dispCtx)->waitFrames > 0) {
            ((struct GtsnegoDispCtx *)dispCtx)->waitFrames = ((struct GtsnegoDispCtx *)dispCtx)->waitFrames - 1;
            return;
        }
        if (GFL_NET_HANDLE_GetNegotiationNum() == 2) {
            parentCtx = *(u8 * *)&((struct GtsnegoDispCtx *)dispCtx)->parentCtx;
            value = (int)GREETING_SAVEDATA_GetFromSaveThunk(*(int *)&((struct GtsnegoDispCtx *)dispCtx)->saveControl);
            *(int *)&((struct GtsnegoParentCtx *)parentCtx)->rowAIndex = ((struct GtsnegoDispCtx *)dispCtx)->rowAIndex;
            *(int *)&((struct GtsnegoParentCtx *)parentCtx)->rowBIndex = ((struct GtsnegoDispCtx *)dispCtx)->rowBIndex;
            GREETING_SAVEDATA_GetSentence((struct Rec0200E6FC *)value, 0, (struct Rec0200E6FC *)(dispCtx + 0x168));
            ((struct GtsnegoDispCtx *)dispCtx)->myTradeCount = TRADE_HISTORY_GetTradeCount(GAME_DATA_GetTradeHistory((void **)(*(int *)&((struct GtsnegoDispCtx *)dispCtx)->gameData)));
            GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 2, 0x22);
            GTSNEGO_DISP_SetStateCallback(((int *)dispCtx), GTSNEGO_DISP_SendHandshake, 0x314);
        }
    }
}








void GTSNEGO_DISP_CheckNegotiation(int *dispCtx)
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
    if (GTSNEGO_MSG_UpdatePrintStream((char *)(*(int *)&dispCtx->msgCtx)) != 0) {
        if (dispCtx->waitFrames > 0) {
            dispCtx->waitFrames = dispCtx->waitFrames - 1;
            return;
        }
        if (GFL_NET_SYSTEM_GetCurrentAid() != 0) {
            if (GFL_NET_HANDLE_CheckNegotiation() != 0) {
                dispCtx->waitFrames = 0xb4;
                GTSNEGO_DISP_SetStateCallback(((int *)dispCtx), GTSNEGO_DISP_WaitNegotiation, 0x33f);
                return;
            }
        } else {
            dispCtx->waitFrames = 0xb4;
            GTSNEGO_DISP_SetStateCallback(((int *)dispCtx), GTSNEGO_DISP_CheckNegotiation, 0x344);
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
    GTSNEGO_MSG_UpdateButtons((char *)(*(int *)&dispCtx->msgCtx));
    if (KEY_GetTrg() == 2) {
        GTSNEGO_MSG_SetDecide((unsigned char *)(*(int *)&dispCtx->msgCtx));
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
    GTSNEGO_MSG_DeleteWindow((char *)(*(int *)&dispCtx->msgCtx));
    GTSNEGO_MSG_PrintWindowB((u8 *)(*(int *)&dispCtx->msgCtx), 0x10);
    dispCtx->waitFrames = 0xb4;
    GTSNEGO_MSG_DeleteConfirmWindow((u8 *)(*(int *)&dispCtx->msgCtx));
    GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_WaitPartnerReady, 0x377);
}








int GTSNEGO_DISP_ScoreMatch(int matchData, u8 *dispCtx)
{
    int mode;
    int x;
    int y;
    int score = -1;
    int id;
    int group;
    int i;
    u8 *parentCtx = *(u8 * *)&((struct GtsnegoDispCtx *)dispCtx)->parentCtx;
    mode = DWC_GetMatchIntValue(matchData, (int)(dispCtx + 0x76), -1);
    x = DWC_GetMatchIntValue(matchData, (int)(dispCtx + 0x8e), -1);
    y = DWC_GetMatchIntValue(matchData, (int)(dispCtx + 0x82), -1);
    id = DWC_GetMatchIntValue(matchData, (int)(dispCtx + 0x5e), 0);
    group = DWC_GetMatchIntValue(matchData, (int)(dispCtx + 0xb2), 0);
    if (I(0x138) == 1) {
        if (mode == 4) {
            if (I(0x148) == -1) {
                if (TRADE_HISTORY_HasPartner(TRADE_HISTORY_GetFromSave(((struct GtsnegoDispCtx *)dispCtx)->saveControl), id) != 0)
                    score = 100;
            } else {
                if (I(0x18) == id) score = 100;
            }
        } else {
            if (group == MYSTATUS_GetId((const struct Sub0200852CObj *)GAME_DATA_GetMyStatus((void *)(((struct GtsnegoParentCtx *)parentCtx)->gameData)))) {
                if (I(0x148) == -1) {
                    if (TRADE_HISTORY_HasPartner(TRADE_HISTORY_GetFromSave(((struct GtsnegoDispCtx *)dispCtx)->saveControl), id) != 0)
                        score = 100;
                } else {
                    if (I(0x18) == id) score = 100;
                }
            }
        }
    } else {
        if (I(0x144) == mode) {
            if (I(0x13c) == x) score += 20;
            else if (I(0x13c) == 0 || x == 0) score += 10;
            else score -= 40;
            if (I(0x140) == y) score += 20;
            else if (y == 0 || I(0x140) == 0) score += 10;
            else score -= 40;
            for (i = 0; i < 100; i++) {
                if (id == *(int *)(parentCtx + i * 4 + 0x1c) && id != 0) {
                    score = 0;
                    break;
                }
            }
        }
    }
    return score;
}








void GTSNEGO_DISP_StartMatchmaking(u8 *dispCtx)
{
    u32 values[8];
    void *entry;
    int i;
    MatchFilterRecord *record;
    if (GTSNEGO_MSG_UpdatePrintStream(((struct GtsnegoDispCtx *)dispCtx)->msgCtx)) {
        if (GFL_NET_GetRunState() == 0) {
            GTSNEGO_MSG_CreateConfirmUi(*(u8 * *)&((struct GtsnegoDispCtx *)dispCtx)->msgCtx, (int)GTSNEGO_DISP_OnDisconnectCallback, (int)dispCtx);
            GTSNEGO_DISP_SetStateCallback(((int *)dispCtx), GTSNEGO_DISP_HandleTradeKeys, 0x3ea);
            return;
        }
        GFL_NET_SetWaitMode(0);
        WIFILIST_CreateExchangeToken((void *)(((struct GtsnegoDispCtx *)dispCtx)->wifiList), values);
        values[0] = ((struct GtsnegoDispCtx *)dispCtx)->myTrainerId;
        values[1] = *(unsigned int *)&((struct GtsnegoDispCtx *)dispCtx)->tradeMode;
        values[2] = *(unsigned int *)&((struct GtsnegoDispCtx *)dispCtx)->rowAIndex;
        values[3] = *(unsigned int *)&((struct GtsnegoDispCtx *)dispCtx)->rowBIndex;
        values[4] = *(unsigned int *)&((struct GtsnegoDispCtx *)dispCtx)->rowCIndex;
        values[5] = 0x20015;
        values[6] = 1;
        values[7] = 0;
        if (*(unsigned int *)&((struct GtsnegoDispCtx *)dispCtx)->tradeMode == 1) {
            if (((struct GtsnegoDispCtx *)dispCtx)->selectedListIndex == -1)
                values[2] = 4;
            else {
                entry = GTSNEGO_DISP_GetEntry(((struct GtsnegoDispCtx *)dispCtx)->gameData, ((struct GtsnegoDispCtx *)dispCtx)->selectedListIndex);
                values[7] = MYSTATUS_GetId(entry);
                ((struct GtsnegoDispCtx *)dispCtx)->selectedPartnerId = MYSTATUS_GetId(entry);
            }
        }
        for (i = 0; i < 8; i++) {
            record = (MatchFilterRecord *)(dispCtx + 0x58) + i;
            MI_CpuCopy8(d_021D8B40 + i, &record->detail, 2);
            record->value = values[i];
            record->kind = DWC_AddMatchKeyInt(record->kind, (char *)(&record->detail), (int *)record);
        }
        STD_TSPrintf((char *)dispCtx + 0xb8, d_021D8B50, *(unsigned int *)&((struct GtsnegoDispCtx *)dispCtx)->tradeMode, 1);
        if (DWC_RAP_StartMatchWithFilter((int)dispCtx + 0xb8, 2, (int)GTSNEGO_DISP_ScoreMatch, (int)dispCtx)) {
            GFL_NET_STATE_WifiEnterFriendMatch();
            DWC_RAP_SetVchatEnabled(0);
            GTSNEGO_MSG_CreateConfirmUi(*(u8 * *)&((struct GtsnegoDispCtx *)dispCtx)->msgCtx, (int)GTSNEGO_DISP_OnDisconnectCallback, (int)dispCtx);
            GTSNEGO_DISP_SetStateCallback(((int *)dispCtx), GTSNEGO_DISP_HandleTradeKeys, 0x41d);
            return;
        }
        GFL_NET_STATE_SetError(0, 0, 0, 0x3f1);
    }
}







void GTSNEGO_DISP_OnMenuCallback(void *selection,int event,u8 *dispCtx) { if (event==0 && ((struct GtsnegoDispCtx *)dispCtx)->rowInputCallback) { GTSNEGO_DISP_SetCursorState(*(u8 * *)&((struct GtsnegoDispCtx *)dispCtx)->actorSys,((struct GtsnegoDispCtx *)dispCtx)->tooltipWin,9); UI_SetInputMode(1); if ((*(int (**)(void *,void *))(dispCtx+4))(selection,dispCtx)==0) return; } }







void GTSNEGO_DISP_OnConfirmDone(struct GtsnegoDispCtx *dispCtx)
{
    if (APP_TASKMENU_WIN_IsFinish(dispCtx->tooltipWin)) {
        APP_TASKMENU_WIN_Delete(dispCtx->tooltipWin);
        *(int *)&dispCtx->tooltipWin = 0;
        BG_SYS_MarkTileDirty(5);
        GTSNEGO_MSG_PrintWindow(dispCtx->msgCtx, 14);
        GTSNEGO_MSG_CreateIdleUi(dispCtx->actorSys);
        GTSNEGO_MSG_PrintStatus(dispCtx->msgCtx, 13);
        GTSNEGO_DISP_SetTradePalette(dispCtx->actorSys, 1, 2);
        ((struct GtsnegoParentCtx *)dispCtx->parentCtx)->screenState = 2;
        GTSNEGO_DISP_SetCursorState(dispCtx->actorSys, 0, 9);
        GTSNEGO_DISP_SetStateCallback(((int *)dispCtx), GTSNEGO_DISP_StartMatchmaking, 0x460);
    }
}







void GTSNEGO_DISP_HandleConfirmKeys(u8 *dispCtx)
{
    int changed = 0;
    int done = 0;
    u8 *touchbar = (u8 *)GTSNEGO_DISP_GetTouchbar(((struct GtsnegoDispCtx *)dispCtx)->actorSys);
    if (GTSNEGO_MSG_UpdatePrintStream(((struct GtsnegoDispCtx *)dispCtx)->msgCtx)) {
        if (TOUCHBAR_IsBusy(touchbar) == 0) {
            GTSNEGO_MSG_UpdateButtons((char *)(*(int *)&((struct GtsnegoDispCtx *)dispCtx)->msgCtx));
            if (KEY_GetTrg() != 0 && UI_GetInputMode() == 1) {
                GTSNEGO_DISP_SetCursorState(((struct GtsnegoDispCtx *)dispCtx)->actorSys, ((struct GtsnegoDispCtx *)dispCtx)->tooltipWin, ((struct GtsnegoDispCtx *)dispCtx)->buttonCursor);
                UI_SetInputMode(changed);
                return;
            }
            if (KEY_GetTrg() == 0x20) GTSNEGO_DISP_MoveCursorVertical(0, (char *)dispCtx);
            if (KEY_GetTrg() == 0x10) GTSNEGO_DISP_MoveCursorVertical(1, (char *)dispCtx);
            if (KEY_GetTrg() == 0x40) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                changed = 1;
                if (((struct GtsnegoDispCtx *)dispCtx)->buttonCursor != 2) --((struct GtsnegoDispCtx *)dispCtx)->buttonCursor;
            }
            if (KEY_GetTrg() == 0x80) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                changed = 1;
                if (((struct GtsnegoDispCtx *)dispCtx)->buttonCursor != 5) ++((struct GtsnegoDispCtx *)dispCtx)->buttonCursor;
            }
            if (KEY_GetTrg() == 1 && ((struct GtsnegoDispCtx *)dispCtx)->buttonCursor == 5) {
                GFL_USE_PlaySeDefaultVolume(0x54c);
                GTSNEGO_MSG_SetCursorAnimSeq(((struct GtsnegoDispCtx *)dispCtx)->actorSys, ((struct GtsnegoDispCtx *)dispCtx)->buttonCursor);
                APP_TASKMENU_WIN_SetDecide(((struct GtsnegoDispCtx *)dispCtx)->tooltipWin, 1);
                GTSNEGO_DISP_SetStateCallback(((int *)dispCtx), GTSNEGO_DISP_OnConfirmDone, 0x4ca);
                return;
            }
            if (changed)
                GTSNEGO_DISP_SetCursorState(((struct GtsnegoDispCtx *)dispCtx)->actorSys, ((struct GtsnegoDispCtx *)dispCtx)->tooltipWin, ((struct GtsnegoDispCtx *)dispCtx)->buttonCursor);
            if (TOUCHPANEL_HitTrg(d_021D88D0) == 0) {
                UI_SetInputMode(1);
                GFL_USE_PlaySeDefaultVolume(0x54c);
                APP_TASKMENU_WIN_SetDecide(((struct GtsnegoDispCtx *)dispCtx)->tooltipWin, 1);
                GTSNEGO_DISP_SetStateCallback(((int *)dispCtx), GTSNEGO_DISP_OnConfirmDone, 0x4f2);
                return;
            }
        }
        TOUCHBAR_Update((struct TouchBar *)GTSNEGO_DISP_GetTouchbar(((struct GtsnegoDispCtx *)dispCtx)->actorSys));
        if (TOUCHBAR_GetPressedButtonIdIfDone((u8 *)GTSNEGO_DISP_GetTouchbar(((struct GtsnegoDispCtx *)dispCtx)->actorSys)) == 1) done = 1;
        if (done) {
            int zero = 0;
            BG_SYS_SetPlaneVisible(4, 0);
            GTSNEGO_DISP_SetCursorState(((struct GtsnegoDispCtx *)dispCtx)->actorSys, ((struct GtsnegoDispCtx *)dispCtx)->tooltipWin, 9);
            GTSNEGO_MSG_DeleteButtonsKeep(((struct GtsnegoDispCtx *)dispCtx)->msgCtx);
            GTSNEGO_DISP_ResetActors(*(u8 * *)&((struct GtsnegoDispCtx *)dispCtx)->actorSys);
            APP_TASKMENU_WIN_Delete(((struct GtsnegoDispCtx *)dispCtx)->tooltipWin);
            *(int *)&((struct GtsnegoDispCtx *)dispCtx)->tooltipWin = zero;
            BG_SYS_MarkTileDirty(5);
            GTSNEGO_DISP_SetStateCallback(((int *)dispCtx), GTSNEGO_DISP_ShowPartySelect, 0x50b);
        }
    }
}







void GTSNEGO_DISP_CreateConfirmUi(u8 *dispCtx)
{
    ((struct GtsnegoDispCtx *)dispCtx)->tradeMode = 0;
    TOUCHBAR_SetAllButtonsVisible((u8 *)GTSNEGO_DISP_GetTouchbar(((struct GtsnegoDispCtx *)dispCtx)->actorSys), 1);
    GTSNEGO_MSG_ClearRows(((struct GtsnegoDispCtx *)dispCtx)->msgCtx);
    GTSNEGO_DISP_RedrawActors(((struct GtsnegoDispCtx *)dispCtx)->actorSys);
    *(void * *)&((struct GtsnegoDispCtx *)dispCtx)->rowInputCallback = GTSNEGO_DISP_OnRowCursorMoved;
    GTSNEGO_MSG_CreateListUi(((struct GtsnegoDispCtx *)dispCtx)->msgCtx, (int)GTSNEGO_DISP_OnMenuCallback, (int)dispCtx, ((struct GtsnegoDispCtx *)dispCtx)->rowAIndex, ((struct GtsnegoDispCtx *)dispCtx)->rowBIndex, ((struct GtsnegoDispCtx *)dispCtx)->rowCIndex);
    GTSNEGO_MSG_PrintWindow(((struct GtsnegoDispCtx *)dispCtx)->msgCtx, 20);
    ((struct GtsnegoDispCtx *)dispCtx)->tooltipWin = GTSNEGO_MSG_CreateTooltip(((struct GtsnegoDispCtx *)dispCtx)->msgCtx, 18);
    if (UI_GetInputMode() == 0) {
        GTSNEGO_DISP_SetCursorState(((struct GtsnegoDispCtx *)dispCtx)->actorSys, 0, ((struct GtsnegoDispCtx *)dispCtx)->buttonCursor);
        if (((struct GtsnegoDispCtx *)dispCtx)->buttonCursor == 5)
            APP_TASKMENU_WIN_SetActive(((struct GtsnegoDispCtx *)dispCtx)->tooltipWin, 1);
    } else {
        GTSNEGO_DISP_SetCursorState(((struct GtsnegoDispCtx *)dispCtx)->actorSys, 0, 9);
    }
    BG_SYS_MarkTileDirty(6);
    GTSNEGO_DISP_SetStateCallback(((int *)dispCtx), GTSNEGO_DISP_HandleConfirmKeys, 0x537);
}







void *GTSNEGO_DISP_GetEntry(void **list,int index) { int n; n=TRADE_HISTORY_GetPartnerCount(GAME_DATA_GetTradeHistory(list)); if (index>=n || index<0) return 0; return TRADE_HISTORY_GetPartner(GAME_DATA_GetTradeHistory(list),index); }






void *GTSNEGO_DISP_GetEntryClamped(void **list,int index) { int n; n=TRADE_HISTORY_GetPartnerCount(GAME_DATA_GetTradeHistory(list)); if (index<0) index=0; if (index>=n) index=n-1; return TRADE_HISTORY_GetPartner(GAME_DATA_GetTradeHistory(list),index); }







/*
 * Addresses are Black-image addresses.
 */
void GTSNEGO_DISP_ShowSubPlanes(u8 *dispCtx)
{
    GTSNEGO_DISP_ShowPartySelect(dispCtx);
    BG_SYS_SetSubVisiblePlanes(0x1f);
}









void GTSNEGO_DISP_Teardown(struct GtsnegoDispCtx *dispCtx) { GTSNEGO_MSG_Teardown(*(u8 * *)&dispCtx->actorSys); GTSNEGO_MSG_DeleteAll(*(char * *)&dispCtx->msgCtx); GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_ShowSubPlanes, 0x5c5); }










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
        GTSNEGO_DISP_SetStateCallback(((int *)dispCtx), GTSNEGO_DISP_Teardown, 0x5dd);
    }
}










void GTSNEGO_DISP_OnDisconnectCallback(int unused, int buttonIndex, int *dispCtx)
{
    if (buttonIndex == 0 && *(void **)dispCtx == GTSNEGO_DISP_HandleTradeKeys) {
        GTSNEGO_MSG_SetDecide(*(u8 * *)&((struct GtsnegoDispCtx *)dispCtx)->msgCtx);
        GFL_NET_STATE_WifiDisconnect(1);
        UI_SetInputMode(1);
        GFL_USE_PlaySeDefaultVolume(0x551);
        GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_OnDisconnect, 0x5f5);
    }
}








void GTSNEGO_DISP_CreateExitTooltip(struct GtsnegoDispCtx *dispCtx) { dispCtx->tooltipWin=GTSNEGO_MSG_CreateTooltip(*(char * *)&dispCtx->msgCtx,44); GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_HandleListInput, 0x5ff); }







void GTSNEGO_DISP_OnExitMenuDone(struct GtsnegoDispCtx *dispCtx)
{
    int state;
    if (APP_TASKMENU_IsFinish(dispCtx->taskMenu)) {
        int zero;
        state = APP_TASKMENU_GetCursorPos(dispCtx->taskMenu);
        GTSNEGO_MSG_CloseMenu(*(int *)&dispCtx->taskMenu);
        zero = 0;
        *(int *)&dispCtx->taskMenu = zero;
        TOUCHBAR_SetButtonVisible((unsigned char *)GTSNEGO_DISP_GetTouchbar(dispCtx->actorSys), 1, 1);
        switch (state) {
        case 0:
            GTSNEGO_MSG_PrintWindow(dispCtx->msgCtx, 0xe);
            GTSNEGO_MSG_CreateIdleUi(dispCtx->actorSys);
            GTSNEGO_MSG_PrintStatus(dispCtx->msgCtx, 0xd);
            dispCtx->rowAIndex = zero;
            dispCtx->rowBIndex = zero;
            dispCtx->rowCIndex = zero;
            ((struct GtsnegoParentCtx *)dispCtx->parentCtx)->screenState = 3;
            GTSNEGO_DISP_SetStateCallback(((int *)dispCtx), GTSNEGO_DISP_StartMatchmaking, 0x614);
            return;
        case 1:
            GTSNEGO_DISP_SetTradePalette(dispCtx->actorSys, zero, zero);
            GTSNEGO_MSG_PrintWindow(dispCtx->msgCtx, 0x13);
            if (UI_GetInputMode() == 0)
                GTSNEGO_DISP_SetCursorState(dispCtx->actorSys, 0, dispCtx->listCursorRow);
            else
                GTSNEGO_DISP_SetCursorState(dispCtx->actorSys, 0, 9);
            GTSNEGO_MSG_RestartIconAnim(dispCtx->actorSys, 1);
            GTSNEGO_DISP_SetStateCallback(((int *)dispCtx), GTSNEGO_DISP_CreateExitTooltip, 0x620);
            break;
        }
    }
}






void GTSNEGO_DISP_OpenExitMenu(struct GtsnegoDispCtx *dispCtx)
{
    if (GTSNEGO_MSG_UpdatePrintStream(dispCtx->msgCtx)) {
        TOUCHBAR_SetButtonVisible((unsigned char *)GTSNEGO_DISP_GetTouchbar(dispCtx->actorSys), 1, 0);
        dispCtx->taskMenu = GTSNEGO_MSG_OpenMenuB(dispCtx->msgCtx, 1);
        GTSNEGO_DISP_SetTradePalette(dispCtx->actorSys, 1, 1);
        GTSNEGO_MSG_RestartIconAnim(dispCtx->actorSys, 0);
        GTSNEGO_DISP_SetStateCallback(((int *)dispCtx), GTSNEGO_DISP_OnExitMenuDone, 0x634);
    }
}









/*
 * lever: The caller has no halfword truncation before GTSNEGO_MSG_PrintWindow;
 * widen its copied u16 argument to int. Explicit calls in both branches
 * hoist the shared p+64 load; a ternary places it after the selection.
 */
void GTSNEGO_DISP_ShowListMessage(struct GtsnegoDispCtx *dispCtx) { if (dispCtx->selectedListIndex==-1) GTSNEGO_MSG_PrintWindow(*(u8 * *)&dispCtx->msgCtx,45); else GTSNEGO_MSG_PrintWindow(*(u8 * *)&dispCtx->msgCtx,31); GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_OpenExitMenu, 0x646); }









void GTSNEGO_DISP_EndList(struct GtsnegoDispCtx *dispCtx) { BG_SYS_SetPlaneVisible(4,0); GTSNEGO_MSG_TeardownTileRows(*(u8 * *)&dispCtx->actorSys); GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_ShowPartySelect, 0x64e); }









/*
 * extent: two zero padding bytes at 0x021D5282 precede labelled 0x021D5284.
 */
int GTSNEGO_DISP_ListCursorUp(u8 *dispCtx)
{
    int result = GTSNEGO_MSG_CursorUp(((struct GtsnegoDispCtx *)dispCtx)->actorSys, (int *)(dispCtx + 0x150));
    switch (result) {
    case 0: break;
    case 1:
        if (((struct GtsnegoDispCtx *)dispCtx)->listCursorRow != 6)
            (((struct GtsnegoDispCtx *)dispCtx)->listCursorRow)--;
        break;
    case 2: {
        int index;
        GTSNEGO_MSG_SetScrollState(((struct GtsnegoDispCtx *)dispCtx)->actorSys, 1);
        index = ((struct GtsnegoDispCtx *)dispCtx)->listScrollTop - 1;
        if (index >= 0)
            GTSNEGO_MSG_PrintListEntryN(((struct GtsnegoDispCtx *)dispCtx)->msgCtx, ((struct GtsnegoDispCtx *)dispCtx)->gameData, index);
        break;
    }
    }
    return result;
}









int GTSNEGO_DISP_ListCursorDown(u8 *dispCtx)
{
    int result = GTSNEGO_MSG_CursorDown(((struct GtsnegoDispCtx *)dispCtx)->actorSys, (int *)(dispCtx + 0x150));
    switch (result) {
    case 0: break;
    case 1:
        if (((struct GtsnegoDispCtx *)dispCtx)->listCursorRow != 8)
            (((struct GtsnegoDispCtx *)dispCtx)->listCursorRow)++;
        break;
    case 2:
        GTSNEGO_MSG_SetScrollState(((struct GtsnegoDispCtx *)dispCtx)->actorSys, 2);
        GTSNEGO_MSG_PrintListEntryAt(((struct GtsnegoDispCtx *)dispCtx)->msgCtx, ((struct GtsnegoDispCtx *)dispCtx)->gameData, ((struct GtsnegoDispCtx *)dispCtx)->listScrollTop + 2);
        break;
    }
    return result;
}









void GTSNEGO_DISP_OnListConfirmDone(struct GtsnegoDispCtx *dispCtx)
{
    if (APP_TASKMENU_WIN_IsFinish(dispCtx->tooltipWin)) {
        APP_TASKMENU_WIN_Delete(dispCtx->tooltipWin);
        *(int *)&dispCtx->tooltipWin = 0;
        dispCtx->selectedListIndex = -1;
        GTSNEGO_DISP_SetCursorState(dispCtx->actorSys, 0, 9);
        BG_SYS_MarkTileDirty(5);
        GTSNEGO_DISP_SetStateCallback(((int *)dispCtx), GTSNEGO_DISP_ShowListMessage, 0x6ba);
    }
}










void GTSNEGO_DISP_DeleteMenuWindow(u8 *dispCtx)
{
    if (((struct GtsnegoDispCtx *)dispCtx)->tooltipWin) {
        APP_TASKMENU_WIN_Delete(((struct GtsnegoDispCtx *)dispCtx)->tooltipWin);
        BG_SYS_MarkTileDirty(5);
        *(u32 *)&((struct GtsnegoDispCtx *)dispCtx)->tooltipWin = 0;
    }
}









void GTSNEGO_DISP_HandleListInput(Ctx *dispCtx)
{
    int out;
    int touchbar;
    int acc = 0;
    int i;
    int sel;
    int x, y;
    out = 0;
    touchbar = GTSNEGO_DISP_GetTouchbar(dispCtx->actorSys);
    if (GTSNEGO_MSG_UpdatePrintStream(dispCtx->msgCtx) == 0)
        return;
    if (TOUCHBAR_IsBusy((u8 *)touchbar) != 0)
        goto end;
    touchbar = GTSNEGO_MSG_StepScroll(dispCtx->actorSys, &out);
    if (out == 1) {
        GTSNEGO_MSG_DrawTileRows(dispCtx->actorSys, dispCtx->gameData, dispCtx->listScrollTop - 2);
        GTSNEGO_MSG_ShiftListUp(dispCtx->msgCtx);
        GTSNEGO_MSG_ScrollListUp(dispCtx->actorSys, GTSNEGO_DISP_GetEntryClamped(dispCtx->gameData, dispCtx->listScrollTop - 2));
    } else if (out == 2) {
        GTSNEGO_MSG_DrawTileRows(dispCtx->actorSys, dispCtx->gameData, dispCtx->listScrollTop - 2);
        GTSNEGO_MSG_ShiftListDown(dispCtx->msgCtx);
        GTSNEGO_MSG_ScrollListDown(dispCtx->actorSys, GTSNEGO_DISP_GetEntryClamped(dispCtx->gameData, dispCtx->listScrollTop + 3));
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
            touchbar = GTSNEGO_DISP_ListCursorDown((u8 *)dispCtx);
            acc |= touchbar;
            GTSNEGO_MSG_ClearScrollState(dispCtx->actorSys);
            if (touchbar == 0)
                break;
            if (touchbar == 1) {
                i--;
            } else {
                GTSNEGO_MSG_ScrollAllRows(dispCtx->actorSys, 1);
                GTSNEGO_MSG_DrawTileRows(dispCtx->actorSys, dispCtx->gameData, dispCtx->listScrollTop - 2);
                GTSNEGO_MSG_ShiftListDown(dispCtx->msgCtx);
                GTSNEGO_MSG_ScrollListDown(dispCtx->actorSys, GTSNEGO_DISP_GetEntryClamped(dispCtx->gameData, dispCtx->listScrollTop + 3));
                GTSNEGO_DISP_SetCursorState(dispCtx->actorSys, 0, dispCtx->listCursorRow);
            }
        }
    }
    if (KEY_GetRepeat() == 0x200) {
        acc = 0;
        for (i = 0; i < 3; i++) {
            touchbar = GTSNEGO_DISP_ListCursorUp((u8 *)dispCtx);
            acc |= touchbar;
            GTSNEGO_MSG_ClearScrollState(dispCtx->actorSys);
            if (touchbar == 0)
                break;
            if (touchbar == 1) {
                i--;
            } else {
                GTSNEGO_DISP_SetCursorState(dispCtx->actorSys, 0, dispCtx->listCursorRow);
                GTSNEGO_MSG_ScrollAllRows(dispCtx->actorSys, 0);
                GTSNEGO_MSG_DrawTileRows(dispCtx->actorSys, dispCtx->gameData, dispCtx->listScrollTop - 2);
                GTSNEGO_MSG_ShiftListUp(dispCtx->msgCtx);
                GTSNEGO_MSG_ScrollListUp(dispCtx->actorSys, GTSNEGO_DISP_GetEntryClamped(dispCtx->gameData, dispCtx->listScrollTop - 2));
            }
        }
    }
    if (KEY_GetRepeat() == 0x40)
        acc = GTSNEGO_DISP_ListCursorUp((u8 *)dispCtx);
    if (KEY_GetRepeat() == 0x80)
        acc = GTSNEGO_DISP_ListCursorDown((u8 *)dispCtx);
    if (acc != 0) {
        GFL_USE_PlaySeDefaultVolume(0x548);
        GTSNEGO_MSG_SetIconY(dispCtx->actorSys, dispCtx->listScrollTop + dispCtx->listCursorRow - 6, dispCtx->listCount);
        GTSNEGO_DISP_SetCursorState(dispCtx->actorSys, 0, dispCtx->listCursorRow);
        return;
    }
    if (KEY_GetTrg() == 1) {
        GFL_USE_PlaySeDefaultVolume(0x54C);
        GTSNEGO_MSG_SetCursorAnimSeq(dispCtx->actorSys, dispCtx->listCursorRow);
        dispCtx->selectedListIndex = dispCtx->listScrollTop + dispCtx->listCursorRow - 6;
        GTSNEGO_DISP_DeleteMenuWindow((u8 *)dispCtx);
        GTSNEGO_DISP_SetStateCallback(((int *)dispCtx), GTSNEGO_DISP_ShowListMessage, 0x760);
        return;
    }
    if (KEY_GetTrg() == 8) {
        GFL_USE_PlaySeDefaultVolume(0x54C);
        APP_TASKMENU_WIN_SetDecide(dispCtx->tooltipWin, 1);
        GTSNEGO_DISP_SetStateCallback(((int *)dispCtx), GTSNEGO_DISP_OnListConfirmDone, 0x766);
        return;
    }
    sel = TOUCHPANEL_HitTrg(d_021D88D8);
    switch (sel) {
    case 3:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        APP_TASKMENU_WIN_SetDecide(dispCtx->tooltipWin, 1);
        GTSNEGO_DISP_SetStateCallback(((int *)dispCtx), GTSNEGO_DISP_OnListConfirmDone, 0x770);
        return;
    case 2:
        if (dispCtx->listCount < 3)
            break;
    case 1:
        if (dispCtx->listCount < 2)
            break;
    case 0:
        UI_SetInputMode(1);
        dispCtx->listCursorRow = sel + 6;
        GTSNEGO_DISP_SetCursorState(dispCtx->actorSys, 0, dispCtx->listCursorRow);
        GTSNEGO_MSG_SetCursorAnimSeq(dispCtx->actorSys, dispCtx->listCursorRow);
        dispCtx->selectedListIndex = dispCtx->listScrollTop + dispCtx->listCursorRow - 6;
        GTSNEGO_MSG_SetCursorIndex(dispCtx->actorSys, &dispCtx->listCount, sel);
        GTSNEGO_MSG_SetIconY(dispCtx->actorSys, dispCtx->listScrollTop + dispCtx->listCursorRow - 6, dispCtx->listCount);
        GFL_USE_PlaySeDefaultVolume(0x54C);
        GTSNEGO_DISP_DeleteMenuWindow((u8 *)dispCtx);
        GTSNEGO_DISP_SetStateCallback(((int *)dispCtx), GTSNEGO_DISP_ShowListMessage, 0x78B);
        return;
    }
    if (TOUCHPANEL_HitCont(d_021D88C8) != 0)
        goto end;
    if (TOUCHPANEL_GetPointCont((u32 *)(&x), (u32 *)(&y)) == 1) {
        touchbar = GTSNEGO_MSG_SetIconYClamped((char *)dispCtx->actorSys, y, dispCtx->listCount);
        if (dispCtx->listScrollTop != touchbar) {
            dispCtx->listScrollTop = touchbar;
            GTSNEGO_MSG_PrintListRange(dispCtx->msgCtx, dispCtx->gameData, touchbar - 2);
            GTSNEGO_MSG_FillListRange(dispCtx->actorSys, dispCtx->gameData, dispCtx->listScrollTop - 2);
            GTSNEGO_MSG_DrawTileRows(dispCtx->actorSys, dispCtx->gameData, dispCtx->listScrollTop - 2);
            GFL_USE_PlaySeDefaultVolume(0x548);
        }
    }
    return;
end:
    TOUCHBAR_Update((struct TouchBar *)GTSNEGO_DISP_GetTouchbar(dispCtx->actorSys));
    if (TOUCHBAR_GetPressedButtonIdIfDone((u8 *)GTSNEGO_DISP_GetTouchbar(dispCtx->actorSys)) == 1) {
        BG_SYS_SetPlaneVisible(4, 0);
        BG_SYS_SetPlaneVisible(6, 0);
        GTSNEGO_DISP_DeleteMenuWindow((u8 *)dispCtx);
        GTSNEGO_DISP_SetCursorState(dispCtx->actorSys, dispCtx->tooltipWin, 9);
        GTSNEGO_MSG_TeardownActorList(dispCtx->actorSys);
        GTSNEGO_MSG_ClearRows(dispCtx->msgCtx);
        GTSNEGO_DISP_SetStateCallback(((int *)dispCtx), GTSNEGO_DISP_EndList, 0x7AD);
    }
}








void GTSNEGO_DISP_WaitSelectStart(struct GtsnegoDispCtx *dispCtx)
{
    if (GTSNEGO_MSG_UpdatePrintStream(dispCtx->msgCtx)) {
        if (--dispCtx->waitFrames <= 0) {
            GTSNEGO_MSG_PrintWindow(dispCtx->msgCtx, 0x20);
            TOUCHBAR_SetAllButtonsVisible((u8 *)GTSNEGO_DISP_GetTouchbar(dispCtx->actorSys), 1);
            GTSNEGO_DISP_SetStateCallback(((int *)dispCtx), GTSNEGO_DISP_HandlePartyInput, 0x7c7);
            if (UI_GetInputMode() == 0)
                GTSNEGO_DISP_SetCursorState(dispCtx->actorSys, 0, dispCtx->partyCursor);
        }
    }
}








void GTSNEGO_DISP_ShowPokemonList(struct GtsnegoDispCtx *dispCtx)
{
    int flag = 1;
    int n = TRADE_HISTORY_GetPartnerCount(GAME_DATA_GetTradeHistory(*(void ** *)&dispCtx->gameData));
    dispCtx->tradeMode = flag;
    if (n == 0) {
        GTSNEGO_MSG_PrintWindow(dispCtx->msgCtx, 0x1d);
        dispCtx->waitFrames = 0x78;
        GTSNEGO_DISP_SetStateCallback(((int *)dispCtx), GTSNEGO_DISP_WaitSelectStart, 0x7e7);
        return;
    }
    dispCtx->listCount = n;
    GTSNEGO_MSG_PrintWindow(dispCtx->msgCtx, 0x13);
    if (UI_GetInputMode() == 0)
        GTSNEGO_DISP_SetCursorState(dispCtx->actorSys, 0, dispCtx->listCursorRow);
    else
        GTSNEGO_DISP_SetCursorState(dispCtx->actorSys, 0, 9);
    GTSNEGO_MSG_ClearRows(dispCtx->msgCtx);
    if (n <= 3) flag = 0;
    GTSNEGO_MSG_InitWindows(*(u8 * *)&dispCtx->actorSys, flag);
    GTSNEGO_MSG_PrintList(*(char * *)&dispCtx->msgCtx, dispCtx->gameData);
    GTSNEGO_MSG_PrintListRange(dispCtx->msgCtx, dispCtx->gameData, dispCtx->listScrollTop - 2);
    GTSNEGO_MSG_FillListRange(dispCtx->actorSys, dispCtx->gameData, dispCtx->listScrollTop - 2);
    GTSNEGO_MSG_DrawTileRows(dispCtx->actorSys, dispCtx->gameData, dispCtx->listScrollTop - 2);
    dispCtx->tooltipWin = GTSNEGO_MSG_CreateTooltip(*(char * *)&dispCtx->msgCtx, 0x2c);
    GTSNEGO_MSG_SetIconY(dispCtx->actorSys, dispCtx->listScrollTop + dispCtx->listCursorRow - 6, dispCtx->listCount);
    GTSNEGO_DISP_SetStateCallback(((int *)dispCtx), GTSNEGO_DISP_HandleListInput, 0x815);
}









void GTSNEGO_DISP_ShowPartySelect(u8 *dispCtx)
{
    GTSNEGO_MSG_SetupRowBg(((struct GtsnegoDispCtx *)dispCtx)->actorSys);
    if (((struct GtsnegoDispCtx *)dispCtx)->restoreBrightness) {
        if ((((struct GtsnegoDispCtx *)dispCtx)->restoreDelay)++ < 3)
            return;
        GFL_NET_ERR_RestoreBrightness();
        ((struct GtsnegoDispCtx *)dispCtx)->restoreBrightness = 0;
    }
    if (UI_GetInputMode() == 0)
        GTSNEGO_DISP_SetCursorState(((struct GtsnegoDispCtx *)dispCtx)->actorSys, 0, ((struct GtsnegoDispCtx *)dispCtx)->partyCursor);
    else
        GTSNEGO_DISP_SetCursorState(((struct GtsnegoDispCtx *)dispCtx)->actorSys, 0, 9);
    GTSNEGO_MSG_CreateYesNoUi(((struct GtsnegoDispCtx *)dispCtx)->msgCtx, (int)GTSNEGO_DISP_OnMenuCallback, (int)dispCtx);
    *(void (**)(void))(dispCtx + 4) = (void (*)(void))GTSNEGO_DISP_StartTrade;
    if ((int)POKEPARTY_GetNonEggCount(GAME_DATA_GetMyParty(((struct GtsnegoDispCtx *)dispCtx)->gameData)) < 2)
        ((struct GtsnegoDispCtx *)dispCtx)->cannotTrade = 1;
    if (((struct GtsnegoDispCtx *)dispCtx)->cannotTrade == 0)
        GTSNEGO_MSG_PrintWindow(((struct GtsnegoDispCtx *)dispCtx)->msgCtx, 0x20);
    else
        GTSNEGO_MSG_PrintWindow(((struct GtsnegoDispCtx *)dispCtx)->msgCtx, 0x2b);
    BG_SYS_SetPlaneVisible(4, 1);
    BG_SYS_SetPlaneVisible(6, 1);
    GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_HandlePartyInput, 0x86c);
}









int GTSNEGO_DISP_SelectParty(u8 *dispCtx,int position) { if (GTSNEGO_MSG_SetCursorAnimSeq(((struct GtsnegoDispCtx *)dispCtx)->actorSys,position)) { TOUCHBAR_SetAllButtonsVisible((u8 *)GTSNEGO_DISP_GetTouchbar((u8 *)(((struct GtsnegoDispCtx *)dispCtx)->actorSys)),0); GFL_USE_PlaySeDefaultVolume(1356); return position; } return 9; }










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
        GTSNEGO_MSG_ClearRows(*(char * *)&dispCtx->msgCtx);
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
        GTSNEGO_MSG_CloseMenu(*(int *)&dispCtx->taskMenu);
        *(int *)&dispCtx->taskMenu = 0;
        switch (state) {
        case 0:
            ((struct GtsnegoParentCtx *)dispCtx->parentCtx)->screenState = 1;
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
            TOUCHBAR_SetButtonVisible((unsigned char *)GTSNEGO_DISP_GetTouchbar(dispCtx->actorSys), 1, 1);
            GTSNEGO_DISP_SetTradePalette(dispCtx->actorSys, 0, 0);
            GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_HandlePartyInput, 0x8c3);
            break;
        }
    }
}









void GTSNEGO_DISP_OpenPartyMenu(struct GtsnegoDispCtx *dispCtx)
{
    if (GTSNEGO_MSG_UpdatePrintStream(dispCtx->msgCtx)) {
        TOUCHBAR_SetButtonVisible((unsigned char *)GTSNEGO_DISP_GetTouchbar(dispCtx->actorSys), 1, 0);
        dispCtx->taskMenu = GTSNEGO_MSG_OpenMenu(dispCtx->msgCtx, 1);
        GTSNEGO_DISP_SetTradePalette(dispCtx->actorSys, 1, 0);
        GTSNEGO_DISP_SetCursorState(dispCtx->actorSys, 0, 9);
        GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_OnPartyMenuDone, 0x8d4);
    }
}









void GTSNEGO_DISP_HandlePartyInput(u8 *dispCtx)
{
    int changed = 0;
    u8 *touchbar = (u8 *)GTSNEGO_DISP_GetTouchbar(((struct GtsnegoDispCtx *)dispCtx)->actorSys);
    if (GTSNEGO_MSG_UpdatePrintStream(((struct GtsnegoDispCtx *)dispCtx)->msgCtx)) {
        if (TOUCHBAR_IsBusy(touchbar) == 0) {
            if (KEY_GetTrg() != 0 && UI_GetInputMode() == 1) {
                GTSNEGO_DISP_SetCursorState(((struct GtsnegoDispCtx *)dispCtx)->actorSys, 0, ((struct GtsnegoDispCtx *)dispCtx)->partyCursor);
                UI_SetInputMode(changed);
                return;
            }
            if (KEY_GetTrg() == 1) {
                if (((struct GtsnegoDispCtx *)dispCtx)->cannotTrade == 0) {
                    GTSNEGO_DISP_SelectParty(dispCtx, ((struct GtsnegoDispCtx *)dispCtx)->partyCursor);
                    GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_OnPartySelected, 0x8f4);
                    return;
                }
                GFL_USE_PlaySeDefaultVolume(0x551);
            }
            if (KEY_GetTrg() == 0x40) {
                changed = 1;
                GFL_USE_PlaySeDefaultVolume(0x548);
                ((struct GtsnegoDispCtx *)dispCtx)->partyCursor = 0;
            }
            if (KEY_GetTrg() == 0x80) {
                changed = 1;
                GFL_USE_PlaySeDefaultVolume(0x548);
                ((struct GtsnegoDispCtx *)dispCtx)->partyCursor = 1;
            }
            if (changed)
                GTSNEGO_DISP_SetCursorState(((struct GtsnegoDispCtx *)dispCtx)->actorSys, 0, ((struct GtsnegoDispCtx *)dispCtx)->partyCursor);
            GTSNEGO_MSG_UpdateButtons((char *)(*(int *)&((struct GtsnegoDispCtx *)dispCtx)->msgCtx));
        }
        TOUCHBAR_Update((struct TouchBar *)GTSNEGO_DISP_GetTouchbar(((struct GtsnegoDispCtx *)dispCtx)->actorSys));
        if (TOUCHBAR_GetPressedButtonIdIfDone((u8 *)GTSNEGO_DISP_GetTouchbar(((struct GtsnegoDispCtx *)dispCtx)->actorSys)) == 1) {
            ((struct GtsnegoDispCtx *)dispCtx)->waitFrames = 1;
            GTSNEGO_MSG_PrintWindow(((struct GtsnegoDispCtx *)dispCtx)->msgCtx, 0x2a);
            if (UI_GetInputMode() == 1)
                GTSNEGO_DISP_SetCursorState(((struct GtsnegoDispCtx *)dispCtx)->actorSys, 0, 9);
            GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_OpenPartyMenu, 0x916);
        }
    }
}









void GTSNEGO_DISP_ResetScreen(u8 *dispCtx)
{
    if (((struct GtsnegoParentCtx *)((struct GtsnegoDispCtx *)dispCtx)->parentCtx)->screenState != 1) {
        int zero = 0;
        GFL_NET_SetAutoExit(0);
        GFL_NET_SetLoginOption(0);
        GTSNEGO_MSG_DeleteDraw(*(u8 * *)&((struct GtsnegoDispCtx *)dispCtx)->msgCtx);
        GTSNEGO_DISP_SetTradePalette(((struct GtsnegoDispCtx *)dispCtx)->actorSys, 0, 0);
        BG_SYS_SetPlaneVisible(4, 0);
        GTSNEGO_MSG_Teardown(((struct GtsnegoDispCtx *)dispCtx)->actorSys);
        GTSNEGO_MSG_DeleteWindow((char *)(*(int *)&((struct GtsnegoDispCtx *)dispCtx)->msgCtx));
        GTSNEGO_MSG_DeleteAll(*(char * *)&((struct GtsnegoDispCtx *)dispCtx)->msgCtx);
        GTSNEGO_DISP_SetCursorState(((struct GtsnegoDispCtx *)dispCtx)->actorSys, 0, 9);
        *(int *)&((struct GtsnegoDispCtx *)dispCtx)->restoreBrightness = 1;
        *(int *)&((struct GtsnegoDispCtx *)dispCtx)->restoreDelay = zero;
        ((struct GtsnegoParentCtx *)((struct GtsnegoDispCtx *)dispCtx)->parentCtx)->screenState = 1;
        GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_ShowPartySelect, 0x937);
    }
}








/*
 * volatile: hardware halfword registers written at 0x021D5C78 and 0x021D5C7E.
 * prototype: 0203064C r2 explicitly loaded despite two-arg definition;
 * 0203159C r0 allocation result used despite void matched definition.
 */
int GTSNEGO_DISP_Create(void *owner, int unused, u8 *parentCtx)
{
    u8 *dispCtx;
    int zero = 0;
    GFL_HEAP_CreateChildHeap(1, 0x1f, 0x38000);
    *(volatile u16 *)0x04000050 = zero;
    *(volatile u16 *)0x04001050 = zero;
    WIPE_SetBrightnessFadeOut(0, 0);
    WIPE_SetBrightnessFadeOut(1, 0);
    dispCtx = PROCSYS_AllocProcWork(owner, 0x1b8, 0x1f);
    MI_CpuFill8(dispCtx, 0, 0x1b8);
    ((struct GtsnegoDispCtx *)dispCtx)->heapId = 0x1f;
    *(u8 * *)&((struct GtsnegoDispCtx *)dispCtx)->parentCtx = parentCtx;
    ((struct GtsnegoDispCtx *)dispCtx)->actorSys = GTSNEGO_DISP_CreateMsgSystem(((struct GtsnegoDispCtx *)dispCtx)->heapId, ((struct GtsnegoParentCtx *)parentCtx)->gameData);
    ((struct GtsnegoDispCtx *)dispCtx)->msgCtx = GTSNEGO_MSG_Create(((struct GtsnegoDispCtx *)dispCtx)->heapId, 0x28);
    ((struct GtsnegoDispCtx *)dispCtx)->gameData = ((struct GtsnegoParentCtx *)parentCtx)->gameData;
    ((struct GtsnegoDispCtx *)dispCtx)->saveControl = GAME_DATA_GetSaveControl(((struct GtsnegoParentCtx *)parentCtx)->gameData);
    ((struct GtsnegoDispCtx *)dispCtx)->wifiList = GAME_DATA_GetWifiList(((struct GtsnegoParentCtx *)parentCtx)->gameData);
    ((struct GtsnegoParentCtx *)((struct GtsnegoDispCtx *)dispCtx)->parentCtx)->screenState = 1;
    ((struct GtsnegoDispCtx *)dispCtx)->partyCursor = zero;
    ((struct GtsnegoDispCtx *)dispCtx)->buttonCursor = 2;
    ((struct GtsnegoDispCtx *)dispCtx)->listCursorRow = 6;
    ((struct GtsnegoDispCtx *)dispCtx)->myTrainerId = MYSTATUS_GetId((const struct Sub0200852CObj *)GAME_DATA_GetMyStatus(((struct GtsnegoParentCtx *)parentCtx)->gameData));
    if (GFL_NET_GetRunState())
        GFL_NET_COMMAND_AddCommandTable(0x2200, (u32)d_021D88EC, 3, (u32)dispCtx);
    WIPE_SYS_Start(0, 1, 1, 0, 6, 1, ((struct GtsnegoDispCtx *)dispCtx)->heapId);
    GFL_USE_CancelChangeAndPlayBgm(0x486, 0xffff);
    GFL_NET_RefreshWmIconAtTopRight(1, ((struct GtsnegoDispCtx *)dispCtx)->heapId);
    GFL_NET_ERR_SetKeepDark(1);
    GTSNEGO_DISP_SetStateCallback(dispCtx, GTSNEGO_DISP_ShowPartySelect, 0x96a);
    return 1;
}








int GTSNEGO_DISP_Step(int unusedA, int unusedB, int unusedC, u8 *dispCtx)
{
    void (*callback)(u8 *) = *(void (**)(u8 *))dispCtx;
    int result = 1;
    if (callback) {
        if (GFL_NET_ERR_GetErrorLevel() == 0)
            callback(dispCtx);
        result = 0;
    }
    if (((struct GtsnegoDispCtx *)dispCtx)->tooltipWin) {
        void *touchbar = (void *)GTSNEGO_DISP_GetTouchbar(((struct GtsnegoDispCtx *)dispCtx)->actorSys);
        if (touchbar == 0 || TOUCHBAR_IsBusy(touchbar) == 0)
            APP_TASKMENU_WIN_Update(((struct GtsnegoDispCtx *)dispCtx)->tooltipWin);
    }
    if (((struct GtsnegoDispCtx *)dispCtx)->taskMenu)
        APP_TASKMENU_UpdateMenu(((struct GtsnegoDispCtx *)dispCtx)->taskMenu);
    GTSNEGO_DISP_DrawSystem(((struct GtsnegoDispCtx *)dispCtx)->actorSys);
    GTSNEGO_MSG_Main(((struct GtsnegoDispCtx *)dispCtx)->msgCtx);
    if (GFL_NET_GetRunState()) {
        if (GFL_NET_ERR_GetErrorLevel()) {
            switch (DWC_RAPCOMMON_HandleNetError(1, 1)) {
            case 0: break;
            case 1:
            case 4:
                GTSNEGO_DISP_ResetScreen(dispCtx);
                break;
            case 2:
                ((struct GtsnegoParentCtx *)((struct GtsnegoDispCtx *)dispCtx)->parentCtx)->screenState = 0;
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
u8 *GTSNEGO_DISP_CreateMsgSystem(u32 heap,void *arg)
{
    u8 *actorSys;
    actorSys=GFL_HEAP_Alloc(heap,0x164,1,d_021D8BC8,258);
    ((struct GtsnegoActorSys *)actorSys)->heapId=heap;
    ((struct GtsnegoActorSys *)actorSys)->gameData=arg;
    GF_OVERLAY_Load((int)ov_id);
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    BMP_SetDisplaySwap(1);
    *(volatile u32 *)0x04001000|=0x10000;
    GX_DispOn();
    BG_SYS_Create(((struct GtsnegoActorSys *)actorSys)->heapId);
    CLACT_InitSystem((const struct Cfg *)d_021D8974,(u32)(&d_021D8B98),((struct GtsnegoActorSys *)actorSys)->heapId);
    ((struct GtsnegoActorSys *)actorSys)->clactUnit=CLACT_CreateUnit(64,0,((struct GtsnegoActorSys *)actorSys)->heapId);
    BG_SYS_SetVramBanks(&d_021D8B98);
    BG_SYS_SetGraphicsMode(&d_021D8B60);
    GTSNEGO_DISP_InitBgLayers(actorSys);
    GTSNEGO_DISP_RegisterGraphics(actorSys);
    ((struct GtsnegoActorSys *)actorSys)->vblankTask=GFL_USE_AddMainTask(GTSNEGO_DISP_VBlank,actorSys,0);
    ((struct GtsnegoActorSys *)actorSys)->savedObjPltt=GFL_HEAP_Alloc(((struct GtsnegoActorSys *)actorSys)->heapId,0x200,0,d_021D8BC8,280);
    ((struct GtsnegoActorSys *)actorSys)->savedBgPltt=GFL_HEAP_Alloc(((struct GtsnegoActorSys *)actorSys)->heapId,0x200,0,d_021D8BC8,281);
    GTSNEGO_DISP_CreateCursorActor(actorSys);
    GTSNEGO_DISP_CreateTouchbar(actorSys,0);
    BG_SYS_SetSubVisiblePlanes(31);
    BG_SYS_SetMainVisiblePlanes(31);
    return actorSys;
}








void GTSNEGO_DISP_DrawSystem(struct GtsnegoActorSys *actorSys){CLACT_DrawSystem();if(actorSys->blinkAnimA)BLINK_PALANM_Update(actorSys->blinkAnimA);if(actorSys->blinkAnimB)BLINK_PALANM_Update(actorSys->blinkAnimB);GTSNEGO_MSG_StepIdleFade((char *)actorSys);}








void GTSNEGO_DISP_DeleteMsgSystem(u8 *actorSys)
{
    int i;
    CLACT_DeleteActor(((struct GtsnegoActorSys *)actorSys)->cursorActor);
    GTSNEGO_DISP_DeleteTouchbar(actorSys);
    GTSNEGO_MSG_DeleteCursorActor(actorSys);
    GTSNEGO_MSG_DeleteTileHandle(actorSys);
    GFL_HEAP_Free(((struct GtsnegoActorSys *)actorSys)->savedObjPltt);
    GFL_HEAP_Free(((struct GtsnegoActorSys *)actorSys)->savedBgPltt);
    GTSNEGO_MSG_DeleteActors(actorSys);
    CLACT_ReleasePalette((u32)(((struct GtsnegoActorSys *)actorSys)->uiPalette));
    CLACT_ReleasePalette((u32)(((struct GtsnegoActorSys *)actorSys)->idlePalette));
    CLACT_ReleaseCharacter((u32)(*(void * *)&((struct GtsnegoActorSys *)actorSys)->uiChar));
    CLACT_ReleaseCharacter((u32)(((struct GtsnegoActorSys *)actorSys)->idleChar));
    CLACT_ReleaseCellAnim((u32)(*(void * *)&((struct GtsnegoActorSys *)actorSys)->uiCellAnim));
    CLACT_ReleaseCellAnim((u32)(((struct GtsnegoActorSys *)actorSys)->idleCellAnim));
    CLACT_ReleasePalette((u32)(((struct GtsnegoActorSys *)actorSys)->cursorPalette));
    CLACT_ReleaseCharacter((u32)(((struct GtsnegoActorSys *)actorSys)->cursorChar));
    CLACT_ReleaseCellAnim((u32)(((struct GtsnegoActorSys *)actorSys)->cursorCellAnim));
    CLACT_ReleasePalette((u32)(((struct GtsnegoActorSys *)actorSys)->listPalette));
    for(i=0;i<16;i++) {
        CLACT_ReleaseCharacter((u32)(*(void **)(actorSys+i*4+0x30)));
        CLACT_ReleaseCellAnim((u32)(*(void **)(actorSys+i*4+0x7c)));
    }
    TCB_DeleteTask(((struct GtsnegoActorSys *)actorSys)->vblankTask);
    CLACT_DeleteUnit(((struct GtsnegoActorSys *)actorSys)->clactUnit);
    CLACT_ExitSystem();
    BLINK_PALANM_Delete(((struct GtsnegoActorSys *)actorSys)->blinkAnimA);
    BLINK_PALANM_Delete(((struct GtsnegoActorSys *)actorSys)->blinkAnimB);
    BG_SYS_FreeTileRun(7,(u16)(*(unsigned int *)&((struct GtsnegoActorSys *)actorSys)->bgCharLayer7),(u16)(*(unsigned int *)&((struct GtsnegoActorSys *)actorSys)->bgCharLayer7>>16));
    BG_SYS_FreeTileRun(4,(u16)(((struct GtsnegoActorSys *)actorSys)->bgCharLayer4),(u16)(((struct GtsnegoActorSys *)actorSys)->bgCharLayer4>>16));
    BG_SYS_FreeTileRun(0,(u16)(((struct GtsnegoActorSys *)actorSys)->bgCharLayer0),(u16)(((struct GtsnegoActorSys *)actorSys)->bgCharLayer0>>16));
    BG_SYS_FreeTiles(1,1,0);
    BG_SYS_FreeTiles(5,1,0);
    BG_SYS_FreeTiles(6,1,0);
    BG_SYS_SetPlaneVisible(5,0);
    for(i=0;i<=7;i++) BG_SYS_FreeLayerBuf((u8)i);
    BG_SYS_Delete();
    GFL_HEAP_Free(actorSys);
    GF_OVERLAY_Unload((int)ov_id);
}









u32 GTSNEGO_DISP_GetUnit(struct GtsnegoActorSys *actorSys){return (u32)actorSys->clactUnit;}









/*
 * BG-layer init: eight copies of the const template table at 0x021D89B0
 * (index order 0,5,1,2,3,4,6,7) passed to BG_SYS_InitBgLayer, each followed by
 * its layer enable / fill sequence.  The local array is written high-to-low
 * (b[7] first) because the original places the first-used slot at the top of
 * the frame.
 */
void GTSNEGO_DISP_InitBgLayers(u8 *actorSys)
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
        MI_CpuCopy8((void *)0x05000600,actorSys->savedObjPltt,0x200);
        MI_CpuCopy8((void *)0x05000400,actorSys->savedBgPltt,0x200);
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
            Pair offsets=d_021D895C;
            Pair sizes=d_021D896C;
            GTSNEGO_DISP_BlendPalette(actorSys,3,&offsets.a,&sizes.a,2);
            break;
        }
        }
        switch(mode) {
        case 0: case 2: {
            Pair offsets=d_021D894C;
            Pair sizes=d_021D8954;
            GTSNEGO_DISP_BlendPalette(actorSys,1,&offsets.a,&sizes.a,2);
            break;
        }
        case 1: {
            Pair offsets=d_021D8944;
            Pair sizes=d_021D8964;
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
void GTSNEGO_DISP_VBlank(void *unused,u8 *actorSys){CLACT_VBlankSystem();if(((struct GtsnegoActorSys *)actorSys)->scrollDirty){BG_SYS_ChangeScrollImmediate(4,3,*(unsigned int *)&((struct GtsnegoActorSys *)actorSys)->scrollOffset+72);BG_SYS_ChangeScrollImmediate(6,3,*(unsigned int *)&((struct GtsnegoActorSys *)actorSys)->scrollOffset+72);((struct GtsnegoActorSys *)actorSys)->scrollDirty=0;}}








void GTSNEGO_DISP_RegisterGraphics(u8 *actorSys)
{
    int i;
    void *arcHandle;
    arcHandle=ARC_TOOL_CreateHandle((u32)((void *)144),((struct GtsnegoActorSys *)actorSys)->heapId);
    ARC_UTIL_UploadPaletteFromHandleWhole(arcHandle,3,4,0,192,((struct GtsnegoActorSys *)actorSys)->heapId);
    ARC_UTIL_UploadPaletteFromHandleWhole(arcHandle,1,4,0,64,((struct GtsnegoActorSys *)actorSys)->heapId);
    *(unsigned int *)&((struct GtsnegoActorSys *)actorSys)->bgCharLayer7=ARC_UTIL_RegisterObjCharFromHandle(arcHandle,6,7,0,0,((struct GtsnegoActorSys *)actorSys)->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(arcHandle,17,7,0,(u16)(*(unsigned int *)&((struct GtsnegoActorSys *)actorSys)->bgCharLayer7),0,0,((struct GtsnegoActorSys *)actorSys)->heapId);
    ((struct GtsnegoActorSys *)actorSys)->bgCharLayer4=ARC_UTIL_RegisterObjCharFromHandle(arcHandle,8,4,0,0,((struct GtsnegoActorSys *)actorSys)->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(arcHandle,18,4,0,(u16)(((struct GtsnegoActorSys *)actorSys)->bgCharLayer4),0,0,((struct GtsnegoActorSys *)actorSys)->heapId);
    ARC_UTIL_UploadPaletteFromHandleWhole(arcHandle,1,0,0,0,((struct GtsnegoActorSys *)actorSys)->heapId);
    ((struct GtsnegoActorSys *)actorSys)->bgCharLayer0=ARC_UTIL_RegisterObjCharFromHandle(arcHandle,6,0,0,0,((struct GtsnegoActorSys *)actorSys)->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(arcHandle,12,0,0,(u16)(((struct GtsnegoActorSys *)actorSys)->bgCharLayer0),0,0,((struct GtsnegoActorSys *)actorSys)->heapId);
    ((struct GtsnegoActorSys *)actorSys)->cursorChar=(void *)CLACT_RegisterCharacter(arcHandle,5,0,1,((struct GtsnegoActorSys *)actorSys)->heapId);
    ((struct GtsnegoActorSys *)actorSys)->cursorPalette=(void *)CLACT_RegisterPaletteEx(arcHandle,0,1,320,0,1,((struct GtsnegoActorSys *)actorSys)->heapId);
    ((struct GtsnegoActorSys *)actorSys)->cursorCellAnim=(void *)CLACT_RegisterCellAnim(arcHandle,10,22,((struct GtsnegoActorSys *)actorSys)->heapId);
    *(void * *)&((struct GtsnegoActorSys *)actorSys)->uiChar=(void *)CLACT_RegisterCharacter(arcHandle,7,0,1,((struct GtsnegoActorSys *)actorSys)->heapId);
    ((struct GtsnegoActorSys *)actorSys)->uiPalette=(void *)CLACT_RegisterPaletteEx(arcHandle,2,1,256,0,8,((struct GtsnegoActorSys *)actorSys)->heapId);
    *(void * *)&((struct GtsnegoActorSys *)actorSys)->uiCellAnim=(void *)CLACT_RegisterCellAnim(arcHandle,11,23,((struct GtsnegoActorSys *)actorSys)->heapId);
    ((struct GtsnegoActorSys *)actorSys)->idleChar=(void *)CLACT_RegisterCharacter(arcHandle,7,0,0,((struct GtsnegoActorSys *)actorSys)->heapId);
    ((struct GtsnegoActorSys *)actorSys)->idlePalette=(void *)CLACT_RegisterPaletteEx(arcHandle,2,0,0,0,8,((struct GtsnegoActorSys *)actorSys)->heapId);
    ((struct GtsnegoActorSys *)actorSys)->idleCellAnim=(void *)CLACT_RegisterCellAnim(arcHandle,11,23,((struct GtsnegoActorSys *)actorSys)->heapId);
    ((struct GtsnegoActorSys *)actorSys)->blinkAnimA=BLINK_PALANM_Create(0,16,0,((struct GtsnegoActorSys *)actorSys)->heapId);
    BLINK_PALANM_LoadPalettes(((struct GtsnegoActorSys *)actorSys)->blinkAnimA,arcHandle,1,0,16);
    ((struct GtsnegoActorSys *)actorSys)->blinkAnimB=BLINK_PALANM_Create(0,16,7,((struct GtsnegoActorSys *)actorSys)->heapId);
    BLINK_PALANM_LoadPalettes(((struct GtsnegoActorSys *)actorSys)->blinkAnimB,arcHandle,1,0,16);
    ARC_TOOL_DeleteHandle(arcHandle);
    arcHandle=ARC_TOOL_CreateHandle((u32)((void *)32),((struct GtsnegoActorSys *)actorSys)->heapId);
    for(i=0;i<16;i++) {
        *(void **)(actorSys+i*4+0x30)=(void *)CLACT_RegisterCharacter(arcHandle,i+1,0,1,((struct GtsnegoActorSys *)actorSys)->heapId);
        *(void **)(actorSys+i*4+0x7c)=(void *)CLACT_RegisterCellAnim(arcHandle,i*2+17,i*2+18,((struct GtsnegoActorSys *)actorSys)->heapId);
    }
    ((struct GtsnegoActorSys *)actorSys)->listPalette=(void *)CLACT_RegisterPaletteEx(arcHandle,0,1,0,0,8,((struct GtsnegoActorSys *)actorSys)->heapId);
    ARC_TOOL_DeleteHandle(arcHandle);
    G2x_SetBlendAlpha_((void *)0x04001050,5,24,15,9);
}









void GTSNEGO_DISP_Noop(u8 *actorSys, int unusedFlag){}








void GTSNEGO_DISP_RedrawActors(u8 *actorSys)
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
void GTSNEGO_DISP_ResetActors(u8 *actorSys)
{
    void *arcHandle = ARC_TOOL_CreateHandle(144, ((struct GtsnegoActorSys *)actorSys)->heapId);
    GTSNEGO_MSG_DeleteActors(actorSys);
    BG_SYS_SetTileEntry(6, 0, 0, 0, 32, 32, 17);
    BG_SYS_MarkTileDirty(6);
    ARC_UTIL_UploadBgPaletteAddFromHandle(arcHandle, 18, 4, 0, (u16)(((struct GtsnegoActorSys *)actorSys)->bgCharLayer4), 0, 0, ((struct GtsnegoActorSys *)actorSys)->heapId);
    BG_SYS_MarkTileDirty(4);
    ARC_TOOL_DeleteHandle(arcHandle);
}








void GTSNEGO_DISP_CreateTouchbar(u8 *actorSys, int actorPlttSlot)
{
    Data data = d_021D8990;
    Config params;
    MI_CpuFill8(&params, 0, 32);
    params.defs = &data;
    params.count = 1;
    params.actorSys = *(u32 *)&((struct GtsnegoActorSys *)actorSys)->clactUnit;
    params.bgLayer = 7;
    params.bgPlttSlot = 15;
    params.iconSet = 2;
    params.skipBgGfx = 0;
    params.actorPlttSlot = actorPlttSlot;
    ((struct GtsnegoActorSys *)actorSys)->touchbar = TOUCHBAR_Create(&params, ((struct GtsnegoActorSys *)actorSys)->heapId);
}









u32 GTSNEGO_DISP_GetTouchbar(u8 *actorSys){return *(unsigned int *)&((struct GtsnegoActorSys *)actorSys)->touchbar;}









void GTSNEGO_DISP_DeleteTouchbar(u8 *actorSys)
{
    if (((struct GtsnegoActorSys *)actorSys)->touchbar) {
        TOUCHBAR_Delete(((struct GtsnegoActorSys *)actorSys)->touchbar);
        *(u32 *)&((struct GtsnegoActorSys *)actorSys)->touchbar = 0;
    }
}








void GTSNEGO_DISP_CreateCursorActor(u8 *actorSys)
{
    PosRecord actorPos;
    actorPos.x = 0; actorPos.y = 0; actorPos.z = 0; actorPos.a = 0; actorPos.b = 2;
    ((struct GtsnegoActorSys *)actorSys)->cursorActor = CLACT_CreateActor((void *)*(u32 *)&((struct GtsnegoActorSys *)actorSys)->clactUnit, ((struct GtsnegoActorSys *)actorSys)->uiChar, *(unsigned int *)&((struct GtsnegoActorSys *)actorSys)->uiPalette, ((struct GtsnegoActorSys *)actorSys)->uiCellAnim, &actorPos, 1, ((struct GtsnegoActorSys *)actorSys)->heapId);
    CLACT_SetActorAutoAnim(((struct GtsnegoActorSys *)actorSys)->cursorActor, 1);
    CLACT_SetActorDrawEnable(((struct GtsnegoActorSys *)actorSys)->cursorActor, 0);
    CLACT_SetActorObjMode(((struct GtsnegoActorSys *)actorSys)->cursorActor, 1);
}








void GTSNEGO_DISP_SetCursorState(u8 *actorSys, void *taskMenuWin, u32 position)
{
    Vec v;
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
    CLACT_AddActorSurfacePos(((struct GtsnegoActorSys *)actorSys)->cursorActor, (const struct Vec2 *)(&v), 1);
    CLACT_SetActorAnimSeq(((struct GtsnegoActorSys *)actorSys)->cursorActor, gGtsnegoEntryTable[position].code);
    CLACT_SetActorDrawEnable(((struct GtsnegoActorSys *)actorSys)->cursorActor, 1);
}
