/*
 * function: func_0218E540
 * address:  0x0218E540
 * packet:   pkt_ov021_0218E540
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Builds two 12-byte vectors from matrix pairs and pushes them to the owner.
 *
 * symbols:
 *   func_0207C9D0  0x0207C9D0  arm
 *   func_02048B44  0x02048B44  arm
 *   func_02048AFC  0x02048AFC  arm
 *   func_0218F004  0x0218F004  thumb  ov021
 *   func_0218E764  0x0218E764  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

extern void func_0207C9D0(void *a, void *b, void *c);
extern void func_02048B44(int, void *);
extern void func_02048AFC(int, void *);
extern void func_0218F004(u8 *a);
extern void func_0218E764(u8 *a, void *b, void *c);

void func_0218E540(u8 *a)
{
    u8 t1[12];
    u8 t0[12];

    func_0207C9D0(a + 0x54, a + 0x60, t1);
    func_0207C9D0(a + 0x3C, a + 0x30, t0);
    func_02048B44(*(int *)(a + 0xC), t1);
    func_02048AFC(*(int *)(a + 0xC), t0);
    func_0218F004(a);
    func_0218E764(a, t1, a + 0x3C);
}
