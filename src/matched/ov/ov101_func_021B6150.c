/*
 * function: func_021B6150
 * address: 0x021B6150
 * packet: pkt_ov101_021B6150
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * witness: callback 0x021B6670 is covered by S5 unit pkt_ov101_021B6634.
 * lever: struct pointer prevents the integer base from hoisting the state address across switch dispatch.
 * symbols:
 *   func_0203CD98 0x0203CD98 arm
 *   func_0203CBAC 0x0203CBAC arm
 *   func_021B6670 0x021B6670 thumb ov101
 *   func_021B66E0 0x021B66E0 thumb ov101
 *   d_021B743C 0x021B743C data a4
 */
typedef unsigned short u16;
struct Config { int words[26]; int context; int tail; };
struct Obj { int first; int data[15]; int context; unsigned state; int rest[11]; int ready; int done; int spare[3]; u16 heap; };
extern const struct Config d_021B743C;
extern int func_0203CD98(void);
extern void func_0203CBAC(struct Config *,void (*)(void),int);
extern void func_021B6670(void);
extern void func_021B66E0(int,int,int);
int func_021B6150(struct Obj *p) {
 struct Config config;
 if(p->done!=0) return 1;
 switch(p->state) {
 case 0:
  if(func_0203CD98()!=0) { p->state=2; }
  else {
   config=d_021B743C;
   config.context=p->context;
   func_0203CBAC(&config,func_021B6670,(int)p);
  }
  p->state=1;
  break;
 case 1:
  if(func_0203CD98()!=0) p->state=2;
  break;
 case 2:
  func_021B66E0((int)p+4,(int)p,p->heap);
  p->ready=1;
  p->state=3;
  break;
 case 3:
  p->state=0;
  return 1;
 }
 return 0;
}
