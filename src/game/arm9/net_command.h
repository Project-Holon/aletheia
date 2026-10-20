#ifndef GAME_ARM9_NET_COMMAND_H
#define GAME_ARM9_NET_COMMAND_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of net_command.c, prototypes copied from their definitions. */

struct NetCommandTable;

#include "../types.h"
#include "../arm9/net_types.h"

void GFL_NET_COMMAND_Init(u32 groupKey, NetCommandEntry *commandList, u32 listNum, void *userData, u32 unusedArg);
void GFL_NET_COMMAND_Exit(void);
void GFL_NET_COMMAND_AddCommandTable(u32 groupKey, NetCommandEntry *commandList, u32 listNum, void *userData);
void GFL_NET_COMMAND_DeleteCommandTable(u32 groupKey);
u32 GFL_NET_COMMAND_GetHeaderSize(u32 destMask);
struct NetCommandTable *GFL_NET_COMMAND_GetCommandTable(u32 command);
NetCommandRecvFunc GFL_NET_COMMAND_GetRecvFunc(u32 command);
u32 GFL_NET_COMMAND_GetCommandWork(u32 command);
NetCommandSizeFunc GFL_NET_COMMAND_GetSizeFunc(u32 command);
void GFL_NET_COMMAND_CallCommand(u32 netId, u32 destMask, int command, u32 size, u32 data, u32 handle);
int GFL_NET_COMMAND_IsCommandValid(unsigned int command);
int GFL_NET_COMMAND_IsHugeCommand(unsigned int command);
u32 GFL_NET_COMMAND_GetHugeBuffer(u32 command, u32 netId, u32 size);
void GFL_NET_COMMAND_NoProc(void);
void GFL_NET_COMMAND_RecvHugeData(int netId, u32 byteCount, void *chunkData, int unusedArg, volatile int handle);
void GFL_NET_COMMAND_RecvHugeBuffer(int netId, int unusedArg, const u8 *header, int unusedArg2, int handle);
u32 GFL_NET_COMMAND_SetSendSlot(GFLNetHandle *handle, u32 destMask, u32 command, u32 totalSize, void *dataAddr);
u32 GFL_NET_COMMAND_SendNextSlot(void);
void GFL_NET_COMMAND_Main(void);
/* END mkheaders: generated region */

#endif
