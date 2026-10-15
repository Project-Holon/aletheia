/*
 * function: GF_FONT_InitCallerSuppliedArray
 * address:  0x0201D33C
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
 * printsys.c: fills a caller-supplied array with the pixel width of each line
 * of a string object, at most `max` of them, and returns how many were
 * written.  GF_FONT_MeasureTextWidth measures one line and hands back the cursor for the
 * next through its fourth argument; the cursor is a stack local because its
 * address is taken.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_FONT_InitCallerSuppliedArray.c
 *       --func GF_FONT_InitCallerSuppliedArray --addr 0x0201D33C --cc 1.1p1 --thumb
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

u32 GF_FONT_InitCallerSuppliedArray(struct StrObj *s, u32 a, u32 b, u32 *out, u32 max)
{
    u16 *p;
    u32 i;

    p = STRBUF_GetChars((struct U16Vec *)s);
    i = 0;
    while (i < max) {
        if (*p == 0xFFFF) {
            break;
        }
        out[i] = GF_FONT_MeasureTextWidth(p, (void *)a, b, &p);
        i++;
    }
    return i;
}
