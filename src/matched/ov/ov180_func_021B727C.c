/*
 * function: func_021B727C
 * address: 0x021B727C
 * packet: pkt_ov180_021B727C
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020056EC 0x020056EC thumb
 */
#include "../include/Obj14404.h"
#include "../include/Obj24490.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern unsigned func_020056EC(unsigned);
void func_021B727C(char *p){u32 i;char *q;((struct Obj24490 *)p)->f915F=0;for(i=0;i<8;i++){q=p+i*2;((struct Obj14404 *)q)->f9164=func_020056EC(8)-4;((struct Obj14404 *)q)->f9174=func_020056EC(8)-4;}}
