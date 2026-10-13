/*
 * function: func_021BFD94
 * address: 0x021BFD94
 * packet: pkt_ov110_021BFD94
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 */
#include "../include/Obj13803.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct Vec2 { s16 x,y; } Vec2;
struct Obj;
extern u32 CLACT_GetActorDrawEnable(struct Obj *p);
struct Actor;
struct PtS;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
u32 func_021BFD94(u8 *p,Vec2 *out) { u32 result; result=CLACT_GetActorDrawEnable(((struct Obj13803 *)p)->f1C); CLACT_GetActorSurfacePos(((struct Obj13803 *)p)->f1C,(struct PtS *)out,0); return result; }
