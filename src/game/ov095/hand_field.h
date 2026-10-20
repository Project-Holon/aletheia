#ifndef GAME_OV095_HAND_FIELD_H
#define GAME_OV095_HAND_FIELD_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of hand_field.c, prototypes copied from their definitions. */

struct BtlEventFactor;
struct BtlServerFlow;

#include "../ov093/btl_event_types.h"
#include "../types.h"

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
/* END mkheaders: generated region */

#endif
