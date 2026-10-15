/*
 * file:     dwc_common.c
 * unit:     yes
 * function: DWC_SetCommonKeyValueString, DWC_AddCommonKeyValueString, DWC_GetCommonValueString, func_021685CC, DWCi_WStrLen
 * address:  0x02168454
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021A1FF8  0x021A1FF8  data
 *   OS_SNPrintf  0x02084F80  arm
 *   strlen  0x0209477C  arm
 *   strchr  0x02094A28  arm
 *   strchr   0x02094A28  arm
 *   strlen   0x0209477C  arm
 *   strncmp  0x020949F4  arm
 *   strncpy  0x02094860  arm
 *   OS_GetMacAddress  0x02087C6C  arm
 *   OS_GetTick        0x020870D0  arm
 *   _ZZ13func_021685CCmE15stRandContext32  0x021AA848  data
 */
#include "../../matched/arm9_sdk/libc/string.h"
extern int strncmp(const char *a, const char *b, unsigned long n);
extern char *strncpy(char *d, const char *s, unsigned long n);
extern char *strchr(const char *s, int c);

typedef unsigned char  u8;

typedef unsigned long u32;

typedef unsigned long long u64;

typedef struct {
    u64 x;
    u64 mul;
    u64 add;
} MATHRandContext32;

extern int OS_SNPrintf(char *dst, int len, const char *fmt, ...);
extern void OS_GetMacAddress(u8 *macAddress);
extern u64 OS_GetTick(void);
/* * DWC_SetCommonKeyValueString: writes one separator-key-separator-value pair and returns its length. */ int DWC_SetCommonKeyValueString(const char *key, const char *value, char *string, char sep);
/* * DWC_AddCommonKeyValueString: appends one key-value pair and returns the whole string's length. */ int DWC_AddCommonKeyValueString(const char *key, const char *value, char *string, char sep);
int DWC_GetCommonValueString(char *key, char *value, char *string, char separator);
/* * lane18 (2026-10-01): EXACT. dwc_common.o's stRandContext32 is a data-local static: * declared as a function-local static (non-aliasing in 1.1p1) with the SDK inlines * MATH_InitRand32/MATH_Rand32, the .bss pool word and the fresh x-store word both fall out. * * sdk: func_021685CC (libdwcmatch.TWL.HYB.a(dwc_common.o)) */ u32 func_021685CC(u32 max);
/* * Returns the index of the first zero halfword in the array. */ int DWCi_WStrLen(unsigned short *p);
extern char d_021A1FF8[];




/*
 * DWC_SetCommonKeyValueString: writes one separator-key-separator-value pair and returns its length.
 */
int DWC_SetCommonKeyValueString(const char *key, const char *value, char *string, char sep)
{
    OS_SNPrintf(string, 0x1000, d_021A1FF8, sep, key, sep, value);
    return strlen((const char *)string);
}




/*
 * DWC_AddCommonKeyValueString: appends one key-value pair and returns the whole string's length.
 */
int DWC_AddCommonKeyValueString(const char *key, const char *value, char *string, char sep)
{
    DWC_SetCommonKeyValueString(key, value, strchr(string, 0), sep);
    return strlen((const char *)string);
}



/*
 * sdk:      DWC_GetCommonValueString (libdwcmatch.TWL.HYB.a(dwc_common.o))
 */
int DWC_GetCommonValueString(char *key, char *value, char *string, char separator)
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



static inline void MATH_InitRand32(MATHRandContext32 *context, u64 seed)
{
    context->x = seed;
    context->mul = (1566083941LL << 32) + 1812433253LL;
    context->add = 2531011;
}



static inline u32 MATH_Rand32(MATHRandContext32 *context, u32 max)
{
    context->x = context->mul * context->x + context->add;
    if (max == 0) {
        return (u32)(context->x >> 32);
    } else {
        return (u32)(((context->x >> 32) * max) >> 32);
    }
}



/*
 * lane18 (2026-10-01): EXACT. dwc_common.o's stRandContext32 is a data-local static:
 *   declared as a function-local static (non-aliasing in 1.1p1) with the SDK inlines
 *   MATH_InitRand32/MATH_Rand32, the .bss pool word and the fresh x-store word both fall out.
 *
 * sdk:      func_021685CC (libdwcmatch.TWL.HYB.a(dwc_common.o))
 */
u32 func_021685CC(u32 max)
{
    static MATHRandContext32 stRandContext32;
    u64 seed;

    if (stRandContext32.x == 0 && stRandContext32.mul == 0 && stRandContext32.add == 0) {
        OS_GetMacAddress((u8 *)&seed);
        seed = ((seed >> 24) & 0xFFFFFF) | (OS_GetTick() << 24);
        MATH_InitRand32(&stRandContext32, seed);
    }
    return MATH_Rand32(&stRandContext32, max);
}


/*
 * Returns the index of the first zero halfword in the array.
 */
int DWCi_WStrLen(unsigned short *p)
{
    int i = 0;

    while (p[i] != 0) i++;
    return i;
}
