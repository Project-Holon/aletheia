#ifndef GAME_OV217_QUEUE_H
#define GAME_OV217_QUEUE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of queue.c, prototypes copied from their definitions. */

struct RingQueue;

#include "../types.h"

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
/* END mkheaders: generated region */

#endif
