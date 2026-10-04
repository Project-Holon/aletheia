/*
 * unit: no
 * function: func_021D679C
 * address: 0x021D679C
 * packet: pkt_ov123_021D679C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 */
#include "../include/Obj10441.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
struct Obj;
extern void func_0204B3DC(struct Obj *,u32);
void func_021D679C(u8 *p){if(*(struct Obj * *)&((struct Obj10441 *)p)->f0)func_0204B3DC(*(struct Obj * *)&((struct Obj10441 *)p)->f0,0);((struct Obj10441 *)p)->f0=0;}
