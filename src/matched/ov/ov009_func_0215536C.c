/*
 * function: GFL_NET_DEVWIFI_GetDeviceTable
 * address:  0x0215536C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Address of the module state object.
 *
 * symbols:
 *   _wifiDeviceTable  0x021A1B80  data
 */

extern char _wifiDeviceTable[];

void *GFL_NET_DEVWIFI_GetDeviceTable(void)
{
    return _wifiDeviceTable;
}

