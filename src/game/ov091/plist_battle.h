#ifndef GAME_OV091_PLIST_BATTLE_H
#define GAME_OV091_PLIST_BATTLE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of plist_battle.c, prototypes copied from their definitions. */

#include "../ov091/plist_battle_types.h"
#include "../ov091/pokelist_types.h"
#include "../ov091/plist_battle_types.h"
#include "../types.h"

PlistTeamPanel *PLIST_BATTLE_CreateTeamPanel(PokelistWork *work, PlistTeamSource *source, u8 x, u8 y, u8 width);
void PLIST_BATTLE_DeleteTeamPanel(PokelistWork *work, PlistTeamPanel *panel);
void PLIST_BATTLE_UpdateTeamPanel(PokelistWork *work, PlistTeamPanel *panel);
PlistMiniCell *PLIST_BATTLE_CreateMiniCell(PokelistWork *work, void *mon, s16 x, u16 y);
void PLIST_BATTLE_DeleteMiniCell(PokelistWork *unusedWork, PlistMiniCell *cell);
void PLIST_BATTLE_UpdateMiniCell(PokelistWork *work, PlistMiniCell *cell);
void PLIST_BATTLE_RefreshOpponentMessage(PokelistWork *work);
void PLIST_BATTLE_PrintOpponentMessage(PokelistWork *work);
void PLIST_BATTLE_CreateTimerWindows(PokelistWork *work);
void PLIST_BATTLE_DeleteTimerWindows(PokelistWork *work);
void PLIST_BATTLE_UpdateTimer(PokelistWork *work);
void PLIST_BATTLE_StartEffect(PokelistWork *work);
void PLIST_BATTLE_FinishEffect(PokelistWork *work);
void PLIST_BATTLE_UpdateEffect(PokelistWork *work);
/* END mkheaders: generated region */

#endif
