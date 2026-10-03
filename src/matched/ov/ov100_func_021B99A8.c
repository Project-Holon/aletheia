/*
 * function: func_021B99A8
 * address: 0x021B99A8
 * packet: pkt_ov100_021B99A8
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_02039338 0x02039338 arm
 *   func_02082D44 0x02082D44 arm
 */
extern void *func_020399A8(void);
extern int func_02039338(void);
extern void func_02082D44(const void *,void *,unsigned);
void func_021B99A8(int a,int b,void *c,unsigned d,void *e)
{
 if(e==func_020399A8()) {
  if(a!=func_02039338()) func_02082D44(c,(void *)(*(unsigned *)(d+0x244)+0x18),4);
 }
}
