/*
 * function: BUTTON_MAN_SetUserData
 * address:  0x02051A2C
 * packet:   pkt_02051A2C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Unlabelled ARM leaf in the ARM9 module: an 8-byte store helper,
 * `p[0x94/4] = v`. The +0x94 twin of BUTTON_MAN_SetCallback.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj16192.h"

void BUTTON_MAN_SetUserData(void *p, int v)
{
    ((struct Obj16192 *)p)->f94 = v;
}
