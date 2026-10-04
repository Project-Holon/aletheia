/*
 * function: func_021FC830
 * address: 0x021FC830
 * packet: pkt_ov186_021FC830
 * region: ov186
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
#include "../include/Obj05502.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;
struct PrintSys;
extern void *func_02045770(struct Descriptor *p);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *d);
int func_021FC830(u8*p){void*owner=*(void* *)&((struct Obj05502 *)p)->f8;if(p[4]){if(!func_0201C6C4(owner,func_02045770(*(void* *)&((struct Obj05502 *)p)->f0))){func_02045334(*(void* *)&((struct Obj05502 *)p)->f0);p[4]=0;}}if(!p[4])return 1;return 0;}
