/*
 * function: func_021BFE24
 * address: 0x021BFE24
 * packet: pkt_ov110_021BFE24
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 */
#include "../include/Obj13804.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct Vec2 { s16 x,y; } Vec2;
struct Actor;
struct PtS;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
struct Obj;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
void func_021BFE24(u8 *p,int y) { Vec2 pos; CLACT_GetActorSurfacePos((struct Actor *)((struct Obj13804 *)p)->f1C,(struct PtS *)&pos,0); pos.y=y; if(pos.y<18) pos.y=18; if(pos.y>149) pos.y=149; CLACT_AddActorSurfacePos(((struct Obj13804 *)p)->f1C,&pos,0); }
