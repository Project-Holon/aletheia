/*
 * file:     mb_comm_sys.c
 * unit:     yes
 * function: MB_COMM_SYS_Init, MB_COMM_SYS_Exit, MB_COMM_SYS_Main, MB_COMM_SYS_VBlank, MB_COMM_SYS_VBlankRefreshBg, MB_COMM_SYS_VBlankRefreshBgStandalone, MB_COMM_SYS_InitDisplay, MB_COMM_SYS_ExitDisplay, MB_COMM_SYS_InitBgLayer, MB_COMM_SYS_LoadGraphics, MB_COMM_SYS_DrawTitle, MB_COMM_SYS_BuildGameStrings, MB_COMM_SYS_FreeGameStrings, MB_COMM_SYS_MainWireless, MB_COMM_SYS_StartParent, MB_COMM_SYS_MainRecruit, MB_COMM_SYS_WmEndCallback, MB_COMM_SYS_UpdateSaveState, MB_COMM_SYS_ResetHook, MB_COMM_SYS_FinishReceive, MB_COMM_SYS_RegisterReceivedMons, MB_COMM_SYS_NoOp, MB_COMM_SYS_MainSave, MB_COMM_SYS_MainChildFlow, MB_COMM_SYS_ShowTextPlane, MB_COMM_SYS_ProcInit, MB_COMM_SYS_ProcExit, MB_COMM_SYS_ProcMain, MB_PARENT_SYS_Init, MB_PARENT_SYS_Register, MB_PARENT_SYS_LoadFileImage, MB_PARENT_SYS_CheckRequest, MB_PARENT_SYS_RejectRequest, MB_PARENT_SYS_StartSending, MB_PARENT_SYS_AllBootable, MB_PARENT_SYS_StartBoot, MB_PARENT_SYS_Cancel, MB_PARENT_SYS_EndIfAllBootable, MB_PARENT_SYS_EventCallback, MB_PARENT_SYS_SetState, MB_PARENT_SYS_GetState, MB_PARENT_SYS_GetChildStage, MB_PARENT_SYS_FreeBuffers, MB_PARENT_SYS_IsRegistered, MB_COMM_SYS_CreateNetState, MB_COMM_SYS_DeleteNetState, MB_COMM_SYS_UpdateNetState, MB_COMM_SYS_StartNetSession, MB_COMM_SYS_StopNetSession, MB_COMM_SYS_GetNetRunState, MB_COMM_SYS_IsNetSessionNull, MB_COMM_SYS_StartNet, MB_COMM_SYS_SetSyncRange, MB_COMM_SYS_IsSyncDone, MB_COMM_SYS_IsLoginDone, MB_COMM_SYS_GetCommStage, MB_COMM_SYS_ClearRoundFlags, MB_COMM_SYS_HasKind11, MB_COMM_SYS_HasKind12, MB_COMM_SYS_HasKind12Again, MB_COMM_SYS_HasKind14, MB_COMM_SYS_HasKind1, MB_COMM_SYS_HasKind2, MB_COMM_SYS_HasKind4, MB_COMM_SYS_GetCount, MB_COMM_SYS_HasKind19, MB_COMM_SYS_GetOfferCount, MB_COMM_SYS_GetOfferExtra, MB_COMM_SYS_GetOfferFlagA, MB_COMM_SYS_GetOfferFlagB, MB_COMM_SYS_HasKind20, MB_COMM_SYS_HasKind21, MB_COMM_SYS_GetKind21Value, MB_COMM_SYS_QueuePayload, MB_COMM_SYS_ClearMonBuffer, MB_COMM_SYS_HasMonsReceived, MB_COMM_SYS_GetMonCount, MB_COMM_SYS_GetMon, MB_COMM_SYS_GetMaxSeen, MB_COMM_SYS_SendMessage, MB_COMM_SYS_OnMessage, MB_COMM_SYS_SendHeader, MB_COMM_SYS_GetHeaderBuffer
 * address:  0x021EE740
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MB_UTIL_MSG_Create 0x021F1404 thumb ov107
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   BEACON_GetBlock 0x0200C0F0 thumb
 *   BEACON_SetRank 0x0200C1B0 thumb
 *   func_020056A0 0x020056A0 thumb
 *   func_02005654 0x02005654 thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   UI_SetKeepAwakeFlagsGlobal 0x02034F84 arm
 *   gMbParentUi 0x021F6EA0 data a4
 *   UI_ClearKeepAwakeFlagsGlobal 0x02034FB8 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_0200566C 0x0200566C thumb
 *   GFL_NET_WM_ICON_EasyEnd 0x020370C8 arm
 *   GFL_USE_CancelChangeAndStopBgm 0x02005D28 thumb
 *   GAME_DATA_GetEventWork 0x0201296C thumb
 *   ZONEDATA_GetEventWorkAddress 0x020143CC thumb
 *   func_020307B0 0x020307B0 arm
 *   MB_UTIL_MSG_Delete 0x021F1520 thumb ov107
 *   MB_UTIL_MSG_SetWindowLayout 0x021F1628 thumb ov107
 *   MB_UTIL_MSG_PrintStream 0x021F1704 thumb ov107
 *   MB_UTIL_MSG_PrintStreamSystemMsg 0x021F1A58 thumb ov107
 *   MB_UTIL_MSG_SetKeyWaitFlag 0x021F1B24 thumb ov107
 *   MB_UTIL_MSG_IsStreamIdle 0x021F1B14 thumb ov107
 *   MB_UTIL_MSG_OpenYesNoMenu 0x021F19E4 thumb ov107
 *   MB_UTIL_MSG_ProcessYesNoMenu 0x021F1A2C thumb ov107
 *   MB_UTIL_MSG_ClearWindow 0x021F1898 thumb ov107
 *   MB_UTIL_MSG_ClearYesNoMenu 0x021F1A24 thumb ov107
 *   MB_UTIL_MSG_Main 0x021F15B0 thumb ov107
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   func_020461E4 0x020461E4 arm
 *   FS_InitFile 0x020788AC arm
 *   FS_OpenFile 0x02078C18 arm
 *   FS_SeekFile 0x02078B44 arm
 *   FS_GetLength 0x02078C28 arm
 *   FS_ReadFile 0x02078B70 arm
 *   FS_CloseFile 0x02078A80 arm
 *   func_02034714 0x02034714 arm
 *   func_02030734 0x02030734 arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   GAME_DATA_IsSaving 0x02012E40 thumb
 *   GAME_DATA_SaveCancel 0x02012E08 thumb
 *   WIPE_SYS_Start 0x0202208C thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   APP_ENV_InitParentalControl 0x0202EB44 thumb
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   BEACON_GetBestScore 0x0200C184 thumb
 *   func_0200575C 0x0200575C thumb
 *   GAME_DATA_GetTrainerRecord 0x02012F2C thumb
 *   func_02008DF0 0x02008DF0 thumb
 *   GAME_DATA_GetBoxManager 0x0201293C thumb
 *   func_02007774 0x02007774 thumb
 *   d_021F6E08 0x021F6E08 data a4
 *   d_021F6E0C 0x021F6E0C data a4
 *   BG_SYS_FillScrollArea 0x02040618 arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   func_02040588 0x02040588 arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   WIPE_SetBrightnessFadeOut 0x0202223C thumb
 *   WIPE_ResetWndMask 0x02022224 thumb
 *   d_021F6C10 0x021F6C10 data a4
 *   d_021F6B00 0x021F6B00 data a4
 *   d_021F6B50 0x021F6B50 data a4
 *   d_021F6B70 0x021F6B70 data a4
 *   d_021F6B90 0x021F6B90 data a4
 *   d_021F6BB0 0x021F6BB0 data a4
 *   d_021F6BD0 0x021F6BD0 data a4
 *   d_021F6BF0 0x021F6BF0 data a4
 *   d_021F6B10 0x021F6B10 data a4
 *   d_021F6B30 0x021F6B30 data a4
 *   gClActorInitParam 0x020A1448 data a4
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   ARC_UTIL_UploadPaletteFromHandle 0x02049BDC arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   APP_ICON_GetArchiveId 0x020275E4 thumb
 *   APP_ICON_GetMoveKindPaletteFileId 0x02027614 thumb
 *   APP_ICON_GetMoveKindAnimFileId 0x02027618 thumb
 *   APP_ICON_GetStatusCellFileId 0x0202761C thumb
 *   APP_ICON_GetStatusPaletteFileId 0x02027620 thumb
 *   APP_ICON_GetStatusAnimFileId 0x02027624 thumb
 *   APP_ICON_GetStatusFrameFileId 0x02027628 thumb
 *   APP_ICON_GetStatusDataFileId 0x0202762C thumb
 *   BMP_WIN_Create 0x020450F0 arm
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   MB_UTIL_MSG_GetFont 0x021F1B04 thumb ov107
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   MB_UTIL_MSG_CreateWordSet 0x021F18D8 thumb ov107
 *   func_02008534 0x02008534 thumb
 *   MB_UTIL_MSG_SetNumberZeroPad 0x021F1918 thumb ov107
 *   MB_UTIL_MSG_GetMsgData 0x021F1AFC thumb ov107
 *   MB_UTIL_MSG_GetWordSet 0x021F1B00 thumb ov107
 *   STRBUF_Create 0x020457B0 arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   STRBUF_GetLength 0x020458F8 arm
 *   STRBUF_GetChars 0x02045A90 arm
 *   MIi_CpuCopy16 0x02082A60 arm
 *   func_02034AC4 0x02034AC4 arm
 *   CARD_SetPulledOutCallback 0x020774A0 arm
 *   ov014_id 0x0000000E data
 *   func_02034A5C 0x02034A5C arm
 *   WIH_GetSysState 0x02178E4C thumb ov014
 *   WIH_StartMeasureChannel 0x02178E84 thumb ov014
 *   WIH_Finalize 0x02179498 thumb ov014
 *   WIH_FreeWork 0x02179158 thumb ov014
 *   WIH_Initialize 0x021790E4 thumb ov014
 *   GFL_NET_WM_ICON_EasyStart 0x02037010 arm
 *   GFL_NET_WM_ICON_EasySetScreen 0x02037118 arm
 *   func_020351F8 0x020351F8 arm
 *   MB_UTIL_MSG_DeleteWordSet 0x021F18EC thumb ov107
 *   MB_UTIL_MSG_PrintQueued 0x021F17E0 thumb ov107
 *   MB_UTIL_MSG_SetTimeIconPending 0x021F1B38 thumb ov107
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   WIH_End 0x02179570 thumb ov014
 *   WM_GetLinkLevel 0x0208EE9C arm
 *   GFL_NET_WM_ICON_EasySetLevel 0x020370F4 arm
 *   GFL_NET_WM_ICON_EasyMain 0x02037154 arm
 *   d_021F6D68 0x021F6D68 data ov107 a4
 *   d_021F6D70 0x021F6D70 data ov107 a4
 *   d_021F6D60 0x021F6D60 data ov107 a4
 *   d_021F6C40 0x021F6C40 data ov107 a4
 *   WIH_GetMeasureChannel 0x02179024 thumb ov014
 *   MI_CpuCopy8 0x02082D44 arm
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   KEY_GetTrg 0x020362DC arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   MB_UTIL_MSG_OpenYesNoTaskMenu 0x021F1930 thumb ov107
 *   MB_UTIL_MSG_GetTaskMenuResult 0x021F19C8 thumb ov107
 *   MB_UTIL_MSG_CloseTaskMenu 0x021F19B8 thumb ov107
 *   d_021F6AF8 0x021F6AF8 data a4
 *   BEACON_GetRank 0x0200C1A4 thumb
 *   OS_WaitIrq 0x0208459C arm
 *   BEACON_SetBestScore 0x0200C18C thumb
 *   ZUKAN_SAVE_GetFromGameData  0x0200CA1C  thumb
 *   func_02008DAC  0x02008DAC  thumb
 *   SAVE_EVENT_StoreTodayDate  0x0202F27C  thumb
 *   func_020074D8  0x020074D8  thumb
 *   POKE_TOOL_CreateFromBoxParam  0x0201747C  thumb
 *   ZUKAN_SAVE_RegisterCaught  0x0200CDE0  thumb
 *   MB_UTIL_MSG_IsPrintQueFinished 0x021F1B08 thumb ov107
 *   func_020056EC 0x020056EC thumb
 *   GAME_DATA_SaveStart 0x02012DAC thumb
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 *   MB_UTIL_MSG_SetNumberLeft  0x021F1900  thumb  ov107
 *   GAME_DATA_GetMyItem  0x0201292C  thumb
 *   GAME_DATA_GetMiscSave  0x02012F08  thumb
 *   FIELD_G3D_MAP_CheckBeaconTrainerKey  0x0216BF9C  thumb  ov010
 *   FIELD_G3D_MAP_StoreBeaconTrainerKey  0x0216BF74  thumb  ov010
 *   func_02007E50  0x02007E50  thumb
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   GFL_NET_IsSessionNull 0x0203CDBC arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   KEY_GetCont 0x0203630C arm
 *   GAME_DATA_Create 0x020124F4 thumb
 *   GAME_DATA_Delete 0x02012704 thumb
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0200FBB0 0x0200FBB0 thumb
 *   GFL_NET_ERR_ShowScreen 0x0200F7B8 thumb
 *   GFL_NET_ERR_ShowSimpleScreen 0x0200F83C thumb
 *   UI_SoftReset 0x02035544 arm
 *   GFL_NET_ERR_RequestScreen 0x0200FB38 thumb
 *   OS_GetOwnerInfoEx 0x02087D28 arm
 *   GFL_NET_AllocAligned 0x0203D7C8 arm
 *   func_021F5904 0x021F5904 arm ov107
 *   MB_SetParentCommParam 0x021F5B4C arm ov107
 *   func_021F1B3C 0x021F1B3C arm ov107
 *   gMbChildStageMasks 0x021F6EB4 data a4
 *   d_021F6E1C 0x021F6E1C data a4
 *   gMbParentSys 0x021F6EAC data a4
 *   d_021F6E24 0x021F6E24 data a4
 *   func_021F5E7C 0x021F5E7C arm ov107
 *   MB_GetSegmentLength 0x021F2F1C arm ov107
 *   func_021F2FA0 0x021F2FA0 arm ov107
 *   func_021F3544 0x021F3544 arm ov107
 *   MB_CommResponseRequest 0x021F1C30 arm ov107
 *   MB_DisconnectChild 0x021F5FB0 arm ov107
 *   OS_DisableInterrupts 0x02087988 arm
 *   OS_RestoreInterrupts 0x0208799C arm
 *   MB_CommIsBootable 0x021F1BE0 arm ov107
 *   func_021F5F74 0x021F5F74 arm ov107
 *   MB_CommGetChildUser 0x021F1B64 arm ov107
 *   GFL_NET_FreeAligned 0x0203D7FC arm
 *   gMbChildEntries 0x021F6EC8 data a4
 *   d_021F6EDE 0x021F6EDE data a2
 *   d_021F6EDF 0x021F6EDF data a1
 *   d_021F6EE0 0x021F6EE0 data a1
 *   d_021F6EE1 0x021F6EE1 data a1
 *   d_021F6EE2 0x021F6EE2 data a1
 *   d_021F6EE3 0x021F6EE3 data a1
 *   d_021F6EE4 0x021F6EE4 data a2
 *   POKE_TOOL_GetBoxParamSize 0x020173E8 thumb
 *   d_021F6E28 0x021F6E28 data a4
 *   GFL_NET_LOWER_DATA_Exit 0x0203E6C0 arm
 *   GFL_NET_HANDLE_CheckNegotiation 0x02039ACC arm
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_IsNegotiationDone 0x020399B8 arm
 *   GFL_NET_IsHandleReady 0x0203D394 arm
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   GFL_NET_SetLoginOption 0x0203D7BC arm
 *   sMbCommSessionRequest 0x021F6C94 data a4
 *   GFL_NET_StartSession 0x0203CBAC arm
 *   GFL_NET_LOWER_DATA_Init 0x0203E5F8 arm
 *   GFL_NET_Exit 0x0203CEAC arm
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   GFL_NET_StartByNetType 0x0203D01C arm
 *   GFL_NET_LOWER_DATA_SetSendData 0x0203E758 arm
 *   POKE_TOOL_ClearBoxParam  0x02017550  thumb
 *   GFL_NET_IsParentAid  0x0203D378  arm
 *   GFL_NET_HANDLE_GetNetHandle  0x0203996C  arm
 *   GFL_NET_SendData  0x0203D3F8  arm
 *   GFL_NET_GetNegotiationNum 0x0203D1B4 arm
 *   d_021F6EE8 0x021F6EE8 data a4
 *   GFL_NET_HANDLE_SetTimingSyncRange  0x02039C68  arm  arm9
 */

