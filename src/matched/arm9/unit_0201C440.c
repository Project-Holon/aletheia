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
 * function: PRINTSYS_QUE_Create
 *
 * A 12-byte pool-word-and-bx tail call
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md), swapping its own
 * parameter into the callee's second argument slot and passing the literal
 * 0x400 as the first: `PRINTSYS_QUE_CreateEx(0x400, p)`.  PRINTSYS_QUE_CreateEx (0x0201C450)
 * is a bigger constructor with an inline division-by-multiplication trick
 * and is left as an unresolved extern; only its address is needed here.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C440.c \
 *       --addr 0x0201C440 --thumb
 *
 * symbols:
 *   PRINTSYS_QUE_CreateEx  0x0201C450  thumb
 */

typedef unsigned int u32;

typedef unsigned short u16;
extern void *PRINTSYS_QUE_CreateEx(u16 n, u32 heap);

u32 PRINTSYS_QUE_Create(void *p)
{
    return (u32)PRINTSYS_QUE_CreateEx(0x400, (u32)p);
}
