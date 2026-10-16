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
 *   func_020355D8 0x020355D8 arm
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
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   STRBUF_Delete 0x02045808 arm
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   MISC_SAVEDATA_GetBlock44 0x0200ED48 thumb
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   func_02008510 0x02008510 thumb
 *   MI_CpuFill8 0x02082BCC arm
 *   STRBUF_GetChars 0x02045A90 arm
 *   STRBUF_GetLength 0x020458F8 arm
 *   STRBUF_GetEosChar 0x02045A98 arm
 *   DWC_CheckProfanityExAsync 0x0217BC44 arm ov009
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   GTSNEGO_MSG_UpdatePrintStream 0x021D7AF4 thumb ov120
 *   GFL_NET_HANDLE_GetNegotiationNum 0x020399EC arm
 *   func_02009EA8 0x02009EA8 thumb
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
 *   func_02009E74 0x02009E74 thumb
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   func_02008530 0x02008530 thumb
 *   GTSNEGO_MSG_CreateConfirmUi 0x021D8590 thumb ov120
 *   GFL_NET_SetWaitMode 0x0203D644 arm
 *   func_02009CA8 0x02009CA8 thumb
 *   DWC_AddMatchKeyInt 0x0216C8DC arm ov009
 *   func_0208D7E0 0x0208D7E0 arm
 *   DWC_RAP_StartMatchWithFilter 0x0215580C thumb ov009
 *   GFL_NET_STATE_WifiEnterFriendMatch 0x0203C35C arm
 *   DWC_RAP_SetVchatEnabled 0x02156BC4 thumb ov009
 *   GFL_NET_STATE_SetError 0x0203C9AC arm
 *   d_021D8B40 0x021D8B40 data a2
 *   d_021D8B50 0x021D8B50 data a1
 *   APP_TASKMENU_WIN_IsFinish 0x02028230 thumb
 *   APP_TASKMENU_WIN_Delete 0x02028148 thumb
 *   func_02041B6C 0x02041B6C arm
 *   GTSNEGO_MSG_PrintWindow 0x021D79F4 thumb ov120
 *   GTSNEGO_MSG_CreateIdleUi 0x021D7550 thumb ov120
 *   GTSNEGO_MSG_PrintStatus 0x021D8520 thumb ov120
 *   TOUCHBAR_IsBusy 0x021B6498 thumb ov067
 *   func_020355C4 0x020355C4 arm
 *   GTSNEGO_MSG_SetCursorAnimSeq 0x021D6A9C thumb ov120
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   d_021D88D0 0x021D88D0 data a4
 *   TOUCHBAR_Update 0x021B63D0 thumb ov067
 *   TOUCHBAR_GetPressedButtonIdIfDone 0x021B6448 thumb ov067
 *   func_02040588 0x02040588 arm
 *   GTSNEGO_MSG_DeleteButtonsKeep 0x021D7EC4 thumb ov120
 *   TOUCHBAR_SetAllButtonsVisible 0x021B64D0 thumb ov067
 *   GTSNEGO_MSG_ClearRows 0x021D7D3C thumb ov120
 *   GTSNEGO_MSG_CreateListUi 0x021D7DC8 thumb ov120
 *   GTSNEGO_MSG_CreateTooltip 0x021D7ECC thumb ov120
 *   GAME_DATA_GetSaveBlock1F 0x02012F14 thumb
 *   func_02009E8C 0x02009E8C thumb
 *   func_02009E54 0x02009E54 thumb
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
 *   func_0200F800 0x0200F800 thumb
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
 *   func_0200F7E8 0x0200F7E8 thumb
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   func_0200FB24 0x0200FB24 thumb
 *   APP_TASKMENU_WIN_Update 0x02028178 thumb
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 *   GTSNEGO_MSG_Main 0x021D7858 thumb ov120
 *   DWC_RAPCOMMON_HandleNetError 0x02157170 thumb ov009
 *   WIPE_SetBrightnessFadeOut 0x0202223C thumb
 *   func_0200F7DC 0x0200F7DC thumb
 *   func_0200F7F4 0x0200F7F4 thumb
 *   GFL_NET_COMMAND_DeleteCommandTable 0x0203A5E4 arm
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   GTSNEGO_MSG_Delete 0x021D7898 thumb ov120
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   func_02030734 0x02030734 arm
 *   func_02034AC4 0x02034AC4 arm
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BMP_SetDisplaySwap 0x0204363C arm
 *   GX_DispOn 0x0207D46C arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   func_020056A0 0x020056A0 thumb
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
 *   func_020307B0 0x020307B0 arm
 *   GTSNEGO_MSG_DeleteActors 0x021D6B5C thumb ov120
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   func_02030EAC 0x02030EAC arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   func_0202EA20 0x0202EA20 thumb
 *   BG_SYS_DeleteHalf 0x0203FB44 arm
 *   BG_SYS_SetTileUnit 0x02040DA8 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   func_02034A5C 0x02034A5C arm
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
 *   DWCi_ScreenDC_FlushRange 0x020862F0 arm
 *   func_0207E5D0 0x0207E5D0 arm
 *   func_0207E468 0x0207E468 arm
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
 *   BG_SYS_FillScrollArea 0x02040618 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   func_02049990 0x02049990 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   BLINK_PALANM_Create 0x0202E940 thumb
 *   BLINK_PALANM_LoadPalettes 0x0202E9AC thumb
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_0207D63C 0x0207D63C arm
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
 *   MISC_SAVEDATA_CopyQuadRecord  0x0200E6FC  thumb  arm9
 *   MISC_SAVEDATA_InsertRecentValue  0x0200ED54  thumb  arm9
 *   GAME_DATA_GetField1A0  0x0201283C  thumb  arm9
 *   GAME_DATA_GetPlayerStatusById  0x02012950  thumb  arm9
 */
#include "ov120_types.h"
struct GtsnegoDispCtx;
struct GtsnegoDispCtx2;
struct GtsnegoDispCtx_f48;

struct GtsnegoDispCtx {
    void *f0;
    unsigned int f4;
    unsigned char pad_8[4];
    unsigned short fC;
    unsigned char pad_E[2];
    unsigned int f10;
    int f14;
    unsigned int f18;
    unsigned char pad_1C[16];
    void *f2C;
    void *f30;
    void *f34;
    void *f38;
    void *f3C;
    void *f40;
    unsigned int f44;
    void *f48;
    unsigned char pad_4C[236];
    int f138;
    int f13C;
    int f140;
    int f144;
    int f148;
    unsigned int f14C;
    int f150;
    unsigned char pad_154[4];
    int f158;
    int f15C;
    int f160;
    int f164;
    unsigned char pad_168[8];
    int f170;
    unsigned char pad_174[8];
    int f17C;
    unsigned char pad_180[4];
    int f184;
    unsigned short f188;
    unsigned char pad_18A[22];
    void *f1A0;
    unsigned char pad_1A4[4];
    int f1A8;
    unsigned short f1AC;
    unsigned char pad_1AE[2];
    unsigned int f1B0;
    unsigned int f1B4;
};

struct GtsnegoDispCtx2 {
    int f0;
    unsigned char pad_4[20];
    void *f18;
};

struct GtsnegoDispCtx_f48 {
    unsigned char pad_0[24];
    void *f18;
    unsigned char pad_1C[404];
    int f1B0;
};

#define I(k) (*(int *)(p + (k)))
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
    void *f2C;
    u8 pad30[4];
    void *f34;
    u8 pad38[4];
    u8 *f3C;
    void *f40;
    u8 pad44[0x148 - 0x44];
    int f148;
    u8 pad14C[4];
    int f150;
    u8 pad154[4];
    int f158;
    u8 pad15C[8];
    int f164;
} Ctx;

struct DispConfig { u32 a,b,c,d; };

struct BgTemplate {
    u32 unk_00;
    u32 unk_04;
    u32 bufSize;
    u32 unk_0c;
    u8  unk_10;
    u8  unk_11;
    u8  unk_12;
    u8  unk_13;
    u32 unk_14;
    u8  unk_18;
    u8  unk_19;
    u8  unk_1a;
    u8  unk_1b;
    u32 unk_1c;
};

typedef struct Pair { int a,b; } Pair;

typedef struct Word { int a; } Word;

typedef struct Data { u32 w[8]; } Data;

typedef struct Config { Data *f0; u32 f4; int f8; u32 fC, f10, f14; int f18, f1c; } Config;

typedef struct PosRecord { u16 x, y, z; u8 a, b; } PosRecord;

typedef signed short s16;

typedef struct Entry { u8 code, x, y, other; } Entry;

typedef struct Vec { s16 x, y; } Vec;

extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_GetHandleNetID(struct Link *);
extern void MI_CpuCopy8(const void *,void *,u32);
extern int MYSTATUS_GetSize(void);
extern void func_020355D8(u8 v);
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
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern void GTSNEGO_MSG_PrintSummary(char *p, void *q, u32 n);
extern void GTSNEGO_MSG_SetIdleAnim(u8 *p, int n);
extern int DWC_CheckProfanityProcess(void);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_020084E4(u16 *out, struct U16Vec *vec);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern struct Rec44 *GAME_DATA_GetPlayerStatusById(struct Sub24 *p, u32 i);
extern void MYSTATUS_Copy(void *src, void *dst);
extern void *MISC_SAVEDATA_GetBlock44(void *p);
extern void MISC_SAVEDATA_InsertRecentValue(struct L0200ED54 *l, u32 val);
extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *, unsigned int, unsigned int);
extern void *func_02008510(void *, int);
extern void MI_CpuFill8(void *, u8, u32);
extern u16 *STRBUF_GetChars(struct U16Vec *vec);
extern u16 STRBUF_GetLength(struct U16Vec *vec);
extern u16 STRBUF_GetEosChar(void);
extern int DWC_CheckProfanityExAsync(u16 **, int, char *, int, char *, int *, int);
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *,u32,u32);
extern int GFL_NET_SendToHandle(void *,u16,u16,u32);
extern int GTSNEGO_MSG_UpdatePrintStream(char *p);
extern int GFL_NET_HANDLE_GetNegotiationNum(void);
extern void *func_0200E6E8(u32 a);
extern void MISC_SAVEDATA_CopyQuadRecord(struct Rec0200E6FC *src, int idx, struct Rec0200E6FC *dst);
extern void *GAME_DATA_GetSaveBlock1F(void **h);
extern u32 func_02009EA8(const struct Sub02009D9CObj *obj);
extern int GFL_NET_HANDLE_CheckNegotiation(void);
extern int GTSNEGO_MSG_UpdateButtons(char *p);
extern u32 KEY_GetTrg(void);
extern void GTSNEGO_MSG_SetDecide(unsigned char *p);
extern void GFL_NET_STATE_WifiDisconnect(u32 a);
extern int GFL_NET_STATE_GetWifiState(void);
extern void GFL_NET_SetAutoExit(u8 a0);
extern void GFL_NET_SetLoginOption(u8 a0);
extern void GTSNEGO_MSG_DeleteWindow(char *p);
extern void GTSNEGO_MSG_DeleteConfirmWindow(u8 *p);
extern int DWC_GetMatchIntValue(int, int, int);
extern void *TRADE_HISTORY_GetFromSave(void *);
extern u32 func_02009E74(struct Sub02009D9CObj *obj, u32 id);
extern void GTSNEGO_MSG_CreateConfirmUi(u8 *, int, int);
extern void GFL_NET_SetWaitMode(int);
extern void func_02009CA8(void *account, void *out);
extern u8 DWC_AddMatchKeyInt(u8 keyID, char *keyString, int *valueSrc);
extern int func_0208D7E0(char *, const char *, ...);
extern int DWC_RAP_StartMatchWithFilter(int, int, int, int);
extern u32 GFL_NET_STATE_WifiEnterFriendMatch(void);
extern void DWC_RAP_SetVchatEnabled(int);
extern void GFL_NET_STATE_SetError(int, u32, u32, u32);
extern u32 APP_TASKMENU_WIN_IsFinish(u8 *p);
extern void APP_TASKMENU_WIN_Delete(u8 *p);
extern void func_02041B6C(u32 bit);
extern void GTSNEGO_MSG_PrintWindow(u8 *p, u16 n);
extern void GTSNEGO_MSG_CreateIdleUi(u8 *p);
extern void GTSNEGO_MSG_PrintStatus(char *p, u16 n);
extern int TOUCHBAR_IsBusy(u8 *);
extern u8 func_020355C4(void);
extern int GTSNEGO_MSG_SetCursorAnimSeq(u8 *p, u32 n);
extern void APP_TASKMENU_WIN_SetDecide(char *p, int v);
extern int TOUCHPANEL_HitTrg(const void *p);
extern void TOUCHBAR_Update(struct TouchBar *p);
extern int TOUCHBAR_GetPressedButtonIdIfDone(u8 *);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void GTSNEGO_MSG_DeleteButtonsKeep(u8 *p);
extern void TOUCHBAR_SetAllButtonsVisible(u8 *, u32);
extern void GTSNEGO_MSG_ClearRows(char *p);
extern void GTSNEGO_MSG_CreateListUi(char *p, int a, int b, int c, int d, int e);
extern void *GTSNEGO_MSG_CreateTooltip(char *p, u16 n);
extern int func_02009E8C(void *);
extern void *func_02009E54(void *,int);
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
extern void func_0200F800(void);
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
extern u32 GAME_DATA_GetField1A0(const struct BigObj *p);
extern void GFL_NET_COMMAND_AddCommandTable(u32, u32, u32, u32);
extern void GFL_USE_CancelChangeAndPlayBgm(u32, u32);
extern void GFL_NET_RestartWithDefaultTimeout(u32, u32);
extern void func_0200F7E8(u32 value);
extern u32 func_0200FB24(void);
extern void APP_TASKMENU_WIN_Update(u8 *p);
extern void APP_TASKMENU_UpdateMenu(void *);
extern void GTSNEGO_MSG_Main(u8 *p);
extern int DWC_RAPCOMMON_HandleNetError(int a0, int a1);
extern void func_0200F7DC(void);
extern void func_0200F7F4(void);
extern void GFL_NET_COMMAND_DeleteCommandTable(unsigned int);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern void GTSNEGO_MSG_Delete(char *p);
extern void func_020315D4(struct Proc *p);
extern void GFL_HEAP_DeleteChecked(unsigned int heap);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern int func_02034AC4(int);
extern void BG_SYS_SetMainVisiblePlanes(u32);
extern void BMP_SetDisplaySwap(u32 swap);
extern void GX_DispOn(void);
extern void BG_SYS_Create(u16);
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void BG_SYS_SetVramBanks(const struct DispVram *);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *);
extern void *func_020056A0(void (*)(void *,u8 *),void *,int);
extern void CLACT_DrawSystem(void);
extern s32 BLINK_PALANM_Update(struct Row *p);
extern void GTSNEGO_MSG_StepIdleFade(char *p);
extern void CLACT_DeleteActor(struct Obj *p);
extern void GTSNEGO_MSG_DeleteCursorActor(u8 *);
extern void GTSNEGO_MSG_DeleteTileHandle(u8 *);
extern u32 func_020307B0(void *p);
extern void GTSNEGO_MSG_DeleteActors(u8 *);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern void func_02030EAC(struct Node *n);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern u32 func_0202EA20(struct BlinkPalAnm *p);
extern void BG_SYS_DeleteHalf(u32 layer, u32 offset, u32 size);
extern void BG_SYS_SetTileUnit(u32,u32,u32);
extern void BG_SYS_FreeLayerBuf(u32 i);
extern void BG_SYS_Delete(void);
extern void func_02034A5C(int handle);
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
extern void DWCi_ScreenDC_FlushRange(void *,unsigned long);
extern void func_0207E5D0(void *,int,int);
extern void func_0207E468(void *,int,int);
extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *slots, u32 idx);
extern u32 PALANM_Delete(void *a0);
extern void CLACT_VBlankSystem(void);
extern void BG_SYS_FillScrollArea(u32,u32,u32);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern u32 func_02049740(void *,u32,u32,u32,u32,u16);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern struct CodeIn *BLINK_PALANM_Create(u16 a0, u16 a1, u32 a2, u16 heap);
extern void BLINK_PALANM_LoadPalettes(struct CodeIn *p, u8 *a1, u32 a2, u32 a3, u32 a4);
extern void ARC_TOOL_DeleteHandle(void *);
extern void func_0207D63C(void *,int,int,int,int);
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
void GTSNEGO_DISP_DrawSystem(struct GtsnegoMsgCtx *p);
void GTSNEGO_DISP_DeleteMsgSystem(u8 *p);
u32 GTSNEGO_DISP_GetUnit(struct GtsnegoDispCtx *p);
void GTSNEGO_DISP_InitBgLayers(u8 *a0);
void GTSNEGO_DISP_BlendPalette(struct GtsnegoMsgCtx *p,int bank,int *offset,int *size,int count);
void GTSNEGO_DISP_SetTradePalette(struct GtsnegoMsgCtx *p,int flag,int mode);
void GTSNEGO_DISP_VBlank(void *unused,u8 *p);
void GTSNEGO_DISP_RegisterGraphics(u8 *p);
void GTSNEGO_DISP_Noop(u8 *a0, int a1);
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




