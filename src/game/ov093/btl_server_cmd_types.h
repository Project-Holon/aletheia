#ifndef BTL_SERVER_CMD_TYPES_H
#define BTL_SERVER_CMD_TYPES_H
/*
 * ov093 battle server command queue: a byte buffer the battle server writes
 * commands into and the client reads them back from.
 *
 * One command is a u16 id followed by arguments packed as the layout byte
 * data_021EFF14[id] says: the low nibble is the argument count, the high
 * nibble picks the packing (all bytes, a byte plus a halfword, several small
 * bit fields in one byte, a halfword or a 24-bit word, ...).  A layout byte of
 * 0x00 or 0x10 marks a variable-length command: arguments are 32-bit words and
 * end at BTL_SERVER_CMD_ARG_END.
 */

#ifndef OV093_BASIC_TYPES
#define OV093_BASIC_TYPES
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
#endif

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

void BTL_SERVER_CMD_WriteU8(BtlServerCmdQueue *queue, u8 value);
u8 BTL_SERVER_CMD_ReadU8(BtlServerCmdQueue *queue);
void BTL_SERVER_CMD_WriteU16(BtlServerCmdQueue *queue, u16 value);
u32 BTL_SERVER_CMD_ReadU16(BtlServerCmdQueue *queue);
void BTL_SERVER_CMD_WriteU24(BtlServerCmdQueue *queue, u32 value);
u32 BTL_SERVER_CMD_ReadU24(BtlServerCmdQueue *queue);
void BTL_SERVER_CMD_WriteU32(BtlServerCmdQueue *queue, u32 value);
u32 BTL_SERVER_CMD_ReadU32(BtlServerCmdQueue *queue);
void BTL_SERVER_CMD_WriteCommand(BtlServerCmdQueue *queue, u32 id, int layout, s32 *args);
void BTL_SERVER_CMD_ReadFixedArgs(BtlServerCmdQueue *queue, int layout, s32 *args);
void BTL_SERVER_CMD_Push(BtlServerCmdQueue *queue, u32 id, ...);
u16 BTL_SERVER_CMD_Reserve(BtlServerCmdQueue *queue, u32 id);
void BTL_SERVER_CMD_FillReserved(BtlServerCmdQueue *queue, u16 slotPos, u32 id, ...);
int BTL_SERVER_CMD_ReadNext(BtlServerCmdQueue *queue, s32 *args);
void BTL_SERVER_CMD_WriteU8Wrapper(BtlServerCmdQueue *queue, u8 value);
u8 BTL_SERVER_CMD_ReadU8Wrapper(BtlServerCmdQueue *queue);
void BTL_SERVER_CMD_PushVariable(BtlServerCmdQueue *queue, u8 id, ...);
void BTL_SERVER_CMD_ReadVariableArgs(BtlServerCmdQueue *queue, u8 id, s32 *args);
void BTL_SERVER_CMD_Dummy(void);

#endif
