/*
 * function: STAFF_ROLL_UpdateBrightness
 * address: 0x021BA2D8
 * packet: pkt_ov181_021BA2D8
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: The progress field at +0x1c is re-read at 0x021BA2F8 after its store at 0x021BA2F6.
 * symbols:
 *   G2x_SetBlendBrightness_ 0x0207D658 arm
 */
#include "../include/Obj03877.h"
extern void G2x_SetBlendBrightness_(unsigned, int, int);
void STAFF_ROLL_UpdateBrightness(char *p)
{
    int v = ((struct Obj03877 *)p)->f1C;
    if (v <= 0x10000) {
        ((struct Obj03877 *)p)->f1C = v + (((struct Obj03877 *)p)->f2D2 == 1 ? 0x400 : 0x100);
        G2x_SetBlendBrightness_(0x04000050, 1, *(volatile int *)&((struct Obj03877 *)p)->f1C / 0x1000 - 0x10);
    }
}
