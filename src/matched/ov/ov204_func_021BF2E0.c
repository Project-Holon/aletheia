/*
 * function: func_021BF2E0
 * address: 0x021BF2E0
 * packet: pkt_ov204_021BF2E0
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201CE30 0x0201CE30 thumb
 */
#include "../include/Obj25386.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_0201CE30(void *p);
u32 func_021BF2E0(u8*p){u32 a=((struct Obj25386 *)p)->f14;if(a==0){return 2;}else{return func_0201CE30((void *)a);}}
