/*
 * function: APP_ICON_GetTypePaletteFileId
 * address:  0x020275FC
 * packet:   pkt_020274B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/APP_ICON_GetTypePaletteFileId.c \\
 *       --func APP_ICON_GetTypePaletteFileId --addr 0x020275FC --thumb --cc 1.1p1
 */

typedef unsigned int u32;

u32 APP_ICON_GetTypePaletteFileId(u32 a)
{
    return a + 0x3b;
}
