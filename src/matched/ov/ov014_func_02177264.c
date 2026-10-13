/*
 * function: GFL_NET_DEVWIRELESS_SetAcceptChild
 * address: 0x02177264
 * packet: pkt_ov014_02177264
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
 *   NET_WHPIPE_SetAcceptChild 0x02177EDC thumb ov014
 */

extern void NET_WHPIPE_SetAcceptChild(int a);
void GFL_NET_DEVWIRELESS_SetAcceptChild(int a);

void GFL_NET_DEVWIRELESS_SetAcceptChild(int a)
{
    NET_WHPIPE_SetAcceptChild(a);
}
