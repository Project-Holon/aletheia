#ifndef GAME_OV093_BTL_ADAPTER_H
#define GAME_OV093_BTL_ADAPTER_H
struct GFLNetHandle;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of btl_adapter.c, prototypes copied from their definitions. */

struct BtlAdapter;
typedef struct BtlAdapter BtlAdapter;

#include "../types.h"

void BTL_ADAPTER_ClearSlots(int mode);
void BTL_ADAPTER_NoOp(void);
BtlAdapter *BTL_ADAPTER_Create(struct GFLNetHandle *owner, int channel, u32 netId, u32 heapId);
void BTL_ADAPTER_ResetCommand(BtlAdapter *adapter);
void BTL_ADAPTER_Delete(BtlAdapter *adapter);
void BTL_ADAPTER_NotifyNet(void);
void BTL_ADAPTER_Idle(void);
void BTL_ADAPTER_SetSendData(BtlAdapter *adapter, u16 command, const void *src, u16 size);
int BTL_ADAPTER_Update(BtlAdapter *adapter);
const void *BTL_ADAPTER_GetSendBuffer(BtlAdapter *adapter, u32 *outSize);
void BTL_ADAPTER_Cancel(BtlAdapter *adapter);
u32 BTL_ADAPTER_StartSend(BtlAdapter *adapter);
u32 BTL_ADAPTER_PollSend(BtlAdapter *adapter);
void BTL_ADAPTER_ClearRecvHeader(BtlAdapter *adapter);
u8 BTL_ADAPTER_GetRecvCommand(BtlAdapter *adapter);
u16 BTL_ADAPTER_GetRecvData(BtlAdapter *adapter, u8 **outData);
u32 BTL_ADAPTER_SetRecvTarget(BtlAdapter *adapter, const u8 *data, u32 size);
/* END mkheaders: generated region */

#endif
