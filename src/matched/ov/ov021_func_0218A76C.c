/*
 * function: func_0218A76C
 * address:  0x0218A76C
 * packet:   pkt_ov021_0218A76C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Tries func_0218A8BC, then func_0218A784 with direction 9.
 *
 * symbols:
 *   func_0218A8BC  0x0218A8BC  thumb
 *   func_0218A784  0x0218A784  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct Ctx784;
struct FieldCtx;
extern int func_0218A8BC(struct FieldCtx *p);
extern int func_0218A784(struct Ctx784 *c, int a);

int func_0218A76C(void *p)
{
    int r = func_0218A8BC(p);

    if (r != 0)
        return r;
    return func_0218A784(p, 9);
}
