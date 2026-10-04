/*
 * function: func_021D4C24
 * address: 0x021D4C24
 * packet: pkt_ov123_021D4C24
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B898 0x0204B898 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B878 0x0204B878 arm
 */
#include "../include/Obj05360.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern u16 func_0204B898(struct Obj *);
extern void func_0204B92C(struct Obj *,u32);
extern void func_0204B878(struct Obj *,u16);
void func_021D4C24(u8 *p,u32 v) { if(v!=func_0204B898(*(struct Obj * *)&((struct Obj05360 *)p)->f2A0)) { func_0204B92C(*(struct Obj * *)&((struct Obj05360 *)p)->f2A0,1); func_0204B878(*(struct Obj * *)&((struct Obj05360 *)p)->f2A0,v); } }
