/*
 * function: MCSS_SetAnmStopFlagAlways
 * address:  0x02015E28
 * packet:   pkt_02015E28
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in the ARM9 module. Sets bit 10 of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */

struct R {
    unsigned int : 9;
    unsigned int f : 2;
};

void MCSS_SetAnmStopFlagAlways(void *p)
{
    ((struct R *)((char *)p + 0x140))->f |= 2;
}
