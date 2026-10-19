/*
 * file:     gpikeys.c
 * unit:     yes
 * function: gpiStatusInfoKeyFree, gpiStatusInfoKeysInit, gpiStatusInfoKeysDestroy, gpiStatusInfoKeyCompFunc, gpiStatusInfoAddKey, gpiStatusInfoSetKey, gpiStatusInfoCheckKey, gpiSaveKeysToBuffer
 * address:  0x0218D7CC
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
 *   gsifree  0x0217EAE0  arm  ov009
 *   ArrayNew  0x02184144  arm  ov009
 *   gpiSetErrorString  0x02193734  arm  ov009
 *   gGpiKeysErrorOutOfMemory  0x021A4D80  data
 *   ArrayFree  0x021841B0  arm  ov009
 *   strcmp                0x020948E0  arm
 *   goastrdup  0x0217F1E0  arm  ov009
 *   ArrayInsertSorted  0x021842D0  arm  ov009
 *   gGpiKeysErrorInvalidName  0x021A4D90  data
 *   gGpiKeysErrorInvalidValue  0x021A4DA4  data
 *   gpiStatusInfoKeyCompFunc  0x0218D864  arm  ov009
 *   ArraySearch  0x021843E8  arm  ov009
 *   ArrayNth  0x02184208  arm  ov009
 *   ArrayLength  0x02184200  arm   ov009
 *   OS_SPrintf  0x02084F40  arm
 *   strlen  0x0209477C  arm
 *   gsimalloc  0x0217EAB0  arm   ov009
 *   gsDebugFormat  0x0217D254  arm   ov009
 *   strcat  0x020948B0  arm
 *   B64Encode  0x0217FA90  arm   ov009
 *   gGpiKeysHeaderFmt     0x021A4DB8  data
 *   gGpiKeysDebugSaveOom     0x021A4DC4  data
 *   gGpiKeysStringFmt     0x021A4DF0  data
 *   gGpiKeysBackslash     0x021A4DF4  data
 */
typedef struct GPIKey {
    char *keyName;
    char *keyValue;
} GPIKey;

typedef struct GPIConnection {
    char pad0[0x3b4];
    void *extendedInfoKeys;
} GPIConnection;

#include "../types.h"

extern void gsifree(void *ptr);
struct DArrayImplementation;
extern struct DArrayImplementation *ArrayNew(int elemSize, int numElems, void (*freeFn)(void *));
extern void gpiSetErrorString(int *p, int b);
struct DArrayImplementation;
extern void ArrayFree(struct DArrayImplementation *array);
extern int strcmp(const char *s1, const char *s2);
extern char *goastrdup(char *src);
extern void ArrayInsertSorted(struct DArrayImplementation *array, void *newElem, int (*comparator)(void *, void *));
extern int ArraySearch(struct DArrayImplementation *array, void *key, int (*comparator)(void *, void *), int fromIndex, int isSorted);
extern void *ArrayNth(struct DArrayImplementation *array, int n);
extern int ArrayLength(const int *p);
extern int OS_SPrintf(char *dst, const char *fmt, ...);
extern int strlen(const u8 *s);
extern void *gsimalloc(unsigned long size);
extern void gsDebugFormat(int cat, int type, int level, char *fmt, ...);
extern u8 *strcat(u8 *dest, const u8 *src);
extern void B64Encode(const char *input, char *output, int inlen, int encodingType);
/*
 * sdk: gpiStatusInfoKeyFree (libdwcgsgp.TWL.HYB.a(gpikeys.o))
 */
void gpiStatusInfoKeyFree(void *element);
/*
 * sdk: gpiStatusInfoKeysInit (libdwcgsgp.TWL.HYB.a(gpikeys.o))
 */
int gpiStatusInfoKeysInit(void **connection);
/*
 * sdk: gpiStatusInfoKeysDestroy (libdwcgsgp.TWL.HYB.a(gpikeys.o))
 */
void gpiStatusInfoKeysDestroy(void **connection);
int gpiStatusInfoKeyCompFunc(char **elem1, char **elem2);
/*
 * sdk: gpiStatusInfoAddKey (libdwcgsgp.TWL.HYB.a(gpikeys.o))
 */
