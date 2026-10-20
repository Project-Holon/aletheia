#ifndef GAME_OV021_SCRCMD_FLD_BATTLE_H
#define GAME_OV021_SCRCMD_FLD_BATTLE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of scrcmd_fld_battle.c, prototypes copied from their definitions. */

struct ScriptVm;
struct ScrcmdWork;
struct FieldTask;
struct PartyCheckTaskWork;
typedef struct PartyCheckTaskWork PartyCheckTaskWork;

#include "../types.h"

int SCRCMD_FLD_BATTLE_RegisterAllowedSpecies(struct ScriptVm *vm, struct ScrcmdWork *work);
int SCRCMD_FLD_BATTLE_CheckPartyRegulation(struct ScriptVm *vm, struct ScrcmdWork *work);
u16 SCRCMD_FLD_BATTLE_StoreAllowedSpeciesNames(void *gameData, void *wordSet, u32 regulationNo, int heapId);
u16 *SCRCMD_FLD_BATTLE_CreateAllowedSpeciesList(u8 *regulation, void *gameData, u16 *count, int heapId);
void *SCRCMD_FLD_BATTLE_CreatePartyCheckTask(void *gameSystem, int isSubwayRules, void *rules, u16 *result, u16 heapId);
int SCRCMD_FLD_BATTLE_PartyCheckTaskMain(struct FieldTask *fieldTask, int *state, PartyCheckTaskWork *taskWork);
/* END mkheaders: generated region */

#endif
