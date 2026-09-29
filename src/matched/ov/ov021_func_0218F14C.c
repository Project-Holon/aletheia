/*
 * function: func_0218F14C
 * address:  0x0218F14C
 * packet:   pkt_ov021_0218F14C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204A380  0x0204A380  arm
 *   func_020307B0  0x020307B0  arm
 *   func_0218F114  0x0218F114  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32  func_0204A380(u32 a0, u32 a1, u32 a2, u16 a3);
extern void func_020307B0(void *p);
extern void func_0218F114(u8 *a, u32 b);

void func_0218F14C(u8 *p, u32 a, u32 b)
{
    u32 r;
    if (*(u16 *)(p + 0xea) != a) {
        r = func_0204A380(*(u32 *)(p + 8), a, 0, (u16)((b & 0x7fff) | 0x8000));
        func_0218F114(p, r);
        func_020307B0((void *)r);
        *(u16 *)(p + 0xea) = a;
    }
}
