/*
 * file:     btl_event.c
 * unit:     yes
 * function: func_021D6EAC, func_021D6EE8, func_021D6F08, func_021D6F0C, func_021D701C, func_021D7040, func_021D7090, func_021D7098, func_021D70A8, func_021D70AC, func_021D70B4, func_021D70BC, func_021D70C8, func_021D70DC, func_021D70E4, func_021D70F0, func_021D70FC, func_021D7108, func_021D713C, func_021D7240, func_021D7320, func_021D7324, func_021D732C, func_021D7360, func_021D7394, func_021D73D4, func_021D7404, func_021D7438, func_021D7474, func_021D7494, func_021D74BC, func_021D74C8, func_021D74E4, func_021D74F8, func_021D7540, func_021D75A8, func_021D75EC, func_021D7630, func_021D7674, func_021D76BC, func_021D7704, func_021D775C, func_021D778C, func_021D77C4, func_021D77E8, func_021D780C
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
 *   d_021F4470  0x021F4470  data  a4
 *   d_021F3CBC  0x021F3CBC  data  a4
 *   g_021F3CB0  0x021F3CB0  data  a4
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021D5BB0 0x021D5BB0 thumb ov093
 *   func_021EF948 0x021EF948 thumb ov093
 *   func_021E03E8  0x021E03E8  thumb  ov093
 *   func_02082BCC  0x02082BCC  arm
 *   g_021F3ECC 0x021F3ECC data a4
 *   data_021F3AB4  0x021F3AB4  data
 *   func_02034714  0x02034714  arm
 */
#include "btl_event_types.h"

typedef signed long long s64;

extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern void *func_021C7CF4(void *context, int pokeId);
extern int func_021D62C4(void *poke, int condition);
extern int func_021D5BB0(void *poke, u32 condition);
extern int func_021EF948(int);
extern int func_021E03E8(void *factor, u32 *work);
void func_02082BCC(int, int, int);
extern void func_02034714(const char *expr, u32 line, const char *file);
void func_021D6EAC(void);
void func_021D6EE8(void);
void func_021D6F08(void);
struct BtlEventFactor *func_021D6F0C(int factorType, u32 key, int priority, u32 subPriority, u8 ownerId, u32 handlers, u16 handlerCount);
void func_021D701C(void);
void func_021D7040(struct BtlEventFactor *factor);
void func_021D7090(struct BtlEventFactor *factor);
int func_021D7098(struct BtlEventFactor *factor);
u16 func_021D70A8(struct BtlEventFactor *factor);
u8 func_021D70AC(struct BtlEventFactor *factor);
u32 func_021D70B4(struct BtlEventFactor *factor, int index);
void func_021D70BC(struct BtlEventFactor *factor);
void func_021D70C8(struct BtlEventFactor *factor);
void func_021D70DC(struct BtlEventFactor *factor, int index, u32 value);
void func_021D70E4(void *context, int eventId);
void func_021D70F0(void *context, int eventId);
void func_021D70FC(int context, int eventId, int factorType);
void func_021D7108(void *context, int eventId, int factorType, int checkSkip);
void func_021D713C(void *context, int eventId, int factorType, int checkSkip);
int func_021D7240(void *context, struct BtlEventFactor *target, int eventId);
void func_021D7320(struct BtlEventFactor *factor, BtlEventSkipCheck skipCheck);
void func_021D7324(struct BtlEventFactor *factor);
struct BtlEventFactor *func_021D732C(int factorType, int ownerId);
struct BtlEventFactor *func_021D7360(struct BtlEventFactor *factor);
void func_021D7394(int pokeId);
void func_021D73D4(int pokeId);
void func_021D7404(u32 pokeId, int factorType);
int func_021D7438(int pokeId, int factorType);
struct BtlEventFactor *func_021D7474(void);
void func_021D7494(void *factor);
void func_021D74BC(int factor);
void func_021D74C8(void);
void func_021D74E4(void);
void func_021D74F8(int line);
void func_021D7540(int line);
void func_021D75A8(int key, u32 value);
void func_021D75EC(int key, u32 value);
void func_021D7630(int key, u32 value);
void func_021D7674(int key, u32 value, u32 minValue, u32 maxValue);
int func_021D76BC(int key, u32 value);
void func_021D7704(int key, s32 multiplier);
int func_021D775C(int key);
int func_021D778C(int key, int *out);
u32 func_021D77C4(struct BtlEventVarStack *stack, int key);
int func_021D77E8(struct BtlEventVarStack *stack, int key);
int func_021D780C(struct BtlEventVarStack *stack, int index, int value);
extern struct BtlEventFactor d_021F4470[BTL_EVENT_FACTOR_MAX];
extern struct BtlEventFactorList g_021F3CB0;
/* stand-in: the same object as g_021F3CB0.freePool (g_021F3CB0 + 0xC); the original reaches it through its own symbol, a field access changes the bytes of func_021D6EAC. */
extern struct BtlEventFactor *d_021F3CBC[BTL_EVENT_FACTOR_MAX];
extern struct BtlEventVarStack g_021F3ECC;
extern char data_021F3AB4[];


