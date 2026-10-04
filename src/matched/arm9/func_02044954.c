/*
 * function: func_02044954
 * address:  0x02044954
 * packet:   pkt_020445F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * bmp.c blit worker, 8bpp tiled source onto an 8bpp tiled destination
 * written a HALFWORD at a time: when the destination byte is odd the
 * store covers it and the byte before, both taken from the source pair
 * ending at the source pixel; otherwise the source pair starting at it.
 * Optional colour key (0xFFFF = none), compared against the source byte.
 * Reached from func_020439A0's kind == 2 arm (x, y, w, h u16; dx, dy s16;
 * the key is ldrh'd, so u16 here).
 *
 * The same four levers as func_020445F4, all measured:
 *   - the address is one integer sum over (u32)pixels with the in-tile
 *     row added afterwards;
 *   - each of the four tile-row masks has its own function-scope local
 *     (shared locals: 149 out; none: 31);
 *   - in the odd arm d is decremented BEFORE the two loads, which keeps
 *     the shared first load in each arm (326 out otherwise);
 *   - the clip goes through a fresh temporary t with u16 x/y; reusing
 *     xend/yend flips the operands of the conditional add (4 out), and
 *     a fresh t with s32 x/y reshuffles the allocation (167 out).
 */
#include "../include/Obj03010.h"
#include "../include/Obj11412.h"
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

struct Surf { u8 *pixels; u16 width; u16 height; };

void func_02044954(struct Surf *src, struct Surf *dst, u16 x, u16 y, s16 dx, s16 dy, u16 w, u16 h, u16 key)
{
    s32 xend, yend, srow, drow;
    s32 i, j, di, dj;
    s32 sTileY, dTileY, kTileY, lTileY;
    u32 s, d;
    u16 c;
    s32 t;
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
                    sTileY = (i * 8) & 0x7fc0;
                    s = (u32)src->pixels + (j & 7) + ((j * 8) & 0x7fc0) + sTileY * srow;
                    s += (i * 8) & 0x38;
                    dTileY = (di * 8) & 0x7fc0;
                    d = (u32)dst->pixels + (dj & 7) + ((dj * 8) & 0x7fc0) + dTileY * drow;
                    d += (di * 8) & 0x38;
                    if (d & 1) {
                        d -= 1;
                        c = (((u8 *)s)[0] << 8) | ((u8 *)s)[-1];
                    } else {
                        c = ((u8 *)s)[0] | (((u8 *)s)[1] << 8);
                    }
                    ((struct Obj11412 *)d)->f0 = c;
                }
    } else {
        for (i = y, di = dy; i < yend; i++, di++)
            for (j = x, dj = dx; j < xend; j++, dj++)
                if (dj >= 0 && di >= 0) {
                    kTileY = (i * 8) & 0x7fc0;
                    s = (u32)src->pixels + (j & 7) + ((j * 8) & 0x7fc0) + kTileY * srow;
                    s += (i * 8) & 0x38;
                    lTileY = (di * 8) & 0x7fc0;
                    d = (u32)dst->pixels + (dj & 7) + ((dj * 8) & 0x7fc0) + lTileY * drow;
                    d += (di * 8) & 0x38;
                    if (d & 1) {
                        d -= 1;
                        c = (((u8 *)s)[0] << 8) | ((u8 *)s)[-1];
                    } else {
                        c = ((u8 *)s)[0] | (((u8 *)s)[1] << 8);
                    }
                    if (((struct Obj03010 *)s)->f0 != key)
                        ((struct Obj11412 *)d)->f0 = c;
                }
    }
}
