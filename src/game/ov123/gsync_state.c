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
 *   gGsyncMessageIds 0x021DA844 data a4
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   GFL_USE_SetBgmPlayerParam 0x02005DE4 thumb
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 *   GFL_USE_PushBgm  0x02005E64  thumb
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   gGsyncStateAllocSource 0x021DAB78 data a1
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
 *   GF_STANDARD_SetupCalc 0x0203F1FC arm
 *   func_02009108 0x02009108 thumb
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   GAME_DATA_PartSaveMain 0x02012E7C thumb
 *   func_0200734C 0x0200734C thumb
 *   func_0200E8E0 0x0200E8E0 thumb
 *   MUSICAL_DIST_SAVE_ProcessApply 0x0200C5F8 thumb
 *   gGsyncExtraSaveName 0x021DAB88 data a1
 *   gGsyncMusicalSaveName 0x021DAB90 data a1
 *   gGsyncRecordSaveName 0x021DAB9C data a1
 *   MUSICAL_DIST_SAVE_GetBlockSize 0x0200C6E4 thumb
 *   func_02009390 0x02009390 thumb
 *   func_020093A8 0x020093A8 thumb
 *   func_020093F0 0x020093F0 thumb
 *   func_0203EFC8 0x0203EFC8 arm
 *   func_02009348 0x02009348 thumb
 *   TPOKE_DATA_Create 0x0202A128 thumb
 *   func_02019C90 0x02019C90 thumb
 *   func_02019D58 0x02019D58 thumb
 *   TPOKE_DATA_IsRecordKindTwo 0x0202A19C thumb
 *   SYMBOL_SAVE_GetBlock 0x0200E0B0 thumb
 *   SYMBOL_SAVE_WriteRecord 0x0200E1A8 thumb
 *   func_0202A170 0x0202A170 thumb
 *   func_020093D0 0x020093D0 thumb
 *   func_020092E0 0x020092E0 thumb
 *   SAVE_CONTROL_GetWorkArea 0x020071D8 thumb
 *   func_020093C8 0x020093C8 thumb
 *   GF_STANDARD_SetField00_F4E4 0x0203F4E4 arm
 *   GF_STANDARD_SetupRtc_F540 0x0203F540 arm
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
 *   gGsyncStateAssertTag 0x021DABA4 data a1
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
 *   GAME_DATA_GetBoxManager  0x0201293C  thumb  arm9
 */
#include "gsync_message_types.h"
#include "gsync_download_types.h"
#include "gsync_common_types.h"
#include "gsync_types.h"

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

extern u16 GF_STANDARD_SetupCalc(const u8 *src, u32 len);

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

extern void *TPOKE_DATA_Create(int);

extern int func_02019C90(u16, int, int);

extern int func_02019D58(u16, int);

extern int TPOKE_DATA_IsRecordKindTwo(u32, void *, u16, u16, int);

extern void *SYMBOL_SAVE_GetBlock(void *);

extern void SYMBOL_SAVE_WriteRecord(void *, u16, u16, u8, int, u8, u32);

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

extern void GF_STANDARD_SetField00_F4E4(struct GsyncRtcDate *);

extern int GF_STANDARD_SetupRtc_F540(struct GsyncRtcDate *);

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

extern u32 GAME_DATA_GetBoxManager(const struct BigObj *p);

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

void *GSYNC_DISP_GetPokeIconActor(GsyncDispWork *p);

u8 *GSYNC_DISP_Init(u32 heap);

void GSYNC_DISP_Draw(GsyncDispWork *p);

void GSYNC_DISP_Exit(GsyncDispWork *p);

void GSYNC_DISP_CreateEffectActorDefault(GsyncDispWork *p);

void GSYNC_DISP_CreateSlotActor(GsyncDispWork *p,unsigned int i);

void GSYNC_DISP_SetSlotAnimSeq(GsyncDispWork *p, int i, u32 v);

void GSYNC_DISP_SetSlotAnimCommand(GsyncDispWork *p, int i, int v);

void GSYNC_DISP_DeleteSlotActor(GsyncDispWork *p, int i);

void GSYNC_DISP_SetMainActorAnimSeq(GsyncDispWork *p);

void GSYNC_DISP_CreateMonIconActor(GsyncDispWork *p, void *n, int i);

void GSYNC_DISP_EnableActorAutoAnim(GsyncDispWork *p);

void GSYNC_DISP_RestartActorAnim(GsyncDispWork *p);

void GSYNC_DISP_StartPaletteWave(GsyncDispWork *p);

void GSYNC_DISP_SetFadeDirection(GsyncStateWork *p,int flag);

void GSYNC_DISP_UpdateProgressPosition(GsyncDispWork *p, int n);

void GSYNC_DISP_UpdateParticles(GsyncDispWork *p);

void GSYNC_DISP_SetIconRecord(GsyncDispWork *p,int i,int a,int b,int c);

void GSYNC_DISP_SetIconRecordSpecies(GsyncDispWork *p, int i, u16 v);

void GSYNC_DISP_LoadIconResources(GsyncDispWork *p);

int GSYNC_STATE_HandleHttpError(GsyncStateWork *p,int x);

int GSYNC_STATE_IsConnectionAlive(GsyncStateWork *p);

int GSYNC_STATE_IsCommIdleWithTarget(GsyncStateWork *p);

int GSYNC_STATE_IsCommReady(GsyncStateWork *p);

void GSYNC_STATE_SetNextState(GsyncStateWork *p,u32 v,int unused);

void GSYNC_STATE_ChangeState(GsyncStateWork *p,u32 v,int unused);

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

void GSYNC_STATE_LoadReceivedMon(GsyncStateWork *p);

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

int GSYNC_STATE_GetListEntry(int a,GsyncConn *p);

void GSYNC_STATE_BuildMonEntry(GsyncStateWork *p, int unused, int species, int gender, int form, int n, int value);

void GSYNC_STATE_BuildMonEntries(GsyncStateWork *p,int a,u8 *records);

void GSYNC_STATE_ApplyIconRecords(GsyncStateWork *p,GsyncConn *list);

void GSYNC_STATE_PrepareReceivedList(GsyncStateWork *p, void *h, GsyncConn *q, int *r);

int GSYNC_STATE_UpdateCurrentEntry(GsyncStateWork *p);

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

void GSYNC_STATE_ParseResponse(GsyncStateWork *p,int x,int *q);

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

void GSYNC_STATE_CommitReceivedMon(GsyncStateWork *p);

int GSYNC_STATE_ProcInit(void *a,int b,GsyncConn *q);

int GSYNC_STATE_ProcMain(void *a, int b, int c, GsyncStateWork *p);

int GSYNC_STATE_ProcExit(void *a, int b, int c, GsyncStateWork *p);

extern const GsyncMessageIdTable gGsyncMessageIds;

extern const char gGsyncStateAllocSource[];

extern const char gGsyncExtraSaveName[];

extern const char gGsyncMusicalSaveName[];

extern const char gGsyncRecordSaveName[];

extern char ov114_id[];

extern const char gGsyncStateAssertTag[];

int GSYNC_STATE_HandleHttpError(GsyncStateWork *p,int x)
{
    switch (x) {
    case 503:
        p->errorCode=0xfff1;
        GSYNC_STATE_ChangeState(p,(int)GSYNC_STATE_StateErrorMessage,0xd3);
        return 1;
    case 502:
        p->errorCode=0xfff2;
        GSYNC_STATE_ChangeState(p,(int)GSYNC_STATE_StateErrorMessage,0xd7);
        return 1;
    }
    if (x>=400) {
        p->errorCode=0xfff3;
        GSYNC_STATE_ChangeState(p,(int)GSYNC_STATE_StateErrorMessage,0xdd);
        return 1;
    }
    return 0;
}

int GSYNC_STATE_IsConnectionAlive(GsyncStateWork *p){u8 *q=p->connection;if(((GsyncConn *)q)->state==2)return 0;if(((GsyncConn *)q)->rapFlags && ((GsyncConn *)q)->rapState==4)return 0;if(GFL_NET_GetRunState())return 1;return 0;}

int GSYNC_STATE_IsCommIdleWithTarget(GsyncStateWork *p)
{
    char *q = p->connection;

    return ((GsyncConn *)q)->rapFlags != 0 && ((GsyncConn *)q)->rapState == 0;
}

int GSYNC_STATE_IsCommReady(GsyncStateWork *p){u8 *q=p->connection;if(((GsyncConn *)q)->rapFlags){unsigned int x=((GsyncConn *)q)->rapState;if(x==0)return 1;if(x==4)return 1;}return 0;}

void GSYNC_STATE_SetNextState(GsyncStateWork *p,u32 v,int unused){p->stateHandler=v;}

void GSYNC_STATE_ChangeState(GsyncStateWork *p,u32 v,int unused){GSYNC_STATE_SetNextState(p,v,unused);}

void GSYNC_STATE_StateWaitFade(char *p)
{
    if (WIPE_SYS_EndCheck() != 0)
        GSYNC_STATE_ChangeState((GsyncStateWork *)p, 0, 0x157);
}

void GSYNC_STATE_StateFadeOutAfterMessage(char *p)
{
    if (GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork))) {
        WIPE_SYS_Start(0,0,0,0,6,1,((GsyncStateWork *)p)->heapId);
        GSYNC_STATE_ChangeState((GsyncStateWork *)p,(int)GSYNC_STATE_StateWaitFade,0x16b);
    }
}

void GSYNC_STATE_StateFreeDownloadAndExit(u8 *p){if(GSYNC_DOWNLOAD_ClearResult((GsyncDownloadWork *)((char *)(((GsyncStateWork *)p)->downloadWork)))){GSYNC_DOWNLOAD_FreeWork((GsyncDownloadWork *)((char *)(((GsyncStateWork *)p)->downloadWork)));((GsyncStateWork *)p)->downloadWork=0;GSYNC_STATE_ChangeState((GsyncStateWork *)p,(u32)GSYNC_STATE_StateSetErrorExit,0x17c);}}

void GSYNC_STATE_StateWaitInputCancelSave(unsigned char *a)
{
    if (((GsyncStateWork *)a)->saveInProgress != 0)
        return;
    if (KEY_GetTrg() == 0 && TOUCHPANEL_GetTrg() == 0)
        return;
    if (((GsyncStateWork *)a)->saveActive != 0) {
        GAME_DATA_SaveCancel((char *)(((GsyncStateWork *)a)->saveData));
        ((GsyncStateWork *)a)->saveActive = 0;
    }
    GSYNC_STATE_CommitReceivedMon((GsyncStateWork *)a);
    if (((GsyncStateWork *)a)->downloadWork != 0) {
        if (GSYNC_DOWNLOAD_CleanupOnce((GsyncDownloadWork *)((char *)(((GsyncStateWork *)a)->downloadWork))) != 0)
            GSYNC_STATE_ChangeState((GsyncStateWork *)a, (int)GSYNC_STATE_StateFreeDownloadAndExit, 0x191);
        GSYNC_STATE_ChangeState((GsyncStateWork *)a, 0x021D706D, 0x193);
    } else {
        GSYNC_STATE_ChangeState((GsyncStateWork *)a, 0x021D706D, 0x196);
    }
}

/*
 * extent: unit includes the 28-byte store-and-tail stub at 021D706C.
 */
