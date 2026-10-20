#ifndef GAME_ARM9_NNS_FND_UNITHEAP_H
#define GAME_ARM9_NNS_FND_UNITHEAP_H

typedef struct NNSiFndUnitBlock NNSiFndUnitBlock;
typedef struct NNSiFndUnitHeap NNSiFndUnitHeap;
typedef struct NNSiFndAllocator NNSiFndAllocator;
typedef struct NNSiFndHeapRef NNSiFndHeapRef;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nns_fnd_unitheap.c, prototypes copied from their definitions. */

struct NNSiFndUnitBlock;
struct NNSiFndUnitHeap;
struct NNSiFndAllocator;
struct NNSiFndHeapRef;
typedef struct NNSiFndUnitBlock NNSiFndUnitBlock;
typedef struct NNSiFndUnitHeap NNSiFndUnitHeap;
typedef struct NNSiFndAllocator NNSiFndAllocator;
typedef struct NNSiFndHeapRef NNSiFndHeapRef;

#include "../types.h"

NNSiFndUnitBlock *NNSi_FndPopFreeBlock(NNSiFndUnitBlock **pFreeList);
void *NNSi_FndAllocBlockFromHeap(NNSiFndUnitHeap *pHeap);
void NNSi_FndPushFreeBlock(NNSiFndUnitHeap *heap, void *block);
void *NNSi_FndAllocFromExpHeapAllocator(NNSiFndAllocator *allocator, u32 size);
void NNSi_FndFreeToExpHeapAllocator(NNSiFndAllocator *allocator, void *block);
void *NNSi_FndAllocFromFrmHeapAllocator(NNSiFndAllocator *allocator, u32 size);
void NNSi_FndFreeToFrmHeapAllocator(NNSiFndAllocator *allocator, void *block);
int NNSi_FndAllocFoundMBlock(NNSiFndHeapRef *o, u32 i);
void NNSi_FndFreeToUnitHeapAllocator(NNSiFndAllocator *allocator, void *block);
void *NNSi_FndAllocFromVramAllocator(NNSiFndAllocator *allocator, u32 size);
void NNSi_FndFreeToVramAllocator(NNSiFndAllocator *allocator, void *ptr);
/* END mkheaders: generated region */

#endif
