/*
 * function: func_021B89B8
 * address: 0x021B89B8
 * packet: pkt_ov102_021B89B8
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B8868 0x021B8868 thumb ov102
 *   MI_CpuFill8 0x02082BCC arm
 */
#include "../include/Obj22169.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021B8868(void *);
extern void MI_CpuFill8(void *,int,u32);
void func_021B89B8(u8 *p) { int i; for(i=0;i<((struct Obj22169 *)p)->f34E;i++)func_021B8868(p+i*28); MI_CpuFill8(p,0,848); }
