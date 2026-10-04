/*
 * function: func_021C91CC
 * address: 0x021C91CC
 * packet: pkt_ov128_021C91CC
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C6B38 0x021C6B38 thumb ov128
 *   func_02041300 0x02041300 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020456F8 0x020456F8 arm
 *   func_02045730 0x02045730 arm
 */
#include "../include/Obj10490.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Descriptor;
extern void func_021C6B38(u8 *p);
extern void func_02041300(u32,int,int,int,u8,u8,u8);
extern void func_02041B6C(u32 bit);
extern void func_020456F8(struct Descriptor *d);
extern u8 func_02045730(struct Descriptor *p);
void func_021C91CC(char *p,void *q) {
 void *v;
 func_021C6B38(q);
 func_02041300(2,0,0,0,32,24,0);func_02041B6C(2);
 v=((struct Obj10490 *)p)->f0;func_020456F8(v);func_02041B6C(func_02045730(v));
 v=((struct Obj10490 *)p)->f8;func_020456F8(v);func_02041B6C(func_02045730(v));
 func_02041300(3,0,0,0,32,24,0);func_02041B6C(3);
}
