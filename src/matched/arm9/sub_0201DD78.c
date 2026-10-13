/*
 * function: GF_FONT_SetTextColor
 * address:  0x0201DD78
 * packet:   pkt_0201DD78
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_02146578   0x02146578  data
 *   g_02146588   0x02146588  data
 *
 * gf_font.c's text-colour setter, 136 bytes.  It records the three requested
 * palette indices in g_02146578 (the three bytes src/matched/unit_0201DE00.c
 * reads back) and then rebuilds the 256-entry expansion table at 0x02146588: a
 * byte of four 2-bit pixels indexes it and the halfword it yields is the same
 * four pixels widened to a nibble each.  The four nested loops enumerate the
 * four pixels; the local array is { 0, r, g, b }, so pixel value 0 stays 0 and
 * 1..3 map to the three requested indices.
 *
 * Two details cost time:
 *
 *   - **The disjunction is written innermost-term-first.**  Spelled
 *     `c[i] | c[j] << 4 | c[k] << 8 | c[l] << 12` the left-associated prefix
 *     `c[i] | c[j] << 4` is invariant in the two inner loops, mwcc hoists it,
 *     and the function is four bytes short with the partial results living in
 *     `ip` and `lr`.  Written the other way round, `c[l] << 12` leads and no
 *     prefix of the chain is loop-invariant, so only the three shifted terms
 *     are hoisted, one per loop level, which is what the original does.
 *   - **The four loop counters are signed.**  The back edges are `blt`, not
 *     `blo`; `u32` counters cost four wrong bytes and nothing else.
 *
 * The store order in the prologue is also load-bearing: the four array slots
 * are written first, the three global bytes after them, and the flat output
 * index last.  Any other order leaves the `strb`s and the `str`s interleaved
 * differently and up to eighteen bytes differ, with the instruction multiset
 * unchanged.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201DD78.c \
 *       --func GF_FONT_SetTextColor --addr 0x0201DD78 --cc 1.1p1 --thumb
 */

#include "../include/G_FontState.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern struct FontState g_02146578;
extern u16 g_02146588[256];

void GF_FONT_SetTextColor(u32 r, u32 g, u32 b)
{
    u32 c[4];
    s32 i;
    s32 j;
    s32 k;
    s32 l;
    u32 n;

    c[0] = 0;
    c[1] = r;
    c[2] = g;
    c[3] = b;
    ((u8 *)&g_02146578)[0] = (u8)r;
    ((u8 *)&g_02146578)[1] = (u8)g;
    ((u8 *)&g_02146578)[2] = (u8)b;
    n = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 4; k++) {
                for (l = 0; l < 4; l++) {
                    g_02146588[n] = (u16)((c[l] << 12) | (c[k] << 8) |
                                          (c[j] << 4) | c[i]);
                    n++;
                }
            }
        }
    }
}
