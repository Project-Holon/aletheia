/*
 * function: WORLDTRADE_ENTER_StateWaitWifiSetup
 * address: 0x021F8DA4
 * packet: pkt_ov135_021F8DA4
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORLDTRADE_SetStateAndReturn 0x021F4EC0 thumb ov135
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj06513.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void WORLDTRADE_SetStateAndReturn(u8 *p, u32 a, u32 b);
extern u32 func_020307B0(void *p);
int WORLDTRADE_ENTER_StateWaitWifiSetup(u8 *p)
{
    u32 *state = *(u32 * *)&((struct Obj06513 *)p)->f10DC;
    if (((struct Obj06513 *)p)->f12F4 == 0) {
        switch (state[7]) {
        case 0: ((struct Obj06513 *)p)->f28 = 0; break;
        case 1:
            WORLDTRADE_SetStateAndReturn(p, 0, 0);
            ((struct Obj06513 *)p)->f28 = 1;
            break;
        }
        func_020307B0(((struct Obj06513 *)p)->f10DC);
    }
    return 2;
}
