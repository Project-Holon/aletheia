#ifndef GAME_ARM9_STD_STRING_H
#define GAME_ARM9_STD_STRING_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of std_string.c, prototypes copied from their definitions. */

char *STD_CopyString(char *destp, const char *srcp);
int STD_CopyLString(char *destp, const char *srcp, int siz);
char *STD_SearchString(const char *srcp, const char *str);
int STD_GetStringLength(const char *str);
int STD_GetStringNLength(const char *str, int len);
int STD_CompareString(const char *str1, const char *str2);
int STD_CompareNString(const char *str1, const char *str2, int len);
int STD_TSScanf(char *dst, const char *fmt, ...);
int STDi_IsSpace(int c);
void STDi_FillBitset(unsigned long *bitset, unsigned long start, unsigned long end);
/* END mkheaders: generated region */

#endif
