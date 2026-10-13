/*
 * function: func_021B66B8
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
 *   func_02082D44 0x02082D44 arm
 */
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern unsigned short GFL_NET_SYSTEM_GetCurrentAid(void);
extern void func_02082D44(void *,const void *,unsigned);
void func_021B66B8(unsigned a,int b,void *c,unsigned char *d,unsigned e) { if(e==(unsigned)GFL_NET_HANDLE_GetCurrentHandle()) { if(a!=GFL_NET_SYSTEM_GetCurrentAid()) func_02082D44(c,d+0x3c,4); } }
