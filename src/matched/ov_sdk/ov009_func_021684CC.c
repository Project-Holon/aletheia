/*
 * function: func_021684CC
 * address:  0x021684CC
 * packet:   pkt_ov009_021684CC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_GetCommonValueString (libdwcmatch.TWL.HYB.a(dwc_common.o))
 *
 * symbols:
 *   strchr   0x02094A28  arm
 *   strlen   0x0209477C  arm
 *   strncmp  0x020949F4  arm
 *   strncpy  0x02094860  arm
 */

#include "../arm9_sdk/libc/string.h"
extern char *strchr(const char *s, int c);
extern int strncmp(const char *a, const char *b, unsigned long n);
extern char *strncpy(char *d, const char *s, unsigned long n);

int func_021684CC(char *key, char *value, char *string, char separator)
{
    int len;
    char *pSrcEnd;
    char *pSrcBegin;

    pSrcBegin = strchr(string, separator);
    if (pSrcBegin == 0)
        return -1;
    for (;;) {
        if (strncmp(pSrcBegin + 1, key, strlen(key)) == 0) {
            len = strlen(key);
            if (separator == *(char *)(len + (int)pSrcBegin + 1))
                break;
        }
        pSrcBegin = strchr(pSrcBegin + 1, separator);
        if (pSrcBegin == 0)
            return -1;
        pSrcBegin = strchr(pSrcBegin + 1, separator);
        if (pSrcBegin == 0)
            return -1;
    }
    pSrcBegin = strchr(pSrcBegin + 1, separator);
    if (pSrcBegin == 0)
        return -1;
    pSrcEnd = strchr(pSrcBegin + 1, separator);
    if (pSrcEnd != 0)
        len = pSrcEnd - (pSrcBegin + 1);
    else
        len = strlen(pSrcBegin + 1);
    if (value == 0)
        return len;
    strncpy(value, pSrcBegin + 1, len);
    value[len] = 0;
    return len;
}