#include "mb_comm_sys.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef short s16;
typedef signed char s8;

struct FSFile;
struct DispVram;
struct DispConfig;
struct BgTemplate;
struct ClActInitParam {
    u32 header[4];
    u16 dimensions[6];
};

typedef enum { FS_OK = 0, FS_ERROR = 1 } FSResult;
typedef struct File {
    struct File *next;
    void *userdata;
    void *arc;
    u32 stat;
    void *argument;
    FSResult error;
    void *queue[2];
    u8 reserved1[16];
    u8 arg[24];
} File;
typedef enum { SEEK_SET = 0, SEEK_CUR = 1, SEEK_END = 2 } SeekOrigin;

/* Actor placement passed to CLACT_CreateActor. */
struct Placement {
    u16 x, y, z;
    u8 animSeq;
    u8 bgPriority;
};

/* Display registers and palette RAM touched directly by this screen. */
#define REG_DISPCNT_MAIN (*(volatile u32 *)0x04000000)
#define REG_DISPCNT_SUB (*(volatile u32 *)0x04001000)
#define REG_BLDCNT_MAIN (*(volatile u16 *)0x04000050)
#define REG_BLDCNT_SUB (*(volatile u16 *)0x04001050)
#define REG_POWCNT1 (*(volatile u16 *)0x04000304)
#define PLTT_BG_MAIN ((volatile u16 *)0x05000000)
#define PLTT_BG_SUB ((volatile u16 *)0x05000400)

typedef struct MbPathPair {
    const char *inGame;
    const char *standalone;
} MbPathPair;

/* OS owner info as returned by the OS (nickname at 0x04, its length at 0x1A). */
typedef struct OwnerInfo {
    u8 language;
    u8 favoriteColor;
    u8 birthMonth;
    u8 birthDay;
    u16 nickname[10];
    u16 word18;
    u16 nicknameLength;
    u16 comment[26];
    u16 word50;
    u16 word52;
    u8 tail;
} OwnerInfo;

typedef struct MBUser {
    u8 favoriteColour : 4;
    u8 playerNo : 4;
    u8 nameLength;
    u16 name[10];
} MBUser;

/* Net session request copied from ROM data and patched with the heap id (112 bytes). */
typedef struct Request {
    u32 settings[21];
    u16 heapId;
    u8 moreSettings[26];
} Request;

/* Message sent on channel 0x400. */
typedef struct MbCommMsg {
    u32 value;
    u8 kind;
} MbCommMsg;

/* Start of the mon receive buffer. */
typedef struct MbMonList {
    u8 count;
    u8 pad01;
    u16 maxSeen;
} MbMonList;

/* Record passed to the MB parent callback. */
typedef struct MbChildEvent {
    u16 errorCode;
    u8 unused02[8];
    u8 mac[6];
} MbChildEvent;

