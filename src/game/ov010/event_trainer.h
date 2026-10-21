#ifndef GAME_OV010_EVENT_TRAINER_H
#define GAME_OV010_EVENT_TRAINER_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of event_trainer.c, prototypes copied from their definitions. */

struct GameEvent;
struct RecordHead24;
typedef struct RecordHead24 RecordHead24;

#include "../types.h"

void EVENT_TRAINER_SetScriptTrainerEntry(struct GameEvent *scrcmdWork, int index, RecordHead24 *src);
u32 EVENT_TRAINER_GetTrainerIdFromScriptId(u32 ticks);
u16 EVENT_TRAINER_GetPrimaryScriptId(unsigned id);
u16 EVENT_TRAINER_GetSecondaryScriptId(unsigned id);
int EVENT_TRAINER_IsSecondaryScriptId(unsigned id);
int EVENT_TRAINER_IsDoubleBattle(int saveData);
int EVENT_TRAINER_GetBattleType(int saveData);
unsigned EVENT_TRAINER_CheckDefeatedFlag(void *flagSet, unsigned flagOffset);
void EVENT_TRAINER_SetDefeatedFlag(char *flagSet, unsigned flagOffset);
void EVENT_TRAINER_ClearDefeatedFlag(char *flagSet, unsigned flagOffset);
/* END mkheaders: generated region */

#endif
