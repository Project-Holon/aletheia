/*
 * function: func_0217E848
 * address:  0x0217E848
 * packet:   pkt_ov009_0217E848
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsLargeIntSetFromHexString (gslargeint.o)
 *
 * symbols:
 *   func_0209477C                  0x0209477C  arm
 *   func_0208CF34                  0x0208CF34  arm
 *   g_021A3728                     0x021A3728  data
 *   g_021A3720                     0x021A3720  data
 */

struct gsLargeInt_s {
    unsigned int mLength;
    unsigned int mData[64];
};

extern unsigned long func_0209477C(const char *s);
extern int func_0208CF34(const char *src, const char *fmt, ...);
extern char g_021A3728[];
extern char g_021A3720[];

int func_0217E848(struct gsLargeInt_s *lint, char *hexstream)
{
    unsigned int *writePos = lint->mData;
    unsigned int temp;
    unsigned int len;
    int byteIndex = 0;
    unsigned int n;

    len = func_0209477C(hexstream);
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