void GSYNC_STATE_StateErrorMessage(char *p)
{
    int n=((GsyncStateWork *)p)->errorCode+29;
    if (((GsyncStateWork *)p)->httpConnection) NHTTP_RAP_DeleteConnection(((GsyncStateWork *)p)->httpConnection);
    if (((GsyncStateWork *)p)->errorCode==0xfff0) n=39;
    else if (((GsyncStateWork *)p)->errorCode==0xfff1) n=40;
    else if (((GsyncStateWork *)p)->errorCode==0xfff2) n=41;
    else if (((GsyncStateWork *)p)->errorCode==0xfff3) n=38;
    else if (((GsyncStateWork *)p)->errorCode<=0 || ((GsyncStateWork *)p)->errorCode>=10) n=38;
    GSYNC_MESSAGE_ClearStream((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork));
    GSYNC_MESSAGE_PrintId((GsyncMessageWork *)((u8 *)(((GsyncStateWork *)p)->messageWork)),n);
    GSYNC_MESSAGE_PrintInWindow((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork),1,16);
    GSYNC_STATE_ChangeState((GsyncStateWork *)p,(int)GSYNC_STATE_StateWaitInputCancelSave,0x1b9);
}

void GSYNC_STATE_StateSetErrorExit(char *p)
{
    ((struct GsyncConn *)(((GsyncStateWork *)p)->connection))->state=6;
    GSYNC_STATE_ChangeState((GsyncStateWork *)p,(int)GSYNC_STATE_StateFadeOutAfterMessage,0x1c9);
}

void GSYNC_STATE_StateWaitMessageInput(char *p) { if(GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork)) && (KEY_GetTrg() || TOUCHPANEL_GetTrg())) GSYNC_STATE_ChangeState((GsyncStateWork *)p,(int)GSYNC_STATE_StateSetErrorExit,0x1d9); }

void GSYNC_STATE_StateClearMessageExit(char *p)
{
    GsyncMessageIdTable t=gGsyncMessageIds;
    if (((GsyncStateWork *)p)->downloadFlags) {
        GSYNC_MESSAGE_ClearStream((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork));
        GSYNC_MESSAGE_PrintId((GsyncMessageWork *)((u8 *)(((GsyncStateWork *)p)->messageWork)),t.ids[((GsyncStateWork *)p)->downloadFlags]);
        GSYNC_MESSAGE_PrintInWindow((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork),1,8);
        GSYNC_STATE_ChangeState((GsyncStateWork *)p,(int)GSYNC_STATE_StateWaitMessageInput,0x1f0);
    } else {
        GSYNC_STATE_ChangeState((GsyncStateWork *)p,(int)GSYNC_STATE_StateSetErrorExit,0x1f3);
    }
}

void GSYNC_STATE_StateWaitEndingBgm(char *p)
{
    if (GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork)) != 0) {
        int n = ((GsyncStateWork *)p)->bgmWait - 1;
        ((GsyncStateWork *)p)->bgmWait = n;
        if (n <= 0) {
            if (n == 0) {
                GFL_USE_PopBgm();
                GFL_USE_SetBgmPlayerParam(0);
                GFL_USE_FadeInBgmFull(6);
            }
            if (KEY_GetTrg() != 0 || TOUCHPANEL_GetTrg() != 0) {
                GSYNC_STATE_ChangeState((GsyncStateWork *)p, (int)GSYNC_STATE_StateClearMessageExit, 0x20B);
            }
        }
    }
}

void GSYNC_STATE_StateShowResultMessage(int a)
{
    if (GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)((char *)((*(int *)&((GsyncStateWork *)a)->messageWork)))) == 0)
        return;
    if (KEY_GetTrg() == 0 && TOUCHPANEL_GetTrg() == 0)
        return;
    if (((GsyncStateWork *)a)->messageArg == 0) {
        GSYNC_STATE_ChangeState((GsyncStateWork *)a, (int)GSYNC_STATE_StateClearMessageExit, 0x217);
        return;
    }
    GSYNC_MESSAGE_ClearWindow((GsyncMessageWork *)((char *)((*(int *)&((GsyncStateWork *)a)->messageWork))));
    GSYNC_MESSAGE_SetMonName((void *)((*(int *)&((GsyncStateWork *)a)->messageWork)), 0x16, ((GsyncStateWork *)a)->messageArg,
                 (void *)((*(int *)&((GsyncStateWork *)a)->receivedMon)));
    GSYNC_MESSAGE_PrintStream((GsyncMessageWork *)((char *)((*(int *)&((GsyncStateWork *)a)->messageWork))), 0);
    GFL_USE_SetBgmPlayerParam((void *)1);
    GFL_USE_PushBgm();
    GFL_USE_CancelChangeAndPlayBgm(0x515, 0xffff);
    ((GsyncStateWork *)a)->bgmWait = 0xb4;
    GSYNC_STATE_ChangeState((GsyncStateWork *)a, (int)GSYNC_STATE_StateWaitEndingBgm, 0x222);
}

void GSYNC_STATE_ResetSlotActors(char *p) { GSYNC_DISP_SetSlotAnimSeq(((GsyncStateWork *)p)->displayWork,0,0); GSYNC_DISP_CreateSlotActor((GsyncDispWork *)((u8 *)(((GsyncStateWork *)p)->displayWork)),12); GSYNC_DISP_SetMainActorAnimSeq((GsyncDispWork *)(((GsyncStateWork *)p)->displayWork)); }

/*
 * lever: update the call-result local in both clamp arms to preserve its register.
 */
void GSYNC_STATE_LoadReceivedMon(GsyncStateWork *p)
{
    void *g;
    void *q;
    int size;
    int n;
    g=func_02009448(p->saveControl);
    if (p->receivedMon) {
        func_020307B0(p->receivedMon);
        p->receivedMon=0;
    }
    if (func_020076D0(p->boxSave,(int *)((char *)p+0x48),(int *)((char *)p+0x4c))) {
        q=func_02030734(p->heapId,func_020173EC(),1,gGsyncStateAllocSource,0x245);
        size=func_020173EC();
        MI_CpuCopy8(func_02009290(g),q,size);
        if (p->messageArg) {
            n=func_02017E1C(q,158,0);
            if (n==100) p->messageArg=0;
            if (n+p->messageArg>100) {
                p->messageArg=100-n;
                n=100;
            } else {
                n+=p->messageArg;
            }
            func_02019CA0(q,n);
        }
        func_020074D8(p->boxSave,(const struct Sub02007454Entry *)((int)POKE_TOOL_GetBoxParam(q)));
        p->receivedMon=q;
        func_020092F8(g,0);
        func_020093D4(g,p->entryId);
    }
}

void GSYNC_STATE_StateSaveFinishMessage(char *p)
{
    NotifyCallback cb;
    func_02009448(((GsyncStateWork *)p)->saveControl);
    if (GAME_DATA_SaveMain((*(void * *)&((GsyncStateWork *)p)->saveData))==2) {
        ((GsyncStateWork *)p)->saveActive=0;
        ((GsyncStateWork *)p)->saveInProgress=0;
        ((GsyncStateWork *)p)->netDone=0;
        GSYNC_MESSAGE_ClearStream((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork));
        GSYNC_MESSAGE_SetMonName(((GsyncStateWork *)p)->messageWork,45,0,(void *)(*(int *)&((GsyncStateWork *)p)->receivedMon));
        GSYNC_MESSAGE_PrintInWindow((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork),1,4);
        GSYNC_DISP_CreateSlotActor((GsyncDispWork *)((u8 *)(((GsyncStateWork *)p)->displayWork)),0);
        GSYNC_DISP_SetSlotAnimSeq((GsyncDispWork *)(((GsyncStateWork *)p)->displayWork),6,7);
        GSYNC_DISP_SetSlotAnimSeq((GsyncDispWork *)(((GsyncStateWork *)p)->displayWork),0,1);
        cb.value=0; cb.object=p; cb.callback=GSYNC_STATE_ResetSlotActors;
        GSYNC_DISP_SetSlotAnimCommand((GsyncDispWork *)(((GsyncStateWork *)p)->displayWork),0,(int)&cb);
        GSYNC_DISP_SetFadeDirection((GsyncStateWork *)((u8 *)(((GsyncStateWork *)p)->displayWork)),0);
        GSYNC_DISP_CreateMonIconActor((GsyncDispWork *)(((GsyncStateWork *)p)->displayWork),(void *)func_020185F0(((GsyncStateWork *)p)->receivedMon),0);
        GSYNC_DISP_RestartActorAnim((GsyncDispWork *)(((GsyncStateWork *)p)->displayWork));
        GFL_USE_PlaySeDefaultVolume(0x658);
        GSYNC_STATE_ChangeState((GsyncStateWork *)p,(int)GSYNC_STATE_StateShowResultMessage,0x295);
    }
}

void GSYNC_STATE_StatePollResponse(char *p)
{
    if (GSYNC_STATE_HandleHttpError((GsyncStateWork *)p,NHTTP_RAP_GetResultCode(((GsyncStateWork *)p)->httpConnection))==0) {
        if (NHTTP_RAP_PollConnection(((GsyncStateWork *)p)->httpConnection)==0) {
            NHTTP_RAP_GetRecvBuffer(((GsyncStateWork *)p)->httpConnection);
            func_02009448(((GsyncStateWork *)p)->saveControl);
            ((GsyncStateWork *)p)->netDone=1;
            GSYNC_STATE_ChangeState((GsyncStateWork *)p,(int)GSYNC_STATE_StateSaveFinishMessage,0x2ae);
        }
    }
}

void GSYNC_STATE_StateSendRequest(char *p)
{
    if (((GsyncStateWork *)p)->bgmWait) {
        --((GsyncStateWork *)p)->bgmWait;
        return;
    }
    if (GFL_NET_GetRunState()) {
        if (NHTTP_RAP_CreateRequest(8,((GsyncStateWork *)p)->httpConnection)) {
            p[2]=1;
            p[3]=0;
            NHTTP_AddPostDataRaw((void *)NHTTP_RAP_GetConnection(((GsyncStateWork *)p)->httpConnection),(void *)((unsigned int)(p+2)),4);
            if (NHTTP_RAP_StartConnection(((GsyncStateWork *)p)->httpConnection)==0)
                GSYNC_STATE_ChangeState((GsyncStateWork *)p,(int)GSYNC_STATE_StatePollResponse,0x2cd);
        }
    }
}

void GSYNC_STATE_StateSaveMainWait(u8 *p) { if(((GsyncStateWork *)p)->progressPercent<100) ++((GsyncStateWork *)p)->progressPercent; GSYNC_DISP_UpdateProgressPosition((GsyncDispWork *)(((GsyncStateWork *)p)->displayWork),((GsyncStateWork *)p)->progressPercent); if(GAME_DATA_SaveMain((*(void * *)&((GsyncStateWork *)p)->saveData))==1) { ((GsyncStateWork *)p)->bgmWait=func_020056EC(190); GSYNC_STATE_ChangeState((GsyncStateWork *)p,(int)GSYNC_STATE_StateSendRequest,0x2e6); } }

