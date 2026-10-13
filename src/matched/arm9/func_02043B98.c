/*
 * function: BMP_Blit4bpp
 * address:  0x02043B98
 * packet:   pkt_02043B98
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * bmp.c blit worker, 4bpp tiled source onto a 4bpp tiled destination,
 * byte read-modify-write of one nibble, optional colour key (0xFFFF =
 * none).  The 4bpp sibling of BMP_Blit8bpp (same dispatcher arm, same
 * inlined clip helper, same parameter types) and the byte-store sibling
 * of BMP_Blit4bppToVram.
 *
 * Levers on top of BMP_Blit8bpp's, each measured:
 *   - the store is written `(v << sh) | (*p & (0xf0 >> sh))`: the other
 *     operand order lets the compiler hoist the *p load above the source
 *     read, which costs a spill slot (984 bytes against 948);
 *   - both loops read the source through a pointer q computed BEFORE the
 *     destination pointer, with the source tile-row local assigned first:
 *     the preheader then computes the source row and product first, as the
 *     image does (100 out otherwise).
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

void BMP_Blit4bpp(struct Surf *src, struct Surf *dst, s32 x, s32 y, s32 dx, s32 dy,
                   u32 w, u32 h, u16 key)
{
    s32 srow, drow;
    u32 i, j;
    s32 dxx, xx;
    s32 sTileY, dTileY, kTileY, lTileY;
    u32 v, sh;
    u8 *p;
    u8 *q;

    if (!ClipRect(src, dst, &x, &y, &dx, &dy, &w, &h))
        return;
    srow = (src->width + (src->width & 7)) >> 3;
    drow = (dst->width + (dst->width & 7)) >> 3;
    if (key == 0xffff) {
        for (i = 0; i < h; i++, y++, dy++)
            for (j = 0, dxx = dx, xx = x; j < w; j++, dxx++, xx++) {
                sTileY = (y * 4) & 0x3fe0;
                q = (u8 *)((u32)src->pixels + ((xx >> 1) & 3) + ((xx * 4) & 0x3fe0)
                           + sTileY * srow + ((y * 4) & 0x1c));
                dTileY = (dy * 4) & 0x3fe0;
                p = (u8 *)((u32)dst->pixels + ((dxx >> 1) & 3) + ((dxx * 4) & 0x3fe0)
                           + dTileY * drow);
                p += (dy * 4) & 0x1c;
                sh = (u32)(dxx << 31) >> 29;
                v = (*q >> ((u32)(xx << 31) >> 29)) & 0xf;
                *p = (v << sh) | (*p & (0xf0 >> sh));
            }
    } else {
        for (i = 0; i < h; i++, y++, dy++)
            for (j = 0, dxx = dx, xx = x; j < w; j++, xx++, dxx++) {
                kTileY = (y * 4) & 0x3fe0;
                q = (u8 *)((u32)src->pixels + ((xx >> 1) & 3) + ((xx * 4) & 0x3fe0)
                           + kTileY * srow + ((y * 4) & 0x1c));
                lTileY = (dy * 4) & 0x3fe0;
                p = (u8 *)((u32)dst->pixels + ((dxx >> 1) & 3) + ((dxx * 4) & 0x3fe0)
                           + lTileY * drow);
                p += (dy * 4) & 0x1c;
                v = (*q >> ((u32)(xx << 31) >> 29)) & 0xf;
                if (v != key) {
                    sh = (u32)(dxx << 31) >> 29;
                    *p = (v << sh) | (*p & (0xf0 >> sh));
                }
            }
    }
}
