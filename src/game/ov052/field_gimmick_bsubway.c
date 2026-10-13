/*
 * file:     field_gimmick_bsubway.c
 * unit:     yes
 * function: func_021F36C0, func_021F3724, func_021F3770, func_021F37C0, func_021F380C, func_021F3844, func_021F3880, func_021F388C, func_021F38C0, func_021F38E4, func_021F38F0
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
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_021F3998  0x021F3998  thumb  ov052
 *   func_0200B3A4  0x0200B3A4  thumb
 *   d_021F3A2C     0x021F3A2C  data  a4
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021D0218  0x021D0218  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   func_021ABE30  0x021ABE30  thumb  ov021
 *   d_021F3AC0     0x021F3AC0  data  ov052  a4
 *   func_020307B0 0x020307B0 arm
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_0218DC4C  0x0218DC4C  thumb  ov021
 *   d_021F39CC     0x021F39CC  data  a4
 */
#include "field_gimmick_bsubway_types.h"

void func_021F36C0(struct FieldMap *fieldMap);
void func_021F3724(struct FieldMap *fieldMap);
void func_021F3770(struct FieldMap *fieldMap);
void func_021F37C0(struct FieldMap *fieldMap, u32 modelIndex, const VecFx32 *pos);
struct FieldEffectObj *func_021F380C(struct FieldMap *fieldMap);
void func_021F3844(BsubwayZoneGimmick *zone, struct FieldMap *fieldMap);
void func_021F3880(BsubwayZoneGimmick *zone, struct FieldMap *fieldMap);
void func_021F388C(struct FieldMap *fieldMap);
void func_021F38C0(BsubwayZoneGimmick *zone, struct FieldMap *fieldMap);
void func_021F38E4(BsubwayZoneGimmick *zone, struct FieldMap *fieldMap);
void func_021F38F0(BsubwayZoneGimmick *zone, struct FieldMap *fieldMap);

extern BsubwayZoneHandlers d_021F3A2C[];
extern char d_021F3AC0[];
extern BsubwaySwayIntervals d_021F39CC;

/* Gimmick init: fills in the record of the zone and runs the init handler of the zone. */
void func_021F36C0(struct FieldMap *fieldMap)
{
    int handlerIndex;
    int slotId;
    int heapId;
    int zoneId;
    struct GameSystem *gameSystem;
    struct GimmickWork *gimmickWork;
    BsubwayZoneGimmick *zone;
    BsubwayZoneHandler init;

    heapId = func_02188C84(fieldMap);
    gameSystem = func_02188C80(fieldMap);
    gimmickWork = func_02012EC4(func_020120F4(gameSystem));
    zoneId = func_02188C9C(fieldMap);
    func_021F3998(zoneId, &slotId, &handlerIndex);
    zone = func_0200B3A4(gimmickWork, slotId);
    zone->handlerIndex = handlerIndex;
    zone->slotId = slotId;
    zone->zoneId = zoneId;
    zone->heapId = heapId;
    zone->gameSystem = gameSystem;
    zone->fieldMap = fieldMap;
    init = d_021F3A2C[zone->handlerIndex].init;
    if (init)
        init(zone, fieldMap);
}

/* Gimmick update: runs the update handler of the zone. */
void func_021F3724(struct FieldMap *fieldMap)
{
    int handlerIndex;
    int slotId;
    struct GimmickWork *gimmickWork;
    BsubwayZoneGimmick *zone;
    BsubwayZoneHandler update;

    func_02188C84(fieldMap);
    gimmickWork = func_02012EC4(func_020120F4(func_02188C80(fieldMap)));
    func_021F3998(func_02188C9C(fieldMap), &slotId, &handlerIndex);
    zone = func_0200B3A4(gimmickWork, slotId);
    update = d_021F3A2C[zone->handlerIndex].update;
    if (update)
        update(zone, fieldMap);
}

