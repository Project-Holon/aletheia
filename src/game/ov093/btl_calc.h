#ifndef GAME_OV093_BTL_CALC_H
#define GAME_OV093_BTL_CALC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of btl_calc.c, prototypes copied from their definitions. */

struct BtlPokeParam;
union SickCont;
struct BattleSetupParam;
struct BattleTrainerData;
struct Party;
struct BtlParty;
struct BtlClientSet;

#include "../ov093/btl_calc_types.h"
#include "../types.h"
#include "../ov093/btl_pokeparam_types.h"

void BTL_CALC_Init(BtlRngState *rng, unsigned int heapId);
void BTL_CALC_SetRngState(const BtlRngState *rng);
void BTL_CALC_Exit(void);
u32 BTL_CALC_Random(u32 range);
unsigned short BTL_CALC_ApplyStatStage(unsigned short stat, int stage);
u8 BTL_CALC_ApplyAccuracyStage(int accuracy, int stage);
int BTL_CALC_RollCriticalHit(int critStage);
int BTL_CALC_GetTypeAffinity(int atkType, int defType);
int BTL_CALC_GetTypeAffinityVsPair(int atkType, int defTypes);
int BTL_CALC_CombineTypeAffinity(int affinityA, int affinityB);
u32 BTL_CALC_CalcBaseDamage(u32 power, u32 attack, u32 level, u32 defense);
u32 BTL_CALC_ApplyTypeAffinity(u32 damage, u32 affinity);
u8 BTL_CALC_ListResistingTypes(int atkType, u8 *outTypes);
int BTL_CALC_SummarizeTypeAffinity(int affinity);
int BTL_CALC_RollPercent(u32 percent);
int BTL_CALC_Max(int value, int floor);
u32 BTL_CALC_MulRatio(u32 value, u32 ratio);
u32 BTL_CALC_MulRatioMin1(u32 value, u32 ratio);
u32 BTL_CALC_MulPercent(u32 value, u32 percent);
u32 BTL_CALC_DivideMaxHp(struct BtlPokeParam *bpp, u32 divisor);
int BTL_CALC_DivideMaxHpMin1(struct BtlPokeParam *bpp, u32 divisor);
u32 BTL_CALC_RandRange(u32 min, u32 max);
int BTL_CALC_RollHitCount(int maxHits);
int BTL_CALC_GetWeatherDamage(struct BtlPokeParam *bpp, int weather);
u32 BTL_CALC_GetWeatherMoveRatio(int weather, int moveType);
void BTL_CALC_MakeSickContFromSpec(struct BtlSickContSpec spec, struct BtlPokeParam *attacker, union SickCont *out);
union SickCont BTL_CALC_MakeDefaultSickCont(int kind);
int BTL_CALC_HasDefaultSickCont(int kind);
union SickCont BTL_CALC_MakeSickContTurns(u32 turns);
union SickCont BTL_CALC_MakeSickContPoke(u32 pokeId);
void BTL_CALC_MakeSickContFromKind(int kind, struct BtlPokeParam *attacker, union SickCont *out);
int BTL_CALC_FindMajorSick(struct BtlPokeParam *bpp);
u16 BTL_CALC_PickRandomMoveExcluding(const u16 *excludedMoves, int excludedCount);
int BTL_CALC_ContainsU16(const u16 *list,u32 count,u32 value);
u32 BTL_CALC_CalcDefeatExp(struct BtlPokeParam *bpp);
u32 BTL_CALC_IsMultiFighterRule(u32 rule);
u32 BTL_CALC_GetFightersPerSide(u32 rule);
u8 BTL_CALC_GetScanStartIndex(u32 rule, u8 startIndex);
int BTL_CALC_IsGymLeaderTrainer(u32 trainerId);
int BTL_CALC_IsEliteFourTrainer(u32 trainerId);
int BTL_CALC_IsBossTrainer(u32 trainerId);
u32 BTL_CALC_CalcPrizeMoney(struct BattleSetupParam *setup);
u32 BTL_CALC_CalcTrainerPrizeMoney(struct BattleTrainerData *trainer,struct Party *party);
u32 BTL_CALC_CalcDefeatMoneyLoss(u32 badgeCount, struct BtlParty *party);
void BTL_CALC_SetHeapId(u32 heapId);
void BTL_CALC_NoOp(void);
u32 BTL_CALC_GetItemParam(u32 itemId,u32 paramId);
u32 BTL_CALC_PackPokeIds(const u8 *pokeIds);
void BTL_CALC_UnpackPokeIds(u32 packed,u8 *pokeIds);
int BTL_CALC_GetCurseTargetKind(struct BtlPokeParam *bpp);
int BTL_CALC_DecideMoveTarget(void *main, void *posTable, struct BtlPokeParam *attacker, u16 moveId);
int BTL_CALC_PeekMoveTarget(void *main, void *posTable, struct BtlPokeParam *attacker, u16 moveId, BtlRngState *savedRng);
void BTL_CLIENT_SET_Clear(struct BtlClientSet *set);
void BTL_CLIENT_SET_Add(struct BtlClientSet *set, int clientId);
u32 BTL_CLIENT_SET_GetCount(struct BtlClientSet *set);
int BTL_CLIENT_SET_JudgeResult(struct BtlClientSet *set, u8 localClientId, u32 rule);
/* END mkheaders: generated region */

#endif
