/*
 * function: POKETRADE_2D_PlaceBoxIconActors
 * address: 0x021E4A1C
 * packet: pkt_ov119_021E4A1C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 */
#include "../include/Obj13921.h"
#include "../include/Obj13922.h"
typedef unsigned int   u32;
struct Obj;
extern u32 CLACT_GetActorDrawEnable(struct Obj *p);
struct Actor;
struct PtS;
typedef unsigned short u16;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
void POKETRADE_2D_PlaceBoxIconActors(char *p)
{
    short xy[2];
    int i, j;
    char *q, *r;
    for (i = 0; i < 5; i++) {
        q = p + i * 4;
        for (j = 0; j < 12; j++) {
            r = q + j * 20;
            if (CLACT_GetActorDrawEnable((struct Obj *)(((struct Obj13922 *)r)->fBB0))) {
                CLACT_GetActorSurfacePos((struct Actor *)((struct Obj13922 *)r)->fBB0, (struct PtS *)xy, 1);
                ((struct Obj13921 *)p)->fF54 = xy[0];
                ((struct Obj13921 *)p)->fF58 = xy[1];
            }
        }
    }
}
