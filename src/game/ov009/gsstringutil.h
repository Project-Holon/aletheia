#ifndef GAME_OV009_GSSTRINGUTIL_H
#define GAME_OV009_GSSTRINGUTIL_H

#include "../ov009/gsudp_types.h"

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gsstringutil.c, prototypes copied from their definitions. */

#include "../types.h"

int _ReadUCS2CharFromUTF8String(char *theUTF8String, int theMaxBytes, unsigned short *theUnicodeCharOut);
int _UCS2CharToUTF8String(unsigned short theUCS2Char, char *theUTF8String);
int _UTF8ToUCS2ConversionLengthOnly(const char *s, int n);
unsigned short *UTF8ToUCS2StringAlloc(char *theUTF8String);
unsigned short *UTF8ToUCS2StringAllocLen(char *theUTF8String, int theUTF8StringLength);
int UTF8ToUCS2StringLen2(const unsigned char *src, int size, u16 *out, int max);
int gsiSafeStrcpyA(char *dst, const char *src, unsigned int n);
GSUdpEngineObject *gsUdpEngineContext(void);
/* END mkheaders: generated region */

#endif
