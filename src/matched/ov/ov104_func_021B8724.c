/*
 * function: func_021B8724
 * address: 0x021B8724
 * packet: pkt_ov104_021B8724
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   func_021B64F0 0x021B64F0 thumb ov101
 *   d_021B8F28 0x021B8F28 data a4
 */
#include "../include/Obj22231.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void MI_CpuFill8(void *,int,int);
extern void func_021B64F0(u32 p, u32 a, u32 b, u32 c, u32 d);
extern const u32 d_021B8F28[];
void func_021B8724(u8 *p,int a) { MI_CpuFill8(p,0,0x198); ((struct Obj22231 *)p)->f0=a; func_021B64F0(a,0xf00,(int)d_021B8F28,1,(int)p); }