void GSYNC_STATE_StateSaveStart(int a)
{
    int b;
    int i;
    u8 *p;
    b=(int)func_02009448((void *)((*(int *)&((GsyncStateWork *)a)->saveControl)));
    ((GsyncStateWork *)a)->saveInProgress=1;
    GSYNC_STATE_LoadReceivedMon((GsyncStateWork *)a);
    if(GSYNC_STATE_IsCommReady((GsyncStateWork *)a)==0) {
        GSYNC_STATE_GetEntryCount(b,(u8 *)(((GsyncStateWork *)a)->listBuffer));
        GSYNC_STATE_BuildMonEntries((GsyncStateWork *)a,b,(u8 *)(((GsyncStateWork *)a)->listBuffer));
        GSYNC_STATE_CopyMonRecord((void *)b,(char *)(((GsyncStateWork *)a)->listBuffer));
        func_020092D0((struct Sub02009210Obj *)b,*(u8 *)(((GsyncStateWork *)a)->listBuffer+0x5a));
    } else {
        p=(u8 *)((GsyncStateWork *)a)->connection+0xc;
        GSYNC_STATE_BuildMonEntry((GsyncStateWork *)a,b,((GsyncMonHeader *)p)->species,p[7],p[6],((GsyncMonHeader *)p)->arg,func_020056EC(8));
        for(i=0;i<20;i++) func_02009348((struct Sub02009210Obj *)b,i,*(u16 *)(p+8+i*2),p[0x30+i]);
    }
    ((GsyncStateWork *)a)->saveActive=1;
    GAME_DATA_SaveStart(((GsyncStateWork *)a)->saveData);
    GSYNC_STATE_ChangeState((GsyncStateWork *)a,(int)GSYNC_STATE_StateSaveMainWait,0x311);
}

void GSYNC_STATE_StateCleanupDownload(int a)
{
    if (GSYNC_DOWNLOAD_CleanupOnce((GsyncDownloadWork *)((char *)(((GsyncStateWork *)a)->downloadWork)))) {
        GSYNC_STATE_ChangeState((GsyncStateWork *)a, (int)GSYNC_STATE_StateDownloadReset, 0x319);
        return;
    }
    ((GsyncStateWork *)a)->errorCode = 0xfff0;
    GSYNC_STATE_ChangeState((GsyncStateWork *)a, (int)GSYNC_STATE_StateErrorMessage, 0x31d);
}

void GSYNC_STATE_StateFreeReceivedMon(u8 *p) { ((GsyncStateWork *)p)->wantMusicalSave=0; func_020307B0(((GsyncStateWork *)p)->iconBuffer); ((GsyncStateWork *)p)->netDone=0; ((GsyncStateWork *)p)->iconBuffer=0; GSYNC_STATE_ChangeState((GsyncStateWork *)p,(int)GSYNC_STATE_StateCleanupDownload,0x328); }

void GSYNC_STATE_StateExtraSaveMain(u8 *a)
{
    int b = (int)GAME_DATA_GetSaveControl((struct Big *)(((GsyncStateWork *)a)->saveData));
    if(GAME_DATA_PartSaveMain((char *)(((GsyncStateWork *)a)->saveData),4)==2) {
        func_0200734C((struct Sub02007324Ctrl *)b,4);
        func_020090F8((struct Sub020090B0Obj *)func_02009210((void *)b),1);
        GSYNC_STATE_ChangeState((GsyncStateWork *)a,(int)GSYNC_STATE_StateFreeReceivedMon,0x333);
    }
}

void GSYNC_STATE_StateExtraSaveLoadStart(int a)
{
    u16 checksum;
    int b;
    u8 *p;
    int x;
    b=(int)GAME_DATA_GetSaveControl((struct Big *)(((GsyncStateWork *)a)->saveData));
    p=(u8 *)GSYNC_DOWNLOAD_NoteFinished((GsyncDownloadWork *)((char *)(((GsyncStateWork *)a)->downloadWork)));
    checksum=GF_STANDARD_SetupCalc(p,0x2600);
    if(checksum!=*(u16 *)(p+0x2600)) {
        ((GsyncStateWork *)a)->errorCode=0xfff0;
        GSYNC_STATE_ChangeState((GsyncStateWork *)a,(int)GSYNC_STATE_StateErrorMessage,0x345);
        return;
    }
    ((GsyncStateWork *)a)->netDone=1;
    x=(int)func_02030734(((GsyncStateWork *)a)->heapId,0x3000,0,gGsyncStateAllocSource,0x34a);
    (*(int *)&((GsyncStateWork *)a)->iconBuffer)=x;
    SAVE_CONTROL_LoadExtraSaveWithBuffer(b,4,((GsyncStateWork *)a)->heapId,x,0x3000);
    MI_CpuCopy8(p,(void *)x,0x2600);
    func_02009108((struct Sub020090B0Obj *)func_02009210((void *)b),checksum);
    GAME_DATA_PartSaveStart((u8 *)((GsyncStateWork *)a)->saveData,4);
    GSYNC_STATE_ChangeState((GsyncStateWork *)a,(int)GSYNC_STATE_StateExtraSaveMain,0x355);
}

void GSYNC_STATE_StateFreeExtraSaveBuffer(u8 *p) { ((GsyncStateWork *)p)->wantRecordSave=0; func_020307B0(((GsyncStateWork *)p)->extraSaveBuffer); ((GsyncStateWork *)p)->netDone=0; ((GsyncStateWork *)p)->extraSaveBuffer=0; GSYNC_STATE_ChangeState((GsyncStateWork *)p,(int)GSYNC_STATE_StateCleanupDownload,0x360); }

void GSYNC_STATE_StateExtraSaveMainSecond(char *p) { int v; v=(int)GAME_DATA_GetSaveControl((struct Big *)(((GsyncStateWork *)p)->saveData)); if(GAME_DATA_PartSaveMain((char *)(((GsyncStateWork *)p)->saveData),7)==2) { func_0200734C((struct Sub02007324Ctrl *)v,7); GSYNC_STATE_ChangeState((GsyncStateWork *)p,(int)GSYNC_STATE_StateFreeExtraSaveBuffer,0x36a); } }

void GSYNC_STATE_StateExtraSaveLoadStartSecond(int a)
{
    int b;
    u8 *p;
    int x;
    u16 checksum;
    b=(int)GAME_DATA_GetSaveControl((struct Big *)(((GsyncStateWork *)a)->saveData));
    p=(u8 *)GSYNC_DOWNLOAD_NoteFinished((GsyncDownloadWork *)((char *)(((GsyncStateWork *)a)->downloadWork)));
    checksum=GF_STANDARD_SetupCalc(p,0x6200);
    if(checksum!=*(u16 *)(p+0x6200)) {
        ((GsyncStateWork *)a)->errorCode=0xfff0;
        GSYNC_STATE_ChangeState((GsyncStateWork *)a,(int)GSYNC_STATE_StateErrorMessage,0x378);
        return;
    }
    ((GsyncStateWork *)a)->netDone=1;
    x=(int)func_02030734(((GsyncStateWork *)a)->heapId,0x6800,0,gGsyncStateAllocSource,0x37d);
    *(int *)&((GsyncStateWork *)a)->extraSaveBuffer=x;
    SAVE_CONTROL_LoadExtraSaveWithBuffer(b,7,((GsyncStateWork *)a)->heapId,*(int *)&((GsyncStateWork *)a)->extraSaveBuffer,0x6800);
    MI_CpuCopy8(p,((GsyncStateWork *)a)->extraSaveBuffer,0x6200);
    func_0200E8E0((void *)(*(int *)&((GsyncStateWork *)a)->extraSaveBuffer),1);
    GAME_DATA_PartSaveStart((u8 *)((GsyncStateWork *)a)->saveData,7);
    GSYNC_STATE_ChangeState((GsyncStateWork *)a,(int)GSYNC_STATE_StateExtraSaveMainSecond,0x383);
}

void GSYNC_STATE_StateMusicalSaveApply(u8 *p) { if(MUSICAL_DIST_SAVE_ProcessApply(((GsyncStateWork *)p)->musicalSave)) { ((GsyncStateWork *)p)->netDone=0; ((GsyncStateWork *)p)->musicalSave=0; GSYNC_STATE_ChangeState((GsyncStateWork *)p,(int)GSYNC_STATE_StateCleanupDownload,0x38e); } }

void GSYNC_STATE_StateMusicalSaveCreate(int a,int n)
{
    u8 *p;
    int h;
    u16 checksum;
    ((GsyncStateWork *)a)->wantExtraSave=0;
    p=(u8 *)GSYNC_DOWNLOAD_NoteFinished((GsyncDownloadWork *)((char *)(((GsyncStateWork *)a)->downloadWork)));
    h=n/2;
    if(n>0x1fc0e) {
        ((GsyncStateWork *)a)->errorCode=0xfff0;
        GSYNC_STATE_ChangeState((GsyncStateWork *)a,(int)GSYNC_STATE_StateErrorMessage,0x39d);
        return;
    }
    checksum=GF_STANDARD_SetupCalc(p,n);
    if(checksum!=*(u16 *)(p+h*2)) {
        ((GsyncStateWork *)a)->errorCode=0xfff0;
        GSYNC_STATE_ChangeState((GsyncStateWork *)a,(int)GSYNC_STATE_StateErrorMessage,0x3a3);
        return;
    }
    ((GsyncStateWork *)a)->netDone=1;
    (*(int *)&((GsyncStateWork *)a)->musicalSave)=(int)MUSICAL_DIST_SAVE_CreateFromData((void *)(((GsyncStateWork *)a)->saveData),p,n,((GsyncStateWork *)a)->heapId);
    GSYNC_STATE_ChangeState((GsyncStateWork *)a,(int)GSYNC_STATE_StateMusicalSaveApply,0x3a9);
}

void GSYNC_STATE_StateDownloadReset(int a)
{
    if(GSYNC_DOWNLOAD_ClearResult((GsyncDownloadWork *)((char *)(((GsyncStateWork *)a)->downloadWork)))) {
        if(GSYNC_DOWNLOAD_Reset((GsyncDownloadWork *)((char *)(((GsyncStateWork *)a)->downloadWork)))) {
            ((GsyncStateWork *)a)->errorCode=0xfff0;
            GSYNC_STATE_ChangeState((GsyncStateWork *)a,(int)GSYNC_STATE_StateErrorMessage,0x3b6);
            return;
        }
        GSYNC_DOWNLOAD_FreeWork((GsyncDownloadWork *)((char *)(((GsyncStateWork *)a)->downloadWork)));
        ((GsyncStateWork *)a)->downloadWork=0;
        if(((GsyncStateWork *)a)->progressPercent<100) ((GsyncStateWork *)a)->progressPercent+=10;
        GSYNC_DISP_UpdateProgressPosition((GsyncDispWork *)(((GsyncStateWork *)a)->displayWork),((GsyncStateWork *)a)->progressPercent);
        GSYNC_STATE_ChangeState((GsyncStateWork *)a,(int)GSYNC_STATE_StateSelectNextDownload,0x3c3);
    }
}

void GSYNC_STATE_StateMusicalSaveRetry(int a)
{
    switch(((GsyncStateWork *)a)->downloadKind) {
    case 0: GSYNC_STATE_ChangeState((GsyncStateWork *)a,(int)GSYNC_STATE_StateExtraSaveLoadStart,0x3cb); break;
    case 1: GSYNC_STATE_StateMusicalSaveCreate(a,(int)GSYNC_DISP_GetPokeIconActor((GsyncDispWork *)((u8 *)(((GsyncStateWork *)a)->downloadWork)))-2); break;
    case 2: GSYNC_STATE_ChangeState((GsyncStateWork *)a,(int)GSYNC_STATE_StateExtraSaveLoadStartSecond,0x3d1); break;
    }
}