void func_021D6EAC(void)
{
    u32 i;
    for (i = 0; i < BTL_EVENT_FACTOR_MAX; i++) {
        struct BtlEventFactor *factor = &d_021F4470[i];
        func_021D74BC((int)factor);
        d_021F3CBC[i] = factor;
    }
    g_021F3CB0.head = 0;
    g_021F3CB0.usedCount = 0;
    g_021F3CB0.dispatchDepth = 0;
    func_021D74C8();
}

void func_021D6EE8(void)
{
    struct BtlEventFactor *factor;
    for (factor = g_021F3CB0.head; factor != 0; factor = factor->next) factor->suspended = 0;
}


void func_021D6F08(void)
{
}


struct BtlEventFactor *func_021D6F0C(int factorType, u32 key, int priority, u32 subPriority, u8 ownerId, u32 handlers, u16 handlerCount)
{
    struct BtlEventFactor *factor = func_021D7474();
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
        factor->addDepth = g_021F3CB0.dispatchDepth;
        factor->active = 1;
        hasPoke = 0;
        if (factorType == 0 || factorType == 4 || factorType == 5) hasPoke = 1;
        factor->pokeId = hasPoke ? ownerId : BTL_EVENT_NO_POKE;
        MI_CpuFill8(factor->work, 0, sizeof(factor->work));

        prev = g_021F3CB0.head;
        if (prev == 0) {
            g_021F3CB0.head = factor;
        } else if (factor->priority > prev->priority) {
            prev->prev = factor;
            factor->next = g_021F3CB0.head;
            factor->prev = 0;
            g_021F3CB0.head = factor;
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
        func_021D6F08();
        return factor;
    }
    return 0;
}

void func_021D701C(void)
{
    struct BtlEventFactor *factor;
    struct BtlEventFactor *next;
    for (factor = g_021F3CB0.head; factor != 0; factor = next) {
        next = factor->next;
        if (factor->factorType == BTL_EVENT_TYPE_DEAD) func_021D7040(factor);
    }
}


void func_021D7040(struct BtlEventFactor *factor)
{
    if (factor != 0) {
        if (factor->active) {
            if (factor->running) {
                factor->removePending = 1;
                return;
            }
            if (factor == g_021F3CB0.head)
                g_021F3CB0.head = factor->next;
            if (factor->prev != 0)
                factor->prev->next = factor->next;
            if (factor->next != 0)
                factor->next->prev = factor->prev;
            func_021D6F08();
            func_021D7494(factor);
        }
    }
}


void func_021D7090(struct BtlEventFactor *factor)
{
    factor->factorType = BTL_EVENT_TYPE_DEAD;
}


