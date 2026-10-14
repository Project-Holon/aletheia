/*
 * file:     gsync_state.c
 * unit:     yes
 * function: GSYNC_STATE_HandleHttpError, GSYNC_STATE_IsConnectionAlive, GSYNC_STATE_IsCommIdleWithTarget, GSYNC_STATE_IsCommReady, GSYNC_STATE_SetNextState, GSYNC_STATE_ChangeState, GSYNC_STATE_StateWaitFade, GSYNC_STATE_StateFadeOutAfterMessage, GSYNC_STATE_StateFreeDownloadAndExit, GSYNC_STATE_StateWaitInputCancelSave, GSYNC_STATE_StateErrorMessage, GSYNC_STATE_StateSetErrorExit, GSYNC_STATE_StateWaitMessageInput, GSYNC_STATE_StateClearMessageExit, GSYNC_STATE_StateWaitEndingBgm, GSYNC_STATE_StateShowResultMessage, GSYNC_STATE_ResetSlotActors, GSYNC_STATE_LoadReceivedMon, GSYNC_STATE_StateSaveFinishMessage, GSYNC_STATE_StatePollResponse, GSYNC_STATE_StateSendRequest, GSYNC_STATE_StateSaveMainWait, GSYNC_STATE_StateSaveStart, GSYNC_STATE_StateCleanupDownload, GSYNC_STATE_StateFreeReceivedMon, GSYNC_STATE_StateExtraSaveMain, GSYNC_STATE_StateExtraSaveLoadStart, GSYNC_STATE_StateFreeExtraSaveBuffer, GSYNC_STATE_StateExtraSaveMainSecond, GSYNC_STATE_StateExtraSaveLoadStartSecond, GSYNC_STATE_StateMusicalSaveApply, GSYNC_STATE_StateMusicalSaveCreate, GSYNC_STATE_StateDownloadReset, GSYNC_STATE_StateMusicalSaveRetry, GSYNC_STATE_StateWaitDownloadIdle, GSYNC_STATE_StateRequestFile, GSYNC_STATE_StateWaitDownloadIdleThenRequest, GSYNC_STATE_StateRequestFileList, GSYNC_STATE_StateSetFileAttribute, GSYNC_STATE_StateInitDownload, GSYNC_STATE_StateSelectNextDownload, GSYNC_STATE_CopyMonRecord, GSYNC_STATE_GetEntryCount, GSYNC_STATE_GetListEntry, GSYNC_STATE_BuildMonEntry, GSYNC_STATE_BuildMonEntries, GSYNC_STATE_ApplyIconRecords, GSYNC_STATE_PrepareReceivedList, GSYNC_STATE_UpdateCurrentEntry, GSYNC_STATE_StateReceiveList, GSYNC_STATE_StateSendListRequest, GSYNC_STATE_StateWaitMessageThenSend, GSYNC_STATE_StateShowProgressMessage, GSYNC_STATE_StateWaitInputFirst, GSYNC_STATE_StateWaitMessageThenPrintSecond, GSYNC_STATE_StateWaitInputSecond, GSYNC_STATE_StateWaitMessageThenPrintThird, GSYNC_STATE_StateConfirmMenuSelect, GSYNC_STATE_StateOpenConfirmMenu, GSYNC_STATE_StateShowEmptyMessage, GSYNC_STATE_StateWaitMessageEnd, GSYNC_STATE_StateWaitInputClearWindow, GSYNC_STATE_StateWaitInputPrintNext, GSYNC_STATE_StatePrintErrorMessage, GSYNC_STATE_StateReceiveResponse, GSYNC_STATE_StateSendResponse, GSYNC_STATE_StateWaitInputThird, GSYNC_STATE_StateWaitMessageThenPrintFourth, GSYNC_STATE_StateWaitInputFourth, GSYNC_STATE_StateWaitMessageThenPrintFifth, GSYNC_STATE_ParseResponse, GSYNC_STATE_StateReceiveParsedResponse, GSYNC_STATE_StateSendParsedRequest, GSYNC_STATE_StateWaitMessageClearStream, GSYNC_STATE_StatePrintFinalMessage, GSYNC_STATE_StateReceiveFinalResponse, GSYNC_STATE_StateSendFinalRequest, GSYNC_STATE_StatePlaySeWaitInput, GSYNC_STATE_StateWaitMessageThenNext, GSYNC_STATE_StateShowCompletionMessage, GSYNC_STATE_StateSaveErrorExit, GSYNC_STATE_StateTrainerRecordSaveStart, GSYNC_STATE_StateReceiveRecordResponse, GSYNC_STATE_StateSendRecordRequest, GSYNC_STATE_StateStartTransferAnimation, GSYNC_STATE_StateTransferAnimationStep, GSYNC_STATE_StateTransferAnimationOpen, GSYNC_STATE_StateTransferAnimationEffect, GSYNC_STATE_StateCreateReceivedMonIcon, GSYNC_STATE_StateStoreReceivedMon, GSYNC_STATE_DestroyHttpConnection, GSYNC_STATE_CommitReceivedMon, GSYNC_STATE_ProcInit, GSYNC_STATE_ProcMain, GSYNC_STATE_ProcExit
 * address:  0x021D6E08
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from gsync_state.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 *   GAME_DATA_SaveStart 0x02012DAC thumb
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_02030734 0x02030734 arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02034714 0x02034714 arm
 *   DWC_RAP_SetErrorHookCallback 0x02156DE0 thumb ov009
 *   func_02034AC4 0x02034AC4 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_020056EC 0x020056EC thumb
 *   func_02019D30 0x02019D30 thumb
 *   KEY_GetTrg  0x020362DC  arm
 *   GAME_DATA_SaveCancel  0x02012E08  thumb
 *   NHTTP_RAP_DeleteConnection 0x021B9774 thumb ov114
 *   d_021DA844 0x021DA844 data a4
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   GFL_USE_SetBgmPlayerParam 0x02005DE4 thumb
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 *   GFL_USE_PushBgm  0x02005E64  thumb
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   d_021DAB78 0x021DAB78 data a1
 *   func_02009290 0x02009290 thumb
 *   func_020092F8 0x020092F8 thumb
 *   func_020093D4 0x020093D4 thumb
 *   NHTTP_RAP_GetResultCode 0x021B99DC thumb ov114
 *   NHTTP_RAP_PollConnection 0x021B9790 thumb ov114
 *   NHTTP_RAP_GetRecvBuffer 0x021B97F4 thumb ov114
 *   NHTTP_RAP_CreateRequest 0x021B95D4 thumb ov114
 *   NHTTP_RAP_GetConnection 0x021B973C thumb ov114
 *   NHTTP_RAP_StartConnection 0x021B9748 thumb ov114
 *   NHTTP_AddPostDataRaw 0x021BE79C arm ov114
 *   func_020092D0 0x020092D0 thumb
 *   func_020090F8 0x020090F8 thumb
 *   func_0203F1FC 0x0203F1FC arm
 *   func_02009108 0x02009108 thumb
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   GAME_DATA_PartSaveMain 0x02012E7C thumb
 *   func_0200734C 0x0200734C thumb
 *   func_0200E8E0 0x0200E8E0 thumb
 *   MUSICAL_DIST_SAVE_ProcessApply 0x0200C5F8 thumb
 *   d_021DAB88 0x021DAB88 data a1
 *   d_021DAB90 0x021DAB90 data a1
 *   d_021DAB9C 0x021DAB9C data a1
 *   MUSICAL_DIST_SAVE_GetBlockSize 0x0200C6E4 thumb
 *   func_02009390 0x02009390 thumb
 *   func_020093A8 0x020093A8 thumb
 *   func_020093F0 0x020093F0 thumb
 *   func_0203EFC8 0x0203EFC8 arm
 *   func_02009348 0x02009348 thumb
 *   func_0202A128 0x0202A128 thumb
 *   func_02019C90 0x02019C90 thumb
 *   func_02019D58 0x02019D58 thumb
 *   func_0202A19C 0x0202A19C thumb
 *   func_0200E0B0 0x0200E0B0 thumb
 *   func_0200E1A8 0x0200E1A8 thumb
 *   func_0202A170 0x0202A170 thumb
 *   func_020093D0 0x020093D0 thumb
 *   func_020092E0 0x020092E0 thumb
 *   SAVE_CONTROL_GetWorkArea 0x020071D8 thumb
 *   func_020093C8 0x020093C8 thumb
 *   func_0203F4E4 0x0203F4E4 arm
 *   func_0203F540 0x0203F540 arm
 *   GFL_NET_STATE_SetError 0x0203C9AC arm
 *   GFL_NET_STATE_SetErrorMode 0x0203C938 arm
 *   func_020093D8 0x020093D8 thumb
 *   func_02009428 0x02009428 thumb
 *   func_020185F0 0x020185F0 thumb
 *   func_02009294 0x02009294 thumb
 *   NHTTP_RAP_Destroy  0x021B9838  thumb  ov114
 *   ov114_id 0x00000072 data
 *   func_020092EC 0x020092EC thumb
 *   NHTTP_RAP_Create 0x021B9800 thumb ov114
 *   DWC_RAP_SetErrorCallback 0x02156DC4 thumb ov009
 *   d_021DABA4 0x021DABA4 data a1
 *   func_0200F7C0 0x0200F7C0 thumb
 *   DWC_RAPCOMMON_HandleNetError 0x02157170 thumb ov009
 *   func_0200FB24 0x0200FB24 thumb
 *   WIPE_SYS_Start 0x0202208C thumb
 *   func_02009448 0x02009448 thumb
 *   MUSICAL_DIST_SAVE_CreateFromData  0x0200C5C8  thumb  arm9
 *   POKE_TOOL_ClearPartyParam  0x02017528  thumb  arm9
 *   POKE_TOOL_GetBoxParam  0x020185F4  thumb  arm9
 *   SAVE_CONTROL_LoadExtraSaveWithBuffer  0x020072CC  thumb  arm9
 *   GAME_DATA_PartSaveStart  0x02012E4C  thumb  arm9
 *   GAME_DATA_GetTrainerRecord  0x02012F2C  thumb  arm9
 *   POKE_TOOL_CreateFromBoxParam  0x0201747C  thumb  arm9
 *   WIPE_SetBrightnessFadeOut  0x0202223C  thumb  arm9
 *   APP_TASKMENU_CloseMenu  0x02027858  thumb  arm9
 *   APP_TASKMENU_UpdateMenu  0x02027974  thumb  arm9
 *   APP_TASKMENU_IsFinish  0x020279E8  thumb  arm9
 *   APP_TASKMENU_GetCursorPos  0x02027A04  thumb  arm9
 *   GSYNC_MESSAGE_InitSystem 0x021D54F4 thumb ov123
 *   GSYNC_MESSAGE_UpdateSystem 0x021D562C thumb ov123
 *   GSYNC_MESSAGE_ExitSystem 0x021D5644 thumb ov123
 *   GSYNC_MESSAGE_PrintStream 0x021D56FC thumb ov123
 *   GSYNC_MESSAGE_PrintStreamId 0x021D57B8 thumb ov123
 *   GSYNC_MESSAGE_SetMonName 0x021D57D0 thumb ov123
 *   GSYNC_MESSAGE_UpdateStream 0x021D580C thumb ov123
 *   GSYNC_MESSAGE_ClearStream 0x021D584C thumb ov123
 *   GSYNC_MESSAGE_OpenYesNoMenu 0x021D5890 thumb ov123
 *   GSYNC_MESSAGE_PrintId 0x021D5950 thumb ov123
 *   GSYNC_MESSAGE_PrintInWindow 0x021D5960 thumb ov123
 *   GSYNC_MESSAGE_PrintInSubWindow 0x021D59E4 thumb ov123
 *   GSYNC_MESSAGE_ClearWindow 0x021D5A60 thumb ov123
 *   GSYNC_MESSAGE_RestartTimeIcon 0x021D5A7C thumb ov123
 *   GSYNC_MESSAGE_PrintDefault 0x021D5AB0 thumb ov123
 *   GSYNC_DOWNLOAD_AllocWork 0x021D5B10 thumb ov123
 *   GSYNC_DOWNLOAD_FreeWork 0x021D5B70 thumb ov123
 *   GSYNC_DOWNLOAD_NoteFinished 0x021D5BA0 thumb ov123
 *   GSYNC_DOWNLOAD_InitAsync 0x021D5BD4 thumb ov123
 *   GSYNC_DOWNLOAD_ClearResult 0x021D5C0C thumb ov123
 *   GSYNC_DOWNLOAD_Reset 0x021D5C2C thumb ov123
 *   GSYNC_DOWNLOAD_SetAttr 0x021D5C64 thumb ov123
 *   GSYNC_DOWNLOAD_IsBusy 0x021D5C9C thumb ov123
 *   GSYNC_DOWNLOAD_GetFileListAsync 0x021D5CF8 thumb ov123
 *   GSYNC_DOWNLOAD_GetFileAsync 0x021D5D24 thumb ov123
 *   GSYNC_DOWNLOAD_CleanupOnce 0x021D5D58 thumb ov123
 *   GSYNC_DOWNLOAD_Process 0x021D5D7C thumb ov123
 *   GSYNC_DISP_GetPokeIconActor 0x021D5D8C thumb ov123
 *   GSYNC_DISP_Init 0x021D5D94 thumb ov123
 *   GSYNC_DISP_Draw 0x021D5E60 thumb ov123
 *   GSYNC_DISP_Exit 0x021D5E8C thumb ov123
 *   GSYNC_DISP_CreateEffectActorDefault 0x021D62A8 thumb ov123
 *   GSYNC_DISP_CreateSlotActor 0x021D62B4 thumb ov123
 *   GSYNC_DISP_SetSlotAnimSeq 0x021D62BC thumb ov123
 *   GSYNC_DISP_SetSlotAnimCommand 0x021D62D0 thumb ov123
 *   GSYNC_DISP_DeleteSlotActor 0x021D62E0 thumb ov123
 *   GSYNC_DISP_SetMainActorAnimSeq 0x021D63D4 thumb ov123
 *   GSYNC_DISP_CreateMonIconActor 0x021D6458 thumb ov123
 *   GSYNC_DISP_EnableActorAutoAnim 0x021D651C thumb ov123
 *   GSYNC_DISP_RestartActorAnim 0x021D652C thumb ov123
 *   GSYNC_DISP_StartPaletteWave 0x021D65F4 thumb ov123
 *   GSYNC_DISP_SetFadeDirection 0x021D6650 thumb ov123
 *   GSYNC_DISP_UpdateProgressPosition 0x021D66D0 thumb ov123
 *   GSYNC_DISP_UpdateParticles 0x021D6934 thumb ov123
 *   GSYNC_DISP_SetIconRecord 0x021D6A70 thumb ov123
 *   GSYNC_DISP_SetIconRecordSpecies 0x021D6AA8 thumb ov123
 *   GSYNC_DISP_LoadIconResources 0x021D6AB8 thumb ov123
 */
#include "gsync_types.h"
#include "gsync_message_types.h"
#include "gsync_download_types.h"
#include "gsync_common_types.h"
#include "gsync_state_shared_types.h"

