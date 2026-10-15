/*
 * function: APP_ICON_GetStatusPaletteFileId
 * address:  0x02027620
 * packet:   pkt_020274B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/APP_ICON_GetStatusPaletteFileId.c \\
 *       --func APP_ICON_GetStatusPaletteFileId --addr 0x02027620 --thumb --cc 1.1p1
 */

typedef unsigned int u32;

u32 APP_ICON_GetStatusPaletteFileId(u32 a)
{
    return a + 0x18;
}
