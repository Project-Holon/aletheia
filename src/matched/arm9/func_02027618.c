/*
 * function: APP_ICON_GetMoveKindAnimFileId
 * address:  0x02027618
 * packet:   pkt_020274B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/APP_ICON_GetMoveKindAnimFileId.c \\
 *       --func APP_ICON_GetMoveKindAnimFileId --addr 0x02027618 --thumb --cc 1.1p1
 */

typedef unsigned int u32;

u32 APP_ICON_GetMoveKindAnimFileId(void)
{
    return 0x14;
}
