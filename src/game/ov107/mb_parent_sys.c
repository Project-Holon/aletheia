/*
 * file:     mb_parent_sys.c
 * unit:     yes
 * function: MB_COMM_SYS_Init, MB_COMM_SYS_Exit, MB_COMM_SYS_Main, MB_COMM_SYS_VBlank, MB_COMM_SYS_VBlankRefreshBg, MB_COMM_SYS_VBlankRefreshBgStandalone, MB_COMM_SYS_InitDisplay, MB_COMM_SYS_ExitDisplay, MB_COMM_SYS_InitBgLayer, MB_COMM_SYS_LoadGraphics, MB_COMM_SYS_DrawTitle, MB_COMM_SYS_BuildGameStrings, MB_COMM_SYS_FreeGameStrings, MB_COMM_SYS_MainWireless, MB_COMM_SYS_StartParent, MB_COMM_SYS_MainRecruit, MB_COMM_SYS_WmEndCallback, MB_COMM_SYS_UpdateSaveState, MB_COMM_SYS_ResetHook, MB_COMM_SYS_FinishReceive, MB_COMM_SYS_RegisterReceivedMons, MB_COMM_SYS_NoOp, MB_COMM_SYS_MainSave, MB_COMM_SYS_MainChildFlow, MB_COMM_SYS_ShowTextPlane, MB_COMM_SYS_ProcInit, MB_COMM_SYS_ProcExit, MB_COMM_SYS_ProcMain
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
 *   MISC_GetBlock 0x0200C0F0 thumb
 *   MISC_SetRank 0x0200C1B0 thumb
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   GFL_USE_SetVBlankHook 0x02005654 thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   UI_SetKeepAwakeFlagsGlobal 0x02034F84 arm
 *   gMbParentUi 0x021F6EA0 data a4
 *   UI_ClearKeepAwakeFlagsGlobal 0x02034FB8 arm
 *   TCB_DeleteTask 0x02030EAC arm
 *   GFL_USE_ClearVBlankHook 0x0200566C thumb
 *   GFL_NET_WM_ICON_EasyEnd 0x020370C8 arm
 *   GFL_USE_CancelChangeAndStopBgm 0x02005D28 thumb
 *   GAME_DATA_GetEventWork 0x0201296C thumb
 *   ZONEDATA_GetEventWorkAddress 0x020143CC thumb
 *   GFL_HEAP_Free 0x020307B0 arm
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
 *   GFL_NET_RefreshWmIconAtTopRight 0x0203D34C arm
 *   MSGDATA_GetLanguage 0x020461E4 arm
 *   FS_InitFile 0x020788AC arm
 *   FS_OpenFile 0x02078C18 arm
 *   FS_SeekFile 0x02078B44 arm
 *   FS_GetLength 0x02078C28 arm
 *   FS_ReadFile 0x02078B70 arm
 *   FS_CloseFile 0x02078A80 arm
 *   GF_PANIC_Fail 0x02034714 arm
 *   GF_PANIC_FailPrintf 0x02034734 arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   GAME_DATA_IsSaving 0x02012E40 thumb
 *   GAME_DATA_SaveCancel 0x02012E08 thumb
 *   WIPE_SYS_Start 0x0202208C thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   APP_ENV_IsWirelessAvailable 0x0202EB44 thumb
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   MISC_GetBestScore 0x0200C184 thumb
 *   GFL_USE_GetArcPath 0x0200575C thumb
 *   GAME_DATA_GetTrainerRecord 0x02012F2C thumb
 *   RECORD_AddOne 0x02008DF0 thumb
 *   GAME_DATA_GetBoxManager 0x0201293C thumb
 *   BOX_SAVEDATA_CountFreeSlots 0x02007774 thumb
 *   d_021F6E08 0x021F6E08 data a4
 *   d_021F6E0C 0x021F6E0C data a4
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
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
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
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
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   MSGDATA_AllocString 0x02045EC0 arm
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
 *   MYSTATUS_GetIdLow16 0x02008534 thumb
 *   MB_UTIL_MSG_SetNumberZeroPad 0x021F1918 thumb ov107
 *   MB_UTIL_MSG_GetMsgData 0x021F1AFC thumb ov107
 *   MB_UTIL_MSG_GetWordSet 0x021F1B00 thumb ov107
 *   STRBUF_Create 0x020457B0 arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   STRBUF_GetLength 0x020458F8 arm
 *   STRBUF_GetChars 0x02045A90 arm
 *   MIi_CpuCopy16 0x02082A60 arm
 *   GF_OVERLAY_Load 0x02034AC4 arm
 *   CARD_SetPulledOutCallback 0x020774A0 arm
 *   ov014_id 0x0000000E data
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   WIH_GetSysState 0x02178E4C thumb ov014
 *   WIH_StartMeasureChannel 0x02178E84 thumb ov014
 *   WIH_Finalize 0x02179498 thumb ov014
 *   WIH_FreeWork 0x02179158 thumb ov014
 *   WIH_Initialize 0x021790E4 thumb ov014
 *   GFL_NET_WM_ICON_EasyStart 0x02037010 arm
 *   GFL_NET_WM_ICON_EasySetScreen 0x02037118 arm
 *   UI_SetIntrDataGlobal 0x020351F8 arm
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
 *   WIH_FinishMeasureChannel 0x02179024 thumb ov014
 *   MI_CpuCopy8 0x02082D44 arm
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   KEY_GetTrg 0x020362DC arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   MB_UTIL_MSG_OpenYesNoTaskMenu 0x021F1930 thumb ov107
 *   MB_UTIL_MSG_GetTaskMenuResult 0x021F19C8 thumb ov107
 *   MB_UTIL_MSG_CloseTaskMenu 0x021F19B8 thumb ov107
 *   d_021F6AF8 0x021F6AF8 data a4
 *   MISC_GetRank 0x0200C1A4 thumb
 *   OS_WaitIrq 0x0208459C arm
 *   MISC_SetBestScore 0x0200C18C thumb
 *   ZUKAN_SAVE_GetFromGameData  0x0200CA1C  thumb
 *   RECORD_AddCounter  0x02008DAC  thumb
 *   SAVE_EVENT_StoreTodayDate  0x0202F27C  thumb
 *   BOX_SAVEDATA_AddPokemon  0x020074D8  thumb
 *   POKE_TOOL_CreateFromBoxParam  0x0201747C  thumb
 *   ZUKAN_SAVE_RegisterCaught  0x0200CDE0  thumb
 *   MB_UTIL_MSG_IsPrintQueFinished 0x021F1B08 thumb ov107
 *   GFL_USE_GetRandom 0x020056EC thumb
 *   GAME_DATA_SaveStart 0x02012DAC thumb
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 *   MB_UTIL_MSG_SetNumberLeft  0x021F1900  thumb  ov107
 *   GAME_DATA_GetMyItem  0x0201292C  thumb
 *   GAME_DATA_GetMiscSave  0x02012F08  thumb
 *   FIELD_G3D_MAP_CheckBeaconTrainerKey  0x0216BF9C  thumb  ov010
 *   FIELD_G3D_MAP_StoreBeaconTrainerKey  0x0216BF74  thumb  ov010
 *   MYITEM_SAVEDATA_AddItem  0x02007E50  thumb
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   GFL_NET_IsSessionNull 0x0203CDBC arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   KEY_GetCont 0x0203630C arm
 *   GAME_DATA_Create 0x020124F4 thumb
 *   GAME_DATA_Delete 0x02012704 thumb
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   GFL_NET_ERR_GetErrorLevel 0x0200FB24 thumb
 *   GFL_NET_ERR_WaitLinkClosed 0x0200FBB0 thumb
 *   GFL_NET_ERR_ShowScreen 0x0200F7B8 thumb
 *   GFL_NET_ERR_ShowSimpleScreen 0x0200F83C thumb
 *   UI_SoftReset 0x02035544 arm
 *   GFL_NET_ERR_RequestScreen 0x0200FB38 thumb
 *   OS_GetOwnerInfoEx 0x02087D28 arm
 *   GFL_NET_AllocAligned 0x0203D7C8 arm
 *   MB_Init 0x021F5904 arm ov107
 *   MB_SetParentCommParam 0x021F5B4C arm ov107
 *   MB_CommSetParentStateCallback 0x021F1B3C arm ov107
 *   gMbChildStageMasks 0x021F6EB4 data a4
 *   d_021F6E1C 0x021F6E1C data a4
 *   gMbParentSys 0x021F6EAC data a4
 *   d_021F6E24 0x021F6E24 data a4
 *   MB_StartParentFromIdle 0x021F5E7C arm ov107
 *   MB_GetSegmentLength 0x021F2F1C arm ov107
 *   MB_ReadSegment 0x021F2FA0 arm ov107
 *   MB_RegisterFile 0x021F3544 arm ov107
 *   MB_CommResponseRequest 0x021F1C30 arm ov107
 *   MB_DisconnectChild 0x021F5FB0 arm ov107
 *   OS_DisableInterrupts 0x02087988 arm
 *   OS_RestoreInterrupts 0x0208799C arm
 *   MB_CommIsBootable 0x021F1BE0 arm ov107
 *   MB_EndToIdle 0x021F5F74 arm ov107
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
 *   MB_COMM_SYS_GetCount         0x021F110C  thumb
 *   MB_COMM_SYS_GetMaxSeen       0x021F11E0  thumb
 *   MB_COMM_SYS_HasKind0         0x021F11E8  thumb
 *   MB_COMM_SYS_HasKind1         0x021F10F4  thumb
 *   MB_COMM_SYS_HasKind11        0x021F10D4  thumb
 *   MB_COMM_SYS_HasKind12        0x021F10DC  thumb
 *   MB_COMM_SYS_HasKind12Again   0x021F10E4  thumb
 *   MB_COMM_SYS_HasKind14        0x021F10EC  thumb
 *   MB_COMM_SYS_HasKind2         0x021F10FC  thumb
 *   MB_COMM_SYS_HasKind4         0x021F1104  thumb
 *   MB_COMM_SYS_SendHeader       0x021F1370  thumb
 */

