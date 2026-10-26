/*
 * file:     gsync_state.c
 * unit:     yes
 * function: GSYNC_STATE_HandleHttpError, GSYNC_STATE_IsConnectionAlive, GSYNC_STATE_IsCommIdleWithTarget, GSYNC_STATE_IsCommReady, GSYNC_STATE_SetNextState, GSYNC_STATE_ChangeState, GSYNC_STATE_StateWaitFade, GSYNC_STATE_StateFadeOutAfterMessage, GSYNC_STATE_StateFreeDownloadAndExit, GSYNC_STATE_StateWaitInputCancelSave, GSYNC_STATE_StateErrorMessage, GSYNC_STATE_StateSetErrorExit, GSYNC_STATE_StateWaitMessageInput, GSYNC_STATE_StateClearMessageExit, GSYNC_STATE_StateWaitEndingBgm, GSYNC_STATE_StateShowResultMessage, GSYNC_STATE_ResetSlotActors, GSYNC_STATE_LoadReceivedMon, GSYNC_STATE_StateSaveFinishMessage, GSYNC_STATE_StatePollResponse, GSYNC_STATE_StateSendRequest, GSYNC_STATE_StateSaveMainWait, GSYNC_STATE_StateSaveStart, GSYNC_STATE_StateCleanupDownload, GSYNC_STATE_StateFreeReceivedMon, GSYNC_STATE_StateExtraSaveMain, GSYNC_STATE_StateExtraSaveLoadStart, GSYNC_STATE_StateFreeExtraSaveBuffer, GSYNC_STATE_StateExtraSaveMainSecond, GSYNC_STATE_StateExtraSaveLoadStartSecond, GSYNC_STATE_StateMusicalSaveApply, GSYNC_STATE_StateMusicalSaveCreate, GSYNC_STATE_StateDownloadReset, GSYNC_STATE_StateMusicalSaveRetry, GSYNC_STATE_StateWaitDownloadIdle, GSYNC_STATE_StateRequestFile, GSYNC_STATE_StateWaitDownloadIdleThenRequest, GSYNC_STATE_StateRequestFileList, GSYNC_STATE_StateSetFileAttribute, GSYNC_STATE_StateInitDownload, GSYNC_STATE_StateSelectNextDownload, GSYNC_STATE_CopyMonRecord, GSYNC_STATE_StoreListEntries, GSYNC_STATE_HasListEntry, GSYNC_STATE_BuildMonEntry, GSYNC_STATE_BuildMonEntries, GSYNC_STATE_ApplyIconRecords, GSYNC_STATE_PrepareReceivedList, GSYNC_STATE_UpdateCurrentEntry, GSYNC_STATE_StateReceiveList, GSYNC_STATE_StateSendListRequest, GSYNC_STATE_StateWaitMessageThenSend, GSYNC_STATE_StateShowProgressMessage, GSYNC_STATE_StateWaitInputFirst, GSYNC_STATE_StateWaitMessageThenPrintSecond, GSYNC_STATE_StateWaitInputSecond, GSYNC_STATE_StateWaitMessageThenPrintThird, GSYNC_STATE_StateConfirmMenuSelect, GSYNC_STATE_StateOpenConfirmMenu, GSYNC_STATE_StateShowEmptyMessage, GSYNC_STATE_StateWaitMessageEnd, GSYNC_STATE_StateWaitInputClearWindow, GSYNC_STATE_StateWaitInputPrintNext, GSYNC_STATE_StatePrintErrorMessage, GSYNC_STATE_StateReceiveResponse, GSYNC_STATE_StateSendResponse, GSYNC_STATE_StateWaitInputThird, GSYNC_STATE_StateWaitMessageThenPrintFourth, GSYNC_STATE_StateWaitInputFourth, GSYNC_STATE_StateWaitMessageThenPrintFifth, GSYNC_STATE_ParseResponse, GSYNC_STATE_StateReceiveParsedResponse, GSYNC_STATE_StateSendParsedRequest, GSYNC_STATE_StateWaitMessageClearStream, GSYNC_STATE_StatePrintFinalMessage, GSYNC_STATE_StateReceiveFinalResponse, GSYNC_STATE_StateSendFinalRequest, GSYNC_STATE_StatePlaySeWaitInput, GSYNC_STATE_StateWaitMessageThenNext, GSYNC_STATE_StateShowCompletionMessage, GSYNC_STATE_StateSaveErrorExit, GSYNC_STATE_StateTrainerRecordSaveStart, GSYNC_STATE_StateReceiveRecordResponse, GSYNC_STATE_StateSendRecordRequest, GSYNC_STATE_StateStartTransferAnimation, GSYNC_STATE_StateTransferAnimationStep, GSYNC_STATE_StateTransferAnimationOpen, GSYNC_STATE_StateTransferAnimationEffect, GSYNC_STATE_StateCreateReceivedMonIcon, GSYNC_STATE_StateStoreReceivedMon, GSYNC_STATE_DestroyHttpConnection, GSYNC_STATE_CommitReceivedMon, GSYNC_STATE_ProcInit, GSYNC_STATE_ProcMain, GSYNC_STATE_ProcExit
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
 *   GFL_HEAP_Free 0x020307B0 arm
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 *   GAME_DATA_SaveStart 0x02012DAC thumb
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_NET_RefreshWmIconAtTopRight 0x0203D34C arm
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   GF_PANIC_Fail 0x02034714 arm
 *   DWC_RAP_SetErrorHookCallback 0x02156DE0 thumb ov009
 *   GF_OVERLAY_Load 0x02034AC4 arm
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   GFL_USE_GetRandom 0x020056EC thumb
 *   POKE_TOOL_NormalizeForm 0x02019D30 thumb
 *   KEY_GetTrg  0x020362DC  arm
 *   GAME_DATA_SaveCancel  0x02012E08  thumb
 *   NHTTP_RAP_DeleteConnection 0x021B9774 thumb ov114
 *   gGsyncMessageIds 0x021DA844 data a4
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   GFL_USE_SetBgmPaused 0x02005DE4 thumb
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 *   GFL_USE_PushBgm  0x02005E64  thumb
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   gGsyncStateAllocSource 0x021DAB78 data a1
 *   BLOCK20_SAVEDATA_GetPokemon 0x02009290 thumb
 *   BLOCK20_SAVEDATA_SetActive 0x020092F8 thumb
 *   BLOCK20_SAVEDATA_SetSavedValue 0x020093D4 thumb
 *   NHTTP_RAP_GetResultCode 0x021B99DC thumb ov114
 *   NHTTP_RAP_PollConnection 0x021B9790 thumb ov114
 *   NHTTP_RAP_GetRecvBuffer 0x021B97F4 thumb ov114
 *   NHTTP_RAP_CreateRequest 0x021B95D4 thumb ov114
 *   NHTTP_RAP_GetConnection 0x021B973C thumb ov114
 *   NHTTP_RAP_StartConnection 0x021B9748 thumb ov114
 *   NHTTP_AddPostDataRaw 0x021BE79C arm ov114
 *   BLOCK20_SAVEDATA_SetMode 0x020092D0 thumb
 *   CGEAR_SAVE_SetGsyncState 0x020090F8 thumb
 *   GF_STANDARD_CalcCrc16 0x0203F1FC arm
 *   CGEAR_SAVE_SetGsyncId 0x02009108 thumb
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   GAME_DATA_PartSaveMain 0x02012E7C thumb
 *   SAVE_CONTROL_DeleteExtraSaveBuffered 0x0200734C thumb
 *   ZUKAN_SKIN_SAVE_SetValidFlag 0x0200E8E0 thumb
 *   MUSICAL_DIST_SAVE_ProcessApply 0x0200C5F8 thumb
 *   gGsyncExtraSaveName 0x021DAB88 data a1
 *   gGsyncMusicalSaveName 0x021DAB90 data a1
 *   gGsyncRecordSaveName 0x021DAB9C data a1
 *   MUSICAL_DIST_SAVE_GetBlockSize 0x0200C6E4 thumb
 *   BLOCK20_SAVEDATA_GetRecord 0x02009390 thumb
 *   BLOCK20_SAVEDATA_SetRecord 0x020093A8 thumb
 *   BLOCK20_SAVEDATA_SetProgress 0x020093F0 thumb
 *   GF_STANDARD_CompareBytes 0x0203EFC8 arm
 *   BLOCK20_SAVEDATA_SetEntry 0x02009348 thumb
 *   TPOKE_DATA_Create 0x0202A128 thumb
 *   POKE_TOOL_GetPersonalParam 0x02019C90 thumb
 *   POKE_TOOL_FilterSpecies 0x02019D58 thumb
 *   TPOKE_DATA_IsRecordKindTwo 0x0202A19C thumb
 *   SYMBOL_SAVE_GetBlock 0x0200E0B0 thumb
 *   SYMBOL_SAVE_WriteRecord 0x0200E1A8 thumb
 *   TPOKE_Delete 0x0202A170 thumb
 *   BLOCK20_SAVEDATA_GetSavedValue 0x020093D0 thumb
 *   BLOCK20_SAVEDATA_SetPending 0x020092E0 thumb
 *   SAVE_CONTROL_GetWorkArea 0x020071D8 thumb
 *   BLOCK20_SAVEDATA_GetDateStamp 0x020093C8 thumb
 *   GF_STANDARD_GetCachedDate 0x0203F4E4 arm
 *   GF_STANDARD_GetDayOfYear 0x0203F540 arm
 *   GFL_NET_STATE_SetError 0x0203C9AC arm
 *   GFL_NET_STATE_SetErrorMode 0x0203C938 arm
 *   BLOCK20_SAVEDATA_GetProgress 0x020093D8 thumb
 *   BLOCK20_SAVEDATA_SetFlag 0x02009428 thumb
 *   POKE_TOOL_CastToBoxParam 0x020185F0 thumb
 *   BLOCK20_SAVEDATA_SetPokemon 0x02009294 thumb
 *   NHTTP_RAP_Destroy  0x021B9838  thumb  ov114
 *   ov114_id 0x00000072 data
 *   BLOCK20_SAVEDATA_GetPending 0x020092EC thumb
 *   NHTTP_RAP_Create 0x021B9800 thumb ov114
 *   DWC_RAP_SetErrorCallback 0x02156DC4 thumb ov009
 *   gGsyncStateAssertTag 0x021DABA4 data a1
 *   GFL_NET_ERR_HaltWithMessage 0x0200F7C0 thumb
 *   DWC_RAPCOMMON_HandleNetError 0x02157170 thumb ov009
 *   GFL_NET_ERR_GetErrorLevel 0x0200FB24 thumb
 *   WIPE_SYS_Start 0x0202208C thumb
 *   GAME_SYNC_GetBlock 0x02009448 thumb
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
 *   GSYNC_DOWNLOAD_GetFileBuffer 0x021D5BA0 thumb ov123
 *   GSYNC_DOWNLOAD_InitAsync 0x021D5BD4 thumb ov123
 *   GSYNC_DOWNLOAD_ClearResult 0x021D5C0C thumb ov123
 *   GSYNC_DOWNLOAD_Reset 0x021D5C2C thumb ov123
 *   GSYNC_DOWNLOAD_SetAttr 0x021D5C64 thumb ov123
 *   GSYNC_DOWNLOAD_IsBusy 0x021D5C9C thumb ov123
 *   GSYNC_DOWNLOAD_GetFileListAsync 0x021D5CF8 thumb ov123
 *   GSYNC_DOWNLOAD_GetFileAsync 0x021D5D24 thumb ov123
 *   GSYNC_DOWNLOAD_CleanupOnce 0x021D5D58 thumb ov123
 *   GSYNC_DOWNLOAD_Process 0x021D5D7C thumb ov123
 *   GSYNC_DOWNLOAD_GetFileSize 0x021D5D8C thumb ov123
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
 *   POKE_TOOL_SetLevelAndRecalc  0x02019CA0  thumb  arm9
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb  arm9
 *   POKE_TOOL_GetPartyParamSize  0x020173EC  thumb  arm9
 *   GAME_DATA_GetMyStatus  0x02012944  thumb  arm9
 *   BOX_SAVEDATA_FindFreeSlot  0x020076D0  thumb  arm9
 *   BLOCK20_SAVEDATA_GetBlock  0x02009210  thumb  arm9
 *   BOX_SAVEDATA_SetPokemon  0x020075B0  thumb  arm9
 *   BOX_SAVEDATA_ClearPokemon  0x02007664  thumb  arm9
 *   BOX_SAVEDATA_AddPokemon  0x020074D8  thumb  arm9
 *   BOX_SAVEDATA_GetPokemon  0x02007A18  thumb  arm9
 *   MYSTATUS_GetProfileId  0x0200853C  thumb  arm9
 *   CONSOLE_STAMP_GetDailyClock  0x02008B14  thumb  arm9
 *   DAILY_CLOCK_HasAllowance  0x02008BD0  thumb  arm9
 *   RECORD_AddOne  0x02008DF0  thumb  arm9
 *   BLOCK20_SAVEDATA_GetBlockSize  0x02009228  thumb  arm9
 *   BLOCK20_SAVEDATA_CountEntries  0x02009370  thumb  arm9
 *   BLOCK20_SAVEDATA_SetDateStamp  0x020093CC  thumb  arm9
 *   ZUKAN_SKIN_SAVE_GetSize  0x0200E8B0  thumb  arm9
 */
