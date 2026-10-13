/*
 * function: func_021E8F60
 * address:  0x021E8F60
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIPE_SYS_Start  0x0202208C  thumb  arm9
 *
 * Sibling of func_021E8F90: the seven-argument setup call then
 * the state word at +0xA188 of the sub-object, return 2.
 */
#include "../include/Obj18469.h"

typedef unsigned int   u32;
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);


int func_021E8F60(void *p, int a)
{
    WIPE_SYS_Start(0, 1, 1, 0, 6, 1, 0x4c);
    *(int *)(((struct Obj18469 *)p)->f2C + 0xA188) = a;
    return 2;
}