#include "../version.h"
#include "../sdk_ioreg_reg.h"

/* Message indices of the multiboot screen: White's message file has one more entry before them. */
#if VERSION == VERSION_WHITE
#define MB_MSG_INTRO_INGAME 0xE
#define MB_MSG_INTRO_STANDALONE 0x11
#define MB_MSG_OFFER_COUNT 0x17
#else
#define MB_MSG_INTRO_INGAME 0xD
#define MB_MSG_INTRO_STANDALONE 0x10
#define MB_MSG_OFFER_COUNT 0x16
#endif
#include "mb_comm_sys.h"

#include "../types.h"

#include "../sdk_fs.h"

struct DispVram;
struct DispConfig;
struct BgTemplate;
struct ClActInitParam {
    u32 header[4];
    u16 dimensions[6];
};

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
#define REG_POWCNT1 (*(volatile u16 *)REG_POWCNT1_ADDR)
#define PLTT_BG_MAIN ((volatile u16 *)HW_BG_PLTT)
#define PLTT_BG_SUB ((volatile u16 *)HW_DB_BG_PLTT)

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

/* Message sent on channel 0x400. */
#include "../ov107/mb_comm_shared_types.h"

/* Start of the mon receive buffer. */
typedef struct MbMonList {
    u8 count;
    u8 pad01;
    u16 maxSeen;
} MbMonList;

