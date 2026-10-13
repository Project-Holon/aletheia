/*
 * unit: yes
 * function: GFL_NET_DEVWIRELESS_StartChild, GFL_NET_DEVWIRELESS_UnusedSlot19, GFL_NET_DEVWIRELESS_RequestShutdown
 * address: 0x02177150
 * packet: pkt_ov014_02177150
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   NET_WHPIPE_StartChild 0x02177E20 thumb ov014
 *   NET_WHPIPE_RequestFinalize 0x021776C4 thumb ov014
 */
typedef unsigned int u32;
typedef unsigned char u8;
extern int NET_WHPIPE_StartChild(u32,u8 *,u32,u32);
int GFL_NET_DEVWIRELESS_StartChild(u32 a,u8 *b,u32 c,u32 d,u32 e) { return NET_WHPIPE_StartChild(a,b,c,e); }
extern int NET_WHPIPE_RequestFinalize(void);
int GFL_NET_DEVWIRELESS_UnusedSlot19(void) { return 0; }
int GFL_NET_DEVWIRELESS_RequestShutdown(void) { return NET_WHPIPE_RequestFinalize(); }
