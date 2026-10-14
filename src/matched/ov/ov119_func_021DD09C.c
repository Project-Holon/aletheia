/*
 * function: func_021DD09C
 * address: 0x021DD09C
 * packet: pkt_ov119_021DD09C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020355C4 0x020355C4 arm
 *   POKETRADE_2D_MovePickedIconActor 0x021E68F4 thumb ov119
 */
#include "../include/Obj22736.h"
typedef unsigned char  u8;
extern u8 func_020355C4(void);
extern void POKETRADE_2D_MovePickedIconActor(int p, int i);
void func_021DD09C(char *p)
{
    if (func_020355C4()) {
        POKETRADE_2D_MovePickedIconActor((int)p, -1);
        return;
    }
    {
        int v = ((struct Obj22736 *)p)->f10A0;
        if (v != -1)
            POKETRADE_2D_MovePickedIconActor((int)p, v);
    }
}
