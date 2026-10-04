/*
 * function: func_021BA9AC
 * address: 0x021BA9AC
 * packet: pkt_ov213_021BA9AC
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020480E4 0x020480E4 arm
 */
#include "../include/Obj02551.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Ctx;
extern void func_020480E4(struct Ctx *,u32);
void func_021BA9AC(char *p) { func_020480E4(*(struct Ctx * *)&((struct Obj02551 *)p)->f8,((struct Obj02551 *)p)->fC); ((struct Obj02551 *)p)->fF=0; ((struct Obj02551 *)p)->fE=0; }
