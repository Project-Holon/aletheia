/*
 * unit: yes
 * function: func_021DCAB4, func_021DCAE8
 * address: 0x021DCAB4
 * packet: pkt_ov137_021DCAB4
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_021DC950 0x021DC950 thumb ov137
 *   func_02031348 0x02031348 arm
 *   d_0000005B 0x0000005B data a1
 *   d_021BED00 0x021BED00 data ov091 a4
 */
#include "../include/Obj08209.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_020307B0(void *);
extern void *func_021DC950(void *,int,int);
extern void func_02031348(void *,int,const void *,void *);
extern const u8 d_0000005B[],d_021BED00[];
int func_021DCAB4(u8 *p) {u8 a;void *v;a=(*(u8 **)(p+28))[15];func_020307B0(((struct Obj08209 *)p)->f1C);v=func_021DC950(p,21,a);((struct Obj08209 *)p)->f18=v;func_02031348(((struct Obj08209 *)p)->f20,(int)d_0000005B,d_021BED00,v);((struct Obj08209 *)p)->f0=2;return 0;}
int func_021DCAE8(u32 *p) {*p=5;return 0;}
