/*
 * function: func_0217FAF0
 * address:  0x0217FAF0
 * packet:   pkt_ov019_0217FAF0
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MTX_Identity33_  0x0207ADC4  arm
 *   func_0216DA30    0x0216DA30  thumb  ov010
 *   func_0217FA9C    0x0217FA9C  thumb  ov019
 *   d_0218071C       0x0218071C  data   ov019 a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct B60 { u32 w[15]; };
extern void MTX_Identity33_(void *m);
extern int func_0216DA30(u32 a);
extern void func_0217FA9C(u32 *p, struct B60 *b);
extern struct B60 d_0218071C;

void func_0217FAF0(u32 *p)
{
    struct B60 b = d_0218071C;

    MTX_Identity33_(&b.w[6]);
    if (p[3] != 0 && func_0216DA30(p[0]) == 1) {
        func_0217FA9C(p, &b);
    }
}
