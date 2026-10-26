#ifndef GAME_OV010_SCRCMD_MMDL_H
#define GAME_OV010_SCRCMD_MMDL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of scrcmd_mmdl.c, prototypes copied from their definitions. */

struct ScrcmdWork;
struct GameEvent;
typedef struct ScrcmdWork ScrcmdWork;

#include "../arm9/script_vm_types.h"
#include "../types.h"

int SCRCMD_MMDL_StartRise(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MMDL_RiseEventMain(struct GameEvent *event, int *state, void *work);
int SCRCMD_MMDL_StartOrbit(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MMDL_OrbitEventMain(struct GameEvent *event, int *mode, void *work);
/* END mkheaders: generated region */

#endif
