/*
 * function: func_021900C4
 * address:  0x021900C4
 * packet:   pkt_ov021_021900C4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0218F19C  0x0218F19C  thumb  ov021
 *   func_0218F18C  0x0218F18C  thumb  ov021
 *   func_0207CA00  0x0207CA00  arm
 *   func_0218ED5C  0x0218ED5C  thumb  ov021
 *   func_0218ECC4  0x0218ECC4  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_0218F19C(u32 a, void *b);
extern void func_0218F18C(u32 a, void *b);
extern void func_0207CA00(void *a, void *b, void *c);
extern void func_0218ED5C(void *a, void *b, void *c, void *d);
extern void func_0218ECC4(u32 a, void *b);

void func_021900C4(u32 a, u8 *b)
{
    u8 v1[12];
    u8 v0[12];
    u8 v2[12];

    func_0218F19C(a, v0);
    func_0218F18C(a, v1);
    func_0207CA00(v0, v1, v2);
    func_0218ED5C(v2, b, b + 2, b + 4);
    func_0218F18C(a, b + 8);
    func_0218ECC4(a, b + 0x14);
}
