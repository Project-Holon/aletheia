/*
 * function: APP_ICON_GetStatusDataFileId
 * address:  0x0202762C
 * packet:   pkt_020274B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/APP_ICON_GetStatusDataFileId.c \\
 *       --func APP_ICON_GetStatusDataFileId --addr 0x0202762C --thumb --cc 1.1p1
 */

typedef unsigned int u32;

u32 APP_ICON_GetStatusDataFileId(void)
{
    return 0x1d;
}
