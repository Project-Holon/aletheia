/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0202C318
 * packet:   pkt_0202C244
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
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
 * This was src/pending/unit_0202C318.c for two waves. Eight of its nine
 * relocations had no witness at all: sub_0202C3E0, sub_0202C470,
 * sub_0202C48C, sub_0202C498, sub_0202C4A4, sub_0202C4D8, sub_0202C504
 * and sub_0202C518 are none of them called by a direct `bl`/`b` anywhere
 * in the image, so the only reference to each is the trampoline here,
 * which is inside the range under test and which no cut can put outside
 * it. The ninth, sub_0202C340's call to 0x0202C4C8, always resolved:
 * that address is the unlabelled leaf of src/matched/sub_0202C4C8.c.
 *
 * What closed it is nine EXACT entries and no cut, one per site, through
 * the `matched` class (docs/MATCHING.md, "The matched class"):
 *
 *   0x0202C3E0  src/matched/sub_0202C3E0.c
 *   0x0202C470  src/matched/unit_0202C470.c
 *   0x0202C48C  src/matched/sub_0202C48C.c
 *   0x0202C498  src/matched/sub_0202C498.c
 *   0x0202C4A4  src/matched/unit_0202C4A4.c
 *   0x0202C4C8  src/matched/sub_0202C4C8.c
 *   0x0202C4D8  src/matched/sub_0202C4D8.c
 *   0x0202C504  src/matched/sub_0202C504.c
 *   0x0202C518  src/matched/unit_0202C518.c
 *
 * Six of those nine were themselves blocked until src/matched/unit_0202C558.c
 * promoted, because each is one `bl` into the second trampoline run at
 * 0x0202C548; that file in turn waited on sub_0202C5F0 and sub_0202C710.
 * The whole family is one chain of trampolines whose leaves had to be
 * matched from the far end inwards.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202C318.c \
 *       --addr 0x0202C318 --thumb
 */

typedef unsigned int u32;

struct Obj0202C3E0;
extern u32 sub_0202C3E0(struct Obj0202C3E0 *a, void *b);
extern u32 sub_0202C470(void *p);
extern u32 sub_0202C48C(void *p, u32 idx);
extern u32 sub_0202C498(void *p, u32 idx);
extern u32 sub_0202C4A4(void *p);
extern u32 func_0202C4C8(u32 *p);
extern u32 sub_0202C4D8(void *a, void *b);
extern u32 sub_0202C504(void *p, u32 idx);
extern u32 sub_0202C518(void *p);

u32 sub_0202C318(void *a, void *b)
{
    return sub_0202C3E0(a, b);
}

u32 sub_0202C320(void *p)
{
    return sub_0202C470(p);
}

u32 sub_0202C328(void *p, u32 idx)
{
    return sub_0202C48C(p, idx);
}

u32 sub_0202C330(void *p, u32 idx)
{
    return sub_0202C498(p, idx);
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

u32 sub_0202C350(void *p, u32 idx)
{
    return sub_0202C504(p, idx);
}

u32 sub_0202C358(void *p)
{
    return sub_0202C518(p);
}
