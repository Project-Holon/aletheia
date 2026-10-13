/*
 * function: BMP_Blit8bpp
 * address:  0x02043F4C
 * packet:   pkt_02043B98
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * bmp.c blit worker, 8bpp tiled source onto an 8bpp tiled destination,
 * byte stores, optional colour key (0xFFFF = none).  Reached from the blit
 * dispatcher BMP_Blit's first arm (kind != 2), which passes all nine
 * arguments wide; the key is ldrh'd off the stack here, so it is u16 on
 * this side.
 *
 * The prologue is an inlined clip helper returning a flag (the image's
 * mov r4,#0 / mov r4,#1 / cmp r4,#0).  Width and height are clamped to the
 * source, the destination origin is rejected when fully outside, and a
 * negative origin is folded into the width/height and the source origin.
 * All the comparisons against the clipped extents are unsigned
 * (movhi/subhi) and those against the destination origin signed (bge/bgt),
 * which is what fixes the u32 extents and the s32 origins.
 *
 * Levers, each measured (compiled bytes out):
 *   - dst is `const struct Surf *` in the helper: that is what makes the
 *     compiler re-read dst->width after the clip (812 bytes without);
 *   - the helper reads *h BEFORE *w into its locals (88 out; 701 the
 *     other way);
 *   - the keyed loop reads the source through a pointer q and tests *q
 *     (14 out; a u8 temporary gives 65 and a different schedule);
 *   - the inner loop headers: dxx before xx in the initialisers, and the
 *     keyed loop steps xx before dxx (a three-register rotation, 12 -> 4
 *     -> 0);
 *   - the address arithmetic is the family's single integer sum over
 *     (u32)pixels (BMP_FillRect8bpp) with one tile-row local per address.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Surf { u8 *pixels; u16 width; u16 height; };

static inline s32 ClipRect(struct Surf *src, const struct Surf *dst, s32 *x, s32 *y,
                           s32 *dx, s32 *dy, u32 *w, u32 *h)
{
    u32 ch = *h;
    u32 cw = *w;
    if (cw > src->width)
        cw = src->width;
    if (*dx >= dst->width || *dx <= -(s32)cw)
        return 0;
    if (ch > src->height)
        ch = src->height;
    if (*dy >= dst->height || *dy <= -(s32)ch)
        return 0;
    if (*dx < 0) {
        cw += *dx;
        *x -= *dx;
        *dx = 0;
    } else if (*dx + cw > dst->width) {
        cw -= *dx + cw - dst->width;
    }
    if (*dy < 0) {
        ch += *dy;
        *y -= *dy;
        *dy = 0;
    } else if (*dy + ch > dst->height) {
        ch -= *dy + ch - dst->height;
    }
    *w = cw;
    *h = ch;
    return 1;
}

void BMP_Blit8bpp(struct Surf *src, struct Surf *dst, s32 x, s32 y, s32 dx, s32 dy,
                   u32 w, u32 h, u16 key)
{
    s32 srow, drow;
    u32 i, j;
    s32 dxx, xx;
    s32 sTileY, dTileY, kTileY, lTileY;
    u8 c;
    u8 *p;
    u8 *q;

    if (!ClipRect(src, dst, &x, &y, &dx, &dy, &w, &h))
        return;
    srow = (src->width + (src->width & 7)) >> 3;
    drow = (dst->width + (dst->width & 7)) >> 3;
    if (key == 0xffff) {
        for (i = 0; i < h; i++, y++, dy++)
            for (j = 0, dxx = dx, xx = x; j < w; j++, dxx++, xx++) {
                sTileY = (y * 8) & 0x7fc0;
                c = *(u8 *)((u32)src->pixels + (xx & 7) + ((xx * 8) & 0x7fc0)
                            + sTileY * srow + ((y * 8) & 0x38));
                dTileY = (dy * 8) & 0x7fc0;
                *(u8 *)((u32)dst->pixels + (dxx & 7) + ((dxx * 8) & 0x7fc0)
                        + dTileY * drow + ((dy * 8) & 0x38)) = c;
            }
    } else {
        for (i = 0; i < h; i++, y++, dy++)
            for (j = 0, dxx = dx, xx = x; j < w; j++, xx++, dxx++) {
                kTileY = (y * 8) & 0x7fc0;
                q = (u8 *)((u32)src->pixels + (xx & 7) + ((xx * 8) & 0x7fc0)
                           + kTileY * srow + ((y * 8) & 0x38));
                lTileY = (dy * 8) & 0x7fc0;
                p = (u8 *)((u32)dst->pixels + (dxx & 7) + ((dxx * 8) & 0x7fc0)
                           + lTileY * drow);
                p += (dy * 8) & 0x38;
                if (*q != key)
                    *p = *q;
            }
    }
}
