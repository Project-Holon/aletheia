/*
 * file:     btl_event.c
 * unit:     yes
 * function: BTL_EVENT_InitFactorList, BTL_EVENT_ClearSuspendedFlags, BTL_EVENT_DebugPrintFactorList, BTL_EVENT_AddFactor, BTL_EVENT_RemoveDeadFactors, BTL_EVENT_RemoveFactor, BTL_EVENT_MarkFactorDead, BTL_EVENT_IsFactorDead, BTL_EVENT_GetFactorKey, BTL_EVENT_GetFactorPokeId, BTL_EVENT_GetFactorWork, BTL_EVENT_EnableFactorSpecialEvent, BTL_EVENT_KeepFactorRunning, BTL_EVENT_SetFactorWork, BTL_EVENT_DispatchEvent, BTL_EVENT_DispatchEventChecked, BTL_EVENT_DispatchEventToType, BTL_EVENT_DispatchEventNested, BTL_EVENT_DispatchToFactors, BTL_EVENT_IsEventBlocked, BTL_EVENT_SetFactorSkipCheck, BTL_EVENT_ClearFactorSkipCheck, BTL_EVENT_FindFactor, BTL_EVENT_FindNextFactor, BTL_EVENT_SuspendPokeFactors, BTL_EVENT_ResumePokeFactors, BTL_EVENT_DisablePokeFactors, BTL_EVENT_EnablePokeFactors, BTL_EVENT_AllocFactor, BTL_EVENT_FreeFactor, BTL_EVENT_ClearFactor, BTL_EVENT_ResetVarStack, BTL_EVENT_ResetVarStackIfUsed, BTL_EVENT_PushVarFrame, BTL_EVENT_PopVarFrame, BTL_EVENT_SetVar, BTL_EVENT_SetVarReadOnly, BTL_EVENT_SetVarOnce, BTL_EVENT_SetVarRanged, BTL_EVENT_OverwriteVar, BTL_EVENT_MultiplyVar, BTL_EVENT_GetVar, BTL_EVENT_TryGetVar, BTL_EVENT_FindVarSlot, BTL_EVENT_FindVar, BTL_EVENT_ClampVar
 * address:  0x021D6EAC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Battle event system: the event factor list (abilities, items and field effects
 * that react to battle events), the event variable stack and the dispatcher.
 *
 * symbols:
 *   gBtlEventFactorStorage  0x021F4470  data  a4
 *   gBtlEventFactorFreePool  0x021F3CBC  data  a4
 *   gBtlEventFactorList  0x021F3CB0  data  a4
 *   MI_CpuFill8    0x02082BCC  arm
 *   BTL_SERVER_FLOW_GetPokeParam 0x021C7CF4 thumb ov093
 *   BTL_POKEPARAM_HasSick 0x021D62C4 thumb ov093
 *   BTL_POKEPARAM_TestTurnFlag 0x021D5BB0 thumb ov093
 *   BTL_FIELD_IsStaticSlotInUse 0x021EF948 thumb ov093
 *   HAND_WAZA_IsKeptOnSuspend  0x021E03E8  thumb  ov093
 *   gBtlEventVarStack 0x021F3ECC data a4
 *   gBtlEventEmptyString  0x021F3AB4  data
 *   GF_PANIC_Fail  0x02034714  arm
 */
#include "btl_event_types.h"

#include "../types.h"

#include "../arm9/mi_memory.h"
#include "btl_server_flow.h"
struct BtlPokeParam;
#include "btl_server_types.h"
#include "btl_pokeparam.h"
#include "btl_field.h"
struct BtlEventFactor;
#include "hand_waza.h"
#include "../arm9/gf_panic.h"
#include "btl_event.h"
extern struct BtlEventFactor gBtlEventFactorStorage[BTL_EVENT_FACTOR_MAX];
extern struct BtlEventFactorList gBtlEventFactorList;
/* stand-in: the same object as gBtlEventFactorList.freePool (gBtlEventFactorList + 0xC); the original reaches it through its own symbol, a field access changes the bytes of BTL_EVENT_InitFactorList. */
extern struct BtlEventFactor *gBtlEventFactorFreePool[BTL_EVENT_FACTOR_MAX];
extern struct BtlEventVarStack gBtlEventVarStack;
extern char gBtlEventEmptyString[];

