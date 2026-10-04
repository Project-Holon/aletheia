/*
 * function: func_021BEB44
 * address: 0x021BEB44
 * packet: pkt_ov110_021BEB44
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021B999C 0x021B999C thumb ov110
 */
#include "../include/Obj13792.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern unsigned func_021B999C(u8 *,int);
int func_021BEB44(u8 *p) { if(func_021B999C(*(u8 * *)&((struct Obj13792 *)p)->f18,((struct Obj13792 *)p)->f4C)!=0) return 1; return 0; }
