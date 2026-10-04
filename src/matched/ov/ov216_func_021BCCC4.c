/*
 * function: func_021BCCC4
 * address: 0x021BCCC4
 * packet: pkt_ov216_021BCCC4
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02035D20 0x02035D20 arm
 */
#include "../include/Obj14718.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_02035D20(u32 *outA, u32 *outB);
int func_021BCCC4(u8*p){u32 x,y;if(func_02035D20(&x,&y)){if((u32)(x-(((struct Obj14718 *)p)->f25C-12))<=24 && (u32)(y-(((struct Obj14718 *)p)->f25E-16))<=32)return 1;}return 0;}
