/*
 * function: GF_FONT_MeasureWidestLine
 * address:  0x0201D304
 * packet:   pkt_0201CEE0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   STRBUF_GetChars  0x02045A90  arm
 *   GF_FONT_MeasureTextWidth  0x0201D26C  thumb
 *
 * printsys.c: the width of the widest line of a multi-line string.  It walks
 * the string object's halfword payload one line at a time with GF_FONT_MeasureTextWidth,
 * which measures one line and writes the cursor for the next one back through
 * its fourth argument, and keeps the running maximum.  0xFFFF is the string
 * terminator (the same sentinel PRINTSYS_RunJob stops on).
 *
 * The cursor is a local whose address is taken, so it lives on the stack and
 * the loop test reloads it every iteration.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_FONT_MeasureWidestLine.c
 *       --func GF_FONT_MeasureWidestLine --addr 0x0201D304 --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct StrObj {
    u16 capacity;
    u16 used;
    u32 magic;
    u16 slots[1];
};

struct U16Vec;
extern u16 *STRBUF_GetChars(struct U16Vec *vec);
extern u32 GF_FONT_MeasureTextWidth(u16 *p, void *font, u32 spacing, u16 **next);

u32 GF_FONT_MeasureWidestLine(struct StrObj *s, u32 a, u32 b)
{
    u16 *p;
    u32 best;
    u32 w;

    best = 0;
    p = STRBUF_GetChars((struct U16Vec *)s);
    while (*p != 0xFFFF) {
        w = GF_FONT_MeasureTextWidth(p, (void *)a, b, &p);
        if (w > best) {
            best = w;
        }
    }
    return best;
}
