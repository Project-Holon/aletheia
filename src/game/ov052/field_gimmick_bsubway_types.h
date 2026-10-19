#ifndef ALETHEIA_OV052_FIELD_GIMMICK_BSUBWAY_TYPES_H
#define ALETHEIA_OV052_FIELD_GIMMICK_BSUBWAY_TYPES_H

/*
 * Battle Subway field gimmick (overlay 52). Each zone of the Battle Subway
 * maps (platforms and the train) has a table entry: the gimmick work slot
 * that holds its runtime record, and an index into the handler table. The
 * handlers allocate a small work block of their own into the record. The
 * script side (ov021 bsubway_scr.c) starts the train effect and reads it
 * back through this overlay.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef int fx32;

struct FieldMap;
struct GameSystem;
struct GameData;
struct GimmickWork;
struct FieldEffectSys;
struct FieldEffectObj;
struct FieldG3dMapper;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

/* Zone of the Battle Subway train, and the work slot of its sway record. */
#define BSUBWAY_ZONE_TRAIN 0x4b
#define BSUBWAY_SLOT_TRAIN_SWAY 0x27

/* Number of zone table entries (and of handler table entries). */
#define BSUBWAY_ZONE_ENTRY_COUNT 10

/* Id of the Battle Subway train resources in the field effect system. */
#define BSUBWAY_EFFECT_ID_TRAIN 14

/* Zone table entry: the zone id and the gimmick work slot of its record. */
typedef struct BsubwayZoneEntry {
    int zoneId;
    int slotId;
} BsubwayZoneEntry;

/* Work of the train handler: the train effect started by the script. */
typedef struct BsubwayTrainWork {
    struct FieldEffectObj *effect;  /* 0x00: null until the script starts the train */
} BsubwayTrainWork;

/* Work of the sway handler: a three frame jolt of the map origin at random intervals. */
typedef struct BsubwayTrainSway {
    u8 halted;          /* 0x00: 1 = no new jolt starts */
    u8 phase;           /* 0x01: 0 = pick the wait, 1 = wait, 2 = jolt */
    u8 intervalIndex;   /* 0x02: next entry of the interval table (0 to 3) */
    u8 reserved03;
    int waitFrames;     /* 0x04: frames until the next jolt */
    int offsetY;        /* 0x08: map origin offset of this frame, in whole units */
} BsubwayTrainSway;

/* The four wait times between two jolts. */
typedef struct BsubwaySwayIntervals {
    int frames[4];
} BsubwaySwayIntervals;

/* Runtime record of the zone in the gimmick work (the work slot named by the zone entry). */
typedef struct BsubwayZoneGimmick {
    u16 reserved00;
    u16 handlerIndex;               /* 0x02: entry of the handler table */
    u16 slotId;                     /* 0x04 */
    u8 reserved06[2];
    int zoneId;                     /* 0x08 */
    u16 heapId;                     /* 0x0C */
    u8 reserved0E[14];
    struct GameSystem *gameSystem;  /* 0x1C */
    struct FieldMap *fieldMap;      /* 0x20 */
    union {
        BsubwayTrainWork *train;
        BsubwayTrainSway *sway;
        void *raw;
    } work;                         /* 0x24: allocated by the init handler */
} BsubwayZoneGimmick;

typedef void (*BsubwayZoneHandler)(BsubwayZoneGimmick *zone, struct FieldMap *fieldMap);

/* Handlers of one zone entry; a null handler is skipped. */
typedef struct BsubwayZoneHandlers {
    BsubwayZoneHandler init;
    BsubwayZoneHandler update;
    BsubwayZoneHandler exit;
} BsubwayZoneHandlers;

/* Functions of overlay 21 and arm9 that the gimmick uses. */
extern u16 FIELDMAP_GetHeapId(struct FieldMap *fieldMap);
extern struct GameSystem *FIELDMAP_GetGameSystem(struct FieldMap *fieldMap);
extern struct GameData *GAMESYSTEM_GetGameData(const struct GameSystem *gameSystem);
extern struct GimmickWork *GAME_DATA_GetFieldSave(struct GameData *gameData);
extern BsubwayZoneGimmick *GIMMICK_WORK_GetWork(struct GimmickWork *gimmickWork, u32 slotId);
extern u16 FIELDMAP_GetZoneId(struct FieldMap *fieldMap);
extern struct FieldEffectSys *FIELDMAP_GetEffect(struct FieldMap *fieldMap);
extern struct FieldG3dMapper *FIELDMAP_GetG3dMapper(struct FieldMap *fieldMap);
extern struct FieldEffectObj *FLDEFF_BTRAIN_Start(struct FieldEffectSys *fieldEffect, u32 modelIndex, const VecFx32 *pos);
extern void FIELD_EFFECT_LoadResources(struct FieldEffectSys *fieldEffect, const int *effectIds, int count);
extern void FIELD_G3D_MAPPER_SetOriginOffset(struct FieldG3dMapper *mapper, VecFx32 *offset);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 line);
extern u32 GFL_HEAP_Free(void *p);

void FIELD_GIMMICK_BSUBWAY_FindZoneEntry(int zoneId, int *slotId, int *handlerIndex);

#endif
