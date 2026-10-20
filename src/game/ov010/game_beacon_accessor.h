#ifndef GAME_OV010_GAME_BEACON_ACCESSOR_H
#define GAME_OV010_GAME_BEACON_ACCESSOR_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of game_beacon_accessor.c, prototypes copied from their definitions. */

struct Strbuf;
struct WordSet;

#include "../ov010/game_beacon_search_shared_types.h"
#include "../arm9/game_beacon_types.h"
#include "../types.h"

int GAME_BEACON_ACCESSOR_TableAddNewLogs(GameBeaconInfoTable *table);
int GAME_BEACON_ACCESSOR_TablePop(GameBeaconInfoTable *table, GameBeaconInfo *info, u16 *receiveTime);
void GAME_BEACON_ACCESSOR_TableMarkLogsNew(GameBeaconInfo *infoList);
int GAME_BEACON_ACCESSOR_TableAdd(GameBeaconInfoTable *table, const GameBeaconInfo *info, int receiveTime, int mode);
int GAME_BEACON_ACCESSOR_TableGetRingIndex(const GameBeaconInfoTable *table, int offset);
int GAME_BEACON_ACCESSOR_TableRingAdd(GameBeaconInfoTable *table, const GameBeaconInfo *info, u16 receiveTime, int *isNew);
int GAME_BEACON_ACCESSOR_TableRingGet(const GameBeaconInfoTable *table, GameBeaconInfo *info, u16 *receiveTime, int offset);
u8 GAME_BEACON_ACCESSOR_TableGetCount(const GameBeaconInfoTable *table);
GameBeaconInfo *GAME_BEACON_ACCESSOR_AllocInfo(u32 heapId);
GameBeaconInfoTable *GAME_BEACON_ACCESSOR_AllocTable(u32 heapId);
int GAME_BEACON_ACCESSOR_IsInfoInvalid(const GameBeaconInfo *info);
int GAME_BEACON_ACCESSOR_IsDistributionAction(const GameBeaconInfo *info);
void GAME_BEACON_ACCESSOR_GetPlayerName(const GameBeaconInfo *info, struct Strbuf *name);
u32 GAME_BEACON_ACCESSOR_GetPmVersion(const GameBeaconInfo *info);
u32 GAME_BEACON_ACCESSOR_GetLanguage(const GameBeaconInfo *info);
u8 GAME_BEACON_ACCESSOR_GetNation(const GameBeaconInfo *info);
u8 GAME_BEACON_ACCESSOR_GetArea(const GameBeaconInfo *info);
u8 GAME_BEACON_ACCESSOR_GetQuestionnaireAnswerSecond(const GameBeaconInfo *info);
u8 GAME_BEACON_ACCESSOR_GetQuestionnaireAnswerFirst(const GameBeaconInfo *info);
void GAME_BEACON_ACCESSOR_GetDetailsPms(const GameBeaconInfo *info, GameBeaconPms *pms);
u8 GAME_BEACON_ACCESSOR_GetResearchTeamRank(const GameBeaconInfo *info);
void GAME_BEACON_ACCESSOR_GetFavoriteColorRgb(u16 *rgb, const GameBeaconInfo *info);
u8 GAME_BEACON_ACCESSOR_GetFavoriteColorIndex(const GameBeaconInfo *info);
u16 GAME_BEACON_ACCESSOR_GetTrainerId(const GameBeaconInfo *info);
u8 GAME_BEACON_ACCESSOR_GetTrainerAppearance(const GameBeaconInfo *info);
u8 GAME_BEACON_ACCESSOR_GetSex(const GameBeaconInfo *info);
void GAME_BEACON_ACCESSOR_GetPlayTime(const GameBeaconInfo *info, u16 *hours, u16 *minutes);
u8 GAME_BEACON_ACCESSOR_GetInfoVersion(const GameBeaconInfo *info);
u16 GAME_BEACON_ACCESSOR_GetZoneId(const GameBeaconInfo *info);
u16 GAME_BEACON_ACCESSOR_GetTownmapRootZoneId(const GameBeaconInfo *info);
u32 GAME_BEACON_ACCESSOR_GetPassCount(const GameBeaconInfo *info);
u32 GAME_BEACON_ACCESSOR_GetThanksCount(const GameBeaconInfo *info);
void GAME_BEACON_ACCESSOR_GetGreeting(const GameBeaconInfo *info, struct Strbuf *greeting);
void GAME_BEACON_ACCESSOR_GetThanksName(const GameBeaconInfo *info, struct Strbuf *name);
void GAME_BEACON_ACCESSOR_GetFreeText(const GameBeaconInfo *info, struct Strbuf *text);
unsigned GAME_BEACON_ACCESSOR_GetDetailsType(const GameBeaconInfo *info);
u16 GAME_BEACON_ACCESSOR_GetDetailsTrainerNo(const GameBeaconInfo *info);
u16 GAME_BEACON_ACCESSOR_GetDetailsMonsNo(const GameBeaconInfo *info);
u16 GAME_BEACON_ACCESSOR_GetActionNo(const GameBeaconInfo *info);
u16 GAME_BEACON_ACCESSOR_GetActionMonsNo(const GameBeaconInfo *info);
u16 GAME_BEACON_ACCESSOR_GetActionItemNo(const GameBeaconInfo *info);
u16 GAME_BEACON_ACCESSOR_GetActionCountValue(const GameBeaconInfo *info);
u16 GAME_BEACON_ACCESSOR_GetDistributionMonsNo(const GameBeaconInfo *info);
u16 GAME_BEACON_ACCESSOR_GetDistributionItemNo(const GameBeaconInfo *info);
u16 GAME_BEACON_ACCESSOR_GetDistributionSerial(const GameBeaconInfo *info);
void GAME_BEACON_ACCESSOR_GetNickname(const GameBeaconInfo *info, struct Strbuf *nickname);
u16 GAME_BEACON_ACCESSOR_GetActionTrainerNo(const GameBeaconInfo *info);
u32 GAME_BEACON_ACCESSOR_GetPresetEventValue(const GameBeaconInfo *info);
u16 GAME_BEACON_ACCESSOR_GetActionSpecialValue(const GameBeaconInfo *info);
u32 GAME_BEACON_ACCESSOR_GetActionWordValue(const GameBeaconInfo *info);
u8 GAME_BEACON_ACCESSOR_GetActionByteValue(const GameBeaconInfo *info);
u16 GAME_BEACON_ACCESSOR_GetActionHalfwordValue(const GameBeaconInfo *info);
u8 GAME_BEACON_ACCESSOR_GetActionCheckIndex(u16 action);
u8 GAME_BEACON_ACCESSOR_GetActionViewVariant(u32 actionType);
void GAME_BEACON_ACCESSOR_RegisterRecordWords(GameBeaconInfo *info, struct WordSet *wordSet, u32 heapId);
int GAME_BEACON_ACCESSOR_IsNoArgInvalid(GameBeaconInfo *info);
int GAME_BEACON_ACCESSOR_IsActionTrainerNoInvalid(GameBeaconInfo *info);
int GAME_BEACON_ACCESSOR_IsActionMonsNoInvalid(GameBeaconInfo *info);
int GAME_BEACON_ACCESSOR_IsNoValueInvalid(GameBeaconInfo *info);
int GAME_BEACON_ACCESSOR_IsActionMonsNoWithNicknameInvalid(GameBeaconInfo *info);
int GAME_BEACON_ACCESSOR_IsActionItemNoInvalid(GameBeaconInfo *info);
int GAME_BEACON_ACCESSOR_IsPlayTimeInvalid(GameBeaconInfo *info);
int GAME_BEACON_ACCESSOR_IsActionCountValueInvalid(GameBeaconInfo *info);
int GAME_BEACON_ACCESSOR_IsDistributionMonsNoInvalid(GameBeaconInfo *info);
int GAME_BEACON_ACCESSOR_IsDistributionItemNoInvalid(GameBeaconInfo *info);
int GAME_BEACON_ACCESSOR_IsActionMoveNoInvalid(GameBeaconInfo *info);
int GAME_BEACON_ACCESSOR_IsActionPresetEventInvalid(GameBeaconInfo *info);
int GAME_BEACON_ACCESSOR_IsActionByteValueInvalid(GameBeaconInfo *info);
int GAME_BEACON_ACCESSOR_IsActionHalfwordValueInvalid(GameBeaconInfo *info);
int GAME_BEACON_ACCESSOR_IsDistributionSerialInvalid(GameBeaconInfo *info);
/* END mkheaders: generated region */

#endif
