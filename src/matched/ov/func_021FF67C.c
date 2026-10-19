/*
 * function: WORLDTRADE_STATUS_Close
 * address:  0x021FF67C
 * packet:   pkt_021FF67C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WORLDTRADE_ClearAndShowPlanes  0x021F5074  thumb  ov135
 *   WORLDTRADE_AdvanceScreenId  0x021F4EC8  thumb  ov135

 * Publish the +0xf byte of the +0x10dc object as the u16 at +0xc6, then tear down.
 */
#include "../include/Obj12222.h"
#include "../include/Obj18600.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
extern u32 func_020307B0(void *p);
extern void WORLDTRADE_ClearAndShowPlanes(u8 *p);
extern void WORLDTRADE_AdvanceScreenId(u8 *p);

u32 WORLDTRADE_STATUS_Close(u8 *p)
{
    u32 q = ((struct Obj12222 *)p)->f10DC;

    ((struct Obj12222 *)p)->fC6 = ((struct Obj18600 *)q)->fF;
    func_020307B0((void *)q);
    WORLDTRADE_ClearAndShowPlanes(p);
    WORLDTRADE_AdvanceScreenId(p);
    return 0;
}
