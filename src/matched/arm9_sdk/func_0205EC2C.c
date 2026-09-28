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
 * SDK symbol: makeShopWepKey (shop_usb.o, libdwcac.TWL.HYB.a)
 *
 * symbols:
 *   MATH_MD5Init      0x02081120  arm
 *   MATH_MD5Update    0x02081164  arm
 *   MATH_MD5GetHash   0x0208122C  arm
 *   MI_CpuCopy8       0x02082D44  arm
 */

struct MATHMD5Context {
    unsigned int w[22];
};

extern void MATH_MD5Init(struct MATHMD5Context *context);
extern void MATH_MD5Update(struct MATHMD5Context *context, void *input,
                           unsigned long length);
extern void MATH_MD5GetHash(struct MATHMD5Context *context, void *digest);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);

void func_0205EC2C(unsigned char *seed, unsigned char *wepkey)
{
    struct MATHMD5Context context;
    unsigned char temp[17];

    MATH_MD5Init(&context);
    MATH_MD5Update(&context, seed, 0x18);
    MATH_MD5GetHash(&context, temp);
    MI_CpuCopy8(&temp[3], wepkey, 0xd);
}
