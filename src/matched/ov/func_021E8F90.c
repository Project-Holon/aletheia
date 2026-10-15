/*
 * function: BOX2_SEQ_StartWipeBlack
 * address:  0x021E8F90
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
 * Same body as BOX2_SEQ_StartWipeWhite with the first four arguments zero;
 * the state word goes to +0xA188, return 2.
 */
#include "../include/Obj18470.h"

typedef unsigned int   u32;
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);


int BOX2_SEQ_StartWipeBlack(void *p, int a)
{
    WIPE_SYS_Start(0, 0, 0, 0, 6, 1, 0x4c);
    *(int *)(((struct Obj18470 *)p)->f2C + 0xA188) = a;
    return 2;
}
