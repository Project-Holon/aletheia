#ifndef GAME_OV016_LIBAOSS_H
#define GAME_OV016_LIBAOSS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of libaoss.c, prototypes copied from their definitions. */

void DWCi_AOSSlInit(void);
void DWCi_AOSSlEnd(int a);
int DWCi_AOSSlStart(void);
void *aossAlloc(unsigned long size);
void aossFree(void *ptr);
/* END mkheaders: generated region */

#endif
