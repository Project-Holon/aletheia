#ifndef GAME_ARM9_DWC_MEMFUNC_H
#define GAME_ARM9_DWC_MEMFUNC_H

/* Public functions of dwc_memfunc.c, prototypes copied from their definitions. */

void *DWCi_GetAllocateHeader(char *p);
void *DWCi_SetAllocateHeader(void *ptr, unsigned long size);
unsigned long DWCi_GetAllocateSize(char *ptr);
void *DWC_Alloc(int name, unsigned long size);
void *DWC_AllocEx(int name, unsigned long size, int align);
void DWC_Free(int name, void *ptr, unsigned long size);
void *DWC_Realloc(int name, void *ptr, unsigned long oldsize, unsigned long newsize);
void *DWC_ReallocEx(int name, void *ptr, unsigned long oldsize, unsigned long newsize, int align);
void *DWCi_GsMalloc(unsigned long size);
void *DWCi_GsRealloc(void *ptr, unsigned long size);
void DWCi_GsFree(void *ptr);
void *DWCi_GsMemalign(unsigned long boundary, unsigned long size);

#endif