/* Record passed to the MB parent callback. */
struct MbMsgWork;

#include "mb_util_msg.h"
struct GameData;
struct SaveControl;
#include "../arm9/game_data.h"
struct MiscSave;
#include "../arm9/beacon.h"
#include "../arm9/gfl_use.h"
#include "../arm9/ui.h"
struct TcbTask;
#include "../arm9/tcb_list.h"
#include "../arm9/wm_icon.h"
struct EventWork;
#include "../arm9/zonedata.h"
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/wipe.h"
#include "../arm9/app_env.h"
#include "../arm9/msg_speed.h"
#include "../arm9/net.h"
#include "../arm9/msgdata.h"
#include "../arm9/fs_file.h"
#include "../arm9/gf_panic.h"
#include "../arm9/record.h"
#include "../arm9/box_savedata.h"
#include "../arm9/clact.h"
#ifdef __MWERKS__
#define BG_SYS_SetPlaneVisible BG_SYS_SetPlaneVisible_hdr
#define BG_SYS_FreeSlot BG_SYS_FreeSlot_hdr
#endif
#include "../arm9/bg_sys.h"
#ifdef __MWERKS__
#undef BG_SYS_SetPlaneVisible
#undef BG_SYS_FreeSlot
void BG_SYS_SetPlaneVisible(u32, unsigned char);
void BG_SYS_FreeSlot(u32);
#endif
#include "../arm9/bmp_win.h"
struct DispVramCfg;
struct SysInit;
struct Actor;
#include "../arm9/arc_tool.h"
#include "../arm9/arc_util.h"
#include "../arm9/app_icon.h"
struct BmpWin;
struct MsgBank;
struct Strbuf;
struct Bmp;
typedef short s16_p07;
#include "../arm9/bmp.h"
struct GfFont;
#include "../arm9/printsys.h"
#include "../arm9/strbuf.h"
struct MyStatus;
#include "../arm9/mystatus.h"
struct WordSet;
#include "../arm9/wordset.h"
#include "../arm9/mi_memory.h"
#include "../arm9/gf_overlay.h"
#include "../arm9/card_pullout.h"
#include "../ov014/wih.h"
#include "../arm9/wm_sync.h"
#include "../arm9/touchpanel.h"
#include "../arm9/key.h"
#include "../arm9/os_irqhandler.h"
#include "../arm9/zukan_save.h"
struct SaveData;
#include "../arm9/save_event.h"
struct BoxPokemon;
struct PokemonParam;
#include "../arm9/poke_tool.h"
struct ZukanSave;
#include "../ov010/field_g3d_map_scr.h"
struct MyItem;
#include "../arm9/myitem_savedata.h"
#include "../arm9/gfl_heap.h"
struct Proc;
#include "../arm9/procsys.h"
#include "../arm9/net_err.h"
struct OSOwnerInfoEx;
#include "../arm9/os_ownerinfoex.h"
#include "mb_wm_base.h"
extern void MB_CommSetParentStateCallback(void (*)(u16,u32,MbChildEvent *));
#include "mb_fileinfo.h"
#include "mb_parent.h"
#include "../arm9/os_system.h"
#include "../arm9/net_lower_data.h"
#include "../arm9/net_handle.h"
struct GFLNetHandle;

