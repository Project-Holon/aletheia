#ifndef GAME_OV114_GHTTPCALLBACKS_H
#define GAME_OV114_GHTTPCALLBACKS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of ghttpcallbacks.c, prototypes copied from their definitions. */

#include "../ov114/ghttp_types.h"

void ghiCallCompletedCallback(GHIConnection *connection);
void ghiCallProgressCallback(GHIConnection *connection, char *buffer, int bufferLen);
void ghiCallPostCallback(GHIConnection *connection);
void ghiInitLock(void);
void ghiFreeLock(void);
void ghiLock(void);
void ghiUnlock(void);
/* END mkheaders: generated region */

#endif
