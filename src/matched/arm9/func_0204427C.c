/*
 * function: BMP_Blit4bppTo8bpp
 * address:  0x0204427C
 * packet:   pkt_0204427C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * bmp.c blit worker, 4bpp tiled source expanded onto an 8bpp tiled
 * destination with a palette offset: every source nibble is widened to a
 * byte and `pal` is added to it unless it is zero.  With key == 0xFFFF every
 * pixel is stored (a zero nibble stays zero); otherwise zero nibbles are
 * skipped.  Reached only through the forwarder BMP_BlitPaletteOffset, whose narrowing
 * loads fix the u16 key and u8 pal.  Same inlined clip helper and parameter
 * types as BMP_Blit4bpp / BMP_Blit8bpp; source-side masks are the 4bpp ones
 * (0x3fe0 / 0x1c), destination-side the 8bpp ones (0x7fc0 / 0x38).
 *
 * Three levers in the keyed loop, each measured against
 * docs/notes/pkt_02043B98.c.txt's 276-byte best:
 *   - the source pointer is computed BEFORE the destination pointer (as in
 *     BMP_Blit4bpp) and the keyed store is `v += pal; *p = v;` inside the
 *     braces: 888 bytes, 114 out (q-then-p with `*p = v + pal` is 880);
 *   - `xx * 4` bound to a named temporary (`xx4`) in the keyed loop:
 *     4 out (tools/permuter.py anneal, then ablated to this one lever);
 *   - the keyed source pointer is plain pointer arithmetic on src->pixels,
 *     not the `(u32)` sum: that fixes the last `add`/`ldrb` operand order.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_Blit4bppTo8bpp.c \
 *       --func BMP_Blit4bppTo8bpp --addr 0x0204427C --cc 1.1p1 --arm
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

void BMP_Blit4bppTo8bpp(struct Surf *src, struct Surf *dst, s32 x, s32 y, s32 dx, s32 dy,
                   u32 w, u32 h, u16 key, u8 pal)
{
    s32 srow, drow;
    u32 i, j;
    s32 dxx, xx;
    s32 sTileY, dTileY, kTileY, lTileY;
    u32 v;
    u8 *p;
    u8 *q;
    s32 xx4;

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
                dTileY = (dy * 8) & 0x7fc0;
                p = (u8 *)((u32)dst->pixels + (dxx & 7) + ((dxx * 8) & 0x7fc0)
                           + dTileY * drow);
                p += (dy * 8) & 0x38;
                v = (*q >> ((u32)(xx << 31) >> 29)) & 0xf;
                if (v != 0)
                    v += pal;
                *p = v;
            }
    } else {
        for (i = 0; i < h; i++, y++, dy++)
            for (j = 0, dxx = dx, xx = x; j < w; j++, xx++, dxx++) {
                kTileY = (y * 4) & 0x3fe0;
                lTileY = (dy * 8) & 0x7fc0;
                xx4 = xx * 4;
                q = src->pixels + ((xx >> 1) & 3) + (xx4 & 0x3fe0) + kTileY * srow
                    + ((y * 4) & 0x1c);
                p = (u8 *)((u32)dst->pixels + (dxx & 7) + ((dxx * 8) & 0x7fc0)
                           + lTileY * drow);
                p += (dy * 8) & 0x38;
                v = (*q >> ((u32)(xx << 31) >> 29)) & 0xf;
                if (v != 0) {
                    v += pal;
                    *p = v;
                }
            }
    }
}