void GSYNC_STATE_StateWaitDownloadIdle(int a)
{
    if(GSYNC_DOWNLOAD_Reset((GsyncDownloadWork *)((char *)(((GsyncStateWork *)a)->downloadWork)))) {
        ((GsyncStateWork *)a)->errorCode=0xfff0;
        GSYNC_STATE_ChangeState((GsyncStateWork *)a,(int)GSYNC_STATE_StateErrorMessage,0x3dd);
        return;
    }
    if(GSYNC_DOWNLOAD_ClearResult((GsyncDownloadWork *)((char *)(((GsyncStateWork *)a)->downloadWork)))) {
        GSYNC_DOWNLOAD_IsBusy((GsyncDownloadWork *)((char *)(((GsyncStateWork *)a)->downloadWork)));
        GSYNC_STATE_ChangeState((GsyncStateWork *)a,(int)GSYNC_STATE_StateMusicalSaveRetry,0x3e8);
    }
}

void GSYNC_STATE_StateRequestFile(int a)
{
    if (GSYNC_DOWNLOAD_GetFileAsync((GsyncDownloadWork *)((char *)(((GsyncStateWork *)a)->downloadWork)))) {
        GSYNC_STATE_ChangeState((GsyncStateWork *)a, (int)GSYNC_STATE_StateWaitDownloadIdle, 0x3f1);
        return;
    }
    ((GsyncStateWork *)a)->errorCode = 0xfff0;
    GSYNC_STATE_ChangeState((GsyncStateWork *)a, (int)GSYNC_STATE_StateErrorMessage, 0x3f5);
}

void GSYNC_STATE_StateWaitDownloadIdleThenRequest(int a)
{
    if(GSYNC_DOWNLOAD_Reset((GsyncDownloadWork *)((char *)(((GsyncStateWork *)a)->downloadWork)))) {
        ((GsyncStateWork *)a)->errorCode=0xfff0;
        GSYNC_STATE_ChangeState((GsyncStateWork *)a,(int)GSYNC_STATE_StateErrorMessage,0x3fe);
        return;
    }
    if(GSYNC_DOWNLOAD_ClearResult((GsyncDownloadWork *)((char *)(((GsyncStateWork *)a)->downloadWork)))) {
        if((void *)(int)GSYNC_DISP_GetPokeIconActor((GsyncDispWork *)((u8 *)((int)((u8 *)(((GsyncStateWork *)a)->downloadWork)))))==0) {
            ((GsyncStateWork *)a)->errorCode=0xfff0;
            GSYNC_STATE_ChangeState((GsyncStateWork *)a,(int)GSYNC_STATE_StateErrorMessage,0x407);
            return;
        }
        GSYNC_DOWNLOAD_IsBusy((GsyncDownloadWork *)((char *)(((GsyncStateWork *)a)->downloadWork)));
        GSYNC_STATE_ChangeState((GsyncStateWork *)a,(int)GSYNC_STATE_StateRequestFile,0x40d);
    }
}

void GSYNC_STATE_StateRequestFileList(int a)
{
    if (GSYNC_DOWNLOAD_GetFileListAsync((GsyncDownloadWork *)((char *)(((GsyncStateWork *)a)->downloadWork)))) {
        GSYNC_STATE_ChangeState((GsyncStateWork *)a, (int)GSYNC_STATE_StateWaitDownloadIdleThenRequest, 0x415);
        return;
    }
    ((GsyncStateWork *)a)->errorCode = 0xfff0;
    GSYNC_STATE_ChangeState((GsyncStateWork *)a, (int)GSYNC_STATE_StateErrorMessage, 0x419);
}

void GSYNC_STATE_StateSetFileAttribute(u8 *p)
{
    if (GSYNC_DOWNLOAD_ClearResult((GsyncDownloadWork *)((*(void * *)&((GsyncStateWork *)p)->downloadWork)))) {
        if (GSYNC_DOWNLOAD_Reset((GsyncDownloadWork *)((*(void * *)&((GsyncStateWork *)p)->downloadWork)))) {
            ((GsyncStateWork *)p)->errorCode = 0xfff0;
            GSYNC_STATE_ChangeState((GsyncStateWork *)p, (int)GSYNC_STATE_StateErrorMessage, 0x424);
            return;
        }
        switch (((GsyncStateWork *)p)->downloadKind) {
        case 0:
            if (GSYNC_DOWNLOAD_SetAttr((GsyncDownloadWork *)((*(void * *)&((GsyncStateWork *)p)->downloadWork)), (void *)gGsyncExtraSaveName, ((GsyncStateWork *)p)->wantMusicalSave)) {
                GSYNC_STATE_ChangeState((GsyncStateWork *)p, (int)GSYNC_STATE_StateRequestFileList, 0x42b);
                return;
            }
            ((GsyncStateWork *)p)->errorCode = 0xfff0;
            GSYNC_STATE_ChangeState((GsyncStateWork *)p, (int)GSYNC_STATE_StateErrorMessage, 0x42f);
            return;
        case 1:
            if (GSYNC_DOWNLOAD_SetAttr((GsyncDownloadWork *)((*(void * *)&((GsyncStateWork *)p)->downloadWork)), (void *)gGsyncMusicalSaveName, ((GsyncStateWork *)p)->wantExtraSave)) {
                GSYNC_STATE_ChangeState((GsyncStateWork *)p, (int)GSYNC_STATE_StateRequestFileList, 0x434);
                return;
            }
            ((GsyncStateWork *)p)->errorCode = 0xfff0;
            GSYNC_STATE_ChangeState((GsyncStateWork *)p, (int)GSYNC_STATE_StateErrorMessage, 0x438);
            return;
        case 2:
            if (GSYNC_DOWNLOAD_SetAttr((GsyncDownloadWork *)((*(void * *)&((GsyncStateWork *)p)->downloadWork)), (void *)gGsyncRecordSaveName, ((GsyncStateWork *)p)->wantRecordSave)) {
                GSYNC_STATE_ChangeState((GsyncStateWork *)p, (int)GSYNC_STATE_StateRequestFileList, 0x43d);
                return;
            }
            ((GsyncStateWork *)p)->errorCode = 0xfff0;
            GSYNC_STATE_ChangeState((GsyncStateWork *)p, (int)GSYNC_STATE_StateErrorMessage, 0x441);
            return;
        }
    }
}

void GSYNC_STATE_StateInitDownload(char *p)
{
    switch (((GsyncStateWork *)p)->downloadKind) {
    case 0: (*(void * *)&((GsyncStateWork *)p)->downloadWork) = GSYNC_DOWNLOAD_AllocWork(((GsyncStateWork *)p)->heapId, MUSICAL_DIST_SAVE_GetBlockSize() + 4); break;
    case 1: (*(void * *)&((GsyncStateWork *)p)->downloadWork) = GSYNC_DOWNLOAD_AllocWork(((GsyncStateWork *)p)->heapId, 0x20000); break;
    case 2: (*(void * *)&((GsyncStateWork *)p)->downloadWork) = GSYNC_DOWNLOAD_AllocWork(((GsyncStateWork *)p)->heapId, func_0200E8B0() + 4); break;
    }
    if (GSYNC_DOWNLOAD_InitAsync((GsyncDownloadWork *)((*(void * *)&((GsyncStateWork *)p)->downloadWork)))) {
        GSYNC_STATE_ChangeState((GsyncStateWork *)p, (int)GSYNC_STATE_StateSetFileAttribute, 0x458);
        return;
    }
    ((GsyncStateWork *)p)->errorCode = 0xfff0;
    GSYNC_STATE_ChangeState((GsyncStateWork *)p, (int)GSYNC_STATE_StateErrorMessage, 0x45c);
}

