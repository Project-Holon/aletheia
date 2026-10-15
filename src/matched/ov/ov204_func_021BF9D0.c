/*
 * function: INTRO_G3D_Delete
 * address: 0x021BF9D0
 * packet: pkt_ov204_021BF9D0
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   G3D_UTIL_RemoveUnit 0x020480E4 arm
 *   G3D_UTIL_Delete 0x02047E54 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj08385.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Ctx; struct Rec; extern void G3D_CAMERA_Delete(void *); extern void G3D_UTIL_RemoveUnit(struct Ctx *,u32); extern void G3D_UTIL_Delete(struct Rec *); extern void func_020307B0(void *);
void INTRO_G3D_Delete(char *p) { u16 id; G3D_CAMERA_Delete(((struct Obj08385 *)p)->fC); id=((struct Obj08385 *)p)->f10; if(id!=65535) G3D_UTIL_RemoveUnit(*(struct Ctx * *)&((struct Obj08385 *)p)->f8,id);G3D_UTIL_Delete(*(struct Rec * *)&((struct Obj08385 *)p)->f8);func_020307B0(p); }
