/*
 * function: MCSS_FlipVanishFlag
 * address:  0x02015EC4
 * packet:   pkt_02015EC4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in the ARM9 module. Toggles bit 11 of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */

typedef struct {
    char pad[0x140];
    unsigned int lo : 11;
    unsigned int b : 1;
    unsigned int hi : 20;
} R;

void MCSS_FlipVanishFlag(R *p)
{
    p->b = p->b ^ 1;
}
