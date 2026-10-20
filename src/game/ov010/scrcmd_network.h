#ifndef GAME_OV010_SCRCMD_NETWORK_H
#define GAME_OV010_SCRCMD_NETWORK_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of scrcmd_network.c, prototypes copied from their definitions. */

struct ScrcmdWork;
struct GameSystem;
struct NpcTableRow;
struct GameData;
struct GameEvent;
typedef struct NpcTableRow NpcTableRow;

#include "../arm9/script_vm_types.h"
#include "../types.h"

int SCRCMD_NETWORK_WaitCommState(ScriptVm *vm, void *scriptWork);
int SCRCMD_NETWORK_CmdWaitCommState(ScriptVm *vm, struct ScrcmdWork *scriptWork);
int SCRCMD_NETWORK_CmdGetCommValue(ScriptVm *vm, struct ScrcmdWork *scriptWork);
int SCRCMD_NETWORK_CmdStartAutoComm(ScriptVm *vm, struct ScrcmdWork *scriptWork);
int SCRCMD_NETWORK_CmdRequestCommExit(ScriptVm *vm, struct ScrcmdWork *scriptWork);
int SCRCMD_NETWORK_CmdRestartAutoComm(ScriptVm *vm, struct ScrcmdWork *scriptWork);
int SCRCMD_NETWORK_CmdUnblockComm(struct GameSystem **gameSystemRef, void *unused);
int SCRCMD_NETWORK_CmdGetAlwaysNet(ScriptVm *vm, struct ScrcmdWork *scriptWork);
int SCRCMD_NETWORK_CmdClearAlwaysNet(ScriptVm *vm, struct ScrcmdWork *scriptWork);
int SCRCMD_NETWORK_CmdLoadNpcTable(ScriptVm *vm, struct ScrcmdWork *scriptWork);
int SCRCMD_NETWORK_CmdFreeNpcTable(ScriptVm *vm, struct ScrcmdWork *scriptWork);
int SCRCMD_NETWORK_CmdSetNpcEventFromTable(ScriptVm *vm, struct ScrcmdWork *scriptWork);
int SCRCMD_NETWORK_CmdSetNpcEventPairFromTable(ScriptVm *vm, struct ScrcmdWork *scriptWork);
int SCRCMD_NETWORK_CmdSetNpcTripleFromTable(ScriptVm *vm, struct ScrcmdWork *scriptWork);
int SCRCMD_NETWORK_CmdApplyTableEventKeys(ScriptVm *vm, struct ScrcmdWork *scriptWork);
int SCRCMD_NETWORK_PickSixDistinctRandom(ScriptVm *vm, struct ScrcmdWork *scriptWork);
int SCRCMD_NETWORK_FindNpcTableRow(const NpcTableRow *table, int keyA, int keyB);
Bool SCRCMD_NETWORK_HasSituationWarpChanged(struct GameData *gameData);
int SCRCMD_NETWORK_CommProcEventMain(struct GameEvent *event, u32 *seq, void *workArg);
struct GameEvent *SCRCMD_NETWORK_CreateCommProcEvent(struct GameSystem *gameSystem);
/* END mkheaders: generated region */

#endif
