/*
 * function: BR_BTN_SetPosY
 * address:  0x021FAF08
 * packet:   pkt_021FAF08
 * region:   ov186
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BR_BTN_DATA_GetRowField  0x021FB7B0  thumb  ov186
 *   BR_BTN_SetObjectPos  0x021FB514  thumb  ov186
 */
#include "../include/Obj14455.h"

extern int BR_BTN_DATA_GetRowField(void *p, int i);
extern void BR_BTN_SetObjectPos(char *p, short x, int y);

void BR_BTN_SetPosY(char *p, int a1)
{
    short r = (short)BR_BTN_DATA_GetRowField((void *)(((struct Obj14455 *)p)->fC), 0);

    BR_BTN_SetObjectPos(((struct Obj14455 *)p)->f8, r, a1);
}
