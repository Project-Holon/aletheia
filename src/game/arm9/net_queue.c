/*
 * file:     net_queue.c
 * unit:     yes
 * function: GFL_NET_QUEUE_GetFreeNode, GFL_NET_QUEUE_IsEmpty, GFL_NET_QUEUE_GetCount, GFL_NET_QUEUE_PopList, GFL_NET_QUEUE_PutByte, GFL_NET_QUEUE_WriteHeader, GFL_NET_QUEUE_WriteNode, GFL_NET_QUEUE_Put, GFL_NET_QUEUE_GetNext, GFL_NET_QUEUE_RemoveNext, GFL_NET_QUEUE_FillSendBuffer, GFL_NET_QUEUE_Init, GFL_NET_QUEUE_Reset, GFL_NET_QUEUE_Exit, GFL_NET_QUEUE_IsCommandQueued
 * address:  0x02036670
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Cut from touchpanel.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc                    0x02030734  arm
 *   GFL_HEAP_Free                    0x020307B0  arm
 *   SAVEDATA_PanicFail                    0x02034714  arm
 *   MI_CpuFill8                      0x02082BCC  arm
 *   MI_CpuCopy8                      0x02082D44  arm
 *   _pTouchPanelWork                 0x021469C4  data
 *   net_queue_File                   0x020A79C4  data
 *   net_queue_AssertZero             0x020A79D0  data
 *   net_queue_AssertSize             0x020A79D4  data
 *   net_queue_AssertRet              0x020A79EC  data
 *   GFL_NET_RING_BUFF_Write 0x02036428 arm arm9
 *   GFL_NET_RING_BUFF_Read 0x020364D4 arm arm9
 *   GFL_NET_RING_BUFF_GetFreeSize 0x0203660C arm arm9
 *   GFL_NET_RING_BUFF_EndChange 0x0203666C arm arm9
 */
#include "touchpanel_shared_types.h"
#include "net_types.h"
#include "net_queue_shared_types.h"

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *file, u16 line);

extern u32 GFL_HEAP_Free(void *p);

extern void SAVEDATA_PanicFail(const char *file, u32 line, const char *expr);

extern void MI_CpuFill8(void *dst, u8 val, u32 size);

extern void MI_CpuCopy8(const void *src, void *dst, u32 size);

void GFL_NET_RING_BUFF_Write(NetRingBuff *ring, const u8 *pDataArea, int size);

int GFL_NET_RING_BUFF_Read(NetRingBuff *ring, u8 *dst, u32 size, u32 max);

int GFL_NET_RING_BUFF_GetFreeSize(NetRingBuff *ring);

void GFL_NET_RING_BUFF_EndChange(NetRingBuff *ring);

/* net_queue.c */
NetQueueNode *GFL_NET_QUEUE_GetFreeNode(NetQueue *queue);

int GFL_NET_QUEUE_IsEmpty(NetQueue *queue);

int GFL_NET_QUEUE_GetCount(NetQueue *queue);

u32 GFL_NET_QUEUE_PopList(NetQueueList *list);

void GFL_NET_QUEUE_PutByte(NetSendBuf *out, int byte);

int GFL_NET_QUEUE_WriteHeader(NetQueueNode *node, NetSendBuf *out);

int GFL_NET_QUEUE_WriteNode(NetQueueNode *node, NetSendBuf *out, NetRingBuff *ring, BOOL needHeader);

int GFL_NET_QUEUE_Put(NetQueue *queue, u32 command, const u8 *pDataArea, u32 size, u32 isFast, u32 copyToRing, u32 sendID);

NetQueueNode *GFL_NET_QUEUE_GetNext(NetQueue *queue);

void GFL_NET_QUEUE_RemoveNext(NetQueue *queue);

int GFL_NET_QUEUE_FillSendBuffer(NetQueue *queue, NetSendBuf *out);

void GFL_NET_QUEUE_Init(NetQueue *queue, u32 nodeMax, NetRingBuff *ring, u32 heapId);

void GFL_NET_QUEUE_Reset(NetQueue *queue);

void GFL_NET_QUEUE_Exit(NetQueue *queue);

int GFL_NET_QUEUE_IsCommandQueued(NetQueue *queue, int command);