void BTL_EVENT_InitFactorList(void)
{
    u32 i;
    for (i = 0; i < BTL_EVENT_FACTOR_MAX; i++) {
        struct BtlEventFactor *factor = &gBtlEventFactorStorage[i];
        BTL_EVENT_ClearFactor((sptr)factor);
        gBtlEventFactorFreePool[i] = factor;
    }
    gBtlEventFactorList.head = 0;
    gBtlEventFactorList.usedCount = 0;
    gBtlEventFactorList.dispatchDepth = 0;
    BTL_EVENT_ResetVarStack();
}

void BTL_EVENT_ClearSuspendedFlags(void)
{
    struct BtlEventFactor *factor;
    for (factor = gBtlEventFactorList.head; factor != 0; factor = factor->next) factor->suspended = 0;
}

void BTL_EVENT_DebugPrintFactorList(void)
{
}

struct BtlEventFactor *BTL_EVENT_AddFactor(int factorType, u32 key, int priority, u32 subPriority, u8 ownerId, u32 handlers, u16 handlerCount)
{
    struct BtlEventFactor *factor = BTL_EVENT_AllocFactor();
    struct BtlEventFactor *cur;
    struct BtlEventFactor *prev;
    int hasPoke;

    if (factor != 0) {
        factor->priority = ((7 - priority) << 24) | subPriority;
        factor->factorType = factorType;
        factor->prev = 0;
        factor->next = 0;
        factor->handlers = (BtlEventHandler *)handlers;
        factor->handlerCount = handlerCount;
        factor->key = key;
        factor->running = 0;
        factor->suspended = 0;
        factor->disabled = 0;
        factor->answersSpecial = 0;
        factor->skipCheck = 0;
        factor->ownerId = ownerId;
        factor->removePending = 0;
        factor->keepRunning = 0;
        factor->addDepth = gBtlEventFactorList.dispatchDepth;
        factor->active = 1;
        hasPoke = 0;
        if (factorType == 0 || factorType == 4 || factorType == 5) hasPoke = 1;
        factor->pokeId = hasPoke ? ownerId : BTL_EVENT_NO_POKE;
        MI_CpuFill8(factor->work, 0, sizeof(factor->work));

        prev = gBtlEventFactorList.head;
        if (prev == 0) {
            gBtlEventFactorList.head = factor;
        } else if (factor->priority > prev->priority) {
            prev->prev = factor;
            factor->next = gBtlEventFactorList.head;
            factor->prev = 0;
            gBtlEventFactorList.head = factor;
        } else {
            for (cur = prev->next; cur != 0; prev = cur, cur = cur->next) {
                if (factor->priority > cur->priority) {
                    factor->next = cur;
                    factor->prev = cur->prev;
                    cur->prev->next = factor;
                    cur->prev = factor;
                    break;
                }
            }
            if (cur == 0) {
                prev->next = factor;
                factor->prev = prev;
            }
        }
        BTL_EVENT_DebugPrintFactorList();
        return factor;
    }
    return 0;
}

void BTL_EVENT_RemoveDeadFactors(void)
{
    struct BtlEventFactor *factor;
    struct BtlEventFactor *next;
    for (factor = gBtlEventFactorList.head; factor != 0; factor = next) {
        next = factor->next;
        if (factor->factorType == BTL_EVENT_TYPE_DEAD) BTL_EVENT_RemoveFactor(factor);
    }
}

