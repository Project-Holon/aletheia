/*
 * function: func_0218DA40
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
 *   func_02184200  0x02184200  arm   ov009
 *   func_02084F40  0x02084F40  arm
 *   func_02184208  0x02184208  arm   ov009
 *   func_0209477C  0x0209477C  arm
 *   func_0217EAB0  0x0217EAB0  arm   ov009
 *   func_0217D254  0x0217D254  arm   ov009
 *   func_02193734  0x02193734  arm   ov009
 *   func_020948B0  0x020948B0  arm
 *   func_0217FA90  0x0217FA90  arm   ov009
 *   g_021A4DB8     0x021A4DB8  data
 *   g_021A4DC4     0x021A4DC4  data
 *   g_021A4D80     0x021A4D80  data
 *   g_021A4DF0     0x021A4DF0  data
 *   g_021A4DF4     0x021A4DF4  data
 *
 * strcat (func_020948B0, arm9) attests as matched through unit_02094860, whose
 * functions list names func_020948B0 since 2026-09-29 (w4_nm).
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

extern int func_02184200(const int *p);
extern int func_02084F40(char *dst, const char *fmt, ...);
extern void *func_02184208(void *array, int n);
extern unsigned long func_0209477C(const char *s);
extern void *func_0217EAB0(unsigned long size);
extern void func_0217D254(int theCat, int theType, unsigned char theLevel, char *theTokenStr, ...);
extern void func_02193734(void **connection, char *errorString);
extern char *func_020948B0(char *dst, const char *src);
extern void func_0217FA90(const char *input, char *output, int inlen, int encodingType);
extern char g_021A4DB8[];
extern char g_021A4DC4[];
extern char g_021A4D80[];
extern char g_021A4DF0[];
extern char g_021A4DF4[];

static inline int B64LEN(char *s)
{
    return (func_0209477C(s) % 3) ? ((4 - func_0209477C(s) % 3) + func_0209477C(s) * 4 / 3) : (func_0209477C(s) * 4 / 3);
}

static inline void B64ADV(char **p, char *s)
{
    if (func_0209477C(s) % 3)
        *p += (4 - func_0209477C(s) % 3) + func_0209477C(s) * 4 / 3;
    else
        *p += func_0209477C(s) * 4 / 3;
}

static inline void B64ENC(char *s, char *out)
{
    func_0217FA90(s, out, (int)func_0209477C(s), 2);
}

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
    func_02084F40(keysHeader, g_021A4DB8, aLength);

    for (i = 0; i < aLength; i++) {
        GPIKey *aKey = (GPIKey *)func_02184208(iconnection->extendedInfoKeys, i);
        base64KeyNameLen = B64LEN(aKey->keyName);
        base64KeyValLen = B64LEN(aKey->keyValue);
        sizeKeys += base64KeyNameLen + 2 + base64KeyValLen;
    }

    *buffer = (char *)func_0217EAB0(func_0209477C(keysHeader) + sizeKeys + 1);
    if (*buffer == 0) {
        func_0217D254(1, 2, 1, g_021A4DC4);
        func_02193734(connection, g_021A4D80);
        return 1;
    }

    bytesWritten = func_02084F40(*buffer, g_021A4DF0, keysHeader);
    tempPoint = *buffer + bytesWritten;

    for (i = 0; i < aLength; i++) {
        GPIKey *aKey = (GPIKey *)func_02184208(iconnection->extendedInfoKeys, i);
        func_020948B0(tempPoint, g_021A4DF4);
        tempPoint++;
        B64ENC(aKey->keyName, tempPoint);
        B64ADV(&tempPoint, aKey->keyName);
        func_020948B0(tempPoint, g_021A4DF4);
        tempPoint++;
        B64ENC(aKey->keyValue, tempPoint);
        B64ADV(&tempPoint, aKey->keyValue);
    }
    return 0;
}