#include "gsync_message_types.h"
#include "gsync_download_types.h"
#include "gsync_common_types.h"
#include "../arm9/clact.h"
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

#include "../arm9/wipe.h"

#include "../arm9/net.h"
struct TaskMenuWork;

#include "../arm9/app_taskmenu.h"



#include "../arm9/mi_memory.h"

#include "../arm9/gfl_heap_wrap.h"


#include "../arm9/touchpanel.h"

#include "../arm9/gfl_use.h"
struct GameData;

#include "../arm9/game_data.h"

struct SaveControl;


#include "../arm9/gfl_heap.h"

#include "../arm9/procsys.h"








#include "../arm9/gf_panic.h"

#include "../ov009/dwc_rap.h"

#include "../arm9/gf_overlay.h"



#ifdef __MWERKS__
#define POKE_TOOL_GetPersonalParam POKE_TOOL_GetPersonalParam_hdr
#endif
#include "../arm9/poke_tool.h"
#ifdef __MWERKS__
#undef POKE_TOOL_GetPersonalParam
int POKE_TOOL_GetPersonalParam(u16, int, int);
#endif

#include "../arm9/key.h"

struct _NHTTPRapSession;

#include "../ov114/nhttp_rap.h"





struct GameSyncData;

#include "../arm9/game_sync.h"

#include "../arm9/box_savedata.h"

struct CgearSaveBlock;

#include "../arm9/block20_savedata.h"
struct PokemonParam;


struct BoxPokemon;









struct _NHTTPConnection;



#include "../ov114/d_nhttp.h"




#include "../arm9/save_control.h"

struct CGearSave;

#include "../arm9/cgear_save.h"

#include "../arm9/gf_standard.h"


#include "../arm9/zukan_skin_savedata.h"



#include "../arm9/musical_dist_save.h"



struct CgearSaveRecord;


struct CgearSaveBlock;






#ifdef __MWERKS__
#define TPOKE_DATA_IsRecordKindTwo TPOKE_DATA_IsRecordKindTwo_hdr
#endif
#include "../arm9/tpoke_data.h"
#ifdef __MWERKS__
#undef TPOKE_DATA_IsRecordKindTwo
int TPOKE_DATA_IsRecordKindTwo(u32, struct Container *, u16, u16, int);
#endif

#ifdef __MWERKS__
#define SYMBOL_SAVE_WriteRecord SYMBOL_SAVE_WriteRecord_hdr
#endif
#include "../arm9/symbol_save.h"
#ifdef __MWERKS__
#undef SYMBOL_SAVE_WriteRecord
void SYMBOL_SAVE_WriteRecord(struct SymbolSave *, u16, u16, u8, int, u8, u32);
#endif





struct MyStatus;


#include "../arm9/mystatus.h"

struct DailyClock;

#include "../arm9/console_stamp.h"


#include "../sdk_rtc.h"

struct RtcDateSigned;


#include "../arm9/net_state.h"






#include "../arm9/record.h"













#include "../arm9/net_err.h"


#include "../ov009/dwc_rapcommon.h"

#include "gsync_message.h"















#include "gsync_download.h"











struct GsyncDownloadWork;


#include "gsync_disp.h"












struct GsyncDispWork;







int GSYNC_STATE_HandleHttpError(GsyncStateWork *state,int resultCode);

int GSYNC_STATE_IsConnectionAlive(GsyncStateWork *state);

int GSYNC_STATE_IsCommIdleWithTarget(GsyncStateWork *state);

int GSYNC_STATE_IsCommReady(GsyncStateWork *state);

void GSYNC_STATE_SetNextState(GsyncStateWork *state,GsyncStateFunc nextState,int unused);

void GSYNC_STATE_ChangeState(GsyncStateWork *state,GsyncStateFunc nextState,int unused);

void GSYNC_STATE_StateWaitFade(GsyncStateWork *state);

void GSYNC_STATE_StateFadeOutAfterMessage(GsyncStateWork *state);

void GSYNC_STATE_StateFreeDownloadAndExit(GsyncStateWork *state);

void GSYNC_STATE_StateWaitInputCancelSave(GsyncStateWork *state);

void GSYNC_STATE_StateErrorMessage(GsyncStateWork *state);

void GSYNC_STATE_StateSetErrorExit(GsyncStateWork *state);

void GSYNC_STATE_StateWaitMessageInput(GsyncStateWork *state);

void GSYNC_STATE_StateClearMessageExit(GsyncStateWork *state);

void GSYNC_STATE_StateWaitEndingBgm(GsyncStateWork *state);

void GSYNC_STATE_StateShowResultMessage(GsyncStateWork *state);

void GSYNC_STATE_ResetSlotActors(void *state, u32 frame);

void GSYNC_STATE_LoadReceivedMon(GsyncStateWork *state);

void GSYNC_STATE_StateSaveFinishMessage(GsyncStateWork *state);

void GSYNC_STATE_StatePollResponse(GsyncStateWork *state);

void GSYNC_STATE_StateSendRequest(GsyncStateWork *state);

void GSYNC_STATE_StateSaveMainWait(GsyncStateWork *state);

void GSYNC_STATE_StateSaveStart(GsyncStateWork *state);

void GSYNC_STATE_StateCleanupDownload(GsyncStateWork *state);

void GSYNC_STATE_StateFreeReceivedMon(GsyncStateWork *state);

void GSYNC_STATE_StateExtraSaveMain(GsyncStateWork *state);

void GSYNC_STATE_StateExtraSaveLoadStart(GsyncStateWork *state);

void GSYNC_STATE_StateFreeExtraSaveBuffer(GsyncStateWork *state);

void GSYNC_STATE_StateExtraSaveMainSecond(GsyncStateWork *state);

void GSYNC_STATE_StateExtraSaveLoadStartSecond(GsyncStateWork *state);

void GSYNC_STATE_StateMusicalSaveApply(GsyncStateWork *state);

void GSYNC_STATE_StateMusicalSaveCreate(GsyncStateWork *state,int dataSize);

void GSYNC_STATE_StateDownloadReset(GsyncStateWork *state);

void GSYNC_STATE_StateMusicalSaveRetry(GsyncStateWork *state);

void GSYNC_STATE_StateWaitDownloadIdle(GsyncStateWork *state);

void GSYNC_STATE_StateRequestFile(GsyncStateWork *state);

void GSYNC_STATE_StateWaitDownloadIdleThenRequest(GsyncStateWork *state);

void GSYNC_STATE_StateRequestFileList(GsyncStateWork *state);

void GSYNC_STATE_StateSetFileAttribute(GsyncStateWork *state);

void GSYNC_STATE_StateInitDownload(GsyncStateWork *state);

void GSYNC_STATE_StateSelectNextDownload(GsyncStateWork *state);

void GSYNC_STATE_CopyMonRecord(void *saveSystem, char *records);

int GSYNC_STATE_StoreListEntries(void *saveSystem,u8 *listBuffer);

int GSYNC_STATE_HasListEntry(void *saveSystem,GsyncWireList *list);

void GSYNC_STATE_BuildMonEntry(GsyncStateWork *state, void *unused, int species, int gender, int form, int entryArg, int value);

void GSYNC_STATE_BuildMonEntries(GsyncStateWork *state,void *saveSystem,u8 *records);

void GSYNC_STATE_ApplyIconRecords(GsyncStateWork *state,GsyncWireList *list);

void GSYNC_STATE_PrepareReceivedList(GsyncStateWork *state, void *saveSystem, GsyncWireList *list, int *errorCode);

int GSYNC_STATE_UpdateCurrentEntry(GsyncStateWork *state);

void GSYNC_STATE_StateReceiveList(GsyncStateWork *state);

void GSYNC_STATE_StateSendListRequest(GsyncStateWork *state);

void GSYNC_STATE_StateWaitMessageThenSend(GsyncStateWork *state);

void GSYNC_STATE_StateShowProgressMessage(GsyncStateWork *state);

void GSYNC_STATE_StateWaitInputFirst(GsyncStateWork *state);

void GSYNC_STATE_StateWaitMessageThenPrintSecond(GsyncStateWork *state);

void GSYNC_STATE_StateWaitInputSecond(GsyncStateWork *state);

void GSYNC_STATE_StateWaitMessageThenPrintThird(GsyncStateWork *state);

void GSYNC_STATE_StateConfirmMenuSelect(GsyncStateWork *state);

void GSYNC_STATE_StateOpenConfirmMenu(GsyncStateWork *state);

void GSYNC_STATE_StateShowEmptyMessage(GsyncStateWork *state);

void GSYNC_STATE_StateWaitMessageEnd(GsyncStateWork *state);

void GSYNC_STATE_StateWaitInputClearWindow(GsyncStateWork *state);

void GSYNC_STATE_StateWaitInputPrintNext(GsyncStateWork *state);

void GSYNC_STATE_StatePrintErrorMessage(GsyncStateWork *state);

void GSYNC_STATE_StateReceiveResponse(GsyncStateWork *state);

void GSYNC_STATE_StateSendResponse(GsyncStateWork *state);

void GSYNC_STATE_StateWaitInputThird(GsyncStateWork *state);

void GSYNC_STATE_StateWaitMessageThenPrintFourth(GsyncStateWork *state);

void GSYNC_STATE_StateWaitInputFourth(GsyncStateWork *state);

void GSYNC_STATE_StateWaitMessageThenPrintFifth(GsyncStateWork *state);

void GSYNC_STATE_ParseResponse(GsyncStateWork *work,int resultCode,int *responseCode);

void GSYNC_STATE_StateReceiveParsedResponse(GsyncStateWork *state);

void GSYNC_STATE_StateSendParsedRequest(GsyncStateWork *state);

void GSYNC_STATE_StateWaitMessageClearStream(GsyncStateWork *state);

void GSYNC_STATE_StatePrintFinalMessage(GsyncStateWork *state);

void GSYNC_STATE_StateReceiveFinalResponse(GsyncStateWork *state);

void GSYNC_STATE_StateSendFinalRequest(GsyncStateWork *state);

void GSYNC_STATE_StatePlaySeWaitInput(GsyncStateWork *state);

void GSYNC_STATE_StateWaitMessageThenNext(GsyncStateWork *state);

void GSYNC_STATE_StateShowCompletionMessage(GsyncStateWork *state);

void GSYNC_STATE_StateSaveErrorExit(GsyncStateWork *state);

void GSYNC_STATE_StateTrainerRecordSaveStart(GsyncStateWork *state);

void GSYNC_STATE_StateReceiveRecordResponse(GsyncStateWork *state);

void GSYNC_STATE_StateSendRecordRequest(GsyncStateWork *state);

void GSYNC_STATE_StateStartTransferAnimation(GsyncStateWork *state);

void GSYNC_STATE_StateTransferAnimationStep(GsyncStateWork *state);

void GSYNC_STATE_StateTransferAnimationOpen(GsyncStateWork *state);

void GSYNC_STATE_StateTransferAnimationEffect(GsyncStateWork *state);

void GSYNC_STATE_StateCreateReceivedMonIcon(GsyncStateWork *state);

void GSYNC_STATE_StateStoreReceivedMon(GsyncStateWork *state);

void GSYNC_STATE_DestroyHttpConnection(void *arg, u32 errorCode, u32 errorType, int dwcError);

