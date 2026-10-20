#ifndef GAME_OV093_BTL_SERVER_CMD_H
#define GAME_OV093_BTL_SERVER_CMD_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of btl_server_cmd.c, prototypes copied from their definitions. */

#include "../ov093/btl_server_cmd_types.h"
#include "../types.h"

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
void BTL_SERVER_CMD_Push(BtlServerCmdQueue *queue, volatile u32 id, ...);
u16 BTL_SERVER_CMD_Reserve(BtlServerCmdQueue *queue, u32 id);
void BTL_SERVER_CMD_FillReserved(BtlServerCmdQueue *queue, u16 slotPos, u32 id, ...);
int BTL_SERVER_CMD_ReadNext(BtlServerCmdQueue *queue, s32 *args);
void BTL_SERVER_CMD_WriteU8Wrapper(BtlServerCmdQueue *queue, u8 value);
u8 BTL_SERVER_CMD_ReadU8Wrapper(BtlServerCmdQueue *queue);
void BTL_SERVER_CMD_PushVariable(BtlServerCmdQueue *queue, u8 id, ...);
void BTL_SERVER_CMD_ReadVariableArgs(BtlServerCmdQueue *queue, u8 id, s32 *args);
void BTL_SERVER_CMD_Dummy(void);
/* END mkheaders: generated region */

#endif
