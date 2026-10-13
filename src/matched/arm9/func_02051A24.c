/*
 * function: BUTTON_MAN_SetCallback
 * address:  0x02051A24
 * packet:   pkt_02051A24
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Unlabelled ARM leaf in the ARM9 module: an 8-byte store helper,
 * `p[0x90/4] = v`. With BUTTON_MAN_SetUserData (the +0x94 twin) it is the storage
 * setter pair the ov118 functions func_021D6EAC/func_021D6F0C call.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj16191.h"

void BUTTON_MAN_SetCallback(void *p, int v)
{
    ((struct Obj16191 *)p)->f90 = v;
}
