/*
 * function: func_02205100
 * address: 0x02205100
 * packet: pkt_ov195_02205100
 * region: ov195
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 */
#include "../include/Obj04593.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern void func_0204B3B4(struct Obj *p);
extern void func_0204AFD8(u32);
extern void func_0204A8D4(u32);
extern void func_0204ADA4(u32);
void func_02205100(void *unused,char *p) {u8 i;if(((struct Obj04593 *)p)->f60){for(i=0;i<6;i++)func_0204B3B4((struct Obj *)(*(u32 *)(p+0x48+i*4)));func_0204AFD8(((struct Obj04593 *)p)->f44);func_0204A8D4(((struct Obj04593 *)p)->f3C);func_0204ADA4(((struct Obj04593 *)p)->f40);((struct Obj04593 *)p)->f60=0;}}
