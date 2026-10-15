/*
 * function: BG_SYS_BlitPixels
 * address:  0x020428E8
 * packet:   pkt_020428E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_GetModeValue  0x020422D4  arm
 *   BG_SYS_GetTileMapEntry  0x02040EE0  arm
 *   BG_SYS_DrawTileRegion  0x02040F84  arm
 *
 * Tile-to-tile copier: copies a cw x ch block of a source tilemap
 * (row stride sw, height sh, origin sx/sy) into the screen's tilemap at
 * dx/dy, clipped to the screen size BG_SYS_GetModeValue reports.  mode 0 reads
 * the source linearly, any other mode through BG_SYS_DrawTileRegion's index.
 *
 * Closed in wave 11.  Three declarations carry it: ch, sw and sh are u8
 * stack parameters even though the image loads each with a full `ldr`
 * (a u8 stack argument still occupies and is read as a word; the narrow
 * type is what moves the prologue's parameter homes, as with
 * BG_SYS_BlitTileMap's seventh parameter), BG_SYS_DrawTileRegion is called with u8
 * w/h, and the two out-bytes are declared `u8 w, h;` so w lands at
 * sp+0x29 and h at sp+0x28.  The callers (BG_SYS_DrawTileEx, BG_SYS_DrawTileSub)
 * already declare the fifth parameter (ch) as u8.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Screen {
    u8 *entries;
    u8  pad_04[0x11];
    u8  size_code;
};

extern void BG_SYS_GetModeValue(u32 mode, u8 *a, u8 *b);
extern u16  BG_SYS_GetTileMapEntry(u8 x, u8 y, u8 size_code);
extern u16  BG_SYS_DrawTileRegion(u8 x, u8 y, u8 w, u8 h);

void BG_SYS_BlitPixels(struct Screen *s, u8 dx, u8 dy, u8 cw, u8 ch,
                   const u8 *src, u8 sx, u8 sy, u8 sw, u8 sh, u8 mode)
{
    u8 *dst;
    u8 w, h;
    u8 x, y;

    dst = s->entries;
    if (dst == 0)
        return;

    BG_SYS_GetModeValue(s->size_code, &w, &h);

    if (mode == 0) {
        for (y = 0; y < ch; y++) {
            if (dy + y >= h || sy + y >= sh)
                return;
            for (x = 0; x < cw; x++) {
                if (dx + x >= w || sx + x >= sw)
                    break;
                dst[BG_SYS_GetTileMapEntry(dx + x, dy + y, s->size_code)] =
                    src[sw * (sy + y) + sx + x];
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
