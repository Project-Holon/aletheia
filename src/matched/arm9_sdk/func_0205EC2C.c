/*
 * function: func_0205EC2C
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

extern void func_02081120(MATHMD5Context *context);
extern void func_02081164(MATHMD5Context *context, const void *input, unsigned long length);
extern void func_0208122C(MATHMD5Context *context, void *digest);
extern void MI_CpuCopy8(const void *srcp, void *dstp, unsigned long size);

static void func_0205EC2C(unsigned char *seed, unsigned char *wepkey)
{
    unsigned char temp[17];
    MATHMD5Context context;

    func_02081120(&context);
    func_02081164(&context, seed, 24);
    func_0208122C(&context, temp);
    MI_CpuCopy8(&temp[3], wepkey, 13);
}
