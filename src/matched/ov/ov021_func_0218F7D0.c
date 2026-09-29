/*
 * function: func_0218F7D0
 * address:  0x0218F7D0
 * packet:   pkt_ov021_0218F7D0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0218F18C  0x0218F18C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u32 a, b, c; } V3;

extern void func_0218F18C(u8 *s, u8 *d);

void func_0218F7D0(u8 *s, u8 *d)
{
    *(V3 *)(d + 0) = *(V3 *)(s + 0x24);
    func_0218F18C(s, d + 0xc);
    *(u16 *)(d + 0x24) = *(u16 *)(s + 0x78);
    *(u16 *)(d + 0x26) = *(u16 *)(s + 0x7a);
    *(u32 *)(d + 0x28) = *(u32 *)(s + 0x7c);
    *(u16 *)(d + 0x2c) = *(u16 *)(s + 0x80);
    *(V3 *)(d + 0x18) = *(V3 *)(s + 0x60);
}
