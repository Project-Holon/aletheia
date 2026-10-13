/*
 * function: MCSS_SetAnmStopFlag
 * address:  0x02015E04
 * packet:   pkt_02015E04
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in the ARM9 module. Compound-OR of the 2-bit
 * bitfield at bits 9..10 of the register at +0x140 with 1. The access is
 * non-volatile in the original: mwcc reads the word once and reinserts the
 * field without a reload (a `volatile` spelling forces a second `ldr` and
 * diverges). Pairs with MCSS_ResetAnmStopFlag, which clears bit 9.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

struct Reg02015Exx {
    unsigned int : 9;
    unsigned int f : 2;
};

void MCSS_SetAnmStopFlag(void *p)
{
    ((struct Reg02015Exx *)((char *)p + 0x140))->f |= 1;
}
