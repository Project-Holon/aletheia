#ifndef BTLV_BG_TYPES_H
#define BTLV_BG_TYPES_H

#include "../ov094/btlv_effvm_types.h"

/* Battle background: scroll state of BG layer 3 (0x0c bytes). */
typedef struct BtlvBg {
    void *taskSystem;               /* 0x00 */
    u32 scrolling : 1;              /* 0x04: set while a scroll job runs */
    u32 : 31;
    u16 heapId;                     /* 0x08 */
    u16 pad_0A;                     /* struct padding */
} BtlvBg;

#endif
