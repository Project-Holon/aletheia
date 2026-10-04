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
struct Entry;
extern struct Entry *func_020399A8(void);
extern u16 func_02039338(void);
typedef unsigned int   u32;
struct Rec44;
struct Sub24;
extern struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
extern int func_0200F5EC(void *a0, void *a1, void *a2, void *a3);
void func_021B9910(int a,int b,int c,int d,int e)
{
 int p = *(int *)(d+0x244);
 int q = *(int *)p;
 if (e == (int)func_020399A8()) {
  if (a != func_02039338()) {
   int r = (int)func_02012950((struct Sub24 *)q,a);
   *(int *)(d+0xc90) = func_0200F5EC((void *)q,(void *)r,(void *)c,(void *)(*(u16 *)(d+0x278)));
  }
 }
}
