/*
 * function: func_021BA124
 * address: 0x021BA124
 * packet: pkt_ov133_021BA124
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 */
#include "../include/Obj03827.h"
#include "../include/Obj14155.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
void func_021BA124(u8*p,u8*q){if(((struct Obj03827 *)p)->f4<((struct Obj03827 *)p)->f6){if(!*(u8* *)&((struct Obj03827 *)p)->f8){*(u8* *)&((struct Obj03827 *)p)->f8=q;*(u8* *)&((struct Obj03827 *)p)->fC=q;*(u8* *)&((struct Obj14155 *)q)->f30=0;}else{*(u8* *)&((struct Obj14155 *)q)->f30=*(u8* *)&((struct Obj03827 *)p)->f8;*(u8* *)&((struct Obj03827 *)p)->f8=q;}(((struct Obj03827 *)p)->f4)++;}}
