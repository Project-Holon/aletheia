/*
 * function: MCSS_SetVanishFlag
 * address:  0x02015EA0
 * packet:   pkt_02015EA0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in the ARM9 module. Sets bit 11 (0x800) of the
 * 32-bit register at +0x140. Pairs with MCSS_ResetVanishFlag, which clears it.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj15663.h"

typedef unsigned int u32;

void MCSS_SetVanishFlag(void *p)
{
    *(volatile u32 *)&((struct Obj15663 *)p)->f140 |= 0x800u;
}
