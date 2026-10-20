#ifndef OV107_MB_BLOCK_TYPES_H
#define OV107_MB_BLOCK_TYPES_H

#include "../types.h"

/* Header of one block the parent sends (MB_COMM_PARENT_*). */
typedef struct MBCommParentBlockHeader {
    u8 type;
    u8 pad1;
    u16 fid;
    u16 seqno;
} MBCommParentBlockHeader;

/* Header of one block a child sends. */
typedef struct MBCommChildBlockHeader {
    u8 type;
    u8 pad1[1];
    union {
        struct {
            u16 req;
            u8 reserved[14];
        } data;
        u8 raw[16];
    } u;
} MBCommChildBlockHeader;

#endif
