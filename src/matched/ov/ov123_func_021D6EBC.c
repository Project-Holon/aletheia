/*
 * unit: yes
 * function: func_021D6EBC,func_021D6EDC
 * address: 0x021D6EBC
 * packet: pkt_ov123_021D6EBC
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 */
#include "../include/Obj13983.h"
#include "../include/Obj22954.h"
#include "../include/Obj22955.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
int func_021D6EBC(u8 *p){u8 *q=*(u8 * *)&((struct Obj22954 *)p)->f20;if(((struct Obj13983 *)q)->f50){unsigned int x=((struct Obj13983 *)q)->fC;if(x==0)return 1;if(x==4)return 1;}return 0;}
void func_021D6EDC(u8 *p,u32 v,int unused){((struct Obj22955 *)p)->f50=v;}