void BTL_EVENT_RemoveFactor(struct BtlEventFactor *factor)
{
    if (factor != 0) {
        if (factor->active) {
            if (factor->running) {
                factor->removePending = 1;
                return;
            }
            if (factor == gBtlEventFactorList.head)
                gBtlEventFactorList.head = factor->next;
            if (factor->prev != 0)
                factor->prev->next = factor->next;
            if (factor->next != 0)
                factor->next->prev = factor->prev;
            BTL_EVENT_DebugPrintFactorList();
            BTL_EVENT_FreeFactor(factor);
        }
    }
}

void BTL_EVENT_MarkFactorDead(struct BtlEventFactor *factor)
{
    factor->factorType = BTL_EVENT_TYPE_DEAD;
}

int BTL_EVENT_IsFactorDead(struct BtlEventFactor *factor)
{
    if (factor->factorType == BTL_EVENT_TYPE_DEAD) return 1;
    return 0;
}

u16 BTL_EVENT_GetFactorKey(struct BtlEventFactor *factor) { return factor->key; }

u8 BTL_EVENT_GetFactorPokeId(struct BtlEventFactor *factor)
{
    return factor->pokeId;
}

u32 BTL_EVENT_GetFactorWork(struct BtlEventFactor *factor, int index) { return factor->work[index]; }

void BTL_EVENT_EnableFactorSpecialEvent(struct BtlEventFactor *factor) { factor->answersSpecial = 1; }

void BTL_EVENT_KeepFactorRunning(struct BtlEventFactor *factor)
{
    if (factor->running) factor->keepRunning = 1;
}

void BTL_EVENT_SetFactorWork(struct BtlEventFactor *factor, int index, u32 value) { factor->work[index] = value; }

void BTL_EVENT_DispatchEvent(struct BtlServerFlow *context, int eventId)
{
    BTL_EVENT_DispatchEventNested(context, eventId, BTL_EVENT_TYPE_ANY, 0);
}

void BTL_EVENT_DispatchEventChecked(struct BtlServerFlow *context, int eventId)
{
    BTL_EVENT_DispatchEventNested(context, eventId, BTL_EVENT_TYPE_ANY, 1);
}

void BTL_EVENT_DispatchEventToType(struct BtlServerFlow *context, int eventId, int factorType)
{
    BTL_EVENT_DispatchEventNested(context, eventId, factorType, 1);
}

void BTL_EVENT_DispatchEventNested(struct BtlServerFlow *context, int eventId, int factorType, int checkSkip)
{
    struct BtlEventFactor *factor;
    gBtlEventFactorList.dispatchDepth++;
    BTL_EVENT_DispatchToFactors(context, eventId, factorType, checkSkip);
    if (--gBtlEventFactorList.dispatchDepth == 0) {
        for (factor = gBtlEventFactorList.head; factor != 0; factor = factor->next) factor->addDepth = 0;
    }
}

void BTL_EVENT_DispatchToFactors(struct BtlServerFlow *context, int eventId, int factorType, int checkSkip)
{
    struct BtlEventFactor *factor;
    struct BtlEventFactor *next;
    BtlEventHandler *handler;
    const BtlEventHandler *handlers;
    u32 i;
    int count;
    int typeMismatch;
    u32 ownerId;
    for (factor = gBtlEventFactorList.head; factor != 0; ) {
        next = factor->next;
        if (factor->running && !factor->keepRunning) goto advance;
        if (factor->suspended || factor->disabled) goto advance;
        typeMismatch = (factorType != BTL_EVENT_TYPE_ANY) && (factor->factorType != factorType);
        if (typeMismatch) goto advance;
        if (factor->addDepth != 0 && factor->addDepth >= gBtlEventFactorList.dispatchDepth) goto advance;
        if (!factor->active) goto advance;
        if (eventId == 0x73 && !factor->answersSpecial) goto advance;
        count = factor->handlerCount;
        handlers = factor->handlers;
        i = 0;
        for (; i < count; i++) {
            handler = (BtlEventHandler *)&handlers[i];
            if (eventId != handler->eventId) continue;
            if (checkSkip && BTL_EVENT_IsEventBlocked(context, factor, eventId)) break;
            factor->running = 1;
            ownerId = factor->ownerId;
            handler->handler(factor, context, ownerId, factor->work);
            if (factor->keepRunning) factor->keepRunning = 0;
            else factor->running = 0;
            if (factor->removePending) {
                if (next != 0 && !next->active) next = factor->next;
                BTL_EVENT_RemoveFactor(factor);
            }
            break;
        }
advance:
        if (next == 0) break;
        if (next->active) factor = next;
        else factor = factor->next;
    }
}

