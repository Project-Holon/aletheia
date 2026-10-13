/*
 * function: func_021FC610
 * address:  0x021FC610
 * packet:   pkt_021FC610
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

 *
 * Push the fixed 6/1/0x48 request and clear the state word.
 */
#include "../include/Obj18569.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);

int func_021FC610(u8 *p, int a1)
{
    WIPE_SYS_Start((void *)3, 0, 0, 0, 6, 1, 0x48);
    ((struct Obj18569 *)p)->f28 = 0;
    return 3;
}
