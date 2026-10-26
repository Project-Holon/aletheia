#ifndef GAME_OV016_ARCHIVE_H
#define GAME_OV016_ARCHIVE_H

#include "../sdk_fs.h"

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of archive.c, prototypes copied from their definitions. */

void DWCi_ARClInit(void);
void DWCi_ARClEnd(void);
FSResult DWCi_ARClCbWrite(struct FSArchive *unused0, const void *unused1, u32 unused2, u32 unused3);
void *DWCi_ARClReadEx(char *path, unsigned long *size, int alignment);
void DWCi_ARClRelease(void *file);
/* END mkheaders: generated region */

#endif
