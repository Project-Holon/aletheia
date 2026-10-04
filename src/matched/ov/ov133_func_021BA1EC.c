/*
 * function: func_021BA1EC
 * address: 0x021BA1EC
 * packet: pkt_ov133_021BA1EC
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021F4D74 0x021F4D74 thumb ov112
 */
#include "../include/Obj14158.h"
#include "../include/Obj14159.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021F4D74(u8*,u8*,int,u16);
void func_021BA1EC(u8*p,u8*q,u8*r){*(u8* *)&((struct Obj14158 *)p)->f4=r;func_021F4D74(q,*(u8* *)&((struct Obj14158 *)p)->fC,((struct Obj14159 *)r)->f0,((struct Obj14159 *)r)->f4);}
