#ifndef GAME_OV021_SCRCMD_PLAYER_EVENTS_H
#define GAME_OV021_SCRCMD_PLAYER_EVENTS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of scrcmd_player_events.c, prototypes copied from their definitions. */

struct ScriptVm;
struct GameEvent;
struct GameSystem;
struct FieldMap;
struct Mmdl;

#include "../types.h"

int SCRCMD_PLAYER_GRID_EVENT_WaitHop(struct ScriptVm *vm, void *scriptWork);
u32 SCRCMD_PLAYER_GRID_EVENT_StartHop(struct ScriptVm *vm, void *scriptWork);
int SCRCMD_PLAYER_GRID_EVENT_WaitJump(struct ScriptVm *vm, void *scriptWork);
u32 SCRCMD_PLAYER_GRID_EVENT_StartJump(struct ScriptVm *vm, void *scriptWork);
int SCRCMD_IAIGIRI_StartOnPlayer(void *vm, void *scriptWork);
int SCRCMD_SAVEANIME_Start(void *vm, void *scriptWork);
struct GameEvent *RAIL_SLIPDOWN_StartAtPlayer(struct GameSystem *a, struct FieldMap *b, u32 c);
void *RAIL_SLIPDOWN_Start(void *a, struct FieldMap *b, struct Mmdl *c);
int RAIL_SLIPDOWN_UpdateTask(struct GameEvent *task, int *seq, void *work);
/* END mkheaders: generated region */

#endif
