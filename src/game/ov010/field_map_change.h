#ifndef GAME_OV010_FIELD_MAP_CHANGE_H
#define GAME_OV010_FIELD_MAP_CHANGE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_map_change.c, prototypes copied from their definitions. */

struct GameData;

#include "../types.h"

void FIELD_MAP_CHANGE_ApplyZoneHeader(struct GameData *gameData, void *zoneHeader);
void FIELD_MAP_CHANGE_SetupZone(struct GameData *gameData, u32 zoneId);
int FIELD_MAP_CHANGE_ResetGimmickStateCase1(int object, int unused);
int FIELD_MAP_CHANGE_ResetGimmickStateCase3(int object, int unused);
int FIELD_MAP_CHANGE_ResetGimmickStateCase2(int object, int unused);
int FIELD_MAP_CHANGE_ResetGimmickStateCase4(struct GameData *object, int unused);
void FIELD_MAP_CHANGE_MoveActiveEntries(void *object, int unused);
void FIELD_MAP_CHANGE_Empty(struct GameData *system, u16 zoneId);
/* END mkheaders: generated region */

#endif
