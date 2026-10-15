/*
 * function: COMM_BTL_DEMO_MAIN_UnloadObject
 * address: 0x021BA9AC
 * packet: pkt_ov213_021BA9AC
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   G3D_UTIL_RemoveUnit 0x020480E4 arm
 */
#include "../include/Obj02551.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Ctx;
extern void G3D_UTIL_RemoveUnit(struct Ctx *,u32);
void COMM_BTL_DEMO_MAIN_UnloadObject(char *p) { G3D_UTIL_RemoveUnit(*(struct Ctx * *)&((struct Obj02551 *)p)->f8,((struct Obj02551 *)p)->fC); ((struct Obj02551 *)p)->fF=0; ((struct Obj02551 *)p)->fE=0; }
