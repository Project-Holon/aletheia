#ifndef GAME_OV010_MAP_REPLACE_H
#define GAME_OV010_MAP_REPLACE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of map_replace.c, prototypes copied from their definitions. */

struct MapReplace;
struct GameSystem;
struct MapReplaceFlagEntry;
struct GameData;
struct Location;
typedef struct MapReplace MapReplace;
typedef struct MapReplaceFlagEntry MapReplaceFlagEntry;

#include "../types.h"

MapReplace *MAP_REPLACE_Create(int heapId, struct GameSystem *gameSystem);
u32 MAP_REPLACE_GetRecordCount(MapReplace *replace);
u32 MAP_REPLACE_LoadRecord(MapReplace *replace, int index);
int MAP_REPLACE_Delete(MapReplace *replace);
int MAP_REPLACE_CheckRecord(MapReplace *replace, u32 *oldId, u32 *newId);
int MAP_REPLACE_GetFlagIndex(int selector);
void MAP_REPLACE_SetupFlags(u8 *variant, struct GameSystem *gameSystem);
MapReplaceFlagEntry *MAP_REPLACE_FindFlagEntry(struct GameData *unused, int flagNo);
void MAP_REPLACE_SetFlag(struct GameData *gameData, int flagNo, int set);
int MAP_REPLACE_CheckFlag(struct GameData *gameData, int flagNo);
int MAP_REPLACE_GetDefaultWarpId(void);
int MAP_REPLACE_IsValidWarpId(int warpId);
u16 MAP_REPLACE_GetWarpFlagId(int warpId);
void MAP_REPLACE_ApplyWarpLocation(int warpId, struct Location *location);
int MAP_REPLACE_FindFlyTargetIndex(int zoneId);
void MAP_REPLACE_SetArriveFlag(void *gameData, int zoneId);
void MAP_REPLACE_SetDirectLocation(void *location, int zoneId, int unused, unsigned gridX, u16 gridZ);
int MAP_REPLACE_WarpIdToIndex(int warpId);
/* END mkheaders: generated region */

#endif