struct Sub02007454Entry;

struct Sub02007324Ctrl;

struct Sub020090B0Obj;

struct MusicalDist;

struct Sub02009210Ent;

struct Sub02008AECSession;

struct Sub02008C20Obj;

struct Mon;

struct Sub020079BCEntry;

struct Sav;

struct Sub020075B0Entry;

struct BigObj;

typedef struct { int x[8]; } Table_021D634C;

struct RtcDate_021D634C { int year; u32 month; int day, week; };

struct RtcDate_021D8A9C { u32 year, month, day, week; };

extern void WIPE_SYS_Start(void *, u32, u32, u32, u32, u32, u32);

extern int GFL_NET_GetRunState(void);

extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);

extern u8 APP_TASKMENU_GetCursorPos(const u8 *p);

extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);

extern void MI_CpuCopy8(const void *, void *, u32);

extern u32 func_020307B0(void *p);

extern u32 WIPE_SYS_EndCheck(void);

extern int TOUCHPANEL_GetTrg(void);

extern void GFL_USE_PlaySeDefaultVolume(u32 a);

extern int GAME_DATA_SaveMain(u8 *p);

extern int GAME_DATA_SaveStart(int a0);

extern void *GAME_DATA_GetSaveControl(struct Big *p);

extern void GFL_HEAP_CreateChildHeap(u32,u32,u32);

extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);

extern void MI_CpuFill8(void *,u8,u32);

extern void *func_02030734(u32,u32,int,const char *,u16);

extern void GFL_NET_RestartWithDefaultTimeout(u32,u32);

extern void APP_TASKMENU_UpdateMenu(void *);

extern void WIPE_SetBrightnessFadeOut(unsigned int,unsigned int);

extern void func_020315D4(struct S020315D4 *p);

extern void func_020306F0(unsigned int);

extern void func_02034714(const char *expr, u32 line, const char *file);

extern void DWC_RAP_SetErrorHookCallback(int a, int b);

extern int func_02034AC4(int);

extern void func_02034A5C(int);

extern u32 func_020056EC(u32 range);

extern u32 func_02019D30(u32 a, u32 n);

extern u32 KEY_GetTrg(void);

extern void GAME_DATA_SaveCancel(char *p);

extern void NHTTP_RAP_DeleteConnection(u8 *p);

extern int GFL_USE_PopBgm(void);

extern void GFL_USE_SetBgmPlayerParam(void *p);

extern void GFL_USE_FadeInBgmFull(u32 v);

extern int GFL_USE_PushBgm(void);

extern void GFL_USE_CancelChangeAndPlayBgm(int, int);

extern struct Sub02009448Obj *func_02009448(void *sys);

extern int func_020076D0(void *save, int *pbox, int *pslot);

extern u32 func_020173EC(void);

extern u8 *func_02009290(struct Sub02009210Obj *obj);

extern u32 func_02017E1C(void *p, u32 id, u32 v);

extern void func_02019CA0(void *p, u32 v);

extern void *POKE_TOOL_GetBoxParam(void *p);

extern int func_020074D8(void **save, const struct Sub02007454Entry *src);

extern void func_020092F8(struct Sub02009210Obj *obj, u8 value);

extern void func_020093D4(struct Sub02009210Obj *obj, s32 value);

extern int func_020185F0(void *);

extern int NHTTP_RAP_GetResultCode(u8 *p);

extern int NHTTP_RAP_PollConnection(u8 *p);

extern u8 *NHTTP_RAP_GetRecvBuffer(u8 *p);

extern int NHTTP_RAP_CreateRequest(int index, u8 *p);

extern int NHTTP_RAP_GetConnection(char *p);

extern int NHTTP_RAP_StartConnection(u8 *p);

extern int NHTTP_AddPostDataRaw(void *handle, void *value_p, unsigned long length);

extern void func_020092D0(struct Sub02009210Obj *obj, u8 value);

extern void func_02009348(struct Sub02009210Obj *obj, int i, u16 a, u8 b);

extern int GAME_DATA_PartSaveMain(char *p, int a1);

extern void func_0200734C(struct Sub02007324Ctrl *,unsigned int);

extern struct Sub02009210Obj *func_02009210(void *sys);

extern void func_020090F8(struct Sub020090B0Obj *obj, unsigned char value);

extern u16 func_0203F1FC(const u8 *src, u32 len);

extern int SAVE_CONTROL_LoadExtraSaveWithBuffer(int,int,u16,int,int);

extern void func_0200E8E0(void *obj, u32 value);

extern void GAME_DATA_PartSaveStart(u8 *,u32);

extern void func_02009108(struct Sub020090B0Obj *obj, u16 value);

extern u32 MUSICAL_DIST_SAVE_ProcessApply(struct MusicalDist *p);

extern struct MusicalDist *MUSICAL_DIST_SAVE_CreateFromData(void *sys, const void *src, u32 size, u32 heap);

extern u32 MUSICAL_DIST_SAVE_GetBlockSize(void);

extern u32 func_0200E8B0(void);

extern struct Sub02009210Ent *func_02009390(struct Sub02009210Obj *obj, int i);

extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);

extern void func_020093A8(struct Sub02009210Obj *obj, int i, const void *src);

extern void func_020093F0(struct Sub02009210Obj *obj, int value);

extern void *func_0202A128(int);

extern int func_02019C90(u16, int, int);

extern int func_02019D58(u16, int);

extern int func_0202A19C(u32, void *, u16, u16, int);

extern void *func_0200E0B0(void *);

extern void func_0200E1A8(void *, u16, u16, u8, int, u8, u32);

extern void func_0202A170(void *);

extern s32 func_020093D0(const struct Sub02009210Obj *obj);

extern u32 func_02009370(const struct Sub02009210Obj *obj);

extern void func_020092E0(struct Sub02009210Obj *obj, u8 value);

extern u8 *func_02012944(void *p);

extern u32 func_0200853C(const struct Sub0200852CObj *obj);

extern void *SAVE_CONTROL_GetWorkArea(struct Ctrl020071D8 *ctrl, int *out);

extern struct Sub02008AECSession *func_02008B14(void *sys);

extern int func_02008BD0(const struct Sub02008AECSession *s);

extern u32 func_020093C8(const struct Sub02009210Obj *obj);

extern void func_0203F4E4(struct RtcDate_021D634C *);

extern int func_0203F540(struct RtcDate_021D634C *);

extern void GFL_NET_STATE_SetError(int a, u32 b, u32 c, u32 d);

extern u32 GFL_NET_STATE_SetErrorMode(u8 mode);

extern void func_020093CC(struct Sub02009210Obj *obj, u32 value);

extern u32 func_020093D8(const struct Sub02009210Obj *obj);

extern void func_02009428(struct Sub02009210Obj *obj, int value);

extern void *GAME_DATA_GetTrainerRecord(int *p);

extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);

extern struct Sub020079BCEntry *func_02007A18(void **save, u32 box, u32 slot);

extern void *POKE_TOOL_CreateFromBoxParam(struct Mon *p, u32 heap);

extern void func_02009294(struct Sub02009210Obj *obj, const void *src);

extern void func_02007664(void *save, u32 box, u32 slot);

extern void NHTTP_RAP_Destroy(u8 *p);

extern u32 func_02009228(void);

extern int func_020075B0(void *save, u32 box, u32 slot, const struct Sub020075B0Entry *src);

extern void POKE_TOOL_ClearPartyParam(struct Sav *p);

extern u32 func_0201293C(const struct BigObj *p);

extern u8 func_020092EC(const struct Sub02009210Obj *obj);

extern u8 *NHTTP_RAP_Create(int,int,int);

extern void DWC_RAP_SetErrorCallback(int,int);

extern u32 func_0200FB24(void);

extern void func_0200F7C0(u32 value);

extern int DWC_RAPCOMMON_HandleNetError(int a0, int a1);

GsyncMessageWork *GSYNC_MESSAGE_InitSystem(u32 heap, u32 msgBank);

void GSYNC_MESSAGE_UpdateSystem(GsyncMessageWork *work);

void GSYNC_MESSAGE_ExitSystem(GsyncMessageWork *work);

void GSYNC_MESSAGE_PrintStream(GsyncMessageWork *work, int instant);

void GSYNC_MESSAGE_PrintStreamId(GsyncMessageWork *work, int msgId);

void GSYNC_MESSAGE_SetMonName(GsyncMessageWork *work, int msgId, int digits, void *mon);

int GSYNC_MESSAGE_UpdateStream(GsyncMessageWork *work);

void GSYNC_MESSAGE_ClearStream(GsyncMessageWork *work);

int GSYNC_MESSAGE_OpenYesNoMenu(GsyncMessageWork *work, int layout);

int GSYNC_MESSAGE_PrintId(GsyncMessageWork *work, int msgId);

void GSYNC_MESSAGE_PrintInWindow(GsyncMessageWork *work, int top, int height);

void GSYNC_MESSAGE_PrintInSubWindow(GsyncMessageWork *work);

void GSYNC_MESSAGE_ClearWindow(GsyncMessageWork *work);

void GSYNC_MESSAGE_RestartTimeIcon(GsyncMessageWork *work);

void GSYNC_MESSAGE_PrintDefault(GsyncMessageWork *work, int value);

GsyncDownloadWork *GSYNC_DOWNLOAD_AllocWork(int heap, int fileBufferSize);

void GSYNC_DOWNLOAD_FreeWork(GsyncDownloadWork *work);

void *GSYNC_DOWNLOAD_NoteFinished(GsyncDownloadWork *work);

int GSYNC_DOWNLOAD_InitAsync(GsyncDownloadWork *p);

int GSYNC_DOWNLOAD_ClearResult(GsyncDownloadWork *work);

int GSYNC_DOWNLOAD_Reset(GsyncDownloadWork *work);

int GSYNC_DOWNLOAD_SetAttr(GsyncDownloadWork *p,void *arg,int value);

void GSYNC_DOWNLOAD_IsBusy(GsyncDownloadWork *p);

int GSYNC_DOWNLOAD_GetFileListAsync(GsyncDownloadWork *p);

int GSYNC_DOWNLOAD_GetFileAsync(GsyncDownloadWork *p);

int GSYNC_DOWNLOAD_CleanupOnce(GsyncDownloadWork *p);

void GSYNC_DOWNLOAD_Process(GsyncDownloadWork *work);

void *GSYNC_DISP_GetPokeIconActor(GsyncStateObj2 *p);

u8 *GSYNC_DISP_Init(u32 heap);

void GSYNC_DISP_Draw(GsyncStateObj2 *p);

void GSYNC_DISP_Exit(GsyncStateObj2 *p);

void GSYNC_DISP_CreateEffectActorDefault(GsyncStateObj15 *p);

void GSYNC_DISP_CreateSlotActor(GsyncStateObj17 *p,unsigned int i);

void GSYNC_DISP_SetSlotAnimSeq(u8 *p, int i, u32 v);

void GSYNC_DISP_SetSlotAnimCommand(u8 *p, int i, int v);

void GSYNC_DISP_DeleteSlotActor(u8 *p, int i);

void GSYNC_DISP_SetMainActorAnimSeq(GsyncStateObj2 *p);

void GSYNC_DISP_CreateMonIconActor(struct GsyncObj171 *p, void *n, int i);

void GSYNC_DISP_EnableActorAutoAnim(GsyncStateObj2 *p);

void GSYNC_DISP_RestartActorAnim(GsyncStateObj2 *p);

void GSYNC_DISP_StartPaletteWave(GsyncStateObj2 *p);

void GSYNC_DISP_SetFadeDirection(GsyncStateObj1 *p,int flag);

void GSYNC_DISP_UpdateProgressPosition(GsyncStateObj2 *p, int n);

void GSYNC_DISP_UpdateParticles(struct Obj *p);

void GSYNC_DISP_SetIconRecord(u8 *p,int i,int a,int b,int c);

void GSYNC_DISP_SetIconRecordSpecies(char *p, int i, u16 v);

void GSYNC_DISP_LoadIconResources(GsyncStateObj2 *p);

int GSYNC_STATE_HandleHttpError(GsyncStateObj1 *p,int x);

int GSYNC_STATE_IsConnectionAlive(GsyncStateObj1 *p);

int GSYNC_STATE_IsCommIdleWithTarget(GsyncStateObj1 *p);

int GSYNC_STATE_IsCommReady(GsyncStateObj1 *p);

void GSYNC_STATE_SetNextState(GsyncStateObj1 *p,u32 v,int unused);

void GSYNC_STATE_ChangeState(GsyncStateObj1 *p,u32 v,int unused);

void GSYNC_STATE_StateWaitFade(char *p);

void GSYNC_STATE_StateFadeOutAfterMessage(char *p);

void GSYNC_STATE_StateFreeDownloadAndExit(u8 *p);

void GSYNC_STATE_StateWaitInputCancelSave(unsigned char *a);

void GSYNC_STATE_StateErrorMessage(char *p);

void GSYNC_STATE_StateSetErrorExit(char *p);

void GSYNC_STATE_StateWaitMessageInput(char *p);

void GSYNC_STATE_StateClearMessageExit(char *p);

void GSYNC_STATE_StateWaitEndingBgm(char *p);

void GSYNC_STATE_StateShowResultMessage(int a);

void GSYNC_STATE_ResetSlotActors(char *p);

void GSYNC_STATE_LoadReceivedMon(GsyncStateObj1 *p);

void GSYNC_STATE_StateSaveFinishMessage(char *p);

void GSYNC_STATE_StatePollResponse(char *p);

void GSYNC_STATE_StateSendRequest(char *p);

void GSYNC_STATE_StateSaveMainWait(u8 *p);

void GSYNC_STATE_StateSaveStart(int a);

void GSYNC_STATE_StateCleanupDownload(int a);

void GSYNC_STATE_StateFreeReceivedMon(u8 *p);

void GSYNC_STATE_StateExtraSaveMain(u8 *a);

void GSYNC_STATE_StateExtraSaveLoadStart(int a);

void GSYNC_STATE_StateFreeExtraSaveBuffer(u8 *p);

void GSYNC_STATE_StateExtraSaveMainSecond(char *p);

void GSYNC_STATE_StateExtraSaveLoadStartSecond(int a);

void GSYNC_STATE_StateMusicalSaveApply(u8 *p);

void GSYNC_STATE_StateMusicalSaveCreate(int a,int n);

void GSYNC_STATE_StateDownloadReset(int a);

void GSYNC_STATE_StateMusicalSaveRetry(int a);

void GSYNC_STATE_StateWaitDownloadIdle(int a);

void GSYNC_STATE_StateRequestFile(int a);

void GSYNC_STATE_StateWaitDownloadIdleThenRequest(int a);

void GSYNC_STATE_StateRequestFileList(int a);

void GSYNC_STATE_StateSetFileAttribute(u8 *p);

void GSYNC_STATE_StateInitDownload(char *p);

void GSYNC_STATE_StateSelectNextDownload(char *p);

void GSYNC_STATE_CopyMonRecord(void *p, char *q);

int GSYNC_STATE_GetEntryCount(int a,u8 *p);

