/*
 * function: func_021BE838
 * address: 0x021BE838
 * packet: pkt_ov204_021BE838
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0207D63C 0x0207D63C arm
 *   func_021BFCE8 0x021BFCE8 thumb ov204
 */
#include "../include/Obj25369.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0207D63C(void*,int,int,int,int);
extern void func_021BFCE8(u32*,u32,u32,u32);
int func_021BE838(u8*p,u32 unused,u32*q){func_0207D63C((void*)0x04000050,1,9,0,0);func_021BFCE8(*(u32* *)&((struct Obj25369 *)p)->f10,q[0],q[1],0);return 1;}
