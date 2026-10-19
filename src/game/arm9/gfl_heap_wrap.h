#ifndef GAME_ARM9_GFL_HEAP_WRAP_H
#define GAME_ARM9_GFL_HEAP_WRAP_H

/* Public functions of gfl_heap_wrap.c, prototypes copied from their definitions. */

void GFL_HEAP_DeleteChecked(u32 heapId);
void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
u32 GFL_HEAP_Free(void *block);
void GFL_HEAP_InitAllocatorChecked(void *block, u32 heapId, s32 newSize);
void GFL_HEAP_CheckAllocator(void *block, u32 size);
void *GFL_HEAP_GetHeapHead(u32 heapId);
void *GFL_HEAP_GetHeapHeadChecked(u32 heapId);
void GFL_HEAP_StampAllocSite(void *payload, const char *site, u16 tag);
int GFL_HEAP_ReadAllocSiteName(u8 *nameBuf, const char *blockName);
void GFL_HEAP_ReportOutOfMemory(u32 heapId, u32 size, const char *site, int tag);
void GFL_HEAP_AuditAlloc(void *payload, u32 size);
void GFL_HEAP_AuditFree(void *payload);
void GFL_HEAP_NotifyAlloc(u32 heapId, void *payload, u32 size);
void GFL_HEAP_NotifyFree(void *payload);
void GFL_HEAP_DumpIfLive(u32 heapId);
void GFL_HEAP_WalkBlocksCallback(void *block, int *heap, u32 userParam);
void GFL_HEAP_DumpReport(u32 heapId);
void GFL_HEAP_InitSystemHeapChecked(u32 size);
void *GFL_HEAP_AllocSystemChecked(u32 size);
int GFL_HEAP_FreeSystemChecked(u32 idx);

#endif