int GSYNC_STATE_GetListEntry(int a,GsyncStateObj3 *p);

void GSYNC_STATE_BuildMonEntry(GsyncStateObj1 *p, int unused, int species, int gender, int form, int n, int value);

void GSYNC_STATE_BuildMonEntries(GsyncStateObj1 *p,int a,u8 *records);

void GSYNC_STATE_ApplyIconRecords(GsyncStateObj1 *p,GsyncStateObj3 *list);

void GSYNC_STATE_PrepareReceivedList(GsyncStateObj1 *p, void *h, GsyncStateObj3 *q, int *r);

int GSYNC_STATE_UpdateCurrentEntry(GsyncStateObj1 *p);

void GSYNC_STATE_StateReceiveList(char *p);

void GSYNC_STATE_StateSendListRequest(char *p);

void GSYNC_STATE_StateWaitMessageThenSend(char *p);

void GSYNC_STATE_StateShowProgressMessage(char *p);

void GSYNC_STATE_StateWaitInputFirst(char *p);

void GSYNC_STATE_StateWaitMessageThenPrintSecond(char *p);

void GSYNC_STATE_StateWaitInputSecond(char *p);

void GSYNC_STATE_StateWaitMessageThenPrintThird(char *p);

void GSYNC_STATE_StateConfirmMenuSelect(char *p);

void GSYNC_STATE_StateOpenConfirmMenu(char *p);

void GSYNC_STATE_StateShowEmptyMessage(char *p);

void GSYNC_STATE_StateWaitMessageEnd(char *p);

void GSYNC_STATE_StateWaitInputClearWindow(char *p);

void GSYNC_STATE_StateWaitInputPrintNext(char *p);

void GSYNC_STATE_StatePrintErrorMessage(char *p);

void GSYNC_STATE_StateReceiveResponse(char *p);

void GSYNC_STATE_StateSendResponse(char *p);

void GSYNC_STATE_StateWaitInputThird(char *p);

void GSYNC_STATE_StateWaitMessageThenPrintFourth(char *p);

void GSYNC_STATE_StateWaitInputFourth(char *p);

void GSYNC_STATE_StateWaitMessageThenPrintFifth(char *p);

void GSYNC_STATE_ParseResponse(GsyncStateObj1 *p,int x,int *q);

void GSYNC_STATE_StateReceiveParsedResponse(char *p);

void GSYNC_STATE_StateSendParsedRequest(char *p);

void GSYNC_STATE_StateWaitMessageClearStream(char *p);

void GSYNC_STATE_StatePrintFinalMessage(char *p);

void GSYNC_STATE_StateReceiveFinalResponse(char *p);

void GSYNC_STATE_StateSendFinalRequest(char *p);

void GSYNC_STATE_StatePlaySeWaitInput(char *p);

void GSYNC_STATE_StateWaitMessageThenNext(char *p);

void GSYNC_STATE_StateShowCompletionMessage(char *p);

void GSYNC_STATE_StateSaveErrorExit(char *p);

void GSYNC_STATE_StateTrainerRecordSaveStart(char *p);

void GSYNC_STATE_StateReceiveRecordResponse(char *p);

void GSYNC_STATE_StateSendRecordRequest(char *p);

void GSYNC_STATE_StateStartTransferAnimation(char *p);

void GSYNC_STATE_StateTransferAnimationStep(char *p);

void GSYNC_STATE_StateTransferAnimationOpen(char *p);

void GSYNC_STATE_StateTransferAnimationEffect(char *p);

void GSYNC_STATE_StateCreateReceivedMonIcon(char *p);

void GSYNC_STATE_StateStoreReceivedMon(char *p);

void GSYNC_STATE_DestroyHttpConnection(char *p);

void GSYNC_STATE_CommitReceivedMon(GsyncStateObj1 *p);

int GSYNC_STATE_ProcInit(void *a,int b,GsyncStateObj3 *q);

int GSYNC_STATE_ProcMain(void *a, int b, int c, GsyncStateObj1 *p);

int GSYNC_STATE_ProcExit(void *a, int b, int c, GsyncStateObj10 *p);

extern const Table_021D634C d_021DA844;

extern const char d_021DAB78[];

extern const char d_021DAB88[];

extern const char d_021DAB90[];

extern const char d_021DAB9C[];

extern char ov114_id[];

extern const char d_021DABA4[];

int GSYNC_STATE_HandleHttpError(GsyncStateObj1 *p,int x)
{
    switch (x) {
    case 503:
        p->f80=0xfff1;
        GSYNC_STATE_ChangeState(p,(int)GSYNC_STATE_StateErrorMessage,0xd3);
        return 1;
    case 502:
        p->f80=0xfff2;
        GSYNC_STATE_ChangeState(p,(int)GSYNC_STATE_StateErrorMessage,0xd7);
        return 1;
    }
    if (x>=400) {
        p->f80=0xfff3;
        GSYNC_STATE_ChangeState(p,(int)GSYNC_STATE_StateErrorMessage,0xdd);
        return 1;
    }
    return 0;
}

int GSYNC_STATE_IsConnectionAlive(GsyncStateObj1 *p){u8 *q=p->f20;if(((GsyncStateObj22 *)q)->f1C8==2)return 0;if(((GsyncStateObj22 *)q)->f50 && ((GsyncStateObj22 *)q)->fC==4)return 0;if(GFL_NET_GetRunState())return 1;return 0;}

int GSYNC_STATE_IsCommIdleWithTarget(GsyncStateObj1 *p)
{
    char *q = p->f20;

    return ((GsyncStateObj26 *)q)->f50 != 0 && ((GsyncStateObj26 *)q)->fC == 0;
}

int GSYNC_STATE_IsCommReady(GsyncStateObj1 *p){u8 *q=p->f20;if(((GsyncStateObj27 *)q)->f50){unsigned int x=((GsyncStateObj27 *)q)->fC;if(x==0)return 1;if(x==4)return 1;}return 0;}

void GSYNC_STATE_SetNextState(GsyncStateObj1 *p,u32 v,int unused){p->f50=v;}

void GSYNC_STATE_ChangeState(GsyncStateObj1 *p,u32 v,int unused){GSYNC_STATE_SetNextState(p,v,unused);}

void GSYNC_STATE_StateWaitFade(char *p)
{
    if (WIPE_SYS_EndCheck() != 0)
        GSYNC_STATE_ChangeState((GsyncStateObj1 *)p, 0, 0x157);
}

void GSYNC_STATE_StateFadeOutAfterMessage(char *p)
{
    if (GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18))) {
        WIPE_SYS_Start(0,0,0,0,6,1,((GsyncStateObj1 *)p)->f0);
        GSYNC_STATE_ChangeState((GsyncStateObj1 *)p,(int)GSYNC_STATE_StateWaitFade,0x16b);
    }
}

void GSYNC_STATE_StateFreeDownloadAndExit(u8 *p){if(GSYNC_DOWNLOAD_ClearResult((GsyncDownloadWork *)((char *)(((GsyncStateObj1 *)p)->f8)))){GSYNC_DOWNLOAD_FreeWork((GsyncDownloadWork *)((char *)(((GsyncStateObj1 *)p)->f8)));((GsyncStateObj1 *)p)->f8=0;GSYNC_STATE_ChangeState((GsyncStateObj1 *)p,(u32)GSYNC_STATE_StateSetErrorExit,0x17c);}}

void GSYNC_STATE_StateWaitInputCancelSave(unsigned char *a)
{
    if (((GsyncStateObj1 *)a)->fAB != 0)
        return;
    if (KEY_GetTrg() == 0 && TOUCHPANEL_GetTrg() == 0)
        return;
    if (((GsyncStateObj1 *)a)->fAD != 0) {
        GAME_DATA_SaveCancel((char *)(((GsyncStateObj1 *)a)->f2C));
        ((GsyncStateObj1 *)a)->fAD = 0;
    }
    GSYNC_STATE_CommitReceivedMon((GsyncStateObj1 *)a);
    if (((GsyncStateObj1 *)a)->f8 != 0) {
        if (GSYNC_DOWNLOAD_CleanupOnce((GsyncDownloadWork *)((char *)(((GsyncStateObj1 *)a)->f8))) != 0)
            GSYNC_STATE_ChangeState((GsyncStateObj1 *)a, (int)GSYNC_STATE_StateFreeDownloadAndExit, 0x191);
        GSYNC_STATE_ChangeState((GsyncStateObj1 *)a, 0x021D706D, 0x193);
    } else {
        GSYNC_STATE_ChangeState((GsyncStateObj1 *)a, 0x021D706D, 0x196);
    }
}

/*
 * extent: unit includes the 28-byte store-and-tail stub at 021D706C.
 */
void GSYNC_STATE_StateErrorMessage(char *p)
{
    int n=((GsyncStateObj1 *)p)->f80+29;
    if (((GsyncStateObj1 *)p)->f10) NHTTP_RAP_DeleteConnection(((GsyncStateObj1 *)p)->f10);
    if (((GsyncStateObj1 *)p)->f80==0xfff0) n=39;
    else if (((GsyncStateObj1 *)p)->f80==0xfff1) n=40;
    else if (((GsyncStateObj1 *)p)->f80==0xfff2) n=41;
    else if (((GsyncStateObj1 *)p)->f80==0xfff3) n=38;
    else if (((GsyncStateObj1 *)p)->f80<=0 || ((GsyncStateObj1 *)p)->f80>=10) n=38;
    GSYNC_MESSAGE_ClearStream((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18));
    GSYNC_MESSAGE_PrintId((GsyncMessageWork *)((u8 *)(((GsyncStateObj1 *)p)->f18)),n);
    GSYNC_MESSAGE_PrintInWindow((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18),1,16);
    GSYNC_STATE_ChangeState((GsyncStateObj1 *)p,(int)GSYNC_STATE_StateWaitInputCancelSave,0x1b9);
}

void GSYNC_STATE_StateSetErrorExit(char *p)
{
    ((struct GsyncObj173 *)(((GsyncStateObj1 *)p)->f20))->f1C8=6;
    GSYNC_STATE_ChangeState((GsyncStateObj1 *)p,(int)GSYNC_STATE_StateFadeOutAfterMessage,0x1c9);
}

void GSYNC_STATE_StateWaitMessageInput(char *p) { if(GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18)) && (KEY_GetTrg() || TOUCHPANEL_GetTrg())) GSYNC_STATE_ChangeState((GsyncStateObj1 *)p,(int)GSYNC_STATE_StateSetErrorExit,0x1d9); }

void GSYNC_STATE_StateClearMessageExit(char *p)
{
    Table_021D634C t=d_021DA844;
    if (((GsyncStateObj1 *)p)->fA8) {
        GSYNC_MESSAGE_ClearStream((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18));
        GSYNC_MESSAGE_PrintId((GsyncMessageWork *)((u8 *)(((GsyncStateObj1 *)p)->f18)),t.x[((GsyncStateObj1 *)p)->fA8]);
        GSYNC_MESSAGE_PrintInWindow((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18),1,8);
        GSYNC_STATE_ChangeState((GsyncStateObj1 *)p,(int)GSYNC_STATE_StateWaitMessageInput,0x1f0);
    } else {
        GSYNC_STATE_ChangeState((GsyncStateObj1 *)p,(int)GSYNC_STATE_StateSetErrorExit,0x1f3);
    }
}

void GSYNC_STATE_StateWaitEndingBgm(char *p)
{
    if (GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(*(char **)(p + 0x18))) != 0) {
        int n = *(int *)(p + 0x78) - 1;
        *(int *)(p + 0x78) = n;
        if (n <= 0) {
            if (n == 0) {
                GFL_USE_PopBgm();
                GFL_USE_SetBgmPlayerParam(0);
                GFL_USE_FadeInBgmFull(6);
            }
            if (KEY_GetTrg() != 0 || TOUCHPANEL_GetTrg() != 0) {
                GSYNC_STATE_ChangeState((GsyncStateObj1 *)p, (int)GSYNC_STATE_StateClearMessageExit, 0x20B);
            }
        }
    }
}

void GSYNC_STATE_StateShowResultMessage(int a)
{
    if (GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)((char *)((*(int *)&((GsyncStateObj1 *)a)->f18)))) == 0)
        return;
    if (KEY_GetTrg() == 0 && TOUCHPANEL_GetTrg() == 0)
        return;
    if (((GsyncStateObj1 *)a)->f6C == 0) {
        GSYNC_STATE_ChangeState((GsyncStateObj1 *)a, (int)GSYNC_STATE_StateClearMessageExit, 0x217);
        return;
    }
    GSYNC_MESSAGE_ClearWindow((GsyncMessageWork *)((char *)((*(int *)&((GsyncStateObj1 *)a)->f18))));
    GSYNC_MESSAGE_SetMonName((void *)((*(int *)&((GsyncStateObj1 *)a)->f18)), 0x16, ((GsyncStateObj1 *)a)->f6C,
                 (void *)((*(int *)&((GsyncStateObj1 *)a)->fC)));
    GSYNC_MESSAGE_PrintStream((GsyncMessageWork *)((char *)((*(int *)&((GsyncStateObj1 *)a)->f18))), 0);
    GFL_USE_SetBgmPlayerParam((void *)1);
    GFL_USE_PushBgm();
    GFL_USE_CancelChangeAndPlayBgm(0x515, 0xffff);
    ((GsyncStateObj1 *)a)->f78 = 0xb4;
    GSYNC_STATE_ChangeState((GsyncStateObj1 *)a, (int)GSYNC_STATE_StateWaitEndingBgm, 0x222);
}

void GSYNC_STATE_ResetSlotActors(char *p) { GSYNC_DISP_SetSlotAnimSeq(((GsyncStateObj1 *)p)->f14,0,0); GSYNC_DISP_CreateSlotActor((GsyncStateObj17 *)((u8 *)(((GsyncStateObj1 *)p)->f14)),12); GSYNC_DISP_SetMainActorAnimSeq((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f14)); }

/*
 * lever: update the call-result local in both clamp arms to preserve its register.
 */
void GSYNC_STATE_LoadReceivedMon(GsyncStateObj1 *p)
{
    void *g;
    void *q;
    int size;
    int n;
    g=func_02009448(p->f28);
    if (p->fC) {
        func_020307B0(p->fC);
        p->fC=0;
    }
    if (func_020076D0(p->f24,(int *)((char *)p+0x48),(int *)((char *)p+0x4c))) {
        q=func_02030734(p->f0,func_020173EC(),1,d_021DAB78,0x245);
        size=func_020173EC();
        MI_CpuCopy8(func_02009290(g),q,size);
        if (p->f6C) {
            n=func_02017E1C(q,158,0);
            if (n==100) p->f6C=0;
            if (n+p->f6C>100) {
                p->f6C=100-n;
                n=100;
            } else {
                n+=p->f6C;
            }
            func_02019CA0(q,n);
        }
        func_020074D8(p->f24,(const struct Sub02007454Entry *)((int)POKE_TOOL_GetBoxParam(q)));
        p->fC=q;
        func_020092F8(g,0);
        func_020093D4(g,p->f7C);
    }
}

