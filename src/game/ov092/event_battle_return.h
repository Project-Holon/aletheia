#ifndef GAME_OV092_EVENT_BATTLE_RETURN_H
#define GAME_OV092_EVENT_BATTLE_RETURN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of event_battle_return.c, prototypes copied from their definitions. */

struct ProcObj;
struct EventBattleReturnWork;
struct EventBattleReturnArgs;
struct PokeParty;
struct BattleField;
struct PokemonParam;

#include "../types.h"

int EVENT_BATTLE_RETURN_Init(struct ProcObj *proc);
int EVENT_BATTLE_RETURN_Exit(struct ProcObj *proc, u32 seq, u32 pwk, struct EventBattleReturnWork *work);
int EVENT_BATTLE_RETURN_Main(struct ProcObj *proc, u32 *seq, struct EventBattleReturnArgs *args, struct EventBattleReturnWork *work);
void EVENT_BATTLE_RETURN_FlagLeveledUpMembers(struct EventBattleReturnWork *work, struct EventBattleReturnArgs *args);
void EVENT_BATTLE_RETURN_ApplyPickupAndHoneyGather(struct PokeParty *party);
void EVENT_BATTLE_RETURN_ApplyNaturalCure(struct PokeParty *party);
void EVENT_BATTLE_RETURN_ApplyBurmyForms(struct EventBattleReturnArgs *args, struct PokeParty *party, int burmyForm);
u32 EVENT_BATTLE_RETURN_GetBurmyForm(const struct BattleField *field, u16 heapId);
void EVENT_BATTLE_RETURN_RegisterShayminForms(struct EventBattleReturnArgs *args, struct PokeParty *party);
void EVENT_BATTLE_RETURN_ApplyHealBall(struct PokemonParam *mon);
/* END mkheaders: generated region */

#endif
