/*
 * function: func_021B9FBC
 * address: 0x021B9FBC
 * packet: pkt_ov100_021B9FBC
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: larger state-store follower 0x021B9FF4 is filed separately.
 * symbols:
 *   func_0203D378 0x0203D378 arm
 *   func_0203D0B8 0x0203D0B8 arm
 *   func_021B95B8 0x021B95B8 thumb ov100
 *   func_021B9F80 0x021B9F80 thumb ov100
 */
extern int func_0203D378(void);
extern void func_0203D0B8(void *,int);
extern void func_021B95B8(int,void (*)(void));
extern void func_021B9F80(void);
void func_021B9FBC(int a) {
 if(func_0203D378()!=0) {
  char *p;
  int i=0;
  p=(char *)(a+0x260);
  for(;i<4;i++) func_0203D0B8(p+i*6,i);
 }
 func_021B95B8(a,func_021B9F80);
}