void GTSNEGO_DISP_SetCallback(void **p, void *v) { *p=v; }




void GTSNEGO_DISP_SetStateCallback(void *p, void *fn, int line) { GTSNEGO_DISP_SetCallback(p, fn); }




void GTSNEGO_DISP_OnTradeSync(u32 id,int b,const void *src,struct GtsnegoDispCtx *p,struct Entry *entry) { u8 *q; q=*(u8 * *)&p->f48; if(entry==GFL_NET_HANDLE_GetCurrentHandle() && id!=GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle())) MI_CpuCopy8(src,q+12,8); }




void GTSNEGO_DISP_OnStatusSync(u32 id,int b,const void *src,struct GtsnegoDispCtx *p,struct Entry *entry) { u8 *q; q=*(u8 * *)&p->f48; if(entry==GFL_NET_HANDLE_GetCurrentHandle() && id!=GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle())) MI_CpuCopy8(src,((struct GtsnegoDispCtx2 *)q)->f18,MYSTATUS_GetSize()); }




void GTSNEGO_DISP_OnRecordSync(u32 id,int b,const void *src,u8 *p,struct Entry *entry) { if(entry==GFL_NET_HANDLE_GetCurrentHandle() && id!=GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle())) MI_CpuCopy8(src,p+0x174,12); }




/*
 * extent: existing matched followers 021D435C, 021D437C, 021D439C remain separate.
 */
int GTSNEGO_DISP_StartTrade(int n, u8 *p)
{
    ((struct GtsnegoDispCtx *)p)->f138 = n;
    func_020355D8(1);
    if (((struct GtsnegoDispCtx *)p)->f184 == 1) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        return 1;
    }
    if (n == 0) {
        ((struct GtsnegoDispCtx *)p)->f15C = 0;
        GTSNEGO_DISP_SetCursorState(*(u8 * *)&((struct GtsnegoDispCtx *)p)->f3C, ((struct GtsnegoDispCtx *)p)->f34, 0);
        GTSNEGO_DISP_SelectParty(p, ((struct GtsnegoDispCtx *)p)->f15C);
        GTSNEGO_DISP_SetStateCallback(p, GTSNEGO_DISP_OnPartySelected, 0x177);
    } else {
        ((struct GtsnegoDispCtx *)p)->f15C = 1;
        GTSNEGO_DISP_SetCursorState(*(u8 * *)&((struct GtsnegoDispCtx *)p)->f3C, ((struct GtsnegoDispCtx *)p)->f34, 1);
        GTSNEGO_DISP_SelectParty(p, ((struct GtsnegoDispCtx *)p)->f15C);
        GTSNEGO_DISP_SetStateCallback(p, GTSNEGO_DISP_OnPartySelected, 0x17e);
    }
    return 1;
}




/*
 * follower: separately filed 021D437C.
 */
void GTSNEGO_DISP_CycleRowB(int n, char *p) {
    ((struct GtsnegoDispCtx *)p)->f13C+=n;
    if(((struct GtsnegoDispCtx *)p)->f13C>=5) ((struct GtsnegoDispCtx *)p)->f13C=0;
    else if(((struct GtsnegoDispCtx *)p)->f13C<0) ((struct GtsnegoDispCtx *)p)->f13C=4;
}




/*
 * follower: separately filed 021D439C.
 */
void GTSNEGO_DISP_CycleRowC(int n, char *p) {
    ((struct GtsnegoDispCtx *)p)->f140+=n;
    if(((struct GtsnegoDispCtx *)p)->f140>=5) ((struct GtsnegoDispCtx *)p)->f140=0;
    else if(((struct GtsnegoDispCtx *)p)->f140<0) ((struct GtsnegoDispCtx *)p)->f140=4;
}




void GTSNEGO_DISP_CycleRowA(int n, char *p) {
    ((struct GtsnegoDispCtx *)p)->f144+=n;
    if(((struct GtsnegoDispCtx *)p)->f144>=4) ((struct GtsnegoDispCtx *)p)->f144=0;
    else if(((struct GtsnegoDispCtx *)p)->f144<0) ((struct GtsnegoDispCtx *)p)->f144=3;
}




int GTSNEGO_DISP_MoveRowCursor(int n, char *p) {
    int result=0;
    switch(n) {
    case 0:GTSNEGO_DISP_CycleRowA(-1,p);result=2;GTSNEGO_MSG_RedrawRowA((char *)(*(int *)&((struct GtsnegoDispCtx *)p)->f40),((struct GtsnegoDispCtx *)p)->f144);break;
    case 1:GTSNEGO_DISP_CycleRowA(1,p);result=2;GTSNEGO_MSG_RedrawRowA((char *)(*(int *)&((struct GtsnegoDispCtx *)p)->f40),((struct GtsnegoDispCtx *)p)->f144);break;
    case 2:GTSNEGO_DISP_CycleRowB(-1,p);result=3;GTSNEGO_MSG_RedrawRowB((char *)(*(int *)&((struct GtsnegoDispCtx *)p)->f40),((struct GtsnegoDispCtx *)p)->f13C);break;
    case 3:GTSNEGO_DISP_CycleRowB(1,p);result=3;GTSNEGO_MSG_RedrawRowB((char *)(*(int *)&((struct GtsnegoDispCtx *)p)->f40),((struct GtsnegoDispCtx *)p)->f13C);break;
    case 4:GTSNEGO_DISP_CycleRowC(-1,p);result=4;GTSNEGO_MSG_RedrawRowC((char *)(*(int *)&((struct GtsnegoDispCtx *)p)->f40),((struct GtsnegoDispCtx *)p)->f140);break;
    case 5:GTSNEGO_DISP_CycleRowC(1,p);result=4;GTSNEGO_MSG_RedrawRowC((char *)(*(int *)&((struct GtsnegoDispCtx *)p)->f40),((struct GtsnegoDispCtx *)p)->f140);break;
    }
    if(n>=0 && n<=5) {GFL_USE_PlaySeDefaultVolume(0x548);GTSNEGO_MSG_SetActorMode((u8 *)(*(int *)&((struct GtsnegoDispCtx *)p)->f3C),n);}
    return result;
}




int GTSNEGO_DISP_OnRowCursorMoved(int n,char *p) { int result; if(*(struct Obj * *)&((struct GtsnegoDispCtx *)p)->f34) APP_TASKMENU_WIN_SetActive(*(struct Obj * *)&((struct GtsnegoDispCtx *)p)->f34,0); result=GTSNEGO_DISP_MoveRowCursor(n,p); if(result) ((struct GtsnegoDispCtx *)p)->f160=result; return 1; }


void GTSNEGO_DISP_MoveCursorVertical(int n,char *p) { int v; v=((struct GtsnegoDispCtx *)p)->f160-2; if(((struct GtsnegoDispCtx *)p)->f160>=2 || ((struct GtsnegoDispCtx *)p)->f160<=4) GTSNEGO_DISP_MoveRowCursor(n+v*2,p); }






void GTSNEGO_DISP_WaitWipeDone(u8 *p) { if (WIPE_SYS_EndCheck()) GTSNEGO_DISP_SetStateCallback(p, 0, 0x213); }






void GTSNEGO_DISP_StartWipe(struct GtsnegoDispCtx *p) {
    if (--p->f14<=0) {
        WIPE_SYS_Start(0,0,0,0,6,1,p->fC);
        GTSNEGO_DISP_SetStateCallback(p, GTSNEGO_DISP_WaitWipeDone, 0x21e);
    }
}





void GTSNEGO_DISP_ShowTradeReady(u8 *a)
{
    Halfwords table = d_021D8904;
    const Halfwords *p = &table;
    if (GFL_NET_GetRunState() != 0)
        p = (const Halfwords *)(a + 0x174);
    ((struct GtsnegoDispCtx *)a)->f14 = 0xb4;
    GTSNEGO_MSG_CreateDraw((u8 *)(*(int *)&((struct GtsnegoDispCtx *)a)->f40), (void *)(*(int *)&((struct GtsnegoDispCtx *)a)->f3C));
    GTSNEGO_MSG_PrintDraw((struct GtsnegoMsgCtx *)(*(int *)&((struct GtsnegoDispCtx *)a)->f40), (void *)p);
    GTSNEGO_DISP_SetStateCallback(a, GTSNEGO_DISP_StartWipe, 0x232);
}




void GTSNEGO_DISP_WaitTradeStart(struct GtsnegoDispCtx *a)
{
    --a->f14;
    if (a->f14 == 20)
        GTSNEGO_MSG_PrintWindowB((u8 *)(*(int *)&a->f40), 0x27);
    if (a->f14 == 0) {
        GTSNEGO_MSG_PrintTooltip((char *)(*(int *)&a->f40), 0x23);
        GTSNEGO_MSG_DeleteEntryWindow((char *)(*(int *)&a->f40));
        GTSNEGO_DISP_SetStateCallback(a, GTSNEGO_DISP_ShowTradeReady, 0x241);
    }
}




