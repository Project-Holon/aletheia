/*
 * unit: yes
 * function: GFL_NET_DEVWIRELESS_ClearScanList, GFL_NET_DEVWIRELESS_UnusedSlot7, GFL_NET_DEVWIRELESS_UnusedSlot8, GFL_NET_DEVWIRELESS_UnusedSlot9
 * address: 0x021770EC
 * packet: pkt_ov014_021770EC
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   NET_WHPIPE_ClearEntries 0x02177560 thumb ov014
 */
extern void NET_WHPIPE_ClearEntries(void);
int GFL_NET_DEVWIRELESS_ClearScanList(void) { NET_WHPIPE_ClearEntries(); return 1; }
int GFL_NET_DEVWIRELESS_UnusedSlot7(void) { return 1; }
int GFL_NET_DEVWIRELESS_UnusedSlot8(void) { return 1; }
int GFL_NET_DEVWIRELESS_UnusedSlot9(void) { return 1; }
