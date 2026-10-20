#ifndef GAME_ARM9_GAME_BEACON_H
#define GAME_ARM9_GAME_BEACON_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of game_beacon.c, prototypes copied from their definitions. */

struct GameData;
struct Strbuf;

#include "../types.h"
#include "../arm9/game_beacon_types.h"

void GAME_BEACON_Create(u32 heapId);
void GAME_BEACON_Update(void);
void GAME_BEACON_Setup(struct GameData *gameData);
void GAME_BEACON_GetMyInfo(GameBeaconInfo *dst);
void GAME_BEACON_SendIfRequested(void);
void GAME_BEACON_UpdateActionTime(GameBeaconRecord *own);
void GAME_BEACON_AddLog(GameBeaconWork *work, const GameBeaconInfo *info);
int GAME_BEACON_ReceiveInfo(const GameBeaconInfo *info);
GameBeaconRecord *GAME_BEACON_GetLogFromWork(GameBeaconWork *work, int index);
GameBeaconRecord *GAME_BEACON_GetLog(int index);
GameBeaconRecord *GAME_BEACON_GetLogByReceiveNoFromWork(GameBeaconWork *work, int receiveNo);
GameBeaconRecord *GAME_BEACON_GetLogByReceiveNo(int receiveNo);
u32 GAME_BEACON_GetReceiveCount(void);
int GAME_BEACON_GetNextNewLogIndex(int *cursor);
void GAME_BEACON_ClearNewFlag(u32 index);
int GAME_BEACON_SetNewFlagByTrainerId(const GameBeaconInfo *info);
u16 GAME_BEACON_GetReceivedFramesByTrainerId(u16 trainerId);
void GAME_BEACON_BuildMyInfo(GameBeaconInfo *info, struct GameData *gameData);
void GAME_BEACON_RequestSend(GameBeaconRecord *record);
u32 GAME_BEACON_CheckActionPriority(u32 action);
int GAME_BEACON_IsSpecialPokemon(u16 monsNo);
void GAME_BEACON_CopyStrbufCodes(const struct Strbuf *str, u16 *dest);
u8 GAME_BEACON_PopQuestionnaireUpdated(void);
void GAME_BEACON_SetQuestionnaire(const u8 *answers);
void GAME_BEACON_SetNationArea(u8 nation, u8 area);
void GAME_BEACON_SetResearchTeamRank(u32 rank);
void GAME_BEACON_SetPms(const GameBeaconPms *pms);
void GAME_BEACON_SetTrainerView(u32 trainerView);
void GAME_BEACON_UpdateGreeting(void);
void GAME_BEACON_SetPokeCapture(u16 monsNo);
void GAME_BEACON_SetPokeGet(u16 monsNo);
void GAME_BEACON_SetSpecialPokeGet(u16 monsNo);
void GAME_BEACON_SetPokeLevelUp(struct Strbuf *nickname);
void GAME_BEACON_SetPokeEvolution(u16 monsNo, struct Strbuf *nickname);
void GAME_BEACON_SetPlayTime(u32 playHours);
void GAME_BEACON_SetItemUse(u16 itemNo);
void GAME_BEACON_SetZone(u32 zoneId, u32 zoneSource);
void GAME_BEACON_SetInfoZone(GameBeaconInfo *info, u32 zoneId, u32 zoneSource);
void GAME_BEACON_SetDetailsBattleWildPoke(GameBeaconInfo *info, u16 monsNo);
void GAME_BEACON_SetDetailsBattleSpecialPoke(GameBeaconInfo *info, u16 monsNo);
void GAME_BEACON_SetDetailsBattleTrainer(GameBeaconInfo *info, u16 trainerId);
void GAME_BEACON_SetDetailsBattleLeader(GameBeaconInfo *info, u16 trainerId);
void GAME_BEACON_SetDetailsBattleBigFour(GameBeaconInfo *info, u16 trainerId);
void GAME_BEACON_ResetDetails(GameBeaconInfo *info);
void GAME_BEACON_WritePms(GameBeaconInfo *info, const GameBeaconPms *pms);
void GAME_BEACON_SetMyPms(const GameBeaconPms *pms);
void GAME_BEACON_RegisterClearCallback(void);
void GAME_BEACON_ClearFlags(void);
/* END mkheaders: generated region */

#endif
