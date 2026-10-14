/*
 * file:     hand_field.c
 * unit:     yes
 * function: HAND_FIELD_AddFactor, HAND_FIELD_RemoveFactor, HAND_FIELD_GravityOverrideGroundImmunity, HAND_FIELD_GetHandlersWaterSport, HAND_FIELD_WaterSportWeakenFire, HAND_FIELD_GetHandlersMudSport, HAND_FIELD_MudSportWeakenElectric, HAND_FIELD_GetHandlersUseCounter, HAND_FIELD_UseCounterIncrement, HAND_FIELD_GetHandlersWonderRoom, HAND_FIELD_GetHandlersMagicRoom, HAND_FIELD_RoomMarkerNoop
 * address:  0x06898020
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   BTL_EVENT_AddFactor  0x021D6F0C  thumb  ov093
 *   gHandFieldEffectTable     0x0689D650  data   ov095  a4
 *   BTL_EVENT_GetVar  0x021D775C  thumb
 *   BTL_EVENT_RemoveFactor  0x021D7040  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   gHandFieldWeatherMarkerHandlers     0x0689D638  data   ov095  a4
 *   gHandFieldTrickRoomHandlers     0x0689D630  data   ov095  a4
 *   gHandFieldGravityHandlers     0x0689D640  data   ov095  a4
 *   gHandFieldWaterSportHandlers 0x0689D620 data a4
 *   gHandFieldMudSportHandlers 0x0689D610 data a4
 *   gHandFieldUseCounterHandlers 0x0689D628 data a4
 *   gHandFieldWonderRoomHandlers 0x0689D618 data a4
 *   gHandFieldMagicRoomHandlers 0x0689D608 data a4
 */
#include "hand_field_types.h"

struct BtlEventFactor *HAND_FIELD_AddFactor(int effectId, int ownerId);
void HAND_FIELD_RemoveFactor(struct BtlEventFactor *factor);
const BtlEventHandler *HAND_FIELD_GetHandlersWeatherMarker(u32 *handlerCount);
void HAND_FIELD_WeatherMarkerNoop(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work);
const BtlEventHandler *HAND_FIELD_GetHandlersTrickRoom(u32 *handlerCount);
void HAND_FIELD_TrickRoomReverseSpeed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work);
const BtlEventHandler *HAND_FIELD_GetHandlersGravity(u32 *handlerCount);
void HAND_FIELD_GravityBoostAccuracy(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work);
void HAND_FIELD_GravityOverrideGroundImmunity(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work);
const BtlEventHandler *HAND_FIELD_GetHandlersWaterSport(u32 *handlerCount);
void HAND_FIELD_WaterSportWeakenFire(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work);
const BtlEventHandler *HAND_FIELD_GetHandlersMudSport(u32 *handlerCount);
void HAND_FIELD_MudSportWeakenElectric(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work);
const BtlEventHandler *HAND_FIELD_GetHandlersUseCounter(u32 *handlerCount);
void HAND_FIELD_UseCounterIncrement(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work);
const BtlEventHandler *HAND_FIELD_GetHandlersWonderRoom(u32 *handlerCount);
const BtlEventHandler *HAND_FIELD_GetHandlersMagicRoom(u32 *handlerCount);
void HAND_FIELD_RoomMarkerNoop(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work);
extern const HandEffectEntry gHandFieldEffectTable[BTL_FLDEFF_COUNT];
extern const BtlEventHandler gHandFieldWeatherMarkerHandlers[1];
extern const BtlEventHandler gHandFieldTrickRoomHandlers[1];
extern const BtlEventHandler gHandFieldGravityHandlers[2];
extern const BtlEventHandler gHandFieldWaterSportHandlers[1];
extern const BtlEventHandler gHandFieldMudSportHandlers[1];
extern const BtlEventHandler gHandFieldUseCounterHandlers[1];
extern const BtlEventHandler gHandFieldWonderRoomHandlers[1];
extern const BtlEventHandler gHandFieldMagicRoomHandlers[1];


/*
 * Registers the event factor of field effect effectId. The table row gives the handler list;
 * returns 0 when the id has no row.
 */
struct BtlEventFactor *HAND_FIELD_AddFactor(int effectId, int ownerId)
{
    u32 i;
    u32 handlerCount;

    for (i = 0; i < BTL_FLDEFF_COUNT; i++) {
        if (effectId == gHandFieldEffectTable[i].effectId) {
            const BtlEventHandler *handlers = gHandFieldEffectTable[i].getHandlers(&handlerCount);
            return BTL_EVENT_AddFactor(BTL_EVENT_TYPE_FIELD_EFFECT, effectId, 3, 0, ownerId, (u32)handlers, handlerCount);
        }
    }
    return 0;
}