int BTL_EVENT_IsEventBlocked(struct BtlServerFlow *context, struct BtlEventFactor *target, int eventId)
{
    void *poke = 0;
    struct BtlEventFactor *factor;
    if (target->pokeId != BTL_EVENT_NO_POKE) poke = BTL_SERVER_FLOW_GetPokeParam(context, target->pokeId);
    if (target->factorType == 4 && poke != 0 && BTL_POKEPARAM_HasSick(poke, 0x10)) return 1;
    if (target->factorType == 5) {
        if (BTL_FIELD_IsStaticSlotInUse(7)) return 1;
        if (poke != 0 && BTL_POKEPARAM_HasSick(poke, 0x13)) return 1;
        if (poke != 0 && BTL_POKEPARAM_TestTurnFlag(poke, 9)) return 1;
    }
    for (factor = gBtlEventFactorList.head; factor != 0; factor = factor->next) {
        if (factor->skipCheck == 0) continue;
        if (factor->factorType == 4) {
            poke = BTL_SERVER_FLOW_GetPokeParam(context, factor->pokeId);
            if (poke != 0 && BTL_POKEPARAM_HasSick(poke, 0x10)) continue;
        }
        if (factor->disabled) continue;
        if (factor->skipCheck(factor, context, target->factorType, eventId, target->key, target->ownerId)) return 1;
    }
    return 0;
}

void BTL_EVENT_SetFactorSkipCheck(struct BtlEventFactor *factor, BtlEventSkipCheck skipCheck) { factor->skipCheck = skipCheck; }

void BTL_EVENT_ClearFactorSkipCheck(struct BtlEventFactor *factor)
{
    factor->skipCheck = 0;
}

struct BtlEventFactor *BTL_EVENT_FindFactor(int factorType, int ownerId)
{
    struct BtlEventFactor *factor;
    for (factor = gBtlEventFactorList.head; factor != 0; factor = factor->next) {
        if (factor->factorType == factorType && factor->ownerId == ownerId && !factor->removePending) return factor;
    }
    return 0;
}

struct BtlEventFactor *BTL_EVENT_FindNextFactor(struct BtlEventFactor *factor)
{
    int factorType;
    u8 ownerId;
    if (factor != 0) {
        factorType = factor->factorType;
        ownerId = factor->ownerId;
        for (factor = factor->next; factor != 0; factor = factor->next) {
            if (factor->factorType == factorType && factor->ownerId == ownerId && !factor->removePending) return factor;
        }
    }
    return 0;
}

void BTL_EVENT_SuspendPokeFactors(int pokeId)
{
    struct BtlEventFactor *factor;
    for (factor = gBtlEventFactorList.head; factor != 0; factor = factor->next) {
        if (factor->factorType == 0 && factor->pokeId == pokeId && HAND_WAZA_IsKeptOnSuspend(factor, factor->work) != 0) factor->suspended = 1;
    }
}

void BTL_EVENT_ResumePokeFactors(int pokeId)
{
    struct BtlEventFactor *factor;
    for (factor = gBtlEventFactorList.head; factor != 0; factor = factor->next) {
        if (factor->factorType == 0 && factor->pokeId == pokeId) factor->suspended = 0;
    }
}

