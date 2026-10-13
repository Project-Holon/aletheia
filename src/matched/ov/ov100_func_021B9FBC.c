/*
 * function: func_021B9FBC
 * address: 0x021B9FBC
 * packet: pkt_ov100_021B9FBC
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: larger state-store follower 0x021B9FF4 is filed separately.
 * symbols:
 *   func_0203D378 0x0203D378 arm
 *   GFL_NET_IRC_WIRELESS_GetMacAddress 0x0203D0B8 arm
 *   func_021B95B8 0x021B95B8 thumb ov100
 *   func_021B9F80 0x021B9F80 thumb ov100
 */
typedef unsigned int   u32;
extern u32 func_0203D378(void);
extern void GFL_NET_IRC_WIRELESS_GetMacAddress(void *,int);
typedef unsigned char  u8;
extern void func_021B95B8(u8 *p, u32 v);
extern void func_021B9F80(unsigned a);
void func_021B9FBC(int a) {
 if(func_0203D378()!=0) {
  char *p;
  int i=0;
  p=(char *)(a+0x260);
  for(;i<4;i++) GFL_NET_IRC_WIRELESS_GetMacAddress(p+i*6,i);
 }
 func_021B95B8((u8 *)a,(u32)func_021B9F80);
}
