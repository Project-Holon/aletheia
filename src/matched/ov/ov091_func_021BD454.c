/*
 * function: func_021BD454
 * address: 0x021BD454
 * packet: pkt_ov091_021BD454
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020452E8 0x020452E8 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj06214.h"
struct Descriptor;
struct Obj;
extern unsigned int func_020452E8(struct Descriptor *d);
extern void func_0204B3B4(struct Obj *);
extern void func_0204A8D4(unsigned int);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void func_021BD454(char *unused,char *p) { func_020452E8(*(struct Descriptor * *)&((struct Obj06214 *)p)->f4); func_020452E8(*(struct Descriptor * *)&((struct Obj06214 *)p)->f8); func_0204B3B4(*(struct Obj * *)&((struct Obj06214 *)p)->f14); func_0204B3B4(*(struct Obj * *)&((struct Obj06214 *)p)->f10); func_0204A8D4(((struct Obj06214 *)p)->fC); func_020307B0(p); }
