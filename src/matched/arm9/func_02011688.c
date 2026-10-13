/*
 * function: ICA_ANIME_GetTranslateAt
 * address:  0x02011688
 * packet:   pkt_02011688
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   _u32_div_f     0x0209C2B0  arm
 *
 * Copy frame `idx % count` of the f1c Rec12 table out to dst when the table
 * length at +0x18 equals the count at +0x0C; returns 1, else 0.  EXACT* because
 * the listing extent (56) includes the 2-byte `movs r0, r0` pad after the
 * second epilogue; the 54 code bytes are exact.
 *
 * Load-bearing (wave 20, after five waves at 14 to 26 out):
 *  - `idx %= n;` writes the remainder back into the PARAMETER, which homes it
 *    in r2 (`adds r2, r1, #0` before the compare).  A named local coalesces
 *    with the helper's r1 return instead.
 *  - the table base as an integer: `u32 base = (u32)p->f1c;` with a u32 byte
 *    offset `off = idx * 12`, the first field read at base + off and the
 *    cursor advanced in place (`base += off`) for +4 and +8.  With the base as
 *    an integer the multiply goes into a copy of idx (`adds r3, r2, #0;
 *    muls r3, r0, r3`) and the base is loaded after 12, as in the image;
 *    every pointer spelling (&p->f1c[idx], t[idx], a struct cursor) multiplies
 *    idx in place.  Same family as
 *    docs/idioms/a-region-symbol-cast-to-u32-keeps-the-bound-an-add.md.
 *  - the two-return shape `if (==) { ...; return 1; } return 0;` gives the
 *    image's fall-through body and its two epilogues.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ICA_ANIME_GetTranslateAt.c \
 *       --func ICA_ANIME_GetTranslateAt --addr 0x02011688 --cc 1.1p1 --thumb
 */
#include "../include/Obj11246.h"

typedef unsigned char  u8;
typedef unsigned int   u32;
typedef int            s32;

struct Rec12 { s32 a; s32 b; s32 c; };

struct IcaAnime {
    u8  pad00[0x0c];
    u32 f0c;
    s32 f10;
    s32 f14;
    u32 f18;
    struct Rec12 *f1c;
};

u32 ICA_ANIME_GetTranslateAt(struct IcaAnime *p, struct Rec12 *dst, u32 idx)
{
    u32 n = p->f0c;

    idx %= n;
    if (p->f18 == n) {
        u32 off = idx * 12;
        u32 base = (u32)p->f1c;
        dst->a = *(s32 *)(base + off);
        base += off;
        dst->b = ((struct Obj11246 *)base)->f4;
        dst->c = ((struct Obj11246 *)base)->f8;
        return 1;
    }
    return 0;
}
