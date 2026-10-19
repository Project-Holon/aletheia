/*
 * function: PRINTSYS_MeasureTextWidth
 * address:  0x0201D26C
 * packet:   pkt_0201CEE0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GF_FONT_GetCharWidth  0x0201DC6C  thumb
 *
 * printsys.c: measures one line of a string object.  It sums the per-glyph
 * advance GF_FONT_GetCharWidth returns plus a fixed inter-character spacing until it
 * hits the line break 0xFFFE or the terminator 0xFFFF, steps over embedded
 * 0xF000 blocks (three header halfwords plus the payload count at +4), and,
 * when the fourth argument is non-NULL, writes back the cursor for the next
 * line (past the break, if that is what stopped it).
 *
 * 0xFFFF is not pooled: the compiler keeps the pooled 0xFFFE in a register and
 * derives the terminator as `adds r6, r0, #1`.
 *
 * The repeated `c == 0xF000` test is the source's own: the block skip re-tests
 * the code word it was selected by, and the compiler keeps the second branch
 * while folding away the second compare.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PRINTSYS_MeasureTextWidth.c
 *       --func PRINTSYS_MeasureTextWidth --addr 0x0201D26C --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Font;
extern u32 GF_FONT_GetCharWidth(struct Font *p, u16 ch);

u32 PRINTSYS_MeasureTextWidth(u16 *p, void *font, u32 spacing, u16 **next)
{
    u32 sum;
    u16 c;

    sum = 0;
    while ((c = *p) != 0xFFFF && c != 0xFFFE) {
        if (c != 0xF000) {
            sum += spacing + GF_FONT_GetCharWidth(font, c);
            p++;
        } else {
            if (c == 0xF000) {
                p = p + 3 + p[2];
            }
        }
    }
    if (next != 0) {
        if (c == 0xFFFE) {
            p++;
        }
        *next = p;
    }
    return sum;
}
