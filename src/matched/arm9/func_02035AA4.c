/*
 * function: TOUCHPANEL_HitRect
 * address:  0x02035AA4
 * packet:   pkt_02035760
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The rectangular counterpart of src/matched/TOUCHPANEL_HitCircle.c, on the same
 * packed four-byte record: a point (a, b) is inside when both distances from
 * the low corner fit in the record's width and height, each spelled as the
 * one-sided range test `v - lo <= hi - lo`.
 *
 * Written as `if (c1 && c2) return 1; return 0;`, the whole body compiles to
 * a single chain of conditionally executed instructions - the second pair of
 * loads, the two subtractions and the comparison all carry the LS condition
 * of the first comparison, and the two `movls`/`movhi` are the boolean - and
 * that chain is exactly the original.  A bare `return c1 && c2;` instead
 * presets a zero register and branches, which is 4 bytes longer and does not
 * match; the `return`-in-`if` spelling is what this source needs, the same
 * shape docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md
 * describes for the disjunction.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/TOUCHPANEL_HitRect.c \
 *       --func TOUCHPANEL_HitRect --addr 0x02035AA4 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

u32 TOUCHPANEL_HitRect(u8 *p, u32 a, u32 b)
{
    if (a - p[2] <= (u32)(p[3] - p[2]) && b - p[0] <= (u32)(p[1] - p[0]))
        return 1;
    return 0;
}
