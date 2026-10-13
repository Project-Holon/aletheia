/*
 * function: ITEMMENU_UpdateCursorFromTouch
 * address:  0x021BA654
 * packet:   pkt_ov070_021BA654
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TOUCHPANEL_GetPointCont  0x02035CB8  arm
 *   CLACT_GetActorSurfacePos  0x0204B454  arm
 *   func_0204B404  0x0204B404  arm
 */
#include "../include/Obj13158.h"

typedef struct {
    unsigned short a, b;
} Pt;

typedef unsigned int   u32;
extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);
struct Actor;
struct PtS;
typedef unsigned short u16;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
struct Obj;
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);

void ITEMMENU_UpdateCursorFromTouch(char *p)
{
    unsigned w;
    unsigned v;
    Pt pt;
    if (TOUCHPANEL_GetPointCont(&w, &v) == 1) {
        if (v < 0x1A) {
            v = 0x1A;
        } else if (v > 0x8E) {
            v = 0x8E;
        }
        CLACT_GetActorSurfacePos((struct Actor *)((struct Obj13158 *)p)->f6A8, (struct PtS *)&pt, 0xFFFF);
        pt.b = v;
        func_0204B404((struct Obj *)(((struct Obj13158 *)p)->f6A8), (const struct Vec2 *)(&pt), 0xFFFF);
    }
}
