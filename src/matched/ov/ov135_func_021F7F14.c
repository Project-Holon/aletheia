/*
 * function: WORLDTRADE_DEPOSIT_StateStartWipeOut
 * address: 0x021F7F14
 * packet: pkt_ov135_021F7F14
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   WIPE_SYS_Start  0x0202208C  thumb  arm9
 */
#include "../include/Obj10577.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
int WORLDTRADE_DEPOSIT_StateStartWipeOut(u8 *p)
{
    if (((struct Obj10577 *)p)->f14 == 0) {
        WIPE_SYS_Start(0, 0, 0, 0, 6, 1, 0x48);
        ((struct Obj10577 *)p)->fEB4 = 1;
    } else {
        WIPE_SYS_Start((void *)3, 0, 0, 0, 6, 1, 0x48);
    }
    ((struct Obj10577 *)p)->f28 = 0;
    return 3;
}
