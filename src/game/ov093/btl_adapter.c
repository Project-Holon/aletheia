/*
 * file:     btl_adapter.c
 * unit:     yes
 * function: BTL_ADAPTER_ClearSlots, BTL_ADAPTER_NoOp, BTL_ADAPTER_Create, BTL_ADAPTER_ResetCommand, BTL_ADAPTER_Delete, BTL_ADAPTER_NotifyNet, BTL_ADAPTER_Idle, BTL_ADAPTER_SetSendData, BTL_ADAPTER_Update, BTL_ADAPTER_GetSendBuffer, BTL_ADAPTER_Cancel, BTL_ADAPTER_StartSend, BTL_ADAPTER_PollSend, BTL_ADAPTER_ClearRecvHeader, BTL_ADAPTER_GetRecvCommand, BTL_ADAPTER_GetRecvData, BTL_ADAPTER_SetRecvTarget
 * address:  0x021EEA30
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from btl_adapter.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free   0x020307B0  arm arm9
 *   MI_CpuCopy8  0x02082D44  arm
 *   gBtlAdapterSlots  0x021F6388  data  a4
 *   gBtlAdapterMode  0x021F6384  data  a4
 *   gBtlAdapterFileName     0x021F3AE8  data  ov093  a4
 *   BTL_NET_ExpectReplies   0x021D4C58  thumb
 *   BTL_NET_SendServerCmd  0x021D4B58  thumb  ov093
 *   BTL_NET_AreAllRepliesReceived  0x021D4B98  thumb  ov093
 *   BTL_NET_GetClientReply  0x021D4BD4  thumb  ov093
 *   BTL_NET_HasServerCmd  0x021D4C60  thumb  ov093
 *   BTL_NET_GetServerCmd  0x021D4C6C  thumb  ov093
 *   BTL_NET_SendClientReply  0x021D4C84  thumb  ov093
 */
#include "../types.h"

/* Wire packet of the adapter: command, size of data, then the data. */
struct BtlAdapterPacket {
    u16 command;
    u16 size;
    u8 data[0xBD0 - 0x14];
};

/*
 * One command channel between the battle logic and the net layer (0xBD0
 * bytes, one per channel in gBtlAdapterSlots). Channel 0 of a local battle
 * has netId 0 and loops the data back through peerData/packetData; with a
 * non-zero netId the data goes through the net functions instead.
 */
typedef struct BtlAdapter {
    struct GFLNetHandle *owner; /* 0x00 */
    const u8 *peerData;         /* 0x04 data the other side supplied (local mode) */
    u32 peerSize;               /* 0x08 */
    u8 peerReady : 4;           /* 0x0c */
    u8 netId : 4;
    u8 channel;                 /* 0x0d */
    u8 phase;                   /* 0x0e send state: 0 idle, 1 sending, 3 waiting, 4 done */
    u8 commandByte;             /* 0x0f */
    struct BtlAdapterPacket packet; /* 0x10 packet sent to the net layer */
} BtlAdapter;

#include "../arm9/gfl_heap_wrap.h"

#include "../arm9/mi_memory.h"


extern void BTL_NET_ExpectReplies(u32 netId);

extern u32 BTL_NET_SendServerCmd(u32 clientId, void *data, u32 size);

extern int BTL_NET_AreAllRepliesReceived(void);

extern u16 BTL_NET_GetClientReply(int channel, const u8 **outData);

extern u8 BTL_NET_HasServerCmd(void);

extern u16 BTL_NET_GetServerCmd(u8 **data);

extern u32 BTL_NET_SendClientReply(void *data, u32 size);

extern BtlAdapter *gBtlAdapterSlots[];

extern int gBtlAdapterMode;

extern const char gBtlAdapterFileName[];

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

void BTL_ADAPTER_ClearSlots(int mode)
{
    int i;

    for (i = 0; i < 4; i++)
        gBtlAdapterSlots[i] = 0;
    gBtlAdapterMode = mode;
}

void BTL_ADAPTER_NoOp(void) { }

BtlAdapter *BTL_ADAPTER_Create(struct GFLNetHandle *owner, int channel, u32 netId, u32 heapId)
{
    BtlAdapter *adapter;

    adapter = 0;
    if (gBtlAdapterSlots[channel] == 0) {
        adapter = GFL_HEAP_Alloc(heapId, sizeof(BtlAdapter), 1, gBtlAdapterFileName, 0x7e);
        adapter->owner = owner;
        adapter->channel = channel;
        adapter->netId = (u8)netId;
        adapter->phase = 0;
        adapter->commandByte = 0;
        adapter->peerReady = 0;
    }
    if (gBtlAdapterMode == 0) {
        if (gBtlAdapterSlots[channel] == 0)
            gBtlAdapterSlots[channel] = adapter;
        return gBtlAdapterSlots[channel];
    }
    gBtlAdapterSlots[channel] = adapter;
    return adapter;
}

