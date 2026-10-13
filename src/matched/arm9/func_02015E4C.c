/*
 * function: MCSS_ResetAnmStopFlag
 * address:  0x02015E4C
 * packet:   pkt_02015E4C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in the ARM9 module. Compound-AND of the 2-bit
 * bitfield at bits 9..10 of the register at +0x140 with ~1 (clears bit 9).
 * Same non-volatile codegen lever as MCSS_SetAnmStopFlag.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

struct Reg02015E4C {
    unsigned int : 9;
    unsigned int f : 2;
};

void MCSS_ResetAnmStopFlag(void *p)
{
    ((struct Reg02015E4C *)((char *)p + 0x140))->f &= ~1u;
}
