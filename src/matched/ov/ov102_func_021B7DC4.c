/*
 * function: func_021B7DC4
 * address: 0x021B7DC4
 * packet: pkt_ov102_021B7DC4
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 */
#include "../include/Obj06365.h"
#include "../include/Obj22147.h"
struct Descriptor;
extern void *func_02045770(struct Descriptor *); extern int func_0201C6C4(int,int); extern void func_02045334(struct Descriptor *);
int func_021B7DC4(unsigned char *p,unsigned char *q) { int a=((struct Obj22147 *)q)->f8; if (p[8]) { if (!func_0201C6C4(a,(int)func_02045770((struct Descriptor *)((struct Obj06365 *)p)->f4))) { func_02045334((struct Descriptor *)((struct Obj06365 *)p)->f4); p[8]=0; } } if (!p[8]) return 1; return 0; }
