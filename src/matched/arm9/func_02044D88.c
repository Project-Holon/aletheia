/*
 * function: BMP_FillRect4bppVram
 * address:  0x02044D88
 * packet:   pkt_020445F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * bmp.c fill worker, 4bpp tiled plotted through a HALFWORD read-modify-
 * write (the pixel's byte is halfword-aligned downward, merged, and the
 * pair stored back with strh).  Reached from func_02043AF4.
 *
 * Levers (2026-09-22, wave 10), each measured:
 *   - the address is the family's single integer sum over (u32)s->pixels
 *     with the tile-row mask in a function-scope local and the in-tile row
 *     added afterwards (BMP_FillRect4bpp);
 *   - hi/lo are u16 locals of a u32 halfword read: `hi = c >> 8` becomes
 *     the image's lsl #8 / lsr #16, and `lo = c & 0xff` its and / lsl #16
 *     with the lsr #16 folded into every use;
 *   - odd is set inside the `if (a & 1)`, which lets tst/subne and the
 *     movne/moveq pair share one flag setting;
 *   - the even arm is written first (`odd == 0`), the fall-through order;
 *   - right is computed and clamped BEFORE bottom is computed: bottom lives
 *     in its spill slot from its first store, and initialising both up
 *     front adds a reload (312 bytes).
 */
#include "../include/Obj08850.h"
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Surf { u8 *pixels; u16 width; u16 height; };

void BMP_FillRect4bppVram(struct Surf *s, s32 x, s32 y, s32 w, u16 h, u8 value)
{
    s32 i;
    s32 j;
    s32 right;
    s32 bottom;
    s32 tilesWide;
    s32 tileY;
    u32 a;
    s32 odd;
    u32 c;
    u16 hi, lo;
    u32 sh;

    right = x + w;
    if (right > s->width)
        right = s->width;
    bottom = y + h;
    if (bottom > s->height)
        bottom = s->height;
    tilesWide = (s->width + (s->width & 7)) >> 3;

    for (i = y; i < bottom; i++)
        for (j = x; j < right; j++)
            if (j >= 0 && i >= 0) {
                tileY = (i * 4) & 0x3fe0;
                a = (u32)s->pixels + ((j >> 1) & 3) + ((j * 4) & 0x3fe0)
                    + tileY * tilesWide;
                a += (i * 4) & 0x1c;
                if (a & 1) {
                    a -= 1;
                    odd = 1;
                } else
                    odd = 0;
                c = ((struct Obj08850 *)a)->f0;
                hi = c >> 8;
                lo = c & 0xff;
                sh = (u32)(j << 31) >> 29;
                if (odd == 0)
                    ((struct Obj08850 *)a)->f0 = (((0xf0 >> sh) & lo) | (value << sh)) | (hi << 8);
                else
                    ((struct Obj08850 *)a)->f0 = (((hi & (0xf0 >> sh)) | (value << sh)) << 8) | lo;
            }
}
