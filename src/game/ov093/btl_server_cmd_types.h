#ifndef BTL_SERVER_CMD_TYPES_H
#define BTL_SERVER_CMD_TYPES_H
/*
 * ov093 battle server command queue: a byte buffer the battle server writes
 * commands into and the client reads them back from.
 *
 * One command is a u16 id followed by arguments packed as the layout byte
 * gBtlServerCmdLayouts[id] says: the low nibble is the argument count, the high
 * nibble picks the packing (all bytes, a byte plus a halfword, several small
 * bit fields in one byte, a halfword or a 24-bit word, ...).  A layout byte of
 * 0x00 or 0x10 marks a variable-length command: arguments are 32-bit words and
 * end at BTL_SERVER_CMD_ARG_END.
 */

#include "../types.h"

#define BTL_SERVER_CMD_QUEUE_SIZE 3000
#define BTL_SERVER_CMD_MAX_ARGS 16
#define BTL_SERVER_CMD_DATA_OFFSET 8 /* offset of data in BtlServerCmdQueue */

#define BTL_SERVER_CMD_ID_LONG_LIST 0x5C /* variable-length command with an extra halfword argument */
#define BTL_SERVER_CMD_ID_NONE 0x5E      /* returned by the reader when the queue is empty */
#define BTL_SERVER_CMD_ID_FILLER 0x5F    /* reserved slot: the byte after the id is the filler length */
#define BTL_SERVER_CMD_ARG_END 0xFFFF0000

typedef struct {
    u32 writePos;                           /* 0x0: next byte to write, index into data */
    u32 readPos;                            /* 0x4: next byte to read, index into data */
    u8 data[BTL_SERVER_CMD_QUEUE_SIZE];     /* 0x8 */
} BtlServerCmdQueue;

#include "../ov093/btl_server_cmd.h"

#endif
