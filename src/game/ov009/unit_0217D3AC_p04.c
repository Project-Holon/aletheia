/*
 * file:     unit_0217D3AC_p04.c
 * unit:     yes
 * function: func_0217E7C4, func_0217E848, func_0217E934, func_0217E978, func_0217E9EC
 * address:  0x0217E7C4
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
 *   func_0209477C                  0x0209477C  arm
 *   func_0208CF34                  0x0208CF34  arm
 *   g_021A3728                     0x021A3728  data
 *   g_021A3720                     0x021A3720  data
 *   memcpy                           0x02092344 arm
 *   gsLargeIntReverseBytes           0x0217e934 arm
 *   GSMD5Update                      0x0218497c arm
 */
struct GSMD5_CTX;
struct gsLargeInt_s {
    unsigned int mLength;
    unsigned int mData[64];
};

typedef unsigned char  u8;

extern int func_0209477C(const u8 *s);
extern int func_0208CF34(const char *src, const char *fmt, ...);
extern void memcpy(void * dst, const void * src, unsigned int n);
extern int gsLargeIntReverseBytes(struct gsLargeInt_s * lint);
extern void GSMD5Update(struct GSMD5_CTX * context, unsigned char * input, unsigned int inputLen);
int func_0217E7C4(struct gsLargeInt_s *mod, unsigned int *dest);
int func_0217E848(struct gsLargeInt_s *lint, char *hexstream);
int func_0217E934(char *p);
void gsLargeIntAddToMD5(struct gsLargeInt_s * _lint, struct GSMD5_CTX * md5);
unsigned int gsLargeIntGetByteLength(struct gsLargeInt_s * lint);
extern char g_021A3728[];
extern char g_021A3720[];


/*
 * sdk:      gsiLargeIntInverseMod (gslargeint.o)
 */
int func_0217E7C4(struct gsLargeInt_s *mod, unsigned int *dest)
{
    unsigned long long x = 2;
    unsigned long long y = 1;
    unsigned int i;

    for (i = 2; i <= 32; i++) {
        unsigned long long mask = (x << 1) - 1;
        unsigned long long p = (unsigned long long)mod->mData[0] * y;
        if (x < (p & mask))
            y += x;
        x <<= 1;
    }
    *dest = (unsigned int)(x - y);
    return 1;
}


/*
 * sdk:      gsLargeIntSetFromHexString (gslargeint.o)
 */
int func_0217E848(struct gsLargeInt_s *lint, char *hexstream)
{
    unsigned int *writePos = lint->mData;
    unsigned int temp;
    unsigned int len;
    int byteIndex = 0;
    unsigned int n;

    len = func_0209477C((const u8 *)hexstream);
    if (len == 0) {
        lint->mLength = 0;
        lint->mData[0] = 0;
        return 1;
    }
    if (len / 2 > 256)
        return 0;
    lint->mLength = (len + 7) / 8;
    lint->mData[lint->mLength - 1] = 0;
    while (len != 0) {
        if (len >= 2)
            func_0208CF34(hexstream + len - 2, g_021A3720, &temp);
        else
            func_0208CF34(hexstream + len - 1, g_021A3728, &temp);
        if (byteIndex == 0)
            *writePos = 0;
        *writePos |= temp << (8 * byteIndex);
        byteIndex++;
        if (byteIndex == 4) {
            byteIndex = 0;
            writePos++;
        }
        n = 2;
        if (len <= 2)
            n = len;
        len -= n;
    }
    return 1;
}

/*
 * Reverses the n*4-byte payload that follows the count word, in place.
 */
int func_0217E934(char *p)
{
    int n = *(int *)p;
    char *a = p + 4;
    char *b = a + n * 4 - 1;

    if (n == 0) return 1;
    while (a < b) {
        char t = *a;

        *a++ = *b;
        *b-- = t;
    }
    return 1;
}


void gsLargeIntAddToMD5(struct gsLargeInt_s * _lint, struct GSMD5_CTX * md5)
{
    struct gsLargeInt_s lint;
    int byteLength;
    unsigned char * dataStart;

    memcpy(&lint, _lint, sizeof(lint));
    byteLength = gsLargeIntGetByteLength(&lint);
    if (byteLength == 0)
        return;

    dataStart = (unsigned char *)&lint.mData;
    if (byteLength & 3)
        dataStart += 4 - (byteLength & 3);

    gsLargeIntReverseBytes(&lint);
    GSMD5Update(md5, dataStart, byteLength);
    gsLargeIntReverseBytes(&lint);
}


unsigned int gsLargeIntGetByteLength(struct gsLargeInt_s * lint)
{
    unsigned int mask;
    unsigned int i;
    int byteSize;
    int intSize;

    intSize = lint->mLength;
    while (intSize > 0 && lint->mData[intSize - 1] == 0)
        intSize--;

    if (intSize == 0)
        return 0;

    byteSize = intSize * 4;
    mask = 0xff;
    for (i = 1; i < 4; i++)
    {
        if (lint->mData[intSize - 1] <= mask)
            return byteSize - (4 - i);
        mask = (mask << 8) | 0xff;
    }

    return byteSize;
}
