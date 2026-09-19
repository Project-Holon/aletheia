/*
 * function: func_0207482C
 * address:  0x0207482C
 * packet:   pkt_02074770
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned char u8; typedef unsigned int u32;

extern u32 func_02061124(u32, u32, u32);
extern u32 func_0206062C(u32 *, u32);
extern void func_020604AC(u32, u32);

u32 func_0207482C(u32 *a, u32 b, u32 c, u32 d, u32 e) {
    u32 t;
    u32 r = func_02061124(*a, ((b + 0x1f) & ~0x1fu) + 0x20, 0x20);
    if (r == 0) return 0;
    t = func_0206062C(a + 1, 0);
    *(u32 *)(r + 8) = b;
    *(u32 *)(r + 0xc) = c;
    *(u32 *)(r + 0x10) = d;
    *(u32 *)(r + 0x14) = e;
    func_020604AC(t, r);
    return r + 0x20;
}
