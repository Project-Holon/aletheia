/*
 * function: PMSIV_WORDWIN_SetCursorCell
 * address: 0x021BFC64
 * packet: pkt_ov110_021BFC64
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of alignment padding follow the return.
 * symbols:
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 */
#include "../include/Obj13801.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u16 x,y; } Vec2;
typedef unsigned int   u32;
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
void PMSIV_WORDWIN_SetCursorCell(u8 *p, unsigned i) {
    Vec2 pos;
    if (i != -1) {
        pos.x = 0x70*(i&1)+0x3e;
        pos.y = 0x18*((i>>1)+1);
        CLACT_AddActorSurfacePos(((struct Obj13801 *)p)->f14, (const struct Vec2 *)(&pos), 0);
        CLACT_SetActorAnimSeq(((struct Obj13801 *)p)->f14, 8);
    }
}
