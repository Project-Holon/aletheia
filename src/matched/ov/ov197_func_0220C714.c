/*
 * function: func_0220C714
 * address:  0x0220C714
 * packet:   pkt_0220C714
 * region:   ov197
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_FINGER_CURSOR_DeleteActor 0x02209C18 thumb
 */
#include "../include/Obj25047.h"

extern void BTLV_FINGER_CURSOR_DeleteActor(int);

void func_0220C714(char *a)
{
    BTLV_FINGER_CURSOR_DeleteActor(((struct Obj25047 *)a)->f14C);
}
