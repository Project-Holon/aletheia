/*
 * unit: no
 * function: func_021BAAE0
 * address: 0x021BAAE0
 * packet: pkt_ov181_021BAAE0
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021B9FD8 0x021B9FD8 thumb ov181
 *   func_021BA2A8 0x021BA2A8 thumb ov181
 */
#include "../include/Obj14415.h"
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
extern void func_021B9FD8(u8 *,int,int);
extern void func_021BA2A8(u8 *,u32);
int func_021BAAE0(u8 *p,u8 *q){u8 *s=(u8 *)((u32)p+0x28);func_021B9FD8(s,q[7],((struct Obj14415 *)q)->f4);func_021BA2A8(s,1);return 1;}
