/*
 * function: WORLDTRADE_SEARCH_StateCursorAnimB
 * address: 0x021FF26C
 * packet: pkt_ov135_021FF26C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   WORLDTRADE_SEARCH_GetSelectedButton 0x021FE9B0 thumb ov135
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   func_020355C4 0x020355C4 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   WORLDTRADE_SEARCH_PrintMessage 0x021FF318 thumb ov135
 *   WORLDTRADE_SetNextState 0x021F4E98 thumb ov135
 *   d_02203D4A 0x02203D4A data a2
 */
#include "../include/Obj00018.h"
typedef unsigned short u16;
typedef unsigned int   u32;
struct Actor;
struct Obj;
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern int WORLDTRADE_SEARCH_GetSelectedButton(char *);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
typedef unsigned char  u8;
extern u8 func_020355C4(void);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);
extern const u16 d_02203D4A[][4];
extern void WORLDTRADE_SEARCH_PrintMessage(u8 *p, u32 k, int b, int c, int d);
extern void WORLDTRADE_SetNextState(u8 *p, u32 a, u32 b);
int WORLDTRADE_SEARCH_StateCursorAnimB(char *p)
{
    if (CLACT_IsActorAnimActive((struct Actor *)(((struct Obj00018 *)p)->fBF4)) == 0) {
        CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00018 *)p)->fBF4), d_02203D4A[WORLDTRADE_SEARCH_GetSelectedButton(p)][0]);
        if (func_020355C4() == 1)
            CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00018 *)p)->fBF4, 0);
        else
            CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00018 *)p)->fBF4, 1);
        WORLDTRADE_SEARCH_PrintMessage((u8 *)p, 15, 1, 0, 0xf0f);
        WORLDTRADE_SetNextState((u8 *)p, 23, 26);
    }
    return 2;
}