void GSYNC_STATE_StateSaveFinishMessage(char *p)
{
    NotifyCallback cb;
    func_02009448(((GsyncStateObj1 *)p)->f28);
    if (GAME_DATA_SaveMain((*(void * *)&((GsyncStateObj1 *)p)->f2C))==2) {
        ((GsyncStateObj1 *)p)->fAD=0;
        ((GsyncStateObj1 *)p)->fAB=0;
        ((GsyncStateObj1 *)p)->fAE=0;
        GSYNC_MESSAGE_ClearStream((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18));
        GSYNC_MESSAGE_SetMonName(((GsyncStateObj1 *)p)->f18,45,0,(void *)(*(int *)&((GsyncStateObj1 *)p)->fC));
        GSYNC_MESSAGE_PrintInWindow((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18),1,4);
        GSYNC_DISP_CreateSlotActor((GsyncStateObj17 *)((u8 *)(((GsyncStateObj1 *)p)->f14)),0);
        GSYNC_DISP_SetSlotAnimSeq((u8 *)(((GsyncStateObj1 *)p)->f14),6,7);
        GSYNC_DISP_SetSlotAnimSeq((u8 *)(((GsyncStateObj1 *)p)->f14),0,1);
        cb.value=0; cb.object=p; cb.callback=GSYNC_STATE_ResetSlotActors;
        GSYNC_DISP_SetSlotAnimCommand((u8 *)(((GsyncStateObj1 *)p)->f14),0,(int)&cb);
        GSYNC_DISP_SetFadeDirection((GsyncStateObj1 *)((u8 *)(((GsyncStateObj1 *)p)->f14)),0);
        GSYNC_DISP_CreateMonIconActor((struct GsyncObj171 *)(((GsyncStateObj1 *)p)->f14),(void *)func_020185F0(((GsyncStateObj1 *)p)->fC),0);
        GSYNC_DISP_RestartActorAnim((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f14));
        GFL_USE_PlaySeDefaultVolume(0x658);
        GSYNC_STATE_ChangeState((GsyncStateObj1 *)p,(int)GSYNC_STATE_StateShowResultMessage,0x295);
    }
}

void GSYNC_STATE_StatePollResponse(char *p)
{
    if (GSYNC_STATE_HandleHttpError((GsyncStateObj1 *)p,NHTTP_RAP_GetResultCode(((GsyncStateObj1 *)p)->f10))==0) {
        if (NHTTP_RAP_PollConnection(((GsyncStateObj1 *)p)->f10)==0) {
            NHTTP_RAP_GetRecvBuffer(((GsyncStateObj1 *)p)->f10);
            func_02009448(((GsyncStateObj1 *)p)->f28);
            ((GsyncStateObj1 *)p)->fAE=1;
            GSYNC_STATE_ChangeState((GsyncStateObj1 *)p,(int)GSYNC_STATE_StateSaveFinishMessage,0x2ae);
        }
    }
}

void GSYNC_STATE_StateSendRequest(char *p)
{
    if (((GsyncStateObj1 *)p)->f78) {
        --((GsyncStateObj1 *)p)->f78;
        return;
    }
    if (GFL_NET_GetRunState()) {
        if (NHTTP_RAP_CreateRequest(8,((GsyncStateObj1 *)p)->f10)) {
            p[2]=1;
            p[3]=0;
            NHTTP_AddPostDataRaw((void *)NHTTP_RAP_GetConnection(((GsyncStateObj1 *)p)->f10),(void *)((unsigned int)(p+2)),4);
            if (NHTTP_RAP_StartConnection(((GsyncStateObj1 *)p)->f10)==0)
                GSYNC_STATE_ChangeState((GsyncStateObj1 *)p,(int)GSYNC_STATE_StatePollResponse,0x2cd);
        }
    }
}

void GSYNC_STATE_StateSaveMainWait(u8 *p) { if(((GsyncStateObj1 *)p)->f70<100) ++((GsyncStateObj1 *)p)->f70; GSYNC_DISP_UpdateProgressPosition((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f14),((GsyncStateObj1 *)p)->f70); if(GAME_DATA_SaveMain((*(void * *)&((GsyncStateObj1 *)p)->f2C))==1) { ((GsyncStateObj1 *)p)->f78=func_020056EC(190); GSYNC_STATE_ChangeState((GsyncStateObj1 *)p,(int)GSYNC_STATE_StateSendRequest,0x2e6); } }

void GSYNC_STATE_StateSaveStart(int a)
{
    int b;
    int i;
    u8 *p;
    b=(int)func_02009448((void *)((*(int *)&((GsyncStateObj1 *)a)->f28)));
    ((GsyncStateObj1 *)a)->fAB=1;
    GSYNC_STATE_LoadReceivedMon((GsyncStateObj1 *)a);
    if(GSYNC_STATE_IsCommReady((GsyncStateObj1 *)a)==0) {
        GSYNC_STATE_GetEntryCount(b,(u8 *)(((GsyncStateObj1 *)a)->f38));
        GSYNC_STATE_BuildMonEntries((GsyncStateObj1 *)a,b,(u8 *)(((GsyncStateObj1 *)a)->f38));
        GSYNC_STATE_CopyMonRecord((void *)b,(char *)(((GsyncStateObj1 *)a)->f38));
        func_020092D0((struct Sub02009210Obj *)b,*(u8 *)(((GsyncStateObj1 *)a)->f38+0x5a));
    } else {
        p=(u8 *)((GsyncStateObj1 *)a)->f20+0xc;
        GSYNC_STATE_BuildMonEntry((GsyncStateObj1 *)a,b,((GsyncStateObj28 *)p)->f2,p[7],p[6],((GsyncStateObj28 *)p)->f4,func_020056EC(8));
        for(i=0;i<20;i++) func_02009348((struct Sub02009210Obj *)b,i,*(u16 *)(p+8+i*2),p[0x30+i]);
    }
    ((GsyncStateObj1 *)a)->fAD=1;
    GAME_DATA_SaveStart(((GsyncStateObj1 *)a)->f2C);
    GSYNC_STATE_ChangeState((GsyncStateObj1 *)a,(int)GSYNC_STATE_StateSaveMainWait,0x311);
}

void GSYNC_STATE_StateCleanupDownload(int a)
{
    if (GSYNC_DOWNLOAD_CleanupOnce((GsyncDownloadWork *)((char *)(((GsyncStateObj1 *)a)->f8)))) {
        GSYNC_STATE_ChangeState((GsyncStateObj1 *)a, (int)GSYNC_STATE_StateDownloadReset, 0x319);
        return;
    }
    ((GsyncStateObj1 *)a)->f80 = 0xfff0;
    GSYNC_STATE_ChangeState((GsyncStateObj1 *)a, (int)GSYNC_STATE_StateErrorMessage, 0x31d);
}

void GSYNC_STATE_StateFreeReceivedMon(u8 *p) { p[165]=0; func_020307B0(((GsyncStateObj1 *)p)->f40); p[174]=0; ((GsyncStateObj1 *)p)->f40=0; GSYNC_STATE_ChangeState((GsyncStateObj1 *)p,(int)GSYNC_STATE_StateCleanupDownload,0x328); }

void GSYNC_STATE_StateExtraSaveMain(u8 *a)
{
    int b = (int)GAME_DATA_GetSaveControl((struct Big *)(((GsyncStateObj1 *)a)->f2C));
    if(GAME_DATA_PartSaveMain((char *)(((GsyncStateObj1 *)a)->f2C),4)==2) {
        func_0200734C((struct Sub02007324Ctrl *)b,4);
        func_020090F8((struct Sub020090B0Obj *)func_02009210((void *)b),1);
        GSYNC_STATE_ChangeState((GsyncStateObj1 *)a,(int)GSYNC_STATE_StateFreeReceivedMon,0x333);
    }
}

void GSYNC_STATE_StateExtraSaveLoadStart(int a)
{
    u16 checksum;
    int b;
    u8 *p;
    int x;
    b=(int)GAME_DATA_GetSaveControl((struct Big *)(((GsyncStateObj1 *)a)->f2C));
    p=(u8 *)GSYNC_DOWNLOAD_NoteFinished((GsyncDownloadWork *)((char *)(((GsyncStateObj1 *)a)->f8)));
    checksum=func_0203F1FC(p,0x2600);
    if(checksum!=((GsyncStateObj31 *)p)->f2600) {
        ((GsyncStateObj1 *)a)->f80=0xfff0;
        GSYNC_STATE_ChangeState((GsyncStateObj1 *)a,(int)GSYNC_STATE_StateErrorMessage,0x345);
        return;
    }
    ((GsyncStateObj1 *)a)->fAE=1;
    x=(int)func_02030734(((GsyncStateObj1 *)a)->f0,0x3000,0,d_021DAB78,0x34a);
    (*(int *)&((GsyncStateObj1 *)a)->f40)=x;
    SAVE_CONTROL_LoadExtraSaveWithBuffer(b,4,((GsyncStateObj1 *)a)->f0,x,0x3000);
    MI_CpuCopy8(p,(void *)x,0x2600);
    func_02009108((struct Sub020090B0Obj *)func_02009210((void *)b),checksum);
    GAME_DATA_PartSaveStart((u8 *)((GsyncStateObj1 *)a)->f2C,4);
    GSYNC_STATE_ChangeState((GsyncStateObj1 *)a,(int)GSYNC_STATE_StateExtraSaveMain,0x355);
}

void GSYNC_STATE_StateFreeExtraSaveBuffer(u8 *p) { p[166]=0; func_020307B0(((GsyncStateObj1 *)p)->f3C); p[174]=0; ((GsyncStateObj1 *)p)->f3C=0; GSYNC_STATE_ChangeState((GsyncStateObj1 *)p,(int)GSYNC_STATE_StateCleanupDownload,0x360); }

void GSYNC_STATE_StateExtraSaveMainSecond(char *p) { int v; v=(int)GAME_DATA_GetSaveControl((struct Big *)(((GsyncStateObj1 *)p)->f2C)); if(GAME_DATA_PartSaveMain((char *)(((GsyncStateObj1 *)p)->f2C),7)==2) { func_0200734C((struct Sub02007324Ctrl *)v,7); GSYNC_STATE_ChangeState((GsyncStateObj1 *)p,(int)GSYNC_STATE_StateFreeExtraSaveBuffer,0x36a); } }

void GSYNC_STATE_StateExtraSaveLoadStartSecond(int a)
{
    int b;
    u8 *p;
    int x;
    u16 checksum;
    b=(int)GAME_DATA_GetSaveControl((struct Big *)(((GsyncStateObj1 *)a)->f2C));
    p=(u8 *)GSYNC_DOWNLOAD_NoteFinished((GsyncDownloadWork *)((char *)(((GsyncStateObj1 *)a)->f8)));
    checksum=func_0203F1FC(p,0x6200);
    if(checksum!=((GsyncStateObj32 *)p)->f6200) {
        ((GsyncStateObj1 *)a)->f80=0xfff0;
        GSYNC_STATE_ChangeState((GsyncStateObj1 *)a,(int)GSYNC_STATE_StateErrorMessage,0x378);
        return;
    }
    ((GsyncStateObj1 *)a)->fAE=1;
    x=(int)func_02030734(((GsyncStateObj1 *)a)->f0,0x6800,0,d_021DAB78,0x37d);
    *(int *)&((GsyncStateObj1 *)a)->f3C=x;
    SAVE_CONTROL_LoadExtraSaveWithBuffer(b,7,((GsyncStateObj1 *)a)->f0,*(int *)&((GsyncStateObj1 *)a)->f3C,0x6800);
    MI_CpuCopy8(p,((GsyncStateObj1 *)a)->f3C,0x6200);
    func_0200E8E0((void *)(*(int *)&((GsyncStateObj1 *)a)->f3C),1);
    GAME_DATA_PartSaveStart((u8 *)((GsyncStateObj1 *)a)->f2C,7);
    GSYNC_STATE_ChangeState((GsyncStateObj1 *)a,(int)GSYNC_STATE_StateExtraSaveMainSecond,0x383);
}

void GSYNC_STATE_StateMusicalSaveApply(u8 *p) { if(MUSICAL_DIST_SAVE_ProcessApply(((GsyncStateObj1 *)p)->f30)) { p[174]=0; ((GsyncStateObj1 *)p)->f30=0; GSYNC_STATE_ChangeState((GsyncStateObj1 *)p,(int)GSYNC_STATE_StateCleanupDownload,0x38e); } }

void GSYNC_STATE_StateMusicalSaveCreate(int a,int n)
{
    u8 *p;
    int h;
    u16 checksum;
    ((GsyncStateObj1 *)a)->fA4=0;
    p=(u8 *)GSYNC_DOWNLOAD_NoteFinished((GsyncDownloadWork *)((char *)(((GsyncStateObj1 *)a)->f8)));
    h=n/2;
    if(n>0x1fc0e) {
        ((GsyncStateObj1 *)a)->f80=0xfff0;
        GSYNC_STATE_ChangeState((GsyncStateObj1 *)a,(int)GSYNC_STATE_StateErrorMessage,0x39d);
        return;
    }
    checksum=func_0203F1FC(p,n);
    if(checksum!=*(u16 *)(p+h*2)) {
        ((GsyncStateObj1 *)a)->f80=0xfff0;
        GSYNC_STATE_ChangeState((GsyncStateObj1 *)a,(int)GSYNC_STATE_StateErrorMessage,0x3a3);
        return;
    }
    ((GsyncStateObj1 *)a)->fAE=1;
    (*(int *)&((GsyncStateObj1 *)a)->f30)=(int)MUSICAL_DIST_SAVE_CreateFromData((void *)(((GsyncStateObj1 *)a)->f2C),p,n,((GsyncStateObj1 *)a)->f0);
    GSYNC_STATE_ChangeState((GsyncStateObj1 *)a,(int)GSYNC_STATE_StateMusicalSaveApply,0x3a9);
}

void GSYNC_STATE_StateDownloadReset(int a)
{
    if(GSYNC_DOWNLOAD_ClearResult((GsyncDownloadWork *)((char *)(((GsyncStateObj1 *)a)->f8)))) {
        if(GSYNC_DOWNLOAD_Reset((GsyncDownloadWork *)((char *)(((GsyncStateObj1 *)a)->f8)))) {
            ((GsyncStateObj1 *)a)->f80=0xfff0;
            GSYNC_STATE_ChangeState((GsyncStateObj1 *)a,(int)GSYNC_STATE_StateErrorMessage,0x3b6);
            return;
        }
        GSYNC_DOWNLOAD_FreeWork((GsyncDownloadWork *)((char *)(((GsyncStateObj1 *)a)->f8)));
        ((GsyncStateObj1 *)a)->f8=0;
        if(((int *)a)[28]<100) ((int *)a)[28]+=10;
        GSYNC_DISP_UpdateProgressPosition((GsyncStateObj2 *)(((GsyncStateObj1 *)a)->f14),((GsyncStateObj1 *)a)->f70);
        GSYNC_STATE_ChangeState((GsyncStateObj1 *)a,(int)GSYNC_STATE_StateSelectNextDownload,0x3c3);
    }
}

