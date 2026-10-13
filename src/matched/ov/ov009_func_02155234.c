/*
 * function: GFL_NET_DEVWIFI_StartMatchWithKey
 * address: 0x02155234
 * packet: pkt_ov009_02155234
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
 *   DWC_RAP_StartMatchWithKey 0x0215568C thumb
 */

int GFL_NET_DEVWIFI_StartMatchWithKey(void *a0, int n, int a2, int a3);
int DWC_RAP_StartMatchWithKey(void *a0, int n, int a2, int a3);

int GFL_NET_DEVWIFI_StartMatchWithKey(void *a0, int n, int a2, int a3)
{
    return DWC_RAP_StartMatchWithKey(a0, n, a2, a3);
}
