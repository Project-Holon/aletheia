/*
 * function: func_0218F004
 * address:  0x0218F004
 * packet:   pkt_ov021_0218F004
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Fetches three vectors from the owner, calls the solver, writes two back.
 *
 * symbols:
 *   func_02048B30  0x02048B30  arm
 *   func_02048AE8  0x02048AE8  arm
 *   func_02048B44  0x02048B44  arm
 *   func_02048AFC  0x02048AFC  arm
 *   func_0218ED9C  0x0218ED9C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

extern void func_02048B30(int, void *);
extern void func_02048AE8(int, void *);
extern void func_02048B44(int, void *);
extern void func_02048AFC(int, void *);
extern void func_0218ED9C(int a, void *b, void *c, void *d, void *e);

void func_0218F004(u8 *a)
{
    if (*(int *)(a + 0x1C) != 0) {
        u8 d[12];
        u8 v[12];
        u8 c[12];
        u8 b[12];

        func_02048B30(*(int *)(a + 0xC), v);
        func_02048AE8(*(int *)(a + 0xC), d);
        func_0218ED9C(*(int *)(a + 0xEC), v, d, b, c);
        func_02048B44(*(int *)(a + 0xC), b);
        func_02048AFC(*(int *)(a + 0xC), c);
    }
}