void BTL_EVENT_DisablePokeFactors(u32 pokeId, int factorType)
{
    struct BtlEventFactor *factor;
    for (factor = gBtlEventFactorList.head; factor != 0; factor = factor->next) {
        if (factor->pokeId == pokeId && factor->factorType == factorType) factor->disabled = 1;
    }
}

int BTL_EVENT_EnablePokeFactors(int pokeId, int factorType) { struct BtlEventFactor *factor; int found=0; for(factor=gBtlEventFactorList.head; factor; factor=factor->next) { if(factor->pokeId==pokeId && factor->factorType==factorType) { factor->disabled=0; found=1; } } return found; }

struct BtlEventFactor *BTL_EVENT_AllocFactor(void)
{
    u32 i;
    if (gBtlEventFactorList.usedCount == BTL_EVENT_FACTOR_MAX) return 0;
    i = gBtlEventFactorList.usedCount++;
    return gBtlEventFactorList.freePool[i];
}

void BTL_EVENT_FreeFactor(void *factor) { if (gBtlEventFactorList.usedCount) { BTL_EVENT_ClearFactor((sptr)factor); gBtlEventFactorList.freePool[--gBtlEventFactorList.usedCount] = factor; } }

void BTL_EVENT_ClearFactor(int factor)
{
    MI_CpuFill8((void *)factor, 0, 0x3c);
}

void BTL_EVENT_ResetVarStack(void) { struct BtlEventVarStack *stack = &gBtlEventVarStack; unsigned int i; stack->frameTop = 0; for (i = 0; i < BTL_EVENT_VAR_MAX; i++) stack->keys[i] = 0; }

void BTL_EVENT_ResetVarStackIfUsed(void)
{
    if (gBtlEventVarStack.frameTop != 0)
        BTL_EVENT_ResetVarStack();
}

void BTL_EVENT_PushVarFrame(int line)
{
    struct BtlEventVarStack *stack = &gBtlEventVarStack;
    while (stack->frameTop < BTL_EVENT_VAR_MAX) {
        if (stack->keys[stack->frameTop] == 0) break;
        stack->frameTop++;
    }
    if (stack->frameTop < BTL_EVENT_VAR_MAX - 1) {
        stack->keys[stack->frameTop++] = 1;
    } else {
        GF_PANIC_Fail(gBtlEventEmptyString, 0, gBtlEventEmptyString);
    }
}

void BTL_EVENT_PopVarFrame(int line)
{
    struct BtlEventVarStack *stack = &gBtlEventVarStack;
    u16 i;
    if (stack->frameTop != 0) {
        i = stack->frameTop;
        while (i < BTL_EVENT_VAR_MAX && stack->keys[i] != 0) {
            stack->keys[i++] = 0;
        }
        stack->frameTop--;
        stack->keys[stack->frameTop] = 0;
        if (stack->frameTop != 0) {
            while (stack->frameTop != 0) {
                stack->frameTop--;
                if (stack->keys[stack->frameTop] == 1) {
                    stack->frameTop++;
                    return;
                }
            }
        }
    }
}

void BTL_EVENT_SetVar(int key, u32 value)
{
    u32 i = BTL_EVENT_FindVarSlot(&gBtlEventVarStack, key);
    gBtlEventVarStack.keys[i] = key;
    gBtlEventVarStack.values[i] = value;
    gBtlEventVarStack.minValues[i] = 0;
    gBtlEventVarStack.maxValues[i] = 0;
    gBtlEventVarStack.modes[i] = 0;
}

void BTL_EVENT_SetVarReadOnly(int key, u32 value)
{
    u32 i = BTL_EVENT_FindVarSlot(&gBtlEventVarStack, key);
    gBtlEventVarStack.keys[i] = key;
    gBtlEventVarStack.values[i] = value;
    gBtlEventVarStack.minValues[i] = 0;
    gBtlEventVarStack.maxValues[i] = 0;
    gBtlEventVarStack.modes[i] = 4;
}