extern void *MB_UTIL_MSG_Create(u16 heap, u32 a, u32 b, u32 c, u32 d, u32 e);
extern void *GAME_DATA_GetSaveControl(void *);
extern void *BEACON_GetBlock(void *);
extern void BEACON_SetRank(void *,u32);
extern void *func_020056A0(u32,u32,u32);
extern int func_02005654(int,int);
extern void GFL_USE_CancelChangeAndPlayBgm(u32,u16);
extern void UI_SetKeepAwakeFlagsGlobal(u32);
extern void UI_ClearKeepAwakeFlagsGlobal(u32 v);
extern void func_02030EAC(void *n);
extern void func_0200566C(void);
extern void GFL_NET_WM_ICON_EasyEnd(void);
extern void GFL_USE_CancelChangeAndStopBgm(void);
extern u32 GAME_DATA_GetEventWork(const void *p);
extern u32 ZONEDATA_GetEventWorkAddress(u32 a, u32 b);
extern u32 func_020307B0(void *p);
extern void MB_UTIL_MSG_Delete(struct MbMsgWork *p);
extern u8 GAME_DATA_IsSaving(const u8 *);
extern void GAME_DATA_SaveCancel(char *p);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern u32 WIPE_SYS_EndCheck(void);
extern int APP_ENV_InitParentalControl(void);
extern signed char MSG_SPEED_GetWait(void);
extern void GFL_USE_FadeOutBgm(u32);
extern void GFL_NET_RestartWithDefaultTimeout(u32,u32);
extern void MB_UTIL_MSG_SetWindowLayout(void *,int);
extern void MB_UTIL_MSG_PrintStream(void *,int,int);
extern void MB_UTIL_MSG_PrintStreamSystemMsg(struct MbMsgWork *p, int a);
extern void MB_UTIL_MSG_SetKeyWaitFlag(void *,int);
extern int MB_UTIL_MSG_IsStreamIdle(void *);
extern int MB_UTIL_MSG_ProcessYesNoMenu(void *);
extern void MB_UTIL_MSG_OpenYesNoMenu(void *,int);
extern void MB_UTIL_MSG_ClearWindow(void *);
extern void MB_UTIL_MSG_ClearYesNoMenu(struct MbMsgWork *p);
extern u32 func_020461E4(int);
extern u32 BEACON_GetBestScore(void *p);
extern void *func_0200575C(u32);
extern void FS_InitFile(File *);
extern int FS_OpenFile(File *,const char *);
extern int FS_CloseFile(File *);
extern int FS_SeekFile(void *file, long offset, int origin);
extern s32 FS_ReadFile(void *file, void *buffer, s32 length);
extern u32 FS_GetLength(void *a0);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *GAME_DATA_GetTrainerRecord(int *p);
extern u32 GAME_DATA_GetBoxManager(const void *p);
extern u32 func_02008DF0(void *obj, int i);
extern int func_02007774(void *);
extern void *MB_UTIL_MSG_Main(void *);
extern void CLACT_DrawSystem(void *);
extern void CLACT_VBlankSystem(void);
extern void BG_SYS_FillScrollArea(unsigned,unsigned,unsigned);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void WIPE_SetBrightnessFadeOut(u32,u32);
extern u32 WIPE_ResetWndMask(void *);
extern void BG_SYS_SetVramBanks(const struct DispVram *);
extern void BG_SYS_Create(u16);
extern void BMP_WIN_Init(u16);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *);
extern void func_02040588(u32 which, unsigned char enable);
extern void CLACT_InitSystem(const void *,u32,u32);
extern void *CLACT_CreateUnit(int,u8,u32);
extern void CLACT_SetUnitDefaultRenderer(void *);
extern void BG_SYS_SetMainPlaneVisible(u32,u32);
extern void BG_SYS_SetSubPlaneVisible(u32,u32);
extern void CLACT_DeleteActor(void *p);
extern u32 CLACT_DeleteUnit(void *bank);
extern void CLACT_ExitSystem(void);
extern void BG_SYS_FreeLayerBuf(unsigned);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_FreeSlot(u32);
extern void BG_SYS_PushTile(u32);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void ARC_UTIL_UploadPaletteFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern void ARC_TOOL_DeleteHandle(void *);
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void *CLACT_CreateActor(void *owner,unsigned int i,unsigned int j,unsigned int k,const void *position,unsigned short space,unsigned short heap);
extern void CLACT_SetActorDrawEnable(void *,u32);
extern u32 APP_ICON_GetArchiveId(void);
extern u32 APP_ICON_GetMoveKindPaletteFileId(void);
extern u32 APP_ICON_GetMoveKindAnimFileId(void);
extern u32 APP_ICON_GetStatusAnimFileId(void);
extern u32 APP_ICON_GetStatusFrameFileId(void);
extern u32 APP_ICON_GetStatusDataFileId(void);
extern u32 APP_ICON_GetStatusCellFileId(u32);
extern u32 APP_ICON_GetStatusPaletteFileId(u32);
extern void *BMP_WIN_Create(u32,u32,u32,u32,u8,u8,u8);
extern void *func_02045B38(u32,u32,u32,u32);
extern void *func_02045EC0(void *,u32);
extern void *BMP_WIN_GetBmp(void *);
extern void BMP_Clear(void *,u8);
extern void *MB_UTIL_MSG_GetFont(void *p);
extern void PRINTSYS_PrintColor(void *,s16,s16,void *,void *,u16);
extern void BMP_WIN_TransferChars(void *);
extern void BMP_WIN_MakeScreen(void *);
extern u8 BMP_WIN_GetBgLayer(void *);
extern void STRBUF_Delete(void *);
extern u32 MSGDATA_Delete(void *rec);
extern u32 BMP_WIN_Delete(void *d);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void MB_UTIL_MSG_CreateWordSet(void *);
extern u16 func_02008534(const void *obj);
extern void MB_UTIL_MSG_SetNumberZeroPad(struct MbMsgWork *a, int b, int c, int d);
extern void *MB_UTIL_MSG_GetMsgData(void *p);
extern void *MB_UTIL_MSG_GetWordSet(void *p);
extern void *STRBUF_Create(u32 capacity, u32 heapId);
extern void WORDSET_CopyTaggedText(void *ws, void *dst, void *src);
extern u16 STRBUF_GetLength(void *vec);
extern u16 *STRBUF_GetChars(void *vec);
extern void MIi_CpuCopy16(const void *, void *, int);
extern int func_02034AC4(s32 handle);
extern void CARD_SetPulledOutCallback(int (*callback)(void));
extern void func_02034A5C(int);
extern int WIH_GetSysState(void);
extern int WIH_StartMeasureChannel(void);
extern int WIH_Finalize(void);
extern void WIH_FreeWork(void);
extern int WIH_Initialize(u32,int,int);
extern void GFL_NET_WM_ICON_EasyStart(u32,u32,u32,u32);
extern void GFL_NET_WM_ICON_EasySetScreen(u32,u32);
extern void func_020351F8(u32 a, u32 b);
extern void MB_UTIL_MSG_DeleteWordSet(void *);
extern void MB_UTIL_MSG_PrintQueued(void *,int);
extern void MB_UTIL_MSG_SetTimeIconPending(struct MbMsgWork *p, u32 v);
extern void CLACT_SetActorAnimSeq(void *p, u16 value);
extern int WIH_End(void (*cb)(int));
extern int WM_GetLinkLevel(void);
extern u32 GFL_NET_WM_ICON_EasySetLevel(u32);
extern void GFL_NET_WM_ICON_EasyMain(void);
extern u16 WIH_GetMeasureChannel(void);
extern void MI_CpuCopy8(const void *,void *,unsigned);
extern int TOUCHPANEL_HitTrg(const void *);
extern int MB_UTIL_MSG_GetTaskMenuResult(struct MbMsgWork *a);
extern u32 KEY_GetTrg(void);
extern void CLACT_SetActorAutoAnim(void *,u32);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void MB_UTIL_MSG_OpenYesNoTaskMenu(struct MbMsgWork *p, int kind);
extern void MB_UTIL_MSG_CloseTaskMenu(struct MbMsgWork *a);
extern u8 BEACON_GetRank(void *p);
extern void OS_WaitIrq(int clear, u32 irqFlags);
extern void BEACON_SetBestScore(void *p, u32 v);
void *ZUKAN_SAVE_GetFromGameData(void *);
u32 func_02008DAC(void *obj, int i, u32 delta);
void SAVE_EVENT_StoreTodayDate(void *);
int func_020074D8(void **save, const void *src);
void *POKE_TOOL_CreateFromBoxParam(void *p, u32 heap);
void ZUKAN_SAVE_RegisterCaught(void *p, void *m);
extern int MB_UTIL_MSG_IsPrintQueFinished(void *);
extern u32 func_020056EC(u32);
extern int GAME_DATA_SaveStart(int);
extern int GAME_DATA_SaveMain(u8 *);
void MB_UTIL_MSG_SetNumberLeft(void *, int, int, int);
void *GAME_DATA_GetMyItem(const void *p);
void *GAME_DATA_GetMiscSave(int *p);
int FIELD_G3D_MAP_CheckBeaconTrainerKey(void *, int, void *);
void FIELD_G3D_MAP_StoreBeaconTrainerKey(void *, int, void *);
u32 func_02007E50(u8 *base, u16 id, u16 qty, u16 d);
extern void BG_SYS_SetMainVisiblePlanes(int);
extern void BG_SYS_SetSubVisiblePlanes(int);
extern int GFL_NET_IsSessionNull(void);
extern void GFL_HEAP_CreateChildHeap(u32,u32,u32);
extern void *PROCSYS_AllocProcWork(void *obj, u32 size, u32 heap);
extern unsigned int KEY_GetCont(void);
extern void *GAME_DATA_Create(u16);
extern void GAME_DATA_Delete(unsigned char *);
extern void func_020315D4(void *);
extern void GFL_HEAP_DeleteChecked(u32);
extern u32 func_0200FB24(void);
extern int func_0200FBB0(void);
extern void GFL_NET_ERR_ShowScreen(int);
extern void GFL_NET_ERR_ShowSimpleScreen(void);
extern void UI_SoftReset(int);
extern void GFL_NET_ERR_RequestScreen(void);
extern void OS_GetOwnerInfoEx(void *info);
extern void *GFL_NET_AllocAligned(u32,u32,const char *,u16);
extern int func_021F5904(void *,MBUser *,int,int,u16);
extern int MB_SetParentCommParam(u16,u16);
extern void func_021F1B3C(void (*)(u16,u32,MbChildEvent *));
extern int func_021F5E7C(int);
extern u32 MB_GetSegmentLength(void *);
extern int func_021F2FA0(void *,void *,u32);
extern int func_021F3544(void *,void *);
extern int MB_CommResponseRequest(u16,int);
extern void MB_DisconnectChild(u16);
extern u32 OS_DisableInterrupts(void);
extern u32 OS_RestoreInterrupts(u32);
extern int MB_CommIsBootable(u16);
extern void func_021F5F74(void);
extern void *MB_CommGetChildUser(u16);
extern void GFL_NET_FreeAligned(void *);
extern u32 POKE_TOOL_GetBoxParamSize(void);
extern void GFL_NET_LOWER_DATA_Exit(void);
extern int GFL_NET_HANDLE_CheckNegotiation(void);
extern void *GFL_NET_HANDLE_GetCurrentHandle(void);
extern int GFL_NET_HANDLE_IsNegotiationDone(void *);
extern int GFL_NET_IsHandleReady(void *);
extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(void *,unsigned int,unsigned int);
extern void GFL_NET_SetLoginOption(int);
extern void GFL_NET_StartSession(void *req, u32 a2, u32 a3);
extern void GFL_NET_LOWER_DATA_Init(int,int);
extern int GFL_NET_Exit(int);
extern int GFL_NET_GetRunState(void);
extern void GFL_NET_StartByNetType(void);
extern void GFL_NET_HANDLE_SetTimingSyncRange(void *, unsigned int, unsigned int);
extern void GFL_NET_LOWER_DATA_SetSendData(int,int,int,int);
void POKE_TOOL_ClearBoxParam(void *);
u32 GFL_NET_IsParentAid(void);
void *GFL_NET_HANDLE_GetNetHandle(s32 idx);
u32 GFL_NET_SendData(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern int GFL_NET_GetNegotiationNum(void);

extern MbParentUi gMbParentUi;
extern const char d_021F6E08[], d_021F6E0C[];
extern const struct ClActInitParam gClActorInitParam;
extern const struct DispVram d_021F6C10;
extern struct DispConfig d_021F6B00;
extern const struct BgTemplate d_021F6B50, d_021F6B70, d_021F6B90, d_021F6BB0, d_021F6BD0, d_021F6BF0, d_021F6B10, d_021F6B30;
extern u8 ov014_id[];
extern const MbPathPair d_021F6D68, d_021F6D70, d_021F6D60;
extern const MbRegistryBlock d_021F6C40;
extern u8 d_021F6AF8[];
extern MbChildStageMasks gMbChildStageMasks;
extern MbParentSys gMbParentSys;
extern const char d_021F6E1C[], d_021F6E24[];
extern u8 gMbChildEntries[], d_021F6EDE[], d_021F6EDF[], d_021F6EE0[], d_021F6EE1[], d_021F6EE2[], d_021F6EE3[], d_021F6EE4[];
extern const char d_021F6E28[];
extern const Request sMbCommSessionRequest;
extern int d_021F6EE8[];

void MB_COMM_SYS_Init(MbCommSysWork *p);
void MB_COMM_SYS_Exit(MbCommSysWork *p);
int MB_COMM_SYS_Main(MbCommSysWork *p);
void MB_COMM_SYS_VBlank(void);
void MB_COMM_SYS_VBlankRefreshBg(void);
void MB_COMM_SYS_VBlankRefreshBgStandalone(void);
void MB_COMM_SYS_InitDisplay(MbCommSysWork *p);
void MB_COMM_SYS_ExitDisplay(MbCommSysWork *p);
void MB_COMM_SYS_InitBgLayer(const void *bgTemplate, u32 layer, u32 mode);
void MB_COMM_SYS_LoadGraphics(MbCommSysWork *p);
void MB_COMM_SYS_DrawTitle(MbCommSysWork *p);
void MB_COMM_SYS_BuildGameStrings(MbCommSysWork *p);
void MB_COMM_SYS_FreeGameStrings(MbCommSysWork *p);
int MB_COMM_SYS_MainWireless(MbCommSysWork *p);
void MB_COMM_SYS_StartParent(MbCommSysWork *p);
void MB_COMM_SYS_MainRecruit(MbCommSysWork *p);
int MB_COMM_SYS_WmEndCallback(void);
void MB_COMM_SYS_UpdateSaveState(MbCommSysWork *p, int mode);
void MB_COMM_SYS_ResetHook(MbCommSysWork *p);
void MB_COMM_SYS_FinishReceive(MbCommSysWork *p);
void MB_COMM_SYS_RegisterReceivedMons(MbCommSysWork *p);
void MB_COMM_SYS_NoOp(MbCommSysWork *p);
void MB_COMM_SYS_MainSave(MbCommSysWork *p);
void MB_COMM_SYS_MainChildFlow(MbCommSysWork *p);
int MB_COMM_SYS_ShowTextPlane(void);
int MB_COMM_SYS_ProcInit(void *task, void *arg, MbParentArg *argument);
int MB_COMM_SYS_ProcExit(void *task, int unused, int keep, MbCommSysWork *p);
int MB_COMM_SYS_ProcMain(int a, int b, int c, MbCommSysWork *p);
void MB_PARENT_SYS_Init(int a, int b);
void MB_PARENT_SYS_Register(MbRegistryBlock *registry, int channel);
int MB_PARENT_SYS_LoadFileImage(MbRegistryBlock *registry);
void MB_PARENT_SYS_CheckRequest(u16 aid);
void MB_PARENT_SYS_RejectRequest(u16 aid);
void MB_PARENT_SYS_StartSending(u16 aid);
int MB_PARENT_SYS_AllBootable(void);
void MB_PARENT_SYS_StartBoot(void);
void MB_PARENT_SYS_Cancel(void);
void MB_PARENT_SYS_EndIfAllBootable(void);
void MB_PARENT_SYS_EventCallback(u16 aid, u32 event, MbChildEvent *info);
void MB_PARENT_SYS_SetState(u16 state);
u16 MB_PARENT_SYS_GetState(void);
int MB_PARENT_SYS_GetChildStage(u16 aid);
void MB_PARENT_SYS_FreeBuffers(void);
u32 MB_PARENT_SYS_IsRegistered(void);
MbNetState *MB_COMM_SYS_CreateNetState(u16 heapId);
void MB_COMM_SYS_DeleteNetState(MbNetState *net);
void MB_COMM_SYS_UpdateNetState(MbNetState *net);
void MB_COMM_SYS_StartNetSession(MbNetState *net);
void MB_COMM_SYS_StopNetSession(MbNetState *net);
int MB_COMM_SYS_GetNetRunState(MbNetState *net);
int MB_COMM_SYS_IsNetSessionNull(MbNetState *net);
void MB_COMM_SYS_StartNet(MbNetState *net);
void MB_COMM_SYS_SetSyncRange(MbNetState *net);
int MB_COMM_SYS_IsSyncDone(MbNetState *net);
int MB_COMM_SYS_IsLoginDone(MbNetState *net);
int MB_COMM_SYS_GetCommStage(MbNetState *net);
void MB_COMM_SYS_ClearRoundFlags(MbNetState *net);
int MB_COMM_SYS_HasKind11(MbNetState *net);
int MB_COMM_SYS_HasKind12(MbNetState *net);
int MB_COMM_SYS_HasKind12Again(MbNetState *net);
int MB_COMM_SYS_HasKind14(MbNetState *net);
int MB_COMM_SYS_HasKind1(MbNetState *net);
int MB_COMM_SYS_HasKind2(MbNetState *net);
int MB_COMM_SYS_HasKind4(MbNetState *net);
int MB_COMM_SYS_GetCount(MbNetState *net);
int MB_COMM_SYS_HasKind19(MbNetState *net);
unsigned short MB_COMM_SYS_GetOfferCount(MbNetState *net);
unsigned short MB_COMM_SYS_GetOfferExtra(MbNetState *net);
int MB_COMM_SYS_GetOfferFlagA(MbNetState *net);
int MB_COMM_SYS_GetOfferFlagB(MbNetState *net);
int MB_COMM_SYS_HasKind20(MbNetState *net);
int MB_COMM_SYS_HasKind21(MbNetState *net);
int MB_COMM_SYS_GetKind21Value(MbNetState *net);
void MB_COMM_SYS_QueuePayload(int a, int payload, int payloadSize);
void MB_COMM_SYS_ClearMonBuffer(MbNetState *net);
int MB_COMM_SYS_HasMonsReceived(MbNetState *net);
u8 MB_COMM_SYS_GetMonCount(MbNetState *net);
void *MB_COMM_SYS_GetMon(MbNetState *net, int i);
int MB_COMM_SYS_GetMaxSeen(MbNetState *net);
int MB_COMM_SYS_HasKind0(MbNetState *net);
int MB_COMM_SYS_SendMessage(void *net, unsigned char kind, unsigned int value);
void MB_COMM_SYS_OnMessage(int a, int b, MbCommMsg *msg, MbNetState *net);
int MB_COMM_SYS_SendHeader(void *net, MbPayloadHeader *header);
void MB_COMM_SYS_OnHeaderReceived(int a, int b, int c, MbNetState *net);
void *MB_COMM_SYS_GetHeaderBuffer(void *a, MbNetState *net);
void MB_COMM_SYS_OnMonsReceived(int a, int b, int c, MbNetState *net);
void *MB_COMM_SYS_GetMonBuffer(int a, MbNetState *net);
int *MB_COMM_SYS_GetChildDataPtr(void);
int MB_COMM_SYS_GetMemberCount(void);

/* Proc init: reads the argument, builds the display, message window and link state. */
void MB_COMM_SYS_Init(MbCommSysWork *p)
{
    p->childPhase = 0;
    p->phase = 0;
    p->standalone = p->arg->standalone;
    MB_COMM_SYS_InitDisplay(p);
    MB_COMM_SYS_LoadGraphics(p);
    if (!p->standalone)
        p->msg = MB_UTIL_MSG_Create(p->heapId, 5, 5, 72, 0, 0);
    else
        p->msg = MB_UTIL_MSG_Create(p->heapId, 1, 1, 72, 0, 1);
    p->net = MB_COMM_SYS_CreateNetState(p->heapId);
    p->payloadQueued = 0;
    p->payload = 0;
    MB_COMM_SYS_DrawTitle(p);
    if (!p->standalone) {
        p->saveState = BEACON_GetBlock(GAME_DATA_GetSaveControl(p->arg->gameData));
        BEACON_SetRank(p->saveState, 4);
    } else {
        p->saveState = 0;
        gMbParentUi.vblankCounter = 0;
    }
    p->vblankTask = func_020056A0((u32)MB_COMM_SYS_VBlank, (u32)p, 8);
    if (!p->standalone) {
        func_02005654((int)MB_COMM_SYS_VBlankRefreshBg, 0);
    } else {
        func_02005654((int)MB_COMM_SYS_VBlankRefreshBgStandalone, 0);
        GFL_USE_CancelChangeAndPlayBgm(1154, 0xffff);
    }
    p->wmActive = 0;
    p->receivedBonus = 0;
    p->gotTrainerKey = 0;
    p->bestChildCount = 0;
    p->transferCount = 0;
    p->receivedTotal = 0;
    UI_SetKeepAwakeFlagsGlobal(16);
}

/* Proc exit: releases the VBlank task, writes the event work flags, frees the screen. */
void MB_COMM_SYS_Exit(MbCommSysWork *p)
{
    void *zoneData;
    u16 *eventWorkA;
    u16 *eventWorkB;

    UI_ClearKeepAwakeFlagsGlobal(16);
    func_02030EAC(p->vblankTask);
    func_0200566C();
    GFL_NET_WM_ICON_EasyEnd();
    if (p->standalone == 1) {
        GFL_USE_CancelChangeAndStopBgm();
    } else {
        zoneData = (void *)GAME_DATA_GetEventWork(p->arg->gameData);
        eventWorkA = (u16 *)ZONEDATA_GetEventWorkAddress((u32)zoneData, 16384);
        eventWorkB = (u16 *)ZONEDATA_GetEventWorkAddress((u32)zoneData, 16385);
        *eventWorkA = p->bestChildCount;
        *eventWorkB = p->transferCount;
    }
    if (p->payload)
        func_020307B0(p->payload);
    MB_COMM_SYS_DeleteNetState(p->net);
    MB_UTIL_MSG_Delete(p->msg);
    MB_COMM_SYS_ExitDisplay(p);
}

/* Reads the file image named by ROM string 142 into a new buffer. */
static inline void MbCommSys_LoadPayload(MbCommSysWork *p)
{
    File file;
    void *name;

    name = func_0200575C(142);
    FS_InitFile(&file);
    if (!FS_OpenFile(&file, name))
        func_02034714(d_021F6E08, 0, d_021F6E08);
    FS_SeekFile(&file, 0, 0);
    p->payloadSize = FS_GetLength(&file);
    p->payload = func_02030734(p->heapId, p->payloadSize, 1, d_021F6E0C, 660);
    FS_ReadFile(&file, p->payload, p->payloadSize);
    if (!FS_CloseFile(&file))
        func_02034714(d_021F6E08, 0, d_021F6E08);
    p->phase = 13;
}

/* Proc main loop: one frame of the parent screen flow. Returns 1 when finished. */
int MB_COMM_SYS_Main(MbCommSysWork *p)
{
    u32 result;

    MB_COMM_SYS_UpdateNetState(p->net);
    if (p->errorScreenRequested == 1 && p->phase != 2 && p->phase != 3) {
        p->wasSaving = GAME_DATA_IsSaving(p->arg->gameData);
        if (p->wasSaving == 1)
            GAME_DATA_SaveCancel(p->arg->gameData);
        p->phase = 2;
        MB_COMM_SYS_UpdateSaveState(p, 3);
    }
    switch (p->phase) {
    case 0:
        WIPE_SYS_Start(0, 1, 1, 0, 6, 1, p->heapId);
        p->phase = 1;
        break;
    case 1:
        if (WIPE_SYS_EndCheck() == 1) {
            if (APP_ENV_InitParentalControl() == 1) {
                if (p->standalone == 0)
                    p->phase = 7;
                else
                    p->phase = 4;
            } else {
                MB_UTIL_MSG_SetWindowLayout(p->msg, 5);
                MB_UTIL_MSG_PrintStreamSystemMsg(p->msg, MSG_SPEED_GetWait());
                MB_UTIL_MSG_SetKeyWaitFlag(p->msg, 1);
                p->phase = 33;
            }
        }
        break;
    case 2:
        if (p->arg->standalone == 0) {
            WIPE_SYS_Start(0, 0, 0, 0, 6, 1, p->heapId);
        } else {
            WIPE_SYS_Start(0, 0, 0, 32767, 6, 1, p->heapId);
            GFL_USE_FadeOutBgm(6);
        }
        p->phase = 3;
        break;
    case 3:
        if (WIPE_SYS_EndCheck() == 1)
            return 1;
        break;
    case 4:
        MB_UTIL_MSG_SetWindowLayout(p->msg, 5);
        MB_UTIL_MSG_PrintStream(p->msg, 43, MSG_SPEED_GetWait());
        p->phase = 5;
        break;
    case 5:
        if (MB_UTIL_MSG_IsStreamIdle(p->msg) == 1) {
            MB_UTIL_MSG_OpenYesNoMenu(p->msg, 0);
            p->phase = 6;
        }
        break;
    case 6:
        result = MB_UTIL_MSG_ProcessYesNoMenu(p->msg);
        if (result == 1) {
            p->phase = 7;
            MB_UTIL_MSG_ClearWindow(p->msg);
            MB_UTIL_MSG_ClearYesNoMenu(p->msg);
        } else if (result == 2) {
            p->phase = 2;
        }
        break;
    case 7:
        MB_COMM_SYS_BuildGameStrings(p);
        p->phase = 8;
        break;
    case 8:
        if (MB_COMM_SYS_MainWireless(p) == 1)
            p->phase = 9;
        break;
    case 9:
        MB_COMM_SYS_FreeGameStrings(p);
        if (p->lobbyAccepted == 1) {
            p->phase = 10;
            p->timeoutFrames = 0;
            MB_COMM_SYS_StartNetSession(p->net);
            if (p->standalone == 0)
                GFL_NET_RestartWithDefaultTimeout(0, p->heapId);
            else
                GFL_NET_RestartWithDefaultTimeout(1, p->heapId);
        } else {
            p->phase = 2;
        }
        break;
    case 10:
        if (MB_COMM_SYS_GetNetRunState(p->net) == 1) {
            p->phase = 11;
            MB_COMM_SYS_StartNet(p->net);
        }
        break;
    case 11:
        p->timeoutFrames++;
        if (p->timeoutFrames >= 1800) {
            MB_COMM_SYS_UpdateSaveState(p, 3);
            p->phase = 30;
        } else if (MB_COMM_SYS_IsLoginDone(p->net) == 1) {
            p->header.msgSpeed = MSG_SPEED_GetWait();
            p->header.configCode = func_020461E4(p->header.msgSpeed);
            if (p->standalone == 0)
                p->header.savedCount = BEACON_GetBestScore(p->saveState);
            if (MB_COMM_SYS_SendHeader(p->net, &p->header) == 1) {
                if (p->standalone == 0)
                    p->phase = 12;
                else
                    p->phase = 32;
            }
        }
        break;
    case 12:
        MbCommSys_LoadPayload(p);
        break;
    case 13:
        p->phase = 14;
        break;
    case 14:
        if (MB_COMM_SYS_GetCommStage(p->net) == 10)
            goto failure;
        if (MB_COMM_SYS_GetCommStage(p->net) == 2) {
            if (p->payloadQueued == 0) {
                p->payloadQueued = 1;
                MB_COMM_SYS_QueuePayload((int)p->net, (int)p->payload, p->payloadSize);
            }
            MB_UTIL_MSG_PrintStream(p->msg, 2, MSG_SPEED_GetWait());
            p->phase = 15;
        }
        break;
    case 15:
        if (MB_COMM_SYS_GetCommStage(p->net) == 3) {
            MB_UTIL_MSG_PrintStream(p->msg, 3, MSG_SPEED_GetWait());
            p->phase = 16;
        } else if (MB_COMM_SYS_GetCommStage(p->net) == 13) {
            MB_COMM_SYS_UpdateSaveState(p, 4);
            MB_UTIL_MSG_PrintStream(p->msg, 8, MSG_SPEED_GetWait());
            MB_COMM_SYS_SetSyncRange(p->net);
            p->phase = 28;
        }
        /* falls into case 16 */
    case 16:
        if (MB_COMM_SYS_GetCommStage(p->net) == 4) {
            MB_COMM_SYS_ClearMonBuffer(p->net);
            MB_UTIL_MSG_PrintStream(p->msg, 4, MSG_SPEED_GetWait());
            p->phase = 17;
        }
        break;
    case 17:
        if (MB_COMM_SYS_GetCommStage(p->net) == 5) {
            func_02008DF0(GAME_DATA_GetTrainerRecord(p->arg->gameData), 120);
            p->transferCount++;
            p->phase = 18;
        } else if (MB_COMM_SYS_GetCommStage(p->net) == 8) {
            func_02008DF0(GAME_DATA_GetTrainerRecord(p->arg->gameData), 120);
            p->transferCount++;
            MB_COMM_SYS_UpdateSaveState(p, 2);
            p->phase = 23;
        }
        break;
    case 18:
        if (MB_COMM_SYS_HasMonsReceived(p->net) == 1 && MB_COMM_SYS_SendMessage(p->net, 0, 0) == 1)
            p->phase = 19;
        break;
    case 19:
        if (MB_COMM_SYS_HasKind0(p->net) == 1 || p->standalone == 1) {
            if (MB_COMM_SYS_GetCommStage(p->net) == 6) {
                p->phase = 20;
            } else if (MB_COMM_SYS_GetCommStage(p->net) == 10) {
                if (p->standalone == 0) {
failure:
                    MB_COMM_SYS_UpdateSaveState(p, 3);
                    MB_UTIL_MSG_PrintStream(p->msg, 8, MSG_SPEED_GetWait());
fail_tail:
                    MB_COMM_SYS_SetSyncRange(p->net);
                    p->phase = 28;
                } else {
                    MB_UTIL_MSG_PrintStream(p->msg, 38, MSG_SPEED_GetWait());
                    MB_UTIL_MSG_SetKeyWaitFlag(p->msg, 1);
                    p->phase = 26;
                }
            }
        }
        break;
    case 20:
        MB_COMM_SYS_FinishReceive(p);
        p->phase = 21;
        p->subPhase = 9;
        break;
    case 21:
        MB_COMM_SYS_MainSave(p);
        break;
    case 22:
        MB_COMM_SYS_NoOp(p);
        if (p->standalone == 0) {
            MB_UTIL_MSG_PrintStream(p->msg, 7, MSG_SPEED_GetWait());
            p->phase = 23;
        } else {
            MB_UTIL_MSG_PrintStream(p->msg, 39, MSG_SPEED_GetWait());
            MB_UTIL_MSG_SetKeyWaitFlag(p->msg, 1);
            p->phase = 27;
        }
        break;
    case 23:
        if (MB_UTIL_MSG_IsStreamIdle(p->msg) == 1) {
            u16 partyCount = func_02007774((void *)GAME_DATA_GetBoxManager(p->arg->gameData));
            if (MB_COMM_SYS_SendMessage(p->net, 5, partyCount) == 1) {
                MB_UTIL_MSG_PrintStream(p->msg, 11, MSG_SPEED_GetWait());
                p->phase = 24;
            }
        }
        break;
    case 24:
        if (MB_COMM_SYS_GetCommStage(p->net) == 2) {
            MB_COMM_SYS_ClearRoundFlags(p->net);
            p->phase = 14;
        } else if (MB_COMM_SYS_GetCommStage(p->net) == 9 || MB_COMM_SYS_GetCommStage(p->net) == 10) {
            if (MB_COMM_SYS_GetCommStage(p->net) == 10)
                MB_COMM_SYS_UpdateSaveState(p, 3);
            MB_UTIL_MSG_PrintStream(p->msg, 8, MSG_SPEED_GetWait());
            p->phase = 27;
        }
        break;
    case 27:
        if (MB_COMM_SYS_SendMessage(p->net, 18, 0) != 1)
            break;
        goto fail_tail;
    case 28:
        if (MB_UTIL_MSG_IsStreamIdle(p->msg) == 1 && MB_COMM_SYS_IsSyncDone(p->net) == 1) {
            MB_COMM_SYS_StopNetSession(p->net);
            p->phase = 29;
        }
        break;
    case 29:
        if (MB_COMM_SYS_IsNetSessionNull(p->net) == 1) {
            if (p->standalone == 0)
                p->phase = 2;
            else
                p->phase = 25;
        }
        break;
    case 25:
        if (MB_UTIL_MSG_IsStreamIdle(p->msg) == 1) {
            MB_UTIL_MSG_ClearWindow(p->msg);
            MB_UTIL_MSG_SetWindowLayout(p->msg, 1);
            MB_UTIL_MSG_PrintStream(p->msg, 35, MSG_SPEED_GetWait());
            MB_UTIL_MSG_SetKeyWaitFlag(p->msg, 1);
            p->phase = 26;
        }
        break;
    case 26:
        if (MB_COMM_SYS_IsNetSessionNull(p->net) == 1 && MB_UTIL_MSG_IsStreamIdle(p->msg) == 1)
            p->phase = 2;
        break;
    case 30:
        MB_UTIL_MSG_PrintStream(p->msg, 10, MSG_SPEED_GetWait());
        MB_UTIL_MSG_SetKeyWaitFlag(p->msg, 1);
        p->phase = 31;
        MB_COMM_SYS_StopNetSession(p->net);
        break;
    case 31:
        if (MB_UTIL_MSG_IsStreamIdle(p->msg) == 1)
            p->phase = 29;
        /* falls into case 32 */
    case 32:
        MB_COMM_SYS_MainChildFlow(p);
        break;
    case 33:
        if (MB_UTIL_MSG_IsStreamIdle(p->msg) == 1)
            p->phase = 2;
        break;
    }
    CLACT_DrawSystem(MB_UTIL_MSG_Main(p->msg));
    return 0;
}

void MB_COMM_SYS_VBlank(void)
{
    CLACT_VBlankSystem();
}

/* VBlank hook, in-game mode: refreshes the BG planes of both engines every third frame. */
void MB_COMM_SYS_VBlankRefreshBg(void)
{
    if (gMbParentUi.vblankDivider > 1) {
        gMbParentUi.vblankDivider = 0;
        BG_SYS_FillScrollArea(3, 2, 1);
        BG_SYS_FillScrollArea(3, 5, 1);
        BG_SYS_FillScrollArea(7, 2, 1);
        BG_SYS_FillScrollArea(7, 5, 1);
    } else {
        gMbParentUi.vblankDivider++;
    }
}

/*
 * volatile: 021EEF02 re-reads counter after 021EEF00 store.
 */
/* VBlank hook, standalone mode: refreshes plane 5 of both engines every fifth frame. */
void MB_COMM_SYS_VBlankRefreshBgStandalone(void)
{
    gMbParentUi.vblankCounter++;
    if (gMbParentUi.vblankCounter >= 5) {
        gMbParentUi.vblankCounter = 0;
        BG_SYS_FillScrollArea(3, 5, 1);
        BG_SYS_FillScrollArea(7, 5, 1);
    }
}

/*
 * volatile: Hardware MMIO read/write at 021EEF3A..021EEF78; display and power registers.
 */
/* Resets both display engines and sets up the BG layers and the CLACT system. */
void MB_COMM_SYS_InitDisplay(MbCommSysWork *p)
{
    struct ClActInitParam clactInit;

    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    REG_DISPCNT_MAIN &= 0xffffe0ff;
    REG_DISPCNT_SUB &= 0xffffe0ff;
    WIPE_SetBrightnessFadeOut(0, 0);
    WIPE_SetBrightnessFadeOut(1, 0);
    WIPE_ResetWndMask((void *)0);
    WIPE_ResetWndMask((void *)1);
    REG_BLDCNT_MAIN = 0;
    REG_BLDCNT_SUB = 0;
    REG_POWCNT1 |= 0x8000;
    BG_SYS_SetVramBanks(&d_021F6C10);
    BG_SYS_Create(p->heapId);
    BMP_WIN_Init(p->heapId);
    BG_SYS_SetGraphicsMode(&d_021F6B00);
    MB_COMM_SYS_InitBgLayer(&d_021F6B50, 0, 0);
    MB_COMM_SYS_InitBgLayer(&d_021F6B70, 1, 0);
    MB_COMM_SYS_InitBgLayer(&d_021F6B90, 2, 0);
    MB_COMM_SYS_InitBgLayer(&d_021F6BB0, 3, 0);
    MB_COMM_SYS_InitBgLayer(&d_021F6BD0, 4, 0);
    MB_COMM_SYS_InitBgLayer(&d_021F6BF0, 5, 0);
    MB_COMM_SYS_InitBgLayer(&d_021F6B10, 6, 0);
    MB_COMM_SYS_InitBgLayer(&d_021F6B30, 7, 0);
    if (!p->standalone)
        func_02040588(6, 1);
    else
        func_02040588(6, 0);
    clactInit = gClActorInitParam;
    clactInit.dimensions[0] = 64;
    CLACT_InitSystem(&clactInit, (u32)&d_021F6C10, p->heapId);
    p->clactUnit = CLACT_CreateUnit(8, 0, p->heapId);
    CLACT_SetUnitDefaultRenderer(p->clactUnit);
    BG_SYS_SetMainPlaneVisible(16, 1);
    BG_SYS_SetSubPlaneVisible(16, 1);
}

/*
 * extent: two bytes of alignment padding follow the return.
 */
/* Deletes the actor, CLACT unit and BG layers created by the init. */
void MB_COMM_SYS_ExitDisplay(MbCommSysWork *p)
{
    CLACT_DeleteActor(p->actor);
    CLACT_DeleteUnit(p->clactUnit);
    CLACT_ExitSystem();
    BG_SYS_FreeLayerBuf(0);
    BG_SYS_FreeLayerBuf(1);
    BG_SYS_FreeLayerBuf(2);
    BG_SYS_FreeLayerBuf(3);
    BG_SYS_FreeLayerBuf(7);
    BG_SYS_FreeLayerBuf(6);
    BG_SYS_FreeLayerBuf(5);
    BG_SYS_FreeLayerBuf(4);
    BMP_WIN_Exit();
    BG_SYS_Delete();
}

/* Sets up one BG layer from a template, shows it and refreshes it. */
void MB_COMM_SYS_InitBgLayer(const void *bgTemplate, u32 layer, u32 mode)
{
    BG_SYS_InitBgLayer(layer, bgTemplate, mode);
    func_02040588(layer, 1);
    BG_SYS_FreeSlot(layer);
    BG_SYS_PushTile(layer);
}

/* Loads the background graphics, palettes and the actor sprite for the current mode. */
void MB_COMM_SYS_LoadGraphics(MbCommSysWork *p)
{
    void *archive;
    u32 firstCell;
    struct Placement placement;

    if (!p->standalone) {
        archive = func_020490F4(139, p->heapId);
        func_02049B68(archive, 1, 4, 0, 0, p->heapId);
        func_02049658(archive, 5, 7, 0, 0, 0, p->heapId);
        func_020498F4(archive, 9, 7, 0, 0, 0, p->heapId);
        func_02049B68(archive, 0, 0, 0, 0, p->heapId);
        func_02049658(archive, 4, 3, 0, 0, 0, p->heapId);
        func_020498F4(archive, 8, 3, 0, 0, 0, p->heapId);
        ARC_UTIL_UploadPaletteFromHandle(archive, 2, 0, 288, 288, 128, p->heapId);
        func_02049658(archive, 6, 2, 0, 0, 0, p->heapId);
        func_020498F4(archive, 10, 2, 0, 0, 0, p->heapId);
        ARC_UTIL_UploadPaletteFromHandle(archive, 3, 0, 416, 416, 32, p->heapId);
        func_02049658(archive, 7, 0, 0, 0, 0, p->heapId);
        func_020498F4(archive, 11, 0, 0, 0, 0, p->heapId);
        BG_SYS_PushTile(2);
        ARC_TOOL_DeleteHandle(archive);
    } else {
        archive = func_020490F4(34, p->heapId);
        func_02049B68(archive, 6, 4, 0, 0, p->heapId);
        func_02049658(archive, 15, 7, 0, 0, 0, p->heapId);
        func_020498F4(archive, 31, 7, 0, 0, 0, p->heapId);
        func_02049B68(archive, 6, 0, 0, 0, p->heapId);
        func_02049658(archive, 15, 3, 0, 0, 0, p->heapId);
        func_020498F4(archive, 31, 3, 0, 0, 0, p->heapId);
        ARC_TOOL_DeleteHandle(archive);
        archive = func_020490F4(139, p->heapId);
        ARC_UTIL_UploadPaletteFromHandle(archive, 2, 4, 288, 288, 128, p->heapId);
        func_02049658(archive, 6, 5, 0, 0, 0, p->heapId);
        func_020498F4(archive, 10, 5, 0, 0, 0, p->heapId);
        ARC_UTIL_UploadPaletteFromHandle(archive, 3, 4, 416, 416, 32, p->heapId);
        func_02049658(archive, 7, 4, 0, 0, 0, p->heapId);
        func_020498F4(archive, 11, 4, 0, 0, 0, p->heapId);
        BG_SYS_PushTile(5);
        func_02040588(5, 0);
        func_02040588(4, 0);
        ARC_TOOL_DeleteHandle(archive);
    }
    archive = func_020490F4(APP_ICON_GetArchiveId(), p->heapId);
    func_02049B68(archive, APP_ICON_GetStatusAnimFileId(), 4, 256, 32, p->heapId);
    func_02049658(archive, APP_ICON_GetStatusFrameFileId(), 6, 0, 0, 0, p->heapId);
    func_020498F4(archive, APP_ICON_GetStatusDataFileId(), 6, 0, 0, 0, p->heapId);
    BG_SYS_FillTileMap(6, 0, 21, 32, 3, 8);
    BG_SYS_PushTile(6);
    p->paletteId = CLACT_RegisterPaletteEx(archive, APP_ICON_GetMoveKindPaletteFileId(), 1, 0, 0, 3, p->heapId);
    p->charId = CLACT_RegisterCharacter(archive, APP_ICON_GetMoveKindAnimFileId(), 0, 1, p->heapId);
    firstCell = APP_ICON_GetStatusCellFileId(2);
    p->cellAnimId = CLACT_RegisterCellAnim(archive, firstCell, APP_ICON_GetStatusPaletteFileId(2), p->heapId);
    ARC_TOOL_DeleteHandle(archive);
    placement.x = 232;
    placement.y = 168;
    placement.z = 1;
    placement.bgPriority = 0;
    placement.animSeq = 0;
    p->actor = CLACT_CreateActor(p->clactUnit, p->charId, p->paletteId, p->cellAnimId, &placement, 1, p->heapId);
    if (!p->standalone) {
        CLACT_SetActorDrawEnable(p->actor, 1);
        return;
    } else {
        CLACT_SetActorDrawEnable(p->actor, 0);
        return;
    }
}

/*
 * extent: two bytes of alignment padding follow the return.
 */
/*
 * volatile: MMIO palette halfword stores at 021EF56E and 021EF572.
 */
/* Draws the title text window on the text BG and sets the backdrop colour. */
void MB_COMM_SYS_DrawTitle(MbCommSysWork *p)
{
    u8 textBg;
    void *window;
    void *archive;
    void *text;
    void *bank;

    if (!p->standalone) {
        gMbParentUi.textOnSubScreen = 1;
        textBg = 4;
    } else {
        gMbParentUi.textOnSubScreen = 0;
        textBg = 2;
    }
    func_02040588(textBg, 0);
    archive = func_020490F4(22, p->heapId);
    func_02049B68(archive, 0, 4, 224, 32, p->heapId);
    func_02049B68(archive, 0, 0, 224, 32, p->heapId);
    func_02049658(archive, 1, textBg, 0, 0, 0, p->heapId);
    func_020498F4(archive, 2, textBg, 0, 0, 0, p->heapId);
    BG_SYS_FillTileMap(textBg, 0, 0, 32, 24, 7);
    BG_SYS_PushTile(textBg);
    ARC_TOOL_DeleteHandle(archive);
    window = BMP_WIN_Create(textBg, 1, 4, 30, 8, 7, 1);
    bank = func_02045B38(0, 2, 0x52, p->heapId);
    text = func_02045EC0(bank, 1);
    BMP_Clear(BMP_WIN_GetBmp(window), 7);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(window), 0, 0, text, (void *)MB_UTIL_MSG_GetFont(p->msg), 0x1167);
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(window));
    STRBUF_Delete(text);
    MSGDATA_Delete(bank);
    BMP_WIN_Delete(window);
    PLTT_BG_MAIN[0] = 0x7eea;
    PLTT_BG_SUB[0] = 0x7eea;
}

