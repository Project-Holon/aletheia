#ifndef GAME_OV093_BTL_EVENT_H
#define GAME_OV093_BTL_EVENT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of btl_event.c, prototypes copied from their definitions. */

struct BtlEventFactor;
struct BtlServerFlow;
struct BtlEventVarStack;

#include "../types.h"
#include "../ov093/btl_event_types.h"

void BTL_EVENT_InitFactorList(void);
void BTL_EVENT_ClearSuspendedFlags(void);
void BTL_EVENT_DebugPrintFactorList(void);
struct BtlEventFactor *BTL_EVENT_AddFactor(int factorType, u32 key, int priority, u32 subPriority, u8 ownerId, u32 handlers, u16 handlerCount);
void BTL_EVENT_RemoveDeadFactors(void);
void BTL_EVENT_RemoveFactor(struct BtlEventFactor *factor);
void BTL_EVENT_MarkFactorDead(struct BtlEventFactor *factor);
int BTL_EVENT_IsFactorDead(struct BtlEventFactor *factor);
u16 BTL_EVENT_GetFactorKey(struct BtlEventFactor *factor);
u8 BTL_EVENT_GetFactorPokeId(struct BtlEventFactor *factor);
u32 BTL_EVENT_GetFactorWork(struct BtlEventFactor *factor, int index);
void BTL_EVENT_EnableFactorSpecialEvent(struct BtlEventFactor *factor);
void BTL_EVENT_KeepFactorRunning(struct BtlEventFactor *factor);
void BTL_EVENT_SetFactorWork(struct BtlEventFactor *factor, int index, u32 value);
void BTL_EVENT_DispatchEvent(struct BtlServerFlow *context, int eventId);
void BTL_EVENT_DispatchEventChecked(struct BtlServerFlow *context, int eventId);
void BTL_EVENT_DispatchEventToType(struct BtlServerFlow *context, int eventId, int factorType);
void BTL_EVENT_DispatchEventNested(struct BtlServerFlow *context, int eventId, int factorType, int checkSkip);
void BTL_EVENT_DispatchToFactors(struct BtlServerFlow *context, int eventId, int factorType, int checkSkip);
int BTL_EVENT_IsEventBlocked(struct BtlServerFlow *context, struct BtlEventFactor *target, int eventId);
void BTL_EVENT_SetFactorSkipCheck(struct BtlEventFactor *factor, BtlEventSkipCheck skipCheck);
void BTL_EVENT_ClearFactorSkipCheck(struct BtlEventFactor *factor);
struct BtlEventFactor *BTL_EVENT_FindFactor(int factorType, int ownerId);
struct BtlEventFactor *BTL_EVENT_FindNextFactor(struct BtlEventFactor *factor);
void BTL_EVENT_SuspendPokeFactors(int pokeId);
void BTL_EVENT_ResumePokeFactors(int pokeId);
void BTL_EVENT_DisablePokeFactors(u32 pokeId, int factorType);
int BTL_EVENT_EnablePokeFactors(int pokeId, int factorType);
struct BtlEventFactor *BTL_EVENT_AllocFactor(void);
void BTL_EVENT_FreeFactor(void *factor);
void BTL_EVENT_ClearFactor(int factor);
void BTL_EVENT_ResetVarStack(void);
void BTL_EVENT_ResetVarStackIfUsed(void);
void BTL_EVENT_PushVarFrame(int line);
void BTL_EVENT_PopVarFrame(int line);
void BTL_EVENT_SetVar(int key, u32 value);
void BTL_EVENT_SetVarReadOnly(int key, u32 value);
void BTL_EVENT_SetVarOnce(int key, u32 value);
void BTL_EVENT_SetVarRanged(int key, u32 value, u32 minValue, u32 maxValue);
int BTL_EVENT_OverwriteVar(int key, u32 value);
void BTL_EVENT_MultiplyVar(int key, s32 multiplier);
int BTL_EVENT_GetVar(int key);
int BTL_EVENT_TryGetVar(int key, int *out);
u32 BTL_EVENT_FindVarSlot(struct BtlEventVarStack *stack, int key);
int BTL_EVENT_FindVar(struct BtlEventVarStack *stack, int key);
int BTL_EVENT_ClampVar(struct BtlEventVarStack *stack, int index, int value);
/* END mkheaders: generated region */

#endif
