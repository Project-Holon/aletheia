/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0202EC24
 * packet:   pkt_0202E770
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: COMM_HISTORY_CountLeadingOccupied
 *
 * Counts the leading run of occupied slots in a 20-entry array of
 * 0x28-byte records and returns the index of the first free one, or 20.
 * No prologue at all, because it calls nothing and needs no callee-saved
 * register, so `disasm.py` gives it no label.
 *
 * The occupancy test is `lsls #0x1B` / `lsrs #0x1F` on a byte at offset
 * 0x26, which is a one-bit unsigned bitfield at bit 4 and cannot be
 * written as a mask: `& 0x10` folds to `movs`/`ands` and a shift pair
 * with unequal amounts is a narrowing cast, not a field
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md,
 * docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md).
 * The record stride arrives as `movs r1, #0x28` / `muls` rather than a
 * scaled index because 0x28 is not a power of two.
 *
 * Matched as a one-function unit because the two bytes of `00 00` after
 * its last instruction are the linker's inter-section fill, so `one`
 * reports EXACT* for a padding gap rather than for an unlabelled
 * follower; `tu` compares the section as laid out.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202EC24.c 
 *       --addr 0x0202EC24 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Ent0202EC24 {
    u8 pad[0x26];
    u8 unk26_0 : 4;
    u8 unk26_4 : 1;
    u8 unk26_5 : 3;
    u8 unk27;
};

u32 COMM_HISTORY_CountLeadingOccupied(const struct Ent0202EC24 *p)
{
    u32 i;

    for (i = 0; i < 20; i++) {
        if (p[i].unk26_4 == 0) {
            break;
        }
    }
    return i;
}