/*
 * 2026-10-05 (integrator): the fullwidth-to-ASCII constants are plain literals (0xFF29, 0xFF24, 0xFF10..0xFF19, c - 0xFEE0); mwcc derives them from one held value itself, so the earlier `u32 k = 0xFF24` local was not needed. EXACT in c99 and c.
 */
/* Builds the game name and description strings (with the player name) for the registry. */
void MB_COMM_SYS_BuildGameStrings(MbCommSysWork *p)
{
    void *ownerData;
    void *nameStr;
    void *introStr;
    void *msgPiece;
    u16 nameLength;
    u16 introLength;
    int i;
    u16 *dst;
    u16 *src;

    ownerData = GAME_DATA_GetMyStatus(p->arg->gameData);
    p->subPhase = 0;
    p->recruitPhase = 0;
    p->gameNameBuf = func_02030734(p->heapId, 0x60, 1, d_021F6E0C, 0x553);
    p->gameIntroBuf = func_02030734(p->heapId, 0xC0, 1, d_021F6E0C, 0x554);
    MB_UTIL_MSG_SetWindowLayout(p->msg, 1);
    MB_UTIL_MSG_CreateWordSet(p->msg);
    MB_UTIL_MSG_SetNumberZeroPad(p->msg, 0, func_02008534(ownerData), 5);
    if (p->standalone == 0)
        msgPiece = func_02045EC0(MB_UTIL_MSG_GetMsgData(p->msg), 0xC);
    else
        msgPiece = func_02045EC0(MB_UTIL_MSG_GetMsgData(p->msg), 0xF);
    nameStr = STRBUF_Create(0x100, p->heapId);
    WORDSET_CopyTaggedText(MB_UTIL_MSG_GetWordSet(p->msg), nameStr, msgPiece);
    STRBUF_Delete(msgPiece);
    if (p->standalone == 0)
        msgPiece = func_02045EC0(MB_UTIL_MSG_GetMsgData(p->msg), 0xD);
    else
        msgPiece = func_02045EC0(MB_UTIL_MSG_GetMsgData(p->msg), 0x10);
    introStr = msgPiece;
    nameLength = (u32)STRBUF_GetLength(nameStr);
    introLength = (u32)STRBUF_GetLength(introStr);
    dst = p->gameNameBuf;
    src = STRBUF_GetChars(nameStr);
    MIi_CpuCopy16(src, dst, nameLength * 2);
    dst = p->gameIntroBuf;
    src = STRBUF_GetChars(introStr);
    MIi_CpuCopy16(src, dst, introLength * 2);
    STRBUF_Delete(nameStr);
    STRBUF_Delete(introStr);
    p->gameNameBuf[nameLength] = 0;
    p->gameIntroBuf[introLength] = 0;
    for (i = 0; i < 0x60; i++) {
        if (p->gameIntroBuf[i] == 0xFFFE)
            p->gameIntroBuf[i] = 0xA;
    }
    for (i = 0; i < 0x30; i++) {
        u16 c = p->gameNameBuf[i];
        if (c == 0xFF29)
            p->gameNameBuf[i] = 0x49;
        else if (c == 0xFF24)
            p->gameNameBuf[i] = 0x44;
        else if (c >= 0xFF10 && c <= 0xFF19)
            p->gameNameBuf[i] = c - 0xFEE0;
    }
    p->lobbyAccepted = 0;
    func_02034AC4((int)ov014_id);
    if (p->standalone == 0) {
        func_02040588(2, 1);
        func_02040588(0, 1);
    } else {
        func_02040588(5, 1);
        func_02040588(4, 1);
    }
    CARD_SetPulledOutCallback(MB_COMM_SYS_ShowTextPlane);
}

