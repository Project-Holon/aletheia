/*
 * function: gpiSaveKeysToBuffer
 * address:  0x0218DA40
 * packet:   pkt_ov009_0218DA40
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiSaveKeysToBuffer (gpikeys.o)
 *
 * symbols:
 *   ArrayLength  0x02184200  arm   ov009
 *   OS_SPrintf  0x02084F40  arm
 *   func_02184208  0x02184208  arm   ov009
 *   strlen  0x0209477C  arm
 *   gsimalloc  0x0217EAB0  arm   ov009
 *   gsDebugFormat  0x0217D254  arm   ov009
 *   gpiSetErrorString  0x02193734  arm   ov009
 *   strcat  0x020948B0  arm
 *   B64Encode  0x0217FA90  arm   ov009
 *   gGpiKeysHeaderFmt     0x021A4DB8  data
 *   gGpiKeysDebugSaveOom     0x021A4DC4  data
 *   gGpiKeysErrorOutOfMemory     0x021A4D80  data
 *   gGpiKeysStringFmt     0x021A4DF0  data
 *   gGpiKeysBackslash     0x021A4DF4  data
 *
 * strcat (strcat, arm9) attests as matched through unit_02094860, whose
 * functions list names strcat since 2026-09-29 (w4_nm).
 * The Base64 length and encode helpers are static inline so that the key
 * string is loaded once per use, as the object loads it (a macro reloads it).
 */

typedef struct GPIKey {
    char *keyName;
    char *keyValue;
} GPIKey;

typedef struct GPIConnection {
    char pad0[0x3b4];
    void *extendedInfoKeys;
} GPIConnection;

extern int ArrayLength(const int *p);
extern int OS_SPrintf(char *dst, const char *fmt, ...);
extern void *func_02184208(void *array, int n);
typedef unsigned char  u8;
extern int strlen(const u8 *s);
extern void *gsimalloc(unsigned long size);
extern int gsDebugFormat(int index, char *table, int mask, const char *fmt, ...);
extern void gpiSetErrorString(int *p, int b);
extern u8 *strcat(u8 *dest, const u8 *src);
extern void B64Encode(const char *input, char *output, int inlen, int encodingType);
extern char gGpiKeysHeaderFmt[];
extern char gGpiKeysDebugSaveOom[];
extern char gGpiKeysErrorOutOfMemory[];
extern char gGpiKeysStringFmt[];
extern char gGpiKeysBackslash[];

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
        GPIKey *aKey = (GPIKey *)func_02184208(iconnection->extendedInfoKeys, i);
        base64KeyNameLen = B64LEN(aKey->keyName);
        base64KeyValLen = B64LEN(aKey->keyValue);
        sizeKeys += base64KeyNameLen + 2 + base64KeyValLen;
    }

    *buffer = (char *)gsimalloc((unsigned long)strlen((const u8 *)keysHeader) + sizeKeys + 1);
    if (*buffer == 0) {
        gsDebugFormat(1, (char *)2, 1, gGpiKeysDebugSaveOom);
        gpiSetErrorString((int *)connection, (int)gGpiKeysErrorOutOfMemory);
        return 1;
    }

    bytesWritten = OS_SPrintf(*buffer, gGpiKeysStringFmt, keysHeader);
    tempPoint = *buffer + bytesWritten;

    for (i = 0; i < aLength; i++) {
        GPIKey *aKey = (GPIKey *)func_02184208(iconnection->extendedInfoKeys, i);
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
