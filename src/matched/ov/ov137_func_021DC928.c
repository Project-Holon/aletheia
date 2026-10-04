/*
 * function: func_021DC928
 * address: 0x021DC928
 * packet: pkt_ov137_021DC928
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DC8D0 0x021DC8D0 thumb ov137
 *   func_02031348 0x02031348 arm
 *   d_021E1A38 0x021E1A38 data a4
 */
#include "../include/Obj08208.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_021DC8D0(void *,int);
extern void func_02031348(void *,int,const void *,void *);
extern const u8 d_021E1A38[];
int func_021DC928(u8 *p) {void *v;v=func_021DC8D0(((struct Obj08208 *)p)->f8,4);((struct Obj08208 *)p)->f0=1;((struct Obj08208 *)p)->fC=v;func_02031348(((struct Obj08208 *)p)->f20,-1,d_021E1A38,v);return 0;}
