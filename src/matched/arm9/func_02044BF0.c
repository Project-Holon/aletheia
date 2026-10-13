/*
 * function: BMP_FillRect4bpp
 * address:  0x02044BF0
 * packet:   pkt_020445F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * bmp.c fill worker, 4bpp tiled (two pixels per byte), reached from the
 * fill dispatcher BMP_FillRect.  Clips right/bottom before the loops and
 * left/top per pixel (signed cmp/cmpge/blt triple), then merges the
 * nibble: odd x takes the high nibble, even x the low one.
 *
 * THE LEVERS (2026-09-22, wave 10), each measured:
 *   - the address is one integer sum over (u32)s->pixels, with only the
 *     tile-row mask lifted into a function-scope local (same lever as
 *     BMP_FillRect8bpp);
 *   - the in-tile row is added to the POINTER afterwards (`p += ...`),
 *     which is what makes the load/store `[p, row]` rather than
 *     `[row, p]` (6 out when it is a fifth term of the sum);
 *   - `hi = value << 4` is assigned INSIDE the guarded body.  LICM then
 *     hoists the shift out of both loops but the `(u8)` narrowing only
 *     one level, so the raw shift is live across the outer loop and is
 *     spilled together with tilesWide: that one extra value is the whole
 *     `sub sp, sp, #8` frame the earlier passes could not reach (208
 *     bytes with hi computed once before the loops);
 *   - the even arm's `(u8)(*p & 0xf0)` is the unfolded `and #0xff`.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Surf { u8 *pixels; u16 width; u16 height; };

void BMP_FillRect4bpp(struct Surf *s, s32 x, s32 y, s32 w, u16 h, u32 value)
{
    s32 i;
    s32 j;
    s32 right = x + w;
    s32 bottom = y + h;
    s32 tilesWide;
    s32 tileY;
    u8 *p;
    u32 hi;

    if (right > s->width)
        right = s->width;
    if (bottom > s->height)
        bottom = s->height;
    tilesWide = (s->width + (s->width & 7)) >> 3;

    for (i = y; i < bottom; i++)
        for (j = x; j < right; j++)
            if (j >= 0 && i >= 0) {
                hi = value << 4;
                tileY = (i * 4) & 0x3fe0;
                p = (u8 *)((u32)s->pixels + ((j >> 1) & 3) + ((j * 4) & 0x3fe0)
                           + tileY * tilesWide);
                p += (i * 4) & 0x1c;
                if (j & 1)
                    *p = (*p & 0x0f) | (u8)hi;
                else
                    *p = (u8)(*p & 0xf0) | value;
            }
}
