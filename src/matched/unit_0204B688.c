/*
 * unit:     yes
 * function: sub_0204B688
 * address:  0x0204B688
 * packet:   pkt_0204B5D4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Two accessors of the cell actor's u32 flag word at +0x60.  0x0204B6E4 saves
 * no lr and so carries no label in the listing
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); it is a seed
 * for layout/function_starts.txt.
 *
 * The flag word is a dense pile of bitfields.  This pair owns the two-bit
 * field at bits 22..23, and writing it also maintains bit 3 of the four-bit
 * field at bits 8..11: setting a non-zero value sets that bit, setting zero
 * clears it.
 *
 * The clear is spelled `^= 8` under a `& 8` guard, not `&= ~8`.  That is
 * visible in the bytes: `&= ~8` on a four-bit field folds to a single
 * `bic r1, r1, #8`, while the original keeps the guard's `tst r1, #8` and then
 * an `eor r1, r1, #8`, which only a real exclusive or produces.
 *
 * Both arms re-read the field out of the value they just stored, so the write
 * of bits 22..23 has to come first as its own statement; the compiler forwards
 * the store and never reloads from +0x60.
 *
 * The polarity matters: the zero case is the source's then-arm
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md), and inside it the
 * `& 8` test is an early `return`, which is what the original's `bxeq lr` is.
 * Written the other way round the compiler predicates the whole clear
 * sequence, which is four bytes short and moves every instruction.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204B688.c \
 *       --addr 0x0204B688 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Actor {
    u8  pad_00[0x60];
    u32 f_00 : 8;
    u32 f_08 : 4;
    u32 f_0c : 6;
    u32 f_12 : 2;
    u32 f_14 : 2;
    u32 f_16 : 2;
    u32 f_18 : 8;
};

void sub_0204B688(struct Actor *actor, u32 value)
{
    actor->f_16 = value;

    if (value == 0) {
        if ((actor->f_08 & 8) == 0) {
            return;
        }
        actor->f_08 = actor->f_08 ^ 8;
    } else {
        actor->f_08 = actor->f_08 | 8;
    }
}

u32 sub_0204B6E4(const struct Actor *actor)
{
    return actor->f_16;
}
