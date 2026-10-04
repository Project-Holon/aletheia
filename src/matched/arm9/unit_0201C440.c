/*
 * unit:     yes
 * address:  0x0201C440
 * packet:   pkt_0201BD28
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_0201C440
 *
 * A 12-byte pool-word-and-bx tail call
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md), swapping its own
 * parameter into the callee's second argument slot and passing the literal
 * 0x400 as the first: `sub_0201C450(0x400, p)`.  sub_0201C450 (0x0201C450)
 * is a bigger constructor with an inline division-by-multiplication trick
 * and is left as an unresolved extern; only its address is needed here.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C440.c \
 *       --addr 0x0201C440 --thumb
 */

typedef unsigned int u32;

typedef unsigned short u16;
extern void *sub_0201C450(u16 n, u32 heap);

u32 sub_0201C440(void *p)
{
    return (u32)sub_0201C450(0x400, (u32)p);
}
