/*
 * unit:     yes
 * address:  0x0201AFD4
 * packet:   pkt_0201AE14
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_0201AFD4
 *
 * The species-to-form resolver the three wrappers in
 * src/matched/unit_0201ADA4.c and src/matched/unit_0201ADD0.c open with: it
 * reads the 0x3C byte personal record for the species out of the archive
 * handle at 0x0214652C and, when the record has a form table and the
 * requested form is inside it, answers with the form's own species-like id.
 *
 * VERSION SENSITIVITY: the guard rejects exactly the two ids 650 and 651,
 * which are the egg and bad-egg entries src/pending/sub_02018E34.c's field
 * map already names, and it spells them as a 16 bit range test.  They are
 * content ids rather than structure offsets, so they are the first thing to
 * re-read for a Pokemon White build; nothing else in this function is
 * version dependent.
 *
 * The test is written `(u16)(species + 0xFD76) > 1`, not `species - 650`:
 * 0x28A does not fit an 8 bit immediate either way, and only the positive
 * unsigned 16 bit spelling of the complement keeps the constant in the pool
 * where the original has it
 * (docs/idioms/out-of-range-immediate-subtract-costs-a-pool-word.md).
 *
 * The three tests in the tail are one disjunction guarding `return species`,
 * not the conjunction guarding the computed answer that the semantics
 * suggest: written the other way round every byte is still right but the two
 * exit blocks are emitted in the opposite order, because the block the source
 * writes inside the `if` is the one that comes first
 * (docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md and
 * docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * The record's halfword at +0x1C is reached with a plain `ldrh [r0, #0x1c]`
 * while its byte at +0x20 costs an `add r0, sp, #0x20` first, which is only
 * the byte immediate's reach of 31 and not a second pointer
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md).
 *
 * symbols:
 *   g_0214652C  0x0214652C  data
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AFD4.c \
 *       --addr 0x0201AFD4 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

struct Personal {
    u8  unk00[0x1C];
    u16 unk1C;
    u8  unk1E[2];
    u8  unk20;
    u8  unk21[0x1B];
};

extern void *func_02049578(void *handle, u32 id);
extern void *func_0204960C(void *handle, void *x);
extern void func_020495F4(void *handle, u32 id, void *dest);

extern void *g_0214652C;

u32 sub_0201AFD4(u32 species, s32 form)
{
    struct Personal rec;

    if ((u16)(species + 0xFD76) <= 1) {
        return 0;
    }
    func_0204960C(g_0214652C, func_02049578(g_0214652C, species));
    func_020495F4(g_0214652C, 0x3C, &rec);
    if (rec.unk1C == 0 || rec.unk20 <= form || form == 0) {
        return species;
    }
    return (u16)(rec.unk1C + form - 1);
}
