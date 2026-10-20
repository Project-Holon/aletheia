#ifndef GAME_OV016_ARCHIVE_H
#define GAME_OV016_ARCHIVE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of archive.c, prototypes copied from their definitions. */

void DWCi_ARClInit(void);
void DWCi_ARClEnd(void);
int DWCi_ARClCbWrite(void);
void *DWCi_ARClReadEx(char *path, unsigned long *size, int alignment);
void DWCi_ARClRelease(void *file);
/* END mkheaders: generated region */

#endif