/* Frees the game name and description strings and hides the BG layers they used. */
void MB_COMM_SYS_FreeGameStrings(MbCommSysWork *p)
{
    func_02034A5C((int)ov014_id);
    CARD_SetPulledOutCallback(0);
    func_020307B0(p->gameNameBuf);
    func_020307B0(p->gameIntroBuf);
    if (!p->standalone) {
        func_02040588(2, 0);
        func_02040588(0, 0);
    } else {
        func_02040588(5, 0);
        func_02040588(4, 0);
    }
}

/* Wireless start-up and teardown state machine (WIH). Returns 1 when WM is down again. */
int MB_COMM_SYS_MainWireless(MbCommSysWork *p)
{
    void *ownerData;

    if (WIH_GetSysState() == 9 || WIH_GetSysState() == 10) {
        p->lobbyAccepted = 0;
        p->wirelessFailed = 1;
        if (WIH_Finalize() == 1) {
            MB_PARENT_SYS_FreeBuffers();
            WIH_FreeWork();
            return 1;
        }
        return 0;
    }
    switch (p->subPhase) {
    case 0:
        gMbParentUi.wmEndDone = 0;
        p->wmActive = 1;
        WIH_Initialize(p->heapId, (int)MB_COMM_SYS_WmEndCallback, 0);
        GFL_NET_WM_ICON_EasyStart(240, 0, 0, p->heapId);
        if (p->standalone == 0)
            GFL_NET_WM_ICON_EasySetScreen(0, p->heapId);
        else
            GFL_NET_WM_ICON_EasySetScreen(1, p->heapId);
        p->subPhase = 1;
        func_020351F8((u32)MB_COMM_SYS_ResetHook, (u32)p);
        break;
    case 1:
        if (WIH_GetSysState() == 1 && WIH_StartMeasureChannel() == 1)
            p->subPhase = 2;
        break;
    default:
        break;
    case 2:
        if (WIH_GetSysState() == 7) {
            ownerData = GAME_DATA_GetMyStatus(p->arg->gameData);
            MB_COMM_SYS_StartParent(p);
            MB_UTIL_MSG_ClearWindow(p->msg);
            if (p->standalone == 0)
                MB_UTIL_MSG_SetWindowLayout(p->msg, 2);
            else
                MB_UTIL_MSG_SetWindowLayout(p->msg, 3);
            MB_UTIL_MSG_CreateWordSet(p->msg);
            MB_UTIL_MSG_SetNumberZeroPad(p->msg, 0, func_02008534(ownerData), 5);
            if (p->standalone == 0)
                MB_UTIL_MSG_PrintStream(p->msg, 0, MSG_SPEED_GetWait());
            else
                MB_UTIL_MSG_PrintStream(p->msg, 20, MSG_SPEED_GetWait());
            MB_UTIL_MSG_DeleteWordSet(p->msg);
            p->subPhase = 3;
        }
        break;
    case 3:
        MB_COMM_SYS_MainRecruit(p);
        break;
    case 4:
        MB_UTIL_MSG_ClearWindow(p->msg);
        MB_UTIL_MSG_SetWindowLayout(p->msg, 1);
        if (p->standalone == 0)
            MB_UTIL_MSG_PrintQueued(p->msg, 1);
        else
            MB_UTIL_MSG_PrintQueued(p->msg, 21);
        MB_UTIL_MSG_SetTimeIconPending(p->msg, 1);
        CLACT_SetActorAnimSeq(p->actor, 15);
        p->subPhase = 5;
        break;
    case 5:
        p->lobbyAccepted = 1;
        p->subPhase = 6;
        break;
    case 8:
        p->subPhase = 6;
        break;
    case 6:
        gMbParentUi.wmEndDone = 0;
        WIH_End((void (*)(int))((int (*)(int))MB_COMM_SYS_WmEndCallback));
        p->wmActive = 0;
        p->subPhase = 7;
        break;
    case 7:
        if (gMbParentUi.wmEndDone == 1) {
            func_020351F8(0, 0);
            WIH_FreeWork();
            return 1;
        }
        break;
    }
    GFL_NET_WM_ICON_EasySetLevel(3 - WM_GetLinkLevel());
    GFL_NET_WM_ICON_EasyMain();
    return 0;
}

/* Builds the registry block, then starts the parent and registers the game. */
void MB_COMM_SYS_StartParent(MbCommSysWork *p)
{
    MbPathPair romPaths = d_021F6D68;
    MbPathPair iconCharPaths = d_021F6D70;
    MbPathPair iconPalettePaths = d_021F6D60;
    MbRegistryBlock registry = d_021F6C40;
    int channel = WIH_GetMeasureChannel();

    MI_CpuCopy8(&registry, &p->registry, 60);
    p->registry.romPath = p->standalone == 0 ? romPaths.inGame : romPaths.standalone;
    p->registry.iconCharPath = iconCharPaths.standalone;
    p->registry.iconPalettePath = iconPalettePaths.standalone;
    p->registry.gameName = p->gameNameBuf;
    p->registry.gameIntro = p->gameIntroBuf;
    MB_PARENT_SYS_Init(4992, 65536);
    MB_PARENT_SYS_Register(&p->registry, channel);
}

/*
 * extent: follower 021EFC10 already has its own matched source/shard.
 * ABI: 19E4 keeps the caller's visibly supplied r1. 0AE4 reads no incoming arguments.
 */
/* Recruiting screen: shows the child count prompts and handles start or cancel. */
void MB_COMM_SYS_MainRecruit(MbCommSysWork *p)
{
    int answer;
    void *ownerData;

    MB_PARENT_SYS_GetState();
    switch (MB_PARENT_SYS_GetState()) {
    case 2:
        if (p->recruitPhase == 0) {
            answer = TOUCHPANEL_HitTrg(d_021F6AF8);
            if (KEY_GetTrg() == 2 || (answer == 0 && p->standalone == 0)) {
                p->recruitPhase = 1;
                CLACT_SetActorAnimSeq(p->actor, 9);
                CLACT_SetActorAutoAnim(p->actor, 1);
                GFL_USE_PlaySeDefaultVolume(1361);
            } else if (MB_PARENT_SYS_AllBootable()) {
                MB_PARENT_SYS_StartBoot();
            }
        }
        break;
    case 5:
        p->subPhase = 4;
        break;
    case 7:
        MB_PARENT_SYS_Cancel();
        break;
    case 0:
        p->subPhase = 8;
        break;
    case 1:
    case 3:
    case 4:
    case 6:
    default:
        break;
    }
    switch (p->recruitPhase) {
    case 1:
        MB_UTIL_MSG_ClearWindow(p->msg);
        CLACT_SetActorAnimSeq(p->actor, 15);
        if (p->standalone == 0) {
            MB_UTIL_MSG_SetWindowLayout(p->msg, 7);
            MB_UTIL_MSG_PrintStream(p->msg, 9, MSG_SPEED_GetWait());
        } else {
            MB_UTIL_MSG_SetWindowLayout(p->msg, 5);
            MB_UTIL_MSG_PrintStream(p->msg, 42, MSG_SPEED_GetWait());
        }
        p->recruitPhase = 2;
        break;
    case 2:
        if (MB_UTIL_MSG_IsStreamIdle(p->msg) == 1) {
            if (p->standalone == 0)
                MB_UTIL_MSG_OpenYesNoTaskMenu(p->msg, 0);
            else
                MB_UTIL_MSG_OpenYesNoMenu(p->msg, 0);
            p->recruitPhase = 3;
        }
        break;
    case 3:
        if (p->standalone == 0)
            answer = MB_UTIL_MSG_GetTaskMenuResult(p->msg);
        else
            answer = MB_UTIL_MSG_ProcessYesNoMenu(p->msg);
        if (answer == 1) {
            if (MB_PARENT_SYS_GetState() != 2)
                func_02034714(d_021F6E08, 0, d_021F6E08);
            MB_COMM_SYS_UpdateSaveState(p, 4);
            MB_PARENT_SYS_Cancel();
            p->recruitPhase = 4;
        } else if (answer == 2) {
            ownerData = GAME_DATA_GetMyStatus(p->arg->gameData);
            if (p->standalone == 0)
                MB_UTIL_MSG_CloseTaskMenu(p->msg);
            else
                MB_UTIL_MSG_ClearYesNoMenu(p->msg);
            MB_UTIL_MSG_ClearWindow(p->msg);
            if (p->standalone == 0)
                MB_UTIL_MSG_SetWindowLayout(p->msg, 2);
            else
                MB_UTIL_MSG_SetWindowLayout(p->msg, 3);
            MB_UTIL_MSG_CreateWordSet(p->msg);
            MB_UTIL_MSG_SetNumberZeroPad(p->msg, 0, func_02008534(ownerData), 5);
            CLACT_SetActorAnimSeq(p->actor, 1);
            if (p->standalone == 0)
                MB_UTIL_MSG_PrintStream(p->msg, 0, MSG_SPEED_GetWait());
            else
                MB_UTIL_MSG_PrintStream(p->msg, 20, MSG_SPEED_GetWait());
            MB_UTIL_MSG_DeleteWordSet(p->msg);
            p->recruitPhase = 0;
        }
        break;
    }
}

/* WM end callback: tells the main loop that WM has finished shutting down. */
int MB_COMM_SYS_WmEndCallback(void)
{
    gMbParentUi.wmEndDone = 1;
    return 1;
}

/* Moves the save state value to mode unless the current state already covers it. */
void MB_COMM_SYS_UpdateSaveState(MbCommSysWork *p, int mode)
{
    unsigned cur;
    int change;

    if (p->standalone == 0) {
        cur = BEACON_GetRank(p->saveState);
        change = 0;
        switch (mode) {
        case 0:
            if (cur != 1 && cur != 3 && cur != 5)
                change = 1;
            break;
        case 1:
            if (cur != 3 && cur != 5)
                change = 1;
            break;
        case 2:
            if (cur != 0 && cur != 1 && cur != 3 && cur != 5)
                change = 1;
            break;
        case 3:
            change = 1;
            if (p->receivedTotal != 0)
                mode = 5;
            break;
        case 4:
            if (cur != 2 && cur != 0 && cur != 1 && cur != 3 && cur != 5)
                change = 1;
            break;
        }
        if (change == 1)
            BEACON_SetRank(p->saveState, mode);
    }
}

/*
 * extent: follower 021EFC10 already has its own matched source/shard.
 * ABI: 19E4 keeps the caller's visibly supplied r1. 0AE4 reads no incoming arguments.
 */
/* Reset hook: stops recruiting and waits for WM to shut down before the reset goes on. */
void MB_COMM_SYS_ResetHook(MbCommSysWork *p)
{
    unsigned registered = MB_PARENT_SYS_IsRegistered();

    if (registered == 1)
        MB_PARENT_SYS_Cancel();
    while (MB_PARENT_SYS_GetState() != 0 && MB_PARENT_SYS_GetState() != 5)
        OS_WaitIrq(1, 1);
    if (p->wmActive == 1) {
        gMbParentUi.wmEndDone = 0;
        while (WIH_End((void (*)(int))((int)MB_COMM_SYS_WmEndCallback)))
            OS_WaitIrq(1, 1);
        while (gMbParentUi.wmEndDone == 0)
            OS_WaitIrq(1, 1);
    }
}

/*
 * extent: two bytes of alignment padding after the return.
 */