void GSYNC_STATE_StateSelectNextDownload(char *p)
{
    if (((GsyncStateWork *)p)->wantMusicalSave) {
        ((GsyncStateWork *)p)->downloadKind = 0;
        GSYNC_STATE_ChangeState((GsyncStateWork *)p, (int)GSYNC_STATE_StateInitDownload, 0x465);
        return;
    }
    if (((GsyncStateWork *)p)->wantExtraSave) {
        ((GsyncStateWork *)p)->downloadKind = 1;
        GSYNC_STATE_ChangeState((GsyncStateWork *)p, (int)GSYNC_STATE_StateInitDownload, 0x46a);
        return;
    }
    if (((GsyncStateWork *)p)->wantRecordSave) {
        ((GsyncStateWork *)p)->downloadKind = 2;
        GSYNC_STATE_ChangeState((GsyncStateWork *)p, (int)GSYNC_STATE_StateInitDownload, 0x46f);
        return;
    }
    GSYNC_STATE_ChangeState((GsyncStateWork *)p, (int)GSYNC_STATE_StateSaveStart, 0x472);
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

int GSYNC_STATE_GetListEntry(int a,GsyncConn *p) { int i,result; u16 n; result=0; for(i=0;i<20;i++) { n=*(u16 *)((u8 *)p+92+i*2); if(n!=0 && n<=626) result=1; } return result; }

void GSYNC_STATE_BuildMonEntry(GsyncStateWork *p, int unused, int species, int gender, int form, int n, int value)
{
    int f;
    u8 v = value;
    void *h;
    int kind;
    int mapped;
    int g;
    if (species == 0 || species > 493) return;
    h = TPOKE_DATA_Create(p->heapId);
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
    if (TPOKE_DATA_IsRecordKindTwo((*(unsigned int *)&p->saveData), h, species, gender, mapped)) kind = 2;
    if (v > 8) v = 0;
    SYMBOL_SAVE_WriteRecord(SYMBOL_SAVE_GetBlock(p->saveControl), species, n, gender, mapped, v, kind);
    func_0202A170(h);
}

void GSYNC_STATE_BuildMonEntries(GsyncStateWork *p,int a,u8 *records) { int i; GsyncListEntry *r; for(i=0;i<10;i++) { r=(GsyncListEntry *) (records+i*8); if(r->species==0) break; GSYNC_STATE_BuildMonEntry(p,a,r->species,((u8 *)r)[9],((u8 *)r)[8],r->arg,((u8 *)r)[10]); } }

void GSYNC_STATE_ApplyIconRecords(GsyncStateWork *p,GsyncConn *list) { int i; u16 n; for(i=0;i<20;i++) { n=*(u16 *)((u8 *)list+92+i*2); if(n!=0 && ((u8 *)list)[132+i]!=0 && n<=626) GSYNC_DISP_SetIconRecordSpecies(p->displayWork,i,n); } }

/*
 * lever: bind the record word before the call and use shared goto guards.
 */
void GSYNC_STATE_PrepareReceivedList(GsyncStateWork *p, void *h, GsyncConn *q, int *r)
{
    int i;
    int v;
    if (*r != 0) {
        p->errorCode = *r;
        GSYNC_STATE_ChangeState(p, (int)GSYNC_STATE_StateErrorMessage, 0x500);
        return;
    }
    if (((u8 *)q)[0x5b] != 0) goto unchanged;
    v = q->statusWord;
    if (v == func_020093D0(h)) goto unchanged;
    {
        p->entryId = v;
        ((GsyncStateWork *)p)->wantExtraSave = ((u8 *)q)[0x57];
        ((GsyncStateWork *)p)->wantMusicalSave = ((u8 *)q)[0x58];
        ((GsyncStateWork *)p)->wantRecordSave = ((u8 *)q)[0x59];
        p->messageArg = q->listFlags;
        if (((GsyncStateWork *)p)->wantMusicalSave) ((GsyncStateWork *)p)->downloadFlags |= 1;
        if (((GsyncStateWork *)p)->wantExtraSave) ((GsyncStateWork *)p)->downloadFlags |= 2;
        if (((GsyncStateWork *)p)->wantRecordSave) ((GsyncStateWork *)p)->downloadFlags |= 4;
        for (i = 0; i < 10; i++) {
            if (*(u16 *)((u8 *)q+i*8+4) == 0) break;
            GSYNC_DISP_SetIconRecord(p->displayWork, i+20, *(u16 *)((u8 *)q+i*8+4), ((u8 *)q)[i*8+8], ((u8 *)q)[i*8+9]);
        }
        ((GsyncStateWork *)p)->hasListEntry = GSYNC_STATE_GetListEntry((int)h,q);
        GSYNC_STATE_ApplyIconRecords(p,q);
        GSYNC_DISP_LoadIconResources((GsyncDispWork *)(p->displayWork));
    }
    goto done;
unchanged:
    ((GsyncStateWork *)p)->hasListEntry = 0;
done:
    GSYNC_STATE_StateSelectNextDownload((char *)p);
}

int GSYNC_STATE_UpdateCurrentEntry(GsyncStateWork *p)
{
    int i, j;
    char *q;
    func_02009448(p->saveControl);
    q = (char *)p->connection + 0xc;
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
    if (GSYNC_STATE_IsConnectionAlive((GsyncStateWork *)p) && !GSYNC_STATE_IsCommReady((GsyncStateWork *)p)) {
        if (((GsyncStateWork *)p)->progressPercent<30) ++((GsyncStateWork *)p)->progressPercent;
        GSYNC_DISP_UpdateProgressPosition((GsyncDispWork *)(((GsyncStateWork *)p)->displayWork),((GsyncStateWork *)p)->progressPercent);
        if (GSYNC_STATE_HandleHttpError((GsyncStateWork *)p,NHTTP_RAP_GetResultCode(((GsyncStateWork *)p)->httpConnection))) return;
        if (NHTTP_RAP_PollConnection(((GsyncStateWork *)p)->httpConnection)) return;
        q=(char *)NHTTP_RAP_GetRecvBuffer((u8 *)(((GsyncStateWork *)p)->httpConnection));
        v=func_02009448(((GsyncStateWork *)p)->saveControl);
        data=q+0x80;
        allocated=func_02030734(((GsyncStateWork *)p)->heapId,0x11c,1,gGsyncStateAllocSource,0x573);
        (*(void * *)&((GsyncStateWork *)p)->listBuffer)=allocated;
        MI_CpuCopy8(data,allocated,0x11c);
        GSYNC_STATE_PrepareReceivedList((GsyncStateWork *)p,v,(GsyncConn *)data,(int *)q);
        return;
    } else {
        ++((GsyncStateWork *)p)->waitTicks;
        if (((GsyncStateWork *)p)->progressPercent<30) ++((GsyncStateWork *)p)->progressPercent;
        if (((GsyncStateWork *)p)->waitTicks==360) {
            GSYNC_MESSAGE_PrintId((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork),43);
            GSYNC_MESSAGE_PrintInSubWindow((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork));
        } else if (((GsyncStateWork *)p)->waitTicks==720) {
            GSYNC_MESSAGE_PrintId((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork),44);
            GSYNC_MESSAGE_PrintInSubWindow((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork));
        } else if (((GsyncStateWork *)p)->waitTicks==1080) {
            if (GSYNC_STATE_IsCommIdleWithTarget((GsyncStateWork *)p)) GSYNC_MESSAGE_ClearWindow((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork));
            if (GSYNC_STATE_UpdateCurrentEntry((GsyncStateWork *)p)) {
                GSYNC_STATE_ChangeState((GsyncStateWork *)p,(int)GSYNC_STATE_StateSaveStart,0x58c);
            } else {
                ((GsyncStateWork *)p)->errorCode=9;
                GSYNC_STATE_ChangeState((GsyncStateWork *)p,(int)GSYNC_STATE_StateErrorMessage,0x591);
            }
        }
        GSYNC_DISP_UpdateProgressPosition((GsyncDispWork *)(((GsyncStateWork *)p)->displayWork),((GsyncStateWork *)p)->progressPercent);
    }
}

void GSYNC_STATE_StateSendListRequest(char *p)
{
    if (GSYNC_STATE_IsConnectionAlive((GsyncStateWork *)p) && !GSYNC_STATE_IsCommReady((GsyncStateWork *)p)) {
        if (NHTTP_RAP_CreateRequest(2, ((GsyncStateWork *)p)->httpConnection) && !NHTTP_RAP_StartConnection(((GsyncStateWork *)p)->httpConnection)) {
            GSYNC_STATE_ChangeState((GsyncStateWork *)p, (int)GSYNC_STATE_StateReceiveList, 0x59d);
            return;
        }
    } else {
        if (GSYNC_STATE_IsCommIdleWithTarget((GsyncStateWork *)p)) {
            ((GsyncStateWork *)p)->waitTicks = 0;
            GSYNC_MESSAGE_PrintId((GsyncMessageWork *)((u8 *)(((GsyncStateWork *)p)->messageWork)), 42);
            GSYNC_MESSAGE_PrintInSubWindow((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork));
        } else {
            ((GsyncStateWork *)p)->waitTicks = 0x42e;
        }
        GSYNC_STATE_ChangeState((GsyncStateWork *)p, (int)GSYNC_STATE_StateReceiveList, 0x5aa);
    }
}

void GSYNC_STATE_StateWaitMessageThenSend(char *p) { if(GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork))) GSYNC_STATE_ChangeState((GsyncStateWork *)p,(int)GSYNC_STATE_StateSendListRequest,0x5b3); }

void GSYNC_STATE_StateShowProgressMessage(char *p)
{
    GSYNC_MESSAGE_PrintStreamId((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork), 11);
    GSYNC_MESSAGE_RestartTimeIcon((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork));
    GSYNC_DISP_DeleteSlotActor(((GsyncStateWork *)p)->displayWork, 8);
    GSYNC_DISP_StartPaletteWave((GsyncDispWork *)((u8 *)(((GsyncStateWork *)p)->displayWork)));
    GSYNC_DISP_SetFadeDirection((GsyncStateWork *)((u8 *)(((GsyncStateWork *)p)->displayWork)), 1);
    GSYNC_DISP_SetSlotAnimSeq(((GsyncStateWork *)p)->displayWork, 6, 5);
    GSYNC_DISP_CreateSlotActor((GsyncDispWork *)((u8 *)(((GsyncStateWork *)p)->displayWork)), 0);
    GSYNC_DISP_CreateSlotActor((GsyncDispWork *)((u8 *)(((GsyncStateWork *)p)->displayWork)), 12);
    GFL_USE_PlaySeDefaultVolume(0x657);
    GSYNC_STATE_ChangeState((GsyncStateWork *)p, (int)GSYNC_STATE_StateWaitMessageThenSend, 0x5c3);
}

void GSYNC_STATE_StateWaitInputFirst(char *p)
{
    if (GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork))) {
        if (KEY_GetTrg() || TOUCHPANEL_GetTrg()) {
            GSYNC_STATE_ChangeState((GsyncStateWork *)p, (int)GSYNC_STATE_StateSetErrorExit, 0x5d0);
        }
    }
}

void GSYNC_STATE_StateWaitMessageThenPrintSecond(char *p)
{
    if (GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork))) {
        GSYNC_MESSAGE_PrintStreamId((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork), 16);
        GSYNC_STATE_ChangeState((GsyncStateWork *)p, (int)GSYNC_STATE_StateWaitInputFirst, 0x5de);
    }
}

void GSYNC_STATE_StateWaitInputSecond(char *p)
{
    if (GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork))) {
        if (KEY_GetTrg() || TOUCHPANEL_GetTrg()) {
            GSYNC_STATE_ChangeState((GsyncStateWork *)p, (int)GSYNC_STATE_StateSetErrorExit, 0x5e9);
        }
    }
}

void GSYNC_STATE_StateWaitMessageThenPrintThird(char *p)
{
    if (GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork))) {
        GSYNC_MESSAGE_PrintStreamId((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork), 49);
        GSYNC_STATE_ChangeState((GsyncStateWork *)p, (int)GSYNC_STATE_StateWaitInputSecond, 0x5f6);
    }
}

void GSYNC_STATE_StateConfirmMenuSelect(char *p)
{
    if (((GsyncStateWork *)p)->blinkTimer % 110 == 0) GFL_USE_PlaySeDefaultVolume(0x659);
    (((GsyncStateWork *)p)->blinkTimer)++;
    if (APP_TASKMENU_IsFinish(((GsyncStateWork *)p)->confirmMenu)) {
        if (APP_TASKMENU_GetCursorPos(((GsyncStateWork *)p)->confirmMenu) == 0) {
            if (func_020076D0(((GsyncStateWork *)p)->boxSave, (int *)(p + 0x48), (int *)(p + 0x4c)) == 0)
                GSYNC_STATE_ChangeState((GsyncStateWork *)p, (int)GSYNC_STATE_StateWaitMessageThenPrintThird, 0x60f);
            else
                GSYNC_STATE_ChangeState((GsyncStateWork *)p, (int)GSYNC_STATE_StateShowProgressMessage, 0x612);
        } else {
            GSYNC_STATE_ChangeState((GsyncStateWork *)p, (int)GSYNC_STATE_StateSetErrorExit, 0x616);
        }
        GSYNC_MESSAGE_ClearStream((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork));
        APP_TASKMENU_CloseMenu(((GsyncStateWork *)p)->confirmMenu);
        *(unsigned short *)0x04001050 = 0;
        ((GsyncStateWork *)p)->confirmMenu = 0;
    }
}

void GSYNC_STATE_StateOpenConfirmMenu(char *p)
{
    if (((GsyncStateWork *)p)->blinkTimer % 110 == 0) GFL_USE_PlaySeDefaultVolume(0x659);
    (((GsyncStateWork *)p)->blinkTimer)++;
    if (GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork))) {
        ((GsyncStateWork *)p)->confirmMenu = (void *)GSYNC_MESSAGE_OpenYesNoMenu((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork), 0);
        GSYNC_STATE_ChangeState((GsyncStateWork *)p, (int)GSYNC_STATE_StateConfirmMenuSelect, 0x632);
    }
}

void GSYNC_STATE_StateShowEmptyMessage(char *p)
{
    GSYNC_MESSAGE_ClearStream((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork));
    GSYNC_DISP_CreateSlotActor((GsyncDispWork *)((u8 *)(((GsyncStateWork *)p)->displayWork)), 0);
    GSYNC_DISP_CreateSlotActor((GsyncDispWork *)((u8 *)(((GsyncStateWork *)p)->displayWork)), 12);
    GSYNC_DISP_CreateSlotActor((GsyncDispWork *)((u8 *)(((GsyncStateWork *)p)->displayWork)), 6);
    GSYNC_DISP_CreateSlotActor((GsyncDispWork *)((u8 *)(((GsyncStateWork *)p)->displayWork)), 8);
    if (func_02009370((const struct Sub02009210Obj *)func_02009448(((GsyncStateWork *)p)->saveControl)))
        GSYNC_MESSAGE_PrintStreamId((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork), 21);
    else
        GSYNC_MESSAGE_PrintStreamId((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork), 10);
    GSYNC_STATE_ChangeState((GsyncStateWork *)p, (int)GSYNC_STATE_StateOpenConfirmMenu, 0x64c);
}

void GSYNC_STATE_StateWaitMessageEnd(char *p)
{
    if (GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork))) {
        GSYNC_STATE_ChangeState((GsyncStateWork *)p, (int)GSYNC_STATE_StateShowEmptyMessage, 0x68d);
    }
}

