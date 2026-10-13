/*
 * function: func_021B9848
 * address: 0x021B9848
 * packet: pkt_ov223_021B9848
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   G3D_UTIL_Delete 0x02047E54 arm
 */
#include "../include/Obj02266.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Rec;extern void G3D_UTIL_Delete(struct Rec *);
void func_021B9848(int *p) { G3D_UTIL_Delete(*(struct Rec * *)&((struct Obj02266 *)p)->f28); }