extern const char net_queue_File[];

extern const char net_queue_AssertZero[];

extern const char net_queue_AssertSize[];

extern const char net_queue_AssertRet[];

/* ==================================================================
 * net_queue.c
 * ================================================================== */

/* First node with no command, or 0 when all are in use. */
NetQueueNode *GFL_NET_QUEUE_GetFreeNode(NetQueue *queue)
{
    NetQueueNode *node;
    s32 i;
    s32 n;

    node = queue->nodes;
    n = queue->nodeMax;
    for (i = 0; i < n; i++) {
        if (node->command == 0)
            return node;
        node++;
    }
    return 0;
}

int GFL_NET_QUEUE_IsEmpty(NetQueue *queue)
{
    return GFL_NET_QUEUE_GetCount(queue) == 0;
}

/* Nodes in use. */
int GFL_NET_QUEUE_GetCount(NetQueue *queue)
{
    const NetQueueNode *node = queue->nodes;
    int i;
    int count = 0;
    int n = queue->nodeMax;

    for (i = 0; i < n; i++, node++) {
        if (node->command != 0)
            count++;
    }
    return count;
}

/* Unlinks the head node of a list; 0 when the list is empty. */
u32 GFL_NET_QUEUE_PopList(NetQueueList *list)
{
    NetQueueNode *next;

    next = list->head;
    if (next != 0) {
        next = next->next;
        if (next != 0) {
            list->head = next;
            next->prev = 0;
        } else {
            list->head = 0;
            list->tail = 0;
        }
        return 1;
    }
    return 0;
}

void GFL_NET_QUEUE_PutByte(NetSendBuf *out, int byte)
{
    *out->ptr = (u8)byte;
    out->ptr = out->ptr + 1;
    out->size = out->size - 1;
}

/* Five-byte header: command and size (high byte first), then sendID. */
int GFL_NET_QUEUE_WriteHeader(NetQueueNode *node, NetSendBuf *out)
{
    GFL_NET_QUEUE_PutByte(out, (node->command >> 8) & 0xff);
    GFL_NET_QUEUE_PutByte(out, node->command & 0xff);
    GFL_NET_QUEUE_PutByte(out, (node->size >> 8) & 0xff);
    GFL_NET_QUEUE_PutByte(out, node->size & 0xff);
    GFL_NET_QUEUE_PutByte(out, node->sendID);
    return 0;
}

/*
 * Moves one node into the send buffer: the header first (refused with 0
 * when needHeader is set and header and data do not fit), then as much
 * data as fits.  When the data does not fit, the buffer is marked full
 * (0xffff) and the node keeps the rest.
 */
int GFL_NET_QUEUE_WriteNode(NetQueueNode *node, NetSendBuf *out, NetRingBuff *ring, BOOL needHeader)
{
    if (node->headerSent == 0) {
        if (needHeader != 0 && out->size < node->size + 5) {
            return 0;
        }
        GFL_NET_QUEUE_WriteHeader(node, out);
    }
    if (out->size < node->size) {
        if (node->data == 0) {
            GFL_NET_RING_BUFF_Read(ring, out->ptr, out->size, out->size);
        } else {
            MI_CpuCopy8(node->data, out->ptr, out->size);
            node->data += out->size;
        }
        node->size = node->size - out->size;
        out->size = 0xffff;
        node->headerSent = 1;
        return 1;
    }
    if (node->data == 0) {
        GFL_NET_RING_BUFF_Read(ring, out->ptr, node->size, node->size);
    } else {
        MI_CpuCopy8(node->data, out->ptr, node->size);
    }
    out->ptr += node->size;
    out->size = out->size - node->size;
    return 1;
}

/*
 * Queues one send.  With copyToRing the data is copied into the ring now,
 * else the node keeps the caller's pointer.  isFast is not used in this
 * version: every node goes on the fast list.
 */
