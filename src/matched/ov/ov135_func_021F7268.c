/*
 * function: WORLDTRADE_DEMO_Exit
 * address: 0x021F7268
 * packet: pkt_ov135_021F7268
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 0x021F72AC writes hardware halfword 0x04000050.
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   WORLDTRADE_ClearAndShowPlanes 0x021F5074 thumb ov135
 *   WORLDTRADE_AdvanceScreenId 0x021F4EC8 thumb ov135
 */
#include "../include/Obj03829.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern void WORLDTRADE_ClearAndShowPlanes(void *p);
extern void WORLDTRADE_AdvanceScreenId(u8 *p);
int WORLDTRADE_DEMO_Exit(u8 *p)
{
    if (((struct Obj03829 *)p)->fD8) {
        func_020307B0(((struct Obj03829 *)p)->fD8);
        ((struct Obj03829 *)p)->fD8 = 0;
    }
    func_020307B0(((struct Obj03829 *)p)->fEA4);
    if (((struct Obj03829 *)p)->f10DC) {
        func_020307B0(((struct Obj03829 *)p)->f10DC);
        ((struct Obj03829 *)p)->f10DC = 0;
    }
    ((struct Obj03829 *)p)->f12F8 = 0;
    WORLDTRADE_ClearAndShowPlanes(p);
    WORLDTRADE_AdvanceScreenId(p);
    *(volatile unsigned short *)0x04000050 = 0;
    return 0;
}
