#ifndef GAME_OV010_SCRCMD_MUSICAL_H
#define GAME_OV010_SCRCMD_MUSICAL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of scrcmd_musical.c, prototypes copied from their definitions. */

struct ScrcmdWork;
struct ScriptWork;
struct GameData;
struct GameSystem;
struct GameComm;
struct GameEvent;

#include "../arm9/script_vm_types.h"
#include "../ov010/musical_event.h"
#include "../types.h"

int SCRCMD_MUSICAL_StartMusical(ScriptVm *vm, struct ScrcmdWork *scriptWork);
int SCRCMD_MUSICAL_ShowPartyMonMusical(ScriptVm *vm, struct ScrcmdWork *scriptWork);
int SCRCMD_MUSICAL_GetValue(ScriptVm *vm, struct ScrcmdWork *scriptWork);
int SCRCMD_MUSICAL_GetProgramInfo(ScriptVm *vm, struct ScrcmdWork *scriptWork);
int SCRCMD_MUSICAL_AddOwnedProp(ScriptVm *vm, struct ScrcmdWork *scriptWork);
int SCRCMD_MUSICAL_BufferString(ScriptVm *vm, struct ScrcmdWork *scriptWork);
int SCRCMD_MUSICAL_ResetProgramRank(ScriptVm *vm, struct ScrcmdWork *scriptWork);
int SCRCMD_MUSICAL_SelectPartyMon(ScriptVm *vm, struct ScrcmdWork *scriptWork);
int SCRCMD_MUSICAL_LinkControl(ScriptVm *vm, struct ScrcmdWork *scriptWork);
void SCRCMD_MUSICAL_CreateLinkWork(struct ScriptWork *unused, struct GameData *gameData);
void SCRCMD_MUSICAL_DeleteLinkWork(MusicalLink *link, struct GameData *gameData);
void SCRCMD_MUSICAL_BeginCommSession(void *link, struct GameSystem *gameSys, struct GameComm *gameComm, int arg);
void SCRCMD_MUSICAL_CloseCommSession(MusicalLink *link);
int SCRCMD_MUSICAL_TaskStartMusical(struct GameEvent *task, int *state, void *work);
int SCRCMD_MUSICAL_TaskShowMusicalProc(struct GameEvent *task, int *state, void *work);
void SCRCMD_MUSICAL_FreeProcArgs(void *callbackArg);
void SCRCMD_MUSICAL_LinkProcCallback(void *callbackArg);
int SCRCMD_MUSICAL_WaitEntryMenuParent(ScriptVm *vm, void *scriptWork);
int SCRCMD_MUSICAL_WaitEntryMenuChild(ScriptVm *vm, void *scriptWork);
int SCRCMD_MUSICAL_WaitSetMemberCount(ScriptVm *vm, void *scriptWork);
int SCRCMD_MUSICAL_WaitSessionReady(ScriptVm *vm, void *scriptWork);
int SCRCMD_MUSICAL_WaitCommAttach(ScriptVm *vm, void *scriptWork);
int SCRCMD_MUSICAL_WaitCommIdle(ScriptVm *vm, void *scriptWork);
int SCRCMD_MUSICAL_WaitSessionFinish(ScriptVm *vm, void *scriptWork);
int SCRCMD_MUSICAL_WifiListCommand(ScriptVm *vm, struct ScrcmdWork *scriptWork);
/* END mkheaders: generated region */

#endif
