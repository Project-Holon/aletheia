/*
 * function: func_021BB290
 * address: 0x021BB290
 * packet: pkt_ov110_021BB290
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_021BF6D4 0x021BF6D4 thumb ov110
 *   d_021C3C44 0x021C3C44 data a1
 */
#include "../include/Obj03751.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(u32,u32,int,const char *,u16); extern u8 *func_021BF6D4(u8 *); extern const char d_021C3C44[];
u8 *func_021BB290(u32 a,u8 *b,u32 c) { u8 *p; p=func_02030734(42,164,0,d_021C3C44,220); ((struct Obj03751 *)p)->f0=a; *(u8 * *)&((struct Obj03751 *)p)->f4=b; ((struct Obj03751 *)p)->f8=c; ((struct Obj03751 *)p)->fC=0; ((struct Obj03751 *)p)->f14=0; ((struct Obj03751 *)p)->f54=0; ((struct Obj03751 *)p)->f58=0; *(u8 * *)&((struct Obj03751 *)p)->f5C=func_021BF6D4(b); return p; }
