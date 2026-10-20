#ifndef GAME_OV114_NHTTP_STDLIB_NTR_H
#define GAME_OV114_NHTTP_STDLIB_NTR_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nhttp_stdlib_ntr.c, prototypes copied from their definitions. */

#include "../types.h"

void NHTTPi_memcpy(void *dst, void *src, u32 size);
int NHTTPi_strlen(const char *s);
int NHTTPi_strnlen(const char *s, int maxLen);
int NHTTPi_strcmp(const char *s1, const char *s2);
void NHTTPi_memclr(void *dst_p, int size);
int NHTTPi_strnicmp(const char *p1_p, const char *p2_p, int size);
int NHTTPi_getUrlEncodedSize(char *s);
int NHTTPi_getUrlEncodedSize2(char *p_p, int len);
int NHTTPi_encodeUrlChar(char *dst, int c);
int NHTTPi_strToHex(char *p_p, int len);
int NHTTPi_strToInt(signed char *s, int len);
int NHTTPi_intToStr(char *p_p, unsigned long n);
int NHTTPi_compareToken(char *p1_p, char *p2_p);
int NHTTPi_strtonum(char *p_p, int size);
int NHTTPi_memfind(signed char *hay, int len1, signed char *needle, int len2);
int NHTTPi_Base64Encode(char *dst_p, const char *src_p);
/* END mkheaders: generated region */

#endif
