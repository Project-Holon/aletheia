/*
 * function: PMSIV_EDIT_SetCursorsVisible
 * address: 0x021BC704
 * packet: pkt_ov110_021BC704
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   PMSIV_EDIT_SetCursorPressed 0x021BC69C thumb ov110
 */
#include "../include/Obj01393.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void PMSIV_EDIT_SetCursorPressed(u8 *, int);
void PMSIV_EDIT_SetCursorsVisible(u8 *p, u32 flag)
{
    CLACT_SetActorDrawEnable(((struct Obj01393 *)p)->f14, flag);
    CLACT_SetActorDrawEnable(((struct Obj01393 *)p)->f18, flag);
    PMSIV_EDIT_SetCursorPressed(p, 1);
}
