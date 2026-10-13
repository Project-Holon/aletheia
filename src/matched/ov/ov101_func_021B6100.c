/*
 * function: func_021B6100
 * address: 0x021B6100
 * packet: pkt_ov101_021B6100
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   d_021B7524 0x021B7524 data a1
 */
#include "../include/Obj06362.h"
typedef unsigned int u32;
typedef unsigned short u16;
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void MI_CpuFill8(void *,int,u32);
extern const char d_021B7524[];
void *func_021B6100(int a,int b,int c,int d) {
 char *p;
 p=func_02030734(c,0x8c,0,d_021B7524,0x113);
 MI_CpuFill8(p,0,0x8c);
 ((struct Obj06362 *)p)->f40=a;
 ((struct Obj06362 *)p)->f88=c;
 ((struct Obj06362 *)p)->f74=0;
 ((struct Obj06362 *)p)->f78=d;
 ((struct Obj06362 *)p)->f0=b;
 return p;
}
