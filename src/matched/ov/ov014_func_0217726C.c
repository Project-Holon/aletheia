/*
 * function: GFL_NET_DEVWIRELESS_StartAutoSearch
 * address: 0x0217726C
 * packet: pkt_ov014_0217726C
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov014/net_whpipe.c and filed here.
 *
 * symbols:
 *   NET_WHPIPE_StartAutoSearch 0x02178034 thumb ov014
 */

extern int NET_WHPIPE_StartAutoSearch(void);
int GFL_NET_DEVWIRELESS_StartAutoSearch(void);

int GFL_NET_DEVWIRELESS_StartAutoSearch(void)
{
    return NET_WHPIPE_StartAutoSearch();
}
