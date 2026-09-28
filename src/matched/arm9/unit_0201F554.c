/*
 * unit:     yes
 * address:  0x0201F554
 * packet:   pkt_0201F020
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_0201F554, func_0201F57C
 *
 * Two font-drawing wrappers, each turning a small id into a glyph-table index
 * through one of the two byte tables just before them and handing it to a
 * seven- and a six-argument SDK-style entry point.  The two table lookups are
 * func_0201F53C and func_0201F548, which are parked in
 * src/pending/sub_0201F53C.c because their tables have no outside witness;
 * the calls to them are ordinary `label` sites here, since func_0201F53C is
 * also called from 0x0201F5EA outside this range and func_0201F548 from ten
 * overlays.
 *
 * func_0201F57C hoists the lookup above the `if`, so the source binds it to a
 * local once rather than calling it in both arms; written in both arms the
 * compiler emits the call twice.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201F554.c  *       --addr 0x0201F554 --thumb
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

extern u8   func_0201F53C(u32 i);
extern u8   func_0201F548(u32 i);
extern void func_02049624(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);

void func_0201F554(u32 a, u32 b, u32 c, u32 d)
{
    func_02049624(5, func_0201F53C(c), a, b, 0, 0, d);
}

void func_0201F57C(u32 a, u32 b, u32 c, u32 d)
{
    u32 t = func_0201F548(c);

    if (a < 4) {
        func_02049B40(5, t, 0, b * 32, 0x20, d);
    } else {
        func_02049B40(5, t, 4, b * 32, 0x20, d);
    }
}
