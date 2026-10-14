/*
 * function: WORLDTRADE_INPUT_MenuDelete
 * address:  0x021F99D0
 * packet:   pkt_021F99D0
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WORLDTRADE_ADAPTER_ExitPrinter  0x02202744  thumb  ov135
 *   WORLDTRADE_ADAPTER_ExitMessageSystem  0x022029D4  thumb  ov135
 *   BGWINFRM_Delete  0x0202CA0C  thumb  arm9
 *

 *
 * Tear the object down: sub-object at +0x7c, buffer at +0x34, then the object.
 */
#include "../include/Obj12206.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
struct WinMgr;
extern void WORLDTRADE_ADAPTER_ExitPrinter(u8 *p);
extern void WORLDTRADE_ADAPTER_ExitMessageSystem(u8 *p);
extern void BGWINFRM_Delete(struct WinMgr *mgr);
extern u32 func_020307B0(void *p);

void WORLDTRADE_INPUT_MenuDelete(u8 *p)
{
    WORLDTRADE_ADAPTER_ExitPrinter(p + 0x7c);
    WORLDTRADE_ADAPTER_ExitMessageSystem(*(u8 * *)&((struct Obj12206 *)p)->f34);
    BGWINFRM_Delete(*(struct WinMgr * *)&((struct Obj12206 *)p)->f18);
    func_020307B0((void *)((u32)p));
}
