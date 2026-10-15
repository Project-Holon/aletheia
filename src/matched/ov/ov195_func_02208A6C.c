/*
 * function: SHINKA_DEMO_EFFECT_DeleteUnit
 * address: 0x02208A6C
 * packet: pkt_ov195_02208A6C
 * region: ov195
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   G3D_UTIL_Delete 0x02047E54 arm
 */
#include "../include/Obj05518.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Rec;
extern void G3D_UTIL_Delete(struct Rec *);
void SHINKA_DEMO_EFFECT_DeleteUnit(char *p) { G3D_UTIL_Delete(*(struct Rec * *)&((struct Obj05518 *)p)->f14); }
