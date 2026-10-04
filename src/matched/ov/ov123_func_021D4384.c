/*
 * function: func_021D4384
 * address: 0x021D4384
 * packet: pkt_ov123_021D4384
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202F038 0x0202F038 thumb
 *   func_0202EE8C 0x0202EE8C thumb
 */
#include "../include/Obj00273.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0202F038(u8 *);
extern u8 *func_0202EE8C(u32,void *,u8,u8,u16);
void func_021D4384(u8 *p) { if(*(u8 * *)&((struct Obj00273 *)p)->f288) { func_0202F038(*(u8 * *)&((struct Obj00273 *)p)->f288); *(u32 *)&((struct Obj00273 *)p)->f288=0; } *(u8 * *)&((struct Obj00273 *)p)->f288=func_0202EE8C(((struct Obj00273 *)p)->f230,((struct Obj00273 *)p)->f224,15,16,((struct Obj00273 *)p)->fC); }
