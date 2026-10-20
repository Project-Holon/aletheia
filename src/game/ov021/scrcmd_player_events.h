#ifndef GAME_OV021_SCRCMD_PLAYER_EVENTS_H
#define GAME_OV021_SCRCMD_PLAYER_EVENTS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of scrcmd_player_events.c, prototypes copied from their definitions. */

#include "../types.h"

int SCRCMD_PLAYER_GRID_EVENT_WaitHop(void *vm, void *scriptWork);
u32 SCRCMD_PLAYER_GRID_EVENT_StartHop(u32 vm, void *scriptWork);
int SCRCMD_PLAYER_GRID_EVENT_WaitJump(void *vm, void *scriptWork);
u32 SCRCMD_PLAYER_GRID_EVENT_StartJump(u32 vm, void *scriptWork);
int SCRCMD_IAIGIRI_StartOnPlayer(void *vm, void *scriptWork);
int SCRCMD_SAVEANIME_Start(void *vm, void *scriptWork);
u32 RAIL_SLIPDOWN_StartAtPlayer(u32 a, u32 b, u32 c);
void *RAIL_SLIPDOWN_Start(void *a, u32 b, u32 c);
int RAIL_SLIPDOWN_UpdateTask(void *task);
/* END mkheaders: generated region */

#endif
