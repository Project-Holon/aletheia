/*
 * function: func_021E69C0
 * address: 0x021E69C0
 * packet: pkt_ov119_021E69C0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * output: 0204B454 writes both halfwords via 0204B53C and 0204CF74/0204B0C8.
 * interface: 02040618 forwards legacy r3 only to 02042360, whose full body
 *            has three inputs and does not read it; caller supplies r0-r2.
 * symbols:
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   func_02040618 0x02040618 arm
 */
#include "../include/Obj05337.h"
typedef struct { short x,y; } Pt;
struct Actor;
struct PtS;
typedef unsigned short u16;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, unsigned int which);
typedef unsigned int   u32;
extern void func_02040618(u32 layer, u32 a, u32 b);
int func_021E69C0(char *p)
{
    Pt a,b,c;
    int i;
    if(((struct Obj05337 *)p)->f11DE<128) ((struct Obj05337 *)p)->f11DE+=4;
    else return 1;
    for(i=0;i<8;i++) {
        CLACT_GetActorSurfacePos(*(void **)(p+i*4+0x10cc),(struct PtS *)&a,1);
        if(i/4) a.x+=4; else a.x-=4;
        CLACT_AddActorSurfacePos(*(void **)(p+i*4+0x10cc),(const struct Vec2 *)(&a),1);
    }
    for(i=0;i<3;i++) {
        if(*(void **)(p+i*4+0x1008)) {
            CLACT_GetActorSurfacePos(*(void **)(p+i*4+0x1008),(struct PtS *)&b,1);
            b.x-=4;
            CLACT_AddActorSurfacePos(*(void **)(p+i*4+0x1008),(const struct Vec2 *)(&b),1);
        }
    }
    for(i=0;i<3;i++) {
        if(*(void **)(p+i*4+0x1014)) {
            CLACT_GetActorSurfacePos(*(void **)(p+i*4+0x1014),(struct PtS *)&c,1);
            c.x+=4;
            CLACT_AddActorSurfacePos(*(void **)(p+i*4+0x1014),(const struct Vec2 *)(&c),1);
        }
    }
    func_02040618(5,0,-((struct Obj05337 *)p)->f11DE);
    func_02040618(4,0,((struct Obj05337 *)p)->f11DE-128);
    return 0;
}