void GSYNC_STATE_StateMusicalSaveRetry(int a)
{
    switch(((GsyncStateObj1 *)a)->fA7) {
    case 0: GSYNC_STATE_ChangeState((GsyncStateObj1 *)a,(int)GSYNC_STATE_StateExtraSaveLoadStart,0x3cb); break;
    case 1: GSYNC_STATE_StateMusicalSaveCreate(a,(int)GSYNC_DISP_GetPokeIconActor((GsyncStateObj2 *)((u8 *)(((GsyncStateObj1 *)a)->f8)))-2); break;
    case 2: GSYNC_STATE_ChangeState((GsyncStateObj1 *)a,(int)GSYNC_STATE_StateExtraSaveLoadStartSecond,0x3d1); break;
    }
}

void GSYNC_STATE_StateWaitDownloadIdle(int a)
{
    if(GSYNC_DOWNLOAD_Reset((GsyncDownloadWork *)((char *)(((GsyncStateObj1 *)a)->f8)))) {
        ((GsyncStateObj1 *)a)->f80=0xfff0;
        GSYNC_STATE_ChangeState((GsyncStateObj1 *)a,(int)GSYNC_STATE_StateErrorMessage,0x3dd);
        return;
    }
    if(GSYNC_DOWNLOAD_ClearResult((GsyncDownloadWork *)((char *)(((GsyncStateObj1 *)a)->f8)))) {
        GSYNC_DOWNLOAD_IsBusy((GsyncDownloadWork *)((char *)(((GsyncStateObj1 *)a)->f8)));
        GSYNC_STATE_ChangeState((GsyncStateObj1 *)a,(int)GSYNC_STATE_StateMusicalSaveRetry,0x3e8);
    }
}

void GSYNC_STATE_StateRequestFile(int a)
{
    if (GSYNC_DOWNLOAD_GetFileAsync((GsyncDownloadWork *)((char *)(((GsyncStateObj1 *)a)->f8)))) {
        GSYNC_STATE_ChangeState((GsyncStateObj1 *)a, (int)GSYNC_STATE_StateWaitDownloadIdle, 0x3f1);
        return;
    }
    ((GsyncStateObj1 *)a)->f80 = 0xfff0;
    GSYNC_STATE_ChangeState((GsyncStateObj1 *)a, (int)GSYNC_STATE_StateErrorMessage, 0x3f5);
}

void GSYNC_STATE_StateWaitDownloadIdleThenRequest(int a)
{
    if(GSYNC_DOWNLOAD_Reset((GsyncDownloadWork *)((char *)(((GsyncStateObj1 *)a)->f8)))) {
        ((GsyncStateObj1 *)a)->f80=0xfff0;
        GSYNC_STATE_ChangeState((GsyncStateObj1 *)a,(int)GSYNC_STATE_StateErrorMessage,0x3fe);
        return;
    }
    if(GSYNC_DOWNLOAD_ClearResult((GsyncDownloadWork *)((char *)(((GsyncStateObj1 *)a)->f8)))) {
        if((void *)(int)GSYNC_DISP_GetPokeIconActor((GsyncStateObj2 *)((u8 *)((int)((u8 *)(((GsyncStateObj1 *)a)->f8)))))==0) {
            ((GsyncStateObj1 *)a)->f80=0xfff0;
            GSYNC_STATE_ChangeState((GsyncStateObj1 *)a,(int)GSYNC_STATE_StateErrorMessage,0x407);
            return;
        }
        GSYNC_DOWNLOAD_IsBusy((GsyncDownloadWork *)((char *)(((GsyncStateObj1 *)a)->f8)));
        GSYNC_STATE_ChangeState((GsyncStateObj1 *)a,(int)GSYNC_STATE_StateRequestFile,0x40d);
    }
}

void GSYNC_STATE_StateRequestFileList(int a)
{
    if (GSYNC_DOWNLOAD_GetFileListAsync((GsyncDownloadWork *)((char *)(((GsyncStateObj1 *)a)->f8)))) {
        GSYNC_STATE_ChangeState((GsyncStateObj1 *)a, (int)GSYNC_STATE_StateWaitDownloadIdleThenRequest, 0x415);
        return;
    }
    ((GsyncStateObj1 *)a)->f80 = 0xfff0;
    GSYNC_STATE_ChangeState((GsyncStateObj1 *)a, (int)GSYNC_STATE_StateErrorMessage, 0x419);
}

void GSYNC_STATE_StateSetFileAttribute(u8 *p)
{
    if (GSYNC_DOWNLOAD_ClearResult((GsyncDownloadWork *)((*(void * *)&((GsyncStateObj1 *)p)->f8)))) {
        if (GSYNC_DOWNLOAD_Reset((GsyncDownloadWork *)((*(void * *)&((GsyncStateObj1 *)p)->f8)))) {
            ((GsyncStateObj1 *)p)->f80 = 0xfff0;
            GSYNC_STATE_ChangeState((GsyncStateObj1 *)p, (int)GSYNC_STATE_StateErrorMessage, 0x424);
            return;
        }
        switch (p[0xa7]) {
        case 0:
            if (GSYNC_DOWNLOAD_SetAttr((GsyncDownloadWork *)((*(void * *)&((GsyncStateObj1 *)p)->f8)), (void *)d_021DAB88, p[0xa5])) {
                GSYNC_STATE_ChangeState((GsyncStateObj1 *)p, (int)GSYNC_STATE_StateRequestFileList, 0x42b);
                return;
            }
            ((GsyncStateObj1 *)p)->f80 = 0xfff0;
            GSYNC_STATE_ChangeState((GsyncStateObj1 *)p, (int)GSYNC_STATE_StateErrorMessage, 0x42f);
            return;
        case 1:
            if (GSYNC_DOWNLOAD_SetAttr((GsyncDownloadWork *)((*(void * *)&((GsyncStateObj1 *)p)->f8)), (void *)d_021DAB90, p[0xa4])) {
                GSYNC_STATE_ChangeState((GsyncStateObj1 *)p, (int)GSYNC_STATE_StateRequestFileList, 0x434);
                return;
            }
            ((GsyncStateObj1 *)p)->f80 = 0xfff0;
            GSYNC_STATE_ChangeState((GsyncStateObj1 *)p, (int)GSYNC_STATE_StateErrorMessage, 0x438);
            return;
        case 2:
            if (GSYNC_DOWNLOAD_SetAttr((GsyncDownloadWork *)((*(void * *)&((GsyncStateObj1 *)p)->f8)), (void *)d_021DAB9C, p[0xa6])) {
                GSYNC_STATE_ChangeState((GsyncStateObj1 *)p, (int)GSYNC_STATE_StateRequestFileList, 0x43d);
                return;
            }
            ((GsyncStateObj1 *)p)->f80 = 0xfff0;
            GSYNC_STATE_ChangeState((GsyncStateObj1 *)p, (int)GSYNC_STATE_StateErrorMessage, 0x441);
            return;
        }
    }
}

void GSYNC_STATE_StateInitDownload(char *p)
{
    switch (((GsyncStateObj1 *)p)->fA7) {
    case 0: (*(void * *)&((GsyncStateObj1 *)p)->f8) = GSYNC_DOWNLOAD_AllocWork(((GsyncStateObj1 *)p)->f0, MUSICAL_DIST_SAVE_GetBlockSize() + 4); break;
    case 1: (*(void * *)&((GsyncStateObj1 *)p)->f8) = GSYNC_DOWNLOAD_AllocWork(((GsyncStateObj1 *)p)->f0, 0x20000); break;
    case 2: (*(void * *)&((GsyncStateObj1 *)p)->f8) = GSYNC_DOWNLOAD_AllocWork(((GsyncStateObj1 *)p)->f0, func_0200E8B0() + 4); break;
    }
    if (GSYNC_DOWNLOAD_InitAsync((GsyncDownloadWork *)((*(void * *)&((GsyncStateObj1 *)p)->f8)))) {
        GSYNC_STATE_ChangeState((GsyncStateObj1 *)p, (int)GSYNC_STATE_StateSetFileAttribute, 0x458);
        return;
    }
    ((GsyncStateObj1 *)p)->f80 = 0xfff0;
    GSYNC_STATE_ChangeState((GsyncStateObj1 *)p, (int)GSYNC_STATE_StateErrorMessage, 0x45c);
}

void GSYNC_STATE_StateSelectNextDownload(char *p)
{
    if (((GsyncStateObj1 *)p)->fA5) {
        p[0xa7] = 0;
        GSYNC_STATE_ChangeState((GsyncStateObj1 *)p, (int)GSYNC_STATE_StateInitDownload, 0x465);
        return;
    }
    if (((GsyncStateObj1 *)p)->fA4) {
        p[0xa7] = 1;
        GSYNC_STATE_ChangeState((GsyncStateObj1 *)p, (int)GSYNC_STATE_StateInitDownload, 0x46a);
        return;
    }
    if (((GsyncStateObj1 *)p)->fA6) {
        p[0xa7] = 2;
        GSYNC_STATE_ChangeState((GsyncStateObj1 *)p, (int)GSYNC_STATE_StateInitDownload, 0x46f);
        return;
    }
    GSYNC_STATE_ChangeState((GsyncStateObj1 *)p, (int)GSYNC_STATE_StateSaveStart, 0x472);
}

/*
 * extent: two zero alignment bytes at 021D7CB2 follow the return.
 */
void GSYNC_STATE_CopyMonRecord(void *p, char *q)
{
    int changed = 0;
    int i;
    for (i = 0; i < 5; i++) {
        if (func_0203EFC8((const u8 *)func_02009390(p, i), (const u8 *)(q + 0x98 + i * 26), 26)) {
            changed = 1;
            break;
        }
    }
    if (changed) {
        for (i = 0; i < 5; i++) func_020093A8(p, i, q + 0x98 + i * 26);
        func_020093F0(p, 127);
    }
}

int GSYNC_STATE_GetEntryCount(int a,u8 *p) { int i,result; u16 n; result=0; for(i=0;i<20;i++) { n=*(u16 *)(p+92+i*2); if(n!=0 && n<=626) { func_02009348((struct Sub02009210Obj *)a,i,n,p[132+i]); result=1; } } return result; }

int GSYNC_STATE_GetListEntry(int a,GsyncStateObj3 *p) { int i,result; u16 n; result=0; for(i=0;i<20;i++) { n=*(u16 *)((u8 *)p+92+i*2); if(n!=0 && n<=626) result=1; } return result; }

void GSYNC_STATE_BuildMonEntry(GsyncStateObj1 *p, int unused, int species, int gender, int form, int n, int value)
{
    int f;
    u8 v = value;
    void *h;
    int kind;
    int mapped;
    int g;
    if (species == 0 || species > 493) return;
    h = func_0202A128(p->f0);
    kind = 3;
    f = (int)func_02019D30((u16)species, (u8)form);
    g = func_02019C90(species, f, 20);
    mapped = func_02019D58(species, f);
    switch (g) {
    case 0: gender = 0; break;
    case 254: gender = 1; break;
    case 255: gender = 2; break;
    default: if (gender > 1) gender = func_020056EC(2); break;
    }
    if (func_0202A19C((*(unsigned int *)&p->f2C), h, species, gender, mapped)) kind = 2;
    if (v > 8) v = 0;
    func_0200E1A8(func_0200E0B0(p->f28), species, n, gender, mapped, v, kind);
    func_0202A170(h);
}

void GSYNC_STATE_BuildMonEntries(GsyncStateObj1 *p,int a,u8 *records) { int i; GsyncStateObj21 *r; for(i=0;i<10;i++) { r=(GsyncStateObj21 *) (records+i*8); if(r->f4==0) break; GSYNC_STATE_BuildMonEntry(p,a,r->f4,((u8 *)r)[9],((u8 *)r)[8],r->f6,((u8 *)r)[10]); } }

void GSYNC_STATE_ApplyIconRecords(GsyncStateObj1 *p,GsyncStateObj3 *list) { int i; u16 n; for(i=0;i<20;i++) { n=*(u16 *)((u8 *)list+92+i*2); if(n!=0 && ((u8 *)list)[132+i]!=0 && n<=626) GSYNC_DISP_SetIconRecordSpecies(p->f14,i,n); } }

/*
 * lever: bind the record word before the call and use shared goto guards.
 */
void GSYNC_STATE_PrepareReceivedList(GsyncStateObj1 *p, void *h, GsyncStateObj3 *q, int *r)
{
    int i;
    int v;
    if (*r != 0) {
        p->f80 = *r;
        GSYNC_STATE_ChangeState(p, (int)GSYNC_STATE_StateErrorMessage, 0x500);
        return;
    }
    if (((u8 *)q)[0x5b] != 0) goto unchanged;
    v = *(int *)q;
    if (v == func_020093D0(h)) goto unchanged;
    {
        p->f7C = v;
        ((u8 *)p)[0xa4] = ((u8 *)q)[0x57];
        ((u8 *)p)[0xa5] = ((u8 *)q)[0x58];
        ((u8 *)p)[0xa6] = ((u8 *)q)[0x59];
        p->f6C = q->f54;
        if (((u8 *)p)[0xa5]) ((u8 *)p)[0xa8] |= 1;
        if (((u8 *)p)[0xa4]) ((u8 *)p)[0xa8] |= 2;
        if (((u8 *)p)[0xa6]) ((u8 *)p)[0xa8] |= 4;
        for (i = 0; i < 10; i++) {
            if (*(u16 *)((u8 *)q+i*8+4) == 0) break;
            GSYNC_DISP_SetIconRecord(p->f14, i+20, *(u16 *)((u8 *)q+i*8+4), ((u8 *)q)[i*8+8], ((u8 *)q)[i*8+9]);
        }
        ((u8 *)p)[0xa9] = GSYNC_STATE_GetListEntry((int)h,q);
        GSYNC_STATE_ApplyIconRecords(p,q);
        GSYNC_DISP_LoadIconResources((GsyncStateObj2 *)(p->f14));
    }
    goto done;
unchanged:
    ((u8 *)p)[0xa9] = 0;
done:
    GSYNC_STATE_StateSelectNextDownload((char *)p);
}

int GSYNC_STATE_UpdateCurrentEntry(GsyncStateObj1 *p)
{
    int i, j;
    char *q;
    func_02009448(p->f28);
    q = (char *)p->f20 + 0xc;
    for (i = 0; i < 20; i++) {
        for (j = i + 1; j < 20; j++) {
            if (*(u16 *)(q + i * 2 + 8) != 0 &&
                *(u16 *)(q + j * 2 + 8) == *(u16 *)(q + i * 2 + 8))
                return 0;
        }
    }
    return 1;
}

