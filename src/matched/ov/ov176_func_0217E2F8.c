/*
 * function: func_0217E2F8
 * address: 0x0217E2F8
 * packet: pkt_ov176_0217E2F8
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuCopy8 0x02082D44 arm
 */
#include "../include/Obj14370.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void MI_CpuCopy8(void *,const void *,u32);
int func_0217E2F8(u8 *p,const void *q) {int v;v=((struct Obj14370 *)p)->f1014;if(v) {((struct Obj14370 *)p)->f1014=0;MI_CpuCopy8(p+6,q,4);}return v;}
