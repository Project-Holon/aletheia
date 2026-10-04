/*
 * function: func_021F4E6C
 * address: 0x021F4E6C
 * packet: pkt_ov112_021F4E6C
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204F720 0x0204F720 arm
 */
#include "../include/Obj13827.h"
#include "../include/Obj22523.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void func_0204F720(void *,u32,u32 *);
void func_021F4E6C(u8 *p,u8 *e,u32 value) { func_0204F720(((struct Obj22523 *)p)->f4,((struct Obj13827 *)e)->f8,&value); ((struct Obj13827 *)e)->f0 |=2; }