void GSYNC_STATE_CommitReceivedMon(GsyncStateWork *state);

int GSYNC_STATE_ProcInit(void *procSys,int unused,GsyncConn *connection);

int GSYNC_STATE_ProcMain(void *unused0, int unused1, int unused2, GsyncStateWork *state);

int GSYNC_STATE_ProcExit(void *procSys, int unused0, int unused1, GsyncStateWork *state);

extern const GsyncMessageIdTable gGsyncMessageIds;

extern const char gGsyncStateAllocSource[];

extern const char gGsyncExtraSaveName[];

extern const char gGsyncMusicalSaveName[];

extern const char gGsyncRecordSaveName[];

extern char ov114_id[];

extern const char gGsyncStateAssertTag[];

int GSYNC_STATE_HandleHttpError(GsyncStateWork *state,int resultCode)
{
    switch (resultCode) {
    case 503:
        state->errorCode=0xfff1;
        GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateErrorMessage,0xd3);
        return 1;
    case 502:
        state->errorCode=0xfff2;
        GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateErrorMessage,0xd7);
        return 1;
    }
    if (resultCode>=400) {
        state->errorCode=0xfff3;
        GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateErrorMessage,0xdd);
        return 1;
    }
    return 0;
}

int GSYNC_STATE_IsConnectionAlive(GsyncStateWork *state){u8 *connection=state->connection;if(((GsyncConn *)connection)->state==2)return 0;if(((GsyncConn *)connection)->rapFlags && ((GsyncConn *)connection)->rapState==4)return 0;if(GFL_NET_GetRunState())return 1;return 0;}

int GSYNC_STATE_IsCommIdleWithTarget(GsyncStateWork *state)
{
    char *connection = state->connection;

    return ((GsyncConn *)connection)->rapFlags != 0 && ((GsyncConn *)connection)->rapState == 0;
}

int GSYNC_STATE_IsCommReady(GsyncStateWork *state){u8 *connection=state->connection;if(((GsyncConn *)connection)->rapFlags){unsigned int rapState=((GsyncConn *)connection)->rapState;if(rapState==0)return 1;if(rapState==4)return 1;}return 0;}

void GSYNC_STATE_SetNextState(GsyncStateWork *state,GsyncStateFunc nextState,int unused){state->stateHandler=nextState;}

void GSYNC_STATE_ChangeState(GsyncStateWork *state,GsyncStateFunc nextState,int unused){GSYNC_STATE_SetNextState(state,nextState,unused);}

void GSYNC_STATE_StateWaitFade(GsyncStateWork *state)
{
    if (WIPE_SYS_EndCheck() != 0)
        GSYNC_STATE_ChangeState(state, 0, 0x157);
}

void GSYNC_STATE_StateFadeOutAfterMessage(GsyncStateWork *state)
{
    if (GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(state->messageWork))) {
        WIPE_SYS_Start(0,0,0,0,6,1,state->heapId);
        GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateWaitFade,0x16b);
    }
}

void GSYNC_STATE_StateFreeDownloadAndExit(GsyncStateWork *state){if(GSYNC_DOWNLOAD_ClearResult((GsyncDownloadWork *)((char *)(state->downloadWork)))){GSYNC_DOWNLOAD_FreeWork((GsyncDownloadWork *)((char *)(state->downloadWork)));state->downloadWork=0;GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateSetErrorExit,0x17c);}}

void GSYNC_STATE_StateWaitInputCancelSave(GsyncStateWork *state)
{
    if (state->saveInProgress != 0)
        return;
    if (KEY_GetTrg() == 0 && TOUCHPANEL_GetTrg() == 0)
        return;
    if (state->saveActive != 0) {
        GAME_DATA_SaveCancel((struct GameData *)(state->saveData));
        state->saveActive = 0;
    }
    GSYNC_STATE_CommitReceivedMon(state);
    if (state->downloadWork != 0) {
        if (GSYNC_DOWNLOAD_CleanupOnce((GsyncDownloadWork *)((char *)(state->downloadWork))) != 0)
            GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateFreeDownloadAndExit, 0x191);
        GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateSetErrorExit, 0x193);
    } else {
        GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateSetErrorExit, 0x196);
    }
}

/*
 * extent: unit includes the 28-byte store-and-tail stub at 021D706C.
 */
void GSYNC_STATE_StateErrorMessage(GsyncStateWork *state)
{
    int messageId=state->errorCode+29;
    if (state->httpConnection) NHTTP_RAP_DeleteConnection(state->httpConnection);
    if (state->errorCode==0xfff0) messageId=39;
    else if (state->errorCode==0xfff1) messageId=40;
    else if (state->errorCode==0xfff2) messageId=41;
    else if (state->errorCode==0xfff3) messageId=38;
    else if (state->errorCode<=0 || state->errorCode>=10) messageId=38;
    GSYNC_MESSAGE_ClearStream((GsyncMessageWork *)(state->messageWork));
    GSYNC_MESSAGE_PrintId((GsyncMessageWork *)((u8 *)(state->messageWork)),messageId);
    GSYNC_MESSAGE_PrintInWindow((GsyncMessageWork *)(state->messageWork),1,16);
    GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateWaitInputCancelSave,0x1b9);
}

void GSYNC_STATE_StateSetErrorExit(GsyncStateWork *state)
{
    ((struct GsyncConn *)(state->connection))->state=6;
    GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateFadeOutAfterMessage,0x1c9);
}

void GSYNC_STATE_StateWaitMessageInput(GsyncStateWork *state) { if(GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(state->messageWork)) && (KEY_GetTrg() || TOUCHPANEL_GetTrg())) GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateSetErrorExit,0x1d9); }

void GSYNC_STATE_StateClearMessageExit(GsyncStateWork *state)
{
    GsyncMessageIdTable messageIdTable=gGsyncMessageIds;
    if (state->downloadFlags) {
        GSYNC_MESSAGE_ClearStream((GsyncMessageWork *)(state->messageWork));
        GSYNC_MESSAGE_PrintId((GsyncMessageWork *)((u8 *)(state->messageWork)),messageIdTable.ids[state->downloadFlags]);
        GSYNC_MESSAGE_PrintInWindow((GsyncMessageWork *)(state->messageWork),1,8);
        GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateWaitMessageInput,0x1f0);
    } else {
        GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateSetErrorExit,0x1f3);
    }
}

void GSYNC_STATE_StateWaitEndingBgm(GsyncStateWork *state)
{
    if (GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(state->messageWork)) != 0) {
        int waitTicks = state->bgmWait - 1;
        state->bgmWait = waitTicks;
        if (waitTicks <= 0) {
            if (waitTicks == 0) {
                GFL_USE_PopBgm();
                GFL_USE_SetBgmPaused(0);
                GFL_USE_FadeInBgmFull(6);
            }
            if (KEY_GetTrg() != 0 || TOUCHPANEL_GetTrg() != 0) {
                GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateClearMessageExit, 0x20B);
            }
        }
    }
}

void GSYNC_STATE_StateShowResultMessage(GsyncStateWork *state)
{
    if (GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)((char *)((state->messageWork)))) == 0)
        return;
    if (KEY_GetTrg() == 0 && TOUCHPANEL_GetTrg() == 0)
        return;
    if (state->messageArg == 0) {
        GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateClearMessageExit, 0x217);
        return;
    }
    GSYNC_MESSAGE_ClearWindow((GsyncMessageWork *)((char *)((state->messageWork))));
    GSYNC_MESSAGE_SetMonName((void *)((state->messageWork)), 0x16, state->messageArg,
                 (void *)((state->receivedMon)));
    GSYNC_MESSAGE_PrintStream((GsyncMessageWork *)((char *)((state->messageWork))), 0);
    GFL_USE_SetBgmPaused((unsigned int)1);
    GFL_USE_PushBgm();
    GFL_USE_CancelChangeAndPlayBgm(0x515, 0xffff);
    state->bgmWait = 0xb4;
    GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateWaitEndingBgm, 0x222);
}

void GSYNC_STATE_ResetSlotActors(void *state, u32 frame) { GSYNC_DISP_SetSlotAnimSeq(((GsyncStateWork *)state)->displayWork,0,0); GSYNC_DISP_CreateSlotActor((GsyncDispWork *)((u8 *)(((GsyncStateWork *)state)->displayWork)),12); GSYNC_DISP_SetMainActorAnimSeq((GsyncDispWork *)(((GsyncStateWork *)state)->displayWork)); }

/*
 * lever: update the call-result local in both clamp arms to preserve its register.
 */
void GSYNC_STATE_LoadReceivedMon(GsyncStateWork *state)
{
    void *saveSystem;
    void *monData;
    int monSize;
    int monValue;
    saveSystem=GAME_SYNC_GetBlock(state->saveControl);
    if (state->receivedMon) {
        GFL_HEAP_Free(state->receivedMon);
        state->receivedMon=0;
    }
    if (BOX_SAVEDATA_FindFreeSlot(state->boxSave,&state->boxIndex,&state->slotIndex)) {
        monData=GFL_HEAP_Alloc(state->heapId,POKE_TOOL_GetPartyParamSize(),1,gGsyncStateAllocSource,0x245);
        monSize=POKE_TOOL_GetPartyParamSize();
        MI_CpuCopy8(BLOCK20_SAVEDATA_GetPokemon(saveSystem),monData,monSize);
        if (state->messageArg) {
            monValue=POKE_TOOL_GetPartyValue(monData,158,0);
            if (monValue==100) state->messageArg=0;
            if (monValue+state->messageArg>100) {
                state->messageArg=100-monValue;
                monValue=100;
            } else {
                monValue+=state->messageArg;
            }
            POKE_TOOL_SetLevelAndRecalc(monData,monValue);
        }
        BOX_SAVEDATA_AddPokemon(state->boxSave,(struct BoxPokemon *)(POKE_TOOL_GetBoxParam(monData)));
        state->receivedMon=monData;
        BLOCK20_SAVEDATA_SetActive(saveSystem,0);
        BLOCK20_SAVEDATA_SetSavedValue(saveSystem,state->entryId);
    }
}

void GSYNC_STATE_StateSaveFinishMessage(GsyncStateWork *state)
{
    struct ClactAnimCommand animCallback;
    GAME_SYNC_GetBlock(state->saveControl);
    if (GAME_DATA_SaveMain((*(void * *)&state->saveData))==2) {
        state->saveActive=0;
        state->saveInProgress=0;
        state->netDone=0;
        GSYNC_MESSAGE_ClearStream((GsyncMessageWork *)(state->messageWork));
        GSYNC_MESSAGE_SetMonName(state->messageWork,45,0,(void *)(state->receivedMon));
        GSYNC_MESSAGE_PrintInWindow((GsyncMessageWork *)(state->messageWork),1,4);
        GSYNC_DISP_CreateSlotActor((GsyncDispWork *)((u8 *)(state->displayWork)),0);
        GSYNC_DISP_SetSlotAnimSeq((GsyncDispWork *)(state->displayWork),6,7);
        GSYNC_DISP_SetSlotAnimSeq((GsyncDispWork *)(state->displayWork),0,1);
        animCallback.op=0; animCallback.param=state; animCallback.func=GSYNC_STATE_ResetSlotActors;
        GSYNC_DISP_SetSlotAnimCommand((GsyncDispWork *)(state->displayWork),0,&animCallback);
        GSYNC_DISP_SetFadeDirection((struct GsyncDispWork *)((u8 *)(state->displayWork)),0);
        GSYNC_DISP_CreateMonIconActor((GsyncDispWork *)(state->displayWork),(void *)POKE_TOOL_CastToBoxParam(state->receivedMon),0);
        GSYNC_DISP_RestartActorAnim((GsyncDispWork *)(state->displayWork));
        GFL_USE_PlaySeDefaultVolume(0x658);
        GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateShowResultMessage,0x295);
    }
}

void GSYNC_STATE_StatePollResponse(GsyncStateWork *state)
{
    if (GSYNC_STATE_HandleHttpError(state,NHTTP_RAP_GetResultCode(state->httpConnection))==0) {
        if (NHTTP_RAP_PollConnection(state->httpConnection)==0) {
            NHTTP_RAP_GetRecvBuffer(state->httpConnection);
            GAME_SYNC_GetBlock(state->saveControl);
            state->netDone=1;
            GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateSaveFinishMessage,0x2ae);
        }
    }
}

