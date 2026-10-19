/*
 * function: WORLDTRADE_TITLE_StateWaitMessageTimed
 * address:  0x0220090C
 * packet:   pkt_0220090C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WORLDTRADE_ADAPTER_IsStreamBusy  0x02202840  thumb  ov135

 * When the build query answers 0, bump the countdown at +0xdfc and roll state when it passes 0x2d.
 */
#include "../include/Obj07254.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern u32 WORLDTRADE_ADAPTER_IsStreamBusy(u8 *p);

int WORLDTRADE_TITLE_StateWaitMessageTimed(u8 *p)
{
    if (WORLDTRADE_ADAPTER_IsStreamBusy(p + 0xfa0) == 0) {
        if (++((struct Obj07254 *)p)->fDFC > 0x2d) {
            ((struct Obj07254 *)p)->fDFC = 0;
            ((struct Obj07254 *)p)->f28 = ((struct Obj07254 *)p)->f2C;
        }
    }
    return 2;
}
