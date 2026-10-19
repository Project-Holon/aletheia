#ifndef GAME_OV009_DWC_RAPCOMMON_H
#define GAME_OV009_DWC_RAPCOMMON_H

/* Public functions of dwc_rapcommon.c, prototypes copied from their definitions. */

void DWC_RAPCOMMON_InitDwcWithNotice(int heapId);
void DWC_RAPCOMMON_CreateSubHeapUnlimited(int ownerId, int size, int heapId);
void DWC_RAPCOMMON_CreateSubHeap(u32 ownerId, u32 size, u32 minRequestSize, u32 heapId);
void DWC_RAPCOMMON_DestroySubHeap(void);
void DWC_RAPCOMMON_ReleaseSubHeap(void);
void DWC_RAPCOMMON_SetHeapTag(int tag);
u32 DWC_RAPCOMMON_Alloc(u32 ownerId, u32 size, u32 align);
void DWC_RAPCOMMON_Free(u32 ownerId, void *block, int unused);
void DWC_RAPCOMMON_CreateHeap(u32 heapId, u32 size);
void DWC_RAPCOMMON_DestroyHeap(void);
int DWC_RAPCOMMON_RunDwcInit(u16 heapId);
void DWC_RAPCOMMON_InitUserData(void *userData);
void DWC_RAPCOMMON_ClearNetError(void);
int DWC_RAPCOMMON_HandleNetError(int hasSession, int keepError);

#endif