void GSYNC_STATE_StateSendRequest(GsyncStateWork *state)
{
    if (state->bgmWait) {
        --state->bgmWait;
        return;
    }
    if (GFL_NET_GetRunState()) {
        if (NHTTP_RAP_CreateRequest(8,state->httpConnection)) {
            state->postData[0]=1;
            state->postData[1]=0;
            NHTTP_AddPostDataRaw((void *)NHTTP_RAP_GetConnection(state->httpConnection),(void *)state->postData,4);
            if (NHTTP_RAP_StartConnection(state->httpConnection)==0)
                GSYNC_STATE_ChangeState(state,GSYNC_STATE_StatePollResponse,0x2cd);
        }
    }
}

void GSYNC_STATE_StateSaveMainWait(GsyncStateWork *state) { if(state->progressPercent<100) ++state->progressPercent; GSYNC_DISP_UpdateProgressPosition((GsyncDispWork *)(state->displayWork),state->progressPercent); if(GAME_DATA_SaveMain((*(void * *)&state->saveData))==1) { state->bgmWait=GFL_USE_GetRandom(190); GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateSendRequest,0x2e6); } }

void GSYNC_STATE_StateSaveStart(GsyncStateWork *state)
{
    void *saveSystem;
    int slotIndex;
    u8 *monHeader;
    saveSystem=GAME_SYNC_GetBlock(state->saveControl);
    state->saveInProgress=1;
    GSYNC_STATE_LoadReceivedMon(state);
    if(GSYNC_STATE_IsCommReady(state)==0) {
        GSYNC_STATE_StoreListEntries(saveSystem,(u8 *)(state->listBuffer));
        GSYNC_STATE_BuildMonEntries(state,saveSystem,(u8 *)(state->listBuffer));
        GSYNC_STATE_CopyMonRecord(saveSystem,(char *)(state->listBuffer));
        BLOCK20_SAVEDATA_SetMode(saveSystem,*(u8 *)(state->listBuffer+0x5a));
    } else {
        monHeader=((GsyncConn *)state->connection)->recvList;
        GSYNC_STATE_BuildMonEntry(state,saveSystem,((GsyncMonHeader *)monHeader)->species,monHeader[7],monHeader[6],((GsyncMonHeader *)monHeader)->arg,GFL_USE_GetRandom(8));
        for(slotIndex=0;slotIndex<20;slotIndex++) BLOCK20_SAVEDATA_SetEntry((struct CgearSaveBlock *)saveSystem,slotIndex,*(u16 *)(monHeader+8+slotIndex*2),monHeader[0x30+slotIndex]);
    }
    state->saveActive=1;
    GAME_DATA_SaveStart((struct GameData *)(state->saveData));
    GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateSaveMainWait,0x311);
}

void GSYNC_STATE_StateCleanupDownload(GsyncStateWork *state)
{
    if (GSYNC_DOWNLOAD_CleanupOnce((GsyncDownloadWork *)((char *)(state->downloadWork)))) {
        GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateDownloadReset, 0x319);
        return;
    }
    state->errorCode = 0xfff0;
    GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateErrorMessage, 0x31d);
}

void GSYNC_STATE_StateFreeReceivedMon(GsyncStateWork *state) { state->wantMusicalSave=0; GFL_HEAP_Free(state->iconBuffer); state->netDone=0; state->iconBuffer=0; GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateCleanupDownload,0x328); }

void GSYNC_STATE_StateExtraSaveMain(GsyncStateWork *state)
{
    struct SaveControl *saveControl = GAME_DATA_GetSaveControl((struct GameData *)(state->saveData));
    if(GAME_DATA_PartSaveMain((struct GameData *)(state->saveData),4)==2) {
        SAVE_CONTROL_DeleteExtraSaveBuffered(saveControl,4);
        CGEAR_SAVE_SetGsyncState((struct CGearSave *)BLOCK20_SAVEDATA_GetBlock((void *)saveControl),1);
        GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateFreeReceivedMon,0x333);
    }
}

void GSYNC_STATE_StateExtraSaveLoadStart(GsyncStateWork *state)
{
    u16 checksum;
    struct SaveControl *saveControl;
    u8 *downloadData;
    void *buffer;
    saveControl=GAME_DATA_GetSaveControl((struct GameData *)(state->saveData));
    downloadData=(u8 *)GSYNC_DOWNLOAD_GetFileBuffer((GsyncDownloadWork *)((char *)(state->downloadWork)));
    checksum=GF_STANDARD_CalcCrc16(downloadData,0x2600);
    if(checksum!=*(u16 *)(downloadData+0x2600)) {
        state->errorCode=0xfff0;
        GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateErrorMessage,0x345);
        return;
    }
    state->netDone=1;
    buffer=GFL_HEAP_Alloc(state->heapId,0x3000,0,gGsyncStateAllocSource,0x34a);
    state->iconBuffer=buffer;
    SAVE_CONTROL_LoadExtraSaveWithBuffer(saveControl,4,state->heapId,buffer,0x3000);
    MI_CpuCopy8(downloadData,buffer,0x2600);
    CGEAR_SAVE_SetGsyncId((struct CGearSave *)BLOCK20_SAVEDATA_GetBlock((void *)saveControl),checksum);
    GAME_DATA_PartSaveStart((struct GameData *)state->saveData,4);
    GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateExtraSaveMain,0x355);
}

void GSYNC_STATE_StateFreeExtraSaveBuffer(GsyncStateWork *state) { state->wantRecordSave=0; GFL_HEAP_Free(state->extraSaveBuffer); state->netDone=0; state->extraSaveBuffer=0; GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateCleanupDownload,0x360); }

void GSYNC_STATE_StateExtraSaveMainSecond(GsyncStateWork *state) { struct SaveControl *saveControl; saveControl=GAME_DATA_GetSaveControl((struct GameData *)(state->saveData)); if(GAME_DATA_PartSaveMain((struct GameData *)(state->saveData),7)==2) { SAVE_CONTROL_DeleteExtraSaveBuffered(saveControl,7); GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateFreeExtraSaveBuffer,0x36a); } }

void GSYNC_STATE_StateExtraSaveLoadStartSecond(GsyncStateWork *state)
{
    struct SaveControl *saveControl;
    u8 *downloadData;
    void *buffer;
    u16 checksum;
    saveControl=GAME_DATA_GetSaveControl((struct GameData *)(state->saveData));
    downloadData=(u8 *)GSYNC_DOWNLOAD_GetFileBuffer((GsyncDownloadWork *)((char *)(state->downloadWork)));
    checksum=GF_STANDARD_CalcCrc16(downloadData,0x6200);
    if(checksum!=*(u16 *)(downloadData+0x6200)) {
        state->errorCode=0xfff0;
        GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateErrorMessage,0x378);
        return;
    }
    state->netDone=1;
    buffer=GFL_HEAP_Alloc(state->heapId,0x6800,0,gGsyncStateAllocSource,0x37d);
    state->extraSaveBuffer=buffer;
    SAVE_CONTROL_LoadExtraSaveWithBuffer(saveControl,7,state->heapId,(void *)(state->extraSaveBuffer),0x6800);
    MI_CpuCopy8(downloadData,state->extraSaveBuffer,0x6200);
    ZUKAN_SKIN_SAVE_SetValidFlag((void *)(state->extraSaveBuffer),1);
    GAME_DATA_PartSaveStart((struct GameData *)state->saveData,7);
    GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateExtraSaveMainSecond,0x383);
}

void GSYNC_STATE_StateMusicalSaveApply(GsyncStateWork *state) { if(MUSICAL_DIST_SAVE_ProcessApply(state->musicalSave)) { state->netDone=0; state->musicalSave=0; GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateCleanupDownload,0x38e); } }

void GSYNC_STATE_StateMusicalSaveCreate(GsyncStateWork *state,int dataSize)
{
    u8 *downloadData;
    int wordCount;
    u16 checksum;
    state->wantExtraSave=0;
    downloadData=(u8 *)GSYNC_DOWNLOAD_GetFileBuffer((GsyncDownloadWork *)((char *)(state->downloadWork)));
    wordCount=dataSize/2;
    if(dataSize>0x1fc0e) {
        state->errorCode=0xfff0;
        GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateErrorMessage,0x39d);
        return;
    }
    checksum=GF_STANDARD_CalcCrc16(downloadData,dataSize);
    if(checksum!=*(u16 *)(downloadData+wordCount*2)) {
        state->errorCode=0xfff0;
        GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateErrorMessage,0x3a3);
        return;
    }
    state->netDone=1;
    (state->musicalSave)=MUSICAL_DIST_SAVE_CreateFromData((void *)(state->saveData),downloadData,dataSize,state->heapId);
    GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateMusicalSaveApply,0x3a9);
}

void GSYNC_STATE_StateDownloadReset(GsyncStateWork *state)
{
    if(GSYNC_DOWNLOAD_ClearResult((GsyncDownloadWork *)((char *)(state->downloadWork)))) {
        if(GSYNC_DOWNLOAD_Reset((GsyncDownloadWork *)((char *)(state->downloadWork)))) {
            state->errorCode=0xfff0;
            GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateErrorMessage,0x3b6);
            return;
        }
        GSYNC_DOWNLOAD_FreeWork((GsyncDownloadWork *)((char *)(state->downloadWork)));
        state->downloadWork=0;
        if(state->progressPercent<100) state->progressPercent+=10;
        GSYNC_DISP_UpdateProgressPosition((GsyncDispWork *)(state->displayWork),state->progressPercent);
        GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateSelectNextDownload,0x3c3);
    }
}

void GSYNC_STATE_StateMusicalSaveRetry(GsyncStateWork *state)
{
    switch(state->downloadKind) {
    case 0: GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateExtraSaveLoadStart,0x3cb); break;
    case 1: GSYNC_STATE_StateMusicalSaveCreate(state,(int)GSYNC_DOWNLOAD_GetFileSize((struct GsyncDownloadWork *)((u8 *)(state->downloadWork)))-2); break;
    case 2: GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateExtraSaveLoadStartSecond,0x3d1); break;
    }
}

void GSYNC_STATE_StateWaitDownloadIdle(GsyncStateWork *state)
{
    if(GSYNC_DOWNLOAD_Reset((GsyncDownloadWork *)((char *)(state->downloadWork)))) {
        state->errorCode=0xfff0;
        GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateErrorMessage,0x3dd);
        return;
    }
    if(GSYNC_DOWNLOAD_ClearResult((GsyncDownloadWork *)((char *)(state->downloadWork)))) {
        GSYNC_DOWNLOAD_IsBusy((GsyncDownloadWork *)((char *)(state->downloadWork)));
        GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateMusicalSaveRetry,0x3e8);
    }
}

void GSYNC_STATE_StateRequestFile(GsyncStateWork *state)
{
    if (GSYNC_DOWNLOAD_GetFileAsync((GsyncDownloadWork *)((char *)(state->downloadWork)))) {
        GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateWaitDownloadIdle, 0x3f1);
        return;
    }
    state->errorCode = 0xfff0;
    GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateErrorMessage, 0x3f5);
}

void GSYNC_STATE_StateWaitDownloadIdleThenRequest(GsyncStateWork *state)
{
    if(GSYNC_DOWNLOAD_Reset((GsyncDownloadWork *)((char *)(state->downloadWork)))) {
        state->errorCode=0xfff0;
        GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateErrorMessage,0x3fe);
        return;
    }
    if(GSYNC_DOWNLOAD_ClearResult((GsyncDownloadWork *)((char *)(state->downloadWork)))) {
        if(GSYNC_DOWNLOAD_GetFileSize((struct GsyncDownloadWork *)((u8 *)(((u8 *)(state->downloadWork)))))==0) {
            state->errorCode=0xfff0;
            GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateErrorMessage,0x407);
            return;
        }
        GSYNC_DOWNLOAD_IsBusy((GsyncDownloadWork *)((char *)(state->downloadWork)));
        GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateRequestFile,0x40d);
    }
}

void GSYNC_STATE_StateRequestFileList(GsyncStateWork *state)
{
    if (GSYNC_DOWNLOAD_GetFileListAsync((GsyncDownloadWork *)((char *)(state->downloadWork)))) {
        GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateWaitDownloadIdleThenRequest, 0x415);
        return;
    }
    state->errorCode = 0xfff0;
    GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateErrorMessage, 0x419);
}

