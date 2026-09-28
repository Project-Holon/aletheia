/*
 * function: func_0218A878
 * address:  0x0218A878
 * packet:   pkt_ov021_0218A878
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * When flag field 0x10 is set and func_021A2FA4 does not report 9, forwards
 * the object to ov018 func_0217B4D8; returns 0 otherwise.
 *
 * symbols:
 *   func_0217B4D8  0x0217B4D8  thumb ov018
 *   func_02013D5C  0x02013D5C  thumb
 *   func_021A2FA4  0x021A2FA4  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern int func_02013D5C(u16 v);
extern int func_021A2FA4(void *p, u32 v);
extern int func_0217B4D8(void *a, void *b, void *c, u32 d, u16 e, int f);

int func_0218A878(u8 *p, void *a, void *b)
{
    int r;

    if (func_02013D5C(*(u16 *)(p + 0x10)) == 0)
        return 0;
    r = func_021A2FA4(*(void **)(p + 0x18), *(u32 *)(p + 0x2C));
    if (r == 9)
        return 0;
    return func_0217B4D8(a, b, *(void **)(p + 0x18), *(u32 *)(p + 0x34), *(u16 *)(p + 0x24), r);
}
