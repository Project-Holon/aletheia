/*
 * function: WORLDTRADE_INPUT_StateReturnToCategoryAlt
 * address: 0x021FB7A0
 * packet: pkt_ov135_021FB7A0
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   WORLDTRADE_INPUT_DrawFrame 0x021FA9C8 thumb ov135
 *   WORLDTRADE_SetActorPos 0x021F4FF4 thumb ov135
 *   tbl_02203298 0x02203298 data a1
 *   BGWINFRM_StartMove  0x0202CD64  thumb  arm9
 */
#include "../include/Obj02859.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed char s8;
struct WinMgr;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int on);
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void WORLDTRADE_INPUT_DrawFrame(u8 *p, int mode, int pos);
extern void WORLDTRADE_SetActorPos(u32 a, u32 b, u32 c);
extern u8 func_020355C4(void);
extern void BGWINFRM_StartMove(struct WinMgr *mgr, u32 idx, s8 dx, s8 dy, u8 frames);
extern const u8 tbl_02203298[][2];
int WORLDTRADE_INPUT_StateReturnToCategoryAlt(u8 *p)
{
    WORLDTRADE_INPUT_DrawFrame(p, 6, 0x10);
    CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj02859 *)p)->f8), 18);
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj02859 *)p)->f8, 1);
    ((struct Obj02859 *)p)->f44 = ((struct Obj02859 *)p)->f38;
    WORLDTRADE_SetActorPos(((struct Obj02859 *)p)->f8, (tbl_02203298[((struct Obj02859 *)p)->f44][0] + 16) * 8, tbl_02203298[((struct Obj02859 *)p)->f44][1] * 8);
    if (func_020355C4() == 1) CLACT_SetActorDrawEnable((struct Obj *)((struct Obj02859 *)p)->f8, 0);
    else CLACT_SetActorDrawEnable((struct Obj *)((struct Obj02859 *)p)->f8, 1);
    ((struct Obj02859 *)p)->f48 = 19;
    return -1;
}