/* 021EEAD0  clear the peer-ready nibble and the phase and command bytes */
void BTL_ADAPTER_ResetCommand(BtlAdapter *adapter)
{
    adapter->phase = 0;
    adapter->commandByte = 0;
    adapter->peerReady = 0;
}

void BTL_ADAPTER_Delete(BtlAdapter *adapter)
{
    GFL_HEAP_Free(adapter);
}

/* 021EEAE8  call through a global pointer when it is set */
void BTL_ADAPTER_NotifyNet(void)
{
    u32 mode = gBtlAdapterMode;
    if (mode != 0)
        BTL_NET_ExpectReplies(mode);
}

void BTL_ADAPTER_Idle(void)
{
}

void BTL_ADAPTER_SetSendData(BtlAdapter *adapter, u16 command, const void *src, u16 size)
{
    adapter->phase = 1;
    adapter->commandByte = command;
    adapter->packet.command = command;
    adapter->packet.size = size;
    MI_CpuCopy8(src, adapter->packet.data, size);
    adapter->peerData = 0;
    adapter->peerSize = 0;
    adapter->peerReady = 0;
}

int BTL_ADAPTER_Update(BtlAdapter *adapter)
{
    switch (adapter->phase) {
    case 1:
        if (BTL_ADAPTER_StartSend(adapter) == 0)
            break;
        adapter->phase = 3;
    case 3:
        if (BTL_ADAPTER_PollSend(adapter) == 0)
            break;
        adapter->phase = 4;
    case 4:
        return 1;
    }
    return 0;
}

const void *BTL_ADAPTER_GetSendBuffer(BtlAdapter *adapter, u32 *outSize)
{
    if (outSize != 0)
        *outSize = adapter->peerSize;
    return adapter->peerData;
}

void BTL_ADAPTER_Cancel(BtlAdapter *adapter)
{
    adapter->phase = 0;
    if (adapter->netId != 0)
        BTL_NET_ExpectReplies(adapter->netId);
}

u32 BTL_ADAPTER_StartSend(BtlAdapter *adapter)
{
    struct BtlAdapterPacket *packet;

    if (adapter->netId != 0) {
        packet = &adapter->packet;
        return BTL_NET_SendServerCmd((u32)adapter->channel, packet, packet->size + 4);
    }
    return 1;
}

u32 BTL_ADAPTER_PollSend(BtlAdapter *adapter)
{
    if (adapter->netId != 0) {
        if (BTL_NET_AreAllRepliesReceived() != 0) {
            adapter->peerSize = BTL_NET_GetClientReply(adapter->channel, &adapter->peerData);
            adapter->peerReady = 1;
            return 1;
        }
        return 0;
    }
    return adapter->peerReady;
}

void BTL_ADAPTER_ClearRecvHeader(BtlAdapter *adapter)
{
    adapter->packet.command = 0;
    adapter->packet.size = 4;
}

u8 BTL_ADAPTER_GetRecvCommand(BtlAdapter *adapter)
{
    struct BtlAdapterPacket *packet;

    if (adapter->netId != 0) {
        if (BTL_NET_HasServerCmd() != 0) {
            BTL_NET_GetServerCmd((u8 **)(&packet));
            return packet->command;
        }
        return 0;
    }
    if (adapter->peerReady == 0)
        return adapter->packet.command;
    return 0;
}

u16 BTL_ADAPTER_GetRecvData(BtlAdapter *adapter, u8 **outData)
{
    struct BtlAdapterPacket *packet;
    struct BtlAdapterPacket *received; /* second local keeps the register allocation */

    if (adapter->netId != 0) {
        BTL_NET_GetServerCmd((u8 **)(&packet));
        received = packet;
        *outData = received->data;
        return received->size;
    }
    *outData = adapter->packet.data;
    return adapter->packet.size;
}

u32 BTL_ADAPTER_SetRecvTarget(BtlAdapter *adapter, const u8 *data, u32 size)
{
    if (adapter->netId != 0)
        return BTL_NET_SendClientReply((void *)data, size);
    if (adapter->peerReady == 0) {
        adapter->peerData = data;
        adapter->peerSize = size;
        adapter->peerReady = 1;
    }
    return 1;
}
