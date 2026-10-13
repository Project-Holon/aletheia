/*
 * function: COMPATIBLE_IRC_SYS_RecvOwnValueHandler
 * address: 0x021B66B8
 * packet: pkt_ov101_021B66B8
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   MI_CpuCopy8 0x02082D44 arm
 */
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern unsigned short GFL_NET_SYSTEM_GetCurrentAid(void);
extern void MI_CpuCopy8(void *,const void *,unsigned);
void COMPATIBLE_IRC_SYS_RecvOwnValueHandler(unsigned a,int b,void *c,unsigned char *d,unsigned e) { if(e==(unsigned)GFL_NET_HANDLE_GetCurrentHandle()) { if(a!=GFL_NET_SYSTEM_GetCurrentAid()) MI_CpuCopy8(c,d+0x3c,4); } }
