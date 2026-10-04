/*
 * function: func_021D81B4
 * address: 0x021D81B4
 * packet: pkt_ov116_021D81B4
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202F038 0x0202F038 thumb
 */
#include "../include/Obj10345.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0202F038(u8 *);
void func_021D81B4(u8 *p) { if(*(u8 * *)&((struct Obj10345 *)p)->f98C!=0) { func_0202F038(*(u8 * *)&((struct Obj10345 *)p)->f98C); *(u32 *)&((struct Obj10345 *)p)->f98C=0; } }
