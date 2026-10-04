/*
 * function: func_021B95C0
 * address: 0x021B95C0
 * packet: pkt_ov100_021B95C0
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203D0D0 0x0203D0D0 arm
 *   func_0203CEAC 0x0203CEAC arm
 */
#include "../include/Obj22064.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_0203D0D0(void);
extern int func_0203CEAC(int a0);
void func_021B95C0(u8 *p) { *(int *)(((struct Obj22064 *)p)->f244+0x1c)=12; func_0203D0D0(); func_0203CEAC(0); }
