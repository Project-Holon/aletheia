/*
 * file:     field_gimmick_bsubway.c
 * unit:     yes
 * function: FIELD_GIMMICK_BSUBWAY_Init, FIELD_GIMMICK_BSUBWAY_Update, FIELD_GIMMICK_BSUBWAY_Exit, FIELD_GIMMICK_BSUBWAY_StartTrain, FIELD_GIMMICK_BSUBWAY_GetTrainEffect, FIELD_GIMMICK_BSUBWAY_InitTrain, FIELD_GIMMICK_BSUBWAY_ExitTrain, FIELD_GIMMICK_BSUBWAY_HaltTrainSway, FIELD_GIMMICK_BSUBWAY_InitTrainSway, FIELD_GIMMICK_BSUBWAY_ExitTrainSway, FIELD_GIMMICK_BSUBWAY_UpdateTrainSway, FIELD_GIMMICK_BSUBWAY_FindZoneEntry
 * address:  0x021F36C0
 * region:   ov052
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   FIELD_GIMMICK_BSUBWAY_FindZoneEntry  0x021F3998  thumb  ov052
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb
 *   sFieldGimmickBsubwayZoneHandlers     0x021F3A2C  data  a4
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   FLDEFF_BTRAIN_Start  0x021D0218  thumb  ov021
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   FIELD_EFFECT_LoadResources  0x021ABE30  thumb  ov021
 *   sFieldGimmickBsubwayFileName     0x021F3AC0  data  ov052  a4
 *   GFL_HEAP_Free 0x020307B0 arm
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb  ov021
 *   FIELD_G3D_MAPPER_SetOriginOffset  0x0218DC4C  thumb  ov021
 *   sFieldGimmickBsubwaySwayIntervals     0x021F39CC  data  a4
 *   sFieldGimmickBsubwayZoneTable     0x021F39DC  data  ov052  a4
 */
#include "field_gimmick_bsubway_types.h"

void FIELD_GIMMICK_BSUBWAY_Init(struct FieldMap *fieldMap);
void FIELD_GIMMICK_BSUBWAY_Update(struct FieldMap *fieldMap);
void FIELD_GIMMICK_BSUBWAY_Exit(struct FieldMap *fieldMap);
void FIELD_GIMMICK_BSUBWAY_StartTrain(struct FieldMap *fieldMap, u32 modelIndex, const VecFx32 *pos);
struct FieldEffectObj *FIELD_GIMMICK_BSUBWAY_GetTrainEffect(struct FieldMap *fieldMap);
void FIELD_GIMMICK_BSUBWAY_InitTrain(BsubwayZoneGimmick *zone, struct FieldMap *fieldMap);
void FIELD_GIMMICK_BSUBWAY_ExitTrain(BsubwayZoneGimmick *zone, struct FieldMap *fieldMap);
void FIELD_GIMMICK_BSUBWAY_HaltTrainSway(struct FieldMap *fieldMap);
void FIELD_GIMMICK_BSUBWAY_InitTrainSway(BsubwayZoneGimmick *zone, struct FieldMap *fieldMap);
void FIELD_GIMMICK_BSUBWAY_ExitTrainSway(BsubwayZoneGimmick *zone, struct FieldMap *fieldMap);
void FIELD_GIMMICK_BSUBWAY_UpdateTrainSway(BsubwayZoneGimmick *zone, struct FieldMap *fieldMap);

extern BsubwayZoneHandlers sFieldGimmickBsubwayZoneHandlers[];
extern char sFieldGimmickBsubwayFileName[];
extern BsubwaySwayIntervals sFieldGimmickBsubwaySwayIntervals;
#define BSUBWAY_ZONE_ENTRY_COUNT 10
extern BsubwayZoneEntry sFieldGimmickBsubwayZoneTable[];

