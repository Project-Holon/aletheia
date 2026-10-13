/*
 * function: BMP_FillRect8bppVram
 * address:  0x02044EBC
 * packet:   pkt_020445F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * bmp.c fill worker (8bpp tiled, one byte per pixel), reached from the
 * fill dispatcher BMP_FillRect.  Clips right/bottom against the
 * descriptor before the loops and left/top per pixel (the signed
 * cmp/cmpge/blt triple), then stores the fill byte at the 8x8-tiled
 * address.  0x02044CE0 and 0x02044EBC are byte-identical twins.
 *
 * THE LEVER (2026-09-22, wave 10): the address is ONE integer expression
 * over the pixel pointer cast to u32, evaluated inside the guarded body,
 * with only the tile-row mask lifted into a function-scope local.  The
 * compiler hoists that local and the product out of the inner loop into
 * the preheader AFTER the entry test (the image's placement) but does not
 * fold the tile row and the in-tile row into one mla, which it does for
 * every pointer-arithmetic or subscript spelling.  Pointer arithmetic
 * (u8 *) with the same terms stays at 17 out; the per-row locals of the
 * older best source at 81.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Surf { u8 *pixels; u16 width; u16 height; };

void BMP_FillRect8bppVram(struct Surf *s, s32 x, s32 y, s32 w, u16 h, u8 value)
{
    s32 i;
    s32 j;
    s32 right = x + w;
    s32 bottom = y + h;
    s32 tilesWide;
    s32 tileY;

    if (right > s->width)
        right = s->width;
    if (bottom > s->height)
        bottom = s->height;
    tilesWide = (s->width + (s->width & 7)) >> 3;

    for (i = y; i < bottom; i++)
        for (j = x; j < right; j++)
            if (j >= 0 && i >= 0) {
                tileY = (i * 8) & 0x7fc0;
                *(u8 *)((u32)s->pixels + (j & 7) + ((j * 8) & 0x7fc0)
                        + tileY * tilesWide + ((i * 8) & 0x38)) = value;
            }
}