int func_021D7098(struct BtlEventFactor *factor)
{
    if (factor->factorType == BTL_EVENT_TYPE_DEAD) return 1;
    return 0;
}


u16 func_021D70A8(struct BtlEventFactor *factor) { return factor->key; }


u8 func_021D70AC(struct BtlEventFactor *factor)
{
    return factor->pokeId;
}


u32 func_021D70B4(struct BtlEventFactor *factor, int index) { return factor->work[index]; }


void func_021D70BC(struct BtlEventFactor *factor) { factor->answersSpecial = 1; }


void func_021D70C8(struct BtlEventFactor *factor)
{
    if (factor->running) factor->keepRunning = 1;
}


void func_021D70DC(struct BtlEventFactor *factor, int index, u32 value) { factor->work[index] = value; }


void func_021D70E4(void *context, int eventId)
{
    func_021D7108(context, eventId, BTL_EVENT_TYPE_ANY, 0);
}


void func_021D70F0(void *context, int eventId)
{
    func_021D7108(context, eventId, BTL_EVENT_TYPE_ANY, 1);
}


void func_021D70FC(int context, int eventId, int factorType)
{
    func_021D7108((void *)context, eventId, factorType, 1);
}


void func_021D7108(void *context, int eventId, int factorType, int checkSkip)
{
    struct BtlEventFactor *factor;
    g_021F3CB0.dispatchDepth++;
    func_021D713C(context, eventId, factorType, checkSkip);
    if (--g_021F3CB0.dispatchDepth == 0) {
        for (factor = g_021F3CB0.head; factor != 0; factor = factor->next) factor->addDepth = 0;
    }
}

void func_021D713C(void *context, int eventId, int factorType, int checkSkip)
{
    struct BtlEventFactor *factor;
    struct BtlEventFactor *next;
    BtlEventHandler *handler;
    const BtlEventHandler *handlers;
    u32 i;
    int count;
    int typeMismatch;
    u32 ownerId;
    for (factor = g_021F3CB0.head; factor != 0; ) {
        next = factor->next;
        if (factor->running && !factor->keepRunning) goto advance;
        if (factor->suspended || factor->disabled) goto advance;
        typeMismatch = (factorType != BTL_EVENT_TYPE_ANY) && (factor->factorType != factorType);
        if (typeMismatch) goto advance;
        if (factor->addDepth != 0 && factor->addDepth >= g_021F3CB0.dispatchDepth) goto advance;
        if (!factor->active) goto advance;
        if (eventId == 0x73 && !factor->answersSpecial) goto advance;
        count = factor->handlerCount;
        handlers = factor->handlers;
        i = 0;
        for (; i < count; i++) {
            handler = (BtlEventHandler *)&handlers[i];
            if (eventId != handler->eventId) continue;
            if (checkSkip && func_021D7240(context, factor, eventId)) break;
            factor->running = 1;
            ownerId = factor->ownerId;
            handler->handler(factor, context, ownerId, factor->work);
            if (factor->keepRunning) factor->keepRunning = 0;
            else factor->running = 0;
            if (factor->removePending) {
                if (next != 0 && !next->active) next = factor->next;
                func_021D7040(factor);
            }
            break;
        }
advance:
        if (next == 0) break;
        if (next->active) factor = next;
        else factor = factor->next;
    }
}

