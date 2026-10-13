/*
 * unit: yes
 * function: GFL_NET_DEVWIRELESS_GetScanResultMac, GFL_NET_DEVWIRELESS_UnusedSlot12, GFL_NET_DEVWIRELESS_UnusedSlot13, GFL_NET_DEVWIRELESS_HasBeaconBeenSent
 * address: 0x02177114
 * packet: pkt_ov014_02177114
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   NET_WHPIPE_GetEntryBssid 0x02177B58 thumb ov014
 *   WIH_HasBeaconBeenSent 0x02177C08 thumb ov014
 */
typedef unsigned char  u8;
extern u8 *NET_WHPIPE_GetEntryBssid(int i);
void *GFL_NET_DEVWIRELESS_GetScanResultMac(int index) { if (index >= 16) return 0; return NET_WHPIPE_GetEntryBssid(index); }
extern int WIH_HasBeaconBeenSent(void);
int GFL_NET_DEVWIRELESS_UnusedSlot12(void) { return 1; }
int GFL_NET_DEVWIRELESS_UnusedSlot13(void) { return 1; }
int GFL_NET_DEVWIRELESS_HasBeaconBeenSent(void) { return WIH_HasBeaconBeenSent(); }
