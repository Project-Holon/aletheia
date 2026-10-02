/*
 * function: func_0218BFB4
 * address:  0x0218BFB4
 * packet:   pkt_ov021_0218BFB4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-02: one colour diff at the dispatch: the original loads t[0] into
 * r4 after the out stores (movs r2,#12 first), ours loads t earlier into r2.
 * Inert: index local (u32/int/reuse i), Fn local, pointer-to-entry, 2-D
 * u32 table, explicit byte offset, out stores via local, decl orders.
 * The unlabelled leaf at 0x0218C02C (clears st[2..5]) sits after the pool.
 *
 * symbols:
 *   func_0218BCAC  0x0218BCAC  thumb  ov021
 *   func_02047400  0x02047400  arm
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   d_021D3D58     0x021D3D58  data   a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

typedef void (*Fn)(void *a, u32 *out);
typedef struct {
    Fn fn;
    u32 pad[2];
} Entry;

extern u8 *func_0218BCAC(u32 p);
extern u32 func_02047400(u32 a, u32 b, u32 c);
extern u32 func_02047564(u32 a, u32 b, u32 c);
extern u32 func_0204767C(u32 a, u32 *b, u32 c);
extern Entry d_021D3D58[];

void func_0218BFB4(u8 *a, u32 *out, u32 *st)
{
    u32 buf[4];
    u8 *t;
    u32 h;
    int i;

    t = func_0218BCAC(st[0]);
    h = func_02047400(st[1], 0, *(u32 *)(a + 0x1D0));
    for (i = 0; i < 4; i++) {
        if (st[2 + i] != 0)
            buf[i] = func_02047564(h, st[2 + i], 0);
        else
            buf[i] = 0;
    }
    out[0] = func_0204767C(h, buf, 4);
    out[1] = (u32)st;
    d_021D3D58[t[0]].fn(a, out);
}
