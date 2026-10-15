/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * unit:     yes
 * address:  0x0200BF08
 * packet:   pkt_0200B448
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: INTRUDE_SetMonolithLevel, INTRUDE_GetMonolithLevel, INTRUDE_SetObtainedFlag, INTRUDE_GetObtainedFlags,
 *           INTRUDE_GetMissionClearCount, INTRUDE_IncrementMissionClearCount, INTRUDE_GetPlaySeconds
 *
 * 156 bytes, 0x0200BF08..0x0200BFA4, 7 functions, none of which carries a
 * label in the generated listing.
 *
 * The tail of the 0x1B0-byte record whose size getter and constructor are
 * src/matched/unit_0200BDBC.c: a byte at +0x1A0, a two-byte bitmap at +0x1A1,
 * a clamped counter at +0x1A4 and a `u64` at +0x1A8, which is 0x1B0 exactly.
 * INTRUDE_GetPlaySeconds is the tell for the last of those: it returns +0x1A8 in r0
 * and +0x1AC in r1, which is one 64-bit value and not two out-parameters.
 * See docs/idioms/long-long-aligns-to-four.md.
 *
 * INTRUDE_SetObtainedFlag sets one bit of the bitmap for an id in 0x21..0x26, and the
 * index arithmetic is signed: `lsrs #0x1F` / `lsls #0x1D` / `subs` /
 * `rors #0x1D` is `% 8` on a signed value, exactly as in
 * src/matched/sub_0200A6BC.c, and `& 7` would have been a two-instruction
 * `movs`/`ands`.  The two range tests branch to one exit, so they are one
 * conjunction rather than two early returns.
 *
 * The base address 0x1A1 arrives from a literal pool in both functions that
 * touch the bitmap, because a register-offset `ldrb`/`strb` has no immediate
 * at all; that is the forced case of
 * docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md
 * and not evidence of a second object.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;
typedef signed int     s32;

struct Rec1B0 {
    u8  unk000[0x1A0];
    u8  unk1A0;
    u8  unk1A1[2];
    u8  unk1A3;
    u32 unk1A4;
    unsigned long long unk1A8;
};

void INTRUDE_SetMonolithLevel(struct Rec1B0 *p, u32 v)
{
    p->unk1A0 = v;
}

u8 INTRUDE_GetMonolithLevel(struct Rec1B0 *p)
{
    return p->unk1A0;
}

void INTRUDE_SetObtainedFlag(struct Rec1B0 *p, s32 id)
{
    s32 n = id - 0x21;

    if (n >= 0 && id <= 0x26) {
        p->unk1A1[n / 8] |= (u8)(1 << (n % 8));
    }
}

void INTRUDE_GetObtainedFlags(struct Rec1B0 *p, u8 *dest, u32 n)
{
    s32 i;

    for (i = 0; i < 2; i++) {
        dest[i] = p->unk1A1[i];
    }
}

u32 INTRUDE_GetMissionClearCount(struct Rec1B0 *p)
{
    return p->unk1A4;
}

u32 INTRUDE_IncrementMissionClearCount(struct Rec1B0 *p)
{
    if (p->unk1A4 < 99999) {
        p->unk1A4++;
    }
    return p->unk1A4;
}

unsigned long long INTRUDE_GetPlaySeconds(struct Rec1B0 *p)
{
    return p->unk1A8;
}
