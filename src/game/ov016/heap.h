#ifndef GAME_OV016_HEAP_H
#define GAME_OV016_HEAP_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of heap.c, prototypes copied from their definitions. */

void DWCi_HEAPlInit(void *address);
void DWCi_HEAPlEnd(void);
void *DWCi_HEAPlAlloc(unsigned long size, int alignment);
void *DWCi_HEAPlAllocEx(unsigned long size, int alignment);
void DWCi_HEAPlFree_(void **mem);
void DWCi_HEAPlFree2(void *mem);
/* END mkheaders: generated region */

#endif
