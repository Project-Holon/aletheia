/*
 * function: func_021B71B0
 * address: 0x021B71B0
 * packet: pkt_ov091_021B71B0
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204B1CC 0x0204B1CC arm
 */
#include "../include/Obj01888.h"
struct Bank;
struct Obj;
extern void func_0204B3B4(struct Obj *p);
extern void func_0204B1CC(struct Bank *bank);
void func_021B71B0(unsigned p) { func_0204B3B4(((struct Obj01888 *)p)->f1E0); func_0204B3B4(((struct Obj01888 *)p)->f1E4); func_0204B3B4(((struct Obj01888 *)p)->f1D8); func_0204B3B4(((struct Obj01888 *)p)->f1DC); func_0204B1CC(((struct Obj01888 *)p)->f1D4); }
