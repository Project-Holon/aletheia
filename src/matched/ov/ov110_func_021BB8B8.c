/*
 * function: func_021BB8B8
 * address: 0x021BB8B8
 * packet: pkt_ov110_021BB8B8
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding after return.
 * symbols:
 *   func_021BF6DC 0x021BF6DC thumb ov110
 *   func_02041EE4 0x02041EE4 arm
 */
#include "../include/Obj22368.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern u8 func_021BF6DC(u8 *);
extern void func_02041EE4(u32,u32,u32);
void func_021BB8B8(u8 *p) { int v; if (func_021BF6DC(*(u8 * *)&((struct Obj22368 *)p)->f4)==0) v=-4; else v=0; func_02041EE4(1,0,v); }
