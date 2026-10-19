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
 * function: ZONEDATA_IsZone4E, ZONEDATA_IsNormalFieldZone, ZONEDATA_GetParentZoneId, ZONEDATA_GetPlaceNameId,
 *           ZONEDATA_GetPlaceNameWindow, ZONEDATA_IsFieldMatrix
 *
 * symbols:
 *   ZONEDATA_GetHeader  0x02013AD0  thumb
 *   ZONEDATA_GetChangedZoneId  0x02013A94  thumb
 *   ZONEDATA_IsUnionRoom  0x02013CC8  thumb
 *   ZONEDATA_IsZone96Pair  0x02013CE0  thumb
 *   ZONEDATA_IsZone4BPair  0x02013D00  thumb
 *   ZONEDATA_IsEntralink  0x02013D5C  thumb
 *   ZONEDATA_IsZoneGroup118To13C  0x02013D74  thumb
 *
 * alias: the last id predicate, ZONEDATA_IsNormalFieldZone, and three more leaf accessors
 * on the record ZONEDATA_GetHeader() returns.  ZONEDATA_IsZoneGroup118To13C (a documented near
 * miss, see unit_02013C10.c) is only reached here as an ordinary extern
 * call from ZONEDATA_IsNormalFieldZone, which does not need ZONEDATA_IsZoneGroup118To13C's own body to
 * be attested, only the call to it.
 *
 * ZONEDATA_IsNormalFieldZone returns true only when NONE of five predicates
 * (ZONEDATA_IsUnionRoom, ZONEDATA_IsZone96Pair, ZONEDATA_IsZone4BPair, ZONEDATA_IsEntralink, ZONEDATA_IsZoneGroup118To13C)
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
 * in unit_02013C10.c and unit_02013BA8.c.  ZONEDATA_GetPlaceNameId reads the low field
 * and then substitutes 0x70 for either of the two values immediately above
 * it (0x70 and 0x71): the substitution test adds the POOL CONSTANT 0xff90
 * (-0x70 as an unsigned 16-bit value) rather than subtracting the immediate
 * 0x70, the same non-foldable-immediate shape documented in
 * unit_02013CC8.c for ZONEDATA_IsZone96Pair and ZONEDATA_IsZone4BPair.
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

extern void *ZONEDATA_GetHeader(u32 id);
extern u16 ZONEDATA_GetChangedZoneId(u32 key);
extern u32   ZONEDATA_IsUnionRoom(u32 id);
extern u32   ZONEDATA_IsZone96Pair(u32 id);
extern u32   ZONEDATA_IsZone4BPair(u32 id);
extern u32   ZONEDATA_IsEntralink(u32 id);
extern int ZONEDATA_IsZoneGroup118To13C(u32 key);

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

u32 ZONEDATA_IsZone4E(u32 id)
{
    return ZONEDATA_GetChangedZoneId(id) == 0x4e;
}

u32 ZONEDATA_IsNormalFieldZone(u32 id)
{
    if (ZONEDATA_IsUnionRoom(id) || ZONEDATA_IsZone96Pair(id) || ZONEDATA_IsZone4BPair(id) ||
        ZONEDATA_IsEntralink(id) || ZONEDATA_IsZoneGroup118To13C(id))
        return 0;
    return 1;
}

u32 ZONEDATA_GetParentZoneId(u32 id)
{
    struct Sub02013AD0Rec *r = ZONEDATA_GetHeader(id);
    return r->unk18;
}

u32 ZONEDATA_GetPlaceNameId(u32 id)
{
    struct Sub02013AD0Rec *r = ZONEDATA_GetHeader(id);
    u32 v = r->unk1a.lo10;

    if ((u16)(v + 0xff90) <= 1)
        v = 0x70;
    return v;
}

u32 ZONEDATA_GetPlaceNameWindow(u32 id)
{
    struct Sub02013AD0Rec *r = ZONEDATA_GetHeader(id);
    return r->unk1a.hi6;
}

u32 ZONEDATA_IsFieldMatrix(u32 id)
{
    struct Sub02013AD0Rec *r = ZONEDATA_GetHeader(id);
    return r->unk04 == 0;
}
