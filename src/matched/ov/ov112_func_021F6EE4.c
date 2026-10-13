/*
 * function: func_021F6EE4
 * address: 0x021F6EE4
 * packet: pkt_ov112_021F6EE4
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 */
#include "../include/Obj13836.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *);
void func_021F6EE4(void *unused,u8 *p) { CLACT_DeleteActor(*(struct Obj * *)&((struct Obj13836 *)p)->f1C); ((struct Obj13836 *)p)->f0=0; }
