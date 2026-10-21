#ifndef GAME_OV010_MOVE_POKEMON_H
#define GAME_OV010_MOVE_POKEMON_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of move_pokemon.c, prototypes copied from their definitions. */

struct MovePokemonSave;
struct GameData;
struct BattleResultWork;
struct MovePokemonEntry;
struct FieldMap;
struct GameEvent;
struct FieldSkillTarget;
struct FieldSkillContext;
struct FieldSkillCheck;
struct FieldSkillWork;
typedef struct BattleResultWork BattleResultWork;
typedef struct FieldSkillTarget FieldSkillTarget;
typedef struct FieldSkillContext FieldSkillContext;
typedef struct FieldSkillCheck FieldSkillCheck;
typedef struct FieldSkillWork FieldSkillWork;

#include "../types.h"
#include "../ov010/move_pokemon_types.h"
#include "../ov010/scrcmd_musical_shared_types.h"

void MOVE_POKEMON_MoveEntry(struct MovePokemonSave *block, u32 season, u16 slot);
void MOVE_POKEMON_MoveActiveEntries(struct GameData *gameData);
void MOVE_POKEMON_MoveActiveEntriesChecked(struct GameData *gameData);
u32 MOVE_POKEMON_GetEntryZoneId(struct MovePokemonSave *block, u32 slot);
int MOVE_POKEMON_HasActiveEntry(struct MovePokemonSave *block);
void MOVE_POKEMON_SetCommonArea(struct MovePokemonSave *block, int value);
void MOVE_POKEMON_SpawnEntry(struct GameData *gameData, u8 slot);
void MOVE_POKEMON_SpawnPendingEntries(struct GameData *gameData);
void MOVE_POKEMON_HandleBattleResult(struct GameData *gameData, BattleResultWork *work);
int MOVE_POKEMON_FindEntryByZone(struct GameData *gameData, int zoneId);
int MOVE_POKEMON_IsAnyEntryActive(struct GameData *gameData);
int MOVE_POKEMON_GetEntryIndexBySpecies(int species);
void MOVE_POKEMON_MoveToNeighbor(struct MovePokemonSave *block, u32 season, u16 slot, int excludedLocation);
void MOVE_POKEMON_SetEntryLocation(struct MovePokemonSave *block, u32 slot, u8 location, u32 zoneId);
struct MovePokemonEntry *MOVE_POKEMON_FindEntryBySpecies(struct MovePokemonSave *block, int species);
void MOVE_POKEMON_InitSkillInfo(struct FieldMap *fieldMap, FieldSkillInfo *out);
int MOVE_POKEMON_IsSkillBlocked(int skillIndex, FieldSkillInfo *info);
void MOVE_POKEMON_InitSkillTarget(SkillTarget *target, u16 id, u16 variant, u32 targetObj);
struct GameEvent *MOVE_POKEMON_CreateSkillEvent(int skillIndex, SkillTarget *target, FieldSkillInfo *info);
int MOVE_POKEMON_CheckCut(FieldSkillInfo *info);
struct GameEvent *MOVE_POKEMON_CreateCutEvent(SkillTarget *target, FieldSkillInfo *info);
int MOVE_POKEMON_CutEventMain(struct GameEvent *event, u32 *state, void *work);
int MOVE_POKEMON_CheckFly(FieldSkillInfo *info);
struct GameEvent *MOVE_POKEMON_CreateFlyEvent(SkillTarget *target, FieldSkillInfo *info);
int MOVE_POKEMON_FlyEventMain(struct GameEvent *event, u32 *state, void *work);
int MOVE_POKEMON_CheckSurf(FieldSkillInfo *info);
struct GameEvent *MOVE_POKEMON_CreateSurfEvent(SkillTarget *target, FieldSkillInfo *info);
int MOVE_POKEMON_SurfEventMain(struct GameEvent *event, u32 *state, void *work);
int MOVE_POKEMON_CheckStrength(FieldSkillInfo *info);
struct GameEvent *MOVE_POKEMON_CreateStrengthEvent(SkillTarget *target, FieldSkillInfo *info);
int MOVE_POKEMON_StrengthEventMain(struct GameEvent *event, u32 *state, void *work);
int MOVE_POKEMON_IsSkill8Unusable(FieldSkillInfo *info);
void *MOVE_POKEMON_CreateDiveEvent(SkillTarget *target, FieldSkillInfo *info);
int MOVE_POKEMON_StartSkillOnTarget(const FieldSkillTarget *target, const FieldSkillContext *ctx, int unused);
int MOVE_POKEMON_CheckWaterfall(const FieldSkillCheck *check);
int MOVE_POKEMON_CheckFlash(const FieldSkillCheck *check);
struct GameEvent *MOVE_POKEMON_CreateFlashEvent(const FieldSkillTarget *target, const FieldSkillContext *ctx);
int MOVE_POKEMON_FlashEventMain(struct GameEvent *event, int *seq, FieldSkillWork *work);
int MOVE_POKEMON_CheckDig(const FieldSkillCheck *check);
struct GameEvent *MOVE_POKEMON_CreateDigEvent(const FieldSkillTarget *target, const FieldSkillContext *ctx);
int MOVE_POKEMON_DigEventMain(struct GameEvent *event, int *seq, FieldSkillWork *work);
int MOVE_POKEMON_CheckTeleport(const FieldSkillCheck *check);
struct GameEvent *MOVE_POKEMON_CreateTeleportEvent(const FieldSkillTarget *target, const FieldSkillContext *ctx);
int MOVE_POKEMON_TeleportEventMain(struct GameEvent *event, int *seq, FieldSkillWork *work);
int MOVE_POKEMON_CheckMilkDrink(const FieldSkillCheck *check);
struct GameEvent *MOVE_POKEMON_CreateMilkDrinkEvent(const FieldSkillTarget *target, const FieldSkillContext *ctx);
int MOVE_POKEMON_MilkDrinkEventMain(struct GameEvent *event, int *seq, FieldSkillWork *work);
int MOVE_POKEMON_CheckSweetScent(const FieldSkillCheck *check);
void MOVE_POKEMON_StartSweetScent(const FieldSkillTarget *target, const FieldSkillContext *ctx);
int MOVE_POKEMON_SweetScentEventMain(struct GameEvent *event, int *seq, FieldSkillWork *work);
struct GameEvent *MOVE_POKEMON_CreateSweetScentEvent(const FieldSkillTarget *target, const FieldSkillContext *ctx);
int MOVE_POKEMON_SoftBoiledEventMain(struct GameEvent *event, int *seq, FieldSkillWork *work);
struct GameEvent *MOVE_POKEMON_CreateSoftBoiledEvent(const FieldSkillTarget *target, const FieldSkillContext *ctx);
SkillCheckFn MOVE_POKEMON_GetSkillCheckFunc(const FieldSkillCheck *check, int skill);
SkillEventFn MOVE_POKEMON_GetSkillEventFunc(const FieldSkillCheck *check, int skill);
void MOVE_POKEMON_InitSkillWork(FieldSkillWork *work, const FieldSkillTarget *target, const FieldSkillContext *ctx);
int MOVE_POKEMON_IsSkillUsable(const FieldSkillCheck *check, int skill);
/* END mkheaders: generated region */

#endif
