#ifndef GAME_OV010_SCRCMD_EVENT_MON_H
#define GAME_OV010_SCRCMD_EVENT_MON_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of scrcmd_event_mon.c, prototypes copied from their definitions. */

struct ScriptVm;
struct ScrcmdWork;

#include "../types.h"

int SCRCMD_EVENT_MON_CmdStartSpPokeGimmickTask(struct ScriptVm *ctx, struct ScrcmdWork *scrWork);
int SCRCMD_EVENT_MON_CmdMoveSpPokeGimmick(struct ScriptVm *ctx, struct ScrcmdWork *scrWork);
int SCRCMD_EVENT_MON_CmdStartSpPokeGimmickStepA(struct ScriptVm *ctx, struct ScrcmdWork *scrWork);
int SCRCMD_EVENT_MON_CmdStartSpPokeGimmickStepB(struct ScriptVm *ctx, struct ScrcmdWork *scrWork);
int SCRCMD_EVENT_MON_CmdFindEventMonInParty(struct ScriptVm *ctx, struct ScrcmdWork *scrWork);
int SCRCMD_EVENT_MON_FindEventMonInParty(void *party, int species, int move, int kind, u16 *outIndex);
int SCRCMD_EVENT_MON_CmdClearEventMonFlag(struct ScriptVm *ctx, struct ScrcmdWork *scrWork);
/* END mkheaders: generated region */

#endif
