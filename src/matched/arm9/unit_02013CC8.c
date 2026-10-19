/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x02013CC8
 * packet:   pkt_02013BA8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: ZONEDATA_IsUnionRoom, ZONEDATA_IsZone96Pair, ZONEDATA_IsZone4BPair, ZONEDATA_IsZone34,
 *           ZONEDATA_IsNoGameEventZone, ZONEDATA_IsEntralink
 *
 * symbols:
 *   ZONEDATA_GetChangedZoneId  0x02013A94  thumb
 *
 * alias: a run of id-classification predicates on the remapped id
 * ZONEDATA_GetChangedZoneId() returns, plus ZONEDATA_IsNoGameEventZone, which is a plain disjunction
 * of three of them.  sub_02013C70/C80/C9C, immediately before this file,
 * and ZONEDATA_IsZoneGroup118To13C, immediately after it, are documented near misses and
 * are not in this file; see unit_02013C10.c and unit_02013D9C.c.
 *
 * ZONEDATA_IsZone96Pair and ZONEDATA_IsZone4BPair reject an id outside a two-value window by
 * adding a POOL CONSTANT rather than subtracting an immediate (0xff6a /
 * 0xffb5, i.e. +65386 / +65461, not -0x96 / -0x4b): those values do not fit
 * an 8-bit immediate as spelled, and mwccarm never folds the arithmetic
 * back down to a subs regardless of how the literal is written in C, so the
 * pool word is what has to be reproduced, not a stylistic choice.
 *
 * ZONEDATA_IsNoGameEventZone is a genuine `||` of ZONEDATA_IsUnionRoom, ZONEDATA_IsZone96Pair and
 * ZONEDATA_IsZone34 (single conjunction/disjunction sharing one exit block),
 * confirmed by trying it first as three separate `if (x) return 1;`
 * statements: that phrasing gives each early return its own copy of the
 * epilogue and comes out with the wrong branch polarity on the last check,
 * because at that point every one of the three callees becomes a real
 * `label`-attested extern (this file is the second caller each of them
 * needed) rather than a `local` call, and the codegen the docs describe
 * for a single boolean expression is what the original bytes show.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02013CC8.c \
 *       --addr 0x02013CC8 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 ZONEDATA_GetChangedZoneId(u32 key);

u32 ZONEDATA_IsUnionRoom(u32 id)
{
    return ZONEDATA_GetChangedZoneId(id) == 0x1a6;
}

u32 ZONEDATA_IsZone96Pair(u32 id)
{
    return (u16)(ZONEDATA_GetChangedZoneId(id) + 0xff6a) <= 1;
}

u32 ZONEDATA_IsZone4BPair(u32 id)
{
    return (u16)(ZONEDATA_GetChangedZoneId(id) + 0xffb5) <= 1;
}

u32 ZONEDATA_IsZone34(u32 id)
{
    return ZONEDATA_GetChangedZoneId(id) == 0x34;
}

u32 ZONEDATA_IsNoGameEventZone(u32 id)
{
    return ZONEDATA_IsUnionRoom(id) || ZONEDATA_IsZone96Pair(id) || ZONEDATA_IsZone34(id);
}

u32 ZONEDATA_IsEntralink(u32 id)
{
    return ZONEDATA_GetChangedZoneId(id) == 0x117;
}
