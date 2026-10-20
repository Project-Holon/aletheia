#ifndef GAME_OV010_EVENT_BATTLE_H
#define GAME_OV010_EVENT_BATTLE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of event_battle.c, prototypes copied from their definitions. */

struct ScriptedBattleArgs;
struct BattleTask;
struct BattleEndCtx;
typedef struct ScriptedBattleArgs ScriptedBattleArgs;
typedef struct BattleTask BattleTask;
typedef struct BattleEndCtx BattleEndCtx;

#include "../types.h"

int EVENT_BATTLE_CallAndInvert(void (*fn)(void));
int EVENT_BATTLE_ProcScriptedBattle(void *event, u32 *state, ScriptedBattleArgs *args);
int EVENT_BATTLE_CreateScriptedBattle(int gameSystem, int battleSrc, int btlSetup, int returnImmediately, int effectId);
int EVENT_BATTLE_CreateEncounterTask(int gameSystem, int battleSrc, int battleMode, int battleFlags, int battleKind, int fieldEffect, int options);
struct GameEvent *EVENT_BATTLE_CreateResultOnlyTask(int gameSystem, int battleSrc, int btlSetup);
int EVENT_BATTLE_CreateForcedWinTask(void *gameSystem, void *battleSrc, void *btlSetup);
void *EVENT_BATTLE_CreateCatchTutorial(void *gameSystem, void *fieldMap, u16 heapId);
void *EVENT_BATTLE_CreateEncounterTaskWithMon(void *gameSystem, u32 battleSrc, u32 battleMode, u32 battleFlags, u32 battleKind, u32 fieldEffect, u32 options, u32 entryIndex);
int EVENT_BATTLE_ProcBattleTask(void *event, u32 *state, BattleTask *work);
int EVENT_BATTLE_GetBattleKindClass(void *battleKind);
void EVENT_BATTLE_DispatchBattleKindNotify(u16 id, int col);
void EVENT_BATTLE_NotifyLeadSpecies(void *btlSetup, int which);
void EVENT_BATTLE_NotifyBattleEnd(BattleEndCtx *ctx);
int EVENT_BATTLE_AddBattleRecord(BattleTask *task);
int EVENT_BATTLE_IsResultSilent(int outcome, int mode);
u8 EVENT_BATTLE_GetResultFlag(int kindId);
int EVENT_BATTLE_IsTaskResultSilent(BattleTask *task);
void EVENT_BATTLE_FinishBattleTask(BattleTask *task, void *gameSystem);
void EVENT_BATTLE_InitTaskWork(BattleTask *task, void *gameSystem, void *btlSetup);
void EVENT_BATTLE_FreeBtlSetup(BattleTask *task);
int EVENT_BATTLE_IntegrityProbeA(int unused);
int EVENT_BATTLE_IntegrityProbeB(int unused);
int EVENT_BATTLE_IntegrityDecoyC(int unused);
/* END mkheaders: generated region */

#endif
