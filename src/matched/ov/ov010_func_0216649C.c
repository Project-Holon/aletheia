/*
 * function: func_0216649C
 * address: 0x0216649C
 * packet: pkt_ov010_0216649C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * A zero case with a default continuation keeps the failure exit first.
 * Returns the full-word pointer payload from the selected table slot.
 * symbols:
 *   func_02166434 0x02166434 thumb ov010
 *   d_02171EF4 0x02171EF4 data a4
 */
typedef unsigned int u32;
typedef unsigned char u8;
extern u8 *d_02171EF4[];
extern int func_02166434(void *, u32 *, u32 *);
u32 func_0216649C(void *p) {
    u32 a;
    u32 b;
    switch (func_02166434(p, &a, &b)) {
    case 0: return 0;
    default: break;
    }
    return *(u32 *)((u32)d_02171EF4 + (a + b * 7u) * 4u);
}
