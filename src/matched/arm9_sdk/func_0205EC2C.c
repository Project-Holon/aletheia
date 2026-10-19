/*
 * function: makeShopWepKey
 * address:  0x0205EC2C
 * packet:   pkt_0205DC74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      makeShopWepKey (shop_usb.o)
 *
 * symbols:
 *   MATH_MD5Init                     0x02081120 arm
 *   MATH_MD5Update                   0x02081164 arm
 *   MATH_MD5GetHash                  0x0208122c arm
 *   MI_CpuCopy8                      0x02082d44 arm
 */

typedef struct MATHMD5Context {
    unsigned long state[4];
    unsigned long length[2];
    unsigned char buffer[64];
} MATHMD5Context;

extern void MATH_MD5Init(MATHMD5Context *context);
extern void MATH_MD5Update(MATHMD5Context *context, const void *input, unsigned long length);
extern void MATH_MD5GetHash(MATHMD5Context *context, void *digest);
extern void MI_CpuCopy8(const void *srcp, void *dstp, unsigned long size);

static void makeShopWepKey(unsigned char *seed, unsigned char *wepkey)
{
    unsigned char temp[17];
    MATHMD5Context context;

    MATH_MD5Init(&context);
    MATH_MD5Update(&context, seed, 24);
    MATH_MD5GetHash(&context, temp);
    MI_CpuCopy8(&temp[3], wepkey, 13);
}