void GSYNC_STATE_StateReceiveList(char *p)
{
    char *q, *data;
    void *v, *allocated;
    if (GSYNC_STATE_IsConnectionAlive((GsyncStateObj1 *)p) && !GSYNC_STATE_IsCommReady((GsyncStateObj1 *)p)) {
        if (((GsyncStateObj1 *)p)->f70<30) ++((GsyncStateObj1 *)p)->f70;
        GSYNC_DISP_UpdateProgressPosition((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f14),((GsyncStateObj1 *)p)->f70);
        if (GSYNC_STATE_HandleHttpError((GsyncStateObj1 *)p,NHTTP_RAP_GetResultCode(((GsyncStateObj1 *)p)->f10))) return;
        if (NHTTP_RAP_PollConnection(((GsyncStateObj1 *)p)->f10)) return;
        q=(char *)NHTTP_RAP_GetRecvBuffer((u8 *)(((GsyncStateObj1 *)p)->f10));
        v=func_02009448(((GsyncStateObj1 *)p)->f28);
        data=q+0x80;
        allocated=func_02030734(((GsyncStateObj1 *)p)->f0,0x11c,1,d_021DAB78,0x573);
        (*(void * *)&((GsyncStateObj1 *)p)->f38)=allocated;
        MI_CpuCopy8(data,allocated,0x11c);
        GSYNC_STATE_PrepareReceivedList((GsyncStateObj1 *)p,v,(GsyncStateObj3 *)data,(int *)q);
        return;
    } else {
        ++((GsyncStateObj1 *)p)->f74;
        if (((GsyncStateObj1 *)p)->f70<30) ++((GsyncStateObj1 *)p)->f70;
        if (((GsyncStateObj1 *)p)->f74==360) {
            GSYNC_MESSAGE_PrintId((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18),43);
            GSYNC_MESSAGE_PrintInSubWindow((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18));
        } else if (((GsyncStateObj1 *)p)->f74==720) {
            GSYNC_MESSAGE_PrintId((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18),44);
            GSYNC_MESSAGE_PrintInSubWindow((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18));
        } else if (((GsyncStateObj1 *)p)->f74==1080) {
            if (GSYNC_STATE_IsCommIdleWithTarget((GsyncStateObj1 *)p)) GSYNC_MESSAGE_ClearWindow((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18));
            if (GSYNC_STATE_UpdateCurrentEntry((GsyncStateObj1 *)p)) {
                GSYNC_STATE_ChangeState((GsyncStateObj1 *)p,(int)GSYNC_STATE_StateSaveStart,0x58c);
            } else {
                ((GsyncStateObj1 *)p)->f80=9;
                GSYNC_STATE_ChangeState((GsyncStateObj1 *)p,(int)GSYNC_STATE_StateErrorMessage,0x591);
            }
        }
        GSYNC_DISP_UpdateProgressPosition((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f14),((GsyncStateObj1 *)p)->f70);
    }
}

void GSYNC_STATE_StateSendListRequest(char *p)
{
    if (GSYNC_STATE_IsConnectionAlive((GsyncStateObj1 *)p) && !GSYNC_STATE_IsCommReady((GsyncStateObj1 *)p)) {
        if (NHTTP_RAP_CreateRequest(2, ((GsyncStateObj1 *)p)->f10) && !NHTTP_RAP_StartConnection(((GsyncStateObj1 *)p)->f10)) {
            GSYNC_STATE_ChangeState((GsyncStateObj1 *)p, (int)GSYNC_STATE_StateReceiveList, 0x59d);
            return;
        }
    } else {
        if (GSYNC_STATE_IsCommIdleWithTarget((GsyncStateObj1 *)p)) {
            ((GsyncStateObj1 *)p)->f74 = 0;
            GSYNC_MESSAGE_PrintId((GsyncMessageWork *)((u8 *)(((GsyncStateObj1 *)p)->f18)), 42);
            GSYNC_MESSAGE_PrintInSubWindow((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18));
        } else {
            ((GsyncStateObj1 *)p)->f74 = 0x42e;
        }
        GSYNC_STATE_ChangeState((GsyncStateObj1 *)p, (int)GSYNC_STATE_StateReceiveList, 0x5aa);
    }
}

void GSYNC_STATE_StateWaitMessageThenSend(char *p) { if(GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18))) GSYNC_STATE_ChangeState((GsyncStateObj1 *)p,(int)GSYNC_STATE_StateSendListRequest,0x5b3); }

void GSYNC_STATE_StateShowProgressMessage(char *p)
{
    GSYNC_MESSAGE_PrintStreamId((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18), 11);
    GSYNC_MESSAGE_RestartTimeIcon((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18));
    GSYNC_DISP_DeleteSlotActor(((GsyncStateObj1 *)p)->f14, 8);
    GSYNC_DISP_StartPaletteWave((GsyncStateObj2 *)((u8 *)(((GsyncStateObj1 *)p)->f14)));
    GSYNC_DISP_SetFadeDirection((GsyncStateObj1 *)((u8 *)(((GsyncStateObj1 *)p)->f14)), 1);
    GSYNC_DISP_SetSlotAnimSeq(((GsyncStateObj1 *)p)->f14, 6, 5);
    GSYNC_DISP_CreateSlotActor((GsyncStateObj17 *)((u8 *)(((GsyncStateObj1 *)p)->f14)), 0);
    GSYNC_DISP_CreateSlotActor((GsyncStateObj17 *)((u8 *)(((GsyncStateObj1 *)p)->f14)), 12);
    GFL_USE_PlaySeDefaultVolume(0x657);
    GSYNC_STATE_ChangeState((GsyncStateObj1 *)p, (int)GSYNC_STATE_StateWaitMessageThenSend, 0x5c3);
}

void GSYNC_STATE_StateWaitInputFirst(char *p)
{
    if (GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18))) {
        if (KEY_GetTrg() || TOUCHPANEL_GetTrg()) {
            GSYNC_STATE_ChangeState((GsyncStateObj1 *)p, (int)GSYNC_STATE_StateSetErrorExit, 0x5d0);
        }
    }
}

void GSYNC_STATE_StateWaitMessageThenPrintSecond(char *p)
{
    if (GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18))) {
        GSYNC_MESSAGE_PrintStreamId((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18), 16);
        GSYNC_STATE_ChangeState((GsyncStateObj1 *)p, (int)GSYNC_STATE_StateWaitInputFirst, 0x5de);
    }
}

void GSYNC_STATE_StateWaitInputSecond(char *p)
{
    if (GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18))) {
        if (KEY_GetTrg() || TOUCHPANEL_GetTrg()) {
            GSYNC_STATE_ChangeState((GsyncStateObj1 *)p, (int)GSYNC_STATE_StateSetErrorExit, 0x5e9);
        }
    }
}

void GSYNC_STATE_StateWaitMessageThenPrintThird(char *p)
{
    if (GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18))) {
        GSYNC_MESSAGE_PrintStreamId((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18), 49);
        GSYNC_STATE_ChangeState((GsyncStateObj1 *)p, (int)GSYNC_STATE_StateWaitInputSecond, 0x5f6);
    }
}

void GSYNC_STATE_StateConfirmMenuSelect(char *p)
{
    if (((GsyncStateObj1 *)p)->f64 % 110 == 0) GFL_USE_PlaySeDefaultVolume(0x659);
    (((GsyncStateObj1 *)p)->f64)++;
    if (APP_TASKMENU_IsFinish(((GsyncStateObj1 *)p)->f1C)) {
        if (APP_TASKMENU_GetCursorPos(((GsyncStateObj1 *)p)->f1C) == 0) {
            if (func_020076D0(((GsyncStateObj1 *)p)->f24, (int *)(p + 0x48), (int *)(p + 0x4c)) == 0)
                GSYNC_STATE_ChangeState((GsyncStateObj1 *)p, (int)GSYNC_STATE_StateWaitMessageThenPrintThird, 0x60f);
            else
                GSYNC_STATE_ChangeState((GsyncStateObj1 *)p, (int)GSYNC_STATE_StateShowProgressMessage, 0x612);
        } else {
            GSYNC_STATE_ChangeState((GsyncStateObj1 *)p, (int)GSYNC_STATE_StateSetErrorExit, 0x616);
        }
        GSYNC_MESSAGE_ClearStream((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18));
        APP_TASKMENU_CloseMenu(((GsyncStateObj1 *)p)->f1C);
        *(unsigned short *)0x04001050 = 0;
        ((GsyncStateObj1 *)p)->f1C = 0;
    }
}

void GSYNC_STATE_StateOpenConfirmMenu(char *p)
{
    if (((GsyncStateObj1 *)p)->f64 % 110 == 0) GFL_USE_PlaySeDefaultVolume(0x659);
    (((GsyncStateObj1 *)p)->f64)++;
    if (GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18))) {
        ((GsyncStateObj1 *)p)->f1C = (void *)GSYNC_MESSAGE_OpenYesNoMenu((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18), 0);
        GSYNC_STATE_ChangeState((GsyncStateObj1 *)p, (int)GSYNC_STATE_StateConfirmMenuSelect, 0x632);
    }
}

void GSYNC_STATE_StateShowEmptyMessage(char *p)
{
    GSYNC_MESSAGE_ClearStream((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18));
    GSYNC_DISP_CreateSlotActor((GsyncStateObj17 *)((u8 *)(((GsyncStateObj1 *)p)->f14)), 0);
    GSYNC_DISP_CreateSlotActor((GsyncStateObj17 *)((u8 *)(((GsyncStateObj1 *)p)->f14)), 12);
    GSYNC_DISP_CreateSlotActor((GsyncStateObj17 *)((u8 *)(((GsyncStateObj1 *)p)->f14)), 6);
    GSYNC_DISP_CreateSlotActor((GsyncStateObj17 *)((u8 *)(((GsyncStateObj1 *)p)->f14)), 8);
    if (func_02009370((const struct Sub02009210Obj *)func_02009448(((GsyncStateObj1 *)p)->f28)))
        GSYNC_MESSAGE_PrintStreamId((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18), 21);
    else
        GSYNC_MESSAGE_PrintStreamId((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18), 10);
    GSYNC_STATE_ChangeState((GsyncStateObj1 *)p, (int)GSYNC_STATE_StateOpenConfirmMenu, 0x64c);
}

void GSYNC_STATE_StateWaitMessageEnd(char *p)
{
    if (GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18))) {
        GSYNC_STATE_ChangeState((GsyncStateObj1 *)p, (int)GSYNC_STATE_StateShowEmptyMessage, 0x68d);
    }
}

void GSYNC_STATE_StateWaitInputClearWindow(char *p)
{
    if (KEY_GetTrg() != 0 || TOUCHPANEL_GetTrg() != 0) {
        GSYNC_MESSAGE_ClearWindow((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18));
        func_020092E0((struct Sub02009210Obj *)func_02009448(((GsyncStateObj1 *)p)->f28), 1);
        p[0xaf] = 1;
        GSYNC_STATE_ChangeState((GsyncStateObj1 *)p, (int)GSYNC_STATE_StateSendFinalRequest, 0x6a2);
    }
}

void GSYNC_STATE_StateWaitInputPrintNext(char *p)
{
    if (KEY_GetTrg() || TOUCHPANEL_GetTrg()) {
        GSYNC_MESSAGE_PrintId((GsyncMessageWork *)((u8 *)(((GsyncStateObj1 *)p)->f18)), 48);
        GSYNC_MESSAGE_PrintInWindow((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18), 7, 14);
        GSYNC_STATE_ChangeState((GsyncStateObj1 *)p, (int)GSYNC_STATE_StateWaitInputClearWindow, 0x6ab);
    }
}

void GSYNC_STATE_StatePrintErrorMessage(char *p)
{
    GSYNC_MESSAGE_PrintDefault((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18), func_0200853C((const struct Sub0200852CObj *)func_02012944(((struct GsyncObj174 *)(((GsyncStateObj1 *)p)->f20))->f4)));
    GSYNC_MESSAGE_PrintStream((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18), 1);
    GSYNC_MESSAGE_PrintId((GsyncMessageWork *)((u8 *)(((GsyncStateObj1 *)p)->f18)), 47);
    GSYNC_MESSAGE_PrintInWindow((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18), 7, 14);
    GSYNC_STATE_ChangeState((GsyncStateObj1 *)p, (int)GSYNC_STATE_StateWaitInputPrintNext, 0x6b7);
}

void GSYNC_STATE_StateReceiveResponse(char *p)
{
    char *q;
    if (GFL_NET_GetRunState()) {
        if (GSYNC_STATE_HandleHttpError((GsyncStateObj1 *)p, NHTTP_RAP_GetResultCode(((GsyncStateObj1 *)p)->f10))) return;
        if (NHTTP_RAP_PollConnection(((GsyncStateObj1 *)p)->f10)) return;
        q = (char *)NHTTP_RAP_GetRecvBuffer((u8 *)(((GsyncStateObj1 *)p)->f10));
        if (((GsyncStateObj19 *)q)->f0 == 2) {
            GSYNC_STATE_ChangeState((GsyncStateObj1 *)p, (int)GSYNC_STATE_StateSendFinalRequest, 0x6d4);
            return;
        }
        if (((GsyncStateObj19 *)q)->f0 == 0) {
            GSYNC_MESSAGE_ClearStream((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18));
            GSYNC_STATE_ChangeState((GsyncStateObj1 *)p, (int)GSYNC_STATE_StatePrintErrorMessage, 0x6d8);
            return;
        }
        ((GsyncStateObj1 *)p)->f80 = ((GsyncStateObj19 *)q)->f0;
        GSYNC_STATE_ChangeState((GsyncStateObj1 *)p, (int)GSYNC_STATE_StateErrorMessage, 0x6dc);
        return;
    } else {
        GSYNC_STATE_ChangeState((GsyncStateObj1 *)p, (int)GSYNC_STATE_StateSendFinalRequest, 0x6e2);
    }
}

void GSYNC_STATE_StateSendResponse(char *p)
{
    int x;
    unsigned int v;
    if (GFL_NET_GetRunState()) {
        if (NHTTP_RAP_CreateRequest(9,*(void **)(p+0x10))) {
            v=(unsigned int)SAVE_CONTROL_GetWorkArea(*(void **)(p+0x28),&x);
            NHTTP_AddPostDataRaw((void *)NHTTP_RAP_GetConnection(*(void **)(p+0x10)),(void *)v,0x80000);
            if (!NHTTP_RAP_StartConnection(*(void **)(p+0x10)))
                GSYNC_STATE_ChangeState((GsyncStateObj1 *)p,(int)GSYNC_STATE_StateReceiveResponse,0x6fa);
        }
    } else {
        if (KEY_GetTrg() || TOUCHPANEL_GetTrg())
            GSYNC_STATE_ChangeState((GsyncStateObj1 *)p,(int)GSYNC_STATE_StateReceiveResponse,0x700);
    }
}

void GSYNC_STATE_StateWaitInputThird(char *p)
{
    if (GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18))) {
        if (KEY_GetTrg() || TOUCHPANEL_GetTrg()) {
            GSYNC_STATE_ChangeState((GsyncStateObj1 *)p, (int)GSYNC_STATE_StateWaitMessageEnd, 0x727);
        }
    }
}

void GSYNC_STATE_StateWaitMessageThenPrintFourth(char *p)
{
    if (GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18))) {
        GSYNC_MESSAGE_PrintStreamId((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18), 17);
        GSYNC_STATE_ChangeState((GsyncStateObj1 *)p, (int)GSYNC_STATE_StateWaitInputThird, 0x739);
    }
}

