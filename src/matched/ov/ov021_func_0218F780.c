/*
 * function: func_0218F780
 * address:  0x0218F780
 * packet:   pkt_ov021_0218F780
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u32 a, b, c; } V3;

void func_0218F780(u8 *s, u8 *d)
{
    *(V3 *)(d + 0)    = *(V3 *)(s + 0x24);
    *(V3 *)(d + 0xc)  = *(V3 *)(s + 0x48);
    *(u16 *)(d + 0x24) = *(u16 *)(s + 0x78);
    *(u16 *)(d + 0x26) = *(u16 *)(s + 0x7a);
    *(u32 *)(d + 0x28) = *(u32 *)(s + 0x7c);
    *(u16 *)(d + 0x2c) = *(u16 *)(s + 0x80);
    *(V3 *)(d + 0x18) = *(V3 *)(s + 0x60);
}
