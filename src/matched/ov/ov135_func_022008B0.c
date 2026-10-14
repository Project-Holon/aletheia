/*
 * function: WORLDTRADE_TITLE_StateUpdateCursorAnim
 * address: 0x022008B0
 * packet: pkt_ov135_022008B0
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   func_020355C4 0x020355C4 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   WORLDTRADE_TITLE_HandleSelection 0x0220053C thumb ov135
 */
#include "../include/Obj01749.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Actor;
struct Obj;
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern u8 func_020355C4(void);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);
extern void WORLDTRADE_TITLE_HandleSelection(u8 *p, int mode);
int WORLDTRADE_TITLE_StateUpdateCursorAnim(u8 *p)
{
    if (CLACT_IsActorAnimActive((struct Actor *)(((struct Obj01749 *)p)->fBF4)) == 0) {
        CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj01749 *)p)->fBF4), 0);
        if (func_020355C4() == 1)
            CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01749 *)p)->fBF4, 0);
        else
            CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01749 *)p)->fBF4, 1);
        WORLDTRADE_TITLE_HandleSelection(p, ((struct Obj01749 *)p)->fC0);
    }
    return 2;
}
