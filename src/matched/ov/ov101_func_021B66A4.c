/*
 * function: COMPATIBLE_IRC_SYS_RecvValueAckHandler
 * address: 0x021B66A4
 * packet: pkt_ov101_021B66A4
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 */
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
void COMPATIBLE_IRC_SYS_RecvValueAckHandler(int a,int b,int c,int *d,unsigned e) { if(e==(unsigned)GFL_NET_HANDLE_GetCurrentHandle()) d[28]=1; }
