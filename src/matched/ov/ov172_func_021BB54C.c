/*
 * function: CTVT_DRAW_UpdateToolButtons
 * address:  0x021BB54C
 * packet:   pkt_ov172_021BB54C
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   COMM_TVT_SYS_GetViewSwapped  0x021BE0B4  thumb  ov172
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_RestartActorAnim  0x0204B9A0  arm
 *   CLACT_SetActorAnimFrame  0x0204B8C4  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   gCtvtDrawPenButtonAnimSeq     0x021C6FB2  data
 *   gCtvtDrawPickButtonAnimSeq     0x021C6FB4  data
 *   gCtvtDrawEraserButtonAnimSeq     0x021C6FB6  data
 *   gCtvtDrawStampButtonAnimSeq     0x021C6FB8  data
 */
#include "../include/Obj00024.h"

typedef unsigned char u8;
typedef unsigned long u32;

typedef unsigned short u16;
struct Actor;
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern u32 COMM_TVT_SYS_GetViewSwapped(void *p);
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern void CLACT_RestartActorAnim(struct Actor *a);
extern void CLACT_SetActorAnimFrame(struct Obj *p, u32 value);
extern void CLACT_SetActorAutoAnim(struct Obj *p, unsigned int v);
extern const u8 gCtvtDrawPenButtonAnimSeq[];
extern const u8 gCtvtDrawPickButtonAnimSeq[];
extern const u8 gCtvtDrawEraserButtonAnimSeq[];
extern const u8 gCtvtDrawStampButtonAnimSeq[];

void CTVT_DRAW_UpdateToolButtons(void *ctx, u8 *p)
{
    int r;

    CLACT_SetActorAnimSeq(((struct Obj00024 *)p)->f58, gCtvtDrawPenButtonAnimSeq[((struct Obj00024 *)p)->f28 == 0]);
    CLACT_SetActorAnimSeq(((struct Obj00024 *)p)->f5C, gCtvtDrawPickButtonAnimSeq[((struct Obj00024 *)p)->f28 == 1]);
    CLACT_SetActorAnimSeq(((struct Obj00024 *)p)->f60, gCtvtDrawEraserButtonAnimSeq[((struct Obj00024 *)p)->f28 == 2]);
    CLACT_SetActorAnimSeq(((struct Obj00024 *)p)->f64, gCtvtDrawStampButtonAnimSeq[((struct Obj00024 *)p)->f28 == 3]);
    r = COMM_TVT_SYS_GetViewSwapped(ctx);
    if (r == 1) {
        CLACT_SetActorAnimSeq(((struct Obj00024 *)p)->f68, 12);
    } else {
        CLACT_SetActorAnimSeq(((struct Obj00024 *)p)->f68, 10);
    }
    if (((struct Obj00024 *)p)->f28 != 0 && ((struct Obj00024 *)p)->f10 == 1) {
        ((struct Obj00024 *)p)->f10 = 0;
        CLACT_SetActorDrawEnable(((struct Obj00024 *)p)->f84, 0);
        CLACT_RestartActorAnim(((struct Obj00024 *)p)->f84);
        CLACT_SetActorAnimFrame(((struct Obj00024 *)p)->f84, 0);
        CLACT_SetActorAutoAnim(((struct Obj00024 *)p)->f84, 0);
        CLACT_SetActorDrawEnable(((struct Obj00024 *)p)->f90, 0);
    }
    if (((struct Obj00024 *)p)->f28 != 3 && ((struct Obj00024 *)p)->f14 == 1) {
        ((struct Obj00024 *)p)->f14 = 0;
        CLACT_SetActorDrawEnable(((struct Obj00024 *)p)->f88, 0);
        CLACT_RestartActorAnim(((struct Obj00024 *)p)->f88);
        CLACT_SetActorAnimFrame(((struct Obj00024 *)p)->f88, 0);
        CLACT_SetActorAutoAnim(((struct Obj00024 *)p)->f88, 0);
        CLACT_SetActorDrawEnable(((struct Obj00024 *)p)->f90, 0);
    }
}
