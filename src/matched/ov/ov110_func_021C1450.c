/*
 * function: func_021C1450
 * address: 0x021C1450
 * packet: pkt_ov110_021C1450
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020355D8 0x020355D8 arm
 *   func_021C0AC8 0x021C0AC8 thumb ov110
 *   func_02023F60 0x02023F60 thumb
 */
#include "../include/Obj06396.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_020355D8(u8);
extern int func_021C0AC8(void *parent, void *bank, u16 size);
extern void func_02023F60(u32,u32,u32);
int func_021C1450(void *a, u8 *p) { if(((struct Obj06396 *)p)->fA8) func_020355D8(1); else func_020355D8(0); ((struct Obj06396 *)p)->f68=(void *)func_021C0AC8((void *)(((struct Obj06396 *)p)->f64),(void *)(((struct Obj06396 *)p)->f60),((struct Obj06396 *)p)->f4); func_02023F60(-8,30,1); return 1; }
