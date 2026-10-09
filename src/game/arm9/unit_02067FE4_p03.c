/*
 * file:     unit_02067FE4_p03.c
 * unit:     yes
 * function: func_02068AE8, func_02068C84, func_02068E78, func_02068EA0, func_02068FC4
 * address:  0x02068AE8
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020682F8    0x020682F8  arm
 *   func_020681E4    0x020681E4  arm
 *   func_02067F9C    0x02067F9C  arm
 *   func_02067FE4    0x02067FE4  arm
 */
struct Obj;
struct NNSG2dCharWidths;
struct NNSG2dFont;
struct Pen;
typedef unsigned char u8;

typedef unsigned int  u32;

struct Surface_02068AE8 {
    char *base;   /* +0x00 */
    int   w;      /* +0x04 */
    int   h;      /* +0x08 */
    u8    bpp;    /* +0x0C */
    int   f10;    /* +0x10 stride in tiles */
};

struct Swz { u32 x : 8; u32 y : 8; u32 rest : 16; };

struct Surface_02068C84 {
    char *base;   /* +0x00 */
    int   w;      /* +0x04 */
    int   h;      /* +0x08 */
    u8    bpp;    /* +0x0C */
    struct Swz f10; /* +0x10 */
};

struct Pen {
    int  f00;
    int  f04;
    int  f08;
    u8   f0c;
    u8   pad0d[3];
    int  f10;
    int  f14;
};

typedef signed char s8;

typedef unsigned short u16;

struct Hdr { u16 f0; u16 stride; u8 pad[3]; u8 kind; };

struct Fnt { struct Hdr *hdr; };

struct Fnt2 { u16 f0; u16 dflt; u8 p[4]; struct Hdr *hdr; };

struct Ctx { u8 pad[0x14]; void **vt; };

extern void func_020682F8(u32 *dst, int x, int y, int w, int h, u32 val, int bpp);
extern int func_020681E4(int tx, int ty, int w, int h, int sx, int sy);
extern u32 func_02067F9C(struct Obj **a0, u32 key);
extern const struct NNSG2dCharWidths *func_02067FE4(const struct NNSG2dFont *pFont, u32 idx);
void func_02068AE8(struct Surface_02068AE8 *s, u32 arg, int x, int y, int w, int h);
void func_02068C84(struct Surface_02068C84 *s, u32 arg, int x, int y, int w, int h);
void func_02068E78(struct Pen *p, int a1, int a2, int a3, int a5, int a6, int a7);
s8 func_02068EA0(struct Ctx *ctx, struct Fnt2 **font, int x, int y, int a6, u16 code);
void func_02068FC4(int a, int b, int c, int d, int e);




/*
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
void func_02068AE8(struct Surface_02068AE8 *s, u32 arg, int x, int y, int w, int h)
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



/*
 * Fill a rectangle of a SWIZZLED tile grid with one pixel value
 * (docs/families/cluster_020682DC.h): expand the pixel to a word, round the
 * rectangle out to whole 8x8 tiles, ask func_020681E4 for each tile's index
 * (tx, ty, w, h and the two swizzle bytes of the +0x10 word) and hand every
 * covered tile to func_020682F8 with its own sub-rectangle.
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
 *     func_02068AE8, where it decides whether bpp or the tile size is the
 *     spilled value.  (Declaring func_020682F8's bpp parameter u8 in this
 *     caller also closes C84 alone, but the callee's own definition,
 *     src/matched/func_020682F8.c, is EXACT only with `int bpp`, so the
 *     re-read is the reading kept.)  The permuter (hill 800 + anneal 2000,
 *     --types) never moved this residue.
 */
void func_02068C84(struct Surface_02068C84 *s, u32 arg, int x, int y, int w, int h)
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
            int off = func_020681E4(tx, ty, sw, sh, sx, sy);
            int xo = (cx < x) ? x - cx : 0;
            int tw = x1 - cx;
            if (tw > 8)
                tw = 8;
            tw -= xo;
            func_020682F8((u32 *)(base + tilesz * off), xo, yo, tw, th, arg, bpp);
            tx = tx + 1;
        }
        ty = ty + 1;
        cy = cy + 8;
    } while (cy < ye);
}