void GSYNC_STATE_StateWaitInputClearWindow(char *p)
{
    if (KEY_GetTrg() != 0 || TOUCHPANEL_GetTrg() != 0) {
        GSYNC_MESSAGE_ClearWindow((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork));
        func_020092E0((struct Sub02009210Obj *)func_02009448(((GsyncStateWork *)p)->saveControl), 1);
        ((GsyncStateWork *)p)->responseValid = 1;
        GSYNC_STATE_ChangeState((GsyncStateWork *)p, (int)GSYNC_STATE_StateSendFinalRequest, 0x6a2);
    }
}

void GSYNC_STATE_StateWaitInputPrintNext(char *p)
{
    if (KEY_GetTrg() || TOUCHPANEL_GetTrg()) {
        GSYNC_MESSAGE_PrintId((GsyncMessageWork *)((u8 *)(((GsyncStateWork *)p)->messageWork)), 48);
        GSYNC_MESSAGE_PrintInWindow((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork), 7, 14);
        GSYNC_STATE_ChangeState((GsyncStateWork *)p, (int)GSYNC_STATE_StateWaitInputClearWindow, 0x6ab);
    }
}

void GSYNC_STATE_StatePrintErrorMessage(char *p)
{
    GSYNC_MESSAGE_PrintDefault((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork), func_0200853C((const struct Sub0200852CObj *)func_02012944(((struct GsyncConn *)(((GsyncStateWork *)p)->connection))->saveData)));
    GSYNC_MESSAGE_PrintStream((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork), 1);
    GSYNC_MESSAGE_PrintId((GsyncMessageWork *)((u8 *)(((GsyncStateWork *)p)->messageWork)), 47);
    GSYNC_MESSAGE_PrintInWindow((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork), 7, 14);
    GSYNC_STATE_ChangeState((GsyncStateWork *)p, (int)GSYNC_STATE_StateWaitInputPrintNext, 0x6b7);
}

void GSYNC_STATE_StateReceiveResponse(char *p)
{
    char *q;
    if (GFL_NET_GetRunState()) {
        if (GSYNC_STATE_HandleHttpError((GsyncStateWork *)p, NHTTP_RAP_GetResultCode(((GsyncStateWork *)p)->httpConnection))) return;
        if (NHTTP_RAP_PollConnection(((GsyncStateWork *)p)->httpConnection)) return;
        q = (char *)NHTTP_RAP_GetRecvBuffer((u8 *)(((GsyncStateWork *)p)->httpConnection));
        if (((GsyncHttpResponse *)q)->resultCode == 2) {
            GSYNC_STATE_ChangeState((GsyncStateWork *)p, (int)GSYNC_STATE_StateSendFinalRequest, 0x6d4);
            return;
        }
        if (((GsyncHttpResponse *)q)->resultCode == 0) {
            GSYNC_MESSAGE_ClearStream((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork));
            GSYNC_STATE_ChangeState((GsyncStateWork *)p, (int)GSYNC_STATE_StatePrintErrorMessage, 0x6d8);
            return;
        }
        ((GsyncStateWork *)p)->errorCode = ((GsyncHttpResponse *)q)->resultCode;
        GSYNC_STATE_ChangeState((GsyncStateWork *)p, (int)GSYNC_STATE_StateErrorMessage, 0x6dc);
        return;
    } else {
        GSYNC_STATE_ChangeState((GsyncStateWork *)p, (int)GSYNC_STATE_StateSendFinalRequest, 0x6e2);
    }
}

void GSYNC_STATE_StateSendResponse(char *p)
{
    int x;
    unsigned int v;
    if (GFL_NET_GetRunState()) {
        if (NHTTP_RAP_CreateRequest(9,((GsyncStateWork *)p)->httpConnection)) {
            v=(unsigned int)SAVE_CONTROL_GetWorkArea(((GsyncStateWork *)p)->saveControl,&x);
            NHTTP_AddPostDataRaw((void *)NHTTP_RAP_GetConnection(((GsyncStateWork *)p)->httpConnection),(void *)v,0x80000);
            if (!NHTTP_RAP_StartConnection(((GsyncStateWork *)p)->httpConnection))
                GSYNC_STATE_ChangeState((GsyncStateWork *)p,(int)GSYNC_STATE_StateReceiveResponse,0x6fa);
        }
    } else {
        if (KEY_GetTrg() || TOUCHPANEL_GetTrg())
            GSYNC_STATE_ChangeState((GsyncStateWork *)p,(int)GSYNC_STATE_StateReceiveResponse,0x700);
    }
}

void GSYNC_STATE_StateWaitInputThird(char *p)
{
    if (GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork))) {
        if (KEY_GetTrg() || TOUCHPANEL_GetTrg()) {
            GSYNC_STATE_ChangeState((GsyncStateWork *)p, (int)GSYNC_STATE_StateWaitMessageEnd, 0x727);
        }
    }
}

void GSYNC_STATE_StateWaitMessageThenPrintFourth(char *p)
{
    if (GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork))) {
        GSYNC_MESSAGE_PrintStreamId((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork), 17);
        GSYNC_STATE_ChangeState((GsyncStateWork *)p, (int)GSYNC_STATE_StateWaitInputThird, 0x739);
    }
}

void GSYNC_STATE_StateWaitInputFourth(char *p)
{
    if (GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork))) {
        if (KEY_GetTrg() || TOUCHPANEL_GetTrg()) {
            GSYNC_STATE_ChangeState((GsyncStateWork *)p, (int)GSYNC_STATE_StateSetErrorExit, 0x746);
        }
    }
}

void GSYNC_STATE_StateWaitMessageThenPrintFifth(char *p)
{
    if (GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork))) {
        GSYNC_MESSAGE_PrintStreamId((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork), 20);
        GSYNC_STATE_ChangeState((GsyncStateWork *)p, (int)GSYNC_STATE_StateWaitInputFourth, 0x758);
    }
}

void GSYNC_STATE_ParseResponse(GsyncStateWork *p,int x,int *q)
{
    int state;
    switch (*q) {
    case 0:
        state=((struct GsyncConn *)(p->connection))->state;
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
            if (p->responseValid==0) GSYNC_STATE_ChangeState(p,(int)GSYNC_STATE_StatePrintErrorMessage,0x78c);
            else GSYNC_STATE_ChangeState(p,(int)GSYNC_STATE_StateSendFinalRequest,0x78f);
            break;
        }
        break;
    case 5:
        if (((struct GsyncConn *)(p->connection))->state==3)
            GSYNC_STATE_ChangeState(p,(int)GSYNC_STATE_StateSendFinalRequest,0x797);
        else {
            p->errorCode=*q;
            GSYNC_STATE_ChangeState(p,(int)GSYNC_STATE_StateErrorMessage,0x79b);
        }
        break;
    case 8:
        switch (((struct GsyncConn *)(p->connection))->state) {
        case 0: GSYNC_STATE_ChangeState(p,(int)GSYNC_STATE_StateWaitMessageEnd,0x7a2); break;
        case 3: GSYNC_STATE_ChangeState(p,(int)GSYNC_STATE_StateSendResponse,0x7a6); break;
        }
        break;
    default:
        p->errorCode=*q;
        GSYNC_STATE_ChangeState(p,(int)GSYNC_STATE_StateErrorMessage,0x7ac);
        break;
    }
}

void GSYNC_STATE_StateReceiveParsedResponse(char *p)
{
    char *q;
    if (GFL_NET_GetRunState()) {
        if (GSYNC_STATE_HandleHttpError((GsyncStateWork *)p,NHTTP_RAP_GetResultCode(((GsyncStateWork *)p)->httpConnection))) return;
        if (NHTTP_RAP_PollConnection(((GsyncStateWork *)p)->httpConnection)) return;
        q=(char *)NHTTP_RAP_GetRecvBuffer((u8 *)(((GsyncStateWork *)p)->httpConnection));
        MI_CpuCopy8(q+0x80,(char *)((GsyncStateWork *)p)->connection+0xc,0x44);
        ((struct GsyncConn *)(((GsyncStateWork *)p)->connection))->rapFlags=1;
        GSYNC_STATE_ParseResponse((GsyncStateWork *)p,((GsyncConn *)q)->responseCode,(int *)q);
    } else {
        GSYNC_STATE_ChangeState((GsyncStateWork *)p,(int)GSYNC_STATE_StateWaitMessageEnd,0x7d4);
    }
}

void GSYNC_STATE_StateSendParsedRequest(char *p)
{
    GSYNC_MESSAGE_PrintStreamId((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork),13);
    GSYNC_MESSAGE_RestartTimeIcon((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork));
    if (GFL_NET_GetRunState()) {
        if (NHTTP_RAP_CreateRequest(0,((GsyncStateWork *)p)->httpConnection)) {
            if (!NHTTP_RAP_StartConnection(((GsyncStateWork *)p)->httpConnection))
                GSYNC_STATE_ChangeState((GsyncStateWork *)p,(int)GSYNC_STATE_StateReceiveParsedResponse,0x7ea);
        }
    } else {
        if (KEY_GetTrg() || TOUCHPANEL_GetTrg())
            GSYNC_STATE_ChangeState((GsyncStateWork *)p,(int)GSYNC_STATE_StateReceiveParsedResponse,0x7f1);
    }
}

void GSYNC_STATE_StateWaitMessageClearStream(char *p)
{
    if (GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork))) {
        if (KEY_GetTrg() || TOUCHPANEL_GetTrg()) {
            ((struct GsyncConn *)(((GsyncStateWork *)p)->connection))->state = 1;
            GSYNC_MESSAGE_ClearStream((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork));
            GSYNC_STATE_ChangeState((GsyncStateWork *)p, (int)GSYNC_STATE_StateFadeOutAfterMessage, 0x808);
        }
    }
}

void GSYNC_STATE_StatePrintFinalMessage(char *p)
{
    GSYNC_MESSAGE_PrintStreamId((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork), 19);
    GSYNC_STATE_ChangeState((GsyncStateWork *)p, (int)GSYNC_STATE_StateWaitMessageClearStream, 0x817);
}

void GSYNC_STATE_StateReceiveFinalResponse(char *p)
{
    char *q;
    int state;
    if (GFL_NET_GetRunState()) {
        if (GSYNC_STATE_HandleHttpError((GsyncStateWork *)p,NHTTP_RAP_GetResultCode(((GsyncStateWork *)p)->httpConnection))) return;
        if (NHTTP_RAP_PollConnection(((GsyncStateWork *)p)->httpConnection)) return;
        q=(char *)NHTTP_RAP_GetRecvBuffer((u8 *)(((GsyncStateWork *)p)->httpConnection));
        state=((GsyncHttpResponse *)q)->resultCode;
        if (state==0 || state==8) {
            MI_CpuCopy8(q+0x80,(char *)((GsyncStateWork *)p)->connection+0x1d8,0x80);
            ((struct GsyncConn *)(((GsyncStateWork *)p)->connection))->state=5;
            GSYNC_STATE_ChangeState((GsyncStateWork *)p,(int)GSYNC_STATE_StateFadeOutAfterMessage,0x837);
        } else {
            ((GsyncStateWork *)p)->errorCode=state;
            GSYNC_STATE_ChangeState((GsyncStateWork *)p,(int)GSYNC_STATE_StateErrorMessage,0x842);
        }
    } else {
        ((struct GsyncConn *)(((GsyncStateWork *)p)->connection))->state=5;
        GSYNC_STATE_ChangeState((GsyncStateWork *)p,(int)GSYNC_STATE_StateFadeOutAfterMessage,0x849);
    }
}

