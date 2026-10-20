#ifndef GAME_OV010_GAME_BEACON_SET_H
#define GAME_OV010_GAME_BEACON_SET_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of game_beacon_set.c, prototypes copied from their definitions. */

struct Strbuf;
struct GameData;

#include "../types.h"
#include "../arm9/game_beacon_types.h"

void GAME_BEACON_SEARCH_SetBattlePokeStart(u32 monsNo);
void GAME_BEACON_SEARCH_SetBattlePokeWin(u32 monsNo);
void GAME_BEACON_SEARCH_SetBattleWildPokeStart(u32 monsNo);
void GAME_BEACON_SEARCH_SetInfoBattleWildPokeStart(GameBeaconInfo *info, u32 monsNo);
void GAME_BEACON_SEARCH_SetBattleWildPokeWin(u32 monsNo);
void GAME_BEACON_SEARCH_SetInfoBattleWildPokeWin(GameBeaconInfo *info, u32 monsNo);
void GAME_BEACON_SEARCH_SetBattleSpecialPokeStart(u32 monsNo);
void GAME_BEACON_SEARCH_SetInfoBattleSpecialPokeStart(GameBeaconInfo *info, u32 monsNo);
void GAME_BEACON_SEARCH_SetBattleSpecialPokeWin(u32 monsNo);
void GAME_BEACON_SEARCH_SetInfoBattleSpecialPokeWin(GameBeaconInfo *info, u32 monsNo);
void GAME_BEACON_SEARCH_SetBattleTrainerStart(u32 trainerId);
void GAME_BEACON_SEARCH_SetInfoBattleTrainerStart(GameBeaconInfo *info, u32 trainerId);
void GAME_BEACON_SEARCH_SetBattleTrainerWin(u32 trainerId);
void GAME_BEACON_SEARCH_SetInfoBattleTrainerWin(GameBeaconInfo *info, u32 trainerId);
void GAME_BEACON_SEARCH_SetBattleLeaderStart(u32 trainerId);
void GAME_BEACON_SEARCH_SetInfoBattleLeaderStart(GameBeaconInfo *info, u32 trainerId);
void GAME_BEACON_SEARCH_SetBattleLeaderWin(u32 trainerId);
void GAME_BEACON_SEARCH_SetInfoBattleLeaderWin(GameBeaconInfo *info, u32 trainerId);
void GAME_BEACON_SEARCH_SetBattleBigFourStart(u32 trainerId);
void GAME_BEACON_SEARCH_SetInfoBattleBigFourStart(GameBeaconInfo *info, u32 trainerId);
void GAME_BEACON_SEARCH_SetBattleBigFourWin(u32 trainerId);
void GAME_BEACON_SEARCH_SetInfoBattleBigFourWin(GameBeaconInfo *info, u32 trainerId);
void GAME_BEACON_SEARCH_SetVersionAction(u32 version);
void GAME_BEACON_SEARCH_SetInfoVersionAction(GameBeaconInfo *info, u32 version);
void GAME_BEACON_SEARCH_SetItemFound(u32 itemNo);
void GAME_BEACON_SEARCH_SetInfoItemFound(GameBeaconInfo *info, u32 itemNo);
void GAME_BEACON_SEARCH_SetScriptEvent(void);
void GAME_BEACON_SEARCH_SetInfoScriptEvent(GameBeaconInfo *info);
void GAME_BEACON_SEARCH_SetPresetEvent(u32 eventId);
void GAME_BEACON_SEARCH_SetInfoPresetEvent(GameBeaconInfo *info, u32 eventId);
void GAME_BEACON_SEARCH_SetFieldEvent(void);
void GAME_BEACON_SEARCH_SetInfoFieldEvent(GameBeaconInfo *info);
void GAME_BEACON_SEARCH_SetPokeEvent(u16 monsNo);
void GAME_BEACON_SEARCH_SetInfoPokeEvent(GameBeaconInfo *info);
void GAME_BEACON_SEARCH_SetEventBattleNameA(const struct Strbuf *name);
void GAME_BEACON_SEARCH_SetInfoEventBattleNameA(GameBeaconInfo *info, const struct Strbuf *name);
void GAME_BEACON_SEARCH_SetEventBattleNameB(const struct Strbuf *name);
void GAME_BEACON_SEARCH_SetInfoEventBattleNameB(GameBeaconInfo *info, const struct Strbuf *name);
void GAME_BEACON_SEARCH_SetEventBattleNameC(const struct Strbuf *name);
void GAME_BEACON_SEARCH_SetInfoEventBattleNameC(GameBeaconInfo *info, const struct Strbuf *name);
void GAME_BEACON_SEARCH_SetEventBattleNameD(const struct Strbuf *name);
void GAME_BEACON_SEARCH_SetInfoEventBattleNameD(GameBeaconInfo *info, const struct Strbuf *name);
void GAME_BEACON_SEARCH_SetCountValue(u32 count);
void GAME_BEACON_SEARCH_SetInfoCountValue(GameBeaconInfo *info, u32 count);
void GAME_BEACON_SEARCH_SetSymbolMapEnter(void);
void GAME_BEACON_SEARCH_SetInfoSymbolMapEnter(GameBeaconInfo *info);
void GAME_BEACON_SEARCH_SetSymbolMapPoke(u32 monsNo);
void GAME_BEACON_SEARCH_SetInfoSymbolMapPoke(GameBeaconInfo *info, u32 monsNo);
void GAME_BEACON_SEARCH_SetFacilityEnter(void);
void GAME_BEACON_SEARCH_SetInfoFacilityEnter(GameBeaconInfo *info);
void GAME_BEACON_SEARCH_SetFacilityExit(void);
void GAME_BEACON_SEARCH_SetInfoFacilityExit(GameBeaconInfo *info);
void GAME_BEACON_SEARCH_SetWordValue(u32 value);
void GAME_BEACON_SEARCH_SetInfoWordValue(GameBeaconInfo *info, u32 value);
void GAME_BEACON_SEARCH_SetWordClear(void);
void GAME_BEACON_SEARCH_SetInfoWordClear(GameBeaconInfo *info);
void GAME_BEACON_SEARCH_SetSimpleEventA(void);
void GAME_BEACON_SEARCH_SetInfoSimpleEventA(GameBeaconInfo *info);
void GAME_BEACON_SEARCH_SetByteValue(u8 value);
void GAME_BEACON_SEARCH_SetInfoByteValue(GameBeaconInfo *info, u8 value);
void GAME_BEACON_SEARCH_SetSimpleEventB(void);
void GAME_BEACON_SEARCH_SetInfoSimpleEventB(GameBeaconInfo *info);
void GAME_BEACON_SEARCH_SetSimpleEventC(void);
void GAME_BEACON_SEARCH_SetInfoSimpleEventC(GameBeaconInfo *info);
void GAME_BEACON_SEARCH_SetNamedEvent(const struct Strbuf *name);
void GAME_BEACON_SEARCH_SetInfoNamedEvent(GameBeaconInfo *info, const struct Strbuf *name);
void GAME_BEACON_SEARCH_SetHalfwordValue(u16 value);
void GAME_BEACON_SEARCH_SetInfoHalfwordValue(GameBeaconInfo *info, u16 value);
void GAME_BEACON_SEARCH_SetThanks(struct GameData *gameData, u16 trainerId);
void GAME_BEACON_SEARCH_SetInfoThanks(GameBeaconInfo *info, struct GameData *gameData, u16 trainerId);
void GAME_BEACON_SEARCH_SetFreeText(const struct Strbuf *text);
void GAME_BEACON_SEARCH_SetInfoFreeText(GameBeaconInfo *info, const struct Strbuf *text);
/* END mkheaders: generated region */

#endif
