/*
 * function: func_021F3E78
 * address: 0x021F3E78
 * packet: pkt_ov194_021F3E78
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 */
#include "../include/Obj05513.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct PrintSys;
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
struct Descriptor;
extern void func_02045334(struct Descriptor *d);
int func_021F3E78(u8 *p) {int window;window=((struct Obj05513 *)p)->f10;if(p[12]) {if(func_0201C6C4((struct PrintSys *)window,(void *)((int)func_02045770((struct Descriptor *)*(int *)&((struct Obj05513 *)p)->f8)))==0) {func_02045334(((struct Obj05513 *)p)->f8);p[12]=0;}}if(!p[12]) return 1;return 0;}
