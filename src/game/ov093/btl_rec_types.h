#ifndef BTL_REC_TYPES_H
#define BTL_REC_TYPES_H

#include "../types.h"

/* Replay buffer of one battle: records are appended after the 8 byte head
 * until 0xC00 bytes are used, then the overflow flag is set. */
typedef struct {
    u16 writeOffset;
    u8 overflowed;
    u8 reserved[5];
    u8 data[0xC00];
} BtlRecBuffer;

/* Read side of a recording: four channels (one per client) walk the same
 * byte stream; each channel keeps its own position and its last record. */
typedef struct {
    u8 *bytes;
    u32 size : 31;
    u32 failed : 1;
    u32 readPos[4];
    u32 lastRecord[4][16];
} BtlRecReader;

/* Write side: one packet of at most 60 bytes. data[0] is the packet id,
 * data[1] the header byte (bits 0-3 count, 4-6 type, 7 flag), then the
 * sub-records (channel in bits 5-7 and size in words in bits 0-4, followed
 * by the words). */
typedef struct {
    u8 used;
    u8 channelMask;
    u8 recordCount;
    u8 type : 6;
    u8 flag : 1;
    u8 full : 1;
    u8 data[60];
} BtlRecPacket;

#endif
