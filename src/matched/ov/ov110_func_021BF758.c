/*
 * function: func_021BF758
 * address: 0x021BF758
 * packet: pkt_ov110_021BF758
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: two trailing zero alignment bytes.
 * symbols:
 *   func_021B99A4 0x021B99A4 thumb ov110
 *   func_021BB1CC 0x021BB1CC thumb ov110
 */
#include "../include/Obj08009.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021B99A4(u32,u32,u32,int);
extern void func_021BB1CC(u8 *,u8,int);
void func_021BF758(u8 *p,u32 a,int b) {
    if(p[0x69]==0) func_021B99A4(((struct Obj08009 *)p)->f18,((struct Obj08009 *)p)->f4C,a,b);
    else func_021BB1CC(*(u8 * *)&((struct Obj08009 *)p)->f1C,a,b);
}
