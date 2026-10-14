/*
 * function: WORLDTRADE_SEARCH_StateStartWipeOutPage
 * address:  0x021FEB50
 * packet:   pkt_021FEB50
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIPE_SYS_Start  0x0202208C  thumb  arm9
 *

 * When the countdown at +0xd3c is spent, run the fixed 3/6/1/0x48 opener, then state 0.
 */
#include "../include/Obj12213.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);

int WORLDTRADE_SEARCH_StateStartWipeOutPage(u8 *p)
{
    if (((struct Obj12213 *)p)->fD3C == 0) {
        WIPE_SYS_Start((void *)3, 0, 0, 0, 6, 1, 0x48);
    }
    ((struct Obj12213 *)p)->f28 = 0;
    return 3;
}
