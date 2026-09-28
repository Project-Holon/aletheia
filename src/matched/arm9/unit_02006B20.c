/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x02006B20
 * packet:   pkt_020064F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02006B20, sub_02006B3C, sub_02006B5C, sub_02006B78,
 *           sub_02006B94, sub_02006BB4, sub_02006BD0, sub_02006BE0,
 *           sub_02006C00
 *
 * symbols:
 *   sub_02006B20_Table  0x02140488  data
 *   func_02006948       0x02006948  thumb
 *
 * Nine consecutive functions of the sound channel file.  The object is a
 * table of 0x34 byte channel records at 0x02140488, seventeen literal pools
 * in the region hold its address, and the index arithmetic is a `muls` by
 * 0x34 rather than a shift because the size is not a power of two.
 *
 * Six of the nine carry no label in the generated listing, because a getter
 * that saves nothing has no prologue for disasm.py's sweep to fire on and
 * lands in the listing as a run of `.word`s:
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.  They are
 * sub_02006B20, sub_02006B3C, sub_02006B5C, sub_02006B78, sub_02006B94,
 * sub_02006BD0 and sub_02006C00.
 *
 * Three details pin the source:
 *
 *  - sub_02006B20 returns the field at +0x1C with a register offset `ldrsb`,
 *    which is the only evidence anywhere in the range that the field is
 *    signed: docs/idioms/ldrsh-register-offset-is-signedness.md.  The
 *    neighbouring 0x1D is read the same way by sub_02006A8C above.
 *  - sub_02006BB4 computes `&Table[i]` only inside the `if`, where every
 *    other function in the run computes it before the test.  That is the
 *    difference between subscripting the table twice and binding a local
 *    pointer first, and it is two instructions.
 *  - sub_02006C00's guard is `if (species < 1 && species > 649)`, with a
 *    conjunction and not a disjunction.  For unsigned operands that is
 *    unsatisfiable, so the `*out = 1` arm is dead code, but it is what the
 *    bytes say: `cmp r0, #1` / `bhs` and `cmp r0, r3` / `bls` both branch
 *    past it, which is the `||` shape with both tests negated.  Written with
 *    `||` the two branches invert and land on the other arm.  The constants
 *    are the national dex range, 1 to 649, and the pair 492 / 650 the second
 *    test maps is a species with a second form.
 *
 * What is left out below this range, and why.  The whole run
 * 0x02006A64..0x02006D3C reproduces every concrete byte as one compile and
 * comes out MATCH, so none of the five functions held out is a codegen
 * failure; every one of them is blocked by the honesty rule, and the census
 * is from `tu --suggest-split`.
 *
 *   0x02006A64  40 bytes.  `label`: func_02006868 has one witness image wide
 *               and it is the `bl` at 0x02006A70 inside this very function.
 *               No cut can free it.
 *   0x02006A8C  96 bytes.  `label`: func_02072C18 has two witnesses image
 *               wide, 0x02006AB8 and 0x02006AE2, and both are inside this one
 *               function, so the pairwise split of
 *               docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md
 *               does not reach it.
 *   0x02006AEC  52 bytes.  The same shape one function later: func_02072C40
 *               has exactly two witnesses, 0x02006B04 and 0x02006B16, both
 *               inside it.
 *   0x02006C2C  128 bytes.  `label`: func_02007B64 and func_02007B68 have one
 *               witness each, the `bl`s at 0x02006C6E and 0x02006C78 inside
 *               this function.  Its guard chain is
 *               docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md.
 *   0x02006CBC  128 bytes.  Three sites at once.  `label`: func_02006D3C is
 *               named only by the `blx` at 0x02006D22 inside it.  `literal`:
 *               0x020A703C, which spells "snd_mic.c" and is the original file
 *               name of this range, and 0x020A7030, are each named by one pool
 *               word and it is this function's own.  The `string` class does
 *               not reach either: the run in front of 0x020A703C is not
 *               printable ASCII, and 0x020A7030 is itself that run.  Its
 *               allocate, clear and store sequence is
 *               docs/idioms/a-store-that-lands-after-the-next-call-names-a-local-temporary.md.
 *
 * Between the last two sits 0x02006D3C, four bytes of ARM followed by its
 * pointer word: `ldr pc, [pc, #-4]` over 0x027047C0.  That is a linker
 * veneer, so no C produces it, and the `veneer` class refuses it as well
 * because 0x027047C0 is not inside any region of layout/layout.json and so
 * cannot be shown to name code.  The Thumb side of the range therefore ends
 * at 0x02006D3C and resumes at 0x02006D44 in
 * src/matched/unit_02006D44.c.
 */

typedef signed char   s8;
typedef unsigned char u8;
typedef unsigned int  u32;

struct Sub02006B20Chan {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    s8  unk1C;
    s8  unk1D;
    s8  unk1E;
    s8  unk1F;
    u32 unk20;
    u32 unk24;
    u32 unk28;
    u32 unk2C;
    u32 unk30;
};

extern struct Sub02006B20Chan sub_02006B20_Table[];

extern void func_02006948(struct Sub02006B20Chan *chan);

s8 sub_02006B20(u32 i)
{
    struct Sub02006B20Chan *chan = &sub_02006B20_Table[i];

    if (chan->unk00 == 0) {
        return 0;
    }
    return chan->unk1C;
}

u32 sub_02006B3C(u32 i)
{
    struct Sub02006B20Chan *chan = &sub_02006B20_Table[i];

    if (chan->unk00 == 0) {
        return 0x64E1;
    }
    return chan->unk20;
}

u32 sub_02006B5C(u32 i)
{
    struct Sub02006B20Chan *chan = &sub_02006B20_Table[i];

    if (chan->unk00 == 0) {
        return 0;
    }
    return chan->unk10;
}

u32 sub_02006B78(u32 i)
{
    struct Sub02006B20Chan *chan = &sub_02006B20_Table[i];

    if (chan->unk00 == 0) {
        return 0;
    }
    return chan->unk08;
}

u32 sub_02006B94(u32 i)
{
    struct Sub02006B20Chan *chan = &sub_02006B20_Table[i];

    if (chan->unk00 == 0) {
        return 0x3443;
    }
    return chan->unk0C;
}

void sub_02006BB4(u32 i)
{
    if (sub_02006B20_Table[i].unk00 == 1) {
        func_02006948(&sub_02006B20_Table[i]);
    }
}

u32 sub_02006BD0(u32 i)
{
    return sub_02006B20_Table[i].unk00;
}

void sub_02006BE0(u8 *p, u32 n)
{
    u32 i;

    for (i = 0; i < n / 2; i++) {
        u8 t = p[i];

        p[i] = p[n - 1 - i];
        p[n - 1 - i] = t;
    }
}

void sub_02006C00(u32 species, u32 form, u32 *out)
{
    if (species < 1 && species > 649) {
        *out = 1;
        return;
    }
    if (species == 492 && form == 1) {
        *out = 650;
        return;
    }
    *out = species;
}
