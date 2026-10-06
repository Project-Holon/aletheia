/*
 * file:     bmp_menu_p01.c
 * unit:     yes
 * function: func_0201F53C, func_0201F548, func_0201F554, func_0201F57C
 * address:  0x0201F53C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   sub_0209E8C8_Map  0x0209E8C8  data
 *   sub_0209E8CA_Map  0x0209E8CA  data  a1
 */
typedef unsigned char u8;

typedef unsigned int   u32;

extern void func_02049624(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
u8 func_0201F53C(int i);
u8 func_0201F548(int i);
void func_0201F554(u32 a, u32 b, u32 c, u32 d);
void func_0201F57C(u32 a, u32 b, u32 c, u32 d);
extern u8 sub_0209E8C8_Map[];
extern u8 sub_0209E8CA_Map[];


u8 func_0201F53C(int i)
{
    return sub_0209E8C8_Map[i];
}


/*
 * Promoted from src/pending/func_0201F548.c on 2026-09-22 (family wave 5,
 * wordset.c).  Every concrete byte was already reproduced; only the one
 * relocation was open.
 *
 * The second of the two three-instruction byte-table lookups behind
 * src/matched/unit_0201F554.c -- func_0201F53C reads the table at 0x0209E8C8
 * and this one the table at 0x0209E8CA, two bytes further on.  Both are
 * `return table[i];` and nothing else.
 *
 * WHAT CHANGED.  The blocker was the ABS32 against 0x0209E8CA.  Its only
 * literal-pool referrer anywhere in the image is the word at 0x0201F550
 * inside this very function (layout/data_objects.txt), which every
 * second-referrer class discards as lying inside the range under test, and
 * 0x0209E8CA is interior to the datum the listings start at 0x0209E8C8, so
 * `sole-ref/data` refuses it as not-a-start.  It is now carried by
 * `sole-ref/self`: the target is in a data section and the ROM word at the
 * relocation site already names exactly the address the relocation writes
 * there, which is the whole of that sub-kind's evidence.  The sibling
 * func_0201F53C reaches EXACT by the stronger `sole-ref/data` instead,
 * because 0x0209E8C8 IS the datum start.
 *
 * Addresses are Black-image addresses.  The table's contents are a glyph
 * index map and are content data, not code shape; if it is ever sized
 * differently between Black and White that is a data-layout question, not a
 * code one.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201F548.c \
 *       --func func_0201F548 --addr 0x0201F548 --cc 1.1p1 --thumb
 */
u8 func_0201F548(int i)
{
    return sub_0209E8CA_Map[i];
}


/*
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
void func_0201F554(u32 a, u32 b, u32 c, u32 d)
{
    func_02049624(5, func_0201F53C(c), a, b, 0, 0, d);
}


/*
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
void func_0201F57C(u32 a, u32 b, u32 c, u32 d)
{
    u32 t = func_0201F548(c);

    if (a < 4) {
        func_02049B40(5, t, 0, b * 32, 0x20, d);
    } else {
        func_02049B40(5, t, 4, b * 32, 0x20, d);
    }
}
