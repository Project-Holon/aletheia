#ifndef OV107_MB_COMM_SHARED_TYPES_H
#define OV107_MB_COMM_SHARED_TYPES_H

#include "../types.h"

/* Net session request copied from ROM data and patched with the heap id (112 bytes). */
typedef struct MbCommRequest {
    u32 settings[21];
    u16 heapId;
    u8 moreSettings[26];
} MbCommRequest;

/* Message sent on channel 0x400. */
typedef struct MbCommMsg {
    u32 value;
    u8 kind;
} MbCommMsg;

/* Record passed to the MB parent callback. */
typedef struct MbChildEvent {
    u16 errorCode;
    u8 unused02[8];
    u8 mac[6];
} MbChildEvent;

#endif