void GSYNC_STATE_StateWaitInputFourth(char *p)
{
    if (GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18))) {
        if (KEY_GetTrg() || TOUCHPANEL_GetTrg()) {
            GSYNC_STATE_ChangeState((GsyncStateObj1 *)p, (int)GSYNC_STATE_StateSetErrorExit, 0x746);
        }
    }
}

void GSYNC_STATE_StateWaitMessageThenPrintFifth(char *p)
{
    if (GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18))) {
        GSYNC_MESSAGE_PrintStreamId((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18), 20);
        GSYNC_STATE_ChangeState((GsyncStateObj1 *)p, (int)GSYNC_STATE_StateWaitInputFourth, 0x758);
    }
}

void GSYNC_STATE_ParseResponse(GsyncStateObj1 *p,int x,int *q)
{
    int state;
    switch (*q) {
    case 0:
        state=((struct GsyncObj175 *)(p->f20))->f1C8;
        switch (state) {
        case 0:
            if (x==0) GSYNC_STATE_ChangeState(p,(int)GSYNC_STATE_StateWaitMessageEnd,0x774);
            else if (x==3) GSYNC_STATE_ChangeState(p,(int)GSYNC_STATE_StateWaitMessageEnd,0x777);
            else if (x==1) GSYNC_STATE_ChangeState(p,(int)GSYNC_STATE_StateWaitMessageThenPrintFourth,0x77b);
            else if (x==2) GSYNC_STATE_ChangeState(p,(int)GSYNC_STATE_StateWaitMessageThenPrintFifth,0x77f);
            else if (x==4) GSYNC_STATE_ChangeState(p,(int)GSYNC_STATE_StateWaitMessageEnd,0x782);
            else GSYNC_STATE_ChangeState(p,(int)GSYNC_STATE_StateWaitMessageEnd,0x787);
            break;
        case 3:
            if (p->fAF==0) GSYNC_STATE_ChangeState(p,(int)GSYNC_STATE_StatePrintErrorMessage,0x78c);
            else GSYNC_STATE_ChangeState(p,(int)GSYNC_STATE_StateSendFinalRequest,0x78f);
            break;
        }
        break;
    case 5:
        if (((struct GsyncObj175 *)(p->f20))->f1C8==3)
            GSYNC_STATE_ChangeState(p,(int)GSYNC_STATE_StateSendFinalRequest,0x797);
        else {
            p->f80=*q;
            GSYNC_STATE_ChangeState(p,(int)GSYNC_STATE_StateErrorMessage,0x79b);
        }
        break;
    case 8:
        switch (((struct GsyncObj175 *)(p->f20))->f1C8) {
        case 0: GSYNC_STATE_ChangeState(p,(int)GSYNC_STATE_StateWaitMessageEnd,0x7a2); break;
        case 3: GSYNC_STATE_ChangeState(p,(int)GSYNC_STATE_StateSendResponse,0x7a6); break;
        }
        break;
    default:
        p->f80=*q;
        GSYNC_STATE_ChangeState(p,(int)GSYNC_STATE_StateErrorMessage,0x7ac);
        break;
    }
}

void GSYNC_STATE_StateReceiveParsedResponse(char *p)
{
    char *q;
    if (GFL_NET_GetRunState()) {
        if (GSYNC_STATE_HandleHttpError((GsyncStateObj1 *)p,NHTTP_RAP_GetResultCode(((GsyncStateObj1 *)p)->f10))) return;
        if (NHTTP_RAP_PollConnection(((GsyncStateObj1 *)p)->f10)) return;
        q=(char *)NHTTP_RAP_GetRecvBuffer((u8 *)(((GsyncStateObj1 *)p)->f10));
        MI_CpuCopy8(q+0x80,(char *)((GsyncStateObj1 *)p)->f20+0xc,0x44);
        ((struct GsyncObj175 *)(((GsyncStateObj1 *)p)->f20))->f50=1;
        GSYNC_STATE_ParseResponse((GsyncStateObj1 *)p,((GsyncStateObj3 *)q)->f80,(int *)q);
    } else {
        GSYNC_STATE_ChangeState((GsyncStateObj1 *)p,(int)GSYNC_STATE_StateWaitMessageEnd,0x7d4);
    }
}

void GSYNC_STATE_StateSendParsedRequest(char *p)
{
    GSYNC_MESSAGE_PrintStreamId((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18),13);
    GSYNC_MESSAGE_RestartTimeIcon((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18));
    if (GFL_NET_GetRunState()) {
        if (NHTTP_RAP_CreateRequest(0,((GsyncStateObj1 *)p)->f10)) {
            if (!NHTTP_RAP_StartConnection(((GsyncStateObj1 *)p)->f10))
                GSYNC_STATE_ChangeState((GsyncStateObj1 *)p,(int)GSYNC_STATE_StateReceiveParsedResponse,0x7ea);
        }
    } else {
        if (KEY_GetTrg() || TOUCHPANEL_GetTrg())
            GSYNC_STATE_ChangeState((GsyncStateObj1 *)p,(int)GSYNC_STATE_StateReceiveParsedResponse,0x7f1);
    }
}

void GSYNC_STATE_StateWaitMessageClearStream(char *p)
{
    if (GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18))) {
        if (KEY_GetTrg() || TOUCHPANEL_GetTrg()) {
            ((struct GsyncObj176 *)(((GsyncStateObj1 *)p)->f20))->f1C8 = 1;
            GSYNC_MESSAGE_ClearStream((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18));
            GSYNC_STATE_ChangeState((GsyncStateObj1 *)p, (int)GSYNC_STATE_StateFadeOutAfterMessage, 0x808);
        }
    }
}

void GSYNC_STATE_StatePrintFinalMessage(char *p)
{
    GSYNC_MESSAGE_PrintStreamId((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18), 19);
    GSYNC_STATE_ChangeState((GsyncStateObj1 *)p, (int)GSYNC_STATE_StateWaitMessageClearStream, 0x817);
}

void GSYNC_STATE_StateReceiveFinalResponse(char *p)
{
    char *q;
    int state;
    if (GFL_NET_GetRunState()) {
        if (GSYNC_STATE_HandleHttpError((GsyncStateObj1 *)p,NHTTP_RAP_GetResultCode(((GsyncStateObj1 *)p)->f10))) return;
        if (NHTTP_RAP_PollConnection(((GsyncStateObj1 *)p)->f10)) return;
        q=(char *)NHTTP_RAP_GetRecvBuffer((u8 *)(((GsyncStateObj1 *)p)->f10));
        state=((GsyncStateObj33 *)q)->f0;
        if (state==0 || state==8) {
            MI_CpuCopy8(q+0x80,(char *)((GsyncStateObj1 *)p)->f20+0x1d8,0x80);
            ((struct GsyncObj175 *)(((GsyncStateObj1 *)p)->f20))->f1C8=5;
            GSYNC_STATE_ChangeState((GsyncStateObj1 *)p,(int)GSYNC_STATE_StateFadeOutAfterMessage,0x837);
        } else {
            ((GsyncStateObj1 *)p)->f80=state;
            GSYNC_STATE_ChangeState((GsyncStateObj1 *)p,(int)GSYNC_STATE_StateErrorMessage,0x842);
        }
    } else {
        ((struct GsyncObj175 *)(((GsyncStateObj1 *)p)->f20))->f1C8=5;
        GSYNC_STATE_ChangeState((GsyncStateObj1 *)p,(int)GSYNC_STATE_StateFadeOutAfterMessage,0x849);
    }
}

void GSYNC_STATE_StateSendFinalRequest(char *p)
{
    struct RtcDate_021D634C saved, current;
    u32 value;
    int day;
    if (func_02008BD0(func_02008B14(((GsyncStateObj1 *)p)->f28)) && ((GsyncStateObj1 *)p)->fAC) {
        GSYNC_STATE_ChangeState((GsyncStateObj1 *)p,(int)GSYNC_STATE_StateWaitMessageThenPrintSecond,0x85c);
        return;
    }
    value=func_020093C8((const struct Sub02009210Obj *)func_02009448(((GsyncStateObj1 *)p)->f28));
    saved.year=(u8)(value>>24);
    saved.month=(u8)(value>>16);
    saved.day=(u8)(value>>8);
    saved.week=(u8)value;
    func_0203F4E4((struct RtcDate_021D634C *)&current);
    day=func_0203F540((struct RtcDate_021D634C *)&saved);
    if (day==func_0203F540((struct RtcDate_021D634C *)&current)) {
        GSYNC_STATE_ChangeState((GsyncStateObj1 *)p,(int)GSYNC_STATE_StateWaitMessageThenPrintSecond,0x869);
        return;
    }
    if (GFL_NET_GetRunState()) {
        if (NHTTP_RAP_CreateRequest(1,((GsyncStateObj1 *)p)->f10) && !NHTTP_RAP_StartConnection(((GsyncStateObj1 *)p)->f10))
            GSYNC_STATE_ChangeState((GsyncStateObj1 *)p,(int)GSYNC_STATE_StateReceiveFinalResponse,0x871);
    } else {
        if (KEY_GetTrg() || TOUCHPANEL_GetTrg())
            GSYNC_STATE_ChangeState((GsyncStateObj1 *)p,(int)GSYNC_STATE_StateReceiveFinalResponse,0x878);
    }
}

void GSYNC_STATE_StatePlaySeWaitInput(char *p)
{
    if (((GsyncStateObj1 *)p)->f64 % 110 == 0) GFL_USE_PlaySeDefaultVolume(0x659);
    ++((GsyncStateObj1 *)p)->f64;
    if (KEY_GetTrg() || TOUCHPANEL_GetTrg())
        GSYNC_STATE_ChangeState((GsyncStateObj1 *)p, (int)GSYNC_STATE_StateSetErrorExit, 0x88e);
}

void GSYNC_STATE_StateWaitMessageThenNext(char *p)
{
    if (GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18))) {
        GSYNC_STATE_ChangeState((GsyncStateObj1 *)p, (int)GSYNC_STATE_StatePlaySeWaitInput, 0x8a0);
    }
}

void GSYNC_STATE_StateShowCompletionMessage(char *p)
{
    if (((GsyncStateObj1 *)p)->f44) {
        func_020307B0(((GsyncStateObj1 *)p)->f44);
        ((GsyncStateObj1 *)p)->f44=0;
    }
    ((GsyncStateObj1 *)p)->f70=100;
    GSYNC_DISP_UpdateProgressPosition((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f14),100);
    GSYNC_MESSAGE_SetMonName(((GsyncStateObj1 *)p)->f18,14,0,(void *)((*(int *)&((GsyncStateObj1 *)p)->fC)));
    GSYNC_MESSAGE_PrintStream((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18),0);
    GSYNC_DISP_CreateSlotActor((GsyncStateObj17 *)(((GsyncStateObj1 *)p)->f14),8);
    GSYNC_DISP_SetFadeDirection((GsyncStateObj1 *)(((GsyncStateObj1 *)p)->f14),0);
    GSYNC_DISP_CreateSlotActor((GsyncStateObj17 *)(((GsyncStateObj1 *)p)->f14),0);
    GSYNC_DISP_SetSlotAnimSeq(((GsyncStateObj1 *)p)->f14,4,6);
    GFL_USE_PlaySeDefaultVolume(0x658);
    GSYNC_STATE_ChangeState((GsyncStateObj1 *)p,(int)GSYNC_STATE_StateWaitMessageThenNext,0x8bd);
}

void GSYNC_STATE_StateSaveErrorExit(char *p)
{
    if (((GsyncStateObj1 *)p)->f70<100) ++((GsyncStateObj1 *)p)->f70;
    GSYNC_DISP_UpdateProgressPosition((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f14),((GsyncStateObj1 *)p)->f70);
    switch (GAME_DATA_SaveMain((*(void * *)&((GsyncStateObj1 *)p)->f2C))) {
    case 1:
        if (((GsyncStateObj1 *)p)->f34) {
            func_020307B0(((GsyncStateObj1 *)p)->f34);
            ((GsyncStateObj1 *)p)->f34=0;
        }
        break;
    case 3:
        GFL_NET_STATE_SetError(0,0,0,0x3f3);
        GFL_NET_STATE_SetErrorMode(0);
        break;
    case 2:
        p[0xad]=0;
        GSYNC_STATE_ChangeState((GsyncStateObj1 *)p,(int)GSYNC_STATE_StateShowCompletionMessage,0x8e6);
        break;
    }
}

/*
 * lever: GAME_DATA_GetTrainerRecord leaves its return in r0 for func_02008DF0.
 */
void GSYNC_STATE_StateTrainerRecordSaveStart(char *p)
{
    void *q;
    struct RtcDate_021D8A9C date;
    q=func_02009448(((GsyncStateObj1 *)p)->f28);
    p[0xaa]=0;
    func_0203F4E4((struct RtcDate_021D634C *)&date);
    func_020093CC(q, (date.year << 24) | ((date.month & 255) << 16) | ((date.day & 255) << 8) | date.week);
    if (func_020093D8(q)!=127) {
        func_02009428(q,1);
        func_020093F0(q,126);
    }
    ((GsyncStateObj1 *)p)->f70=50;
    func_02008DF0(GAME_DATA_GetTrainerRecord((*(void * *)&((GsyncStateObj1 *)p)->f2C)),119);
    p[0xad]=1;
    GAME_DATA_SaveStart((int)((*(void * *)&((GsyncStateObj1 *)p)->f2C)));
    GSYNC_STATE_ChangeState((GsyncStateObj1 *)p,(int)GSYNC_STATE_StateSaveErrorExit,0x914);
}

void GSYNC_STATE_StateReceiveRecordResponse(char *p)
{
    char *q;
    int state;
    func_02009448(((GsyncStateObj1 *)p)->f28);
    GSYNC_DISP_UpdateParticles(((GsyncStateObj1 *)p)->f14);
    if (GSYNC_STATE_IsCommIdleWithTarget((GsyncStateObj1 *)p)) {
        if (((GsyncStateObj1 *)p)->f74==0) {
            GSYNC_MESSAGE_PrintId((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18),42);
            GSYNC_MESSAGE_PrintInSubWindow((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18));
        } else if (((GsyncStateObj1 *)p)->f74==360) {
            GSYNC_MESSAGE_PrintId((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18),43);
            GSYNC_MESSAGE_PrintInSubWindow((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18));
        } else if (((GsyncStateObj1 *)p)->f74==720) {
            GSYNC_MESSAGE_PrintId((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18),44);
            GSYNC_MESSAGE_PrintInSubWindow((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18));
        }
        ++((GsyncStateObj1 *)p)->f74;
    }
    if (GSYNC_STATE_IsConnectionAlive((GsyncStateObj1 *)p)) {
        if (((GsyncStateObj1 *)p)->f70<50) ++((GsyncStateObj1 *)p)->f70;
        GSYNC_DISP_UpdateProgressPosition((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f14),((GsyncStateObj1 *)p)->f70);
        if (GSYNC_STATE_HandleHttpError((GsyncStateObj1 *)p,NHTTP_RAP_GetResultCode(((GsyncStateObj1 *)p)->f10))) return;
        if (NHTTP_RAP_PollConnection(((GsyncStateObj1 *)p)->f10)) return;
        q=(char *)NHTTP_RAP_GetRecvBuffer((u8 *)(((GsyncStateObj1 *)p)->f10));
        if (GSYNC_STATE_IsCommIdleWithTarget((GsyncStateObj1 *)p)) GSYNC_MESSAGE_ClearWindow((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18));
        state=((GsyncStateObj34 *)q)->f0;
        if (state==0) {
            GSYNC_STATE_ChangeState((GsyncStateObj1 *)p,(int)GSYNC_STATE_StateTrainerRecordSaveStart,0x955);
            return;
        }
        ((GsyncStateObj1 *)p)->f80=state;
        GSYNC_STATE_ChangeState((GsyncStateObj1 *)p,(int)GSYNC_STATE_StateErrorMessage,0x959);
        return;
    } else {
        GSYNC_DISP_UpdateProgressPosition((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f14),((GsyncStateObj1 *)p)->f68);
        if (++((GsyncStateObj1 *)p)->f68==100) {
            if (GSYNC_STATE_IsCommIdleWithTarget((GsyncStateObj1 *)p)) GSYNC_MESSAGE_ClearWindow((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18));
            GSYNC_STATE_ChangeState((GsyncStateObj1 *)p,(int)GSYNC_STATE_StateTrainerRecordSaveStart,0x967);
        }
    }
}

