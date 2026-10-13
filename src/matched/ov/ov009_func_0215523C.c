/*
 * function: GFL_NET_DEVWIFI_StartFriendMatch
 * address: 0x0215523C
 * packet: pkt_ov009_0215523C
 * region: ov009
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov009/dwc_rap_p01.c and filed here.
 *
 * symbols:
 *   DWC_RAP_StartFriendMatch 0x02156888 thumb ov009
 */

int DWC_RAP_StartFriendMatch(int a, int b, int c);
int GFL_NET_DEVWIFI_StartFriendMatch(int a, int b, int c);

int GFL_NET_DEVWIFI_StartFriendMatch(int a, int b, int c)
{
    return DWC_RAP_StartFriendMatch(a, b, c);
}