void GSYNC_STATE_StateSetFileAttribute(GsyncStateWork *state)
{
    if (GSYNC_DOWNLOAD_ClearResult((GsyncDownloadWork *)((*(void * *)&state->downloadWork)))) {
        if (GSYNC_DOWNLOAD_Reset((GsyncDownloadWork *)((*(void * *)&state->downloadWork)))) {
            state->errorCode = 0xfff0;
            GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateErrorMessage, 0x424);
            return;
        }
        switch (state->downloadKind) {
        case 0:
            if (GSYNC_DOWNLOAD_SetAttr((GsyncDownloadWork *)((*(void * *)&state->downloadWork)), (void *)gGsyncExtraSaveName, state->wantMusicalSave)) {
                GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateRequestFileList, 0x42b);
                return;
            }
            state->errorCode = 0xfff0;
            GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateErrorMessage, 0x42f);
            return;
        case 1:
            if (GSYNC_DOWNLOAD_SetAttr((GsyncDownloadWork *)((*(void * *)&state->downloadWork)), (void *)gGsyncMusicalSaveName, state->wantExtraSave)) {
                GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateRequestFileList, 0x434);
                return;
            }
            state->errorCode = 0xfff0;
            GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateErrorMessage, 0x438);
            return;
        case 2:
            if (GSYNC_DOWNLOAD_SetAttr((GsyncDownloadWork *)((*(void * *)&state->downloadWork)), (void *)gGsyncRecordSaveName, state->wantRecordSave)) {
                GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateRequestFileList, 0x43d);
                return;
            }
            state->errorCode = 0xfff0;
            GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateErrorMessage, 0x441);
            return;
        }
    }
}

void GSYNC_STATE_StateInitDownload(GsyncStateWork *state)
{
    switch (state->downloadKind) {
    case 0: (*(void * *)&state->downloadWork) = GSYNC_DOWNLOAD_AllocWork(state->heapId, MUSICAL_DIST_SAVE_GetBlockSize() + 4); break;
    case 1: (*(void * *)&state->downloadWork) = GSYNC_DOWNLOAD_AllocWork(state->heapId, 0x20000); break;
    case 2: (*(void * *)&state->downloadWork) = GSYNC_DOWNLOAD_AllocWork(state->heapId, ZUKAN_SKIN_SAVE_GetSize() + 4); break;
    }
    if (GSYNC_DOWNLOAD_InitAsync((GsyncDownloadWork *)((*(void * *)&state->downloadWork)))) {
        GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateSetFileAttribute, 0x458);
        return;
    }
    state->errorCode = 0xfff0;
    GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateErrorMessage, 0x45c);
}

void GSYNC_STATE_StateSelectNextDownload(GsyncStateWork *state)
{
    if (state->wantMusicalSave) {
        state->downloadKind = 0;
        GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateInitDownload, 0x465);
        return;
    }
    if (state->wantExtraSave) {
        state->downloadKind = 1;
        GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateInitDownload, 0x46a);
        return;
    }
    if (state->wantRecordSave) {
        state->downloadKind = 2;
        GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateInitDownload, 0x46f);
        return;
    }
    GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateSaveStart, 0x472);
}

/*
 * extent: two zero alignment bytes at 021D7CB2 follow the return.
 */
void GSYNC_STATE_CopyMonRecord(void *saveSystem, char *records)
{
    int changed = 0;
    int slotIndex;
    for (slotIndex = 0; slotIndex < 5; slotIndex++) {
        if (GF_STANDARD_CompareBytes((const u8 *)BLOCK20_SAVEDATA_GetRecord(saveSystem, slotIndex), (const u8 *)(records + 0x98 + slotIndex * 26), 26)) {
            changed = 1;
            break;
        }
    }
    if (changed) {
        for (slotIndex = 0; slotIndex < 5; slotIndex++) BLOCK20_SAVEDATA_SetRecord(saveSystem, slotIndex, records + 0x98 + slotIndex * 26);
        BLOCK20_SAVEDATA_SetProgress(saveSystem, 127);
    }
}

int GSYNC_STATE_StoreListEntries(void *saveSystem,u8 *listBuffer) { int slotIndex,found; u16 species; found=0; for(slotIndex=0;slotIndex<20;slotIndex++) { species=*(u16 *)(listBuffer+92+slotIndex*2); if(species!=0 && species<=626) { BLOCK20_SAVEDATA_SetEntry((struct CgearSaveBlock *)saveSystem,slotIndex,species,listBuffer[132+slotIndex]); found=1; } } return found; }

int GSYNC_STATE_HasListEntry(void *saveSystem,GsyncWireList *list) { int slotIndex,found; u16 species; found=0; for(slotIndex=0;slotIndex<20;slotIndex++) { species=list->iconSpecies[slotIndex]; if(species!=0 && species<=626) found=1; } return found; }

void GSYNC_STATE_BuildMonEntry(GsyncStateWork *state, void *unused, int species, int gender, int form, int entryArg, int value)
{
    int formIndex;
    u8 valueByte = value;
    void *pokeData;
    int kind;
    int mapped;
    int genderCode;
    if (species == 0 || species > 493) return;
    pokeData = TPOKE_DATA_Create(state->heapId);
    kind = 3;
    formIndex = (int)POKE_TOOL_NormalizeForm((u16)species, (u8)form);
    genderCode = POKE_TOOL_GetPersonalParam(species, formIndex, 20);
    mapped = POKE_TOOL_FilterSpecies(species, formIndex);
    switch (genderCode) {
    case 0: gender = 0; break;
    case 254: gender = 1; break;
    case 255: gender = 2; break;
    default: if (gender > 1) gender = GFL_USE_GetRandom(2); break;
    }
    if (TPOKE_DATA_IsRecordKindTwo((uptr)(state->saveData), pokeData, species, gender, mapped)) kind = 2;
    if (valueByte > 8) valueByte = 0;
    SYMBOL_SAVE_WriteRecord(SYMBOL_SAVE_GetBlock(state->saveControl), species, entryArg, gender, mapped, valueByte, kind);
    TPOKE_Delete(pokeData);
}

void GSYNC_STATE_BuildMonEntries(GsyncStateWork *state,void *saveSystem,u8 *records) { int slotIndex; GsyncListEntry *entry; for(slotIndex=0;slotIndex<10;slotIndex++) { entry=(GsyncListEntry *) (records+slotIndex*8); if(entry->species==0) break; GSYNC_STATE_BuildMonEntry(state,saveSystem,entry->species,((u8 *)entry)[9],((u8 *)entry)[8],entry->arg,((u8 *)entry)[10]); } }

void GSYNC_STATE_ApplyIconRecords(GsyncStateWork *state,GsyncWireList *list) { int slotIndex; u16 species; for(slotIndex=0;slotIndex<20;slotIndex++) { species=list->iconSpecies[slotIndex]; if(species!=0 && list->iconFlags[slotIndex]!=0 && species<=626) GSYNC_DISP_SetIconRecordSpecies(state->displayWork,slotIndex,species); } }

/*
 * lever: bind the record word before the call and use shared goto guards.
 */
void GSYNC_STATE_PrepareReceivedList(GsyncStateWork *state, void *saveSystem, GsyncWireList *list, int *errorCode)
{
    int slotIndex;
    int statusWord;
    if (*errorCode != 0) {
        state->errorCode = *errorCode;
        GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateErrorMessage, 0x500);
        return;
    }
    if (list->skipUpdate != 0) goto unchanged;
    statusWord = list->statusWord;
    if (statusWord == BLOCK20_SAVEDATA_GetSavedValue(saveSystem)) goto unchanged;
    {
        state->entryId = statusWord;
        state->wantExtraSave = list->wantExtraSave;
        state->wantMusicalSave = list->wantMusicalSave;
        state->wantRecordSave = list->wantRecordSave;
        state->messageArg = list->listFlags;
        if (state->wantMusicalSave) state->downloadFlags |= 1;
        if (state->wantExtraSave) state->downloadFlags |= 2;
        if (state->wantRecordSave) state->downloadFlags |= 4;
        for (slotIndex = 0; slotIndex < 10; slotIndex++) {
            if (*(u16 *)((u8 *)list+slotIndex*8+4) == 0) break;
            GSYNC_DISP_SetIconRecord(state->displayWork, slotIndex+20, *(u16 *)((u8 *)list+slotIndex*8+4), ((u8 *)list)[slotIndex*8+8], ((u8 *)list)[slotIndex*8+9]);
        }
        state->hasListEntry = GSYNC_STATE_HasListEntry(saveSystem,list);
        GSYNC_STATE_ApplyIconRecords(state,list);
        GSYNC_DISP_LoadIconResources((GsyncDispWork *)(state->displayWork));
    }
    goto done;
unchanged:
    state->hasListEntry = 0;
done:
    GSYNC_STATE_StateSelectNextDownload(state);
}

int GSYNC_STATE_UpdateCurrentEntry(GsyncStateWork *state)
{
    int slotIndex, otherIndex;
    char *list;
    GAME_SYNC_GetBlock(state->saveControl);
    list = (char *)((GsyncConn *)state->connection)->recvList;
    for (slotIndex = 0; slotIndex < 20; slotIndex++) {
        for (otherIndex = slotIndex + 1; otherIndex < 20; otherIndex++) {
            if (*(u16 *)(list + slotIndex * 2 + 8) != 0 &&
                *(u16 *)(list + otherIndex * 2 + 8) == *(u16 *)(list + slotIndex * 2 + 8))
                return 0;
        }
    }
    return 1;
}

void GSYNC_STATE_StateReceiveList(GsyncStateWork *state)
{
    char *response, *listData;
    void *saveSystem, *listBuffer;
    if (GSYNC_STATE_IsConnectionAlive(state) && !GSYNC_STATE_IsCommReady(state)) {
        if (state->progressPercent<30) ++state->progressPercent;
        GSYNC_DISP_UpdateProgressPosition((GsyncDispWork *)(state->displayWork),state->progressPercent);
        if (GSYNC_STATE_HandleHttpError(state,NHTTP_RAP_GetResultCode(state->httpConnection))) return;
        if (NHTTP_RAP_PollConnection(state->httpConnection)) return;
        response=(char *)NHTTP_RAP_GetRecvBuffer((struct _NHTTPRapSession *)(state->httpConnection));
        saveSystem=GAME_SYNC_GetBlock(state->saveControl);
        listData=response+0x80;
        listBuffer=GFL_HEAP_Alloc(state->heapId,0x11c,1,gGsyncStateAllocSource,0x573);
        (*(void * *)&state->listBuffer)=listBuffer;
        MI_CpuCopy8(listData,listBuffer,0x11c);
        GSYNC_STATE_PrepareReceivedList(state,saveSystem,(GsyncWireList *)listData,(int *)response);
        return;
    } else {
        ++state->waitTicks;
        if (state->progressPercent<30) ++state->progressPercent;
        if (state->waitTicks==360) {
            GSYNC_MESSAGE_PrintId((GsyncMessageWork *)(state->messageWork),43);
            GSYNC_MESSAGE_PrintInSubWindow((GsyncMessageWork *)(state->messageWork));
        } else if (state->waitTicks==720) {
            GSYNC_MESSAGE_PrintId((GsyncMessageWork *)(state->messageWork),44);
            GSYNC_MESSAGE_PrintInSubWindow((GsyncMessageWork *)(state->messageWork));
        } else if (state->waitTicks==1080) {
            if (GSYNC_STATE_IsCommIdleWithTarget(state)) GSYNC_MESSAGE_ClearWindow((GsyncMessageWork *)(state->messageWork));
            if (GSYNC_STATE_UpdateCurrentEntry(state)) {
                GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateSaveStart,0x58c);
            } else {
                state->errorCode=9;
                GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateErrorMessage,0x591);
            }
        }
        GSYNC_DISP_UpdateProgressPosition((GsyncDispWork *)(state->displayWork),state->progressPercent);
    }
}

