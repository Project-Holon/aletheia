/*
 * function: func_0218E6F0
 * address:  0x0218E6F0
 * packet:   pkt_ov021_0218E6F0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Twin of func_0218E6A4 with mode 0 and the other matrix pair.
 *
 * symbols:
 *   func_0207CA00  0x0207CA00  arm
 *   func_0218E674  0x0218E674  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;

extern void func_0207CA00(void *a, void *b, void *c);
extern void func_0218E674(u8 *a, void *v);

void func_0218E6F0(u8 *a)
{
    u8 tmp[12];

    if (*(int *)(a + 0x14) == 0) {
        *(u16 *)(a + 0x7A) = *(u16 *)(a + 0x7A) + 0x8000;
        *(u16 *)(a + 0x78) = *(u16 *)(a + 0x78) + 0x8000;
    } else {
        func_0207CA00(a + 0x48, a + 0x3C, tmp);
        func_0218E674(a, tmp);
    }
}
