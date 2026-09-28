/*
 * function: func_020477D4
 * address:  0x020477D4
 * packet:   pkt_020477D4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02069F7C   0x02069F7C  arm
 *
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
 *
 * Hand the indexed sub-record's +4 word to func_02069F7C, along with the
 * owner's own +4 record's +4 word: the pointer chain is two `ldr`s deep on
 * the owner side and one on the sub-record side, and nothing is loaded until
 * the null test has passed, because the failure path is a predicated
 * `moveq`/`popeq` off the compare.
 *
 * Every concrete byte is right.  The single PC24 stays wildcarded: 0x02069F7C
 * is called from this site and nowhere else the harness can see, it is not in
 * the manifest, and a one-function range admits no cut (--suggest-split cannot
 * help).  Blocking evidence class: label/matched, no witness.  It unsticks the
 * moment 0x02069F7C is itself EXACT (`matched` class) or a second caller of it
 * turns up in an overlay.
 *
 * The `*` is the unlabelled follower at 0x02047804 (a leaf with no lr-saving
 * prologue) making disasm.py's extent for the original run to 0x02047970.
 */

typedef unsigned int u32;

struct Sub {
    u32 pad_00;
    u32 unk_04;
};

struct Mid {
    u32 pad_00;
    u32 unk_04;
};

struct Owner {
    u32      pad_00;
    struct Mid *unk_04;
    struct Sub **unk_08;
};

extern void func_02069F7C(u32 a, u32 b);

int func_020477D4(struct Owner *owner, u32 index)
{
    struct Sub *sub = owner->unk_08[index];

    if (sub == 0)
        return 0;

    func_02069F7C(owner->unk_04->unk_04, sub->unk_04);
    return 1;
}
