#ifndef BTL_EVENT_TYPES_H
#define BTL_EVENT_TYPES_H
/*
 * ov093 battle events: the event factor list and the event variable stack.
 */

#include "../types.h"

#define BTL_EVENT_FACTOR_MAX 0x84
#define BTL_EVENT_VAR_MAX 0x60
#define BTL_EVENT_NO_POKE 0x1F
#define BTL_EVENT_TYPE_ANY 7
#define BTL_EVENT_TYPE_DEAD 6

struct BtlEventFactor;

/* Asks one factor whether it blocks an event for another factor; nonzero blocks. */
typedef int (*BtlEventSkipCheck)(struct BtlEventFactor *other, void *context, int factorType, int eventId, u16 key, u8 ownerId);

/* One handler of a factor: the event it answers and the function to call. */
typedef struct {
    int eventId;
    void (*handler)(struct BtlEventFactor *factor, void *context, u8 ownerId, void *work);
} BtlEventHandler;

/*
 * One event factor (0x3C bytes): an ability, item, field effect and so on that
 * reacts to battle events. Factors form a list sorted by priority.
 */
struct BtlEventFactor {
    struct BtlEventFactor *prev, *next;
    const BtlEventHandler *handlers;
    BtlEventSkipCheck skipCheck;
    int factorType;
    u32 priority;
    u32 addDepth : 16;      /* dispatch depth when the factor was added */
    u32 handlerCount : 8;
    u32 running : 1;        /* a handler of this factor is running */
    u32 suspended : 1;
    u32 answersSpecial : 1; /* also reacts to event 0x73 */
    u32 removePending : 1;  /* removal asked while a handler was running */
    u32 keepRunning : 1;
    u32 active : 1;
    u32 disabled : 1;
    u32 reserved31 : 1;
    u32 work[7];
    u16 key;
    u8 ownerId;
    u8 pokeId;
};

/* The list head, the used count of the free pool, and the free pool itself. */
struct BtlEventFactorList {
    u32 dispatchDepth;
    struct BtlEventFactor *head;
    u32 usedCount;
    struct BtlEventFactor *freePool[BTL_EVENT_FACTOR_MAX];
};

/*
 * Event variable stack. Frames are separated by key 1; a key of 0 ends the
 * used part. mode: 0 plain, 1 settable once, 2 set, 3 ranged, 4 read only.
 */
struct BtlEventVarStack {
    u32 frameTop;
    u16 keys[BTL_EVENT_VAR_MAX];
    sptr values[BTL_EVENT_VAR_MAX];
    u32 maxValues[BTL_EVENT_VAR_MAX];
    u32 minValues[BTL_EVENT_VAR_MAX];
    u8 modes[BTL_EVENT_VAR_MAX];
};

#endif
