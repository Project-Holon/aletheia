#ifndef GAME_ARM9_GFL_USE_H
#define GAME_ARM9_GFL_USE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gfl_use.c, prototypes copied from their definitions. */

struct Config;
struct TcbTask;
struct TcbList;
struct GflRandom;
struct SndHeap;
struct SndHandle;
struct SndWaveSetHeader;

#include "../arm9/tcb_list.h"
#include "../types.h"

void NitroMain(void);
int GFL_USE_IsNetQuiet(void);
void GFL_USE_HBlankHandler(void);
void GFL_USE_VBlankHandler(void);
void GFL_USE_PostIrqUpdate(void);
void GFL_USE_InitGameSystems(void);
void GFL_USE_UpdateFrameSubsystems(void);
void GFL_USE_ApplySoundModeFromConfig(const struct Config *config);
void GFL_USE_InitSdk(void);
void GFL_USE_PollPowerExit(void);
void GFL_USE_DoVramTransfer(void);
void GFL_USE_CtrdgDummyInit(void);
void GFL_USE_OnPreExit(void);
void GFL_USE_InitSystem(void);
void GFL_USE_PollFrameInput(void);
void GFL_USE_NoOpFrameHook(void);
void GFL_USE_RunHBlankTasks(void);
struct TcbTask *GFL_USE_AddHBlankTask(TcbFunc callback, void *work, u32 priority);
void GFL_USE_CallVBlankHook(void);
u32 GFL_USE_SetVBlankHook(void (*hook)(void *), void *hookArg);
void GFL_USE_ClearVBlankHook(void);
void GFL_USE_RunMainTasks(void);
struct TcbTask *GFL_USE_AddMainTask(TcbFunc callback, void *work, u32 priority);
struct TcbList *GFL_USE_GetMainTaskList(void);
void GFL_USE_InitRandomState(struct GflRandom *rand);
void GFL_USE_InitRandom(void);
u32 GFL_USE_GetRandom(u32 range);
u32 GFL_USE_GetRandomBelow(u32 range);
void *GFL_USE_GetArcPath(u32 index);
void GFL_USE_WaitInputReady(void);
void GFL_USE_MuteSound(void);
void GFL_USE_UnmuteSound(void);
void GFL_USE_SetSleepVolumeHooks(void);
int GFL_USE_IsMuteHookActive(void);
void GFL_USE_SetSndStackHeap(struct SndHeap **heapPtr);
void GFL_USE_InitSndSlot(u32 level);
void GFL_USE_BeginSndSlot(u32 state);
void GFL_USE_EndSndSlot(void);
void GFL_USE_InitSndStack(u16 playerNo);
u16 GFL_USE_GetCurrentBgmId(void);
u32 GFL_USE_GetSndStackDepth(void);
struct SndHandle *GFL_USE_GetCurrentSndHandle(void);
int GFL_USE_LoadBgmData(u32 bgmId);
void GFL_USE_SaveSeqBankState(void);
int GFL_USE_FinishBgmLoad(u32 bgmId);
void GFL_USE_UnloadBgmData(void);
int GFL_USE_PushSndSlot(void);
int GFL_USE_PopSndSlot(void);
struct SndWaveSetHeader *GFL_USE_LoadWaveArcSet(const u32 *waveArcIds, u32 count);
void GFL_USE_ReleaseWaveArcSet(const struct SndWaveSetHeader *header);
void GFL_USE_InitSound(void);
void GFL_USE_ResetSound(int clearHeap);
void GFL_USE_UpdateSound(void);
void GFL_USE_ClearSndHeap(void);
void GFL_USE_SetStereoOutput(u32 mode);
struct SndHandle *GFL_USE_GetBgmHandle(void);
u16 GFL_USE_GetBgmNo(void);
u32 GFL_USE_GetTargetBgmNo(void);
int GFL_USE_IsLoaderBusy(void);
int GFL_USE_IsCardIrqEnabled(void);
void GFL_USE_SetPlayersAudible(int enable, u32 playerMask);
void GFL_USE_SetPlayerVolumes(u32 volume, u32 playerMask);
int GFL_USE_IsSeqStartAllowed(u32 seqNo);
void GFL_USE_SetSeqStartFilter(int (*filter)(u32 seqNo));
void GFL_USE_StopBgm(void);
void GFL_USE_CancelChangeAndStopBgm(void);
u32 GFL_USE_PlayBgm(u32 bgmNo, u32 trackMask);
void GFL_USE_CancelChangeAndPlayBgm(u32 bgmNo, u32 trackMask);
void GFL_USE_ChangeBgm(unsigned int bgmNo, unsigned short trackMask, int fadeOutFrames, int fadeInFrames);
void GFL_USE_PlayFanfare(u32 seqNo);
void GFL_USE_SetBgmPaused(u32 value);
void GFL_USE_FadeInBgmFull(u32 frames);
void GFL_USE_FadeInBgm(u32 frames, u32 volume);
void GFL_USE_FadeOutBgm(u32 frames);
int GFL_USE_IsBgmFading(void);
int GFL_USE_PushBgm(void);
int GFL_USE_PopBgm(void);
void GFL_USE_SetBgmAudibleTracks(u32 trackMask);
void GFL_USE_SetBgmTrackParams(u32 trackMask, u32 tempoRatio, u32 pitch, u32 pan);
void GFL_USE_SetBgmTrackVolume(u32 trackMask, u32 volumeIndex);
int GFL_USE_IsBgmPlaying(void);
void GFL_USE_CancelChangeDefaultFade(void);
void GFL_USE_BeginBgmChange(u32 bgmNo, u16 trackMask, int fadeOutFrames, int fadeInFrames);
void GFL_USE_CancelBgmChange(void);
void GFL_USE_FlushBgmChange(void);
void GFL_USE_UpdateBgmChange(void);
void GFL_USE_InitSeSlots(void);
struct SndHandle *GFL_USE_GetSeHandle(int slot);
int GFL_USE_GetSeSlot(u32 seqNo);
void GFL_USE_PlaySeInSlot(u32 seqNo, int slot);
void GFL_USE_PlaySe(u32 seqNo, u32 volume);
void GFL_USE_PlaySeDefaultVolume(u32 seqNo);
void GFL_USE_PlaySeWithVolume(u32 seqNo, u32 volume);
void GFL_USE_StopSeSlot(int slot);
void GFL_USE_StopAllSe(void);
int GFL_USE_IsSeSlotBusy(u32 slot);
int GFL_USE_IsAnySeBusy(void);
int GFL_USE_IsSeqPlaying(u32 seqNo);
void GFL_USE_SetSeSlotParams(int slot, u32 tempoRatio, u32 pitch, u32 pan);
void GFL_USE_SetSeSlotVolume(int slot, u32 volume);
void GFL_USE_LoaderThreadSeqBank(void *arg);
void GFL_USE_LoaderThreadWaves(void *arg);
void GFL_USE_StartLoaderThread(u32 bgmNo, int mode);
void GFL_USE_StopLoaderThread(void);
int GFL_USE_IsLoaderDone(void);
u32 GFL_USE_StepBgmLoad(u32 bgmNo, u32 *step, u32 abort);
int GFL_USE_InstallBgmBuffers(u32 seqAddr, u32 bankAddr, u32 bgmNo);
int GFL_USE_ReplaceWaveData(u32 waveArcNo, u32 waveIndex, u32 srcWaveArc, u32 srcWaveIndex);
void GFL_USE_StartSeq(u32 seqNo);
void GFL_USE_StopSeqAndUnload(void);
void GFL_USE_ClearPreloadedBgmBuffers(void);
/* END mkheaders: generated region */

#endif
