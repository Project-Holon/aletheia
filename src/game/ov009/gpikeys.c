/*
 * file:     gpikeys.c
 * unit:     yes
 * function: func_0218D7CC, func_0218D7F4, func_0218D840, func_0218D864, func_0218D878, func_0218D900, func_0218D9A8, func_0218DA40
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
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 *   func_02184144  0x02184144  arm  ov009
 *   func_02193734  0x02193734  arm  ov009
 *   g_021A4D80  0x021A4D80  data
 *   func_021841B0  0x021841B0  arm  ov009
 *   func_020948E0                0x020948E0  arm
 *   func_0217F1E0  0x0217F1E0  arm  ov009
 *   func_021842D0  0x021842D0  arm  ov009
 *   g_021A4D90  0x021A4D90  data
 *   g_021A4DA4  0x021A4DA4  data
 *   func_0218D864  0x0218D864  arm  ov009
 *   func_021843E8  0x021843E8  arm  ov009
 *   func_02184208  0x02184208  arm  ov009
 *   func_02184200  0x02184200  arm   ov009
 *   OS_SPrintf  0x02084F40  arm
 *   func_0209477C  0x0209477C  arm
 *   func_0217EAB0  0x0217EAB0  arm   ov009
 *   func_0217D254  0x0217D254  arm   ov009
 *   func_020948B0  0x020948B0  arm
 *   func_0217FA90  0x0217FA90  arm   ov009
 *   g_021A4DB8     0x021A4DB8  data
 *   g_021A4DC4     0x021A4DC4  data
 *   g_021A4DF0     0x021A4DF0  data
 *   g_021A4DF4     0x021A4DF4  data
 */
typedef struct GPIKey {
    char *keyName;
    char *keyValue;
} GPIKey;

typedef struct GPIConnection {
    char pad0[0x3b4];
    void *extendedInfoKeys;
} GPIConnection;

typedef unsigned char  u8;

extern void func_0217EAE0(void *ptr);
extern void *func_02184144(int elemSize, int numElems, void (*freeFn)(void *));
extern void func_02193734(int *p, int b);
extern void func_021841B0(void *array);
extern int func_020948E0(const char *s1, const char *s2);
extern char *func_0217F1E0(char *src);
extern void func_021842D0(void *array, void *newElem, int (*comparator)(void *, void *));
extern int func_0218D864(void *elem1, void *elem2);
extern int func_021843E8(void *array, void *key, int (*comparator)(void *, void *), int fromIndex, int isSorted);
extern void *func_02184208(void *array, int n);
extern int func_02184200(const int *p);
extern int OS_SPrintf(char *dst, const char *fmt, ...);
extern int func_0209477C(const u8 *s);
extern void *func_0217EAB0(unsigned long size);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern u8 *func_020948B0(u8 *dest, const u8 *src);
extern void func_0217FA90(const char *input, char *output, int inlen, int encodingType);
/*
 * sdk: gpiStatusInfoKeyFree (libdwcgsgp.TWL.HYB.a(gpikeys.o))
 */
void func_0218D7CC(void *element);
/*
 * sdk: gpiStatusInfoKeysInit (libdwcgsgp.TWL.HYB.a(gpikeys.o))
 */
int func_0218D7F4(void **connection);
/*
 * sdk: gpiStatusInfoKeysDestroy (libdwcgsgp.TWL.HYB.a(gpikeys.o))
 */
void func_0218D840(void **connection);
int gpiStatusInfoKeyCompFunc(char **elem1, char **elem2);
/*
 * sdk: gpiStatusInfoAddKey (libdwcgsgp.TWL.HYB.a(gpikeys.o))
 */
int func_0218D878(void **connection, void *keys, char *theKeyName, char *theKeyValue);
/*
 * sdk: gpiStatusInfoSetKey (libdwcgsgp.TWL.HYB.a(gpikeys.o))
 */
int func_0218D900(void **connection, void *keys, char *keyName, char *newKeyValue);
int func_0218D9A8(void **connection, void *keys, char *keyName, char **keyValue);
int func_0218DA40(void **connection, char **buffer);
extern char g_021A4D80[];
extern char g_021A4D90[];
extern char g_021A4DA4[];
extern char g_021A4DB8[];
extern char g_021A4DC4[];
extern char g_021A4DF0[];
extern char g_021A4DF4[];





/*
 * sdk:      gpiStatusInfoKeyFree (libdwcgsgp.TWL.HYB.a(gpikeys.o))
 */
void func_0218D7CC(void *element)
{
    struct GPIKey *aKey = (struct GPIKey *)element;

    func_0217EAE0(aKey->keyName);
    aKey->keyName = 0;
    func_0217EAE0(aKey->keyValue);
    aKey->keyValue = 0;
}





/*
 * sdk:      gpiStatusInfoKeysInit (libdwcgsgp.TWL.HYB.a(gpikeys.o))
 */
int func_0218D7F4(void **connection)
{
    struct GPIConnection *iconnection = (struct GPIConnection *)*connection;
    int result = 1;

    iconnection->extendedInfoKeys = func_02184144(8, result, func_0218D7CC);
    if (iconnection->extendedInfoKeys != 0)
        return 0;
    func_02193734((int *)connection, (int)g_021A4D80);
    return result;
}





/*
 * sdk:      gpiStatusInfoKeysDestroy (libdwcgsgp.TWL.HYB.a(gpikeys.o))
 */
void func_0218D840(void **connection)
{
    struct GPIConnection *iconnection = (struct GPIConnection *)*connection;

    if (iconnection->extendedInfoKeys == 0)
        return;
    func_021841B0(iconnection->extendedInfoKeys);
    iconnection->extendedInfoKeys = 0;
}