void GSYNC_STATE_StateSendFinalRequest(char *p)
{
    struct GsyncRtcDate saved, current;
    u32 value;
    int day;
    if (func_02008BD0(func_02008B14(((GsyncStateWork *)p)->saveControl)) && ((GsyncStateWork *)p)->responsePending) {
        GSYNC_STATE_ChangeState((GsyncStateWork *)p,(int)GSYNC_STATE_StateWaitMessageThenPrintSecond,0x85c);
        return;
    }
    value=func_020093C8((const struct Sub02009210Obj *)func_02009448(((GsyncStateWork *)p)->saveControl));
    saved.year=(u8)(value>>24);
    saved.month=(u8)(value>>16);
    saved.day=(u8)(value>>8);
    saved.week=(u8)value;
    GF_STANDARD_SetField00_F4E4((struct GsyncRtcDate *)&current);
    day=GF_STANDARD_SetupRtc_F540((struct GsyncRtcDate *)&saved);
    if (day==GF_STANDARD_SetupRtc_F540((struct GsyncRtcDate *)&current)) {
        GSYNC_STATE_ChangeState((GsyncStateWork *)p,(int)GSYNC_STATE_StateWaitMessageThenPrintSecond,0x869);
        return;
    }
    if (GFL_NET_GetRunState()) {
        if (NHTTP_RAP_CreateRequest(1,((GsyncStateWork *)p)->httpConnection) && !NHTTP_RAP_StartConnection(((GsyncStateWork *)p)->httpConnection))
            GSYNC_STATE_ChangeState((GsyncStateWork *)p,(int)GSYNC_STATE_StateReceiveFinalResponse,0x871);
    } else {
        if (KEY_GetTrg() || TOUCHPANEL_GetTrg())
            GSYNC_STATE_ChangeState((GsyncStateWork *)p,(int)GSYNC_STATE_StateReceiveFinalResponse,0x878);
    }
}

void GSYNC_STATE_StatePlaySeWaitInput(char *p)
{
    if (((GsyncStateWork *)p)->blinkTimer % 110 == 0) GFL_USE_PlaySeDefaultVolume(0x659);
    ++((GsyncStateWork *)p)->blinkTimer;
    if (KEY_GetTrg() || TOUCHPANEL_GetTrg())
        GSYNC_STATE_ChangeState((GsyncStateWork *)p, (int)GSYNC_STATE_StateSetErrorExit, 0x88e);
}

void GSYNC_STATE_StateWaitMessageThenNext(char *p)
{
    if (GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork))) {
        GSYNC_STATE_ChangeState((GsyncStateWork *)p, (int)GSYNC_STATE_StatePlaySeWaitInput, 0x8a0);
    }
}

void GSYNC_STATE_StateShowCompletionMessage(char *p)
{
    if (((GsyncStateWork *)p)->auxBuffer) {
        func_020307B0(((GsyncStateWork *)p)->auxBuffer);
        ((GsyncStateWork *)p)->auxBuffer=0;
    }
    ((GsyncStateWork *)p)->progressPercent=100;
    GSYNC_DISP_UpdateProgressPosition((GsyncDispWork *)(((GsyncStateWork *)p)->displayWork),100);
    GSYNC_MESSAGE_SetMonName(((GsyncStateWork *)p)->messageWork,14,0,(void *)((*(int *)&((GsyncStateWork *)p)->receivedMon)));
    GSYNC_MESSAGE_PrintStream((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork),0);
    GSYNC_DISP_CreateSlotActor((GsyncDispWork *)(((GsyncStateWork *)p)->displayWork),8);
    GSYNC_DISP_SetFadeDirection((GsyncStateWork *)(((GsyncStateWork *)p)->displayWork),0);
    GSYNC_DISP_CreateSlotActor((GsyncDispWork *)(((GsyncStateWork *)p)->displayWork),0);
    GSYNC_DISP_SetSlotAnimSeq(((GsyncStateWork *)p)->displayWork,4,6);
    GFL_USE_PlaySeDefaultVolume(0x658);
    GSYNC_STATE_ChangeState((GsyncStateWork *)p,(int)GSYNC_STATE_StateWaitMessageThenNext,0x8bd);
}

void GSYNC_STATE_StateSaveErrorExit(char *p)
{
    if (((GsyncStateWork *)p)->progressPercent<100) ++((GsyncStateWork *)p)->progressPercent;
    GSYNC_DISP_UpdateProgressPosition((GsyncDispWork *)(((GsyncStateWork *)p)->displayWork),((GsyncStateWork *)p)->progressPercent);
    switch (GAME_DATA_SaveMain((*(void * *)&((GsyncStateWork *)p)->saveData))) {
    case 1:
        if (((GsyncStateWork *)p)->receivedMonCopy) {
            func_020307B0(((GsyncStateWork *)p)->receivedMonCopy);
            ((GsyncStateWork *)p)->receivedMonCopy=0;
        }
        break;
    case 3:
        GFL_NET_STATE_SetError(0,0,0,0x3f3);
        GFL_NET_STATE_SetErrorMode(0);
        break;
    case 2:
        ((GsyncStateWork *)p)->saveActive=0;
        GSYNC_STATE_ChangeState((GsyncStateWork *)p,(int)GSYNC_STATE_StateShowCompletionMessage,0x8e6);
        break;
    }
}

/*
 * lever: GAME_DATA_GetTrainerRecord leaves its return in r0 for func_02008DF0.
 */
void GSYNC_STATE_StateTrainerRecordSaveStart(char *p)
{
    void *q;
    struct GsyncRtcDate date;
    q=func_02009448(((GsyncStateWork *)p)->saveControl);
    ((GsyncStateWork *)p)->monStored=0;
    GF_STANDARD_SetField00_F4E4((struct GsyncRtcDate *)&date);
    func_020093CC(q, (date.year << 24) | ((date.month & 255) << 16) | ((date.day & 255) << 8) | date.week);
    if (func_020093D8(q)!=127) {
        func_02009428(q,1);
        func_020093F0(q,126);
    }
    ((GsyncStateWork *)p)->progressPercent=50;
    func_02008DF0(GAME_DATA_GetTrainerRecord((*(void * *)&((GsyncStateWork *)p)->saveData)),119);
    ((GsyncStateWork *)p)->saveActive=1;
    GAME_DATA_SaveStart((int)((*(void * *)&((GsyncStateWork *)p)->saveData)));
    GSYNC_STATE_ChangeState((GsyncStateWork *)p,(int)GSYNC_STATE_StateSaveErrorExit,0x914);
}

void GSYNC_STATE_StateReceiveRecordResponse(char *p)
{
    char *q;
    int state;
    func_02009448(((GsyncStateWork *)p)->saveControl);
    GSYNC_DISP_UpdateParticles(((GsyncStateWork *)p)->displayWork);
    if (GSYNC_STATE_IsCommIdleWithTarget((GsyncStateWork *)p)) {
        if (((GsyncStateWork *)p)->waitTicks==0) {
            GSYNC_MESSAGE_PrintId((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork),42);
            GSYNC_MESSAGE_PrintInSubWindow((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork));
        } else if (((GsyncStateWork *)p)->waitTicks==360) {
            GSYNC_MESSAGE_PrintId((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork),43);
            GSYNC_MESSAGE_PrintInSubWindow((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork));
        } else if (((GsyncStateWork *)p)->waitTicks==720) {
            GSYNC_MESSAGE_PrintId((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork),44);
            GSYNC_MESSAGE_PrintInSubWindow((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork));
        }
        ++((GsyncStateWork *)p)->waitTicks;
    }
    if (GSYNC_STATE_IsConnectionAlive((GsyncStateWork *)p)) {
        if (((GsyncStateWork *)p)->progressPercent<50) ++((GsyncStateWork *)p)->progressPercent;
        GSYNC_DISP_UpdateProgressPosition((GsyncDispWork *)(((GsyncStateWork *)p)->displayWork),((GsyncStateWork *)p)->progressPercent);
        if (GSYNC_STATE_HandleHttpError((GsyncStateWork *)p,NHTTP_RAP_GetResultCode(((GsyncStateWork *)p)->httpConnection))) return;
        if (NHTTP_RAP_PollConnection(((GsyncStateWork *)p)->httpConnection)) return;
        q=(char *)NHTTP_RAP_GetRecvBuffer((u8 *)(((GsyncStateWork *)p)->httpConnection));
        if (GSYNC_STATE_IsCommIdleWithTarget((GsyncStateWork *)p)) GSYNC_MESSAGE_ClearWindow((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork));
        state=((GsyncHttpResponse *)q)->resultCode;
        if (state==0) {
            GSYNC_STATE_ChangeState((GsyncStateWork *)p,(int)GSYNC_STATE_StateTrainerRecordSaveStart,0x955);
            return;
        }
        ((GsyncStateWork *)p)->errorCode=state;
        GSYNC_STATE_ChangeState((GsyncStateWork *)p,(int)GSYNC_STATE_StateErrorMessage,0x959);
        return;
    } else {
        GSYNC_DISP_UpdateProgressPosition((GsyncDispWork *)(((GsyncStateWork *)p)->displayWork),((GsyncStateWork *)p)->progressStep);
        if (++((GsyncStateWork *)p)->progressStep==100) {
            if (GSYNC_STATE_IsCommIdleWithTarget((GsyncStateWork *)p)) GSYNC_MESSAGE_ClearWindow((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork));
            GSYNC_STATE_ChangeState((GsyncStateWork *)p,(int)GSYNC_STATE_StateTrainerRecordSaveStart,0x967);
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
    func_02009448(((GsyncStateWork *)p)->saveControl);
    if (GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork))) {
        ((GsyncStateWork *)p)->waitTicks=0;
        if (GSYNC_STATE_IsConnectionAlive((GsyncStateWork *)p)) {
            if (NHTTP_RAP_CreateRequest(3,((GsyncStateWork *)p)->httpConnection)) {
                v=(unsigned int)SAVE_CONTROL_GetWorkArea(((GsyncStateWork *)p)->saveControl,&x);
                NHTTP_AddPostDataRaw((void *)NHTTP_RAP_GetConnection(((GsyncStateWork *)p)->httpConnection),(void *)v,0x80000);
                GSYNC_DISP_UpdateProgressPosition((GsyncDispWork *)(((GsyncStateWork *)p)->displayWork),0);
                ((GsyncStateWork *)p)->progressPercent=0;
                if (!NHTTP_RAP_StartConnection(((GsyncStateWork *)p)->httpConnection))
                    GSYNC_STATE_ChangeState((GsyncStateWork *)p,(int)GSYNC_STATE_StateReceiveRecordResponse,0x986);
            }
        } else {
            GSYNC_DISP_UpdateProgressPosition((GsyncDispWork *)(((GsyncStateWork *)p)->displayWork),0);
            GSYNC_STATE_ChangeState((GsyncStateWork *)p,(int)GSYNC_STATE_StateReceiveRecordResponse,0x98c);
        }
    }
}

void GSYNC_STATE_StateStartTransferAnimation(char *p)
{
    if (--((GsyncStateWork *)p)->timer==0) {
        GSYNC_DISP_StartPaletteWave((GsyncDispWork *)((unsigned char *)(((GsyncStateWork *)p)->displayWork)));
        GSYNC_MESSAGE_PrintStreamId((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork),8);
        GSYNC_MESSAGE_RestartTimeIcon((GsyncMessageWork *)(((GsyncStateWork *)p)->messageWork));
        GSYNC_DISP_SetFadeDirection((GsyncStateWork *)(((GsyncStateWork *)p)->displayWork),1);
        GSYNC_DISP_SetSlotAnimSeq(((GsyncStateWork *)p)->displayWork,4,5);
        GSYNC_DISP_SetSlotAnimSeq(((GsyncStateWork *)p)->displayWork,0,0);
        GSYNC_DISP_CreateSlotActor((GsyncDispWork *)(((GsyncStateWork *)p)->displayWork),12);
        GFL_USE_PlaySeDefaultVolume(0x657);
        GSYNC_STATE_ChangeState((GsyncStateWork *)p,(int)GSYNC_STATE_StateSendRecordRequest,0x9a8);
    }
}

