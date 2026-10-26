#ifndef GAME_OV021_SCRCMD_TRAINER_AUDIO_ITEM_H
#define GAME_OV021_SCRCMD_TRAINER_AUDIO_ITEM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of scrcmd_trainer_audio_item.c, prototypes copied from their definitions. */

struct ScrcmdWork;
struct BgmEventWork;
struct PokeVoiceWork;
typedef struct ScrcmdWork ScrcmdWork;
typedef struct BgmEventWork BgmEventWork;
typedef struct PokeVoiceWork PokeVoiceWork;

#include "../arm9/script_vm_types.h"
#include "../types.h"
#include "../ov010/script_work_types.h"
#include "../ov020/event_mapchange_types.h"

int SCRCMD_CreateTrainerEye(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_CallTrainerEyePairEvent(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_GetTrainerHitKind(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_GetTrainerEyeTrainerId(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_GetTrainerEyeObjId(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_GetScriptTrainerId(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_StartTrainerBattle(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_StartMultiTrainerBattle(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_GetTrainerMessageIds(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_GetTrainerBattleKind(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_PlayTrainerEncounterBgm(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FadeInField(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_ClassifyTrainer(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_GetTrainerBattleParam(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_StartTrainerBattleWithMon(ScriptVm *vm, ScrcmdWork *cmdWork);
void SCRCMD_IncrementTrainerRecord(ScrcmdWork *cmdWork);
int SCRCMD_FadeOutPlayBgm(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FadeOutPlayBgmWithFade(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FadeOutPlayFixedBgm(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_IsBgmPlaying(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_WaitBgmStopped(ScriptVm *vm, void *user);
int SCRCMD_StartWaitBgmStopped(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FadeBgmVolume(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_RestoreBgmVolume(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_RestoreBgmVolumeEvent(BgmEventWork *work, u32 *seq);
int SCRCMD_ResumeZoneBgm(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_ResumeZoneBgmWithFade(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_PushBgmAndPlayWait(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_PushBgm(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_PopBgm(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_PopBgmEvent(BgmEventWork *work, u32 *seq);
int SCRCMD_ResumeBgmSlots(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_ResumeBgmSlotsEvent(BgmEventWork *work, u32 *seq);
void SCRCMD_ClearFinishedSeSlots(ScriptWork *scriptWork);
void SCRCMD_MarkSeSlot(ScriptWork *scriptWork, u32 seNo);
int SCRCMD_IsMarkedSeBusy(ScriptWork *scriptWork);
void SCRCMD_StopMarkedSeSlots(ScriptWork *scriptWork);
int SCRCMD_PlaySe(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_StopSe(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_WaitSeStopped(ScriptVm *vm, void *user);
int SCRCMD_StartWaitSeStopped(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_PushAndPlayBgm(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_WaitBgmThenPop(ScriptVm *vm, void *user);
int SCRCMD_StartWaitBgmThenPop(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_PlayPokeVoice(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_PlayPerapVoice(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_WaitPokeVoice(ScriptVm *vm, void *user);
int SCRCMD_StartWaitPokeVoice(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_IssSwitchOn(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_IssSwitchOff(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_IsIssSwitchOn(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_PokeVoiceEvent(struct GameEvent *event, int *seq, void *work);
int SCRCMD_AddItem(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_RemoveItem(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_CanAddItem(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_HasItem(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_GetItemQuantity(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_IsItemMachine(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_GetItemPocket(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_GetItemPartyUse(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_GetItemMachineFlag(u32 itemNo);
/* END mkheaders: generated region */

#endif
