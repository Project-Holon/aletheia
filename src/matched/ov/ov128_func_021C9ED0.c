/*
 * function: func_021C9ED0
 * address: 0x021C9ED0
 * packet: pkt_ov128_021C9ED0
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj08133.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
void func_021C9ED0(u32 p,int unused,const u16 *q,u32 value) { int i; ((struct Obj08133 *)p)->f8=value; ((struct Obj08133 *)p)->f0=q[0]; ((struct Obj08133 *)p)->f2=q[1]; ((struct Obj08133 *)p)->f4=q[2]; for(i=0;i<8;i++) *(u32 *)(p+44+i*4)=0; }
