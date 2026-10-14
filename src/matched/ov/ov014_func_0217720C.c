/*
 * function: NET_WHPIPE_QueryConnectBitmap
 * address: 0x0217720C
 * packet: pkt_ov014_0217720C
 * region: ov014
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov014/unit_021771F8.c and filed here.
 *
 * symbols:
 *   NET_WHPIPE_GetConnectBitmap 0x02177C3C thumb ov014
 */

extern unsigned int NET_WHPIPE_GetConnectBitmap(void);
unsigned int NET_WHPIPE_QueryConnectBitmap(void);

unsigned int NET_WHPIPE_QueryConnectBitmap(void)
{
    return NET_WHPIPE_GetConnectBitmap();
}
