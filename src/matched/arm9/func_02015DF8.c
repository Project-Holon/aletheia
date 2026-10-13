/*
 * function: MCSS_GetAnmStopFlag
 * address:  0x02015DF8
 * packet:   pkt_02015DF8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in the ARM9 module. Reads the two-bit field at bits 9..10 of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */

typedef struct {
    char pad[0x140];
    unsigned int lo : 9;
    unsigned int b : 2;
    unsigned int hi : 21;
} R;

int MCSS_GetAnmStopFlag(R *p)
{
    return p->b;
}