void GSYNC_STATE_StateSendListRequest(GsyncStateWork *state)
{
    if (GSYNC_STATE_IsConnectionAlive(state) && !GSYNC_STATE_IsCommReady(state)) {
        if (NHTTP_RAP_CreateRequest(2, state->httpConnection) && !NHTTP_RAP_StartConnection(state->httpConnection)) {
            GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateReceiveList, 0x59d);
            return;
        }
    } else {
        if (GSYNC_STATE_IsCommIdleWithTarget(state)) {
            state->waitTicks = 0;
            GSYNC_MESSAGE_PrintId((GsyncMessageWork *)((u8 *)(state->messageWork)), 42);
            GSYNC_MESSAGE_PrintInSubWindow((GsyncMessageWork *)(state->messageWork));
        } else {
            state->waitTicks = 0x42e;
        }
        GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateReceiveList, 0x5aa);
    }
}

void GSYNC_STATE_StateWaitMessageThenSend(GsyncStateWork *state) { if(GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(state->messageWork))) GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateSendListRequest,0x5b3); }

void GSYNC_STATE_StateShowProgressMessage(GsyncStateWork *state)
{
    GSYNC_MESSAGE_PrintStreamId((GsyncMessageWork *)(state->messageWork), 11);
    GSYNC_MESSAGE_RestartTimeIcon((GsyncMessageWork *)(state->messageWork));
    GSYNC_DISP_DeleteSlotActor(state->displayWork, 8);
    GSYNC_DISP_StartPaletteWave((GsyncDispWork *)((u8 *)(state->displayWork)));
    GSYNC_DISP_SetFadeDirection((struct GsyncDispWork *)((u8 *)(state->displayWork)), 1);
    GSYNC_DISP_SetSlotAnimSeq(state->displayWork, 6, 5);
    GSYNC_DISP_CreateSlotActor((GsyncDispWork *)((u8 *)(state->displayWork)), 0);
    GSYNC_DISP_CreateSlotActor((GsyncDispWork *)((u8 *)(state->displayWork)), 12);
    GFL_USE_PlaySeDefaultVolume(0x657);
    GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateWaitMessageThenSend, 0x5c3);
}

void GSYNC_STATE_StateWaitInputFirst(GsyncStateWork *state)
{
    if (GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(state->messageWork))) {
        if (KEY_GetTrg() || TOUCHPANEL_GetTrg()) {
            GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateSetErrorExit, 0x5d0);
        }
    }
}

void GSYNC_STATE_StateWaitMessageThenPrintSecond(GsyncStateWork *state)
{
    if (GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(state->messageWork))) {
        GSYNC_MESSAGE_PrintStreamId((GsyncMessageWork *)(state->messageWork), 16);
        GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateWaitInputFirst, 0x5de);
    }
}

void GSYNC_STATE_StateWaitInputSecond(GsyncStateWork *state)
{
    if (GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(state->messageWork))) {
        if (KEY_GetTrg() || TOUCHPANEL_GetTrg()) {
            GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateSetErrorExit, 0x5e9);
        }
    }
}

void GSYNC_STATE_StateWaitMessageThenPrintThird(GsyncStateWork *state)
{
    if (GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(state->messageWork))) {
        GSYNC_MESSAGE_PrintStreamId((GsyncMessageWork *)(state->messageWork), 49);
        GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateWaitInputSecond, 0x5f6);
    }
}

void GSYNC_STATE_StateConfirmMenuSelect(GsyncStateWork *state)
{
    if (state->blinkTimer % 110 == 0) GFL_USE_PlaySeDefaultVolume(0x659);
    (state->blinkTimer)++;
    if (APP_TASKMENU_IsFinish(state->confirmMenu)) {
        if (APP_TASKMENU_GetCursorPos(state->confirmMenu) == 0) {
            if (BOX_SAVEDATA_FindFreeSlot(state->boxSave, &state->boxIndex, &state->slotIndex) == 0)
                GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateWaitMessageThenPrintThird, 0x60f);
            else
                GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateShowProgressMessage, 0x612);
        } else {
            GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateSetErrorExit, 0x616);
        }
        GSYNC_MESSAGE_ClearStream((GsyncMessageWork *)(state->messageWork));
        APP_TASKMENU_CloseMenu(state->confirmMenu);
        *(unsigned short *)0x04001050 = 0;
        state->confirmMenu = 0;
    }
}

void GSYNC_STATE_StateOpenConfirmMenu(GsyncStateWork *state)
{
    if (state->blinkTimer % 110 == 0) GFL_USE_PlaySeDefaultVolume(0x659);
    (state->blinkTimer)++;
    if (GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(state->messageWork))) {
        state->confirmMenu = (void *)GSYNC_MESSAGE_OpenYesNoMenu((GsyncMessageWork *)(state->messageWork), 0);
        GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateConfirmMenuSelect, 0x632);
    }
}

void GSYNC_STATE_StateShowEmptyMessage(GsyncStateWork *state)
{
    GSYNC_MESSAGE_ClearStream((GsyncMessageWork *)(state->messageWork));
    GSYNC_DISP_CreateSlotActor((GsyncDispWork *)((u8 *)(state->displayWork)), 0);
    GSYNC_DISP_CreateSlotActor((GsyncDispWork *)((u8 *)(state->displayWork)), 12);
    GSYNC_DISP_CreateSlotActor((GsyncDispWork *)((u8 *)(state->displayWork)), 6);
    GSYNC_DISP_CreateSlotActor((GsyncDispWork *)((u8 *)(state->displayWork)), 8);
    if (BLOCK20_SAVEDATA_CountEntries((struct CgearSaveBlock *)GAME_SYNC_GetBlock(state->saveControl)))
        GSYNC_MESSAGE_PrintStreamId((GsyncMessageWork *)(state->messageWork), 21);
    else
        GSYNC_MESSAGE_PrintStreamId((GsyncMessageWork *)(state->messageWork), 10);
    GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateOpenConfirmMenu, 0x64c);
}

void GSYNC_STATE_StateWaitMessageEnd(GsyncStateWork *state)
{
    if (GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(state->messageWork))) {
        GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateShowEmptyMessage, 0x68d);
    }
}

void GSYNC_STATE_StateWaitInputClearWindow(GsyncStateWork *state)
{
    if (KEY_GetTrg() != 0 || TOUCHPANEL_GetTrg() != 0) {
        GSYNC_MESSAGE_ClearWindow((GsyncMessageWork *)(state->messageWork));
        BLOCK20_SAVEDATA_SetPending((struct CgearSaveBlock *)GAME_SYNC_GetBlock(state->saveControl), 1);
        state->responseValid = 1;
        GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateSendFinalRequest, 0x6a2);
    }
}

void GSYNC_STATE_StateWaitInputPrintNext(GsyncStateWork *state)
{
    if (KEY_GetTrg() || TOUCHPANEL_GetTrg()) {
        GSYNC_MESSAGE_PrintId((GsyncMessageWork *)((u8 *)(state->messageWork)), 48);
        GSYNC_MESSAGE_PrintInWindow((GsyncMessageWork *)(state->messageWork), 7, 14);
        GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateWaitInputClearWindow, 0x6ab);
    }
}

void GSYNC_STATE_StatePrintErrorMessage(GsyncStateWork *state)
{
    GSYNC_MESSAGE_PrintDefault((GsyncMessageWork *)(state->messageWork), MYSTATUS_GetProfileId((struct MyStatus *)GAME_DATA_GetMyStatus(((struct GsyncConn *)(state->connection))->saveData)));
    GSYNC_MESSAGE_PrintStream((GsyncMessageWork *)(state->messageWork), 1);
    GSYNC_MESSAGE_PrintId((GsyncMessageWork *)((u8 *)(state->messageWork)), 47);
    GSYNC_MESSAGE_PrintInWindow((GsyncMessageWork *)(state->messageWork), 7, 14);
    GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateWaitInputPrintNext, 0x6b7);
}

void GSYNC_STATE_StateReceiveResponse(GsyncStateWork *state)
{
    char *response;
    if (GFL_NET_GetRunState()) {
        if (GSYNC_STATE_HandleHttpError(state, NHTTP_RAP_GetResultCode(state->httpConnection))) return;
        if (NHTTP_RAP_PollConnection(state->httpConnection)) return;
        response = (char *)NHTTP_RAP_GetRecvBuffer((struct _NHTTPRapSession *)(state->httpConnection));
        if (((GsyncHttpResponse *)response)->resultCode == 2) {
            GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateSendFinalRequest, 0x6d4);
            return;
        }
        if (((GsyncHttpResponse *)response)->resultCode == 0) {
            GSYNC_MESSAGE_ClearStream((GsyncMessageWork *)(state->messageWork));
            GSYNC_STATE_ChangeState(state, GSYNC_STATE_StatePrintErrorMessage, 0x6d8);
            return;
        }
        state->errorCode = ((GsyncHttpResponse *)response)->resultCode;
        GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateErrorMessage, 0x6dc);
        return;
    } else {
        GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateSendFinalRequest, 0x6e2);
    }
}

void GSYNC_STATE_StateSendResponse(GsyncStateWork *state)
{
    int workAreaSize;
    void *workArea;
    if (GFL_NET_GetRunState()) {
        if (NHTTP_RAP_CreateRequest(9,state->httpConnection)) {
            workArea=SAVE_CONTROL_GetWorkArea(state->saveControl,(unsigned int *)(&workAreaSize));
            NHTTP_AddPostDataRaw((void *)NHTTP_RAP_GetConnection(state->httpConnection),workArea,0x80000);
            if (!NHTTP_RAP_StartConnection(state->httpConnection))
                GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateReceiveResponse,0x6fa);
        }
    } else {
        if (KEY_GetTrg() || TOUCHPANEL_GetTrg())
            GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateReceiveResponse,0x700);
    }
}

void GSYNC_STATE_StateWaitInputThird(GsyncStateWork *state)
{
    if (GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(state->messageWork))) {
        if (KEY_GetTrg() || TOUCHPANEL_GetTrg()) {
            GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateWaitMessageEnd, 0x727);
        }
    }
}

void GSYNC_STATE_StateWaitMessageThenPrintFourth(GsyncStateWork *state)
{
    if (GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(state->messageWork))) {
        GSYNC_MESSAGE_PrintStreamId((GsyncMessageWork *)(state->messageWork), 17);
        GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateWaitInputThird, 0x739);
    }
}

void GSYNC_STATE_StateWaitInputFourth(GsyncStateWork *state)
{
    if (GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(state->messageWork))) {
        if (KEY_GetTrg() || TOUCHPANEL_GetTrg()) {
            GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateSetErrorExit, 0x746);
        }
    }
}

void GSYNC_STATE_StateWaitMessageThenPrintFifth(GsyncStateWork *state)
{
    if (GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(state->messageWork))) {
        GSYNC_MESSAGE_PrintStreamId((GsyncMessageWork *)(state->messageWork), 20);
        GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateWaitInputFourth, 0x758);
    }
}

void GSYNC_STATE_ParseResponse(GsyncStateWork *work,int resultCode,int *responseCode)
{
    int state;
    switch (*responseCode) {
    case 0:
        state=((struct GsyncConn *)(work->connection))->state;
        switch (state) {
        case 0:
            if (resultCode==0) GSYNC_STATE_ChangeState(work,GSYNC_STATE_StateWaitMessageEnd,0x774);
            else if (resultCode==3) GSYNC_STATE_ChangeState(work,GSYNC_STATE_StateWaitMessageEnd,0x777);
            else if (resultCode==1) GSYNC_STATE_ChangeState(work,GSYNC_STATE_StateWaitMessageThenPrintFourth,0x77b);
            else if (resultCode==2) GSYNC_STATE_ChangeState(work,GSYNC_STATE_StateWaitMessageThenPrintFifth,0x77f);
            else if (resultCode==4) GSYNC_STATE_ChangeState(work,GSYNC_STATE_StateWaitMessageEnd,0x782);
            else GSYNC_STATE_ChangeState(work,GSYNC_STATE_StateWaitMessageEnd,0x787);
            break;
        case 3:
            if (work->responseValid==0) GSYNC_STATE_ChangeState(work,GSYNC_STATE_StatePrintErrorMessage,0x78c);
            else GSYNC_STATE_ChangeState(work,GSYNC_STATE_StateSendFinalRequest,0x78f);
            break;
        }
        break;
    case 5:
        if (((struct GsyncConn *)(work->connection))->state==3)
            GSYNC_STATE_ChangeState(work,GSYNC_STATE_StateSendFinalRequest,0x797);
        else {
            work->errorCode=*responseCode;
            GSYNC_STATE_ChangeState(work,GSYNC_STATE_StateErrorMessage,0x79b);
        }
        break;
    case 8:
        switch (((struct GsyncConn *)(work->connection))->state) {
        case 0: GSYNC_STATE_ChangeState(work,GSYNC_STATE_StateWaitMessageEnd,0x7a2); break;
        case 3: GSYNC_STATE_ChangeState(work,GSYNC_STATE_StateSendResponse,0x7a6); break;
        }
        break;
    default:
        work->errorCode=*responseCode;
        GSYNC_STATE_ChangeState(work,GSYNC_STATE_StateErrorMessage,0x7ac);
        break;
    }
}

