/*
 * function: MCSS_ResetMepachiFlag
 * address:  0x02015DC0
 * packet:   pkt_02015DC0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in the ARM9 module. Clears bit 8 of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj15662.h"

void MCSS_ResetMepachiFlag(void *p)
{
    ((struct Obj15662 *)p)->f140 &= ~0x100u;
}
