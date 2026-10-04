/*
 * function: func_021BA1D8
 * address: 0x021BA1D8
 * packet: pkt_ov133_021BA1D8
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F4D40 0x021F4D40 thumb ov112
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj23329.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021F4D40(u8*,u8*);
extern void func_020307B0(void*);
void func_021BA1D8(u8*p,u8*q){func_021F4D40(q,*(u8* *)&((struct Obj23329 *)p)->fC);func_020307B0(p);}