int GFL_NET_QUEUE_Put(NetQueue *queue, u32 command, const u8 *pDataArea, u32 size, u32 isFast, u32 copyToRing, u32 sendID)
{
    NetQueueNode *node = GFL_NET_QUEUE_GetFreeNode(queue);

    if (node == 0) {
        SAVEDATA_PanicFail(net_queue_File, 0xdb, net_queue_AssertZero);
        return 0;
    }
    if (!((u16)size < 0xffff / 2)) {
        SAVEDATA_PanicFail(net_queue_File, 0xdf, net_queue_AssertSize);
    }
    if (copyToRing != 0) {
        if (!((int)(size + 5) < (int)GFL_NET_RING_BUFF_GetFreeSize(queue->ring))) {
            SAVEDATA_PanicFail(net_queue_File, 0xe3, net_queue_AssertZero);
            return 0;
        }
        GFL_NET_RING_BUFF_Write(queue->ring, pDataArea, size);
        GFL_NET_RING_BUFF_EndChange(queue->ring);
        node->data = 0;
    } else {
        node->data = pDataArea;
    }
    node->size = size;
    node->command = command;
    node->sendID = sendID;
    node->headerSent = 0;
    if (queue->fast.tail == 0) {
        queue->fast.tail = node;
        queue->fast.head = node;
    } else {
        queue->fast.tail->next = node;
        node->prev = queue->fast.tail;
        queue->fast.tail = node;
    }
    return 1;
}

/* Next node to send: the cut one first, then the fast list, then the slow. */
NetQueueNode *GFL_NET_QUEUE_GetNext(NetQueue *queue)
{
    if (queue->current != 0)
        return queue->current;
    if (queue->fast.head != 0)
        return queue->fast.head;
    if (queue->slow.head != 0)
        return queue->slow.head;
    return 0;
}

/* Removes the node GFL_NET_QUEUE_GetNext picked. */
void GFL_NET_QUEUE_RemoveNext(NetQueue *queue)
{
    if (queue->current != 0) {
        queue->current = 0;
        return;
    }
    if (GFL_NET_QUEUE_PopList(&queue->fast) != 0) {
        return;
    }
    if (GFL_NET_QUEUE_PopList(&queue->slow) != 0) {
        return;
    }
    SAVEDATA_PanicFail(net_queue_File, 0x12f, net_queue_AssertRet);
}

/*
 * Fills the send buffer from the queue.  Returns 0 only when the buffer
 * filled up in the middle of a node after at least one node went in.
 */
int GFL_NET_QUEUE_FillSendBuffer(NetQueue *queue, NetSendBuf *out)
{
    int needHeader = 0;

    if (out->size == 0)
        goto done;
    while (1) {
        NetQueueNode *node = GFL_NET_QUEUE_GetNext(queue);

        if (node == 0)
            goto done;
        GFL_NET_QUEUE_RemoveNext(queue);
        if (GFL_NET_QUEUE_WriteNode(node, out, queue->ring, needHeader) == 0) {
            queue->current = node;
            goto done;
        }
        needHeader = 1;
        if (out->size == 0xffff) {
            queue->current = node;
            return 0;
        }
        MI_CpuFill8(node, 0, sizeof(NetQueueNode));
        if (out->size == 0)
            break;
    }
done:
    return 1;
}

void GFL_NET_QUEUE_Init(NetQueue *queue, u32 nodeMax, NetRingBuff *ring, u32 heapId)
{
    MI_CpuFill8(queue, 0, sizeof(NetQueue));
    queue->nodes = GFL_HEAP_Alloc(heapId, nodeMax * sizeof(NetQueueNode), 1, net_queue_File, 0x173);
    queue->nodeMax = nodeMax;
    queue->ring = ring;
}

void GFL_NET_QUEUE_Reset(NetQueue *queue)
{
    MI_CpuFill8(queue->nodes, 0, queue->nodeMax * sizeof(NetQueueNode));
    queue->fast.head = 0;
    queue->fast.tail = 0;
    queue->slow.head = 0;
    queue->slow.tail = 0;
    queue->current = 0;
}

void GFL_NET_QUEUE_Exit(NetQueue *queue)
{
    GFL_HEAP_Free(queue->nodes);
}

/* Is a node with this command queued? */
int GFL_NET_QUEUE_IsCommandQueued(NetQueue *queue, int command)
{
    int i;
    NetQueueNode *node = queue->nodes;
    int n = queue->nodeMax;

    for (i = 0; i < n; i++, node++) {
        if (node->command == command)
            return 1;
    }
    return 0;
}
