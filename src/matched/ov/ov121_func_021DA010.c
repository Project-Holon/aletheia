/*
 * function: func_021DA010
 * address: 0x021DA010
 * packet: pkt_ov121_021DA010
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202F038 0x0202F038 thumb
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 */
#include "../include/Obj00236.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0202F038(u8 *);
struct Cfg;
struct Descriptor;
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32);
void func_021DA010(u8 *p) { ((struct Obj00236 *)p)->f2C=1; if(*(u8 * *)&((struct Obj00236 *)p)->f3C) { func_0202F038(*(u8 * *)&((struct Obj00236 *)p)->f3C); *(u32 *)&((struct Obj00236 *)p)->f3C=0; func_02045374(((struct Obj00236 *)p)->f10); func_020409B4(func_02045730(((struct Obj00236 *)p)->f10)); } }
