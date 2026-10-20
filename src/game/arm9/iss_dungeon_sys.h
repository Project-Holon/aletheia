#ifndef GAME_ARM9_ISS_DUNGEON_SYS_H
#define GAME_ARM9_ISS_DUNGEON_SYS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of iss_dungeon_sys.c, prototypes copied from their definitions. */

struct DungeonSoundRecord;
struct DungeonSoundTable;
struct IssDungeonSys;
struct GameData;
struct PlayerWork;
typedef struct DungeonSoundRecord DungeonSoundRecord;
typedef struct DungeonSoundTable DungeonSoundTable;
typedef struct IssDungeonSys IssDungeonSys;

#include "../types.h"

void ISS_DUNGEON_SYS_ApplyTrack(DungeonSoundRecord *record, u32 trackIndex);
DungeonSoundTable *ISS_DUNGEON_SYS_CreateTable(u32 heapId);
void ISS_DUNGEON_SYS_DeleteTable(DungeonSoundTable *table);
DungeonSoundRecord *ISS_DUNGEON_SYS_FindRecord(DungeonSoundTable *table, u16 areaId);
IssDungeonSys *ISS_DUNGEON_SYS_Create(struct GameData *gameData, struct PlayerWork *player, u32 heapId);
void ISS_DUNGEON_SYS_Delete(IssDungeonSys *dungeon);
void ISS_DUNGEON_SYS_Update(IssDungeonSys *dungeon);
void ISS_DUNGEON_SYS_SetTargetAreaId(IssDungeonSys *dungeon, u16 areaId);
void ISS_DUNGEON_SYS_Start(IssDungeonSys *dungeon);
void ISS_DUNGEON_SYS_Stop(IssDungeonSys *dungeon);
u32 ISS_DUNGEON_SYS_IsActive(IssDungeonSys *dungeon);
u32 ISS_DUNGEON_SYS_HasRecord(IssDungeonSys *dungeon, u16 areaId);
void ISS_DUNGEON_SYS_ResetTracks(IssDungeonSys *dungeon);
void ISS_DUNGEON_SYS_Activate(IssDungeonSys *dungeon);
void ISS_DUNGEON_SYS_Deactivate(IssDungeonSys *dungeon);
void ISS_DUNGEON_SYS_SelectRecord(IssDungeonSys *dungeon, u16 areaId);
/* END mkheaders: generated region */

typedef struct DungeonSoundRecord DungeonSoundRecord;
typedef struct DungeonSoundTable DungeonSoundTable;
typedef struct IssDungeonSys IssDungeonSys;

#endif
