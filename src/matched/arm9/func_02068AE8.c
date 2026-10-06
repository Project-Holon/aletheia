/*
 * function: func_02068AE8
 * address:  0x02068AE8
 * packet:   pkt_02068AE8
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020682F8    0x020682F8  arm
 *
 * Fill a rectangle of a LINEAR tile grid with one pixel value
 * (docs/families/cluster_020682DC.h): expand the pixel to a word, round the
 * rectangle out to whole 8x8 tiles and hand every covered tile to
 * func_020682F8 with its own sub-rectangle, walking the grid with
 * `p += tilesz` per tile and `row += stride * tilesz` per tile row.
 *
 * Levers (docs/notes/pkt_02068808.c.txt has the earlier passes):
 *   - ../2.0/sp2 pin (1.1p1 is 408 bytes on this source);
 *   - the func_02068C84 loop shape: yo as `(cy < y) ? y - cy : 0`, p = row
 *     after it, th through a clamped temporary, loop locals declared
 *     `cx, th, xe, p, yo` at function scope (image r4..r8);
 *   - wave 10: the tile size reads the field again,
 *     `tilesz = (s->bpp << 6) / 8;` (CSE'd into the one `ldrb`).  From the
 *     bpp local, bpp is the spilled value and the tile size takes fp; from
 *     the field, the image's choice (bpp in fp, tile size at [sp,#0x14]);
 *   - wave 10: the two rounded bounds come BEFORE the row pointer:
 *     `xe, ye, row, rowadv` (found by permuting the four statements; the
 *     permuter's reorder(+2) from the old order reached 412/72, and only
 *     xe-ye-first orders are exact).
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Surface {
    char *base;   /* +0x00 */
    int   w;      /* +0x04 */
    int   h;      /* +0x08 */
    u8    bpp;    /* +0x0C */
    int   f10;    /* +0x10 stride in tiles */
};

extern void func_020682F8(u32 *dst, int x, int y, int w, int h, u32 val, int bpp);

void func_02068AE8(struct Surface *s, u32 arg, int x, int y, int w, int h)
{
    int cy;
    int x1;
    int y1;
    int ye;
    char *row;
    int x0;
    int tilesz;
    int rowadv;
    u8 bpp;
    int cx;
    int th;
    int xe;
    char *p;
    int yo;

    bpp = s->bpp;
    x1 = x + w;
    y1 = y + h;
    if (bpp == 4) { u32 t = arg | (arg << 4); t = t | (t << 8); arg = t | (t << 16); }
    else { u32 t = arg | (arg << 8); arg = t | (t << 16); }
    cy = y & ~7;
    tilesz = (s->bpp << 6) / 8;
    x0 = x & ~7;
    xe = (x1 + 7) & ~7;
    ye = (y1 + 7) & ~7;
    row = s->base + tilesz * ((cy / 8) * s->f10 + (x0 / 8));
    rowadv = s->f10 * tilesz;
    if (cy >= ye)
        return;
    do {
        int t;
        yo = (cy < y) ? y - cy : 0;
        p = row;
        t = y1 - cy;
        if (t > 8)
            t = 8;
        th = t - yo;
        for (cx = x0; cx < xe; cx += 8) {
            int xo = (cx < x) ? x - cx : 0;
            int tw = x1 - cx;
            if (tw > 8)
                tw = 8;
            tw -= xo;
            func_020682F8((u32 *)p, xo, yo, tw, th, arg, bpp);
            p = p + tilesz;
        }
        row = row + rowadv;
        cy = cy + 8;
    } while (cy < ye);
}
