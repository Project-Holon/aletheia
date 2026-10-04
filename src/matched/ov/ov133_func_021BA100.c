/*
 * function: func_021BA100
 * address: 0x021BA100
 * packet: pkt_ov133_021BA100
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 */
#include "../include/Obj04523.h"
#include "../include/Obj05410.h"
#include "../include/Obj23326.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
void func_021BA100(u8*p,u8*q){if(((struct Obj04523 *)p)->f4<((struct Obj04523 *)p)->f6){if(!*(u8* *)&((struct Obj04523 *)p)->f8)*(u8* *)&((struct Obj04523 *)p)->f8=q;else *(u8* *)&((struct Obj23326 *)(*(u8* *)&((struct Obj04523 *)p)->fC))->f30=q;*(u8* *)&((struct Obj04523 *)p)->fC=q;*(u8* *)&((struct Obj05410 *)q)->f30=0;(((struct Obj04523 *)p)->f4)++;}}
