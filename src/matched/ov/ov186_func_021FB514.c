/*
 * function: BR_BTN_SetObjectPos
 * address: 0x021FB514
 * packet: pkt_ov186_021FB514
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   BMP_OAM_SetPos 0x0202590C thumb
 */
#include "../include/Obj10786.h"
struct Obj; struct Grid; struct Vec2{short x,y;};
typedef unsigned int   u32;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void BMP_OAM_SetPos(struct Grid *,short,short);
void BR_BTN_SetObjectPos(char *p, short x, int y) { struct Vec2 v;v.x=x;v.y=y;CLACT_AddActorSurfacePos(*(struct Obj * *)&((struct Obj10786 *)p)->f0,&v,(unsigned short)(((struct Obj10786 *)p)->f10));BMP_OAM_SetPos(*(struct Grid * *)&((struct Obj10786 *)p)->f4,v.x+32,v.y-8); }
