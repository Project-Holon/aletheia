#ifndef RING_QUEUE_H
#define RING_QUEUE_H

#include "../types.h"

/* Ring buffer of 32-bit values, 16 bytes. */
struct RingQueue {
    u32 *buffer;
    int capacity;
    int readIndex;
    int writeIndex;
};

int RingQueue_Create(int capacity, int heapId);
void RingQueue_Destroy(struct RingQueue *queue);
void RingQueue_Push(struct RingQueue *queue, int value);
u32 RingQueue_Pop(struct RingQueue *queue);
void RingQueue_Reset(struct RingQueue *queue);
int RingQueue_IsEmpty(struct RingQueue *queue);

#endif
