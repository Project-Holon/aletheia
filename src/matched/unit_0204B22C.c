/*
 * unit:     yes
 * function: sub_0204B22C
 * address:  0x0204B22C
 * packet:   pkt_0204B0C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Three leaf accessors of clact.c's bank header, packed end to end with no
 * literal pool between them.  Only the first has a `func_` label in the
 * listing, because none of the three saves lr
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); 0x0204B248 and
 * 0x0204B258 are unlabelled followers and are seeds for
 * layout/function_starts.txt.
 *
 * The byte at +0x0e is two 4-bit unsigned bitfields.  The low nibble is a
 * source selector paired with the pointer at +0x08: sub_0204B270 sets it to 0
 * for the shared default at g_02146A74 + 0x40, and 0x0204B258 sets it to 1
 * for a caller-supplied pointer.  The high nibble is written by 0x0204B22C
 * and read back by 0x0204B248, and never appears next to the pointer, so it
 * is an independent mode.
 *
 * The nibble accesses are the giveaway: a plain u8 field masked and shifted
 * would fold to `ands`, while the write here is `bic` plus a shifted `orr`
 * and the read is the unequal `lsl #24` / `lsr #28` pair, which is a bitfield
 * extraction (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204B22C.c \
 *       --addr 0x0204B22C --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Bank {
    u8    pad_00[8];
    void *unk_08;
    u8    pad_0c[2];
    u8    source : 4;
    u8    mode   : 4;
    u8    pad_0f[9];
};

void sub_0204B22C(struct Bank *bank, u32 mode)
{
    bank->mode = mode;
}

u32 sub_0204B248(struct Bank *bank)
{
    return bank->mode;
}

void sub_0204B258(struct Bank *bank, void *p)
{
    bank->unk_08 = p;
    bank->source = 1;
}