/* Gimmick init: fills in the record of the zone and runs the init handler of the zone. */
void FIELD_GIMMICK_BSUBWAY_Init(struct FieldMap *fieldMap)
{
    int handlerIndex;
    int slotId;
    int heapId;
    int zoneId;
    struct GameSystem *gameSystem;
    struct GimmickWork *gimmickWork;
    BsubwayZoneGimmick *zone;
    BsubwayZoneHandler init;

    heapId = FIELDMAP_GetHeapId(fieldMap);
    gameSystem = FIELDMAP_GetGameSystem(fieldMap);
    gimmickWork = GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(gameSystem));
    zoneId = FIELDMAP_GetZoneId(fieldMap);
    FIELD_GIMMICK_BSUBWAY_FindZoneEntry(zoneId, &slotId, &handlerIndex);
    zone = GIMMICK_WORK_GetSaveArea(gimmickWork, slotId);
    zone->handlerIndex = handlerIndex;
    zone->slotId = slotId;
    zone->zoneId = zoneId;
    zone->heapId = heapId;
    zone->gameSystem = gameSystem;
    zone->fieldMap = fieldMap;
    init = sFieldGimmickBsubwayZoneHandlers[zone->handlerIndex].init;
    if (init)
        init(zone, fieldMap);
}

/* Gimmick update: runs the update handler of the zone. */
void FIELD_GIMMICK_BSUBWAY_Update(struct FieldMap *fieldMap)
{
    int handlerIndex;
    int slotId;
    struct GimmickWork *gimmickWork;
    BsubwayZoneGimmick *zone;
    BsubwayZoneHandler update;

    FIELDMAP_GetHeapId(fieldMap);
    gimmickWork = GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap)));
    FIELD_GIMMICK_BSUBWAY_FindZoneEntry(FIELDMAP_GetZoneId(fieldMap), &slotId, &handlerIndex);
    zone = GIMMICK_WORK_GetSaveArea(gimmickWork, slotId);
    update = sFieldGimmickBsubwayZoneHandlers[zone->handlerIndex].update;
    if (update)
        update(zone, fieldMap);
}

/* Gimmick exit: runs the exit handler of the zone. */
void FIELD_GIMMICK_BSUBWAY_Exit(struct FieldMap *fieldMap)
{
    int handlerIndex;
    int slotId;
    struct GimmickWork *gimmickWork;

    gimmickWork = GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap)));
    FIELD_GIMMICK_BSUBWAY_FindZoneEntry(FIELDMAP_GetZoneId(fieldMap), &slotId, &handlerIndex);
    if (sFieldGimmickBsubwayZoneHandlers[handlerIndex].exit) {
        BsubwayZoneGimmick *zone = GIMMICK_WORK_GetSaveArea(gimmickWork, slotId);
        sFieldGimmickBsubwayZoneHandlers[handlerIndex].exit(zone, fieldMap);
    }
}

/* Script command: starts the train effect of one train kind at pos. */
void FIELD_GIMMICK_BSUBWAY_StartTrain(struct FieldMap *fieldMap, u32 modelIndex, const VecFx32 *pos)
{
    int handlerIndex;
    int slotId;
    struct GimmickWork *gimmickWork;
    BsubwayTrainWork *train;

    FIELDMAP_GetHeapId(fieldMap);
    gimmickWork = GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap)));
    FIELD_GIMMICK_BSUBWAY_FindZoneEntry(FIELDMAP_GetZoneId(fieldMap), &slotId, &handlerIndex);
    train = GIMMICK_WORK_GetSaveArea(gimmickWork, slotId)->work.train;
    train->effect = FLDEFF_BTRAIN_Start(FIELDMAP_GetEffect(fieldMap), modelIndex, pos);
}

/* Returns the train effect that the script started. */
struct FieldEffectObj *FIELD_GIMMICK_BSUBWAY_GetTrainEffect(struct FieldMap *fieldMap)
{
    int handlerIndex, slotId;
    struct GimmickWork *gimmickWork;

    FIELDMAP_GetHeapId(fieldMap);
    gimmickWork = GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap)));
    FIELD_GIMMICK_BSUBWAY_FindZoneEntry(FIELDMAP_GetZoneId(fieldMap), &slotId, &handlerIndex);
    return GIMMICK_WORK_GetSaveArea(gimmickWork, slotId)->work.train->effect;
}

