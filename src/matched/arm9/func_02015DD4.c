/*
 * function: MCSS_FlipMepachiFlag
 * address:  0x02015DD4
 * packet:   pkt_02015DD4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in the ARM9 module. Toggles bit 8 of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */

struct R {
    unsigned int : 8;
    unsigned int f : 1;
};

void MCSS_FlipMepachiFlag(void *p)
{
    ((struct R *)((char *)p + 0x140))->f ^= 1;
}