/* Counts the mons the children sent, records them and updates the save state. */
void MB_COMM_SYS_FinishReceive(MbCommSysWork *p)
{
    unsigned received = MB_COMM_SYS_GetMonCount(p->net);
    unsigned oldCount;
    unsigned newCount;

    MB_UTIL_MSG_PrintQueued(p->msg, 6);
    MB_UTIL_MSG_SetTimeIconPending(p->msg, 1);
    MB_COMM_SYS_RegisterReceivedMons(p);
    if (p->standalone == 0) {
        oldCount = (u16)BEACON_GetBestScore(p->saveState);
        newCount = MB_COMM_SYS_GetMaxSeen(p->net);
        if (oldCount < newCount) {
            BEACON_SetBestScore(p->saveState, newCount);
            MB_COMM_SYS_UpdateSaveState(p, 1);
        } else if (received == 0) {
            MB_COMM_SYS_UpdateSaveState(p, 2);
        } else {
            MB_COMM_SYS_UpdateSaveState(p, 0);
        }
        if (p->bestChildCount < newCount)
            p->bestChildCount = newCount;
        p->receivedTotal = p->receivedTotal + received;
    }
}

/* Registers each received mon in the Pokedex and adds it to the party. */
void MB_COMM_SYS_RegisterReceivedMons(MbCommSysWork *p)
{
    void *party;
    void *dex;
    unsigned int received;
    void *trainerRecord;
    void *mon;
    int added;
    unsigned char i;

    party = (void *)GAME_DATA_GetBoxManager(p->arg->gameData);
    dex = ZUKAN_SAVE_GetFromGameData(p->arg->gameData);
    received = MB_COMM_SYS_GetMonCount(p->net);
    if (p->standalone == 0) {
        trainerRecord = GAME_DATA_GetTrainerRecord(p->arg->gameData);
        func_02008DAC(trainerRecord, 7, received);
        func_02008DAC(trainerRecord, 0x54, received);
    }
    for (i = 0; i < received; i++) {
        mon = MB_COMM_SYS_GetMon(p->net, i);
        SAVE_EVENT_StoreTodayDate(mon);
        added = func_020074D8(party, mon);
        mon = POKE_TOOL_CreateFromBoxParam(mon, p->heapId);
        ZUKAN_SAVE_RegisterCaught(dex, mon);
        func_020307B0(mon);
        if (added != 1)
            func_02034714(d_021F6E08, 0, d_021F6E08);
    }
}

/* Empty hook called between receiving and the closing prompt. */
void MB_COMM_SYS_NoOp(MbCommSysWork *p)
{
}

/*
 * evidence: caller-only TU/split was MATCH with nine overlay-only leaves;
 * parent-cleared 60-byte getter unit10D4 and standalone1B08 each verified
 * before unchanged caller re-run EXACT. Case18 is empty; case19 stores22.
 * prototype: own legacy02012DAC has three unused trailing parameters;
 * original supplies only r0; full body forwards only r0 to02012CE0 and
 * no inputs to0201042C, then replaces r0/r1 before remaining calls.
 */
/* Save sequence after the transfer: message, save start, wait, save main, closing messages. */
void MB_COMM_SYS_MainSave(MbCommSysWork *p)
{
    switch (p->subPhase) {
    case 9:
        if (MB_UTIL_MSG_IsPrintQueFinished(p->msg) == 1 && MB_UTIL_MSG_IsStreamIdle(p->msg) == 1 && MB_COMM_SYS_HasKind11(p->net) == 1) {
            if (MB_COMM_SYS_SendMessage(p->net, 1, func_020056EC(20) + 10) == 1)
                p->subPhase = 10;
        }
        break;
    case 10:
        if (MB_COMM_SYS_HasKind1(p->net) == 1)
            p->subPhase = 11;
        break;
    case 11:
        GAME_DATA_SaveStart((int)p->arg->gameData);
        p->subPhase = 12;
        break;
    case 12:
        if (GAME_DATA_SaveMain(p->arg->gameData) == 1)
            p->subPhase = 13;
        break;
    case 13:
        if (MB_COMM_SYS_HasKind12(p->net) == 1 && MB_COMM_SYS_SendMessage(p->net, 2, func_020056EC(20) + 10) == 1) {
            p->subPhase = 14;
            p->waitCounter = 0;
        }
        break;
    case 14:
        if (MB_COMM_SYS_HasKind2(p->net) == 1) {
            p->waitCounter++;
            if (p->waitCounter > (u32)MB_COMM_SYS_GetCount(p->net))
                p->subPhase = 15;
        }
        break;
    case 15:
        if (GAME_DATA_SaveMain(p->arg->gameData) == 2)
            p->subPhase = 16;
        break;
    case 16:
        if (MB_COMM_SYS_HasKind12Again(p->net) == 1 && MB_COMM_SYS_SendMessage(p->net, 3, 0) == 1) {
            p->subPhase = 17;
            p->waitCounter = 0;
        }
        break;
    case 17:
        if (MB_COMM_SYS_HasKind14(p->net) == 1 && MB_COMM_SYS_SendMessage(p->net, 4, 0) == 1)
            p->subPhase = 19;
        break;
    case 18:
        break;
    case 19:
        if (MB_COMM_SYS_HasKind4(p->net) == 1)
            p->phase = 22;
        break;
    }
}

/* Child-side flow after the link is up (phase 32): offer prompts, mon exchange, trainer key. */
void MB_COMM_SYS_MainChildFlow(MbCommSysWork *p)
{
    int a;
    int b;
    void *saveTrainerKey;
    void *ownerData;
    void *miscSave;

    switch (p->childPhase) {
    case 0:
        if (MB_COMM_SYS_GetCommStage(p->net) == 10 || MB_COMM_SYS_GetCommStage(p->net) == 12) {
            MB_UTIL_MSG_PrintStream(p->msg, 0x29, MSG_SPEED_GetWait());
            MB_UTIL_MSG_SetKeyWaitFlag(p->msg, 1);
            MB_COMM_SYS_SetSyncRange(p->net);
            p->phase = 0x1B;
        }
        if (MB_COMM_SYS_GetCommStage(p->net) == 11) {
            MB_UTIL_MSG_PrintStream(p->msg, 0x2C, MSG_SPEED_GetWait());
            MB_UTIL_MSG_SetKeyWaitFlag(p->msg, 1);
            MB_COMM_SYS_SetSyncRange(p->net);
            p->phase = 0x1B;
        }
        if (MB_COMM_SYS_HasKind19(p->net) == 1) {
            a = MB_COMM_SYS_GetOfferCount(p->net);
            b = MB_COMM_SYS_GetOfferExtra(p->net);
            if (a != 0) {
                MB_UTIL_MSG_ClearWindow(p->msg);
                MB_UTIL_MSG_SetWindowLayout(p->msg, 5);
                MB_UTIL_MSG_CreateWordSet(p->msg);
                MB_UTIL_MSG_SetNumberLeft(p->msg, 0, a + b, 3);
                MB_UTIL_MSG_PrintStream(p->msg, 0x16, MSG_SPEED_GetWait());
                MB_UTIL_MSG_SetKeyWaitFlag(p->msg, 1);
                MB_UTIL_MSG_DeleteWordSet(p->msg);
                p->childPhase = 1;
            } else {
                p->childPhase = 0x13;
            }
        }
        break;
    case 1:
        if (MB_UTIL_MSG_IsStreamIdle(p->msg) == 1) {
            MB_UTIL_MSG_OpenYesNoMenu(p->msg, 1);
            p->childPhase = 2;
        }
        break;
    case 2:
        p->answer = MB_UTIL_MSG_ProcessYesNoMenu(p->msg);
        if (p->answer == 1) {
            b = MB_COMM_SYS_GetOfferCount(p->net);
            a = (unsigned short)func_02007774((void *)GAME_DATA_GetBoxManager(p->arg->gameData));
            MB_UTIL_MSG_ClearYesNoMenu(p->msg);
            if ((unsigned int)a < (unsigned int)b) {
                p->notEnoughRoom = 1;
                p->childPhase = 0xD;
            } else {
                p->notEnoughRoom = 0;
                p->childPhase = 3;
            }
        } else if (p->answer == 2) {
            p->childPhase = 0xD;
        }
        break;
    case 3:
        if (MB_COMM_SYS_GetOfferExtra(p->net) != 0) {
            a = MB_COMM_SYS_GetOfferCount(p->net);
            MB_UTIL_MSG_ClearWindow(p->msg);
            MB_UTIL_MSG_SetWindowLayout(p->msg, 1);
            MB_UTIL_MSG_CreateWordSet(p->msg);
            MB_UTIL_MSG_SetNumberLeft(p->msg, 0, a, 3);
            MB_UTIL_MSG_PrintStream(p->msg, 0x24, MSG_SPEED_GetWait());
            MB_UTIL_MSG_SetKeyWaitFlag(p->msg, 1);
            MB_UTIL_MSG_DeleteWordSet(p->msg);
            p->childPhase = 4;
        } else {
            p->childPhase = 5;
        }
        break;
    case 4:
        if (MB_UTIL_MSG_IsStreamIdle(p->msg) == 1)
            p->childPhase = 5;
        break;
    case 5:
        if (MB_COMM_SYS_GetOfferFlagA(p->net) == 1) {
            MB_UTIL_MSG_ClearWindow(p->msg);
            MB_UTIL_MSG_SetWindowLayout(p->msg, 5);
            MB_UTIL_MSG_PrintStream(p->msg, 0x1A, MSG_SPEED_GetWait());
            p->childPhase = 6;
        } else {
            p->childPhase = 0xD;
        }
        break;
    case 6:
        if (MB_UTIL_MSG_IsStreamIdle(p->msg) == 1) {
            MB_UTIL_MSG_OpenYesNoMenu(p->msg, 1);
            p->childPhase = 7;
        }
        break;
    case 7:
        a = MB_UTIL_MSG_ProcessYesNoMenu(p->msg);
        if (a == 1) {
            if (MB_COMM_SYS_GetOfferFlagB(p->net) == 1) {
                MB_UTIL_MSG_PrintStream(p->msg, 0x1B, MSG_SPEED_GetWait());
                p->childPhase = 8;
            } else {
                p->childPhase = 0xD;
            }
        } else if (a == 2) {
            p->childPhase = 0xA;
        }
        break;
    case 8:
        if (MB_UTIL_MSG_IsStreamIdle(p->msg) == 1) {
            MB_UTIL_MSG_OpenYesNoMenu(p->msg, 1);
            p->childPhase = 9;
        }
        break;
    case 9:
        a = MB_UTIL_MSG_ProcessYesNoMenu(p->msg);
        if (a == 1)
            p->childPhase = 0xD;
        else if (a == 2)
            p->childPhase = 0xA;
        break;
    case 10:
        MB_UTIL_MSG_PrintStream(p->msg, 0x1C, MSG_SPEED_GetWait());
        p->childPhase = 0xB;
        break;
    case 11:
        if (MB_UTIL_MSG_IsStreamIdle(p->msg) == 1) {
            MB_UTIL_MSG_OpenYesNoMenu(p->msg, 1);
            p->childPhase = 0xC;
        }
        break;
    case 12:
        a = MB_UTIL_MSG_ProcessYesNoMenu(p->msg);
        if (a == 1) {
            p->answer = 2;
            p->childPhase = 0xD;
        } else if (a == 2) {
            p->childPhase = 5;
        }
        break;
    case 13:
        if (p->answer == 1) {
            if (p->notEnoughRoom == 1)
                a = 2;
            else
                a = 0;
        } else {
            a = 1;
        }
        if (MB_COMM_SYS_SendMessage(p->net, 0xF, a) == 1) {
            if (a == 0) {
                p->childPhase = 0xE;
                MB_UTIL_MSG_ClearWindow(p->msg);
                MB_UTIL_MSG_SetWindowLayout(p->msg, 1);
                MB_UTIL_MSG_PrintQueued(p->msg, 0x19);
                MB_UTIL_MSG_SetTimeIconPending(p->msg, 1);
            } else if (a == 2) {
                p->childPhase = 0x11;
            } else {
                p->childPhase = 0x13;
            }
        }
        break;
    case 14:
        if (MB_COMM_SYS_HasMonsReceived(p->net) == 1) {
            MB_COMM_SYS_RegisterReceivedMons(p);
            p->childPhase = 0xF;
        }
        if (MB_COMM_SYS_HasKind20(p->net) == 1) {
            a = MB_COMM_SYS_GetOfferCount(p->net);
            MB_UTIL_MSG_ClearWindow(p->msg);
            MB_UTIL_MSG_SetWindowLayout(p->msg, 1);
            MB_UTIL_MSG_CreateWordSet(p->msg);
            MB_UTIL_MSG_SetNumberLeft(p->msg, 0, a, 3);
            MB_UTIL_MSG_PrintStream(p->msg, 0x1E, MSG_SPEED_GetWait());
            MB_UTIL_MSG_SetKeyWaitFlag(p->msg, 1);
            MB_UTIL_MSG_DeleteWordSet(p->msg);
            p->childPhase = 0x10;
            p->receivedBonus = 1;
        }
        break;
    case 15:
        if (MB_COMM_SYS_SendMessage(p->net, 0, 0) == 1) {
            MB_COMM_SYS_ClearMonBuffer(p->net);
            p->childPhase = 0xE;
        }
        break;
    case 16:
        if (MB_UTIL_MSG_IsStreamIdle(p->msg) == 1)
            p->childPhase = 0x13;
        break;
    case 17:
        MB_UTIL_MSG_ClearWindow(p->msg);
        MB_UTIL_MSG_SetWindowLayout(p->msg, 5);
        MB_UTIL_MSG_PrintStream(p->msg, 0x18, MSG_SPEED_GetWait());
        p->childPhase = 0x12;
        break;
    case 18:
        if (MB_UTIL_MSG_IsStreamIdle(p->msg) == 1)
            p->childPhase = 0x13;
        break;
    case 19:
        if (MB_COMM_SYS_HasKind21(p->net) == 1) {
            if (MB_COMM_SYS_GetKind21Value(p->net) == 1) {
                MB_UTIL_MSG_ClearWindow(p->msg);
                MB_UTIL_MSG_SetWindowLayout(p->msg, 5);
                MB_UTIL_MSG_PrintStream(p->msg, 0x1F, MSG_SPEED_GetWait());
                p->childPhase = 0x14;
            } else {
                p->childPhase = 0x19;
            }
        }
        break;
    case 20:
        if (MB_UTIL_MSG_IsStreamIdle(p->msg) == 1) {
            p->childPhase = 0x15;
            MB_UTIL_MSG_OpenYesNoMenu(p->msg, 1);
        }
        break;
    case 21:
        a = MB_UTIL_MSG_ProcessYesNoMenu(p->msg);
        if (a == 1 || a == 2) {
            saveTrainerKey = GAME_DATA_GetMyItem(p->arg->gameData);
            ownerData = GAME_DATA_GetMyStatus(p->arg->gameData);
            miscSave = GAME_DATA_GetMiscSave(p->arg->gameData);
            if (a == 1 && FIELD_G3D_MAP_CheckBeaconTrainerKey(miscSave, 0, ownerData) == 1) {
                p->answer = 2;
                p->childPhase = 0x16;
                MB_UTIL_MSG_ClearWindow(p->msg);
                MB_UTIL_MSG_SetWindowLayout(p->msg, 1);
                MB_UTIL_MSG_PrintStream(p->msg, 0x25, MSG_SPEED_GetWait());
                MB_UTIL_MSG_SetKeyWaitFlag(p->msg, 1);
            } else {
                p->answer = a;
                p->childPhase = 0x17;
            }
        }
        break;
    case 22:
        if (MB_UTIL_MSG_IsStreamIdle(p->msg) == 1)
            p->childPhase = 0x17;
        break;
    case 23:
        a = 1;
        if (p->answer != 1)
            a = 0;
        if (MB_COMM_SYS_SendMessage(p->net, 0x10, a) == 1) {
            if (a == 1) {
                saveTrainerKey = GAME_DATA_GetMyItem(p->arg->gameData);
                ownerData = GAME_DATA_GetMyStatus(p->arg->gameData);
                miscSave = GAME_DATA_GetMiscSave(p->arg->gameData);
                MB_UTIL_MSG_ClearWindow(p->msg);
                MB_UTIL_MSG_SetWindowLayout(p->msg, 1);
                MB_UTIL_MSG_PrintStream(p->msg, 0x21, MSG_SPEED_GetWait());
                MB_UTIL_MSG_SetKeyWaitFlag(p->msg, 1);
                FIELD_G3D_MAP_StoreBeaconTrainerKey(miscSave, 0, ownerData);
                func_02007E50(saveTrainerKey, 0x215, 1, p->heapId);
                p->gotTrainerKey = 1;
                p->childPhase = 0x18;
            } else {
                p->childPhase = 0x19;
            }
        }
        break;
    case 24:
        if (MB_UTIL_MSG_IsStreamIdle(p->msg) == 1)
            p->childPhase = 0x19;
        break;
    case 25:
        if (p->receivedBonus == 1 || p->gotTrainerKey == 1) {
            if (MB_COMM_SYS_SendMessage(p->net, 0x11, 0) == 1)
                p->phase = 0x13;
        } else {
            if (MB_COMM_SYS_GetOfferCount(p->net) == 0 && MB_COMM_SYS_GetKind21Value(p->net) == 0) {
                MB_UTIL_MSG_ClearWindow(p->msg);
                MB_UTIL_MSG_SetWindowLayout(p->msg, 1);
                MB_UTIL_MSG_PrintStream(p->msg, 0x28, MSG_SPEED_GetWait());
                MB_UTIL_MSG_SetKeyWaitFlag(p->msg, 1);
            }
            p->phase = 0x1B;
        }
        break;
    }
}

