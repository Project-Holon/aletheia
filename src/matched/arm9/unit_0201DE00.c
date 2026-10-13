/*
 * unit:     yes
 * address:  0x0201DE00
 * packet:   pkt_0201D6D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: GF_FONT_GetTextColor, GF_FONT_IsTextColorDifferent
 *
 * symbols:
 *   g_02146578   0x02146578  data
 *
 * The current text colour, read back and compared.  g_02146578 is the three
 * bytes func_0201DD78 stores the last requested colour into.
 *
 * GF_FONT_IsTextColorDifferent returns 1 when the colour differs, and its shape is the
 * disjunction form rather than the conjunction: the first two comparisons branch
 * to one shared `movs r0, #1` block and only the last one branches past it,
 * which is what `if (r != c[0] || g != c[1] || b != c[2]) return 1;` gives.
 * Written as `if (all equal) return 0; return 1;` the arms swap and ten of the
 * forty bytes are wrong
 * (docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201DE00.c \
 *       --addr 0x0201DE00 --thumb
 */

#include "../include/G_FontState.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

extern struct FontState g_02146578;

void GF_FONT_GetTextColor(u8 *r, u8 *g, u8 *b)
{
    *r = ((u8 *)&g_02146578)[0];
    *g = ((u8 *)&g_02146578)[1];
    *b = ((u8 *)&g_02146578)[2];
}

u32 GF_FONT_IsTextColorDifferent(u32 r, u32 g, u32 b)
{
    if (r != ((u8 *)&g_02146578)[0] || g != ((u8 *)&g_02146578)[1] || b != ((u8 *)&g_02146578)[2]) {
        return 1;
    }
    return 0;
}