int gpiStatusInfoAddKey(void **connection, void *keys, char *theKeyName, char *theKeyValue);
/*
 * sdk: gpiStatusInfoSetKey (libdwcgsgp.TWL.HYB.a(gpikeys.o))
 */
int gpiStatusInfoSetKey(void **connection, void *keys, char *keyName, char *newKeyValue);
int gpiStatusInfoCheckKey(void **connection, void *keys, char *keyName, char **keyValue);
int gpiSaveKeysToBuffer(void **connection, char **buffer);
extern char gGpiKeysErrorOutOfMemory[];
extern char gGpiKeysErrorInvalidName[];
extern char gGpiKeysErrorInvalidValue[];
extern char gGpiKeysHeaderFmt[];
extern char gGpiKeysDebugSaveOom[];
extern char gGpiKeysStringFmt[];
extern char gGpiKeysBackslash[];

/*
 * sdk:      gpiStatusInfoKeyFree (libdwcgsgp.TWL.HYB.a(gpikeys.o))
 */
void gpiStatusInfoKeyFree(void *element)
{
    struct GPIKey *aKey = (struct GPIKey *)element;

    gsifree(aKey->keyName);
    aKey->keyName = 0;
    gsifree(aKey->keyValue);
    aKey->keyValue = 0;
}

/*
 * sdk:      gpiStatusInfoKeysInit (libdwcgsgp.TWL.HYB.a(gpikeys.o))
 */
int gpiStatusInfoKeysInit(void **connection)
{
    struct GPIConnection *iconnection = (struct GPIConnection *)*connection;
    int result = 1;

    iconnection->extendedInfoKeys = ArrayNew(8, result, gpiStatusInfoKeyFree);
    if (iconnection->extendedInfoKeys != 0)
        return 0;
    gpiSetErrorString((int *)connection, (int)gGpiKeysErrorOutOfMemory);
    return result;
}

/*
 * sdk:      gpiStatusInfoKeysDestroy (libdwcgsgp.TWL.HYB.a(gpikeys.o))
 */
void gpiStatusInfoKeysDestroy(void **connection)
{
    struct GPIConnection *iconnection = (struct GPIConnection *)*connection;

    if (iconnection->extendedInfoKeys == 0)
        return;
    ArrayFree(iconnection->extendedInfoKeys);
    iconnection->extendedInfoKeys = 0;
}

int gpiStatusInfoKeyCompFunc(char **elem1, char **elem2)
{
    return strcmp(*elem1, *elem2);
}

/*
 * sdk:      gpiStatusInfoAddKey (libdwcgsgp.TWL.HYB.a(gpikeys.o))
 */
int gpiStatusInfoAddKey(void **connection, void *keys, char *theKeyName, char *theKeyValue)
{
    struct GPIKey aKey;

    if (theKeyName == 0) {
        gpiSetErrorString((int *)connection, (int)gGpiKeysErrorInvalidName);
        return 2;
    }
    if (theKeyValue == 0) {
        gpiSetErrorString((int *)connection, (int)gGpiKeysErrorInvalidValue);
        return 2;
    }
    aKey.keyName = goastrdup(theKeyName);
    aKey.keyValue = goastrdup(theKeyValue);
    ArrayInsertSorted(keys, &aKey, (int (*)(void *, void *))gpiStatusInfoKeyCompFunc);
    return 0;
}

/*
 * sdk:      gpiStatusInfoSetKey (libdwcgsgp.TWL.HYB.a(gpikeys.o))
 */
int gpiStatusInfoSetKey(void **connection, void *keys, char *keyName, char *newKeyValue)
{
    struct GPIKey aKey;
    struct GPIKey *aKeyFound;
    int anIndex;

    if (keyName == 0) {
        gpiSetErrorString((int *)connection, (int)gGpiKeysErrorInvalidName);
        return 2;
    }
    aKey.keyName = goastrdup(keyName);
    anIndex = ArraySearch(keys, &aKey, (int (*)(void *, void *))gpiStatusInfoKeyCompFunc, 0, 1);
    if (anIndex != -1) {
        aKeyFound = (struct GPIKey *)ArrayNth(keys, anIndex);
        gsifree(aKeyFound->keyValue);
        aKeyFound->keyValue = goastrdup(newKeyValue);
    }
    gsifree(aKey.keyName);
    aKey.keyName = 0;
    return 0;
}

