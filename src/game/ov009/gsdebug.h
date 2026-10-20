#ifndef GAME_OV009_GSDEBUG_H
#define GAME_OV009_GSDEBUG_H

#include "../sdk_stdarg.h"

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gsdebug.c, prototypes copied from their definitions. */

void gsiDebugCallback(int cat, int type, int level, const char *fmt, va_list args);
void gsDebugFormat(int cat, int type, int level, const char *fmt, ...);
void HexEncode16(char *theInStream, char *theOutStream, unsigned int theInLen);
void gsDebugBinary(int theCat, int theType, unsigned char theLevel, char *theBuffer, int theLength);
/* END mkheaders: generated region */

#endif
