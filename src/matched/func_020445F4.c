/*
 * function: func_020445F4
 * address:  0x020445F4
 * packet:   pkt_020445F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * bmp.c blit worker, 4bpp tiled source onto a 4bpp tiled destination that
 * is written a HALFWORD at a time (func_02044D88's read-modify-write
 * store), with an optional colour key (0xFFFF = none).  Reached from the
 * blit dispatcher func_020439A0's kind == 2 arm, whose shift pairs give
 * the narrow parameter types (x, y, w, h u16; dx, dy s16); the key is
 * loaded with ldrh here, so it is u16 on this side.  The plain and keyed
 * loops are written out in full, each with its OWN pair of tile-row
 * locals (sharing one pair across both loops costs ~150 bytes of
 * allocation).
 *
 * The clip against the destination goes through a fresh temporary t.
 * Reusing xend/yend for the difference makes the compiler emit the
 * conditional add with the reused variable as the first operand
 * (add fp, r5, r2) where the image has add fp, r2, r5; that was the
 * last 4 bytes.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

struct Surf { u8 *pixels; u16 width; u16 height; };

void func_020445F4(struct Surf *src, struct Surf *dst, u16 x, u16 y, s16 dx, s16 dy, u16 w, u16 h, u16 key)
{
    s32 xend, yend, srow, drow;
    s32 i, j, di, dj;
    s32 sTileY, dTileY, kTileY, lTileY;
    u32 s, d;
    s32 odd;
    u32 c;
    u16 hi, lo;
    s32 t, u;
    u32 v, sh;
    t = dst->width - dx;
    if (t < w)
        xend = x + t;
    else
        xend = w + x;
    t = dst->height - dy;
    if (t < h)
        yend = y + t;
    else
        yend = h + y;
    srow = (src->width + (src->width & 7)) >> 3;
    drow = (dst->width + (dst->width & 7)) >> 3;
    if (key == 0xffff) {
        for (i = y, di = dy; i < yend; i++, di++)
            for (j = x, dj = dx; j < xend; j++, dj++)
                if (dj >= 0 && di >= 0) {
                    sTileY = (i * 4) & 0x3fe0;
                    s = (u32)src->pixels + ((j >> 1) & 3) + ((j * 4) & 0x3fe0) + sTileY * srow;
                    s += (i * 4) & 0x1c;
                    dTileY = (di * 4) & 0x3fe0;
                    d = (u32)dst->pixels + ((dj >> 1) & 3) + ((dj * 4) & 0x3fe0) + dTileY * drow;
                    d += (di * 4) & 0x1c;
                    if (d & 1) {
                        d -= 1;
                        odd = 1;
                    } else
                        odd = 0;
                    c = *(u16 *)d;
                    hi = c >> 8;
                    lo = c & 0xff;
                    v = (*(u8 *)s >> ((u32)(j << 31) >> 29)) & 0xf;
                    sh = (u32)(dj << 31) >> 29;
                    if (odd == 0)
                        *(u16 *)d = (((0xf0 >> sh) & lo) | (v << sh)) | (hi << 8);
                    else
                        *(u16 *)d = (((hi & (0xf0 >> sh)) | (v << sh)) << 8) | lo;
                }
    } else {
        for (i = y, di = dy; i < yend; i++, di++)
            for (j = x, dj = dx; j < xend; j++, dj++)
                if (dj >= 0 && di >= 0) {
                    kTileY = (i * 4) & 0x3fe0;
                    s = (u32)src->pixels + ((j >> 1) & 3) + ((j * 4) & 0x3fe0) + kTileY * srow;
                    s += (i * 4) & 0x1c;
                    lTileY = (di * 4) & 0x3fe0;
                    d = (u32)dst->pixels + ((dj >> 1) & 3) + ((dj * 4) & 0x3fe0) + lTileY * drow;
                    d += (di * 4) & 0x1c;
                    if (d & 1) {
                        d -= 1;
                        odd = 1;
                    } else
                        odd = 0;
                    c = *(u16 *)d;
                    hi = c >> 8;
                    lo = c & 0xff;
                    v = (*(u8 *)s >> ((u32)(j << 31) >> 29)) & 0xf;
                    if (v != key) {
                        sh = (u32)(dj << 31) >> 29;
                        if (odd == 0)
                            *(u16 *)d = (((0xf0 >> sh) & lo) | (v << sh)) | (hi << 8);
                        else
                            *(u16 *)d = (((hi & (0xf0 >> sh)) | (v << sh)) << 8) | lo;
                    }
                }
    }
}
