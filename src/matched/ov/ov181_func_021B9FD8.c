/*
 * unit: no
 * function: func_021B9FD8
 * address: 0x021B9FD8
 * packet: pkt_ov181_021B9FD8
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 */
#include "../include/Obj10722.h"
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
void func_021B9FD8(u8 *p,int a,int b){u32 i;for(i=0;i<16;i++){u8 *q=p+i*4;if(((struct Obj10722 *)q)->f34==65535){((struct Obj10722 *)q)->f34=a;((struct Obj10722 *)q)->f36=b;return;}}}
