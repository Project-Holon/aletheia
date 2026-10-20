#ifndef GAME_OV188_BATTLE_REC_TOOL_H
#define GAME_OV188_BATTLE_REC_TOOL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of battle_rec_tool.c, prototypes copied from their definitions. */

struct PokemonParam;
struct BattleRecMon;
struct BattleSetupParam;
struct Party;
struct BattleRecParty;
struct BattleRecData;
struct BattleTrainerData;
struct BattleRecTrainer;

#include "../types.h"

void BATTLE_REC_TOOL_PackMon(struct PokemonParam *mon, struct BattleRecMon *rec);
void BATTLE_REC_TOOL_UnpackMon(struct BattleRecMon *rec, struct PokemonParam *mon);
void BATTLE_REC_TOOL_PackSetup(struct BattleSetupParam *setup);
void BATTLE_REC_TOOL_UnpackSetup(struct BattleSetupParam *setup, u32 heapId);
void BATTLE_REC_TOOL_PackParty(struct Party *party, struct BattleRecParty *rec);
void BATTLE_REC_TOOL_UnpackParty(struct BattleRecParty *rec, struct Party *party, u32 heapId);
void BATTLE_REC_TOOL_PackParties(struct BattleSetupParam *setup, struct BattleRecData *rec);
void BATTLE_REC_TOOL_UnpackParties(struct BattleSetupParam *setup, struct BattleRecData *rec, u32 heapId);
void BATTLE_REC_TOOL_PackPlayers(struct BattleSetupParam *setup, struct BattleRecData *rec);
void BATTLE_REC_TOOL_UnpackPlayers(struct BattleSetupParam *setup, struct BattleRecData *rec);
void BATTLE_REC_TOOL_PackPlayerProfile(struct BattleTrainerData *trainer, struct BattleRecTrainer *rec);
void BATTLE_REC_TOOL_UnpackPlayerProfile(struct BattleTrainerData *trainer, struct BattleRecTrainer *rec);
int BATTLE_REC_TOOL_PackInputLog(struct BattleSetupParam *setup, struct BattleRecData *rec);
int BATTLE_REC_TOOL_UnpackInputLog(struct BattleSetupParam *setup, struct BattleRecData *rec);
int BATTLE_REC_TOOL_PackBattleRules(struct BattleSetupParam *setup, struct BattleRecData *rec);
int BATTLE_REC_TOOL_UnpackBattleRules(struct BattleSetupParam *setup, const struct BattleRecData *rec);
/* END mkheaders: generated region */

#endif
