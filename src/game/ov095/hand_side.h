#ifndef GAME_OV095_HAND_SIDE_H
#define GAME_OV095_HAND_SIDE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of hand_side.c, prototypes copied from their definitions. */

struct BtlEventFactor;
struct BtlServerFlow;

#include "../types.h"
#include "../ov095/hand_field_types.h"
#include "../ov093/btl_event_types.h"

void HAND_SIDE_InitTable(void);
struct BtlEventFactor *HAND_SIDE_AddFactor(u8 side, int effectId, BtlEffectCont cont);
u32 HAND_SIDE_GetStackCount(u32 side, u32 effectId);
int HAND_SIDE_IsActive(int side, int effectId);
int HAND_SIDE_Remove(u32 side, u32 effectId);
void HAND_SIDE_TickTurns(void (*onExpired)(u8 side, u32 effectId, void *arg), void *arg);
int HAND_SIDE_GetStackCountByFactor(struct BtlEventFactor *factor, u32 side);
const BtlEventHandler *HAND_SIDE_GetHandlersReflect(u32 *handlerCount);
void HAND_SIDE_ReflectOnDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int side, void *work);
const BtlEventHandler *HAND_SIDE_GetHandlersLightScreen(u32 *handlerCount);
void HAND_SIDE_LightScreenOnDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int side, void *work);
void HAND_SIDE_ScreenReduceDamage(struct BtlServerFlow *flow, int side, int damageType);
const BtlEventHandler *HAND_SIDE_GetHandlersSafeguard(u32 *handlerCount);
void HAND_SIDE_SafeguardBlockSick(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int side, int *work);
void HAND_SIDE_SafeguardNoticeBlocked(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int side, int *work);
const BtlEventHandler *HAND_SIDE_GetHandlersMist(u32 *handlerCount);
void HAND_SIDE_MistBlockStatDrop(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int side, int *work);
void HAND_SIDE_MistNoticeStatDrop(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int side, int *work);
const BtlEventHandler *HAND_SIDE_GetHandlersTailwind(u32 *handlerCount);
void HAND_SIDE_TailwindDoubleSpeed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int side, int *work);
const BtlEventHandler *HAND_SIDE_GetHandlersLuckyChant(u32 *handlerCount);
void HAND_SIDE_LuckyChantBlockCritical(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int side, int *work);
const BtlEventHandler *HAND_SIDE_GetHandlersStealthRock(u32 *handlerCount);
void HAND_SIDE_StealthRockHurtOnEnter(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int side, int *work);
const BtlEventHandler *HAND_SIDE_GetHandlersWideGuard(u32 *handlerCount);
void HAND_SIDE_WideGuardBlockSpreadMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int side, int *work);
const BtlEventHandler *HAND_SIDE_GetHandlersQuickGuard(u32 *handlerCount);
void HAND_SIDE_QuickGuardBlockPriorityMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int side, int *work);
const BtlEventHandler *HAND_SIDE_GetHandlersSpikes(u32 *handlerCount);
void HAND_SIDE_SpikesHurtOnEnter(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int side, int *work);
const BtlEventHandler *HAND_SIDE_GetHandlersToxicSpikes(u32 *handlerCount);
void HAND_SIDE_ToxicSpikesOnEnter(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int side, int *work);
const BtlEventHandler *HAND_SIDE_GetHandlersRainbow(u32 *handlerCount);
void HAND_SIDE_RainbowDoubleEffectChance(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int side, int *work);
void HAND_SIDE_RainbowForceCriticalFlag(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int side, int *work);
const BtlEventHandler *HAND_SIDE_GetHandlersSeaOfFire(u32 *handlerCount);
void HAND_SIDE_SeaOfFireHurt(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int side, int *work);
const BtlEventHandler *HAND_SIDE_GetHandlersSwamp(u32 *handlerCount);
void HAND_SIDE_SwampQuarterSpeed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int side, int *work);
/* END mkheaders: generated region */

#endif
