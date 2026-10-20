#ifndef GAME_OV009_MD5C_H
#define GAME_OV009_MD5C_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of md5c.c, prototypes copied from their definitions. */

#include "../ov175/auth_types.h"
#include "../types.h"

void GSMD5Init(GSMD5_CTX * context);
void GSMD5Update(GSMD5_CTX * context, unsigned char * input, unsigned int inputLen);
void GSMD5Final(unsigned char * digest, GSMD5_CTX * context);
void *GSMD5_memcpy(void *dest, const void *src, unsigned int n);
void *GSMD5_memset(void *p, int c, u32 n);
void GSMD5Print(unsigned char * digest, char * output);
void GSMD5Digest(unsigned char * input, unsigned int len, char * output);
/* END mkheaders: generated region */

#endif
