/*
 * function: func_021E665C
 * address: 0x021E665C
 * packet: pkt_ov119_021E665C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   func_021E66E8 0x021E66E8 thumb ov119
 *   func_021E729C 0x021E729C thumb ov119
 */
#include "../include/Obj00001.h"
typedef struct { short x,y; } Pt;
struct Actor;
struct PtS;
typedef unsigned short u16;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
typedef unsigned int   u32;
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_021E66E8(void *);
struct Curve;
extern int func_021E729C(struct Curve *c);
int func_021E665C(char *p) {
    Pt pos;
    if (((struct Obj00001 *)p)->f11DC) {
        --((struct Obj00001 *)p)->f11DC;
        if (!((struct Obj00001 *)p)->f11DC) return 1;
        CLACT_GetActorSurfacePos((struct Actor *)((struct Obj00001 *)p)->fF20,(struct PtS *)&pos,1);
        if (pos.y<0) ((struct Obj00001 *)p)->f11DC=1;
        if (((struct Obj00001 *)p)->f11DC==1) func_021E66E8(p);
        else {
            func_021E729C((struct Curve *)(p+0x1190));
            pos.x=((struct Obj00001 *)p)->f1190/4096;
            pos.y=((struct Obj00001 *)p)->f1194/4096;
            CLACT_AddActorSurfacePos((struct Obj *)(((struct Obj00001 *)p)->fF20),(const struct Vec2 *)(&pos),1);
        }
    }
    return 0;
}
