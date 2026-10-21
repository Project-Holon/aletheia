#ifndef GAME_OV021_PLEASURE_BOAT_H
#define GAME_OV021_PLEASURE_BOAT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of pleasure_boat.c, prototypes copied from their definitions. */

struct ScrcmdWork;
typedef struct ScrcmdWork ScrcmdWork;

#include "../ov021/pleasure_boat_types.h"
#include "../ov020/event_mapchange_types.h"
#include "../ov020/event_mapchange_types.h"
#include "../types.h"
#include "../arm9/script_vm_types.h"

PleasureBoatWork *PLEASURE_BOAT_Create(void);
void PLEASURE_BOAT_AckEvent(PleasureBoatWork *work);
GameEvent *PLEASURE_BOAT_Update(GameSystem *gameSystem, PleasureBoatWork *work);
void PLEASURE_BOAT_AdvanceTime(PleasureBoatWork *work, int seconds, int clamp);
int PLEASURE_BOAT_GetStat(PleasureBoatWork *work, int kind);
u32 PLEASURE_BOAT_GetPassengerParam(PleasureBoatWork *work, u32 index);
u32 PLEASURE_BOAT_GetPassengerType(PleasureBoatWork *work, u32 index);
u32 PLEASURE_BOAT_GetPassengerExtra(PleasureBoatWork *work, u32 index, u32 wordIndex);
u32 PLEASURE_BOAT_GetPassengerOccupied(PleasureBoatWork *work, u32 index);
void PLEASURE_BOAT_SetPassengerOccupied(PleasureBoatWork *work, int index, int occupied);
int PLEASURE_BOAT_GetTimeEvent(PleasureBoatWork *work);
PleasureBoatWork *PLEASURE_BOAT_Lock(PleasureBoatWork *work);
int PLEASURE_BOAT_ScrCmdCreate(ScriptVm *vm, ScrcmdWork *scrCmdWork);
int PLEASURE_BOAT_ScrCmdDelete(ScriptVm *vm, ScrcmdWork *scrCmdWork);
int PLEASURE_BOAT_ScrCmdGetStat(ScriptVm *vm, ScrcmdWork *scrCmdWork);
int PLEASURE_BOAT_ScrCmdAddTime(ScriptVm *vm, ScrcmdWork *scrCmdWork);
int PLEASURE_BOAT_ScrCmdSetPassengerInfo(ScriptVm *vm, ScrcmdWork *scrCmdWork);
int PLEASURE_BOAT_ScrCmdLock(ScriptVm *vm, ScrcmdWork *scrCmdWork);
/* END mkheaders: generated region */

#endif
