#ifndef GAME_ARM9_GFL_HEAP_H
#define GAME_ARM9_GFL_HEAP_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gfl_heap.c, prototypes copied from their definitions. */

struct HeapSpec;

#include "../types.h"

void *GFL_HEAP_GetHeap(u32 heapId);
void *GFL_HEAP_GetParentHeap(u32 heapId);
void *GFL_HEAP_GetBlock(u32 heapId);
u16 GFL_HEAP_GetAllocCount(u32 heapId);
int GFL_HEAP_InitManager(const struct HeapSpec *specs, u16 staticCount, u16 heapIdCount, u32 extraSize);
int GFL_HEAP_CreateChildHeapImpl(u32 parentHeapId, u32 newHeapId, u32 size);
int GFL_HEAP_RegisterBlockHeapImpl(void *block, u32 size, u32 newHeapId);
int GFL_HEAP_AddRecord(void *parentHeap, u32 heapId, void *block, u32 size);
u32 GFL_HEAP_Delete(u32 heapHandle);
void *GFL_HEAP_AllocMemory(u32 heapId, u32 size);
u32 GFL_HEAP_FreeMemory(void *mem);
u32 GFL_HEAP_InitAllocator(void *allocator, u32 heapIdAndDirection, s32 alignment);
u32 GFL_HEAP_ResizeMemory(void *mem, u32 newSize);
u32 GFL_HEAP_GetTotalFreeSize(u32 heapId);
u32 GFL_HEAP_GetAllocatableSize(u32 heapId);
u32 GFL_HEAP_GetHeapSize(u32 heapId);
void *GFL_HEAP_GetHeapHandle(u32 heapId);
u16 GFL_HEAP_GetAllocCountById(u32 heapId);
u16 GFL_HEAP_GetBlockHeapId(void *mem);
void *GFL_HEAP_GetBlockName(void *mem);
u32 GFL_HEAP_IsHeapValid(u32 heapId);
u16 GFL_HEAP_GetLastError(void);
BOOL GFL_HEAP_InitSystemHeap(u32 size);
void *GFL_HEAP_AllocSystem(u32 size);
int GFL_HEAP_FreeSystem(void *mem);
void GFL_HEAP_Init(u8 *specs, u32 staticCount, u32 heapIdCount, u32 extraSize);
void GFL_HEAP_CreateChildHeap(u32 parentHeapId, u32 newHeapId, u32 size);
void GFL_HEAP_RegisterBlockHeap(void *block, u32 size, u32 newHeapId);
void GFL_HEAP_FatalError(int errorCode, u32 parentHeapId, u32 newHeapId);
/* END mkheaders: generated region */

#endif
