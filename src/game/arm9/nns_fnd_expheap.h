#ifndef GAME_ARM9_NNS_FND_EXPHEAP_H
#define GAME_ARM9_NNS_FND_EXPHEAP_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nns_fnd_expheap.c, prototypes copied from their definitions. */

struct DList;
struct Elem;
struct ExpHeap;
struct ExpHeapLists;
struct MBlock;
struct HeapHead;
struct Heap;

#include "../arm9/nns_fnd_types.h"
#include "../types.h"

void NNS_FndInitList(int list, int offset);
void NNSi_FndSetFirstObject(volatile struct DList *list, void *elem);
void NNS_FndAppendListObject(NNSFndList *list, void *object);
void NNS_FndPrependListObject(NNSFndList *list, void *object);
void NNS_FndInsertListObject(volatile struct DList *list, void *before, void *elem);
void NNS_FndRemoveListObject(volatile struct DList *list, void *elem);
void *NNS_FndGetNextListObject(struct DList *list, void *elem);
void *NNS_FndGetPrevListObject(struct DList *list, void *elem);
struct Elem *NNSi_FndFindElem(struct DList *list, u32 val);
void *NNSi_FndFindListContainHeap(u32 a);
void NNSi_FndInitHeapHead(NNSiFndHeapHead *pHeapHd, u32 signature, void *heapStart, void *heapEnd, u16 optFlag);
void NNSi_FndFinalizeHeap(void *p);
void NNSi_FndGetMBlockRegion(int *out, int *blk);
void *NNSi_FndRemoveMBlock(int *p, int *node);
void *NNSi_FndInsertMBlock(int *p, void *node, int *a);
void *NNSi_FndInitMBlock(int *p, int v);
void *NNSi_FndCreateExpHeap(struct ExpHeap *heap, void *lo, u16 attr);
void *NNSi_FndAllocFromExpHeap(struct ExpHeapLists *heap, struct MBlock *block, void *ptr, u32 size, u16 fromTail);
void *NNSi_FndAllocFromExpHeapHead(struct ExpHeap *heap, u32 size, s32 align);
void *NNSi_FndAllocFromExpHeapTail(struct ExpHeap *heap, u32 size, s32 align);
void *NNS_FndCreateExpHeapEx(void *start, u32 size, u16 attr);
void NNSi_FndDestroyExpHeap(void *heap);
void *NNS_FndAllocFromExpHeapEx(struct ExpHeap *heap, u32 size, s32 align);
u32 NNS_FndResizeForMBlockExpHeap(struct HeapHead *heap, void *memBlock, u32 size);
void NNS_FndFreeToExpHeap(struct ExpHeap *heap, void *block);
int NNSi_FndGetListTotalSize(int *p);
s32 NNSi_FndGetListAllocatableSize(struct Heap *heap, s32 x);
u32 NNSi_FndSetAllocModeBit(char *p, u32 v);
u16 NNSi_FndSetGroupId(char *p, u16 v);
void NNSi_FndWalkHeapBlocks(int *p, void (*fn)(void *, void *, int), int ctx);
int NNSi_FndGetMBlockSize(char *p);
u8 NNSi_FndGetMBlockAttribute(char *p);
/* END mkheaders: generated region */

#endif
