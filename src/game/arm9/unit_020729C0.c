/*
 * file:     unit_020729C0.c
 * function: func_020729C0
 * address:  0x020729C0
 * packet:   pkt_020729C0
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_0214DEC0  0x0214DEC0  data
 *
 * Channel allocator, allocate-by-index over the 8-bit bitmap at g_0214DEC0+4.
 * Walks i = 0..7 with a running bit that starts at 1 and doubles, sets and
 * returns the first free index, returns -1 (`mvn r0,#0`) when all eight are
 * taken.  Matched src/matched/func_02072A08.c is the matching free.
 *
 * Two levers, both visible in the image:
 *   - the loop bound is a LITERAL 8 (`cmp r0,#8` / `blt`), signed, not a
 *     sizeof or a field.
 *   - the hit arm RE-READS the bitmap (`ldr r1,[pc,#0x24] / ldr r2,[r1,#4]`)
 *     rather than reusing the `flags` copy the guard tested.  That is what the
 *     separate `flags` local plus the plain `g_0214DEC0.flags4 |= bit` store
 *     spells; writing `flags |= bit; g_0214DEC0.flags4 = flags;` reuses the
 *     cached load and loses the second pool word.
 *
 * PIN ../2.0/sp2, the "kept constants" tell (docs/FRONTEND-PINS.md, and
 * docs/families/cluster_020726D0.h).  THE C BELOW IS UNCHANGED from the version
 * this file carried while it was parked in src/pending as DIFF: only the
 * compiler moved.  Under dsi/1.1p1 the base is live at the loop head and again
 * in the hit arm, so it is hoisted into a callee-saved register and the two
 * pool entries (0x02072A00's neighbours at +0x3c and +0x24 reach the SAME word)
 * fold into one: 46 concrete bytes out at the same 72 bytes.  Under the pin the
 * same C is 72 bytes, 0 mismatches.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_020729C0.c \
 *       --func func_020729C0 --addr 0x020729C0 --cc ../2.0/sp2 --arm
 */

struct Global0214DEC0_2 {
    char pad[4];
    int flags4;
};

extern struct Global0214DEC0_2 g_0214DEC0;

int func_020729C0(void)
{
    int bit = 1;
    int flags = g_0214DEC0.flags4;
    int i;
    for (i = 0; i < 8; i++) {
        if ((flags & bit) == 0) {
            g_0214DEC0.flags4 |= bit;
            return i;
        }
        bit <<= 1;
    }
    return -1;
}
