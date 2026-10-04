/*
 * function: func_021BACC8
 * address: 0x021BACC8
 * packet: pkt_ov100_021BACC8
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA5F4 0x021BA5F4 thumb ov100
 *   func_021BA3A4 0x021BA3A4 thumb ov100
 *   func_021BA290 0x021BA290 thumb ov100
 *   func_021B95B8 0x021B95B8 thumb ov100
 *   func_021BB270 0x021BB270 thumb ov100
 */
#include "../include/Obj10217.h"
struct Word { int x; };
extern void func_021BA5F4(unsigned a);
extern void func_021BA3A4(struct Word *,int);
extern void func_021BA290(int,int);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_021B95B8(u8 *p, u32 v);
extern void func_021BB270(void);
void func_021BACC8(int a) {
 struct Word x;
 func_021BA5F4(a);
 x.x=((struct Obj10217 *)a)->fCB0;
 func_021BA3A4(&x,a);
 if(((struct Obj10217 *)a)->f24C==9 && ((struct Obj10217 *)a)->fCE8>0) {
  func_021BA290(a,1);
  func_021B95B8((u8 *)a,(u32)func_021BB270);
  return;
 }
 func_021BA290(a,0);
 func_021B95B8((u8 *)a,(u32)func_021BB270);
}
