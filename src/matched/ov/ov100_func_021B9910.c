/*
 * function: func_021B9910
 * address: 0x021B9910
 * packet: pkt_ov100_021B9910
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_02039338 0x02039338 arm
 *   func_02012950 0x02012950 thumb
 *   func_0200F5EC 0x0200F5EC thumb
 */
typedef unsigned short u16;
extern int func_020399A8(void);
extern u16 func_02039338(void);
extern int func_02012950(int,int);
extern int func_0200F5EC(int,int,int,u16);
void func_021B9910(int a,int b,int c,int d,int e)
{
 int p = *(int *)(d+0x244);
 int q = *(int *)p;
 if (e == func_020399A8()) {
  if (a != func_02039338()) {
   int r = func_02012950(q,a);
   *(int *)(d+0xc90) = func_0200F5EC(q,r,c,*(u16 *)(d+0x278));
  }
 }
}
