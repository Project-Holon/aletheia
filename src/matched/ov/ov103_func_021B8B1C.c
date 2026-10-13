/*
 * function: func_021B8B1C
 * address: 0x021B8B1C
 * packet: pkt_ov103_021B8B1C
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   func_021B6508 0x021B6508 thumb ov101
 */
#include "../include/Obj22210.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void MI_CpuFill8(void *,int,u32); extern void func_021B6508(void *,int);
void func_021B8B1C(u8 *p) {func_021B6508(((struct Obj22210 *)p)->f0,0xe00);MI_CpuFill8(p,0,0x294);}
