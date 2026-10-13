/*
 * function: func_021BAA5C
 * address: 0x021BAA5C
 * packet: pkt_ov223_021BAA5C
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BAA84 0x021BAA84 thumb ov223
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 */
#include "../include/Obj00211.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;typedef struct Vec2 {s16 x,y;} Vec2;struct Obj;extern void func_021BAA84(char *,int);extern void CLACT_AddActorSurfacePos(struct Obj *,const Vec2 *,u32);
void func_021BAA5C(char *p,int flag) {Vec2 pos;if(flag) {func_021BAA84(p,flag);}else {pos.x=400;pos.y=300;CLACT_AddActorSurfacePos(*(struct Obj * *)&((struct Obj00211 *)p)->f224,&pos,0);}}