int gpiStatusInfoKeyCompFunc(char **elem1, char **elem2)
{
    return func_020948E0(*elem1, *elem2);
}





/*
 * sdk:      gpiStatusInfoAddKey (libdwcgsgp.TWL.HYB.a(gpikeys.o))
 */
int func_0218D878(void **connection, void *keys, char *theKeyName, char *theKeyValue)
{
    struct GPIKey aKey;

    if (theKeyName == 0) {
        func_02193734((int *)connection, (int)g_021A4D90);
        return 2;
    }
    if (theKeyValue == 0) {
        func_02193734((int *)connection, (int)g_021A4DA4);
        return 2;
    }
    aKey.keyName = func_0217F1E0(theKeyName);
    aKey.keyValue = func_0217F1E0(theKeyValue);
    func_021842D0(keys, &aKey, func_0218D864);
    return 0;
}





/*
 * sdk:      gpiStatusInfoSetKey (libdwcgsgp.TWL.HYB.a(gpikeys.o))
 */
int func_0218D900(void **connection, void *keys, char *keyName, char *newKeyValue)
{
    struct GPIKey aKey;
    struct GPIKey *aKeyFound;
    int anIndex;

    if (keyName == 0) {
        func_02193734((int *)connection, (int)g_021A4D90);
        return 2;
    }
    aKey.keyName = func_0217F1E0(keyName);
    anIndex = func_021843E8(keys, &aKey, func_0218D864, 0, 1);
    if (anIndex != -1) {
        aKeyFound = (struct GPIKey *)func_02184208(keys, anIndex);
        func_0217EAE0(aKeyFound->keyValue);
        aKeyFound->keyValue = func_0217F1E0(newKeyValue);
    }
    func_0217EAE0(aKey.keyName);
    aKey.keyName = 0;
    return 0;
}



/*
 * sdk:      gpiStatusInfoCheckKey (libdwcgsgp.TWL.HYB.a(gpikeys.o))
 */
int func_0218D9A8(void **connection, void *keys, char *keyName, char **keyValue)
{
    struct GPIKey aKey;
    struct GPIKey *aKeyFound;
    int anIndex;

    if (keyName == 0) {
        func_02193734((int *)connection, (int)g_021A4D90);
        return 2;
    }
    aKey.keyName = func_0217F1E0(keyName);
    anIndex = func_021843E8(keys, &aKey, func_0218D864, 0, 1);
    if (anIndex != -1) {
        aKeyFound = (struct GPIKey *)func_02184208(keys, anIndex);
        *keyValue = aKeyFound->keyValue;
    }
    func_0217EAE0(aKey.keyName);
    aKey.keyName = 0;
    return 0;
}


static inline int B64LEN(char *s)
{
    return ((unsigned long)func_0209477C((const u8 *)s) % 3) ? ((4 - (unsigned long)func_0209477C((const u8 *)s) % 3) + (unsigned long)func_0209477C((const u8 *)s) * 4 / 3) : ((unsigned long)func_0209477C((const u8 *)s) * 4 / 3);
}


static inline void B64ADV(char **p, char *s)
{
    if ((unsigned long)func_0209477C((const u8 *)s) % 3)
        *p += (4 - (unsigned long)func_0209477C((const u8 *)s) % 3) + (unsigned long)func_0209477C((const u8 *)s) * 4 / 3;
    else
        *p += (unsigned long)func_0209477C((const u8 *)s) * 4 / 3;
}


static inline void B64ENC(char *s, char *out)
{
    func_0217FA90(s, out, (int)(unsigned long)func_0209477C((const u8 *)s), 2);
}


/*
 * sdk:      gpiSaveKeysToBuffer (gpikeys.o)
 *
 * strcat (func_020948B0, arm9) attests as matched through unit_02094860, whose
 * functions list names func_020948B0 since 2026-09-29 (w4_nm).
 * The Base64 length and encode helpers are static inline so that the key
 * string is loaded once per use, as the object loads it (a macro reloads it).
 */
int func_0218DA40(void **connection, char **buffer)
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

    aLength = func_02184200(iconnection->extendedInfoKeys);
    OS_SPrintf(keysHeader, g_021A4DB8, aLength);

    for (i = 0; i < aLength; i++) {
        GPIKey *aKey = (GPIKey *)func_02184208(iconnection->extendedInfoKeys, i);
        base64KeyNameLen = B64LEN(aKey->keyName);
        base64KeyValLen = B64LEN(aKey->keyValue);
        sizeKeys += base64KeyNameLen + 2 + base64KeyValLen;
    }

    *buffer = (char *)func_0217EAB0((unsigned long)func_0209477C((const u8 *)keysHeader) + sizeKeys + 1);
    if (*buffer == 0) {
        func_0217D254(1, (char *)2, 1, g_021A4DC4);
        func_02193734((int *)connection, (int)g_021A4D80);
        return 1;
    }

    bytesWritten = OS_SPrintf(*buffer, g_021A4DF0, keysHeader);
    tempPoint = *buffer + bytesWritten;

    for (i = 0; i < aLength; i++) {
        GPIKey *aKey = (GPIKey *)func_02184208(iconnection->extendedInfoKeys, i);
        func_020948B0((u8 *)tempPoint, (const u8 *)g_021A4DF4);
        tempPoint++;
        B64ENC(aKey->keyName, tempPoint);
        B64ADV(&tempPoint, aKey->keyName);
        func_020948B0((u8 *)tempPoint, (const u8 *)g_021A4DF4);
        tempPoint++;
        B64ENC(aKey->keyValue, tempPoint);
        B64ADV(&tempPoint, aKey->keyValue);
    }
    return 0;
}
