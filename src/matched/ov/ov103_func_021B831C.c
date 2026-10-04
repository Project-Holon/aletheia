/*
 * function: func_021B831C
 * address: 0x021B831C
 * packet: pkt_ov103_021B831C
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 */
#include "../include/Obj10244.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;
extern void *func_02045770(struct Descriptor *); extern void func_02043B5C(int,u8); extern void func_02045334(struct Descriptor *);
void func_021B831C(u8 *p) {func_02043B5C((int)func_02045770((struct Descriptor *)((struct Obj10244 *)p)->f0),((struct Obj10244 *)p)->f10);func_02045334((struct Descriptor *)((struct Obj10244 *)p)->f0);}