/* Train handler init: allocates the train work and loads the train effect resources. */
void FIELD_GIMMICK_BSUBWAY_InitTrain(BsubwayZoneGimmick *zone, struct FieldMap *fieldMap)
{
    int effectId;
    struct FieldEffectSys *fieldEffect = FIELDMAP_GetEffect(fieldMap);

    zone->work.raw = GFL_HEAP_Alloc(zone->heapId, sizeof(BsubwayTrainWork), 1, sFieldGimmickBsubwayFileName, 0x112);
    effectId = BSUBWAY_EFFECT_ID_TRAIN;
    FIELD_EFFECT_LoadResources(fieldEffect, &effectId, 1);
}

/* Train handler exit. */
void FIELD_GIMMICK_BSUBWAY_ExitTrain(BsubwayZoneGimmick *zone, struct FieldMap *fieldMap)
{
    GFL_HEAP_Free(zone->work.raw);
}

/* Script command: stops the sway of the train, when the player is in the train zone. */
void FIELD_GIMMICK_BSUBWAY_HaltTrainSway(struct FieldMap *fieldMap)
{
    struct GimmickWork *gimmickWork = GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap)));

    if (FIELDMAP_GetZoneId(fieldMap) == BSUBWAY_ZONE_TRAIN) {
        BsubwayZoneGimmick *zone = GIMMICK_WORK_GetSaveArea(gimmickWork, BSUBWAY_SLOT_TRAIN_SWAY);
        if (zone != 0) {
            BsubwayTrainSway *sway = zone->work.sway;
            if (sway != 0)
                sway->halted = 1;
        }
    }
}

/* Sway handler init. */
void FIELD_GIMMICK_BSUBWAY_InitTrainSway(BsubwayZoneGimmick *zone, struct FieldMap *fieldMap)
{
    zone->work.raw = GFL_HEAP_Alloc(zone->heapId, sizeof(BsubwayTrainSway), 1, sFieldGimmickBsubwayFileName, 0x164);
}

/* Sway handler exit. */
void FIELD_GIMMICK_BSUBWAY_ExitTrainSway(BsubwayZoneGimmick *zone, struct FieldMap *fieldMap)
{
    GFL_HEAP_Free(zone->work.raw);
}

/*
 * Sway handler update: after a wait taken from the interval table the map
 * origin moves by +1, -1 and 0 units on three frames in a row.
 */
void FIELD_GIMMICK_BSUBWAY_UpdateTrainSway(BsubwayZoneGimmick *zone, struct FieldMap *fieldMap)
{
    VecFx32 offset = {0, 0, 0};
    BsubwaySwayIntervals intervals = sFieldGimmickBsubwaySwayIntervals;
    BsubwayTrainSway *sway = zone->work.sway;
    struct FieldG3dMapper *mapper = FIELDMAP_GetG3dMapper(fieldMap);

    switch (sway->phase) {
    case 0:
        if (sway->halted == 1)
            return;
        sway->waitFrames = intervals.frames[sway->intervalIndex];
        sway->intervalIndex++;
        sway->intervalIndex &= 3;
        sway->phase++;
    case 1:
        if (--sway->waitFrames <= 0) {
            sway->offsetY = 1;
            sway->phase++;
        }
        break;
    case 2:
        offset.y = sway->offsetY << 12;
        FIELD_G3D_MAPPER_SetOriginOffset(mapper, &offset);
        if (sway->offsetY == 0)
            sway->phase = 0;
        if (sway->offsetY < 0) {
            sway->offsetY += 2;
            if (sway->offsetY > 0)
                sway->offsetY = 0;
        }
        sway->offsetY = -sway->offsetY;
        break;
    }
}

/*
 * Looks the zone up in the zone table. Returns the gimmick work slot of the
 * zone and the table index (the index of its handlers); both 0 for an
 * unknown zone.
 */
void FIELD_GIMMICK_BSUBWAY_FindZoneEntry(int zoneId, int *slotId, int *handlerIndex)
{
    int i;
    for (i = 0; i < BSUBWAY_ZONE_ENTRY_COUNT; i++) {
        if (zoneId == sFieldGimmickBsubwayZoneTable[i].zoneId) {
            *slotId = sFieldGimmickBsubwayZoneTable[i].slotId;
            *handlerIndex = i;
            return;
        }
    }
    *slotId = 0;
    *handlerIndex = 0;
}
