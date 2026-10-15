/*
 * function: APP_ICON_GetArchiveId
 * address:  0x020275E4
 * packet:   pkt_020274B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns the constant 0x53.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/APP_ICON_GetArchiveId.c \
 *       --func APP_ICON_GetArchiveId --addr 0x020275E4 --thumb --cc 1.1p1
 */

typedef unsigned int u32;

u32 APP_ICON_GetArchiveId(void)
{
    return 0x53;
}