/* Visibility hook: hides both text planes, then shows the one this mode uses. */
int MB_COMM_SYS_ShowTextPlane(void)
{
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    func_02040588(gMbParentUi.textOnSubScreen == 1 ? 4 : 2, 1);
    return 1;
}

/* Proc entry: creates the heap and work, loads or creates the argument, then runs init. */
int MB_COMM_SYS_ProcInit(void *task, void *arg, MbParentArg *argument)
{
    MbCommSysWork *p;

    if (!GFL_NET_IsSessionNull())
        return 0;
    GFL_HEAP_CreateChildHeap(1, 93, 0x130000);
    p = PROCSYS_AllocProcWork(task, 188, 93);
    if (!argument) {
        argument = func_02030734(93, 8, 0, d_021F6E0C, 2788);
        if (KEY_GetCont() & 256) {
            argument->standalone = 1;
        } else {
            argument->standalone = 0;
            argument->gameData = GAME_DATA_Create(93);
        }
    }
    if (argument->standalone == 1)
        argument->gameData = GAME_DATA_Create(93);
    p->heapId = 93;
    p->arg = argument;
    p->errorScreenRequested = 0;
    p->wirelessFailed = 0;
    p->wasSaving = 0;
    MB_COMM_SYS_Init(p);
    return 1;
}

/*
 * extent: two zero padding bytes follow the epilogue.
 */
/* Proc end: runs exit, frees the game data when owned, shows the net error screens if needed. */
int MB_COMM_SYS_ProcExit(void *task, int unused, int keep, MbCommSysWork *p)
{
    int standalone;
    u32 errorRequested;
    u32 wasSaving;
    u32 wirelessFailed;

    errorRequested = p->errorScreenRequested;
    standalone = 0;
    wasSaving = p->wasSaving;
    wirelessFailed = p->wirelessFailed;
    if (p->arg->standalone == 1)
        standalone = 1;
    MB_COMM_SYS_Exit(p);
    if (!keep) {
        GAME_DATA_Delete(p->arg->gameData);
        func_020307B0(p->arg);
    } else if (p->arg->standalone == 1) {
        GAME_DATA_Delete(p->arg->gameData);
        func_020307B0(p->arg);
    }
    func_020315D4(task);
    GFL_HEAP_DeleteChecked(93);
    if (errorRequested == 1) {
        if (standalone) {
            if (wasSaving == 1 || func_0200FB24() == 1) {
                func_0200FBB0();
                GFL_NET_ERR_ShowScreen(1);
            } else {
                GFL_NET_ERR_ShowScreen(0);
            }
        } else if (wasSaving == 1) {
            func_0200FBB0();
            GFL_NET_ERR_ShowScreen(1);
        }
    }
    if (wirelessFailed == 1)
        GFL_NET_ERR_ShowSimpleScreen();
    if (standalone == 1)
        UI_SoftReset(0);
    return 1;
}

/* Proc update: runs the main loop and requests the net error screen when an error shows up. */
int MB_COMM_SYS_ProcMain(int a, int b, int c, MbCommSysWork *p)
{
    if (MB_COMM_SYS_Main(p) == 1)
        return 1;
    if (func_0200FB24() != 0 && p->errorScreenRequested == 0) {
        GFL_NET_ERR_RequestScreen();
        p->errorScreenRequested = 1;
    }
    return 0;
}

/* Initializes the MB parent: owner info, MB work buffer, comm params and the event callback. */
void MB_PARENT_SYS_Init(int a, int b)
{
    OwnerInfo owner;
    MBUser userInfo;
    u8 zeroBuffer[20];
    MbChildStageMasks *zero;

    OS_GetOwnerInfoEx(&owner);
    userInfo.favoriteColour = owner.favoriteColor;
    userInfo.nameLength = owner.nicknameLength;
    MI_CpuCopy8(owner.nickname, userInfo.name, owner.nicknameLength * 2);
    userInfo.playerNo = 0;
    zero = (MbChildStageMasks *)zeroBuffer;
    zero->words[0] = 0;
    zero->words[1] = 0;
    zero->words[2] = 0;
    zero->words[3] = 0;
    zero->words[4] = 0;
    gMbChildStageMasks = *zero;
    gMbParentSys.mbWork = GFL_NET_AllocAligned(93, 45312, d_021F6E1C, 158);
    if (func_021F5904(gMbParentSys.mbWork, &userInfo, a, b, 1))
        func_02034714(d_021F6E24, 0, d_021F6E24);
    MB_SetParentCommParam(256, 1);
    func_021F1B3C(MB_PARENT_SYS_EventCallback);
    MB_PARENT_SYS_SetState(1);
}

/* Registers the game: starts recruiting on the channel, loads the file image. */
void MB_PARENT_SYS_Register(MbRegistryBlock *registry, int channel)
{
    MB_PARENT_SYS_SetState(2);
    if (func_021F5E7C(channel)) {
        MB_PARENT_SYS_SetState(7);
        return;
    }
    gMbParentSys.registered = 1;
    if (!MB_PARENT_SYS_LoadFileImage(registry))
        func_02034714(d_021F6E24, 0, d_021F6E24);
}

/* Opens the ROM file named by the registry, reads its header and image into the file buffer. */
int MB_PARENT_SYS_LoadFileImage(MbRegistryBlock *registry)
{
    File file;
    File *fp;
    int result;

    result = 0;
    if (!registry->romPath) {
        fp = 0;
    } else {
        fp = &file;
        FS_InitFile(fp);
        if (!FS_OpenFile(fp, registry->romPath))
            return 0;
    }
    if (MB_GetSegmentLength(fp)) {
        gMbParentSys.fileBuffer = func_02030734(93, 65536, 1, d_021F6E1C, 287);
        if (gMbParentSys.fileBuffer) {
            if (func_021F2FA0(fp, gMbParentSys.fileBuffer, 65536)) {
                if (func_021F3544(registry, gMbParentSys.fileBuffer))
                    result = 1;
            }
            if (!result)
                func_020307B0(gMbParentSys.fileBuffer);
        }
    }
    if (fp == &file)
        FS_CloseFile(&file);
    return result;
}

/* Clears one child from every state mask under an interrupt lock. */
static inline void MbCommSys_ClearChild(u16 aid)
{
    u16 mask;
    u32 irq;

    mask = ~(1 << aid);
    irq = OS_DisableInterrupts();
    gMbParentSys.connectedMask &= mask;
    gMbParentSys.requestedMask &= mask;
    gMbParentSys.waitToSendMask &= mask;
    gMbParentSys.sendingMask &= mask;
    gMbParentSys.sendCompleteMask &= mask;
    gMbParentSys.bootStartableMask &= mask;
    OS_RestoreInterrupts(irq);
}

/* Child asked to download: drops it when the MB library refuses stage 1. */
void MB_PARENT_SYS_CheckRequest(u16 aid)
{
    if (!MB_CommResponseRequest(aid, 1)) {
        MbCommSys_ClearChild(aid);
        MB_DisconnectChild(aid);
    }
}

/* Child is waiting to send: on refusal drops it, otherwise moves it back to connected only. */
void MB_PARENT_SYS_RejectRequest(u16 aid)
{
    u32 irq;

    if (!MB_CommResponseRequest(aid, 0)) {
        MbCommSys_ClearChild(aid);
        MB_DisconnectChild(aid);
    } else {
        irq = OS_DisableInterrupts();
        gMbParentSys.requestedMask &= (u16)~(1 << aid);
        gMbParentSys.connectedMask &= (u16)~(1 << aid);
        OS_RestoreInterrupts(irq);
    }
}

/* Child moved to sending: on refusal drops it, otherwise moves it from waitToSend to sending. */
void MB_PARENT_SYS_StartSending(u16 aid)
{
    u16 mask;
    u32 irq;
    u16 bit;

    if (!MB_CommResponseRequest(aid, 2)) {
        MbCommSys_ClearChild(aid);
        MB_DisconnectChild(aid);
    } else {
        irq = OS_DisableInterrupts();
        mask = ~(1 << aid);
        bit = 1 << aid;
        gMbParentSys.waitToSendMask &= mask;
        gMbParentSys.sendingMask |= bit;
        OS_RestoreInterrupts(irq);
    }
}

/* Returns 1 when every connected child (AID 1 to 15) is bootable and at least one is connected. */
int MB_PARENT_SYS_AllBootable(void)
{
    u16 aid;

    if (!gMbParentSys.connectedMask)
        return 0;
    for (aid = 1; aid < 16; aid++) {
        if (gMbParentSys.connectedMask & (1 << aid)) {
            if (!MB_CommIsBootable(aid))
                return 0;
        }
    }
    return 1;
}

/* Starts the boot: drops children that cannot boot, fails when none are left. */
void MB_PARENT_SYS_StartBoot(void)
{
    u32 active;
    u16 aid;
    int bit;

    active = 0;
    for (aid = 1; aid < 16; aid++) {
        bit = 1 << aid;
        if (gMbParentSys.sendCompleteMask & bit) {
            if (!MB_CommResponseRequest(aid, 3)) {
                MbCommSys_ClearChild(aid);
                MB_DisconnectChild(aid);
            } else {
                active |= (u16)bit;
            }
        }
    }
    if (!active) {
        MB_PARENT_SYS_SetState(7);
        return;
    }
    MB_PARENT_SYS_SetState(4);
}

/* Cancels recruiting and ends the MB session when it was registered. */
void MB_PARENT_SYS_Cancel(void)
{
    MB_PARENT_SYS_SetState(6);
    if (gMbParentSys.registered == 1) {
        gMbParentSys.registered = 0;
        func_021F5F74();
    }
}

/* Ends the MB session when starting and every connected child can boot. */
void MB_PARENT_SYS_EndIfAllBootable(void)
{
    if (gMbParentSys.state == 4 && gMbParentSys.connectedMask == gMbParentSys.bootStartableMask && gMbParentSys.registered == 1) {
        gMbParentSys.registered = 0;
        func_021F5F74();
    }
}

/* MB parent event callback: updates the masks and the child table for one child event. */
void MB_PARENT_SYS_EventCallback(u16 aid, u32 event, MbChildEvent *info)
{
    u32 irq;
    u16 mask;
    void *userInfo;
    u32 offset;

    switch (event) {
    case 2:
        if (MB_PARENT_SYS_GetState() != 2)
            break;
        irq = OS_DisableInterrupts();
        gMbParentSys.connectedMask |= (u16)(1 << aid);
        OS_RestoreInterrupts(irq);
        offset = 30 * (aid - 1);
        *(u8 *)((u32)d_021F6EDE + offset) = info->mac[0];
        *(u8 *)((u32)d_021F6EDF + offset) = info->mac[1];
        *(u8 *)((u32)d_021F6EE0 + offset) = info->mac[2];
        *(u8 *)((u32)d_021F6EE1 + offset) = info->mac[3];
        *(u8 *)((u32)d_021F6EE2 + offset) = info->mac[4];
        *(u8 *)((u32)d_021F6EE3 + offset) = info->mac[5];
        *(u16 *)((u32)d_021F6EE4 + offset) = aid;
        break;
    case 3:
        if (MB_PARENT_SYS_GetChildStage(aid) == 6)
            break;
        mask = ~(1 << aid);
        irq = OS_DisableInterrupts();
        gMbParentSys.connectedMask &= mask;
        gMbParentSys.requestedMask &= mask;
        gMbParentSys.waitToSendMask &= mask;
        gMbParentSys.sendingMask &= mask;
        gMbParentSys.sendCompleteMask &= mask;
        gMbParentSys.bootStartableMask &= mask;
        OS_RestoreInterrupts(irq);
        MB_PARENT_SYS_EndIfAllBootable();
        break;
    case 10:
        if (MB_PARENT_SYS_GetState() != 2) {
            MB_PARENT_SYS_RejectRequest(aid);
            break;
        }
        gMbParentSys.requestedMask |= (u16)(1 << aid);
        MB_PARENT_SYS_CheckRequest(aid);
        userInfo = MB_CommGetChildUser(aid);
        if (userInfo)
            MI_CpuCopy8(userInfo, (void *)((u32)gMbChildEntries + 30 * (aid - 1)), 22);
        break;
    case 14:
        gMbParentSys.requestedMask &= (u16)~(1 << aid);
        gMbParentSys.waitToSendMask |= (u16)(1 << aid);
        MB_PARENT_SYS_StartSending(aid);
        break;
    case 7:
        gMbParentSys.sendingMask &= (u16)~(1 << aid);
        gMbParentSys.sendCompleteMask |= (u16)(1 << aid);
        break;
    case 9:
        gMbParentSys.sendCompleteMask &= (u16)~(1 << aid);
        gMbParentSys.bootStartableMask |= (u16)(1 << aid);
        MB_PARENT_SYS_EndIfAllBootable();
        break;
    case 12:
        if (MB_PARENT_SYS_GetState() == 4)
            MB_PARENT_SYS_SetState(5);
        else
            MB_PARENT_SYS_SetState(0);
        if (gMbParentSys.fileBuffer) {
            func_020307B0(gMbParentSys.fileBuffer);
            gMbParentSys.fileBuffer = 0;
        }
        if (gMbParentSys.mbWork) {
            GFL_NET_FreeAligned(gMbParentSys.mbWork);
            gMbParentSys.mbWork = 0;
        }
        break;
    case 13:
        switch (info->errorCode) {
        case 1:
        case 2:
        case 9:
            MB_PARENT_SYS_SetState(7);
            break;
        case 8:
            break;
        }
        break;
    case 1:
    case 4:
    case 5:
    case 6:
    case 8:
    case 11:
        break;
    case 0:
    default:
        func_02034714(d_021F6E24, 0, d_021F6E24);
        break;
    }
}

/* Sets the parent state. */
void MB_PARENT_SYS_SetState(u16 state)
{
    gMbParentSys.state = state;
}

/* Returns the parent state. */
u16 MB_PARENT_SYS_GetState(void)
{
    return gMbParentSys.state;
}

/* Returns the stage of a connected child (1 to 6), or 0 when it is not connected. */
int MB_PARENT_SYS_GetChildStage(u16 aid)
{
    u32 irq;
    MbChildStageMasks snap;
    u16 bit;

    bit = 1 << aid;
    irq = OS_DisableInterrupts();
    if (!(gMbParentSys.connectedMask & bit)) {
        OS_RestoreInterrupts(irq);
        return 0;
    }
    MI_CpuCopy8(((u8 *)&gMbChildStageMasks), &snap, 20);
    OS_RestoreInterrupts(irq);
    if (snap.stageMask[2] & bit)
        return 2;
    if (snap.stageMask[3] & bit)
        return 3;
    if (snap.stageMask[4] & bit)
        return 4;
    if (snap.stageMask[5] & bit)
        return 5;
    if (snap.stageMask[6] & bit)
        return 6;
    return 1;
}

