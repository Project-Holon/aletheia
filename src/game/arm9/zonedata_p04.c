/*
 * file:     zonedata_p04.c
 * unit:     yes
 * function: func_02013C9C, func_02013CC8, func_02013CE0, func_02013D00, func_02013D20, func_02013D34, func_02013D5C
 * address:  0x02013C9C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   sub_0209E026_Map  0x0209E026  data
 *   sub_02013A94  0x02013A94  thumb
 */
typedef unsigned int u32;

struct Ent0209E026 {
    unsigned short code : 11;
    unsigned short kind : 5;
};

typedef unsigned short u16;

extern u16 func_02013A94(u32 key);
extern u16 sub_02013A94(u32 key);
int func_02013C9C(u16 key);
u32 sub_02013CC8(u32 id);
u32 sub_02013CE0(u32 id);
u32 sub_02013D00(u32 id);
u32 sub_02013D20(u32 id);
u32 sub_02013D34(u32 id);
u32 sub_02013D5C(u32 id);
extern struct Ent0209E026 sub_0209E026_Map[];


int func_02013C9C(u16 key)
{
    u32 r = func_02013A94(key);
    u32 i;

    for (i = 0; i < 0x14; i++) {
        if (r == sub_0209E026_Map[i].code)
            return sub_0209E026_Map[i].kind;
    }
    return -1;
}


/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_02013D34, sub_02013D5C
 *
 * alias: a run of id-classification predicates on the remapped id
 * sub_02013A94() returns, plus sub_02013D34, which is a plain disjunction
 * of three of them.  sub_02013C70/C80/C9C, immediately before this file,
 * and sub_02013D74, immediately after it, are documented near misses and
 * are not in this file; see unit_02013C10.c and unit_02013D9C.c.
 *
 * sub_02013CE0 and sub_02013D00 reject an id outside a two-value window by
 * adding a POOL CONSTANT rather than subtracting an immediate (0xff6a /
 * 0xffb5, i.e. +65386 / +65461, not -0x96 / -0x4b): those values do not fit
 * an 8-bit immediate as spelled, and mwccarm never folds the arithmetic
 * back down to a subs regardless of how the literal is written in C, so the
 * pool word is what has to be reproduced, not a stylistic choice.
 *
 * sub_02013D34 is a genuine `||` of sub_02013CC8, sub_02013CE0 and
 * sub_02013D20 (single conjunction/disjunction sharing one exit block),
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
u32 sub_02013CC8(u32 id)
{
    return sub_02013A94(id) == 0x1a6;
}


u32 sub_02013CE0(u32 id)
{
    return (u16)(sub_02013A94(id) + 0xff6a) <= 1;
}


u32 sub_02013D00(u32 id)
{
    return (u16)(sub_02013A94(id) + 0xffb5) <= 1;
}


u32 sub_02013D20(u32 id)
{
    return sub_02013A94(id) == 0x34;
}


u32 sub_02013D34(u32 id)
{
    return sub_02013CC8(id) || sub_02013CE0(id) || sub_02013D20(id);
}


u32 sub_02013D5C(u32 id)
{
    return sub_02013A94(id) == 0x117;
}
