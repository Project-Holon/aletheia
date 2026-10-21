#ifndef GAME_OV021_SCRCMD_MISC_H
#define GAME_OV021_SCRCMD_MISC_H

#include "../arm9/mic.h"

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of scrcmd_misc.c, prototypes copied from their definitions. */

struct ScrcmdWork;
struct IcaAnime;
typedef struct ScrcmdWork ScrcmdWork;
typedef struct IcaAnime IcaAnime;

#include "../arm9/script_vm_types.h"
#include "../ov021/scrcmd_misc_types.h"
#include "../ov020/event_mapchange_types.h"
#include "../types.h"
#include "../sdk_fx.h"
#include "../ov010/fldmmdl_types.h"
#include "../ov010/fld_btl_inst_tool_shared_types.h"

int SCRCMD_CheckWifiListFlags(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_WifiListOperation(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_SetWifiFriendNameWord(ScriptVm *vm, ScrcmdWork *cmdWork);
MmdlIcaWork *SCRCMD_MMDL_ICA_CreateProc(FieldMap *fieldMap, u16 mmdlId, VecFx32 *offset, u16 heapId);
void SCRCMD_MMDL_ICA_EndProc(MmdlIcaWork *work);
void SCRCMD_MMDL_ICA_Start(MmdlIcaWork *work, u32 animKind);
u32 SCRCMD_MMDL_ICA_IsDone(MmdlIcaWork *work, u32 unusedArg1, u32 unusedArg2, u32 unusedArg3);
void SCRCMD_MMDL_ICA_Update(u32 event, u32 state, MmdlIcaWork *work);
void SCRCMD_MMDL_ICA_Nop(void);
void SCRCMD_MMDL_ICA_ApplyFrame(IcaAnime *icaAnime, Mmdl *mmdl, VecFx32 *offset);
int SCRCMD_CreateMmdlIcaProc(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_EndMmdlIcaProc(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_StartMmdlIcaAnime(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MMDL_ICA_WaitTask(u32 event, u32 state, MmdlIcaWaitWork *work, u32 arg);
int SCRCMD_WaitMmdlIcaAnime(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_SUBSCREEN_ChangeModeTask(GameEvent *event, int *seq, SubscreenModeWork *work);
int SCRCMD_ChangeSubscreenMode(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_ResetSubscreenMode(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_SUBSCREEN_ResetModeTask(void **eventWords, int *seq);
GameEvent *EVENT_PERAP_RECORD_Create(GameSystem *gameSystem, FieldMap *fieldMap, u32 partySlot);
int EVENT_PERAP_RECORD_Main(GameEvent *event, int *seq, PerapRecordWork *work);
void EVENT_PERAP_RECORD_OnRecorded(MICResult result, void *arg);
void EVENT_PERAP_RECORD_PauseMmdls(PerapRecordWork *work);
void EVENT_PERAP_RECORD_ResumeMmdls(PerapRecordWork *work);
void EVENT_PERAP_RECORD_CreatePokeIcon(PerapRecordWork *work);
int EVENT_PERAP_RECORD_DeletePokeIcon(PerapRecordWork *work);
int EVENT_PERAP_RECORD_HopPokeIcon(PerapRecordWork *work);
void EVENT_PERAP_RECORD_SetupWindow(PerapRecordWork *work);
int EVENT_PERAP_RECORD_Cleanup(PerapRecordWork *work);
int SCRCMD_CheckPmsWordPair(ScriptVm *vm, ScrcmdWork *cmdWork);
int FIELD_SOUND_SYSTEM_FindSlotSound(u32 soundId);
int FIELD_SOUND_SYSTEM_IsSlotSoundTracked(u32 soundId);
GameEvent *SCRCMD_ShowStepMilestoneMessage(GameSystem *gameSystem, FieldMap *fieldMap);
int FLDEFF_RIPPLE_WarpToZoneStartTask(GameEvent *event, int *seq, RippleWarpWork *work);
int FLDEFF_RIPPLE_WarpToSpecialLocationTask(GameEvent *event, int *seq, RippleWarpWork *work);
GameEvent *FLDEFF_RIPPLE_CreateZoneStartWarpTask(GameSystem *gameSystem, FieldMap *fieldMap);
GameEvent *FLDEFF_RIPPLE_CreateSpecialLocationWarpTask(GameSystem *gameSystem, FieldMap *fieldMap, u32 useSpin);
int SCRCMD_GetBirthdayMessageIds(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_ShowPokeIconWindow(ScriptVm *vm, ScrcmdWork *cmdWork);
void SCRCMD_POKE_ICON_InitWindow(PokeIconWork *work);
void SCRCMD_POKE_ICON_ShowWindow(PokeIconWork *work);
void SCRCMD_POKE_ICON_CreateIcon(PokeIconWork *work, int species, int form, int isEgg, int gender, int charFlags);
int SCRCMD_POKE_ICON_DeleteIcon(PokeIconWork *work);
u32 SCRCMD_POKE_ICON_Task(GameEvent *event, u32 *state, PokeIconWork *work);
u32 SCRCMD_CheckBeaconTrainerKey(ScriptVm *vm, ScrcmdWork *cmdWork);
int FIELD_CheckPlayerPositionFree(GameSystem *gameSystem);
GameEvent *FIELD_SUBSCREEN_CreateAnimTask(GameSystem *gameSystem);
u32 FIELD_SUBSCREEN_AnimTask(GameEvent *event, u32 *state, SubscreenAnimWork *work);
int SCRCMD_ShowOrClearInfoWindow(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_AddTrainerRecordValue(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_GetTrainerRecordValue(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_GetNpcGreetingMessage(ScriptVm *vm, ScrcmdWork *cmdWork);
u32 SCRCMD_GREETING_AdjustMessageIdByMisc(GameData *gameData, int messageId);
u32 SCRCMD_GREETING_AdjustMessageIdByRandom(GameData *gameData, u32 messageId, int fixedMessage);
GameEvent *FIELD_CAMERA_CreateShakeTask(GameSystem *gameSystem, CameraShakeParams *params);
int FIELD_CAMERA_ShakeTask(GameEvent *event, int *state);
u32 SCRCMD_StartSwapNpcEvent(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_StartArcPlayerEffect(ScriptVm *vm, ScrcmdWork *cmdWork);
u32 SCRCMD_StartArcEffect(ScriptVm *vm, ScrcmdWork *cmdWork);
u32 SCRCMD_ShowArcModelAt(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_WaitArcEffectEnd(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_WaitArcEffectPeak(ScriptVm *vm, ScrcmdWork *cmdWork);
/* END mkheaders: generated region */

#endif
