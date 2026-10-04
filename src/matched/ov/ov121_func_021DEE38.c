/*
 * function: func_021DEE38
 * address: 0x021DEE38
 * packet: pkt_ov121_021DEE38
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021DFC00 0x021DFC00 data a4
 *   func_021C5B80 0x021C5B80 arm ov114
 */
#include "../include/Obj08104.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int d_021DFC00[];extern int func_021C5B80(void);
void func_021DEE38(u32 p,int a,int *state,int b,int c) {d_021DFC00[0]=0;d_021DFC00[3]=a;((struct Obj08104 *)p)->f708=b;((struct Obj08104 *)p)->f72C=0;*state=200;if(func_021C5B80()==0)*state=c;}
