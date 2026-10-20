#ifndef GAME_OV009_GSMEMORY_H
#define GAME_OV009_GSMEMORY_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gsmemory.c, prototypes copied from their definitions. */

void *_gsi_memalign(unsigned long boundary, unsigned long size);
void gsiMemoryCallbacksSet(void *(*p_malloc)(unsigned long), void (*p_free)(void *), void *(*p_realloc)(void *, unsigned long), void *(*p_memalign)(unsigned long, unsigned long));
void *gsimalloc(unsigned long size);
void *gsirealloc(void *ptr, unsigned long size);
void gsifree(void *p);
/* END mkheaders: generated region */

#endif
