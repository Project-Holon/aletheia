/*
 * function: func_021B9C50
 * address: 0x021B9C50
 * packet: pkt_ov100_021B9C50
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: switch cases preserve three equality compares; disjunction folds to a range test.
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_02087C6C 0x02087C6C arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_021B95B8 0x021B95B8 thumb ov100
 *   func_021B96B8 0x021B96B8 thumb ov100
 *   func_021B9BE4 0x021B9BE4 thumb ov100
 */
typedef unsigned short u16;
typedef unsigned char u8;
extern void *func_020399A8(void);
extern int func_02039CB4(void *,int,int);
extern void func_02087C6C(void *);
extern int func_0203D3A8(void *a, u16 b, u16 c, void *d);
extern int func_02039C68(void *,int,int);
extern void func_021B95B8(int,void (*)(void));
extern void func_021B96B8(void);
extern void func_021B9BE4(void);
void func_021B9C50(int a)
{
 u8 x[6];
 int k=12;
 if(func_02039CB4(func_020399A8(),0x79,k)!=0) {
  int t=*(int *)(a+0x24c);
  switch(t) {
  case 9: case 10: case 11:
   func_021B95B8(a,func_021B96B8);
   return;
  default: break;
  }
  func_02087C6C(x);
  if(func_0203D3A8(func_020399A8(),0xc04,6,x)!=0) {
   func_02039C68(func_020399A8(),0x7d,k);
   func_021B95B8(a,func_021B9BE4);
  }
 }
}
