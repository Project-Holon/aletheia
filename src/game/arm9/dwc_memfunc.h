#ifndef GAME_ARM9_DWC_MEMFUNC_H
#define GAME_ARM9_DWC_MEMFUNC_H

typedef void *(*DWCiMemAlloc)(int, unsigned long, int);
typedef void (*DWCiMemFree)(int, void *, unsigned long);

void DWCi_SetMemFunc(DWCiMemAlloc alloc, DWCiMemFree free);

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dwc_memfunc.c, prototypes copied from their definitions. */

void *DWCi_GetAllocateHeader(char *p);
void *DWCi_SetAllocateHeader(void *ptr, unsigned long size);
unsigned long DWCi_GetAllocateSize(char *ptr);
void DWCi_SetMemFunc(DWCiMemAlloc alloc, DWCiMemFree free);
void *DWC_Alloc(int name, unsigned long size);
void *DWC_AllocEx(int name, unsigned long size, int align);
void DWC_Free(int name, void *ptr, unsigned long size);
void *DWC_Realloc(int name, void *ptr, unsigned long oldsize, unsigned long newsize);
void *DWC_ReallocEx(int name, void *ptr, unsigned long oldsize, unsigned long newsize, int align);
void *DWCi_GsMalloc(unsigned long size);
void *DWCi_GsRealloc(void *ptr, unsigned long size);
void DWCi_GsFree(void *ptr);
void *DWCi_GsMemalign(unsigned long boundary, unsigned long size);
/* END mkheaders: generated region */

#ifndef __MWERKS__
/* Allocator callbacks with the SDK typedef signatures (DWCAuthAlloc, ACAllocFunc), calling DWC_Alloc and DWC_Free. */
void *DWC_AllocCallback(unsigned long name, long size);
void DWC_FreeCallback(unsigned long name, void *ptr, long size);
#endif

#endif
