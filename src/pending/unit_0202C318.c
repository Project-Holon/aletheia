/*
 * unit:     yes
 * address:  0x0202C318
 * packet:   pkt_0202C244
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * function: sub_0202C318, sub_0202C320, sub_0202C328, sub_0202C330,
 *           sub_0202C338, sub_0202C340, sub_0202C348, sub_0202C350,
 *           sub_0202C358
 *
 * symbols:
 *   func_0202C4C8  0x0202C4C8  thumb
 *
 * Nine pool-word-and-bx tail calls back to back
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md), each 4 bytes: one
 * `ldr r3, [pc, #0]; bx r3` and its own pool word, with no gap between one
 * function's pool word and the next function's instruction. Every
 * concrete byte matches.
 *
 * Eight of the nine relocations stay unresolved: sub_0202C3E0,
 * sub_0202C470, sub_0202C48C, sub_0202C498, sub_0202C4A4, sub_0202C4D8,
 * sub_0202C504 and sub_0202C518 are none of them called by a direct
 * `bl`/`b` anywhere in the image; the only way anything reaches them is
 * through one of these nine pool-word-and-bx trampolines, which is inside
 * the range under test. The ninth, sub_0202C340's call to 0x0202C4C8,
 * does resolve: that address is the unlabelled leaf of
 * src/matched/sub_0202C4C8.c, matched independently, so the `matched`
 * class covers it (`python tools/match.py manifest --verify --shard
 * pkt_0202C244` must run first for that entry to be on disk).
 *
 * sub_0202C4D8 is now matched too (src/matched/sub_0202C4D8.c, EXACT).
 * sub_0202C470, sub_0202C48C, sub_0202C498, sub_0202C4A4, sub_0202C504
 * and sub_0202C518 all forward, through the four-way trampoline of
 * src/pending/unit_0202C548.c, to targets that unit does not yet cover
 * (its own header records why), so none of the six resolves until that
 * file promotes. sub_0202C3E0 is a 144-byte routine with a loop and
 * multiple SDK calls (FSi_ConvertStringSjisToUnicode at 0x02048F74);
 * it has not been attempted.
 *
 * Closes when the last seven are matched (the `matched` class then
 * covers each site with no cut needed), or when the image acquires a
 * second, non-trampoline caller for one of them.
 *
 * Verified with:
 *   python tools/match.py tu --src src/pending/unit_0202C318.c \
 *       --addr 0x0202C318 --thumb
 */

typedef unsigned int u32;

extern u32 sub_0202C3E0(void *a, void *b);
extern u32 sub_0202C470(void *p);
extern u32 sub_0202C48C(void *p);
extern u32 sub_0202C498(void *p);
extern u32 sub_0202C4A4(void *p);
extern u32 func_0202C4C8(void *p);
extern u32 sub_0202C4D8(void *a, void *b);
extern u32 sub_0202C504(void *p);
extern u32 sub_0202C518(void *p);

u32 sub_0202C318(void *a, void *b)
{
    return sub_0202C3E0(a, b);
}

u32 sub_0202C320(void *p)
{
    return sub_0202C470(p);
}

u32 sub_0202C328(void *p)
{
    return sub_0202C48C(p);
}

u32 sub_0202C330(void *p)
{
    return sub_0202C498(p);
}

u32 sub_0202C338(void *p)
{
    return sub_0202C4A4(p);
}

u32 sub_0202C340(void *p)
{
    return func_0202C4C8(p);
}

u32 sub_0202C348(void *a, void *b)
{
    return sub_0202C4D8(a, b);
}

u32 sub_0202C350(void *p)
{
    return sub_0202C504(p);
}

u32 sub_0202C358(void *p)
{
    return sub_0202C518(p);
}
