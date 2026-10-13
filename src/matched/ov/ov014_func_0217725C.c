/*
 * function: GFL_NET_DEVWIRELESS_SetWatchDisconnect
 * address: 0x0217725C
 * packet: pkt_ov014_0217725C
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
 *   NET_WHPIPE_SetWatchDisconnect 0x02177B0C thumb
 */

typedef unsigned char  u8;
void GFL_NET_DEVWIRELESS_SetWatchDisconnect(unsigned char v);
void NET_WHPIPE_SetWatchDisconnect(u8 v);

void GFL_NET_DEVWIRELESS_SetWatchDisconnect(unsigned char v)
{
    NET_WHPIPE_SetWatchDisconnect(v);
}