/*
 * sdk:      gpiStatusInfoCheckKey (libdwcgsgp.TWL.HYB.a(gpikeys.o))
 */
int gpiStatusInfoCheckKey(void **connection, void *keys, char *keyName, char **keyValue)
{
    struct GPIKey aKey;
    struct GPIKey *aKeyFound;
    int anIndex;

    if (keyName == 0) {
        gpiSetErrorString((int *)connection, (int)gGpiKeysErrorInvalidName);
        return 2;
    }
    aKey.keyName = goastrdup(keyName);
    anIndex = ArraySearch(keys, &aKey, (int (*)(void *, void *))gpiStatusInfoKeyCompFunc, 0, 1);
    if (anIndex != -1) {
        aKeyFound = (struct GPIKey *)ArrayNth(keys, anIndex);
        *keyValue = aKeyFound->keyValue;
    }
    gsifree(aKey.keyName);
    aKey.keyName = 0;
    return 0;
}

static inline int B64LEN(char *s)
{
    return ((unsigned long)strlen((const u8 *)s) % 3) ? ((4 - (unsigned long)strlen((const u8 *)s) % 3) + (unsigned long)strlen((const u8 *)s) * 4 / 3) : ((unsigned long)strlen((const u8 *)s) * 4 / 3);
}

static inline void B64ADV(char **p, char *s)
{
    if ((unsigned long)strlen((const u8 *)s) % 3)
        *p += (4 - (unsigned long)strlen((const u8 *)s) % 3) + (unsigned long)strlen((const u8 *)s) * 4 / 3;
    else
        *p += (unsigned long)strlen((const u8 *)s) * 4 / 3;
}

static inline void B64ENC(char *s, char *out)
{
    B64Encode(s, out, (int)(unsigned long)strlen((const u8 *)s), 2);
}

/*
 * sdk:      gpiSaveKeysToBuffer (gpikeys.o)
 *
 * strcat (strcat, arm9) attests as matched through unit_02094860, whose
 * functions list names strcat since 2026-09-29 (w4_nm).
 * The Base64 length and encode helpers are static inline so that the key
 * string is loaded once per use, as the object loads it (a macro reloads it).
 */
int gpiSaveKeysToBuffer(void **connection, char **buffer)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;
    char *tempPoint;
    int sizeKeys = 0;
    int i;
    int bytesWritten;
    int base64KeyNameLen;
    int base64KeyValLen;
    int aLength;
    char keysHeader[64];

    aLength = ArrayLength(iconnection->extendedInfoKeys);
    OS_SPrintf(keysHeader, gGpiKeysHeaderFmt, aLength);

    for (i = 0; i < aLength; i++) {
        GPIKey *aKey = (GPIKey *)ArrayNth(iconnection->extendedInfoKeys, i);
        base64KeyNameLen = B64LEN(aKey->keyName);
        base64KeyValLen = B64LEN(aKey->keyValue);
        sizeKeys += base64KeyNameLen + 2 + base64KeyValLen;
    }

    *buffer = (char *)gsimalloc((unsigned long)strlen((const u8 *)keysHeader) + sizeKeys + 1);
    if (*buffer == 0) {
        gsDebugFormat((int)1, (int)2, 1, gGpiKeysDebugSaveOom);
        gpiSetErrorString((int *)connection, (int)gGpiKeysErrorOutOfMemory);
        return 1;
    }

    bytesWritten = OS_SPrintf(*buffer, gGpiKeysStringFmt, keysHeader);
    tempPoint = *buffer + bytesWritten;

    for (i = 0; i < aLength; i++) {
        GPIKey *aKey = (GPIKey *)ArrayNth(iconnection->extendedInfoKeys, i);
        strcat((u8 *)tempPoint, (const u8 *)gGpiKeysBackslash);
        tempPoint++;
        B64ENC(aKey->keyName, tempPoint);
        B64ADV(&tempPoint, aKey->keyName);
        strcat((u8 *)tempPoint, (const u8 *)gGpiKeysBackslash);
        tempPoint++;
        B64ENC(aKey->keyValue, tempPoint);
        B64ADV(&tempPoint, aKey->keyValue);
    }
    return 0;
}
