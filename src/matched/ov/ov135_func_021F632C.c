/*
 * function: WORLDTRADE_BOX_StateStartWipeOut
 * address: 0x021F632C
 * packet: pkt_ov135_021F632C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   WIPE_SYS_Start  0x0202208C  thumb  arm9
 */
#include "../include/Obj06507.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void WIPE_SYS_Start(void *, u32, u32, u32, u32, u32, u32);
int WORLDTRADE_BOX_StateStartWipeOut(u8 *p)
{
    if (((struct Obj06507 *)p)->f14 == 0 || ((struct Obj06507 *)p)->f14 == 8 || ((struct Obj06507 *)p)->f14 == 3) {
        WIPE_SYS_Start(0, 0, 0, 0, 6, 1, 0x48);
        ((struct Obj06507 *)p)->fEB4 = 1;
    } else {
        WIPE_SYS_Start((void *)3, 0, 0, 0, 6, 1, 0x48);
    }
    ((struct Obj06507 *)p)->f28 = 0;
    return 3;
}