void BTL_EVENT_SetVarOnce(int key, u32 value)
{
    u32 i = BTL_EVENT_FindVarSlot(&gBtlEventVarStack, key);
    gBtlEventVarStack.keys[i] = key;
    gBtlEventVarStack.values[i] = value;
    gBtlEventVarStack.minValues[i] = 0;
    gBtlEventVarStack.maxValues[i] = 0;
    gBtlEventVarStack.modes[i] = 1;
}

void BTL_EVENT_SetVarRanged(int key, u32 value, u32 minValue, u32 maxValue)
{
    u32 i = BTL_EVENT_FindVarSlot(&gBtlEventVarStack, key);
    gBtlEventVarStack.keys[i] = key;
    gBtlEventVarStack.values[i] = value;
    gBtlEventVarStack.minValues[i] = minValue;
    gBtlEventVarStack.maxValues[i] = maxValue;
    gBtlEventVarStack.modes[i] = 3;
}

int BTL_EVENT_OverwriteVar(int key, u32 value)
{
    struct BtlEventVarStack *stack = &gBtlEventVarStack;
    int i = BTL_EVENT_FindVar(stack, key);

    if (i >= 0 && stack->modes[i] <= 1) {
        stack->keys[i] = key;
        stack->values[i] = value;
        if (stack->modes[i] == 1)
            stack->modes[i] = 2;
        return 1;
    }
    return 0;
}

void BTL_EVENT_MultiplyVar(int key, s32 multiplier)
{
    struct BtlEventVarStack *stack = &gBtlEventVarStack;
    int i = BTL_EVENT_FindVar(stack, key);

    if (i >= 0 && stack->modes[i] == 3) {
        s32 value = stack->values[i];
        s64 product = (s64)value * (s64)multiplier;
        stack->values[i] = BTL_EVENT_ClampVar(stack, i, (s32)((product + 0x800) >> 12));
    }
}

int BTL_EVENT_GetVar(int key)
{
    struct BtlEventVarStack *stack = &gBtlEventVarStack;
    u32 i;

    i = stack->frameTop;
    if (i < BTL_EVENT_VAR_MAX) {
        for (;;) {
            if (stack->keys[i] == key)
                return stack->values[i];
            if (stack->keys[i] == 0)
                break;
            if (++i >= BTL_EVENT_VAR_MAX)
                break;
        }
    }
    return 0;
}

int BTL_EVENT_TryGetVar(int key, int *out) { struct BtlEventVarStack *stack = &gBtlEventVarStack; unsigned int i; for(i=stack->frameTop; i<BTL_EVENT_VAR_MAX; i++) { if(key==stack->keys[i]) { *out=stack->values[i]; return 1; } if(stack->keys[i]==0) break; } return 0; }

u32 BTL_EVENT_FindVarSlot(struct BtlEventVarStack *stack, int key)
{
    u32 i;
    for (i = stack->frameTop; i < BTL_EVENT_VAR_MAX; i++) {
        if (stack->keys[i] == 0) break;
        if (key == stack->keys[i]) break;
    }
    if (i >= BTL_EVENT_VAR_MAX) i = 0;
    return i;
}

int BTL_EVENT_FindVar(struct BtlEventVarStack *stack, int key) { unsigned int i; for (i=stack->frameTop; i<BTL_EVENT_VAR_MAX && stack->keys[i]!=0; i++) { if(key==stack->keys[i]) return i; } return -1; }

int BTL_EVENT_ClampVar(struct BtlEventVarStack *stack, int index, int value) { int maxValue = stack->maxValues[index]; if (maxValue || stack->minValues[index]) { if ((int)stack->minValues[index] > value) value = stack->minValues[index]; if (maxValue < value) value=maxValue; } return value; }
