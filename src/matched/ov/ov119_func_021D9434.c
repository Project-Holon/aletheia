/*
 * function: POKETRADE_PROC_StepBeginWipeOut
 * address:  0x021D9434
 * packet:   pkt_ov119_021D9434
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   POKETRADE_PROC_SetStep  0x021D8E84  thumb  ov119
 *   POKETRADE_PROC_StepWaitWipeEnd  0x021D941C  thumb  ov119
 *
 * Start a 7-argument timer/slot request (0,0,0,0,6,1,*(u16*)(p+0x5f4)) then
 * hand POKETRADE_PROC_SetStep the POKETRADE_PROC_StepWaitWipeEnd callback. Non-SDK dep of
 * POKETRADE_SAVE_ResetClactAndBeginEvent's case-5 arm.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj22723.h"

typedef unsigned short u16;

typedef unsigned int   u32;
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void POKETRADE_PROC_SetStep(void *, int);
extern void POKETRADE_PROC_StepWaitWipeEnd(void *p);

void POKETRADE_PROC_StepBeginWipeOut(void *p)
{
    WIPE_SYS_Start(0, 0, 0, 0, 6, 1, ((struct Obj22723 *)p)->f5F4);
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_PROC_StepWaitWipeEnd);
}
