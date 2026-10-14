#ifndef BTLV_TIMER_SHARED_TYPES_H
#define BTLV_TIMER_SHARED_TYPES_H

#include "btlv_effvm_types.h"

#ifndef BTLV_U64_DEFINED
#define BTLV_U64_DEFINED
typedef unsigned long long u64;
#endif

struct ClactActor;

struct ClactUnit;

struct Task;

/* Slots of one timer side: the clock icon, then minutes, colon, seconds. */
typedef enum {
    BTLV_TIMER_SLOT_ICON,
    BTLV_TIMER_SLOT_MINUTE_TENS,
    BTLV_TIMER_SLOT_MINUTE_ONES,
    BTLV_TIMER_SLOT_COLON,
    BTLV_TIMER_SLOT_SECOND_TENS,
    BTLV_TIMER_SLOT_SECOND_ONES,
    BTLV_TIMER_SLOT_COUNT
} BtlvTimerSlot;

typedef struct {
    struct ClactActor *actor[BTLV_TIMER_SLOT_COUNT];
    void *reservedSlot;
} BtlvTimerSide;

/* Two-sided battle timer (0x78 bytes): one clock per side of the field. */
typedef struct BtlvTimer {
    struct ClactUnit *unit[2];      /* 0x00 */
    BtlvTimerSide side[2];          /* 0x08 */
    s32 charResId;                  /* 0x40 */
    s32 cellResId;                  /* 0x44 */
    s32 paletteResId;               /* 0x48 */
    int limit[2];                   /* 0x4c: seconds allowed per side */
    u64 startTick[2];               /* 0x54 */
    int animBase[2];                /* 0x64: 0 normal, 13 warning colour */
    struct Task *tickTask;          /* 0x6c */
    struct Task *spareTask;         /* 0x70 */
    u16 heapId;                     /* 0x74 */
} BtlvTimer;

#endif
