/*
 * function: NNSi_G2dSurfaceFillRectSwizzled
 * address:  0x02068C84
 * packet:   pkt_02068AE8
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNSi_G2dCalcRectMask    0x020681E4  arm
 *   NNSi_G2dCharCanvasFill    0x020682F8  arm
 *
 * Fill a rectangle of a SWIZZLED tile grid with one pixel value
 * (docs/families/cluster_020682DC.h): expand the pixel to a word, round the
 * rectangle out to whole 8x8 tiles, ask NNSi_G2dCalcRectMask for each tile's index
 * (tx, ty, w, h and the two swizzle bytes of the +0x10 word) and hand every
 * covered tile to NNSi_G2dCharCanvasFill with its own sub-rectangle.
 *
 * Levers, in the order they were found (docs/notes/pkt_02068808.c.txt):
 *   - ../2.0/sp2 pin (1.1p1 is 492 bytes);
 *   - yo as `(cy < y) ? y - cy : 0`, tx = tx0 after it, th through a
 *     clamped temporary; loop registers declared `cx, th, tx, xe, ty`;
 *   - THE LAST 8 BYTES (wave 10): the tile size is computed from a fresh
 *     read of the field, `tilesz = (s->bpp << 6) / 8;`, not from the bpp
 *     local.  The two loads CSE to the one `ldrb`, but the tile size then
 *     becomes its own value in the IR and the image's `stm sp, {r5, fp}` is
 *     scheduled before `sub r3, r2, r1` (tw - xo).  The same lever closes
 *     NNSi_G2dSurfaceFillRect, where it decides whether bpp or the tile size is the
 *     spilled value.  (Declaring NNSi_G2dCharCanvasFill's bpp parameter u8 in this
 *     caller also closes C84 alone, but the callee's own definition,
 *     src/matched/NNSi_G2dCharCanvasFill.c, is EXACT only with `int bpp`, so the
 *     re-read is the reading kept.)  The permuter (hill 800 + anneal 2000,
 *     --types) never moved this residue.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Swz { u32 x : 8; u32 y : 8; u32 rest : 16; };

struct Surface {
    char *base;   /* +0x00 */
    int   w;      /* +0x04 */
    int   h;      /* +0x08 */
    u8    bpp;    /* +0x0C */
    struct Swz f10; /* +0x10 */
};

extern int NNSi_G2dCalcRectMask(int tx, int ty, int w, int h, int sx, int sy);
extern void NNSi_G2dCharCanvasFill(u32 *dst, int x, int y, int w, int h, u32 val, int bpp);

void NNSi_G2dSurfaceFillRectSwizzled(struct Surface *s, u32 arg, int x, int y, int w, int h)
{
    struct Swz f10;
    int cy;
    int x1;
    int y1;
    int ye;
    char *base;
    int tx0;
    int x0;
    int sy;
    int sx;
    int sh;
    int sw;
    int tilesz;
    u8 bpp;
    int cx;
    int th;
    int tx;
    int xe;
    int ty;

    bpp = s->bpp;
    x1 = x + w;
    y1 = y + h;
    if (bpp == 4) { u32 t = arg | (arg << 4); t = t | (t << 8); arg = t | (t << 16); }
    else { u32 t = arg | (arg << 8); arg = t | (t << 16); }
    x0 = x & ~7;
    cy = y & ~7;
    ye = (y1 + 7) & ~7;
    tilesz = (s->bpp << 6) / 8;
    tx0 = x0 / 8;
    f10 = s->f10;
    ty = cy / 8;
    xe = (x1 + 7) & ~7;
    sw = s->w;
    sh = s->h;
    base = s->base;
    sx = f10.x;
    sy = f10.y;
    if (cy >= ye)
        return;
    do {
        int yo, t;
        yo = (cy < y) ? y - cy : 0;
        tx = tx0;
        t = y1 - cy;
        if (t > 8)
            t = 8;
        th = t - yo;
        for (cx = x0; cx < xe; cx += 8) {
            int off = NNSi_G2dCalcRectMask(tx, ty, sw, sh, sx, sy);
            int xo = (cx < x) ? x - cx : 0;
            int tw = x1 - cx;
            if (tw > 8)
                tw = 8;
            tw -= xo;
            NNSi_G2dCharCanvasFill((u32 *)(base + tilesz * off), xo, yo, tw, th, arg, bpp);
            tx = tx + 1;
        }
        ty = ty + 1;
        cy = cy + 8;
    } while (cy < ye);
}
