/*
 * unit: yes
 * function: GFL_NET_DEVWIRELESS_SetConnectCallback, GFL_NET_DEVWIRELESS_StartParent, GFL_NET_DEVWIRELESS_StartChildScan
 * address: 0x02177134
 * packet: pkt_ov014_02177134
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIH_SetConnectCallback 0x02179628 thumb ov014
 *   NET_WHPIPE_StartParent 0x02177D0C thumb ov014
 *   func_021775BC 0x021775BC thumb ov014
 */
extern void WIH_SetConnectCallback(unsigned v);
int GFL_NET_DEVWIRELESS_SetConnectCallback(int a) { WIH_SetConnectCallback(a); return 1; }
extern int NET_WHPIPE_StartParent(int);
extern int func_021775BC(int);
int GFL_NET_DEVWIRELESS_StartParent(int a) { return NET_WHPIPE_StartParent(a); }
int GFL_NET_DEVWIRELESS_StartChildScan(int a) { return func_021775BC(a); }
