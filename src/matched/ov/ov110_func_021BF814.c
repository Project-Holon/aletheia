/*
 * function: func_021BF814
 * address: 0x021BF814
 * packet: pkt_ov110_021BF814
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BB1CC 0x021BB1CC thumb ov110
 */
#include "../include/Obj22401.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021BB1CC(u8 *,u8,int);
void func_021BF814(u8 *p,u32 a,int b) { func_021BB1CC(*(u8 * *)&((struct Obj22401 *)p)->f1C,a,b); }
