/*
 * function: func_021BA098
 * address: 0x021BA098
 * packet: pkt_ov133_021BA098
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_RestartActorAnim 0x0204B9A0 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 */
#include "../include/Obj00004.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Actor;
typedef struct {short x,y;} Pos;
extern void CLACT_RestartActorAnim(struct Actor*);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
void func_021BA098(u8*p){Pos pos;pos.x=((struct Obj00004 *)p)->f1C;pos.y=*(int *)&((struct Obj00004 *)p)->f20;CLACT_RestartActorAnim(*(struct Actor* *)&((struct Obj00004 *)p)->f18B4);CLACT_SetActorDrawEnable(*(void* *)&((struct Obj00004 *)p)->f18B4,1);CLACT_AddActorSurfacePos(*(void* *)&((struct Obj00004 *)p)->f18B4,(const struct Vec2 *)(&pos),0);}
