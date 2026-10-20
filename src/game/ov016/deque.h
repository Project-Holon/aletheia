#ifndef GAME_OV016_DEQUE_H
#define GAME_OV016_DEQUE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of deque.c, prototypes copied from their definitions. */

struct tagLISTCB;

void *DWCi_QUElForm(long size);
void *DWCi_QUElFormEx(long size, void *data, long dataSize);
void DWCi_QUElDelete(struct tagLISTCB *list);
void DWCi_QUElPushBack(void *queue, void *data);
void *DWCi_QUElPopBack(void *queue);
/* END mkheaders: generated region */

#endif
