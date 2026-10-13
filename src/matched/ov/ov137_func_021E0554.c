/*
 * unit: no
 * function: func_021E0554
 * address: 0x021E0554
 * packet: pkt_ov137_021E0554
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   G3D_UTIL_RemoveUnit 0x020480E4 arm
 */
#include "../include/Obj14232.h"
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
struct Descriptor;struct Cfg;struct CharBuf;struct Bank;struct Util;struct Setup;struct Ctx;
extern void G3D_UTIL_RemoveUnit(struct Ctx *c, u32 i);
void func_021E0554(u8 *p){G3D_UTIL_RemoveUnit(*(struct Ctx * *)&((struct Obj14232 *)p)->fAF4,(u16)(((struct Obj14232 *)p)->f19C));}
