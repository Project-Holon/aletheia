/*
 * function: GFL_NET_DEVWIFI_SendMessage
 * address: 0x02155264
 * packet: pkt_ov009_02155264
 * region: ov009
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DWC_RAP_SendMessage 0x02155B14 thumb ov009
 */
extern int DWC_RAP_SendMessage(int, int);
int GFL_NET_DEVWIFI_SendMessage(int a, int b, int c, void (*cb)(int))
{
    if (DWC_RAP_SendMessage(a, b)) {
        if (cb) cb(1);
        return 1;
    }
    return 0;
}
