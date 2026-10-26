#ifndef GAME_OV021_SCRCMD_ENCOUNT_H
#define GAME_OV021_SCRCMD_ENCOUNT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of scrcmd_encount.c, prototypes copied from their definitions. */

struct ScriptVm;
struct ScrcmdWork;

int SCRCMD_PROC_FLD_StoreRandomUniqueEntry(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
void SCRCMD_PROC_FLD_RestoreCamera(void *fieldMap, void *fieldRegion);
int SCRCMD_PROC_FLD_RestoreCameraTask(void **eventWork);
int SCRCMD_PROC_FLD_SaveCamera(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_RestoreCameraCmd(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_StopCameraTargetTrace(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_ResumeCameraTargetTrace(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_StartCameraMoveFromStream(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_StartCameraMoveFromArchive(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_StartCameraMoveToSaved(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_StartCameraMoveToSetting(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_WaitCameraIdle(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_StartCameraShake(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_PollCameraSaveReady(void *event);
int SCRCMD_PROC_FLD_PollCameraIdle(struct GameEvent *event, int *seq, void *work);
int SCRCMD_PROC_FLD_CallOv056Event(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_SetCameraSettingFromFkDemoSlot(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_StartFkDemoSubProc(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
/* END mkheaders: generated region */

#endif