void GSYNC_STATE_StateTransferAnimationStep(char *p) { if(--((GsyncStateWork *)p)->timer==0) { GSYNC_DISP_CreateSlotActor((GsyncDispWork *)(((GsyncStateWork *)p)->displayWork),4); ((GsyncStateWork *)p)->timer=60; GSYNC_STATE_ChangeState((GsyncStateWork *)p,(int)GSYNC_STATE_StateStartTransferAnimation,0x9b9); } }

void GSYNC_STATE_StateTransferAnimationOpen(char *p)
{
    if (--((GsyncStateWork *)p)->timer == 0) {
        GSYNC_DISP_SetSlotAnimSeq(((GsyncStateWork *)p)->displayWork, 0, 1);
        GSYNC_DISP_CreateSlotActor((GsyncDispWork *)(((GsyncStateWork *)p)->displayWork), 2);
        GSYNC_DISP_CreateSlotActor((GsyncDispWork *)(((GsyncStateWork *)p)->displayWork), 3);
        ((GsyncStateWork *)p)->timer = 15;
        GSYNC_STATE_ChangeState((GsyncStateWork *)p, (int)GSYNC_STATE_StateTransferAnimationStep, 0x9cf);
    }
}

void GSYNC_STATE_StateTransferAnimationEffect(char *p) { if(--((GsyncStateWork *)p)->timer==0) { GSYNC_DISP_CreateEffectActorDefault((GsyncDispWork *)(((GsyncStateWork *)p)->displayWork)); GSYNC_DISP_EnableActorAutoAnim((GsyncDispWork *)(((GsyncStateWork *)p)->displayWork)); ((GsyncStateWork *)p)->timer=70; GSYNC_STATE_ChangeState((GsyncStateWork *)p,(int)GSYNC_STATE_StateTransferAnimationOpen,0x9e4); } }

void GSYNC_STATE_StateCreateReceivedMonIcon(char *p) { GSYNC_DISP_CreateMonIconActor(((GsyncStateWork *)p)->displayWork,(void *)func_020185F0(((GsyncStateWork *)p)->receivedMon),1); ((GsyncStateWork *)p)->timer=10; GSYNC_STATE_ChangeState((GsyncStateWork *)p,(int)GSYNC_STATE_StateTransferAnimationEffect,0x9f6); }

void GSYNC_STATE_StateStoreReceivedMon(char *p)
{
    void *v;
    void *q;
    void *t;
    v=func_02009448(((GsyncStateWork *)p)->saveControl);
    if (((GsyncStateWork *)p)->receivedMon) {
        func_020307B0(((GsyncStateWork *)p)->receivedMon);
        ((GsyncStateWork *)p)->receivedMon=0;
    }
    t=func_02007A18(((GsyncStateWork *)p)->boxSave,((GsyncStateWork *)p)->boxIndex,((GsyncStateWork *)p)->slotIndex);
    if (t) {
        q=POKE_TOOL_CreateFromBoxParam(t,((GsyncStateWork *)p)->heapId);
        func_02009294(v,q);
        ((GsyncStateWork *)p)->receivedMon=q;
        func_02007664(((GsyncStateWork *)p)->boxSave,((GsyncStateWork *)p)->boxIndex,((GsyncStateWork *)p)->slotIndex);
        func_020092F8(v,1);
        ((GsyncStateWork *)p)->monStored=1;
    }
    GSYNC_DISP_CreateSlotActor((GsyncDispWork *)(((GsyncStateWork *)p)->displayWork),0);
    GSYNC_DISP_CreateSlotActor((GsyncDispWork *)(((GsyncStateWork *)p)->displayWork),12);
    GSYNC_STATE_ChangeState((GsyncStateWork *)p,(int)GSYNC_STATE_StateCreateReceivedMonIcon,0xa2a);
}

void GSYNC_STATE_DestroyHttpConnection(char *p)
{
    if (*(u32 *)&((GsyncStateWork *)p)->httpConnection != 0) {
        NHTTP_RAP_DeleteConnection(((GsyncStateWork *)p)->httpConnection);
        NHTTP_RAP_Destroy(((GsyncStateWork *)p)->httpConnection);
        *(u32 *)&((GsyncStateWork *)p)->httpConnection = 0;
    }
}

/*
 * extent: two zero alignment bytes follow the return.
 */
void GSYNC_STATE_CommitReceivedMon(GsyncStateWork *p)
{
    void *v;
    void *q;
    v=func_02009448(p->saveControl);
    if (p->receivedMonCopy) {
        MI_CpuCopy8(p->receivedMonCopy,v,func_02009228());
        func_020307B0(p->receivedMonCopy);
        p->receivedMonCopy=0;
    }
    if (p->monStored) {
        q=func_02009290(v);
        func_020075B0(p->boxSave,p->boxIndex,p->slotIndex,POKE_TOOL_GetBoxParam(q));
        POKE_TOOL_ClearPartyParam(q);
        func_020092F8(v,0);
        p->monStored=0;
    }
}

/*
 * interface: 0203159C returns the allocation live in r0 (original store
 * at 020315C0, then return); legacy matched definition says void.
 */
int GSYNC_STATE_ProcInit(void *a,int b,GsyncConn *q)
{
    GsyncStateWork *p;
    int value;
    func_02034AC4((int)ov114_id);
    GFL_HEAP_CreateChildHeap(1,98,0x88000);
    p=(GsyncStateWork *) PROCSYS_AllocProcWork(a,0xb0,98);
    MI_CpuFill8(p,0,0xb0);
    p->heapId=98;
    if (!q) func_02034714(gGsyncStateAssertTag,0,gGsyncStateAssertTag);
    if (q) {
        p->connection=(char *)q;
        (*(void * *)&p->saveData)=q->saveData;
        p->saveControl=GAME_DATA_GetSaveControl(q->saveData);
        value=func_0200853C((const struct Sub0200852CObj *)func_02012944(q->saveData));
        (*(unsigned int *)&p->boxSave)=GAME_DATA_GetBoxManager(q->saveData);
        p->boxIndex=q->boxIndex;
        p->slotIndex=q->slotIndex;
        p->responsePending=func_020092EC((const struct Sub02009210Obj *)func_02009448(p->saveControl));
        p->responseValid=p->responsePending;
        func_02009448(p->saveControl);
        switch (q->state) {
        case 0:
            if (!value) func_02034714(gGsyncStateAssertTag,0,gGsyncStateAssertTag);
            GSYNC_STATE_ChangeState(p,(int)GSYNC_STATE_StateSendParsedRequest,0xa89);
            break;
        case 1:
            if (!value) func_02034714(gGsyncStateAssertTag,0,gGsyncStateAssertTag);
            GSYNC_STATE_ChangeState(p,(int)GSYNC_STATE_StateStoreReceivedMon,0xa8d);
            break;
        case 2:
            if (!value) func_02034714(gGsyncStateAssertTag,0,gGsyncStateAssertTag);
            GSYNC_STATE_ChangeState(p,(int)GSYNC_STATE_StateStoreReceivedMon,0xa91);
            break;
        case 3:
            if (!value) func_02034714(gGsyncStateAssertTag,0,gGsyncStateAssertTag);
            GSYNC_STATE_ChangeState(p,(int)GSYNC_STATE_StateSendParsedRequest,0xa95);
            break;
        case 4:
            GSYNC_STATE_ChangeState(p,(int)GSYNC_STATE_StatePrintFinalMessage,0xa98);
            break;
        }
        if (*(int *)&q->state!=4) {
            p->httpConnection=NHTTP_RAP_Create(98,value,(int)((char *)q+0x54));
            DWC_RAP_SetErrorCallback((int)GSYNC_STATE_DestroyHttpConnection,(int)p);
        }
    }
    p->displayWork=GSYNC_DISP_Init(p->heapId);
    p->messageWork=GSYNC_MESSAGE_InitSystem(p->heapId,39);
    WIPE_SYS_Start(0,1,1,0,6,1,p->heapId);
    GFL_NET_RestartWithDefaultTimeout(0,p->heapId);
    return 1;
}

int GSYNC_STATE_ProcMain(void *a, int b, int c, GsyncStateWork *p)
{
    void (*callback)(char *);
    int result;
    callback=(void (*)(char *))p->stateHandler;
    result=1;
    if (WIPE_SYS_EndCheck() && !p->netDone && func_0200FB24()) {
        if ((*(void * *)&p->downloadWork)) GSYNC_DOWNLOAD_CleanupOnce((GsyncDownloadWork *)((*(void * *)&p->downloadWork)));
        NHTTP_RAP_DeleteConnection(p->httpConnection);
        if (p->saveActive) {
            GAME_DATA_SaveCancel((*(void * *)&p->saveData));
            p->saveActive=0;
        }
        GSYNC_STATE_CommitReceivedMon(p);
        if (p->saveInProgress) func_0200F7C0(41);
        WIPE_SetBrightnessFadeOut(0,0);
        WIPE_SetBrightnessFadeOut(1,0);
        DWC_RAPCOMMON_HandleNetError(1,0);
        ((struct GsyncConn *)(p->connection))->state=7;
        return 1;
    }
    if (callback) { callback((char *)p); result=0; }
    if (p->confirmMenu) APP_TASKMENU_UpdateMenu(p->confirmMenu);
    if ((*(void * *)&p->downloadWork)) GSYNC_DOWNLOAD_Process((GsyncDownloadWork *)((*(void * *)&p->downloadWork)));
    GSYNC_DISP_Draw((GsyncDispWork *)(p->displayWork));
    GSYNC_MESSAGE_UpdateSystem((GsyncMessageWork *)(p->messageWork));
    return result;
}

/*
 * evidence: unlabelled ov009 02156DE0 leaf filed and verified before caller rerun.
 */
int GSYNC_STATE_ProcExit(void *a, int b, int c, GsyncStateWork *p)
{
    if (!WIPE_SYS_EndCheck()) return 0;
    if (p->confirmMenu) APP_TASKMENU_CloseMenu(p->confirmMenu);
    if (p->listBuffer) {
        func_020307B0(p->listBuffer);
        p->listBuffer=0;
    }
    GSYNC_MESSAGE_ExitSystem((GsyncMessageWork *)(p->messageWork));
    GSYNC_DISP_Exit((GsyncDispWork *)(p->displayWork));
    GSYNC_DOWNLOAD_FreeWork((GsyncDownloadWork *)(p->downloadWork));
    if (p->musicalSave) func_020307B0(p->musicalSave);
    if (p->extraSaveBuffer) func_020307B0(p->extraSaveBuffer);
    if (p->iconBuffer) func_020307B0(p->iconBuffer);
    if (p->receivedMon) func_020307B0(p->receivedMon);
    if (p->auxBuffer) func_020307B0(p->auxBuffer);
    if (GFL_NET_GetRunState()) DWC_RAP_SetErrorHookCallback(0,0);
    if (p->httpConnection) {
        NHTTP_RAP_Destroy(p->httpConnection);
        DWC_RAP_SetErrorCallback(0,0);
    }
    func_020315D4(a);
    func_020306F0(98);
    func_02034A5C((int)ov114_id);
    return 1;
}