void GSYNC_STATE_StateReceiveParsedResponse(GsyncStateWork *state)
{
    char *response;
    if (GFL_NET_GetRunState()) {
        if (GSYNC_STATE_HandleHttpError(state,NHTTP_RAP_GetResultCode(state->httpConnection))) return;
        if (NHTTP_RAP_PollConnection(state->httpConnection)) return;
        response=(char *)NHTTP_RAP_GetRecvBuffer((struct _NHTTPRapSession *)(state->httpConnection));
        MI_CpuCopy8(response+0x80,(char *)((GsyncConn *)state->connection)->recvList,0x44);
        ((struct GsyncConn *)(state->connection))->rapFlags=1;
        GSYNC_STATE_ParseResponse(state,((GsyncHttpResponse *)response)->responseCode,(int *)response);
    } else {
        GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateWaitMessageEnd,0x7d4);
    }
}

void GSYNC_STATE_StateSendParsedRequest(GsyncStateWork *state)
{
    GSYNC_MESSAGE_PrintStreamId((GsyncMessageWork *)(state->messageWork),13);
    GSYNC_MESSAGE_RestartTimeIcon((GsyncMessageWork *)(state->messageWork));
    if (GFL_NET_GetRunState()) {
        if (NHTTP_RAP_CreateRequest(0,state->httpConnection)) {
            if (!NHTTP_RAP_StartConnection(state->httpConnection))
                GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateReceiveParsedResponse,0x7ea);
        }
    } else {
        if (KEY_GetTrg() || TOUCHPANEL_GetTrg())
            GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateReceiveParsedResponse,0x7f1);
    }
}

void GSYNC_STATE_StateWaitMessageClearStream(GsyncStateWork *state)
{
    if (GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(state->messageWork))) {
        if (KEY_GetTrg() || TOUCHPANEL_GetTrg()) {
            ((struct GsyncConn *)(state->connection))->state = 1;
            GSYNC_MESSAGE_ClearStream((GsyncMessageWork *)(state->messageWork));
            GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateFadeOutAfterMessage, 0x808);
        }
    }
}

void GSYNC_STATE_StatePrintFinalMessage(GsyncStateWork *state)
{
    GSYNC_MESSAGE_PrintStreamId((GsyncMessageWork *)(state->messageWork), 19);
    GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateWaitMessageClearStream, 0x817);
}

void GSYNC_STATE_StateReceiveFinalResponse(GsyncStateWork *state)
{
    char *response;
    int resultCode;
    if (GFL_NET_GetRunState()) {
        if (GSYNC_STATE_HandleHttpError(state,NHTTP_RAP_GetResultCode(state->httpConnection))) return;
        if (NHTTP_RAP_PollConnection(state->httpConnection)) return;
        response=(char *)NHTTP_RAP_GetRecvBuffer((struct _NHTTPRapSession *)(state->httpConnection));
        resultCode=((GsyncHttpResponse *)response)->resultCode;
        if (resultCode==0 || resultCode==8) {
            MI_CpuCopy8(response+0x80,(char *)((GsyncConn *)state->connection)->recvData,0x80);
            ((struct GsyncConn *)(state->connection))->state=5;
            GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateFadeOutAfterMessage,0x837);
        } else {
            state->errorCode=resultCode;
            GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateErrorMessage,0x842);
        }
    } else {
        ((struct GsyncConn *)(state->connection))->state=5;
        GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateFadeOutAfterMessage,0x849);
    }
}

void GSYNC_STATE_StateSendFinalRequest(GsyncStateWork *state)
{
    struct GsyncRtcDate saved, current;
    u32 rtcPacked;
    int day;
    if (DAILY_CLOCK_HasAllowance(CONSOLE_STAMP_GetDailyClock(state->saveControl)) && state->responsePending) {
        GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateWaitMessageThenPrintSecond,0x85c);
        return;
    }
    rtcPacked=BLOCK20_SAVEDATA_GetDateStamp((struct CgearSaveBlock *)GAME_SYNC_GetBlock(state->saveControl));
    saved.year=(u8)(rtcPacked>>24);
    saved.month=(u8)(rtcPacked>>16);
    saved.day=(u8)(rtcPacked>>8);
    saved.week=(u8)rtcPacked;
    GF_STANDARD_GetCachedDate((RTCDate *)&current);
    day=GF_STANDARD_GetDayOfYear((struct RtcDateSigned *)&saved);
    if (day==GF_STANDARD_GetDayOfYear((struct RtcDateSigned *)&current)) {
        GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateWaitMessageThenPrintSecond,0x869);
        return;
    }
    if (GFL_NET_GetRunState()) {
        if (NHTTP_RAP_CreateRequest(1,state->httpConnection) && !NHTTP_RAP_StartConnection(state->httpConnection))
            GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateReceiveFinalResponse,0x871);
    } else {
        if (KEY_GetTrg() || TOUCHPANEL_GetTrg())
            GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateReceiveFinalResponse,0x878);
    }
}

void GSYNC_STATE_StatePlaySeWaitInput(GsyncStateWork *state)
{
    if (state->blinkTimer % 110 == 0) GFL_USE_PlaySeDefaultVolume(0x659);
    ++state->blinkTimer;
    if (KEY_GetTrg() || TOUCHPANEL_GetTrg())
        GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateSetErrorExit, 0x88e);
}

void GSYNC_STATE_StateWaitMessageThenNext(GsyncStateWork *state)
{
    if (GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(state->messageWork))) {
        GSYNC_STATE_ChangeState(state, GSYNC_STATE_StatePlaySeWaitInput, 0x8a0);
    }
}

void GSYNC_STATE_StateShowCompletionMessage(GsyncStateWork *state)
{
    if (state->auxBuffer) {
        GFL_HEAP_Free(state->auxBuffer);
        state->auxBuffer=0;
    }
    state->progressPercent=100;
    GSYNC_DISP_UpdateProgressPosition((GsyncDispWork *)(state->displayWork),100);
    GSYNC_MESSAGE_SetMonName(state->messageWork,14,0,(void *)((state->receivedMon)));
    GSYNC_MESSAGE_PrintStream((GsyncMessageWork *)(state->messageWork),0);
    GSYNC_DISP_CreateSlotActor((GsyncDispWork *)(state->displayWork),8);
    GSYNC_DISP_SetFadeDirection((struct GsyncDispWork *)(state->displayWork),0);
    GSYNC_DISP_CreateSlotActor((GsyncDispWork *)(state->displayWork),0);
    GSYNC_DISP_SetSlotAnimSeq(state->displayWork,4,6);
    GFL_USE_PlaySeDefaultVolume(0x658);
    GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateWaitMessageThenNext,0x8bd);
}

void GSYNC_STATE_StateSaveErrorExit(GsyncStateWork *state)
{
    if (state->progressPercent<100) ++state->progressPercent;
    GSYNC_DISP_UpdateProgressPosition((GsyncDispWork *)(state->displayWork),state->progressPercent);
    switch (GAME_DATA_SaveMain((*(void * *)&state->saveData))) {
    case 1:
        if (state->receivedMonCopy) {
            GFL_HEAP_Free(state->receivedMonCopy);
            state->receivedMonCopy=0;
        }
        break;
    case 3:
        GFL_NET_STATE_SetError(0,0,0,0x3f3);
        GFL_NET_STATE_SetErrorMode(0);
        break;
    case 2:
        state->saveActive=0;
        GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateShowCompletionMessage,0x8e6);
        break;
    }
}

/*
 * lever: GAME_DATA_GetTrainerRecord leaves its return in r0 for RECORD_AddOne.
 */
void GSYNC_STATE_StateTrainerRecordSaveStart(GsyncStateWork *state)
{
    void *saveSystem;
    struct GsyncRtcDate date;
    saveSystem=GAME_SYNC_GetBlock(state->saveControl);
    state->monStored=0;
    GF_STANDARD_GetCachedDate((RTCDate *)&date);
    BLOCK20_SAVEDATA_SetDateStamp(saveSystem, (date.year << 24) | ((date.month & 255) << 16) | ((date.day & 255) << 8) | date.week);
    if (BLOCK20_SAVEDATA_GetProgress(saveSystem)!=127) {
        BLOCK20_SAVEDATA_SetFlag(saveSystem,1);
        BLOCK20_SAVEDATA_SetProgress(saveSystem,126);
    }
    state->progressPercent=50;
    RECORD_AddOne(GAME_DATA_GetTrainerRecord((*(void * *)&state->saveData)),119);
    state->saveActive=1;
    GAME_DATA_SaveStart(((*(void * *)&state->saveData)));
    GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateSaveErrorExit,0x914);
}

void GSYNC_STATE_StateReceiveRecordResponse(GsyncStateWork *state)
{
    char *response;
    int resultCode;
    GAME_SYNC_GetBlock(state->saveControl);
    GSYNC_DISP_UpdateParticles(state->displayWork);
    if (GSYNC_STATE_IsCommIdleWithTarget(state)) {
        if (state->waitTicks==0) {
            GSYNC_MESSAGE_PrintId((GsyncMessageWork *)(state->messageWork),42);
            GSYNC_MESSAGE_PrintInSubWindow((GsyncMessageWork *)(state->messageWork));
        } else if (state->waitTicks==360) {
            GSYNC_MESSAGE_PrintId((GsyncMessageWork *)(state->messageWork),43);
            GSYNC_MESSAGE_PrintInSubWindow((GsyncMessageWork *)(state->messageWork));
        } else if (state->waitTicks==720) {
            GSYNC_MESSAGE_PrintId((GsyncMessageWork *)(state->messageWork),44);
            GSYNC_MESSAGE_PrintInSubWindow((GsyncMessageWork *)(state->messageWork));
        }
        ++state->waitTicks;
    }
    if (GSYNC_STATE_IsConnectionAlive(state)) {
        if (state->progressPercent<50) ++state->progressPercent;
        GSYNC_DISP_UpdateProgressPosition((GsyncDispWork *)(state->displayWork),state->progressPercent);
        if (GSYNC_STATE_HandleHttpError(state,NHTTP_RAP_GetResultCode(state->httpConnection))) return;
        if (NHTTP_RAP_PollConnection(state->httpConnection)) return;
        response=(char *)NHTTP_RAP_GetRecvBuffer((struct _NHTTPRapSession *)(state->httpConnection));
        if (GSYNC_STATE_IsCommIdleWithTarget(state)) GSYNC_MESSAGE_ClearWindow((GsyncMessageWork *)(state->messageWork));
        resultCode=((GsyncHttpResponse *)response)->resultCode;
        if (resultCode==0) {
            GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateTrainerRecordSaveStart,0x955);
            return;
        }
        state->errorCode=resultCode;
        GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateErrorMessage,0x959);
        return;
    } else {
        GSYNC_DISP_UpdateProgressPosition((GsyncDispWork *)(state->displayWork),state->progressStep);
        if (++state->progressStep==100) {
            if (GSYNC_STATE_IsCommIdleWithTarget(state)) GSYNC_MESSAGE_ClearWindow((GsyncMessageWork *)(state->messageWork));
            GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateTrainerRecordSaveStart,0x967);
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
void GSYNC_STATE_StateSendRecordRequest(GsyncStateWork *state)
{
    int workAreaSize;
    void *workArea;
    GAME_SYNC_GetBlock(state->saveControl);
    if (GSYNC_MESSAGE_UpdateStream((GsyncMessageWork *)(state->messageWork))) {
        state->waitTicks=0;
        if (GSYNC_STATE_IsConnectionAlive(state)) {
            if (NHTTP_RAP_CreateRequest(3,state->httpConnection)) {
                workArea=SAVE_CONTROL_GetWorkArea(state->saveControl,(unsigned int *)(&workAreaSize));
                NHTTP_AddPostDataRaw((void *)NHTTP_RAP_GetConnection(state->httpConnection),workArea,0x80000);
                GSYNC_DISP_UpdateProgressPosition((GsyncDispWork *)(state->displayWork),0);
                state->progressPercent=0;
                if (!NHTTP_RAP_StartConnection(state->httpConnection))
                    GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateReceiveRecordResponse,0x986);
            }
        } else {
            GSYNC_DISP_UpdateProgressPosition((GsyncDispWork *)(state->displayWork),0);
            GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateReceiveRecordResponse,0x98c);
        }
    }
}

