/*
 * function: func_02072A08
 * address:  0x02072A08
 * packet:   pkt_020729C0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_0214DEC0  0x0214DEC0  data
 *
 * Frees one channel of the 8-bit bitmap at g_0214DEC0+4, the matching release
 * for matched func_020729C0's allocate.
 *
 * The parameter is an INDEX, not a mask: `mov r2,#1 / mvn r0, r2, lsl r0` at
 * 0x02072A0C shows the shift happening INSIDE the complement, i.e. `~(1u << b)`
 * as one expression.  Spelling it `u32 m = 1u << b; ... &= ~m;` splits the
 * complement out and costs an extra instruction.  Compare func_020729A4, whose
 * `mvn r0, r0` on the bare parameter proves IT takes a mask.
 *
 * NO PIN NEEDED: EXACT under both dsi/1.1p1 and ../2.0/sp2 (the base pool word
 * is live at exactly one point, so there is nothing for 1.1p1 to hoist).
 * Recorded because its cluster neighbours DO need ../2.0/sp2; see
 * docs/families/cluster_020726D0.h.
 *
 * This file was parked in src/pending at MATCH only because the `symbols:`
 * block was missing its g_0214DEC0 line, so the single ABS32 site had no
 * address to resolve; the C was always byte-correct.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02072A08.c \
 *       --func func_02072A08 --addr 0x02072A08 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct Struct0214DEC0 {
    u32 field0;
    u32 field4;
    u32 field8;
};

extern struct Struct0214DEC0 g_0214DEC0;

void func_02072A08(u32 bit)
{
    g_0214DEC0.field4 &= ~(1U << bit);
}
