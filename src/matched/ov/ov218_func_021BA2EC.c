/*
 * function: func_021BA2EC
 * address: 0x021BA2EC
 * packet: pkt_ov218_021BA2EC
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 */
#include "../include/Obj01983.h"
typedef unsigned char u8;typedef unsigned short u16;typedef signed short s16;typedef unsigned int u32;
extern void func_0204A8D4(u32);extern void func_0204ADA4(u32);extern void func_0204AFD8(u32);
void func_021BA2EC(char *p){if(((struct Obj01983 *)p)->f2D0!=-1)func_0204A8D4(((struct Obj01983 *)p)->f2D0);if(((struct Obj01983 *)p)->f2D4!=-1)func_0204ADA4(((struct Obj01983 *)p)->f2D4);if(((struct Obj01983 *)p)->f2D8!=-1)func_0204AFD8(((struct Obj01983 *)p)->f2D8);}
