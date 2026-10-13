/*
 * function: GFL_NET_DEVWIRELESS_StartJoinLock
 * address: 0x02177274
 * packet: pkt_ov014_02177274
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
 *   NET_WHPIPE_StartJoinLock 0x021780E4 thumb ov014
 */

extern void NET_WHPIPE_StartJoinLock(int a);
void GFL_NET_DEVWIRELESS_StartJoinLock(int a);

void GFL_NET_DEVWIRELESS_StartJoinLock(int a)
{
    NET_WHPIPE_StartJoinLock(a);
}
