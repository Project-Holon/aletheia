#ifndef GAME_OV114_CRYPTO_UTIL_H
#define GAME_OV114_CRYPTO_UTIL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of crypto_util.c, prototypes copied from their definitions. */

void *CRYPTOi_MyAlloc(unsigned long size);
void CRYPTOi_MyFree(void *ptr);
void CRYPTO_SetMemAllocator(void *(*allocFunc)(unsigned long), void (*freeFunc)(void *), void *(*reallocFunc)(void *, unsigned long));
/* END mkheaders: generated region */

#endif
