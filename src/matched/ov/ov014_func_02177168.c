/*
 * unit: yes
 * function: GFL_NET_DEVWIRELESS_IsDataSharing, GFL_NET_DEVWIRELESS_StepDataSharing, GFL_NET_DEVWIRELESS_GetSharedData, GFL_NET_DEVWIRELESS_SendData
 * address: 0x02177168
 * packet: pkt_ov014_02177168
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * interface: 02177190 forwards r1 unchanged to 02177C30; that leaf
 * performs the u16 truncation itself. Its matched signature uses full width.
 * symbols:
 *   WIH_GetSysState 0x02178E4C thumb ov014
 *   func_021793B8 0x021793B8 thumb ov014
 *   func_02179394 0x02179394 thumb ov014
 *   NET_WHPIPE_SendData 0x02177C30 thumb ov014
 */
extern int WIH_GetSysState(void);
int GFL_NET_DEVWIRELESS_IsDataSharing(void) { if (WIH_GetSysState() == 5) return 1; return 0; }
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021793B8(int);
extern int func_02179394(u16);
extern int NET_WHPIPE_SendData(int,u32,int);
int GFL_NET_DEVWIRELESS_StepDataSharing(int a) { return func_021793B8(a); }
int GFL_NET_DEVWIRELESS_GetSharedData(u32 a) { return func_02179394((u16)a); }
int GFL_NET_DEVWIRELESS_SendData(int a,u32 b,int c,int d) { return NET_WHPIPE_SendData(a,b,d); }
