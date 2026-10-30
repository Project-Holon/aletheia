/*
 * file:     mb_comm_sys.c
 * unit:     yes
 * function: MB_COMM_SYS_CreateNetState, MB_COMM_SYS_DeleteNetState, MB_COMM_SYS_UpdateNetState, MB_COMM_SYS_StartNetSession, MB_COMM_SYS_StopNetSession, MB_COMM_SYS_GetNetRunState, MB_COMM_SYS_IsNetSessionNull, MB_COMM_SYS_StartNet, MB_COMM_SYS_SetSyncRange, MB_COMM_SYS_IsSyncDone, MB_COMM_SYS_IsLoginDone, MB_COMM_SYS_GetCommStage, MB_COMM_SYS_ClearRoundFlags, MB_COMM_SYS_HasKind11, MB_COMM_SYS_HasKind12, MB_COMM_SYS_HasKind12Again, MB_COMM_SYS_HasKind14, MB_COMM_SYS_HasKind1, MB_COMM_SYS_HasKind2, MB_COMM_SYS_HasKind4, MB_COMM_SYS_GetCount, MB_COMM_SYS_HasKind19, MB_COMM_SYS_GetOfferCount, MB_COMM_SYS_GetOfferExtra, MB_COMM_SYS_GetOfferFlagA, MB_COMM_SYS_GetOfferFlagB, MB_COMM_SYS_HasKind20, MB_COMM_SYS_HasKind21, MB_COMM_SYS_GetKind21Value, MB_COMM_SYS_QueuePayload, MB_COMM_SYS_ClearMonBuffer, MB_COMM_SYS_HasMonsReceived, MB_COMM_SYS_GetMonCount, MB_COMM_SYS_GetMon, MB_COMM_SYS_GetMaxSeen, MB_COMM_SYS_HasKind0, MB_COMM_SYS_SendMessage, MB_COMM_SYS_OnMessage, MB_COMM_SYS_SendHeader, MB_COMM_SYS_OnHeaderReceived, MB_COMM_SYS_GetHeaderBuffer, MB_COMM_SYS_OnMonsReceived, MB_COMM_SYS_GetMonBuffer, MB_COMM_SYS_GetChildDataPtr, MB_COMM_SYS_GetMemberCount
 * address:  0x021F0DE8
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
 */

#include "../version.h"
#include "mb_comm_sys.h"
#include "../sdk_ioreg_reg.h"

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
struct MbYesNoMsgWork;
#include "../arm9/msgdata.h"
#include "../arm9/fs_file.h"
#include "../arm9/gf_panic.h"
#include "../arm9/record.h"
#include "../arm9/box_savedata.h"
#include "../arm9/clact.h"
#include "../arm9/bg_sys.h"
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
#if LANGUAGE == LANGUAGE_JAPANESE
extern const char str_ja_021F6D94[];
#endif
extern const MbCommRequest sMbCommSessionRequest;
extern int d_021F6EE8[];

#include "mb_parent_sys.h"
#include "mbp.h"
void MB_PARENT_SYS_CheckRequest(u16 aid);
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
void MB_COMM_SYS_QueuePayload(int a, void *payload, int payloadSize);
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

/* Allocates the link state and its receive buffer for six box params. */
MbNetState *MB_COMM_SYS_CreateNetState(u16 heapId)
{
    MbNetState *net;

    net = GFL_HEAP_Alloc(heapId, sizeof(*net), 1, PM_LANG_JA(d_021F6E28, str_ja_021F6D94), 159);
    net->heapId = heapId;
    net->netStage = 0;
    net->headerBuffer = 0;
    net->flagsA.bits.lowerDataActive = 0;
    net->commStage = 0;
    net->nextCommStage = 0;
    net->monBuffer = GFL_HEAP_Alloc(net->heapId, 6 * POKE_TOOL_GetBoxParamSize() + 4, 1, PM_LANG_JA(d_021F6E28, str_ja_021F6D94), 169);
    return net;
}

/* Frees the link state and its buffers, shutting the lower data layer down when active. */
void MB_COMM_SYS_DeleteNetState(MbNetState *net)
{
    if (net->headerBuffer)
        GFL_HEAP_Free(net->headerBuffer);
    if (net->flagsA.bits.lowerDataActive == 1)
        GFL_NET_LOWER_DATA_Exit();
    GFL_HEAP_Free(net->monBuffer);
    GFL_HEAP_Free(net);
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
    MbCommRequest request = sMbCommSessionRequest;

    request.heapId = net->heapId;
    GFL_NET_StartSession((GFLNetInitializeStruct *)&request, 0, net);
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
    void *handle = GFL_NET_HANDLE_GetCurrentHandle();

    GFL_NET_HANDLE_SetTimingSyncRange(handle, 0x40, 4);
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
void MB_COMM_SYS_QueuePayload(int a, void *payload, int payloadSize)
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
        POKE_TOOL_ClearBoxParam((struct BoxPokemon *)(net->monBuffer + i * POKE_TOOL_GetBoxParamSize() + 4));
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
    return GFL_NET_SendData(handle, 0xFF, 0x400, 8, (&msg), 1, 0, 0);
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
    return GFL_NET_SendData(handle, 1, 0x401, 8, header, 1, 0, 1);
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
        net->headerBuffer = GFL_HEAP_Alloc(net->heapId, 8, 1, PM_LANG_JA(d_021F6E28, str_ja_021F6D94), 862);
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
