/*
 * function: func_021BB10C
 * address: 0x021BB10C
 * packet: pkt_ov100_021BB10C
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B898 0x0204B898 arm
 *   func_0204B878 0x0204B878 arm
 *   func_021B9800 0x021B9800 thumb ov100
 *   func_021B974C 0x021B974C thumb ov100
 */
typedef unsigned short u16;
struct Obj;
extern u16 func_0204B898(struct Obj *p);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_021B9800(int a, int b, int c, int d);
extern void func_021B974C(int,int,int,int,int);
void func_021BB10C(int a) {
 switch(func_0204B898(*(void **)(a+0x2d0))) {
 case 9:
  func_0204B878(*(void **)(a+0x2d0),10);
  func_021B9800(a,57,154,2);
  func_021B974C(a,128,77,5,3);
  return;
 case 10: break;
 default: func_0204B878(*(void **)(a+0x2d0),9); break;
 }
}
