#ifndef UNIT_021EFA94_TYPES_H
#define UNIT_021EFA94_TYPES_H

#include "../types.h"
#include "../ov093/btl_pokeparam_types.h"

#define BTL_FIELD_SLOT_COUNT 8
#define BTL_FIELD_HOLDER_MAX 6
#define BTL_FIELD_EMPTY_HOLDER 0x1f


/* Armed timer: while value is set and count is not 0xff, count steps down;
 * at zero the value is returned and cleared. */
typedef struct {
    u32 value;
    u32 count;
} BtlFieldCountdown;

/* Battle field effect table: eight slots, one u32[8] array per property plus
 * the u32[8][6] holder list, all indexed by the slot number.  A slot is a
 * running field effect with a view handle, a key (owner position and
 * duration), the turns elapsed, and the ids of the Pokemon holding it.
 * Written as member arrays, the load of inUse[slot] keeps slot*4 in its own
 * register while the other stores recompute base + slot*4 (raw
 * `*(u32 *)(a + K + slot * 4)` casts CSE'd slot*4 and swapped the registers). */
typedef struct {
    BtlFieldCountdown countdown;    /* 0x000 */
    u32 effectHandle[8];            /* 0x008 */
    union SickCont key[8];          /* 0x028 */
    u32 elapsedTurns[8];            /* 0x048 */
    u32 holderIds[8][6];            /* 0x068 */
    u32 holderCount[8];             /* 0x128 */
    u32 inUse[8];                   /* 0x148 */
} BtlFieldState;

#endif
