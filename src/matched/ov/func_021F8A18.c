/*
 * function: WORLDTRADE_ENTER_Exit
 * address:  0x021F8A18
 * packet:   pkt_021F8A18
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WORLDTRADE_ENTER_EmptyExitHook  0x021F8A40  thumb  ov135
 *   WORLDTRADE_ClearAndShowPlanes  0x021F5074  thumb  ov135
 *   WORLDTRADE_ClearBusyFlag  0x021F4EC8  thumb  ov135

 * Run the three teardown steps, then report 4 while the +0x10 handle is gone.
 */
#include "../include/Obj00287.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
extern void WORLDTRADE_ENTER_EmptyExitHook(void);
extern void WORLDTRADE_ClearAndShowPlanes(u8 *p);
extern void WORLDTRADE_ClearBusyFlag(u8 *p);

u32 WORLDTRADE_ENTER_Exit(u8 *p)
{
    WORLDTRADE_ENTER_EmptyExitHook();
    WORLDTRADE_ClearAndShowPlanes(p);
    WORLDTRADE_ClearBusyFlag(p);
    if (((struct Obj00287 *)p)->f10 == 0) {
        return 4;
    }
    return 0;
}
