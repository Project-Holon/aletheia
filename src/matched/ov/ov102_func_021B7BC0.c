/*
 * function: func_021B7BC0
 * address: 0x021B7BC0
 * packet: pkt_ov102_021B7BC0
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 * func_0204B3B4 0x0204B3B4 arm
 * func_0204ADA4 0x0204ADA4 arm
 * func_0204A8D4 0x0204A8D4 arm
 * func_0204AFD8 0x0204AFD8 arm
 * func_0204B1CC 0x0204B1CC arm
 * func_0204A5AC 0x0204A5AC arm
 * func_02082BCC 0x02082BCC arm
 */
#include "../include/Obj07973.h"
struct Bank;
struct Obj;
extern void func_0204B3B4(struct Obj *p);
extern void func_0204ADA4(unsigned);
extern void func_0204A8D4(unsigned);
extern void func_0204AFD8(unsigned);
typedef unsigned int   u32;
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_02082BCC(void *,int,unsigned);
void func_021B7BC0(void *p) {
 int i;
 for(i=0;i<32;i++) {
  if(*(void **)((char *)p+16+i*4)) func_0204B3B4(*(void **)((char *)p+16+i*4));
 }
 func_0204ADA4(((struct Obj07973 *)p)->f4);
 func_0204A8D4(((struct Obj07973 *)p)->f8);
 func_0204AFD8(((struct Obj07973 *)p)->fC);
 func_0204B1CC(((struct Obj07973 *)p)->f0);
 func_0204A5AC();
 func_02082BCC(p,0,0x90);
}
