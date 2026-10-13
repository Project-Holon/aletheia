/*
 * function: GFL_NET_DEVWIFI_IsConnected
 * address:  0x02155294
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * False when the word call returns -1.
 *
 * symbols:
 *   DWC_RAP_GetMyAidIfConnected  0x021562EC  thumb  ov009
 */

extern int DWC_RAP_GetMyAidIfConnected(void);

int GFL_NET_DEVWIFI_IsConnected(void)
{
    if (DWC_RAP_GetMyAidIfConnected() != -1) {
        return 1;
    }

    return 0;
}

