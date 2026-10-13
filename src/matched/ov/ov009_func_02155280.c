/*
 * function: GFL_NET_DEVWIFI_SetRecvCallback
 * address:  0x02155280
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Calls DWC_RAP_SetRecvCallbacks on the argument twice and returns 1.
 *
 * symbols:
 *   DWC_RAP_SetRecvCallbacks  0x02155648  thumb  ov009
 */

extern void DWC_RAP_SetRecvCallbacks(int a, int b);

int GFL_NET_DEVWIFI_SetRecvCallback(int a)
{
    DWC_RAP_SetRecvCallbacks(a, a);

    return 1;
}

