/*
 * function: func_021B7EE4
 * address: 0x021B7EE4
 * packet: pkt_ov104_021B7EE4
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes follow compiled code.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 */
#include "../include/Obj06372.h"
#include "../include/Obj22224.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;
struct PrintSys;
extern void *func_02045770(struct Descriptor *p);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *);
int func_021B7EE4(u8 *p,u8 *q) { void *v; v=((struct Obj22224 *)q)->f8; if(p[8]) { if(!func_0201C6C4(v,func_02045770(((struct Obj06372 *)p)->f4))) { func_02045334(*(struct Descriptor * *)&((struct Obj06372 *)p)->f4); p[8]=0; } } if(!p[8]) return 1; return 0; }