/*
 * The text-context initialiser: seven arguments straight into six fields of a
 * 0x18-byte pen/draw context, with no computation at all.  A leaf, and the
 * image proves it -- it never pushes and returns with a bare `bx lr`.
 *
 * TWO THINGS THE BYTES FORCED:
 *
 *   1. THE STORE ORDER IS THE SOURCE ORDER, and it is deliberately not the
 *      field order: +0x04, +0x08, +0x0c, +0x00, +0x14, +0x10.  Writing the
 *      fields in ascending order instead lets the front end fuse the first two
 *      into `stm r0, {r1, r2}` (which is what 1.1p1 does even with the source
 *      order, see the pin below), and the function changes shape.  This
 *      compiler never reorders independent stores to the same object, so the
 *      image's order IS the original statement order -- the same reading rule
 *      as docs/idioms/the-fall-through-arm-is-the-source-order.md applied to
 *      straight-line code.
 *
 *   2. +0x0c IS A BYTE.  `strb r2, [r0, #0xc]` with the value arriving as a
 *      full stack word, so the parameter is an `int` and the field is `u8`;
 *      the narrowing is at the store, not at the call.
 *
 * THE ARITY AND THE ARGUMENT ORDER are not guessed: the caller
 * src/matched/func_02068FC4.c (already EXACT) spells the call as
 *
 *     func_02068E78((char *)a, b, c, d, e, 0x020A18DC, c);
 *
 * which fixes seven arguments, three in registers and four on the stack at
 * [sp+0], [sp+4], [sp+8], and shows the last argument repeating the third.
 * The other caller, func_02068FF0 at 0x02069064, agrees.
 *
 * THE `../2.0/sp2` PIN.  dsi/1.1p1 cannot produce a leaf here at all: it
 * spends `r4` and `lr` on the three stack arguments and therefore opens
 * `push {r4, lr}` and returns through `pop {r4, pc}`, which also shifts every
 * stack-argument displacement by 8 and lets it fuse `str r1, [r0]` with
 * `str r2, [r0, #4]` into one `stm`.  Nine of the ten instructions differ.
 * ../2.0/sp2 and ../1.2/sp2 both reproduce the image byte for byte with the
 * same C.  ../2.0/sp2 is recorded because the adjacent matched member of this
 * cluster, src/matched/func_02068EA0.c, is independently pinned to it (on the
 * "kept constants" re-read tell) and because the other function filed into
 * this cluster in the same pass, src/matched/func_02068FF0.c, is 2.0 and NOT
 * 1.2.  Since two front ends agree on this row it is not usable as evidence
 * for either pin on its own, and it is deliberately not offered as one in
 * docs/FRONTEND-PINS.md -- but the symptom is worth naming: A LEAF THAT GROWS
 * A PROLOGUE is a front-end question, not a spelling one.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02068E78.c \
 *       --func func_02068E78 --addr 0x02068E78 --arm --cc ../2.0/sp2
 *   -> EXACT, compiled 40 = original 40, 0 relocation sites
 */
void func_02068E78(struct Pen *p, int a1, int a2, int a3, int a5, int a6, int a7)
{
    p->f04 = a2;
    p->f08 = a3;
    p->f0c = (u8)a5;
    p->f00 = a1;
    p->f14 = a6;
    p->f10 = a7;
}



/*
 * Per-file compiler pin, the re-read/forward form of the "kept constants"
 * family (docs/FRONTEND-PINS.md, the func_02070BD8 row). The image RE-READS
 * the font's header chain a second time before the switch dispatch,
 * `ldr r1, [r7]` at 0x02068F00 (`00 10 97 e5`) then `ldr r3, [r1, #8]` at
 * 0x02068F04 (`08 30 91 e5`), although the same chain was already loaded at
 * 0x02068EE8/0x02068EEC for the stride computation two instructions earlier.
 * dsi/1.1p1 -O4,p forwards the register it still has live and collapses the
 * pair to a single `ldr r3, [r3, #8]`, giving 284 bytes against the original's
 * 292 with everything from the dispatch onward shifted by four. A volatile
 * qualifier on the outer load, struct-typed field chains, binding the header
 * to a local before or after out[1], and a fresh `(*font)->hdr` chain spelled
 * out in every switch arm all CSE identically at 284. Under the pin the same C
 * is 292 bytes, 0 mismatches.
 *
 * Draw one glyph: look the character up in the font's range table, fall back
 * to the font's default glyph when the lookup returns its 0xFFFF "not found"
 * sentinel (the pool word at 0x02068FC0), then adjust the pen position by the
 * glyph's own bearings according to the header's layout kind before handing
 * both the glyph record and the metrics record to the context's draw hook.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02068EA0.c \
 *       --func func_02068EA0 --addr 0x02068EA0 --cc ../2.0/sp2 --arm
 */
s8 func_02068EA0(struct Ctx *ctx, struct Fnt2 **font, int x, int y, int a6, u16 code)
{
    s8 *out[2];
    u32 idx;
    s8 *g;
    u8 k;

    idx = func_02067F9C((struct Obj **)font, code);
    if (idx == 0xffff)
        idx = (*font)->dflt;
    out[0] = (s8 *)func_02067FE4((const struct NNSG2dFont *)font, idx);
    out[1] = (s8 *)((char *)(*font)->hdr + 8 + idx * (*font)->hdr->stride);
    g = out[0];
    k = (*font)->hdr->kind;

    switch (k) {
    case 0:
    case 7:
        x += g[0];
        break;
    case 1:
    case 2:
        x -= ((u8 *)(*font)->hdr)[0];
        y += g[0];
        break;
    case 3:
    case 4:
        x -= g[0] + (u8)g[1];
        y -= ((u8 *)(*font)->hdr)[1];
        break;
    case 5:
    case 6:
        y -= g[0] + ((u8 *)(*font)->hdr)[1];
        break;
    }
    ((void (*)(struct Ctx *, void *, int, int, int, s8 **))ctx->vt[0])(ctx, font, x, y, a6, out);
    return out[0][2];
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02068FC4.c \
 *       --func func_02068FC4 --addr 0x02068FC4 --cc 1.1p1 --arm
 */
void func_02068FC4(int a, int b, int c, int d, int e)
{
    func_02068E78((struct Pen *)a, b, c, d, e, 0x020A18DC, c);
}
