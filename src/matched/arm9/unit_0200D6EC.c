/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 * unit:     yes
 * address:  0x0200D6EC
 * packet:   pkt_0200D6D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: GDS_PROFILE_GetEggFlag, GDS_PROFILE_GetSpecies, GDS_PROFILE_GetFormSpecies, GDS_PROFILE_GetNicknameFlag,
 *           GDS_PROFILE_GetBadEggFlag
 *
 * 96 bytes, 0x0200D6EC..0x0200D74C, 5 functions, none of which carries a
 * label in the generated listing.
 *
 * Five validating getters on one record: a byte at +0x14, three bitfields
 * packed into the byte at +0x1B and a halfword at +0x1C.  Each one reads the
 * field and substitutes a safe value when it is out of range, and the shape
 * of the guard is what says how the source was written.
 *
 * GDS_PROFILE_GetEggFlag and GDS_PROFILE_GetNicknameFlag both test the value against 0 and then
 * against 1 with two `beq` to the same address, which is one `if` with `&&`
 * and not two statements; see
 * docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md.
 * That the test survives at all in GDS_PROFILE_GetNicknameFlag is the interesting part: the
 * field there is one bit wide, so `v != 0 && v != 1` is provably false and
 * the compiler still emits both compares, which is the same reading as
 * docs/idioms/a-guard-on-a-struct-member-survives-constant-folding.md.
 *
 * GDS_PROFILE_GetBadEggFlag clamps rather than zeroes, and the branch is `bls` over a
 * `movs r0, #1`, so its guard is `if (v > 1) v = 1;` and the fall-through arm
 * is the assignment.
 *
 * The bitfield widths are read off the shift pairs: `lsls #0x1F` / `lsrs
 * #0x1F` is bit 0, `lsls #0x18` / `lsrs #0x1F` is bit 7, and `lsls #0x19` /
 * `lsrs #0x1A` is the six bits between them, which is what GDS_PROFILE_GetFormSpecies
 * passes as the second argument of POKE_TOOL_FilterSpecies.
 *
 * symbols:
 *   POKE_TOOL_FilterSpecies  0x02019D58  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int POKE_TOOL_FilterSpecies(u16 a, int b);

struct RecGet {
    u8  unk00[0x14];
    u8  unk14;
    u8  unk15[6];
    u8  b0 : 1;
    u8  b1 : 6;
    u8  b7 : 1;
    u16 unk1C;
};

u32 GDS_PROFILE_GetEggFlag(struct RecGet *p)
{
    u32 v = p->unk14;

    if (v != 0 && v != 1) {
        v = 0;
    }
    return v;
}

u32 GDS_PROFILE_GetSpecies(struct RecGet *p)
{
    u32 v = p->unk1C;

    if (v >= 0x28B) {
        v = 0;
    }
    return v;
}

u32 GDS_PROFILE_GetFormSpecies(struct RecGet *p)
{
    if (p->unk1C >= 0x28B) {
        return 0;
    }
    return POKE_TOOL_FilterSpecies(p->unk1C, p->b1);
}

u32 GDS_PROFILE_GetNicknameFlag(struct RecGet *p)
{
    u32 v = p->b7;

    if (v != 0 && v != 1) {
        v = 0;
    }
    return v;
}

u32 GDS_PROFILE_GetBadEggFlag(struct RecGet *p)
{
    u32 v = p->b0;

    if (v > 1) {
        v = 1;
    }
    return v;
}
