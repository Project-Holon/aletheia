/*
 * file:     queue.c
 * unit:     yes
 * function: RingQueue_Create, RingQueue_Destroy, RingQueue_Push, RingQueue_Pop, RingQueue_Reset, RingQueue_IsEmpty, RingQueue_ClearFields, RingQueue_AllocBuffer, RingQueue_FreeBuffer, RingQueue_PushImpl, RingQueue_PopImpl, RingQueue_ResetImpl, RingQueue_IsEmptyImpl
 * address:  0x021C0E08
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from research_top.c, unit_021BFFC8.c, queue.c, palette_anime.c, PALETTE_ANIME_ReleaseOriginal.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Free 0x020307B0 arm
 *   RingQueue_Push  0x021C0E4C  thumb  ov217
 *   RingQueue_Pop  0x021C0E54  thumb  ov217
 *   RingQueue_IsEmpty  0x021C0E64  thumb  ov217
 *   RingQueue_Create  0x021C0E08  thumb  ov217
 *   RingQueue_Destroy  0x021C0E3C  thumb  ov217
 *   d_021C4050  0x021C4050  data  a4
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   RingQueue_Reset  0x021C0E5C  thumb  ov217
 */
#include "research_shared_types.h"

#include "ring_queue.h"

#include "../arm9/gfl_heap_wrap.h"

struct RingQueue *RingQueue_Create(int capacity, int heapId);
void RingQueue_Destroy(struct RingQueue *queue);
void RingQueue_Push(struct RingQueue *queue, int value);
u32 RingQueue_Pop(struct RingQueue *queue);
void RingQueue_Reset(struct RingQueue *queue);
int RingQueue_IsEmpty(struct RingQueue *queue);
void RingQueue_ClearFields(struct RingQueue *queue);
void RingQueue_AllocBuffer(struct RingQueue *queue, u32 capacity, u32 heapId);
void RingQueue_FreeBuffer(struct RingQueue *queue);
void RingQueue_PushImpl(struct RingQueue *queue, int value);
u32 RingQueue_PopImpl(struct RingQueue *queue);
void RingQueue_ResetImpl(struct RingQueue *queue);
int RingQueue_IsEmptyImpl(struct RingQueue *queue);

extern const int d_021C4050[];

/* Allocates and initialises a queue holding capacity values. */
struct RingQueue *RingQueue_Create(int capacity, int heapId)
{
    struct RingQueue *queue;
    queue = GFL_HEAP_Alloc(heapId, sizeof(struct RingQueue), 0, (const char *)d_021C4050, 0x3C);
    RingQueue_ClearFields(queue);
    RingQueue_AllocBuffer(queue, capacity, heapId);
    return queue;
}

void RingQueue_Destroy(struct RingQueue *queue)
{
    RingQueue_FreeBuffer(queue);
    GFL_HEAP_Free(queue);
}

void RingQueue_Push(struct RingQueue *queue, int value)
{
    RingQueue_PushImpl(queue, value);
}

/*
 * Tail-call veneer: branch to RingQueue_PopImpl.
 */
u32 RingQueue_Pop(struct RingQueue *queue)
{
    return RingQueue_PopImpl(queue);
}

/*
 * Tail-call veneer: branch to RingQueue_ResetImpl.
 */
void RingQueue_Reset(struct RingQueue *queue)
{
    RingQueue_ResetImpl(queue);
}

/*
 * Tail-call veneer: branch to RingQueue_IsEmptyImpl.
 */
int RingQueue_IsEmpty(struct RingQueue *queue)
{
    return RingQueue_IsEmptyImpl(queue);
}

/* Clears the buffer pointer and both indices. */
void RingQueue_ClearFields(struct RingQueue *queue)
{
    queue->buffer = 0;
    queue->readIndex = 0;
    queue->writeIndex = 0;
}

void RingQueue_AllocBuffer(struct RingQueue *queue, u32 capacity, u32 heapId)
{
    queue->buffer = (u32 *)GFL_HEAP_Alloc(heapId, capacity << 2, 0, (const char *)0x21C4050, 211);
    queue->capacity = capacity;
}

void RingQueue_FreeBuffer(struct RingQueue *queue)
{
    GFL_HEAP_Free(queue->buffer);
}

/* Stores value at the write index and advances it, wrapping at capacity. */
void RingQueue_PushImpl(struct RingQueue *queue, int value)
{
    *(int *)((uptr)queue->buffer + queue->writeIndex * 4) = value;
    queue->writeIndex = (queue->writeIndex + 1) % queue->capacity;
}

/* Returns the value at the read index and advances it, wrapping at capacity. */
u32 RingQueue_PopImpl(struct RingQueue *queue)
{
    u32 value;
    value = queue->buffer[queue->readIndex];
    queue->readIndex = (queue->readIndex + 1) % queue->capacity;
    return value;
}

/*
 * Empties the queue (both indices to 0).  Reached only from the tail-call
 * veneer RingQueue_Reset.
 */
void RingQueue_ResetImpl(struct RingQueue *queue)
{
    queue->readIndex = 0;
    queue->writeIndex = 0;
}

/*
 * Whether the queue is empty (read index equals write index).  Reached only
 * from the tail-call veneer RingQueue_IsEmpty.
 */
int RingQueue_IsEmptyImpl(struct RingQueue *queue)
{
    return queue->readIndex == queue->writeIndex;
}
