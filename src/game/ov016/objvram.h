#ifndef GAME_OV016_OBJVRAM_H
#define GAME_OV016_OBJVRAM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of objvram.c, prototypes copied from their definitions. */

void DWCi_OVRlInit(void);
void *DWCi_OVRlAlloc(int lcd, int num, int head, int *name);
void DWCi_OVRlFree(void *ovram);
/* END mkheaders: generated region */

#endif