/*
 *   Run 2 also left ov114 0x021B973C unresolved; S23 has since verified its
 *   pkt_ov114_021B973C shard. No caller retry while ARM9 remains blocked.
 *   extern unsigned int BACKUP_SYSTEM_GetWork(void *, int *);
 *   unsigned int SAVE_CONTROL_GetWorkArea(char *p, int *out) {
 *       return BACKUP_SYSTEM_GetWork(*(void **)(p + 0x10), out);
 *   }
 */
void GSYNC_STATE_StateSendRecordRequest(char *p)
{
    int x;
    unsigned int v;
    func_02009448(*(void **)(p+0x28));
    if (GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(*(char **)(p+0x18)))) {
        *(int *)(p+0x74)=0;
        if (GSYNC_STATE_IsConnectionAlive((GsyncStateObj1 *)p)) {
            if (NHTTP_RAP_CreateRequest(3,*(void **)(p+0x10))) {
                v=(unsigned int)SAVE_CONTROL_GetWorkArea(*(void **)(p+0x28),&x);
                NHTTP_AddPostDataRaw((void *)NHTTP_RAP_GetConnection(*(void **)(p+0x10)),(void *)v,0x80000);
                GSYNC_DISP_UpdateProgressPosition((GsyncStateObj2 *)(*(void **)(p+0x14)),0);
                *(int *)(p+0x70)=0;
                if (!NHTTP_RAP_StartConnection(*(void **)(p+0x10)))
                    GSYNC_STATE_ChangeState((GsyncStateObj1 *)p,(int)GSYNC_STATE_StateReceiveRecordResponse,0x986);
            }
        } else {
            GSYNC_DISP_UpdateProgressPosition((GsyncStateObj2 *)(*(void **)(p+0x14)),0);
            GSYNC_STATE_ChangeState((GsyncStateObj1 *)p,(int)GSYNC_STATE_StateReceiveRecordResponse,0x98c);
        }
    }
}

void GSYNC_STATE_StateStartTransferAnimation(char *p)
{
    if (--((GsyncStateObj1 *)p)->f60==0) {
        GSYNC_DISP_StartPaletteWave((GsyncStateObj2 *)((unsigned char *)(((GsyncStateObj1 *)p)->f14)));
        GSYNC_MESSAGE_PrintStreamId((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18),8);
        GSYNC_MESSAGE_RestartTimeIcon((GsyncMessageWork *)(((GsyncStateObj1 *)p)->f18));
        GSYNC_DISP_SetFadeDirection((GsyncStateObj1 *)(((GsyncStateObj1 *)p)->f14),1);
        GSYNC_DISP_SetSlotAnimSeq(((GsyncStateObj1 *)p)->f14,4,5);
        GSYNC_DISP_SetSlotAnimSeq(((GsyncStateObj1 *)p)->f14,0,0);
        GSYNC_DISP_CreateSlotActor((GsyncStateObj17 *)(((GsyncStateObj1 *)p)->f14),12);
        GFL_USE_PlaySeDefaultVolume(0x657);
        GSYNC_STATE_ChangeState((GsyncStateObj1 *)p,(int)GSYNC_STATE_StateSendRecordRequest,0x9a8);
    }
}

void GSYNC_STATE_StateTransferAnimationStep(char *p) { if(--((GsyncStateObj1 *)p)->f60==0) { GSYNC_DISP_CreateSlotActor((GsyncStateObj17 *)(((GsyncStateObj1 *)p)->f14),4); ((GsyncStateObj1 *)p)->f60=60; GSYNC_STATE_ChangeState((GsyncStateObj1 *)p,(int)GSYNC_STATE_StateStartTransferAnimation,0x9b9); } }

void GSYNC_STATE_StateTransferAnimationOpen(char *p)
{
    if (--((GsyncStateObj1 *)p)->f60 == 0) {
        GSYNC_DISP_SetSlotAnimSeq(((GsyncStateObj1 *)p)->f14, 0, 1);
        GSYNC_DISP_CreateSlotActor((GsyncStateObj17 *)(((GsyncStateObj1 *)p)->f14), 2);
        GSYNC_DISP_CreateSlotActor((GsyncStateObj17 *)(((GsyncStateObj1 *)p)->f14), 3);
        ((GsyncStateObj1 *)p)->f60 = 15;
        GSYNC_STATE_ChangeState((GsyncStateObj1 *)p, (int)GSYNC_STATE_StateTransferAnimationStep, 0x9cf);
    }
}

void GSYNC_STATE_StateTransferAnimationEffect(char *p) { if(--((GsyncStateObj1 *)p)->f60==0) { GSYNC_DISP_CreateEffectActorDefault((GsyncStateObj15 *)(((GsyncStateObj1 *)p)->f14)); GSYNC_DISP_EnableActorAutoAnim((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f14)); ((GsyncStateObj1 *)p)->f60=70; GSYNC_STATE_ChangeState((GsyncStateObj1 *)p,(int)GSYNC_STATE_StateTransferAnimationOpen,0x9e4); } }

void GSYNC_STATE_StateCreateReceivedMonIcon(char *p) { GSYNC_DISP_CreateMonIconActor(((GsyncStateObj1 *)p)->f14,(void *)func_020185F0(((GsyncStateObj1 *)p)->fC),1); ((GsyncStateObj1 *)p)->f60=10; GSYNC_STATE_ChangeState((GsyncStateObj1 *)p,(int)GSYNC_STATE_StateTransferAnimationEffect,0x9f6); }

void GSYNC_STATE_StateStoreReceivedMon(char *p)
{
    void *v;
    void *q;
    void *t;
    v=func_02009448(((GsyncStateObj1 *)p)->f28);
    if (((GsyncStateObj1 *)p)->fC) {
        func_020307B0(((GsyncStateObj1 *)p)->fC);
        ((GsyncStateObj1 *)p)->fC=0;
    }
    t=func_02007A18(((GsyncStateObj1 *)p)->f24,((GsyncStateObj1 *)p)->f48,((GsyncStateObj1 *)p)->f4C);
    if (t) {
        q=POKE_TOOL_CreateFromBoxParam(t,((GsyncStateObj1 *)p)->f0);
        func_02009294(v,q);
        ((GsyncStateObj1 *)p)->fC=q;
        func_02007664(((GsyncStateObj1 *)p)->f24,((GsyncStateObj1 *)p)->f48,((GsyncStateObj1 *)p)->f4C);
        func_020092F8(v,1);
        ((GsyncStateObj1 *)p)->fAA=1;
    }
    GSYNC_DISP_CreateSlotActor((GsyncStateObj17 *)(((GsyncStateObj1 *)p)->f14),0);
    GSYNC_DISP_CreateSlotActor((GsyncStateObj17 *)(((GsyncStateObj1 *)p)->f14),12);
    GSYNC_STATE_ChangeState((GsyncStateObj1 *)p,(int)GSYNC_STATE_StateCreateReceivedMonIcon,0xa2a);
}

void GSYNC_STATE_DestroyHttpConnection(char *p)
{
    if (*(u32 *)&((GsyncStateObj1 *)p)->f10 != 0) {
        NHTTP_RAP_DeleteConnection(((GsyncStateObj1 *)p)->f10);
        NHTTP_RAP_Destroy(((GsyncStateObj1 *)p)->f10);
        *(u32 *)&((GsyncStateObj1 *)p)->f10 = 0;
    }
}

/*
 * extent: two zero alignment bytes follow the return.
 */
void GSYNC_STATE_CommitReceivedMon(GsyncStateObj1 *p)
{
    void *v;
    void *q;
    v=func_02009448(p->f28);
    if (p->f34) {
        MI_CpuCopy8(p->f34,v,func_02009228());
        func_020307B0(p->f34);
        p->f34=0;
    }
    if (p->fAA) {
        q=func_02009290(v);
        func_020075B0(p->f24,p->f48,p->f4C,POKE_TOOL_GetBoxParam(q));
        POKE_TOOL_ClearPartyParam(q);
        func_020092F8(v,0);
        p->fAA=0;
    }
}

/*
 * interface: 0203159C returns the allocation live in r0 (original store
 * at 020315C0, then return); legacy matched definition says void.
 */
int GSYNC_STATE_ProcInit(void *a,int b,GsyncStateObj3 *q)
{
    GsyncStateObj1 *p;
    int value;
    func_02034AC4((int)ov114_id);
    GFL_HEAP_CreateChildHeap(1,98,0x88000);
    p=(GsyncStateObj1 *) PROCSYS_AllocProcWork(a,0xb0,98);
    MI_CpuFill8(p,0,0xb0);
    p->f0=98;
    if (!q) func_02034714(d_021DABA4,0,d_021DABA4);
    if (q) {
        p->f20=(char *)q;
        (*(void * *)&p->f2C)=q->f4;
        p->f28=GAME_DATA_GetSaveControl(q->f4);
        value=func_0200853C((const struct Sub0200852CObj *)func_02012944(q->f4));
        (*(unsigned int *)&p->f24)=func_0201293C(q->f4);
        p->f48=q->f1D0;
        p->f4C=q->f1D2;
        p->fAC=func_020092EC((const struct Sub02009210Obj *)func_02009448(p->f28));
        p->fAF=p->fAC;
        func_02009448(p->f28);
        switch (q->f1C8) {
        case 0:
            if (!value) func_02034714(d_021DABA4,0,d_021DABA4);
            GSYNC_STATE_ChangeState(p,(int)GSYNC_STATE_StateSendParsedRequest,0xa89);
            break;
        case 1:
            if (!value) func_02034714(d_021DABA4,0,d_021DABA4);
            GSYNC_STATE_ChangeState(p,(int)GSYNC_STATE_StateStoreReceivedMon,0xa8d);
            break;
        case 2:
            if (!value) func_02034714(d_021DABA4,0,d_021DABA4);
            GSYNC_STATE_ChangeState(p,(int)GSYNC_STATE_StateStoreReceivedMon,0xa91);
            break;
        case 3:
            if (!value) func_02034714(d_021DABA4,0,d_021DABA4);
            GSYNC_STATE_ChangeState(p,(int)GSYNC_STATE_StateSendParsedRequest,0xa95);
            break;
        case 4:
            GSYNC_STATE_ChangeState(p,(int)GSYNC_STATE_StatePrintFinalMessage,0xa98);
            break;
        }
        if (*(int *)&q->f1C8!=4) {
            p->f10=NHTTP_RAP_Create(98,value,(int)((char *)q+0x54));
            DWC_RAP_SetErrorCallback((int)GSYNC_STATE_DestroyHttpConnection,(int)p);
        }
    }
    p->f14=GSYNC_DISP_Init(p->f0);
    p->f18=GSYNC_MESSAGE_InitSystem(p->f0,39);
    WIPE_SYS_Start(0,1,1,0,6,1,p->f0);
    GFL_NET_RestartWithDefaultTimeout(0,p->f0);
    return 1;
}

int GSYNC_STATE_ProcMain(void *a, int b, int c, GsyncStateObj1 *p)
{
    void (*callback)(char *);
    int result;
    callback=*(void (**)(char *))((char *)p+0x50);
    result=1;
    if (WIPE_SYS_EndCheck() && !p->fAE && func_0200FB24()) {
        if ((*(void * *)&p->f8)) GSYNC_DOWNLOAD_CleanupOnce((GsyncDownloadWork *)((*(void * *)&p->f8)));
        NHTTP_RAP_DeleteConnection(p->f10);
        if (p->fAD) {
            GAME_DATA_SaveCancel((*(void * *)&p->f2C));
            p->fAD=0;
        }
        GSYNC_STATE_CommitReceivedMon(p);
        if (p->fAB) func_0200F7C0(41);
        WIPE_SetBrightnessFadeOut(0,0);
        WIPE_SetBrightnessFadeOut(1,0);
        DWC_RAPCOMMON_HandleNetError(1,0);
        ((struct GsyncObj177 *)(p->f20))->f1C8=7;
        return 1;
    }
    if (callback) { callback((char *)p); result=0; }
    if (p->f1C) APP_TASKMENU_UpdateMenu(p->f1C);
    if ((*(void * *)&p->f8)) GSYNC_DOWNLOAD_Process((GsyncDownloadWork *)((*(void * *)&p->f8)));
    GSYNC_DISP_Draw((GsyncStateObj2 *)(p->f14));
    GSYNC_MESSAGE_UpdateSystem((GsyncMessageWork *)(p->f18));
    return result;
}

/*
 * evidence: unlabelled ov009 02156DE0 leaf filed and verified before caller rerun.
 */
int GSYNC_STATE_ProcExit(void *a, int b, int c, GsyncStateObj10 *p)
{
    if (!WIPE_SYS_EndCheck()) return 0;
    if (p->f1C) APP_TASKMENU_CloseMenu(p->f1C);
    if (p->f38) {
        func_020307B0(p->f38);
        p->f38=0;
    }
    GSYNC_MESSAGE_ExitSystem((GsyncMessageWork *)(p->f18));
    GSYNC_DISP_Exit((GsyncStateObj2 *)(p->f14));
    GSYNC_DOWNLOAD_FreeWork((GsyncDownloadWork *)(p->f8));
    if (p->f30) func_020307B0(p->f30);
    if (p->f3C) func_020307B0(p->f3C);
    if (p->f40) func_020307B0(p->f40);
    if (p->fC) func_020307B0(p->fC);
    if (p->f44) func_020307B0(p->f44);
    if (GFL_NET_GetRunState()) DWC_RAP_SetErrorHookCallback(0,0);
    if (p->f10) {
        NHTTP_RAP_Destroy(p->f10);
        DWC_RAP_SetErrorCallback(0,0);
    }
    func_020315D4(a);
    func_020306F0(98);
    func_02034A5C((int)ov114_id);
    return 1;
}