void GTSNEGO_DISP_ShowTradeConfirm(struct GtsnegoDispCtx *p)
{
    u8 *q = *(u8 * *)&p->f48;
    int value;
    int mode = 2;
    if (GFL_NET_GetRunState() == 0) {
        value = (int)GAME_DATA_GetMyStatus((void *)(*(int *)&((struct GtsnegoMsgCtx *)q)->f0));
    } else {
        value = *(int *)&((struct GtsnegoMsgCtx *)q)->f18;
        mode = p->f17C;
        *(int *)(q + ((struct GtsnegoMsgCtx *)q)->f1AC * 4 + 0x1c) = func_02008530((const struct Sub0200852CObj *)value);
        ((struct GtsnegoMsgCtx *)q)->f1AC = ((struct GtsnegoMsgCtx *)q)->f1AC + 1;
        if (((struct GtsnegoMsgCtx *)q)->f1AC >= 100)
            ((struct GtsnegoMsgCtx *)q)->f1AC = 0;
    }
    GTSNEGO_MSG_PrintSummary((char *)(*(int *)&p->f40), (void *)value, mode);
    GTSNEGO_MSG_SetIdleAnim((u8 *)(*(int *)&p->f3C), func_02008554((const struct Sub0200852CObj *)value));
    p->f14 = 0xb4;
    GTSNEGO_DISP_SetStateCallback(((int *)p), GTSNEGO_DISP_WaitTradeStart, 0x265);
}




void GTSNEGO_DISP_ConfirmStatus(struct GtsnegoDispCtx *p)
{
    int ready = 0;
    int value = *(int *)&((struct GtsnegoDispCtx_f48 *)p->f48)->f18;
    int active;
    void *message;
    void *text;
    int result;
    active = DWC_CheckProfanityProcess() == 2;
    if (active)
        ready = p->f1A8 > 0;
    if (active) {
        if (ready) {
            message = func_02045B38(0, 2, 0x51, 0x1f);
            text = func_02045EC0(message, 15);
            MSGDATA_Delete(message);
            func_020084E4((u16 *)value, text);
            STRBUF_Delete(text);
        }
        MYSTATUS_Copy((void *)value, GAME_DATA_GetPlayerStatusById((struct Sub24 *)(*(int *)&p->f2C), 1 - GFL_NET_SYSTEM_GetCurrentAid()));
        result = func_02008530((const struct Sub0200852CObj *)value);
        MISC_SAVEDATA_InsertRecentValue(MISC_SAVEDATA_GetBlock44((void *)(*(int *)&p->f30)), result);
        GTSNEGO_DISP_SetStateCallback(((int *)p), GTSNEGO_DISP_ShowTradeConfirm, 0x283);
    }
}




/*
 * evidence: 020399A8's r0 is consumed by 02039CB4 despite its void definition.
 * evidence: 020458F8 returns ldrh r0; this caller uses full-word r0+1 without narrowing.
 */
void GTSNEGO_DISP_PrepareTrade(u8 *p)
{
    void *str;
    u16 *chars;
    u32 i;
    void *value = ((struct GtsnegoDispCtx_f48 *)((struct GtsnegoDispCtx *)p)->f48)->f18;
    if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 3, 0x22) != 0) {
        str = func_02008510(value, 31);
        MI_CpuFill8(p + 0x188, 0, 40);
        ((struct GtsnegoDispCtx *)p)->f1AC = 31;
        chars = STRBUF_GetChars(str);
        for (i = 0; i < STRBUF_GetLength(str) + 1u; i++) {
            u16 c = chars[i];
            if (c == STRBUF_GetEosChar()) ((u16 *)(p + 0x188))[i] = 0;
            else ((u16 *)(p + 0x188))[i] = c;
        }
        ((struct GtsnegoDispCtx *)p)->f1A0 = p + 0x188;
        *(unsigned int *)&((struct GtsnegoDispCtx *)p)->f1A8 = 0;
        DWC_CheckProfanityExAsync((u16 **)(p + 0x1a0), 1, 0, 0, (char *)(p + 0x1a4), (int *)(p + 0x1a8), 128);
        STRBUF_Delete(str);
        GTSNEGO_DISP_SetStateCallback(((int *)p), GTSNEGO_DISP_ConfirmStatus, 0x29c);
    }
}




void GTSNEGO_DISP_StartSync(u8 *p) { GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),3,34); GTSNEGO_DISP_SetStateCallback(p, GTSNEGO_DISP_PrepareTrade, 0x2ac); }




void GTSNEGO_DISP_SendStatus(struct GtsnegoDispCtx *p) { void *link; int n; link=GFL_NET_HANDLE_GetCurrentHandle(); n=MYSTATUS_GetSize(); if (GFL_NET_SendToHandle(link,0x2201,n,*(u32 *)(*(unsigned int *)&p->f48+20))) GTSNEGO_DISP_SetStateCallback(p, GTSNEGO_DISP_StartSync, 0x2bd); }








void GTSNEGO_DISP_SendRecord(u8 *p) { if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0x2202,12,(u32)(p+360))) GTSNEGO_DISP_SetStateCallback(p, GTSNEGO_DISP_SendStatus, 0x2cf); }









void GTSNEGO_DISP_SendHandshake(struct GtsnegoDispCtx *a)
{
    if (GFL_NET_GetRunState() == 0) {
        GTSNEGO_DISP_SetStateCallback(a, GTSNEGO_DISP_ShowTradeConfirm, 0x2df);
        return;
    }
    if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 2, 0x22) != 0) {
        if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x2200, 8, (u32)(*(char * *)&a->f48 + 4)) != 0)
            GTSNEGO_DISP_SetStateCallback(a, GTSNEGO_DISP_SendRecord, 0x2e7);
    }
}









void GTSNEGO_DISP_WaitNegotiation(u8 *p)
{
    u8 *q;
    int value;
    if (GTSNEGO_MSG_UpdatePrintStream((char *)(*(int *)&((struct GtsnegoDispCtx *)p)->f40))) {
        if (GFL_NET_GetRunState() == 0) {
            GTSNEGO_DISP_SetStateCallback(((int *)p), GTSNEGO_DISP_SendHandshake, 0x2fe);
            return;
        }
        if (((struct GtsnegoDispCtx *)p)->f14 > 0) {
            ((struct GtsnegoDispCtx *)p)->f14 = ((struct GtsnegoDispCtx *)p)->f14 - 1;
            return;
        }
        if (GFL_NET_HANDLE_GetNegotiationNum() == 2) {
            q = *(u8 * *)&((struct GtsnegoDispCtx *)p)->f48;
            value = (int)func_0200E6E8(*(int *)&((struct GtsnegoDispCtx *)p)->f30);
            *(int *)&((struct GtsnegoMsgCtx *)q)->f4 = ((struct GtsnegoDispCtx *)p)->f144;
            *(int *)&((struct GtsnegoMsgCtx *)q)->f8 = ((struct GtsnegoDispCtx *)p)->f13C;
            MISC_SAVEDATA_CopyQuadRecord((struct Rec0200E6FC *)value, 0, (struct Rec0200E6FC *)(p + 0x168));
            ((struct GtsnegoDispCtx *)p)->f170 = func_02009EA8(GAME_DATA_GetSaveBlock1F((void **)(*(int *)&((struct GtsnegoDispCtx *)p)->f2C)));
            GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 2, 0x22);
            GTSNEGO_DISP_SetStateCallback(((int *)p), GTSNEGO_DISP_SendHandshake, 0x314);
        }
    }
}








void GTSNEGO_DISP_CheckNegotiation(int *a)
{
    if (GFL_NET_GetRunState() == 0) {
        GTSNEGO_DISP_SetStateCallback(a, GTSNEGO_DISP_WaitNegotiation, 0x31d);
        return;
    }
    if (GFL_NET_HANDLE_GetNegotiationNum() != 0 && GFL_NET_HANDLE_CheckNegotiation() != 0)
        GTSNEGO_DISP_SetStateCallback(a, GTSNEGO_DISP_WaitNegotiation, 0x322);
}








