/*
 * function: BG_SYS_BlitTiles
 * address:  0x020426A0
 * packet:   pkt_020426A0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020422D4  0x020422D4  arm
 *   BG_SYS_GetTileMapEntry  0x02040EE0  arm
 *   BG_SYS_DrawTileRegion  0x02040F84  arm
 *
 * The u16 tile-to-tile copier, sibling of BG_SYS_BlitPixels (u8 cells) and
 * BG_SYS_BlitTilesEx (linear destination).  mode 0 clips each row and cell
 * with u8-wrapped coordinates and skips; any other mode clips with int
 * sums, stops at the first miss and indexes the source through
 * BG_SYS_DrawTileRegion.  Written in wave 11 straight from the two siblings'
 * settled declarations (u8 ch/sw/sh stack parameters, u8 w/h for
 * BG_SYS_DrawTileRegion, `u8 w, h;` and `u8 y, x;`); EXACT at the first compile.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Screen {
    u16 *entries;
    u8   pad_04[0x11];
    u8   size_code;
};

extern void func_020422D4(u32 mode, u8 *a, u8 *b);
extern u16  BG_SYS_GetTileMapEntry(u8 x, u8 y, u8 size_code);
extern u16  BG_SYS_DrawTileRegion(u8 x, u8 y, u8 w, u8 h);

void BG_SYS_BlitTiles(struct Screen *s, u8 dx, u8 dy, u8 cw, u8 ch,
                   const u16 *src, u8 sx, u8 sy, u8 sw, u8 sh, u8 mode)
{
    u16 *dst;
    u8 w, h;
    u8 y, x;

    dst = s->entries;
    if (dst == 0)
        return;

    func_020422D4(s->size_code, &w, &h);

    if (mode == 0) {
        for (y = 0; y < ch; y++) {
            if ((u8)(dy + y) < h && (u8)(sy + y) < sh) {
                for (x = 0; x < cw; x++) {
                    if ((u8)(dx + x) < w && (u8)(sx + x) < sw)
                        dst[BG_SYS_GetTileMapEntry(dx + x, dy + y, s->size_code)] =
                            src[sx + x + sw * (sy + y)];
                }
            }
        }
    } else {
        for (y = 0; y < ch; y++) {
            if (dy + y >= h || sy + y >= sh)
                return;
            for (x = 0; x < cw; x++) {
                if (dx + x >= w || sx + x >= sw)
                    break;
                dst[BG_SYS_GetTileMapEntry(dx + x, dy + y, s->size_code)] =
                    src[BG_SYS_DrawTileRegion(sx + x, sy + y, sw, sh)];
            }
        }
    }
}
