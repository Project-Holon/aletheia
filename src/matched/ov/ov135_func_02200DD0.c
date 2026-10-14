/*
 * function: WORLDTRADE_SERVER_LoadBgGraphics
 * address: 0x02200DD0
 * packet: pkt_ov135_02200DD0
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02049B40 0x02049B40 arm
 *   func_02040588 0x02040588 arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   WORLDTRADE_TITLE_LoadMainBgSwap 0x02200AB4 thumb ov135
 *   WORLDTRADE_TITLE_LoadSubBgSwap 0x02200B34 thumb ov135
 */
#include "../include/Obj00137.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0201F5BC(u32, u32, u32, u32, u16);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void BG_SYS_SetSubPlaneVisible(u32, u32);
extern void WORLDTRADE_TITLE_LoadMainBgSwap(u8 *);
extern void WORLDTRADE_TITLE_LoadSubBgSwap(u8 *);
void WORLDTRADE_SERVER_LoadBgGraphics(u8 *p)
{
    func_02049B40(0x17, 5, 0, 0x1a0, 0x20, 0x48);
    func_0201F5BC(0, 1, 0xe, 0, 0x48);
    func_0201F5BC(0, 0x1f, 0xb, 0, 0x48);
    if (((struct Obj00137 *)p)->fE18 == 0) {
        func_02040588(4, 0);
        func_02040588(5, 0);
        BG_SYS_SetSubPlaneVisible(0x10, 0);
    }
    if (((struct Obj00137 *)p)->f1C == 9) {
        WORLDTRADE_TITLE_LoadMainBgSwap(p);
        WORLDTRADE_TITLE_LoadSubBgSwap(p);
    }
}