void GSYNC_STATE_StateStartTransferAnimation(GsyncStateWork *state)
{
    if (--state->timer==0) {
        GSYNC_DISP_StartPaletteWave((GsyncDispWork *)((unsigned char *)(state->displayWork)));
        GSYNC_MESSAGE_PrintStreamId((GsyncMessageWork *)(state->messageWork),8);
        GSYNC_MESSAGE_RestartTimeIcon((GsyncMessageWork *)(state->messageWork));
        GSYNC_DISP_SetFadeDirection((struct GsyncDispWork *)(state->displayWork),1);
        GSYNC_DISP_SetSlotAnimSeq(state->displayWork,4,5);
        GSYNC_DISP_SetSlotAnimSeq(state->displayWork,0,0);
        GSYNC_DISP_CreateSlotActor((GsyncDispWork *)(state->displayWork),12);
        GFL_USE_PlaySeDefaultVolume(0x657);
        GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateSendRecordRequest,0x9a8);
    }
}

void GSYNC_STATE_StateTransferAnimationStep(GsyncStateWork *state) { if(--state->timer==0) { GSYNC_DISP_CreateSlotActor((GsyncDispWork *)(state->displayWork),4); state->timer=60; GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateStartTransferAnimation,0x9b9); } }

void GSYNC_STATE_StateTransferAnimationOpen(GsyncStateWork *state)
{
    if (--state->timer == 0) {
        GSYNC_DISP_SetSlotAnimSeq(state->displayWork, 0, 1);
        GSYNC_DISP_CreateSlotActor((GsyncDispWork *)(state->displayWork), 2);
        GSYNC_DISP_CreateSlotActor((GsyncDispWork *)(state->displayWork), 3);
        state->timer = 15;
        GSYNC_STATE_ChangeState(state, GSYNC_STATE_StateTransferAnimationStep, 0x9cf);
    }
}

void GSYNC_STATE_StateTransferAnimationEffect(GsyncStateWork *state) { if(--state->timer==0) { GSYNC_DISP_CreateEffectActorDefault((GsyncDispWork *)(state->displayWork)); GSYNC_DISP_EnableActorAutoAnim((GsyncDispWork *)(state->displayWork)); state->timer=70; GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateTransferAnimationOpen,0x9e4); } }

void GSYNC_STATE_StateCreateReceivedMonIcon(GsyncStateWork *state) { GSYNC_DISP_CreateMonIconActor(state->displayWork,(void *)POKE_TOOL_CastToBoxParam(state->receivedMon),1); state->timer=10; GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateTransferAnimationEffect,0x9f6); }

void GSYNC_STATE_StateStoreReceivedMon(GsyncStateWork *state)
{
    void *saveSystem;
    void *monData;
    void *boxMon;
    saveSystem=GAME_SYNC_GetBlock(state->saveControl);
    if (state->receivedMon) {
        GFL_HEAP_Free(state->receivedMon);
        state->receivedMon=0;
    }
    boxMon=BOX_SAVEDATA_GetPokemon(state->boxSave,state->boxIndex,state->slotIndex);
    if (boxMon) {
        monData=POKE_TOOL_CreateFromBoxParam(boxMon,state->heapId);
        BLOCK20_SAVEDATA_SetPokemon(saveSystem,monData);
        state->receivedMon=monData;
        BOX_SAVEDATA_ClearPokemon(state->boxSave,state->boxIndex,state->slotIndex);
        BLOCK20_SAVEDATA_SetActive(saveSystem,1);
        state->monStored=1;
    }
    GSYNC_DISP_CreateSlotActor((GsyncDispWork *)(state->displayWork),0);
    GSYNC_DISP_CreateSlotActor((GsyncDispWork *)(state->displayWork),12);
    GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateCreateReceivedMonIcon,0xa2a);
}

void GSYNC_STATE_DestroyHttpConnection(void *arg, u32 errorCode, u32 errorType, int dwcError)
{
    GsyncStateWork *state = arg;
    if (state->httpConnection != 0) {
        NHTTP_RAP_DeleteConnection(state->httpConnection);
        NHTTP_RAP_Destroy(state->httpConnection);
        ((GsyncStateWork *)state)->httpConnection = 0;
    }
}

/*
 * extent: two zero alignment bytes follow the return.
 */
void GSYNC_STATE_CommitReceivedMon(GsyncStateWork *state)
{
    void *saveSystem;
    void *monData;
    saveSystem=GAME_SYNC_GetBlock(state->saveControl);
    if (state->receivedMonCopy) {
        MI_CpuCopy8(state->receivedMonCopy,saveSystem,BLOCK20_SAVEDATA_GetBlockSize());
        GFL_HEAP_Free(state->receivedMonCopy);
        state->receivedMonCopy=0;
    }
    if (state->monStored) {
        monData=BLOCK20_SAVEDATA_GetPokemon(saveSystem);
        BOX_SAVEDATA_SetPokemon(state->boxSave,state->boxIndex,state->slotIndex,POKE_TOOL_GetBoxParam(monData));
        POKE_TOOL_ClearPartyParam(monData);
        BLOCK20_SAVEDATA_SetActive(saveSystem,0);
        state->monStored=0;
    }
}

/*
 * interface: 0203159C returns the allocation live in r0 (original store
 * at 020315C0, then return); legacy matched definition says void.
 */
int GSYNC_STATE_ProcInit(void *procSys,int unused,GsyncConn *connection)
{
    GsyncStateWork *state;
    int profileValue;
    GF_OVERLAY_Load((sptr)ov114_id);
    GFL_HEAP_CreateChildHeap(1,98,0x88000);
    state=(GsyncStateWork *) PROCSYS_AllocProcWork(procSys,sizeof(GsyncStateWork),98);
    MI_CpuFill8(state,0,sizeof(GsyncStateWork));
    state->heapId=98;
    if (!connection) GF_PANIC_Fail(gGsyncStateAssertTag,0,gGsyncStateAssertTag);
    if (connection) {
        state->connection=(char *)connection;
        (*(void * *)&state->saveData)=connection->saveData;
        state->saveControl=GAME_DATA_GetSaveControl(connection->saveData);
        profileValue=MYSTATUS_GetProfileId((struct MyStatus *)GAME_DATA_GetMyStatus(connection->saveData));
        (state->boxSave)=(void *)GAME_DATA_GetBoxManager(connection->saveData);
        state->boxIndex=connection->boxIndex;
        state->slotIndex=connection->slotIndex;
        state->responsePending=BLOCK20_SAVEDATA_GetPending((struct CgearSaveBlock *)GAME_SYNC_GetBlock(state->saveControl));
        state->responseValid=state->responsePending;
        GAME_SYNC_GetBlock(state->saveControl);
        switch (connection->state) {
        case 0:
            if (!profileValue) GF_PANIC_Fail(gGsyncStateAssertTag,0,gGsyncStateAssertTag);
            GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateSendParsedRequest,0xa89);
            break;
        case 1:
            if (!profileValue) GF_PANIC_Fail(gGsyncStateAssertTag,0,gGsyncStateAssertTag);
            GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateStoreReceivedMon,0xa8d);
            break;
        case 2:
            if (!profileValue) GF_PANIC_Fail(gGsyncStateAssertTag,0,gGsyncStateAssertTag);
            GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateStoreReceivedMon,0xa91);
            break;
        case 3:
            if (!profileValue) GF_PANIC_Fail(gGsyncStateAssertTag,0,gGsyncStateAssertTag);
            GSYNC_STATE_ChangeState(state,GSYNC_STATE_StateSendParsedRequest,0xa95);
            break;
        case 4:
            GSYNC_STATE_ChangeState(state,GSYNC_STATE_StatePrintFinalMessage,0xa98);
            break;
        }
        if (connection->state!=4) {
            state->httpConnection=NHTTP_RAP_Create(98,profileValue,(char *)connection->rapKey);
            DWC_RAP_SetErrorCallback(GSYNC_STATE_DestroyHttpConnection, state);
        }
    }
    state->displayWork=GSYNC_DISP_Init(state->heapId);
    state->messageWork=GSYNC_MESSAGE_InitSystem(state->heapId,39);
    WIPE_SYS_Start(0,1,1,0,6,1,state->heapId);
    GFL_NET_RefreshWmIconAtTopRight(0,state->heapId);
    return 1;
}

int GSYNC_STATE_ProcMain(void *unused0, int unused1, int unused2, GsyncStateWork *state)
{
    GsyncStateFunc stateFunc;
    int result;
    stateFunc=state->stateHandler;
    result=1;
    if (WIPE_SYS_EndCheck() && !state->netDone && GFL_NET_ERR_GetErrorLevel()) {
        if ((*(void * *)&state->downloadWork)) GSYNC_DOWNLOAD_CleanupOnce((GsyncDownloadWork *)((*(void * *)&state->downloadWork)));
        NHTTP_RAP_DeleteConnection(state->httpConnection);
        if (state->saveActive) {
            GAME_DATA_SaveCancel((*(void * *)&state->saveData));
            state->saveActive=0;
        }
        GSYNC_STATE_CommitReceivedMon(state);
        if (state->saveInProgress) GFL_NET_ERR_HaltWithMessage(41);
        WIPE_SetBrightnessFadeOut(0,0);
        WIPE_SetBrightnessFadeOut(1,0);
        DWC_RAPCOMMON_HandleNetError(1,0);
        ((struct GsyncConn *)(state->connection))->state=7;
        return 1;
    }
    if (stateFunc) { stateFunc(state); result=0; }
    if (state->confirmMenu) APP_TASKMENU_UpdateMenu(state->confirmMenu);
    if ((*(void * *)&state->downloadWork)) GSYNC_DOWNLOAD_Process((GsyncDownloadWork *)((*(void * *)&state->downloadWork)));
    GSYNC_DISP_Draw((GsyncDispWork *)(state->displayWork));
    GSYNC_MESSAGE_UpdateSystem((GsyncMessageWork *)(state->messageWork));
    return result;
}

/*
 * evidence: unlabelled ov009 02156DE0 leaf filed and verified before caller rerun.
 */
int GSYNC_STATE_ProcExit(void *procSys, int unused0, int unused1, GsyncStateWork *state)
{
    if (!WIPE_SYS_EndCheck()) return 0;
    if (state->confirmMenu) APP_TASKMENU_CloseMenu(state->confirmMenu);
    if (state->listBuffer) {
        GFL_HEAP_Free(state->listBuffer);
        state->listBuffer=0;
    }
    GSYNC_MESSAGE_ExitSystem((GsyncMessageWork *)(state->messageWork));
    GSYNC_DISP_Exit((GsyncDispWork *)(state->displayWork));
    GSYNC_DOWNLOAD_FreeWork((GsyncDownloadWork *)(state->downloadWork));
    if (state->musicalSave) GFL_HEAP_Free(state->musicalSave);
    if (state->extraSaveBuffer) GFL_HEAP_Free(state->extraSaveBuffer);
    if (state->iconBuffer) GFL_HEAP_Free(state->iconBuffer);
    if (state->receivedMon) GFL_HEAP_Free(state->receivedMon);
    if (state->auxBuffer) GFL_HEAP_Free(state->auxBuffer);
    if (GFL_NET_GetRunState()) DWC_RAP_SetErrorHookCallback(0,0);
    if (state->httpConnection) {
        NHTTP_RAP_Destroy(state->httpConnection);
        DWC_RAP_SetErrorCallback(0,0);
    }
    PROCSYS_FreeProcWork(procSys);
    GFL_HEAP_DeleteChecked(98);
    GF_OVERLAY_Unload((sptr)ov114_id);
    return 1;
}
