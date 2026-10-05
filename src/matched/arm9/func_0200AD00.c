/*
 * function: sub_0200AD00
 * address:  0x0200AD00
 * packet:   pkt_0200AD00
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   (none - no relocations; the two pool words at 0x0200AD64 (0xFFFE007F)
 *    and 0x0200AD68 (999) are the bitfield mask and the clamp, both plain
 *    literals the compiler emits itself)
 *
 * EXACT*: the listing extent runs to 156 bytes because the function at
 * 0x0200AD6C that follows saves nothing and therefore carries no label
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); this file
 * reproduces the 108 bytes of sub_0200AD00 itself, code and both pool words.
 * The unlabelled follower at 0x0200AD6C should be seeded into
 * layout/function_starts.txt by the integrator.
 *
 * Another linear scan over the family's 0x1C-byte Entry records (see
 * docs/families/mystery_data.h): for every entry whose u32 at +0x14 matches
 * the reference's, bump the 10-bit counter at bit 7 of the packed word at
 * +0x10, set bit 7 of the byte at +0x1B, and clamp the counter to 999.
 *
 * WHAT CHANGED THIS WAVE (docs/notes/pkt_0200AD00.c.txt had this row at DIFF,
 * 104 bytes against 156, 94 concrete bytes out -- effectively a whole-function
 * mismatch).  The note's C did the field access by hand:
 *
 *     v = *(u32 *)(e + 0x10);
 *     *(u32 *)(e + 0x10) = (v & 0xfffe007fu) | ((((v >> 7) & 0x3ff) + 1) << 7);
 *
 * which compiles to `lsrs #7; ands <0x3ff>` for the read and a pool word for
 * the 0x3FF, three instructions and a constant the original never
 * materialises.  The original reads the field as `lsls #0xf / lsrs #0x16` and
 * writes it back as `lsls #0x16 / lsrs #0xf`: an EQUAL-width shift pair with
 * no matching type, which is
 * docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md -- a 10-bit
 * unsigned BITFIELD at bit 7, not a hand-rolled mask.  Declaring the whole
 * packed word as the `struct Entry` bitfields the family header already
 * evidences (func_0200A8D0/A8E4/A8F8 in src/matched/unit_0200A864.c prove the
 * 7/10/1 widths) takes the row from 94 concrete bytes out to 2 in one edit,
 * and also drops the lr push: the hand-written version needed a spill the
 * bitfield form does not.
 *
 * The last two bytes were the operand order of the guard.  Both sides are
 * loads, and the side the SOURCE names first lands in the left register:
 * `ref->unk14 != e->unk14` gives `ldr r2, [r6, #0x14]` then `ldr r1, [r5,
 * #0x14]`, and the natural-reading `e->unk14 != ref->unk14` gives them the
 * other way round.  This is docs/idioms/cmp-operand-order-names-the-temporary.md
 * and it is the THIRD function in this family to turn on it
 * (src/matched/func_0200ABE0.c and src/matched/func_0200AA00.c are the others).
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0200AD00.c \
 *       --func sub_0200AD00 --addr 0x0200AD00 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Entry {
    u8  unk00[0x10];
    u32 f10_0  : 7;
    u32 f10_7  : 10;
    u32 f10_17 : 15;
    u32 unk14;
    u8  unk18[3];
    u8  f1B_0 : 7;
    u8  f1B_7 : 1;
};

void sub_0200AD00(struct Entry *base, int n, struct Entry *ref)
{
    int i;

    for (i = 0; i < n; i++) {
        struct Entry *e = &base[i];
        u32 x;

        if (ref->unk14 != e->unk14) {
            continue;
        }
        e->f10_7 = e->f10_7 + 1;
        e->f1B_7 = 1;
        x = e->f10_7;
        if (x > 999) {
            x = 999;
        }
        e->f10_7 = x;
    }
}
