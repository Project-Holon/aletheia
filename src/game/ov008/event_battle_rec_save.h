#ifndef GAME_OV008_EVENT_BATTLE_REC_SAVE_H
#define GAME_OV008_EVENT_BATTLE_REC_SAVE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of event_battle_rec_save.c, prototypes copied from their definitions. */

struct BattleSetupParam;
struct BattleSlotTable;
struct BattleRecSaveArgs;
struct BattleRecSaveEventWork;
struct EventBattleRecSaveProc;
struct GameSystem;
typedef struct BattleSlotTable BattleSlotTable;
typedef struct BattleRecSaveArgs BattleRecSaveArgs;
typedef struct BattleRecSaveEventWork BattleRecSaveEventWork;
typedef struct EventBattleRecSaveProc EventBattleRecSaveProc;

int EVENT_BATTLE_REC_SAVE_ProcInit(void *procsysOwner);
int EVENT_BATTLE_REC_SAVE_ProcExit(void *procWork, int unused, char *taskWork, EventBattleRecSaveProc *proc);
struct GameEvent *EVENT_BATTLE_REC_SAVE_Start(struct GameSystem *gameSystem, void *argsArg);
void *EVENT_BATTLE_REC_SAVE_CreateEvent(struct GameSystem *gameSystem, struct BattleSetupParam *info, BattleSlotTable *slots, int flag);
int EVENT_BATTLE_REC_SAVE_EventMain(struct GameEvent *unused, int *stage, void *work);
/* END mkheaders: generated region */

#endif
