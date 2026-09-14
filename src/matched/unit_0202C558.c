/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0202C558
 * packet:   pkt_0202C4CC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_0202C558, sub_0202C560, sub_0202C568, sub_0202C570,
 *           sub_0202C578, sub_0202C580, sub_0202C588
 *
 * symbols:
 *   sub_0202C72C   0x0202C72C  thumb
 *   sub_0202C670   0x0202C670  thumb
 *   sub_0202C688   0x0202C688  thumb
 *   func_0202C6A0  0x0202C6A0  thumb
 *   func_0202C6AC  0x0202C6AC  thumb
 *   sub_0202C5F0   0x0202C5F0  thumb
 *   sub_0202C710   0x0202C710  thumb
 *
 * Seven of the nine pool-word-and-bx tail calls at 0x0202C548
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md), 8 bytes each with no
 * gap: one `ldr r3, [pc, #0]; bx r3` and its own pool word. The
 * dispatch table of the window-frame family, one entry per operation.
 *
 * This file was src/pending/unit_0202C548.c, which carried all nine (bar
 * sub_0202C550, split out to src/matched/sub_0202C550.c) and was capped
 * at MATCH because none of the four targets sub_0202C5F0, sub_0202C670,
 * sub_0202C688 and sub_0202C710 is reached by a direct `bl`/`b` anywhere
 * in the image: the trampoline here is the only reference, and it is
 * inside the range under test, so no cut can reach a witness. All four
 * now have EXACT entries of their own and the `matched` class witnesses
 * each of them (docs/MATCHING.md, "The matched class"):
 *
 *   0x0202C670  src/matched/unit_0202C670.c
 *   0x0202C688  src/matched/sub_0202C688.c   (needed sub_0202C760 first)
 *   0x0202C5F0  src/matched/unit_0202C5F0.c  (was a codegen near miss)
 *   0x0202C710  src/matched/sub_0202C710.c   (needed sub_0202C6C4 first)
 *
 * The other three resolve as they always did: sub_0202C72C by `label`
 * from its two direct callers, func_0202C6A0 and func_0202C6AC by
 * `matched` from src/matched/unit_0202C6A0.c. The address range starts at
 * 0x0202C558 and not 0x0202C548 only because sub_0202C550 was split out
 * of the middle of the run; sub_0202C548 is src/matched/sub_0202C548.c.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202C558.c \
 *       --addr 0x0202C558 --thumb
 */

typedef unsigned int u32;

extern u32 sub_0202C72C(void *p);
extern u32 sub_0202C670(void *p);
extern u32 sub_0202C688(void *p);
extern u32 func_0202C6A0(void *p);
extern u32 func_0202C6AC(void *p);
extern u32 sub_0202C5F0(void *p);
extern u32 sub_0202C710(void *p, u32 v);

u32 sub_0202C558(void *p)
{
    return sub_0202C72C(p);
}

u32 sub_0202C560(void *p)
{
    return sub_0202C670(p);
}

u32 sub_0202C568(void *p)
{
    return sub_0202C688(p);
}

u32 sub_0202C570(void *p)
{
    return func_0202C6A0(p);
}

u32 sub_0202C578(void *p)
{
    return func_0202C6AC(p);
}

u32 sub_0202C580(void *p)
{
    return sub_0202C5F0(p);
}

u32 sub_0202C588(void *p, u32 v)
{
    return sub_0202C710(p, v);
}
