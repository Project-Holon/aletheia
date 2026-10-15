/*
 * function: EGG_DEMO_MENU_InitDialog
 * address:  0x021F6280
 * packet:   pkt_021F6280
 * region:   ov215
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_CreateRun 0x0203FA08 arm
 *   BG_SYS_DeleteHalf 0x0203FB44 arm
 */
#include "../include/Obj05550.h"

typedef unsigned int   u32;
extern u32 BG_SYS_CreateRun(u32 layer, u32 size, u32 top);
extern void BG_SYS_DeleteHalf(u32 layer, u32 offset, u32 size);

void EGG_DEMO_MENU_InitDialog(int unused, unsigned char *q)
{
    int h = BG_SYS_CreateRun(1, 0x500, 1);

    BG_SYS_DeleteHalf(1, h, 0x500);
    q[0x70] = 1;
    q[0x71] = 0x18;
    q[0x72] = 0xd;
    q[0x73] = 1;
    ((struct Obj05550 *)q)->f74 = h;
    ((struct Obj05550 *)q)->f7C = 2;
}
