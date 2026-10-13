/*
 * function: func_021F6F18
 * address: 0x021F6F18
 * packet: pkt_ov215_021F6F18
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   G3D_UTIL_Delete 0x02047E54 arm
 */
#include "../include/Obj04636.h"
struct Rec;
extern void G3D_UTIL_Delete(struct Rec *);
void func_021F6F18(char *p){G3D_UTIL_Delete(*(struct Rec * *)&((struct Obj04636 *)p)->f48);}
