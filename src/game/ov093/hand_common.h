#ifndef GAME_OV093_HAND_COMMON_H
#define GAME_OV093_HAND_COMMON_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of hand_common.c, prototypes copied from their definitions. */

struct BtlServerFlow;
struct BtlEventFactor;

int HAND_COMMON_IsMoveTarget(int pokeId);
int HAND_COMMON_IsLastToAct(struct BtlServerFlow *flow, int pokeId);
int HAND_COMMON_IsItemBoundToSpecies(int speciesId, int itemId);
int HAND_COMMON_IsHeldItemBoundToOwnSpecies(void *party, int slot);
int BTLV_CORE_CheckPartySlotCondition(void *party, int slot);
int BTLV_CORE_CheckEitherSlotPair(void *party, int slotA, int slotB);
void HAND_COMMON_EventRedirectMove(struct BtlEventFactor *unusedArg0, struct BtlServerFlow *eventCtx, int pokeId, int unusedArg1);
void HAND_COMMON_EventCounterMove(struct BtlEventFactor *unusedArg0, struct BtlServerFlow *eventCtx, int pokeId, int unusedArg1);
void HAND_COMMON_EventQueueMoveNotice(struct BtlEventFactor *unusedArg0, struct BtlServerFlow *eventCtx, int pokeId, int unusedArg1);
void HAND_COMMON_EventScaleDamage(int factor);
void HAND_COMMON_EventSetFlagIfAttacker(int unusedArg0, int unusedArg1, int pokeId, int unusedArg2);
int HAND_COMMON_EventTrySetFlagIfAttacker(struct BtlEventFactor *unusedArg0, struct BtlServerFlow *unusedArg1, int pokeId);
/* END mkheaders: generated region */

#endif
