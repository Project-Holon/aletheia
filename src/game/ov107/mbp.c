/*
 * file:     mbp.c
 * unit:     yes
 * function: MB_PARENT_SYS_Init, MB_PARENT_SYS_Register, MB_PARENT_SYS_LoadFileImage, MB_PARENT_SYS_AcceptRequest, MB_PARENT_SYS_RejectRequest, MB_PARENT_SYS_StartSending, MB_PARENT_SYS_AllBootable, MB_PARENT_SYS_StartBoot, MB_PARENT_SYS_Cancel, MB_PARENT_SYS_EndIfAllBootable, MB_PARENT_SYS_EventCallback, MB_PARENT_SYS_SetState, MB_PARENT_SYS_GetState, MB_PARENT_SYS_GetChildStage, MB_PARENT_SYS_FreeBuffers, MB_PARENT_SYS_IsRegistered
 * address:  0x021F0754
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
struct MbMsgWork;

extern struct MbMsgWork *MB_UTIL_MSG_Create(u16 heap, u32 a, u32 b, u32 c, u32 d, u32 e);
struct GameData;
struct SaveControl;
extern struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *gd);
struct MiscSave;
extern struct MiscSave *MISC_GetBlock(struct SaveControl *save);
extern void MISC_SetRank(struct MiscSave *beacon, u32 rank);
extern void *GFL_USE_AddMainTask(u32,u32,u32);
extern int GFL_USE_SetVBlankHook(int,int);
extern void GFL_USE_CancelChangeAndPlayBgm(u32 bgmNo, u32 trackMask);
extern void UI_SetKeepAwakeFlagsGlobal(u8 flags);
extern void UI_ClearKeepAwakeFlagsGlobal(u8 v);
struct TcbTask;
extern void TCB_DeleteTask(struct TcbTask *task);
extern void GFL_USE_ClearVBlankHook(void);
extern void GFL_NET_WM_ICON_EasyEnd(void);
extern void GFL_USE_CancelChangeAndStopBgm(void);
extern void *GAME_DATA_GetEventWork(struct GameData *gd);
struct EventWork;
extern u16 *ZONEDATA_GetEventWorkAddress(struct EventWork *ev, u32 workId);
extern u32 GFL_HEAP_Free(void *p);
extern void MB_UTIL_MSG_Delete(struct MbMsgWork *p);
extern u8 GAME_DATA_IsSaving(struct GameData *gd);
extern void GAME_DATA_SaveCancel(struct GameData *gd);
extern void WIPE_SYS_Start(void *divisionMode, u32 mainPattern, u32 subPattern, u16 color, u32 frames, u32 wait, u32 heapId);
extern u32 WIPE_SYS_EndCheck(void);
extern void APP_ENV_IsWirelessAvailable(void);
extern signed char MSG_SPEED_GetWait(void);
extern void GFL_USE_FadeOutBgm(u32);
extern void GFL_NET_RefreshWmIconAtTopRight(u32,u32);
extern void MB_UTIL_MSG_SetWindowLayout(struct MbMsgWork *work, s32 layout);
extern void MB_UTIL_MSG_PrintStream(struct MbMsgWork *work, s32 msgId, s32 speed);
extern void MB_UTIL_MSG_PrintStreamSystemMsg(struct MbMsgWork *p, int a);
extern void MB_UTIL_MSG_SetKeyWaitFlag(struct MbMsgWork *work, s32 flag);
extern int MB_UTIL_MSG_IsStreamIdle(struct MbMsgWork *work);
extern int MB_UTIL_MSG_ProcessYesNoMenu(struct MbMsgWork *work);
struct MbYesNoMsgWork;
extern void MB_UTIL_MSG_OpenYesNoMenu(struct MbYesNoMsgWork *work);
extern void MB_UTIL_MSG_ClearWindow(struct MbMsgWork *work);
extern void MB_UTIL_MSG_ClearYesNoMenu(struct MbMsgWork *p);
extern u8 MSGDATA_GetLanguage(void);
extern u32 MISC_GetBestScore(struct MiscSave *beacon);
extern void *GFL_USE_GetArcPath(u32);
extern void FS_InitFile(File *);
extern int FS_OpenFile(File *,const char *);
extern int FS_CloseFile(File *);
extern int FS_SeekFile(void *file, long offset, int origin);
extern s32 FS_ReadFile(void *file, void *buffer, s32 length);
extern u32 FS_GetLength(void *file);
extern void GF_PANIC_Fail(const char *expr, u32 line, const char *file);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *GAME_DATA_GetTrainerRecord(struct GameData *gd);
extern u32 GAME_DATA_GetBoxManager(struct GameData *gd);
extern u32 RECORD_AddOne(void *obj, int i);
extern int BOX_SAVEDATA_CountFreeSlots(struct GameData *gameData);
extern void MB_UTIL_MSG_Main(struct MbMsgWork *work);
extern void CLACT_DrawSystem(void);
extern void CLACT_VBlankSystem(void);
extern void BG_SYS_ChangeScrollImmediate(unsigned,unsigned,unsigned);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void WIPE_SetBrightnessFadeOut(u32,u32);
extern void WIPE_ResetWndMask(void *);
extern void BG_SYS_SetVramBanks(const struct DispVram *);
extern void BG_SYS_Create(u16);
extern void BMP_WIN_Init(u16);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *);
extern void BG_SYS_SetPlaneVisible(u8 which, u8 enable);
struct DispVramCfg;
struct SysInit;
extern void CLACT_InitSystem(struct SysInit *cfg, struct DispVramCfg *res_cfg, u32 heapId);
extern void *CLACT_CreateUnit(int,u8,u32);
extern void CLACT_SetUnitDefaultRenderer(void *);
extern void BG_SYS_SetMainPlaneVisible(u32,u32);
extern void BG_SYS_SetSubPlaneVisible(u32,u32);
struct Actor;
extern void CLACT_DeleteActor(struct Actor *actor);
extern u32 CLACT_DeleteUnit(void *bank);
extern void CLACT_ExitSystem(void);
extern void BG_SYS_FreeLayerBuf(unsigned);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_FreeSlot(u8 idx);
extern void BG_SYS_PushTile(u32);
extern void *ARC_TOOL_CreateHandle(u32 archiveID, u16 heapID);
extern void ARC_UTIL_UploadPaletteFromHandleWhole(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 ARC_UTIL_UploadBgCharFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void ARC_UTIL_UploadBgPaletteFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void ARC_UTIL_UploadPaletteFromHandle(void *arc, u32 memberIdx, u32 kind, u32 offset, u32 dest, u32 size, u16 flags);
extern void ARC_TOOL_DeleteHandle(void *);
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 vram_mode, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void *CLACT_CreateActor(void *owner,unsigned int i,unsigned int j,unsigned int k,const void *position,unsigned short space,unsigned short heap);
extern void CLACT_SetActorDrawEnable(struct Actor *actor, u32 value);
extern u32 APP_ICON_GetArchiveId(void);
extern u32 APP_ICON_GetMoveKindPaletteFileId(void);
extern u32 APP_ICON_GetMoveKindAnimFileId(void);
extern u32 APP_ICON_GetStatusAnimFileId(void);
extern u32 APP_ICON_GetStatusFrameFileId(void);
extern u32 APP_ICON_GetStatusDataFileId(void);
extern u32 APP_ICON_GetStatusCellFileId(u32);
extern u32 APP_ICON_GetStatusPaletteFileId(u32);
struct BmpWin;
extern struct BmpWin *BMP_WIN_Create(u32 bgLayer, u32 posX, u32 posY, u8 width, u8 height, u8 palette, u8 allocDir);
struct MsgBank;
extern struct MsgBank *MSGDATA_CreateFromArchive(u32,u32,u32,u32);
struct Strbuf;
extern struct Strbuf *MSGDATA_AllocString(struct MsgBank *bank, u32 index);
struct Bmp;
extern struct Bmp *BMP_WIN_GetBmp(struct BmpWin *win);
extern void BMP_Clear(struct Bmp *bmp, u8 value);
struct GfFont;
extern struct GfFont *MB_UTIL_MSG_GetFont(struct MbMsgWork *work);
extern void PRINTSYS_PrintColor(struct Bmp *bmp, s16 x, s16 y, struct Strbuf *str, struct GfFont *font, u16 color);
extern void BMP_WIN_TransferChars(struct BmpWin *win);
extern void BMP_WIN_MakeScreen(struct BmpWin *win);
extern u8 BMP_WIN_GetBgLayer(struct BmpWin *win);
extern void STRBUF_Delete(struct Strbuf *strbuf);
extern u32 MSGDATA_Delete(struct MsgBank *bank);
extern u32 BMP_WIN_Delete(struct BmpWin *win);
struct MyStatus;
extern struct MyStatus *GAME_DATA_GetMyStatus(struct GameData *gd);
extern void MB_UTIL_MSG_CreateWordSet(struct MbMsgWork *work);
extern u16 MYSTATUS_GetIdLow16(struct MyStatus *mystatus);
extern void MB_UTIL_MSG_SetNumberZeroPad(struct MbMsgWork *a, int b, int c, int d);
extern struct MsgBank *MB_UTIL_MSG_GetMsgData(struct MbMsgWork *work);
struct WordSet;
extern struct WordSet *MB_UTIL_MSG_GetWordSet(struct MbMsgWork *work);
extern struct Strbuf *STRBUF_Create(u32 capacity, u32 heapId);
extern void WORDSET_CopyTaggedText(struct WordSet *words, struct Strbuf *dst, struct Strbuf *src);
extern u16 STRBUF_GetLength(struct Strbuf *strbuf);
extern u16 *STRBUF_GetChars(struct Strbuf *strbuf);
extern void MIi_CpuCopy16(const void *, void *, int);
extern int GF_OVERLAY_Load(s32 handle);
extern void CARD_SetPulledOutCallback(int (*callback)(void));
extern void GF_OVERLAY_Unload(int);
extern int WIH_GetSysState(void);
extern int WIH_StartMeasureChannel(void);
extern int WIH_Finalize(void);
extern void WIH_FreeWork(void);
extern int WIH_Initialize(u32,int,int);
extern void GFL_NET_WM_ICON_EasyStart(u32,u32,u32,u32);
extern void GFL_NET_WM_ICON_EasySetScreen(u32,u32);
extern void UI_SetIntrDataGlobal(u32 a, u32 b);
extern void MB_UTIL_MSG_DeleteWordSet(struct MbMsgWork *work);
extern void MB_UTIL_MSG_PrintQueued(struct MbMsgWork *work, s32 msgId);
extern void MB_UTIL_MSG_SetTimeIconPending(struct MbMsgWork *work, s32 pending);
extern void CLACT_SetActorAnimSeq(struct Actor *actor, u16 value);
extern int WIH_End(void (*cb)(int));
extern int WM_GetLinkLevel(void);
extern u32 GFL_NET_WM_ICON_EasySetLevel(u32);
extern void GFL_NET_WM_ICON_EasyMain(void);
extern u16 WIH_FinishMeasureChannel(void);
extern void MI_CpuCopy8(const void *,void *,unsigned);
extern int TOUCHPANEL_HitTrg(const void *);
extern int MB_UTIL_MSG_GetTaskMenuResult(struct MbMsgWork *a);
extern u32 KEY_GetTrg(void);
extern void CLACT_SetActorAutoAnim(struct Actor *actor, u32 enable);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void MB_UTIL_MSG_OpenYesNoTaskMenu(struct MbMsgWork *p, int kind);
extern void MB_UTIL_MSG_CloseTaskMenu(struct MbMsgWork *a);
extern u8 MISC_GetRank(struct MiscSave *beacon);
extern void OS_WaitIrq(int clear, u32 irqFlags);
extern void MISC_SetBestScore(struct MiscSave *beacon, u32 score);
void *ZUKAN_SAVE_GetFromGameData(void *);
u32 RECORD_AddCounter(void *obj, int i, u32 delta);
struct SaveData;
void SAVE_EVENT_StoreTodayDate(struct SaveData *save);
struct BoxPokemon;
int BOX_SAVEDATA_AddPokemon(struct GameData *gameData, struct BoxPokemon *mon);
struct PokemonParam;
struct PokemonParam *POKE_TOOL_CreateFromBoxParam(struct PokemonParam *src, u16 heapId);
struct ZukanSave;
void ZUKAN_SAVE_RegisterCaught(struct ZukanSave *pZukan, void *pMon);
extern int MB_UTIL_MSG_IsPrintQueFinished(struct MbMsgWork *work);
extern u32 GFL_USE_GetRandom(u32);
extern int GAME_DATA_SaveStart(struct GameData *gd);
extern int GAME_DATA_SaveMain(struct GameData *gd);
void MB_UTIL_MSG_SetNumberLeft(struct MbMsgWork *work, s32 index, s32 value, s32 digits);
void *GAME_DATA_GetMyItem(struct GameData *gd);
void *GAME_DATA_GetMiscSave(struct GameData *gd);
int FIELD_G3D_MAP_CheckBeaconTrainerKey(void *, int, void *);
void FIELD_G3D_MAP_StoreBeaconTrainerKey(void *, int, void *);
struct MyItem;
u32 MYITEM_SAVEDATA_AddItem(struct MyItem *bag, u16 itemId, u16 quantity, u16 heapId);
extern void BG_SYS_SetMainVisiblePlanes(u32 planes);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
extern int GFL_NET_IsSessionNull(void);
extern void GFL_HEAP_CreateChildHeap(u32,u32,u32);
struct Proc;
extern void *PROCSYS_AllocProcWork(struct Proc *proc, u32 size, u32 heapId);
extern unsigned int KEY_GetCont(void);
extern struct GameData *GAME_DATA_Create(u16);
extern void GAME_DATA_Delete(struct GameData *gameData);
extern void PROCSYS_FreeProcWork(struct Proc *proc);
extern void GFL_HEAP_DeleteChecked(u32);
extern u32 GFL_NET_ERR_GetErrorLevel(void);
extern u32 GFL_NET_ERR_WaitLinkClosed(void);
extern u32 GFL_NET_ERR_ShowScreen(u32 isFatal);
extern void GFL_NET_ERR_ShowSimpleScreen(void);
extern void UI_SoftReset(u32 resetParam);
extern void GFL_NET_ERR_RequestScreen(void);
struct OSOwnerInfoEx;
extern void OS_GetOwnerInfoEx(struct OSOwnerInfoEx *info);
extern void *GFL_NET_AllocAligned(u32,u32,const char *,u16);
extern int MB_Init(void *,MBUser *,int,int,u16);
extern int MB_SetParentCommParam(u16,u16);
extern void MB_CommSetParentStateCallback(void (*)(u16,u32,MbChildEvent *));
extern int MB_StartParentFromIdle(int);
extern u32 MB_GetSegmentLength(void *);
extern int MB_ReadSegment(void *,void *,u32);
extern int MB_RegisterFile(void *,void *);
extern int MB_CommResponseRequest(u16,int);
extern void MB_DisconnectChild(u16);
extern u32 OS_DisableInterrupts(void);
extern u32 OS_RestoreInterrupts(u32);
extern int MB_CommIsBootable(u16);
extern void MB_EndToIdle(void);
extern void *MB_CommGetChildUser(u16);
extern void GFL_NET_FreeAligned(void *);
extern u32 POKE_TOOL_GetBoxParamSize(void);
extern void GFL_NET_LOWER_DATA_Exit(void);
extern int GFL_NET_HANDLE_CheckNegotiation(void);
struct GFLNetHandle;
extern struct GFLNetHandle *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_HANDLE_IsNegotiationDone(struct GFLNetHandle *handle);
extern u32 GFL_NET_IsHandleReady(struct GFLNetHandle *handle);
extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct GFLNetHandle *handle, u32 timingLow, u32 timingHigh);
extern void GFL_NET_SetLoginOption(u8 loginOption);
extern void GFL_NET_StartSession(void *req, u32 transportArg, u32 userArg);
extern void GFL_NET_LOWER_DATA_Init(int,int);
extern int GFL_NET_Exit(int);
extern int GFL_NET_GetRunState(void);
extern void GFL_NET_StartByNetType(void);
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct GFLNetHandle *handle, u32 timingLow, u32 timingHigh);
extern void GFL_NET_LOWER_DATA_SetSendData(int,int,int,int);
void POKE_TOOL_ClearBoxParam(struct BoxPokemon *box);
u32 GFL_NET_IsParentAid(void);
struct GFLNetHandle *GFL_NET_HANDLE_GetNetHandle(s32 idx);
u32 GFL_NET_SendData(struct GFLNetHandle *handle, u32 sendId, u32 command, u32 size, void *data, u32 sendFlags, u32 skipIfQueued, u32 queueMode);
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
void MB_PARENT_SYS_AcceptRequest(u16 aid);
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

/* Initializes the MB parent: owner info, MB work buffer, comm params and the event callback. */
void MB_PARENT_SYS_Init(int a, int b)
{
    OwnerInfo owner;
    MBUser userInfo;
    u8 zeroBuffer[20];
    MbChildStageMasks *zero;

    OS_GetOwnerInfoEx((struct OSOwnerInfoEx *)(&owner));
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
    if (MB_Init(gMbParentSys.mbWork, &userInfo, a, b, 1))
        GF_PANIC_Fail(d_021F6E24, 0, d_021F6E24);
    MB_SetParentCommParam(256, 1);
    MB_CommSetParentStateCallback(MB_PARENT_SYS_EventCallback);
    MB_PARENT_SYS_SetState(1);
}

