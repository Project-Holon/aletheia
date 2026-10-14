/*
 * function: WORLDTRADE_INPUT_StateWaitFrameHide
 * address:  0x021FAD84
 * packet:   pkt_021FAD84
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BGWINFRM_HideFrame  0x0202CC70  thumb  arm9
 *   BGWINFRM_IsMoving  0x0202CE40  thumb  arm9
 *

 *
 * Drain the queue then flush the shadowed value, always answering -1.
 */
#include "../include/Obj07245.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
struct WinMgr;
extern u32 BGWINFRM_IsMoving(struct WinMgr *mgr, u32 idx);
extern void BGWINFRM_HideFrame(struct WinMgr *mgr, u32 idx);

int WORLDTRADE_INPUT_StateWaitFrameHide(u8 *p)
{
    if (BGWINFRM_IsMoving(*(struct WinMgr * *)&((struct Obj07245 *)p)->f18, 0) == 0) {
        BGWINFRM_HideFrame(*(struct WinMgr * *)&((struct Obj07245 *)p)->f18, 0);
        ((struct Obj07245 *)p)->f48 = ((struct Obj07245 *)p)->f4C;
    }
    return -1;
}
