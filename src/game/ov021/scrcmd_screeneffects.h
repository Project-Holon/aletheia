#ifndef GAME_OV021_SCRCMD_SCREENEFFECTS_H
#define GAME_OV021_SCRCMD_SCREENEFFECTS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of scrcmd_screeneffects.c, prototypes copied from their definitions. */

struct ScriptVm;
struct ScrcmdWork;
struct BuildModelMgr;
struct BuildModelEntry;
struct GameSystem;
struct FieldMap;
struct TcbTask;
struct FadeEffectTask;
typedef struct FadeEffectTask FadeEffectTask;

#include "../types.h"

int SCRCMD_SCREENEFFECTS_StartBrightnessChange(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_CheckBrightnessDone(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_CheckScriptEffectDone(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_StartFieldFadeIn(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_FadeInSlow(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_FadeInSlowAgain(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_FadeOutSlow(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_FadeInSlowAltScreens(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_FadeOutSlowAltScreens(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_FadeInFast(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_FadeOutFast(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_FadeInFastAltScreens(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_FadeOutFastAltScreens(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_WaitBrightness(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_WaitScriptEffect(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_StartRecoveryPartyEvent(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_StartRecoveryBallsEvent(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_StartDoorOpen(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_StartDoorSetOpen(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_StartDoorClose(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
struct BuildModelMgr *SCRCMD_SCREENEFFECTS_GetBuildModelMgr(struct ScrcmdWork *cmdWork);
struct BuildModelEntry *SCRCMD_SCREENEFFECTS_FindBuildModelEntry(struct BuildModelMgr *mgr, int modelId, int x, int z);
int SCRCMD_SCREENEFFECTS_PlayBuildModelAnimPair(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_PlayBuildModelAnimTwo(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_SwapBuildModelId(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_SetBuildModelIndex(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_CreateBuildModelNode(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_DeleteBuildModelNode(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_PlayBuildModelNodeSlotWithSe(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_PlayBuildModelNodeSlotMode2(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_PlayBuildModelNodeCurrentMode3(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_WaitBuildModelNodeAnim(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_CheckBuildModelNodeAnimDone(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
void SCRCMD_SCREENEFFECTS_CreateFadeTask(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u32 kind, u32 screenSelect, u32 skipWait);
void SCRCMD_SCREENEFFECTS_StepFadeTask(struct TcbTask *tcb, void *arg);
int SCRCMD_SCREENEFFECTS_ShowPlaceName(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
/* END mkheaders: generated region */

#endif