void GTSNEGO_DISP_WaitPartnerReady(struct GtsnegoDispCtx *a)
{
    if (GTSNEGO_MSG_UpdatePrintStream((char *)(*(int *)&a->f40)) != 0) {
        if (a->f14 > 0) {
            a->f14 = a->f14 - 1;
            return;
        }
        if (GFL_NET_SYSTEM_GetCurrentAid() != 0) {
            if (GFL_NET_HANDLE_CheckNegotiation() != 0) {
                a->f14 = 0xb4;
                GTSNEGO_DISP_SetStateCallback(((int *)a), GTSNEGO_DISP_WaitNegotiation, 0x33f);
                return;
            }
        } else {
            a->f14 = 0xb4;
            GTSNEGO_DISP_SetStateCallback(((int *)a), GTSNEGO_DISP_CheckNegotiation, 0x344);
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
void GTSNEGO_DISP_HandleTradeKeys(struct GtsnegoDispCtx *a)
{
    GTSNEGO_MSG_UpdateButtons((char *)(*(int *)&a->f40));
    if (KEY_GetTrg() == 2) {
        GTSNEGO_MSG_SetDecide((unsigned char *)(*(int *)&a->f40));
        if (GFL_NET_GetRunState() != 0)
            GFL_NET_STATE_WifiDisconnect(1);
        func_020355D8(0);
        GFL_USE_PlaySeDefaultVolume(0x551);
        GTSNEGO_DISP_SetStateCallback(a, GTSNEGO_DISP_OnDisconnect, 0x360);
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
    GTSNEGO_MSG_DeleteWindow((char *)(*(int *)&a->f40));
    GTSNEGO_MSG_PrintWindowB((u8 *)(*(int *)&a->f40), 0x10);
    a->f14 = 0xb4;
    GTSNEGO_MSG_DeleteConfirmWindow((u8 *)(*(int *)&a->f40));
    GTSNEGO_DISP_SetStateCallback(a, GTSNEGO_DISP_WaitPartnerReady, 0x377);
}








int GTSNEGO_DISP_ScoreMatch(int a, u8 *p)
{
    int mode;
    int x;
    int y;
    int score = -1;
    int id;
    int group;
    int i;
    u8 *q = *(u8 * *)&((struct GtsnegoDispCtx *)p)->f48;
    mode = DWC_GetMatchIntValue(a, (int)(p + 0x76), -1);
    x = DWC_GetMatchIntValue(a, (int)(p + 0x8e), -1);
    y = DWC_GetMatchIntValue(a, (int)(p + 0x82), -1);
    id = DWC_GetMatchIntValue(a, (int)(p + 0x5e), 0);
    group = DWC_GetMatchIntValue(a, (int)(p + 0xb2), 0);
    if (I(0x138) == 1) {
        if (mode == 4) {
            if (I(0x148) == -1) {
                if (func_02009E74(TRADE_HISTORY_GetFromSave(((struct GtsnegoDispCtx *)p)->f30), id) != 0)
                    score = 100;
            } else {
                if (I(0x18) == id) score = 100;
            }
        } else {
            if (group == func_02008530((const struct Sub0200852CObj *)GAME_DATA_GetMyStatus((void *)(((struct GtsnegoDispCtx2 *)q)->f0)))) {
                if (I(0x148) == -1) {
                    if (func_02009E74(TRADE_HISTORY_GetFromSave(((struct GtsnegoDispCtx *)p)->f30), id) != 0)
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
                if (id == *(int *)(q + i * 4 + 0x1c) && id != 0) {
                    score = 0;
                    break;
                }
            }
        }
    }
    return score;
}








void GTSNEGO_DISP_StartMatchmaking(u8 *p)
{
    u32 values[8];
    void *q;
    int i;
    MatchFilterRecord *r;
    if (GTSNEGO_MSG_UpdatePrintStream(((struct GtsnegoDispCtx *)p)->f40)) {
        if (GFL_NET_GetRunState() == 0) {
            GTSNEGO_MSG_CreateConfirmUi(*(u8 * *)&((struct GtsnegoDispCtx *)p)->f40, (int)GTSNEGO_DISP_OnDisconnectCallback, (int)p);
            GTSNEGO_DISP_SetStateCallback(((int *)p), GTSNEGO_DISP_HandleTradeKeys, 0x3ea);
            return;
        }
        GFL_NET_SetWaitMode(0);
        func_02009CA8((void *)(((struct GtsnegoDispCtx *)p)->f44), values);
        values[0] = ((struct GtsnegoDispCtx *)p)->f14C;
        values[1] = *(unsigned int *)&((struct GtsnegoDispCtx *)p)->f138;
        values[2] = *(unsigned int *)&((struct GtsnegoDispCtx *)p)->f144;
        values[3] = *(unsigned int *)&((struct GtsnegoDispCtx *)p)->f13C;
        values[4] = *(unsigned int *)&((struct GtsnegoDispCtx *)p)->f140;
        values[5] = 0x20015;
        values[6] = 1;
        values[7] = 0;
        if (*(unsigned int *)&((struct GtsnegoDispCtx *)p)->f138 == 1) {
            if (((struct GtsnegoDispCtx *)p)->f148 == -1)
                values[2] = 4;
            else {
                q = GTSNEGO_DISP_GetEntry(((struct GtsnegoDispCtx *)p)->f2C, ((struct GtsnegoDispCtx *)p)->f148);
                values[7] = func_02008530(q);
                ((struct GtsnegoDispCtx *)p)->f18 = func_02008530(q);
            }
        }
        for (i = 0; i < 8; i++) {
            r = (MatchFilterRecord *)(p + 0x58) + i;
            MI_CpuCopy8(d_021D8B40 + i, &r->detail, 2);
            r->value = values[i];
            r->kind = DWC_AddMatchKeyInt(r->kind, (char *)(&r->detail), (int *)r);
        }
        func_0208D7E0((char *)p + 0xb8, d_021D8B50, *(unsigned int *)&((struct GtsnegoDispCtx *)p)->f138, 1);
        if (DWC_RAP_StartMatchWithFilter((int)p + 0xb8, 2, (int)GTSNEGO_DISP_ScoreMatch, (int)p)) {
            GFL_NET_STATE_WifiEnterFriendMatch();
            DWC_RAP_SetVchatEnabled(0);
            GTSNEGO_MSG_CreateConfirmUi(*(u8 * *)&((struct GtsnegoDispCtx *)p)->f40, (int)GTSNEGO_DISP_OnDisconnectCallback, (int)p);
            GTSNEGO_DISP_SetStateCallback(((int *)p), GTSNEGO_DISP_HandleTradeKeys, 0x41d);
            return;
        }
        GFL_NET_STATE_SetError(0, 0, 0, 0x3f1);
    }
}







void GTSNEGO_DISP_OnMenuCallback(void *p,int n,u8 *s) { if (n==0 && ((struct GtsnegoDispCtx *)s)->f4) { GTSNEGO_DISP_SetCursorState(*(u8 * *)&((struct GtsnegoDispCtx *)s)->f3C,((struct GtsnegoDispCtx *)s)->f34,9); func_020355D8(1); if ((*(int (**)(void *,void *))(s+4))(p,s)==0) return; } }







void GTSNEGO_DISP_OnConfirmDone(struct GtsnegoDispCtx *p)
{
    if (APP_TASKMENU_WIN_IsFinish(p->f34)) {
        APP_TASKMENU_WIN_Delete(p->f34);
        *(int *)&p->f34 = 0;
        func_02041B6C(5);
        GTSNEGO_MSG_PrintWindow(p->f40, 14);
        GTSNEGO_MSG_CreateIdleUi(p->f3C);
        GTSNEGO_MSG_PrintStatus(p->f40, 13);
        GTSNEGO_DISP_SetTradePalette(p->f3C, 1, 2);
        ((struct GtsnegoDispCtx_f48 *)p->f48)->f1B0 = 2;
        GTSNEGO_DISP_SetCursorState(p->f3C, 0, 9);
        GTSNEGO_DISP_SetStateCallback(((int *)p), GTSNEGO_DISP_StartMatchmaking, 0x460);
    }
}







void GTSNEGO_DISP_HandleConfirmKeys(u8 *p)
{
    int changed = 0;
    int done = 0;
    u8 *q = (u8 *)GTSNEGO_DISP_GetTouchbar(((struct GtsnegoDispCtx *)p)->f3C);
    if (GTSNEGO_MSG_UpdatePrintStream(((struct GtsnegoDispCtx *)p)->f40)) {
        if (TOUCHBAR_IsBusy(q) == 0) {
            GTSNEGO_MSG_UpdateButtons((char *)(*(int *)&((struct GtsnegoDispCtx *)p)->f40));
            if (KEY_GetTrg() != 0 && func_020355C4() == 1) {
                GTSNEGO_DISP_SetCursorState(((struct GtsnegoDispCtx *)p)->f3C, ((struct GtsnegoDispCtx *)p)->f34, ((struct GtsnegoDispCtx *)p)->f160);
                func_020355D8(changed);
                return;
            }
            if (KEY_GetTrg() == 0x20) GTSNEGO_DISP_MoveCursorVertical(0, (char *)p);
            if (KEY_GetTrg() == 0x10) GTSNEGO_DISP_MoveCursorVertical(1, (char *)p);
            if (KEY_GetTrg() == 0x40) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                changed = 1;
                if (((struct GtsnegoDispCtx *)p)->f160 != 2) --((struct GtsnegoDispCtx *)p)->f160;
            }
            if (KEY_GetTrg() == 0x80) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                changed = 1;
                if (((struct GtsnegoDispCtx *)p)->f160 != 5) ++((struct GtsnegoDispCtx *)p)->f160;
            }
            if (KEY_GetTrg() == 1 && ((struct GtsnegoDispCtx *)p)->f160 == 5) {
                GFL_USE_PlaySeDefaultVolume(0x54c);
                GTSNEGO_MSG_SetCursorAnimSeq(((struct GtsnegoDispCtx *)p)->f3C, ((struct GtsnegoDispCtx *)p)->f160);
                APP_TASKMENU_WIN_SetDecide(((struct GtsnegoDispCtx *)p)->f34, 1);
                GTSNEGO_DISP_SetStateCallback(((int *)p), GTSNEGO_DISP_OnConfirmDone, 0x4ca);
                return;
            }
            if (changed)
                GTSNEGO_DISP_SetCursorState(((struct GtsnegoDispCtx *)p)->f3C, ((struct GtsnegoDispCtx *)p)->f34, ((struct GtsnegoDispCtx *)p)->f160);
            if (TOUCHPANEL_HitTrg(d_021D88D0) == 0) {
                func_020355D8(1);
                GFL_USE_PlaySeDefaultVolume(0x54c);
                APP_TASKMENU_WIN_SetDecide(((struct GtsnegoDispCtx *)p)->f34, 1);
                GTSNEGO_DISP_SetStateCallback(((int *)p), GTSNEGO_DISP_OnConfirmDone, 0x4f2);
                return;
            }
        }
        TOUCHBAR_Update((struct TouchBar *)GTSNEGO_DISP_GetTouchbar(((struct GtsnegoDispCtx *)p)->f3C));
        if (TOUCHBAR_GetPressedButtonIdIfDone((u8 *)GTSNEGO_DISP_GetTouchbar(((struct GtsnegoDispCtx *)p)->f3C)) == 1) done = 1;
        if (done) {
            int zero = 0;
            func_02040588(4, 0);
            GTSNEGO_DISP_SetCursorState(((struct GtsnegoDispCtx *)p)->f3C, ((struct GtsnegoDispCtx *)p)->f34, 9);
            GTSNEGO_MSG_DeleteButtonsKeep(((struct GtsnegoDispCtx *)p)->f40);
            GTSNEGO_DISP_ResetActors(*(u8 * *)&((struct GtsnegoDispCtx *)p)->f3C);
            APP_TASKMENU_WIN_Delete(((struct GtsnegoDispCtx *)p)->f34);
            *(int *)&((struct GtsnegoDispCtx *)p)->f34 = zero;
            func_02041B6C(5);
            GTSNEGO_DISP_SetStateCallback(((int *)p), GTSNEGO_DISP_ShowPartySelect, 0x50b);
        }
    }
}







void GTSNEGO_DISP_CreateConfirmUi(u8 *p)
{
    ((struct GtsnegoDispCtx *)p)->f138 = 0;
    TOUCHBAR_SetAllButtonsVisible((u8 *)GTSNEGO_DISP_GetTouchbar(((struct GtsnegoDispCtx *)p)->f3C), 1);
    GTSNEGO_MSG_ClearRows(((struct GtsnegoDispCtx *)p)->f40);
    GTSNEGO_DISP_RedrawActors(((struct GtsnegoDispCtx *)p)->f3C);
    *(void * *)&((struct GtsnegoDispCtx *)p)->f4 = GTSNEGO_DISP_OnRowCursorMoved;
    GTSNEGO_MSG_CreateListUi(((struct GtsnegoDispCtx *)p)->f40, (int)GTSNEGO_DISP_OnMenuCallback, (int)p, ((struct GtsnegoDispCtx *)p)->f144, ((struct GtsnegoDispCtx *)p)->f13C, ((struct GtsnegoDispCtx *)p)->f140);
    GTSNEGO_MSG_PrintWindow(((struct GtsnegoDispCtx *)p)->f40, 20);
    ((struct GtsnegoDispCtx *)p)->f34 = GTSNEGO_MSG_CreateTooltip(((struct GtsnegoDispCtx *)p)->f40, 18);
    if (func_020355C4() == 0) {
        GTSNEGO_DISP_SetCursorState(((struct GtsnegoDispCtx *)p)->f3C, 0, ((struct GtsnegoDispCtx *)p)->f160);
        if (((struct GtsnegoDispCtx *)p)->f160 == 5)
            APP_TASKMENU_WIN_SetActive(((struct GtsnegoDispCtx *)p)->f34, 1);
    } else {
        GTSNEGO_DISP_SetCursorState(((struct GtsnegoDispCtx *)p)->f3C, 0, 9);
    }
    func_02041B6C(6);
    GTSNEGO_DISP_SetStateCallback(((int *)p), GTSNEGO_DISP_HandleConfirmKeys, 0x537);
}







void *GTSNEGO_DISP_GetEntry(void **p,int i) { int n; n=func_02009E8C(GAME_DATA_GetSaveBlock1F(p)); if (i>=n || i<0) return 0; return func_02009E54(GAME_DATA_GetSaveBlock1F(p),i); }






void *GTSNEGO_DISP_GetEntryClamped(void **p,int i) { int n; n=func_02009E8C(GAME_DATA_GetSaveBlock1F(p)); if (i<0) i=0; if (i>=n) i=n-1; return func_02009E54(GAME_DATA_GetSaveBlock1F(p),i); }







/*
 * Addresses are Black-image addresses.
 */
void GTSNEGO_DISP_ShowSubPlanes(u8 *p)
{
    GTSNEGO_DISP_ShowPartySelect(p);
    BG_SYS_SetSubVisiblePlanes(0x1f);
}









void GTSNEGO_DISP_Teardown(struct GtsnegoDispCtx *p) { GTSNEGO_MSG_Teardown(*(u8 * *)&p->f3C); GTSNEGO_MSG_DeleteAll(*(char * *)&p->f40); GTSNEGO_DISP_SetStateCallback(p, GTSNEGO_DISP_ShowSubPlanes, 0x5c5); }










void GTSNEGO_DISP_OnDisconnect(struct GtsnegoDispCtx *p)
{
    if (GTSNEGO_MSG_IsConfirmFinished(p->f40)) {
        BG_SYS_SetSubVisiblePlanes(8);
        GTSNEGO_MSG_DeleteButtonsKeep(p->f40);
        GTSNEGO_DISP_ResetActors(p->f3C);
        GTSNEGO_DISP_SetTradePalette(p->f3C, 0, 0);
        GTSNEGO_DISP_SetCursorState(p->f3C, 0, 9);
        func_02041B6C(5);
        if (p->f138 == 1) {
            func_02040588(4, 0);
            GTSNEGO_MSG_TeardownTileRows(p->f3C);
        }
        GTSNEGO_DISP_SetStateCallback(((int *)p), GTSNEGO_DISP_Teardown, 0x5dd);
    }
}










void GTSNEGO_DISP_OnDisconnectCallback(int a, int b, int *p)
{
    if (b == 0 && *(void **)p == GTSNEGO_DISP_HandleTradeKeys) {
        GTSNEGO_MSG_SetDecide(*(u8 * *)&((struct GtsnegoDispCtx *)p)->f40);
        GFL_NET_STATE_WifiDisconnect(1);
        func_020355D8(1);
        GFL_USE_PlaySeDefaultVolume(0x551);
        GTSNEGO_DISP_SetStateCallback(p, GTSNEGO_DISP_OnDisconnect, 0x5f5);
    }
}








void GTSNEGO_DISP_CreateExitTooltip(struct GtsnegoDispCtx *p) { p->f34=GTSNEGO_MSG_CreateTooltip(*(char * *)&p->f40,44); GTSNEGO_DISP_SetStateCallback(p, GTSNEGO_DISP_HandleListInput, 0x5ff); }







void GTSNEGO_DISP_OnExitMenuDone(struct GtsnegoDispCtx *p)
{
    int state;
    if (APP_TASKMENU_IsFinish(p->f38)) {
        int zero;
        state = APP_TASKMENU_GetCursorPos(p->f38);
        GTSNEGO_MSG_CloseMenu(*(int *)&p->f38);
        zero = 0;
        *(int *)&p->f38 = zero;
        TOUCHBAR_SetButtonVisible((unsigned char *)GTSNEGO_DISP_GetTouchbar(p->f3C), 1, 1);
        switch (state) {
        case 0:
            GTSNEGO_MSG_PrintWindow(p->f40, 0xe);
            GTSNEGO_MSG_CreateIdleUi(p->f3C);
            GTSNEGO_MSG_PrintStatus(p->f40, 0xd);
            p->f144 = zero;
            p->f13C = zero;
            p->f140 = zero;
            ((struct GtsnegoDispCtx_f48 *)p->f48)->f1B0 = 3;
            GTSNEGO_DISP_SetStateCallback(((int *)p), GTSNEGO_DISP_StartMatchmaking, 0x614);
            return;
        case 1:
            GTSNEGO_DISP_SetTradePalette(p->f3C, zero, zero);
            GTSNEGO_MSG_PrintWindow(p->f40, 0x13);
            if (func_020355C4() == 0)
                GTSNEGO_DISP_SetCursorState(p->f3C, 0, p->f164);
            else
                GTSNEGO_DISP_SetCursorState(p->f3C, 0, 9);
            GTSNEGO_MSG_RestartIconAnim(p->f3C, 1);
            GTSNEGO_DISP_SetStateCallback(((int *)p), GTSNEGO_DISP_CreateExitTooltip, 0x620);
            break;
        }
    }
}






void GTSNEGO_DISP_OpenExitMenu(struct GtsnegoDispCtx *p)
{
    if (GTSNEGO_MSG_UpdatePrintStream(p->f40)) {
        TOUCHBAR_SetButtonVisible((unsigned char *)GTSNEGO_DISP_GetTouchbar(p->f3C), 1, 0);
        p->f38 = GTSNEGO_MSG_OpenMenuB(p->f40, 1);
        GTSNEGO_DISP_SetTradePalette(p->f3C, 1, 1);
        GTSNEGO_MSG_RestartIconAnim(p->f3C, 0);
        GTSNEGO_DISP_SetStateCallback(((int *)p), GTSNEGO_DISP_OnExitMenuDone, 0x634);
    }
}









/*
 * lever: The caller has no halfword truncation before GTSNEGO_MSG_PrintWindow;
 * widen its copied u16 argument to int. Explicit calls in both branches
 * hoist the shared p+64 load; a ternary places it after the selection.
 */
void GTSNEGO_DISP_ShowListMessage(struct GtsnegoDispCtx *p) { if (p->f148==-1) GTSNEGO_MSG_PrintWindow(*(u8 * *)&p->f40,45); else GTSNEGO_MSG_PrintWindow(*(u8 * *)&p->f40,31); GTSNEGO_DISP_SetStateCallback(p, GTSNEGO_DISP_OpenExitMenu, 0x646); }









void GTSNEGO_DISP_EndList(struct GtsnegoDispCtx *p) { func_02040588(4,0); GTSNEGO_MSG_TeardownTileRows(*(u8 * *)&p->f3C); GTSNEGO_DISP_SetStateCallback(p, GTSNEGO_DISP_ShowPartySelect, 0x64e); }









/*
 * extent: two zero padding bytes at 0x021D5282 precede labelled 0x021D5284.
 */
int GTSNEGO_DISP_ListCursorUp(u8 *p)
{
    int result = GTSNEGO_MSG_CursorUp(((struct GtsnegoDispCtx *)p)->f3C, (int *)(p + 0x150));
    switch (result) {
    case 0: break;
    case 1:
        if (((struct GtsnegoDispCtx *)p)->f164 != 6)
            (((struct GtsnegoDispCtx *)p)->f164)--;
        break;
    case 2: {
        int index;
        GTSNEGO_MSG_SetScrollState(((struct GtsnegoDispCtx *)p)->f3C, 1);
        index = ((struct GtsnegoDispCtx *)p)->f158 - 1;
        if (index >= 0)
            GTSNEGO_MSG_PrintListEntryN(((struct GtsnegoDispCtx *)p)->f40, ((struct GtsnegoDispCtx *)p)->f2C, index);
        break;
    }
    }
    return result;
}









int GTSNEGO_DISP_ListCursorDown(u8 *p)
{
    int result = GTSNEGO_MSG_CursorDown(((struct GtsnegoDispCtx *)p)->f3C, (int *)(p + 0x150));
    switch (result) {
    case 0: break;
    case 1:
        if (((struct GtsnegoDispCtx *)p)->f164 != 8)
            (((struct GtsnegoDispCtx *)p)->f164)++;
        break;
    case 2:
        GTSNEGO_MSG_SetScrollState(((struct GtsnegoDispCtx *)p)->f3C, 2);
        GTSNEGO_MSG_PrintListEntryAt(((struct GtsnegoDispCtx *)p)->f40, ((struct GtsnegoDispCtx *)p)->f2C, ((struct GtsnegoDispCtx *)p)->f158 + 2);
        break;
    }
    return result;
}









void GTSNEGO_DISP_OnListConfirmDone(struct GtsnegoDispCtx *p)
{
    if (APP_TASKMENU_WIN_IsFinish(p->f34)) {
        APP_TASKMENU_WIN_Delete(p->f34);
        *(int *)&p->f34 = 0;
        p->f148 = -1;
        GTSNEGO_DISP_SetCursorState(p->f3C, 0, 9);
        func_02041B6C(5);
        GTSNEGO_DISP_SetStateCallback(((int *)p), GTSNEGO_DISP_ShowListMessage, 0x6ba);
    }
}










void GTSNEGO_DISP_DeleteMenuWindow(u8 *p)
{
    if (((struct GtsnegoDispCtx *)p)->f34) {
        APP_TASKMENU_WIN_Delete(((struct GtsnegoDispCtx *)p)->f34);
        func_02041B6C(5);
        *(u32 *)&((struct GtsnegoDispCtx *)p)->f34 = 0;
    }
}









void GTSNEGO_DISP_HandleListInput(Ctx *p)
{
    int out;
    int r;
    int acc = 0;
    int i;
    int sel;
    int x, y;
    out = 0;
    r = GTSNEGO_DISP_GetTouchbar(p->f3C);
    if (GTSNEGO_MSG_UpdatePrintStream(p->f40) == 0)
        return;
    if (TOUCHBAR_IsBusy((u8 *)r) != 0)
        goto end;
    r = GTSNEGO_MSG_StepScroll(p->f3C, &out);
    if (out == 1) {
        GTSNEGO_MSG_DrawTileRows(p->f3C, p->f2C, p->f158 - 2);
        GTSNEGO_MSG_ShiftListUp(p->f40);
        GTSNEGO_MSG_ScrollListUp(p->f3C, GTSNEGO_DISP_GetEntryClamped(p->f2C, p->f158 - 2));
    } else if (out == 2) {
        GTSNEGO_MSG_DrawTileRows(p->f3C, p->f2C, p->f158 - 2);
        GTSNEGO_MSG_ShiftListDown(p->f40);
        GTSNEGO_MSG_ScrollListDown(p->f3C, GTSNEGO_DISP_GetEntryClamped(p->f2C, p->f158 + 3));
    }
    if (r != 0)
        return;
    if (func_020355C4() == 1 && KEY_GetTrg() != 0) {
        GTSNEGO_DISP_SetCursorState(p->f3C, 0, p->f164);
        func_020355D8(0);
        return;
    }
    if (KEY_GetRepeat() == 0x100) {
        acc = 0;
        for (i = 0; i < 3; i++) {
            r = GTSNEGO_DISP_ListCursorDown((u8 *)p);
            acc |= r;
            GTSNEGO_MSG_ClearScrollState(p->f3C);
            if (r == 0)
                break;
            if (r == 1) {
                i--;
            } else {
                GTSNEGO_MSG_ScrollAllRows(p->f3C, 1);
                GTSNEGO_MSG_DrawTileRows(p->f3C, p->f2C, p->f158 - 2);
                GTSNEGO_MSG_ShiftListDown(p->f40);
                GTSNEGO_MSG_ScrollListDown(p->f3C, GTSNEGO_DISP_GetEntryClamped(p->f2C, p->f158 + 3));
                GTSNEGO_DISP_SetCursorState(p->f3C, 0, p->f164);
            }
        }
    }
    if (KEY_GetRepeat() == 0x200) {
        acc = 0;
        for (i = 0; i < 3; i++) {
            r = GTSNEGO_DISP_ListCursorUp((u8 *)p);
            acc |= r;
            GTSNEGO_MSG_ClearScrollState(p->f3C);
            if (r == 0)
                break;
            if (r == 1) {
                i--;
            } else {
                GTSNEGO_DISP_SetCursorState(p->f3C, 0, p->f164);
                GTSNEGO_MSG_ScrollAllRows(p->f3C, 0);
                GTSNEGO_MSG_DrawTileRows(p->f3C, p->f2C, p->f158 - 2);
                GTSNEGO_MSG_ShiftListUp(p->f40);
                GTSNEGO_MSG_ScrollListUp(p->f3C, GTSNEGO_DISP_GetEntryClamped(p->f2C, p->f158 - 2));
            }
        }
    }
    if (KEY_GetRepeat() == 0x40)
        acc = GTSNEGO_DISP_ListCursorUp((u8 *)p);
    if (KEY_GetRepeat() == 0x80)
        acc = GTSNEGO_DISP_ListCursorDown((u8 *)p);
    if (acc != 0) {
        GFL_USE_PlaySeDefaultVolume(0x548);
        GTSNEGO_MSG_SetIconY(p->f3C, p->f158 + p->f164 - 6, p->f150);
        GTSNEGO_DISP_SetCursorState(p->f3C, 0, p->f164);
        return;
    }
    if (KEY_GetTrg() == 1) {
        GFL_USE_PlaySeDefaultVolume(0x54C);
        GTSNEGO_MSG_SetCursorAnimSeq(p->f3C, p->f164);
        p->f148 = p->f158 + p->f164 - 6;
        GTSNEGO_DISP_DeleteMenuWindow((u8 *)p);
        GTSNEGO_DISP_SetStateCallback(((int *)p), GTSNEGO_DISP_ShowListMessage, 0x760);
        return;
    }
    if (KEY_GetTrg() == 8) {
        GFL_USE_PlaySeDefaultVolume(0x54C);
        APP_TASKMENU_WIN_SetDecide(p->f34, 1);
        GTSNEGO_DISP_SetStateCallback(((int *)p), GTSNEGO_DISP_OnListConfirmDone, 0x766);
        return;
    }
    sel = TOUCHPANEL_HitTrg(d_021D88D8);
    switch (sel) {
    case 3:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        APP_TASKMENU_WIN_SetDecide(p->f34, 1);
        GTSNEGO_DISP_SetStateCallback(((int *)p), GTSNEGO_DISP_OnListConfirmDone, 0x770);
        return;
    case 2:
        if (p->f150 < 3)
            break;
    case 1:
        if (p->f150 < 2)
            break;
    case 0:
        func_020355D8(1);
        p->f164 = sel + 6;
        GTSNEGO_DISP_SetCursorState(p->f3C, 0, p->f164);
        GTSNEGO_MSG_SetCursorAnimSeq(p->f3C, p->f164);
        p->f148 = p->f158 + p->f164 - 6;
        GTSNEGO_MSG_SetCursorIndex(p->f3C, &p->f150, sel);
        GTSNEGO_MSG_SetIconY(p->f3C, p->f158 + p->f164 - 6, p->f150);
        GFL_USE_PlaySeDefaultVolume(0x54C);
        GTSNEGO_DISP_DeleteMenuWindow((u8 *)p);
        GTSNEGO_DISP_SetStateCallback(((int *)p), GTSNEGO_DISP_ShowListMessage, 0x78B);
        return;
    }
    if (TOUCHPANEL_HitCont(d_021D88C8) != 0)
        goto end;
    if (TOUCHPANEL_GetPointCont((u32 *)(&x), (u32 *)(&y)) == 1) {
        r = GTSNEGO_MSG_SetIconYClamped((char *)p->f3C, y, p->f150);
        if (p->f158 != r) {
            p->f158 = r;
            GTSNEGO_MSG_PrintListRange(p->f40, p->f2C, r - 2);
            GTSNEGO_MSG_FillListRange(p->f3C, p->f2C, p->f158 - 2);
            GTSNEGO_MSG_DrawTileRows(p->f3C, p->f2C, p->f158 - 2);
            GFL_USE_PlaySeDefaultVolume(0x548);
        }
    }
    return;
end:
    TOUCHBAR_Update((struct TouchBar *)GTSNEGO_DISP_GetTouchbar(p->f3C));
    if (TOUCHBAR_GetPressedButtonIdIfDone((u8 *)GTSNEGO_DISP_GetTouchbar(p->f3C)) == 1) {
        func_02040588(4, 0);
        func_02040588(6, 0);
        GTSNEGO_DISP_DeleteMenuWindow((u8 *)p);
        GTSNEGO_DISP_SetCursorState(p->f3C, p->f34, 9);
        GTSNEGO_MSG_TeardownActorList(p->f3C);
        GTSNEGO_MSG_ClearRows(p->f40);
        GTSNEGO_DISP_SetStateCallback(((int *)p), GTSNEGO_DISP_EndList, 0x7AD);
    }
}








void GTSNEGO_DISP_WaitSelectStart(struct GtsnegoDispCtx *p)
{
    if (GTSNEGO_MSG_UpdatePrintStream(p->f40)) {
        if (--p->f14 <= 0) {
            GTSNEGO_MSG_PrintWindow(p->f40, 0x20);
            TOUCHBAR_SetAllButtonsVisible((u8 *)GTSNEGO_DISP_GetTouchbar(p->f3C), 1);
            GTSNEGO_DISP_SetStateCallback(((int *)p), GTSNEGO_DISP_HandlePartyInput, 0x7c7);
            if (func_020355C4() == 0)
                GTSNEGO_DISP_SetCursorState(p->f3C, 0, p->f15C);
        }
    }
}








void GTSNEGO_DISP_ShowPokemonList(struct GtsnegoDispCtx *p)
{
    int flag = 1;
    int n = func_02009E8C(GAME_DATA_GetSaveBlock1F(*(void ** *)&p->f2C));
    p->f138 = flag;
    if (n == 0) {
        GTSNEGO_MSG_PrintWindow(p->f40, 0x1d);
        p->f14 = 0x78;
        GTSNEGO_DISP_SetStateCallback(((int *)p), GTSNEGO_DISP_WaitSelectStart, 0x7e7);
        return;
    }
    p->f150 = n;
    GTSNEGO_MSG_PrintWindow(p->f40, 0x13);
    if (func_020355C4() == 0)
        GTSNEGO_DISP_SetCursorState(p->f3C, 0, p->f164);
    else
        GTSNEGO_DISP_SetCursorState(p->f3C, 0, 9);
    GTSNEGO_MSG_ClearRows(p->f40);
    if (n <= 3) flag = 0;
    GTSNEGO_MSG_InitWindows(*(u8 * *)&p->f3C, flag);
    GTSNEGO_MSG_PrintList(*(char * *)&p->f40, p->f2C);
    GTSNEGO_MSG_PrintListRange(p->f40, p->f2C, p->f158 - 2);
    GTSNEGO_MSG_FillListRange(p->f3C, p->f2C, p->f158 - 2);
    GTSNEGO_MSG_DrawTileRows(p->f3C, p->f2C, p->f158 - 2);
    p->f34 = GTSNEGO_MSG_CreateTooltip(*(char * *)&p->f40, 0x2c);
    GTSNEGO_MSG_SetIconY(p->f3C, p->f158 + p->f164 - 6, p->f150);
    GTSNEGO_DISP_SetStateCallback(((int *)p), GTSNEGO_DISP_HandleListInput, 0x815);
}









void GTSNEGO_DISP_ShowPartySelect(u8 *p)
{
    GTSNEGO_MSG_SetupRowBg(((struct GtsnegoDispCtx *)p)->f3C);
    if (((struct GtsnegoDispCtx *)p)->f1B0) {
        if ((((struct GtsnegoDispCtx *)p)->f1B4)++ < 3)
            return;
        func_0200F800();
        ((struct GtsnegoDispCtx *)p)->f1B0 = 0;
    }
    if (func_020355C4() == 0)
        GTSNEGO_DISP_SetCursorState(((struct GtsnegoDispCtx *)p)->f3C, 0, ((struct GtsnegoDispCtx *)p)->f15C);
    else
        GTSNEGO_DISP_SetCursorState(((struct GtsnegoDispCtx *)p)->f3C, 0, 9);
    GTSNEGO_MSG_CreateYesNoUi(((struct GtsnegoDispCtx *)p)->f40, (int)GTSNEGO_DISP_OnMenuCallback, (int)p);
    *(void (**)(void))(p + 4) = (void (*)(void))GTSNEGO_DISP_StartTrade;
    if ((int)POKEPARTY_GetNonEggCount(GAME_DATA_GetMyParty(((struct GtsnegoDispCtx *)p)->f2C)) < 2)
        ((struct GtsnegoDispCtx *)p)->f184 = 1;
    if (((struct GtsnegoDispCtx *)p)->f184 == 0)
        GTSNEGO_MSG_PrintWindow(((struct GtsnegoDispCtx *)p)->f40, 0x20);
    else
        GTSNEGO_MSG_PrintWindow(((struct GtsnegoDispCtx *)p)->f40, 0x2b);
    func_02040588(4, 1);
    func_02040588(6, 1);
    GTSNEGO_DISP_SetStateCallback(p, GTSNEGO_DISP_HandlePartyInput, 0x86c);
}









int GTSNEGO_DISP_SelectParty(u8 *p,int n) { if (GTSNEGO_MSG_SetCursorAnimSeq(((struct GtsnegoDispCtx *)p)->f3C,n)) { TOUCHBAR_SetAllButtonsVisible((u8 *)GTSNEGO_DISP_GetTouchbar((u8 *)(((struct GtsnegoDispCtx *)p)->f3C)),0); GFL_USE_PlaySeDefaultVolume(1356); return n; } return 9; }










int GTSNEGO_DISP_CheckPartySelect(struct GtsnegoDispCtx *p, int x)
{
    if (GTSNEGO_MSG_IsCursorAnimDone(p->f3C) == 0)
        x = 9;
    return x;
}









void GTSNEGO_DISP_OnPartySelected(struct GtsnegoDispCtx *p)
{
    int state = GTSNEGO_DISP_CheckPartySelect(p, p->f15C);
    if (state == 0) {
        GTSNEGO_DISP_SetCursorState(p->f3C, p->f34, 9);
        GTSNEGO_MSG_ClearRows(*(char * *)&p->f40);
        func_02041B6C(6);
        GTSNEGO_DISP_SetStateCallback(p, GTSNEGO_DISP_CreateConfirmUi, 0x8a3);
        return;
    }
    if (state == 1) {
        GTSNEGO_DISP_SetCursorState(p->f3C, p->f34, 9);
        GTSNEGO_DISP_SetStateCallback(p, GTSNEGO_DISP_ShowPokemonList, 0x8a7);
    }
}









void GTSNEGO_DISP_OnPartyMenuDone(struct GtsnegoDispCtx *p)
{
    int state;
    if (APP_TASKMENU_IsFinish(p->f38)) {
        state = APP_TASKMENU_GetCursorPos(p->f38);
        GTSNEGO_MSG_CloseMenu(*(int *)&p->f38);
        *(int *)&p->f38 = 0;
        switch (state) {
        case 0:
            ((struct GtsnegoDispCtx_f48 *)p->f48)->f1B0 = 1;
            p->f14 = 0;
            GTSNEGO_DISP_SetStateCallback(p, GTSNEGO_DISP_StartWipe, 0x8b5);
            return;
        case 1:
            if (p->f184 == 0)
                GTSNEGO_MSG_PrintWindow(p->f40, 0x20);
            else
                GTSNEGO_MSG_PrintWindow(p->f40, 0x2b);
            if (func_020355C4() == 0)
                GTSNEGO_DISP_SetCursorState(p->f3C, 0, p->f15C);
            TOUCHBAR_SetButtonVisible((unsigned char *)GTSNEGO_DISP_GetTouchbar(p->f3C), 1, 1);
            GTSNEGO_DISP_SetTradePalette(p->f3C, 0, 0);
            GTSNEGO_DISP_SetStateCallback(p, GTSNEGO_DISP_HandlePartyInput, 0x8c3);
            break;
        }
    }
}









void GTSNEGO_DISP_OpenPartyMenu(struct GtsnegoDispCtx *p)
{
    if (GTSNEGO_MSG_UpdatePrintStream(p->f40)) {
        TOUCHBAR_SetButtonVisible((unsigned char *)GTSNEGO_DISP_GetTouchbar(p->f3C), 1, 0);
        p->f38 = GTSNEGO_MSG_OpenMenu(p->f40, 1);
        GTSNEGO_DISP_SetTradePalette(p->f3C, 1, 0);
        GTSNEGO_DISP_SetCursorState(p->f3C, 0, 9);
        GTSNEGO_DISP_SetStateCallback(p, GTSNEGO_DISP_OnPartyMenuDone, 0x8d4);
    }
}









void GTSNEGO_DISP_HandlePartyInput(u8 *p)
{
    int changed = 0;
    u8 *q = (u8 *)GTSNEGO_DISP_GetTouchbar(((struct GtsnegoDispCtx *)p)->f3C);
    if (GTSNEGO_MSG_UpdatePrintStream(((struct GtsnegoDispCtx *)p)->f40)) {
        if (TOUCHBAR_IsBusy(q) == 0) {
            if (KEY_GetTrg() != 0 && func_020355C4() == 1) {
                GTSNEGO_DISP_SetCursorState(((struct GtsnegoDispCtx *)p)->f3C, 0, ((struct GtsnegoDispCtx *)p)->f15C);
                func_020355D8(changed);
                return;
            }
            if (KEY_GetTrg() == 1) {
                if (((struct GtsnegoDispCtx *)p)->f184 == 0) {
                    GTSNEGO_DISP_SelectParty(p, ((struct GtsnegoDispCtx *)p)->f15C);
                    GTSNEGO_DISP_SetStateCallback(p, GTSNEGO_DISP_OnPartySelected, 0x8f4);
                    return;
                }
                GFL_USE_PlaySeDefaultVolume(0x551);
            }
            if (KEY_GetTrg() == 0x40) {
                changed = 1;
                GFL_USE_PlaySeDefaultVolume(0x548);
                ((struct GtsnegoDispCtx *)p)->f15C = 0;
            }
            if (KEY_GetTrg() == 0x80) {
                changed = 1;
                GFL_USE_PlaySeDefaultVolume(0x548);
                ((struct GtsnegoDispCtx *)p)->f15C = 1;
            }
            if (changed)
                GTSNEGO_DISP_SetCursorState(((struct GtsnegoDispCtx *)p)->f3C, 0, ((struct GtsnegoDispCtx *)p)->f15C);
            GTSNEGO_MSG_UpdateButtons((char *)(*(int *)&((struct GtsnegoDispCtx *)p)->f40));
        }
        TOUCHBAR_Update((struct TouchBar *)GTSNEGO_DISP_GetTouchbar(((struct GtsnegoDispCtx *)p)->f3C));
        if (TOUCHBAR_GetPressedButtonIdIfDone((u8 *)GTSNEGO_DISP_GetTouchbar(((struct GtsnegoDispCtx *)p)->f3C)) == 1) {
            ((struct GtsnegoDispCtx *)p)->f14 = 1;
            GTSNEGO_MSG_PrintWindow(((struct GtsnegoDispCtx *)p)->f40, 0x2a);
            if (func_020355C4() == 1)
                GTSNEGO_DISP_SetCursorState(((struct GtsnegoDispCtx *)p)->f3C, 0, 9);
            GTSNEGO_DISP_SetStateCallback(p, GTSNEGO_DISP_OpenPartyMenu, 0x916);
        }
    }
}









void GTSNEGO_DISP_ResetScreen(u8 *p)
{
    if (((struct GtsnegoDispCtx_f48 *)((struct GtsnegoDispCtx *)p)->f48)->f1B0 != 1) {
        int zero = 0;
        GFL_NET_SetAutoExit(0);
        GFL_NET_SetLoginOption(0);
        GTSNEGO_MSG_DeleteDraw(*(u8 * *)&((struct GtsnegoDispCtx *)p)->f40);
        GTSNEGO_DISP_SetTradePalette(((struct GtsnegoDispCtx *)p)->f3C, 0, 0);
        func_02040588(4, 0);
        GTSNEGO_MSG_Teardown(((struct GtsnegoDispCtx *)p)->f3C);
        GTSNEGO_MSG_DeleteWindow((char *)(*(int *)&((struct GtsnegoDispCtx *)p)->f40));
        GTSNEGO_MSG_DeleteAll(*(char * *)&((struct GtsnegoDispCtx *)p)->f40);
        GTSNEGO_DISP_SetCursorState(((struct GtsnegoDispCtx *)p)->f3C, 0, 9);
        *(int *)&((struct GtsnegoDispCtx *)p)->f1B0 = 1;
        *(int *)&((struct GtsnegoDispCtx *)p)->f1B4 = zero;
        ((struct GtsnegoDispCtx_f48 *)((struct GtsnegoDispCtx *)p)->f48)->f1B0 = 1;
        GTSNEGO_DISP_SetStateCallback(p, GTSNEGO_DISP_ShowPartySelect, 0x937);
    }
}








/*
 * volatile: hardware halfword registers written at 0x021D5C78 and 0x021D5C7E.
 * prototype: 0203064C r2 explicitly loaded despite two-arg definition;
 * 0203159C r0 allocation result used despite void matched definition.
 */
int GTSNEGO_DISP_Create(void *a, int unused, u8 *q)
{
    u8 *p;
    int zero = 0;
    GFL_HEAP_CreateChildHeap(1, 0x1f, 0x38000);
    *(volatile u16 *)0x04000050 = zero;
    *(volatile u16 *)0x04001050 = zero;
    WIPE_SetBrightnessFadeOut(0, 0);
    WIPE_SetBrightnessFadeOut(1, 0);
    p = PROCSYS_AllocProcWork(a, 0x1b8, 0x1f);
    MI_CpuFill8(p, 0, 0x1b8);
    ((struct GtsnegoDispCtx *)p)->fC = 0x1f;
    *(u8 * *)&((struct GtsnegoDispCtx *)p)->f48 = q;
    ((struct GtsnegoDispCtx *)p)->f3C = GTSNEGO_DISP_CreateMsgSystem(((struct GtsnegoDispCtx *)p)->fC, ((struct GtsnegoDispCtx *)q)->f0);
    ((struct GtsnegoDispCtx *)p)->f40 = GTSNEGO_MSG_Create(((struct GtsnegoDispCtx *)p)->fC, 0x28);
    ((struct GtsnegoDispCtx *)p)->f2C = ((struct GtsnegoDispCtx *)q)->f0;
    ((struct GtsnegoDispCtx *)p)->f30 = GAME_DATA_GetSaveControl(((struct GtsnegoDispCtx *)q)->f0);
    ((struct GtsnegoDispCtx *)p)->f44 = GAME_DATA_GetField1A0(((struct GtsnegoDispCtx *)q)->f0);
    ((struct GtsnegoDispCtx_f48 *)((struct GtsnegoDispCtx *)p)->f48)->f1B0 = 1;
    ((struct GtsnegoDispCtx *)p)->f15C = zero;
    ((struct GtsnegoDispCtx *)p)->f160 = 2;
    ((struct GtsnegoDispCtx *)p)->f164 = 6;
    ((struct GtsnegoDispCtx *)p)->f14C = func_02008530((const struct Sub0200852CObj *)GAME_DATA_GetMyStatus(((struct GtsnegoDispCtx *)q)->f0));
    if (GFL_NET_GetRunState())
        GFL_NET_COMMAND_AddCommandTable(0x2200, (u32)d_021D88EC, 3, (u32)p);
    WIPE_SYS_Start(0, 1, 1, 0, 6, 1, ((struct GtsnegoDispCtx *)p)->fC);
    GFL_USE_CancelChangeAndPlayBgm(0x486, 0xffff);
    GFL_NET_RestartWithDefaultTimeout(1, ((struct GtsnegoDispCtx *)p)->fC);
    func_0200F7E8(1);
    GTSNEGO_DISP_SetStateCallback(p, GTSNEGO_DISP_ShowPartySelect, 0x96a);
    return 1;
}








int GTSNEGO_DISP_Step(int a, int b, int c, u8 *p)
{
    void (*callback)(u8 *) = *(void (**)(u8 *))p;
    int result = 1;
    if (callback) {
        if (func_0200FB24() == 0)
            callback(p);
        result = 0;
    }
    if (((struct GtsnegoDispCtx *)p)->f34) {
        void *q = (void *)GTSNEGO_DISP_GetTouchbar(((struct GtsnegoDispCtx *)p)->f3C);
        if (q == 0 || TOUCHBAR_IsBusy(q) == 0)
            APP_TASKMENU_WIN_Update(((struct GtsnegoDispCtx *)p)->f34);
    }
    if (((struct GtsnegoDispCtx *)p)->f38)
        APP_TASKMENU_UpdateMenu(((struct GtsnegoDispCtx *)p)->f38);
    GTSNEGO_DISP_DrawSystem(((struct GtsnegoDispCtx *)p)->f3C);
    GTSNEGO_MSG_Main(((struct GtsnegoDispCtx *)p)->f40);
    if (GFL_NET_GetRunState()) {
        if (func_0200FB24()) {
            switch (DWC_RAPCOMMON_HandleNetError(1, 1)) {
            case 0: break;
            case 1:
            case 4:
                GTSNEGO_DISP_ResetScreen(p);
                break;
            case 2:
                ((struct GtsnegoDispCtx_f48 *)((struct GtsnegoDispCtx *)p)->f48)->f1B0 = 0;
                result = 1;
                WIPE_SetBrightnessFadeOut(0, 0);
                WIPE_SetBrightnessFadeOut(1, 0);
                break;
            case 3:
                func_0200F7DC();
                break;
            }
        }
    } else if (func_0200FB24()) {
        result = 1;
    }
    return result;
}








/*
 * trailing: 2-byte zero alignment padding at 0x021D5E86.
 */
int GTSNEGO_DISP_Delete(void *p, int a, int b, struct GtsnegoDispCtx *q)
{
    func_0200F7F4();
    if (!WIPE_SYS_EndCheck()) return 0;
    if (GFL_NET_GetRunState()) GFL_NET_COMMAND_DeleteCommandTable(0x2200);
    if (q->f34) APP_TASKMENU_WIN_Delete(q->f34);
    if (q->f38) APP_TASKMENU_CloseMenu(q->f38);
    GTSNEGO_MSG_Delete(q->f40);
    GTSNEGO_DISP_DeleteMsgSystem(q->f3C);
    func_020315D4(p);
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
    u8 *p;
    p=func_02030734(heap,0x164,1,d_021D8BC8,258);
    ((struct GtsnegoMsgCtx *)p)->fF4=heap;
    ((struct GtsnegoMsgCtx *)p)->f118=arg;
    func_02034AC4((int)ov_id);
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    BMP_SetDisplaySwap(1);
    *(volatile u32 *)0x04001000|=0x10000;
    GX_DispOn();
    BG_SYS_Create(((struct GtsnegoMsgCtx *)p)->fF4);
    CLACT_InitSystem((const struct Cfg *)d_021D8974,(u32)(&d_021D8B98),((struct GtsnegoMsgCtx *)p)->fF4);
    ((struct GtsnegoMsgCtx *)p)->f10=CLACT_CreateUnit(64,0,((struct GtsnegoMsgCtx *)p)->fF4);
    BG_SYS_SetVramBanks(&d_021D8B98);
    BG_SYS_SetGraphicsMode(&d_021D8B60);
    GTSNEGO_DISP_InitBgLayers(p);
    GTSNEGO_DISP_RegisterGraphics(p);
    ((struct GtsnegoMsgCtx *)p)->f14=func_020056A0(GTSNEGO_DISP_VBlank,p,0);
    ((struct GtsnegoMsgCtx *)p)->f124=func_02030734(((struct GtsnegoMsgCtx *)p)->fF4,0x200,0,d_021D8BC8,280);
    ((struct GtsnegoMsgCtx *)p)->f128=func_02030734(((struct GtsnegoMsgCtx *)p)->fF4,0x200,0,d_021D8BC8,281);
    GTSNEGO_DISP_CreateCursorActor(p);
    GTSNEGO_DISP_CreateTouchbar(p,0);
    BG_SYS_SetSubVisiblePlanes(31);
    BG_SYS_SetMainVisiblePlanes(31);
    return p;
}








void GTSNEGO_DISP_DrawSystem(struct GtsnegoMsgCtx *p){CLACT_DrawSystem();if(p->fF8)BLINK_PALANM_Update(p->fF8);if(p->fFC)BLINK_PALANM_Update(p->fFC);GTSNEGO_MSG_StepIdleFade((char *)p);}








void GTSNEGO_DISP_DeleteMsgSystem(u8 *p)
{
    int i;
    CLACT_DeleteActor(((struct GtsnegoMsgCtx *)p)->f134);
    GTSNEGO_DISP_DeleteTouchbar(p);
    GTSNEGO_MSG_DeleteCursorActor(p);
    GTSNEGO_MSG_DeleteTileHandle(p);
    func_020307B0(((struct GtsnegoMsgCtx *)p)->f124);
    func_020307B0(((struct GtsnegoMsgCtx *)p)->f128);
    GTSNEGO_MSG_DeleteActors(p);
    CLACT_ReleasePalette((u32)(((struct GtsnegoMsgCtx *)p)->f18));
    CLACT_ReleasePalette((u32)(((struct GtsnegoMsgCtx *)p)->f1C));
    CLACT_ReleaseCharacter((u32)(*(void * *)&((struct GtsnegoMsgCtx *)p)->f28));
    CLACT_ReleaseCharacter((u32)(((struct GtsnegoMsgCtx *)p)->f2C));
    CLACT_ReleaseCellAnim((u32)(*(void * *)&((struct GtsnegoMsgCtx *)p)->f74));
    CLACT_ReleaseCellAnim((u32)(((struct GtsnegoMsgCtx *)p)->f78));
    CLACT_ReleasePalette((u32)(((struct GtsnegoMsgCtx *)p)->f24));
    CLACT_ReleaseCharacter((u32)(((struct GtsnegoMsgCtx *)p)->f70));
    CLACT_ReleaseCellAnim((u32)(((struct GtsnegoMsgCtx *)p)->fBC));
    CLACT_ReleasePalette((u32)(((struct GtsnegoMsgCtx *)p)->f20));
    for(i=0;i<16;i++) {
        CLACT_ReleaseCharacter((u32)(*(void **)(p+i*4+0x30)));
        CLACT_ReleaseCellAnim((u32)(*(void **)(p+i*4+0x7c)));
    }
    func_02030EAC(((struct GtsnegoMsgCtx *)p)->f14);
    CLACT_DeleteUnit(((struct GtsnegoMsgCtx *)p)->f10);
    CLACT_ExitSystem();
    func_0202EA20(((struct GtsnegoMsgCtx *)p)->fF8);
    func_0202EA20(((struct GtsnegoMsgCtx *)p)->fFC);
    BG_SYS_DeleteHalf(7,(u16)(*(unsigned int *)&((struct GtsnegoMsgCtx *)p)->f8),(u16)(*(unsigned int *)&((struct GtsnegoMsgCtx *)p)->f8>>16));
    BG_SYS_DeleteHalf(4,(u16)(((struct GtsnegoMsgCtx *)p)->f0),(u16)(((struct GtsnegoMsgCtx *)p)->f0>>16));
    BG_SYS_DeleteHalf(0,(u16)(((struct GtsnegoMsgCtx *)p)->f4),(u16)(((struct GtsnegoMsgCtx *)p)->f4>>16));
    BG_SYS_SetTileUnit(1,1,0);
    BG_SYS_SetTileUnit(5,1,0);
    BG_SYS_SetTileUnit(6,1,0);
    func_02040588(5,0);
    for(i=0;i<=7;i++) BG_SYS_FreeLayerBuf((u8)i);
    BG_SYS_Delete();
    func_020307B0(p);
    func_02034A5C((int)ov_id);
}









u32 GTSNEGO_DISP_GetUnit(struct GtsnegoDispCtx *p){return p->f10;}









/*
 * BG-layer init: eight copies of the const template table at 0x021D89B0
 * (index order 0,5,1,2,3,4,6,7) passed to BG_SYS_InitBgLayer, each followed by
 * its layer enable / fill sequence.  The local array is written high-to-low
 * (b[7] first) because the original places the first-used slot at the top of
 * the frame.
 */
void GTSNEGO_DISP_InitBgLayers(u8 *a0)
{
    struct BgTemplate b[8];

    b[7] = d_021D89B0[0];
    BG_SYS_InitBgLayer(0, &b[7], 0);
    BG_SYS_FreeSlot(0);
    BG_SYS_PushTile(0);
    func_02040588(0, 1);

    b[6] = d_021D89B0[5];
    BG_SYS_InitBgLayer(1, &b[6], 0);
    func_02040588(1, 1);
    BG_SYS_Init(1, 0, 1, 0);
    BG_SYS_SetTileEntry(1, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_PushTile(1);

    b[5] = d_021D89B0[1];
    BG_SYS_InitBgLayer(2, &b[5], 0);
    func_02040588(2, 1);
    BG_SYS_SetTileEntry(2, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_PushTile(2);

    b[4] = d_021D89B0[2];
    BG_SYS_InitBgLayer(3, &b[4], 0);
    func_02040588(3, 1);
    BG_SYS_SetTileEntry(3, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_PushTile(3);

    b[3] = d_021D89B0[3];
    BG_SYS_InitBgLayer(4, &b[3], 0);
    func_02040588(4, 1);
    BG_SYS_PushTile(4);

    b[2] = d_021D89B0[4];
    BG_SYS_InitBgLayer(5, &b[2], 0);
    func_02040588(5, 1);
    BG_SYS_Init(5, 0, 1, 0);
    BG_SYS_SetTileEntry(5, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_PushTile(5);

    b[1] = d_021D89B0[6];
    BG_SYS_InitBgLayer(6, &b[1], 0);
    func_02040588(6, 1);
    BG_SYS_Init(6, 0, 1, 0);
    BG_SYS_SetTileEntry(6, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_PushTile(6);

    b[0] = d_021D89B0[7];
    BG_SYS_InitBgLayer(7, &b[0], 0);
    func_02040588(7, 1);
    BG_SYS_PushTile(7);
}








void GTSNEGO_DISP_BlendPalette(struct GtsnegoMsgCtx *p,int bank,int *offset,int *size,int count)
{
    int i;
    void *obj;
    u8 *buffer;
    obj=PALANM_Create(p->fF4);
    PALANM_AllocSlotBuffers(obj,bank,0x200,p->fF4);
    PALANM_CopyHwPaletteToSlot(obj,bank,0,0x200);
    PALANM_BlendChannel(obj,bank,0,0x100,6,0);
    buffer=(u8 *)PALANM_GetTransWork(obj,bank);
    for(i=0;i<count;i++) {
        switch(bank) {
        case 3:
            DWCi_ScreenDC_FlushRange(buffer+offset[i]*32,size[i]*32);
            func_0207E5D0(buffer+offset[i]*32,offset[i]*32,size[i]*32);
            break;
        case 1:
            DWCi_ScreenDC_FlushRange(buffer+offset[i]*32,size[i]*32);
            func_0207E468(buffer+offset[i]*32,offset[i]*32,size[i]*32);
            break;
        }
    }
    PALANM_FreeSlotBuffers(obj,bank);
    PALANM_Delete(obj);
}








/*
 * lever: one-word aggregate locals preserve the early address setup and merge.
 */
void GTSNEGO_DISP_SetTradePalette(struct GtsnegoMsgCtx *p,int flag,int mode)
{
    if(flag) {
        MI_CpuCopy8((void *)0x05000600,p->f124,0x200);
        MI_CpuCopy8((void *)0x05000400,p->f128,0x200);
        switch(mode) {
        case 2: {
            Word a={0};
            Word b=d_021D8920;
            GTSNEGO_DISP_BlendPalette(p,3,&a.a,&b.a,1);
            break;
        }
        case 0: {
            Word a=d_021D891C;
            Word b=d_021D8918;
            GTSNEGO_DISP_BlendPalette(p,3,&a.a,&b.a,1);
            break;
        }
        case 1: {
            Pair a=d_021D895C;
            Pair b=d_021D896C;
            GTSNEGO_DISP_BlendPalette(p,3,&a.a,&b.a,2);
            break;
        }
        }
        switch(mode) {
        case 0: case 2: {
            Pair a=d_021D894C;
            Pair b=d_021D8954;
            GTSNEGO_DISP_BlendPalette(p,1,&a.a,&b.a,2);
            break;
        }
        case 1: {
            Pair a=d_021D8944;
            Pair b=d_021D8964;
            GTSNEGO_DISP_BlendPalette(p,1,&a.a,&b.a,2);
            break;
        }
        }
    } else {
        DWCi_ScreenDC_FlushRange(p->f124,0x200);
        func_0207E5D0(p->f124,0,0x200);
        DWCi_ScreenDC_FlushRange(p->f128,0x200);
        func_0207E468(p->f128,0,0x200);
    }
}








/*
 * extent: two-byte zero alignment padding follows.
 */
void GTSNEGO_DISP_VBlank(void *unused,u8 *p){CLACT_VBlankSystem();if(((struct GtsnegoMsgCtx *)p)->f100){BG_SYS_FillScrollArea(4,3,*(unsigned int *)&((struct GtsnegoMsgCtx *)p)->f104+72);BG_SYS_FillScrollArea(6,3,*(unsigned int *)&((struct GtsnegoMsgCtx *)p)->f104+72);((struct GtsnegoMsgCtx *)p)->f100=0;}}








void GTSNEGO_DISP_RegisterGraphics(u8 *p)
{
    int i;
    void *t;
    t=func_020490F4((u32)((void *)144),((struct GtsnegoMsgCtx *)p)->fF4);
    func_02049B68(t,3,4,0,192,((struct GtsnegoMsgCtx *)p)->fF4);
    func_02049B68(t,1,4,0,64,((struct GtsnegoMsgCtx *)p)->fF4);
    *(unsigned int *)&((struct GtsnegoMsgCtx *)p)->f8=func_02049740(t,6,7,0,0,((struct GtsnegoMsgCtx *)p)->fF4);
    func_02049990(t,17,7,0,(u16)(*(unsigned int *)&((struct GtsnegoMsgCtx *)p)->f8),0,0,((struct GtsnegoMsgCtx *)p)->fF4);
    ((struct GtsnegoMsgCtx *)p)->f0=func_02049740(t,8,4,0,0,((struct GtsnegoMsgCtx *)p)->fF4);
    func_02049990(t,18,4,0,(u16)(((struct GtsnegoMsgCtx *)p)->f0),0,0,((struct GtsnegoMsgCtx *)p)->fF4);
    func_02049B68(t,1,0,0,0,((struct GtsnegoMsgCtx *)p)->fF4);
    ((struct GtsnegoMsgCtx *)p)->f4=func_02049740(t,6,0,0,0,((struct GtsnegoMsgCtx *)p)->fF4);
    func_02049990(t,12,0,0,(u16)(((struct GtsnegoMsgCtx *)p)->f4),0,0,((struct GtsnegoMsgCtx *)p)->fF4);
    ((struct GtsnegoMsgCtx *)p)->f70=(void *)CLACT_RegisterCharacter(t,5,0,1,((struct GtsnegoMsgCtx *)p)->fF4);
    ((struct GtsnegoMsgCtx *)p)->f24=(void *)CLACT_RegisterPaletteEx(t,0,1,320,0,1,((struct GtsnegoMsgCtx *)p)->fF4);
    ((struct GtsnegoMsgCtx *)p)->fBC=(void *)CLACT_RegisterCellAnim(t,10,22,((struct GtsnegoMsgCtx *)p)->fF4);
    *(void * *)&((struct GtsnegoMsgCtx *)p)->f28=(void *)CLACT_RegisterCharacter(t,7,0,1,((struct GtsnegoMsgCtx *)p)->fF4);
    ((struct GtsnegoMsgCtx *)p)->f18=(void *)CLACT_RegisterPaletteEx(t,2,1,256,0,8,((struct GtsnegoMsgCtx *)p)->fF4);
    *(void * *)&((struct GtsnegoMsgCtx *)p)->f74=(void *)CLACT_RegisterCellAnim(t,11,23,((struct GtsnegoMsgCtx *)p)->fF4);
    ((struct GtsnegoMsgCtx *)p)->f2C=(void *)CLACT_RegisterCharacter(t,7,0,0,((struct GtsnegoMsgCtx *)p)->fF4);
    ((struct GtsnegoMsgCtx *)p)->f1C=(void *)CLACT_RegisterPaletteEx(t,2,0,0,0,8,((struct GtsnegoMsgCtx *)p)->fF4);
    ((struct GtsnegoMsgCtx *)p)->f78=(void *)CLACT_RegisterCellAnim(t,11,23,((struct GtsnegoMsgCtx *)p)->fF4);
    ((struct GtsnegoMsgCtx *)p)->fF8=BLINK_PALANM_Create(0,16,0,((struct GtsnegoMsgCtx *)p)->fF4);
    BLINK_PALANM_LoadPalettes(((struct GtsnegoMsgCtx *)p)->fF8,t,1,0,16);
    ((struct GtsnegoMsgCtx *)p)->fFC=BLINK_PALANM_Create(0,16,7,((struct GtsnegoMsgCtx *)p)->fF4);
    BLINK_PALANM_LoadPalettes(((struct GtsnegoMsgCtx *)p)->fFC,t,1,0,16);
    ARC_TOOL_DeleteHandle(t);
    t=func_020490F4((u32)((void *)32),((struct GtsnegoMsgCtx *)p)->fF4);
    for(i=0;i<16;i++) {
        *(void **)(p+i*4+0x30)=(void *)CLACT_RegisterCharacter(t,i+1,0,1,((struct GtsnegoMsgCtx *)p)->fF4);
        *(void **)(p+i*4+0x7c)=(void *)CLACT_RegisterCellAnim(t,i*2+17,i*2+18,((struct GtsnegoMsgCtx *)p)->fF4);
    }
    ((struct GtsnegoMsgCtx *)p)->f20=(void *)CLACT_RegisterPaletteEx(t,0,1,0,0,8,((struct GtsnegoMsgCtx *)p)->fF4);
    ARC_TOOL_DeleteHandle(t);
    func_0207D63C((void *)0x04001050,5,24,15,9);
}









void GTSNEGO_DISP_Noop(u8 *a0, int a1){}








void GTSNEGO_DISP_RedrawActors(u8 *p)
{
    void *t;
    GTSNEGO_DISP_Noop(p, 0);
    t = func_020490F4(144, ((struct GtsnegoMsgCtx *)p)->fF4);
    func_02049990(t, 19, 4, 0, (u16)(((struct GtsnegoMsgCtx *)p)->f0), 0, 0, ((struct GtsnegoMsgCtx *)p)->fF4);
    func_02049990(t, 20, 4, 0, (u16)(((struct GtsnegoMsgCtx *)p)->f0), 192, 0, ((struct GtsnegoMsgCtx *)p)->fF4);
    ARC_TOOL_DeleteHandle(t);
    GTSNEGO_MSG_CreateActorAt(p, 96, 56, 0);
    GTSNEGO_MSG_CreateActorAt(p, 240, 56, 1);
    GTSNEGO_MSG_CreateActorAt(p, 120, 96, 0);
    GTSNEGO_MSG_CreateActorAt(p, 240, 96, 1);
    GTSNEGO_MSG_CreateActorAt(p, 120, 136, 0);
    GTSNEGO_MSG_CreateActorAt(p, 240, 136, 1);
}








/*
 * trailing: 2-byte zero alignment padding at 0x021D692A.
 */
void GTSNEGO_DISP_ResetActors(u8 *p)
{
    void *t = func_020490F4(144, ((struct GtsnegoMsgCtx *)p)->fF4);
    GTSNEGO_MSG_DeleteActors(p);
    BG_SYS_SetTileEntry(6, 0, 0, 0, 32, 32, 17);
    func_02041B6C(6);
    func_02049990(t, 18, 4, 0, (u16)(((struct GtsnegoMsgCtx *)p)->f0), 0, 0, ((struct GtsnegoMsgCtx *)p)->fF4);
    func_02041B6C(4);
    ARC_TOOL_DeleteHandle(t);
}








void GTSNEGO_DISP_CreateTouchbar(u8 *p, int n)
{
    Data data = d_021D8990;
    Config c;
    MI_CpuFill8(&c, 0, 32);
    c.f0 = &data;
    c.f4 = 1;
    c.f8 = *(u32 *)&((struct GtsnegoMsgCtx *)p)->f10;
    c.fC = 7;
    c.f10 = 15;
    c.f18 = 2;
    c.f1c = 0;
    c.f14 = n;
    ((struct GtsnegoMsgCtx *)p)->fC = TOUCHBAR_Create(&c, ((struct GtsnegoMsgCtx *)p)->fF4);
}









u32 GTSNEGO_DISP_GetTouchbar(u8 *p){return *(unsigned int *)&((struct GtsnegoMsgCtx *)p)->fC;}









void GTSNEGO_DISP_DeleteTouchbar(u8 *p)
{
    if (((struct GtsnegoMsgCtx *)p)->fC) {
        TOUCHBAR_Delete(((struct GtsnegoMsgCtx *)p)->fC);
        *(u32 *)&((struct GtsnegoMsgCtx *)p)->fC = 0;
    }
}








void GTSNEGO_DISP_CreateCursorActor(u8 *p)
{
    PosRecord r;
    r.x = 0; r.y = 0; r.z = 0; r.a = 0; r.b = 2;
    ((struct GtsnegoMsgCtx *)p)->f134 = CLACT_CreateActor((void *)*(u32 *)&((struct GtsnegoMsgCtx *)p)->f10, ((struct GtsnegoMsgCtx *)p)->f28, *(unsigned int *)&((struct GtsnegoMsgCtx *)p)->f18, ((struct GtsnegoMsgCtx *)p)->f74, &r, 1, ((struct GtsnegoMsgCtx *)p)->fF4);
    CLACT_SetActorAutoAnim(((struct GtsnegoMsgCtx *)p)->f134, 1);
    CLACT_SetActorDrawEnable(((struct GtsnegoMsgCtx *)p)->f134, 0);
    CLACT_SetActorObjMode(((struct GtsnegoMsgCtx *)p)->f134, 1);
}








void GTSNEGO_DISP_SetCursorState(u8 *p, void *q, u32 n)
{
    Vec v;
    switch (n) {
    case 9:
        CLACT_SetActorDrawEnable(((struct GtsnegoMsgCtx *)p)->f134, 0);
        return;
    case 5:
        CLACT_SetActorDrawEnable(((struct GtsnegoMsgCtx *)p)->f134, 0);
        if (q) APP_TASKMENU_WIN_SetActive(q, 1);
        return;
    case 2: case 3: case 4: case 6: case 7: case 8:
        if (q) APP_TASKMENU_WIN_SetActive(q, 0);
        break;
    case 0: case 1: default: break;
    }
    v.x = gGtsnegoEntryTable[n].x;
    v.y = gGtsnegoEntryTable[n].y;
    CLACT_AddActorSurfacePos(((struct GtsnegoMsgCtx *)p)->f134, (const struct Vec2 *)(&v), 1);
    CLACT_SetActorAnimSeq(((struct GtsnegoMsgCtx *)p)->f134, gGtsnegoEntryTable[n].code);
    CLACT_SetActorDrawEnable(((struct GtsnegoMsgCtx *)p)->f134, 1);
}
