/*
 * function: func_0202A9F4
 * address:  0x0202A9F4
 * packet:   pkt_0202A9F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_020185B0  0x020185B0  thumb
 *   func_02018A00  0x02018A00  thumb
 *   func_02019C90  0x02019C90  thumb
 *   _s32_div_f     0x0209C0A4  arm
 *
 * tr_tool.c: finish one trainer party member.  Field 9 (friendship) is
 * 0xFF unless one of the four moves (fields 0x36..0x39) is 0xDA, then 0;
 * field 0x6F takes a2; the 0xF0 nibble of a3 selects a form path
 * (0x30: func_02018A00, otherwise func_02019C90 with selector 0x1A or
 * 0x1B); two trainer/species pairs force a fixed nature, the rest take
 * (personality >> 8) % 25.
 *
 * What closed the old 248-byte near miss (docs/notes/func_0202A9F4.c.txt):
 * the register the note read as a copy of the loop counter (`adds r6, r4,
 * #0` before the loop) is the constant 0, kept in r6 for the call's third
 * argument and for `found = 0`.  That zero occupies the fourth callee-saved
 * register across the loop, which is what spills species to sp+0xC.  The
 * tail is the remainder of _s32_div_f (r1), so `% 25`, not `/ 25`.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u32  func_02017E1C(void *rec, u32 id, u32 slot);
extern void func_02017E40(void *rec, u32 id, u32 val);
extern void func_020185B0(void *rec, u32 val);
extern void func_02018A00(void *rec, u32 species, u32 arg);
extern u32  func_02019C90(u32 species, u16 arg, u32 sel);

void func_0202A9F4(u32 a0, void *rec, u32 a2, u32 a3)
{
    s32 slot;
    u32 found = 0xff;
    u32 species;
    u32 sel;
    u32 alt;
    u32 masked;
    u32 base;

    species = (u16)func_02017E1C(rec, 5, 0);
    for (slot = 0; slot < 4; slot++) {
        if (func_02017E1C(rec, 0x36 + slot, 0) == 0xda) {
            found = 0;
        }
    }
    func_02017E40(rec, 9, found);
    func_02017E40(rec, 0x6f, a2);

    masked = a3 & 0xf0;
    if (masked == 0x30) {
        func_02018A00(rec, species, a2);
    } else if (masked != 0) {
        sel = 0x1a;
        alt = 0x1b;
        if (func_02019C90(species, (u16)a2, 0x1b) != 0 && masked == 0x20) {
            sel = alt;
        }
        func_02017E40(rec, 0xa, func_02019C90(species, (u16)a2, sel));
    }

    base = 0x24a;
    if (a0 == base && species == base + 0x39) {
        func_020185B0(rec, 0xd);
        return;
    }
    base = 0x24b;
    if (a0 == base && species == base + 0x39) {
        func_020185B0(rec, 0xa);
        return;
    }
    func_020185B0(rec, (u8)(((s32)func_02017E1C(rec, 0, 0) >> 8) % 0x19));
}
