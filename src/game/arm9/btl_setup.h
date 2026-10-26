#ifndef GAME_ARM9_BTL_SETUP_H
#define GAME_ARM9_BTL_SETUP_H

#include "../types.h"

struct BattleSetupParam *BTL_SETUP_Create(u32 heap);
struct BattleTrainerData *BTL_SETUP_CreateTrainerData(u16 heap);

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of btl_setup.c, prototypes copied from their definitions. */

struct BattleSetupParam;
struct GFLNetHandle;
struct Party;
struct Regulation;
struct FieldSituation;
struct BattleTrainerData;
struct GameData;

#include "../types.h"

struct BattleSetupParam *BTL_SETUP_Create(u32 heap);
void BTL_SETUP_Delete(struct BattleSetupParam *param);
void BTL_SETUP_Clear(struct BattleSetupParam *param);
void BTL_SETUP_FreeSlots(struct BattleSetupParam *param);
void BTL_SETUP_SetParty(struct BattleSetupParam *param, struct Party *src, int client);
void *BTL_SETUP_GetParty(struct BattleSetupParam *param, int client);
void BTL_SETUP_SetStatusFlag(struct BattleSetupParam *param, int flag);
int BTL_SETUP_CheckStatusFlag(struct BattleSetupParam *param, int mask);
void BTL_SETUP_ApplyRegulation(struct BattleSetupParam *param, struct Regulation *reg, u32 level);
void BTL_SETUP_InitCommFieldSituation(struct FieldSituation *sit);
void BTL_SETUP_InitFieldSituation(struct FieldSituation *sit);
struct BattleTrainerData *BTL_SETUP_CreateTrainerData(u16 heap);
void BTL_SETUP_DeleteTrainerData(struct BattleTrainerData *tr);
void BTL_SETUP_SetTrainer(struct BattleSetupParam *param, struct GameData *gd, u32 client, struct Party **party, u32 trainerId, u16 heap);
void BTL_SETUP_SetPlayerParty(struct BattleSetupParam *param, struct GameData *gd, u16 heap);
void BTL_SETUP_InitCommon(struct BattleSetupParam *param, struct GameData *gd, const struct FieldSituation *sit);
void BTL_SETUP_SetupWild(struct BattleSetupParam *param, struct GameData *gd, struct Party *wildParty, const struct FieldSituation *sit, u32 rule, u16 heap);
void BTL_SETUP_SetupTrainerBase(struct BattleSetupParam *param, struct GameData *gd, u32 rule, const struct FieldSituation *sit, u16 heap);
void BTL_SETUP_SetupComm(struct BattleSetupParam *param, struct GameData *gd, u32 rule, u8 multiMode, struct GFLNetHandle *netHandle, u8 commPos, u8 netId, u16 heap);
void BTL_SETUP_SetupDemo(struct BattleSetupParam *param, struct GameData *gd, struct Party *enemyParty, struct Party *partnerParty, const struct FieldSituation *sit, u16 heap);
void BTL_SETUP_SetupTrainerSingle(struct BattleSetupParam *param, struct GameData *gd, const struct FieldSituation *sit, u32 trainerId, u16 heap);
void BTL_SETUP_SetupTrainerDouble(struct BattleSetupParam *param, struct GameData *gd, const struct FieldSituation *sit, u32 trainerId, u16 heap);
void BTL_SETUP_SetupTrainerTriple(struct BattleSetupParam *param, struct GameData *gd, const struct FieldSituation *sit, u32 trainerId, u16 heap);
void BTL_SETUP_SetupTrainerRotation(struct BattleSetupParam *param, struct GameData *gd, const struct FieldSituation *sit, u32 trainerId, u16 heap);
void BTL_SETUP_SetupTrainerTag(struct BattleSetupParam *param, struct GameData *gd, const struct FieldSituation *sit, u32 trainerId1, u32 trainerId2, u16 heap);
void BTL_SETUP_SetupTrainerMulti(struct BattleSetupParam *param, struct GameData *gd, const struct FieldSituation *sit, u32 partnerId, u32 trainerId1, u32 trainerId2, u16 heap);
void BTL_SETUP_SetupCommSingle(struct BattleSetupParam *param, struct GameData *gd, struct GFLNetHandle *netHandle, u8 commPos, u16 heap);
void BTL_SETUP_SetupCommDouble(struct BattleSetupParam *param, struct GameData *gd, struct GFLNetHandle *netHandle, u8 commPos, u16 heap);
void BTL_SETUP_SetupCommMulti(struct BattleSetupParam *param, struct GameData *gd, struct GFLNetHandle *netHandle, u8 commPos, u8 netId, u16 heap);
void BTL_SETUP_SetupCommAiMulti(struct BattleSetupParam *param, struct GameData *gd, struct GFLNetHandle *netHandle, u8 commPos, u8 netId, u32 trainerId1, u32 trainerId2, u16 heap);
void BTL_SETUP_SetupCommTriple(struct BattleSetupParam *param, struct GameData *gd, struct GFLNetHandle *netHandle, u8 commPos, u16 heap);
void BTL_SETUP_SetupCommRotation(struct BattleSetupParam *param, struct GameData *gd, struct GFLNetHandle *netHandle, u8 commPos, u16 heap);
void BTL_SETUP_InitWithSlots(struct BattleSetupParam *param, struct GameData *gd, u16 heap);
void BTL_SETUP_ClearWithSlots(struct BattleSetupParam *param);
void BTL_SETUP_ChangeToSubway(struct BattleSetupParam *param);
void BTL_SETUP_AllocRecordBuffer(struct BattleSetupParam *param, u32 heap);
/* END mkheaders: generated region */

#endif