int func_021D7240(void *context, struct BtlEventFactor *target, int eventId)
{
    void *poke = 0;
    struct BtlEventFactor *factor;
    if (target->pokeId != BTL_EVENT_NO_POKE) poke = func_021C7CF4(context, target->pokeId);
    if (target->factorType == 4 && poke != 0 && func_021D62C4(poke, 0x10)) return 1;
    if (target->factorType == 5) {
        if (func_021EF948(7)) return 1;
        if (poke != 0 && func_021D62C4(poke, 0x13)) return 1;
        if (poke != 0 && func_021D5BB0(poke, 9)) return 1;
    }
    for (factor = g_021F3CB0.head; factor != 0; factor = factor->next) {
        if (factor->skipCheck == 0) continue;
        if (factor->factorType == 4) {
            poke = func_021C7CF4(context, factor->pokeId);
            if (poke != 0 && func_021D62C4(poke, 0x10)) continue;
        }
        if (factor->disabled) continue;
        if (factor->skipCheck(factor, context, target->factorType, eventId, target->key, target->ownerId)) return 1;
    }
    return 0;
}


void func_021D7320(struct BtlEventFactor *factor, BtlEventSkipCheck skipCheck) { factor->skipCheck = skipCheck; }


void func_021D7324(struct BtlEventFactor *factor)
{
    factor->skipCheck = 0;
}


struct BtlEventFactor *func_021D732C(int factorType, int ownerId)
{
    struct BtlEventFactor *factor;
    for (factor = g_021F3CB0.head; factor != 0; factor = factor->next) {
        if (factor->factorType == factorType && factor->ownerId == ownerId && !factor->removePending) return factor;
    }
    return 0;
}


struct BtlEventFactor *func_021D7360(struct BtlEventFactor *factor)
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


void func_021D7394(int pokeId)
{
    struct BtlEventFactor *factor;
    for (factor = g_021F3CB0.head; factor != 0; factor = factor->next) {
        if (factor->factorType == 0 && factor->pokeId == pokeId && func_021E03E8(factor, factor->work) != 0) factor->suspended = 1;
    }
}


void func_021D73D4(int pokeId)
{
    struct BtlEventFactor *factor;
    for (factor = g_021F3CB0.head; factor != 0; factor = factor->next) {
        if (factor->factorType == 0 && factor->pokeId == pokeId) factor->suspended = 0;
    }
}

void func_021D7404(u32 pokeId, int factorType)
{
    struct BtlEventFactor *factor;
    for (factor = g_021F3CB0.head; factor != 0; factor = factor->next) {
        if (factor->pokeId == pokeId && factor->factorType == factorType) factor->disabled = 1;
    }
}

int func_021D7438(int pokeId, int factorType) { struct BtlEventFactor *factor; int found=0; for(factor=g_021F3CB0.head; factor; factor=factor->next) { if(factor->pokeId==pokeId && factor->factorType==factorType) { factor->disabled=0; found=1; } } return found; }

struct BtlEventFactor *func_021D7474(void)
{
    u32 i;
    if (g_021F3CB0.usedCount == BTL_EVENT_FACTOR_MAX) return 0;
    i = g_021F3CB0.usedCount++;
    return g_021F3CB0.freePool[i];
}


void func_021D7494(void *factor) { if (g_021F3CB0.usedCount) { func_021D74BC((int)factor); g_021F3CB0.freePool[--g_021F3CB0.usedCount] = factor; } }


void func_021D74BC(int factor)
{
    func_02082BCC(factor, 0, 0x3c);
}


void func_021D74C8(void) { struct BtlEventVarStack *stack = &g_021F3ECC; unsigned int i; stack->frameTop = 0; for (i = 0; i < BTL_EVENT_VAR_MAX; i++) stack->keys[i] = 0; }


void func_021D74E4(void)
{
    if (g_021F3ECC.frameTop != 0)
        func_021D74C8();
}


void func_021D74F8(int line)
{
    struct BtlEventVarStack *stack = &g_021F3ECC;
    while (stack->frameTop < BTL_EVENT_VAR_MAX) {
        if (stack->keys[stack->frameTop] == 0) break;
        stack->frameTop++;
    }
    if (stack->frameTop < BTL_EVENT_VAR_MAX - 1) {
        stack->keys[stack->frameTop++] = 1;
    } else {
        func_02034714(data_021F3AB4, 0, data_021F3AB4);
    }
}


