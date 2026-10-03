/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x02013DF0
 * packet:   pkt_02013BA8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02013DF0, sub_02013E04, sub_02013E40, sub_02013E4C,
 *           sub_02013E6C, sub_02013E7C
 *
 * symbols:
 *   sub_02013AD0  0x02013AD0  thumb
 *   sub_02013A94  0x02013A94  thumb
 *   sub_02013CC8  0x02013CC8  thumb
 *   sub_02013CE0  0x02013CE0  thumb
 *   sub_02013D00  0x02013D00  thumb
 *   sub_02013D5C  0x02013D5C  thumb
 *   sub_02013D74  0x02013D74  thumb
 *
 * alias: the last id predicate, sub_02013E04, and three more leaf accessors
 * on the record sub_02013AD0() returns.  sub_02013D74 (a documented near
 * miss, see unit_02013C10.c) is only reached here as an ordinary extern
 * call from sub_02013E04, which does not need sub_02013D74's own body to
 * be attested, only the call to it.
 *
 * sub_02013E04 returns true only when NONE of five predicates
 * (sub_02013CC8, sub_02013CE0, sub_02013D00, sub_02013D5C, sub_02013D74)
 * match, written as the direct disjunction `if (a || b || c || d || e)
 * return 0; return 1;`.  Splitting the disjunction into two `if`s, or
 * writing the same thing as `if (x) return 0;` five times, both changed
 * which comparisons share the shared-exit block with which: this compiler
 * only tail-merges an early `return 0;` across every operand of one `||`
 * expression, and only the last operand gets different codegen (its
 * comparison result stands for the whole expression rather than branching
 * past a shared block), so the five calls have to be one source-level
 * disjunction to reproduce the original's four-shared/one-different shape.
 *
 * The record's halfword at +0x1a is a ten-bit low field and a six-bit high
 * field, the same two-way split as the +0x1c and +0x1e halfwords documented
 * in unit_02013C10.c and unit_02013BA8.c.  sub_02013E4C reads the low field
 * and then substitutes 0x70 for either of the two values immediately above
 * it (0x70 and 0x71): the substitution test adds the POOL CONSTANT 0xff90
 * (-0x70 as an unsigned 16-bit value) rather than subtracting the immediate
 * 0x70, the same non-foldable-immediate shape documented in
 * unit_02013CC8.c for sub_02013CE0 and sub_02013D00.
 *
 * Near miss: sub_02013E90 (0x02013E90 to 0x02013EC0, 48 bytes) reproduces
 * every concrete byte of its first half (the va==vb case) but the two
 * remaining special cases (0 and 0xaf treated as equivalent to each other)
 * compile to a different shared-exit shape than the original under every
 * phrasing tried: two plain `&&` conjunctions, one written as a nested
 * `if`, and both orders of the pair.  It is not in this file; see
 * unit_02013EC0.c for what resumes after it.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02013DF0.c \
 *       --addr 0x02013DF0 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *sub_02013AD0(u32 id);
extern u16 sub_02013A94(u32 key);
extern u32   sub_02013CC8(u32 id);
extern u32   sub_02013CE0(u32 id);
extern u32   sub_02013D00(u32 id);
extern u32   sub_02013D5C(u32 id);
extern int sub_02013D74(u32 key);

struct Sub02013AD0Rec {
    u8 pad00[4];
    u16 unk04;
    u8 pad06[0x14 - 6];
    u16 unk14;
    u16 unk16;
    u16 unk18;
    struct {
        u16 lo10 : 10;
        u16 hi6 : 6;
    } unk1a;
};

u32 sub_02013DF0(u32 id)
{
    return sub_02013A94(id) == 0x4e;
}

u32 sub_02013E04(u32 id)
{
    if (sub_02013CC8(id) || sub_02013CE0(id) || sub_02013D00(id) ||
        sub_02013D5C(id) || sub_02013D74(id))
        return 0;
    return 1;
}

u32 sub_02013E40(u32 id)
{
    struct Sub02013AD0Rec *r = sub_02013AD0(id);
    return r->unk18;
}

u32 sub_02013E4C(u32 id)
{
    struct Sub02013AD0Rec *r = sub_02013AD0(id);
    u32 v = r->unk1a.lo10;

    if ((u16)(v + 0xff90) <= 1)
        v = 0x70;
    return v;
}

u32 sub_02013E6C(u32 id)
{
    struct Sub02013AD0Rec *r = sub_02013AD0(id);
    return r->unk1a.hi6;
}

u32 sub_02013E7C(u32 id)
{
    struct Sub02013AD0Rec *r = sub_02013AD0(id);
    return r->unk04 == 0;
}