/* Registers the game: starts recruiting on the channel, loads the file image. */
void MB_PARENT_SYS_Register(MbRegistryBlock *registry, int channel)
{
    MB_PARENT_SYS_SetState(2);
    if (MB_StartParentFromIdle(channel)) {
        MB_PARENT_SYS_SetState(7);
        return;
    }
    gMbParentSys.registered = 1;
    if (!MB_PARENT_SYS_LoadFileImage(registry))
        GF_PANIC_Fail(d_021F6E24, 0, d_021F6E24);
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
        gMbParentSys.fileBuffer = GFL_HEAP_Alloc(93, 65536, 1, d_021F6E1C, 287);
        if (gMbParentSys.fileBuffer) {
            if (MB_ReadSegment(fp, gMbParentSys.fileBuffer, 65536)) {
                if (MB_RegisterFile(registry, gMbParentSys.fileBuffer))
                    result = 1;
            }
            if (!result)
                GFL_HEAP_Free(gMbParentSys.fileBuffer);
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
void MB_PARENT_SYS_AcceptRequest(u16 aid)
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
        MB_EndToIdle();
    }
}

/* Ends the MB session when starting and every connected child can boot. */
void MB_PARENT_SYS_EndIfAllBootable(void)
{
    if (gMbParentSys.state == 4 && gMbParentSys.connectedMask == gMbParentSys.bootStartableMask && gMbParentSys.registered == 1) {
        gMbParentSys.registered = 0;
        MB_EndToIdle();
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
        MB_PARENT_SYS_AcceptRequest(aid);
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
            GFL_HEAP_Free(gMbParentSys.fileBuffer);
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
        GF_PANIC_Fail(d_021F6E24, 0, d_021F6E24);
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
        GFL_HEAP_Free(gMbParentSys.fileBuffer);
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
