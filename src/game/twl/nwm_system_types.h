#ifndef GAME_TWL_NWM_SYSTEM_TYPES_H
#define GAME_TWL_NWM_SYSTEM_TYPES_H

#include "../types.h"
#include "../twl/nwm_callback_types.h"

struct Msg;

/* Status block shared with the other processor: one busy byte per command, then the link state. */
struct NwmStatus {
    u8 busy[0x24];                  /* 0x00: indexed by command id */
    u16 state;                      /* 0x24 */
    u8 pad26[0x78];
    u16 allowedChannel;             /* 0x9E */
};

/* The NWM system work: the command buffers, the queue that hands them out, and the callback tables. */
struct NwmSystemWork {
    u8 cmdArea[0x2000];             /* 0x0000: command buffers */
    u8 cmdQueue[0x274];             /* 0x2000: struct OSMessageQueue and its slots */
    u8 *recvFlag;                   /* 0x2274 */
    struct NwmStatus *status;       /* 0x2278 */
    struct Msg *cmdBuf;             /* 0x227C */
    u16 recvDmaNo;                  /* 0x2280 */
    u16 pad2282;
    NWMCallbackFunc callback[20];              /* 0x2284: indexed by command id */
    NWMCallbackFunc recvCallback[20]; /* 0x22D4 */
};

#endif
