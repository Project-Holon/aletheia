/*
 * function: func_021F9C84
 * address: 0x021F9C84
 * packet: pkt_ov186_021F9C84
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 */
#include "../include/Obj08325.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Pair;struct PrintSys;
extern void MI_CpuFill8(void *,int,unsigned);
void func_021F9C84(char *p,int a,int b) { int zero=0;MI_CpuFill8(p,0,16);((struct Obj08325 *)p)->f0=1;((struct Obj08325 *)p)->f4=zero;((struct Obj08325 *)p)->fC=a;((struct Obj08325 *)p)->f8=b; }
