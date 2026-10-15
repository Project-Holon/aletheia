/*
 * function: APP_ICON_GetStatusCellFileId
 * address:  0x0202761C
 * packet:   pkt_020274B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/APP_ICON_GetStatusCellFileId.c \\
 *       --func APP_ICON_GetStatusCellFileId --addr 0x0202761C --thumb --cc 1.1p1
 */

typedef unsigned int u32;

u32 APP_ICON_GetStatusCellFileId(u32 a)
{
    return a + 0x15;
}
