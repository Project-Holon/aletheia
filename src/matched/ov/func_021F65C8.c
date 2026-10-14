/*
 * function: WORLDTRADE_BOX_StateWaitCursorAnim
 * address:  0x021F65C8
 * packet:   pkt_021F65C8
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WORLDTRADE_BOX_FinishByKind  0x021F5CD4  thumb  ov135
 *   CLACT_IsActorAnimActive  0x0204B98C  arm  arm9

 * While the +0xbfc buffer is free, feed the mode word at +0x20 to the dispatch.
 */
#include "../include/Obj12196.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
struct Actor;
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern void WORLDTRADE_BOX_FinishByKind(u8 *p, u32 k);

int WORLDTRADE_BOX_StateWaitCursorAnim(u8 *p)
{
    if (CLACT_IsActorAnimActive((struct Actor *)(((struct Obj12196 *)p)->fBFC)) == 0) {
        WORLDTRADE_BOX_FinishByKind(p, ((struct Obj12196 *)p)->f20);
    }
    return 2;
}