/*
 * Handed extent 0x06898070 (92 bytes) opens with a 16-byte `bx pc` veneer
 * to BTL_EVENT_AddFactor (ARM linker stub, not compilable); the seven functions after
 * it (0x06898080..0x068980CC) are this unit. Two of them (0x06898094,
 * 0x06898088) are entries of the {effectId, getHandlers} table at 0x0689D650 that
 * HAND_FIELD_AddFactor walks.
 */

/* Removes the factor of a field effect when the effect ends. */
void HAND_FIELD_RemoveFactor(struct BtlEventFactor *factor)
{
    BTL_EVENT_RemoveFactor(factor);
}


/* Handler list of the weather marker field effect: one entry whose handler does nothing. */
const BtlEventHandler *HAND_FIELD_GetHandlersWeatherMarker(u32 *handlerCount)
{
    *handlerCount = 1;
    return gHandFieldWeatherMarkerHandlers;
}


/* Handler that does nothing; the effect only has to exist. */
void HAND_FIELD_WeatherMarkerNoop(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work)
{
}


/* Handler list of Trick Room: answers the speed event. */
const BtlEventHandler *HAND_FIELD_GetHandlersTrickRoom(u32 *handlerCount)
{
    *handlerCount = 1;
    return gHandFieldTrickRoomHandlers;
}


/* Trick Room: the slowest Pokemon moves first. */
void HAND_FIELD_TrickRoomReverseSpeed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work)
{
    BTL_EVENT_OverwriteVar(BTL_EVAR_REVERSE_SPEED_ORDER_FLAG, 1);
}


/* Handler list of Gravity: accuracy and ground immunity events. */
const BtlEventHandler *HAND_FIELD_GetHandlersGravity(u32 *handlerCount)
{
    *handlerCount = 2;
    return gHandFieldGravityHandlers;
}


/* Gravity: moves hit about 1.67 times as often. */
void HAND_FIELD_GravityBoostAccuracy(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work)
{
    BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, HAND_RATIO_GRAVITY_ACCURACY);
}


/* Gravity: Ground moves hit Pokemon that would be immune (Flying type, Levitate). */
void HAND_FIELD_GravityOverrideGroundImmunity(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work)
{
    if (BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE) == HAND_POKETYPE_GROUND)
        BTL_EVENT_OverwriteVar(BTL_EVAR_IMMUNITY_OVERRIDE_FLAG, 1);
}


/* Handler list of Water Sport: one entry on the move power event. */
const BtlEventHandler *HAND_FIELD_GetHandlersWaterSport(u32 *handlerCount)
{
    *handlerCount = 1;
    return gHandFieldWaterSportHandlers;
}


/* Water Sport: Fire moves do about a third of their damage. */
void HAND_FIELD_WaterSportWeakenFire(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work)
{
    if (BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE) == HAND_POKETYPE_FIRE)
        BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, HAND_RATIO_SPORT_POWER);
}


/* Handler list of Mud Sport: one entry on the move power event. */
const BtlEventHandler *HAND_FIELD_GetHandlersMudSport(u32 *handlerCount)
{
    *handlerCount = 1;
    return gHandFieldMudSportHandlers;
}


/* Mud Sport: Electric moves do about a third of their damage. */
void HAND_FIELD_MudSportWeakenElectric(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work)
{
    if (BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE) == HAND_POKETYPE_ELECTRIC)
        BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, HAND_RATIO_SPORT_POWER);
}


/* Handler list of the use counter field effect. */
const BtlEventHandler *HAND_FIELD_GetHandlersUseCounter(u32 *handlerCount)
{
    *handlerCount = 1;
    return gHandFieldUseCounterHandlers;
}


/* Adds one to the use counter event variable. */
void HAND_FIELD_UseCounterIncrement(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work)
{
    int count;
    count = BTL_EVENT_GetVar(BTL_EVAR_USE_COUNTER);
    BTL_EVENT_OverwriteVar(BTL_EVAR_USE_COUNTER, count + 1);
}


/* Handler list of the Wonder Room marker field effect (guess): one handler that does nothing. */
const BtlEventHandler *HAND_FIELD_GetHandlersWonderRoom(u32 *handlerCount)
{
    *handlerCount = 1;
    return gHandFieldWonderRoomHandlers;
}


/* Handler list of the Magic Room marker field effect (guess): one handler that does nothing. */
const BtlEventHandler *HAND_FIELD_GetHandlersMagicRoom(u32 *handlerCount)
{
    *handlerCount = 1;
    return gHandFieldMagicRoomHandlers;
}


/* Handler that does nothing; the effect only has to exist. */
void HAND_FIELD_RoomMarkerNoop(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, void *work)
{
}