void func_021D7540(int line)
{
    struct BtlEventVarStack *stack = &g_021F3ECC;
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


void func_021D75A8(int key, u32 value)
{
    u32 i = func_021D77C4(&g_021F3ECC, key);
    g_021F3ECC.keys[i] = key;
    g_021F3ECC.values[i] = value;
    g_021F3ECC.minValues[i] = 0;
    g_021F3ECC.maxValues[i] = 0;
    g_021F3ECC.modes[i] = 0;
}


void func_021D75EC(int key, u32 value)
{
    u32 i = func_021D77C4(&g_021F3ECC, key);
    g_021F3ECC.keys[i] = key;
    g_021F3ECC.values[i] = value;
    g_021F3ECC.minValues[i] = 0;
    g_021F3ECC.maxValues[i] = 0;
    g_021F3ECC.modes[i] = 4;
}


void func_021D7630(int key, u32 value)
{
    u32 i = func_021D77C4(&g_021F3ECC, key);
    g_021F3ECC.keys[i] = key;
    g_021F3ECC.values[i] = value;
    g_021F3ECC.minValues[i] = 0;
    g_021F3ECC.maxValues[i] = 0;
    g_021F3ECC.modes[i] = 1;
}


void func_021D7674(int key, u32 value, u32 minValue, u32 maxValue)
{
    u32 i = func_021D77C4(&g_021F3ECC, key);
    g_021F3ECC.keys[i] = key;
    g_021F3ECC.values[i] = value;
    g_021F3ECC.minValues[i] = minValue;
    g_021F3ECC.maxValues[i] = maxValue;
    g_021F3ECC.modes[i] = 3;
}


int func_021D76BC(int key, u32 value)
{
    struct BtlEventVarStack *stack = &g_021F3ECC;
    int i = func_021D77E8(stack, key);

    if (i >= 0 && stack->modes[i] <= 1) {
        stack->keys[i] = key;
        stack->values[i] = value;
        if (stack->modes[i] == 1)
            stack->modes[i] = 2;
        return 1;
    }
    return 0;
}


void func_021D7704(int key, s32 multiplier)
{
    struct BtlEventVarStack *stack = &g_021F3ECC;
    int i = func_021D77E8(stack, key);

    if (i >= 0 && stack->modes[i] == 3) {
        s32 value = stack->values[i];
        s64 product = (s64)value * (s64)multiplier;
        stack->values[i] = func_021D780C(stack, i, (s32)((product + 0x800) >> 12));
    }
}


int func_021D775C(int key)
{
    struct BtlEventVarStack *stack = &g_021F3ECC;
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


int func_021D778C(int key, int *out) { struct BtlEventVarStack *stack = &g_021F3ECC; unsigned int i; for(i=stack->frameTop; i<BTL_EVENT_VAR_MAX; i++) { if(key==stack->keys[i]) { *out=stack->values[i]; return 1; } if(stack->keys[i]==0) break; } return 0; }


u32 func_021D77C4(struct BtlEventVarStack *stack, int key)
{
    u32 i;
    for (i = stack->frameTop; i < BTL_EVENT_VAR_MAX; i++) {
        if (stack->keys[i] == 0) break;
        if (key == stack->keys[i]) break;
    }
    if (i >= BTL_EVENT_VAR_MAX) i = 0;
    return i;
}


int func_021D77E8(struct BtlEventVarStack *stack, int key) { unsigned int i; for (i=stack->frameTop; i<BTL_EVENT_VAR_MAX && stack->keys[i]!=0; i++) { if(key==stack->keys[i]) return i; } return -1; }


int func_021D780C(struct BtlEventVarStack *stack, int index, int value) { int maxValue = stack->maxValues[index]; if (maxValue || stack->minValues[index]) { if ((int)stack->minValues[index] > value) value = stack->minValues[index]; if (maxValue < value) value=maxValue; } return value; }