extern MbParentUi gMbParentUi;
extern const char d_021F6E08[], d_021F6E0C[];
#if LANGUAGE == LANGUAGE_JAPANESE
extern const char str_ja_021F6CE0[];
extern const char str_ja_021F6CF0[];
extern const char str_ja_021F6CF8[];
extern const char str_ja_021F6D20[];
#endif
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
extern const MbCommRequest sMbCommSessionRequest;
extern int d_021F6EE8[];

void MB_COMM_SYS_Init(MbCommSysWork *p);
void MB_COMM_SYS_Exit(MbCommSysWork *p);
int MB_COMM_SYS_Main(MbCommSysWork *p);
void MB_COMM_SYS_VBlank(struct TcbTask *unused0, void *unused1);
void MB_COMM_SYS_VBlankRefreshBg(void *unused0);
void MB_COMM_SYS_VBlankRefreshBgStandalone(void *unused0);
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
int MB_COMM_SYS_WmEndCallback(int ok);
void MB_COMM_SYS_UpdateSaveState(MbCommSysWork *p, int mode);
void MB_COMM_SYS_ResetHook(void *arg);
void MB_COMM_SYS_FinishReceive(MbCommSysWork *p);
void MB_COMM_SYS_RegisterReceivedMons(MbCommSysWork *p);
void MB_COMM_SYS_NoOp(MbCommSysWork *p);
void MB_COMM_SYS_MainSave(MbCommSysWork *p);
void MB_COMM_SYS_MainChildFlow(MbCommSysWork *p);
int MB_COMM_SYS_ShowTextPlane(void);
int MB_COMM_SYS_ProcInit(void *task, void *arg, MbParentArg *argument);
int MB_COMM_SYS_ProcExit(void *task, int unused, int keep, MbCommSysWork *p);
int MB_COMM_SYS_ProcMain(int a, int b, int c, MbCommSysWork *p);
#include "mbp.h"
void MB_PARENT_SYS_CheckRequest(u16 aid);

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
        p->saveState = MISC_GetBlock(GAME_DATA_GetSaveControl(p->arg->gameData));
        MISC_SetRank(p->saveState, 4);
    } else {
        p->saveState = 0;
        gMbParentUi.vblankCounter = 0;
    }
    p->vblankTask = GFL_USE_AddMainTask(MB_COMM_SYS_VBlank, (void *)p, 8);
    if (!p->standalone) {
        GFL_USE_SetVBlankHook(MB_COMM_SYS_VBlankRefreshBg, 0);
    } else {
        GFL_USE_SetVBlankHook(MB_COMM_SYS_VBlankRefreshBgStandalone, 0);
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
    TCB_DeleteTask(p->vblankTask);
    GFL_USE_ClearVBlankHook();
    GFL_NET_WM_ICON_EasyEnd();
    if (p->standalone == 1) {
        GFL_USE_CancelChangeAndStopBgm();
    } else {
        zoneData = (void *)GAME_DATA_GetEventWork(p->arg->gameData);
        eventWorkA = (u16 *)ZONEDATA_GetEventWorkAddress((struct EventWork *)zoneData, 16384);
        eventWorkB = (u16 *)ZONEDATA_GetEventWorkAddress((struct EventWork *)zoneData, 16385);
        *eventWorkA = p->bestChildCount;
        *eventWorkB = p->transferCount;
    }
    if (p->payload)
        GFL_HEAP_Free(p->payload);
    MB_COMM_SYS_DeleteNetState(p->net);
    MB_UTIL_MSG_Delete(p->msg);
    MB_COMM_SYS_ExitDisplay(p);
}

