/*
 * unit: no
 * function: func_021BA2B8
 * address: 0x021BA2B8
 * packet: pkt_ov214_021BA2B8
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj01082.h"
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
struct Descriptor;struct Cfg;struct PrintSys;extern void *func_02045770(struct Descriptor *);extern u32 func_0201C6C4(struct PrintSys *,void *);extern void func_02045334(struct Descriptor *);extern void func_02045374(struct Cfg *);extern u8 func_02045730(struct Descriptor *);extern void func_02041B6C(u32);
u32 func_021BA2B8(int unused,u8 *p){struct Descriptor *d;if(((struct Obj01082 *)p)->f7C==0){if(func_0201C6C4(*(struct PrintSys * *)&((struct Obj01082 *)p)->fC,func_02045770(*(struct Descriptor * *)&((struct Obj01082 *)p)->f6C))==0){d=*(struct Descriptor * *)&((struct Obj01082 *)p)->f6C;func_02045334(d);func_02045374((struct Cfg *)d);func_02041B6C(func_02045730(d));((struct Obj01082 *)p)->f7C=1;}}return ((struct Obj01082 *)p)->f7C;}