/* Frees the file buffer and the MB work buffer. */
void MB_PARENT_SYS_FreeBuffers(void)
{
    if (gMbParentSys.fileBuffer) {
        func_020307B0(gMbParentSys.fileBuffer);
        gMbParentSys.fileBuffer = 0;
    }
    if (gMbParentSys.mbWork) {
        GFL_NET_FreeAligned(gMbParentSys.mbWork);
        gMbParentSys.mbWork = 0;
    }
}

/* Returns whether the file is registered with the MB library. */
u32 MB_PARENT_SYS_IsRegistered(void)
{
    return gMbParentSys.registered;
}

/* Allocates the link state and its receive buffer for six box params. */
MbNetState *MB_COMM_SYS_CreateNetState(u16 heapId)
{
    MbNetState *net;

    net = func_02030734(heapId, 40, 1, d_021F6E28, 159);
    net->heapId = heapId;
    net->netStage = 0;
    net->headerBuffer = 0;
    net->flagsA.bits.lowerDataActive = 0;
    net->commStage = 0;
    net->nextCommStage = 0;
    net->monBuffer = func_02030734(net->heapId, 6 * POKE_TOOL_GetBoxParamSize() + 4, 1, d_021F6E28, 169);
    return net;
}

/* Frees the link state and its buffers, shutting the lower data layer down when active. */
void MB_COMM_SYS_DeleteNetState(MbNetState *net)
{
    if (net->headerBuffer)
        func_020307B0(net->headerBuffer);
    if (net->flagsA.bits.lowerDataActive == 1)
        GFL_NET_LOWER_DATA_Exit();
    func_020307B0(net->monBuffer);
    func_020307B0(net);
}

/*
 * extent: two zero padding bytes follow the epilogue.
 */
/* Steps the network bring-up and announces the next stage to the peer when it changed. */
void MB_COMM_SYS_UpdateNetState(MbNetState *net)
{
    switch (net->netStage) {
    case 0:
        break;
    case 1:
        if (GFL_NET_HANDLE_CheckNegotiation() == 1)
            net->netStage = 2;
        break;
    case 2:
        if (GFL_NET_HANDLE_IsNegotiationDone(GFL_NET_HANDLE_GetCurrentHandle()) == 1)
            net->netStage = 3;
        break;
    case 3:
        if (GFL_NET_IsHandleReady(GFL_NET_HANDLE_GetCurrentHandle()) == 1) {
            net->netStage = 6;
            GFL_NET_SetLoginOption(1);
        }
        break;
    case 4:
        if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 64, 4) == 1) {
            net->netStage = 5;
            GFL_NET_SetLoginOption(0);
        }
        break;
    case 5:
    case 6:
    default:
        break;
    }
    if (net->commStage != net->nextCommStage && net->nextCommStage != 0) {
        if (MB_COMM_SYS_SendMessage(net, 10, net->nextCommStage) == 1)
            net->commStage = net->nextCommStage;
    }
}

/*
 * evidence: 112-byte request copy, heap halfword at54, and own matched
 * 0203CBAC/0203E5F8 bodies establish all three/two arguments. The third
 * CBAC input carries the unchanged pointer word through its u32 parameter.
 * Halfword flag fields reproduce every original read/store without volatile.
 */
/* Starts the net session and resets every message flag of the link state. */
void MB_COMM_SYS_StartNetSession(MbNetState *net)
{
    Request request = sMbCommSessionRequest;

    request.heapId = net->heapId;
    GFL_NET_StartSession(&request, 0, (u32)net);
    net->offer = 0;
    net->flagsA.bits.headerReceived = 0;
    net->childSaveCount = 0;
    net->flagsA.bits.rxKind11 = 0;
    net->count = 0;
    net->flagsA.bits.rxKind12 = 0;
    net->flagsA.bits.rxKind13 = 0;
    net->flagsA.bits.rxKind14 = 0;
    net->flagsA.bits.rxKind1 = 0;
    net->flagsA.bits.rxKind2 = 0;
    net->flagsA.bits.rxKind3 = 0;
    net->flagsA.bits.rxKind4 = 0;
    net->flagsA.bits.lowerDataActive = 1;
    net->flagsA.bits.rxKind19 = 0;
    net->flagsA.bits.rxKind15 = 0;
    net->flagsA.bits.rxKind20 = 0;
    net->flagsB.bits.rxKind21 = 0;
    net->flagsB.bits.kind21Value = 0;
    net->flagsB.bits.rxKind16 = 0;
    net->flagsB.bits.kind16Value = 0;
    net->flagsB.bits.rxKind17 = 0;
    net->flagsB.bits.rxKind18 = 0;
    net->result = 0;
    GFL_NET_LOWER_DATA_Init(net->heapId, 0);
}

/* Shuts the net session and the lower data layer down. */
void MB_COMM_SYS_StopNetSession(MbNetState *net)
{
    GFL_NET_Exit(0);
    GFL_NET_LOWER_DATA_Exit();
    net->flagsA.bits.lowerDataActive = 0;
    net->netStage = 0;
}

/* Returns the net run state. */
int MB_COMM_SYS_GetNetRunState(MbNetState *net)
{
    return GFL_NET_GetRunState();
}

/* Returns whether no net session exists. */
int MB_COMM_SYS_IsNetSessionNull(MbNetState *net)
{
    return GFL_NET_IsSessionNull();
}

/* Starts the net layer by type and enters stage 1. */
void MB_COMM_SYS_StartNet(MbNetState *net)
{
    GFL_NET_StartByNetType();
    net->netStage = 1;
}

/* Sets the timing sync range of the current handle and enters stage 4. */
void MB_COMM_SYS_SetSyncRange(MbNetState *net)
{
    int handle = (int)GFL_NET_HANDLE_GetCurrentHandle();

    GFL_NET_HANDLE_SetTimingSyncRange((void *)handle, 0x40, 4);
    net->netStage = 4;
}

/* Returns whether the sync range is set (stage 5). */
int MB_COMM_SYS_IsSyncDone(MbNetState *net)
{
    return net->netStage == 5;
}

/* Returns whether login is complete (stage 6 or later). */
int MB_COMM_SYS_IsLoginDone(MbNetState *net)
{
    return net->netStage >= 6;
}

/* Returns the last announced or received stage. */
int MB_COMM_SYS_GetCommStage(MbNetState *net)
{
    return net->commStage;
}

/* Clears the per-round message flags and the count. */
void MB_COMM_SYS_ClearRoundFlags(MbNetState *net)
{
    unsigned short *flags = &net->flagsA.raw;

    *flags = *flags & ~(unsigned short)2;
    *flags = *flags & ~(unsigned short)4;
    *flags = *flags & ~(unsigned short)8;
    *flags = *flags & ~(unsigned short)0x10;
    *flags = *flags & ~(unsigned short)0x20;
    *flags = *flags & ~(unsigned short)0x40;
    *flags = *flags & ~(unsigned short)0x80;
    *flags = *flags & ~0x100;
    *flags = *flags & ~0x200;
    *flags = *flags & ~0x400;
    *flags = *flags & ~0x1000;
    net->count = 0;
}

/*
 * leaf: parent cleared all eight original Thumb starts; 60 bytes stop
 * before existing 021F1110. Both 10DC and10E4 read bit4 in the ROM.
 */
int MB_COMM_SYS_HasKind11(MbNetState *net)
{
    return net->flagsA.bits.rxKind11;
}

int MB_COMM_SYS_HasKind12(MbNetState *net)
{
    return net->flagsA.bits.rxKind12;
}

int MB_COMM_SYS_HasKind12Again(MbNetState *net)
{
    return net->flagsA.bits.rxKind12;
}

int MB_COMM_SYS_HasKind14(MbNetState *net)
{
    return net->flagsA.bits.rxKind14;
}

int MB_COMM_SYS_HasKind1(MbNetState *net)
{
    return net->flagsA.bits.rxKind1;
}

int MB_COMM_SYS_HasKind2(MbNetState *net)
{
    return net->flagsA.bits.rxKind2;
}

int MB_COMM_SYS_HasKind4(MbNetState *net)
{
    return net->flagsA.bits.rxKind4;
}

/* Returns the value of the last message of kinds 2 and 3. */
int MB_COMM_SYS_GetCount(MbNetState *net)
{
    return net->count;
}

int MB_COMM_SYS_HasKind19(MbNetState *net)
{
    return net->flagsA.bits.rxKind19;
}

/* Returns the offered mon count (low half of the offer). */
unsigned short MB_COMM_SYS_GetOfferCount(MbNetState *net)
{
    return net->offer;
}

/* Returns the extra count of the offer. */
unsigned short MB_COMM_SYS_GetOfferExtra(MbNetState *net)
{
    return (net->offer & MB_OFFER_EXTRA_MASK) >> MB_OFFER_EXTRA_SHIFT;
}

int MB_COMM_SYS_GetOfferFlagA(MbNetState *net)
{
    if (net->offer & MB_OFFER_FLAG_A)
        return 1;
    return 0;
}

int MB_COMM_SYS_GetOfferFlagB(MbNetState *net)
{
    if (net->offer & MB_OFFER_FLAG_B)
        return 1;
    return 0;
}

int MB_COMM_SYS_HasKind20(MbNetState *net)
{
    return net->flagsA.bits.rxKind20;
}

int MB_COMM_SYS_HasKind21(MbNetState *net)
{
    return net->flagsB.bits.rxKind21;
}

int MB_COMM_SYS_GetKind21Value(MbNetState *net)
{
    return net->flagsB.bits.kind21Value;
}

/* Queues the payload for sending on the lower data layer. */
void MB_COMM_SYS_QueuePayload(int a, int payload, int payloadSize)
{
    GFL_NET_LOWER_DATA_SetSendData(payload, payloadSize, 2, 1);
}

/* Clears the receive buffer and its six box params, and the mons-received and kind 0 flags. */
void MB_COMM_SYS_ClearMonBuffer(MbNetState *net)
{
    MbMonList *list;
    unsigned char i;

    list = (MbMonList *)net->monBuffer;
    list->count = 0;
    list->maxSeen = 0;
    for (i = 0; i < 6; i++) {
        POKE_TOOL_ClearBoxParam(net->monBuffer + i * POKE_TOOL_GetBoxParamSize() + 4);
    }
    net->flagsA.bits.monsReceived = 0;
    net->flagsA.bits.rxKind0 = 0;
}

int MB_COMM_SYS_HasMonsReceived(MbNetState *net)
{
    return net->flagsA.bits.monsReceived;
}

/* Returns how many mons the receive buffer holds. */
u8 MB_COMM_SYS_GetMonCount(MbNetState *net)
{
    return *net->monBuffer;
}

/* Returns the box param of mon i in the receive buffer. */
void *MB_COMM_SYS_GetMon(MbNetState *net, int i)
{
    return net->monBuffer + i * POKE_TOOL_GetBoxParamSize() + 4;
}

/* Returns the second halfword of the receive buffer. */
int MB_COMM_SYS_GetMaxSeen(MbNetState *net)
{
    return ((MbMonList *)net->monBuffer)->maxSeen;
}

int MB_COMM_SYS_HasKind0(MbNetState *net)
{
    return net->flagsA.bits.rxKind0;
}

/* Sends a message of the given kind and value to the parent or current handle. */
int MB_COMM_SYS_SendMessage(void *net, unsigned char kind, unsigned int value)
{
    MbCommMsg msg;
    void *handle;

    if (GFL_NET_IsParentAid() == 1)
        handle = GFL_NET_HANDLE_GetNetHandle(0xFF);
    else
        handle = GFL_NET_HANDLE_GetCurrentHandle();
    msg.kind = kind;
    msg.value = value;
    return GFL_NET_SendData((u32)handle, 0xFF, 0x400, 8, (u32)(&msg), 1, 0, 0);
}

/* Receive handler for messages on channel 0x400: records the kind and its value. */
void MB_COMM_SYS_OnMessage(int a, int b, MbCommMsg *msg, MbNetState *net)
{
    switch (msg->kind) {
    case 0:
        net->flagsA.raw |= MB_FLAGA_KIND0;
        break;
    case 1:
        net->flagsA.raw |= MB_FLAGA_KIND1;
        break;
    case 2:
        net->flagsA.raw |= MB_FLAGA_KIND2;
        net->count = *(u32 *)msg;
        break;
    case 3:
        net->flagsA.raw |= MB_FLAGA_KIND3;
        net->count = *(u32 *)msg;
        break;
    case 4:
        net->flagsA.raw |= MB_FLAGA_KIND4;
        break;
    case 5:
        net->childSaveCount = *(u32 *)msg;
        net->flagsA.raw |= MB_FLAGA_KIND5;
        break;
    case 10:
        net->commStage = *(u32 *)msg;
        break;
    case 11:
        net->flagsA.raw |= MB_FLAGA_KIND11;
        break;
    case 12:
        net->flagsA.raw |= MB_FLAGA_KIND12;
        break;
    case 13:
        net->flagsA.raw |= MB_FLAGA_KIND13;
        break;
    case 14:
        net->flagsA.raw |= MB_FLAGA_KIND14;
        break;
    case 15:
        net->flagsA.raw |= MB_FLAGA_KIND15;
        net->result = *(u32 *)msg;
        break;
    case 16:
        net->flagsB.raw |= MB_FLAGB_KIND16;
        net->flagsB.raw = (net->flagsB.raw & ~MB_FLAGB_KIND16_VALUE) | (((u16)*(u32 *)msg & 1) << 3);
        break;
    case 17:
        net->flagsB.raw |= MB_FLAGB_KIND17;
        break;
    case 18:
        net->flagsB.raw |= MB_FLAGB_KIND18;
        break;
    case 19:
        net->flagsA.raw |= MB_FLAGA_KIND19;
        net->offer = *(u32 *)msg;
        break;
    case 20:
        net->flagsA.raw |= MB_FLAGA_KIND20;
        break;
    case 21:
        net->flagsB.raw = (net->flagsB.raw & ~MB_FLAGB_KIND21) | MB_FLAGB_KIND21;
        net->flagsB.raw = (net->flagsB.raw & ~MB_FLAGB_KIND21_VALUE) | (((u16)*(u32 *)msg & 1) << 1);
        break;
    }
}

/* Sends the payload header to the first peer once at least two nodes negotiated. */
int MB_COMM_SYS_SendHeader(void *net, MbPayloadHeader *header)
{
    void *handle;

    handle = GFL_NET_HANDLE_GetNetHandle(255);
    if (GFL_NET_GetNegotiationNum() < 2)
        return 0;
    return GFL_NET_SendData((u32)handle, 1, 0x401, 8, (u32)header, 1, 0, 1);
}

/* Receive callback: the header message arrived. */
void MB_COMM_SYS_OnHeaderReceived(int a, int b, int c, MbNetState *net)
{
    net->flagsA.bits.headerReceived = 1;
}

/* Receive buffer getter for the 8 byte header message, allocated on first use. */
void *MB_COMM_SYS_GetHeaderBuffer(void *a, MbNetState *net)
{
    if (!net->headerBuffer)
        net->headerBuffer = func_02030734(net->heapId, 8, 1, d_021F6E28, 862);
    return net->headerBuffer;
}

/* Receive callback: the mon data arrived. */
void MB_COMM_SYS_OnMonsReceived(int a, int b, int c, MbNetState *net)
{
    net->flagsA.bits.monsReceived = 1;
}

/* Receive buffer getter for the mon data. */
void *MB_COMM_SYS_GetMonBuffer(int a, MbNetState *net)
{
    return net->monBuffer;
}

int *MB_COMM_SYS_GetChildDataPtr(void)
{
    return d_021F6EE8;
}

int MB_COMM_SYS_GetMemberCount(void)
{
    return 2;
}
