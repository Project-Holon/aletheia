#ifndef GAME_OV095_HAND_POS_H
#define GAME_OV095_HAND_POS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of hand_pos.c, prototypes copied from their definitions. */

struct BtlEventFactor;
struct BtlServerFlow;

#include "../types.h"
#include "../ov093/btl_event_types.h"
#include "../ov095/hand_field_types.h"

struct BtlEventFactor *HAND_POS_AddFactor(int effectId, int position, u32 userPokeId, u32 *values, u8 valueCount);
int HAND_POS_IsRegistered(int a, int b);
int HAND_POS_IsNotRegistered(int effectId, int position);
const BtlEventHandler *HAND_POS_GetHandlersWish(u32 *handlerCount);
void HAND_POS_WishHealOnTurn(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int position, HandWishWork *work);
const BtlEventHandler *HAND_POS_GetHandlersLunarDance(u32 *handlerCount);
void HAND_POS_LunarDanceOnSwitchIn(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 position);
const BtlEventHandler *HAND_POS_GetHandlersHealingWish(u32 *handlerCount);
void HAND_POS_HealingWishOnSwitchIn(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 position);
const BtlEventHandler *HAND_POS_GetHandlersFutureSight(u32 *handlerCount);
void HAND_POS_FutureSightOnTurn(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int position, HandFutureSightWork *work);
const BtlEventHandler *HAND_POS_GetHandlersPending(u32 *handlerCount);
void HAND_POS_PendingOnEnter(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int position, u32 *work);
/* END mkheaders: generated region */

#endif
