/*
 * function: func_021B8AF4
 * address: 0x021B8AF4
 * packet: pkt_ov103_021B8AF4
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_021B64F0 0x021B64F0 thumb ov101
 *   func_021B9220 0x021B9220 data a4
 */
#include "../include/Obj22209.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02082BCC(void *,int,u32); extern void func_021B64F0(void *,int,void *,int,void *); extern u8 func_021B9220[];
void func_021B8AF4(u8 *p,void *q) {func_02082BCC(p,0,0x294);((struct Obj22209 *)p)->f0=q;func_021B64F0(q,0xe00,func_021B9220,1,p);}
