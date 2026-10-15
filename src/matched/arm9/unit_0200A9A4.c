/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0200A9A4
 * packet:   pkt_0200A940
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: IRC_RANKING_IsEntryNew, IRC_RANKING_HasEntry
 *
 * The two helpers between func_0200A940 and IRC_RANKING_GetDateScore, both invisible
 * to the worklist: each saves registers but not lr and nothing branches to
 * either from outside, so disasm.py prints the pair as a single run of
 * `.word` (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * The 92 bytes here cover the whole gap.
 *
 * Both walk the same array of 0x1e records of 0x1c bytes that
 * func_0200A940 above them indexes, and both accept a record on the same
 * pair of tests: the u32 at +0x14 equal to the key and bit 31 of the u32
 * at +0x10 set.  The first returns bit 7 of the byte at +0x1b of the
 * matching record, the second returns 1.
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct T0200A9A4 {
    u8  pad00[0x10];
    u32 f10;
    u32 f14;
    u8  pad18[3];
    u8  f1b;
};

int IRC_RANKING_IsEntryNew(struct T0200A9A4 *o, u32 v)
{
    int i;

    for (i = 0; i < 0x1e; i++) {
        if (o[i].f14 == v && (o[i].f10 >> 31) == 1)
            return (u32)(o[i].f1b << 24) >> 31;
    }
    return 0;
}

int IRC_RANKING_HasEntry(struct T0200A9A4 *o, u32 v)
{
    int i;

    for (i = 0; i < 0x1e; i++) {
        if (o[i].f14 == v && (o[i].f10 >> 31) == 1)
            return 1;
    }
    return 0;
}
