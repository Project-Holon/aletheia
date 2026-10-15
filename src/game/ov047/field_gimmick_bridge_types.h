#ifndef ALETHEIA_OV047_FIELD_GIMMICK_BRIDGE_TYPES_H
#define ALETHEIA_OV047_FIELD_GIMMICK_BRIDGE_TYPES_H

/*
 * Field gimmick 31 (overlay 47): while the player stands on a no-dash tile
 * the player model bobs up and down, as on a swaying bridge. Each cycle of
 * the sway picks a random amplitude from a four entry table.
 */

#include "../ov021/fieldmap_types.h"
#include "../ov010/fldmmdl_types.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed int s32;
typedef long long s64;
typedef int fx32;

struct GameSystem;
struct GameData;
struct GimmickWork;
typedef struct FieldPlayer FieldPlayer;

/* Id of this gimmick in the gimmick work. */
#define FIELD_GIMMICK_ID_BRIDGE_SWAY 31

/* Work id of the sway work in the field map work table. */
#define BRIDGE_SWAY_WORK_ID 1

/* The sway work (0x14 bytes, field map work id 1). */
typedef struct BridgeSwayWork {
    FieldPlayer *player;    /* 0x00 */
    Mmdl *playerMmdl;       /* 0x04: model that receives the draw offset */
    MmdlVec drawOffset;     /* 0x08: only y is written, in fx32 */
} BridgeSwayWork;

/* The sway state in the gimmick save area (4 bytes). */
typedef struct BridgeSwaySave {
    s16 angle;              /* 0x00: sway phase in degrees, 0..359 */
    s16 amplitude;          /* 0x02: peak height of the current cycle, in tiles */
} BridgeSwaySave;

/* The functions of overlay 21 and arm9 that the gimmick uses. */
extern struct GameSystem *FIELDMAP_GetGameSystem(FieldMap *fieldMap);
extern u16 FIELDMAP_GetHeapId(FieldMap *fieldMap);
extern FieldPlayer *FIELDMAP_GetFieldPlayer(FieldMap *fieldMap);
extern void *FIELDMAP_AllocCommonWork(FieldMap *fieldMap, int id, int heapId, int size);
extern void FIELDMAP_FreeCommonWork(FieldMap *fieldMap, int id);
extern void *FIELDMAP_GetCommonWork(FieldMap *fieldMap, int id);
extern struct GameData *ICA_ANIME_GetField1C(const struct GameSystem *gameSystem);
extern struct GimmickWork *GAME_DATA_GetFieldSave(struct GameData *gameData);
extern void *GIMMICK_WORK_GetWork(struct GimmickWork *gimmickWork, u32 gimmickId);
extern Mmdl *FIELD_PLAYER_GetMmdl(FieldPlayer *player);
extern u32 FIELD_PLAYER_GetNowAttribute(FieldPlayer *player);
extern int MAP_ATTR_IsPresent(u32 attr);
extern u16 MAP_ATTR_GetTerrainId(u32 attr);
extern int func_021AB44C(u16 terrainId);
extern void FLDMMDL_SetDrawOffsetOutside(Mmdl *mmdl, const MmdlVec *offset);
extern u32 func_02005728(u32 range);
extern short GF_STANDARD_Get_F684(unsigned short degrees);
extern void MI_CpuFill8(void *dst, int value, int size);

void FIELD_GIMMICK_BRIDGE_Init(FieldMap *fieldMap);
void FIELD_GIMMICK_BRIDGE_Exit(FieldMap *fieldMap);
void FIELD_GIMMICK_BRIDGE_Update(FieldMap *fieldMap);
void FIELD_GIMMICK_BRIDGE_ResetSave(struct GameSystem *gameSystem);
int FIELD_GIMMICK_BRIDGE_IsOnSwayTile(BridgeSwayWork *work);

#endif