/* Reads the file image named by ROM string 142 into a new buffer. */
static inline void MbCommSys_LoadPayload(MbCommSysWork *p)
{
    File file;
    void *name;

    name = GFL_USE_GetArcPath(142);
    FS_InitFile((FSFile *)&file);
    if (!FS_OpenFile((FSFile *)&file, (const char *)name))
        GF_PANIC_Fail(PM_LANG_JA(d_021F6E08, str_ja_021F6CE0), PM_SRC_LINE(0, 0x28D), PM_LANG_JA(d_021F6E08, str_ja_021F6CF0));
    FS_SeekFile((FSFile *)&file, 0, 0);
    p->payloadSize = FS_GetLength((struct FSFile *)&file);
    p->payload = GFL_HEAP_Alloc(p->heapId, p->payloadSize, 1, PM_LANG_JA(d_021F6E0C, str_ja_021F6CE0), PM_SRC_LINE(660, 0x290));
    FS_ReadFile((FSFile *)&file, (void *)p->payload, p->payloadSize);
    if (!FS_CloseFile((FSFile *)&file))
        GF_PANIC_Fail(PM_LANG_JA(d_021F6E08, str_ja_021F6CE0), PM_SRC_LINE(0, 0x293), PM_LANG_JA(d_021F6E08, str_ja_021F6CF0));
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
            if (APP_ENV_IsWirelessAvailable() == 1) {
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
                GFL_NET_RefreshWmIconAtTopRight(0, p->heapId);
            else
                GFL_NET_RefreshWmIconAtTopRight(1, p->heapId);
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
            p->header.configCode = MSGDATA_GetLanguage();
            if (p->standalone == 0)
                p->header.savedCount = MISC_GetBestScore(p->saveState);
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
                MB_COMM_SYS_QueuePayload((sptr)p->net, (void *)p->payload, p->payloadSize);
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
            RECORD_AddOne(GAME_DATA_GetTrainerRecord(p->arg->gameData), 120);
            p->transferCount++;
            p->phase = 18;
        } else if (MB_COMM_SYS_GetCommStage(p->net) == 8) {
            RECORD_AddOne(GAME_DATA_GetTrainerRecord(p->arg->gameData), 120);
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
            u16 partyCount = BOX_SAVEDATA_CountFreeSlots((void *)GAME_DATA_GetBoxManager(p->arg->gameData));
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
    MB_UTIL_MSG_Main(p->msg);
    CLACT_DrawSystem();
    return 0;
}

void MB_COMM_SYS_VBlank(struct TcbTask *unused0, void *unused1)
{
    CLACT_VBlankSystem();
}

/* VBlank hook, in-game mode: refreshes the BG planes of both engines every third frame. */
void MB_COMM_SYS_VBlankRefreshBg(void *unused0)
{
    if (gMbParentUi.vblankDivider > 1) {
        gMbParentUi.vblankDivider = 0;
        BG_SYS_ChangeScrollImmediate(3, 2, 1);
        BG_SYS_ChangeScrollImmediate(3, 5, 1);
        BG_SYS_ChangeScrollImmediate(7, 2, 1);
        BG_SYS_ChangeScrollImmediate(7, 5, 1);
    } else {
        gMbParentUi.vblankDivider++;
    }
}

/*
 * volatile: 021EEF02 re-reads counter after 021EEF00 store.
 */
/* VBlank hook, standalone mode: refreshes plane 5 of both engines every fifth frame. */
void MB_COMM_SYS_VBlankRefreshBgStandalone(void *unused0)
{
    gMbParentUi.vblankCounter++;
    if (gMbParentUi.vblankCounter >= 5) {
        gMbParentUi.vblankCounter = 0;
        BG_SYS_ChangeScrollImmediate(3, 5, 1);
        BG_SYS_ChangeScrollImmediate(7, 5, 1);
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
    REG_DISPCNT &= 0xffffe0ff;
    REG_DB_DISPCNT &= 0xffffe0ff;
    WIPE_SetBrightnessFadeOut(0, 0);
    WIPE_SetBrightnessFadeOut(1, 0);
    WIPE_ResetWndMask(0);
    WIPE_ResetWndMask(1);
    REG_BLDCNT = 0;
    REG_DB_BLDCNT = 0;
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
        BG_SYS_SetPlaneVisible(6, 1);
    else
        BG_SYS_SetPlaneVisible(6, 0);
    clactInit = gClActorInitParam;
    clactInit.dimensions[0] = 64;
    CLACT_InitSystem((const struct ClactSysInit *)((struct SysInit *)(&clactInit)), (const struct DispVramCfg *)&d_021F6C10, p->heapId);
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
    BG_SYS_SetPlaneVisible(layer, 1);
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
        archive = ARC_TOOL_CreateHandle(139, p->heapId);
        ARC_UTIL_UploadPaletteFromHandleWhole(archive, 1, 4, 0, 0, p->heapId);
        ARC_UTIL_UploadBgCharFromHandle(archive, 5, 7, 0, 0, 0, p->heapId);
        ARC_UTIL_UploadBgPaletteFromHandle(archive, 9, 7, 0, 0, 0, p->heapId);
        ARC_UTIL_UploadPaletteFromHandleWhole(archive, 0, 0, 0, 0, p->heapId);
        ARC_UTIL_UploadBgCharFromHandle(archive, 4, 3, 0, 0, 0, p->heapId);
        ARC_UTIL_UploadBgPaletteFromHandle(archive, 8, 3, 0, 0, 0, p->heapId);
        ARC_UTIL_UploadPaletteFromHandle(archive, 2, 0, 288, 288, 128, p->heapId);
        ARC_UTIL_UploadBgCharFromHandle(archive, 6, 2, 0, 0, 0, p->heapId);
        ARC_UTIL_UploadBgPaletteFromHandle(archive, 10, 2, 0, 0, 0, p->heapId);
        ARC_UTIL_UploadPaletteFromHandle(archive, 3, 0, 416, 416, 32, p->heapId);
        ARC_UTIL_UploadBgCharFromHandle(archive, 7, 0, 0, 0, 0, p->heapId);
        ARC_UTIL_UploadBgPaletteFromHandle(archive, 11, 0, 0, 0, 0, p->heapId);
        BG_SYS_PushTile(2);
        ARC_TOOL_DeleteHandle(archive);
    } else {
        archive = ARC_TOOL_CreateHandle(34, p->heapId);
        ARC_UTIL_UploadPaletteFromHandleWhole(archive, 6, 4, 0, 0, p->heapId);
        ARC_UTIL_UploadBgCharFromHandle(archive, 15, 7, 0, 0, 0, p->heapId);
        ARC_UTIL_UploadBgPaletteFromHandle(archive, 31, 7, 0, 0, 0, p->heapId);
        ARC_UTIL_UploadPaletteFromHandleWhole(archive, 6, 0, 0, 0, p->heapId);
        ARC_UTIL_UploadBgCharFromHandle(archive, 15, 3, 0, 0, 0, p->heapId);
        ARC_UTIL_UploadBgPaletteFromHandle(archive, 31, 3, 0, 0, 0, p->heapId);
        ARC_TOOL_DeleteHandle(archive);
        archive = ARC_TOOL_CreateHandle(139, p->heapId);
        ARC_UTIL_UploadPaletteFromHandle(archive, 2, 4, 288, 288, 128, p->heapId);
        ARC_UTIL_UploadBgCharFromHandle(archive, 6, 5, 0, 0, 0, p->heapId);
        ARC_UTIL_UploadBgPaletteFromHandle(archive, 10, 5, 0, 0, 0, p->heapId);
        ARC_UTIL_UploadPaletteFromHandle(archive, 3, 4, 416, 416, 32, p->heapId);
        ARC_UTIL_UploadBgCharFromHandle(archive, 7, 4, 0, 0, 0, p->heapId);
        ARC_UTIL_UploadBgPaletteFromHandle(archive, 11, 4, 0, 0, 0, p->heapId);
        BG_SYS_PushTile(5);
        BG_SYS_SetPlaneVisible(5, 0);
        BG_SYS_SetPlaneVisible(4, 0);
        ARC_TOOL_DeleteHandle(archive);
    }
    archive = ARC_TOOL_CreateHandle(APP_ICON_GetArchiveId(), p->heapId);
    ARC_UTIL_UploadPaletteFromHandleWhole(archive, APP_ICON_GetStatusAnimFileId(), 4, 256, 32, p->heapId);
    ARC_UTIL_UploadBgCharFromHandle(archive, APP_ICON_GetStatusFrameFileId(), 6, 0, 0, 0, p->heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(archive, APP_ICON_GetStatusDataFileId(), 6, 0, 0, 0, p->heapId);
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
    p->actor = CLACT_CreateActor((struct Unit *)p->clactUnit, p->charId, p->paletteId, p->cellAnimId, (const struct ActorInitParam *)&placement, 1, p->heapId);
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
    BG_SYS_SetPlaneVisible(textBg, 0);
    archive = ARC_TOOL_CreateHandle(22, p->heapId);
    ARC_UTIL_UploadPaletteFromHandleWhole(archive, 0, 4, 224, 32, p->heapId);
    ARC_UTIL_UploadPaletteFromHandleWhole(archive, 0, 0, 224, 32, p->heapId);
    ARC_UTIL_UploadBgCharFromHandle(archive, 1, textBg, 0, 0, 0, p->heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(archive, 2, textBg, 0, 0, 0, p->heapId);
    BG_SYS_FillTileMap(textBg, 0, 0, 32, 24, 7);
    BG_SYS_PushTile(textBg);
    ARC_TOOL_DeleteHandle(archive);
    window = BMP_WIN_Create(textBg, 1, 4, 30, 8, 7, 1);
    bank = MSGDATA_CreateFromArchive(0, 2, 0x52, p->heapId);
    text = MSGDATA_AllocString(bank, 1);
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
    p->gameNameBuf = GFL_HEAP_Alloc(p->heapId, 0x60, 1, PM_LANG_JA(d_021F6E0C, str_ja_021F6CE0), PM_SRC_LINE(0x553, 0x54F));
    p->gameIntroBuf = GFL_HEAP_Alloc(p->heapId, 0xC0, 1, PM_LANG_JA(d_021F6E0C, str_ja_021F6CE0), PM_SRC_LINE(0x554, 0x550));
    MB_UTIL_MSG_SetWindowLayout(p->msg, 1);
    MB_UTIL_MSG_CreateWordSet(p->msg);
    MB_UTIL_MSG_SetNumberZeroPad(p->msg, 0, MYSTATUS_GetIdLow16(ownerData), 5);
    if (p->standalone == 0)
        msgPiece = MSGDATA_AllocString(MB_UTIL_MSG_GetMsgData(p->msg), 0xC);
    else
        msgPiece = MSGDATA_AllocString(MB_UTIL_MSG_GetMsgData(p->msg), 0xF);
    nameStr = STRBUF_Create(0x100, p->heapId);
    WORDSET_CopyTaggedText(MB_UTIL_MSG_GetWordSet(p->msg), nameStr, msgPiece);
    STRBUF_Delete(msgPiece);
    if (p->standalone == 0)
        msgPiece = MSGDATA_AllocString(MB_UTIL_MSG_GetMsgData(p->msg), MB_MSG_INTRO_INGAME);
    else
        msgPiece = MSGDATA_AllocString(MB_UTIL_MSG_GetMsgData(p->msg), MB_MSG_INTRO_STANDALONE);
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
    GF_OVERLAY_Load((sptr)ov014_id);
    if (p->standalone == 0) {
        BG_SYS_SetPlaneVisible(2, 1);
        BG_SYS_SetPlaneVisible(0, 1);
    } else {
        BG_SYS_SetPlaneVisible(5, 1);
        BG_SYS_SetPlaneVisible(4, 1);
    }
    CARD_SetPulledOutCallback(MB_COMM_SYS_ShowTextPlane);
}

/* Frees the game name and description strings and hides the BG layers they used. */
void MB_COMM_SYS_FreeGameStrings(MbCommSysWork *p)
{
    GF_OVERLAY_Unload((sptr)ov014_id);
    CARD_SetPulledOutCallback(0);
    GFL_HEAP_Free(p->gameNameBuf);
    GFL_HEAP_Free(p->gameIntroBuf);
    if (!p->standalone) {
        BG_SYS_SetPlaneVisible(2, 0);
        BG_SYS_SetPlaneVisible(0, 0);
    } else {
        BG_SYS_SetPlaneVisible(5, 0);
        BG_SYS_SetPlaneVisible(4, 0);
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
        WIH_Initialize(p->heapId, (sptr)MB_COMM_SYS_WmEndCallback, 0);
        GFL_NET_WM_ICON_EasyStart(240, 0, 0, p->heapId);
        if (p->standalone == 0)
            GFL_NET_WM_ICON_EasySetScreen(0, p->heapId);
        else
            GFL_NET_WM_ICON_EasySetScreen(1, p->heapId);
        p->subPhase = 1;
        UI_SetIntrDataGlobal(MB_COMM_SYS_ResetHook, p);
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
            MB_UTIL_MSG_SetNumberZeroPad(p->msg, 0, MYSTATUS_GetIdLow16(ownerData), 5);
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
        WIH_End(MB_COMM_SYS_WmEndCallback);
        p->wmActive = 0;
        p->subPhase = 7;
        break;
    case 7:
        if (gMbParentUi.wmEndDone == 1) {
            UI_SetIntrDataGlobal(0, 0);
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
    int channel = WIH_FinishMeasureChannel();

    MI_CpuCopy8(&registry, &p->registry, sizeof(registry));
    p->registry.romPath = p->standalone == 0 ? romPaths.inGame : romPaths.standalone;
#if VERSION == VERSION_WHITE
    p->registry.iconCharPath = iconCharPaths.inGame;
    p->registry.iconPalettePath = iconPalettePaths.inGame;
#else
    p->registry.iconCharPath = iconCharPaths.standalone;
    p->registry.iconPalettePath = iconPalettePaths.standalone;
#endif
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
            answer = TOUCHPANEL_HitTrg((const TouchHitTable *)d_021F6AF8);
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
#if LANGUAGE == LANGUAGE_JAPANESE
                GF_PANIC_FailPrintf(str_ja_021F6CE0, 0x76C, str_ja_021F6CF8, MB_PARENT_SYS_GetState());
#else
                GF_PANIC_Fail(d_021F6E08, 0, d_021F6E08);
#endif
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
            MB_UTIL_MSG_SetNumberZeroPad(p->msg, 0, MYSTATUS_GetIdLow16(ownerData), 5);
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
int MB_COMM_SYS_WmEndCallback(int ok)
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
        cur = MISC_GetRank(p->saveState);
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
            MISC_SetRank(p->saveState, mode);
    }
}

/*
 * extent: follower 021EFC10 already has its own matched source/shard.
 * ABI: 19E4 keeps the caller's visibly supplied r1. 0AE4 reads no incoming arguments.
 */
/* Reset hook: stops recruiting and waits for WM to shut down before the reset goes on. */
void MB_COMM_SYS_ResetHook(void *arg)
{
    MbCommSysWork *p = arg;
    unsigned registered = MB_PARENT_SYS_IsRegistered();

    if (registered == 1)
        MB_PARENT_SYS_Cancel();
    while (MB_PARENT_SYS_GetState() != 0 && MB_PARENT_SYS_GetState() != 5)
        OS_WaitIrq(1, 1);
    if (p->wmActive == 1) {
        gMbParentUi.wmEndDone = 0;
        while (WIH_End(MB_COMM_SYS_WmEndCallback))
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
        oldCount = (u16)MISC_GetBestScore(p->saveState);
        newCount = MB_COMM_SYS_GetMaxSeen(p->net);
        if (oldCount < newCount) {
            MISC_SetBestScore(p->saveState, newCount);
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
        RECORD_AddCounter(trainerRecord, 7, received);
        RECORD_AddCounter(trainerRecord, 0x54, received);
    }
    for (i = 0; i < received; i++) {
        mon = MB_COMM_SYS_GetMon(p->net, i);
        SAVE_EVENT_StoreTodayDate(mon);
        added = BOX_SAVEDATA_AddPokemon(party, mon);
        mon = POKE_TOOL_CreateFromBoxParam(mon, p->heapId);
        ZUKAN_SAVE_RegisterCaught(dex, mon);
        GFL_HEAP_Free(mon);
        if (added != 1)
#if LANGUAGE == LANGUAGE_JAPANESE
            GF_PANIC_FailPrintf(str_ja_021F6CE0, 0x84E, str_ja_021F6D20);
#else
            GF_PANIC_Fail(d_021F6E08, 0, d_021F6E08);
#endif
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
            if (MB_COMM_SYS_SendMessage(p->net, 1, GFL_USE_GetRandom(20) + 10) == 1)
                p->subPhase = 10;
        }
        break;
    case 10:
        if (MB_COMM_SYS_HasKind1(p->net) == 1)
            p->subPhase = 11;
        break;
    case 11:
        GAME_DATA_SaveStart((struct GameData *)p->arg->gameData);
        p->subPhase = 12;
        break;
    case 12:
        if (GAME_DATA_SaveMain(p->arg->gameData) == 1)
            p->subPhase = 13;
        break;
    case 13:
        if (MB_COMM_SYS_HasKind12(p->net) == 1 && MB_COMM_SYS_SendMessage(p->net, 2, GFL_USE_GetRandom(20) + 10) == 1) {
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
                MB_UTIL_MSG_PrintStream(p->msg, MB_MSG_OFFER_COUNT, MSG_SPEED_GetWait());
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
            a = (unsigned short)BOX_SAVEDATA_CountFreeSlots((void *)GAME_DATA_GetBoxManager(p->arg->gameData));
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
                MYITEM_SAVEDATA_AddItem(saveTrainerKey, 0x215, 1, p->heapId);
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
    BG_SYS_SetPlaneVisible(gMbParentUi.textOnSubScreen == 1 ? 4 : 2, 1);
    return 1;
}

/* Proc entry: creates the heap and work, loads or creates the argument, then runs init. */
int MB_COMM_SYS_ProcInit(void *task, void *arg, MbParentArg *argument)
{
    MbCommSysWork *p;

    if (!GFL_NET_IsSessionNull())
        return 0;
    GFL_HEAP_CreateChildHeap(1, 93, 0x130000);
    p = PROCSYS_AllocProcWork(task, sizeof(*p), 93);
    if (!argument) {
        argument = GFL_HEAP_Alloc(93, sizeof(*argument), 0, PM_LANG_JA(d_021F6E0C, str_ja_021F6CE0), PM_SRC_LINE(2788, 0xADF));
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
        GFL_HEAP_Free(p->arg);
    } else if (p->arg->standalone == 1) {
        GAME_DATA_Delete(p->arg->gameData);
        GFL_HEAP_Free(p->arg);
    }
    PROCSYS_FreeProcWork(task);
    GFL_HEAP_DeleteChecked(93);
    if (errorRequested == 1) {
        if (standalone) {
            if (wasSaving == 1 || GFL_NET_ERR_GetErrorLevel() == 1) {
                GFL_NET_ERR_WaitLinkClosed();
                GFL_NET_ERR_ShowScreen(1);
            } else {
                GFL_NET_ERR_ShowScreen(0);
            }
        } else if (wasSaving == 1) {
            GFL_NET_ERR_WaitLinkClosed();
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
    if (GFL_NET_ERR_GetErrorLevel() != 0 && p->errorScreenRequested == 0) {
        GFL_NET_ERR_RequestScreen();
        p->errorScreenRequested = 1;
    }
    return 0;
}
