/*
 * function: PARTICLE_EMITTER_GetUserData
 * address:  0x02051A34
 * packet:   pkt_02051A34
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Unlabelled ARM leaf in the ARM9 module: an 8-byte load helper,
 * `return p[0x94/4]`. The getter half of BUTTON_MAN_SetUserData.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj16193.h"

int PARTICLE_EMITTER_GetUserData(void *p)
{
    return ((struct Obj16193 *)p)->f94;
}