/* Gimmick exit: runs the exit handler of the zone. */
void func_021F3770(struct FieldMap *fieldMap)
{
    int handlerIndex;
    int slotId;
    struct GimmickWork *gimmickWork;

    gimmickWork = func_02012EC4(func_020120F4(func_02188C80(fieldMap)));
    func_021F3998(func_02188C9C(fieldMap), &slotId, &handlerIndex);
    if (d_021F3A2C[handlerIndex].exit) {
        BsubwayZoneGimmick *zone = func_0200B3A4(gimmickWork, slotId);
        d_021F3A2C[handlerIndex].exit(zone, fieldMap);
    }
}

/* Script command: starts the train effect of one train kind at pos. */
void func_021F37C0(struct FieldMap *fieldMap, u32 modelIndex, const VecFx32 *pos)
{
    int handlerIndex;
    int slotId;
    struct GimmickWork *gimmickWork;
    BsubwayTrainWork *train;

    func_02188C84(fieldMap);
    gimmickWork = func_02012EC4(func_020120F4(func_02188C80(fieldMap)));
    func_021F3998(func_02188C9C(fieldMap), &slotId, &handlerIndex);
    train = func_0200B3A4(gimmickWork, slotId)->work.train;
    train->effect = func_021D0218(func_02188CD0(fieldMap), modelIndex, pos);
}

/* Returns the train effect that the script started. */
struct FieldEffectObj *func_021F380C(struct FieldMap *fieldMap)
{
    int handlerIndex, slotId;
    struct GimmickWork *gimmickWork;

    func_02188C84(fieldMap);
    gimmickWork = func_02012EC4(func_020120F4(func_02188C80(fieldMap)));
    func_021F3998(func_02188C9C(fieldMap), &slotId, &handlerIndex);
    return func_0200B3A4(gimmickWork, slotId)->work.train->effect;
}

/* Train handler init: allocates the train work and loads the train effect resources. */
void func_021F3844(BsubwayZoneGimmick *zone, struct FieldMap *fieldMap)
{
    int effectId;
    struct FieldEffectSys *fieldEffect = func_02188CD0(fieldMap);

    zone->work.raw = func_02030734(zone->heapId, sizeof(BsubwayTrainWork), 1, d_021F3AC0, 0x112);
    effectId = BSUBWAY_EFFECT_ID_TRAIN;
    func_021ABE30(fieldEffect, &effectId, 1);
}

/* Train handler exit. */
void func_021F3880(BsubwayZoneGimmick *zone, struct FieldMap *fieldMap)
{
    func_020307B0(zone->work.raw);
}

/* Script command: stops the sway of the train, when the player is in the train zone. */
void func_021F388C(struct FieldMap *fieldMap)
{
    struct GimmickWork *gimmickWork = func_02012EC4(func_020120F4(func_02188C80(fieldMap)));

    if (func_02188C9C(fieldMap) == BSUBWAY_ZONE_TRAIN) {
        BsubwayZoneGimmick *zone = func_0200B3A4(gimmickWork, BSUBWAY_SLOT_TRAIN_SWAY);
        if (zone != 0) {
            BsubwayTrainSway *sway = zone->work.sway;
            if (sway != 0)
                sway->halted = 1;
        }
    }
}

/* Sway handler init. */
void func_021F38C0(BsubwayZoneGimmick *zone, struct FieldMap *fieldMap)
{
    zone->work.raw = func_02030734(zone->heapId, sizeof(BsubwayTrainSway), 1, d_021F3AC0, 0x164);
}

/* Sway handler exit. */
void func_021F38E4(BsubwayZoneGimmick *zone, struct FieldMap *fieldMap)
{
    func_020307B0(zone->work.raw);
}

/*
 * Sway handler update: after a wait taken from the interval table the map
 * origin moves by +1, -1 and 0 units on three frames in a row.
 */
void func_021F38F0(BsubwayZoneGimmick *zone, struct FieldMap *fieldMap)
{
    VecFx32 offset = {0, 0, 0};
    BsubwaySwayIntervals intervals = d_021F39CC;
    BsubwayTrainSway *sway = zone->work.sway;
    struct FieldG3dMapper *mapper = func_02188C98(fieldMap);

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
        func_0218DC4C(mapper, &offset);
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
