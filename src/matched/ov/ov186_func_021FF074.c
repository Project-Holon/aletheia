/*
 * function: func_021FF074
 * address: 0x021FF074
 * packet: pkt_ov186_021FF074
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B49C 0x0204B49C arm
 *   func_0204B5D4 0x0204B5D4 arm
 */
#include "../include/Obj05508.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Actor;
extern void func_0204B49C(struct Actor *actor, s16 value, u32 space, u32 axis);
extern void func_0204B5D4(struct Actor*,u32,u32);
/* Space is explicitly truncated to u16 at the original call. */
void func_021FF074(u8*p){((struct Obj05508 *)p)->f14=410;func_0204B49C(*(struct Actor* *)&((struct Obj05508 *)p)->f4,((struct Obj05508 *)p)->f3C,(u16)(((struct Obj05508 *)p)->f44),0);func_0204B5D4(*(struct Actor* *)&((struct Obj05508 *)p)->f4,((struct Obj05508 *)p)->f14,0);}
