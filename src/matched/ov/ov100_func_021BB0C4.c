/*
 * function: func_021BB0C4
 * address: 0x021BB0C4
 * packet: pkt_ov100_021BB0C4
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   func_0204B878 0x0204B878 arm
 *   func_021B9800 0x021B9800 thumb ov100
 *   func_021B974C 0x021B974C thumb ov100
 */
#include "../include/Obj10219.h"
typedef unsigned short u16;
struct Obj;
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_021B9800(int a, int b, int c, int d);
extern void func_021B974C(int,int,int,int,int);
void func_021BB0C4(int a) {
 switch(CLACT_GetActorAnimSeq(((struct Obj10219 *)a)->f2C8)) {
 case 8:
  func_0204B878(((struct Obj10219 *)a)->f2C8,11);
  func_021B9800(a,200,38,0);
  func_021B974C(a,128,113,4,2);
  return;
 case 11: break;
 default: func_0204B878(((struct Obj10219 *)a)->f2C8,8); break;
 }
}
