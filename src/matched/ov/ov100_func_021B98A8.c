/*
 * unit: yes
 * function: func_021B98A8, func_021B98F0
 * address: 0x021B98A8
 * packet: pkt_ov100_021B98A8
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: 74 compiled bytes include empty stub 021B98F0; padding then separate leaf 021B98F4.
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_02012950 0x02012950 thumb
 *   func_02008494 0x02008494 thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200ED48 0x0200ED48 thumb
 *   func_02008530 0x02008530 thumb
 *   func_0200ED54 0x0200ED54 thumb
 */
struct Entry;
extern struct Entry *func_020399A8(void);
extern int func_02012950(int,int);
extern void func_02008494(int,int);
extern int func_02012EBC(int);
extern int func_0200ED48(int);
extern unsigned func_02008530(int);
extern void func_0200ED54(int,unsigned);
void func_021B98A8(int a,int b,int c,int d,int e)
{
 int p;
 int q;
 if(e==(int)func_020399A8()) {
  p=func_02012950(**(int **)(d+0x244),a);
  func_02008494(c,p);
  q=func_0200ED48(func_02012EBC(**(int **)(d+0x244)));
 func_0200ED54(q,func_02008530(p));
 }
}
void func_021B98F0(void) {}
