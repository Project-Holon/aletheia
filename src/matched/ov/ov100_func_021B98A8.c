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
typedef unsigned int   u32;
struct Big;
struct L0200ED54;
struct Rec44;
struct Sub0200852CObj;
struct Sub24;
extern struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
extern void func_02008494(void *src, void *dst);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200ED48(void *p);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void func_0200ED54(struct L0200ED54 *l, u32 val);
void func_021B98A8(int a,int b,int c,int d,int e)
{
 int p;
 int q;
 if(e==(int)func_020399A8()) {
  p=(int)func_02012950((struct Sub24 *)(**(int **)(d+0x244)),a);
  func_02008494((void *)c,(void *)p);
  q=(int)func_0200ED48(func_02012EBC((struct Big *)(**(int **)(d+0x244))));
 func_0200ED54((struct L0200ED54 *)q,func_02008530((const struct Sub0200852CObj *)p));
 }
}
void func_021B98F0(void) {}
